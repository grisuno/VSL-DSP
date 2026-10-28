# VSL-DSP Architecture and Execution Flows

[Back to index](index.md)

## Architecture Overview

10 components stacked in 2 dependency tiers (weighted Eades-Lin-Smyth ordering: arrows point from dependent to dependency, top to bottom). Labels are import counts, thick arrows the top quartile; 0 transitively implied edges are omitted. Dashed red arrows are upward dependencies: the smallest set of imports that closes every cycle and breaks the layering. Cyan components hold entry points. Interactive version: `readmenator-apidocs/index.html#/flows`.

Upward dependencies to fix first: `voicecloak/src: vc_crypto` -> `voicecloak/src: vc_denoise` (2 imports); `voicecloak/src: vc_effects` -> `voicecloak/src: vc_denoise` (1 imports)

```mermaid
flowchart TB
    classDef cycle fill:#1f1530,stroke:#f472b6,color:#fce7f3,stroke-width:2px;
    classDef default fill:#111827,stroke:#38bdf8,color:#e5e7eb;
    classDef entry fill:#0e7490,stroke:#22d3ee,color:#ecfeff,stroke-width:2px;
    subgraph lane_0["Tier 1 - entry / orchestration"]
        direction LR
        n_c0["voicecloak/src: vc_denoise<br/>11 files, 128 symbols<br/>Core / utility"]:::cycle
        n_d_tests["tests<br/>1 files, 2 symbols<br/>Infrastructure"]:::default
        n_d_legacy["legacy<br/>4 files, 29 symbols<br/>Core / utility"]:::entry
        n_d__root_["(root)<br/>1 files, 0 symbols<br/>Core / utility"]:::default
        n_c6["avatar<br/>4 files, 41 symbols<br/>Business logic"]:::default
        n_c5["root<br/>3 files, 323 symbols<br/>Core / utility"]:::default
        n_c4["src<br/>6 files, 59 symbols<br/>Core / utility"]:::default
        n_c2["legacy<br/>10 files, 62 symbols<br/>Core / utility"]:::entry
    end
    subgraph lane_1["Tier 2 - foundation"]
        direction LR
        n_c3["voicecloak/src: vc_crypto<br/>10 files, 79 symbols<br/>Core / utility"]:::cycle
        n_c1["voicecloak/src: vc_effects<br/>9 files, 104 symbols<br/>Core / utility"]:::cycle
    end
    n_c0 ==>|"5"| n_c1
    n_c0 -->|"1"| n_c3
    n_c0 <-.-|"1 upward"| n_c1
    n_c0 <-.-|"2 upward"| n_c3
    linkStyle 2,3 stroke:#f87171,stroke-width:2px;
    n_c0 ~~~ n_c3
```

---

## Execution Flows

Entry points are scored from `__main__` guards, `main` functions, entry-style names and files, and call-graph sources. Each flow walks resolved calls in call-site order (depth <= 4, <= 40 steps); numbers give the call order, dashed arrows revisit an already expanded callee, red arrows are recursion. Interactive version with zoom and per-node docs: `readmenator-apidocs/index.html#/flows`.

### `main.main`

`legacy/main.c:5`, score 13: `main` in a compiled-language file; entry-style name `main`; defined in entry file `main.c`.

Call tree:

