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
    if (!c->prev_phase || !c->sum_phase || !c->ana_mag ||
        !c->true_hz || !c->syn_mag || !c->syn_hz) {
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

static void formant_warp(float *syn_mag, size_t nbins, float factor) {
    if (fabsf(factor - 1.0f) < 0.01f) return;
    if (factor < 0.3f) factor = 0.3f;
    if (factor > 3.0f) factor = 3.0f;

    float *tmp = (float *)calloc(nbins, sizeof(float));
    if (!tmp) return;

    size_t b;
    double es = 0.0, ed = 0.0;
    tmp[0] = syn_mag[0];
    for (b = 1; b < nbins; ++b) {
        float dst_bin = (float)b * factor;
        if (dst_bin >= (float)(nbins - 1)) dst_bin = (float)(nbins - 2);
        if (dst_bin < 0.0f) dst_bin = 0.0f;
        size_t lo = (size_t)dst_bin;
        size_t hi = lo + 1;
        if (hi >= nbins) hi = nbins - 1;
        float frac = dst_bin - (float)lo;
        tmp[lo] += syn_mag[b] * (1.0f - frac);
        tmp[hi] += syn_mag[b] * frac;
    }
    for (b = 0; b < nbins; ++b) {
        es += (double)syn_mag[b] * (double)syn_mag[b];
        ed += (double)tmp[b] * (double)tmp[b];
    }
    if (ed > 1e-8 && es > 1e-8) {
        float scale = (float)sqrt(es / ed);
        for (b = 0; b < nbins; ++b) syn_mag[b] = tmp[b] * scale;
    } else {
        for (b = 0; b < nbins; ++b) syn_mag[b] = tmp[b];
    }
    free(tmp);
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
        double dphi = ph - c->prev_phase[b];
        c->prev_phase[b] = ph;
        dphi -= (double)b * expct;
        dphi = wrap_pi(dphi);
        dphi = osamp * dphi / (2.0 * M_PI);
        c->true_hz[b] = ((double)b + dphi) * freq_per_bin;
        c->ana_mag[b] = mag[b];
        c->syn_mag[b] = 0.0f;
        c->syn_hz[b]  = (double)b * freq_per_bin;
    }

    for (b = 0; b < nbins; ++b) {
        long idx = (long)floor((double)b * ratio + 0.5);
        if (idx >= 0 && (size_t)idx < nbins) {
            c->syn_mag[idx] += c->ana_mag[b];
            c->syn_hz[idx]   = c->true_hz[b] * ratio;
        }
    }

    formant_warp(c->syn_mag, nbins, c->p.formant_factor);

    float intensity = c->p.scramble_intensity;
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
                }
            }
        }
    }

    for (b = 0; b < nbins; ++b) {
        double dev = c->syn_hz[b] / freq_per_bin - (double)b;
        double adv = 2.0 * M_PI * dev / osamp + (double)b * expct;
        c->sum_phase[b] += adv;
        double out_phase = c->sum_phase[b];
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
