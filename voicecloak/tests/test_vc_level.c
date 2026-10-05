#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "vc_level.h"

#include <math.h>
#include <stdint.h>
#include <stdlib.h>

#define TEST_RATE 48000U
#define PI_F 3.14159265358979323846f

static float rms(const float *samples, size_t count) {
    double sum = 0.0;
    size_t i;
    for (i = 0; i < count; ++i)
        sum += (double)samples[i] * (double)samples[i];
    return (float)sqrt(sum / (double)count);
}

static void test_default_config_and_rms_target(void **state) {
    (void)state;
    vc_level_config_t cfg;
    vc_level_config_defaults(&cfg);
    assert_true(fabsf(cfg.target_dbfs - (-18.0f)) < 0.001f);
    assert_true(fabsf(cfg.max_gain_db - 12.0f) < 0.001f);
    assert_true(fabsf(cfg.ceiling_dbfs - (-1.0f)) < 0.001f);
    assert_true(fabsf(cfg.attack_ms - 10.0f) < 0.001f);
    assert_true(fabsf(cfg.release_ms - 250.0f) < 0.001f);
    assert_true(cfg.agc_enabled != 0);
    assert_float_equal(cfg.saturation_drive, 0.0f, 0.0f);

    const size_t count = 2U * (size_t)TEST_RATE;
    float samples[2U * (size_t)TEST_RATE];
    size_t i;
    for (i = 0; i < count; ++i)
        samples[i] = 0.05f * sinf(2.0f * PI_F * 440.0f *
                                  (float)i / (float)TEST_RATE);

    vc_level_t *level = vc_level_create(TEST_RATE, &cfg);
    assert_non_null(level);
    assert_int_equal(vc_level_process(level, samples, count), 0);

    float measured = rms(samples + count / 2U, count / 2U);
    float measured_db = 20.0f * log10f(measured);
    assert_true(fabsf(measured_db - cfg.target_dbfs) < 1.0f);
    assert_true(vc_level_current_gain_db(level) <= cfg.max_gain_db + 0.01f);
    vc_level_destroy(level);
}

static void test_limiter_ceiling_and_agc_off(void **state) {
    (void)state;
    vc_level_config_t cfg;
    vc_level_config_defaults(&cfg);
    cfg.agc_enabled = 0;

    float samples[256];
    size_t i;
    for (i = 0; i < sizeof(samples) / sizeof(samples[0]); ++i)
        samples[i] = (i & 1U) == 0U ? 1.5f : -1.5f;

    vc_level_t *level = vc_level_create(TEST_RATE, &cfg);
    assert_non_null(level);
    assert_int_equal(vc_level_process(level, samples,
                                      sizeof(samples) / sizeof(samples[0])), 0);
    float ceiling = powf(10.0f, cfg.ceiling_dbfs / 20.0f);
    for (i = 0; i < sizeof(samples) / sizeof(samples[0]); ++i)
        assert_true(fabsf(samples[i]) <= ceiling + 1e-6f);
    vc_level_destroy(level);
}

static void test_gain_changes_smoothly_between_periods(void **state) {
    (void)state;
    vc_level_config_t cfg;
    vc_level_config_defaults(&cfg);
    const size_t quiet_count = (size_t)TEST_RATE;
    float *quiet = (float *)malloc(quiet_count * sizeof(float));
    assert_non_null(quiet);
    size_t i;
    for (i = 0; i < quiet_count; ++i)
        quiet[i] = 0.03f * sinf(2.0f * PI_F * 220.0f *
                                (float)i / (float)TEST_RATE);
    vc_level_t *level = vc_level_create(TEST_RATE, &cfg);
    assert_non_null(level);
    assert_int_equal(vc_level_process(level, quiet, quiet_count), 0);
    float before_db = vc_level_current_gain_db(level);

    float loud[TEST_RATE / 1000U];
    for (i = 0; i < TEST_RATE / 1000U; ++i)
        loud[i] = 0.8f * sinf(2.0f * PI_F * 220.0f *
                              (float)(quiet_count + i) / (float)TEST_RATE);
    assert_int_equal(vc_level_process(level, loud,
                                      TEST_RATE / 1000U), 0);
    float after_db = vc_level_current_gain_db(level);
    assert_true(after_db < before_db);
    assert_true(after_db > before_db - 2.0f);

    free(quiet);
    vc_level_destroy(level);
}

static void test_silence_stays_silent(void **state) {
    (void)state;
    vc_level_config_t cfg;
    vc_level_config_defaults(&cfg);
    float samples[512] = {0.0f};
    vc_level_t *level = vc_level_create(TEST_RATE, &cfg);
    assert_non_null(level);
    assert_int_equal(vc_level_process(level, samples,
                                      sizeof(samples) / sizeof(samples[0])), 0);
    size_t i;
    for (i = 0; i < sizeof(samples) / sizeof(samples[0]); ++i)
        assert_float_equal(samples[i], 0.0f, 0.0f);
    vc_level_destroy(level);
}