```mermaid
flowchart LR
    classDef entry fill:#0e7490,stroke:#22d3ee,color:#ecfeff,stroke-width:2px;
    classDef external fill:#1a1530,stroke:#a78bfa,color:#ede9fe;
    n_legacy_main_c__main["main.main<br/>main.c:5"]:::entry
    n_legacy_vsl_dsp_logic_h__VSL_Encode_Gain["vsl_dsp_logic.VSL_Encode_Gain<br/>@brief Codifica un valor lineal (ej.<br/>vsl_dsp_logic.h:42"]:::external
    n_legacy_vsl_dsp_logic_h__VSL_Final_Encode_To_Int["vsl_dsp_logic.VSL_Final_Encode_To_Int<br/>@brief Convierte el valor codificado en float...<br/>vsl_dsp_logic.h:60"]:::external
    n_legacy_vsl_dsp_logic_h__VSL_Map_Frequency["vsl_dsp_logic.VSL_Map_Frequency<br/>@brief Convierte una posición lineal (ej.<br/>vsl_dsp_logic.h:50"]:::external
    n_legacy_vsl_dsp_logic_h__VSL_Decode_Frequency["vsl_dsp_logic.VSL_Decode_Frequency<br/>@brief Decodifica una frecuencia real (Hz) de...<br/>vsl_dsp_logic.h:73"]:::external
    n_legacy_vsl_dsp_transport_h__VSL_Build_And_Send_Packet["vsl_dsp_transport.VSL_Build_And_Send_Packet<br/>vsl_dsp_transport.h:25"]:::external
    n_legacy_main_c__main -.->|"recursion"| n_legacy_main_c__main
    n_legacy_main_c__main -->|"1"| n_legacy_vsl_dsp_logic_h__VSL_Encode_Gain
    n_legacy_vsl_dsp_logic_h__VSL_Encode_Gain -.->|"recursion"| n_legacy_vsl_dsp_logic_h__VSL_Encode_Gain
    n_legacy_main_c__main -->|"2"| n_legacy_vsl_dsp_logic_h__VSL_Final_Encode_To_Int
    n_legacy_vsl_dsp_logic_h__VSL_Final_Encode_To_Int -.->|"recursion"| n_legacy_vsl_dsp_logic_h__VSL_Final_Encode_To_Int
    n_legacy_main_c__main -->|"3"| n_legacy_vsl_dsp_logic_h__VSL_Map_Frequency
    n_legacy_vsl_dsp_logic_h__VSL_Map_Frequency -.->|"recursion"| n_legacy_vsl_dsp_logic_h__VSL_Map_Frequency
    n_legacy_main_c__main -->|"4"| n_legacy_vsl_dsp_logic_h__VSL_Decode_Frequency
    n_legacy_vsl_dsp_logic_h__VSL_Decode_Frequency -.->|"recursion"| n_legacy_vsl_dsp_logic_h__VSL_Decode_Frequency
    n_legacy_main_c__main -->|"5"| n_legacy_vsl_dsp_transport_h__VSL_Build_And_Send_Packet
    n_legacy_vsl_dsp_transport_h__VSL_Build_And_Send_Packet -.->|"recursion"| n_legacy_vsl_dsp_transport_h__VSL_Build_And_Send_Packet
    linkStyle 0,2,4,6,8,10 stroke:#f87171,stroke-width:2px;
```

Cross-file sequence:

```mermaid
sequenceDiagram
    autonumber
    participant p_legacy_main_c as main.c
    participant p_legacy_vsl_dsp_logic_h as vsl_dsp_logic.h
    participant p_legacy_vsl_dsp_transport_h as vsl_dsp_transport.h
    p_legacy_main_c->>p_legacy_vsl_dsp_logic_h: VSL_Encode_Gain()
    p_legacy_main_c->>p_legacy_vsl_dsp_logic_h: VSL_Final_Encode_To_Int()
    p_legacy_main_c->>p_legacy_vsl_dsp_logic_h: VSL_Map_Frequency()
    p_legacy_main_c->>p_legacy_vsl_dsp_logic_h: VSL_Decode_Frequency()
    p_legacy_main_c->>p_legacy_vsl_dsp_transport_h: VSL_Build_And_Send_Packet()
```

### `avatar_main.main`

`avatar/avatar_main.c:191`, score 11: `main` in a compiled-language file; entry-style name `main`.

Call tree:

