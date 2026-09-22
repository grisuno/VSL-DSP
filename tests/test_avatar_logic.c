#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <math.h>
#include <cmocka.h>

#include "avatar_logic.h"

static const avatar_cfg_t kCfg = {
    .silence_db = -50.0f,
    .zcr_thr = 0.25f,
    .hf_thr = 0.60f,
    .hold_ms = 120
};

static void test_rms_silence(void **s)
{
    (void)s;
    float x[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
    assert_float_equal(avatar_rms_f32(x, 4), 0.0f, 1e-6f);
    assert_true(avatar_rms_to_dbfs(0.0f) <= -119.0f);
    assert_true(avatar_rms_f32(NULL, 4) == 0.0f);
    assert_true(avatar_rms_f32(x, 0) == 0.0f);
}

static void test_rms_vowel(void **s)
{
    (void)s;
    float x[4] = { 0.5f, -0.5f, 0.5f, -0.5f };
    assert_float_equal(avatar_rms_f32(x, 4), 0.5f, 1e-6f);
    assert_float_equal(avatar_rms_to_dbfs(0.5f), -6.0206f, 1e-3f);
}

static void test_zcr(void **s)
{
    (void)s;
    float flat[4] = { 0.5f, 0.5f, 0.5f, 0.5f };
    float alt[4] = { 0.5f, -0.5f, 0.5f, -0.5f };
    assert_float_equal(avatar_zcr_f32(flat, 4), 0.0f, 1e-6f);
    assert_float_equal(avatar_zcr_f32(alt, 4), 1.0f, 1e-6f);
    assert_true(avatar_zcr_f32(NULL, 4) == 0.0f);
    assert_true(avatar_zcr_f32(flat, 0) == 0.0f);
    assert_true(avatar_zcr_f32(flat, 1) == 0.0f);
}

static void test_hf_ratio(void **s)
{
    (void)s;
    float smooth[8] = { 0.0f, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f };
    float noisy[8] = { 0.5f, -0.5f, 0.5f, -0.5f, 0.5f, -0.5f, 0.5f, -0.5f };
    float hf_smooth = avatar_hf_ratio_f32(smooth, 8);
    float hf_noisy = avatar_hf_ratio_f32(noisy, 8);
    assert_true(hf_noisy > hf_smooth);
    assert_true(hf_smooth < 0.60f);
    assert_true(hf_noisy > 0.60f);
    assert_true(avatar_hf_ratio_f32(NULL, 8) == 0.0f);
}

static void test_classify_silence(void **s)
{
    (void)s;
    assert_int_equal(avatar_classify(-70.0f, 0.9f, 1.5f, &kCfg), AVATAR_CLOSED);
    assert_int_equal(avatar_classify(-50.01f, 0.0f, 0.0f, &kCfg), AVATAR_CLOSED);
    assert_int_equal(avatar_classify(-70.0f, 0.0f, 0.0f, NULL), AVATAR_CLOSED);
}

static void test_classify_vowel_open(void **s)
{
    (void)s;
    assert_int_equal(avatar_classify(-20.0f, 0.08f, 0.25f, &kCfg), AVATAR_OPEN);
}

static void test_classify_sibilant(void **s)
{
    (void)s;
    assert_int_equal(avatar_classify(-25.0f, 0.45f, 0.90f, &kCfg), AVATAR_SIBILANT);
}

static void test_classify_borderline_needs_both_gates(void **s)
{
    (void)s;
    assert_int_equal(avatar_classify(-25.0f, 0.45f, 0.30f, &kCfg), AVATAR_OPEN);
    assert_int_equal(avatar_classify(-25.0f, 0.10f, 0.90f, &kCfg), AVATAR_OPEN);
}

static void test_smooth_hold(void **s)
{
    (void)s;
    avatar_smooth_t sm;
    avatar_smooth_init(&sm, AVATAR_CLOSED, 0, kCfg.hold_ms);
    assert_int_equal(avatar_smooth(&sm, AVATAR_OPEN, 0), AVATAR_OPEN);
    assert_int_equal(avatar_smooth(&sm, AVATAR_CLOSED, 30), AVATAR_OPEN);
    assert_int_equal(avatar_smooth(&sm, AVATAR_CLOSED, 150), AVATAR_CLOSED);
}

static void test_smooth_sibilant_instant(void **s)
{
    (void)s;
    avatar_smooth_t sm;
    avatar_smooth_init(&sm, AVATAR_OPEN, 0, kCfg.hold_ms);
    assert_int_equal(avatar_smooth(&sm, AVATAR_SIBILANT, 10), AVATAR_SIBILANT);
    assert_int_equal(avatar_smooth(&sm, AVATAR_OPEN, 20), AVATAR_OPEN);
    assert_int_equal(avatar_smooth(NULL, AVATAR_OPEN, 20), AVATAR_CLOSED);
}

static void test_smooth_init_null(void **s)
{
    (void)s;
    avatar_smooth_init(NULL, AVATAR_OPEN, 0, kCfg.hold_ms);
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_rms_silence),
        cmocka_unit_test(test_rms_vowel),
        cmocka_unit_test(test_zcr),
        cmocka_unit_test(test_hf_ratio),
        cmocka_unit_test(test_classify_silence),
        cmocka_unit_test(test_classify_vowel_open),
        cmocka_unit_test(test_classify_sibilant),
        cmocka_unit_test(test_classify_borderline_needs_both_gates),
        cmocka_unit_test(test_smooth_hold),
        cmocka_unit_test(test_smooth_sibilant_instant),
        cmocka_unit_test(test_smooth_init_null),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
