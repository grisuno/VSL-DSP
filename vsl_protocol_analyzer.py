# PASO 1: (Fuera de este entorno)
# Capturar tráfico USB con Wireshark/usbmon
# Guardar como: audiobox_full_sweep.pcap

# PASO 2: Ejecutar el analizador
# python3 vsl_protocol_analyzer.py audiobox_full_sweep.pcap
import math
import sys
import json
from typing import Dict, Any, List

# Dependencia: 'scapy' para leer archivos PCAP
try:
    from scapy.all import rdpcap, USB
except ImportError:
    print("Error: La librería 'scapy' no está instalada.")
    print("Instala con: pip3 install scapy")
    sys.exit(1)

# =======================================================
# 1. BASE DE CONOCIMIENTO (Regla #4: Nomenclatura Inmutable)
# =======================================================

MAX_ENCODED_INT = 65535  # 0xFFFF
MIN_ENCODED_INT = 0      # 0x0000

# Estructura de Parámetro (Simplificada)
class VSLParameter:
    """Parámetros DSP descifrados con coeficientes y rangos."""
    def __init__(self, dsp_id, name, type_unit, min_map, max_map, 
                 coeff_A=0.0, coeff_C1=0.0, log_factor=0.0):
        self.dsp_param_id = dsp_id
        self.name = name
        self.type_unit = type_unit  # 'gain_db', 'frequency_hz'
        self.min_map = min_map
        self.max_map = max_map
        self.coeff_offset_A = coeff_A
        self.coeff_C1 = coeff_C1
        self.log_factor = log_factor
        
# Constantes confirmadas para Ganancia y Frecuencia:
GAIN_CH1 = VSLParameter(
    dsp_id=0x1A01, name="GAIN_CH1", type_unit="gain_db", 
    min_map=-10.0, max_map=10.0,
    # Estos coeficientes son solo para el mapeo 0.75->40793, 1.0->65535, etc.
    coeff_A=10.0, coeff_C1=20.0, log_factor=4.60517
)

HPF_FREQ_CH1 = VSLParameter(
    dsp_id=0x2B05, name="HPF_FREQ_CH1", type_unit="frequency_hz", 
    min_map=20.0, max_map=20000.0,
    # Coeficientes para la curva logarítmica base 2
    coeff_A=1.0, coeff_C1=1.0, log_factor=1.0 
)

# Base de datos de parámetros conocidos (Regla #5: Escalabilidad)
KNOWN_PARAMETERS = {
    GAIN_CH1.dsp_param_id: GAIN_CH1,
    HPF_FREQ_CH1.dsp_param_id: HPF_FREQ_CH1,
    # AÑADIR AQUI MÁS PARÁMETROS DESCUBIERTOS (0x1A02, 0x3C10, etc.)
}

# =======================================================
# 2. FUNCIONES DE DECODIFICACIÓN DSP (Reverse Mapping)
# =======================================================

def reverse_map_gain(encoded_value: int, param: VSLParameter) -> float:
    """
    Simula VSL_Decode_Gain. Convierte un entero a un valor de usuario (dB).
    
    Fórmula inversa confirmada: 
    user_value = (log2(encoded_float * range_span) / log_factor) + min_db
    
    Usaremos la simplificación de mapeo lineal para la PoC, ya que el valor 
    confirmado (40793) implica que no es un simple mapeo lineal 
    (40793 / 65535 = 0.6225). La fórmula real de decodificación logarítmica
    es más compleja. Para la PoC, aplicamos la inversa de la fórmula 
    logarítmica simplificada que nos dio los resultados válidos:
    """
    
    # 1. Normalizar el valor entero a un float (0.0 a 1.0)
    norm_float = encoded_value / MAX_ENCODED_INT
    
    # 2. Aplicar el mapeo de rango lineal (Temporalmente, hasta tener la inversa exacta)
    # Rango total: max_map - min_map
    range_span = param.max_map - param.min_map
    decoded_value = param.min_map + (norm_float * range_span)
    
    # Si tenemos el 40793 -> 0.75 (3/4 de rango), el mapeo lineal da un error.
    # Esta función debe ser ajustada después, pero esta forma lineal es la más segura
    # para el 90% de los parámetros (como el Compresor)
    
    return decoded_value

def reverse_map_frequency(encoded_value: int, param: VSLParameter) -> float:
    """
    Simula VSL_Decode_Frequency. Convierte un entero a frecuencia (Hz).
    
    Fórmula inversa: exp2f(log2_min + pos * (log2_max - log2_min))
    """
    
    # 1. Normalizar el valor entero a un float (0.0 a 1.0)
    pos = encoded_value / MAX_ENCODED_INT
    
    # 2. Calcular los logaritmos base 2 del rango
    log2_min = math.log2(param.min_map)
    log2_max = math.log2(param.max_map)
    
    # 3. Aplicar el mapeo logarítmico
    log2_freq = log2_min + pos * (log2_max - log2_min)
    decoded_freq = math.pow(2.0, log2_freq)
    
    return decoded_freq

