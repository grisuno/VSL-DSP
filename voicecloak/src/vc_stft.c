#include "vc_stft.h"
#include "vc_fft.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

struct vc_stft_s {
    size_t fft_size;
    size_t hop_size;
    size_t nbins;
    float *window;
    float *win_sq_sum;
    float *buf_r;
    float *buf_i;
};

vc_stft_t *vc_stft_create(size_t fft_size, size_t hop_size) {
    vc_stft_t *st = (vc_stft_t *)malloc(sizeof(vc_stft_t));
    if (!st) return NULL;

    st->fft_size = fft_size;
    st->hop_size = hop_size;
    st->nbins    = fft_size / 2 + 1;

    st->window   = (float *)malloc(fft_size * sizeof(float));
    st->win_sq_sum = (float *)malloc(fft_size * sizeof(float));
    st->buf_r    = (float *)malloc(fft_size * sizeof(float));
    st->buf_i    = (float *)malloc(fft_size * sizeof(float));

    if (!st->window || !st->win_sq_sum || !st->buf_r || !st->buf_i) {
        vc_stft_destroy(st);
        return NULL;
    }

    size_t i;
    for (i = 0; i < fft_size; ++i) {
        st->window[i] = 0.5f * (1.0f - cosf(2.0f * (float)M_PI * (float)i / (float)(fft_size - 1)));
    }

    /* Compute overlap-add normalization for synthesis hop */
    memset(st->win_sq_sum, 0, fft_size * sizeof(float));
    /* Pre-compute for default analysis hop (caller can override for synthesis) */
    size_t pos;
    for (pos = 0; pos < fft_size; pos += hop_size) {
        for (i = 0; i < fft_size && (pos + i) < fft_size + fft_size; ++i) {
            float w = st->window[i];
            st->win_sq_sum[(pos + i) % fft_size] += w * w;
        }
    }

    return st;
}

void vc_stft_destroy(vc_stft_t *st) {
    if (!st) return;
    free(st->window);
    free(st->win_sq_sum);
    free(st->buf_r);
    free(st->buf_i);
    free(st);
}

size_t vc_stft_num_bins(const vc_stft_t *st) {
    return st ? st->nbins : 0;
}

int vc_stft_forward(vc_stft_t *st,
                    const float *samples, size_t num_samples,
                    float **mag, float **phase,
                    size_t *num_frames_out) {
    if (!st || !samples || !mag || !phase || !num_frames_out) return -1;

    size_t fft_n = st->fft_size;
    size_t hop   = st->hop_size;
    size_t nbins = st->nbins;

    if (num_samples + hop < fft_n) { *num_frames_out = 0; return 0; }

    size_t nframes = (num_samples - fft_n) / hop + 1;
    if (((num_samples - fft_n) % hop) != 0) nframes++;

    size_t total_bins = nframes * nbins;
    float *mag_out   = (float *)malloc(total_bins * sizeof(float));
    float *phase_out = (float *)malloc(total_bins * sizeof(float));
    if (!mag_out || !phase_out) { free(mag_out); free(phase_out); return -1; }

    size_t f;
    for (f = 0; f < nframes; ++f) {
        size_t offset = f * hop;
        memset(st->buf_r, 0, fft_n * sizeof(float));
        memset(st->buf_i, 0, fft_n * sizeof(float));

        size_t i;
        for (i = 0; i < fft_n && (offset + i) < num_samples; ++i) {
            st->buf_r[i] = samples[offset + i] * st->window[i];
        }

        vc_fft(fft_n, st->buf_r, st->buf_i, 0);

        size_t b;
        float *m = mag_out   + f * nbins;
        float *p = phase_out + f * nbins;
        for (b = 0; b < nbins; ++b) {
            m[b] = sqrtf(st->buf_r[b] * st->buf_r[b] + st->buf_i[b] * st->buf_i[b]);
            p[b] = atan2f(st->buf_i[b], st->buf_r[b]);
        }
    }

    *mag     = mag_out;
    *phase   = phase_out;
    *num_frames_out = nframes;
    return 0;
}

int vc_stft_inverse(vc_stft_t *st,
                    const float *mag, const float *phase,
                    size_t num_frames,
                    float *samples_out, size_t num_samples_out) {
    return vc_stft_inverse_hop(st, mag, phase, num_frames,
                               samples_out, num_samples_out, st->hop_size);
}

int vc_stft_inverse_hop(vc_stft_t *st,
                        const float *mag, const float *phase,
                        size_t num_frames,
                        float *samples_out, size_t num_samples_out,
                        size_t synth_hop) {
    if (!st || !mag || !phase || !samples_out) return -1;

    size_t fft_n = st->fft_size;
    size_t nbins = st->nbins;

    memset(samples_out, 0, num_samples_out * sizeof(float));

    /* scaled window for synthesis */
    float *synth_win = (float *)malloc(fft_n * sizeof(float));
    float *win_accum = (float *)calloc(num_samples_out, sizeof(float));
    if (!synth_win || !win_accum) { free(synth_win); free(win_accum); return -1; }

    size_t i;
    for (i = 0; i < fft_n; ++i) synth_win[i] = st->window[i];

    size_t f;
    for (f = 0; f < num_frames; ++f) {
        const float *m = mag   + f * nbins;
        const float *p = phase + f * nbins;

        /* Reconstruct complex spectrum */
        size_t b;
        for (b = 0; b < nbins; ++b) {
            st->buf_r[b] = m[b] * cosf(p[b]);
            st->buf_i[b] = m[b] * sinf(p[b]);
        }
        /* Conjugate symmetry for bins > nbins-1 */
        for (b = nbins; b < fft_n; ++b) {
            size_t conj_b = fft_n - b;
            st->buf_r[b] =  st->buf_r[conj_b];
            st->buf_i[b] = -st->buf_i[conj_b];
        }

        vc_fft(fft_n, st->buf_r, st->buf_i, 1);

        size_t offset = f * synth_hop;
        for (i = 0; i < fft_n && (offset + i) < num_samples_out; ++i) {
            samples_out[offset + i] += st->buf_r[i] * synth_win[i];
            win_accum[offset + i] += synth_win[i] * synth_win[i];
        }
    }

    /* COLA normalization with edge protection */
    for (i = 0; i < num_samples_out; ++i) {
        if (win_accum[i] > 0.01f)
            samples_out[i] /= win_accum[i];
        else
            samples_out[i] = 0.0f;
    }

    free(synth_win);
    free(win_accum);
    return 0;
}
