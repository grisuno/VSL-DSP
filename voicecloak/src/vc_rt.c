#include "vc_rt.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

struct vc_rt_ctx_s {
    size_t         nbins;
    vc_rt_params_t p;
    uint64_t       frame_index;

    double *prev_phase;  /* analysis phase of previous frame */
    double *sum_phase;   /* accumulated synthesis phase       */
    float  *ana_mag;     /* analysis magnitude scratch        */
    double *true_hz;     /* per-bin true frequency (Hz)        */
    float  *syn_mag;     /* synthesis magnitude scratch        */
    double *syn_hz;      /* synthesis true frequency (Hz)      */
    float  *cur_phase;   /* current-frame analysis phases      */
    float  *best_mag;    /* dominant contributor per target    */
    float  *tmp_mag;     /* formant resampling scratch         */
    size_t *peaks;       /* detected peak bins                 */
    ptrdiff_t *delta;    /* rigid shift per peak               */
    size_t *tgt_src;     /* dominant analysis source per target */
    size_t *tgt_pk;      /* peak-region index per target        */
    size_t  npeak;       /* peak count of the last move         */
};

vc_rt_ctx_t *vc_rt_create(size_t nbins, vc_rt_params_t params) {
    if (nbins < 2) return NULL;
    vc_rt_ctx_t *c = (vc_rt_ctx_t *)calloc(1, sizeof(*c));
    if (!c) return NULL;
    c->nbins = nbins;
    c->p = params;
    c->prev_phase = (double *)calloc(nbins, sizeof(double));
    c->sum_phase  = (double *)calloc(nbins, sizeof(double));
    c->ana_mag    = (float  *)calloc(nbins, sizeof(float));
    c->true_hz    = (double *)calloc(nbins, sizeof(double));
    c->syn_mag    = (float  *)calloc(nbins, sizeof(float));
    c->syn_hz     = (double *)calloc(nbins, sizeof(double));
    c->cur_phase  = (float  *)calloc(nbins, sizeof(float));
    c->best_mag   = (float  *)calloc(nbins, sizeof(float));
    c->tmp_mag    = (float  *)calloc(nbins, sizeof(float));
    c->peaks      = (size_t *)calloc(nbins, sizeof(size_t));
    c->delta      = (ptrdiff_t *)calloc(nbins, sizeof(ptrdiff_t));
    c->tgt_src    = (size_t *)calloc(nbins, sizeof(size_t));
    c->tgt_pk     = (size_t *)calloc(nbins, sizeof(size_t));
    if (!c->prev_phase || !c->sum_phase || !c->ana_mag ||
        !c->true_hz || !c->syn_mag || !c->syn_hz ||
        !c->cur_phase || !c->best_mag || !c->tmp_mag ||
        !c->peaks || !c->delta || !c->tgt_src || !c->tgt_pk) {
        vc_rt_destroy(c);
        return NULL;
    }
    return c;
}

void vc_rt_destroy(vc_rt_ctx_t *c) {
    if (!c) return;
    free(c->prev_phase);
    free(c->sum_phase);
    free(c->ana_mag);
    free(c->true_hz);
    free(c->syn_mag);
    free(c->syn_hz);
    free(c->cur_phase);
    free(c->best_mag);
    free(c->tmp_mag);
    free(c->peaks);
    free(c->delta);
    free(c->tgt_src);
    free(c->tgt_pk);
    free(c);
}

void vc_rt_reset(vc_rt_ctx_t *c) {
    if (!c) return;
    memset(c->prev_phase, 0, c->nbins * sizeof(double));
    memset(c->sum_phase, 0, c->nbins * sizeof(double));
    c->frame_index = 0;
}

float vc_rt_semitones_to_ratio(float semitones) {
    return powf(2.0f, semitones / 12.0f);
}

static double wrap_pi(double x) {
    while (x >  M_PI) x -= 2.0 * M_PI;
    while (x < -M_PI) x += 2.0 * M_PI;
    return x;
}

