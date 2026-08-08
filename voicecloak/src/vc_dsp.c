#include "vc_dsp.h"
#include "vc_stft.h"
#include "vc_crypto.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>

#define VC_FFT_SIZE 2048U
#define VC_HOP_SIZE  (VC_FFT_SIZE / 4)

static int stft_process(const float *samples, size_t num_samples,
                        float **mag, float **phase, size_t *nframes) {
    vc_stft_t *st = vc_stft_create(VC_FFT_SIZE, VC_HOP_SIZE);
    if (!st) return -1;
    int r = vc_stft_forward(st, samples, num_samples, mag, phase, nframes);
    vc_stft_destroy(st);
    return r;
}

static int stft_reconstruct(const float *mag, const float *phase,
                            size_t nframes, size_t num_samples,
                            float *out, size_t synth_hop) {
    vc_stft_t *st = vc_stft_create(VC_FFT_SIZE, VC_HOP_SIZE);
    if (!st) return -1;
    int r = vc_stft_inverse_hop(st, mag, phase, nframes, out, num_samples, synth_hop);
    vc_stft_destroy(st);
    return r;
}

static size_t compute_out_len(size_t nframes, size_t hop) {
    return nframes > 0 ? (nframes - 1) * hop + VC_FFT_SIZE : 0;
}

int vc_dsp_pitch_shift(const float *samples, size_t num_samples,
                       uint32_t sample_rate, float semitones,
                       float **out, size_t *out_len) {
    if (!samples || !num_samples || !out || !out_len) return -1;

    float ratio = powf(2.0f, semitones / 12.0f);
    size_t synth_hop = (size_t)((float)VC_HOP_SIZE * ratio);
    if (synth_hop < 16) synth_hop = 16;
    if (synth_hop > VC_FFT_SIZE * 2) synth_hop = VC_FFT_SIZE * 2;

    float *mag = NULL, *phase = NULL;
    size_t nframes;
    if (stft_process(samples, num_samples, &mag, &phase, &nframes) != 0)
        return -1;

    size_t nbins = VC_FFT_SIZE / 2 + 1;

    float *synth_phase = (float *)calloc(nbins, sizeof(float));
    if (!synth_phase) { free(mag); free(phase); return -1; }
    memcpy(synth_phase, phase, nbins * sizeof(float));

    size_t f, b;
    for (f = 1; f < nframes; ++f) {
        float *p_prev = phase + (f - 1) * nbins;
        float *p_curr = phase + f * nbins;

        for (b = 0; b < nbins; ++b) {
            float bin_freq = (float)b * (float)sample_rate / (float)VC_FFT_SIZE;
            float phase_adv = 2.0f * 3.14159265358979323846f * bin_freq
                            * (float)VC_HOP_SIZE / (float)sample_rate;
            float delta = p_curr[b] - p_prev[b] - phase_adv;
            while (delta >  3.14159265358979323846f) delta -= 2.0f * 3.14159265358979323846f;
            while (delta < -3.14159265358979323846f) delta += 2.0f * 3.14159265358979323846f;

            float inst_freq_adv = phase_adv + delta;
            synth_phase[b] += ratio * inst_freq_adv;
            p_curr[b] = synth_phase[b];
        }
    }
    free(synth_phase);

    size_t out_n = compute_out_len(nframes, synth_hop);
    float *out_buf = (float *)calloc(out_n, sizeof(float));
    if (!out_buf) { free(mag); free(phase); return -1; }

    if (stft_reconstruct(mag, phase, nframes, out_n, out_buf, synth_hop) != 0) {
        free(mag); free(phase); free(out_buf); return -1;
    }

    free(mag);
    free(phase);
    *out = out_buf;
    *out_len = out_n;
    return 0;
}

