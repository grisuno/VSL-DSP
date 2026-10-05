#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "vc_presets.h"
#include "vc_eq.h"
#include "vc_level.h"
#include "vc_stream.h"

#include <math.h>
#include <string.h>
#include <stdlib.h>

#define TEST_RATE 48000U
#define TEST_PI 3.14159265358979323846f

static float rms(const float *samples, size_t count) {
    double sum = 0.0;
    size_t i;
    for (i = 0; i < count; ++i)
        sum += (double)samples[i] * (double)samples[i];
    return (float)sqrt(sum / (double)count);
}

static void test_all_named_presets_resolve(void **state) {
    (void)state;
    static const char *const names[] = {
        "robot", "monster", "woman", "man", "space", "underwater",
        "church", "phaser"
    };
    static const vc_effect_kind_t expected_effects[] = {
        VC_EFFECT_METALLIC, VC_EFFECT_NONE, VC_EFFECT_NONE, VC_EFFECT_NONE,
        VC_EFFECT_SPACE, VC_EFFECT_UNDERWATER, VC_EFFECT_REVERB,
        VC_EFFECT_PHASER
    };
    size_t i;
    for (i = 0; i < sizeof(names) / sizeof(names[0]); ++i) {
        vc_preset_t preset;
        assert_int_equal(vc_preset_lookup(names[i], &preset), 0);
        assert_string_equal(preset.name, names[i]);
        assert_true(preset.cloak.pitch_ratio > 0.0f);
        assert_true(preset.cloak.formant_factor > 0.0f);
        assert_true(preset.cloak.scramble_intensity >= 0.0f);
        assert_true(preset.cloak.scramble_intensity <= 1.0f);
        assert_int_equal(preset.effects.kind, expected_effects[i]);
        assert_true(preset.saturation_drive >= 0.0f);
        assert_true(preset.saturation_drive <= VC_LEVEL_MAX_SATURATION_DRIVE);
        if (i != 0U) {
            assert_int_equal(preset.cloak.robotize, 0);
            assert_float_equal(preset.saturation_drive, 0.0f, 0.0f);
            assert_float_equal(preset.eq.highpass_hz, 0.0f, 0.0f);
            assert_float_equal(preset.eq.presence_gain_db, 0.0f, 0.0f);
        }
    }
}

static void test_robot_preset_is_clear_robotization(void **state) {
    (void)state;
    vc_preset_t robot;
    assert_int_equal(vc_preset_lookup("robot", &robot), 0);
    assert_int_equal(robot.cloak.robotize, 1);
    assert_float_equal(robot.cloak.scramble_intensity, 0.0f, 0.0f);
    assert_float_equal(robot.cloak.pitch_ratio, 1.0f, 1e-6f);
    assert_int_equal(robot.effects.kind, VC_EFFECT_METALLIC);
    assert_true(robot.effects.delay_ms >= 6.0f &&
                robot.effects.delay_ms <= 10.0f);
    assert_true(robot.effects.feedback >= 0.5f &&
                robot.effects.feedback <= 0.7f);
    assert_true(robot.effects.rate_hz >= 80.0f &&
                robot.effects.rate_hz <= 150.0f);
    assert_true(robot.effects.ring_amount < 0.5f);
    assert_true(robot.eq.highpass_hz > 0.0f);
    assert_true(robot.eq.presence_hz >= 2000.0f &&
                robot.eq.presence_hz <= 4000.0f);
    assert_true(robot.eq.presence_gain_db >= 4.0f &&
                robot.eq.presence_gain_db <= 6.0f);
    assert_true(robot.saturation_drive > 0.0f);
}

static void test_voice_profiles_are_distinct(void **state) {
    (void)state;
    vc_preset_t woman, man, monster;
    assert_int_equal(vc_preset_lookup("woman", &woman), 0);
    assert_int_equal(vc_preset_lookup("man", &man), 0);
    assert_int_equal(vc_preset_lookup("monster", &monster), 0);
    assert_true(woman.cloak.pitch_ratio > 1.0f);
    assert_true(man.cloak.pitch_ratio < 1.0f);
    assert_true(monster.cloak.pitch_ratio < man.cloak.pitch_ratio);
    assert_true(woman.cloak.formant_factor > man.cloak.formant_factor);
}

static void test_lookup_rejects_unknown_and_invalid_output(void **state) {
    (void)state;
    vc_preset_t preset;
    assert_int_not_equal(vc_preset_lookup("not-a-preset", &preset), 0);
    assert_int_not_equal(vc_preset_lookup("robot", NULL), 0);
}

