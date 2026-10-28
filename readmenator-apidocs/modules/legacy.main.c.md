# `legacy/main.c`

> Source: [legacy/main.c:1](../../legacy/main.c#L1) | language `c` | coverage 0.0% | [API index](../index.md)

## Contents

- **Functions:** [`main`](#main)

## Call Graph

Solid arrows stay in this module, dashed arrows leave it.

```mermaid
flowchart LR
    n_legacy_main_c__main(["main"])
    n_legacy_vsl_dsp_logic_h__VSL_Decode_Frequency["vsl_dsp_logic.VSL_Decode_Frequency"]
    n_legacy_vsl_dsp_logic_h__VSL_Encode_Gain["vsl_dsp_logic.VSL_Encode_Gain"]
    n_legacy_vsl_dsp_logic_h__VSL_Final_Encode_To_Int["vsl_dsp_logic.VSL_Final_Encode_To_Int"]
    n_legacy_vsl_dsp_logic_h__VSL_Map_Frequency["vsl_dsp_logic.VSL_Map_Frequency"]
    n_legacy_vsl_dsp_transport_h__VSL_Build_And_Send_Packet["vsl_dsp_transport.VSL_Build_And_Send_Packet"]
    n_legacy_main_c__main -.-> n_legacy_vsl_dsp_logic_h__VSL_Decode_Frequency
    n_legacy_main_c__main -.-> n_legacy_vsl_dsp_logic_h__VSL_Encode_Gain
    n_legacy_main_c__main -.-> n_legacy_vsl_dsp_logic_h__VSL_Final_Encode_To_Int
    n_legacy_main_c__main -.-> n_legacy_vsl_dsp_logic_h__VSL_Map_Frequency
    n_legacy_main_c__main -.-> n_legacy_vsl_dsp_transport_h__VSL_Build_And_Send_Packet
```

## Functions

<a id="main"></a>

### `main`

`function` | [legacy/main.c:5](../../legacy/main.c#L5)

```c
int main()
```

**Returns:** `int`

*Calls:* [`VSL_Decode_Frequency`](legacy.vsl_dsp_logic.h.md#vsl_decode_frequency), [`VSL_Encode_Gain`](legacy.vsl_dsp_logic.h.md#vsl_encode_gain), [`VSL_Final_Encode_To_Int`](legacy.vsl_dsp_logic.h.md#vsl_final_encode_to_int), [`VSL_Map_Frequency`](legacy.vsl_dsp_logic.h.md#vsl_map_frequency), [`VSL_Build_And_Send_Packet`](legacy.vsl_dsp_transport.h.md#vsl_build_and_send_packet)

---