```mermaid
flowchart LR
    classDef default fill:#111827,stroke:#38bdf8,color:#e5e7eb;
    classDef entry fill:#0e7490,stroke:#22d3ee,color:#ecfeff,stroke-width:2px;
    classDef external fill:#1a1530,stroke:#a78bfa,color:#ede9fe;
    n_avatar_avatar_main_c__main["avatar_main.main<br/>avatar_main.c:191"]:::entry
    n_avatar_avatar_main_c__env_or["avatar_main.env_or<br/>avatar_main.c:79"]:::default
    n_avatar_avatar_main_c__list_pcms["avatar_main.list_pcms<br/>avatar_main.c:54"]:::default
    n_avatar_avatar_main_c__usage["avatar_main.usage<br/>avatar_main.c:30"]:::default
    n_avatar_avatar_main_c__open_capture["avatar_main.open_capture<br/>avatar_main.c:85"]:::default
    n_avatar_avatar_logic_h__avatar_smooth_init["avatar_logic.avatar_smooth_init<br/>@brief Init hysteresis holder.<br/>avatar_logic.h:85"]:::external
    n_avatar_avatar_main_c__to_mono_f32["avatar_main.to_mono_f32<br/>if (snd_pcm_hw_params(pcm, hw) #lt; 0) { fprintf...<br/>avatar_main.c:156"]:::default
    n_avatar_avatar_logic_h__avatar_rms_f32["avatar_logic.avatar_rms_f32<br/>@brief RMS of a mono float frame, 0..1.<br/>avatar_logic.h:45"]:::external
    n_avatar_avatar_logic_h__avatar_rms_to_dbfs["avatar_logic.avatar_rms_to_dbfs<br/>@brief Convert RMS to dBFS with -120 dB floor.<br/>avatar_logic.h:52"]:::external
    n_avatar_avatar_logic_h__avatar_zcr_f32["avatar_logic.avatar_zcr_f32<br/>@brief Zero-crossing rate 0..1.<br/>avatar_logic.h:60"]:::external
    n_avatar_avatar_logic_h__avatar_hf_ratio_f32["avatar_logic.avatar_hf_ratio_f32<br/>@brief High-frequency ratio RMS(diff)/RMS, cl...<br/>avatar_logic.h:68"]:::external
    n_avatar_avatar_logic_h__avatar_classify["avatar_logic.avatar_classify<br/>@brief Instantaneous state without hysteresis...<br/>avatar_logic.h:78"]:::external
    n_avatar_avatar_logic_h__avatar_smooth["avatar_logic.avatar_smooth<br/>@brief Hysteresis: instant attack, delayed re...<br/>avatar_logic.h:95"]:::external
    n_avatar_avatar_logic_h__avatar_state_name["avatar_logic.avatar_state_name<br/>@brief State label for window title and headl...<br/>avatar_logic.h:103"]:::external
    n_avatar_avatar_main_c__main -.->|"recursion"| n_avatar_avatar_main_c__main
    n_avatar_avatar_main_c__main -->|"1"| n_avatar_avatar_main_c__env_or
    n_avatar_avatar_main_c__main -->|"2"| n_avatar_avatar_main_c__list_pcms
    n_avatar_avatar_main_c__main -->|"3"| n_avatar_avatar_main_c__usage
    n_avatar_avatar_main_c__main -->|"4"| n_avatar_avatar_main_c__open_capture
    n_avatar_avatar_main_c__main -->|"5"| n_avatar_avatar_logic_h__avatar_smooth_init
    n_avatar_avatar_logic_h__avatar_smooth_init -.->|"recursion"| n_avatar_avatar_logic_h__avatar_smooth_init
    n_avatar_avatar_main_c__main -->|"6"| n_avatar_avatar_main_c__to_mono_f32
    n_avatar_avatar_main_c__main -->|"7"| n_avatar_avatar_logic_h__avatar_rms_f32
    n_avatar_avatar_logic_h__avatar_rms_f32 -.->|"recursion"| n_avatar_avatar_logic_h__avatar_rms_f32
    n_avatar_avatar_main_c__main -->|"8"| n_avatar_avatar_logic_h__avatar_rms_to_dbfs
    n_avatar_avatar_logic_h__avatar_rms_to_dbfs -.->|"recursion"| n_avatar_avatar_logic_h__avatar_rms_to_dbfs
    n_avatar_avatar_main_c__main -->|"9"| n_avatar_avatar_logic_h__avatar_zcr_f32
    n_avatar_avatar_logic_h__avatar_zcr_f32 -.->|"recursion"| n_avatar_avatar_logic_h__avatar_zcr_f32
    n_avatar_avatar_main_c__main -->|"10"| n_avatar_avatar_logic_h__avatar_hf_ratio_f32
    n_avatar_avatar_logic_h__avatar_hf_ratio_f32 -.->|"recursion"| n_avatar_avatar_logic_h__avatar_hf_ratio_f32
    n_avatar_avatar_main_c__main -->|"11"| n_avatar_avatar_logic_h__avatar_classify
    n_avatar_avatar_logic_h__avatar_classify -.->|"recursion"| n_avatar_avatar_logic_h__avatar_classify
    n_avatar_avatar_main_c__main -->|"12"| n_avatar_avatar_logic_h__avatar_smooth
    n_avatar_avatar_logic_h__avatar_smooth -.->|"recursion"| n_avatar_avatar_logic_h__avatar_smooth
    n_avatar_avatar_main_c__main -->|"13"| n_avatar_avatar_logic_h__avatar_state_name
    n_avatar_avatar_logic_h__avatar_state_name -.->|"recursion"| n_avatar_avatar_logic_h__avatar_state_name
    linkStyle 0,6,9,11,13,15,17,19,21 stroke:#f87171,stroke-width:2px;
```

