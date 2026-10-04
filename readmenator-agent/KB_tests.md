# Subsystem: tests

## tests/test_audiobox_vsl.c
- Layer: testing
- Doc: SPDX-License-Identifier: GPL-2.0-or-later
- Language: c
- Symbols:
  - `test_supported_models_table_shape` (function, line 31) `static void test_supported_models_table_shape(void **state)`
  - `test_model_pids_match_table` (function, line 46) `static void test_model_pids_match_table(void **state)`
  - `test_lookup_returns_22_vsl` (function, line 55) `static void test_lookup_returns_22_vsl(void **state)`
  - `test_lookup_returns_44_vsl` (function, line 65) `static void test_lookup_returns_44_vsl(void **state)`
  - `test_lookup_returns_1818_vsl` (function, line 75) `static void test_lookup_returns_1818_vsl(void **state)`
  - `test_lookup_returns_null_for_unknown_pid` (function, line 85) `static void test_lookup_returns_null_for_unknown_pid(void **state)`
  - `test_lookup_handles_full_pid_range` (function, line 95) `static void test_lookup_handles_full_pid_range(void **state)`
  - `test_table_pids_are_unique` (function, line 115) `static void test_table_pids_are_unique(void **state)`
  - `test_table_product_names_non_empty` (function, line 126) `static void test_table_product_names_non_empty(void **state)`
  - `main` (function, line 136) `int main(void)`
- Depends on: `audiobox_vsl.h`

## tests/test_avatar_logic.c
- Layer: testing
- Language: c
- Symbols:
  - `test_rms_silence` (function, line 17) `static void test_rms_silence(void **s)`
  - `test_rms_vowel` (function, line 27) `static void test_rms_vowel(void **s)`
  - `test_zcr` (function, line 35) `static void test_zcr(void **s)`
  - `test_hf_ratio` (function, line 47) `static void test_hf_ratio(void **s)`
  - `test_classify_silence` (function, line 60) `static void test_classify_silence(void **s)`
  - `test_classify_vowel_open` (function, line 68) `static void test_classify_vowel_open(void **s)`
  - `test_classify_sibilant` (function, line 74) `static void test_classify_sibilant(void **s)`
  - `test_classify_borderline_needs_both_gates` (function, line 80) `static void test_classify_borderline_needs_both_gates(void **s)`
  - `test_smooth_hold` (function, line 87) `static void test_smooth_hold(void **s)`
  - `test_smooth_sibilant_instant` (function, line 97) `static void test_smooth_sibilant_instant(void **s)`
  - `test_smooth_init_null` (function, line 107) `static void test_smooth_init_null(void **s)`
  - `main` (function, line 113) `int main(void)`
- Depends on: `avatar/avatar_logic.h`

## tests/test_vsl_dsp_logic.c
- Layer: testing
- Language: c
- Symbols:
  - `test_VSL_Encode_Gain` (function, line 9) `static void test_VSL_Encode_Gain(void **state)`
  - `test_VSL_Map_Frequency` (function, line 36) `static void test_VSL_Map_Frequency(void **state)`
  - `test_VSL_Decode_Frequency` (function, line 68) `static void test_VSL_Decode_Frequency(void **state)`
  - `test_VSL_Final_Encode_To_Int` (function, line 100) `static void test_VSL_Final_Encode_To_Int(void **state)`
  - `test_VSL_Decode_Gain_c1_zero` (function, line 128) `static void test_VSL_Decode_Gain_c1_zero(void **state)`
  - `test_VSL_Decode_Gain_log_factor_zero` (function, line 146) `static void test_VSL_Decode_Gain_log_factor_zero(void **state)`
  - `test_VSL_Decode_Gain_encoded_below_offset` (function, line 164) `static void test_VSL_Decode_Gain_encoded_below_offset(void **state)`
  - `test_VSL_Decode_Gain_range_zero` (function, line 183) `static void test_VSL_Decode_Gain_range_zero(void **state)`
  - `test_VSL_Decode_Gain_roundtrip_mid` (function, line 201) `static void test_VSL_Decode_Gain_roundtrip_mid(void **state)`
  - `test_VSL_Decode_Gain_roundtrip_extremes` (function, line 221) `static void test_VSL_Decode_Gain_roundtrip_extremes(void **state)`
  - `test_VSL_Decode_Gain_roundtrip_75` (function, line 242) `static void test_VSL_Decode_Gain_roundtrip_75(void **state)`
  - `test_VSL_Decode_Gain_custom_range_roundtrip` (function, line 262) `static void test_VSL_Decode_Gain_custom_range_roundtrip(void **state)`
  - `test_VSL_Decode_Gain_encoded_equals_offset` (function, line 290) `static void test_VSL_Decode_Gain_encoded_equals_offset(void **state)`
  - `test_VSL_Decode_Gain_clamps_output` (function, line 309) `static void test_VSL_Decode_Gain_clamps_output(void **state)`
  - `main` (function, line 329) `int main(void)`
