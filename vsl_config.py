"""
VSL-DSP Configuration Module
Contiene todas las constantes y configuraciones del protocolo.

⚠️ BLOQUEADORES CRÍTICOS (Pendientes del desensamblado):
- VSL_VENDOR_ID
- VSL_PRODUCT_ID  
- VSL_REPORT_ID
"""

import sys
from typing import NamedTuple

# ============================================================================
# CONSTANTES DEL PROTOCOLO (Confirmadas del Desensamblado)
# ============================================================================

# ⚠️ BLOQUEADOR #1 y #2: Deben ser extraídos del desensamblado o hardware
VSL_VENDOR_ID = None   # Placeholder: Ejecutar vsl_discover o buscar en .so
VSL_PRODUCT_ID = None  # Placeholder: Ejecutar vsl_discover o buscar en .so

# ⚠️ BLOQUEADOR #3: Debe ser extraído del desensamblado (buf[0] antes de FUN_00412345)
VSL_REPORT_ID = None   # Placeholder: Buscar en pseudocódigo de Ghidra/IDA

# ✅ CONFIRMADO del desensamblado (FUN_00412345)
VSL_PACKET_SIZE = 64   # Tamaño del paquete HID (0x40 bytes)

# ✅ CONFIRMADO: Escala de conversión Float → Int
VSL_MAX_ENCODED_FLOAT = 1000.0
VSL_MAX_ENCODED_INT = 65535  # 16-bit unsigned (0xFFFF)

# Constantes matemáticas
VSL_INV_LN2 = 1.442695  # 1 / ln(2) para conversión log2


# ============================================================================
# ESTRUCTURA DE PARÁMETROS DSP
# ============================================================================

class VSLParameter(NamedTuple):
    """
    Estructura que replica exactamente VSL_Parameter del código C.
    Todos los campos están confirmados del desensamblado.
    """
    dsp_param_id: int         # ID binario del parámetro (ej: 0x1A01)
    max_encoded_int: int      # Valor máximo del entero (65535)
    coeff_offset_A: float     # Offset de la curva exponencial
    coeff_C1: float           # Coeficiente C1 de la curva
    log_factor: float         # Factor logarítmico (ln(X))
    curve_min_map: float      # Límite inferior del mapeo (0.0)
    curve_max_map: float      # Límite superior del mapeo (1.0)
    freq_min_hz: float        # Frecuencia mínima en Hz (0.0 para gain)
    freq_max_hz: float        # Frecuencia máxima en Hz (0.0 para gain)


# ============================================================================
# BASE DE DATOS DE PARÁMETROS (Coeficientes de Prueba)
# ============================================================================

# Parámetro de Ganancia Canal 1 (Valores aproximados para testing)
# NOTA: Estos coeficientes deben ser extraídos del constructor del driver
GAIN_CH1 = VSLParameter(
    dsp_param_id=0x1A01,
    max_encoded_int=65535,
    coeff_offset_A=-10.0,     # Offset típico para dB
    coeff_C1=20.0,            # Rango de 20 dB
    log_factor=4.60517,       # ln(100)
    curve_min_map=0.0,
    curve_max_map=1.0,
    freq_min_hz=0.0,          # No aplica para ganancia
    freq_max_hz=0.0
)

# Parámetro de Frecuencia HPF Canal 1
FREQ_HPF_CH1 = VSLParameter(
    dsp_param_id=0x2B05,
    max_encoded_int=65535,
    coeff_offset_A=0.0,       # No aplica para frecuencia
    coeff_C1=0.0,
    log_factor=0.0,
    curve_min_map=0.0,
    curve_max_map=0.0,
    freq_min_hz=20.0,         # Rango típico de audio
    freq_max_hz=20000.0
)


# ============================================================================
# VALIDACIÓN DE CONFIGURACIÓN
# ============================================================================

def validate_configuration() -> tuple[bool, str]:
    """
    Valida que todos los valores críticos estén configurados.
    
    Returns:
        (is_valid, error_message)
    """
    errors = []
    
    if VSL_VENDOR_ID is None:
        errors.append("VSL_VENDOR_ID no configurado (BLOQUEADOR #1)")

    if VSL_PRODUCT_ID is None:
        errors.append("VSL_PRODUCT_ID no configurado (BLOQUEADOR #2)")

    if VSL_REPORT_ID is None:
        errors.append("VSL_REPORT_ID no configurado (BLOQUEADOR #3)")

    if errors:
        return False, "\n".join(errors)

    return True, "Configuración válida"


def print_configuration_status():
    """Imprime el estado de la configuración con formato."""
    print("=" * 70)
    print(" VSL-DSP CONFIGURATION STATUS")
    print("=" * 70)
    
    status = "✅" if VSL_VENDOR_ID is not None else "⚠️ PENDIENTE"
    print(f"Vendor ID:       {status} - {VSL_VENDOR_ID or 'No configurado'}")
    
    status = "✅" if VSL_PRODUCT_ID is not None else "⚠️ PENDIENTE"
    print(f"Product ID:      {status} - {VSL_PRODUCT_ID or 'No configurado'}")
    
    status = "✅" if VSL_REPORT_ID is not None else "⚠️ PENDIENTE"
    print(f"Report ID:       {status} - {VSL_REPORT_ID or 'No configurado'}")
    
    print(f"Packet Size:     ✅ - {VSL_PACKET_SIZE} bytes")
    print(f"Max Encoded Int: ✅ - {VSL_MAX_ENCODED_INT}")
    print("=" * 70)
    
    is_valid, message = validate_configuration()
    if not is_valid:
        print(f"\n⚠️ ADVERTENCIA: {message}")
        print("   El modo de I/O real no estará disponible hasta resolver los bloqueadores.\n")


if __name__ == "__main__":
    print_configuration_status()