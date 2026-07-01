/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * audiobox_vsl userspace unit tests (CMocka)
 *
 * Exercises the pure, kernel-independent portion of the audiobox_vsl
 * public API: the supported model table and the audiobox_lookup_model
 * helper. The kernel-only parts of the header (probe, disconnect, the
 * snd_audiobox_vsl_init declaration) are guarded by __KERNEL__ and
 * are not compiled in this userspace test.
 *
 * BDD mapping (see spec/audiobox_vsl.md):
 *   Scenario "model name lookup is total"
 *   Scenario "every supported model is detected" (table shape)
 *   Scenario "unknown product from same vendor is ignored" (NULL)
 */

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>

#include "audiobox_vsl.h"

static void test_vendor_id_is_presonus(void **state)
{
    (void)state;
    assert_int_equal(AUDIOBOX_VENDOR_ID, 0x194fU);
}

static void test_supported_models_table_shape(void **state)
{
    (void)state;

    assert_int_equal(audiobox_models_count, 3U);

    const audiobox_model_info_t *m = audiobox_models;
    assert_int_equal(m[0].pid, 0x0101U);
    assert_string_equal(m[0].product_name, "AudioBox 22 VSL");
    assert_int_equal(m[1].pid, 0x0102U);
    assert_string_equal(m[1].product_name, "AudioBox 44 VSL");
    assert_int_equal(m[2].pid, 0x0103U);
    assert_string_equal(m[2].product_name, "AudioBox 1818 VSL");
}

static void test_model_pids_match_table(void **state)
{
    (void)state;

    assert_int_equal((uint16_t)AUDIOBOX_MODEL_22_VSL, 0x0101U);
    assert_int_equal((uint16_t)AUDIOBOX_MODEL_44_VSL, 0x0102U);
    assert_int_equal((uint16_t)AUDIOBOX_MODEL_1818_VSL, 0x0103U);
}

static void test_lookup_returns_22_vsl(void **state)
{
    (void)state;

    const audiobox_model_info_t *m = audiobox_lookup_model(0x0101U);
    assert_non_null(m);
    assert_int_equal(m->pid, 0x0101U);
    assert_string_equal(m->product_name, "AudioBox 22 VSL");
}

static void test_lookup_returns_44_vsl(void **state)
{
    (void)state;

    const audiobox_model_info_t *m = audiobox_lookup_model(0x0102U);
    assert_non_null(m);
    assert_int_equal(m->pid, 0x0102U);
    assert_string_equal(m->product_name, "AudioBox 44 VSL");
}

static void test_lookup_returns_1818_vsl(void **state)
{
    (void)state;

    const audiobox_model_info_t *m = audiobox_lookup_model(0x0103U);
    assert_non_null(m);
    assert_int_equal(m->pid, 0x0103U);
    assert_string_equal(m->product_name, "AudioBox 1818 VSL");
}

static void test_lookup_returns_null_for_unknown_pid(void **state)
{
    (void)state;

    assert_null(audiobox_lookup_model(0x0000U));
    assert_null(audiobox_lookup_model(0xFFFFU));
    assert_null(audiobox_lookup_model(0x9999U));
    assert_null(audiobox_lookup_model(0x0104U));
}

static void test_lookup_handles_full_pid_range(void **state)
{
    (void)state;

    const uint16_t probes[] = {
        0x0000U, 0x0001U, 0x00FFU, 0x0100U, 0x0101U, 0x0102U, 0x0103U,
        0x0104U, 0x7FFFU, 0x8000U, 0xFFFEU, 0xFFFFU
    };
    const size_t n = sizeof(probes) / sizeof(probes[0]);

    for (size_t i = 0; i < n; ++i) {
        const audiobox_model_info_t *m = audiobox_lookup_model(probes[i]);
        if (probes[i] == 0x0101U || probes[i] == 0x0102U || probes[i] == 0x0103U) {
            assert_non_null(m);
        } else {
            assert_null(m);
        }
    }
}

static void test_table_pids_are_unique(void **state)
{
    (void)state;

    for (size_t i = 0; i < audiobox_models_count; ++i) {
        for (size_t j = i + 1; j < audiobox_models_count; ++j) {
            assert_int_not_equal(audiobox_models[i].pid, audiobox_models[j].pid);
        }
    }
}

static void test_table_product_names_non_empty(void **state)
{
    (void)state;

    for (size_t i = 0; i < audiobox_models_count; ++i) {
        assert_non_null(audiobox_models[i].product_name);
        assert_true(audiobox_models[i].product_name[0] != '\0');
    }
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_vendor_id_is_presonus),
        cmocka_unit_test(test_supported_models_table_shape),
        cmocka_unit_test(test_model_pids_match_table),
        cmocka_unit_test(test_lookup_returns_22_vsl),
        cmocka_unit_test(test_lookup_returns_44_vsl),
        cmocka_unit_test(test_lookup_returns_1818_vsl),
        cmocka_unit_test(test_lookup_returns_null_for_unknown_pid),
        cmocka_unit_test(test_lookup_handles_full_pid_range),
        cmocka_unit_test(test_table_pids_are_unique),
        cmocka_unit_test(test_table_product_names_non_empty),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
