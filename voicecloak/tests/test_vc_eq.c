#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "vc_eq.h"

#include <math.h>
#include <stdint.h>
#include <stdlib.h>

#define TEST_RATE 48000U
#define PI_F 3.14159265358979323846f

static const vc_eq_params_t robot_eq = {
    .highpass_hz = 100.0f,
    .presence_hz = 3000.0f,
    .presence_gain_db = 5.0f,
    .presence_q = 1.0f
};

static float tone_gain_db(const vc_eq_params_t *params, float frequency) {
    const size_t count = (size_t)TEST_RATE;
    float *samples = (float *)malloc(count * sizeof(float));
    assert_non_null(samples);
    size_t i;
    for (i = 0; i < count; ++i)
        samples[i] = 0.25f * sinf(2.0f * PI_F * frequency *
                                  (float)i / (float)TEST_RATE);
    vc_eq_t *eq = vc_eq_create(TEST_RATE, params);
    assert_non_null(eq);
    assert_int_equal(vc_eq_process(eq, samples, count), 0);
    double sum = 0.0;
    for (i = count / 2U; i < count; ++i) {
        assert_true(isfinite(samples[i]));
        sum += (double)samples[i] * (double)samples[i];
    }
    vc_eq_destroy(eq);
    free(samples);
    double out_rms = sqrt(sum / (double)(count - count / 2U));
    return (float)(20.0 * log10(out_rms / (0.25 / sqrt(2.0))));
}

static void test_highpass_removes_rumble(void **state) {
    (void)state;
    assert_true(tone_gain_db(&robot_eq, 40.0f) < -12.0f);
}

static void test_presence_peak_boosts_consonant_band(void **state) {
    (void)state;
    float presence = tone_gain_db(&robot_eq, 3000.0f);
    assert_true(fabsf(presence - 5.0f) < 0.5f);
    float mid = tone_gain_db(&robot_eq, 1000.0f);
    assert_true(mid > -1.0f && mid < 3.0f);
}

static void test_zero_params_bypass(void **state) {
    (void)state;
    vc_eq_params_t params = {0};
    float samples[512], reference[512];
    size_t i;
    for (i = 0; i < 512U; ++i) {
        samples[i] = 0.3f * sinf(2.0f * PI_F * 50.0f *
                                 (float)i / (float)TEST_RATE);
        reference[i] = samples[i];
    }
    vc_eq_t *eq = vc_eq_create(TEST_RATE, &params);
    assert_non_null(eq);
    assert_int_equal(vc_eq_process(eq, samples, 512U), 0);
    for (i = 0; i < 512U; ++i)
        assert_float_equal(samples[i], reference[i], 0.0f);
    vc_eq_destroy(eq);
}

static void test_invalid_params_rejected(void **state) {
    (void)state;
    vc_eq_params_t params = robot_eq;
    assert_null(vc_eq_create(1000U, &params));
    assert_null(vc_eq_create(TEST_RATE, NULL));
    params.highpass_hz = -1.0f;
    assert_null(vc_eq_create(TEST_RATE, &params));
    params.highpass_hz = 24000.0f;
    assert_null(vc_eq_create(TEST_RATE, &params));
    params = robot_eq;
    params.presence_gain_db = VC_EQ_MAX_GAIN_DB + 1.0f;
    assert_null(vc_eq_create(TEST_RATE, &params));
    params = robot_eq;
    params.presence_q = 0.0f;
    assert_null(vc_eq_create(TEST_RATE, &params));
    params = robot_eq;
    params.presence_hz = 0.0f;
    assert_null(vc_eq_create(TEST_RATE, &params));
    params = robot_eq;
    params.presence_hz = NAN;
    assert_null(vc_eq_create(TEST_RATE, &params));
}

static void test_bad_samples_fail_closed(void **state) {
    (void)state;
    float samples[4] = {0.1f, INFINITY, 0.2f, 0.3f};
    vc_eq_t *eq = vc_eq_create(TEST_RATE, &robot_eq);
    assert_non_null(eq);
    assert_int_not_equal(vc_eq_process(eq, samples, 4U), 0);
    size_t i;
    for (i = 0; i < 4U; ++i) assert_float_equal(samples[i], 0.0f, 0.0f);
    float loud = VC_AUDIO_MAX_INTERNAL_SAMPLE + 1.0f;
    assert_int_not_equal(vc_eq_process(eq, &loud, 1U), 0);
    assert_float_equal(loud, 0.0f, 0.0f);
    assert_int_not_equal(vc_eq_process(NULL, samples, 4U), 0);
    assert_int_equal(vc_eq_process(eq, NULL, 0U), 0);
    vc_eq_destroy(eq);
    vc_eq_destroy(NULL);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_highpass_removes_rumble),
        cmocka_unit_test(test_presence_peak_boosts_consonant_band),
        cmocka_unit_test(test_zero_params_bypass),
        cmocka_unit_test(test_invalid_params_rejected),
        cmocka_unit_test(test_bad_samples_fail_closed),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