Cross-file sequence:

```mermaid
sequenceDiagram
    autonumber
    participant p_avatar_avatar_main_c as avatar_main.c
    participant p_avatar_avatar_logic_h as avatar_logic.h
    p_avatar_avatar_main_c->>p_avatar_avatar_logic_h: avatar_smooth_init()
    p_avatar_avatar_main_c->>p_avatar_avatar_logic_h: avatar_rms_f32()
    p_avatar_avatar_main_c->>p_avatar_avatar_logic_h: avatar_rms_to_dbfs()
    p_avatar_avatar_main_c->>p_avatar_avatar_logic_h: avatar_zcr_f32()
    p_avatar_avatar_main_c->>p_avatar_avatar_logic_h: avatar_hf_ratio_f32()
    p_avatar_avatar_main_c->>p_avatar_avatar_logic_h: avatar_classify()
    p_avatar_avatar_main_c->>p_avatar_avatar_logic_h: avatar_smooth()
    p_avatar_avatar_main_c->>p_avatar_avatar_logic_h: avatar_state_name()
```

### `vsl_cli.main`

`src/vsl_cli.c:227`, score 11: `main` in a compiled-language file; entry-style name `main`.

Call tree:

```mermaid
flowchart LR
    classDef default fill:#111827,stroke:#38bdf8,color:#e5e7eb;
    classDef entry fill:#0e7490,stroke:#22d3ee,color:#ecfeff,stroke-width:2px;
    classDef external fill:#1a1530,stroke:#a78bfa,color:#ede9fe;
    n_src_vsl_cli_c__main["vsl_cli.main<br/>vsl_cli.c:227"]:::entry
    n_src_vsl_cli_c__print_usage["vsl_cli.print_usage<br/>vsl_cli.c:61"]:::default
    n_src_vsl_cli_c__print_version["vsl_cli.print_version<br/>vsl_cli.c:89"]:::default
    n_src_vsl_config_h__VSL_ModelLookupByTag["vsl_config.VSL_ModelLookupByTag<br/>vsl_config.h:50"]:::external
    n_src_vsl_cli_c__print_list["vsl_cli.print_list<br/>vsl_cli.c:96"]:::default
    n_src_vsl_config_h__VSL_ModelLookup["vsl_config.VSL_ModelLookup<br/>vsl_config.h:38"]:::external
    n_src_vsl_cli_c__do_probe["vsl_cli.do_probe<br/>vsl_cli.c:135"]:::default
    n_src_vsl_dsp_transport_h__VSL_Probe_Device["vsl_dsp_transport.VSL_Probe_Device<br/>@brief Read USB identification strings withou...<br/>vsl_dsp_transport.h:40"]:::external
    n_src_vsl_cli_c__lookup_coeffs_by_param_id["vsl_cli.lookup_coeffs_by_param_id<br/>vsl_cli.c:116"]:::default
    n_src_vsl_cli_c__do_send["vsl_cli.do_send<br/>vsl_cli.c:152"]:::default
    n_src_vsl_dsp_logic_h__VSL_Encode_Gain["vsl_dsp_logic.VSL_Encode_Gain<br/>@brief Encodes a linear gain value [0.0, 1.0]...<br/>vsl_dsp_logic.h:44"]:::external
    n_src_vsl_dsp_logic_h__VSL_Final_Encode_To_Int["vsl_dsp_logic.VSL_Final_Encode_To_Int<br/>@brief Converts an encoded float to a 16-bit...<br/>vsl_dsp_logic.h:81"]:::external
    n_src_vsl_dsp_transport_h__VSL_Send_Parameter["vsl_dsp_transport.VSL_Send_Parameter<br/>@brief Send a DSP parameter value to the devi...<br/>vsl_dsp_transport.h:67"]:::external
    n_src_vsl_dsp_transport_h__VSL_Close_Device["vsl_dsp_transport.VSL_Close_Device<br/>@brief Release the MIDI interface and close t...<br/>vsl_dsp_transport.h:26"]:::external
    n_src_vsl_dsp_logic_h__VSL_DB_To_Linear["vsl_dsp_logic.VSL_DB_To_Linear<br/>@brief Converts a decibel gain back to linear...<br/>vsl_dsp_logic.h:97"]:::external
    n_src_vsl_cli_c__do_send_freq["vsl_cli.do_send_freq<br/>vsl_cli.c:190"]:::default
    n_src_vsl_dsp_logic_h__VSL_Map_Frequency["vsl_dsp_logic.VSL_Map_Frequency<br/>@brief Maps a linear position [0.0, 1.0] to a...<br/>vsl_dsp_logic.h:62"]:::external
    n_src_vsl_cli_c__find_entry_by_name["vsl_cli.find_entry_by_name<br/>vsl_cli.c:126"]:::default
    n_src_vsl_cli_c__main -.->|"recursion"| n_src_vsl_cli_c__main
    n_src_vsl_cli_c__main -->|"1"| n_src_vsl_cli_c__print_usage
    n_src_vsl_cli_c__main -->|"2"| n_src_vsl_cli_c__print_version
    n_src_vsl_cli_c__main -->|"3"| n_src_vsl_config_h__VSL_ModelLookupByTag
    n_src_vsl_config_h__VSL_ModelLookupByTag -.->|"recursion"| n_src_vsl_config_h__VSL_ModelLookupByTag
    n_src_vsl_cli_c__main -->|"4"| n_src_vsl_cli_c__print_list
    n_src_vsl_cli_c__print_list -->|"1"| n_src_vsl_config_h__VSL_ModelLookup
    n_src_vsl_config_h__VSL_ModelLookup -.->|"recursion"| n_src_vsl_config_h__VSL_ModelLookup
    n_src_vsl_cli_c__main -->|"5"| n_src_vsl_cli_c__do_probe
    n_src_vsl_cli_c__do_probe -->|"1"| n_src_vsl_dsp_transport_h__VSL_Probe_Device
    n_src_vsl_dsp_transport_h__VSL_Probe_Device -.->|"recursion"| n_src_vsl_dsp_transport_h__VSL_Probe_Device
    n_src_vsl_cli_c__main -->|"6"| n_src_vsl_cli_c__lookup_coeffs_by_param_id
    n_src_vsl_cli_c__lookup_coeffs_by_param_id -.->|"recursion"| n_src_vsl_cli_c__lookup_coeffs_by_param_id
    n_src_vsl_cli_c__main -->|"7"| n_src_vsl_cli_c__do_send
    n_src_vsl_cli_c__do_send -->|"1"| n_src_vsl_dsp_logic_h__VSL_Encode_Gain
    n_src_vsl_dsp_logic_h__VSL_Encode_Gain -.->|"recursion"| n_src_vsl_dsp_logic_h__VSL_Encode_Gain
    n_src_vsl_cli_c__do_send -->|"2"| n_src_vsl_dsp_logic_h__VSL_Final_Encode_To_Int
    n_src_vsl_dsp_logic_h__VSL_Final_Encode_To_Int -.->|"recursion"| n_src_vsl_dsp_logic_h__VSL_Final_Encode_To_Int
    n_src_vsl_cli_c__do_send -->|"3"| n_src_vsl_dsp_transport_h__VSL_Send_Parameter
    n_src_vsl_dsp_transport_h__VSL_Send_Parameter -.->|"recursion"| n_src_vsl_dsp_transport_h__VSL_Send_Parameter
    n_src_vsl_cli_c__do_send -->|"4"| n_src_vsl_dsp_transport_h__VSL_Close_Device
    n_src_vsl_dsp_transport_h__VSL_Close_Device -.->|"recursion"| n_src_vsl_dsp_transport_h__VSL_Close_Device
    n_src_vsl_cli_c__main -->|"8"| n_src_vsl_dsp_logic_h__VSL_DB_To_Linear
    n_src_vsl_dsp_logic_h__VSL_DB_To_Linear -.->|"recursion"| n_src_vsl_dsp_logic_h__VSL_DB_To_Linear
    n_src_vsl_cli_c__main -->|"9"| n_src_vsl_cli_c__do_send_freq
    n_src_vsl_cli_c__do_send_freq -->|"1"| n_src_vsl_dsp_logic_h__VSL_Map_Frequency
    n_src_vsl_dsp_logic_h__VSL_Map_Frequency -.->|"recursion"| n_src_vsl_dsp_logic_h__VSL_Map_Frequency
    n_src_vsl_cli_c__do_send_freq -.-> n_src_vsl_dsp_logic_h__VSL_Final_Encode_To_Int
    n_src_vsl_cli_c__do_send_freq -.-> n_src_vsl_dsp_transport_h__VSL_Send_Parameter
    n_src_vsl_cli_c__do_send_freq -.-> n_src_vsl_dsp_transport_h__VSL_Close_Device
    n_src_vsl_cli_c__main -->|"10"| n_src_vsl_cli_c__find_entry_by_name
    n_src_vsl_cli_c__find_entry_by_name -.->|"recursion"| n_src_vsl_cli_c__find_entry_by_name
    linkStyle 0,4,7,10,12,15,17,19,21,23,26,31 stroke:#f87171,stroke-width:2px;
```

