#include "vsl_dsp_logic.h"

float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param) {
    float clamped_linear = fmaxf(0.0f, fminf(linear_value, 1.0f));

    float range = param->curve_max_map - param->curve_min_map;
    if (range <= FLT_EPSILON) return param->coeff_offset_A;

    float norm_factor = (clamped_linear - param->curve_min_map) / range;

    float exp_term = expf(norm_factor * param->log_factor);

    return param->coeff_offset_A + param->coeff_C1 * exp_term;
}

float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param) {
    float denom = param->coeff_C1;
    if (fabsf(denom) <= FLT_EPSILON) {
        float r = param->curve_min_map;
        return fmaxf(0.0f, fminf(r, 1.0f));
    }

    float ratio = (encoded_float - param->coeff_offset_A) / denom;
    if (ratio <= 0.0f) {
        float r = param->curve_min_map;
        return fmaxf(0.0f, fminf(r, 1.0f));
    }

    float logf_result = logf(ratio);

    float log_factor = param->log_factor;
    if (fabsf(log_factor) <= FLT_EPSILON) {
        float r = param->curve_min_map;
        return fmaxf(0.0f, fminf(r, 1.0f));
    }

    float norm = logf_result / log_factor;

    float range = param->curve_max_map - param->curve_min_map;
    if (fabsf(range) <= FLT_EPSILON) {
        float r = param->curve_min_map;
        return fmaxf(0.0f, fminf(r, 1.0f));
    }

    float linear = norm * range + param->curve_min_map;

    return fmaxf(0.0f, fminf(linear, 1.0f));
}

float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param) {

    if (param->freq_min_hz <= 0.0f || param->freq_max_hz <= 0.0f) {
        return 0.0f;
    }

    float clamped_pos = fmaxf(0.0f, fminf(linear_position, 1.0f));

    float log2_min = logf(param->freq_min_hz) * VSL_INV_LN2;
    float log2_max = logf(param->freq_max_hz) * VSL_INV_LN2;

    float log2_value = log2_min + clamped_pos * (log2_max - log2_min);

    return exp2f(log2_value);
}

uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param) {
    if (param->max_encoded_int == 0) return 0;

    float scale_factor = (float)param->max_encoded_int / VSL_MAX_ENCODED_FLOAT;

    float scaled_float = encoded_float * scale_factor;

    return (uint16_t)fmaxf(0.0f, fminf(roundf(scaled_float), (float)param->max_encoded_int));
}

float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param) {

    if (param->freq_min_hz <= 0.0f || param->freq_max_hz <= 0.0f) {
        return 0.0f;
    }

    float clamped_freq = fmaxf(param->freq_min_hz, fminf(freq_hz_value, param->freq_max_hz));

    float log2_min = logf(param->freq_min_hz) * VSL_INV_LN2;
    float log2_max = logf(param->freq_max_hz) * VSL_INV_LN2;
    float log2_current = logf(clamped_freq) * VSL_INV_LN2;

    float log2_range = log2_max - log2_min;

    if (log2_range < FLT_EPSILON && log2_range > -FLT_EPSILON) {
        return 0.0f;
    }

    return (log2_current - log2_min) / log2_range;
}
