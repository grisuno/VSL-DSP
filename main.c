#include <stdio.h>
#include "vsl_dsp_logic.h"
#include "vsl_dsp_transport.h"

int main() {

    uint16_t gain_id = 0x1A01; // ID de Ganancia (Ejemplo)

    // --- Ejemplo de Inicialización de Parámetro (Valores de ejemplo) ---
    // En un cliente real, estos coeficientes deben ser llenados por la función constructora (FUN_00132b10)
    VSL_Parameter Gain_Param = {
        .dsp_param_id = 0x1A01,
        .max_encoded_int = 65535, // Típico para 16-bit
        .coeff_offset_A = -10.0f,
        .coeff_C1 = 20.0f,
        .log_factor = 4.60517f, // ln(100), típico para dB
        .curve_min_map = 0.0f,
        .curve_max_map = 1.0f,
        .freq_min_hz = 0.0f,
        .freq_max_hz = 0.0f
    };

    VSL_Parameter Freq_Param = {
        .dsp_param_id = 0x2B05,
        .max_encoded_int = 65535,
        .coeff_offset_A = 0.0f, .coeff_C1 = 0.0f, .log_factor = 0.0f,
        .curve_min_map = 0.0f, .curve_max_map = 0.0f,
        .freq_min_hz = 20.0f,
        .freq_max_hz = 20000.0f // Rango completo de audio
    };
    
    // --- Prueba de Codificación (Ganancia) ---
    float user_gain_value = 0.75f; // Usuario mueve el fader al 75%
    float encoded_gain_float = VSL_Encode_Gain(user_gain_value, &Gain_Param);
    uint32_t final_dsp_gain_int = VSL_Final_Encode_To_Int(encoded_gain_float, &Gain_Param);

    printf("--- Ganancia ---\n");
    printf("Valor Lineal (Input): %.2f\n", user_gain_value);
    printf("Valor Codificado (Float): %.4f\n", encoded_gain_float);
    printf("Valor Binario DSP (Output): %u\n", final_dsp_gain_int);
    
    // --- Prueba de Codificación (Frecuencia) ---
    float user_freq_position = 0.5f; // Usuario selecciona el punto medio (logarítmico)
    float mapped_freq_hz = VSL_Map_Frequency(user_freq_position, &Freq_Param);
    
    printf("\n--- Frecuencia ---\n");
    printf("Posición Lineal (Input): %.2f\n", user_freq_position);
    printf("Frecuencia Mapeada (Hz): %.2f Hz\n", mapped_freq_hz);

    // --- Prueba de Decodificación (Frecuencia) ---
    float decoded_position = VSL_Decode_Frequency(mapped_freq_hz, &Freq_Param);
    printf("Decodificación a Posición Lineal: %.4f\n", decoded_position);
    // 2. Codificación (Lógica Matemática)
    encoded_gain_float = VSL_Encode_Gain(user_gain_value, &Gain_Param);

    // --- Prueba de Codificación (Ganancia) ---
    user_gain_value = 0.75f; // Usuario mueve el fader al 75%
    encoded_gain_float = VSL_Encode_Gain(user_gain_value, &Gain_Param);
    final_dsp_gain_int = VSL_Final_Encode_To_Int(encoded_gain_float, &Gain_Param);

    printf("--- Ganancia ---\n");
    printf("Valor Lineal (Input): %.2f\n", user_gain_value);
    printf("Valor Codificado (Float): %.4f\n", encoded_gain_float);
    printf("Valor Binario DSP (Output): %u\n", final_dsp_gain_int);
    
    // ************************************************************
    // *** ¡Llamada para Enviar el Paquete DSP a través de HIDAPI! ***
    VSL_Build_And_Send_Packet(gain_id, encoded_gain_float);
    // ************************************************************
    return 0;
}