/* Peak picking on a magnitude spectrum: a bin is a peak when it is a
 * local maximum above a relative (-80 dB) and absolute floor. Returns
 * the peak count (ascending). Silence yields zero peaks. */
static size_t pick_peaks(const float *mag, size_t nbins, size_t *peaks) {
    float max = 0.0f, thr;
    size_t q, n = 0;
    for (q = 0; q < nbins; ++q)
        if (mag[q] > max) max = mag[q];
    if (max <= 0.0f) return 0;
    thr = max * 1e-4f;
    if (thr < 1e-7f) thr = 1e-7f;
    if (nbins > 1 && mag[0] > thr && mag[0] >= mag[1])
        peaks[n++] = 0;
    for (q = 1; q + 1 < nbins; ++q) {
        if (mag[q] > thr && mag[q] > mag[q - 1] && mag[q] >= mag[q + 1])
            peaks[n++] = q;
    }
    if (nbins > 1 && mag[nbins - 1] > thr && mag[nbins - 1] > mag[nbins - 2])
        peaks[n++] = nbins - 1;
    return n;
}

/**
 * @brief Rigidly translate each peak region by a proportional factor.
 *
 * Every bin belongs to its nearest peak; the whole region moves by the
 * same integer offset, so a partial keeps its shape and its bins keep
 * coherent relative phases (per-bin proportional mapping scatters one
 * partial across unrelated bins and the overlap-add cancels itself,
 * costing ~8 dB and the "drowned" character).
 *
 * Magnitude and true frequency travel as a pair, so phase propagation
 * stays consistent with content; magnitudes accumulate while the
 * dominant source wins the true frequency. The winning source and its
 * peak region are recorded per target (tgt_src/tgt_pk) so the final
 * stage can identity-lock non-peak bins to their peak. Out-of-range
 * content is discarded (the caller renormalizes energy). With zero
 * peaks (silence) falls back to legacy per-bin mapping with no
 * records (targets keep the nbins sentinel and use plain tracks).
 */
static void rigid_move(vc_rt_ctx_t *c,
                       const float *src_mag, const double *src_hz,
                       float *dst_mag, double *dst_hz,
                       double factor, double hz_scale,
                       double freq_per_bin) {
    size_t nbins = c->nbins, b, r = 0;
    size_t npeak = pick_peaks(src_mag, nbins, c->peaks);
    for (r = 0; r < npeak; ++r) {
        long t = (long)floor((double)c->peaks[r] * factor + 0.5);
        c->delta[r] = (ptrdiff_t)(t - (long)c->peaks[r]);
    }
    for (b = 0; b < nbins; ++b) {
        dst_mag[b] = 0.0f;
        dst_hz[b] = (double)b * freq_per_bin;
        c->best_mag[b] = 0.0f;
        c->tgt_src[b] = nbins;
        c->tgt_pk[b] = 0;
    }
    r = 0;
    for (b = 0; b < nbins; ++b) {
        long idx;
        if (npeak == 0) {
            idx = (long)floor((double)b * factor + 0.5);
        } else {
            while (r + 1 < npeak &&
                   c->peaks[r] + c->peaks[r + 1] <= 2 * b)
                ++r;
            idx = (long)b + c->delta[r];
        }
        if (idx >= 0 && (size_t)idx < nbins) {
            dst_mag[(size_t)idx] += src_mag[b];
            if (src_mag[b] > c->best_mag[(size_t)idx]) {
                c->best_mag[(size_t)idx] = src_mag[b];
                dst_hz[(size_t)idx] = src_hz[b] * hz_scale;
                if (npeak != 0) {
                    c->tgt_src[(size_t)idx] = b;
                    c->tgt_pk[(size_t)idx] = r;
                }
            }
        }
    }
    c->npeak = npeak;
}

