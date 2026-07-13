# Polyglot Codebase Knowledge Graph

> Generated offline by **readmenator**. Supports C, C++, Python, Go, Rust, JS/TS, Java, C#, Shell, PHP, Dart, GDScript, Nim, ASM, Ruby, Swift, Kotlin, Scala, Lua, Elixir.
> No LLMs. No tokens. Pure static analysis. See more [here](https://github.com/grisuno/ReadMenator)

**Total Files Parsed:** 28 | **Total Symbols Extracted:** 433 | **Total Imports:** 116
 | **Resolved Imports:** 11


## Table of Contents

1. [Statistics Dashboard](#statistics-dashboard)
2. [Architectural Layers](#architectural-layers)
3. [God Nodes](#god-nodes)
4. [Community Analysis](#community-analysis)
5. [Suggested Questions](#suggested-questions)
6. [Structural Knowledge Map](#structural-knowledge-map)
7. [Architecture Reference](#architecture-reference)
    - [C (12 files)](#c-12-files)
    - [H (6 files)](#h-6-files)
    - [PY (7 files)](#py-7-files)
    - [SH (3 files)](#sh-3-files)

---

## Statistics Dashboard

| Metric | Value |
|--------|-------|
| Total Files | 28 |
| Total Symbols | 433 |
| Total Imports | 116 |
| Call Edges | 250 |
| Inheritance Edges | 1 |
| Languages | 4 |
| Avg Symbols/File | 15.5 |
| Avg Imports/File | 4.1 |
| Resolved Imports | 11 |

### Top Files by Import Count (Fan-Out)

| File | Imports | Symbols | Language |
|------|---------|---------|----------|
| `mixer_quirks.c` | 25 | 306 | c |
| `vsl_hid_io.py` | 8 | 9 | py |
| `vsl_dsp_transport.c` | 7 | 5 | c |
| `vsl_cli.c` | 7 | 6 | c |
| `test_vsl_dsp_logic.c` | 7 | 5 | c |
| `vsl_poc_main.py` | 6 | 7 | py |
| `test_audiobox_vsl.c` | 6 | 10 | c |
| `vsl_protocol_analyzer.py` | 5 | 7 | py |
| `vsl_dsp_transport.c` | 5 | 10 | c |
| `audiobox_vsl.c` | 4 | 5 | c |

### Top Files by Imported-By Count (Fan-In)

| File | Imported By | Symbols | Language |
|------|-------------|---------|----------|
| `audiobox_vsl.h` | 3 | 4 | h |

---

## Architectural Layers

Auto-detected from path patterns, naming conventions, and imported frameworks.

| Layer | Files |
|-------|-------|
| utility | 13 |
| infrastructure | 5 |
| testing | 4 |
| business_logic | 4 |
| presentation | 2 |

### infrastructure

- `audiobox_vsl.c` (c, 5 symbols)
- `audiobox_vsl.h` (h, 4 symbols)
- `audiobox_vsl.mod.c` (c, 0 symbols)
- `vsl_config.h` (h, 8 symbols)
- `vsl_config.py` (py, 3 symbols)

### utility

- `install.sh` (sh, 0 symbols)
- `app.py` (py, 0 symbols)
- `main.c` (c, 1 symbols)
- `vsl_core.py` (py, 5 symbols)
- `vsl_dsp_transport.c` (c, 5 symbols)
- `vsl_dsp_transport.h` (h, 1 symbols)
- `vsl_hid_io.py` (py, 9 symbols)
- `vsl_poc_main.py` (py, 7 symbols)
- `vsl_protocol_analyzer.py` (py, 7 symbols)
- `vsl_transport.py` (py, 8 symbols)
- `vsl_cli.c` (c, 6 symbols)
- `vsl_dsp_transport.c` (c, 10 symbols)
- `vsl_dsp_transport.h` (h, 1 symbols)

### presentation

- `build-dkms.sh` (sh, 19 symbols)
- `mixer_quirks.c` (c, 306 symbols)

### testing

- `test.sh` (sh, 0 symbols)
- `test_connection.c` (c, 1 symbols)
- `test_audiobox_vsl.c` (c, 10 symbols)
- `test_vsl_dsp_logic.c` (c, 5 symbols)

### business_logic

- `vsl_dsp_logic.c` (c, 4 symbols)
- `vsl_dsp_logic.h` (h, 2 symbols)
- `vsl_dsp_logic.c` (c, 4 symbols)
- `vsl_dsp_logic.h` (h, 2 symbols)

---

## God Nodes

Most architecturally central files ranked by combined import/export degree and symbol richness.

| File | Score | Connections |
|------|-------|-------------|
| `mixer_quirks.c` | 32.6 | |
| `vsl_config.py` | 8.3 | |
| `vsl_hid_io.py` | 6.9 | |
| `vsl_transport.py` | 6.8 | |
| `vsl_poc_main.py` | 6.7 | |
| `vsl_core.py` | 6.5 | |
| `audiobox_vsl.h` | 6.4 | |
| `test_audiobox_vsl.c` | 3.0 | |
| `audiobox_vsl.c` | 2.5 | |
| `build-dkms.sh` | 1.9 | |

---

## Community Analysis

Files grouped by import-based community detection. Cohesion measures how tightly connected each community is internally.

### root (Cohesion: 1.00)

**4 files** in this community:

- `audiobox_vsl.c` (c, 5 symbols)
- `audiobox_vsl.h` (h, 4 symbols)
- `mixer_quirks.c` (c, 306 symbols)
- `test_audiobox_vsl.c` (c, 10 symbols)

### legacy (Cohesion: 1.00)

**5 files** in this community:

- `vsl_config.py` (py, 3 symbols)
- `vsl_core.py` (py, 5 symbols)
- `vsl_hid_io.py` (py, 9 symbols)
- `vsl_poc_main.py` (py, 7 symbols)
- `vsl_transport.py` (py, 8 symbols)

---

## Suggested Questions

Auto-generated exploration prompts based on graph structure:

- What does mixer_quirks.c depend on, and what depends on it? (1 connections)
- What does vsl_config.py depend on, and what depends on it? (4 connections)
- What does vsl_hid_io.py depend on, and what depends on it? (3 connections)
- How are the 4 files in 'root' related to each other?
- What is usb_mixer_interface in audiobox_vsl.h and how is it used?

---

## Structural Knowledge Map

```mermaid
graph TD
    classDef mod fill:#1e1e1e,stroke:#ff6666,stroke-width:2px,color:#fff;
    classDef cls fill:#2d2d2d,stroke:#4ec9b0,stroke-width:2px,color:#fff;
    classDef fn fill:#333,stroke:#dcdcaa,stroke-width:1px,color:#dcdcaa;
    classDef ext fill:#111,stroke:#666,stroke-dasharray:5 5,color:#aaa;
    subgraph community_0 ["root"]
    legacy_mixer_quirks_c["mixer_quirks.c (c)"]
    class legacy_mixer_quirks_c mod;
    legacy_mixer_quirks_c_std_mono_table["std_mono_table"]
    class legacy_mixer_quirks_c_std_mono_table cls;
    legacy_mixer_quirks_c --> legacy_mixer_quirks_c_std_mono_table
    legacy_mixer_quirks_c_rc_config["rc_config"]
    class legacy_mixer_quirks_c_rc_config cls;
    legacy_mixer_quirks_c --> legacy_mixer_quirks_c_rc_config
    legacy_mixer_quirks_c_sb_jack["sb_jack"]
    class legacy_mixer_quirks_c_sb_jack cls;
    legacy_mixer_quirks_c --> legacy_mixer_quirks_c_sb_jack
    legacy_mixer_quirks_c_dualsense_mixer_elem_info["dualsense_mixer_elem_info"]
    class legacy_mixer_quirks_c_dualsense_mixer_elem_info cls;
    legacy_mixer_quirks_c --> legacy_mixer_quirks_c_dualsense_mixer_elem_info
    legacy_mixer_quirks_c_snd_djm_device["snd_djm_device"]
    class legacy_mixer_quirks_c_snd_djm_device cls;
    legacy_mixer_quirks_c --> legacy_mixer_quirks_c_snd_djm_device
    end
    subgraph community_1 ["legacy"]
    legacy_vsl_hid_io_py["vsl_hid_io.py (py)"]
    class legacy_vsl_hid_io_py mod;
    legacy_vsl_hid_io_py_VSLDevice["VSLDevice"]
    class legacy_vsl_hid_io_py_VSLDevice cls;
    legacy_vsl_hid_io_py --> legacy_vsl_hid_io_py_VSLDevice
    legacy_vsl_hid_io_py_enumerate_vsl_devices["enumerate_vsl_devices"]
    class legacy_vsl_hid_io_py_enumerate_vsl_devices fn;
    legacy_vsl_hid_io_py --> legacy_vsl_hid_io_py_enumerate_vsl_devices
    legacy_vsl_hid_io_py___new__["__new__"]
    class legacy_vsl_hid_io_py___new__ fn;
    legacy_vsl_hid_io_py --> legacy_vsl_hid_io_py___new__
    legacy_vsl_hid_io_py___init__["__init__"]
    class legacy_vsl_hid_io_py___init__ fn;
    legacy_vsl_hid_io_py --> legacy_vsl_hid_io_py___init__
    legacy_vsl_hid_io_py_open["open"]
    class legacy_vsl_hid_io_py_open fn;
    legacy_vsl_hid_io_py --> legacy_vsl_hid_io_py_open
    legacy_vsl_poc_main_py["vsl_poc_main.py (py)"]
    class legacy_vsl_poc_main_py mod;
    legacy_vsl_poc_main_py_test_gain_encoding["test_gain_encoding"]
    class legacy_vsl_poc_main_py_test_gain_encoding fn;
    legacy_vsl_poc_main_py --> legacy_vsl_poc_main_py_test_gain_encoding
    legacy_vsl_poc_main_py_test_frequency_mapping["test_frequency_mapping"]
    class legacy_vsl_poc_main_py_test_frequency_mapping fn;
    legacy_vsl_poc_main_py --> legacy_vsl_poc_main_py_test_frequency_mapping
    legacy_vsl_poc_main_py_test_packet_construction["test_packet_construction"]
    class legacy_vsl_poc_main_py_test_packet_construction fn;
    legacy_vsl_poc_main_py --> legacy_vsl_poc_main_py_test_packet_construction
    legacy_vsl_poc_main_py_test_edge_cases["test_edge_cases"]
    class legacy_vsl_poc_main_py_test_edge_cases fn;
    legacy_vsl_poc_main_py --> legacy_vsl_poc_main_py_test_edge_cases
    legacy_vsl_poc_main_py_run_full_workflow["run_full_workflow"]
    class legacy_vsl_poc_main_py_run_full_workflow fn;
    legacy_vsl_poc_main_py --> legacy_vsl_poc_main_py_run_full_workflow
    src_vsl_cli_c["vsl_cli.c (c)"]
    class src_vsl_cli_c mod;
    src_vsl_cli_c_print_list["print_list"]
    class src_vsl_cli_c_print_list fn;
    src_vsl_cli_c --> src_vsl_cli_c_print_list
    src_vsl_cli_c_find_by_name["find_by_name"]
    class src_vsl_cli_c_find_by_name fn;
    src_vsl_cli_c --> src_vsl_cli_c_find_by_name
    src_vsl_cli_c_do_send_param["do_send_param"]
    class src_vsl_cli_c_do_send_param fn;
    src_vsl_cli_c --> src_vsl_cli_c_do_send_param
    src_vsl_cli_c_main["main"]
    class src_vsl_cli_c_main fn;
    src_vsl_cli_c --> src_vsl_cli_c_main
    src_vsl_cli_c_VSL_VENDOR_ID["VSL_VENDOR_ID"]
    class src_vsl_cli_c_VSL_VENDOR_ID fn;
    src_vsl_cli_c --> src_vsl_cli_c_VSL_VENDOR_ID
    legacy_vsl_dsp_transport_c["vsl_dsp_transport.c (c)"]
    class legacy_vsl_dsp_transport_c mod;
    legacy_vsl_dsp_transport_c_VSL_Init_Device["VSL_Init_Device"]
    class legacy_vsl_dsp_transport_c_VSL_Init_Device fn;
    legacy_vsl_dsp_transport_c --> legacy_vsl_dsp_transport_c_VSL_Init_Device
    legacy_vsl_dsp_transport_c_VSL_Close_Device["VSL_Close_Device"]
    class legacy_vsl_dsp_transport_c_VSL_Close_Device fn;
    legacy_vsl_dsp_transport_c --> legacy_vsl_dsp_transport_c_VSL_Close_Device
    legacy_vsl_dsp_transport_c_VSL_Get_Device_Handle["VSL_Get_Device_Handle"]
    class legacy_vsl_dsp_transport_c_VSL_Get_Device_Handle fn;
    legacy_vsl_dsp_transport_c --> legacy_vsl_dsp_transport_c_VSL_Get_Device_Handle
    legacy_vsl_dsp_transport_c_FUN_Send_Packet["FUN_Send_Packet"]
    class legacy_vsl_dsp_transport_c_FUN_Send_Packet fn;
    legacy_vsl_dsp_transport_c --> legacy_vsl_dsp_transport_c_FUN_Send_Packet
    legacy_vsl_dsp_transport_c_VSL_Build_And_Send_Packet["VSL_Build_And_Send_Packet"]
    class legacy_vsl_dsp_transport_c_VSL_Build_And_Send_Packet fn;
    legacy_vsl_dsp_transport_c --> legacy_vsl_dsp_transport_c_VSL_Build_And_Send_Packet
    tests_test_vsl_dsp_logic_c["test_vsl_dsp_logic.c (c)"]
    class tests_test_vsl_dsp_logic_c mod;
    tests_test_vsl_dsp_logic_c_test_VSL_Encode_Gain["test_VSL_Encode_Gain"]
    class tests_test_vsl_dsp_logic_c_test_VSL_Encode_Gain fn;
    tests_test_vsl_dsp_logic_c --> tests_test_vsl_dsp_logic_c_test_VSL_Encode_Gain
    tests_test_vsl_dsp_logic_c_test_VSL_Map_Frequency["test_VSL_Map_Frequency"]
    class tests_test_vsl_dsp_logic_c_test_VSL_Map_Frequency fn;
    tests_test_vsl_dsp_logic_c --> tests_test_vsl_dsp_logic_c_test_VSL_Map_Frequency
    tests_test_vsl_dsp_logic_c_test_VSL_Decode_Frequency["test_VSL_Decode_Frequency"]
    class tests_test_vsl_dsp_logic_c_test_VSL_Decode_Frequency fn;
    tests_test_vsl_dsp_logic_c --> tests_test_vsl_dsp_logic_c_test_VSL_Decode_Frequency
    tests_test_vsl_dsp_logic_c_test_VSL_Final_Encode_To_Int["test_VSL_Final_Encode_To_Int"]
    class tests_test_vsl_dsp_logic_c_test_VSL_Final_Encode_To_Int fn;
    tests_test_vsl_dsp_logic_c --> tests_test_vsl_dsp_logic_c_test_VSL_Final_Encode_To_Int
    tests_test_vsl_dsp_logic_c_main["main"]
    class tests_test_vsl_dsp_logic_c_main fn;
    tests_test_vsl_dsp_logic_c --> tests_test_vsl_dsp_logic_c_main
    tests_test_audiobox_vsl_c["test_audiobox_vsl.c (c)"]
    class tests_test_audiobox_vsl_c mod;
    tests_test_audiobox_vsl_c_test_supported_models_table_shape["test_supported_models_table_shape"]
    class tests_test_audiobox_vsl_c_test_supported_models_table_shape fn;
    tests_test_audiobox_vsl_c --> tests_test_audiobox_vsl_c_test_supported_models_table_shape
    tests_test_audiobox_vsl_c_test_model_pids_match_table["test_model_pids_match_table"]
    class tests_test_audiobox_vsl_c_test_model_pids_match_table fn;
    tests_test_audiobox_vsl_c --> tests_test_audiobox_vsl_c_test_model_pids_match_table
    tests_test_audiobox_vsl_c_test_lookup_returns_22_vsl["test_lookup_returns_22_vsl"]
    class tests_test_audiobox_vsl_c_test_lookup_returns_22_vsl fn;
    tests_test_audiobox_vsl_c --> tests_test_audiobox_vsl_c_test_lookup_returns_22_vsl
    tests_test_audiobox_vsl_c_test_lookup_returns_44_vsl["test_lookup_returns_44_vsl"]
    class tests_test_audiobox_vsl_c_test_lookup_returns_44_vsl fn;
    tests_test_audiobox_vsl_c --> tests_test_audiobox_vsl_c_test_lookup_returns_44_vsl
    tests_test_audiobox_vsl_c_test_lookup_returns_1818_vsl["test_lookup_returns_1818_vsl"]
    class tests_test_audiobox_vsl_c_test_lookup_returns_1818_vsl fn;
    tests_test_audiobox_vsl_c --> tests_test_audiobox_vsl_c_test_lookup_returns_1818_vsl
    legacy_vsl_core_py["vsl_core.py (py)"]
    class legacy_vsl_core_py mod;
    legacy_vsl_core_py_vsl_encode_gain["vsl_encode_gain"]
    class legacy_vsl_core_py_vsl_encode_gain fn;
    legacy_vsl_core_py --> legacy_vsl_core_py_vsl_encode_gain
    legacy_vsl_core_py_vsl_map_frequency["vsl_map_frequency"]
    class legacy_vsl_core_py_vsl_map_frequency fn;
    legacy_vsl_core_py --> legacy_vsl_core_py_vsl_map_frequency
    legacy_vsl_core_py_vsl_final_encode_to_int["vsl_final_encode_to_int"]
    class legacy_vsl_core_py_vsl_final_encode_to_int fn;
    legacy_vsl_core_py --> legacy_vsl_core_py_vsl_final_encode_to_int
    legacy_vsl_core_py_vsl_decode_frequency["vsl_decode_frequency"]
    class legacy_vsl_core_py_vsl_decode_frequency fn;
    legacy_vsl_core_py --> legacy_vsl_core_py_vsl_decode_frequency
    legacy_vsl_core_py_validate_parameter["validate_parameter"]
    class legacy_vsl_core_py_validate_parameter fn;
    legacy_vsl_core_py --> legacy_vsl_core_py_validate_parameter
    src_vsl_dsp_transport_c["vsl_dsp_transport.c (c)"]
    class src_vsl_dsp_transport_c mod;
    src_vsl_dsp_transport_c_vsl_device["vsl_device"]
    class src_vsl_dsp_transport_c_vsl_device cls;
    src_vsl_dsp_transport_c --> src_vsl_dsp_transport_c_vsl_device
    src_vsl_dsp_transport_c_VSL_Init_Device["VSL_Init_Device"]
    class src_vsl_dsp_transport_c_VSL_Init_Device fn;
    src_vsl_dsp_transport_c --> src_vsl_dsp_transport_c_VSL_Init_Device
    src_vsl_dsp_transport_c_VSL_Close_Device["VSL_Close_Device"]
    class src_vsl_dsp_transport_c_VSL_Close_Device fn;
    src_vsl_dsp_transport_c --> src_vsl_dsp_transport_c_VSL_Close_Device
    src_vsl_dsp_transport_c_VSL_Send_Parameter["VSL_Send_Parameter"]
    class src_vsl_dsp_transport_c_VSL_Send_Parameter fn;
    src_vsl_dsp_transport_c --> src_vsl_dsp_transport_c_VSL_Send_Parameter
    src_vsl_dsp_transport_c_VSL_VENDOR_ID["VSL_VENDOR_ID"]
    class src_vsl_dsp_transport_c_VSL_VENDOR_ID fn;
    src_vsl_dsp_transport_c --> src_vsl_dsp_transport_c_VSL_VENDOR_ID
    legacy_vsl_transport_py["vsl_transport.py (py)"]
    class legacy_vsl_transport_py mod;
    legacy_vsl_transport_py_VSLPacket["VSLPacket"]
    class legacy_vsl_transport_py_VSLPacket cls;
    legacy_vsl_transport_py --> legacy_vsl_transport_py_VSLPacket
    legacy_vsl_transport_py_build_packet_safe["build_packet_safe"]
    class legacy_vsl_transport_py_build_packet_safe fn;
    legacy_vsl_transport_py --> legacy_vsl_transport_py_build_packet_safe
    legacy_vsl_transport_py___init__["__init__"]
    class legacy_vsl_transport_py___init__ fn;
    legacy_vsl_transport_py --> legacy_vsl_transport_py___init__
    legacy_vsl_transport_py__build_buffer["_build_buffer"]
    class legacy_vsl_transport_py__build_buffer fn;
    legacy_vsl_transport_py --> legacy_vsl_transport_py__build_buffer
    legacy_vsl_transport_py_buffer["buffer"]
    class legacy_vsl_transport_py_buffer fn;
    legacy_vsl_transport_py --> legacy_vsl_transport_py_buffer
    legacy_vsl_protocol_analyzer_py["vsl_protocol_analyzer.py (py)"]
    class legacy_vsl_protocol_analyzer_py mod;
    legacy_vsl_protocol_analyzer_py_VSLParameter["VSLParameter"]
    class legacy_vsl_protocol_analyzer_py_VSLParameter cls;
    legacy_vsl_protocol_analyzer_py --> legacy_vsl_protocol_analyzer_py_VSLParameter
    legacy_vsl_protocol_analyzer_py_reverse_map_gain["reverse_map_gain"]
    class legacy_vsl_protocol_analyzer_py_reverse_map_gain fn;
    legacy_vsl_protocol_analyzer_py --> legacy_vsl_protocol_analyzer_py_reverse_map_gain
    legacy_vsl_protocol_analyzer_py_reverse_map_frequency["reverse_map_frequency"]
    class legacy_vsl_protocol_analyzer_py_reverse_map_frequency fn;
    legacy_vsl_protocol_analyzer_py --> legacy_vsl_protocol_analyzer_py_reverse_map_frequency
    legacy_vsl_protocol_analyzer_py_get_decoded_value["get_decoded_value"]
    class legacy_vsl_protocol_analyzer_py_get_decoded_value fn;
    legacy_vsl_protocol_analyzer_py --> legacy_vsl_protocol_analyzer_py_get_decoded_value
    legacy_vsl_protocol_analyzer_py_decode_vsl_packet["decode_vsl_packet"]
    class legacy_vsl_protocol_analyzer_py_decode_vsl_packet fn;
    legacy_vsl_protocol_analyzer_py --> legacy_vsl_protocol_analyzer_py_decode_vsl_packet
    audiobox_vsl_c["audiobox_vsl.c (c)"]
    class audiobox_vsl_c mod;
    audiobox_vsl_c_audiobox_probe["audiobox_probe"]
    class audiobox_vsl_c_audiobox_probe fn;
    audiobox_vsl_c --> audiobox_vsl_c_audiobox_probe
    audiobox_vsl_c_audiobox_disconnect["audiobox_disconnect"]
    class audiobox_vsl_c_audiobox_disconnect fn;
    audiobox_vsl_c --> audiobox_vsl_c_audiobox_disconnect
    audiobox_vsl_c_AUDIOBOX_DRIVER_NAME["AUDIOBOX_DRIVER_NAME"]
    class audiobox_vsl_c_AUDIOBOX_DRIVER_NAME fn;
    audiobox_vsl_c --> audiobox_vsl_c_AUDIOBOX_DRIVER_NAME
    audiobox_vsl_c_AUDIOBOX_DRIVER_DESC["AUDIOBOX_DRIVER_DESC"]
    class audiobox_vsl_c_AUDIOBOX_DRIVER_DESC fn;
    audiobox_vsl_c --> audiobox_vsl_c_AUDIOBOX_DRIVER_DESC
    audiobox_vsl_c_AUDIOBOX_DRIVER_LIC["AUDIOBOX_DRIVER_LIC"]
    class audiobox_vsl_c_AUDIOBOX_DRIVER_LIC fn;
    audiobox_vsl_c --> audiobox_vsl_c_AUDIOBOX_DRIVER_LIC
    legacy_vsl_dsp_transport_h["vsl_dsp_transport.h (h)"]
    class legacy_vsl_dsp_transport_h mod;
    legacy_vsl_dsp_transport_h_VSL_DSP_TRANSPORT_H["VSL_DSP_TRANSPORT_H"]
    class legacy_vsl_dsp_transport_h_VSL_DSP_TRANSPORT_H fn;
    legacy_vsl_dsp_transport_h --> legacy_vsl_dsp_transport_h_VSL_DSP_TRANSPORT_H
    audiobox_vsl_h["audiobox_vsl.h (h)"]
    class audiobox_vsl_h mod;
    audiobox_vsl_h_usb_mixer_interface["usb_mixer_interface"]
    class audiobox_vsl_h_usb_mixer_interface cls;
    audiobox_vsl_h --> audiobox_vsl_h_usb_mixer_interface
    audiobox_vsl_h_audiobox_lookup_model["audiobox_lookup_model"]
    class audiobox_vsl_h_audiobox_lookup_model fn;
    audiobox_vsl_h --> audiobox_vsl_h_audiobox_lookup_model
    audiobox_vsl_h_AUDIOBOX_VSL_H["AUDIOBOX_VSL_H"]
    class audiobox_vsl_h_AUDIOBOX_VSL_H fn;
    audiobox_vsl_h --> audiobox_vsl_h_AUDIOBOX_VSL_H
    audiobox_vsl_h_AUDIOBOX_VENDOR_ID["AUDIOBOX_VENDOR_ID"]
    class audiobox_vsl_h_AUDIOBOX_VENDOR_ID fn;
    audiobox_vsl_h --> audiobox_vsl_h_AUDIOBOX_VENDOR_ID
    legacy_vsl_dsp_logic_h["vsl_dsp_logic.h (h)"]
    class legacy_vsl_dsp_logic_h mod;
    legacy_vsl_dsp_logic_h_VSL_DSP_LOGIC_H["VSL_DSP_LOGIC_H"]
    class legacy_vsl_dsp_logic_h_VSL_DSP_LOGIC_H fn;
    legacy_vsl_dsp_logic_h --> legacy_vsl_dsp_logic_h_VSL_DSP_LOGIC_H
    legacy_vsl_dsp_logic_h_VSL_INV_LN2["VSL_INV_LN2"]
    class legacy_vsl_dsp_logic_h_VSL_INV_LN2 fn;
    legacy_vsl_dsp_logic_h --> legacy_vsl_dsp_logic_h_VSL_INV_LN2
    src_vsl_dsp_logic_h["vsl_dsp_logic.h (h)"]
    class src_vsl_dsp_logic_h mod;
    src_vsl_dsp_logic_h_VSL_DSP_LOGIC_H["VSL_DSP_LOGIC_H"]
    class src_vsl_dsp_logic_h_VSL_DSP_LOGIC_H fn;
    src_vsl_dsp_logic_h --> src_vsl_dsp_logic_h_VSL_DSP_LOGIC_H
    src_vsl_dsp_logic_h_VSL_INV_LN2["VSL_INV_LN2"]
    class src_vsl_dsp_logic_h_VSL_INV_LN2 fn;
    src_vsl_dsp_logic_h --> src_vsl_dsp_logic_h_VSL_INV_LN2
    legacy_main_c["main.c (c)"]
    class legacy_main_c mod;
    legacy_main_c_main["main"]
    class legacy_main_c_main fn;
    legacy_main_c --> legacy_main_c_main
    legacy_test_connection_c["test_connection.c (c)"]
    class legacy_test_connection_c mod;
    legacy_test_connection_c_main["main"]
    class legacy_test_connection_c_main fn;
    legacy_test_connection_c --> legacy_test_connection_c_main
    audiobox_vsl_mod_c["audiobox_vsl.mod.c (c)"]
    class audiobox_vsl_mod_c mod;
    legacy_vsl_config_py["vsl_config.py (py)"]
    class legacy_vsl_config_py mod;
    legacy_vsl_config_py_VSLParameter["VSLParameter"]
    class legacy_vsl_config_py_VSLParameter cls;
    legacy_vsl_config_py --> legacy_vsl_config_py_VSLParameter
    legacy_vsl_config_py_validate_configuration["validate_configuration"]
    class legacy_vsl_config_py_validate_configuration fn;
    legacy_vsl_config_py --> legacy_vsl_config_py_validate_configuration
    legacy_vsl_config_py_print_configuration_status["print_configuration_status"]
    class legacy_vsl_config_py_print_configuration_status fn;
    legacy_vsl_config_py --> legacy_vsl_config_py_print_configuration_status
    src_vsl_dsp_transport_h["vsl_dsp_transport.h (h)"]
    class src_vsl_dsp_transport_h mod;
    src_vsl_dsp_transport_h_VSL_DSP_TRANSPORT_H["VSL_DSP_TRANSPORT_H"]
    class src_vsl_dsp_transport_h_VSL_DSP_TRANSPORT_H fn;
    src_vsl_dsp_transport_h --> src_vsl_dsp_transport_h_VSL_DSP_TRANSPORT_H
    legacy_vsl_config_h["vsl_config.h (h)"]
    class legacy_vsl_config_h mod;
    legacy_vsl_config_h_VSL_CONFIG_H["VSL_CONFIG_H"]
    class legacy_vsl_config_h_VSL_CONFIG_H fn;
    legacy_vsl_config_h --> legacy_vsl_config_h_VSL_CONFIG_H
    legacy_vsl_config_h_VSL_VENDOR_ID["VSL_VENDOR_ID"]
    class legacy_vsl_config_h_VSL_VENDOR_ID fn;
    legacy_vsl_config_h --> legacy_vsl_config_h_VSL_VENDOR_ID
    legacy_vsl_config_h_VSL_PRODUCT_ID["VSL_PRODUCT_ID"]
    class legacy_vsl_config_h_VSL_PRODUCT_ID fn;
    legacy_vsl_config_h --> legacy_vsl_config_h_VSL_PRODUCT_ID
    legacy_vsl_config_h_VSL_REPORT_ID["VSL_REPORT_ID"]
    class legacy_vsl_config_h_VSL_REPORT_ID fn;
    legacy_vsl_config_h --> legacy_vsl_config_h_VSL_REPORT_ID
    legacy_vsl_config_h_VSL_SCALE_FACTOR["VSL_SCALE_FACTOR"]
    class legacy_vsl_config_h_VSL_SCALE_FACTOR fn;
    legacy_vsl_config_h --> legacy_vsl_config_h_VSL_SCALE_FACTOR
    legacy_vsl_dsp_logic_c["vsl_dsp_logic.c (c)"]
    class legacy_vsl_dsp_logic_c mod;
    legacy_vsl_dsp_logic_c_VSL_Encode_Gain["VSL_Encode_Gain"]
    class legacy_vsl_dsp_logic_c_VSL_Encode_Gain fn;
    legacy_vsl_dsp_logic_c --> legacy_vsl_dsp_logic_c_VSL_Encode_Gain
    legacy_vsl_dsp_logic_c_VSL_Map_Frequency["VSL_Map_Frequency"]
    class legacy_vsl_dsp_logic_c_VSL_Map_Frequency fn;
    legacy_vsl_dsp_logic_c --> legacy_vsl_dsp_logic_c_VSL_Map_Frequency
    legacy_vsl_dsp_logic_c_VSL_Final_Encode_To_Int["VSL_Final_Encode_To_Int"]
    class legacy_vsl_dsp_logic_c_VSL_Final_Encode_To_Int fn;
    legacy_vsl_dsp_logic_c --> legacy_vsl_dsp_logic_c_VSL_Final_Encode_To_Int
    legacy_vsl_dsp_logic_c_VSL_Decode_Frequency["VSL_Decode_Frequency"]
    class legacy_vsl_dsp_logic_c_VSL_Decode_Frequency fn;
    legacy_vsl_dsp_logic_c --> legacy_vsl_dsp_logic_c_VSL_Decode_Frequency
    src_vsl_dsp_logic_c["vsl_dsp_logic.c (c)"]
    class src_vsl_dsp_logic_c mod;
    src_vsl_dsp_logic_c_VSL_Encode_Gain["VSL_Encode_Gain"]
    class src_vsl_dsp_logic_c_VSL_Encode_Gain fn;
    src_vsl_dsp_logic_c --> src_vsl_dsp_logic_c_VSL_Encode_Gain
    src_vsl_dsp_logic_c_VSL_Map_Frequency["VSL_Map_Frequency"]
    class src_vsl_dsp_logic_c_VSL_Map_Frequency fn;
    src_vsl_dsp_logic_c --> src_vsl_dsp_logic_c_VSL_Map_Frequency
    src_vsl_dsp_logic_c_VSL_Final_Encode_To_Int["VSL_Final_Encode_To_Int"]
    class src_vsl_dsp_logic_c_VSL_Final_Encode_To_Int fn;
    src_vsl_dsp_logic_c --> src_vsl_dsp_logic_c_VSL_Final_Encode_To_Int
    src_vsl_dsp_logic_c_VSL_Decode_Frequency["VSL_Decode_Frequency"]
    class src_vsl_dsp_logic_c_VSL_Decode_Frequency fn;
    src_vsl_dsp_logic_c --> src_vsl_dsp_logic_c_VSL_Decode_Frequency
    legacy_build_dkms_sh["build-dkms.sh (sh)"]
    class legacy_build_dkms_sh mod;
    legacy_build_dkms_sh_print_header["print_header"]
    class legacy_build_dkms_sh_print_header fn;
    legacy_build_dkms_sh --> legacy_build_dkms_sh_print_header
    legacy_build_dkms_sh_print_success["print_success"]
    class legacy_build_dkms_sh_print_success fn;
    legacy_build_dkms_sh --> legacy_build_dkms_sh_print_success
    legacy_build_dkms_sh_print_error["print_error"]
    class legacy_build_dkms_sh_print_error fn;
    legacy_build_dkms_sh --> legacy_build_dkms_sh_print_error
    legacy_build_dkms_sh_print_warning["print_warning"]
    class legacy_build_dkms_sh_print_warning fn;
    legacy_build_dkms_sh --> legacy_build_dkms_sh_print_warning
    legacy_build_dkms_sh_print_info["print_info"]
    class legacy_build_dkms_sh_print_info fn;
    legacy_build_dkms_sh --> legacy_build_dkms_sh_print_info
    install_sh["install.sh (sh)"]
    class install_sh mod;
    legacy_app_py["app.py (py)"]
    class legacy_app_py mod;
    legacy_test_sh["test.sh (sh)"]
    class legacy_test_sh mod;
    end
    legacy_vsl_core_py -- resolved_imports --> legacy_vsl_config_py
    legacy_vsl_core_py -- resolved_imports --> legacy_vsl_config_py
    legacy_vsl_hid_io_py -- resolved_imports --> legacy_vsl_config_py
    legacy_vsl_hid_io_py -- resolved_imports --> legacy_vsl_transport_py
    legacy_vsl_hid_io_py -- resolved_imports --> legacy_vsl_config_py
    legacy_vsl_hid_io_py -- resolved_imports --> legacy_vsl_core_py
    legacy_vsl_poc_main_py -- resolved_imports --> legacy_vsl_config_py
    legacy_vsl_poc_main_py -- resolved_imports --> legacy_vsl_core_py
    legacy_vsl_poc_main_py -- resolved_imports --> legacy_vsl_transport_py
    legacy_vsl_transport_py -- resolved_imports --> legacy_vsl_config_py
    legacy_vsl_transport_py -- resolved_imports --> legacy_vsl_config_py
    ext_audiobox_vsl_h["audiobox_vsl.h"]
    class ext_audiobox_vsl_h ext;
    audiobox_vsl_c -.->|imports| ext_audiobox_vsl_h
    ext_linux_module_h["module.h"]
    class ext_linux_module_h ext;
    audiobox_vsl_c -.->|imports| ext_linux_module_h
    ext_linux_printk_h["printk.h"]
    class ext_linux_printk_h ext;
    audiobox_vsl_c -.->|imports| ext_linux_printk_h
    ext_linux_usb_h["usb.h"]
    class ext_linux_usb_h ext;
    audiobox_vsl_c -.->|imports| ext_linux_usb_h
    ext_linux_types_h["types.h"]
    class ext_linux_types_h ext;
    audiobox_vsl_h -.->|imports| ext_linux_types_h
    audiobox_vsl_h -.->|imports| ext_linux_usb_h
    ext_sound_core_h["core.h"]
    class ext_sound_core_h ext;
    audiobox_vsl_h -.->|imports| ext_sound_core_h
    audiobox_vsl_mod_c -.->|imports| ext_linux_module_h
    ext_linux_export_internal_h["export-internal.h"]
    class ext_linux_export_internal_h ext;
    audiobox_vsl_mod_c -.->|imports| ext_linux_export_internal_h
    ext_linux_compiler_h["compiler.h"]
    class ext_linux_compiler_h ext;
    audiobox_vsl_mod_c -.->|imports| ext_linux_compiler_h
    ext_stdio_h["stdio.h"]
    class ext_stdio_h ext;
    legacy_main_c -.->|imports| ext_stdio_h
    ext_vsl_dsp_logic_h["vsl_dsp_logic.h"]
    class ext_vsl_dsp_logic_h ext;
    legacy_main_c -.->|imports| ext_vsl_dsp_logic_h
    ext_vsl_dsp_transport_h["vsl_dsp_transport.h"]
    class ext_vsl_dsp_transport_h ext;
    legacy_main_c -.->|imports| ext_vsl_dsp_transport_h
    ext_linux_bitfield_h["bitfield.h"]
    class ext_linux_bitfield_h ext;
    legacy_mixer_quirks_c -.->|imports| ext_linux_bitfield_h
    ext_linux_hid_h["hid.h"]
    class ext_linux_hid_h ext;
    legacy_mixer_quirks_c -.->|imports| ext_linux_hid_h
    ext_linux_init_h["init.h"]
    class ext_linux_init_h ext;
    legacy_mixer_quirks_c -.->|imports| ext_linux_init_h
    ext_linux_input_h["input.h"]
    class ext_linux_input_h ext;
    legacy_mixer_quirks_c -.->|imports| ext_linux_input_h
    ext_linux_math64_h["math64.h"]
    class ext_linux_math64_h ext;
    legacy_mixer_quirks_c -.->|imports| ext_linux_math64_h
    ext_linux_slab_h["slab.h"]
    class ext_linux_slab_h ext;
    legacy_mixer_quirks_c -.->|imports| ext_linux_slab_h
    legacy_mixer_quirks_c -.->|imports| ext_linux_usb_h
    ext_linux_usb_audio_h["audio.h"]
    class ext_linux_usb_audio_h ext;
    legacy_mixer_quirks_c -.->|imports| ext_linux_usb_audio_h
    ext_sound_asoundef_h["asoundef.h"]
    class ext_sound_asoundef_h ext;
    legacy_mixer_quirks_c -.->|imports| ext_sound_asoundef_h
    legacy_mixer_quirks_c -.->|imports| ext_sound_core_h
    ext_sound_control_h["control.h"]
    class ext_sound_control_h ext;
    legacy_mixer_quirks_c -.->|imports| ext_sound_control_h
    ext_sound_hda_verbs_h["hda_verbs.h"]
    class ext_sound_hda_verbs_h ext;
    legacy_mixer_quirks_c -.->|imports| ext_sound_hda_verbs_h
    ext_sound_hwdep_h["hwdep.h"]
    class ext_sound_hwdep_h ext;
    legacy_mixer_quirks_c -.->|imports| ext_sound_hwdep_h
    ext_sound_info_h["info.h"]
    class ext_sound_info_h ext;
    legacy_mixer_quirks_c -.->|imports| ext_sound_info_h
    ext_sound_tlv_h["tlv.h"]
    class ext_sound_tlv_h ext;
    legacy_mixer_quirks_c -.->|imports| ext_sound_tlv_h
    ext_usbaudio_h["usbaudio.h"]
    class ext_usbaudio_h ext;
    legacy_mixer_quirks_c -.->|imports| ext_usbaudio_h
    ext_mixer_h["mixer.h"]
    class ext_mixer_h ext;
    legacy_mixer_quirks_c -.->|imports| ext_mixer_h
    ext_mixer_quirks_h["mixer_quirks.h"]
    class ext_mixer_quirks_h ext;
    legacy_mixer_quirks_c -.->|imports| ext_mixer_quirks_h
    legacy_mixer_quirks_c -.->|imports| ext_audiobox_vsl_h
    ext_mixer_scarlett_h["mixer_scarlett.h"]
    class ext_mixer_scarlett_h ext;
    legacy_mixer_quirks_c -.->|imports| ext_mixer_scarlett_h
    ext_mixer_scarlett2_h["mixer_scarlett2.h"]
    class ext_mixer_scarlett2_h ext;
    legacy_mixer_quirks_c -.->|imports| ext_mixer_scarlett2_h
    ext_mixer_us16x08_h["mixer_us16x08.h"]
    class ext_mixer_us16x08_h ext;
    legacy_mixer_quirks_c -.->|imports| ext_mixer_us16x08_h
    ext_mixer_s1810c_h["mixer_s1810c.h"]
    class ext_mixer_s1810c_h ext;
    legacy_mixer_quirks_c -.->|imports| ext_mixer_s1810c_h
    ext_helper_h["helper.h"]
    class ext_helper_h ext;
    legacy_mixer_quirks_c -.->|imports| ext_helper_h
    ext_fcp_h["fcp.h"]
    class ext_fcp_h ext;
    legacy_mixer_quirks_c -.->|imports| ext_fcp_h
    legacy_test_connection_c -.->|imports| ext_stdio_h
    ext_vsl_config_h["vsl_config.h"]
    class ext_vsl_config_h ext;
    legacy_test_connection_c -.->|imports| ext_vsl_config_h
    legacy_test_connection_c -.->|imports| ext_vsl_dsp_transport_h
    ext_stdint_h["stdint.h"]
    class ext_stdint_h ext;
    legacy_vsl_config_h -.->|imports| ext_stdint_h
    ext_sys["sys"]
    class ext_sys ext;
    legacy_vsl_config_py -.->|imports| ext_sys
    ext_typing["typing"]
    class ext_typing ext;
    legacy_vsl_config_py -.->|imports| ext_typing
    ext_math["math"]
    class ext_math ext;
    legacy_vsl_core_py -.->|imports| ext_math
    legacy_vsl_core_py -.->|imports| ext_typing
    ext_vsl_config["vsl_config"]
    class ext_vsl_config ext;
    legacy_vsl_core_py -.->|imports| ext_vsl_config
    legacy_vsl_core_py -.->|imports| ext_vsl_config
    legacy_vsl_dsp_logic_c -.->|imports| ext_vsl_dsp_logic_h
    legacy_vsl_dsp_logic_h -.->|imports| ext_stdint_h
    ext_math_h["math.h"]
    class ext_math_h ext;
    legacy_vsl_dsp_logic_h -.->|imports| ext_math_h
    ext_float_h["float.h"]
    class ext_float_h ext;
    legacy_vsl_dsp_logic_h -.->|imports| ext_float_h
    legacy_vsl_dsp_transport_c -.->|imports| ext_stdio_h
    ext_string_h["string.h"]
    class ext_string_h ext;
    legacy_vsl_dsp_transport_c -.->|imports| ext_string_h
    legacy_vsl_dsp_transport_c -.->|imports| ext_math_h
    ext_hidapi_hidapi_h["hidapi.h"]
    class ext_hidapi_hidapi_h ext;
    legacy_vsl_dsp_transport_c -.->|imports| ext_hidapi_hidapi_h
    ext_stdlib_h["stdlib.h"]
    class ext_stdlib_h ext;
    legacy_vsl_dsp_transport_c -.->|imports| ext_stdlib_h
    legacy_vsl_dsp_transport_c -.->|imports| ext_vsl_config_h
    legacy_vsl_dsp_transport_c -.->|imports| ext_vsl_dsp_transport_h
    legacy_vsl_dsp_transport_h -.->|imports| ext_stdint_h
    ext_stddef_h["stddef.h"]
    class ext_stddef_h ext;
    legacy_vsl_dsp_transport_h -.->|imports| ext_stddef_h
    legacy_vsl_dsp_transport_h -.->|imports| ext_hidapi_hidapi_h
    legacy_vsl_dsp_transport_h -.->|imports| ext_vsl_config_h
    legacy_vsl_hid_io_py -.->|imports| ext_typing
    legacy_vsl_hid_io_py -.->|imports| ext_sys
    legacy_vsl_hid_io_py -.->|imports| ext_vsl_config
    ext_vsl_transport["vsl_transport"]
    class ext_vsl_transport ext;
    legacy_vsl_hid_io_py -.->|imports| ext_vsl_transport
    ext_hid["hid"]
    class ext_hid ext;
    legacy_vsl_hid_io_py -.->|imports| ext_hid
    legacy_vsl_hid_io_py -.->|imports| ext_vsl_config
    ext_vsl_core["vsl_core"]
    class ext_vsl_core ext;
    legacy_vsl_hid_io_py -.->|imports| ext_vsl_core
    ext_traceback["traceback"]
    class ext_traceback ext;
    legacy_vsl_hid_io_py -.->|imports| ext_traceback
    legacy_vsl_poc_main_py -.->|imports| ext_sys
    legacy_vsl_poc_main_py -.->|imports| ext_typing
    legacy_vsl_poc_main_py -.->|imports| ext_vsl_config
    legacy_vsl_poc_main_py -.->|imports| ext_vsl_core
    legacy_vsl_poc_main_py -.->|imports| ext_vsl_transport
    legacy_vsl_poc_main_py -.->|imports| ext_traceback
    legacy_vsl_protocol_analyzer_py -.->|imports| ext_math
    legacy_vsl_protocol_analyzer_py -.->|imports| ext_sys
    ext_json["json"]
    class ext_json ext;
    legacy_vsl_protocol_analyzer_py -.->|imports| ext_json
    legacy_vsl_protocol_analyzer_py -.->|imports| ext_typing
    ext_scapy_all["scapy.all"]
    class ext_scapy_all ext;
    legacy_vsl_protocol_analyzer_py -.->|imports| ext_scapy_all
    legacy_vsl_transport_py -.->|imports| ext_typing
    legacy_vsl_transport_py -.->|imports| ext_vsl_config
    legacy_vsl_transport_py -.->|imports| ext_vsl_config
    src_vsl_cli_c -.->|imports| ext_stdio_h
    src_vsl_cli_c -.->|imports| ext_stdlib_h
    src_vsl_cli_c -.->|imports| ext_string_h
    src_vsl_cli_c -.->|imports| ext_math_h
    src_vsl_cli_c -.->|imports| ext_stdint_h
    src_vsl_cli_c -.->|imports| ext_vsl_dsp_logic_h
    src_vsl_cli_c -.->|imports| ext_vsl_dsp_transport_h
    src_vsl_dsp_logic_c -.->|imports| ext_vsl_dsp_logic_h
    src_vsl_dsp_logic_h -.->|imports| ext_stdint_h
    src_vsl_dsp_logic_h -.->|imports| ext_math_h
    src_vsl_dsp_logic_h -.->|imports| ext_float_h
    src_vsl_dsp_transport_c -.->|imports| ext_vsl_dsp_transport_h
    src_vsl_dsp_transport_c -.->|imports| ext_stdio_h
    src_vsl_dsp_transport_c -.->|imports| ext_stdlib_h
    src_vsl_dsp_transport_c -.->|imports| ext_string_h
    ext_libusb_1_0_libusb_h["libusb.h"]
    class ext_libusb_1_0_libusb_h ext;
    src_vsl_dsp_transport_c -.->|imports| ext_libusb_1_0_libusb_h
    src_vsl_dsp_transport_h -.->|imports| ext_stdint_h
    src_vsl_dsp_transport_h -.->|imports| ext_vsl_dsp_logic_h
    ext_stdarg_h["stdarg.h"]
    class ext_stdarg_h ext;
    tests_test_audiobox_vsl_c -.->|imports| ext_stdarg_h
    tests_test_audiobox_vsl_c -.->|imports| ext_stddef_h
    ext_setjmp_h["setjmp.h"]
    class ext_setjmp_h ext;
    tests_test_audiobox_vsl_c -.->|imports| ext_setjmp_h
    tests_test_audiobox_vsl_c -.->|imports| ext_stdint_h
    ext_cmocka_h["cmocka.h"]
    class ext_cmocka_h ext;
    tests_test_audiobox_vsl_c -.->|imports| ext_cmocka_h
    tests_test_audiobox_vsl_c -.->|imports| ext_audiobox_vsl_h
    tests_test_vsl_dsp_logic_c -.->|imports| ext_stdarg_h
    tests_test_vsl_dsp_logic_c -.->|imports| ext_stddef_h
    tests_test_vsl_dsp_logic_c -.->|imports| ext_setjmp_h
    tests_test_vsl_dsp_logic_c -.->|imports| ext_cmocka_h
    tests_test_vsl_dsp_logic_c -.->|imports| ext_math_h
    tests_test_vsl_dsp_logic_c -.->|imports| ext_float_h
    tests_test_vsl_dsp_logic_c -.->|imports| ext_vsl_dsp_logic_h
```

---

## Architecture Reference

### C (12 files)

#### `audiobox_vsl.c`
**Path:** `audiobox_vsl.c`
**File Doc:** *SPDX-License-Identifier: GPL-2.0-or-later*

**Functions:**
- `audiobox_probe` (line 36) `static int audiobox_probe(struct usb_interface *intf,
                          const struct usb_...`
- `audiobox_disconnect` (line 58) `static void audiobox_disconnect(struct usb_interface *intf)`

**Macros:**
- `AUDIOBOX_DRIVER_NAME` (line 24)
- `AUDIOBOX_DRIVER_DESC` (line 26)
- `AUDIOBOX_DRIVER_LIC` (line 27)

#### `audiobox_vsl.mod.c`
**Path:** `audiobox_vsl.mod.c`
**File Doc:** *include <linux/module.h> include <linux/export-internal.h> include <linux/compiler.h>*

*No symbols extracted*

#### `main.c`
**Path:** `legacy/main.c`
**File Doc:** *include <stdio.h> include "vsl_dsp_logic.h" include "vsl_dsp_transport.h"*

**Functions:**
- `main` (line 4) `int main()` - *include <stdio.h> include "vsl_dsp_logic.h" include "vsl_dsp_transport.h"*

#### `mixer_quirks.c`
**Path:** `legacy/mixer_quirks.c`
**File Doc:** *SPDX-License-Identifier: GPL-2.0-or-later*

**Functions:**
- `snd_create_std_mono_ctl_offset` (line 59) `static int snd_create_std_mono_ctl_offset(struct usb_mixer_interface *mixer,
					  unsigned int ...` - *This function allows for the creation of standard UAC controls. See the quirks for M-Audio FTUs or Ebox-44. If you don't want to set a TLV callback...*
- `snd_create_std_mono_ctl` (line 112) `static int snd_create_std_mono_ctl(struct usb_mixer_interface *mixer,
				   unsigned int unitid,...`
- `snd_create_std_mono_table` (line 129) `static int snd_create_std_mono_table(struct usb_mixer_interface *mixer,
				     const struct std...` - *Create a set of standard UAC controls from a table*
- `add_single_ctl_with_resume` (line 145) `static int add_single_ctl_with_resume(struct usb_mixer_interface *mixer,
				      int id,
				  ...`
- `snd_usb_soundblaster_remote_complete` (line 199) `static void snd_usb_soundblaster_remote_complete(struct urb *urb)`
- `snd_usb_sbrc_hwdep_read` (line 219) `static long snd_usb_sbrc_hwdep_read(struct snd_hwdep *hw, char __user *buf,
				    long count, l...`
- `snd_usb_sbrc_hwdep_poll` (line 239) `static __poll_t snd_usb_sbrc_hwdep_poll(struct snd_hwdep *hw, struct file *file,
					poll_table ...`
- `snd_usb_soundblaster_remote_init` (line 248) `static int snd_usb_soundblaster_remote_init(struct usb_mixer_interface *mixer)`
- `snd_audigy2nx_led_get` (line 298) `static int snd_audigy2nx_led_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)` - *define snd_audigy2nx_led_info		snd_ctl_boolean_mono_info*
- `snd_audigy2nx_led_update` (line 304) `static int snd_audigy2nx_led_update(struct usb_mixer_interface *mixer,
				    int value, int index)`
- `snd_audigy2nx_led_put` (line 333) `static int snd_audigy2nx_led_put(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_value *u...`
- `snd_audigy2nx_led_resume` (line 352) `static int snd_audigy2nx_led_resume(struct usb_mixer_elem_list *list)`
- `snd_audigy2nx_controls_create` (line 374) `static int snd_audigy2nx_controls_create(struct usb_mixer_interface *mixer)`
- `snd_audigy2nx_proc_read` (line 406) `static void snd_audigy2nx_proc_read(struct snd_info_entry *entry,
				    struct snd_info_buffer ...`
- `snd_emu0204_ch_switch_info` (line 457) `static int snd_emu0204_ch_switch_info(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_ele...` - *return; err = snd_usb_ctl_msg(mixer->chip->dev, usb_rcvctrlpipe(mixer->chip->dev, 0), UAC_GET_MEM, USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFAC...*
- `snd_emu0204_ch_switch_get` (line 464) `static int snd_emu0204_ch_switch_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- `snd_emu0204_ch_switch_update` (line 471) `static int snd_emu0204_ch_switch_update(struct usb_mixer_interface *mixer,
					int value)`
- `snd_emu0204_ch_switch_put` (line 489) `static int snd_emu0204_ch_switch_put(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- `snd_emu0204_ch_switch_resume` (line 508) `static int snd_emu0204_ch_switch_resume(struct usb_mixer_elem_list *list)`
- `snd_emu0204_controls_create` (line 523) `static int snd_emu0204_controls_create(struct usb_mixer_interface *mixer)`
- `snd_dualsense_ih_event` (line 549) `static void snd_dualsense_ih_event(struct input_handle *handle,
				   unsigned int type, unsigne...`
- `snd_dualsense_ih_match` (line 570) `static bool snd_dualsense_ih_match(struct input_handler *handler,
				   struct input_dev *dev)`
- `snd_dualsense_ih_connect` (line 617) `static int snd_dualsense_ih_connect(struct input_handler *handler,
				    struct input_dev *dev,...`
- `snd_dualsense_ih_disconnect` (line 649) `static void snd_dualsense_ih_disconnect(struct input_handle *handle)`
- `snd_dualsense_ih_start` (line 656) `static void snd_dualsense_ih_start(struct input_handle *handle)`
- `snd_dualsense_jack_get` (line 679) `static int snd_dualsense_jack_get(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...`
- `snd_dualsense_resume_jack` (line 696) `static int snd_dualsense_resume_jack(struct usb_mixer_elem_list *list)`
- `snd_dualsense_mixer_elem_free` (line 703) `static void snd_dualsense_mixer_elem_free(struct snd_kcontrol *kctl)`
- `snd_dualsense_jack_create` (line 713) `static int snd_dualsense_jack_create(struct usb_mixer_interface *mixer,
				     const char *name...`
- `snd_dualsense_controls_create` (line 777) `static int snd_dualsense_controls_create(struct usb_mixer_interface *mixer)`
- `snd_xonar_u1_switch_get` (line 791) `static int snd_xonar_u1_switch_get(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...` - *static int snd_dualsense_controls_create(struct usb_mixer_interface *mixer) { int err; err = snd_dualsense_jack_create(mixer, "Headphone Jack", tru...*
- `snd_xonar_u1_switch_update` (line 798) `static int snd_xonar_u1_switch_update(struct usb_mixer_interface *mixer,
				      unsigned char ...`
- `snd_xonar_u1_switch_put` (line 812) `static int snd_xonar_u1_switch_put(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...`
- `snd_xonar_u1_switch_resume` (line 832) `static int snd_xonar_u1_switch_resume(struct usb_mixer_elem_list *list)`
- `snd_xonar_u1_controls_create` (line 847) `static int snd_xonar_u1_controls_create(struct usb_mixer_interface *mixer)`
- `snd_mbox1_is_spdif_synced` (line 856) `static int snd_mbox1_is_spdif_synced(struct snd_usb_audio *chip)` - *.info = snd_ctl_boolean_mono_info, .get = snd_xonar_u1_switch_get, .put = snd_xonar_u1_switch_put, .private_value = 0x05, }; static int snd_xonar_u...*
- `snd_mbox1_set_clk_source` (line 876) `static int snd_mbox1_set_clk_source(struct snd_usb_audio *chip, int rate_or_zero)`
- `snd_mbox1_is_spdif_input` (line 894) `static int snd_mbox1_is_spdif_input(struct snd_usb_audio *chip)`
- `snd_mbox1_set_input_source` (line 914) `static int snd_mbox1_set_input_source(struct snd_usb_audio *chip, int is_spdif)`
- `snd_mbox1_clk_switch_get` (line 933) `static int snd_mbox1_clk_switch_get(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...` - *S/PDIF Source  -> 0x02  unsigned char buff[1]; buff[0] = (is_spdif & 1) + 1; /* Set input source return snd_usb_ctl_msg(chip->dev, usb_sndctrlpipe(...*
- `snd_mbox1_clk_switch_update` (line 953) `static int snd_mbox1_clk_switch_update(struct usb_mixer_interface *mixer, int is_spdif_sync)`
- `snd_mbox1_clk_switch_put` (line 978) `static int snd_mbox1_clk_switch_put(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...`
- `snd_mbox1_clk_switch_info` (line 996) `static int snd_mbox1_clk_switch_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- `snd_mbox1_clk_switch_resume` (line 1007) `static int snd_mbox1_clk_switch_resume(struct usb_mixer_elem_list *list)`
- `snd_mbox1_src_switch_get` (line 1014) `static int snd_mbox1_src_switch_get(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...` - *static const char *const texts[2] = { "Internal", "S/PDIF" }; return snd_ctl_enum_info(uinfo, 1, ARRAY_SIZE(texts), texts); } static int snd_mbox1_...*
- `snd_mbox1_src_switch_update` (line 1021) `static int snd_mbox1_src_switch_update(struct usb_mixer_interface *mixer, int is_spdif_input)`
- `snd_mbox1_src_switch_put` (line 1045) `static int snd_mbox1_src_switch_put(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...`
- `snd_mbox1_src_switch_info` (line 1063) `static int snd_mbox1_src_switch_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- `snd_mbox1_src_switch_resume` (line 1074) `static int snd_mbox1_src_switch_resume(struct usb_mixer_elem_list *list)`
- `snd_mbox1_controls_create` (line 1101) `static int snd_mbox1_controls_create(struct usb_mixer_interface *mixer)`
- `snd_ni_control_init_val` (line 1120) `static int snd_ni_control_init_val(struct usb_mixer_interface *mixer,
				   struct snd_kcontrol ...` - *define _MAKE_NI_CONTROL(bRequest, wIndex) ((bRequest) << 16 | (wIndex))*
- `snd_nativeinstruments_control_get` (line 1142) `static int snd_nativeinstruments_control_get(struct snd_kcontrol *kcontrol,
					     struct snd_...`
- `snd_ni_update_cur_val` (line 1149) `static int snd_ni_update_cur_val(struct usb_mixer_elem_list *list)`
- `snd_nativeinstruments_control_put` (line 1163) `static int snd_nativeinstruments_control_put(struct snd_kcontrol *kcontrol,
					     struct snd_...`
- `snd_nativeinstruments_create_mixer` (line 1234) `static int snd_nativeinstruments_create_mixer(struct usb_mixer_interface *mixer,
					      const...`
- `snd_ftu_eff_switch_info` (line 1267) `static int snd_ftu_eff_switch_info(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_info...` - *err = add_single_ctl_with_resume(mixer, 0, snd_ni_update_cur_val, &template, &list); if (err < 0) break; snd_ni_control_init_val(mixer, list->kctl)...*
- `snd_ftu_eff_switch_init` (line 1277) `static int snd_ftu_eff_switch_init(struct usb_mixer_interface *mixer,
				   struct snd_kcontrol ...`
- `snd_ftu_eff_switch_get` (line 1300) `static int snd_ftu_eff_switch_get(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...`
- `snd_ftu_eff_switch_update` (line 1307) `static int snd_ftu_eff_switch_update(struct usb_mixer_elem_list *list)`
- `snd_ftu_eff_switch_put` (line 1328) `static int snd_ftu_eff_switch_put(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...`
- `snd_ftu_create_effect_switch` (line 1346) `static int snd_ftu_create_effect_switch(struct usb_mixer_interface *mixer,
					int validx, int b...`
- `snd_ftu_create_volume_ctls` (line 1373) `static int snd_ftu_create_volume_ctls(struct usb_mixer_interface *mixer)` - *struct usb_mixer_elem_list *list; int err; err = add_single_ctl_with_resume(mixer, bUnitID, snd_ftu_eff_switch_update, &template, &list); if (err <...*
- `snd_ftu_create_effect_volume_ctl` (line 1412) `static int snd_ftu_create_effect_volume_ctl(struct usb_mixer_interface *mixer)` - *"DIn%d - Out%d Playback Volume", in - 7, out + 1); err = snd_create_std_mono_ctl(mixer, id, control, cmask, val_type, name, &snd_usb_mixer_vol_tlv)...*
- `snd_ftu_create_effect_duration_ctl` (line 1425) `static int snd_ftu_create_effect_duration_ctl(struct usb_mixer_interface *mixer)` - */* This control needs a volume quirk, see mixer.c static int snd_ftu_create_effect_volume_ctl(struct usb_mixer_interface *mixer) { static const cha...*
- `snd_ftu_create_effect_feedback_ctl` (line 1438) `static int snd_ftu_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)` - */* This control needs a volume quirk, see mixer.c static int snd_ftu_create_effect_duration_ctl(struct usb_mixer_interface *mixer) { static const c...*
- `snd_ftu_create_effect_return_ctls` (line 1449) `static int snd_ftu_create_effect_return_ctls(struct usb_mixer_interface *mixer)`
- `snd_ftu_create_effect_send_ctls` (line 1473) `static int snd_ftu_create_effect_send_ctls(struct usb_mixer_interface *mixer)`
- `snd_ftu_create_mixer` (line 1506) `static int snd_ftu_create_mixer(struct usb_mixer_interface *mixer)`
- `snd_emuusb_set_samplerate` (line 1541) `void snd_emuusb_set_samplerate(struct snd_usb_audio *chip,
			       unsigned char samplerate_id)`
- `list_for_each_entry` (line 1548) `list_for_each_entry(mixer, &chip->mixer_list, list)` - *err = snd_ftu_create_effect_send_ctls(mixer); if (err < 0) return err; return 0; } void snd_emuusb_set_samplerate(struct snd_usb_audio *chip, unsig...*
- `snd_c400_create_vol_ctls` (line 1563) `static int snd_c400_create_vol_ctls(struct usb_mixer_interface *mixer)` - *list_for_each_entry(mixer, &chip->mixer_list, list) { if (mixer->id_elems[unitid]) { cval = mixer_elem_list_to_info(mixer->id_elems[unitid]); snd_u...*
- `snd_c400_create_effect_volume_ctl` (line 1612) `static int snd_c400_create_effect_volume_ctl(struct usb_mixer_interface *mixer)` - *cmask = (out == 0) ? 0 : BIT(out - 1); offset = chan * num_outs; err = snd_create_std_mono_ctl_offset(mixer, id, control, cmask, val_type, offset, ...*
- `snd_c400_create_effect_duration_ctl` (line 1625) `static int snd_c400_create_effect_duration_ctl(struct usb_mixer_interface *mixer)` - */* This control needs a volume quirk, see mixer.c static int snd_c400_create_effect_volume_ctl(struct usb_mixer_interface *mixer) { static const ch...*
- `snd_c400_create_effect_feedback_ctl` (line 1638) `static int snd_c400_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)` - */* This control needs a volume quirk, see mixer.c static int snd_c400_create_effect_duration_ctl(struct usb_mixer_interface *mixer) { static const ...*
- `snd_c400_create_effect_vol_ctls` (line 1649) `static int snd_c400_create_effect_vol_ctls(struct usb_mixer_interface *mixer)`
- `snd_c400_create_effect_ret_vol_ctls` (line 1694) `static int snd_c400_create_effect_ret_vol_ctls(struct usb_mixer_interface *mixer)`
- `snd_c400_create_mixer` (line 1736) `static int snd_c400_create_mixer(struct usb_mixer_interface *mixer)`
- `snd_microii_spdif_info` (line 1869) `static int snd_microii_spdif_info(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_info *...` - *power on values: r2: 0x10 r3: 0x20 (b7 is zeroed just before playback (except IEC61937) and set just after it to 0xa0, presumably it disables/mutes...*
- `snd_microii_spdif_default_get` (line 1876) `static int snd_microii_spdif_default_get(struct snd_kcontrol *kcontrol,
					 struct snd_ctl_elem...`
- `snd_microii_spdif_default_update` (line 1923) `static int snd_microii_spdif_default_update(struct usb_mixer_elem_list *list)`
- `snd_microii_spdif_default_put` (line 1959) `static int snd_microii_spdif_default_put(struct snd_kcontrol *kcontrol,
					 struct snd_ctl_elem...`
- `snd_microii_spdif_mask_get` (line 1987) `static int snd_microii_spdif_mask_get(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_ele...`
- `snd_microii_spdif_switch_get` (line 1998) `static int snd_microii_spdif_switch_get(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_v...`
- `snd_microii_spdif_switch_update` (line 2006) `static int snd_microii_spdif_switch_update(struct usb_mixer_elem_list *list)`
- `snd_microii_spdif_switch_put` (line 2025) `static int snd_microii_spdif_switch_put(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_v...`
- `snd_microii_controls_create` (line 2067) `static int snd_microii_controls_create(struct usb_mixer_interface *mixer)`
- `snd_soundblaster_e1_switch_get` (line 2090) `static int snd_soundblaster_e1_switch_get(struct snd_kcontrol *kcontrol,
					  struct snd_ctl_el...` - *for (i = 0; i < ARRAY_SIZE(snd_microii_mixer_spdif); ++i) { err = add_single_ctl_with_resume(mixer, 0, resume_funcs[i], &snd_microii_mixer_spdif[i]...*
- `snd_soundblaster_e1_switch_update` (line 2097) `static int snd_soundblaster_e1_switch_update(struct usb_mixer_interface *mixer,
					     unsigne...`
- `snd_soundblaster_e1_switch_put` (line 2115) `static int snd_soundblaster_e1_switch_put(struct snd_kcontrol *kcontrol,
					  struct snd_ctl_el...`
- `snd_soundblaster_e1_switch_resume` (line 2129) `static int snd_soundblaster_e1_switch_resume(struct usb_mixer_elem_list *list)`
- `snd_soundblaster_e1_switch_info` (line 2135) `static int snd_soundblaster_e1_switch_info(struct snd_kcontrol *kcontrol,
					   struct snd_ctl_...`
- `snd_soundblaster_e1_switch_create` (line 2154) `static int snd_soundblaster_e1_switch_create(struct usb_mixer_interface *mixer)`
- `realtek_hda_set` (line 2191) `static int realtek_hda_set(struct snd_usb_audio *chip, u32 cmd)` - *define REALTEK_MIC_FLAG 0x100*
- `realtek_hda_get` (line 2201) `static int realtek_hda_get(struct snd_usb_audio *chip, u32 cmd, u32 *value)`
- `realtek_ctl_connector_get` (line 2222) `static int realtek_ctl_connector_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- `realtek_resume_jack` (line 2272) `static int realtek_resume_jack(struct usb_mixer_elem_list *list)`
- `realtek_add_jack` (line 2279) `static int realtek_add_jack(struct usb_mixer_interface *mixer,
			    char *name, u32 val)`
- `dell_dock_mixer_create` (line 2306) `static int dell_dock_mixer_create(struct usb_mixer_interface *mixer)`
- `dell_dock_init_vol` (line 2338) `static void dell_dock_init_vol(struct usb_mixer_interface *mixer, int ch, int id)`
- `dell_dock_mixer_init` (line 2350) `static int dell_dock_mixer_init(struct usb_mixer_interface *mixer)`
- `snd_rme_read_value` (line 2418) `static int snd_rme_read_value(struct snd_usb_audio *chip,
			      unsigned int item,
			      u3...`
- `snd_rme_get_status1` (line 2437) `static int snd_rme_get_status1(struct snd_kcontrol *kcontrol,
			       u32 *status1)`
- `snd_rme_rate_get` (line 2449) `static int snd_rme_rate_get(struct snd_kcontrol *kcontrol,
			    struct snd_ctl_elem_value *ucon...`
- `snd_rme_sync_state_get` (line 2483) `static int snd_rme_sync_state_get(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_value ...`
- `snd_rme_spdif_if_get` (line 2513) `static int snd_rme_spdif_if_get(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *uco...`
- `snd_rme_spdif_format_get` (line 2526) `static int snd_rme_spdif_format_get(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_va...`
- `snd_rme_sync_source_get` (line 2539) `static int snd_rme_sync_source_get(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...`
- `snd_rme_current_freq_get` (line 2552) `static int snd_rme_current_freq_get(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_va...`
- `snd_rme_rate_info` (line 2578) `static int snd_rme_rate_info(struct snd_kcontrol *kcontrol,
			     struct snd_ctl_elem_info *uinfo)`
- `snd_rme_sync_state_info` (line 2598) `static int snd_rme_sync_state_info(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_info...`
- `snd_rme_spdif_if_info` (line 2609) `static int snd_rme_spdif_if_info(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_info *ui...`
- `snd_rme_spdif_format_info` (line 2620) `static int snd_rme_spdif_format_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- `snd_rme_sync_source_info` (line 2631) `static int snd_rme_sync_source_info(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_in...`
- `snd_rme_controls_create` (line 2713) `static int snd_rme_controls_create(struct usb_mixer_interface *mixer)`
- `snd_bbfpro_ctl_update` (line 2779) `static int snd_bbfpro_ctl_update(struct usb_mixer_interface *mixer, u8 reg,
				 u8 index, u8 value)` - *define SND_BBFPRO_USBREQ_CTL_REG1 0x10 define SND_BBFPRO_USBREQ_CTL_REG2 0x17 define SND_BBFPRO_USBREQ_GAIN 0x1a define SND_BBFPRO_USBREQ_MIXER 0x12*
- `snd_bbfpro_ctl_get` (line 2810) `static int snd_bbfpro_ctl_get(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...`
- `snd_bbfpro_ctl_info` (line 2833) `static int snd_bbfpro_ctl_info(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_info ...`
- `snd_bbfpro_ctl_put` (line 2867) `static int snd_bbfpro_ctl_put(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...`
- `snd_bbfpro_ctl_resume` (line 2906) `static int snd_bbfpro_ctl_resume(struct usb_mixer_elem_list *list)`
- `snd_bbfpro_gain_update` (line 2919) `static int snd_bbfpro_gain_update(struct usb_mixer_interface *mixer,
				  u8 channel, u8 gain)`
- `snd_bbfpro_gain_get` (line 2943) `static int snd_bbfpro_gain_get(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_value...`
- `snd_bbfpro_gain_info` (line 2952) `static int snd_bbfpro_gain_info(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_info *uinfo)`
- `snd_bbfpro_gain_put` (line 2973) `static int snd_bbfpro_gain_put(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_value...`
- `snd_bbfpro_gain_resume` (line 3010) `static int snd_bbfpro_gain_resume(struct usb_mixer_elem_list *list)`
- `snd_bbfpro_vol_update` (line 3023) `static int snd_bbfpro_vol_update(struct usb_mixer_interface *mixer, u16 index,
				 u32 value)`
- `snd_bbfpro_vol_get` (line 3049) `static int snd_bbfpro_vol_get(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...`
- `snd_bbfpro_vol_info` (line 3057) `static int snd_bbfpro_vol_info(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_info ...`
- `snd_bbfpro_vol_put` (line 3067) `static int snd_bbfpro_vol_put(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...`
- `snd_bbfpro_vol_resume` (line 3095) `static int snd_bbfpro_vol_resume(struct usb_mixer_elem_list *list)`
- `snd_bbfpro_ctl_add` (line 3132) `static int snd_bbfpro_ctl_add(struct usb_mixer_interface *mixer, u8 reg,
			      u8 index, char ...`
- `snd_bbfpro_gain_add` (line 3146) `static int snd_bbfpro_gain_add(struct usb_mixer_interface *mixer, u8 channel,
			       char *name)`
- `snd_bbfpro_vol_add` (line 3158) `static int snd_bbfpro_vol_add(struct usb_mixer_interface *mixer, u16 index,
			      char *name)`
- `snd_bbfpro_controls_create` (line 3170) `static int snd_bbfpro_controls_create(struct usb_mixer_interface *mixer)`
- `snd_rme_digiface_write_reg` (line 3318) `static int snd_rme_digiface_write_reg(struct snd_kcontrol *kcontrol, int item, u16 mask, u16 val)` - *#define RME_DIGIFACE_STATUS_REG2H 5 #define RME_DIGIFACE_STATUS_REG3L 6 #define RME_DIGIFACE_STATUS_REG3H 7 #define RME_DIGIFACE_CTL_REG1 16 #defin...*
- `snd_rme_digiface_read_status` (line 3336) `static int snd_rme_digiface_read_status(struct snd_kcontrol *kcontrol, u32 status[4])`
- `snd_rme_digiface_get_status_val` (line 3360) `static int snd_rme_digiface_get_status_val(struct snd_kcontrol *kcontrol)`
- `snd_rme_digiface_rate_get` (line 3398) `static int snd_rme_digiface_rate_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- `snd_rme_digiface_enum_get` (line 3412) `static int snd_rme_digiface_enum_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- `snd_rme_digiface_enum_put` (line 3424) `static int snd_rme_digiface_enum_put(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- `snd_rme_digiface_current_sync_get` (line 3438) `static int snd_rme_digiface_current_sync_get(struct snd_kcontrol *kcontrol,
					     struct snd_...`
- `snd_rme_digiface_sync_state_get` (line 3450) `static int snd_rme_digiface_sync_state_get(struct snd_kcontrol *kcontrol,
					   struct snd_ctl_...`
- `snd_rme_digiface_format_info` (line 3473) `static int snd_rme_digiface_format_info(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_i...`
- `snd_rme_digiface_sync_source_info` (line 3484) `static int snd_rme_digiface_sync_source_info(struct snd_kcontrol *kcontrol,
					     struct snd_...`
- `snd_rme_digiface_rate_info` (line 3495) `static int snd_rme_digiface_rate_info(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_ele...`
- `snd_rme_digiface_controls_create` (line 3684) `static int snd_rme_digiface_controls_create(struct usb_mixer_interface *mixer)`
- `snd_djm_get_label_caplevel_common` (line 3791) `static const char *snd_djm_get_label_caplevel_common(u16 wvalue)`
- `snd_djm_get_label_caplevel_high` (line 3804) `static const char *snd_djm_get_label_caplevel_high(u16 wvalue)` - *Models like DJM-A9 or DJM-V10 have different capture levels than others*
- `snd_djm_get_label_cap_common` (line 3816) `static const char *snd_djm_get_label_cap_common(u16 wvalue)`
- `snd_djm_get_label_cap_850` (line 3849) `static const char *snd_djm_get_label_cap_850(u16 wvalue)` - *The DJM-850 has different values for CD/LINE and LINE capture control options than the other DJM declared in this file.*
- `snd_djm_get_label_caplevel` (line 3857) `static const char *snd_djm_get_label_caplevel(u8 device_idx, u16 wvalue)`
- `snd_djm_get_label_cap` (line 3866) `static const char *snd_djm_get_label_cap(u8 device_idx, u16 wvalue)`
- `snd_djm_get_label_pb` (line 3874) `static const char *snd_djm_get_label_pb(u16 wvalue)`
- `snd_djm_get_label` (line 3884) `static const char *snd_djm_get_label(u8 device_idx, u16 wvalue, u16 windex)`
- `snd_djm_controls_info` (line 4116) `static int snd_djm_controls_info(struct snd_kcontrol *kctl,
				 struct snd_ctl_elem_info *info)`
- `snd_djm_controls_update` (line 4148) `static int snd_djm_controls_update(struct usb_mixer_interface *mixer,
				   u8 device_idx, u8 gr...`
- `snd_djm_controls_get` (line 4169) `static int snd_djm_controls_get(struct snd_kcontrol *kctl,
				struct snd_ctl_elem_value *elem)`
- `snd_djm_controls_put` (line 4176) `static int snd_djm_controls_put(struct snd_kcontrol *kctl, struct snd_ctl_elem_value *elem)`
- `snd_djm_controls_resume` (line 4193) `static int snd_djm_controls_resume(struct usb_mixer_elem_list *list)`
- `snd_djm_controls_create` (line 4203) `static int snd_djm_controls_create(struct usb_mixer_interface *mixer,
				   const u8 device_idx)`
- `snd_usb_mixer_apply_create_quirk` (line 4238) `int snd_usb_mixer_apply_create_quirk(struct usb_mixer_interface *mixer)`
- `snd_usb_mixer_resume_quirk` (line 4420) `void snd_usb_mixer_resume_quirk(struct usb_mixer_interface *mixer)`
- `snd_usb_mixer_rc_memory_change` (line 4429) `void snd_usb_mixer_rc_memory_change(struct usb_mixer_interface *mixer,
				    int unitid)`
- `snd_dragonfly_quirk_db_scale` (line 4457) `static void snd_dragonfly_quirk_db_scale(struct usb_mixer_interface *mixer,
					 struct usb_mixe...`
- `snd_fix_plt_name` (line 4509) `static void snd_fix_plt_name(struct snd_usb_audio *chip,
			     struct snd_ctl_elem_id *id)` - *standards. This function fixes nonstandard source names. By the time this function is called the control name should look like one of these: "sourc...*
- `snd_usb_mixer_fu_apply_quirk` (line 4538) `void snd_usb_mixer_fu_apply_quirk(struct usb_mixer_interface *mixer,
				  struct usb_mixer_elem_...`

**Macros:**
- `snd_audigy2nx_led_info` (line 296)
- `SND_DUALSENSE_JACK_OUT_TERM_ID` (line 539)
- `SND_DUALSENSE_JACK_IN_TERM_ID` (line 541)
- `_MAKE_NI_CONTROL` (line 1118)
- `HDA_VERB_CMD` (line 2171)
- `REALTEK_HDA_VALUE` (line 2173)
- `REALTEK_HDA_SET` (line 2175)
- `REALTEK_MANUAL_MODE` (line 2177)
- `REALTEK_HDA_GET_OUT` (line 2178)
- `REALTEK_HDA_GET_IN` (line 2179)
- `REALTEK_AUDIO_FUNCTION_GROUP` (line 2180)
- `REALTEK_LINE1` (line 2182)
- `REALTEK_VENDOR_REGISTERS` (line 2183)
- `REALTEK_HP_OUT` (line 2184)
- `REALTEK_CBJ_CTRL2` (line 2185)
- `REALTEK_JACK_INTERRUPT_NODE` (line 2187)
- `REALTEK_MIC_FLAG` (line 2189)
- `SND_RME_GET_STATUS1` (line 2362)
- `SND_RME_GET_CURRENT_FREQ` (line 2364)
- `SND_RME_CLK_SYSTEM_SHIFT` (line 2365)
- `SND_RME_CLK_SYSTEM_MASK` (line 2366)
- `SND_RME_CLK_AES_SHIFT` (line 2367)
- `SND_RME_CLK_SPDIF_SHIFT` (line 2368)
- `SND_RME_CLK_AES_SPDIF_MASK` (line 2369)
- `SND_RME_CLK_SYNC_SHIFT` (line 2370)
- `SND_RME_CLK_SYNC_MASK` (line 2371)
- `SND_RME_CLK_FREQMUL_SHIFT` (line 2372)
- `SND_RME_CLK_FREQMUL_MASK` (line 2373)
- `SND_RME_CLK_SYSTEM` (line 2374)
- `SND_RME_CLK_AES` (line 2376)
- `SND_RME_CLK_SPDIF` (line 2378)
- `SND_RME_CLK_SYNC` (line 2380)
- `SND_RME_CLK_FREQMUL` (line 2382)
- `SND_RME_CLK_AES_LOCK` (line 2384)
- `SND_RME_CLK_AES_SYNC` (line 2385)
- `SND_RME_CLK_SPDIF_LOCK` (line 2386)
- `SND_RME_CLK_SPDIF_SYNC` (line 2387)
- `SND_RME_SPDIF_IF_SHIFT` (line 2388)
- `SND_RME_SPDIF_FORMAT_SHIFT` (line 2389)
- `SND_RME_BINARY_MASK` (line 2390)
- `SND_RME_SPDIF_IF` (line 2391)
- `SND_RME_SPDIF_FORMAT` (line 2393)
- `SND_RME_RATE_IDX_AES_SPDIF_NUM` (line 2405)
- `SND_BBFPRO_CTL_REG_MASK` (line 2743)
- `SND_BBFPRO_CTL_IDX_MASK` (line 2745)
- `SND_BBFPRO_CTL_IDX_SHIFT` (line 2746)
- `SND_BBFPRO_CTL_VAL_MASK` (line 2747)
- `SND_BBFPRO_CTL_VAL_SHIFT` (line 2748)
- `SND_BBFPRO_CTL_REG1_CLK_MASTER` (line 2749)
- `SND_BBFPRO_CTL_REG1_CLK_OPTICAL` (line 2750)
- `SND_BBFPRO_CTL_REG1_SPDIF_PRO` (line 2751)
- `SND_BBFPRO_CTL_REG1_SPDIF_EMPH` (line 2752)
- `SND_BBFPRO_CTL_REG1_SPDIF_OPTICAL` (line 2753)
- `SND_BBFPRO_CTL_REG2_48V_AN1` (line 2754)
- `SND_BBFPRO_CTL_REG2_48V_AN2` (line 2755)
- `SND_BBFPRO_CTL_REG2_SENS_IN3` (line 2756)
- `SND_BBFPRO_CTL_REG2_SENS_IN4` (line 2757)
- `SND_BBFPRO_CTL_REG2_PAD_AN1` (line 2758)
- `SND_BBFPRO_CTL_REG2_PAD_AN2` (line 2759)
- `SND_BBFPRO_MIXER_MAIN_OUT_CH_OFFSET` (line 2760)
- `SND_BBFPRO_MIXER_IDX_MASK` (line 2762)
- `SND_BBFPRO_MIXER_VAL_MASK` (line 2763)
- `SND_BBFPRO_MIXER_VAL_SHIFT` (line 2764)
- `SND_BBFPRO_MIXER_VAL_MIN` (line 2765)
- `SND_BBFPRO_MIXER_VAL_MAX` (line 2766)
- `SND_BBFPRO_GAIN_CHANNEL_MASK` (line 2767)
- `SND_BBFPRO_GAIN_CHANNEL_SHIFT` (line 2769)
- `SND_BBFPRO_GAIN_VAL_MASK` (line 2770)
- `SND_BBFPRO_GAIN_VAL_MIN` (line 2771)
- `SND_BBFPRO_GAIN_VAL_MIC_MAX` (line 2772)
- `SND_BBFPRO_GAIN_VAL_LINE_MAX` (line 2773)
- `SND_BBFPRO_USBREQ_CTL_REG1` (line 2774)
- `SND_BBFPRO_USBREQ_CTL_REG2` (line 2776)
- `SND_BBFPRO_USBREQ_GAIN` (line 2777)
- `SND_BBFPRO_USBREQ_MIXER` (line 2778)
- `RME_DIGIFACE_READ_STATUS` (line 3297)
- `RME_DIGIFACE_STATUS_REG0L` (line 3299)
- `RME_DIGIFACE_STATUS_REG0H` (line 3300)
- `RME_DIGIFACE_STATUS_REG1L` (line 3301)
- `RME_DIGIFACE_STATUS_REG1H` (line 3302)
- `RME_DIGIFACE_STATUS_REG2L` (line 3303)
- `RME_DIGIFACE_STATUS_REG2H` (line 3304)
- `RME_DIGIFACE_STATUS_REG3L` (line 3305)
- `RME_DIGIFACE_STATUS_REG3H` (line 3306)
- `RME_DIGIFACE_CTL_REG1` (line 3307)
- `RME_DIGIFACE_CTL_REG2` (line 3309)
- `RME_DIGIFACE_REGISTER` (line 3312)
- `RME_DIGIFACE_INVERT` (line 3313)
- `field_get` (line 3316)
- `field_prep` (line 3317)
- `SND_DJM_CAP_LINE` (line 3715)
- `SND_DJM_CAP_CDLINE` (line 3716)
- `SND_DJM_CAP_DIGITAL` (line 3717)
- `SND_DJM_CAP_PHONO` (line 3718)
- `SND_DJM_CAP_PREFADER` (line 3719)
- `SND_DJM_CAP_PFADER` (line 3720)
- `SND_DJM_CAP_XFADERA` (line 3721)
- `SND_DJM_CAP_XFADERB` (line 3722)
- `SND_DJM_CAP_MIC` (line 3723)
- `SND_DJM_CAP_AUX` (line 3724)
- `SND_DJM_CAP_RECOUT` (line 3725)
- `SND_DJM_CAP_RECOUT_NOMIC` (line 3726)
- `SND_DJM_CAP_NONE` (line 3727)
- `SND_DJM_CAP_FXSEND` (line 3728)
- `SND_DJM_CAP_CH1PFADER` (line 3729)
- `SND_DJM_CAP_CH2PFADER` (line 3730)
- `SND_DJM_CAP_CH3PFADER` (line 3731)
- `SND_DJM_CAP_CH4PFADER` (line 3732)
- `SND_DJM_CAP_EXT1SEND` (line 3733)
- `SND_DJM_CAP_EXT2SEND` (line 3734)
- `SND_DJM_CAP_CH1PREFADER` (line 3735)
- `SND_DJM_CAP_CH2PREFADER` (line 3736)
- `SND_DJM_CAP_CH3PREFADER` (line 3737)
- `SND_DJM_CAP_CH4PREFADER` (line 3738)
- `SND_DJM_PB_CH1` (line 3741)
- `SND_DJM_PB_CH2` (line 3742)
- `SND_DJM_PB_AUX` (line 3743)
- `SND_DJM_WINDEX_CAP` (line 3744)
- `SND_DJM_WINDEX_CAPLVL` (line 3746)
- `SND_DJM_WINDEX_PB` (line 3747)
- `SND_DJM_VALUE_MASK` (line 3750)
- `SND_DJM_GROUP_MASK` (line 3751)
- `SND_DJM_DEVICE_MASK` (line 3752)
- `SND_DJM_GROUP_SHIFT` (line 3753)
- `SND_DJM_DEVICE_SHIFT` (line 3754)
- `SND_DJM_250MK2_IDX` (line 3758)
- `SND_DJM_750_IDX` (line 3759)
- `SND_DJM_850_IDX` (line 3760)
- `SND_DJM_900NXS2_IDX` (line 3761)
- `SND_DJM_750MK2_IDX` (line 3762)
- `SND_DJM_450_IDX` (line 3763)
- `SND_DJM_A9_IDX` (line 3764)
- `SND_DJM_V10_IDX` (line 3765)
- `SND_DJM_CTL` (line 3766)
- `SND_DJM_DEVICE` (line 3773)

**Structs:**
- `std_mono_table` (line 45)
- `rc_config` (line 181) - *Sound Blaster remote control configuration  format of remote control data: Extigy:       xx 00 Audigy 2 NX:  06 80 xx 00 00 00 Live! 24-bit: 06 80 ...*
- `sb_jack` (line 410)
- `dualsense_mixer_elem_info` (line 543)
- `snd_djm_device` (line 3778)
- `snd_djm_ctl` (line 3784)

#### `test_connection.c`
**Path:** `legacy/test_connection.c`
**File Doc:** *test_connection.c  include <stdio.h> include "vsl_config.h" include "vsl_dsp_transport.h" // Asumiendo que esta es la plantilla B*

**Functions:**
- `main` (line 6) `int main()` - *include <stdio.h> include "vsl_config.h" include "vsl_dsp_transport.h" // Asumiendo que esta es la plantilla B*

#### `vsl_dsp_logic.c`
**Path:** `legacy/vsl_dsp_logic.c`
**File Doc:** *include "vsl_dsp_logic.h"  Declaración de la nueva función de envío*

**Functions:**
- `VSL_Encode_Gain` (line 11) `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)` - *Implementación de FUN_00132c90*
- `VSL_Map_Frequency` (line 29) `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)` - *Implementación de FUN_00132d00*
- `VSL_Final_Encode_To_Int` (line 58) `uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)` - *@brief Convierte el valor codificado en float a un entero sin signo para el firmware. @note Basado en la hipótesis común de DSP donde el rango flot...*
- `VSL_Decode_Frequency` (line 78) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)` - *Implementación de FUN_00132da8*

#### `vsl_dsp_transport.c`
**Path:** `legacy/vsl_dsp_transport.c`
**File Doc:** *vsl_dsp_transport.c (Añadir la Plantilla B completa aquí)  include <stdio.h> include <string.h> include <math.h> include <hidapi/hidapi.h> include ...*

**Functions:**
- `VSL_Init_Device` (line 22) `int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)` - *... (las inclusiones y el singleton handle) ...*
- `VSL_Close_Device` (line 69) `void VSL_Close_Device(void)`
- `VSL_Get_Device_Handle` (line 78) `hid_device* VSL_Get_Device_Handle(void)`
- `FUN_Send_Packet` (line 97) `void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length)` - *@brief Función de I/O real usando HIDAPI. @note DEBE SER REEMPLAZADA con la lógica específica de tu dispositivo (Report ID, longitud, etc.)*
- `VSL_Build_And_Send_Packet` (line 140) `void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float)` - *Implementación de la función de construcción y envío*

#### `vsl_cli.c`
**Path:** `src/vsl_cli.c`

**Functions:**
- `print_list` (line 64) `static void print_list(void)`
- `find_by_name` (line 79) `static const ParamEntry *find_by_name(const char *name)`
- `do_send_param` (line 89) `static int do_send_param(uint16_t param_id, float user_value, const VSL_Parameter *coeffs)`
- `main` (line 123) `int main(int argc, char *argv[])`

**Macros:**
- `VSL_VENDOR_ID` (line 22)
- `VSL_PRODUCT_ID` (line 24)

#### `vsl_dsp_logic.c`
**Path:** `src/vsl_dsp_logic.c`
**File Doc:** *include "vsl_dsp_logic.h"  ========================================================================= FUNCIONES DE CODIFICACIÓN (Enviar al DSP) ====...*

**Functions:**
- `VSL_Encode_Gain` (line 8) `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)` - *Implementación de FUN_00132c90*
- `VSL_Map_Frequency` (line 26) `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)` - *Implementación de FUN_00132d00*
- `VSL_Final_Encode_To_Int` (line 55) `uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)` - *@brief Convierte el valor codificado en float a un entero sin signo para el firmware. @note Basado en la hipótesis común de DSP donde el rango flot...*
- `VSL_Decode_Frequency` (line 75) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)` - *Implementación de FUN_00132da8*

#### `vsl_dsp_transport.c`
**Path:** `src/vsl_dsp_transport.c`
**File Doc:** *include "vsl_dsp_transport.h" include <stdio.h> include <stdlib.h> include <string.h> include <libusb-1.0/libusb.h>*

**Functions:**
- `VSL_Init_Device` (line 35) `vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)`
- `VSL_Close_Device` (line 64) `void VSL_Close_Device(vsl_device_handle handle)`
- `VSL_Send_Parameter` (line 80) `int VSL_Send_Parameter(vsl_device_handle handle,
                       uint16_t dsp_param_id,
  ...`

**Macros:**
- `VSL_VENDOR_ID` (line 22)
- `VSL_PRODUCT_ID` (line 23)
- `VSL_REPORT_ID` (line 24)
- `VSL_PACKET_SIZE` (line 25)
- `MIDI_IFACE` (line 26)
- `EP_MIDI_OUT` (line 28)

**Structs:**
- `vsl_device` (line 30)

#### `test_audiobox_vsl.c`
**Path:** `tests/test_audiobox_vsl.c`
**File Doc:** *SPDX-License-Identifier: GPL-2.0-or-later*

**Functions:**
- `test_supported_models_table_shape` (line 30) `static void test_supported_models_table_shape(void **state)`
- `test_model_pids_match_table` (line 45) `static void test_model_pids_match_table(void **state)`
- `test_lookup_returns_22_vsl` (line 54) `static void test_lookup_returns_22_vsl(void **state)`
- `test_lookup_returns_44_vsl` (line 64) `static void test_lookup_returns_44_vsl(void **state)`
- `test_lookup_returns_1818_vsl` (line 74) `static void test_lookup_returns_1818_vsl(void **state)`
- `test_lookup_returns_null_for_unknown_pid` (line 84) `static void test_lookup_returns_null_for_unknown_pid(void **state)`
- `test_lookup_handles_full_pid_range` (line 94) `static void test_lookup_handles_full_pid_range(void **state)`
- `test_table_pids_are_unique` (line 114) `static void test_table_pids_are_unique(void **state)`
- `test_table_product_names_non_empty` (line 125) `static void test_table_product_names_non_empty(void **state)`
- `main` (line 135) `int main(void)`

#### `test_vsl_dsp_logic.c`
**Path:** `tests/test_vsl_dsp_logic.c`
**File Doc:** *include <stdarg.h> include <stddef.h> include <setjmp.h> include <cmocka.h> include <math.h> include <float.h> include "vsl_dsp_logic.h"*

**Functions:**
- `test_VSL_Encode_Gain` (line 8) `static void test_VSL_Encode_Gain(void **state)` - *include <stdarg.h> include <stddef.h> include <setjmp.h> include <cmocka.h> include <math.h> include <float.h> include "vsl_dsp_logic.h"*
- `test_VSL_Map_Frequency` (line 35) `static void test_VSL_Map_Frequency(void **state)`
- `test_VSL_Decode_Frequency` (line 67) `static void test_VSL_Decode_Frequency(void **state)`
- `test_VSL_Final_Encode_To_Int` (line 99) `static void test_VSL_Final_Encode_To_Int(void **state)`
- `main` (line 127) `int main(void)`

### H (6 files)

#### `audiobox_vsl.h`
**Path:** `audiobox_vsl.h`
**File Doc:** *SPDX-License-Identifier: GPL-2.0-or-later*

**Imported by:** `audiobox_vsl.c`, `mixer_quirks.c`, `test_audiobox_vsl.c`

**Functions:**
- `audiobox_lookup_model` (line 95) `static inline const audiobox_model_info_t *
audiobox_lookup_model(uint16_t pid)` - *@brief Look up the model info entry for a given USB product ID.  @param pid 16-bit product ID reported by the USB device. @return Pointer to a cons...*

**Macros:**
- `AUDIOBOX_VSL_H` (line 21)
- `AUDIOBOX_VENDOR_ID` (line 32)

**Structs:**
- `usb_mixer_interface` (line 113)

#### `vsl_config.h`
**Path:** `legacy/vsl_config.h`
**File Doc:** *vsl_config.h (VERSION CORREGIDA)  ifndef VSL_CONFIG_H define VSL_CONFIG_H  include <stdint.h>  ====================================================...*

**Macros:**
- `VSL_CONFIG_H` (line 4)
- `VSL_VENDOR_ID` (line 11)
- `VSL_PRODUCT_ID` (line 12)
- `VSL_REPORT_ID` (line 13)
- `VSL_SCALE_FACTOR` (line 20)
- `VSL_MAX_ENCODED_INT` (line 23)
- `VSL_PACKET_SIZE` (line 24)
- `VSL_PAYLOAD_SIZE` (line 26)

#### `vsl_dsp_logic.h`
**Path:** `legacy/vsl_dsp_logic.h`
**File Doc:** *ifndef VSL_DSP_LOGIC_H define VSL_DSP_LOGIC_H  include <stdint.h> include <math.h> include <float.h> // Para fmaxf, fminf  Constante para la conver...*

**Macros:**
- `VSL_DSP_LOGIC_H` (line 2)
- `VSL_INV_LN2` (line 10)

#### `vsl_dsp_transport.h`
**Path:** `legacy/vsl_dsp_transport.h`
**File Doc:** *vsl_dsp_transport.h (CORREGIDO)  ifndef VSL_DSP_TRANSPORT_H define VSL_DSP_TRANSPORT_H  include <stdint.h> include <stddef.h> include <hidapi/hidap...*

**Macros:**
- `VSL_DSP_TRANSPORT_H` (line 4)

#### `vsl_dsp_logic.h`
**Path:** `src/vsl_dsp_logic.h`
**File Doc:** *ifndef VSL_DSP_LOGIC_H define VSL_DSP_LOGIC_H  include <stdint.h> include <math.h> include <float.h> // Para fmaxf, fminf  Constante para la conver...*

**Macros:**
- `VSL_DSP_LOGIC_H` (line 2)
- `VSL_INV_LN2` (line 10)

#### `vsl_dsp_transport.h`
**Path:** `src/vsl_dsp_transport.h`
**File Doc:** *ifndef VSL_DSP_TRANSPORT_H define VSL_DSP_TRANSPORT_H  include <stdint.h> include "vsl_dsp_logic.h"  ifdef __cplusplus*

**Macros:**
- `VSL_DSP_TRANSPORT_H` (line 2)

### PY (7 files)

#### `app.py`
**Path:** `legacy/app.py`
**File Doc:** *_*_ coding: utf8 _*_*

*No symbols extracted*

#### `vsl_config.py`
**Path:** `legacy/vsl_config.py`

**Classes:**
- `VSLParameter` (line 40) `class VSLParameter(NamedTuple)` - *Estructura que replica exactamente VSL_Parameter del código C.
Todos los campos están confirmados del desensamblado.*

**Methods:**
- `validate_configuration` (line 92) `def validate_configuration()` - *Valida que todos los valores críticos estén configurados.

Returns:
    (is_valid, error_message)*
- `print_configuration_status` (line 116) `def print_configuration_status()` - *Imprime el estado de la configuración con formato.*

#### `vsl_core.py`
**Path:** `legacy/vsl_core.py`

**Functions:**
- `vsl_encode_gain` (line 16) `def vsl_encode_gain(linear_value, param)` - *Traducción de FUN_00132c90 (VSL_Encode_Gain en C).

Convierte un valor lineal (0.0 - 1.0) a la escala exponencial del DSP.

Fórmula:
    encoded = coeff_offset_A + coeff_C1 * exp(norm_factor * log_factor)

Args:
    linear_value: Valor lineal de entrada (0.0 a 1.0)
    param: Estructura de parámetros con coeficientes
    
Returns:
    Valor codificado en float (rango: ~-10.0 a ~1000.0)
    
Raises:
    ValueError: Si param es inválido*
- `vsl_map_frequency` (line 58) `def vsl_map_frequency(linear_position, param)` - *Traducción de FUN_00132d00 (VSL_Map_Frequency en C).

Convierte una posición lineal (0.0 - 1.0) a frecuencia logarítmica (Hz).

Args:
    linear_position: Posición lineal (0.0 a 1.0)
    param: Estructura de parámetros con rangos de frecuencia
    
Returns:
    Frecuencia en Hz (ej: 20.0 a 20000.0)
    
Raises:
    ValueError: Si las frecuencias son inválidas*
- `vsl_final_encode_to_int` (line 94) `def vsl_final_encode_to_int(encoded_float, param)` - *Traducción de VSL_Final_Encode_To_Int en C.

Convierte el valor codificado float a entero de 16-bit para el DSP.

Args:
    encoded_float: Valor float codificado (ej: -10.0 a 1000.0)
    param: Estructura de parámetros con max_encoded_int
    
Returns:
    Valor entero (0 a 65535)*
- `vsl_decode_frequency` (line 127) `def vsl_decode_frequency(freq_hz_value, param)` - *Traducción de FUN_00132da8 (VSL_Decode_Frequency en C).

Convierte una frecuencia real (Hz) a su posición lineal (0.0 - 1.0).

Args:
    freq_hz_value: Frecuencia en Hz
    param: Estructura de parámetros con rangos
    
Returns:
    Posición lineal (0.0 a 1.0)
    
Raises:
    ValueError: Si las frecuencias son inválidas*
- `validate_parameter` (line 170) `def validate_parameter(param)` - *Valida la integridad de un VSLParameter.

Returns:
    (is_valid, error_message)*

#### `vsl_hid_io.py`
**Path:** `legacy/vsl_hid_io.py`

**Classes:**
- `VSLDevice` (line 31) `class VSLDevice` - *Gestor de dispositivo VSL-DSP con patrón Singleton.
Maneja la conexión HID y envío de paquetes.*

**Methods:**
- `enumerate_vsl_devices` (line 149) `def enumerate_vsl_devices()` - *Enumera todos los dispositivos HID conectados.
Útil para descubrir VID/PID del hardware.*
- `__new__` (line 39) `def __new__(cls)`
- `__init__` (line 45) `def __init__(self)`
- `open` (line 59) `def open(self)` - *Abre la conexión con el dispositivo VSL.

Returns:
    True si la conexión fue exitosa, False en caso contrario*
- `close` (line 90) `def close(self)` - *Cierra la conexión con el dispositivo.*
- `send_packet` (line 101) `def send_packet(self, packet)` - *Envía un paquete VSL al dispositivo.

Args:
    packet: VSLPacket a enviar
    
Returns:
    True si el envío fue exitoso*
- `__enter__` (line 139) `def __enter__(self)` - *Context manager entry.*
- `__exit__` (line 144) `def __exit__(self, exc_type, exc_val, exc_tb)` - *Context manager exit.*

#### `vsl_poc_main.py`
**Path:** `legacy/vsl_poc_main.py`

**Functions:**
- `test_gain_encoding` (line 43) `def test_gain_encoding()` - *Test de codificación de ganancia con tabla de validación.*
- `test_frequency_mapping` (line 72) `def test_frequency_mapping()` - *Test de mapeo logarítmico de frecuencias.*
- `test_packet_construction` (line 92) `def test_packet_construction()` - *Test de construcción de paquetes HID.*
- `test_edge_cases` (line 150) `def test_edge_cases()` - *Test de casos extremos y validación de errores.*
- `run_full_workflow` (line 197) `def run_full_workflow()` - *Simula el flujo completo: Usuario → Encoding → Paquete.*
- `print_summary` (line 229) `def print_summary()` - *Imprime resumen del estado del proyecto.*
- `main` (line 266) `def main()` - *Función principal de la PoC.*

#### `vsl_protocol_analyzer.py`
**Path:** `legacy/vsl_protocol_analyzer.py`
**File Doc:** *PASO 1: (Fuera de este entorno) Capturar tráfico USB con Wireshark/usbmon Guardar como: audiobox_full_sweep.pcap  PASO 2: Ejecutar el analizador py...*

**Classes:**
- `VSLParameter` (line 28) `class VSLParameter` - *Parámetros DSP descifrados con coeficientes y rangos.*

**Methods:**
- `reverse_map_gain` (line 67) `def reverse_map_gain(encoded_value, param)` - *Simula VSL_Decode_Gain. Convierte un entero a un valor de usuario (dB).

Fórmula inversa confirmada: 
user_value = (log2(encoded_float * range_span) / log_factor) + min_db

Usaremos la simplificación de mapeo lineal para la PoC, ya que el valor 
confirmado (40793) implica que no es un simple mapeo lineal 
(40793 / 65535 = 0.6225). La fórmula real de decodificación logarítmica
es más compleja. Para la PoC, aplicamos la inversa de la fórmula 
logarítmica simplificada que nos dio los resultados válidos:*
- `reverse_map_frequency` (line 95) `def reverse_map_frequency(encoded_value, param)` - *Simula VSL_Decode_Frequency. Convierte un entero a frecuencia (Hz).

Fórmula inversa: exp2f(log2_min + pos * (log2_max - log2_min))*
- `get_decoded_value` (line 115) `def get_decoded_value(encoded_value, param_id)` - *Dirige la decodificación al motor DSP correcto.*
- `decode_vsl_packet` (line 140) `def decode_vsl_packet(data)` - *Decodifica el payload de 64 bytes. (Regla #3: Seguridad)*
- `analyze_pcap` (line 173) `def analyze_pcap(pcap_file)` - *Carga un archivo PCAP y filtra los paquetes USB VSL.*
- `__init__` (line 30) `def __init__(self, dsp_id, name, type_unit, min_map, max_map, coeff_A, coeff_C1, log_factor)`

#### `vsl_transport.py`
**Path:** `legacy/vsl_transport.py`

**Classes:**
- `VSLPacket` (line 15) `class VSLPacket` - *Representa un paquete HID VSL-DSP de 64 bytes.
Implementa construcción y validación con seguridad de tipos.*

**Methods:**
- `build_packet_safe` (line 141) `def build_packet_safe(param, encoded_value)` - *Construye un paquete con manejo de errores.

Args:
    param: Parámetro DSP
    encoded_value: Valor codificado (0-65535)
    
Returns:
    VSLPacket o None si hay error*
- `__init__` (line 21) `def __init__(self, param_id, encoded_value, report_id)` - *Construye un paquete VSL-DSP.

Args:
    param_id: ID del parámetro DSP (16-bit, ej: 0x1A01)
    encoded_value: Valor codificado (16-bit, 0-65535)
    report_id: Report ID HID (8-bit, None usa configuración global)
    
Raises:
    ValueError: Si los valores están fuera de rango
    RuntimeError: Si VSL_REPORT_ID no está configurado y report_id es None*
- `_build_buffer` (line 58) `def _build_buffer(self)` - *Construye el buffer de 64 bytes según el protocolo VSL-DSP.

Estructura (Little-Endian):
  [0]    : Report ID
  [1-2]  : Parameter ID (LSB, MSB)
  [3-4]  : Encoded Value (LSB, MSB)
  [5-63] : Padding (0x00)

Returns:
    bytearray de 64 bytes*
- `buffer` (line 89) `def buffer(self)` - *Retorna el buffer como bytes inmutables.*
- `hex_dump` (line 93) `def hex_dump(self, num_bytes)` - *Genera un hex dump del paquete para debugging.

Args:
    num_bytes: Número de bytes a mostrar (default: 8)
    
Returns:
    String con formato hexadecimal*
- `validate` (line 106) `def validate(self)` - *Valida la integridad del paquete.

Returns:
    (is_valid, message)*
- `__repr__` (line 133) `def __repr__(self)`

### SH (3 files)

#### `install.sh`
**Path:** `install.sh`
**File Doc:** *SPDX-License-Identifier: GPL-2.0-or-later Thin wrapper that installs the build-time dependencies for the audiobox_vsl kernel module. All real build...*

*No symbols extracted*

#### `build-dkms.sh`
**Path:** `legacy/build-dkms.sh`
**File Doc:** *AudioBox 22 VSL Enhanced Driver - Installation Script Copyright (c) 2025 grisuno (LazyOwn Project) License: GPL-2.0-or-later  This script installs ...*

**Functions:**
- `print_header` (line 40)
- `print_success` (line 48)
- `print_error` (line 52)
- `print_warning` (line 56)
- `print_info` (line 60)
- `check_root` (line 64)
- `check_dependencies` (line 72)
- `detect_audiobox` (line 101)
- `create_source_structure` (line 123)
- `copy_source_files` (line 138)
- `create_dkms_conf` (line 174)
- `create_makefile` (line 193)
- `verify_mixer_quirks` (line 252)
- `build_with_dkms` (line 295)
- `install_module` (line 309)
- `reload_module` (line 323)
- `verify_installation` (line 344)
- `show_usage_info` (line 394)
- `main` (line 452)

#### `test.sh`
**Path:** `legacy/test.sh`
**File Doc:** *==================================================================== VSL-DSP: Captura COMPLETA de tráfico USB del AudioBox ========================...*

*No symbols extracted*
