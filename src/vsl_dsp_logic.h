#ifndef VSL_DSP_LOGIC_H
#define VSL_DSP_LOGIC_H

#include <stdint.h>
#include <math.h>
#include <float.h>

#define VSL_INV_LN2            1.442695f
#define VSL_MAX_ENCODED_FLOAT  1000.0f

typedef struct {
    uint32_t dsp_param_id;
    uint32_t max_encoded_int;

    float coeff_offset_A;
    float coeff_C1;
    float log_factor;
    float curve_min_map;
    float curve_max_map;

    float freq_min_hz;
    float freq_max_hz;

} VSL_Parameter;

/**
 * @brief Encodes a linear gain value [0.0, 1.0] to the DSP exponential curve.
 * @param linear_value Linear control position clamped to [0,1].
 * @param param Parameter coefficients from the DSP parameter database.
 * @return Encoded float value ready for integer conversion.
 * @source Reverse-engineered from FUN_00132c90 in the Android driver.
 */
float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);

/**
 * @brief Decodes an encoded gain float back to a linear position [0.0, 1.0].
 * @param encoded_float Value received from the DSP or produced by VSL_Encode_Gain.
 * @param param Same coefficients used during encoding.
 * @return Linear control position clamped to [0,1].
 * @source Inverse of VSL_Encode_Gain (FUN_00132c90).
 */
float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param);

/**
 * @brief Maps a linear position [0.0, 1.0] to a logarithmic frequency (Hz).
 * @param linear_position Linear control position clamped to [0,1].
 * @param param Parameter with freq_min_hz and freq_max_hz.
 * @return Frequency in Hz.
 * @source Reverse-engineered from FUN_00132d00 in the Android driver.
 */
float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);

/**
 * @brief Decodes a frequency (Hz) from the DSP to a linear position [0.0, 1.0].
 * @param freq_hz_value Frequency in Hz read from the DSP, clamped to range.
 * @param param Parameter with freq_min_hz and freq_max_hz.
 * @return Linear control position [0,1].
 * @source Reverse-engineered from FUN_00132da8 in the Android driver.
 */
float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);

/**
 * @brief Converts an encoded float to a 16-bit integer for the DSP firmware.
 * @param encoded_float Value from VSL_Encode_Gain or VSL_Map_Frequency.
 * @param param Parameter with max_encoded_int (typically 65535).
 * @return Integer value clamped to [0, max_encoded_int] ready for the USB packet.
 * @note The scale factor VSL_MAX_ENCODED_FLOAT (1000.0f) is a hypothesis
 *       from the DSP scaling. Validated test: 0.75 -> 40793 (full pipeline).
 */
uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param);

#endif /* VSL_DSP_LOGIC_H */
