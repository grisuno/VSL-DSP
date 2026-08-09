#include "vc_stream.h"
#include "vc_fft.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

struct vc_stream_s {
    size_t   fft_size;
    size_t   hop_size;
    size_t   nbins;
    uint32_t sample_rate;

    float   *window;      /* Hann analysis+synthesis window            */
    float    cola_gain;   /* steady-state overlap sum of window^2      */

    float   *in_fifo;     /* sliding analysis buffer (fft_size)        */
    float   *out_accum;   /* synthesis overlap accumulator (fft_size)  */
    float   *out_fifo;    /* ready output samples (hop_size)           */
    size_t   rover;       /* write cursor inside in_fifo               */

    float   *buf_r;       /* FFT work buffers (fft_size)               */
    float   *buf_i;
    float   *mag;         /* per-bin scratch (nbins)                   */
    float   *phase;
};

static int is_pow2(size_t v) {
    return v != 0 && (v & (v - 1)) == 0;
}

vc_stream_t *vc_stream_create(size_t fft_size, size_t hop_size,
                              uint32_t sample_rate) {
    if (!is_pow2(fft_size) || hop_size == 0 || sample_rate == 0) return NULL;
    if (fft_size % hop_size != 0) return NULL;
    size_t osamp = fft_size / hop_size;
    if (osamp != 2 && osamp != 4) return NULL;

    vc_stream_t *st = (vc_stream_t *)calloc(1, sizeof(*st));
    if (!st) return NULL;

    st->fft_size    = fft_size;
    st->hop_size    = hop_size;
    st->nbins       = fft_size / 2 + 1;
    st->sample_rate = sample_rate;

    st->window    = (float *)malloc(fft_size * sizeof(float));
    st->in_fifo   = (float *)calloc(fft_size, sizeof(float));
    st->out_accum = (float *)calloc(fft_size, sizeof(float));
    st->out_fifo  = (float *)calloc(hop_size, sizeof(float));
    st->buf_r     = (float *)malloc(fft_size * sizeof(float));
    st->buf_i     = (float *)malloc(fft_size * sizeof(float));
    st->mag       = (float *)malloc(st->nbins * sizeof(float));
    st->phase     = (float *)malloc(st->nbins * sizeof(float));

    if (!st->window || !st->in_fifo || !st->out_accum || !st->out_fifo ||
        !st->buf_r || !st->buf_i || !st->mag || !st->phase) {
        vc_stream_destroy(st);
        return NULL;
    }

    size_t i;
    for (i = 0; i < fft_size; ++i)
        st->window[i] = 0.5f * (1.0f - cosf(2.0f * (float)M_PI *
                                            (float)i / (float)(fft_size - 1)));

    /* Steady-state overlap sum of window^2, averaged over one hop so the
     * value is robust to numerical drift. For COLA-compliant Hann it is
     * constant across output positions; dividing by it makes passthrough
     * unity. */
    double acc = 0.0;
    size_t m, k;
    for (m = 0; m < hop_size; ++m) {
        double s = 0.0;
        for (k = 0; k < osamp; ++k) {
            size_t idx = m + k * hop_size;
            if (idx < fft_size) {
                double w = st->window[idx];
                s += w * w;
            }
        }
        acc += s;
    }
    st->cola_gain = (float)(acc / (double)hop_size);
    if (st->cola_gain <= 0.0f) st->cola_gain = 1.0f;

    st->rover = fft_size - hop_size;
    return st;
}

void vc_stream_destroy(vc_stream_t *st) {
    if (!st) return;
    free(st->window);
    free(st->in_fifo);
    free(st->out_accum);
    free(st->out_fifo);
    free(st->buf_r);
    free(st->buf_i);
    free(st->mag);
    free(st->phase);
    free(st);
}

size_t vc_stream_latency_samples(const vc_stream_t *st) {
    return st ? st->fft_size - st->hop_size : 0;
}

static void process_frame(vc_stream_t *st, vc_spectral_fn fn, void *user) {
    size_t N = st->fft_size;
    size_t nbins = st->nbins;
    size_t b, i;

    for (i = 0; i < N; ++i) {
        st->buf_r[i] = st->in_fifo[i] * st->window[i];
        st->buf_i[i] = 0.0f;
    }

    vc_fft(N, st->buf_r, st->buf_i, 0);

    for (b = 0; b < nbins; ++b) {
        float re = st->buf_r[b], im = st->buf_i[b];
        st->mag[b]   = sqrtf(re * re + im * im);
        st->phase[b] = atan2f(im, re);
    }

    if (fn)
        fn(st->mag, st->phase, nbins, st->sample_rate, st->hop_size, user);

    for (b = 0; b < nbins; ++b) {
        st->buf_r[b] = st->mag[b] * cosf(st->phase[b]);
        st->buf_i[b] = st->mag[b] * sinf(st->phase[b]);
    }
    for (b = nbins; b < N; ++b) {
        size_t conj_b = N - b;
        st->buf_r[b] =  st->buf_r[conj_b];
        st->buf_i[b] = -st->buf_i[conj_b];
    }

    vc_fft(N, st->buf_r, st->buf_i, 1);

    for (i = 0; i < N; ++i)
        st->out_accum[i] += st->buf_r[i] * st->window[i];

    for (i = 0; i < st->hop_size; ++i)
        st->out_fifo[i] = st->out_accum[i] / st->cola_gain;

    memmove(st->out_accum, st->out_accum + st->hop_size,
            (N - st->hop_size) * sizeof(float));
    memset(st->out_accum + (N - st->hop_size), 0,
           st->hop_size * sizeof(float));

    memmove(st->in_fifo, st->in_fifo + st->hop_size,
            (N - st->hop_size) * sizeof(float));
}

int vc_stream_process(vc_stream_t *st,
                      const float *in, float *out, size_t n,
                      vc_spectral_fn fn, void *user) {
    if (!st || !in || !out) return -1;

    size_t lat = st->fft_size - st->hop_size;
    size_t i;
    for (i = 0; i < n; ++i) {
        st->in_fifo[st->rover] = in[i];
        out[i] = st->out_fifo[st->rover - lat];
        st->rover++;
        if (st->rover >= st->fft_size) {
            st->rover = lat;
            process_frame(st, fn, user);
        }
    }
    return 0;
}