/**
 * @brief Resample the spectral envelope for formant shifting.
 *
 * Partials keep their bins, true frequencies, and phase tracks; only
 * magnitudes are remapped (nearest neighbor), so no heterodyne offset
 * is introduced and coherence is fully preserved (unlike shifting
 * magnitudes across bins, which renders content far from its bin
 * center where the overlap-add response attenuates it ~-3.5 dB and
 * smears it). Nearest (not linear) sampling avoids mixing neighboring
 * bins, which measured -8 dB from overlap-add cancellation.
 */
static void formant_resample_mag(vc_rt_ctx_t *c, float factor) {
    size_t nbins = c->nbins, b;
    if (fabsf(factor - 1.0f) < 0.01f) return;
    if (factor < 0.3f) factor = 0.3f;
    if (factor > 3.0f) factor = 3.0f;
    for (b = 0; b < nbins; ++b) {
        long j = (long)floor((double)b / (double)factor + 0.5);
        if (j < 0) j = 0;
        if ((size_t)j >= nbins) j = (long)(nbins - 1);
        c->tmp_mag[b] = c->syn_mag[(size_t)j];
    }
    for (b = 0; b < nbins; ++b) c->syn_mag[b] = c->tmp_mag[b];
}

void vc_rt_transform(float *mag, float *phase, size_t nbins,
                     uint32_t sample_rate, size_t hop, void *user) {
    vc_rt_ctx_t *c = (vc_rt_ctx_t *)user;
    if (!c || c->nbins != nbins) return;

    size_t fft = 2 * (nbins - 1);
    double freq_per_bin = (double)sample_rate / (double)fft;
    double osamp = (double)fft / (double)hop;
    double expct = 2.0 * M_PI / osamp;
    double ratio = (double)c->p.pitch_ratio;
    size_t b;

    for (b = 0; b < nbins; ++b) {
        double ph = (double)phase[b];
        /* NOTE: vc_fft uses a positive exponent for the forward
         * transform (swapped convention), so measured phases advance at
         * minus the true rate (verified: +2.0944 instead of +4.1888
         * rad/frame for a 1 kHz sine at hop 512). Negate the difference
         * to recover the standard-convention deviation. */
        double dphi = c->prev_phase[b] - ph;
        c->prev_phase[b] = ph;
        dphi -= (double)b * expct;
        dphi = wrap_pi(dphi);
        dphi = osamp * dphi / (2.0 * M_PI);
        c->true_hz[b] = ((double)b + dphi) * freq_per_bin;
        c->ana_mag[b] = mag[b];
        c->cur_phase[b] = (float)ph;
        c->syn_mag[b] = 0.0f;
        c->syn_hz[b]  = (double)b * freq_per_bin;
    }

    /* Pitch: rigid per-peak translation of (magnitude, true frequency)
     * pairs; true frequencies scale by ratio so every partial keeps a
     * small heterodyne offset and full overlap-add response. */
    rigid_move(c, c->ana_mag, c->true_hz, c->syn_mag, c->syn_hz,
               ratio, ratio, freq_per_bin);

    /* Formant: envelope-only magnitude resampling; partials stay on
     * their bins with untouched tracks. */
    formant_resample_mag(c, c->p.formant_factor);

    /* Energy renormalization safety net: out-of-range discards must not
     * silently drop the level. Silence passes through untouched: if
     * either energy is near zero no scaling is applied (fail closed). */
    {
        double es = 0.0, ed = 0.0;
        for (b = 0; b < nbins; ++b) {
            es += (double)c->ana_mag[b] * (double)c->ana_mag[b];
            ed += (double)c->syn_mag[b] * (double)c->syn_mag[b];
        }
        if (ed > 1e-8 && es > 1e-8) {
            float scale = (float)sqrt(es / ed);
            for (b = 0; b < nbins; ++b) c->syn_mag[b] *= scale;
        }
    }

    float intensity = c->p.scramble_intensity;
    /* Time-varying permutation: a frozen pattern measured like a
     * lottery (good on some signals, -12 dB on others) because content
     * sits in fixed wrong bins; varying averages configurations to a
     * stable mean. Locking records travel with the content. */
    if (intensity > 0.0f) {
        if (intensity > 1.0f) intensity = 1.0f;
        size_t band_edges[] = {1, 8, 16, 32, 64, 128, 256, 512, nbins - 1};
        size_t nbands = sizeof(band_edges) / sizeof(band_edges[0]) - 1;
        size_t band;
        for (band = 0; band < nbands; ++band) {
            size_t b0 = band_edges[band];
            size_t b1 = band_edges[band + 1];
            if (b1 <= b0 || b0 >= nbins) continue;
            if (b1 > nbins - 1) b1 = nbins - 1;
            size_t bandsz = b1 - b0;
            if (bandsz < 2) continue;
            size_t bi;
            for (bi = 0; bi < bandsz; ++bi) {
                size_t src = b0 + bi;
                size_t tgt = b0 + (size_t)((c->frame_index * 2654435761UL +
                                            bi * 1597334677UL) % bandsz);
                if (tgt != src && tgt < nbins) {
                    float tm = c->syn_mag[src];
                    c->syn_mag[src] = c->syn_mag[tgt];
                    c->syn_mag[tgt] = tm;
                    double th = c->syn_hz[src];
                    c->syn_hz[src] = c->syn_hz[tgt];
                    c->syn_hz[tgt] = th;
                    size_t ts = c->tgt_src[src];
                    c->tgt_src[src] = c->tgt_src[tgt];
                    c->tgt_src[tgt] = ts;
                    size_t tp = c->tgt_pk[src];
                    c->tgt_pk[src] = c->tgt_pk[tgt];
                    c->tgt_pk[tgt] = tp;
                }
            }
        }
    }

    /* Advance every phase track at its own true rate (tracks for peak
     * bins are the reference that locked bins inherit below). */
    for (b = 0; b < nbins; ++b) {
        double dev = c->syn_hz[b] / freq_per_bin - (double)b;
        double adv = 2.0 * M_PI * dev / osamp + (double)b * expct;
        /* Subtract: synthesis consumes the same swapped-convention
         * phases as the analysis produces (vc_fft uses a positive
         * exponent forward), so tracks must run at minus the true
         * rate; passthrough with untouched phases reconstructing at
         * unity is the consistency proof. */
        c->sum_phase[b] -= adv;
    }

    /* Identity phase locking: a non-peak bin inherits its region
     * peak's propagated track plus the measured analysis offset
     * between its dominant source and that peak. This preserves the
     * lobe's physical relative phases (measured pi-structured on real
     * tones), without which adjacent bins cancel in overlap-add.
     * Peak bins use their own track unchanged, so pitch tracking is
     * unaffected by construction. Bins with no records (silence,
     * out-of-range peaks) fall back to plain tracks. */
    for (b = 0; b < nbins; ++b) {
        double out_phase = c->sum_phase[b];
        size_t s = c->tgt_src[b];
        if (s < nbins) {
            size_t r = c->tgt_pk[b];
            if (r < c->npeak) {
                size_t q = c->peaks[r];
                long pt = (long)q + c->delta[r];
                if (q < nbins && pt >= 0 && (size_t)pt < nbins)
                    out_phase = c->sum_phase[(size_t)pt] +
                        ((double)c->cur_phase[s] - (double)c->cur_phase[q]);
            }
        }
        if (intensity > 0.0f && b >= 1) {
            unsigned long h = (unsigned long)(c->frame_index * nbins + b) *
                              1103515245UL + 12345UL;
            double r = (double)(h & 0x7FFFFF) / 8388608.0;
            out_phase += r * (double)intensity * 2.0 * M_PI;
        }
        mag[b]   = c->syn_mag[b];
        phase[b] = (float)out_phase;
    }

    c->frame_index++;
}
