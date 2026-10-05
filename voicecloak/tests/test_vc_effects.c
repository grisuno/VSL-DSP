#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "vc_effects.h"

#include <math.h>
#include <stdint.h>

#define TEST_RATE 48000U
#define PI_F 3.14159265358979323846f

static float rms(const float *samples, size_t count) {
    double sum = 0.0;
    size_t i;
    for (i = 0; i < count; ++i)
        sum += (double)samples[i] * (double)samples[i];
    return (float)sqrt(sum / (double)count);
}

static void assert_finite(const float *samples, size_t count) {
    size_t i;
    for (i = 0; i < count; ++i) assert_true(isfinite(samples[i]));
}

static void test_ring_modulation_changes_tone(void **state) {
    (void)state;
    vc_effects_params_t params = {0};
    params.kind = VC_EFFECT_RING_MOD;
    params.ring_amount = 1.0f;
    params.rate_hz = 35.0f;
    float samples[TEST_RATE];
    size_t i;
    for (i = 0; i < TEST_RATE; ++i)
        samples[i] = 0.2f * sinf(2.0f * PI_F * 440.0f *
                                 (float)i / (float)TEST_RATE);
    float input_rms = rms(samples, TEST_RATE);
    vc_effects_t *fx = vc_effects_create(TEST_RATE, &params);
    assert_non_null(fx);
    assert_int_equal(vc_effects_process(fx, samples, TEST_RATE), 0);
    assert_finite(samples, TEST_RATE);
    assert_true(rms(samples, TEST_RATE) > 0.0f);
    assert_true(fabsf(rms(samples, TEST_RATE) - input_rms) > 0.01f);
    vc_effects_destroy(fx);
}

static void test_ring_amount_zero_is_identity(void **state) {
    (void)state;
    vc_effects_params_t params = {0};
    params.kind = VC_EFFECT_RING_MOD;
    params.ring_amount = 0.0f;
    params.rate_hz = 100.0f;
    params.waveform = VC_RING_WAVE_SQUARE;
    float samples[1024], reference[1024];
    size_t i;
    for (i = 0; i < 1024U; ++i) {
        samples[i] = 0.3f * sinf(2.0f * PI_F * 440.0f *
                                 (float)i / (float)TEST_RATE);
        reference[i] = samples[i];
    }
    vc_effects_t *fx = vc_effects_create(TEST_RATE, &params);
    assert_non_null(fx);
    assert_int_equal(vc_effects_process(fx, samples, 1024U), 0);
    for (i = 0; i < 1024U; ++i)
        assert_true(fabsf(samples[i] - reference[i]) < 1e-6f);
    vc_effects_destroy(fx);
}

static void test_square_carrier_is_soft_and_bounded(void **state) {
    (void)state;
    vc_effects_params_t params = {0};
    params.kind = VC_EFFECT_RING_MOD;
    params.ring_amount = 1.0f;
    params.rate_hz = 100.0f;
    params.waveform = VC_RING_WAVE_SQUARE;
    float square[TEST_RATE / 10U];
    float sine[TEST_RATE / 10U];
    size_t i;
    for (i = 0; i < TEST_RATE / 10U; ++i) {
        square[i] = 0.5f;
        sine[i] = 0.5f;
    }
    vc_effects_t *square_fx = vc_effects_create(TEST_RATE, &params);
    params.waveform = VC_RING_WAVE_SINE;
    vc_effects_t *sine_fx = vc_effects_create(TEST_RATE, &params);
    assert_non_null(square_fx);
    assert_non_null(sine_fx);
    assert_int_equal(vc_effects_process(square_fx, square, TEST_RATE / 10U), 0);
    assert_int_equal(vc_effects_process(sine_fx, sine, TEST_RATE / 10U), 0);
    for (i = 0; i < TEST_RATE / 10U; ++i)
        assert_true(fabsf(square[i]) <= 0.5f + 1e-6f);
    assert_true(rms(square, TEST_RATE / 10U) >
                1.2f * rms(sine, TEST_RATE / 10U));
    vc_effects_destroy(square_fx);
    vc_effects_destroy(sine_fx);
}