static void test_preset_pipeline_on_deterministic_noise(void **state) {
    (void)state;
    static const char *const names[] = {
        "robot", "monster", "woman", "man", "space", "underwater",
        "church", "phaser"
    };
    vc_level_config_t level_config;
    vc_level_config_defaults(&level_config);
    uint32_t random_state = 0x13579BDFU;
    float block[256];
    size_t preset_index, i;
    float ceiling = powf(10.0f, level_config.ceiling_dbfs / 20.0f);

    for (preset_index = 0;
         preset_index < sizeof(names) / sizeof(names[0]);
         ++preset_index) {
        vc_preset_t preset;
        assert_int_equal(vc_preset_lookup(names[preset_index], &preset), 0);
        level_config.saturation_drive = preset.saturation_drive;
        vc_effects_t *effects = vc_effects_create(48000U, &preset.effects);
        vc_eq_t *eq = vc_eq_create(48000U, &preset.eq);
        vc_level_t *level = vc_level_create(48000U, &level_config);
        assert_non_null(effects);
        assert_non_null(eq);
        assert_non_null(level);

        size_t block_index;
        for (block_index = 0; block_index < 100U; ++block_index) {
            for (i = 0; i < sizeof(block) / sizeof(block[0]); ++i) {
                random_state = random_state * 1664525U + 1013904223U;
                block[i] = 2.0f * (float)(random_state >> 8) /
                           16777215.0f - 1.0f;
            }
            assert_int_equal(vc_effects_process(effects, block,
                                                sizeof(block) / sizeof(block[0])), 0);
            assert_int_equal(vc_eq_process(eq, block,
                                           sizeof(block) / sizeof(block[0])), 0);
            assert_int_equal(vc_level_process(level, block,
                                              sizeof(block) / sizeof(block[0])), 0);
            for (i = 0; i < sizeof(block) / sizeof(block[0]); ++i) {
                assert_true(isfinite(block[i]));
                assert_true(fabsf(block[i]) <= ceiling + 1e-6f);
            }
        }
        vc_level_destroy(level);
        vc_eq_destroy(eq);
        vc_effects_destroy(effects);
    }
}

static void test_full_live_chain_tracks_rms_and_ceiling(void **state) {
    (void)state;
    const size_t count = 2U * (size_t)TEST_RATE;
    const size_t block_size = 256U;
    float *input = (float *)malloc(count * sizeof(float));
    float *output = (float *)malloc(count * sizeof(float));
    assert_non_null(input);
    assert_non_null(output);
    size_t i;
    for (i = 0; i < count; ++i)
        input[i] = 0.05f * sinf(2.0f * TEST_PI * 220.0f *
                               (float)i / (float)TEST_RATE);

    vc_effects_params_t effect_params = {0};
    vc_stream_t *stream = vc_stream_create(1024U, block_size, TEST_RATE);
    vc_effects_t *effects = vc_effects_create(TEST_RATE, &effect_params);
    vc_level_config_t level_config;
    vc_level_config_defaults(&level_config);
    vc_level_t *level = vc_level_create(TEST_RATE, &level_config);
    assert_non_null(stream);
    assert_non_null(effects);
    assert_non_null(level);

    for (i = 0; i < count; i += block_size) {
        size_t amount = count - i < block_size ? count - i : block_size;
        assert_int_equal(vc_stream_process(stream, input + i, output + i,
                                           amount, NULL, NULL), 0);
        assert_int_equal(vc_effects_process(effects, output + i, amount), 0);
        assert_int_equal(vc_level_process(level, output + i, amount), 0);
    }

    size_t skip = count / 2U + vc_stream_latency_samples(stream);
    float output_rms = rms(output + skip, count - skip);
    float output_dbfs = 20.0f * log10f(output_rms);
    assert_true(fabsf(output_dbfs - level_config.target_dbfs) < 2.0f);
    float ceiling = powf(10.0f, level_config.ceiling_dbfs / 20.0f);
    for (i = 0; i < count; ++i)
        assert_true(fabsf(output[i]) <= ceiling + 1e-6f);

    vc_level_destroy(level);
    vc_effects_destroy(effects);
    vc_stream_destroy(stream);
    free(input);
    free(output);
}

