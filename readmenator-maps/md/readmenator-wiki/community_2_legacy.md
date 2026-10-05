# legacy

*Community 2 | 11 files | cohesion 1.00*

## Definition

This community groups 11 file(s) rooted at `legacy` with dominant language c (cohesion 1.00). Central symbols: `FUN_Send_Packet`, `VSLDevice`, `VSLPacket`, `VSL_Build_And_Send_Packet`, `VSL_CONFIG_H`, `VSL_Close_Device`, `VSL_DSP_LOGIC_H`, `VSL_DSP_Packet`. Core file: `legacy/vsl_hid_io.py` (9 symbols). Documented purpose: VSL-DSP Core Logic Module Implementa las funciones matemáticas de encoding/decoding. Traducción 1:1 del código C desensamblado..

## Files

| File | Language | Layer | Symbols | Doc |
|------|----------|-------|---------|-----|
| `legacy/main.c` | c | utility | 1 | no |
| `legacy/test_connection.c` | c | testing | 1 | yes |
| `legacy/vsl_config.h` | h | infrastructure | 8 | yes |
| `legacy/vsl_core.py` | py | utility | 5 | yes |
| `legacy/vsl_dsp_logic.c` | c | business_logic | 5 | yes |
| `legacy/vsl_dsp_logic.h` | h | business_logic | 7 | yes |
| `legacy/vsl_dsp_transport.c` | c | utility | 5 | yes |
| `legacy/vsl_dsp_transport.h` | h | utility | 7 | yes |
| `legacy/vsl_hid_io.py` | py | utility | 9 | yes |
| `legacy/vsl_poc_main.py` | py | utility | 7 | yes |
| `legacy/vsl_transport.py` | py | utility | 8 | yes |

## Key Symbols

