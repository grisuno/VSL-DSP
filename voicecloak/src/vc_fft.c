#include "vc_fft.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

static unsigned int bit_reverse(unsigned int x, unsigned int bits) {
    unsigned int r = 0;
    unsigned int i;
    for (i = 0; i < bits; ++i) {
        r = (r << 1) | (x & 1);
        x >>= 1;
    }
    return r;
}

static void bit_reverse_reorder(size_t n, float *real, float *imag) {
    unsigned int bits = 0;
    size_t temp = n;
    while (temp > 1) { ++bits; temp >>= 1; }

    unsigned int i;
    for (i = 0; i < (unsigned int)n; ++i) {
        unsigned int j = bit_reverse(i, bits);
        if (j > i) {
            float tr = real[i], ti = imag[i];
            real[i] = real[j]; imag[i] = imag[j];
            real[j] = tr;     imag[j] = ti;
        }
    }
}

void vc_fft(size_t n, float *real, float *imag, int inverse) {
    float *work_r = (float *)malloc(n * sizeof(float));
    float *work_i = (float *)malloc(n * sizeof(float));
    if (!work_r || !work_i) { free(work_r); free(work_i); return; }

    size_t i;
    for (i = 0; i < n; ++i) { work_r[i] = real[i]; work_i[i] = imag[i]; }
    bit_reverse_reorder(n, work_r, work_i);

    size_t len;
    for (len = 2; len <= n; len <<= 1) {
        float angle = 2.0f * (float)M_PI / (float)len;
        if (inverse) angle = -angle;

        size_t half = len >> 1;
        size_t j;
        for (j = 0; j < half; ++j) {
            float w_r, w_i;
            if (j == 0) { w_r = 1.0f; w_i = 0.0f; }
            else if (j * 2 == half) { w_r = 0.0f; w_i = inverse ? -1.0f : 1.0f; }
            else { w_r = cosf(angle * (float)j); w_i = sinf(angle * (float)j); }

            size_t k;
            for (k = j; k < n; k += len) {
                size_t k2 = k + half;
                float u_r = work_r[k];
                float u_i = work_i[k];
                float v_r = work_r[k2] * w_r - work_i[k2] * w_i;
                float v_i = work_r[k2] * w_i + work_i[k2] * w_r;
                work_r[k]  = u_r + v_r;  work_i[k]  = u_i + v_i;
                work_r[k2] = u_r - v_r;  work_i[k2] = u_i - v_i;
            }
        }
    }

    float scale = inverse ? 1.0f / (float)n : 1.0f;
    for (i = 0; i < n; ++i) { real[i] = work_r[i] * scale; imag[i] = work_i[i] * scale; }

    free(work_r);
    free(work_i);
}
