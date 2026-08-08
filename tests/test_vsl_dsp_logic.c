#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <math.h>
#include <float.h>
#include "vsl_dsp_logic.h"

static void test_VSL_Encode_Gain(void **state) {
    (void) state; /* unused */

    VSL_Parameter param = {
        .coeff_offset_A = 0.0f,
        .coeff_C1 = 1.0f,
        .log_factor = 1.0f,
        .curve_min_map = 0.0f,
        .curve_max_map = 1.0f,
        .freq_min_hz = 0.0f, /* unused */
        .freq_max_hz = 0.0f, /* unused */
        .dsp_param_id = 0,   /* unused */
        .max_encoded_int = 0 /* unused */
    };

    /* Test clamping and basic computation */
    assert_float_equal(VSL_Encode_Gain(0.5f, &param), 1.6487212707f, 1e-5f);
    assert_float_equal(VSL_Encode_Gain(0.0f, &param), 1.0f, 1e-5f); /* exp(0) = 1 */
    assert_float_equal(VSL_Encode_Gain(1.0f, &param), expf(1.0f), 1e-5f); /* exp(1) */
    assert_float_equal(VSL_Encode_Gain(-0.5f, &param), 1.0f, 1e-5f); /* clamped to 0 */
    assert_float_equal(VSL_Encode_Gain(1.5f, &param), expf(1.0f), 1e-5f); /* clamped to 1 */

    /* Test zero range */
    param.curve_max_map = param.curve_min_map;
    assert_float_equal(VSL_Encode_Gain(0.5f, &param), param.coeff_offset_A, 1e-5f);
}

static void test_VSL_Map_Frequency(void **state) {
    (void) state;

    VSL_Parameter param = {
        .coeff_offset_A = 0.0f, /* unused */
        .coeff_C1 = 0.0f,     /* unused */
        .log_factor = 0.0f,   /* unused */
        .curve_min_map = 0.0f,/* unused */
        .curve_max_map = 0.0f,/* unused */
        .freq_min_hz = 100.0f,
        .freq_max_hz = 400.0f,
        .dsp_param_id = 0,    /* unused */
        .max_encoded_int = 0  /* unused */
    };

    /* Test mapping: log2(100) + 0.5*(log2(400)-log2(100)) = log2(200) */
    assert_float_equal(VSL_Map_Frequency(0.0f, &param), 100.0f, 1e-3f);
    assert_float_equal(VSL_Map_Frequency(1.0f, &param), 400.0f, 1e-3f);
    assert_float_equal(VSL_Map_Frequency(0.5f, &param), 200.0f, 1e-3f);

    /* Test clamping */
    assert_float_equal(VSL_Map_Frequency(-0.5f, &param), 100.0f, 1e-3f);
    assert_float_equal(VSL_Map_Frequency(1.5f, &param), 400.0f, 1e-3f);

    /* Invalid frequencies */
    param.freq_min_hz = 0.0f;
    assert_float_equal(VSL_Map_Frequency(0.5f, &param), 0.0f, 1e-3f);
    param.freq_min_hz = 100.0f;
    param.freq_max_hz = 0.0f;
    assert_float_equal(VSL_Map_Frequency(0.5f, &param), 0.0f, 1e-3f);
}

static void test_VSL_Decode_Frequency(void **state) {
    (void) state;

    VSL_Parameter param = {
        .coeff_offset_A = 0.0f, /* unused */
        .coeff_C1 = 0.0f,     /* unused */
        .log_factor = 0.0f,   /* unused */
        .curve_min_map = 0.0f,/* unused */
        .curve_max_map = 0.0f,/* unused */
        .freq_min_hz = 100.0f,
        .freq_max_hz = 400.0f,
        .dsp_param_id = 0,    /* unused */
        .max_encoded_int = 0  /* unused */
    };

    /* Test decoding */
    assert_float_equal(VSL_Decode_Frequency(100.0f, &param), 0.0f, 1e-3f);
    assert_float_equal(VSL_Decode_Frequency(400.0f, &param), 1.0f, 1e-3f);
    assert_float_equal(VSL_Decode_Frequency(200.0f, &param), 0.5f, 1e-3f);

    /* Test clamping */
    assert_float_equal(VSL_Decode_Frequency(50.0f, &param), 0.0f, 1e-3f);
    assert_float_equal(VSL_Decode_Frequency(500.0f, &param), 1.0f, 1e-3f);

    /* Invalid frequencies */
    param.freq_min_hz = 0.0f;
    assert_float_equal(VSL_Decode_Frequency(200.0f, &param), 0.0f, 1e-3f);
    param.freq_min_hz = 100.0f;
    param.freq_max_hz = 0.0f;
    assert_float_equal(VSL_Decode_Frequency(200.0f, &param), 0.0f, 1e-3f);
}

