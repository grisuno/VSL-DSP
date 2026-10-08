# Subsystem: tests

## tests/bdd_driver_gate.sh
- Doc: BDD hardware gate for audiobox_vsl.
- Layer: infrastructure
- Language: sh
- Symbols:
  - `ok` (function, line 29)
  - `bad` (function, line 30)

## tests/test_audiobox_vsl.c
- Layer: testing
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
  - `test_version_string_is_release` (function, line 136) `static void test_version_string_is_release(void **state)`
  - `test_primary_interface_announces_once` (function, line 143) `static void test_primary_interface_announces_once(void **state)`
  - `main` (function, line 155) `int main(void)`
- Depends on: `audiobox_vsl.h`