int vc_dsp_formant_shift(const float *samples, size_t num_samples,
                         uint32_t sample_rate, float shift_factor,
                         float **out, size_t *out_len) {
    (void)sample_rate;
    if (!samples || !num_samples || !out || !out_len) return -1;
    if (shift_factor < 0.3f) shift_factor = 0.3f;
    if (shift_factor > 3.0f) shift_factor = 3.0f;

    float *mag = NULL, *phase = NULL;
    size_t nframes;
    if (stft_process(samples, num_samples, &mag, &phase, &nframes) != 0)
        return -1;

    size_t nbins = VC_FFT_SIZE / 2 + 1;

    float *shifted_mag = (float *)malloc(nframes * nbins * sizeof(float));
    if (!shifted_mag) { free(mag); free(phase); return -1; }

    size_t f, b;
    for (f = 0; f < nframes; ++f) {
        float *src = mag + f * nbins;
        float *dst = shifted_mag + f * nbins;
        memset(dst, 0, nbins * sizeof(float));

        for (b = 1; b < nbins; ++b) {
            float src_bin = (float)b;
            float dst_bin = src_bin * shift_factor;

            if (dst_bin < 0.0f) dst_bin = 0.0f;
            if (dst_bin >= (float)(nbins - 1)) dst_bin = (float)(nbins - 2);

            size_t lo = (size_t)dst_bin;
            size_t hi = lo + 1;
            if (hi >= nbins) hi = nbins - 1;
            float frac = dst_bin - (float)lo;

            dst[lo] += src[b] * (1.0f - frac);
            dst[hi] += src[b] * frac;
        }
        dst[0] = src[0];

        float es = 0.0f, ed = 0.0f;
        for (b = 0; b < nbins; ++b) {
            es += src[b] * src[b];
            ed += dst[b] * dst[b];
        }
        if (ed > 1e-8f && es > 1e-8f) {
            float scale = sqrtf(es / ed);
            for (b = 0; b < nbins; ++b) dst[b] *= scale;
        }
    }

    free(mag);
    mag = shifted_mag;

    size_t out_n = compute_out_len(nframes, VC_HOP_SIZE);
    float *out_buf = (float *)calloc(out_n, sizeof(float));
    if (!out_buf) { free(mag); free(phase); return -1; }

    if (stft_reconstruct(mag, phase, nframes, out_n, out_buf, VC_HOP_SIZE) != 0) {
        free(mag); free(phase); free(out_buf); return -1;
    }

    free(mag);
    free(phase);
    *out = out_buf;
    *out_len = out_n;
    return 0;
}

int vc_dsp_spectral_scramble(const float *samples, size_t num_samples,
                             uint32_t sample_rate, float intensity,
                             float **out, size_t *out_len) {
    (void)sample_rate;
    if (!samples || !num_samples || !out || !out_len) return -1;
    if (intensity < 0.0f) intensity = 0.0f;
    if (intensity > 1.0f) intensity = 1.0f;

    float *mag = NULL, *phase = NULL;
    size_t nframes;
    if (stft_process(samples, num_samples, &mag, &phase, &nframes) != 0)
        return -1;

    size_t nbins = VC_FFT_SIZE / 2 + 1;

    size_t f, b;
    for (f = 0; f < nframes; ++f) {
        float *m = mag + f * nbins;
        float *p = phase + f * nbins;

        /* Permute bins within bands. Band edges follow mel-scale-ish divisions */
        size_t band_edges[] = {1, 8, 16, 32, 64, 128, 256, 512, nbins - 1};
        size_t nbands = sizeof(band_edges) / sizeof(band_edges[0]) - 1;

        size_t band;
        for (band = 0; band < nbands; ++band) {
            size_t b_start = band_edges[band];
            size_t b_end   = band_edges[band + 1];
            if (b_end <= b_start) continue;

            size_t band_size = b_end - b_start;

            /* Deterministic permutation based on frame index */
            size_t bi;
            for (bi = 0; bi < band_size; ++bi) {
                size_t src_idx = b_start + bi;
                /* Swap with a pseudo-random index within the band */
                size_t target = b_start + ((f * 2654435761U + bi * 1597334677U) % band_size);
                if (target != src_idx && target < nbins) {
                    float tmp_m = m[src_idx];
                    float tmp_p = p[src_idx];
                    m[src_idx] = m[target];
                    p[src_idx] = p[target];
                    m[target] = tmp_m;
                    p[target] = tmp_p;
                }
            }
        }

        /* Phase randomization proportional to intensity */
        for (b = 1; b < nbins; ++b) {
            /* Use multiplicative hash for deterministic pseudo-random phase */
            unsigned int hash = (unsigned int)(f * nbins + b) * 1103515245U + 12345U;
            float r = (float)(hash & 0x7FFFFF) / 8388608.0f;
            p[b] += r * intensity * 2.0f * 3.14159265358979323846f;
        }
    }

    size_t out_n = compute_out_len(nframes, VC_HOP_SIZE);
    float *out_buf = (float *)calloc(out_n, sizeof(float));
    if (!out_buf) { free(mag); free(phase); return -1; }

    if (stft_reconstruct(mag, phase, nframes, out_n, out_buf, VC_HOP_SIZE) != 0) {
        free(mag); free(phase); free(out_buf); return -1;
    }

    free(mag);
    free(phase);
    *out = out_buf;
    *out_len = out_n;
    return 0;
}