static void test_VSL_Final_Encode_To_Int(void **state) {
    (void) state;

    VSL_Parameter param = {
        .coeff_offset_A = 0.0f, /* unused */
        .coeff_C1 = 0.0f,     /* unused */
        .log_factor = 0.0f,   /* unused */
        .curve_min_map = 0.0f,/* unused */
        .curve_max_map = 0.0f,/* unused */
        .freq_min_hz = 0.0f,  /* unused */
        .freq_max_hz = 0.0f,  /* unused */
        .dsp_param_id = 0,    /* unused */
        .max_encoded_int = 65535 /* max uint16 */
    };

    /* Test scaling: encoded_float = 0.75 -> 0.75 * 65535/1000 = 49.15125 -> round -> 49 */
    assert_int_equal(VSL_Final_Encode_To_Int(0.75f, &param), 49);

    /* Test clamping */
    assert_int_equal(VSL_Final_Encode_To_Int(1000.0f, &param), 65535);
    assert_int_equal(VSL_Final_Encode_To_Int(2000.0f, &param), 65535);
    assert_int_equal(VSL_Final_Encode_To_Int(-100.0f, &param), 0);

    /* Test zero max_encoded_int */
    param.max_encoded_int = 0;
    assert_int_equal(VSL_Final_Encode_To_Int(0.75f, &param), 0);
}

static void test_VSL_Decode_Gain_c1_zero(void **state) {
    (void) state;

    VSL_Parameter param = {
        .coeff_offset_A = 10.0f,
        .coeff_C1 = 0.0f,
        .log_factor = 1.0f,
        .curve_min_map = 0.2f,
        .curve_max_map = 0.8f,
        .freq_min_hz = 0.0f,
        .freq_max_hz = 0.0f,
        .dsp_param_id = 0,
        .max_encoded_int = 0
    };

    assert_float_equal(VSL_Decode_Gain(50.0f, &param), 0.2f, 1e-4f);
}

static void test_VSL_Decode_Gain_log_factor_zero(void **state) {
    (void) state;

    VSL_Parameter param = {
        .coeff_offset_A = 10.0f,
        .coeff_C1 = 20.0f,
        .log_factor = 0.0f,
        .curve_min_map = 0.2f,
        .curve_max_map = 0.8f,
        .freq_min_hz = 0.0f,
        .freq_max_hz = 0.0f,
        .dsp_param_id = 0,
        .max_encoded_int = 0
    };

    assert_float_equal(VSL_Decode_Gain(50.0f, &param), 0.2f, 1e-4f);
}

static void test_VSL_Decode_Gain_encoded_below_offset(void **state) {
    (void) state;

    VSL_Parameter param = {
        .coeff_offset_A = 10.0f,
        .coeff_C1 = 20.0f,
        .log_factor = 1.0f,
        .curve_min_map = 0.2f,
        .curve_max_map = 0.8f,
        .freq_min_hz = 0.0f,
        .freq_max_hz = 0.0f,
        .dsp_param_id = 0,
        .max_encoded_int = 0
    };

    float result = VSL_Decode_Gain(5.0f, &param);
    assert_float_equal(result, 0.2f, 1e-4f);
}

static void test_VSL_Decode_Gain_range_zero(void **state) {
    (void) state;

    VSL_Parameter param = {
        .coeff_offset_A = 10.0f,
        .coeff_C1 = 20.0f,
        .log_factor = 1.0f,
        .curve_min_map = 0.5f,
        .curve_max_map = 0.5f,
        .freq_min_hz = 0.0f,
        .freq_max_hz = 0.0f,
        .dsp_param_id = 0,
        .max_encoded_int = 0
    };

    assert_float_equal(VSL_Decode_Gain(50.0f, &param), 0.5f, 1e-4f);
}

static void test_VSL_Decode_Gain_roundtrip_mid(void **state) {
    (void) state;

    VSL_Parameter param = {
        .coeff_offset_A = -10.0f,
        .coeff_C1 = 20.0f,
        .log_factor = 4.60517f,
        .curve_min_map = 0.0f,
        .curve_max_map = 1.0f,
        .freq_min_hz = 0.0f,
        .freq_max_hz = 0.0f,
        .dsp_param_id = 0x1A01,
        .max_encoded_int = 65535
    };

    float encoded = VSL_Encode_Gain(0.5f, &param);
    float decoded = VSL_Decode_Gain(encoded, &param);
    assert_float_equal(decoded, 0.5f, 1e-4f);
}