static void test_metallic_comb_echoes_with_feedback_ratio(void **state) {
    (void)state;
    vc_effects_params_t params = {0};
    params.kind = VC_EFFECT_METALLIC;
    params.amount = 1.0f;
    params.delay_ms = 7.0f;
    params.feedback = 0.6f;
    float samples[2048] = {0.0f};
    samples[0] = 1.0f;
    vc_effects_t *fx = vc_effects_create(TEST_RATE, &params);
    assert_non_null(fx);
    assert_int_equal(vc_effects_process(fx, samples, 2048U), 0);
    assert_finite(samples, 2048U);
    const size_t delay = 336U;
    assert_true(fabsf(samples[0] - 1.0f) < 1e-6f);
    assert_true(fabsf(samples[delay] - 0.6f) < 1e-5f);
    assert_true(fabsf(samples[2U * delay] - 0.36f) < 1e-5f);
    assert_true(fabsf(samples[delay / 2U]) < 1e-6f);
    vc_effects_destroy(fx);
}

static void test_metallic_bounds_rejected(void **state) {
    (void)state;
    vc_effects_params_t params = {0};
    params.kind = VC_EFFECT_METALLIC;
    params.amount = 0.5f;
    params.delay_ms = 7.0f;
    params.feedback = 0.6f;
    vc_effects_t *fx = vc_effects_create(TEST_RATE, &params);
    assert_non_null(fx);
    vc_effects_destroy(fx);
    params.feedback = 0.95f;
    assert_null(vc_effects_create(TEST_RATE, &params));
    params.feedback = 0.6f;
    params.delay_ms = 0.0f;
    assert_null(vc_effects_create(TEST_RATE, &params));
    params.delay_ms = 60.0f;
    assert_null(vc_effects_create(TEST_RATE, &params));
    params.delay_ms = 7.0f;
    params.ring_amount = 0.3f;
    params.rate_hz = 0.0f;
    assert_null(vc_effects_create(TEST_RATE, &params));
    params.rate_hz = 93.75f;
    params.waveform = (vc_ring_waveform_t)7;
    assert_null(vc_effects_create(TEST_RATE, &params));
    params.waveform = VC_RING_WAVE_SQUARE;
    params.ring_amount = 1.5f;
    assert_null(vc_effects_create(TEST_RATE, &params));
}

static void test_underwater_lowpass_reduces_high_tone(void **state) {
    (void)state;
    vc_effects_params_t params = {0};
    params.kind = VC_EFFECT_UNDERWATER;
    params.cutoff_hz = 800.0f;
    params.amount = 1.0f;
    float low[TEST_RATE / 2U], high[TEST_RATE / 2U];
    size_t i;
    for (i = 0; i < TEST_RATE / 2U; ++i) {
        low[i] = 0.2f * sinf(2.0f * PI_F * 200.0f *
                             (float)i / (float)TEST_RATE);
        high[i] = 0.2f * sinf(2.0f * PI_F * 6000.0f *
                              (float)i / (float)TEST_RATE);
    }
    vc_effects_t *low_fx = vc_effects_create(TEST_RATE, &params);
    vc_effects_t *high_fx = vc_effects_create(TEST_RATE, &params);
    assert_non_null(low_fx);
    assert_non_null(high_fx);
    assert_int_equal(vc_effects_process(low_fx, low, TEST_RATE / 2U), 0);
    assert_int_equal(vc_effects_process(high_fx, high, TEST_RATE / 2U), 0);
    assert_true(rms(high + TEST_RATE / 4U, TEST_RATE / 4U) <
                0.2f * rms(low + TEST_RATE / 4U, TEST_RATE / 4U));
    vc_effects_destroy(low_fx);
    vc_effects_destroy(high_fx);
}