static void test_non_finite_block_fails_closed(void **state) {
    (void)state;
    vc_level_config_t cfg;
    vc_level_config_defaults(&cfg);
    float samples[4] = {0.1f, NAN, 0.2f, 0.3f};
    vc_level_t *level = vc_level_create(TEST_RATE, &cfg);
    assert_non_null(level);
    assert_int_not_equal(vc_level_process(level, samples, 4U), 0);
    size_t i;
    for (i = 0; i < 4U; ++i) assert_float_equal(samples[i], 0.0f, 0.0f);
    vc_level_destroy(level);
}

static void test_invalid_rate_and_excessive_input_fail_closed(void **state) {
    (void)state;
    vc_level_config_t cfg;
    vc_level_config_defaults(&cfg);
    assert_null(vc_level_create(1000U, &cfg));
    cfg.target_dbfs = -0.5f;
    assert_null(vc_level_create(TEST_RATE, &cfg));
    vc_level_config_defaults(&cfg);
    float sample = VC_AUDIO_MAX_INTERNAL_SAMPLE + 1.0f;
    vc_level_t *level = vc_level_create(TEST_RATE, &cfg);
    assert_non_null(level);
    assert_int_not_equal(vc_level_process(level, &sample, 1U), 0);
    assert_float_equal(sample, 0.0f, 0.0f);
    vc_level_destroy(level);
}

static void run_constant_level(float drive, float input, float *output) {
    vc_level_config_t cfg;
    vc_level_config_defaults(&cfg);
    cfg.agc_enabled = 0;
    cfg.saturation_drive = drive;
    vc_level_t *level = vc_level_create(TEST_RATE, &cfg);
    assert_non_null(level);
    *output = input;
    assert_int_equal(vc_level_process(level, output, 1U), 0);
    vc_level_destroy(level);
}

static void test_saturation_curve_and_bypass(void **state) {
    (void)state;
    float output = 0.0f;
    run_constant_level(0.0f, 0.1f, &output);
    assert_float_equal(output, 0.1f, 1e-7f);

    run_constant_level(2.0f, 0.1f, &output);
    float expected = tanhf(0.2f) / tanhf(2.0f);
    assert_float_equal(output, expected, 1e-6f);
    assert_true(output > 0.19f);

    run_constant_level(2.0f, -0.1f, &output);
    assert_float_equal(output, -expected, 1e-6f);
}

static void test_saturation_raises_loudness_within_ceiling(void **state) {
    (void)state;
    const size_t count = 2U * (size_t)TEST_RATE;
    float *dry = (float *)malloc(count * sizeof(float));
    float *driven = (float *)malloc(count * sizeof(float));
    assert_non_null(dry);
    assert_non_null(driven);
    size_t i;
    for (i = 0; i < count; ++i) {
        dry[i] = 0.05f * sinf(2.0f * PI_F * 220.0f *
                              (float)i / (float)TEST_RATE);
        driven[i] = dry[i];
    }
    vc_level_config_t cfg;
    vc_level_config_defaults(&cfg);
    vc_level_t *plain = vc_level_create(TEST_RATE, &cfg);
    cfg.saturation_drive = 2.0f;
    vc_level_t *saturated = vc_level_create(TEST_RATE, &cfg);
    assert_non_null(plain);
    assert_non_null(saturated);
    for (i = 0; i < count; i += 256U) {
        assert_int_equal(vc_level_process(plain, dry + i, 256U), 0);
        assert_int_equal(vc_level_process(saturated, driven + i, 256U), 0);
    }
    size_t skip = count / 2U;
    float gain_db = 20.0f * log10f(rms(driven + skip, count - skip) /
                                   rms(dry + skip, count - skip));
    assert_true(gain_db > 3.0f);
    float ceiling = powf(10.0f, cfg.ceiling_dbfs / 20.0f);
    for (i = 0; i < count; ++i)
        assert_true(fabsf(driven[i]) <= ceiling + 1e-6f);
    vc_level_destroy(plain);
    vc_level_destroy(saturated);
    free(dry);
    free(driven);
}

static void test_invalid_saturation_drive_rejected(void **state) {
    (void)state;
    vc_level_config_t cfg;
    vc_level_config_defaults(&cfg);
    cfg.saturation_drive = -0.1f;
    assert_null(vc_level_create(TEST_RATE, &cfg));
    cfg.saturation_drive = VC_LEVEL_MAX_SATURATION_DRIVE + 0.1f;
    assert_null(vc_level_create(TEST_RATE, &cfg));
    cfg.saturation_drive = NAN;
    assert_null(vc_level_create(TEST_RATE, &cfg));
    cfg.saturation_drive = VC_LEVEL_MAX_SATURATION_DRIVE;
    vc_level_t *level = vc_level_create(TEST_RATE, &cfg);
    assert_non_null(level);
    vc_level_destroy(level);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_default_config_and_rms_target),
        cmocka_unit_test(test_limiter_ceiling_and_agc_off),
        cmocka_unit_test(test_gain_changes_smoothly_between_periods),
        cmocka_unit_test(test_silence_stays_silent),
        cmocka_unit_test(test_non_finite_block_fails_closed),
        cmocka_unit_test(test_invalid_rate_and_excessive_input_fail_closed),
        cmocka_unit_test(test_saturation_curve_and_bypass),
        cmocka_unit_test(test_saturation_raises_loudness_within_ceiling),
        cmocka_unit_test(test_invalid_saturation_drive_rejected),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
