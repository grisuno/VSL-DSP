#include "vsl_dsp_logic.h"

// Declaración de la nueva función de envío
void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float);

// =========================================================================
//                       FUNCIONES DE CODIFICACIÓN (Enviar al DSP)
// =========================================================================

// Implementación de FUN_00132c90
float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param) {
    // 1. Clamping del valor lineal (Normalización 0.0 - 1.0)
    float clamped_linear = fmaxf(0.0f, fminf(linear_value, 1.0f));

    // 2. Normalización al rango de mapeo (0.0 - 1.0)
    float range = param->curve_max_map - param->curve_min_map;
    if (range <= FLT_EPSILON) return param->coeff_offset_A; // Evitar división por cero

    float norm_factor = (clamped_linear - param->curve_min_map) / range;
    
    // 3. Aplicación de la curva exponencial: expf(fVar4 * *(0x2c))
    float exp_term = expf(norm_factor * param->log_factor);
    
    // 4. Cálculo del valor codificado final: fVar1 + fVar5 * fVar2
    return param->coeff_offset_A + param->coeff_C1 * exp_term;
}

// Implementación de FUN_00132d00
float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param) {
    
    if (param->freq_min_hz <= 0.0f || param->freq_max_hz <= 0.0f) {
        return 0.0f; // Frecuencias no válidas para logf
    }
    
    // 1. Clamping del valor de entrada (0.0 - 1.0)
    float clamped_pos = fmaxf(0.0f, fminf(linear_position, 1.0f));

    // 2. Cálculo de los logs en base 2 de los límites de frecuencia (logf * 1.442695)
    float log2_min = logf(param->freq_min_hz) * VSL_INV_LN2;
    float log2_max = logf(param->freq_max_hz) * VSL_INV_LN2;
    
    // 3. Mapeo logarítmico: log2_min + clamped_pos * (log2_max - log2_min)
    float log2_value = log2_min + clamped_pos * (log2_max - log2_min);

    // 4. Conversión a frecuencia lineal (exp2f)
    return exp2f(log2_value);
}

// =========================================================================
//                       FUNCIÓN DE CONVERSIÓN FINAL (FALTA DE DETALLE)
// =========================================================================

/**
 * @brief Convierte el valor codificado en float a un entero sin signo para el firmware.
 * @note Basado en la hipótesis común de DSP donde el rango flotante es 0.0 - 1000.0.
 * Si el valor real es diferente, solo se debe cambiar la constante VSL_MAX_ENCODED_FLOAT.
 */
uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param) {
    if (param->max_encoded_int == 0) return 0;
    
    // Hipótesis: el rango máximo de float del DSP es 1000.0
    const float VSL_MAX_ENCODED_FLOAT = 1000.0f;
    const float SCALE_FACTOR = (float)param->max_encoded_int / VSL_MAX_ENCODED_FLOAT;

    // Fórmula: (Float Codificado * (65535 / 1000.0))
    float scaled_float = encoded_float * SCALE_FACTOR;
    
    // El 'FCVTZS' implica que se trunca el decimal (floor) y se convierte a entero.
    // También se aplica el clamping para asegurar que no exceda el máximo de 65535.
    return (uint32_t)fmaxf(0.0f, fminf(roundf(scaled_float), (float)param->max_encoded_int));
}

// =========================================================================
//                       FUNCIONES DE DECODIFICACIÓN (Leer del DSP)
// =========================================================================

// Implementación de FUN_00132da8
float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param) {
    
    if (param->freq_min_hz <= 0.0f || param->freq_max_hz <= 0.0f) {
        return 0.0f; // Frecuencias no válidas para logf
    }
    
    // 1. Clamping de la frecuencia al rango definido
    float clamped_freq = fmaxf(param->freq_min_hz, fminf(freq_hz_value, param->freq_max_hz));

    // 2. Cálculo de los logs en base 2
    float log2_min = logf(param->freq_min_hz) * VSL_INV_LN2;
    float log2_max = logf(param->freq_max_hz) * VSL_INV_LN2;
    float log2_current = logf(clamped_freq) * VSL_INV_LN2;
    
    // 3. Normalización inversa: (log2_actual - log2_min) / (log2_max - log2_min)
    float log2_range = log2_max - log2_min;
    
    if (log2_range < FLT_EPSILON && log2_range > -FLT_EPSILON) {
        return 0.0f; // Evitar división por cero (rango nulo)
    }
    
    // Retorna la posición lineal (0.0 - 1.0)
    return (log2_current - log2_min) / log2_range;
}