- `main` (function, `legacy/main.c:5`) `int main()`
- `main` (function, `legacy/test_connection.c:7`) `int main()`
- `VSL_CONFIG_H` (macro, `legacy/vsl_config.h:4`) `#define VSL_CONFIG_H`
- `VSL_VENDOR_ID` (macro, `legacy/vsl_config.h:11`) `#define VSL_VENDOR_ID`
- `VSL_PRODUCT_ID` (macro, `legacy/vsl_config.h:12`) `#define VSL_PRODUCT_ID`
- `VSL_REPORT_ID` (macro, `legacy/vsl_config.h:13`) `#define VSL_REPORT_ID`
- `VSL_SCALE_FACTOR` (macro, `legacy/vsl_config.h:20`) `#define VSL_SCALE_FACTOR`
- `VSL_MAX_ENCODED_INT` (macro, `legacy/vsl_config.h:23`) `#define VSL_MAX_ENCODED_INT`
- `VSL_PACKET_SIZE` (macro, `legacy/vsl_config.h:25`) `#define VSL_PACKET_SIZE`
- `VSL_PAYLOAD_SIZE` (macro, `legacy/vsl_config.h:26`) `#define VSL_PAYLOAD_SIZE`
- `vsl_encode_gain` (function, `legacy/vsl_core.py:16`) `def vsl_encode_gain(linear_value, param)` - Traducción de FUN_00132c90 (VSL_Encode_Gain en C).
- `vsl_map_frequency` (function, `legacy/vsl_core.py:58`) `def vsl_map_frequency(linear_position, param)` - Traducción de FUN_00132d00 (VSL_Map_Frequency en C).
- `vsl_final_encode_to_int` (function, `legacy/vsl_core.py:94`) `def vsl_final_encode_to_int(encoded_float, param)` - Traducción de VSL_Final_Encode_To_Int en C.
- `vsl_decode_frequency` (function, `legacy/vsl_core.py:127`) `def vsl_decode_frequency(freq_hz_value, param)` - Traducción de FUN_00132da8 (VSL_Decode_Frequency en C).
- `validate_parameter` (function, `legacy/vsl_core.py:170`) `def validate_parameter(param)` - Valida la integridad de un VSLParameter.
- `VSL_Build_And_Send_Packet` (function, `legacy/vsl_dsp_logic.c:4`) `void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float);` - Declaración de la nueva función de envío
- `VSL_Encode_Gain` (function, `legacy/vsl_dsp_logic.c:11`) `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)` - Implementación de FUN_00132c90
- `VSL_Map_Frequency` (function, `legacy/vsl_dsp_logic.c:29`) `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)` - Implementación de FUN_00132d00
- `VSL_Final_Encode_To_Int` (function, `legacy/vsl_dsp_logic.c:58`) `uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param` - @brief Convierte el valor codificado en float a un entero sin signo para el firmware. @note Basado e
- `VSL_Decode_Frequency` (function, `legacy/vsl_dsp_logic.c:78`) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)` - Implementación de FUN_00132da8
- `VSL_DSP_LOGIC_H` (macro, `legacy/vsl_dsp_logic.h:2`) `#define VSL_DSP_LOGIC_H`
- `VSL_INV_LN2` (macro, `legacy/vsl_dsp_logic.h:10`) `#define VSL_INV_LN2`
- `VSL_Parameter` (struct, `legacy/vsl_dsp_logic.h:13`) - Estructura que almacena todos los coeficientes precalculados del DSP
- `VSL_Encode_Gain` (function, `legacy/vsl_dsp_logic.h:42`) `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);` - @brief Codifica un valor lineal (ej. 0.5) a la escala exponencial/logarítmica del DSP (Ganancia/Volu
- `VSL_Map_Frequency` (function, `legacy/vsl_dsp_logic.h:50`) `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);` - @brief Convierte una posición lineal (ej. 0.5) a su frecuencia logarítmica (Hz) real. @param linear_
- `VSL_Final_Encode_To_Int` (function, `legacy/vsl_dsp_logic.h:60`) `uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param` - @brief Convierte el valor codificado en float a un entero sin signo para el firmware. @note ESTA FUN
- `VSL_Decode_Frequency` (function, `legacy/vsl_dsp_logic.h:73`) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);` - @brief Decodifica una frecuencia real (Hz) del DSP a su posición lineal de control (0.0 a 1.0). @par
- `VSL_Init_Device` (function, `legacy/vsl_dsp_transport.c:23`) `int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)`
- `VSL_Close_Device` (function, `legacy/vsl_dsp_transport.c:70`) `void VSL_Close_Device(void)`
- `VSL_Get_Device_Handle` (function, `legacy/vsl_dsp_transport.c:79`) `hid_device* VSL_Get_Device_Handle(void)`

## Internal vs External Edges

- Internal resolved imports (EXTRACTED): 19
- Cross-boundary resolved imports (EXTRACTED): 0

## Connections

- [INFERRED] shares_context community 0 <-> 2 (strength 0.5): Inferred shared context (language c) with no import path between community 0 (root) and community 2 (legacy).
- [INFERRED] shares_context community 1 <-> 2 (strength 0.5): Inferred shared context (language c) with no import path between community 1 (avatar) and community 2 (legacy).
- [INFERRED] shares_context community 2 <-> 3 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 2 (legacy) and community 3 (src).
- [INFERRED] shares_context community 2 <-> 4 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 2 (legacy) and community 4 (voicecloak/src).
- [INFERRED] shares_context community 2 <-> 5 (strength 0.5): Inferred shared context (layer utility) with no import path between community 2 (legacy) and community 5 (orphans).

## Risks

- No scoped security, taint, cycle, or layer risks.

## Open Questions

- Why do 1 file(s) lack file-level docs (e.g. `legacy/main.c`)? What purpose do they serve?
- What would break if the most connected file in legacy changed?
- Should legacy be split, given cohesion 1.00?

## Sources

- `legacy/main.c`
- `legacy/test_connection.c`
- `legacy/vsl_config.h`
- `legacy/vsl_core.py`
- `legacy/vsl_dsp_logic.c`
- `legacy/vsl_dsp_logic.h`
- `legacy/vsl_dsp_transport.c`
- `legacy/vsl_dsp_transport.h`
- `legacy/vsl_hid_io.py`
- `legacy/vsl_poc_main.py`
- `legacy/vsl_transport.py`
