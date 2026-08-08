#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "vc_fft.h"

static void test_fft_identity(void **state) {
    (void)state;

    size_t n = 8;
    float real[8] = {1, 0, 0, 0, 0, 0, 0, 0};
    float imag[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    vc_fft(n, real, imag, 0);
    vc_fft(n, real, imag, 1);

    size_t i;
    for (i = 0; i < n; ++i) {
        assert_float_equal(real[i], i == 0 ? 1.0f : 0.0f, 1e-4f);
        assert_float_equal(imag[i], 0.0f, 1e-4f);
    }
}

static void test_fft_dc_signal(void **state) {
    (void)state;

    size_t n = 16;
    float *real = (float *)calloc(n, sizeof(float));
    float *imag = (float *)calloc(n, sizeof(float));
    size_t i;
    for (i = 0; i < n; ++i) real[i] = 0.5f;

    vc_fft(n, real, imag, 0);

    assert_float_equal(real[0], 0.5f * (float)n, 1e-4f);
    for (i = 1; i < n; ++i) {
        assert_float_equal(real[i], 0.0f, 1e-4f);
    }

    free(real);
    free(imag);
}

static void test_fft_sine(void **state) {
    (void)state;

    size_t n = 32;
    float *real = (float *)calloc(n, sizeof(float));
    float *imag = (float *)calloc(n, sizeof(float));
    /* 2 cycles of sine in n samples */
    size_t k = 2;
    size_t i;
    for (i = 0; i < n; ++i) {
        real[i] = sinf(2.0f * 3.14159265358979323846f * (float)(k * i) / (float)n);
    }

    vc_fft(n, real, imag, 0);

    float mag_k = sqrtf(real[k] * real[k] + imag[k] * imag[k]);
    float mag_other = 0.0f;
    for (i = 0; i < n; ++i) {
        if (i != k && i != n - k) {
            float m = sqrtf(real[i] * real[i] + imag[i] * imag[i]);
            if (m > mag_other) mag_other = m;
        }
    }
    assert_true(mag_k > mag_other * 10.0f);

    free(real);
    free(imag);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_fft_identity),
        cmocka_unit_test(test_fft_dc_signal),
        cmocka_unit_test(test_fft_sine),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