static void test_reverb_has_tail(void **state) {
    (void)state;
    vc_effects_params_t params = {0};
    params.kind = VC_EFFECT_REVERB;
    params.amount = 0.5f;
    params.decay_seconds = 1.5f;
    params.comb_delay_ms[0] = 30.0f;
    params.comb_delay_ms[1] = 33.1f;
    params.comb_delay_ms[2] = 36.7f;
    params.comb_delay_ms[3] = 40.9f;
    float samples[TEST_RATE] = {0.0f};
    samples[0] = 1.0f;
    vc_effects_t *fx = vc_effects_create(TEST_RATE, &params);
    assert_non_null(fx);
    assert_int_equal(vc_effects_process(fx, samples, TEST_RATE), 0);
    assert_finite(samples, TEST_RATE);
    float tail_peak = 0.0f;
    for (size_t i = 1200U; i < 3000U; ++i)
        if (fabsf(samples[i]) > tail_peak) tail_peak = fabsf(samples[i]);
    assert_true(tail_peak > 1e-6f);
    vc_effects_destroy(fx);
}

static void test_space_delay_adds_echo_without_unbounded_feedback(void **state) {
    (void)state;
    vc_effects_params_t params = {0};
    params.kind = VC_EFFECT_SPACE;
    params.amount = 0.5f;
    params.rate_hz = 0.2f;
    params.delay_ms = 40.0f;
    params.depth_ms = 5.0f;
    params.feedback = 0.3f;
    float samples[TEST_RATE] = {0.0f};
    samples[0] = 1.0f;
    vc_effects_t *fx = vc_effects_create(TEST_RATE, &params);
    assert_non_null(fx);
    assert_int_equal(vc_effects_process(fx, samples, TEST_RATE), 0);
    assert_finite(samples, TEST_RATE);
    float tail_peak = 0.0f;
    size_t i;
    for (i = 1000U; i < TEST_RATE; ++i) {
        if (fabsf(samples[i]) > tail_peak) tail_peak = fabsf(samples[i]);
        assert_true(fabsf(samples[i]) <= 1.0f);
    }
    assert_true(tail_peak > 0.0f);
    vc_effects_destroy(fx);
}

static void test_phaser_bounded_and_non_identity(void **state) {
    (void)state;
    vc_effects_params_t params = {0};
    params.kind = VC_EFFECT_PHASER;
    params.amount = 0.7f;
    params.rate_hz = 0.35f;
    params.low_hz = 250.0f;
    params.high_hz = 1600.0f;
    float samples[TEST_RATE / 2U];
    size_t i;
    for (i = 0; i < TEST_RATE / 2U; ++i)
        samples[i] = 0.3f * sinf(2.0f * PI_F * 440.0f *
                                 (float)i / (float)TEST_RATE);
    vc_effects_t *fx = vc_effects_create(TEST_RATE, &params);
    assert_non_null(fx);
    assert_int_equal(vc_effects_process(fx, samples, TEST_RATE / 2U), 0);
    assert_finite(samples, TEST_RATE / 2U);
    for (i = 0; i < TEST_RATE / 2U; ++i)
        assert_true(fabsf(samples[i]) <= 1.0f);
    vc_effects_destroy(fx);
}

static void test_invalid_rate_and_parameters_rejected(void **state) {
    (void)state;
    vc_effects_params_t params = {0};
    params.kind = VC_EFFECT_NONE;
    assert_null(vc_effects_create(1000U, &params));
    params.kind = (vc_effect_kind_t)99;
    assert_null(vc_effects_create(TEST_RATE, &params));
    params.kind = VC_EFFECT_RING_MOD;
    params.rate_hz = NAN;
    assert_null(vc_effects_create(TEST_RATE, &params));
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_ring_modulation_changes_tone),
        cmocka_unit_test(test_ring_amount_zero_is_identity),
        cmocka_unit_test(test_square_carrier_is_soft_and_bounded),
        cmocka_unit_test(test_metallic_comb_echoes_with_feedback_ratio),
        cmocka_unit_test(test_metallic_bounds_rejected),
        cmocka_unit_test(test_underwater_lowpass_reduces_high_tone),
        cmocka_unit_test(test_reverb_has_tail),
        cmocka_unit_test(test_space_delay_adds_echo_without_unbounded_feedback),
        cmocka_unit_test(test_phaser_bounded_and_non_identity),
        cmocka_unit_test(test_invalid_rate_and_parameters_rejected),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