static void trim_edges(float **buf, size_t *len) {
    size_t start = 0;
    size_t end = *len;
    while (start < end && fabsf((*buf)[start]) < 1e-6f) ++start;
    while (end > start && fabsf((*buf)[end - 1]) < 1e-6f) --end;
    if (start > 0 || end < *len) {
        size_t new_len = end - start;
        if (new_len > 0 && new_len < *len) {
            float *trimmed = (float *)malloc(new_len * sizeof(float));
            if (trimmed) {
                size_t i;
                for (i = 0; i < new_len; ++i)
                    trimmed[i] = (*buf)[start + i];
                free(*buf);
                *buf = trimmed;
                *len = new_len;
            }
        }
    }
}

static void normalize_rms(const float *in, size_t in_len,
                          float *out, size_t out_len) {
    double rms_in = 0.0, rms_out = 0.0;
    size_t i;
    for (i = 0; i < in_len; ++i)
        rms_in += (double)in[i] * (double)in[i];
    rms_in = sqrt(rms_in / (double)in_len);
    for (i = 0; i < out_len; ++i)
        rms_out += (double)out[i] * (double)out[i];
    rms_out = sqrt(rms_out / (double)out_len);
    if (rms_out > 1e-8 && rms_in > 1e-8) {
        float gain = (float)(rms_in / rms_out);
        if (gain > 10.0f) gain = 10.0f;
        for (i = 0; i < out_len; ++i) out[i] *= gain;
    }
}

int vc_dsp_cloak(const float *samples, size_t num_samples,
                 uint32_t sample_rate,
                 const unsigned char *pitch_seed,
                 const unsigned char *formant_seed,
                 const unsigned char *spectral_seed,
                 VcMode mode,
                 float **out, size_t *out_len) {
    if (!samples || !num_samples || !out || !out_len) return -1;

    vc_prng_t *pp = vc_prng_create(pitch_seed);
    vc_prng_t *pf = vc_prng_create(formant_seed);
    vc_prng_t *ps = vc_prng_create(spectral_seed);
    if (!pp || !pf || !ps) {
        vc_prng_destroy(pp); vc_prng_destroy(pf); vc_prng_destroy(ps);
        return -1;
    }

    float pitch_semitones, formant_factor, scramble_intensity;

    if (mode == VC_MODE_WITNESS) {
        pitch_semitones    = vc_prng_float(pp, -10.0f, 10.0f);
        formant_factor     = vc_prng_float(pf, 0.5f, 1.8f);
        scramble_intensity = vc_prng_float(ps, 0.6f, 1.0f);
    } else {
        pitch_semitones    = vc_prng_float(pp, -3.0f, 3.0f);
        formant_factor     = vc_prng_float(pf, 0.85f, 1.15f);
        scramble_intensity = vc_prng_float(ps, 0.1f, 0.3f);
    }

    vc_prng_destroy(pp);
    vc_prng_destroy(pf);
    vc_prng_destroy(ps);

    float *step1 = NULL, *step2 = NULL, *result = NULL;
    size_t s1_len, s2_len, r_len;

    if (vc_dsp_pitch_shift(samples, num_samples, sample_rate,
                           pitch_semitones, &step1, &s1_len) != 0) goto fail;

    if (fabsf(formant_factor - 1.0f) > 0.01f) {
        if (vc_dsp_formant_shift(step1, s1_len, sample_rate,
                                 formant_factor, &step2, &s2_len) != 0) goto fail;
        free(step1);
        step1 = step2;
        s1_len = s2_len;
        step2 = NULL;
    }

    if (vc_dsp_spectral_scramble(step1, s1_len, sample_rate,
                                 scramble_intensity, &result, &r_len) != 0) goto fail;

    free(step1);

    normalize_rms(samples, num_samples, result, r_len);
    trim_edges(&result, &r_len);

    *out = result;
    *out_len = r_len;
    return 0;

fail:
    free(step1); free(step2);
    return -1;
}
