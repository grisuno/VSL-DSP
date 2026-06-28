# VSL DSP Logic Specification

## Module: vsl_dsp_logic

### Purpose
Provides pure mathematical functions for encoding and decoding DSP parameters for the PreSonus AudioBox 22 VSL, based on reverse-engineered Android driver functions.

### Functions

#### VSL_Encode_Gain
- **Description**: Encodes a linear gain value (0.0-1.0) to the DSP's exponential gain curve.
- **Inputs**:
  - `linear_value`: float, the linear gain (clamped to 0.0-1.0).
  - `param`: pointer to `VSL_Parameter` containing the curve coefficients.
- **Output**: float, the encoded gain value.
- **Error Handling**: 
  - If `param->curve_max_map == param->curve_min_map`, returns `param->coeff_offset_A` to avoid division by zero.
- **Source**: Reverse-engineered from `FUN_00132c90` in the Android driver.

#### VSL_Map_Frequency
- **Description**: Maps a linear position (0.0-1.0) to a frequency using a logarithmic curve (base 2).
- **Inputs**:
  - `linear_position`: float, the linear position (clamped to 0.0-1.0).
  - `param`: pointer to `VSL_Parameter` containing frequency range.
- **Output**: float, the frequency in Hz.
- **Error Handling**:
  - If `param->freq_min_hz <= 0.0f` or `param->freq_max_hz <= 0.0f`, returns 0.0f (invalid for log).
- **Source**: Reverse-engineered from `FUN_00132d00` in the Android driver.

#### VSL_Decode_Frequency
- **Description**: Decodes a frequency (Hz) from the DSP to a linear position (0.0-1.0) using the inverse logarithmic curve.
- **Inputs**:
  - `freq_hz_value`: float, the frequency in Hz (clamped to the parameter's range).
  - `param`: pointer to `VSL_Parameter` containing frequency range.
- **Output**: float, the linear position (0.0-1.0).
- **Error Handling**:
  - If `param->freq_min_hz <= 0.0f` or `param->freq_max_hz <= 0.0f`, returns 0.0f.
  - If the logarithmic range is zero (to avoid division by zero), returns 0.0f.
- **Source**: Reverse-engineered from `FUN_00132da8` in the Android driver.

#### VSL_Final_Encode_To_Int
- **Description**: Converts a float encoded value (assumed to be in the range 0.0-1000.0) to an integer for transmission to the DSP.
- **Inputs**:
  - `encoded_float`: float, the encoded value from `VSL_Encode_Gain` or `VSL_Map_Frequency`.
  - `param`: pointer to `VSL_Parameter` containing `max_encoded_int` (the maximum integer value, e.g., 65535).
- **Output**: uint32_t, the integer value to send (clamped to 0..max_encoded_int).
- **Error Handling**:
  - If `param->max_encoded_int == 0`, returns 0.
  - Values are scaled, rounded, and clamped to the valid range.
- **Note**: The scaling factor (1000.0) is based on the hypothesis that the DSP uses a float range of 0.0-1000.0. This constant should be verified against the disassembly.
- **Source**: Placeholder implementation; the exact scaling factor and rounding method (roundf) are based on the hypothesis and the validated test case (0.75 -> 40793 for max_encoded_int=65535? Wait, note: the test in the code uses 0.75 -> 49, which is inconsistent with the validated test in the CLAUDE.md (0.75 -> 40793). This discrepancy must be resolved by extracting the correct constant from the disassembly.

### Data Structure: VSL_Parameter
- `dsp_param_id`: uint32_t, the DSP parameter ID (e.g., 0x1A01 for gain).
- `max_encoded_int`: uint32_t, the maximum integer value for the parameter (e.g., 65535 for a 16-bit value).
- `coeff_offset_A`: float, offset coefficient in the gain curve.
- `coeff_C1`: float, coefficient for the exponential term.
- `log_factor`: float, factor for the exponential (log factor).
- `curve_min_map`: float, minimum value of the input curve mapping.
- `curve_max_map`: float, maximum value of the input curve mapping.
- `freq_min_hz`: float, minimum frequency for mapping (Hz).
- `freq_max_hz`: float, maximum frequency for mapping (Hz).

### Constants
- `VSL_INV_LN2`: 1.0f / ln(2) ≈ 1.442695f, used to convert natural log to base-2 log.

### Assumptions and Open Issues
- The exact scaling factor in `VSL_Final_Encode_To_Int` (currently 1000.0) is not yet verified from the disassembly. This is a blocker and must be resolved by extracting the constant from the Android driver (see CLAUDE.md blockers).
- The `VSL_Parameter` structure fields are annotated with comments indicating their likely offsets in the original structure (from the disassembly). These annotations should be verified and updated as needed.

### Safety
- All functions are pure (no side effects, no static state).
- Input validation is performed to avoid undefined operations (division by zero, log of non-positive).
- No dynamic memory allocation.
- No use of unsafe functions (e.g., strcpy, sprintf).

### Testing
- Unit tests are provided in `tests/test_vsl_dsp_logic.c` using CMocka.
- Tests cover normal operation, clamping, and error conditions.
- The test for `VSL_Final_Encode_To_Int` uses the hypothesis (0.75 -> 49 with max_encoded_int=65535) and must be updated once the true scaling factor is known.