static void test_VSL_Decode_Gain_roundtrip_extremes(void **state) {
    (void) state;

    VSL_Parameter param = {
        .coeff_offset_A = -10.0f,
        .coeff_C1 = 20.0f,
        .log_factor = 4.60517f,
        .curve_min_map = 0.0f,
        .curve_max_map = 1.0f,
        .freq_min_hz = 0.0f,
        .freq_max_hz = 0.0f,
        .dsp_param_id = 0x1A01,
        .max_encoded_int = 65535
    };

    float e0 = VSL_Encode_Gain(0.0f, &param);
    float e1 = VSL_Encode_Gain(1.0f, &param);
    assert_float_equal(VSL_Decode_Gain(e0, &param), 0.0f, 1e-4f);
    assert_float_equal(VSL_Decode_Gain(e1, &param), 1.0f, 1e-4f);
}

static void test_VSL_Decode_Gain_roundtrip_75(void **state) {
    (void) state;

    VSL_Parameter param = {
        .coeff_offset_A = -10.0f,
        .coeff_C1 = 20.0f,
        .log_factor = 4.60517f,
        .curve_min_map = 0.0f,
        .curve_max_map = 1.0f,
        .freq_min_hz = 0.0f,
        .freq_max_hz = 0.0f,
        .dsp_param_id = 0x1A01,
        .max_encoded_int = 65535
    };

    float encoded = VSL_Encode_Gain(0.75f, &param);
    float decoded = VSL_Decode_Gain(encoded, &param);
    assert_float_equal(decoded, 0.75f, 1e-4f);
}

static void test_VSL_Decode_Gain_custom_range_roundtrip(void **state) {
    (void) state;

    VSL_Parameter param = {
        .coeff_offset_A = 0.0f,
        .coeff_C1 = 1.0f,
        .log_factor = 1.0f,
        .curve_min_map = 0.2f,
        .curve_max_map = 0.8f,
        .freq_min_hz = 0.0f,
        .freq_max_hz = 0.0f,
        .dsp_param_id = 0,
        .max_encoded_int = 0
    };

    float l0 = 0.2f;
    float l1 = 0.8f;
    float lmid = 0.5f;

    float e0 = VSL_Encode_Gain(l0, &param);
    float e1 = VSL_Encode_Gain(l1, &param);
    float emid = VSL_Encode_Gain(lmid, &param);

    assert_float_equal(VSL_Decode_Gain(e0, &param), l0, 1e-4f);
    assert_float_equal(VSL_Decode_Gain(e1, &param), l1, 1e-4f);
    assert_float_equal(VSL_Decode_Gain(emid, &param), lmid, 1e-4f);
}

static void test_VSL_Decode_Gain_encoded_equals_offset(void **state) {
    (void) state;

    VSL_Parameter param = {
        .coeff_offset_A = -10.0f,
        .coeff_C1 = 20.0f,
        .log_factor = 4.60517f,
        .curve_min_map = 0.0f,
        .curve_max_map = 1.0f,
        .freq_min_hz = 0.0f,
        .freq_max_hz = 0.0f,
        .dsp_param_id = 0,
        .max_encoded_int = 0
    };

    float result = VSL_Decode_Gain(-10.0f, &param);
    assert_float_equal(result, 0.0f, 1e-4f);
}

static void test_VSL_Decode_Gain_clamps_output(void **state) {
    (void) state;

    VSL_Parameter param = {
        .coeff_offset_A = 0.0f,
        .coeff_C1 = 1.0f,
        .log_factor = 10.0f,
        .curve_min_map = 0.0f,
        .curve_max_map = 1.0f,
        .freq_min_hz = 0.0f,
        .freq_max_hz = 0.0f,
        .dsp_param_id = 0,
        .max_encoded_int = 0
    };

    float result = VSL_Decode_Gain(100000.0f, &param);
    assert_true(result >= 0.0f);
    assert_true(result <= 1.0f);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_VSL_Encode_Gain),
        cmocka_unit_test(test_VSL_Map_Frequency),
        cmocka_unit_test(test_VSL_Decode_Frequency),
        cmocka_unit_test(test_VSL_Final_Encode_To_Int),
        cmocka_unit_test(test_VSL_Decode_Gain_c1_zero),
        cmocka_unit_test(test_VSL_Decode_Gain_log_factor_zero),
        cmocka_unit_test(test_VSL_Decode_Gain_encoded_below_offset),
        cmocka_unit_test(test_VSL_Decode_Gain_range_zero),
        cmocka_unit_test(test_VSL_Decode_Gain_roundtrip_mid),
        cmocka_unit_test(test_VSL_Decode_Gain_roundtrip_extremes),
        cmocka_unit_test(test_VSL_Decode_Gain_roundtrip_75),
        cmocka_unit_test(test_VSL_Decode_Gain_custom_range_roundtrip),
        cmocka_unit_test(test_VSL_Decode_Gain_encoded_equals_offset),
        cmocka_unit_test(test_VSL_Decode_Gain_clamps_output),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}