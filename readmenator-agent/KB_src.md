# Subsystem: src

## src/vsl_cli.c
- Layer: utility
- Doc: include <stdio.h> include <stdlib.h> include <string.h> include <math.h> include <stdint.h> include "vsl_dsp_logic.h" in
- Language: c
- Symbols:
  - `ParamEntry` (struct, line 15)
  - `print_usage` (function, line 57) `static void print_usage(FILE *fp, const char *prog)`
  - `print_version` (function, line 83) `static void print_version(void)`
  - `print_list` (function, line 90) `static void print_list(uint16_t product_id)`
  - `lookup_coeffs_by_param_id` (function, line 109) `static const VSL_Parameter *
lookup_coeffs_by_param_id(uint16_t param_id)`
  - `find_entry_by_name` (function, line 119) `static const ParamEntry *
find_entry_by_name(const char *name)`
  - `do_send` (function, line 129) `static int do_send(uint16_t product_id,
                   uint16_t param_id,
                   ...`
  - `do_send_freq` (function, line 167) `static int do_send_freq(uint16_t product_id,
                        uint16_t param_id,
         ...`
  - `main` (function, line 204) `int main(int argc, char *argv[])`
  - `fprintf` (function, line 60) `fprintf(fp, "Usage: %s [OPTIONS] COMMAND [ARGS...]\n" "\n" "Options:\n" " -p, --pid <hex> USB product ID (default: 0x0101 = 22 VSL)\n" " -m, --model <tag> Model tag: 22vsl, 44vsl, 1818vsl\n" " -h, --h`
  - `printf` (function, line 86) `printf("vsl-cli 2.0.0\n" "PreSonus AudioBox VSL DSP control tool\n" "License: AGPL-3.0-or-later\n");`
  - `VSL_Close_Device` (function, line 163) `VSL_Close_Device(dev);`
  - `fmaxf` (function, line 186) `fmaxf(0.0f, fminf(freq_hz / coeffs->freq_max_hz, 1.0f)), coeffs);`
  - `MAX_CHANNELS` (macro, line 47) `#define MAX_CHANNELS`
- Depends on: `src/vsl_config.h`, `src/vsl_dsp_logic.h`, `src/vsl_dsp_transport.h`

## src/vsl_config.h
- Layer: infrastructure
- Doc: ifndef VSL_CONFIG_H define VSL_CONFIG_H  include <stdint.h> include <stddef.h>  ifdef __cplusplus
- Language: h
- Symbols:
  - `VSL_ModelInfo` (struct, line 21)
  - `VSL_ModelLookup` (function, line 35) `static inline const VSL_ModelInfo *
VSL_ModelLookup(uint16_t pid)`
  - `VSL_ModelLookupByTag` (function, line 47) `static inline const VSL_ModelInfo *
VSL_ModelLookupByTag(const char *tag)`
  - `pid` (variable, line 8) `extern "C" { #endif #define VSL_VENDOR_ID 0x194fU #define VSL_PRODUCT_ID_22VSL 0x0101U #define VSL_PRODUCT_ID_44VSL 0x0102U #define VSL_PRODUCT_ID_1818VSL 0x0103U #define VSL_REPORT_ID 0x06U #define V`
  - `VSL_CONFIG_H` (macro, line 2) `#define VSL_CONFIG_H`
  - `VSL_VENDOR_ID` (macro, line 10) `#define VSL_VENDOR_ID`
  - `VSL_PRODUCT_ID_22VSL` (macro, line 12) `#define VSL_PRODUCT_ID_22VSL`
  - `VSL_PRODUCT_ID_44VSL` (macro, line 13) `#define VSL_PRODUCT_ID_44VSL`
  - `VSL_PRODUCT_ID_1818VSL` (macro, line 14) `#define VSL_PRODUCT_ID_1818VSL`
  - `VSL_REPORT_ID` (macro, line 15) `#define VSL_REPORT_ID`
  - `VSL_PACKET_SIZE` (macro, line 17) `#define VSL_PACKET_SIZE`
  - `VSL_MIDI_IFACE` (macro, line 18) `#define VSL_MIDI_IFACE`
  - `VSL_EP_MIDI_OUT` (macro, line 19) `#define VSL_EP_MIDI_OUT`
- Imported by: `src/vsl_cli.c`, `src/vsl_dsp_transport.h`

