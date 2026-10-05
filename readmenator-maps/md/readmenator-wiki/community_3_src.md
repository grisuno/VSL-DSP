# src

*Community 3 | 6 files | cohesion 1.00*

## Definition

This community groups 6 file(s) rooted at `src` with dominant language c (cohesion 1.00). Central symbols: `MAX_CHANNELS`, `ParamEntry`, `VSL_CONFIG_H`, `VSL_Close_Device`, `VSL_DSP_LOGIC_H`, `VSL_DSP_TRANSPORT_H`, `VSL_Decode_Frequency`, `VSL_Decode_Gain`. Core file: `src/vsl_config.h` (13 symbols).

## Files

| File | Language | Layer | Symbols | Doc |
|------|----------|-------|---------|-----|
| `src/vsl_cli.c` | c | utility | 10 | no |
| `src/vsl_config.h` | h | infrastructure | 13 | no |
| `src/vsl_dsp_logic.c` | c | business_logic | 5 | no |
| `src/vsl_dsp_logic.h` | h | business_logic | 9 | no |
| `src/vsl_dsp_transport.c` | c | utility | 4 | no |
| `src/vsl_dsp_transport.h` | h | utility | 5 | no |

## Key Symbols

- `ParamEntry` (struct, `src/vsl_cli.c:15`)
- `MAX_CHANNELS` (macro, `src/vsl_cli.c:48`) `#define MAX_CHANNELS`
- `print_usage` (function, `src/vsl_cli.c:58`) `static void print_usage(FILE *fp, const char *prog)`
- `print_version` (function, `src/vsl_cli.c:84`) `static void print_version(void)`
- `print_list` (function, `src/vsl_cli.c:91`) `static void print_list(uint16_t product_id)`
- `lookup_coeffs_by_param_id` (function, `src/vsl_cli.c:111`) `static const VSL_Parameter * lookup_coeffs_by_param_id(uint16_t param_id)`
- `find_entry_by_name` (function, `src/vsl_cli.c:121`) `static const ParamEntry * find_entry_by_name(const char *name)`
- `do_send` (function, `src/vsl_cli.c:130`) `static int do_send(uint16_t product_id,                    uint16_t param_id,`
- `do_send_freq` (function, `src/vsl_cli.c:168`) `static int do_send_freq(uint16_t product_id,                         uint16_t pa`
- `main` (function, `src/vsl_cli.c:205`) `int main(int argc, char *argv[])`
- `VSL_CONFIG_H` (macro, `src/vsl_config.h:2`) `#define VSL_CONFIG_H`
- `pid` (variable, `src/vsl_config.h:8`) `extern "C" { #endif #define VSL_VENDOR_ID 0x194fU #define VSL_PRODUCT_ID_22VSL 0` - ifdef __cplusplus
- `VSL_VENDOR_ID` (macro, `src/vsl_config.h:11`) `#define VSL_VENDOR_ID`
- `VSL_PRODUCT_ID_22VSL` (macro, `src/vsl_config.h:12`) `#define VSL_PRODUCT_ID_22VSL`
- `VSL_PRODUCT_ID_44VSL` (macro, `src/vsl_config.h:13`) `#define VSL_PRODUCT_ID_44VSL`
- `VSL_PRODUCT_ID_1818VSL` (macro, `src/vsl_config.h:14`) `#define VSL_PRODUCT_ID_1818VSL`
- `VSL_REPORT_ID` (macro, `src/vsl_config.h:16`) `#define VSL_REPORT_ID`
- `VSL_PACKET_SIZE` (macro, `src/vsl_config.h:17`) `#define VSL_PACKET_SIZE`
- `VSL_MIDI_IFACE` (macro, `src/vsl_config.h:18`) `#define VSL_MIDI_IFACE`
- `VSL_EP_MIDI_OUT` (macro, `src/vsl_config.h:19`) `#define VSL_EP_MIDI_OUT`
- `VSL_ModelInfo` (struct, `src/vsl_config.h:21`)
- `VSL_ModelLookup` (function, `src/vsl_config.h:37`) `static inline const VSL_ModelInfo * VSL_ModelLookup(uint16_t pid)`
- `VSL_ModelLookupByTag` (function, `src/vsl_config.h:49`) `static inline const VSL_ModelInfo * VSL_ModelLookupByTag(const char *tag)`
- `VSL_Encode_Gain` (function, `src/vsl_dsp_logic.c:3`) `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)`
- `VSL_Decode_Gain` (function, `src/vsl_dsp_logic.c:16`) `float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param)`
- `VSL_Map_Frequency` (function, `src/vsl_dsp_logic.c:50`) `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)`
- `VSL_Final_Encode_To_Int` (function, `src/vsl_dsp_logic.c:66`) `uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param`
- `VSL_Decode_Frequency` (function, `src/vsl_dsp_logic.c:76`) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)`
- `VSL_DSP_LOGIC_H` (macro, `src/vsl_dsp_logic.h:2`) `#define VSL_DSP_LOGIC_H`
- `VSL_INV_LN2` (macro, `src/vsl_dsp_logic.h:8`) `#define VSL_INV_LN2`

## Internal vs External Edges

- Internal resolved imports (EXTRACTED): 7
- Cross-boundary resolved imports (EXTRACTED): 0

## Connections

- [INFERRED] shares_context community 0 <-> 3 (strength 0.5): Inferred shared context (language c) with no import path between community 0 (root) and community 3 (src).
- [INFERRED] shares_context community 1 <-> 3 (strength 0.5): Inferred shared context (language c) with no import path between community 1 (avatar) and community 3 (src).
- [INFERRED] shares_context community 2 <-> 3 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 2 (legacy) and community 3 (src).
- [INFERRED] shares_context community 3 <-> 4 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 3 (src) and community 4 (voicecloak/src).
- [INFERRED] shares_context community 3 <-> 5 (strength 0.5): Inferred shared context (layer utility) with no import path between community 3 (src) and community 5 (orphans).

## Risks

- No scoped security, taint, cycle, or layer risks.

## Open Questions

- Why do 6 file(s) lack file-level docs (e.g. `src/vsl_cli.c`)? What purpose do they serve?
- What would break if the most connected file in src changed?
- Should src be split, given cohesion 1.00?

## Sources

- `src/vsl_cli.c`
- `src/vsl_config.h`
- `src/vsl_dsp_logic.c`
- `src/vsl_dsp_logic.h`
- `src/vsl_dsp_transport.c`
- `src/vsl_dsp_transport.h`