Cross-file sequence:

```mermaid
sequenceDiagram
    autonumber
    participant p_src_vsl_cli_c as vsl_cli.c
    participant p_src_vsl_config_h as vsl_config.h
    participant p_src_vsl_dsp_transport_h as vsl_dsp_transport.h
    participant p_src_vsl_dsp_logic_h as vsl_dsp_logic.h
    p_src_vsl_cli_c->>p_src_vsl_config_h: VSL_ModelLookupByTag()
    p_src_vsl_cli_c->>p_src_vsl_config_h: VSL_ModelLookup()
    p_src_vsl_cli_c->>p_src_vsl_dsp_transport_h: VSL_Probe_Device()
    p_src_vsl_cli_c->>p_src_vsl_dsp_logic_h: VSL_Encode_Gain()
    p_src_vsl_cli_c->>p_src_vsl_dsp_logic_h: VSL_Final_Encode_To_Int()
    p_src_vsl_cli_c->>p_src_vsl_dsp_transport_h: VSL_Send_Parameter()
    p_src_vsl_cli_c->>p_src_vsl_dsp_transport_h: VSL_Close_Device()
    p_src_vsl_cli_c->>p_src_vsl_dsp_logic_h: VSL_DB_To_Linear()
    p_src_vsl_cli_c->>p_src_vsl_dsp_logic_h: VSL_Map_Frequency()
```

---
