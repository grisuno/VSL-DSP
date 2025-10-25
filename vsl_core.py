"""
VSL-DSP Core Logic Module
Implementa las funciones matemáticas de encoding/decoding.
Traducción 1:1 del código C desensamblado.
"""

import math
from typing import Union
from vsl_config import VSLParameter, VSL_MAX_ENCODED_FLOAT


# ============================================================================
# FUNCIONES DE CODIFICACIÓN (Enviar al DSP)
# ============================================================================

def vsl_encode_gain(linear_value: float, param: VSLParameter) -> float:
    """
    Traducción de FUN_00132c90 (VSL_Encode_Gain en C).
    
    Convierte un valor lineal (0.0 - 1.0) a la escala exponencial del DSP.
    
    Fórmula:
        encoded = coeff_offset_A + coeff_C1 * exp(norm_factor * log_factor)
    
    Args:
        linear_value: Valor lineal de entrada (0.0 a 1.0)
        param: Estructura de parámetros con coeficientes
        
    Returns:
        Valor codificado en float (rango: ~-10.0 a ~1000.0)
        
    Raises:
        ValueError: Si param es inválido
    """
    if not isinstance(param, VSLParameter):
        raise ValueError("param debe ser instancia de VSLParameter")
    
    # 1. Clamping del valor lineal
    clamped_linear = max(0.0, min(linear_value, 1.0))
    
    # 2. Normalización al rango de mapeo
    range_val = param.curve_max_map - param.curve_min_map
    
    if abs(range_val) < 1e-7:  # Equivalente a FLT_EPSILON en C
        return param.coeff_offset_A
    
    norm_factor = (clamped_linear - param.curve_min_map) / range_val
    
    # 3. Aplicación de la curva exponencial
    exp_term = math.exp(norm_factor * param.log_factor)
    
    # 4. Cálculo del valor codificado final
    encoded_float = param.coeff_offset_A + param.coeff_C1 * exp_term
    
    return encoded_float


def vsl_map_frequency(linear_position: float, param: VSLParameter) -> float:
    """
    Traducción de FUN_00132d00 (VSL_Map_Frequency en C).
    
    Convierte una posición lineal (0.0 - 1.0) a frecuencia logarítmica (Hz).
    
    Args:
        linear_position: Posición lineal (0.0 a 1.0)
        param: Estructura de parámetros con rangos de frecuencia
        
    Returns:
        Frecuencia en Hz (ej: 20.0 a 20000.0)
        
    Raises:
        ValueError: Si las frecuencias son inválidas
    """
    if not isinstance(param, VSLParameter):
        raise ValueError("param debe ser instancia de VSLParameter")
    
    if param.freq_min_hz <= 0.0 or param.freq_max_hz <= 0.0:
        raise ValueError("Frecuencias min/max deben ser > 0 para mapeo logarítmico")
    
    # 1. Clamping del valor de entrada
    clamped_pos = max(0.0, min(linear_position, 1.0))
    
    # 2. Cálculo de logs en base 2
    log2_min = math.log(param.freq_min_hz) * 1.442695  # * VSL_INV_LN2
    log2_max = math.log(param.freq_max_hz) * 1.442695
    
    # 3. Mapeo logarítmico
    log2_value = log2_min + clamped_pos * (log2_max - log2_min)
    
    # 4. Conversión a frecuencia lineal (exp2)
    return math.pow(2.0, log2_value)


def vsl_final_encode_to_int(encoded_float: float, param: VSLParameter) -> int:
    """
    Traducción de VSL_Final_Encode_To_Int en C.
    
    Convierte el valor codificado float a entero de 16-bit para el DSP.
    
    Args:
        encoded_float: Valor float codificado (ej: -10.0 a 1000.0)
        param: Estructura de parámetros con max_encoded_int
        
    Returns:
        Valor entero (0 a 65535)
    """
    if not isinstance(param, VSLParameter):
        raise ValueError("param debe ser instancia de VSLParameter")
    
    if param.max_encoded_int == 0:
        return 0
    
    # Escala: float (0-1000) → int (0-65535)
    scale_factor = param.max_encoded_int / VSL_MAX_ENCODED_FLOAT
    scaled_float = encoded_float * scale_factor
    
    # Redondeo y clamping
    final_int = int(round(max(0.0, min(scaled_float, float(param.max_encoded_int)))))
    
    return final_int