## src/vsl_dsp_logic.c
- Layer: business_logic
- Doc: include "vsl_dsp_logic.h"
- Language: c
- Symbols:
  - `VSL_Encode_Gain` (function, line 2) `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)`
  - `VSL_Decode_Gain` (function, line 15) `float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param)`
  - `VSL_Map_Frequency` (function, line 49) `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)`
  - `VSL_Final_Encode_To_Int` (function, line 65) `uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)`
  - `VSL_Decode_Frequency` (function, line 75) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)`
  - `fmaxf` (function, line 20) `return fmaxf(0.0f, fminf(r, 1.0f));`
  - `exp2f` (function, line 62) `return exp2f(log2_value);`
- Depends on: `src/vsl_dsp_logic.h`

## src/vsl_dsp_logic.h
- Layer: business_logic
- Doc: ifndef VSL_DSP_LOGIC_H define VSL_DSP_LOGIC_H  include <stdint.h> include <math.h> include <float.h>  define VSL_INV_LN2
- Language: h
- Symbols:
  - `VSL_Parameter` (struct, line 11)
  - `VSL_Encode_Gain` (function, line 33) `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);`
  - `VSL_Decode_Gain` (function, line 42) `float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param);`
  - `VSL_Map_Frequency` (function, line 51) `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);`
  - `VSL_Decode_Frequency` (function, line 60) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);`
  - `VSL_Final_Encode_To_Int` (function, line 70) `uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param);`
  - `VSL_DSP_LOGIC_H` (macro, line 2) `#define VSL_DSP_LOGIC_H`
  - `VSL_INV_LN2` (macro, line 7) `#define VSL_INV_LN2`
  - `VSL_MAX_ENCODED_FLOAT` (macro, line 9) `#define VSL_MAX_ENCODED_FLOAT`
- Imported by: `src/vsl_cli.c`, `src/vsl_dsp_logic.c`, `src/vsl_dsp_transport.h`

## src/vsl_dsp_transport.c
- Layer: utility
- Doc: include "vsl_dsp_transport.h" include <stdio.h> include <stdlib.h> include <string.h> include <libusb-1.0/libusb.h>
- Language: c
- Symbols:
  - `vsl_device` (struct, line 7)
  - `VSL_Init_Device` (function, line 12) `vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)`
  - `VSL_Close_Device` (function, line 44) `void VSL_Close_Device(vsl_device_handle handle)`
  - `VSL_Send_Parameter` (function, line 60) `int VSL_Send_Parameter(vsl_device_handle handle,
                       uint16_t dsp_param_id,
  ...`
  - `free` (function, line 21) `free(dev);`
  - `libusb_exit` (function, line 27) `libusb_exit(NULL);`
  - `libusb_set_auto_detach_kernel_driver` (function, line 34) `libusb_set_auto_detach_kernel_driver(dev->handle, 1);`
  - `libusb_detach_kernel_driver` (function, line 38) `libusb_detach_kernel_driver(dev->handle, VSL_MIDI_IFACE);`
  - `libusb_claim_interface` (function, line 40) `libusb_claim_interface(dev->handle, VSL_MIDI_IFACE);`
  - `libusb_release_interface` (function, line 53) `libusb_release_interface(dev->handle, VSL_MIDI_IFACE);`
  - `libusb_attach_kernel_driver` (function, line 54) `libusb_attach_kernel_driver(dev->handle, VSL_MIDI_IFACE);`
  - `libusb_close` (function, line 55) `libusb_close(dev->handle);`
  - `memset` (function, line 72) `memset(buf, 0, sizeof(buf));`
  - `fprintf` (function, line 83) `fprintf(stderr, "VSL_Send_Parameter: bulk write failed: %s\n", libusb_error_name(ret));`
- Depends on: `src/vsl_dsp_transport.h`

## src/vsl_dsp_transport.h
- Layer: utility
- Doc: ifndef VSL_DSP_TRANSPORT_H define VSL_DSP_TRANSPORT_H  include <stdint.h> include "vsl_dsp_logic.h" include "vsl_config.
- Language: h
- Symbols:
  - `vsl_device_handle` (type_alias, line 11) `typedef void* vsl_device_handle;`
  - `VSL_Init_Device` (function, line 20) `vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id);`
  - `VSL_Close_Device` (function, line 26) `void VSL_Close_Device(vsl_device_handle handle);`
  - `VSL_Send_Parameter` (function, line 35) `int VSL_Send_Parameter(vsl_device_handle handle, uint16_t dsp_param_id, uint16_t encoded_value);`
  - `vsl_device_handle` (variable, line 9) `extern "C" { #endif typedef void* vsl_device_handle;`
  - `VSL_DSP_TRANSPORT_H` (macro, line 2) `#define VSL_DSP_TRANSPORT_H`
- Depends on: `src/vsl_config.h`, `src/vsl_dsp_logic.h`
- Imported by: `src/vsl_cli.c`, `src/vsl_dsp_transport.c`
