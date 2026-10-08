# Subsystem: src

## src/vsl_cli.c
- Layer: utility
- Language: c
- Symbols:
  - `ParamEntry` (struct, line 16)
  - `print_usage` (function, line 61) `static void print_usage(FILE *fp, const char *prog)`
  - `print_version` (function, line 88) `static void print_version(void)`
  - `print_list` (function, line 95) `static void print_list(uint16_t product_id)`
  - `lookup_coeffs_by_param_id` (function, line 115) `static const VSL_Parameter *
lookup_coeffs_by_param_id(uint16_t param_id)`
  - `find_entry_by_name` (function, line 125) `static const ParamEntry *
find_entry_by_name(const char *name)`
  - `do_send` (function, line 134) `static int do_send(uint16_t product_id,
                   uint16_t param_id,
                   ...`
  - `do_send_freq` (function, line 172) `static int do_send_freq(uint16_t product_id,
                        uint16_t param_id,
         ...`
  - `main` (function, line 209) `int main(int argc, char *argv[])`
  - `MAX_CHANNELS` (macro, line 49) `#define MAX_CHANNELS`
- Depends on: `src/vsl_config.h`, `src/vsl_dsp_logic.h`, `src/vsl_dsp_transport.h`

## src/vsl_config.h
- Doc: pid: ifdef __cplusplus
- Layer: infrastructure
- Language: h
- Symbols:
  - `VSL_ModelInfo` (struct, line 22)
  - `VSL_ModelLookup` (function, line 38) `static inline const VSL_ModelInfo *
VSL_ModelLookup(uint16_t pid)`
  - `VSL_ModelLookupByTag` (function, line 50) `static inline const VSL_ModelInfo *
VSL_ModelLookupByTag(const char *tag)`
  - `pid` (variable, line 8) `extern "C" { #endif #define VSL_VENDOR_ID 0x194fU #define VSL_PRODUCT_ID_22VSL 0x0101U #define VSL_PRODUCT_ID_44VSL...`
  - `VSL_CONFIG_H` (macro, line 2) `#define VSL_CONFIG_H`
  - `VSL_VENDOR_ID` (macro, line 11) `#define VSL_VENDOR_ID`
  - `VSL_PRODUCT_ID_22VSL` (macro, line 12) `#define VSL_PRODUCT_ID_22VSL`
  - `VSL_PRODUCT_ID_44VSL` (macro, line 13) `#define VSL_PRODUCT_ID_44VSL`
  - `VSL_PRODUCT_ID_1818VSL` (macro, line 14) `#define VSL_PRODUCT_ID_1818VSL`
  - `VSL_REPORT_ID` (macro, line 16) `#define VSL_REPORT_ID`
  - `VSL_PACKET_SIZE` (macro, line 17) `#define VSL_PACKET_SIZE`
  - `VSL_MIDI_IFACE` (macro, line 18) `#define VSL_MIDI_IFACE`
  - `VSL_EP_MIDI_OUT` (macro, line 19) `#define VSL_EP_MIDI_OUT`
  - `VSL_USB_TIMEOUT_MS` (macro, line 20) `#define VSL_USB_TIMEOUT_MS`
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
  - `VSL_Linear_To_DB` (function, line 95) `float VSL_Linear_To_DB(float linear_value)`
  - `VSL_DB_To_Linear` (function, line 105) `float VSL_DB_To_Linear(float db_value)`
- Depends on: `src/vsl_dsp_logic.h`

## src/vsl_dsp_logic.h
- Doc: VSL_Encode_Gain: @brief Encodes a linear gain value [0.0, 1.0] to the DSP exponential curve....
- Layer: business_logic
- Language: h
- Symbols:
  - `VSL_Parameter` (struct, line 22)
  - `VSL_Encode_Gain` (function, line 44) `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);`
  - `VSL_Decode_Gain` (function, line 53) `float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param);`
  - `VSL_Map_Frequency` (function, line 62) `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);`
  - `VSL_Decode_Frequency` (function, line 71) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);`
  - `VSL_Final_Encode_To_Int` (function, line 81) `uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param);`
  - `negative` (function, line 87) `* when linear_value is zero or negative (the `db.inf` domain). */ float VSL_Linear_To_DB(float linear_value);`
  - `VSL_DB_To_Linear` (function, line 97) `float VSL_DB_To_Linear(float db_value);`
  - `VSL_DSP_LOGIC_H` (macro, line 2) `#define VSL_DSP_LOGIC_H`
  - `VSL_INV_LN2` (macro, line 8) `#define VSL_INV_LN2`
  - `VSL_MAX_ENCODED_FLOAT` (macro, line 9) `#define VSL_MAX_ENCODED_FLOAT`
  - `VSL_DB_NEG_INF` (macro, line 19) `#define VSL_DB_NEG_INF`
  - `VSL_DB_FLOOR_LINEAR` (macro, line 20) `#define VSL_DB_FLOOR_LINEAR`
- Imported by: `src/vsl_cli.c`, `src/vsl_dsp_logic.c`, `src/vsl_dsp_transport.h`

## src/vsl_dsp_transport.c
- Layer: utility
- Language: c
- Symbols:
  - `vsl_device` (struct, line 7)
  - `VSL_Init_Device` (function, line 13) `vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)`
  - `VSL_Close_Device` (function, line 50) `void VSL_Close_Device(vsl_device_handle handle)`
  - `VSL_Build_Packet` (function, line 79) `int VSL_Build_Packet(uint16_t dsp_param_id,
                     uint16_t encoded_value,
        ...`
  - `VSL_Send_Parameter` (function, line 96) `int VSL_Send_Parameter(vsl_device_handle handle,
                       uint16_t dsp_param_id,
  ...`
- Depends on: `src/vsl_dsp_transport.h`

## src/vsl_dsp_transport.h
- Doc: VSL_Close_Device: @brief Release the MIDI interface and close the device. @param handle Handle...
- Layer: utility
- Language: h
- Symbols:
  - `vsl_device_handle` (type_alias, line 11) `typedef void* vsl_device_handle;`
  - `VSL_Close_Device` (function, line 26) `void VSL_Close_Device(vsl_device_handle handle);`
  - `evidence` (function, line 37) `* evidence (blockers #2/#3);`
  - `VSL_Build_Packet` (function, line 39) `int VSL_Build_Packet(uint16_t dsp_param_id, uint16_t encoded_value, unsigned char *out);`
  - `VSL_Send_Parameter` (function, line 50) `int VSL_Send_Parameter(vsl_device_handle handle, uint16_t dsp_param_id, uint16_t encoded_value);`
  - `vsl_device_handle` (variable, line 9) `extern "C" { #endif typedef void* vsl_device_handle;`
  - `VSL_DSP_TRANSPORT_H` (macro, line 2) `#define VSL_DSP_TRANSPORT_H`
- Depends on: `src/vsl_config.h`, `src/vsl_dsp_logic.h`
- Imported by: `src/vsl_cli.c`, `src/vsl_dsp_transport.c`