static void test_witness_loss_is_compensated_in_live_chain(void **state) {
    (void)state;
    const size_t count = 2U * (size_t)TEST_RATE;
    const size_t block_size = 256U;
    float *input = (float *)malloc(count * sizeof(float));
    float *output = (float *)malloc(count * sizeof(float));
    assert_non_null(input);
    assert_non_null(output);
    size_t i;
    for (i = 0; i < count; ++i) {
        double value = 0.0;
        int harmonic;
        for (harmonic = 1; harmonic <= 12; ++harmonic)
            value += sin(2.0 * (double)TEST_PI * 120.0 * (double)harmonic *
                         (double)i / (double)TEST_RATE) / (double)harmonic;
        input[i] = (float)(value * 0.15);
    }

    vc_rt_params_t transform_params = {
        vc_rt_semitones_to_ratio(-8.0f), 0.5f, 1.0f, 0
    };
    vc_effects_params_t effect_params = {0};
    vc_stream_t *stream = vc_stream_create(1024U, block_size, TEST_RATE);
    vc_rt_ctx_t *transform = vc_rt_create(513U, transform_params);
    vc_effects_t *effects = vc_effects_create(TEST_RATE, &effect_params);
    vc_level_config_t level_config;
    vc_level_config_defaults(&level_config);
    vc_level_t *level = vc_level_create(TEST_RATE, &level_config);
    assert_non_null(stream);
    assert_non_null(transform);
    assert_non_null(effects);
    assert_non_null(level);

    for (i = 0; i < count; i += block_size) {
        size_t amount = count - i < block_size ? count - i : block_size;
        assert_int_equal(vc_stream_process(stream, input + i, output + i,
                                           amount, vc_rt_transform, transform), 0);
        assert_int_equal(vc_effects_process(effects, output + i, amount), 0);
        assert_int_equal(vc_level_process(level, output + i, amount), 0);
    }

    size_t skip = count / 2U + vc_stream_latency_samples(stream);
    float output_rms = rms(output + skip, count - skip);
    float output_dbfs = 20.0f * log10f(output_rms);
    assert_true(fabsf(output_dbfs - level_config.target_dbfs) < 3.0f);

    vc_level_destroy(level);
    vc_effects_destroy(effects);
    vc_rt_destroy(transform);
    vc_stream_destroy(stream);
    free(input);
    free(output);
}

static void test_robot_live_chain_is_loud_and_bounded(void **state) {
    (void)state;
    const size_t count = 2U * (size_t)TEST_RATE;
    const size_t block_size = 256U;
    float *input = (float *)malloc(count * sizeof(float));
    float *output = (float *)malloc(count * sizeof(float));
    assert_non_null(input);
    assert_non_null(output);
    size_t i;
    for (i = 0; i < count; ++i) {
        double value = 0.0;
        int harmonic;
        for (harmonic = 1; harmonic <= 12; ++harmonic)
            value += sin(2.0 * (double)TEST_PI * 140.0 * (double)harmonic *
                         (double)i / (double)TEST_RATE) / (double)harmonic;
        input[i] = (float)(value * 0.1);
    }

    vc_preset_t robot;
    assert_int_equal(vc_preset_lookup("robot", &robot), 0);
    vc_level_config_t level_config;
    vc_level_config_defaults(&level_config);
    level_config.saturation_drive = robot.saturation_drive;
    vc_stream_t *stream = vc_stream_create(1024U, block_size, TEST_RATE);
    vc_rt_ctx_t *transform = vc_rt_create(513U, robot.cloak);
    vc_effects_t *effects = vc_effects_create(TEST_RATE, &robot.effects);
    vc_eq_t *eq = vc_eq_create(TEST_RATE, &robot.eq);
    vc_level_t *level = vc_level_create(TEST_RATE, &level_config);
    assert_non_null(stream);
    assert_non_null(transform);
    assert_non_null(effects);
    assert_non_null(eq);
    assert_non_null(level);

    for (i = 0; i < count; i += block_size) {
        size_t amount = count - i < block_size ? count - i : block_size;
        assert_int_equal(vc_stream_process(stream, input + i, output + i,
                                           amount, vc_rt_transform, transform), 0);
        assert_int_equal(vc_effects_process(effects, output + i, amount), 0);
        assert_int_equal(vc_eq_process(eq, output + i, amount), 0);
        assert_int_equal(vc_level_process(level, output + i, amount), 0);
    }

    float ceiling = powf(10.0f, level_config.ceiling_dbfs / 20.0f);
    for (i = 0; i < count; ++i) {
        assert_true(isfinite(output[i]));
        assert_true(fabsf(output[i]) <= ceiling + 1e-6f);
    }
    size_t skip = count / 2U + vc_stream_latency_samples(stream);
    float output_dbfs = 20.0f * log10f(rms(output + skip, count - skip));
    assert_true(output_dbfs > level_config.target_dbfs + 2.0f);

    vc_level_destroy(level);
    vc_eq_destroy(eq);
    vc_effects_destroy(effects);
    vc_rt_destroy(transform);
    vc_stream_destroy(stream);
    free(input);
    free(output);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_all_named_presets_resolve),
        cmocka_unit_test(test_robot_preset_is_clear_robotization),
        cmocka_unit_test(test_voice_profiles_are_distinct),
        cmocka_unit_test(test_lookup_rejects_unknown_and_invalid_output),
        cmocka_unit_test(test_preset_pipeline_on_deterministic_noise),
        cmocka_unit_test(test_full_live_chain_tracks_rms_and_ceiling),
        cmocka_unit_test(test_witness_loss_is_compensated_in_live_chain),
        cmocka_unit_test(test_robot_live_chain_is_loud_and_bounded),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
