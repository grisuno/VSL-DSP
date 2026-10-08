# Subsystem: legacy (page 2 of 2)
Previous: [KB_legacy.md](KB_legacy.md)

## legacy/vsl_dsp_logic.c
- Doc: Declaración de la nueva función de envío
- Layer: business_logic
- Language: c
- Symbols:
  - `VSL_Encode_Gain` (function, line 11) `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)`
  - `VSL_Map_Frequency` (function, line 29) `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)`
  - `VSL_Final_Encode_To_Int` (function, line 58) `uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)`
  - `VSL_Decode_Frequency` (function, line 78) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)`
  - `VSL_Build_And_Send_Packet` (function, line 4) `void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float);`
- Depends on: `legacy/vsl_dsp_logic.h`

## legacy/vsl_dsp_logic.h
- Doc: Constante para la conversión de logaritmo natural (ln) a logaritmo base 2 (log2) 1 / ln(2) ≈...
- Layer: business_logic
- Language: h
- Symbols:
  - `VSL_Parameter` (struct, line 13)
  - `VSL_Encode_Gain` (function, line 42) `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);`
  - `VSL_Map_Frequency` (function, line 50) `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);`
  - `VSL_Final_Encode_To_Int` (function, line 60) `uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param);`
  - `VSL_Decode_Frequency` (function, line 73) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);`
  - `VSL_DSP_LOGIC_H` (macro, line 2) `#define VSL_DSP_LOGIC_H`
  - `VSL_INV_LN2` (macro, line 10) `#define VSL_INV_LN2`
- Imported by: `legacy/main.c`, `legacy/vsl_dsp_logic.c`

## legacy/vsl_dsp_transport.c
- Doc: FUN_Send_Packet: @brief Función de I/O real usando HIDAPI. @note DEBE SER REEMPLAZADA con la...
- Layer: utility
- Language: c
- Symbols:
  - `VSL_Init_Device` (function, line 23) `int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)`
  - `VSL_Close_Device` (function, line 70) `void VSL_Close_Device(void)`
  - `VSL_Get_Device_Handle` (function, line 79) `hid_device* VSL_Get_Device_Handle(void)`
  - `FUN_Send_Packet` (function, line 97) `void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length)`
  - `VSL_Build_And_Send_Packet` (function, line 140) `void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float)`
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_dsp_transport.h`

## legacy/vsl_dsp_transport.h
- Doc: VSL_DSP_Packet: Estructura de Paquete: Sin 'header' (lo quitaste en la estructura typedef)
- Layer: utility
- Language: h
- Symbols:
  - `VSL_DSP_Packet` (struct, line 12)
  - `VSL_Init_Device` (function, line 19) `int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id);`
  - `VSL_Close_Device` (function, line 20) `void VSL_Close_Device(void);`
  - `VSL_Get_Device_Handle` (function, line 21) `hid_device* VSL_Get_Device_Handle(void);`
  - `FUN_Send_Packet` (function, line 24) `void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length);`
  - `VSL_Build_And_Send_Packet` (function, line 25) `void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float);`
  - `VSL_DSP_TRANSPORT_H` (macro, line 4) `#define VSL_DSP_TRANSPORT_H`
- Depends on: `legacy/vsl_config.h`
- Imported by: `legacy/main.c`, `legacy/test_connection.c`, `legacy/vsl_dsp_transport.c`

## legacy/vsl_hid_io.py
- Doc: VSL-DSP HID I/O Module (OPCIONAL) Comunicación real con hardware via hidapi.
- Layer: utility
- Language: py
- Symbols:
  - `VSLDevice` (class, line 31) `class VSLDevice`
  - `enumerate_vsl_devices` (method, line 149) `def enumerate_vsl_devices()`
  - `__new__` (method, line 39) `def __new__(cls)`
  - `__init__` (method, line 45) `def __init__(self)`
  - `open` (method, line 59) `def open(self)`
  - `close` (method, line 90) `def close(self)`
  - `send_packet` (method, line 101) `def send_packet(self, packet)`
  - `__enter__` (method, line 139) `def __enter__(self)`
  - `__exit__` (method, line 144) `def __exit__(self, exc_type, exc_val, exc_tb)`
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

## legacy/vsl_poc_main.py
- Doc: VSL-DSP Proof of Concept - Main Program Programa principal de pruebas y validación.
- Layer: utility
- Language: py
- Symbols:
  - `test_gain_encoding` (function, line 43) `def test_gain_encoding()`
  - `test_frequency_mapping` (function, line 72) `def test_frequency_mapping()`
  - `test_packet_construction` (function, line 92) `def test_packet_construction()`
  - `test_edge_cases` (function, line 150) `def test_edge_cases()`
  - `run_full_workflow` (function, line 197) `def run_full_workflow()`
  - `print_summary` (function, line 229) `def print_summary()`
  - `main` (function, line 266) `def main()`
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

## legacy/vsl_protocol_analyzer.py
- Doc: PASO 1: (Fuera de este entorno) Capturar tráfico USB con Wireshark/usbmon Guardar como...
- Layer: utility
- Language: py
- Symbols:
  - `VSLParameter` (class, line 28) `class VSLParameter`
  - `reverse_map_gain` (method, line 67) `def reverse_map_gain(encoded_value, param)`
  - `reverse_map_frequency` (method, line 95) `def reverse_map_frequency(encoded_value, param)`
  - `get_decoded_value` (method, line 115) `def get_decoded_value(encoded_value, param_id)`
  - `decode_vsl_packet` (method, line 140) `def decode_vsl_packet(data)`
  - `analyze_pcap` (method, line 173) `def analyze_pcap(pcap_file)`
  - `__init__` (method, line 30) `def __init__(self, dsp_id, name, type_unit, min_map, max_map, coeff_A, coeff_C1, log_factor)`

## legacy/vsl_transport.py
- Doc: VSL-DSP Transport Module Construcción y validación de paquetes HID.
- Layer: utility
- Language: py
- Symbols:
  - `VSLPacket` (class, line 15) `class VSLPacket`
  - `build_packet_safe` (method, line 141) `def build_packet_safe(param, encoded_value)`
  - `__init__` (method, line 21) `def __init__(self, param_id, encoded_value, report_id)`
  - `_build_buffer` (method, line 58) `def _build_buffer(self)`
  - `buffer` (method, line 89) `def buffer(self)`
  - `hex_dump` (method, line 93) `def hex_dump(self, num_bytes)`
  - `validate` (method, line 106) `def validate(self)`
  - `__repr__` (method, line 133) `def __repr__(self)`
- Depends on: `legacy/vsl_config.h`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