# ============================================================================
# FUNCIONES DE DECODIFICACIÓN (Leer del DSP)
# ============================================================================

def vsl_decode_frequency(freq_hz_value: float, param: VSLParameter) -> float:
    """
    Traducción de FUN_00132da8 (VSL_Decode_Frequency en C).
    
    Convierte una frecuencia real (Hz) a su posición lineal (0.0 - 1.0).
    
    Args:
        freq_hz_value: Frecuencia en Hz
        param: Estructura de parámetros con rangos
        
    Returns:
        Posición lineal (0.0 a 1.0)
        
    Raises:
        ValueError: Si las frecuencias son inválidas
    """
    if not isinstance(param, VSLParameter):
        raise ValueError("param debe ser instancia de VSLParameter")
    
    if param.freq_min_hz <= 0.0 or param.freq_max_hz <= 0.0:
        raise ValueError("Frecuencias min/max deben ser > 0")
    
    # 1. Clamping de la frecuencia
    clamped_freq = max(param.freq_min_hz, min(freq_hz_value, param.freq_max_hz))
    
    # 2. Cálculo de logs en base 2
    log2_min = math.log(param.freq_min_hz) * 1.442695
    log2_max = math.log(param.freq_max_hz) * 1.442695
    log2_current = math.log(clamped_freq) * 1.442695
    
    # 3. Normalización inversa
    log2_range = log2_max - log2_min
    
    if abs(log2_range) < 1e-7:
        return 0.0
    
    return (log2_current - log2_min) / log2_range


# ============================================================================
# FUNCIÓN AUXILIAR DE VALIDACIÓN
# ============================================================================

def validate_parameter(param: VSLParameter) -> tuple[bool, str]:
    """
    Valida la integridad de un VSLParameter.
    
    Returns:
        (is_valid, error_message)
    """
    if param.max_encoded_int <= 0:
        return False, "max_encoded_int debe ser > 0"
    
    if param.curve_max_map < param.curve_min_map:
        return False, "curve_max_map debe ser >= curve_min_map"
    
    # Validación específica para parámetros de frecuencia
    if param.freq_max_hz > 0.0:  # Es un parámetro de frecuencia
        if param.freq_min_hz <= 0.0:
            return False, "freq_min_hz debe ser > 0 para parámetros de frecuencia"
        if param.freq_max_hz <= param.freq_min_hz:
            return False, "freq_max_hz debe ser > freq_min_hz"
    
    return True, "Parámetro válido"


if __name__ == "__main__":
    # Tests básicos de las funciones
    from vsl_config import GAIN_CH1, FREQ_HPF_CH1
    
    print("=== Tests de vsl_core.py ===\n")
    
    # Test 1: Encoding de ganancia
    test_value = 0.75
    encoded = vsl_encode_gain(test_value, GAIN_CH1)
    final_int = vsl_final_encode_to_int(encoded, GAIN_CH1)
    
    print(f"Test Gain Encoding:")
    print(f"  Input: {test_value}")
    print(f"  Encoded Float: {encoded:.4f}")
    print(f"  Final Int: {final_int}")
    print(f"  Expected: ~40793 (puede variar según coeficientes exactos)\n")
    
    # Test 2: Mapeo de frecuencia
    freq_pos = 0.5
    mapped_freq = vsl_map_frequency(freq_pos, FREQ_HPF_CH1)
    decoded_pos = vsl_decode_frequency(mapped_freq, FREQ_HPF_CH1)
    
    print(f"Test Frequency Mapping:")
    print(f"  Input Position: {freq_pos}")
    print(f"  Mapped Frequency: {mapped_freq:.2f} Hz")
    print(f"  Decoded Position: {decoded_pos:.4f}")
    print(f"  Round-trip Error: {abs(freq_pos - decoded_pos):.6f}")