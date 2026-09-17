# Subsystem: src

## src/vsl_cli.c
- Layer: utility
- Language: c
- Symbols:
  - `ParamEntry` (struct, line 15)
  - `print_usage` (function, line 58) `static void print_usage(FILE *fp, const char *prog)`
  - `print_version` (function, line 84) `static void print_version(void)`
  - `print_list` (function, line 91) `static void print_list(uint16_t product_id)`
  - `lookup_coeffs_by_param_id` (function, line 111) `static const VSL_Parameter *
lookup_coeffs_by_param_id(uint16_t param_id)`
  - `find_entry_by_name` (function, line 121) `static const ParamEntry *
find_entry_by_name(const char *name)`
  - `do_send` (function, line 130) `static int do_send(uint16_t product_id,
                   uint16_t param_id,
                   ...`
  - `do_send_freq` (function, line 168) `static int do_send_freq(uint16_t product_id,
                        uint16_t param_id,
         ...`
  - `main` (function, line 205) `int main(int argc, char *argv[])`
  - `MAX_CHANNELS` (macro, line 48) `#define MAX_CHANNELS`
- Depends on: `src/vsl_config.h`, `src/vsl_dsp_logic.h`, `src/vsl_dsp_transport.h`

## src/vsl_config.h
- Layer: infrastructure
- Language: h
- Symbols:
  - `VSL_ModelInfo` (struct, line 21)
  - `VSL_ModelLookup` (function, line 37) `static inline const VSL_ModelInfo *
VSL_ModelLookup(uint16_t pid)`
  - `VSL_ModelLookupByTag` (function, line 49) `static inline const VSL_ModelInfo *
VSL_ModelLookupByTag(const char *tag)`
  - `pid` (variable, line 8) `extern "C" { #endif #define VSL_VENDOR_ID 0x194fU #define VSL_PRODUCT_ID_22VSL 0x0101U #define VSL_PRODUCT_ID_44VSL 0x0102U #define VSL_PRODUCT_ID_1818VSL 0x0103U #define VSL_REPORT_ID 0x06U #define V`
  - `VSL_CONFIG_H` (macro, line 2) `#define VSL_CONFIG_H`
  - `VSL_VENDOR_ID` (macro, line 11) `#define VSL_VENDOR_ID`
  - `VSL_PRODUCT_ID_22VSL` (macro, line 12) `#define VSL_PRODUCT_ID_22VSL`
  - `VSL_PRODUCT_ID_44VSL` (macro, line 13) `#define VSL_PRODUCT_ID_44VSL`
  - `VSL_PRODUCT_ID_1818VSL` (macro, line 14) `#define VSL_PRODUCT_ID_1818VSL`
  - `VSL_REPORT_ID` (macro, line 16) `#define VSL_REPORT_ID`
  - `VSL_PACKET_SIZE` (macro, line 17) `#define VSL_PACKET_SIZE`
  - `VSL_MIDI_IFACE` (macro, line 18) `#define VSL_MIDI_IFACE`
  - `VSL_EP_MIDI_OUT` (macro, line 19) `#define VSL_EP_MIDI_OUT`
- Imported by: `src/vsl_cli.c`, `src/vsl_dsp_transport.h`

## src/vsl_dsp_logic.c
- Layer: business_logic
- Language: c
- Symbols:
  - `VSL_Encode_Gain` (function, line 3) `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)`
  - `VSL_Decode_Gain` (function, line 16) `float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param)`
  - `VSL_Map_Frequency` (function, line 50) `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)`
  - `VSL_Final_Encode_To_Int` (function, line 66) `uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)`
  - `VSL_Decode_Frequency` (function, line 76) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)`
- Depends on: `src/vsl_dsp_logic.h`

## src/vsl_dsp_logic.h
- Layer: business_logic
- Language: h
- Symbols:
  - `VSL_Parameter` (struct, line 11)
  - `VSL_Encode_Gain` (function, line 33) `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);`
  - `VSL_Decode_Gain` (function, line 42) `float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param);`
  - `VSL_Map_Frequency` (function, line 51) `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);`
  - `VSL_Decode_Frequency` (function, line 60) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);`
  - `VSL_Final_Encode_To_Int` (function, line 70) `uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param);`
  - `VSL_DSP_LOGIC_H` (macro, line 2) `#define VSL_DSP_LOGIC_H`
  - `VSL_INV_LN2` (macro, line 8) `#define VSL_INV_LN2`
  - `VSL_MAX_ENCODED_FLOAT` (macro, line 9) `#define VSL_MAX_ENCODED_FLOAT`
- Imported by: `src/vsl_cli.c`, `src/vsl_dsp_logic.c`, `src/vsl_dsp_transport.h`

## src/vsl_dsp_transport.c
- Layer: utility
- Language: c
- Symbols:
  - `vsl_device` (struct, line 7)
  - `VSL_Init_Device` (function, line 13) `vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)`
  - `VSL_Close_Device` (function, line 45) `void VSL_Close_Device(vsl_device_handle handle)`
  - `VSL_Send_Parameter` (function, line 61) `int VSL_Send_Parameter(vsl_device_handle handle,
                       uint16_t dsp_param_id,
  ...`
- Depends on: `src/vsl_dsp_transport.h`

## src/vsl_dsp_transport.h
- Layer: utility
- Language: h
- Symbols:
  - `vsl_device_handle` (type_alias, line 11) `typedef void* vsl_device_handle;`
  - `VSL_Close_Device` (function, line 26) `void VSL_Close_Device(vsl_device_handle handle);`
  - `VSL_Send_Parameter` (function, line 35) `int VSL_Send_Parameter(vsl_device_handle handle, uint16_t dsp_param_id, uint16_t encoded_value);`
  - `vsl_device_handle` (variable, line 9) `extern "C" { #endif typedef void* vsl_device_handle;`
  - `VSL_DSP_TRANSPORT_H` (macro, line 2) `#define VSL_DSP_TRANSPORT_H`
- Depends on: `src/vsl_config.h`, `src/vsl_dsp_logic.h`
- Imported by: `src/vsl_cli.c`, `src/vsl_dsp_transport.c`
