#ifndef VSL_DSP_LOGIC_H
#define VSL_DSP_LOGIC_H

#include <stdint.h>
#include <math.h>
#include <float.h> // Para fmaxf, fminf

// Constante para la conversión de logaritmo natural (ln) a logaritmo base 2 (log2)
// 1 / ln(2) ≈ 1.442695
#define VSL_INV_LN2 1.442695f

// Estructura que almacena todos los coeficientes precalculados del DSP
typedef struct {
    // === Parámetros de Comunicación DSP (Faltan los valores finales) ===
    uint32_t dsp_param_id;        // ID binario del parámetro (Ej: 0x1A01 para 'Gain')
    uint32_t max_encoded_int;     // Valor entero máximo para la precisión DSP (Ej: 65535)

    // === Coeficientes de la Curva de Ganancia/Volumen (Base e/10, Mapeo [0x20] a [0x30]) ===
    float coeff_offset_A;         // Mapeado a [0x20]
    float coeff_C1;               // Mapeado a [0x24]
    float log_factor;             // Mapeado a [0x2c] (el resultado de logf(...) de la función constructora)
    float curve_min_map;          // Mapeado a [0x40]
    float curve_max_map;          // Mapeado a [0x44]

    // === Rango de Frecuencia (Usado para Frecuencia, Mapeo [0x8] a [0xc]) ===
    float freq_min_hz;            // Mapeado a [0x8]
    float freq_max_hz;            // Mapeado a [0xc]

} VSL_Parameter;


// =========================================================================
//                       FUNCIONES DE CODIFICACIÓN (Enviar al DSP)
// =========================================================================

/**
 * @brief Codifica un valor lineal (ej. 0.5) a la escala exponencial/logarítmica del DSP (Ganancia/Volumen).
 * @param linear_value El valor lineal de entrada (ej. la posición del slider, 0.0 a 1.0).
 * @param param La estructura del parámetro con sus coeficientes.
 * @return El valor codificado en formato float (listo para la conversión final a int).
 */
float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);

/**
 * @brief Convierte una posición lineal (ej. 0.5) a su frecuencia logarítmica (Hz) real.
 * @param linear_position La posición lineal de entrada (0.0 a 1.0).
 * @param param La estructura del parámetro con sus coeficientes.
 * @return La frecuencia mapeada en Hertz (Hz).
 */
float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);

/**
 * @brief Convierte el valor codificado en float a un entero sin signo para el firmware.
 * @note ESTA FUNCIÓN ES UN MARCADOR DE POSICIÓN. El factor de escala final (la fórmula interna) 
 * aún debe ser determinado con ingeniería inversa.
 * @param encoded_float El valor float retornado por VSL_Encode_Gain o VSL_Map_Frequency.
 * @param param La estructura del parámetro con la precisión máxima entera.
 * @return El valor binario final (uint32_t) listo para ser enviado en el paquete DSP.
 */
uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param);


// =========================================================================
//                       FUNCIONES DE DECODIFICACIÓN (Leer del DSP)
// =========================================================================

/**
 * @brief Decodifica una frecuencia real (Hz) del DSP a su posición lineal de control (0.0 a 1.0).
 * @param freq_hz_value La frecuencia real en Hertz leída del DSP.
 * @param param La estructura del parámetro con sus rangos.
 * @return La posición lineal (0.0 a 1.0) para actualizar el control de la GUI.
 */
float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);

#endif // VSL_DSP_LOGIC_H