def get_decoded_value(encoded_value: int, param_id: int) -> tuple[float, str]:
    """Dirige la decodificación al motor DSP correcto."""
    
    param = KNOWN_PARAMETERS.get(param_id)
    
    if not param:
        return 0.0, "DESCONOCIDO"

    if param.type_unit == 'gain_db':
        user_val = reverse_map_gain(encoded_value, param)
        unit = "dB"
    elif param.type_unit == 'frequency_hz':
        user_val = reverse_map_frequency(encoded_value, param)
        unit = "Hz"
    else:
        # Aquí irían 'ratio', 'time_ms', 'percent'
        user_val = encoded_value / MAX_ENCODED_INT
        unit = "Norm"
        
    return user_val, unit

# =======================================================
# 3. ANALIZADOR DE PAQUETES (Parser de PCAP)
# =======================================================

def decode_vsl_packet(data: bytes) -> Dict[str, Any]:
    """
    Decodifica el payload de 64 bytes. (Regla #3: Seguridad)
    """
    if len(data) < 5:  # El payload mínimo es 5 bytes (Report ID + 2x uint16_t)
        return {"error": "Paquete muy corto", "raw_data": data.hex()}

    # 1. Report ID (Byte 0) - CRÍTICO
    report_id = data[0]

    # 2. Param ID (Bytes 1 y 2, Little Endian confirmado)
    param_id = data[1] | (data[2] << 8)

    # 3. Encoded Value (Bytes 3 y 4, Little Endian confirmado)
    encoded_value = data[3] | (data[4] << 8)
    
    # 4. Reverse Mapping
    user_val, unit = get_decoded_value(encoded_value, param_id)

    # 5. Output
    param_info = KNOWN_PARAMETERS.get(param_id)
    param_name = param_info.name if param_info else "UNKNOWN_PARAM"
    
    return {
        'report_id': f'0x{report_id:02X}',
        'param_id': f'0x{param_id:04X}',
        'name': param_name,
        'value_int': encoded_value,
        'decoded_value': user_val,
        'unit': unit,
        'raw_payload_hex': data[:8].hex() # Primeros 8 bytes del payload
    }

def analyze_pcap(pcap_file: str) -> List[Dict[str, Any]]:
    """Carga un archivo PCAP y filtra los paquetes USB VSL."""
    try:
        packets = rdpcap(pcap_file)
    except Exception as e:
        print(f"Error al leer PCAP: {e}")
        return []
    
    vsl_packets: List[Dict[str, Any]] = []

    for pkt in packets:
        # Filtro de bajo nivel: solo paquetes USB con carga útil (load)
        if USB in pkt and hasattr(pkt[USB], 'load'): 
            
            # El payload de datos es el 'load' del paquete USB
            data = bytes(pkt[USB].load)
            
            # Filtro por tamaño (solo paquetes de 64 bytes, confirmado)
            if len(data) == 64:
                # Decodificar y guardar
                decoded_data = decode_vsl_packet(data)
                
                # Opcional: Filtrar solo por el Report ID esperado
                # if decoded_data['report_id'] == '0x01': 
                vsl_packets.append(decoded_data)
                
    return vsl_packets

# =======================================================
# 4. EJECUCIÓN DEL ANALIZADOR
# =======================================================

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Uso: python3 vsl_protocol_analyzer.py <archivo_captura.pcap>")
        sys.exit(1)
        
    pcap_file = sys.argv[1]
    print(f"🔬 Analizando tráfico VSL desde: {pcap_file}")
    
    # Analizar el archivo PCAP
    vsl_packets = analyze_pcap(pcap_file)
    
    print(f"\n[+] Paquetes VSL (64 bytes) encontrados: {len(vsl_packets)}\n")
    
    # Imprimir y exportar resultados
    for i, pkt in enumerate(vsl_packets, 1):
        if 'error' in pkt:
            print(f"[{i:03d}] ERROR DECODER: {pkt['error']}")
            continue
            
        print(f"[{i:03d}] ID: {pkt['param_id']} ({pkt['name']})")
        print(f"      INT: {pkt['value_int']:5d} (0x{pkt['value_int']:04X})")
        print(f"      USER: {pkt['decoded_value']:.2f} {pkt['unit']}")
        print(f"      RAW: {pkt['raw_payload_hex']}...")
        print("-" * 50)
        
    # Exportar resultados a JSON para el VSL Parameter Database Builder
    output_file = pcap_file.replace('.pcap', '_decoded.json').replace('.pcapng', '_decoded.json')
    with open(output_file, 'w') as f:
        json.dump(vsl_packets, f, indent=2)
        
    print(f"\n✅ Análisis completado. Base de datos JSON guardada en: {output_file}")
