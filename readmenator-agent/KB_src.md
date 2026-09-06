# Subsystem: src

## src/vsl_cli.c
- Layer: utility
- Doc: include <stdio.h> include <stdlib.h> include <string.h> include <math.h> include <stdint.h> include "vsl_dsp_logic.h" in
- Language: c
- Symbols:
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
  - `MAX_CHANNELS` (macro, line 47)

## src/vsl_config.h
- Layer: infrastructure
- Doc: ifndef VSL_CONFIG_H define VSL_CONFIG_H  include <stdint.h> include <stddef.h>  ifdef __cplusplus
- Language: h
- Symbols:
  - `VSL_ModelLookup` (function, line 35) `static inline const VSL_ModelInfo *
VSL_ModelLookup(uint16_t pid)`
  - `VSL_ModelLookupByTag` (function, line 47) `static inline const VSL_ModelInfo *
VSL_ModelLookupByTag(const char *tag)`
  - `VSL_CONFIG_H` (macro, line 2)
  - `VSL_VENDOR_ID` (macro, line 10)
  - `VSL_PRODUCT_ID_22VSL` (macro, line 12)
  - `VSL_PRODUCT_ID_44VSL` (macro, line 13)
  - `VSL_PRODUCT_ID_1818VSL` (macro, line 14)
  - `VSL_REPORT_ID` (macro, line 15)
  - `VSL_PACKET_SIZE` (macro, line 17)
  - `VSL_MIDI_IFACE` (macro, line 18)
  - `VSL_EP_MIDI_OUT` (macro, line 19)

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

## src/vsl_dsp_logic.h
- Layer: business_logic
- Doc: ifndef VSL_DSP_LOGIC_H define VSL_DSP_LOGIC_H  include <stdint.h> include <math.h> include <float.h>  define VSL_INV_LN2
- Language: h
- Symbols:
  - `VSL_DSP_LOGIC_H` (macro, line 2)
  - `VSL_INV_LN2` (macro, line 7)
  - `VSL_MAX_ENCODED_FLOAT` (macro, line 9)

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

## src/vsl_dsp_transport.h
- Layer: utility
- Doc: ifndef VSL_DSP_TRANSPORT_H define VSL_DSP_TRANSPORT_H  include <stdint.h> include "vsl_dsp_logic.h" include "vsl_config.
- Language: h
- Symbols:
  - `VSL_DSP_TRANSPORT_H` (macro, line 2)
