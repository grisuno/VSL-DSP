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
- **Description**: Converts a float encoded value to a 16-bit integer for transmission to the DSP.
- **Inputs**:
  - `encoded_float`: float, the encoded value from `VSL_Encode_Gain` or `VSL_Map_Frequency`.
  - `param`: pointer to `VSL_Parameter` containing `max_encoded_int` (the maximum integer value, e.g., 65535 for the 2-byte encoded value slot).
- **Output**: uint16_t, the integer value to send (clamped to 0..max_encoded_int).
- **Error Handling**:
  - If `param->max_encoded_int == 0`, returns 0.
  - Values are scaled, rounded with `roundf`, and clamped to the valid range.
- **Scale**: `encoded_float * (max_encoded_int / 1000.0f)`, where `VSL_MAX_ENCODED_FLOAT` (1000.0f) is the DSP float-range hypothesis. Validated test: full pipeline `VSL_Encode_Gain` + `VSL_Final_Encode_To_Int` maps user value `0.75 -> 40793` with `max_encoded_int=65535`.
- **Source**: `src/vsl_dsp_logic.c`, return type `uint16_t` to match the 2-byte protocol slot.

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
- The float-range divisor in `VSL_Final_Encode_To_Int` (1000.0f, `VSL_MAX_ENCODED_FLOAT`) remains a hypothesis from DSP scaling, pending extraction of the exact constant from the disassembly. The current behavior is pinned by the validated test (`0.75 -> 40793`, full pipeline).
- The dB floor is vendor evidence, not a hypothesis: `libfatchannelplugins.so` `FUN_0011ccfc` case 6 returns `-144.0` below linear `6.309573e-08` (`20*log10` above it), and `FUN_0011f5b8` inverts with `powf(10, db*0.05)` floored at the same pair. Hence `VSL_DB_NEG_INF = -144.0f` and `VSL_DB_FLOOR_LINEAR = 6.309573e-08f`. True silence stays in the separate `db.inf` domain; sub-floor linear never means mute.
- The input clamp of `VSL_Linear_To_DB`/`VSL_DB_To_Linear` to [0,1] linear is a project-side guard; the vendor functions operate on raw struct fields without it.
- The `VSL_Parameter` structure fields are annotated with comments indicating their likely offsets in the original structure (from the disassembly). These annotations should be verified and updated as needed.

### Safety
- All functions are pure (no side effects, no static state).
- Input validation is performed to avoid undefined operations (division by zero, log of non-positive).
- No dynamic memory allocation.
- No use of unsafe functions (e.g., strcpy, sprintf).

### Testing
- Unit tests are provided in `tests/test_vsl_dsp_logic.c` using CMocka.
- Tests cover normal operation, clamping, and error conditions.
- The test for `VSL_Final_Encode_To_Int` pins the validated full-pipeline case (`0.75 -> 40793` with max_encoded_int=65535).