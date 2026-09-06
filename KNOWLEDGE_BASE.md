# Polyglot Codebase Knowledge Graph

> Generated offline by **readmenator**. Supports C, C++, Python, Go, Rust, JS/TS, Java, C#, Shell, PHP, Dart, GDScript, Nim, ASM, Ruby, Swift, Kotlin, Scala, Lua, Elixir.
> No LLMs. No tokens. Pure static analysis. See more [here](https://github.com/grisuno/ReadMenator)

**Total Files Parsed:** 49 | **Total Symbols Extracted:** 563 | **Total Imports:** 221
 | **Resolved Imports:** 11

<!-- ranking_model: v1.0 | weights: {ppr:0.45,auth:0.2,test:0.15,doc:0.1,fresh:0.1} | alpha:0.85 | commit:4c8e0d2 | date:2026-07-18 -->


## Table of Contents

1. [Statistics Dashboard](#statistics-dashboard)
2. [Architectural Layers](#architectural-layers)
3. [Ranked Context](#ranked-context)
4. [God Nodes](#god-nodes)
5. [Community Analysis](#community-analysis)
6. [Suggested Questions](#suggested-questions)
7. [Taint Propagation Map](#taint-propagation-map)
8. [Hotspot Analysis](#hotspot-analysis)
9. [Change Impact Analysis](#change-impact-analysis)
10. [Suggested Linting Rules](#suggested-linting-rules)
11. [Query Recipes](#query-recipes)
12. [Structural Knowledge Map](#structural-knowledge-map)
13. [UML Class Diagram](#uml-class-diagram)
14. [Code Property Graph](#code-property-graph)
15. [Architecture Reference](#architecture-reference)
    - [C (24 files)](#c-24-files)
    - [H (15 files)](#h-15-files)
    - [PY (7 files)](#py-7-files)
    - [SH (3 files)](#sh-3-files)

---

## Statistics Dashboard

| Metric | Value |
|--------|-------|
| Total Files | 49 |
| Total Symbols | 563 |
| Total Imports | 221 |
| Call Edges | 250 |
| Inheritance Edges | 1 |
| Languages | 4 |
| Avg Symbols/File | 11.5 |
| Avg Imports/File | 4.5 |
| Resolved Imports | 11 |

### Top Files by Import Count (Fan-Out)

| File | Imports | Symbols | Language |
|------|---------|---------|----------|
| `mixer_quirks.c` | 25 | 306 | c |
| `vc_crypto.c` | 10 | 10 | c |
| `vc_rt_cli.c` | 10 | 9 | c |
| `test_vc_stream.c` | 10 | 13 | c |
| `vsl_hid_io.py` | 8 | 9 | py |
| `vsl_cli.c` | 8 | 9 | c |
| `vc_alsa.c` | 8 | 7 | c |
| `test_vc_fft.c` | 8 | 4 | c |
| `vsl_dsp_transport.c` | 7 | 5 | c |
| `test_vsl_dsp_logic.c` | 7 | 15 | c |

### Top Files by Imported-By Count (Fan-In)

| File | Imported By | Symbols | Language |
|------|-------------|---------|----------|
| `audiobox_vsl.h` | 3 | 4 | h |

---

## Architectural Layers

Auto-detected from path patterns, naming conventions, and imported frameworks.

| Layer | Files |
|-------|-------|
| utility | 31 |
| testing | 6 |
| infrastructure | 5 |
| business_logic | 4 |
| presentation | 2 |
| data_access | 1 |

### infrastructure

- `audiobox_vsl.c` (c, 5 symbols)
- `audiobox_vsl.h` (h, 4 symbols)
- `vsl_config.h` (h, 8 symbols)
- `vsl_config.py` (py, 3 symbols)
- `vsl_config.h` (h, 11 symbols)

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
- `vsl_cli.c` (c, 9 symbols)
- `vsl_dsp_transport.c` (c, 4 symbols)
- `vsl_dsp_transport.h` (h, 1 symbols)
- `vc_alsa.c` (c, 7 symbols)
- `vc_alsa.h` (h, 1 symbols)
- *... and 16 more*

### presentation

- `build-dkms.sh` (sh, 19 symbols)
- `mixer_quirks.c` (c, 306 symbols)

### testing

- `test.sh` (sh, 0 symbols)
- `test_connection.c` (c, 1 symbols)
- `test_audiobox_vsl.c` (c, 10 symbols)
- `test_vsl_dsp_logic.c` (c, 15 symbols)
- `test_vc_fft.c` (c, 4 symbols)
- `test_vc_stream.c` (c, 13 symbols)

### business_logic

- `vsl_dsp_logic.c` (c, 4 symbols)
- `vsl_dsp_logic.h` (h, 2 symbols)
- `vsl_dsp_logic.c` (c, 5 symbols)
- `vsl_dsp_logic.h` (h, 3 symbols)

### data_access

- `vc_rt_seed.c` (c, 1 symbols)

---

## Ranked Context

Files ranked by composite score for the current query context. The ranking combines Personalized PageRank (query relevance), global authority, test coverage, documentation coverage, and code freshness. Model: v1.0.

| Rank | File | Composite | PPR | Authority | Test | Doc |
|------|------|-----------|-----|-----------|------|-----|
| 1 | `vsl_config.py` | 0.2750 | 0.2692 | 0.2692 | 0.00 | 1.00 |
| 2 | `main.c` | 0.2000 | 0.0000 | 0.0000 | 0.00 | 2.00 |
| 3 | `test_connection.c` | 0.2000 | 0.0000 | 0.0000 | 0.00 | 2.00 |
| 4 | `vc_rt_seed.c` | 0.2000 | 0.0000 | 0.0000 | 0.00 | 2.00 |
| 5 | `audiobox_vsl.h` | 0.1961 | 0.2248 | 0.2248 | 0.00 | 0.50 |
| 6 | `vsl_core.py` | 0.1616 | 0.0947 | 0.0947 | 0.00 | 1.00 |
| 7 | `vsl_transport.py` | 0.1491 | 0.0947 | 0.0947 | 0.00 | 0.88 |
| 8 | `vsl_poc_main.py` | 0.1412 | 0.0633 | 0.0633 | 0.00 | 1.00 |
| 9 | `vsl_dsp_logic.c` | 0.1250 | 0.0000 | 0.0000 | 0.00 | 1.25 |
| 10 | `vsl_hid_io.py` | 0.1189 | 0.0633 | 0.0633 | 0.00 | 0.78 |

---

## God Nodes

Most architecturally central files ranked by combined import/export degree and symbol richness.

| File | Score | Connections | PageRank |
|------|-------|-------------|----------|
| `mixer_quirks.c` | 32.6 | | 0.0000 |
| `vsl_config.py` | 8.3 | | 0.2692 |
| `vsl_hid_io.py` | 6.9 | | 0.0633 |
| `vsl_transport.py` | 6.8 | | 0.0947 |
| `vsl_poc_main.py` | 6.7 | | 0.0633 |
| `vsl_core.py` | 6.5 | | 0.0947 |
| `audiobox_vsl.h` | 6.4 | | 0.2248 |
| `test_audiobox_vsl.c` | 3.0 | | 0.0000 |
| `audiobox_vsl.c` | 2.5 | | 0.0000 |
| `build-dkms.sh` | 1.9 | | 0.0000 |

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

## Taint Propagation Map

Taint analysis traces how dangerous imports propagate through the codebase via transitive dependencies. Source files import dangerous modules directly; sink files receive the danger indirectly.

**Taint Sources:** 1 | **Taint Sinks:** 1 | **Propagation Paths:** 1

- `mixer_quirks.c` imports `input` (0 hop to `mixer_quirks.c`) [medium]
  Path: mixer_quirks.c

---

## Hotspot Analysis

Files ranked by combined complexity (symbol count) and centrality (connection count). High-scoring files are architecturally critical and may need refactoring attention.

| File | Complexity | Centrality | Combined | Symbols | Connections |
|------|-----------|------------|----------|---------|-------------|
| `vsl_config.py` | 0.010 | 0.360 | 0.220 | 3 | 9 |
| `main.c` | 0.003 | 0.120 | 0.073 | 1 | 3 |
| `test_connection.c` | 0.003 | 0.120 | 0.073 | 1 | 3 |
| `vc_rt_seed.c` | 0.003 | 0.120 | 0.073 | 1 | 3 |
| `audiobox_vsl.h` | 0.013 | 0.240 | 0.149 | 4 | 6 |
| `vsl_core.py` | 0.016 | 0.320 | 0.199 | 5 | 8 |
| `vsl_transport.py` | 0.026 | 0.280 | 0.178 | 8 | 7 |
| `vsl_poc_main.py` | 0.023 | 0.360 | 0.225 | 7 | 9 |
| `vsl_dsp_logic.c` | 0.013 | 0.040 | 0.029 | 4 | 1 |
| `vsl_hid_io.py` | 0.029 | 0.480 | 0.300 | 9 | 12 |
| `mixer_quirks.c` | 1.000 | 1.000 | 1.000 | 306 | 25 |
| `test_vc_stream.c` | 0.043 | 0.400 | 0.257 | 13 | 10 |
| `vc_crypto.c` | 0.033 | 0.400 | 0.253 | 10 | 10 |
| `vc_rt_cli.c` | 0.029 | 0.400 | 0.252 | 9 | 10 |
| `vsl_cli.c` | 0.029 | 0.320 | 0.204 | 9 | 8 |

---

## Change Impact Analysis

Files sorted by how many other files would be affected if they changed. High-impact files should be changed with caution.

| File | Direct Dependents | Transitive Dependents | Total Impact |
|------|------------------|----------------------|--------------|
| `vsl_config.py` | 4 | 0 | 4 |
| `vsl_core.py` | 2 | 0 | 2 |
| `vsl_transport.py` | 2 | 0 | 2 |
| `audiobox_vsl.c` | 0 | 0 | 0 |
| `audiobox_vsl.h` | 0 | 0 | 0 |
| `install.sh` | 0 | 0 | 0 |
| `app.py` | 0 | 0 | 0 |
| `build-dkms.sh` | 0 | 0 | 0 |
| `main.c` | 0 | 0 | 0 |
| `mixer_quirks.c` | 0 | 0 | 0 |
| `test.sh` | 0 | 0 | 0 |
| `test_connection.c` | 0 | 0 | 0 |
| `vsl_config.h` | 0 | 0 | 0 |
| `vsl_dsp_logic.c` | 0 | 0 | 0 |
| `vsl_dsp_logic.h` | 0 | 0 | 0 |

---

## Suggested Linting Rules

Automatically suggested linting and security rules based on patterns detected in the codebase. These can be exported as Semgrep rules using the `--export-rules` flag.

| Rule ID | Severity | Description | Language | Matches |
|---------|----------|-------------|----------|---------|
| `RM001` | info | Large number of functions in c: 300 total | c | 300 |
| `RM002` | info | Large number of functions in h: 3 total | h | 3 |
| `RM003` | info | Large number of functions in sh: 19 total | sh | 19 |
| `RM004` | info | Large number of functions in py: 35 total | py | 35 |
| `RM005` | info | Print statement found (consider logging instead) | python | 186 |

---

## Query Recipes

Example queries you can run against this knowledge base using the ranking engine:

```
# Find files most relevant to a concept
readmenator query "Where is the import resolver implemented?"

# Rank files by relevance to a topic
readmenator query "How does documentation generation work?"

# Explain why a file ranks highly
readmenator query "explain readmenator/_documentation.py"

# Trace dependency paths with ranked context
readmenator query "path from CLI to exporter"
```

The ranking model uses the following signals:

- **Personalized PageRank** (45% weight): query-specific relevance via seed propagation
- **Global Authority** (20% weight): structural importance via standard PageRank
- **Test Coverage** (15% weight): fraction of symbols referenced in test files
- **Doc Coverage** (10% weight): presence of docstrings and file-level docs
- **Freshness** (10% weight): recent modification activity

Results include score decomposition and justification paths for each ranked item.

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
    voicecloak_tests_test_vc_stream_c["test_vc_stream.c (c)"]
    class voicecloak_tests_test_vc_stream_c mod;
    voicecloak_src_vc_crypto_c["vc_crypto.c (c)"]
    class voicecloak_src_vc_crypto_c mod;
    voicecloak_src_vc_rt_cli_c["vc_rt_cli.c (c)"]
    class voicecloak_src_vc_rt_cli_c mod;
    legacy_vsl_poc_main_py["vsl_poc_main.py (py)"]
    class legacy_vsl_poc_main_py mod;
    src_vsl_cli_c["vsl_cli.c (c)"]
    class src_vsl_cli_c mod;
    voicecloak_src_vc_alsa_c["vc_alsa.c (c)"]
    class voicecloak_src_vc_alsa_c mod;
    voicecloak_tests_test_vc_fft_c["test_vc_fft.c (c)"]
    class voicecloak_tests_test_vc_fft_c mod;
    tests_test_vsl_dsp_logic_c["test_vsl_dsp_logic.c (c)"]
    class tests_test_vsl_dsp_logic_c mod;
    voicecloak_src_vc_dsp_c["vc_dsp.c (c)"]
    class voicecloak_src_vc_dsp_c mod;
    legacy_vsl_dsp_transport_c["vsl_dsp_transport.c (c)"]
    class legacy_vsl_dsp_transport_c mod;
    voicecloak_src_vc_cli_c["vc_cli.c (c)"]
    class voicecloak_src_vc_cli_c mod;
    tests_test_audiobox_vsl_c["test_audiobox_vsl.c (c)"]
    class tests_test_audiobox_vsl_c mod;
    voicecloak_src_vc_wav_c["vc_wav.c (c)"]
    class voicecloak_src_vc_wav_c mod;
    legacy_vsl_core_py["vsl_core.py (py)"]
    class legacy_vsl_core_py mod;
    legacy_vsl_transport_py["vsl_transport.py (py)"]
    class legacy_vsl_transport_py mod;
    voicecloak_src_vc_stft_c["vc_stft.c (c)"]
    class voicecloak_src_vc_stft_c mod;
    voicecloak_src_vc_stream_c["vc_stream.c (c)"]
    class voicecloak_src_vc_stream_c mod;
    legacy_vsl_protocol_analyzer_py["vsl_protocol_analyzer.py (py)"]
    class legacy_vsl_protocol_analyzer_py mod;
    src_vsl_dsp_transport_c["vsl_dsp_transport.c (c)"]
    class src_vsl_dsp_transport_c mod;
    voicecloak_src_vc_rt_c["vc_rt.c (c)"]
    class voicecloak_src_vc_rt_c mod;
    audiobox_vsl_c["audiobox_vsl.c (c)"]
    class audiobox_vsl_c mod;
    voicecloak_src_vc_fft_c["vc_fft.c (c)"]
    class voicecloak_src_vc_fft_c mod;
    legacy_vsl_dsp_transport_h["vsl_dsp_transport.h (h)"]
    class legacy_vsl_dsp_transport_h mod;
    voicecloak_src_vc_alsa_h["vc_alsa.h (h)"]
    class voicecloak_src_vc_alsa_h mod;
    audiobox_vsl_h["audiobox_vsl.h (h)"]
    class audiobox_vsl_h mod;
    src_vsl_dsp_logic_h["vsl_dsp_logic.h (h)"]
    class src_vsl_dsp_logic_h mod;
    legacy_vsl_dsp_logic_h["vsl_dsp_logic.h (h)"]
    class legacy_vsl_dsp_logic_h mod;
    legacy_main_c["main.c (c)"]
    class legacy_main_c mod;
    legacy_test_connection_c["test_connection.c (c)"]
    class legacy_test_connection_c mod;
    src_vsl_dsp_transport_h["vsl_dsp_transport.h (h)"]
    class src_vsl_dsp_transport_h mod;
    voicecloak_src_vc_rt_seed_c["vc_rt_seed.c (c)"]
    class voicecloak_src_vc_rt_seed_c mod;
    src_vsl_config_h["vsl_config.h (h)"]
    class src_vsl_config_h mod;
    voicecloak_src_vc_crypto_h["vc_crypto.h (h)"]
    class voicecloak_src_vc_crypto_h mod;
    legacy_vsl_config_py["vsl_config.py (py)"]
    class legacy_vsl_config_py mod;
    voicecloak_src_vc_dsp_h["vc_dsp.h (h)"]
    class voicecloak_src_vc_dsp_h mod;
    voicecloak_src_vc_rt_h["vc_rt.h (h)"]
    class voicecloak_src_vc_rt_h mod;
    voicecloak_src_vc_stft_h["vc_stft.h (h)"]
    class voicecloak_src_vc_stft_h mod;
    voicecloak_src_vc_stream_h["vc_stream.h (h)"]
    class voicecloak_src_vc_stream_h mod;
    voicecloak_src_vc_wav_h["vc_wav.h (h)"]
    class voicecloak_src_vc_wav_h mod;
    legacy_vsl_config_h["vsl_config.h (h)"]
    class legacy_vsl_config_h mod;
    src_vsl_dsp_logic_c["vsl_dsp_logic.c (c)"]
    class src_vsl_dsp_logic_c mod;
    legacy_vsl_dsp_logic_c["vsl_dsp_logic.c (c)"]
    class legacy_vsl_dsp_logic_c mod;
    voicecloak_src_vc_fft_h["vc_fft.h (h)"]
    class voicecloak_src_vc_fft_h mod;
    legacy_build_dkms_sh["build-dkms.sh (sh)"]
    class legacy_build_dkms_sh mod;
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
    src_vsl_cli_c -.->|imports| ext_vsl_config_h
    src_vsl_config_h -.->|imports| ext_stdint_h
    src_vsl_config_h -.->|imports| ext_stddef_h
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
    src_vsl_dsp_transport_h -.->|imports| ext_vsl_config_h
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
    ext_vc_alsa_h["vc_alsa.h"]
    class ext_vc_alsa_h ext;
    voicecloak_src_vc_alsa_c -.->|imports| ext_vc_alsa_h
    ext_vc_stream_h["vc_stream.h"]
    class ext_vc_stream_h ext;
    voicecloak_src_vc_alsa_c -.->|imports| ext_vc_stream_h
    ext_alloca_h["alloca.h"]
    class ext_alloca_h ext;
    voicecloak_src_vc_alsa_c -.->|imports| ext_alloca_h
    ext_alsa_asoundlib_h["asoundlib.h"]
    class ext_alsa_asoundlib_h ext;
    voicecloak_src_vc_alsa_c -.->|imports| ext_alsa_asoundlib_h
    voicecloak_src_vc_alsa_c -.->|imports| ext_stdio_h
    voicecloak_src_vc_alsa_c -.->|imports| ext_stdlib_h
    voicecloak_src_vc_alsa_c -.->|imports| ext_string_h
    voicecloak_src_vc_alsa_c -.->|imports| ext_math_h
    voicecloak_src_vc_alsa_h -.->|imports| ext_stddef_h
    voicecloak_src_vc_alsa_h -.->|imports| ext_stdint_h
    ext_signal_h["signal.h"]
    class ext_signal_h ext;
    voicecloak_src_vc_alsa_h -.->|imports| ext_signal_h
    voicecloak_src_vc_alsa_h -.->|imports| ext_vc_stream_h
    ext_vc_wav_h["vc_wav.h"]
    class ext_vc_wav_h ext;
    voicecloak_src_vc_cli_c -.->|imports| ext_vc_wav_h
    ext_vc_dsp_h["vc_dsp.h"]
    class ext_vc_dsp_h ext;
    voicecloak_src_vc_cli_c -.->|imports| ext_vc_dsp_h
    ext_vc_crypto_h["vc_crypto.h"]
    class ext_vc_crypto_h ext;
    voicecloak_src_vc_cli_c -.->|imports| ext_vc_crypto_h
    voicecloak_src_vc_cli_c -.->|imports| ext_stdio_h
    voicecloak_src_vc_cli_c -.->|imports| ext_stdlib_h
    voicecloak_src_vc_cli_c -.->|imports| ext_string_h
    ext_time_h["time.h"]
    class ext_time_h ext;
    voicecloak_src_vc_cli_c -.->|imports| ext_time_h
    voicecloak_src_vc_crypto_c -.->|imports| ext_vc_crypto_h
    voicecloak_src_vc_crypto_c -.->|imports| ext_stdio_h
    voicecloak_src_vc_crypto_c -.->|imports| ext_stdlib_h
    voicecloak_src_vc_crypto_c -.->|imports| ext_string_h
    ext_openssl_evp_h["evp.h"]
    class ext_openssl_evp_h ext;
    voicecloak_src_vc_crypto_c -.->|imports| ext_openssl_evp_h
    ext_openssl_pem_h["pem.h"]
    class ext_openssl_pem_h ext;
    voicecloak_src_vc_crypto_c -.->|imports| ext_openssl_pem_h
    ext_openssl_rsa_h["rsa.h"]
    class ext_openssl_rsa_h ext;
    voicecloak_src_vc_crypto_c -.->|imports| ext_openssl_rsa_h
    ext_openssl_rand_h["rand.h"]
    class ext_openssl_rand_h ext;
    voicecloak_src_vc_crypto_c -.->|imports| ext_openssl_rand_h
    ext_openssl_err_h["err.h"]
    class ext_openssl_err_h ext;
    voicecloak_src_vc_crypto_c -.->|imports| ext_openssl_err_h
    ext_openssl_hmac_h["hmac.h"]
    class ext_openssl_hmac_h ext;
    voicecloak_src_vc_crypto_c -.->|imports| ext_openssl_hmac_h
    voicecloak_src_vc_crypto_h -.->|imports| ext_stddef_h
    voicecloak_src_vc_crypto_h -.->|imports| ext_stdint_h
    voicecloak_src_vc_dsp_c -.->|imports| ext_vc_dsp_h
    ext_vc_stft_h["vc_stft.h"]
    class ext_vc_stft_h ext;
    voicecloak_src_vc_dsp_c -.->|imports| ext_vc_stft_h
    voicecloak_src_vc_dsp_c -.->|imports| ext_vc_crypto_h
    voicecloak_src_vc_dsp_c -.->|imports| ext_stdlib_h
    voicecloak_src_vc_dsp_c -.->|imports| ext_string_h
    voicecloak_src_vc_dsp_c -.->|imports| ext_math_h
    voicecloak_src_vc_dsp_c -.->|imports| ext_float_h
    voicecloak_src_vc_dsp_h -.->|imports| ext_stddef_h
    voicecloak_src_vc_dsp_h -.->|imports| ext_stdint_h
    ext_vc_fft_h["vc_fft.h"]
    class ext_vc_fft_h ext;
    voicecloak_src_vc_fft_c -.->|imports| ext_vc_fft_h
    voicecloak_src_vc_fft_c -.->|imports| ext_math_h
    voicecloak_src_vc_fft_c -.->|imports| ext_string_h
    voicecloak_src_vc_fft_c -.->|imports| ext_stdlib_h
    voicecloak_src_vc_fft_h -.->|imports| ext_stddef_h
    ext_vc_rt_h["vc_rt.h"]
    class ext_vc_rt_h ext;
    voicecloak_src_vc_rt_c -.->|imports| ext_vc_rt_h
    voicecloak_src_vc_rt_c -.->|imports| ext_stdlib_h
    voicecloak_src_vc_rt_c -.->|imports| ext_string_h
    voicecloak_src_vc_rt_c -.->|imports| ext_math_h
    voicecloak_src_vc_rt_h -.->|imports| ext_stddef_h
    voicecloak_src_vc_rt_h -.->|imports| ext_stdint_h
    voicecloak_src_vc_rt_cli_c -.->|imports| ext_vc_alsa_h
    voicecloak_src_vc_rt_cli_c -.->|imports| ext_vc_stream_h
    voicecloak_src_vc_rt_cli_c -.->|imports| ext_vc_rt_h
    voicecloak_src_vc_rt_cli_c -.->|imports| ext_vc_fft_h
    voicecloak_src_vc_rt_cli_c -.->|imports| ext_vc_crypto_h
    voicecloak_src_vc_rt_cli_c -.->|imports| ext_stdio_h
    voicecloak_src_vc_rt_cli_c -.->|imports| ext_stdlib_h
    voicecloak_src_vc_rt_cli_c -.->|imports| ext_string_h
    voicecloak_src_vc_rt_cli_c -.->|imports| ext_signal_h
    voicecloak_src_vc_rt_cli_c -.->|imports| ext_math_h
    voicecloak_src_vc_rt_seed_c -.->|imports| ext_vc_rt_h
    voicecloak_src_vc_rt_seed_c -.->|imports| ext_vc_crypto_h
    voicecloak_src_vc_rt_seed_c -.->|imports| ext_math_h
    voicecloak_src_vc_stft_c -.->|imports| ext_vc_stft_h
    voicecloak_src_vc_stft_c -.->|imports| ext_vc_fft_h
    voicecloak_src_vc_stft_c -.->|imports| ext_stdlib_h
    voicecloak_src_vc_stft_c -.->|imports| ext_string_h
    voicecloak_src_vc_stft_c -.->|imports| ext_math_h
    voicecloak_src_vc_stft_h -.->|imports| ext_stddef_h
    voicecloak_src_vc_stft_h -.->|imports| ext_stdint_h
    voicecloak_src_vc_stream_c -.->|imports| ext_vc_stream_h
    voicecloak_src_vc_stream_c -.->|imports| ext_vc_fft_h
    voicecloak_src_vc_stream_c -.->|imports| ext_stdlib_h
    voicecloak_src_vc_stream_c -.->|imports| ext_string_h
    voicecloak_src_vc_stream_c -.->|imports| ext_math_h
    voicecloak_src_vc_stream_h -.->|imports| ext_stddef_h
    voicecloak_src_vc_stream_h -.->|imports| ext_stdint_h
    voicecloak_src_vc_wav_c -.->|imports| ext_vc_wav_h
    voicecloak_src_vc_wav_c -.->|imports| ext_stdio_h
    voicecloak_src_vc_wav_c -.->|imports| ext_stdlib_h
    voicecloak_src_vc_wav_c -.->|imports| ext_string_h
    voicecloak_src_vc_wav_c -.->|imports| ext_math_h
    voicecloak_src_vc_wav_c -.->|imports| ext_stdint_h
    voicecloak_src_vc_wav_h -.->|imports| ext_stddef_h
    voicecloak_src_vc_wav_h -.->|imports| ext_stdint_h
    voicecloak_tests_test_vc_fft_c -.->|imports| ext_stdarg_h
    voicecloak_tests_test_vc_fft_c -.->|imports| ext_stddef_h
    voicecloak_tests_test_vc_fft_c -.->|imports| ext_setjmp_h
    voicecloak_tests_test_vc_fft_c -.->|imports| ext_cmocka_h
    voicecloak_tests_test_vc_fft_c -.->|imports| ext_stdlib_h
    voicecloak_tests_test_vc_fft_c -.->|imports| ext_math_h
    voicecloak_tests_test_vc_fft_c -.->|imports| ext_string_h
    voicecloak_tests_test_vc_fft_c -.->|imports| ext_vc_fft_h
    voicecloak_tests_test_vc_stream_c -.->|imports| ext_stdarg_h
    voicecloak_tests_test_vc_stream_c -.->|imports| ext_stddef_h
    voicecloak_tests_test_vc_stream_c -.->|imports| ext_setjmp_h
    voicecloak_tests_test_vc_stream_c -.->|imports| ext_cmocka_h
    voicecloak_tests_test_vc_stream_c -.->|imports| ext_vc_stream_h
    voicecloak_tests_test_vc_stream_c -.->|imports| ext_vc_rt_h
    voicecloak_tests_test_vc_stream_c -.->|imports| ext_vc_fft_h
    voicecloak_tests_test_vc_stream_c -.->|imports| ext_stdlib_h
    voicecloak_tests_test_vc_stream_c -.->|imports| ext_string_h
    voicecloak_tests_test_vc_stream_c -.->|imports| ext_math_h
```

---

## UML Class Diagram

Auto-generated Mermaid class diagram from parsed class-level symbols. Shows classes, structs, interfaces, traits, and their methods with inheritance and dependency relationships.

```mermaid
classDiagram
  class audiobox_vsl_h_usb_mixer_interface {
    <<struct>>
    +audiobox_lookup_model(uint16_t pid)
  }
  class mixer_quirks_c_std_mono_table {
    <<struct>>
    +snd_create_std_mono_ctl_offset(struct usb_mixer_interface *mixer,
					  unsigned int ...
    +snd_create_std_mono_ctl(struct usb_mixer_interface *mixer,
				   unsigned int unitid,...
    +snd_create_std_mono_table(struct usb_mixer_interface *mixer,
				     const struct std...
    +add_single_ctl_with_resume(struct usb_mixer_interface *mixer,
				      int id,
				  ...
    +snd_usb_soundblaster_remote_complete(struct urb *urb)
    +snd_usb_sbrc_hwdep_read(struct snd_hwdep *hw, char __user *buf,
				    long count, l...
    +snd_usb_sbrc_hwdep_poll(struct snd_hwdep *hw, struct file *file,
					poll_table ...
    +snd_usb_soundblaster_remote_init(struct usb_mixer_interface *mixer)
    +snd_audigy2nx_led_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
    +snd_audigy2nx_led_update(struct usb_mixer_interface *mixer,
				    int value, int index)
  }
  class mixer_quirks_c_rc_config {
    <<struct>>
    +snd_create_std_mono_ctl_offset(struct usb_mixer_interface *mixer,
					  unsigned int ...
    +snd_create_std_mono_ctl(struct usb_mixer_interface *mixer,
				   unsigned int unitid,...
    +snd_create_std_mono_table(struct usb_mixer_interface *mixer,
				     const struct std...
    +add_single_ctl_with_resume(struct usb_mixer_interface *mixer,
				      int id,
				  ...
    +snd_usb_soundblaster_remote_complete(struct urb *urb)
    +snd_usb_sbrc_hwdep_read(struct snd_hwdep *hw, char __user *buf,
				    long count, l...
    +snd_usb_sbrc_hwdep_poll(struct snd_hwdep *hw, struct file *file,
					poll_table ...
    +snd_usb_soundblaster_remote_init(struct usb_mixer_interface *mixer)
    +snd_audigy2nx_led_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
    +snd_audigy2nx_led_update(struct usb_mixer_interface *mixer,
				    int value, int index)
  }
  class mixer_quirks_c_sb_jack {
    <<struct>>
    +snd_create_std_mono_ctl_offset(struct usb_mixer_interface *mixer,
					  unsigned int ...
    +snd_create_std_mono_ctl(struct usb_mixer_interface *mixer,
				   unsigned int unitid,...
    +snd_create_std_mono_table(struct usb_mixer_interface *mixer,
				     const struct std...
    +add_single_ctl_with_resume(struct usb_mixer_interface *mixer,
				      int id,
				  ...
    +snd_usb_soundblaster_remote_complete(struct urb *urb)
    +snd_usb_sbrc_hwdep_read(struct snd_hwdep *hw, char __user *buf,
				    long count, l...
    +snd_usb_sbrc_hwdep_poll(struct snd_hwdep *hw, struct file *file,
					poll_table ...
    +snd_usb_soundblaster_remote_init(struct usb_mixer_interface *mixer)
    +snd_audigy2nx_led_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
    +snd_audigy2nx_led_update(struct usb_mixer_interface *mixer,
				    int value, int index)
  }
  class mixer_quirks_c_dualsense_mixer_elem_info {
    <<struct>>
    +snd_create_std_mono_ctl_offset(struct usb_mixer_interface *mixer,
					  unsigned int ...
    +snd_create_std_mono_ctl(struct usb_mixer_interface *mixer,
				   unsigned int unitid,...
    +snd_create_std_mono_table(struct usb_mixer_interface *mixer,
				     const struct std...
    +add_single_ctl_with_resume(struct usb_mixer_interface *mixer,
				      int id,
				  ...
    +snd_usb_soundblaster_remote_complete(struct urb *urb)
    +snd_usb_sbrc_hwdep_read(struct snd_hwdep *hw, char __user *buf,
				    long count, l...
    +snd_usb_sbrc_hwdep_poll(struct snd_hwdep *hw, struct file *file,
					poll_table ...
    +snd_usb_soundblaster_remote_init(struct usb_mixer_interface *mixer)
    +snd_audigy2nx_led_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
    +snd_audigy2nx_led_update(struct usb_mixer_interface *mixer,
				    int value, int index)
  }
  class mixer_quirks_c_snd_djm_device {
    <<struct>>
    +snd_create_std_mono_ctl_offset(struct usb_mixer_interface *mixer,
					  unsigned int ...
    +snd_create_std_mono_ctl(struct usb_mixer_interface *mixer,
				   unsigned int unitid,...
    +snd_create_std_mono_table(struct usb_mixer_interface *mixer,
				     const struct std...
    +add_single_ctl_with_resume(struct usb_mixer_interface *mixer,
				      int id,
				  ...
    +snd_usb_soundblaster_remote_complete(struct urb *urb)
    +snd_usb_sbrc_hwdep_read(struct snd_hwdep *hw, char __user *buf,
				    long count, l...
    +snd_usb_sbrc_hwdep_poll(struct snd_hwdep *hw, struct file *file,
					poll_table ...
    +snd_usb_soundblaster_remote_init(struct usb_mixer_interface *mixer)
    +snd_audigy2nx_led_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
    +snd_audigy2nx_led_update(struct usb_mixer_interface *mixer,
				    int value, int index)
  }
  class mixer_quirks_c_snd_djm_ctl {
    <<struct>>
    +snd_create_std_mono_ctl_offset(struct usb_mixer_interface *mixer,
					  unsigned int ...
    +snd_create_std_mono_ctl(struct usb_mixer_interface *mixer,
				   unsigned int unitid,...
    +snd_create_std_mono_table(struct usb_mixer_interface *mixer,
				     const struct std...
    +add_single_ctl_with_resume(struct usb_mixer_interface *mixer,
				      int id,
				  ...
    +snd_usb_soundblaster_remote_complete(struct urb *urb)
    +snd_usb_sbrc_hwdep_read(struct snd_hwdep *hw, char __user *buf,
				    long count, l...
    +snd_usb_sbrc_hwdep_poll(struct snd_hwdep *hw, struct file *file,
					poll_table ...
    +snd_usb_soundblaster_remote_init(struct usb_mixer_interface *mixer)
    +snd_audigy2nx_led_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
    +snd_audigy2nx_led_update(struct usb_mixer_interface *mixer,
				    int value, int index)
  }
  class vsl_config_py_VSLParameter {
    <<class>>
    +validate_configuration()
    +print_configuration_status()
  }
  class vsl_hid_io_py_VSLDevice {
    <<class>>
    +enumerate_vsl_devices()
    +__new__(cls)
    +__init__(self)
    +open(self)
    +close(self)
    +send_packet(self, packet)
    +__enter__(self)
    +__exit__(self, exc_type, exc_val, exc_tb)
  }
  class vsl_protocol_analyzer_py_VSLParameter {
    <<class>>
    +reverse_map_gain(encoded_value, param)
    +reverse_map_frequency(encoded_value, param)
    +get_decoded_value(encoded_value, param_id)
    +decode_vsl_packet(data)
    +analyze_pcap(pcap_file)
    +__init__(self, dsp_id, name, type_unit, min_map, max_map, coeff_A, coeff_C1, log_factor)
  }
  class vsl_transport_py_VSLPacket {
    <<class>>
    +build_packet_safe(param, encoded_value)
    +__init__(self, param_id, encoded_value, report_id)
    +_build_buffer(self)
    +buffer(self)
    +hex_dump(self, num_bytes)
    +validate(self)
    +__repr__(self)
  }
  class vsl_dsp_transport_c_vsl_device {
    <<struct>>
    +VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)
    +VSL_Close_Device(vsl_device_handle handle)
    +VSL_Send_Parameter(vsl_device_handle handle,
                       uint16_t dsp_param_id,
  ...
  }
  class vc_crypto_c_vc_prng_s {
    <<struct>>
    +openssl_init(void)
    +vc_crypto_keygen(const char *pubkey_path, const char *privkey_path)
    +vc_crypto_seal(const char *pubkey_path,
                   const unsigned char *seed, size_t ...
    +vc_crypto_unseal(const char *privkey_path,
                     const unsigned char *enc, siz...
    +vc_crypto_derive_seeds(const unsigned char *master_seed, size_t seed_len,
                   ...
    +vc_prng_create(const unsigned char *seed)
    +vc_prng_destroy(vc_prng_t *p)
    +vc_prng_fill(vc_prng_t *p, unsigned char *buf, size_t len)
    +vc_prng_float(vc_prng_t *p, float low, float high)
  }
  class vc_rt_c_vc_rt_ctx_s {
    <<struct>>
    +vc_rt_create(size_t nbins, vc_rt_params_t params)
    +vc_rt_destroy(vc_rt_ctx_t *c)
    +vc_rt_reset(vc_rt_ctx_t *c)
    +vc_rt_semitones_to_ratio(float semitones)
    +wrap_pi(double x)
    +formant_warp(float *syn_mag, size_t nbins, float factor)
    +vc_rt_transform(float *mag, float *phase, size_t nbins,
                     uint32_t sample...
  }
  class vc_stft_c_vc_stft_s {
    <<struct>>
    +vc_stft_create(size_t fft_size, size_t hop_size)
    +vc_stft_destroy(vc_stft_t *st)
    +vc_stft_num_bins(const vc_stft_t *st)
    +vc_stft_forward(vc_stft_t *st,
                    const float *samples, size_t num_samples,
...
    +vc_stft_inverse(vc_stft_t *st,
                    const float *mag, const float *phase,
    ...
    +vc_stft_inverse_hop(vc_stft_t *st,
                        const float *mag, const float *pha...
  }
  class vc_stream_c_vc_stream_s {
    <<struct>>
    +is_pow2(size_t v)
    +vc_stream_create(size_t fft_size, size_t hop_size,
                              uin...
    +vc_stream_destroy(vc_stream_t *st)
    +vc_stream_latency_samples(const vc_stream_t *st)
    +process_frame(vc_stream_t *st, vc_spectral_fn fn, void *user)
    +vc_stream_process(vc_stream_t *st,
                      const float *in, float *out, size_t ...
  }
  mixer_quirks_c_dualsense_mixer_elem_info --> audiobox_vsl_h_usb_mixer_interface : uses
  mixer_quirks_c_rc_config --> audiobox_vsl_h_usb_mixer_interface : uses
  mixer_quirks_c_sb_jack --> audiobox_vsl_h_usb_mixer_interface : uses
  mixer_quirks_c_snd_djm_ctl --> audiobox_vsl_h_usb_mixer_interface : uses
  mixer_quirks_c_snd_djm_device --> audiobox_vsl_h_usb_mixer_interface : uses
  mixer_quirks_c_std_mono_table --> audiobox_vsl_h_usb_mixer_interface : uses
```

---

## Code Property Graph

Machine-readable Code Property Graph (CPG) in JSON-LD format. This block allows AI agents to parse the full structural graph without additional file reads. Compatible with GraphRAG pipelines.

```json
{"@context": "https://schema.org", "analysis": {"communities": [{"cohesion": 1.0, "id": 0, "label": "root", "size": 4}, {"cohesion": 1.0, "id": 1, "label": "legacy", "size": 5}], "god_nodes": [{"node_id": "legacy/mixer_quirks.c", "score": 32.6}, {"node_id": "legacy/vsl_config.py", "score": 8.3}, {"node_id": "legacy/vsl_hid_io.py", "score": 6.9}, {"node_id": "legacy/vsl_transport.py", "score": 6.8}, {"node_id": "legacy/vsl_poc_main.py", "score": 6.7}, {"node_id": "legacy/vsl_core.py", "score": 6.5}, {"node_id": "audiobox_vsl.h", "score": 6.4}, {"node_id": "tests/test_audiobox_vsl.c", "score": 3.0}, {"node_id": "audiobox_vsl.c", "score": 2.5}, {"node_id": "legacy/build-dkms.sh", "score": 1.9}], "surprising_connections": []}, "edges": [{"confidence": "EXTRACTED", "relation": "imports", "source": "audiobox_vsl.c", "target": "audiobox_vsl.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "audiobox_vsl.c", "target": "linux/module.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "audiobox_vsl.c", "target": "linux/printk.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "audiobox_vsl.c", "target": "linux/usb.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "audiobox_vsl.h", "target": "linux/types.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "audiobox_vsl.h", "target": "linux/usb.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "audiobox_vsl.h", "target": "sound/core.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/main.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/main.c", "target": "vsl_dsp_logic.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/main.c", "target": "vsl_dsp_transport.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "linux/bitfield.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "linux/hid.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "linux/init.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "linux/input.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "linux/math64.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "linux/slab.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "linux/usb.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "linux/usb/audio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "sound/asoundef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "sound/core.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "sound/control.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "sound/hda_verbs.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "sound/hwdep.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "sound/info.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "sound/tlv.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "usbaudio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "mixer.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "mixer_quirks.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "audiobox_vsl.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "mixer_scarlett.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "mixer_scarlett2.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "mixer_us16x08.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "mixer_s1810c.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "helper.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "fcp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/test_connection.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/test_connection.c", "target": "vsl_config.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/test_connection.c", "target": "vsl_dsp_transport.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_config.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_config.py", "target": "sys"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_config.py", "target": "typing"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_core.py", "target": "math"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_core.py", "target": "typing"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_core.py", "target": "vsl_config"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_core.py", "target": "vsl_config"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_logic.c", "target": "vsl_dsp_logic.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_logic.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_logic.h", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_logic.h", "target": "float.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_transport.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_transport.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_transport.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_transport.c", "target": "hidapi/hidapi.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_transport.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_transport.c", "target": "vsl_config.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_transport.c", "target": "vsl_dsp_transport.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_transport.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_transport.h", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_transport.h", "target": "hidapi/hidapi.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_transport.h", "target": "vsl_config.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_hid_io.py", "target": "typing"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_hid_io.py", "target": "sys"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_hid_io.py", "target": "vsl_config"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_hid_io.py", "target": "vsl_transport"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_hid_io.py", "target": "hid"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_hid_io.py", "target": "vsl_config"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_hid_io.py", "target": "vsl_core"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_hid_io.py", "target": "traceback"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_poc_main.py", "target": "sys"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_poc_main.py", "target": "typing"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_poc_main.py", "target": "vsl_config"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_poc_main.py", "target": "vsl_core"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_poc_main.py", "target": "vsl_transport"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_poc_main.py", "target": "traceback"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_protocol_analyzer.py", "target": "math"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_protocol_analyzer.py", "target": "sys"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_protocol_analyzer.py", "target": "json"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_protocol_analyzer.py", "target": "typing"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_protocol_analyzer.py", "target": "scapy.all"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_transport.py", "target": "typing"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_transport.py", "target": "vsl_config"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_transport.py", "target": "vsl_config"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_cli.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_cli.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_cli.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_cli.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_cli.c", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_cli.c", "target": "vsl_dsp_logic.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_cli.c", "target": "vsl_dsp_transport.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_cli.c", "target": "vsl_config.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_config.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_config.h", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_dsp_logic.c", "target": "vsl_dsp_logic.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_dsp_logic.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_dsp_logic.h", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_dsp_logic.h", "target": "float.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_dsp_transport.c", "target": "vsl_dsp_transport.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_dsp_transport.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_dsp_transport.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_dsp_transport.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_dsp_transport.c", "target": "libusb-1.0/libusb.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_dsp_transport.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_dsp_transport.h", "target": "vsl_dsp_logic.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_dsp_transport.h", "target": "vsl_config.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_audiobox_vsl.c", "target": "stdarg.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_audiobox_vsl.c", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_audiobox_vsl.c", "target": "setjmp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_audiobox_vsl.c", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_audiobox_vsl.c", "target": "cmocka.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_audiobox_vsl.c", "target": "audiobox_vsl.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_vsl_dsp_logic.c", "target": "stdarg.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_vsl_dsp_logic.c", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_vsl_dsp_logic.c", "target": "setjmp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_vsl_dsp_logic.c", "target": "cmocka.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_vsl_dsp_logic.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_vsl_dsp_logic.c", "target": "float.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_vsl_dsp_logic.c", "target": "vsl_dsp_logic.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_alsa.c", "target": "vc_alsa.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_alsa.c", "target": "vc_stream.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_alsa.c", "target": "alloca.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_alsa.c", "target": "alsa/asoundlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_alsa.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_alsa.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_alsa.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_alsa.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_alsa.h", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_alsa.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_alsa.h", "target": "signal.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_alsa.h", "target": "vc_stream.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_cli.c", "target": "vc_wav.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_cli.c", "target": "vc_dsp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_cli.c", "target": "vc_crypto.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_cli.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_cli.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_cli.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_cli.c", "target": "time.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_crypto.c", "target": "vc_crypto.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_crypto.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_crypto.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_crypto.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_crypto.c", "target": "openssl/evp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_crypto.c", "target": "openssl/pem.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_crypto.c", "target": "openssl/rsa.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_crypto.c", "target": "openssl/rand.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_crypto.c", "target": "openssl/err.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_crypto.c", "target": "openssl/hmac.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_crypto.h", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_crypto.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_dsp.c", "target": "vc_dsp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_dsp.c", "target": "vc_stft.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_dsp.c", "target": "vc_crypto.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_dsp.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_dsp.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_dsp.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_dsp.c", "target": "float.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_dsp.h", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_dsp.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_fft.c", "target": "vc_fft.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_fft.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_fft.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_fft.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_fft.h", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt.c", "target": "vc_rt.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt.h", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "vc_alsa.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "vc_stream.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "vc_rt.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "vc_fft.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "vc_crypto.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "signal.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_seed.c", "target": "vc_rt.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_seed.c", "target": "vc_crypto.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_seed.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stft.c", "target": "vc_stft.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stft.c", "target": "vc_fft.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stft.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stft.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stft.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stft.h", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stft.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stream.c", "target": "vc_stream.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stream.c", "target": "vc_fft.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stream.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stream.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stream.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stream.h", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stream.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_wav.c", "target": "vc_wav.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_wav.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_wav.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_wav.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_wav.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_wav.c", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_wav.h", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_wav.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_fft.c", "target": "stdarg.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_fft.c", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_fft.c", "target": "setjmp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_fft.c", "target": "cmocka.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_fft.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_fft.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_fft.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_fft.c", "target": "vc_fft.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_stream.c", "target": "stdarg.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_stream.c", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_stream.c", "target": "setjmp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_stream.c", "target": "cmocka.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_stream.c", "target": "vc_stream.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_stream.c", "target": "vc_rt.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_stream.c", "target": "vc_fft.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_stream.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_stream.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_stream.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_core.py", "target": "legacy/vsl_config.py"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_core.py", "target": "legacy/vsl_config.py"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_hid_io.py", "target": "legacy/vsl_config.py"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_hid_io.py", "target": "legacy/vsl_transport.py"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_hid_io.py", "target": "legacy/vsl_config.py"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_hid_io.py", "target": "legacy/vsl_core.py"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_poc_main.py", "target": "legacy/vsl_config.py"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_poc_main.py", "target": "legacy/vsl_core.py"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_poc_main.py", "target": "legacy/vsl_transport.py"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_transport.py", "target": "legacy/vsl_config.py"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_transport.py", "target": "legacy/vsl_config.py"}], "generator": "readmenator", "metadata": {"edge_count": 483, "file_count": 49, "language_count": 4, "symbol_count": 563}, "nodes": [{"doc": "SPDX-License-Identifier: GPL-2.0-or-later", "id": "audiobox_vsl.c", "kind": "module", "label": "audiobox_vsl.c", "language": "c", "sha256": "200395ef3d7c2421", "symbol_count": 5, "symbols": [{"kind": "function", "line": 36, "name": "audiobox_probe", "signature": "static int audiobox_probe(struct usb_interface *intf,\n                          const struct usb_..."}, {"kind": "function", "line": 58, "name": "audiobox_disconnect", "signature": "static void audiobox_disconnect(struct usb_interface *intf)"}, {"kind": "macro", "line": 24, "name": "AUDIOBOX_DRIVER_NAME"}, {"kind": "macro", "line": 26, "name": "AUDIOBOX_DRIVER_DESC"}, {"kind": "macro", "line": 27, "name": "AUDIOBOX_DRIVER_LIC"}]}, {"doc": "SPDX-License-Identifier: GPL-2.0-or-later", "id": "audiobox_vsl.h", "kind": "module", "label": "audiobox_vsl.h", "language": "h", "sha256": "05321cb8a973dc00", "symbol_count": 4, "symbols": [{"kind": "struct", "line": 113, "name": "usb_mixer_interface"}, {"doc": "@brief Look up the model info entry for a given USB product ID.  @param pid 16-bit product ID reported by the USB device. @return Pointer to a const entry in audiobox_models[] on match. NULL if pid does not correspond to any supported model.  Pure function: no side effects, no allocation, safe to call from any context including the USB probe path. The returned pointer remains valid for the lifetime of the kernel. Defined as a static inline so both the kernel module and the userspace test suite can include this header and exercise the lookup without linking against kernel-only object files.", "kind": "function", "line": 95, "name": "audiobox_lookup_model", "signature": "static inline const audiobox_model_info_t *\naudiobox_lookup_model(uint16_t pid)"}, {"kind": "macro", "line": 21, "name": "AUDIOBOX_VSL_H"}, {"kind": "macro", "line": 32, "name": "AUDIOBOX_VENDOR_ID"}]}, {"doc": "SPDX-License-Identifier: GPL-2.0-or-later Thin wrapper that installs the build-time dependencies for the audiobox_vsl kernel module. All real build, install, and clean commands live in the top-level Makefile. This script is intentionally minimal: it only ensures the toolchain and kernel headers are present, then exits.", "id": "install.sh", "kind": "module", "label": "install.sh", "language": "sh", "sha256": "c907d80fd6734993", "symbol_count": 0, "symbols": []}, {"doc": "_*_ coding: utf8 _*_", "id": "legacy/app.py", "kind": "module", "label": "app.py", "language": "py", "sha256": "e13d4e20ecf11033", "symbol_count": 0, "symbols": []}, {"doc": "AudioBox 22 VSL Enhanced Driver - Installation Script Copyright (c) 2025 grisuno (LazyOwn Project) License: GPL-2.0-or-later  This script installs enhanced ALSA controls for PreSonus AudioBox 22 VSL using DKMS (Dynamic Kernel Module Support) for automatic kernel updates.", "id": "legacy/build-dkms.sh", "kind": "module", "label": "build-dkms.sh", "language": "sh", "sha256": "df6198c88ef13ca4", "symbol_count": 19, "symbols": [{"kind": "function", "line": 40, "name": "print_header"}, {"kind": "function", "line": 48, "name": "print_success"}, {"kind": "function", "line": 52, "name": "print_error"}, {"kind": "function", "line": 56, "name": "print_warning"}, {"kind": "function", "line": 60, "name": "print_info"}, {"kind": "function", "line": 64, "name": "check_root"}, {"kind": "function", "line": 72, "name": "check_dependencies"}, {"kind": "function", "line": 101, "name": "detect_audiobox"}, {"kind": "function", "line": 123, "name": "create_source_structure"}, {"kind": "function", "line": 138, "name": "copy_source_files"}, {"kind": "function", "line": 174, "name": "create_dkms_conf"}, {"kind": "function", "line": 193, "name": "create_makefile"}, {"kind": "function", "line": 252, "name": "verify_mixer_quirks"}, {"kind": "function", "line": 295, "name": "build_with_dkms"}, {"kind": "function", "line": 309, "name": "install_module"}, {"kind": "function", "line": 323, "name": "reload_module"}, {"kind": "function", "line": 344, "name": "verify_installation"}, {"kind": "function", "line": 394, "name": "show_usage_info"}, {"kind": "function", "line": 452, "name": "main"}]}, {"doc": "include <stdio.h> include \"vsl_dsp_logic.h\" include \"vsl_dsp_transport.h\"", "id": "legacy/main.c", "kind": "module", "label": "main.c", "language": "c", "sha256": "6c7a6eda70c63bcb", "symbol_count": 1, "symbols": [{"doc": "include <stdio.h> include \"vsl_dsp_logic.h\" include \"vsl_dsp_transport.h\"", "kind": "function", "line": 4, "name": "main", "signature": "int main()"}]}, {"doc": "SPDX-License-Identifier: GPL-2.0-or-later", "id": "legacy/mixer_quirks.c", "kind": "module", "label": "mixer_quirks.c", "language": "c", "sha256": "674864e039433003", "symbol_count": 306, "symbols": [{"kind": "struct", "line": 45, "name": "std_mono_table"}, {"doc": "Sound Blaster remote control configuration  format of remote control data: Extigy:       xx 00 Audigy 2 NX:  06 80 xx 00 00 00 Live! 24-bit: 06 80 xx yy 22 83", "kind": "struct", "line": 181, "name": "rc_config"}, {"kind": "struct", "line": 410, "name": "sb_jack"}, {"kind": "struct", "line": 543, "name": "dualsense_mixer_elem_info"}, {"kind": "struct", "line": 3778, "name": "snd_djm_device"}, {"kind": "struct", "line": 3784, "name": "snd_djm_ctl"}, {"doc": "This function allows for the creation of standard UAC controls. See the quirks for M-Audio FTUs or Ebox-44. If you don't want to set a TLV callback pass NULL.  Since there doesn't seem to be a devices that needs a multichannel version, we keep it mono for simplicity.", "kind": "function", "line": 59, "name": "snd_create_std_mono_ctl_offset", "signature": "static int snd_create_std_mono_ctl_offset(struct usb_mixer_interface *mixer,\n\t\t\t\t\t  unsigned int ..."}, {"kind": "function", "line": 112, "name": "snd_create_std_mono_ctl", "signature": "static int snd_create_std_mono_ctl(struct usb_mixer_interface *mixer,\n\t\t\t\t   unsigned int unitid,..."}, {"doc": "Create a set of standard UAC controls from a table", "kind": "function", "line": 129, "name": "snd_create_std_mono_table", "signature": "static int snd_create_std_mono_table(struct usb_mixer_interface *mixer,\n\t\t\t\t     const struct std..."}, {"kind": "function", "line": 145, "name": "add_single_ctl_with_resume", "signature": "static int add_single_ctl_with_resume(struct usb_mixer_interface *mixer,\n\t\t\t\t      int id,\n\t\t\t\t  ..."}, {"kind": "function", "line": 199, "name": "snd_usb_soundblaster_remote_complete", "signature": "static void snd_usb_soundblaster_remote_complete(struct urb *urb)"}, {"kind": "function", "line": 219, "name": "snd_usb_sbrc_hwdep_read", "signature": "static long snd_usb_sbrc_hwdep_read(struct snd_hwdep *hw, char __user *buf,\n\t\t\t\t    long count, l..."}, {"kind": "function", "line": 239, "name": "snd_usb_sbrc_hwdep_poll", "signature": "static __poll_t snd_usb_sbrc_hwdep_poll(struct snd_hwdep *hw, struct file *file,\n\t\t\t\t\tpoll_table ..."}, {"kind": "function", "line": 248, "name": "snd_usb_soundblaster_remote_init", "signature": "static int snd_usb_soundblaster_remote_init(struct usb_mixer_interface *mixer)"}, {"doc": "define snd_audigy2nx_led_info\t\tsnd_ctl_boolean_mono_info", "kind": "function", "line": 298, "name": "snd_audigy2nx_led_get", "signature": "static int snd_audigy2nx_led_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)"}, {"kind": "function", "line": 304, "name": "snd_audigy2nx_led_update", "signature": "static int snd_audigy2nx_led_update(struct usb_mixer_interface *mixer,\n\t\t\t\t    int value, int index)"}, {"kind": "function", "line": 333, "name": "snd_audigy2nx_led_put", "signature": "static int snd_audigy2nx_led_put(struct snd_kcontrol *kcontrol,\n\t\t\t\t struct snd_ctl_elem_value *u..."}, {"kind": "function", "line": 352, "name": "snd_audigy2nx_led_resume", "signature": "static int snd_audigy2nx_led_resume(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 374, "name": "snd_audigy2nx_controls_create", "signature": "static int snd_audigy2nx_controls_create(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 406, "name": "snd_audigy2nx_proc_read", "signature": "static void snd_audigy2nx_proc_read(struct snd_info_entry *entry,\n\t\t\t\t    struct snd_info_buffer ..."}, {"doc": "return; err = snd_usb_ctl_msg(mixer->chip->dev, usb_rcvctrlpipe(mixer->chip->dev, 0), UAC_GET_MEM, USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE, 0, jacks[i].unitid << 8, buf, 3); if (err == 3 && (buf[0] == 3 || buf[0] == 6)) snd_iprintf(buffer, \"%02x %02x\\n\", buf[1], buf[2]); else snd_iprintf(buffer, \"?\\n\"); } } /* EMU0204", "kind": "function", "line": 457, "name": "snd_emu0204_ch_switch_info", "signature": "static int snd_emu0204_ch_switch_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t      struct snd_ctl_ele..."}, {"kind": "function", "line": 464, "name": "snd_emu0204_ch_switch_get", "signature": "static int snd_emu0204_ch_switch_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t     struct snd_ctl_elem_..."}, {"kind": "function", "line": 471, "name": "snd_emu0204_ch_switch_update", "signature": "static int snd_emu0204_ch_switch_update(struct usb_mixer_interface *mixer,\n\t\t\t\t\tint value)"}, {"kind": "function", "line": 489, "name": "snd_emu0204_ch_switch_put", "signature": "static int snd_emu0204_ch_switch_put(struct snd_kcontrol *kcontrol,\n\t\t\t\t     struct snd_ctl_elem_..."}, {"kind": "function", "line": 508, "name": "snd_emu0204_ch_switch_resume", "signature": "static int snd_emu0204_ch_switch_resume(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 523, "name": "snd_emu0204_controls_create", "signature": "static int snd_emu0204_controls_create(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 549, "name": "snd_dualsense_ih_event", "signature": "static void snd_dualsense_ih_event(struct input_handle *handle,\n\t\t\t\t   unsigned int type, unsigne..."}, {"kind": "function", "line": 570, "name": "snd_dualsense_ih_match", "signature": "static bool snd_dualsense_ih_match(struct input_handler *handler,\n\t\t\t\t   struct input_dev *dev)"}, {"kind": "function", "line": 617, "name": "snd_dualsense_ih_connect", "signature": "static int snd_dualsense_ih_connect(struct input_handler *handler,\n\t\t\t\t    struct input_dev *dev,..."}, {"kind": "function", "line": 649, "name": "snd_dualsense_ih_disconnect", "signature": "static void snd_dualsense_ih_disconnect(struct input_handle *handle)"}, {"kind": "function", "line": 656, "name": "snd_dualsense_ih_start", "signature": "static void snd_dualsense_ih_start(struct input_handle *handle)"}, {"kind": "function", "line": 679, "name": "snd_dualsense_jack_get", "signature": "static int snd_dualsense_jack_get(struct snd_kcontrol *kctl,\n\t\t\t\t  struct snd_ctl_elem_value *uco..."}, {"kind": "function", "line": 696, "name": "snd_dualsense_resume_jack", "signature": "static int snd_dualsense_resume_jack(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 703, "name": "snd_dualsense_mixer_elem_free", "signature": "static void snd_dualsense_mixer_elem_free(struct snd_kcontrol *kctl)"}, {"kind": "function", "line": 713, "name": "snd_dualsense_jack_create", "signature": "static int snd_dualsense_jack_create(struct usb_mixer_interface *mixer,\n\t\t\t\t     const char *name..."}, {"kind": "function", "line": 777, "name": "snd_dualsense_controls_create", "signature": "static int snd_dualsense_controls_create(struct usb_mixer_interface *mixer)"}, {"doc": "static int snd_dualsense_controls_create(struct usb_mixer_interface *mixer) { int err; err = snd_dualsense_jack_create(mixer, \"Headphone Jack\", true); if (err < 0) return err; return snd_dualsense_jack_create(mixer, \"Headset Mic Jack\", false); } #endif /* IS_REACHABLE(CONFIG_INPUT) /* ASUS Xonar U1 / U3 controls", "kind": "function", "line": 791, "name": "snd_xonar_u1_switch_get", "signature": "static int snd_xonar_u1_switch_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t   struct snd_ctl_elem_valu..."}, {"kind": "function", "line": 798, "name": "snd_xonar_u1_switch_update", "signature": "static int snd_xonar_u1_switch_update(struct usb_mixer_interface *mixer,\n\t\t\t\t      unsigned char ..."}, {"kind": "function", "line": 812, "name": "snd_xonar_u1_switch_put", "signature": "static int snd_xonar_u1_switch_put(struct snd_kcontrol *kcontrol,\n\t\t\t\t   struct snd_ctl_elem_valu..."}, {"kind": "function", "line": 832, "name": "snd_xonar_u1_switch_resume", "signature": "static int snd_xonar_u1_switch_resume(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 847, "name": "snd_xonar_u1_controls_create", "signature": "static int snd_xonar_u1_controls_create(struct usb_mixer_interface *mixer)"}, {"doc": ".info = snd_ctl_boolean_mono_info, .get = snd_xonar_u1_switch_get, .put = snd_xonar_u1_switch_put, .private_value = 0x05, }; static int snd_xonar_u1_controls_create(struct usb_mixer_interface *mixer) { return add_single_ctl_with_resume(mixer, 0, snd_xonar_u1_switch_resume, &snd_xonar_u1_output_switch, NULL); } /* Digidesign Mbox 1 helper functions", "kind": "function", "line": 856, "name": "snd_mbox1_is_spdif_synced", "signature": "static int snd_mbox1_is_spdif_synced(struct snd_usb_audio *chip)"}, {"kind": "function", "line": 876, "name": "snd_mbox1_set_clk_source", "signature": "static int snd_mbox1_set_clk_source(struct snd_usb_audio *chip, int rate_or_zero)"}, {"kind": "function", "line": 894, "name": "snd_mbox1_is_spdif_input", "signature": "static int snd_mbox1_is_spdif_input(struct snd_usb_audio *chip)"}, {"kind": "function", "line": 914, "name": "snd_mbox1_set_input_source", "signature": "static int snd_mbox1_set_input_source(struct snd_usb_audio *chip, int is_spdif)"}, {"doc": "S/PDIF Source  -> 0x02  unsigned char buff[1]; buff[0] = (is_spdif & 1) + 1; /* Set input source return snd_usb_ctl_msg(chip->dev, usb_sndctrlpipe(chip->dev, 0), 0x1, USB_TYPE_CLASS | USB_RECIP_INTERFACE, 0x00, 0x500, buff, 1); } /* Digidesign Mbox 1 clock source switch (internal/spdif)", "kind": "function", "line": 933, "name": "snd_mbox1_clk_switch_get", "signature": "static int snd_mbox1_clk_switch_get(struct snd_kcontrol *kctl,\n\t\t\t\t    struct snd_ctl_elem_value ..."}, {"kind": "function", "line": 953, "name": "snd_mbox1_clk_switch_update", "signature": "static int snd_mbox1_clk_switch_update(struct usb_mixer_interface *mixer, int is_spdif_sync)"}, {"kind": "function", "line": 978, "name": "snd_mbox1_clk_switch_put", "signature": "static int snd_mbox1_clk_switch_put(struct snd_kcontrol *kctl,\n\t\t\t\t    struct snd_ctl_elem_value ..."}, {"kind": "function", "line": 996, "name": "snd_mbox1_clk_switch_info", "signature": "static int snd_mbox1_clk_switch_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t     struct snd_ctl_elem_..."}, {"kind": "function", "line": 1007, "name": "snd_mbox1_clk_switch_resume", "signature": "static int snd_mbox1_clk_switch_resume(struct usb_mixer_elem_list *list)"}, {"doc": "static const char *const texts[2] = { \"Internal\", \"S/PDIF\" }; return snd_ctl_enum_info(uinfo, 1, ARRAY_SIZE(texts), texts); } static int snd_mbox1_clk_switch_resume(struct usb_mixer_elem_list *list) { return snd_mbox1_clk_switch_update(list->mixer, list->kctl->private_value); } /* Digidesign Mbox 1 input source switch (analog/spdif)", "kind": "function", "line": 1014, "name": "snd_mbox1_src_switch_get", "signature": "static int snd_mbox1_src_switch_get(struct snd_kcontrol *kctl,\n\t\t\t\t    struct snd_ctl_elem_value ..."}, {"kind": "function", "line": 1021, "name": "snd_mbox1_src_switch_update", "signature": "static int snd_mbox1_src_switch_update(struct usb_mixer_interface *mixer, int is_spdif_input)"}, {"kind": "function", "line": 1045, "name": "snd_mbox1_src_switch_put", "signature": "static int snd_mbox1_src_switch_put(struct snd_kcontrol *kctl,\n\t\t\t\t    struct snd_ctl_elem_value ..."}, {"kind": "function", "line": 1063, "name": "snd_mbox1_src_switch_info", "signature": "static int snd_mbox1_src_switch_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t     struct snd_ctl_elem_..."}, {"kind": "function", "line": 1074, "name": "snd_mbox1_src_switch_resume", "signature": "static int snd_mbox1_src_switch_resume(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 1101, "name": "snd_mbox1_controls_create", "signature": "static int snd_mbox1_controls_create(struct usb_mixer_interface *mixer)"}, {"doc": "define _MAKE_NI_CONTROL(bRequest, wIndex) ((bRequest) << 16 | (wIndex))", "kind": "function", "line": 1120, "name": "snd_ni_control_init_val", "signature": "static int snd_ni_control_init_val(struct usb_mixer_interface *mixer,\n\t\t\t\t   struct snd_kcontrol ..."}, {"kind": "function", "line": 1142, "name": "snd_nativeinstruments_control_get", "signature": "static int snd_nativeinstruments_control_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t\t     struct snd_..."}, {"kind": "function", "line": 1149, "name": "snd_ni_update_cur_val", "signature": "static int snd_ni_update_cur_val(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 1163, "name": "snd_nativeinstruments_control_put", "signature": "static int snd_nativeinstruments_control_put(struct snd_kcontrol *kcontrol,\n\t\t\t\t\t     struct snd_..."}, {"kind": "function", "line": 1234, "name": "snd_nativeinstruments_create_mixer", "signature": "static int snd_nativeinstruments_create_mixer(struct usb_mixer_interface *mixer,\n\t\t\t\t\t      const..."}, {"doc": "err = add_single_ctl_with_resume(mixer, 0, snd_ni_update_cur_val, &template, &list); if (err < 0) break; snd_ni_control_init_val(mixer, list->kctl); } return err; } /* M-Audio FastTrack Ultra quirks /* FTU Effect switch (also used by C400/C600)", "kind": "function", "line": 1267, "name": "snd_ftu_eff_switch_info", "signature": "static int snd_ftu_eff_switch_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t   struct snd_ctl_elem_info..."}, {"kind": "function", "line": 1277, "name": "snd_ftu_eff_switch_init", "signature": "static int snd_ftu_eff_switch_init(struct usb_mixer_interface *mixer,\n\t\t\t\t   struct snd_kcontrol ..."}, {"kind": "function", "line": 1300, "name": "snd_ftu_eff_switch_get", "signature": "static int snd_ftu_eff_switch_get(struct snd_kcontrol *kctl,\n\t\t\t\t  struct snd_ctl_elem_value *uco..."}, {"kind": "function", "line": 1307, "name": "snd_ftu_eff_switch_update", "signature": "static int snd_ftu_eff_switch_update(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 1328, "name": "snd_ftu_eff_switch_put", "signature": "static int snd_ftu_eff_switch_put(struct snd_kcontrol *kctl,\n\t\t\t\t  struct snd_ctl_elem_value *uco..."}, {"kind": "function", "line": 1346, "name": "snd_ftu_create_effect_switch", "signature": "static int snd_ftu_create_effect_switch(struct usb_mixer_interface *mixer,\n\t\t\t\t\tint validx, int b..."}, {"doc": "struct usb_mixer_elem_list *list; int err; err = add_single_ctl_with_resume(mixer, bUnitID, snd_ftu_eff_switch_update, &template, &list); if (err < 0) return err; list->kctl->private_value = (validx << 8) | bUnitID; snd_ftu_eff_switch_init(mixer, list->kctl); return 0; } /* Create volume controls for FTU devices", "kind": "function", "line": 1373, "name": "snd_ftu_create_volume_ctls", "signature": "static int snd_ftu_create_volume_ctls(struct usb_mixer_interface *mixer)"}, {"doc": "\"DIn%d - Out%d Playback Volume\", in - 7, out + 1); err = snd_create_std_mono_ctl(mixer, id, control, cmask, val_type, name, &snd_usb_mixer_vol_tlv); if (err < 0) return err; } } return 0; } /* This control needs a volume quirk, see mixer.c", "kind": "function", "line": 1412, "name": "snd_ftu_create_effect_volume_ctl", "signature": "static int snd_ftu_create_effect_volume_ctl(struct usb_mixer_interface *mixer)"}, {"doc": "/* This control needs a volume quirk, see mixer.c static int snd_ftu_create_effect_volume_ctl(struct usb_mixer_interface *mixer) { static const char name[] = \"Effect Volume\"; const unsigned int id = 6; const int val_type = USB_MIXER_U8; const unsigned int control = 2; const unsigned int cmask = 0; return snd_create_std_mono_ctl(mixer, id, control, cmask, val_type, name, snd_usb_mixer_vol_tlv); } /* This control needs a volume quirk, see mixer.c", "kind": "function", "line": 1425, "name": "snd_ftu_create_effect_duration_ctl", "signature": "static int snd_ftu_create_effect_duration_ctl(struct usb_mixer_interface *mixer)"}, {"doc": "/* This control needs a volume quirk, see mixer.c static int snd_ftu_create_effect_duration_ctl(struct usb_mixer_interface *mixer) { static const char name[] = \"Effect Duration\"; const unsigned int id = 6; const int val_type = USB_MIXER_S16; const unsigned int control = 3; const unsigned int cmask = 0; return snd_create_std_mono_ctl(mixer, id, control, cmask, val_type, name, snd_usb_mixer_vol_tlv); } /* This control needs a volume quirk, see mixer.c", "kind": "function", "line": 1438, "name": "snd_ftu_create_effect_feedback_ctl", "signature": "static int snd_ftu_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 1449, "name": "snd_ftu_create_effect_return_ctls", "signature": "static int snd_ftu_create_effect_return_ctls(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 1473, "name": "snd_ftu_create_effect_send_ctls", "signature": "static int snd_ftu_create_effect_send_ctls(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 1506, "name": "snd_ftu_create_mixer", "signature": "static int snd_ftu_create_mixer(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 1541, "name": "snd_emuusb_set_samplerate", "signature": "void snd_emuusb_set_samplerate(struct snd_usb_audio *chip,\n\t\t\t       unsigned char samplerate_id)"}, {"doc": "err = snd_ftu_create_effect_send_ctls(mixer); if (err < 0) return err; return 0; } void snd_emuusb_set_samplerate(struct snd_usb_audio *chip, unsigned char samplerate_id) { struct usb_mixer_interface *mixer; struct usb_mixer_elem_info *cval; int unitid = 12; /* SampleRate ExtensionUnit ID", "kind": "function", "line": 1548, "name": "list_for_each_entry", "signature": "list_for_each_entry(mixer, &chip->mixer_list, list)"}, {"doc": "list_for_each_entry(mixer, &chip->mixer_list, list) { if (mixer->id_elems[unitid]) { cval = mixer_elem_list_to_info(mixer->id_elems[unitid]); snd_usb_mixer_set_ctl_value(cval, UAC_SET_CUR, cval->control << 8, samplerate_id); snd_usb_mixer_notify_id(mixer, unitid); break; } } } /* M-Audio Fast Track C400/C600 /* C400/C600 volume controls, this control needs a volume quirk, see mixer.c", "kind": "function", "line": 1563, "name": "snd_c400_create_vol_ctls", "signature": "static int snd_c400_create_vol_ctls(struct usb_mixer_interface *mixer)"}, {"doc": "cmask = (out == 0) ? 0 : BIT(out - 1); offset = chan * num_outs; err = snd_create_std_mono_ctl_offset(mixer, id, control, cmask, val_type, offset, name, &snd_usb_mixer_vol_tlv); if (err < 0) return err; } } return 0; } /* This control needs a volume quirk, see mixer.c", "kind": "function", "line": 1612, "name": "snd_c400_create_effect_volume_ctl", "signature": "static int snd_c400_create_effect_volume_ctl(struct usb_mixer_interface *mixer)"}, {"doc": "/* This control needs a volume quirk, see mixer.c static int snd_c400_create_effect_volume_ctl(struct usb_mixer_interface *mixer) { static const char name[] = \"Effect Volume\"; const unsigned int id = 0x43; const int val_type = USB_MIXER_U8; const unsigned int control = 3; const unsigned int cmask = 0; return snd_create_std_mono_ctl(mixer, id, control, cmask, val_type, name, snd_usb_mixer_vol_tlv); } /* This control needs a volume quirk, see mixer.c", "kind": "function", "line": 1625, "name": "snd_c400_create_effect_duration_ctl", "signature": "static int snd_c400_create_effect_duration_ctl(struct usb_mixer_interface *mixer)"}, {"doc": "/* This control needs a volume quirk, see mixer.c static int snd_c400_create_effect_duration_ctl(struct usb_mixer_interface *mixer) { static const char name[] = \"Effect Duration\"; const unsigned int id = 0x43; const int val_type = USB_MIXER_S16; const unsigned int control = 4; const unsigned int cmask = 0; return snd_create_std_mono_ctl(mixer, id, control, cmask, val_type, name, snd_usb_mixer_vol_tlv); } /* This control needs a volume quirk, see mixer.c", "kind": "function", "line": 1638, "name": "snd_c400_create_effect_feedback_ctl", "signature": "static int snd_c400_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 1649, "name": "snd_c400_create_effect_vol_ctls", "signature": "static int snd_c400_create_effect_vol_ctls(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 1694, "name": "snd_c400_create_effect_ret_vol_ctls", "signature": "static int snd_c400_create_effect_ret_vol_ctls(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 1736, "name": "snd_c400_create_mixer", "signature": "static int snd_c400_create_mixer(struct usb_mixer_interface *mixer)"}, {"doc": "power on values: r2: 0x10 r3: 0x20 (b7 is zeroed just before playback (except IEC61937) and set just after it to 0xa0, presumably it disables/mutes some analog parts when there is no audio.) r9: 0x28  Optical transmitter on/off: vendor register.bit: 9.1 0 - on (0x28 register value) 1 - off (0x2a register value)", "kind": "function", "line": 1869, "name": "snd_microii_spdif_info", "signature": "static int snd_microii_spdif_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t  struct snd_ctl_elem_info *..."}, {"kind": "function", "line": 1876, "name": "snd_microii_spdif_default_get", "signature": "static int snd_microii_spdif_default_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t\t struct snd_ctl_elem..."}, {"kind": "function", "line": 1923, "name": "snd_microii_spdif_default_update", "signature": "static int snd_microii_spdif_default_update(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 1959, "name": "snd_microii_spdif_default_put", "signature": "static int snd_microii_spdif_default_put(struct snd_kcontrol *kcontrol,\n\t\t\t\t\t struct snd_ctl_elem..."}, {"kind": "function", "line": 1987, "name": "snd_microii_spdif_mask_get", "signature": "static int snd_microii_spdif_mask_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t      struct snd_ctl_ele..."}, {"kind": "function", "line": 1998, "name": "snd_microii_spdif_switch_get", "signature": "static int snd_microii_spdif_switch_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t\tstruct snd_ctl_elem_v..."}, {"kind": "function", "line": 2006, "name": "snd_microii_spdif_switch_update", "signature": "static int snd_microii_spdif_switch_update(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 2025, "name": "snd_microii_spdif_switch_put", "signature": "static int snd_microii_spdif_switch_put(struct snd_kcontrol *kcontrol,\n\t\t\t\t\tstruct snd_ctl_elem_v..."}, {"kind": "function", "line": 2067, "name": "snd_microii_controls_create", "signature": "static int snd_microii_controls_create(struct usb_mixer_interface *mixer)"}, {"doc": "for (i = 0; i < ARRAY_SIZE(snd_microii_mixer_spdif); ++i) { err = add_single_ctl_with_resume(mixer, 0, resume_funcs[i], &snd_microii_mixer_spdif[i], NULL); if (err < 0) return err; } return 0; } /* Creative Sound Blaster E1", "kind": "function", "line": 2090, "name": "snd_soundblaster_e1_switch_get", "signature": "static int snd_soundblaster_e1_switch_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t\t  struct snd_ctl_el..."}, {"kind": "function", "line": 2097, "name": "snd_soundblaster_e1_switch_update", "signature": "static int snd_soundblaster_e1_switch_update(struct usb_mixer_interface *mixer,\n\t\t\t\t\t     unsigne..."}, {"kind": "function", "line": 2115, "name": "snd_soundblaster_e1_switch_put", "signature": "static int snd_soundblaster_e1_switch_put(struct snd_kcontrol *kcontrol,\n\t\t\t\t\t  struct snd_ctl_el..."}, {"kind": "function", "line": 2129, "name": "snd_soundblaster_e1_switch_resume", "signature": "static int snd_soundblaster_e1_switch_resume(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 2135, "name": "snd_soundblaster_e1_switch_info", "signature": "static int snd_soundblaster_e1_switch_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t\t   struct snd_ctl_..."}, {"kind": "function", "line": 2154, "name": "snd_soundblaster_e1_switch_create", "signature": "static int snd_soundblaster_e1_switch_create(struct usb_mixer_interface *mixer)"}, {"doc": "define REALTEK_MIC_FLAG 0x100", "kind": "function", "line": 2191, "name": "realtek_hda_set", "signature": "static int realtek_hda_set(struct snd_usb_audio *chip, u32 cmd)"}, {"kind": "function", "line": 2201, "name": "realtek_hda_get", "signature": "static int realtek_hda_get(struct snd_usb_audio *chip, u32 cmd, u32 *value)"}, {"kind": "function", "line": 2222, "name": "realtek_ctl_connector_get", "signature": "static int realtek_ctl_connector_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t     struct snd_ctl_elem_..."}, {"kind": "function", "line": 2272, "name": "realtek_resume_jack", "signature": "static int realtek_resume_jack(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 2279, "name": "realtek_add_jack", "signature": "static int realtek_add_jack(struct usb_mixer_interface *mixer,\n\t\t\t    char *name, u32 val)"}, {"kind": "function", "line": 2306, "name": "dell_dock_mixer_create", "signature": "static int dell_dock_mixer_create(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 2338, "name": "dell_dock_init_vol", "signature": "static void dell_dock_init_vol(struct usb_mixer_interface *mixer, int ch, int id)"}, {"kind": "function", "line": 2350, "name": "dell_dock_mixer_init", "signature": "static int dell_dock_mixer_init(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 2418, "name": "snd_rme_read_value", "signature": "static int snd_rme_read_value(struct snd_usb_audio *chip,\n\t\t\t      unsigned int item,\n\t\t\t      u3..."}, {"kind": "function", "line": 2437, "name": "snd_rme_get_status1", "signature": "static int snd_rme_get_status1(struct snd_kcontrol *kcontrol,\n\t\t\t       u32 *status1)"}, {"kind": "function", "line": 2449, "name": "snd_rme_rate_get", "signature": "static int snd_rme_rate_get(struct snd_kcontrol *kcontrol,\n\t\t\t    struct snd_ctl_elem_value *ucon..."}, {"kind": "function", "line": 2483, "name": "snd_rme_sync_state_get", "signature": "static int snd_rme_sync_state_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t  struct snd_ctl_elem_value ..."}, {"kind": "function", "line": 2513, "name": "snd_rme_spdif_if_get", "signature": "static int snd_rme_spdif_if_get(struct snd_kcontrol *kcontrol,\n\t\t\t\tstruct snd_ctl_elem_value *uco..."}, {"kind": "function", "line": 2526, "name": "snd_rme_spdif_format_get", "signature": "static int snd_rme_spdif_format_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t    struct snd_ctl_elem_va..."}, {"kind": "function", "line": 2539, "name": "snd_rme_sync_source_get", "signature": "static int snd_rme_sync_source_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t   struct snd_ctl_elem_valu..."}, {"kind": "function", "line": 2552, "name": "snd_rme_current_freq_get", "signature": "static int snd_rme_current_freq_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t    struct snd_ctl_elem_va..."}, {"kind": "function", "line": 2578, "name": "snd_rme_rate_info", "signature": "static int snd_rme_rate_info(struct snd_kcontrol *kcontrol,\n\t\t\t     struct snd_ctl_elem_info *uinfo)"}, {"kind": "function", "line": 2598, "name": "snd_rme_sync_state_info", "signature": "static int snd_rme_sync_state_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t   struct snd_ctl_elem_info..."}, {"kind": "function", "line": 2609, "name": "snd_rme_spdif_if_info", "signature": "static int snd_rme_spdif_if_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t struct snd_ctl_elem_info *ui..."}, {"kind": "function", "line": 2620, "name": "snd_rme_spdif_format_info", "signature": "static int snd_rme_spdif_format_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t     struct snd_ctl_elem_..."}, {"kind": "function", "line": 2631, "name": "snd_rme_sync_source_info", "signature": "static int snd_rme_sync_source_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t    struct snd_ctl_elem_in..."}, {"kind": "function", "line": 2713, "name": "snd_rme_controls_create", "signature": "static int snd_rme_controls_create(struct usb_mixer_interface *mixer)"}, {"doc": "define SND_BBFPRO_USBREQ_CTL_REG1 0x10 define SND_BBFPRO_USBREQ_CTL_REG2 0x17 define SND_BBFPRO_USBREQ_GAIN 0x1a define SND_BBFPRO_USBREQ_MIXER 0x12", "kind": "function", "line": 2779, "name": "snd_bbfpro_ctl_update", "signature": "static int snd_bbfpro_ctl_update(struct usb_mixer_interface *mixer, u8 reg,\n\t\t\t\t u8 index, u8 value)"}, {"kind": "function", "line": 2810, "name": "snd_bbfpro_ctl_get", "signature": "static int snd_bbfpro_ctl_get(struct snd_kcontrol *kcontrol,\n\t\t\t      struct snd_ctl_elem_value *..."}, {"kind": "function", "line": 2833, "name": "snd_bbfpro_ctl_info", "signature": "static int snd_bbfpro_ctl_info(struct snd_kcontrol *kcontrol,\n\t\t\t       struct snd_ctl_elem_info ..."}, {"kind": "function", "line": 2867, "name": "snd_bbfpro_ctl_put", "signature": "static int snd_bbfpro_ctl_put(struct snd_kcontrol *kcontrol,\n\t\t\t      struct snd_ctl_elem_value *..."}, {"kind": "function", "line": 2906, "name": "snd_bbfpro_ctl_resume", "signature": "static int snd_bbfpro_ctl_resume(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 2919, "name": "snd_bbfpro_gain_update", "signature": "static int snd_bbfpro_gain_update(struct usb_mixer_interface *mixer,\n\t\t\t\t  u8 channel, u8 gain)"}, {"kind": "function", "line": 2943, "name": "snd_bbfpro_gain_get", "signature": "static int snd_bbfpro_gain_get(struct snd_kcontrol *kcontrol,\n\t\t\t       struct snd_ctl_elem_value..."}, {"kind": "function", "line": 2952, "name": "snd_bbfpro_gain_info", "signature": "static int snd_bbfpro_gain_info(struct snd_kcontrol *kcontrol,\n\t\t\t\tstruct snd_ctl_elem_info *uinfo)"}, {"kind": "function", "line": 2973, "name": "snd_bbfpro_gain_put", "signature": "static int snd_bbfpro_gain_put(struct snd_kcontrol *kcontrol,\n\t\t\t       struct snd_ctl_elem_value..."}, {"kind": "function", "line": 3010, "name": "snd_bbfpro_gain_resume", "signature": "static int snd_bbfpro_gain_resume(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 3023, "name": "snd_bbfpro_vol_update", "signature": "static int snd_bbfpro_vol_update(struct usb_mixer_interface *mixer, u16 index,\n\t\t\t\t u32 value)"}, {"kind": "function", "line": 3049, "name": "snd_bbfpro_vol_get", "signature": "static int snd_bbfpro_vol_get(struct snd_kcontrol *kcontrol,\n\t\t\t      struct snd_ctl_elem_value *..."}, {"kind": "function", "line": 3057, "name": "snd_bbfpro_vol_info", "signature": "static int snd_bbfpro_vol_info(struct snd_kcontrol *kcontrol,\n\t\t\t       struct snd_ctl_elem_info ..."}, {"kind": "function", "line": 3067, "name": "snd_bbfpro_vol_put", "signature": "static int snd_bbfpro_vol_put(struct snd_kcontrol *kcontrol,\n\t\t\t      struct snd_ctl_elem_value *..."}, {"kind": "function", "line": 3095, "name": "snd_bbfpro_vol_resume", "signature": "static int snd_bbfpro_vol_resume(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 3132, "name": "snd_bbfpro_ctl_add", "signature": "static int snd_bbfpro_ctl_add(struct usb_mixer_interface *mixer, u8 reg,\n\t\t\t      u8 index, char ..."}, {"kind": "function", "line": 3146, "name": "snd_bbfpro_gain_add", "signature": "static int snd_bbfpro_gain_add(struct usb_mixer_interface *mixer, u8 channel,\n\t\t\t       char *name)"}, {"kind": "function", "line": 3158, "name": "snd_bbfpro_vol_add", "signature": "static int snd_bbfpro_vol_add(struct usb_mixer_interface *mixer, u16 index,\n\t\t\t      char *name)"}, {"kind": "function", "line": 3170, "name": "snd_bbfpro_controls_create", "signature": "static int snd_bbfpro_controls_create(struct usb_mixer_interface *mixer)"}, {"doc": "#define RME_DIGIFACE_STATUS_REG2H 5 #define RME_DIGIFACE_STATUS_REG3L 6 #define RME_DIGIFACE_STATUS_REG3H 7 #define RME_DIGIFACE_CTL_REG1 16 #define RME_DIGIFACE_CTL_REG2 18 /* Reg is overloaded, 0-7 for status halfwords or 16 or 18 for control registers #define RME_DIGIFACE_REGISTER(reg, mask) (((reg) << 16) | (mask)) #define RME_DIGIFACE_INVERT BIT(31) /* Nonconst helpers define field_get(_mask, _reg) (((_reg) & (_mask)) >> (ffs(_mask) - 1)) define field_prep(_mask, _val) (((_val) << (ffs(_mask) - 1)) & (_mask))", "kind": "function", "line": 3318, "name": "snd_rme_digiface_write_reg", "signature": "static int snd_rme_digiface_write_reg(struct snd_kcontrol *kcontrol, int item, u16 mask, u16 val)"}, {"kind": "function", "line": 3336, "name": "snd_rme_digiface_read_status", "signature": "static int snd_rme_digiface_read_status(struct snd_kcontrol *kcontrol, u32 status[4])"}, {"kind": "function", "line": 3360, "name": "snd_rme_digiface_get_status_val", "signature": "static int snd_rme_digiface_get_status_val(struct snd_kcontrol *kcontrol)"}, {"kind": "function", "line": 3398, "name": "snd_rme_digiface_rate_get", "signature": "static int snd_rme_digiface_rate_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t     struct snd_ctl_elem_..."}, {"kind": "function", "line": 3412, "name": "snd_rme_digiface_enum_get", "signature": "static int snd_rme_digiface_enum_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t     struct snd_ctl_elem_..."}, {"kind": "function", "line": 3424, "name": "snd_rme_digiface_enum_put", "signature": "static int snd_rme_digiface_enum_put(struct snd_kcontrol *kcontrol,\n\t\t\t\t     struct snd_ctl_elem_..."}, {"kind": "function", "line": 3438, "name": "snd_rme_digiface_current_sync_get", "signature": "static int snd_rme_digiface_current_sync_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t\t     struct snd_..."}, {"kind": "function", "line": 3450, "name": "snd_rme_digiface_sync_state_get", "signature": "static int snd_rme_digiface_sync_state_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t\t   struct snd_ctl_..."}, {"kind": "function", "line": 3473, "name": "snd_rme_digiface_format_info", "signature": "static int snd_rme_digiface_format_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t\tstruct snd_ctl_elem_i..."}, {"kind": "function", "line": 3484, "name": "snd_rme_digiface_sync_source_info", "signature": "static int snd_rme_digiface_sync_source_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t\t     struct snd_..."}, {"kind": "function", "line": 3495, "name": "snd_rme_digiface_rate_info", "signature": "static int snd_rme_digiface_rate_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t      struct snd_ctl_ele..."}, {"kind": "function", "line": 3684, "name": "snd_rme_digiface_controls_create", "signature": "static int snd_rme_digiface_controls_create(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 3791, "name": "snd_djm_get_label_caplevel_common", "signature": "static const char *snd_djm_get_label_caplevel_common(u16 wvalue)"}, {"doc": "Models like DJM-A9 or DJM-V10 have different capture levels than others", "kind": "function", "line": 3804, "name": "snd_djm_get_label_caplevel_high", "signature": "static const char *snd_djm_get_label_caplevel_high(u16 wvalue)"}, {"kind": "function", "line": 3816, "name": "snd_djm_get_label_cap_common", "signature": "static const char *snd_djm_get_label_cap_common(u16 wvalue)"}, {"doc": "The DJM-850 has different values for CD/LINE and LINE capture control options than the other DJM declared in this file.", "kind": "function", "line": 3849, "name": "snd_djm_get_label_cap_850", "signature": "static const char *snd_djm_get_label_cap_850(u16 wvalue)"}, {"kind": "function", "line": 3857, "name": "snd_djm_get_label_caplevel", "signature": "static const char *snd_djm_get_label_caplevel(u8 device_idx, u16 wvalue)"}, {"kind": "function", "line": 3866, "name": "snd_djm_get_label_cap", "signature": "static const char *snd_djm_get_label_cap(u8 device_idx, u16 wvalue)"}, {"kind": "function", "line": 3874, "name": "snd_djm_get_label_pb", "signature": "static const char *snd_djm_get_label_pb(u16 wvalue)"}, {"kind": "function", "line": 3884, "name": "snd_djm_get_label", "signature": "static const char *snd_djm_get_label(u8 device_idx, u16 wvalue, u16 windex)"}, {"kind": "function", "line": 4116, "name": "snd_djm_controls_info", "signature": "static int snd_djm_controls_info(struct snd_kcontrol *kctl,\n\t\t\t\t struct snd_ctl_elem_info *info)"}, {"kind": "function", "line": 4148, "name": "snd_djm_controls_update", "signature": "static int snd_djm_controls_update(struct usb_mixer_interface *mixer,\n\t\t\t\t   u8 device_idx, u8 gr..."}, {"kind": "function", "line": 4169, "name": "snd_djm_controls_get", "signature": "static int snd_djm_controls_get(struct snd_kcontrol *kctl,\n\t\t\t\tstruct snd_ctl_elem_value *elem)"}, {"kind": "function", "line": 4176, "name": "snd_djm_controls_put", "signature": "static int snd_djm_controls_put(struct snd_kcontrol *kctl, struct snd_ctl_elem_value *elem)"}, {"kind": "function", "line": 4193, "name": "snd_djm_controls_resume", "signature": "static int snd_djm_controls_resume(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 4203, "name": "snd_djm_controls_create", "signature": "static int snd_djm_controls_create(struct usb_mixer_interface *mixer,\n\t\t\t\t   const u8 device_idx)"}, {"kind": "function", "line": 4238, "name": "snd_usb_mixer_apply_create_quirk", "signature": "int snd_usb_mixer_apply_create_quirk(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 4420, "name": "snd_usb_mixer_resume_quirk", "signature": "void snd_usb_mixer_resume_quirk(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 4429, "name": "snd_usb_mixer_rc_memory_change", "signature": "void snd_usb_mixer_rc_memory_change(struct usb_mixer_interface *mixer,\n\t\t\t\t    int unitid)"}, {"kind": "function", "line": 4457, "name": "snd_dragonfly_quirk_db_scale", "signature": "static void snd_dragonfly_quirk_db_scale(struct usb_mixer_interface *mixer,\n\t\t\t\t\t struct usb_mixe..."}, {"doc": "standards. This function fixes nonstandard source names. By the time this function is called the control name should look like one of these: \"source names Playback Volume\" \"source names Playback Switch\" \"source names Capture Volume\" \"source names Capture Switch\" If any of the trigger words are found in the name then the name will be changed to: \"Headset Playback Volume\" \"Headset Playback Switch\" \"Headset Capture Volume\" \"Headset Capture Switch\" depending on the current suffix.", "kind": "function", "line": 4509, "name": "snd_fix_plt_name", "signature": "static void snd_fix_plt_name(struct snd_usb_audio *chip,\n\t\t\t     struct snd_ctl_elem_id *id)"}, {"kind": "function", "line": 4538, "name": "snd_usb_mixer_fu_apply_quirk", "signature": "void snd_usb_mixer_fu_apply_quirk(struct usb_mixer_interface *mixer,\n\t\t\t\t  struct usb_mixer_elem_..."}, {"kind": "macro", "line": 296, "name": "snd_audigy2nx_led_info"}, {"kind": "macro", "line": 539, "name": "SND_DUALSENSE_JACK_OUT_TERM_ID"}, {"kind": "macro", "line": 541, "name": "SND_DUALSENSE_JACK_IN_TERM_ID"}, {"kind": "macro", "line": 1118, "name": "_MAKE_NI_CONTROL"}, {"kind": "macro", "line": 2171, "name": "HDA_VERB_CMD"}, {"kind": "macro", "line": 2173, "name": "REALTEK_HDA_VALUE"}, {"kind": "macro", "line": 2175, "name": "REALTEK_HDA_SET"}, {"kind": "macro", "line": 2177, "name": "REALTEK_MANUAL_MODE"}, {"kind": "macro", "line": 2178, "name": "REALTEK_HDA_GET_OUT"}, {"kind": "macro", "line": 2179, "name": "REALTEK_HDA_GET_IN"}, {"kind": "macro", "line": 2180, "name": "REALTEK_AUDIO_FUNCTION_GROUP"}, {"kind": "macro", "line": 2182, "name": "REALTEK_LINE1"}, {"kind": "macro", "line": 2183, "name": "REALTEK_VENDOR_REGISTERS"}, {"kind": "macro", "line": 2184, "name": "REALTEK_HP_OUT"}, {"kind": "macro", "line": 2185, "name": "REALTEK_CBJ_CTRL2"}, {"kind": "macro", "line": 2187, "name": "REALTEK_JACK_INTERRUPT_NODE"}, {"kind": "macro", "line": 2189, "name": "REALTEK_MIC_FLAG"}, {"kind": "macro", "line": 2362, "name": "SND_RME_GET_STATUS1"}, {"kind": "macro", "line": 2364, "name": "SND_RME_GET_CURRENT_FREQ"}, {"kind": "macro", "line": 2365, "name": "SND_RME_CLK_SYSTEM_SHIFT"}, {"kind": "macro", "line": 2366, "name": "SND_RME_CLK_SYSTEM_MASK"}, {"kind": "macro", "line": 2367, "name": "SND_RME_CLK_AES_SHIFT"}, {"kind": "macro", "line": 2368, "name": "SND_RME_CLK_SPDIF_SHIFT"}, {"kind": "macro", "line": 2369, "name": "SND_RME_CLK_AES_SPDIF_MASK"}, {"kind": "macro", "line": 2370, "name": "SND_RME_CLK_SYNC_SHIFT"}, {"kind": "macro", "line": 2371, "name": "SND_RME_CLK_SYNC_MASK"}, {"kind": "macro", "line": 2372, "name": "SND_RME_CLK_FREQMUL_SHIFT"}, {"kind": "macro", "line": 2373, "name": "SND_RME_CLK_FREQMUL_MASK"}, {"kind": "macro", "line": 2374, "name": "SND_RME_CLK_SYSTEM"}, {"kind": "macro", "line": 2376, "name": "SND_RME_CLK_AES"}, {"kind": "macro", "line": 2378, "name": "SND_RME_CLK_SPDIF"}, {"kind": "macro", "line": 2380, "name": "SND_RME_CLK_SYNC"}, {"kind": "macro", "line": 2382, "name": "SND_RME_CLK_FREQMUL"}, {"kind": "macro", "line": 2384, "name": "SND_RME_CLK_AES_LOCK"}, {"kind": "macro", "line": 2385, "name": "SND_RME_CLK_AES_SYNC"}, {"kind": "macro", "line": 2386, "name": "SND_RME_CLK_SPDIF_LOCK"}, {"kind": "macro", "line": 2387, "name": "SND_RME_CLK_SPDIF_SYNC"}, {"kind": "macro", "line": 2388, "name": "SND_RME_SPDIF_IF_SHIFT"}, {"kind": "macro", "line": 2389, "name": "SND_RME_SPDIF_FORMAT_SHIFT"}, {"kind": "macro", "line": 2390, "name": "SND_RME_BINARY_MASK"}, {"kind": "macro", "line": 2391, "name": "SND_RME_SPDIF_IF"}, {"kind": "macro", "line": 2393, "name": "SND_RME_SPDIF_FORMAT"}, {"kind": "macro", "line": 2405, "name": "SND_RME_RATE_IDX_AES_SPDIF_NUM"}, {"kind": "macro", "line": 2743, "name": "SND_BBFPRO_CTL_REG_MASK"}, {"kind": "macro", "line": 2745, "name": "SND_BBFPRO_CTL_IDX_MASK"}, {"kind": "macro", "line": 2746, "name": "SND_BBFPRO_CTL_IDX_SHIFT"}, {"kind": "macro", "line": 2747, "name": "SND_BBFPRO_CTL_VAL_MASK"}, {"kind": "macro", "line": 2748, "name": "SND_BBFPRO_CTL_VAL_SHIFT"}, {"kind": "macro", "line": 2749, "name": "SND_BBFPRO_CTL_REG1_CLK_MASTER"}, {"kind": "macro", "line": 2750, "name": "SND_BBFPRO_CTL_REG1_CLK_OPTICAL"}, {"kind": "macro", "line": 2751, "name": "SND_BBFPRO_CTL_REG1_SPDIF_PRO"}, {"kind": "macro", "line": 2752, "name": "SND_BBFPRO_CTL_REG1_SPDIF_EMPH"}, {"kind": "macro", "line": 2753, "name": "SND_BBFPRO_CTL_REG1_SPDIF_OPTICAL"}, {"kind": "macro", "line": 2754, "name": "SND_BBFPRO_CTL_REG2_48V_AN1"}, {"kind": "macro", "line": 2755, "name": "SND_BBFPRO_CTL_REG2_48V_AN2"}, {"kind": "macro", "line": 2756, "name": "SND_BBFPRO_CTL_REG2_SENS_IN3"}, {"kind": "macro", "line": 2757, "name": "SND_BBFPRO_CTL_REG2_SENS_IN4"}, {"kind": "macro", "line": 2758, "name": "SND_BBFPRO_CTL_REG2_PAD_AN1"}, {"kind": "macro", "line": 2759, "name": "SND_BBFPRO_CTL_REG2_PAD_AN2"}, {"kind": "macro", "line": 2760, "name": "SND_BBFPRO_MIXER_MAIN_OUT_CH_OFFSET"}, {"kind": "macro", "line": 2762, "name": "SND_BBFPRO_MIXER_IDX_MASK"}, {"kind": "macro", "line": 2763, "name": "SND_BBFPRO_MIXER_VAL_MASK"}, {"kind": "macro", "line": 2764, "name": "SND_BBFPRO_MIXER_VAL_SHIFT"}, {"kind": "macro", "line": 2765, "name": "SND_BBFPRO_MIXER_VAL_MIN"}, {"kind": "macro", "line": 2766, "name": "SND_BBFPRO_MIXER_VAL_MAX"}, {"kind": "macro", "line": 2767, "name": "SND_BBFPRO_GAIN_CHANNEL_MASK"}, {"kind": "macro", "line": 2769, "name": "SND_BBFPRO_GAIN_CHANNEL_SHIFT"}, {"kind": "macro", "line": 2770, "name": "SND_BBFPRO_GAIN_VAL_MASK"}, {"kind": "macro", "line": 2771, "name": "SND_BBFPRO_GAIN_VAL_MIN"}, {"kind": "macro", "line": 2772, "name": "SND_BBFPRO_GAIN_VAL_MIC_MAX"}, {"kind": "macro", "line": 2773, "name": "SND_BBFPRO_GAIN_VAL_LINE_MAX"}, {"kind": "macro", "line": 2774, "name": "SND_BBFPRO_USBREQ_CTL_REG1"}, {"kind": "macro", "line": 2776, "name": "SND_BBFPRO_USBREQ_CTL_REG2"}, {"kind": "macro", "line": 2777, "name": "SND_BBFPRO_USBREQ_GAIN"}, {"kind": "macro", "line": 2778, "name": "SND_BBFPRO_USBREQ_MIXER"}, {"kind": "macro", "line": 3297, "name": "RME_DIGIFACE_READ_STATUS"}, {"kind": "macro", "line": 3299, "name": "RME_DIGIFACE_STATUS_REG0L"}, {"kind": "macro", "line": 3300, "name": "RME_DIGIFACE_STATUS_REG0H"}, {"kind": "macro", "line": 3301, "name": "RME_DIGIFACE_STATUS_REG1L"}, {"kind": "macro", "line": 3302, "name": "RME_DIGIFACE_STATUS_REG1H"}, {"kind": "macro", "line": 3303, "name": "RME_DIGIFACE_STATUS_REG2L"}, {"kind": "macro", "line": 3304, "name": "RME_DIGIFACE_STATUS_REG2H"}, {"kind": "macro", "line": 3305, "name": "RME_DIGIFACE_STATUS_REG3L"}, {"kind": "macro", "line": 3306, "name": "RME_DIGIFACE_STATUS_REG3H"}, {"kind": "macro", "line": 3307, "name": "RME_DIGIFACE_CTL_REG1"}, {"kind": "macro", "line": 3309, "name": "RME_DIGIFACE_CTL_REG2"}, {"kind": "macro", "line": 3312, "name": "RME_DIGIFACE_REGISTER"}, {"kind": "macro", "line": 3313, "name": "RME_DIGIFACE_INVERT"}, {"kind": "macro", "line": 3316, "name": "field_get"}, {"kind": "macro", "line": 3317, "name": "field_prep"}, {"kind": "macro", "line": 3715, "name": "SND_DJM_CAP_LINE"}, {"kind": "macro", "line": 3716, "name": "SND_DJM_CAP_CDLINE"}, {"kind": "macro", "line": 3717, "name": "SND_DJM_CAP_DIGITAL"}, {"kind": "macro", "line": 3718, "name": "SND_DJM_CAP_PHONO"}, {"kind": "macro", "line": 3719, "name": "SND_DJM_CAP_PREFADER"}, {"kind": "macro", "line": 3720, "name": "SND_DJM_CAP_PFADER"}, {"kind": "macro", "line": 3721, "name": "SND_DJM_CAP_XFADERA"}, {"kind": "macro", "line": 3722, "name": "SND_DJM_CAP_XFADERB"}, {"kind": "macro", "line": 3723, "name": "SND_DJM_CAP_MIC"}, {"kind": "macro", "line": 3724, "name": "SND_DJM_CAP_AUX"}, {"kind": "macro", "line": 3725, "name": "SND_DJM_CAP_RECOUT"}, {"kind": "macro", "line": 3726, "name": "SND_DJM_CAP_RECOUT_NOMIC"}, {"kind": "macro", "line": 3727, "name": "SND_DJM_CAP_NONE"}, {"kind": "macro", "line": 3728, "name": "SND_DJM_CAP_FXSEND"}, {"kind": "macro", "line": 3729, "name": "SND_DJM_CAP_CH1PFADER"}, {"kind": "macro", "line": 3730, "name": "SND_DJM_CAP_CH2PFADER"}, {"kind": "macro", "line": 3731, "name": "SND_DJM_CAP_CH3PFADER"}, {"kind": "macro", "line": 3732, "name": "SND_DJM_CAP_CH4PFADER"}, {"kind": "macro", "line": 3733, "name": "SND_DJM_CAP_EXT1SEND"}, {"kind": "macro", "line": 3734, "name": "SND_DJM_CAP_EXT2SEND"}, {"kind": "macro", "line": 3735, "name": "SND_DJM_CAP_CH1PREFADER"}, {"kind": "macro", "line": 3736, "name": "SND_DJM_CAP_CH2PREFADER"}, {"kind": "macro", "line": 3737, "name": "SND_DJM_CAP_CH3PREFADER"}, {"kind": "macro", "line": 3738, "name": "SND_DJM_CAP_CH4PREFADER"}, {"kind": "macro", "line": 3741, "name": "SND_DJM_PB_CH1"}, {"kind": "macro", "line": 3742, "name": "SND_DJM_PB_CH2"}, {"kind": "macro", "line": 3743, "name": "SND_DJM_PB_AUX"}, {"kind": "macro", "line": 3744, "name": "SND_DJM_WINDEX_CAP"}, {"kind": "macro", "line": 3746, "name": "SND_DJM_WINDEX_CAPLVL"}, {"kind": "macro", "line": 3747, "name": "SND_DJM_WINDEX_PB"}, {"kind": "macro", "line": 3750, "name": "SND_DJM_VALUE_MASK"}, {"kind": "macro", "line": 3751, "name": "SND_DJM_GROUP_MASK"}, {"kind": "macro", "line": 3752, "name": "SND_DJM_DEVICE_MASK"}, {"kind": "macro", "line": 3753, "name": "SND_DJM_GROUP_SHIFT"}, {"kind": "macro", "line": 3754, "name": "SND_DJM_DEVICE_SHIFT"}, {"kind": "macro", "line": 3758, "name": "SND_DJM_250MK2_IDX"}, {"kind": "macro", "line": 3759, "name": "SND_DJM_750_IDX"}, {"kind": "macro", "line": 3760, "name": "SND_DJM_850_IDX"}, {"kind": "macro", "line": 3761, "name": "SND_DJM_900NXS2_IDX"}, {"kind": "macro", "line": 3762, "name": "SND_DJM_750MK2_IDX"}, {"kind": "macro", "line": 3763, "name": "SND_DJM_450_IDX"}, {"kind": "macro", "line": 3764, "name": "SND_DJM_A9_IDX"}, {"kind": "macro", "line": 3765, "name": "SND_DJM_V10_IDX"}, {"kind": "macro", "line": 3766, "name": "SND_DJM_CTL"}, {"kind": "macro", "line": 3773, "name": "SND_DJM_DEVICE"}]}, {"doc": "==================================================================== VSL-DSP: Captura COMPLETA de tráfico USB del AudioBox ====================================================================", "id": "legacy/test.sh", "kind": "module", "label": "test.sh", "language": "sh", "sha256": "f0947b318a5d14e9", "symbol_count": 0, "symbols": []}, {"doc": "test_connection.c  include <stdio.h> include \"vsl_config.h\" include \"vsl_dsp_transport.h\" // Asumiendo que esta es la plantilla B", "id": "legacy/test_connection.c", "kind": "module", "label": "test_connection.c", "language": "c", "sha256": "55f1d89ed58a877f", "symbol_count": 1, "symbols": [{"doc": "include <stdio.h> include \"vsl_config.h\" include \"vsl_dsp_transport.h\" // Asumiendo que esta es la plantilla B", "kind": "function", "line": 6, "name": "main", "signature": "int main()"}]}, {"doc": "vsl_config.h (VERSION CORREGIDA)  ifndef VSL_CONFIG_H define VSL_CONFIG_H  include <stdint.h>  ======================================================= BLOQUEADORES CRÍTICOS (Hardware) ======================================================= define VSL_VENDOR_ID   0x194f define VSL_PRODUCT_ID  0x0101 define VSL_REPORT_ID   0x06  ======================================================= CONSTANTES CRÍTICAS VSL-DSP (Necesarias para la lógica) =======================================================  Factor de escala usado en la fórmula VSL (Confirmado en la PoC Python) define VSL_SCALE_FACTOR        1000.0f  Máximo valor codificado de 16 bits (0xFFFF) define VSL_MAX_ENCODED_INT     65535  define VSL_PACKET_SIZE         64      // 0x40 bytes define VSL_PAYLOAD_SIZE        5       // Byte 1 (ID LSB) a Byte 4 (Value MSB)  endif // VSL_CONFIG_H", "id": "legacy/vsl_config.h", "kind": "module", "label": "vsl_config.h", "language": "h", "sha256": "508da740df2b3805", "symbol_count": 8, "symbols": [{"kind": "macro", "line": 4, "name": "VSL_CONFIG_H"}, {"kind": "macro", "line": 11, "name": "VSL_VENDOR_ID"}, {"kind": "macro", "line": 12, "name": "VSL_PRODUCT_ID"}, {"kind": "macro", "line": 13, "name": "VSL_REPORT_ID"}, {"kind": "macro", "line": 20, "name": "VSL_SCALE_FACTOR"}, {"kind": "macro", "line": 23, "name": "VSL_MAX_ENCODED_INT"}, {"kind": "macro", "line": 24, "name": "VSL_PACKET_SIZE"}, {"kind": "macro", "line": 26, "name": "VSL_PAYLOAD_SIZE"}]}, {"id": "legacy/vsl_config.py", "kind": "module", "label": "vsl_config.py", "language": "py", "sha256": "f497ee94aa7dcc87", "symbol_count": 3, "symbols": [{"doc": "Estructura que replica exactamente VSL_Parameter del código C.\nTodos los campos están confirmados del desensamblado.", "kind": "class", "line": 40, "name": "VSLParameter", "signature": "class VSLParameter(NamedTuple)"}, {"doc": "Valida que todos los valores críticos estén configurados.\n\nReturns:\n    (is_valid, error_message)", "kind": "method", "line": 92, "name": "validate_configuration", "signature": "def validate_configuration()"}, {"doc": "Imprime el estado de la configuración con formato.", "kind": "method", "line": 116, "name": "print_configuration_status", "signature": "def print_configuration_status()"}]}, {"id": "legacy/vsl_core.py", "kind": "module", "label": "vsl_core.py", "language": "py", "sha256": "8a0f062d0a3852e1", "symbol_count": 5, "symbols": [{"doc": "Traducción de FUN_00132c90 (VSL_Encode_Gain en C).\n\nConvierte un valor lineal (0.0 - 1.0) a la escala exponencial del DSP.\n\nFórmula:\n    encoded = coeff_offset_A + coeff_C1 * exp(norm_factor * log_factor)\n\nArgs:\n    linear_value: Valor lineal de entrada (0.0 a 1.0)\n    param: Estructura de parámetros con coeficientes\n    \nReturns:\n    Valor codificado en float (rango: ~-10.0 a ~1000.0)\n    \nRaises:\n    ValueError: Si param es inválido", "kind": "function", "line": 16, "name": "vsl_encode_gain", "signature": "def vsl_encode_gain(linear_value, param)"}, {"doc": "Traducción de FUN_00132d00 (VSL_Map_Frequency en C).\n\nConvierte una posición lineal (0.0 - 1.0) a frecuencia logarítmica (Hz).\n\nArgs:\n    linear_position: Posición lineal (0.0 a 1.0)\n    param: Estructura de parámetros con rangos de frecuencia\n    \nReturns:\n    Frecuencia en Hz (ej: 20.0 a 20000.0)\n    \nRaises:\n    ValueError: Si las frecuencias son inválidas", "kind": "function", "line": 58, "name": "vsl_map_frequency", "signature": "def vsl_map_frequency(linear_position, param)"}, {"doc": "Traducción de VSL_Final_Encode_To_Int en C.\n\nConvierte el valor codificado float a entero de 16-bit para el DSP.\n\nArgs:\n    encoded_float: Valor float codificado (ej: -10.0 a 1000.0)\n    param: Estructura de parámetros con max_encoded_int\n    \nReturns:\n    Valor entero (0 a 65535)", "kind": "function", "line": 94, "name": "vsl_final_encode_to_int", "signature": "def vsl_final_encode_to_int(encoded_float, param)"}, {"doc": "Traducción de FUN_00132da8 (VSL_Decode_Frequency en C).\n\nConvierte una frecuencia real (Hz) a su posición lineal (0.0 - 1.0).\n\nArgs:\n    freq_hz_value: Frecuencia en Hz\n    param: Estructura de parámetros con rangos\n    \nReturns:\n    Posición lineal (0.0 a 1.0)\n    \nRaises:\n    ValueError: Si las frecuencias son inválidas", "kind": "function", "line": 127, "name": "vsl_decode_frequency", "signature": "def vsl_decode_frequency(freq_hz_value, param)"}, {"doc": "Valida la integridad de un VSLParameter.\n\nReturns:\n    (is_valid, error_message)", "kind": "function", "line": 170, "name": "validate_parameter", "signature": "def validate_parameter(param)"}]}, {"doc": "include \"vsl_dsp_logic.h\"  Declaración de la nueva función de envío", "id": "legacy/vsl_dsp_logic.c", "kind": "module", "label": "vsl_dsp_logic.c", "language": "c", "sha256": "13b21f9548f9c983", "symbol_count": 4, "symbols": [{"doc": "Implementación de FUN_00132c90", "kind": "function", "line": 11, "name": "VSL_Encode_Gain", "signature": "float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)"}, {"doc": "Implementación de FUN_00132d00", "kind": "function", "line": 29, "name": "VSL_Map_Frequency", "signature": "float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)"}, {"doc": "@brief Convierte el valor codificado en float a un entero sin signo para el firmware. @note Basado en la hipótesis común de DSP donde el rango flotante es 0.0 - 1000.0. Si el valor real es diferente, solo se debe cambiar la constante VSL_MAX_ENCODED_FLOAT.", "kind": "function", "line": 58, "name": "VSL_Final_Encode_To_Int", "signature": "uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)"}, {"doc": "Implementación de FUN_00132da8", "kind": "function", "line": 78, "name": "VSL_Decode_Frequency", "signature": "float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)"}]}, {"doc": "ifndef VSL_DSP_LOGIC_H define VSL_DSP_LOGIC_H  include <stdint.h> include <math.h> include <float.h> // Para fmaxf, fminf  Constante para la conversión de logaritmo natural (ln) a logaritmo base 2 (log2) 1 / ln(2) ≈ 1.442695 define VSL_INV_LN2 1.442695f  Estructura que almacena todos los coeficientes precalculados del DSP", "id": "legacy/vsl_dsp_logic.h", "kind": "module", "label": "vsl_dsp_logic.h", "language": "h", "sha256": "15b8b7ba4fac5a1f", "symbol_count": 2, "symbols": [{"kind": "macro", "line": 2, "name": "VSL_DSP_LOGIC_H"}, {"kind": "macro", "line": 10, "name": "VSL_INV_LN2"}]}, {"doc": "vsl_dsp_transport.c (Añadir la Plantilla B completa aquí)  include <stdio.h> include <string.h> include <math.h> include <hidapi/hidapi.h> include <stdlib.h> include \"vsl_config.h\" include \"vsl_dsp_transport.h\"  Handle de Singleton (Regla #5: Diseño Escalable)", "id": "legacy/vsl_dsp_transport.c", "kind": "module", "label": "vsl_dsp_transport.c", "language": "c", "sha256": "1b24ae3897a9279c", "symbol_count": 5, "symbols": [{"doc": "... (las inclusiones y el singleton handle) ...", "kind": "function", "line": 22, "name": "VSL_Init_Device", "signature": "int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)"}, {"kind": "function", "line": 69, "name": "VSL_Close_Device", "signature": "void VSL_Close_Device(void)"}, {"kind": "function", "line": 78, "name": "VSL_Get_Device_Handle", "signature": "hid_device* VSL_Get_Device_Handle(void)"}, {"doc": "@brief Función de I/O real usando HIDAPI. @note DEBE SER REEMPLAZADA con la lógica específica de tu dispositivo (Report ID, longitud, etc.)", "kind": "function", "line": 97, "name": "FUN_Send_Packet", "signature": "void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length)"}, {"doc": "Implementación de la función de construcción y envío", "kind": "function", "line": 140, "name": "VSL_Build_And_Send_Packet", "signature": "void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float)"}]}, {"doc": "vsl_dsp_transport.h (CORREGIDO)  ifndef VSL_DSP_TRANSPORT_H define VSL_DSP_TRANSPORT_H  include <stdint.h> include <stddef.h> include <hidapi/hidapi.h> include \"vsl_config.h\" // Solo incluye la configuración  Estructura de Paquete: Sin 'header' (lo quitaste en la estructura typedef)", "id": "legacy/vsl_dsp_transport.h", "kind": "module", "label": "vsl_dsp_transport.h", "language": "h", "sha256": "ec937032c6f9b1f5", "symbol_count": 1, "symbols": [{"kind": "macro", "line": 4, "name": "VSL_DSP_TRANSPORT_H"}]}, {"id": "legacy/vsl_hid_io.py", "kind": "module", "label": "vsl_hid_io.py", "language": "py", "sha256": "a7edc02a249a85db", "symbol_count": 9, "symbols": [{"doc": "Gestor de dispositivo VSL-DSP con patrón Singleton.\nManeja la conexión HID y envío de paquetes.", "kind": "class", "line": 31, "name": "VSLDevice", "signature": "class VSLDevice"}, {"doc": "Enumera todos los dispositivos HID conectados.\nÚtil para descubrir VID/PID del hardware.", "kind": "method", "line": 149, "name": "enumerate_vsl_devices", "signature": "def enumerate_vsl_devices()"}, {"kind": "method", "line": 39, "name": "__new__", "signature": "def __new__(cls)"}, {"kind": "method", "line": 45, "name": "__init__", "signature": "def __init__(self)"}, {"doc": "Abre la conexión con el dispositivo VSL.\n\nReturns:\n    True si la conexión fue exitosa, False en caso contrario", "kind": "method", "line": 59, "name": "open", "signature": "def open(self)"}, {"doc": "Cierra la conexión con el dispositivo.", "kind": "method", "line": 90, "name": "close", "signature": "def close(self)"}, {"doc": "Envía un paquete VSL al dispositivo.\n\nArgs:\n    packet: VSLPacket a enviar\n    \nReturns:\n    True si el envío fue exitoso", "kind": "method", "line": 101, "name": "send_packet", "signature": "def send_packet(self, packet)"}, {"doc": "Context manager entry.", "kind": "method", "line": 139, "name": "__enter__", "signature": "def __enter__(self)"}, {"doc": "Context manager exit.", "kind": "method", "line": 144, "name": "__exit__", "signature": "def __exit__(self, exc_type, exc_val, exc_tb)"}]}, {"id": "legacy/vsl_poc_main.py", "kind": "module", "label": "vsl_poc_main.py", "language": "py", "sha256": "8723ac23990f418d", "symbol_count": 7, "symbols": [{"doc": "Test de codificación de ganancia con tabla de validación.", "kind": "function", "line": 43, "name": "test_gain_encoding", "signature": "def test_gain_encoding()"}, {"doc": "Test de mapeo logarítmico de frecuencias.", "kind": "function", "line": 72, "name": "test_frequency_mapping", "signature": "def test_frequency_mapping()"}, {"doc": "Test de construcción de paquetes HID.", "kind": "function", "line": 92, "name": "test_packet_construction", "signature": "def test_packet_construction()"}, {"doc": "Test de casos extremos y validación de errores.", "kind": "function", "line": 150, "name": "test_edge_cases", "signature": "def test_edge_cases()"}, {"doc": "Simula el flujo completo: Usuario → Encoding → Paquete.", "kind": "function", "line": 197, "name": "run_full_workflow", "signature": "def run_full_workflow()"}, {"doc": "Imprime resumen del estado del proyecto.", "kind": "function", "line": 229, "name": "print_summary", "signature": "def print_summary()"}, {"doc": "Función principal de la PoC.", "kind": "function", "line": 266, "name": "main", "signature": "def main()"}]}, {"doc": "PASO 1: (Fuera de este entorno) Capturar tráfico USB con Wireshark/usbmon Guardar como: audiobox_full_sweep.pcap  PASO 2: Ejecutar el analizador python3 vsl_protocol_analyzer.py audiobox_full_sweep.pcap", "id": "legacy/vsl_protocol_analyzer.py", "kind": "module", "label": "vsl_protocol_analyzer.py", "language": "py", "sha256": "f87cb90ff4e9b30f", "symbol_count": 7, "symbols": [{"doc": "Parámetros DSP descifrados con coeficientes y rangos.", "kind": "class", "line": 28, "name": "VSLParameter", "signature": "class VSLParameter"}, {"doc": "Simula VSL_Decode_Gain. Convierte un entero a un valor de usuario (dB).\n\nFórmula inversa confirmada: \nuser_value = (log2(encoded_float * range_span) / log_factor) + min_db\n\nUsaremos la simplificación de mapeo lineal para la PoC, ya que el valor \nconfirmado (40793) implica que no es un simple mapeo lineal \n(40793 / 65535 = 0.6225). La fórmula real de decodificación logarítmica\nes más compleja. Para la PoC, aplicamos la inversa de la fórmula \nlogarítmica simplificada que nos dio los resultados válidos:", "kind": "method", "line": 67, "name": "reverse_map_gain", "signature": "def reverse_map_gain(encoded_value, param)"}, {"doc": "Simula VSL_Decode_Frequency. Convierte un entero a frecuencia (Hz).\n\nFórmula inversa: exp2f(log2_min + pos * (log2_max - log2_min))", "kind": "method", "line": 95, "name": "reverse_map_frequency", "signature": "def reverse_map_frequency(encoded_value, param)"}, {"doc": "Dirige la decodificación al motor DSP correcto.", "kind": "method", "line": 115, "name": "get_decoded_value", "signature": "def get_decoded_value(encoded_value, param_id)"}, {"doc": "Decodifica el payload de 64 bytes. (Regla #3: Seguridad)", "kind": "method", "line": 140, "name": "decode_vsl_packet", "signature": "def decode_vsl_packet(data)"}, {"doc": "Carga un archivo PCAP y filtra los paquetes USB VSL.", "kind": "method", "line": 173, "name": "analyze_pcap", "signature": "def analyze_pcap(pcap_file)"}, {"kind": "method", "line": 30, "name": "__init__", "signature": "def __init__(self, dsp_id, name, type_unit, min_map, max_map, coeff_A, coeff_C1, log_factor)"}]}, {"id": "legacy/vsl_transport.py", "kind": "module", "label": "vsl_transport.py", "language": "py", "sha256": "df5d1b7a52953df7", "symbol_count": 8, "symbols": [{"doc": "Representa un paquete HID VSL-DSP de 64 bytes.\nImplementa construcción y validación con seguridad de tipos.", "kind": "class", "line": 15, "name": "VSLPacket", "signature": "class VSLPacket"}, {"doc": "Construye un paquete con manejo de errores.\n\nArgs:\n    param: Parámetro DSP\n    encoded_value: Valor codificado (0-65535)\n    \nReturns:\n    VSLPacket o None si hay error", "kind": "method", "line": 141, "name": "build_packet_safe", "signature": "def build_packet_safe(param, encoded_value)"}, {"doc": "Construye un paquete VSL-DSP.\n\nArgs:\n    param_id: ID del parámetro DSP (16-bit, ej: 0x1A01)\n    encoded_value: Valor codificado (16-bit, 0-65535)\n    report_id: Report ID HID (8-bit, None usa configuración global)\n    \nRaises:\n    ValueError: Si los valores están fuera de rango\n    RuntimeError: Si VSL_REPORT_ID no está configurado y report_id es None", "kind": "method", "line": 21, "name": "__init__", "signature": "def __init__(self, param_id, encoded_value, report_id)"}, {"doc": "Construye el buffer de 64 bytes según el protocolo VSL-DSP.\n\nEstructura (Little-Endian):\n  [0]    : Report ID\n  [1-2]  : Parameter ID (LSB, MSB)\n  [3-4]  : Encoded Value (LSB, MSB)\n  [5-63] : Padding (0x00)\n\nReturns:\n    bytearray de 64 bytes", "kind": "method", "line": 58, "name": "_build_buffer", "signature": "def _build_buffer(self)"}, {"doc": "Retorna el buffer como bytes inmutables.", "kind": "method", "line": 89, "name": "buffer", "signature": "def buffer(self)"}, {"doc": "Genera un hex dump del paquete para debugging.\n\nArgs:\n    num_bytes: Número de bytes a mostrar (default: 8)\n    \nReturns:\n    String con formato hexadecimal", "kind": "method", "line": 93, "name": "hex_dump", "signature": "def hex_dump(self, num_bytes)"}, {"doc": "Valida la integridad del paquete.\n\nReturns:\n    (is_valid, message)", "kind": "method", "line": 106, "name": "validate", "signature": "def validate(self)"}, {"kind": "method", "line": 133, "name": "__repr__", "signature": "def __repr__(self)"}]}, {"doc": "include <stdio.h> include <stdlib.h> include <string.h> include <math.h> include <stdint.h> include \"vsl_dsp_logic.h\" include \"vsl_dsp_transport.h\" include \"vsl_config.h\"", "id": "src/vsl_cli.c", "kind": "module", "label": "vsl_cli.c", "language": "c", "sha256": "5c66a9cd1fa003cb", "symbol_count": 9, "symbols": [{"kind": "function", "line": 57, "name": "print_usage", "signature": "static void print_usage(FILE *fp, const char *prog)"}, {"kind": "function", "line": 83, "name": "print_version", "signature": "static void print_version(void)"}, {"kind": "function", "line": 90, "name": "print_list", "signature": "static void print_list(uint16_t product_id)"}, {"kind": "function", "line": 109, "name": "lookup_coeffs_by_param_id", "signature": "static const VSL_Parameter *\nlookup_coeffs_by_param_id(uint16_t param_id)"}, {"kind": "function", "line": 119, "name": "find_entry_by_name", "signature": "static const ParamEntry *\nfind_entry_by_name(const char *name)"}, {"kind": "function", "line": 129, "name": "do_send", "signature": "static int do_send(uint16_t product_id,\n                   uint16_t param_id,\n                   ..."}, {"kind": "function", "line": 167, "name": "do_send_freq", "signature": "static int do_send_freq(uint16_t product_id,\n                        uint16_t param_id,\n         ..."}, {"kind": "function", "line": 204, "name": "main", "signature": "int main(int argc, char *argv[])"}, {"kind": "macro", "line": 47, "name": "MAX_CHANNELS"}]}, {"doc": "ifndef VSL_CONFIG_H define VSL_CONFIG_H  include <stdint.h> include <stddef.h>  ifdef __cplusplus", "id": "src/vsl_config.h", "kind": "module", "label": "vsl_config.h", "language": "h", "sha256": "e4ca191b92f5e4e3", "symbol_count": 11, "symbols": [{"kind": "function", "line": 35, "name": "VSL_ModelLookup", "signature": "static inline const VSL_ModelInfo *\nVSL_ModelLookup(uint16_t pid)"}, {"kind": "function", "line": 47, "name": "VSL_ModelLookupByTag", "signature": "static inline const VSL_ModelInfo *\nVSL_ModelLookupByTag(const char *tag)"}, {"kind": "macro", "line": 2, "name": "VSL_CONFIG_H"}, {"kind": "macro", "line": 10, "name": "VSL_VENDOR_ID"}, {"kind": "macro", "line": 12, "name": "VSL_PRODUCT_ID_22VSL"}, {"kind": "macro", "line": 13, "name": "VSL_PRODUCT_ID_44VSL"}, {"kind": "macro", "line": 14, "name": "VSL_PRODUCT_ID_1818VSL"}, {"kind": "macro", "line": 15, "name": "VSL_REPORT_ID"}, {"kind": "macro", "line": 17, "name": "VSL_PACKET_SIZE"}, {"kind": "macro", "line": 18, "name": "VSL_MIDI_IFACE"}, {"kind": "macro", "line": 19, "name": "VSL_EP_MIDI_OUT"}]}, {"doc": "include \"vsl_dsp_logic.h\"", "id": "src/vsl_dsp_logic.c", "kind": "module", "label": "vsl_dsp_logic.c", "language": "c", "sha256": "b9d189bd08d9ffeb", "symbol_count": 5, "symbols": [{"doc": "include \"vsl_dsp_logic.h\"", "kind": "function", "line": 2, "name": "VSL_Encode_Gain", "signature": "float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)"}, {"kind": "function", "line": 15, "name": "VSL_Decode_Gain", "signature": "float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param)"}, {"kind": "function", "line": 49, "name": "VSL_Map_Frequency", "signature": "float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)"}, {"kind": "function", "line": 65, "name": "VSL_Final_Encode_To_Int", "signature": "uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)"}, {"kind": "function", "line": 75, "name": "VSL_Decode_Frequency", "signature": "float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)"}]}, {"doc": "ifndef VSL_DSP_LOGIC_H define VSL_DSP_LOGIC_H  include <stdint.h> include <math.h> include <float.h>  define VSL_INV_LN2            1.442695f define VSL_MAX_ENCODED_FLOAT  1000.0f", "id": "src/vsl_dsp_logic.h", "kind": "module", "label": "vsl_dsp_logic.h", "language": "h", "sha256": "5e15831d001a0613", "symbol_count": 3, "symbols": [{"kind": "macro", "line": 2, "name": "VSL_DSP_LOGIC_H"}, {"kind": "macro", "line": 7, "name": "VSL_INV_LN2"}, {"kind": "macro", "line": 9, "name": "VSL_MAX_ENCODED_FLOAT"}]}, {"doc": "include \"vsl_dsp_transport.h\" include <stdio.h> include <stdlib.h> include <string.h> include <libusb-1.0/libusb.h>", "id": "src/vsl_dsp_transport.c", "kind": "module", "label": "vsl_dsp_transport.c", "language": "c", "sha256": "44375ed1f26ebef1", "symbol_count": 4, "symbols": [{"kind": "struct", "line": 7, "name": "vsl_device"}, {"kind": "function", "line": 12, "name": "VSL_Init_Device", "signature": "vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)"}, {"kind": "function", "line": 44, "name": "VSL_Close_Device", "signature": "void VSL_Close_Device(vsl_device_handle handle)"}, {"kind": "function", "line": 60, "name": "VSL_Send_Parameter", "signature": "int VSL_Send_Parameter(vsl_device_handle handle,\n                       uint16_t dsp_param_id,\n  ..."}]}, {"doc": "ifndef VSL_DSP_TRANSPORT_H define VSL_DSP_TRANSPORT_H  include <stdint.h> include \"vsl_dsp_logic.h\" include \"vsl_config.h\"  ifdef __cplusplus", "id": "src/vsl_dsp_transport.h", "kind": "module", "label": "vsl_dsp_transport.h", "language": "h", "sha256": "24f1b10f5325e583", "symbol_count": 1, "symbols": [{"kind": "macro", "line": 2, "name": "VSL_DSP_TRANSPORT_H"}]}, {"doc": "SPDX-License-Identifier: GPL-2.0-or-later", "id": "tests/test_audiobox_vsl.c", "kind": "module", "label": "test_audiobox_vsl.c", "language": "c", "sha256": "2692ba803c7658a0", "symbol_count": 10, "symbols": [{"kind": "function", "line": 30, "name": "test_supported_models_table_shape", "signature": "static void test_supported_models_table_shape(void **state)"}, {"kind": "function", "line": 45, "name": "test_model_pids_match_table", "signature": "static void test_model_pids_match_table(void **state)"}, {"kind": "function", "line": 54, "name": "test_lookup_returns_22_vsl", "signature": "static void test_lookup_returns_22_vsl(void **state)"}, {"kind": "function", "line": 64, "name": "test_lookup_returns_44_vsl", "signature": "static void test_lookup_returns_44_vsl(void **state)"}, {"kind": "function", "line": 74, "name": "test_lookup_returns_1818_vsl", "signature": "static void test_lookup_returns_1818_vsl(void **state)"}, {"kind": "function", "line": 84, "name": "test_lookup_returns_null_for_unknown_pid", "signature": "static void test_lookup_returns_null_for_unknown_pid(void **state)"}, {"kind": "function", "line": 94, "name": "test_lookup_handles_full_pid_range", "signature": "static void test_lookup_handles_full_pid_range(void **state)"}, {"kind": "function", "line": 114, "name": "test_table_pids_are_unique", "signature": "static void test_table_pids_are_unique(void **state)"}, {"kind": "function", "line": 125, "name": "test_table_product_names_non_empty", "signature": "static void test_table_product_names_non_empty(void **state)"}, {"kind": "function", "line": 135, "name": "main", "signature": "int main(void)"}]}, {"doc": "include <stdarg.h> include <stddef.h> include <setjmp.h> include <cmocka.h> include <math.h> include <float.h> include \"vsl_dsp_logic.h\"", "id": "tests/test_vsl_dsp_logic.c", "kind": "module", "label": "test_vsl_dsp_logic.c", "language": "c", "sha256": "47fd077dcc7b4ba1", "symbol_count": 15, "symbols": [{"doc": "include <stdarg.h> include <stddef.h> include <setjmp.h> include <cmocka.h> include <math.h> include <float.h> include \"vsl_dsp_logic.h\"", "kind": "function", "line": 8, "name": "test_VSL_Encode_Gain", "signature": "static void test_VSL_Encode_Gain(void **state)"}, {"kind": "function", "line": 35, "name": "test_VSL_Map_Frequency", "signature": "static void test_VSL_Map_Frequency(void **state)"}, {"kind": "function", "line": 67, "name": "test_VSL_Decode_Frequency", "signature": "static void test_VSL_Decode_Frequency(void **state)"}, {"kind": "function", "line": 99, "name": "test_VSL_Final_Encode_To_Int", "signature": "static void test_VSL_Final_Encode_To_Int(void **state)"}, {"kind": "function", "line": 127, "name": "test_VSL_Decode_Gain_c1_zero", "signature": "static void test_VSL_Decode_Gain_c1_zero(void **state)"}, {"kind": "function", "line": 145, "name": "test_VSL_Decode_Gain_log_factor_zero", "signature": "static void test_VSL_Decode_Gain_log_factor_zero(void **state)"}, {"kind": "function", "line": 163, "name": "test_VSL_Decode_Gain_encoded_below_offset", "signature": "static void test_VSL_Decode_Gain_encoded_below_offset(void **state)"}, {"kind": "function", "line": 182, "name": "test_VSL_Decode_Gain_range_zero", "signature": "static void test_VSL_Decode_Gain_range_zero(void **state)"}, {"kind": "function", "line": 200, "name": "test_VSL_Decode_Gain_roundtrip_mid", "signature": "static void test_VSL_Decode_Gain_roundtrip_mid(void **state)"}, {"kind": "function", "line": 220, "name": "test_VSL_Decode_Gain_roundtrip_extremes", "signature": "static void test_VSL_Decode_Gain_roundtrip_extremes(void **state)"}, {"kind": "function", "line": 241, "name": "test_VSL_Decode_Gain_roundtrip_75", "signature": "static void test_VSL_Decode_Gain_roundtrip_75(void **state)"}, {"kind": "function", "line": 261, "name": "test_VSL_Decode_Gain_custom_range_roundtrip", "signature": "static void test_VSL_Decode_Gain_custom_range_roundtrip(void **state)"}, {"kind": "function", "line": 289, "name": "test_VSL_Decode_Gain_encoded_equals_offset", "signature": "static void test_VSL_Decode_Gain_encoded_equals_offset(void **state)"}, {"kind": "function", "line": 308, "name": "test_VSL_Decode_Gain_clamps_output", "signature": "static void test_VSL_Decode_Gain_clamps_output(void **state)"}, {"kind": "function", "line": 328, "name": "main", "signature": "int main(void)"}]}, {"doc": "define _GNU_SOURCE  include \"vc_alsa.h\" include \"vc_stream.h\"  include <alloca.h> include <alsa/asoundlib.h> include <stdio.h> include <stdlib.h> include <string.h> include <math.h>", "id": "voicecloak/src/vc_alsa.c", "kind": "module", "label": "vc_alsa.c", "language": "c", "sha256": "a649e94f40f4a979", "symbol_count": 7, "symbols": [{"kind": "function", "line": 19, "name": "fmt_bps", "signature": "static size_t fmt_bps(snd_pcm_format_t f)"}, {"kind": "function", "line": 28, "name": "open_stream", "signature": "static int open_stream(vc_pcm_t *s, const char *dev, snd_pcm_stream_t dir,\n                      ..."}, {"kind": "function", "line": 98, "name": "raw_to_mono", "signature": "static void raw_to_mono(const unsigned char *raw, float *mono,\n                        snd_pcm_uf..."}, {"kind": "function", "line": 129, "name": "mono_to_raw", "signature": "static void mono_to_raw(unsigned char *raw, const float *mono,\n                        snd_pcm_uf..."}, {"kind": "function", "line": 162, "name": "vc_alsa_list", "signature": "int vc_alsa_list(void)"}, {"kind": "function", "line": 188, "name": "vc_alsa_run", "signature": "int vc_alsa_run(const vc_alsa_cfg_t *cfg)"}, {"kind": "macro", "line": 1, "name": "_GNU_SOURCE"}]}, {"doc": "ifndef VC_ALSA_H define VC_ALSA_H  include <stddef.h> include <stdint.h> include <signal.h> include \"vc_stream.h\"  ifdef __cplusplus", "id": "voicecloak/src/vc_alsa.h", "kind": "module", "label": "vc_alsa.h", "language": "h", "sha256": "2a5c489c45d444bd", "symbol_count": 1, "symbols": [{"kind": "macro", "line": 2, "name": "VC_ALSA_H"}]}, {"doc": "include \"vc_wav.h\" include \"vc_dsp.h\" include \"vc_crypto.h\" include <stdio.h> include <stdlib.h> include <string.h> include <time.h>", "id": "voicecloak/src/vc_cli.c", "kind": "module", "label": "vc_cli.c", "language": "c", "sha256": "4cc15ca8592ae12d", "symbol_count": 5, "symbols": [{"doc": "include \"vc_wav.h\" include \"vc_dsp.h\" include \"vc_crypto.h\" include <stdio.h> include <stdlib.h> include <string.h> include <time.h>", "kind": "function", "line": 8, "name": "print_usage", "signature": "static void print_usage(const char *prog)"}, {"kind": "function", "line": 40, "name": "cmd_keygen", "signature": "static int cmd_keygen(void)"}, {"kind": "function", "line": 52, "name": "cmd_cloak", "signature": "static int cmd_cloak(const char *pubkey_path,\n                     const char *in_path, const cha..."}, {"kind": "function", "line": 141, "name": "cmd_info", "signature": "static int cmd_info(const char *path)"}, {"kind": "function", "line": 176, "name": "main", "signature": "int main(int argc, char *argv[])"}]}, {"doc": "include \"vc_crypto.h\" include <stdio.h> include <stdlib.h> include <string.h> include <openssl/evp.h> include <openssl/pem.h> include <openssl/rsa.h> include <openssl/rand.h> include <openssl/err.h> include <openssl/hmac.h>", "id": "voicecloak/src/vc_crypto.c", "kind": "module", "label": "vc_crypto.c", "language": "c", "sha256": "b2bae229104fa609", "symbol_count": 10, "symbols": [{"doc": "int i; for (i = 0; i < 3; ++i) { unsigned int outlen = 32; unsigned char data[64]; size_t data_len = info_lens[i] + 1; memcpy(data, infos[i], info_lens[i]); data[info_lens[i]] = (unsigned char)0x01; if (!HMAC(EVP_sha256(), prk, 32, data, data_len, outputs[i], &outlen)) return -1; } return 0; } /* PRNG: AES-256-CTR using OpenSSL EVP", "kind": "struct", "line": 136, "name": "vc_prng_s"}, {"doc": "include \"vc_crypto.h\" include <stdio.h> include <stdlib.h> include <string.h> include <openssl/evp.h> include <openssl/pem.h> include <openssl/rsa.h> include <openssl/rand.h> include <openssl/err.h> include <openssl/hmac.h>", "kind": "function", "line": 11, "name": "openssl_init", "signature": "static void openssl_init(void)"}, {"kind": "function", "line": 16, "name": "vc_crypto_keygen", "signature": "int vc_crypto_keygen(const char *pubkey_path, const char *privkey_path)"}, {"kind": "function", "line": 46, "name": "vc_crypto_seal", "signature": "int vc_crypto_seal(const char *pubkey_path,\n                   const unsigned char *seed, size_t ..."}, {"kind": "function", "line": 70, "name": "vc_crypto_unseal", "signature": "int vc_crypto_unseal(const char *privkey_path,\n                     const unsigned char *enc, siz..."}, {"kind": "function", "line": 95, "name": "vc_crypto_derive_seeds", "signature": "int vc_crypto_derive_seeds(const unsigned char *master_seed, size_t seed_len,\n                   ..."}, {"kind": "function", "line": 142, "name": "vc_prng_create", "signature": "vc_prng_t *vc_prng_create(const unsigned char *seed)"}, {"kind": "function", "line": 156, "name": "vc_prng_destroy", "signature": "void vc_prng_destroy(vc_prng_t *p)"}, {"kind": "function", "line": 163, "name": "vc_prng_fill", "signature": "void vc_prng_fill(vc_prng_t *p, unsigned char *buf, size_t len)"}, {"kind": "function", "line": 183, "name": "vc_prng_float", "signature": "float vc_prng_float(vc_prng_t *p, float low, float high)"}]}, {"doc": "ifndef VC_CRYPTO_H define VC_CRYPTO_H  include <stddef.h> include <stdint.h>  ifdef __cplusplus", "id": "voicecloak/src/vc_crypto.h", "kind": "module", "label": "vc_crypto.h", "language": "h", "sha256": "4b6796a093a15928", "symbol_count": 7, "symbols": [{"kind": "macro", "line": 2, "name": "VC_CRYPTO_H"}, {"kind": "macro", "line": 10, "name": "VC_CRYPTO_SEED_BYTES"}, {"kind": "macro", "line": 12, "name": "VC_CRYPTO_KEY_BYTES"}, {"kind": "macro", "line": 13, "name": "VC_PITCH_SEED_BYTES"}, {"kind": "macro", "line": 14, "name": "VC_FORMANT_SEED_BYTES"}, {"kind": "macro", "line": 15, "name": "VC_SPECTRAL_SEED_BYTES"}, {"kind": "macro", "line": 16, "name": "VC_TOTAL_SEED_BYTES"}]}, {"doc": "include \"vc_dsp.h\" include \"vc_stft.h\" include \"vc_crypto.h\" include <stdlib.h> include <string.h> include <math.h> include <float.h>  define VC_FFT_SIZE 2048U define VC_HOP_SIZE  (VC_FFT_SIZE / 4)", "id": "voicecloak/src/vc_dsp.c", "kind": "module", "label": "vc_dsp.c", "language": "c", "sha256": "7fc2c4f9bde14a19", "symbol_count": 11, "symbols": [{"doc": "define VC_FFT_SIZE 2048U define VC_HOP_SIZE  (VC_FFT_SIZE / 4)", "kind": "function", "line": 11, "name": "stft_process", "signature": "static int stft_process(const float *samples, size_t num_samples,\n                        float *..."}, {"kind": "function", "line": 20, "name": "stft_reconstruct", "signature": "static int stft_reconstruct(const float *mag, const float *phase,\n                            siz..."}, {"kind": "function", "line": 30, "name": "compute_out_len", "signature": "static size_t compute_out_len(size_t nframes, size_t hop)"}, {"kind": "function", "line": 34, "name": "vc_dsp_pitch_shift", "signature": "int vc_dsp_pitch_shift(const float *samples, size_t num_samples,\n                       uint32_t ..."}, {"kind": "function", "line": 90, "name": "vc_dsp_formant_shift", "signature": "int vc_dsp_formant_shift(const float *samples, size_t num_samples,\n                         uint3..."}, {"kind": "function", "line": 160, "name": "vc_dsp_spectral_scramble", "signature": "int vc_dsp_spectral_scramble(const float *samples, size_t num_samples,\n                          ..."}, {"kind": "function", "line": 233, "name": "trim_edges", "signature": "static void trim_edges(float **buf, size_t *len)"}, {"kind": "function", "line": 254, "name": "normalize_rms", "signature": "static void normalize_rms(const float *in, size_t in_len,\n                          float *out, s..."}, {"kind": "function", "line": 271, "name": "vc_dsp_cloak", "signature": "int vc_dsp_cloak(const float *samples, size_t num_samples,\n                 uint32_t sample_rate,..."}, {"kind": "macro", "line": 8, "name": "VC_FFT_SIZE"}, {"kind": "macro", "line": 10, "name": "VC_HOP_SIZE"}]}, {"doc": "ifndef VC_DSP_H define VC_DSP_H  include <stddef.h> include <stdint.h>  ifdef __cplusplus", "id": "voicecloak/src/vc_dsp.h", "kind": "module", "label": "vc_dsp.h", "language": "h", "sha256": "2a6e8613e457041f", "symbol_count": 1, "symbols": [{"kind": "macro", "line": 2, "name": "VC_DSP_H"}]}, {"doc": "include \"vc_fft.h\" include <math.h> include <string.h> include <stdlib.h>  ifndef M_PI define M_PI 3.14159265358979323846f endif", "id": "voicecloak/src/vc_fft.c", "kind": "module", "label": "vc_fft.c", "language": "c", "sha256": "d14302782b27c70e", "symbol_count": 4, "symbols": [{"doc": "ifndef M_PI define M_PI 3.14159265358979323846f endif", "kind": "function", "line": 9, "name": "bit_reverse", "signature": "static unsigned int bit_reverse(unsigned int x, unsigned int bits)"}, {"kind": "function", "line": 19, "name": "bit_reverse_reorder", "signature": "static void bit_reverse_reorder(size_t n, float *real, float *imag)"}, {"kind": "function", "line": 35, "name": "vc_fft", "signature": "void vc_fft(size_t n, float *real, float *imag, int inverse)"}, {"kind": "macro", "line": 7, "name": "M_PI"}]}, {"doc": "ifndef VC_FFT_H define VC_FFT_H  include <stddef.h>  ifdef __cplusplus", "id": "voicecloak/src/vc_fft.h", "kind": "module", "label": "vc_fft.h", "language": "h", "sha256": "0b0d782fdb6ceac3", "symbol_count": 1, "symbols": [{"kind": "macro", "line": 2, "name": "VC_FFT_H"}]}, {"doc": "include \"vc_rt.h\" include <stdlib.h> include <string.h> include <math.h>  ifndef M_PI define M_PI 3.14159265358979323846 endif", "id": "voicecloak/src/vc_rt.c", "kind": "module", "label": "vc_rt.c", "language": "c", "sha256": "5af4cef8a2ad9a30", "symbol_count": 9, "symbols": [{"kind": "struct", "line": 10, "name": "vc_rt_ctx_s"}, {"kind": "function", "line": 22, "name": "vc_rt_create", "signature": "vc_rt_ctx_t *vc_rt_create(size_t nbins, vc_rt_params_t params)"}, {"kind": "function", "line": 42, "name": "vc_rt_destroy", "signature": "void vc_rt_destroy(vc_rt_ctx_t *c)"}, {"kind": "function", "line": 53, "name": "vc_rt_reset", "signature": "void vc_rt_reset(vc_rt_ctx_t *c)"}, {"kind": "function", "line": 60, "name": "vc_rt_semitones_to_ratio", "signature": "float vc_rt_semitones_to_ratio(float semitones)"}, {"kind": "function", "line": 64, "name": "wrap_pi", "signature": "static double wrap_pi(double x)"}, {"kind": "function", "line": 70, "name": "formant_warp", "signature": "static void formant_warp(float *syn_mag, size_t nbins, float factor)"}, {"kind": "function", "line": 105, "name": "vc_rt_transform", "signature": "void vc_rt_transform(float *mag, float *phase, size_t nbins,\n                     uint32_t sample..."}, {"kind": "macro", "line": 7, "name": "M_PI"}]}, {"doc": "ifndef VC_RT_H define VC_RT_H  include <stddef.h> include <stdint.h>  ifdef __cplusplus", "id": "voicecloak/src/vc_rt.h", "kind": "module", "label": "vc_rt.h", "language": "h", "sha256": "561ad0ea36ab8e21", "symbol_count": 1, "symbols": [{"kind": "macro", "line": 2, "name": "VC_RT_H"}]}, {"doc": "define _POSIX_C_SOURCE 200809L  include \"vc_alsa.h\" include \"vc_stream.h\" include \"vc_rt.h\" include \"vc_fft.h\" include \"vc_crypto.h\"  include <stdio.h> include <stdlib.h> include <string.h> include <signal.h> include <math.h>  ifndef M_PI define M_PI 3.14159265358979323846 endif", "id": "voicecloak/src/vc_rt_cli.c", "kind": "module", "label": "vc_rt_cli.c", "language": "c", "sha256": "84c405ba8bdf5cd7", "symbol_count": 9, "symbols": [{"kind": "function", "line": 20, "name": "on_sigint", "signature": "static void on_sigint(int sig)"}, {"kind": "function", "line": 25, "name": "print_usage", "signature": "static void print_usage(const char *prog)"}, {"kind": "function", "line": 57, "name": "dominant_freq", "signature": "static float dominant_freq(const float *x, size_t n, unsigned int sr)"}, {"kind": "function", "line": 80, "name": "cmd_selftest", "signature": "static int cmd_selftest(void)"}, {"kind": "function", "line": 118, "name": "resolve_params", "signature": "static int resolve_params(int have_fixed, float semis, float formant,\n                          f..."}, {"kind": "function", "line": 141, "name": "cmd_live", "signature": "static int cmd_live(int argc, char *argv[])"}, {"kind": "function", "line": 222, "name": "main", "signature": "int main(int argc, char *argv[])"}, {"kind": "macro", "line": 1, "name": "_POSIX_C_SOURCE"}, {"kind": "macro", "line": 16, "name": "M_PI"}]}, {"doc": "include \"vc_rt.h\" include \"vc_crypto.h\" include <math.h>", "id": "voicecloak/src/vc_rt_seed.c", "kind": "module", "label": "vc_rt_seed.c", "language": "c", "sha256": "9c908d1c894c4ae8", "symbol_count": 1, "symbols": [{"doc": "include \"vc_rt.h\" include \"vc_crypto.h\" include <math.h>", "kind": "function", "line": 4, "name": "vc_rt_derive", "signature": "int vc_rt_derive(const unsigned char *pitch_seed,\n                 const unsigned char *formant_s..."}]}, {"doc": "include \"vc_stft.h\" include \"vc_fft.h\" include <stdlib.h> include <string.h> include <math.h>  ifndef M_PI define M_PI 3.14159265358979323846f endif", "id": "voicecloak/src/vc_stft.c", "kind": "module", "label": "vc_stft.c", "language": "c", "sha256": "e470f667b614fa11", "symbol_count": 8, "symbols": [{"kind": "struct", "line": 11, "name": "vc_stft_s"}, {"kind": "function", "line": 20, "name": "vc_stft_create", "signature": "vc_stft_t *vc_stft_create(size_t fft_size, size_t hop_size)"}, {"kind": "function", "line": 57, "name": "vc_stft_destroy", "signature": "void vc_stft_destroy(vc_stft_t *st)"}, {"kind": "function", "line": 66, "name": "vc_stft_num_bins", "signature": "size_t vc_stft_num_bins(const vc_stft_t *st)"}, {"kind": "function", "line": 70, "name": "vc_stft_forward", "signature": "int vc_stft_forward(vc_stft_t *st,\n                    const float *samples, size_t num_samples,\n..."}, {"kind": "function", "line": 118, "name": "vc_stft_inverse", "signature": "int vc_stft_inverse(vc_stft_t *st,\n                    const float *mag, const float *phase,\n    ..."}, {"kind": "function", "line": 126, "name": "vc_stft_inverse_hop", "signature": "int vc_stft_inverse_hop(vc_stft_t *st,\n                        const float *mag, const float *pha..."}, {"kind": "macro", "line": 8, "name": "M_PI"}]}, {"doc": "ifndef VC_STFT_H define VC_STFT_H  include <stddef.h> include <stdint.h>  ifdef __cplusplus", "id": "voicecloak/src/vc_stft.h", "kind": "module", "label": "vc_stft.h", "language": "h", "sha256": "15e5d0ed0a8af453", "symbol_count": 1, "symbols": [{"kind": "macro", "line": 2, "name": "VC_STFT_H"}]}, {"doc": "include \"vc_stream.h\" include \"vc_fft.h\" include <stdlib.h> include <string.h> include <math.h>  ifndef M_PI define M_PI 3.14159265358979323846 endif", "id": "voicecloak/src/vc_stream.c", "kind": "module", "label": "vc_stream.c", "language": "c", "sha256": "d49a34024417b145", "symbol_count": 8, "symbols": [{"kind": "struct", "line": 11, "name": "vc_stream_s"}, {"kind": "function", "line": 30, "name": "is_pow2", "signature": "static int is_pow2(size_t v)"}, {"kind": "function", "line": 34, "name": "vc_stream_create", "signature": "vc_stream_t *vc_stream_create(size_t fft_size, size_t hop_size,\n                              uin..."}, {"kind": "function", "line": 93, "name": "vc_stream_destroy", "signature": "void vc_stream_destroy(vc_stream_t *st)"}, {"kind": "function", "line": 106, "name": "vc_stream_latency_samples", "signature": "size_t vc_stream_latency_samples(const vc_stream_t *st)"}, {"kind": "function", "line": 110, "name": "process_frame", "signature": "static void process_frame(vc_stream_t *st, vc_spectral_fn fn, void *user)"}, {"kind": "function", "line": 158, "name": "vc_stream_process", "signature": "int vc_stream_process(vc_stream_t *st,\n                      const float *in, float *out, size_t ..."}, {"kind": "macro", "line": 8, "name": "M_PI"}]}, {"doc": "ifndef VC_STREAM_H define VC_STREAM_H  include <stddef.h> include <stdint.h>  ifdef __cplusplus", "id": "voicecloak/src/vc_stream.h", "kind": "module", "label": "vc_stream.h", "language": "h", "sha256": "0238d8f6f9b46cf0", "symbol_count": 1, "symbols": [{"kind": "macro", "line": 2, "name": "VC_STREAM_H"}]}, {"doc": "include \"vc_wav.h\" include <stdio.h> include <stdlib.h> include <string.h> include <math.h> include <stdint.h>  pragma pack(push, 1)", "id": "voicecloak/src/vc_wav.c", "kind": "module", "label": "vc_wav.c", "language": "c", "sha256": "2c5f3bf27077cf92", "symbol_count": 7, "symbols": [{"doc": "pragma pack(pop)", "kind": "function", "line": 29, "name": "read_bytes", "signature": "static int read_bytes(FILE *fp, void *buf, size_t n)"}, {"kind": "function", "line": 33, "name": "write_bytes", "signature": "static int write_bytes(FILE *fp, const void *buf, size_t n)"}, {"kind": "function", "line": 37, "name": "sample_to_float", "signature": "static float sample_to_float(const unsigned char *p, int bps)"}, {"kind": "function", "line": 61, "name": "float_to_sample", "signature": "static void float_to_sample(float f, unsigned char *p, int bps)"}, {"kind": "function", "line": 77, "name": "find_chunk", "signature": "static int find_chunk(FILE *fp, const char *id, uint32_t *size)"}, {"kind": "function", "line": 92, "name": "vc_wav_read", "signature": "int vc_wav_read(const char *path,\n                float **samples_out, size_t *num_samples_out,\n ..."}, {"kind": "function", "line": 168, "name": "vc_wav_write", "signature": "int vc_wav_write(const char *path,\n                 const float *samples, size_t num_samples,\n   ..."}]}, {"doc": "ifndef VC_WAV_H define VC_WAV_H  include <stddef.h> include <stdint.h>  ifdef __cplusplus", "id": "voicecloak/src/vc_wav.h", "kind": "module", "label": "vc_wav.h", "language": "h", "sha256": "55b3dcb7df9f8cfd", "symbol_count": 1, "symbols": [{"kind": "macro", "line": 2, "name": "VC_WAV_H"}]}, {"doc": "include <stdarg.h> include <stddef.h> include <setjmp.h> include <cmocka.h> include <stdlib.h> include <math.h> include <string.h> include \"vc_fft.h\"", "id": "voicecloak/tests/test_vc_fft.c", "kind": "module", "label": "test_vc_fft.c", "language": "c", "sha256": "eda3b90b014c00e3", "symbol_count": 4, "symbols": [{"doc": "include <stdarg.h> include <stddef.h> include <setjmp.h> include <cmocka.h> include <stdlib.h> include <math.h> include <string.h> include \"vc_fft.h\"", "kind": "function", "line": 9, "name": "test_fft_identity", "signature": "static void test_fft_identity(void **state)"}, {"kind": "function", "line": 26, "name": "test_fft_dc_signal", "signature": "static void test_fft_dc_signal(void **state)"}, {"kind": "function", "line": 46, "name": "test_fft_sine", "signature": "static void test_fft_sine(void **state)"}, {"kind": "function", "line": 75, "name": "main", "signature": "int main(void)"}]}, {"doc": "include <stdarg.h> include <stddef.h> include <setjmp.h> include <cmocka.h>  include \"vc_stream.h\" include \"vc_rt.h\" include \"vc_fft.h\"  include <stdlib.h> include <string.h> include <math.h>  ifndef M_PI define M_PI 3.14159265358979323846 endif  define SR 48000U", "id": "voicecloak/tests/test_vc_stream.c", "kind": "module", "label": "test_vc_stream.c", "language": "c", "sha256": "c1d5a4f11919b9d7", "symbol_count": 13, "symbols": [{"doc": "define SR 48000U", "kind": "function", "line": 19, "name": "gen_sines", "signature": "static void gen_sines(float *buf, size_t n, uint32_t sr,\n                      const float *freqs..."}, {"kind": "function", "line": 31, "name": "dominant_freq", "signature": "static float dominant_freq(const float *x, size_t n, uint32_t sr)"}, {"kind": "function", "line": 53, "name": "rms", "signature": "static float rms(const float *x, size_t n)"}, {"doc": "Stream a whole buffer through the engine in small, irregular chunks * to exercise arbitrary block sizes.", "kind": "function", "line": 63, "name": "run_stream", "signature": "static void run_stream(vc_stream_t *st, const float *in, float *out, size_t n,\n                  ..."}, {"kind": "function", "line": 73, "name": "test_create_validation", "signature": "static void test_create_validation(void **state)"}, {"kind": "function", "line": 85, "name": "test_passthrough_identity", "signature": "static void test_passthrough_identity(void **state)"}, {"kind": "function", "line": 121, "name": "run_pitch", "signature": "static void run_pitch(float in_freq, float ratio, float expect_freq)"}, {"kind": "function", "line": 145, "name": "test_pitch_up_octave", "signature": "static void test_pitch_up_octave(void **state)"}, {"kind": "function", "line": 150, "name": "test_pitch_down_octave", "signature": "static void test_pitch_down_octave(void **state)"}, {"kind": "function", "line": 155, "name": "test_bounded_output", "signature": "static void test_bounded_output(void **state)"}, {"kind": "function", "line": 184, "name": "main", "signature": "int main(void)"}, {"kind": "macro", "line": 15, "name": "M_PI"}, {"kind": "macro", "line": 17, "name": "SR"}]}], "type": "CodePropertyGraph", "version": "1.0"}
```

---

## Architecture Reference

### C (24 files)

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
					  unsigned int ...` - *This function allows for the creation of standard UAC controls. See the quirks for M-Audio FTUs or Ebox-44. If you don't want to set a TLV callback pass NULL.  Since there doesn't seem to be a devices that needs a multichannel version, we keep it mono for simplicity.*
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
				      struct snd_ctl_ele...` - *return; err = snd_usb_ctl_msg(mixer->chip->dev, usb_rcvctrlpipe(mixer->chip->dev, 0), UAC_GET_MEM, USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE, 0, jacks[i].unitid << 8, buf, 3); if (err == 3 && (buf[0] == 3 || buf[0] == 6)) snd_iprintf(buffer, "%02x %02x\n", buf[1], buf[2]); else snd_iprintf(buffer, "?\n"); } } /* EMU0204*
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
				   struct snd_ctl_elem_valu...` - *static int snd_dualsense_controls_create(struct usb_mixer_interface *mixer) { int err; err = snd_dualsense_jack_create(mixer, "Headphone Jack", true); if (err < 0) return err; return snd_dualsense_jack_create(mixer, "Headset Mic Jack", false); } #endif /* IS_REACHABLE(CONFIG_INPUT) /* ASUS Xonar U1 / U3 controls*
- `snd_xonar_u1_switch_update` (line 798) `static int snd_xonar_u1_switch_update(struct usb_mixer_interface *mixer,
				      unsigned char ...`
- `snd_xonar_u1_switch_put` (line 812) `static int snd_xonar_u1_switch_put(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...`
- `snd_xonar_u1_switch_resume` (line 832) `static int snd_xonar_u1_switch_resume(struct usb_mixer_elem_list *list)`
- `snd_xonar_u1_controls_create` (line 847) `static int snd_xonar_u1_controls_create(struct usb_mixer_interface *mixer)`
- `snd_mbox1_is_spdif_synced` (line 856) `static int snd_mbox1_is_spdif_synced(struct snd_usb_audio *chip)` - *.info = snd_ctl_boolean_mono_info, .get = snd_xonar_u1_switch_get, .put = snd_xonar_u1_switch_put, .private_value = 0x05, }; static int snd_xonar_u1_controls_create(struct usb_mixer_interface *mixer) { return add_single_ctl_with_resume(mixer, 0, snd_xonar_u1_switch_resume, &snd_xonar_u1_output_switch, NULL); } /* Digidesign Mbox 1 helper functions*
- `snd_mbox1_set_clk_source` (line 876) `static int snd_mbox1_set_clk_source(struct snd_usb_audio *chip, int rate_or_zero)`
- `snd_mbox1_is_spdif_input` (line 894) `static int snd_mbox1_is_spdif_input(struct snd_usb_audio *chip)`
- `snd_mbox1_set_input_source` (line 914) `static int snd_mbox1_set_input_source(struct snd_usb_audio *chip, int is_spdif)`
- `snd_mbox1_clk_switch_get` (line 933) `static int snd_mbox1_clk_switch_get(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...` - *S/PDIF Source  -> 0x02  unsigned char buff[1]; buff[0] = (is_spdif & 1) + 1; /* Set input source return snd_usb_ctl_msg(chip->dev, usb_sndctrlpipe(chip->dev, 0), 0x1, USB_TYPE_CLASS | USB_RECIP_INTERFACE, 0x00, 0x500, buff, 1); } /* Digidesign Mbox 1 clock source switch (internal/spdif)*
- `snd_mbox1_clk_switch_update` (line 953) `static int snd_mbox1_clk_switch_update(struct usb_mixer_interface *mixer, int is_spdif_sync)`
- `snd_mbox1_clk_switch_put` (line 978) `static int snd_mbox1_clk_switch_put(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...`
- `snd_mbox1_clk_switch_info` (line 996) `static int snd_mbox1_clk_switch_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- `snd_mbox1_clk_switch_resume` (line 1007) `static int snd_mbox1_clk_switch_resume(struct usb_mixer_elem_list *list)`
- `snd_mbox1_src_switch_get` (line 1014) `static int snd_mbox1_src_switch_get(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...` - *static const char *const texts[2] = { "Internal", "S/PDIF" }; return snd_ctl_enum_info(uinfo, 1, ARRAY_SIZE(texts), texts); } static int snd_mbox1_clk_switch_resume(struct usb_mixer_elem_list *list) { return snd_mbox1_clk_switch_update(list->mixer, list->kctl->private_value); } /* Digidesign Mbox 1 input source switch (analog/spdif)*
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
				   struct snd_ctl_elem_info...` - *err = add_single_ctl_with_resume(mixer, 0, snd_ni_update_cur_val, &template, &list); if (err < 0) break; snd_ni_control_init_val(mixer, list->kctl); } return err; } /* M-Audio FastTrack Ultra quirks /* FTU Effect switch (also used by C400/C600)*
- `snd_ftu_eff_switch_init` (line 1277) `static int snd_ftu_eff_switch_init(struct usb_mixer_interface *mixer,
				   struct snd_kcontrol ...`
- `snd_ftu_eff_switch_get` (line 1300) `static int snd_ftu_eff_switch_get(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...`
- `snd_ftu_eff_switch_update` (line 1307) `static int snd_ftu_eff_switch_update(struct usb_mixer_elem_list *list)`
- `snd_ftu_eff_switch_put` (line 1328) `static int snd_ftu_eff_switch_put(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...`
- `snd_ftu_create_effect_switch` (line 1346) `static int snd_ftu_create_effect_switch(struct usb_mixer_interface *mixer,
					int validx, int b...`
- `snd_ftu_create_volume_ctls` (line 1373) `static int snd_ftu_create_volume_ctls(struct usb_mixer_interface *mixer)` - *struct usb_mixer_elem_list *list; int err; err = add_single_ctl_with_resume(mixer, bUnitID, snd_ftu_eff_switch_update, &template, &list); if (err < 0) return err; list->kctl->private_value = (validx << 8) | bUnitID; snd_ftu_eff_switch_init(mixer, list->kctl); return 0; } /* Create volume controls for FTU devices*
- `snd_ftu_create_effect_volume_ctl` (line 1412) `static int snd_ftu_create_effect_volume_ctl(struct usb_mixer_interface *mixer)` - *"DIn%d - Out%d Playback Volume", in - 7, out + 1); err = snd_create_std_mono_ctl(mixer, id, control, cmask, val_type, name, &snd_usb_mixer_vol_tlv); if (err < 0) return err; } } return 0; } /* This control needs a volume quirk, see mixer.c*
- `snd_ftu_create_effect_duration_ctl` (line 1425) `static int snd_ftu_create_effect_duration_ctl(struct usb_mixer_interface *mixer)` - */* This control needs a volume quirk, see mixer.c static int snd_ftu_create_effect_volume_ctl(struct usb_mixer_interface *mixer) { static const char name[] = "Effect Volume"; const unsigned int id = 6; const int val_type = USB_MIXER_U8; const unsigned int control = 2; const unsigned int cmask = 0; return snd_create_std_mono_ctl(mixer, id, control, cmask, val_type, name, snd_usb_mixer_vol_tlv); } /* This control needs a volume quirk, see mixer.c*
- `snd_ftu_create_effect_feedback_ctl` (line 1438) `static int snd_ftu_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)` - */* This control needs a volume quirk, see mixer.c static int snd_ftu_create_effect_duration_ctl(struct usb_mixer_interface *mixer) { static const char name[] = "Effect Duration"; const unsigned int id = 6; const int val_type = USB_MIXER_S16; const unsigned int control = 3; const unsigned int cmask = 0; return snd_create_std_mono_ctl(mixer, id, control, cmask, val_type, name, snd_usb_mixer_vol_tlv); } /* This control needs a volume quirk, see mixer.c*
- `snd_ftu_create_effect_return_ctls` (line 1449) `static int snd_ftu_create_effect_return_ctls(struct usb_mixer_interface *mixer)`
- `snd_ftu_create_effect_send_ctls` (line 1473) `static int snd_ftu_create_effect_send_ctls(struct usb_mixer_interface *mixer)`
- `snd_ftu_create_mixer` (line 1506) `static int snd_ftu_create_mixer(struct usb_mixer_interface *mixer)`
- `snd_emuusb_set_samplerate` (line 1541) `void snd_emuusb_set_samplerate(struct snd_usb_audio *chip,
			       unsigned char samplerate_id)`
- `list_for_each_entry` (line 1548) `list_for_each_entry(mixer, &chip->mixer_list, list)` - *err = snd_ftu_create_effect_send_ctls(mixer); if (err < 0) return err; return 0; } void snd_emuusb_set_samplerate(struct snd_usb_audio *chip, unsigned char samplerate_id) { struct usb_mixer_interface *mixer; struct usb_mixer_elem_info *cval; int unitid = 12; /* SampleRate ExtensionUnit ID*
- `snd_c400_create_vol_ctls` (line 1563) `static int snd_c400_create_vol_ctls(struct usb_mixer_interface *mixer)` - *list_for_each_entry(mixer, &chip->mixer_list, list) { if (mixer->id_elems[unitid]) { cval = mixer_elem_list_to_info(mixer->id_elems[unitid]); snd_usb_mixer_set_ctl_value(cval, UAC_SET_CUR, cval->control << 8, samplerate_id); snd_usb_mixer_notify_id(mixer, unitid); break; } } } /* M-Audio Fast Track C400/C600 /* C400/C600 volume controls, this control needs a volume quirk, see mixer.c*
- `snd_c400_create_effect_volume_ctl` (line 1612) `static int snd_c400_create_effect_volume_ctl(struct usb_mixer_interface *mixer)` - *cmask = (out == 0) ? 0 : BIT(out - 1); offset = chan * num_outs; err = snd_create_std_mono_ctl_offset(mixer, id, control, cmask, val_type, offset, name, &snd_usb_mixer_vol_tlv); if (err < 0) return err; } } return 0; } /* This control needs a volume quirk, see mixer.c*
- `snd_c400_create_effect_duration_ctl` (line 1625) `static int snd_c400_create_effect_duration_ctl(struct usb_mixer_interface *mixer)` - */* This control needs a volume quirk, see mixer.c static int snd_c400_create_effect_volume_ctl(struct usb_mixer_interface *mixer) { static const char name[] = "Effect Volume"; const unsigned int id = 0x43; const int val_type = USB_MIXER_U8; const unsigned int control = 3; const unsigned int cmask = 0; return snd_create_std_mono_ctl(mixer, id, control, cmask, val_type, name, snd_usb_mixer_vol_tlv); } /* This control needs a volume quirk, see mixer.c*
- `snd_c400_create_effect_feedback_ctl` (line 1638) `static int snd_c400_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)` - */* This control needs a volume quirk, see mixer.c static int snd_c400_create_effect_duration_ctl(struct usb_mixer_interface *mixer) { static const char name[] = "Effect Duration"; const unsigned int id = 0x43; const int val_type = USB_MIXER_S16; const unsigned int control = 4; const unsigned int cmask = 0; return snd_create_std_mono_ctl(mixer, id, control, cmask, val_type, name, snd_usb_mixer_vol_tlv); } /* This control needs a volume quirk, see mixer.c*
- `snd_c400_create_effect_vol_ctls` (line 1649) `static int snd_c400_create_effect_vol_ctls(struct usb_mixer_interface *mixer)`
- `snd_c400_create_effect_ret_vol_ctls` (line 1694) `static int snd_c400_create_effect_ret_vol_ctls(struct usb_mixer_interface *mixer)`
- `snd_c400_create_mixer` (line 1736) `static int snd_c400_create_mixer(struct usb_mixer_interface *mixer)`
- `snd_microii_spdif_info` (line 1869) `static int snd_microii_spdif_info(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_info *...` - *power on values: r2: 0x10 r3: 0x20 (b7 is zeroed just before playback (except IEC61937) and set just after it to 0xa0, presumably it disables/mutes some analog parts when there is no audio.) r9: 0x28  Optical transmitter on/off: vendor register.bit: 9.1 0 - on (0x28 register value) 1 - off (0x2a register value)*
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
					  struct snd_ctl_el...` - *for (i = 0; i < ARRAY_SIZE(snd_microii_mixer_spdif); ++i) { err = add_single_ctl_with_resume(mixer, 0, resume_funcs[i], &snd_microii_mixer_spdif[i], NULL); if (err < 0) return err; } return 0; } /* Creative Sound Blaster E1*
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
- `snd_rme_digiface_write_reg` (line 3318) `static int snd_rme_digiface_write_reg(struct snd_kcontrol *kcontrol, int item, u16 mask, u16 val)` - *#define RME_DIGIFACE_STATUS_REG2H 5 #define RME_DIGIFACE_STATUS_REG3L 6 #define RME_DIGIFACE_STATUS_REG3H 7 #define RME_DIGIFACE_CTL_REG1 16 #define RME_DIGIFACE_CTL_REG2 18 /* Reg is overloaded, 0-7 for status halfwords or 16 or 18 for control registers #define RME_DIGIFACE_REGISTER(reg, mask) (((reg) << 16) | (mask)) #define RME_DIGIFACE_INVERT BIT(31) /* Nonconst helpers define field_get(_mask, _reg) (((_reg) & (_mask)) >> (ffs(_mask) - 1)) define field_prep(_mask, _val) (((_val) << (ffs(_mask) - 1)) & (_mask))*
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
			     struct snd_ctl_elem_id *id)` - *standards. This function fixes nonstandard source names. By the time this function is called the control name should look like one of these: "source names Playback Volume" "source names Playback Switch" "source names Capture Volume" "source names Capture Switch" If any of the trigger words are found in the name then the name will be changed to: "Headset Playback Volume" "Headset Playback Switch" "Headset Capture Volume" "Headset Capture Switch" depending on the current suffix.*
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
- `rc_config` (line 181) - *Sound Blaster remote control configuration  format of remote control data: Extigy:       xx 00 Audigy 2 NX:  06 80 xx 00 00 00 Live! 24-bit: 06 80 xx yy 22 83*
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
- `VSL_Final_Encode_To_Int` (line 58) `uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)` - *@brief Convierte el valor codificado en float a un entero sin signo para el firmware. @note Basado en la hipótesis común de DSP donde el rango flotante es 0.0 - 1000.0. Si el valor real es diferente, solo se debe cambiar la constante VSL_MAX_ENCODED_FLOAT.*
- `VSL_Decode_Frequency` (line 78) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)` - *Implementación de FUN_00132da8*

#### `vsl_dsp_transport.c`
**Path:** `legacy/vsl_dsp_transport.c`
**File Doc:** *vsl_dsp_transport.c (Añadir la Plantilla B completa aquí)  include <stdio.h> include <string.h> include <math.h> include <hidapi/hidapi.h> include <stdlib.h> include "vsl_config.h" include "vsl_dsp_transport.h"  Handle de Singleton (Regla #5: Diseño Escalable)*

**Functions:**
- `VSL_Init_Device` (line 22) `int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)` - *... (las inclusiones y el singleton handle) ...*
- `VSL_Close_Device` (line 69) `void VSL_Close_Device(void)`
- `VSL_Get_Device_Handle` (line 78) `hid_device* VSL_Get_Device_Handle(void)`
- `FUN_Send_Packet` (line 97) `void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length)` - *@brief Función de I/O real usando HIDAPI. @note DEBE SER REEMPLAZADA con la lógica específica de tu dispositivo (Report ID, longitud, etc.)*
- `VSL_Build_And_Send_Packet` (line 140) `void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float)` - *Implementación de la función de construcción y envío*

#### `vsl_cli.c`
**Path:** `src/vsl_cli.c`
**File Doc:** *include <stdio.h> include <stdlib.h> include <string.h> include <math.h> include <stdint.h> include "vsl_dsp_logic.h" include "vsl_dsp_transport.h" include "vsl_config.h"*

**Functions:**
- `print_usage` (line 57) `static void print_usage(FILE *fp, const char *prog)`
- `print_version` (line 83) `static void print_version(void)`
- `print_list` (line 90) `static void print_list(uint16_t product_id)`
- `lookup_coeffs_by_param_id` (line 109) `static const VSL_Parameter *
lookup_coeffs_by_param_id(uint16_t param_id)`
- `find_entry_by_name` (line 119) `static const ParamEntry *
find_entry_by_name(const char *name)`
- `do_send` (line 129) `static int do_send(uint16_t product_id,
                   uint16_t param_id,
                   ...`
- `do_send_freq` (line 167) `static int do_send_freq(uint16_t product_id,
                        uint16_t param_id,
         ...`
- `main` (line 204) `int main(int argc, char *argv[])`

**Macros:**
- `MAX_CHANNELS` (line 47)

#### `vsl_dsp_logic.c`
**Path:** `src/vsl_dsp_logic.c`
**File Doc:** *include "vsl_dsp_logic.h"*

**Functions:**
- `VSL_Encode_Gain` (line 2) `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)` - *include "vsl_dsp_logic.h"*
- `VSL_Decode_Gain` (line 15) `float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param)`
- `VSL_Map_Frequency` (line 49) `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)`
- `VSL_Final_Encode_To_Int` (line 65) `uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)`
- `VSL_Decode_Frequency` (line 75) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)`

#### `vsl_dsp_transport.c`
**Path:** `src/vsl_dsp_transport.c`
**File Doc:** *include "vsl_dsp_transport.h" include <stdio.h> include <stdlib.h> include <string.h> include <libusb-1.0/libusb.h>*

**Functions:**
- `VSL_Init_Device` (line 12) `vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)`
- `VSL_Close_Device` (line 44) `void VSL_Close_Device(vsl_device_handle handle)`
- `VSL_Send_Parameter` (line 60) `int VSL_Send_Parameter(vsl_device_handle handle,
                       uint16_t dsp_param_id,
  ...`

**Structs:**
- `vsl_device` (line 7)

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
- `test_VSL_Decode_Gain_c1_zero` (line 127) `static void test_VSL_Decode_Gain_c1_zero(void **state)`
- `test_VSL_Decode_Gain_log_factor_zero` (line 145) `static void test_VSL_Decode_Gain_log_factor_zero(void **state)`
- `test_VSL_Decode_Gain_encoded_below_offset` (line 163) `static void test_VSL_Decode_Gain_encoded_below_offset(void **state)`
- `test_VSL_Decode_Gain_range_zero` (line 182) `static void test_VSL_Decode_Gain_range_zero(void **state)`
- `test_VSL_Decode_Gain_roundtrip_mid` (line 200) `static void test_VSL_Decode_Gain_roundtrip_mid(void **state)`
- `test_VSL_Decode_Gain_roundtrip_extremes` (line 220) `static void test_VSL_Decode_Gain_roundtrip_extremes(void **state)`
- `test_VSL_Decode_Gain_roundtrip_75` (line 241) `static void test_VSL_Decode_Gain_roundtrip_75(void **state)`
- `test_VSL_Decode_Gain_custom_range_roundtrip` (line 261) `static void test_VSL_Decode_Gain_custom_range_roundtrip(void **state)`
- `test_VSL_Decode_Gain_encoded_equals_offset` (line 289) `static void test_VSL_Decode_Gain_encoded_equals_offset(void **state)`
- `test_VSL_Decode_Gain_clamps_output` (line 308) `static void test_VSL_Decode_Gain_clamps_output(void **state)`
- `main` (line 328) `int main(void)`

#### `vc_alsa.c`
**Path:** `voicecloak/src/vc_alsa.c`
**File Doc:** *define _GNU_SOURCE  include "vc_alsa.h" include "vc_stream.h"  include <alloca.h> include <alsa/asoundlib.h> include <stdio.h> include <stdlib.h> include <string.h> include <math.h>*

**Functions:**
- `fmt_bps` (line 19) `static size_t fmt_bps(snd_pcm_format_t f)`
- `open_stream` (line 28) `static int open_stream(vc_pcm_t *s, const char *dev, snd_pcm_stream_t dir,
                      ...`
- `raw_to_mono` (line 98) `static void raw_to_mono(const unsigned char *raw, float *mono,
                        snd_pcm_uf...`
- `mono_to_raw` (line 129) `static void mono_to_raw(unsigned char *raw, const float *mono,
                        snd_pcm_uf...`
- `vc_alsa_list` (line 162) `int vc_alsa_list(void)`
- `vc_alsa_run` (line 188) `int vc_alsa_run(const vc_alsa_cfg_t *cfg)`

**Macros:**
- `_GNU_SOURCE` (line 1)

#### `vc_cli.c`
**Path:** `voicecloak/src/vc_cli.c`
**File Doc:** *include "vc_wav.h" include "vc_dsp.h" include "vc_crypto.h" include <stdio.h> include <stdlib.h> include <string.h> include <time.h>*

**Functions:**
- `print_usage` (line 8) `static void print_usage(const char *prog)` - *include "vc_wav.h" include "vc_dsp.h" include "vc_crypto.h" include <stdio.h> include <stdlib.h> include <string.h> include <time.h>*
- `cmd_keygen` (line 40) `static int cmd_keygen(void)`
- `cmd_cloak` (line 52) `static int cmd_cloak(const char *pubkey_path,
                     const char *in_path, const cha...`
- `cmd_info` (line 141) `static int cmd_info(const char *path)`
- `main` (line 176) `int main(int argc, char *argv[])`

#### `vc_crypto.c`
**Path:** `voicecloak/src/vc_crypto.c`
**File Doc:** *include "vc_crypto.h" include <stdio.h> include <stdlib.h> include <string.h> include <openssl/evp.h> include <openssl/pem.h> include <openssl/rsa.h> include <openssl/rand.h> include <openssl/err.h> include <openssl/hmac.h>*

**Functions:**
- `openssl_init` (line 11) `static void openssl_init(void)` - *include "vc_crypto.h" include <stdio.h> include <stdlib.h> include <string.h> include <openssl/evp.h> include <openssl/pem.h> include <openssl/rsa.h> include <openssl/rand.h> include <openssl/err.h> include <openssl/hmac.h>*
- `vc_crypto_keygen` (line 16) `int vc_crypto_keygen(const char *pubkey_path, const char *privkey_path)`
- `vc_crypto_seal` (line 46) `int vc_crypto_seal(const char *pubkey_path,
                   const unsigned char *seed, size_t ...`
- `vc_crypto_unseal` (line 70) `int vc_crypto_unseal(const char *privkey_path,
                     const unsigned char *enc, siz...`
- `vc_crypto_derive_seeds` (line 95) `int vc_crypto_derive_seeds(const unsigned char *master_seed, size_t seed_len,
                   ...`
- `vc_prng_create` (line 142) `vc_prng_t *vc_prng_create(const unsigned char *seed)`
- `vc_prng_destroy` (line 156) `void vc_prng_destroy(vc_prng_t *p)`
- `vc_prng_fill` (line 163) `void vc_prng_fill(vc_prng_t *p, unsigned char *buf, size_t len)`
- `vc_prng_float` (line 183) `float vc_prng_float(vc_prng_t *p, float low, float high)`

**Structs:**
- `vc_prng_s` (line 136) - *int i; for (i = 0; i < 3; ++i) { unsigned int outlen = 32; unsigned char data[64]; size_t data_len = info_lens[i] + 1; memcpy(data, infos[i], info_lens[i]); data[info_lens[i]] = (unsigned char)0x01; if (!HMAC(EVP_sha256(), prk, 32, data, data_len, outputs[i], &outlen)) return -1; } return 0; } /* PRNG: AES-256-CTR using OpenSSL EVP*

#### `vc_dsp.c`
**Path:** `voicecloak/src/vc_dsp.c`
**File Doc:** *include "vc_dsp.h" include "vc_stft.h" include "vc_crypto.h" include <stdlib.h> include <string.h> include <math.h> include <float.h>  define VC_FFT_SIZE 2048U define VC_HOP_SIZE  (VC_FFT_SIZE / 4)*

**Functions:**
- `stft_process` (line 11) `static int stft_process(const float *samples, size_t num_samples,
                        float *...` - *define VC_FFT_SIZE 2048U define VC_HOP_SIZE  (VC_FFT_SIZE / 4)*
- `stft_reconstruct` (line 20) `static int stft_reconstruct(const float *mag, const float *phase,
                            siz...`
- `compute_out_len` (line 30) `static size_t compute_out_len(size_t nframes, size_t hop)`
- `vc_dsp_pitch_shift` (line 34) `int vc_dsp_pitch_shift(const float *samples, size_t num_samples,
                       uint32_t ...`
- `vc_dsp_formant_shift` (line 90) `int vc_dsp_formant_shift(const float *samples, size_t num_samples,
                         uint3...`
- `vc_dsp_spectral_scramble` (line 160) `int vc_dsp_spectral_scramble(const float *samples, size_t num_samples,
                          ...`
- `trim_edges` (line 233) `static void trim_edges(float **buf, size_t *len)`
- `normalize_rms` (line 254) `static void normalize_rms(const float *in, size_t in_len,
                          float *out, s...`
- `vc_dsp_cloak` (line 271) `int vc_dsp_cloak(const float *samples, size_t num_samples,
                 uint32_t sample_rate,...`

**Macros:**
- `VC_FFT_SIZE` (line 8)
- `VC_HOP_SIZE` (line 10)

#### `vc_fft.c`
**Path:** `voicecloak/src/vc_fft.c`
**File Doc:** *include "vc_fft.h" include <math.h> include <string.h> include <stdlib.h>  ifndef M_PI define M_PI 3.14159265358979323846f endif*

**Functions:**
- `bit_reverse` (line 9) `static unsigned int bit_reverse(unsigned int x, unsigned int bits)` - *ifndef M_PI define M_PI 3.14159265358979323846f endif*
- `bit_reverse_reorder` (line 19) `static void bit_reverse_reorder(size_t n, float *real, float *imag)`
- `vc_fft` (line 35) `void vc_fft(size_t n, float *real, float *imag, int inverse)`

**Macros:**
- `M_PI` (line 7)

#### `vc_rt.c`
**Path:** `voicecloak/src/vc_rt.c`
**File Doc:** *include "vc_rt.h" include <stdlib.h> include <string.h> include <math.h>  ifndef M_PI define M_PI 3.14159265358979323846 endif*

**Functions:**
- `vc_rt_create` (line 22) `vc_rt_ctx_t *vc_rt_create(size_t nbins, vc_rt_params_t params)`
- `vc_rt_destroy` (line 42) `void vc_rt_destroy(vc_rt_ctx_t *c)`
- `vc_rt_reset` (line 53) `void vc_rt_reset(vc_rt_ctx_t *c)`
- `vc_rt_semitones_to_ratio` (line 60) `float vc_rt_semitones_to_ratio(float semitones)`
- `wrap_pi` (line 64) `static double wrap_pi(double x)`
- `formant_warp` (line 70) `static void formant_warp(float *syn_mag, size_t nbins, float factor)`
- `vc_rt_transform` (line 105) `void vc_rt_transform(float *mag, float *phase, size_t nbins,
                     uint32_t sample...`

**Macros:**
- `M_PI` (line 7)

**Structs:**
- `vc_rt_ctx_s` (line 10)

#### `vc_rt_cli.c`
**Path:** `voicecloak/src/vc_rt_cli.c`
**File Doc:** *define _POSIX_C_SOURCE 200809L  include "vc_alsa.h" include "vc_stream.h" include "vc_rt.h" include "vc_fft.h" include "vc_crypto.h"  include <stdio.h> include <stdlib.h> include <string.h> include <signal.h> include <math.h>  ifndef M_PI define M_PI 3.14159265358979323846 endif*

**Functions:**
- `on_sigint` (line 20) `static void on_sigint(int sig)`
- `print_usage` (line 25) `static void print_usage(const char *prog)`
- `dominant_freq` (line 57) `static float dominant_freq(const float *x, size_t n, unsigned int sr)`
- `cmd_selftest` (line 80) `static int cmd_selftest(void)`
- `resolve_params` (line 118) `static int resolve_params(int have_fixed, float semis, float formant,
                          f...`
- `cmd_live` (line 141) `static int cmd_live(int argc, char *argv[])`
- `main` (line 222) `int main(int argc, char *argv[])`

**Macros:**
- `_POSIX_C_SOURCE` (line 1)
- `M_PI` (line 16)

#### `vc_rt_seed.c`
**Path:** `voicecloak/src/vc_rt_seed.c`
**File Doc:** *include "vc_rt.h" include "vc_crypto.h" include <math.h>*

**Functions:**
- `vc_rt_derive` (line 4) `int vc_rt_derive(const unsigned char *pitch_seed,
                 const unsigned char *formant_s...` - *include "vc_rt.h" include "vc_crypto.h" include <math.h>*

#### `vc_stft.c`
**Path:** `voicecloak/src/vc_stft.c`
**File Doc:** *include "vc_stft.h" include "vc_fft.h" include <stdlib.h> include <string.h> include <math.h>  ifndef M_PI define M_PI 3.14159265358979323846f endif*

**Functions:**
- `vc_stft_create` (line 20) `vc_stft_t *vc_stft_create(size_t fft_size, size_t hop_size)`
- `vc_stft_destroy` (line 57) `void vc_stft_destroy(vc_stft_t *st)`
- `vc_stft_num_bins` (line 66) `size_t vc_stft_num_bins(const vc_stft_t *st)`
- `vc_stft_forward` (line 70) `int vc_stft_forward(vc_stft_t *st,
                    const float *samples, size_t num_samples,
...`
- `vc_stft_inverse` (line 118) `int vc_stft_inverse(vc_stft_t *st,
                    const float *mag, const float *phase,
    ...`
- `vc_stft_inverse_hop` (line 126) `int vc_stft_inverse_hop(vc_stft_t *st,
                        const float *mag, const float *pha...`

**Macros:**
- `M_PI` (line 8)

**Structs:**
- `vc_stft_s` (line 11)

#### `vc_stream.c`
**Path:** `voicecloak/src/vc_stream.c`
**File Doc:** *include "vc_stream.h" include "vc_fft.h" include <stdlib.h> include <string.h> include <math.h>  ifndef M_PI define M_PI 3.14159265358979323846 endif*

**Functions:**
- `is_pow2` (line 30) `static int is_pow2(size_t v)`
- `vc_stream_create` (line 34) `vc_stream_t *vc_stream_create(size_t fft_size, size_t hop_size,
                              uin...`
- `vc_stream_destroy` (line 93) `void vc_stream_destroy(vc_stream_t *st)`
- `vc_stream_latency_samples` (line 106) `size_t vc_stream_latency_samples(const vc_stream_t *st)`
- `process_frame` (line 110) `static void process_frame(vc_stream_t *st, vc_spectral_fn fn, void *user)`
- `vc_stream_process` (line 158) `int vc_stream_process(vc_stream_t *st,
                      const float *in, float *out, size_t ...`

**Macros:**
- `M_PI` (line 8)

**Structs:**
- `vc_stream_s` (line 11)

#### `vc_wav.c`
**Path:** `voicecloak/src/vc_wav.c`
**File Doc:** *include "vc_wav.h" include <stdio.h> include <stdlib.h> include <string.h> include <math.h> include <stdint.h>  pragma pack(push, 1)*

**Functions:**
- `read_bytes` (line 29) `static int read_bytes(FILE *fp, void *buf, size_t n)` - *pragma pack(pop)*
- `write_bytes` (line 33) `static int write_bytes(FILE *fp, const void *buf, size_t n)`
- `sample_to_float` (line 37) `static float sample_to_float(const unsigned char *p, int bps)`
- `float_to_sample` (line 61) `static void float_to_sample(float f, unsigned char *p, int bps)`
- `find_chunk` (line 77) `static int find_chunk(FILE *fp, const char *id, uint32_t *size)`
- `vc_wav_read` (line 92) `int vc_wav_read(const char *path,
                float **samples_out, size_t *num_samples_out,
 ...`
- `vc_wav_write` (line 168) `int vc_wav_write(const char *path,
                 const float *samples, size_t num_samples,
   ...`

#### `test_vc_fft.c`
**Path:** `voicecloak/tests/test_vc_fft.c`
**File Doc:** *include <stdarg.h> include <stddef.h> include <setjmp.h> include <cmocka.h> include <stdlib.h> include <math.h> include <string.h> include "vc_fft.h"*

**Functions:**
- `test_fft_identity` (line 9) `static void test_fft_identity(void **state)` - *include <stdarg.h> include <stddef.h> include <setjmp.h> include <cmocka.h> include <stdlib.h> include <math.h> include <string.h> include "vc_fft.h"*
- `test_fft_dc_signal` (line 26) `static void test_fft_dc_signal(void **state)`
- `test_fft_sine` (line 46) `static void test_fft_sine(void **state)`
- `main` (line 75) `int main(void)`

#### `test_vc_stream.c`
**Path:** `voicecloak/tests/test_vc_stream.c`
**File Doc:** *include <stdarg.h> include <stddef.h> include <setjmp.h> include <cmocka.h>  include "vc_stream.h" include "vc_rt.h" include "vc_fft.h"  include <stdlib.h> include <string.h> include <math.h>  ifndef M_PI define M_PI 3.14159265358979323846 endif  define SR 48000U*

**Functions:**
- `gen_sines` (line 19) `static void gen_sines(float *buf, size_t n, uint32_t sr,
                      const float *freqs...` - *define SR 48000U*
- `dominant_freq` (line 31) `static float dominant_freq(const float *x, size_t n, uint32_t sr)`
- `rms` (line 53) `static float rms(const float *x, size_t n)`
- `run_stream` (line 63) `static void run_stream(vc_stream_t *st, const float *in, float *out, size_t n,
                  ...` - *Stream a whole buffer through the engine in small, irregular chunks * to exercise arbitrary block sizes.*
- `test_create_validation` (line 73) `static void test_create_validation(void **state)`
- `test_passthrough_identity` (line 85) `static void test_passthrough_identity(void **state)`
- `run_pitch` (line 121) `static void run_pitch(float in_freq, float ratio, float expect_freq)`
- `test_pitch_up_octave` (line 145) `static void test_pitch_up_octave(void **state)`
- `test_pitch_down_octave` (line 150) `static void test_pitch_down_octave(void **state)`
- `test_bounded_output` (line 155) `static void test_bounded_output(void **state)`
- `main` (line 184) `int main(void)`

**Macros:**
- `M_PI` (line 15)
- `SR` (line 17)

### H (15 files)

#### `audiobox_vsl.h`
**Path:** `audiobox_vsl.h`
**File Doc:** *SPDX-License-Identifier: GPL-2.0-or-later*

**Imported by:** `audiobox_vsl.c`, `mixer_quirks.c`, `test_audiobox_vsl.c`

**Functions:**
- `audiobox_lookup_model` (line 95) `static inline const audiobox_model_info_t *
audiobox_lookup_model(uint16_t pid)` - *@brief Look up the model info entry for a given USB product ID.  @param pid 16-bit product ID reported by the USB device. @return Pointer to a const entry in audiobox_models[] on match. NULL if pid does not correspond to any supported model.  Pure function: no side effects, no allocation, safe to call from any context including the USB probe path. The returned pointer remains valid for the lifetime of the kernel. Defined as a static inline so both the kernel module and the userspace test suite can include this header and exercise the lookup without linking against kernel-only object files.*

**Macros:**
- `AUDIOBOX_VSL_H` (line 21)
- `AUDIOBOX_VENDOR_ID` (line 32)

**Structs:**
- `usb_mixer_interface` (line 113)

#### `vsl_config.h`
**Path:** `legacy/vsl_config.h`
**File Doc:** *vsl_config.h (VERSION CORREGIDA)  ifndef VSL_CONFIG_H define VSL_CONFIG_H  include <stdint.h>  ======================================================= BLOQUEADORES CRÍTICOS (Hardware) ======================================================= define VSL_VENDOR_ID   0x194f define VSL_PRODUCT_ID  0x0101 define VSL_REPORT_ID   0x06  ======================================================= CONSTANTES CRÍTICAS VSL-DSP (Necesarias para la lógica) =======================================================  Factor de escala usado en la fórmula VSL (Confirmado en la PoC Python) define VSL_SCALE_FACTOR        1000.0f  Máximo valor codificado de 16 bits (0xFFFF) define VSL_MAX_ENCODED_INT     65535  define VSL_PACKET_SIZE         64      // 0x40 bytes define VSL_PAYLOAD_SIZE        5       // Byte 1 (ID LSB) a Byte 4 (Value MSB)  endif // VSL_CONFIG_H*

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
**File Doc:** *ifndef VSL_DSP_LOGIC_H define VSL_DSP_LOGIC_H  include <stdint.h> include <math.h> include <float.h> // Para fmaxf, fminf  Constante para la conversión de logaritmo natural (ln) a logaritmo base 2 (log2) 1 / ln(2) ≈ 1.442695 define VSL_INV_LN2 1.442695f  Estructura que almacena todos los coeficientes precalculados del DSP*

**Macros:**
- `VSL_DSP_LOGIC_H` (line 2)
- `VSL_INV_LN2` (line 10)

#### `vsl_dsp_transport.h`
**Path:** `legacy/vsl_dsp_transport.h`
**File Doc:** *vsl_dsp_transport.h (CORREGIDO)  ifndef VSL_DSP_TRANSPORT_H define VSL_DSP_TRANSPORT_H  include <stdint.h> include <stddef.h> include <hidapi/hidapi.h> include "vsl_config.h" // Solo incluye la configuración  Estructura de Paquete: Sin 'header' (lo quitaste en la estructura typedef)*

**Macros:**
- `VSL_DSP_TRANSPORT_H` (line 4)

#### `vsl_config.h`
**Path:** `src/vsl_config.h`
**File Doc:** *ifndef VSL_CONFIG_H define VSL_CONFIG_H  include <stdint.h> include <stddef.h>  ifdef __cplusplus*

**Functions:**
- `VSL_ModelLookup` (line 35) `static inline const VSL_ModelInfo *
VSL_ModelLookup(uint16_t pid)`
- `VSL_ModelLookupByTag` (line 47) `static inline const VSL_ModelInfo *
VSL_ModelLookupByTag(const char *tag)`

**Macros:**
- `VSL_CONFIG_H` (line 2)
- `VSL_VENDOR_ID` (line 10)
- `VSL_PRODUCT_ID_22VSL` (line 12)
- `VSL_PRODUCT_ID_44VSL` (line 13)
- `VSL_PRODUCT_ID_1818VSL` (line 14)
- `VSL_REPORT_ID` (line 15)
- `VSL_PACKET_SIZE` (line 17)
- `VSL_MIDI_IFACE` (line 18)
- `VSL_EP_MIDI_OUT` (line 19)

#### `vsl_dsp_logic.h`
**Path:** `src/vsl_dsp_logic.h`
**File Doc:** *ifndef VSL_DSP_LOGIC_H define VSL_DSP_LOGIC_H  include <stdint.h> include <math.h> include <float.h>  define VSL_INV_LN2            1.442695f define VSL_MAX_ENCODED_FLOAT  1000.0f*

**Macros:**
- `VSL_DSP_LOGIC_H` (line 2)
- `VSL_INV_LN2` (line 7)
- `VSL_MAX_ENCODED_FLOAT` (line 9)

#### `vsl_dsp_transport.h`
**Path:** `src/vsl_dsp_transport.h`
**File Doc:** *ifndef VSL_DSP_TRANSPORT_H define VSL_DSP_TRANSPORT_H  include <stdint.h> include "vsl_dsp_logic.h" include "vsl_config.h"  ifdef __cplusplus*

**Macros:**
- `VSL_DSP_TRANSPORT_H` (line 2)

#### `vc_alsa.h`
**Path:** `voicecloak/src/vc_alsa.h`
**File Doc:** *ifndef VC_ALSA_H define VC_ALSA_H  include <stddef.h> include <stdint.h> include <signal.h> include "vc_stream.h"  ifdef __cplusplus*

**Macros:**
- `VC_ALSA_H` (line 2)

#### `vc_crypto.h`
**Path:** `voicecloak/src/vc_crypto.h`
**File Doc:** *ifndef VC_CRYPTO_H define VC_CRYPTO_H  include <stddef.h> include <stdint.h>  ifdef __cplusplus*

**Macros:**
- `VC_CRYPTO_H` (line 2)
- `VC_CRYPTO_SEED_BYTES` (line 10)
- `VC_CRYPTO_KEY_BYTES` (line 12)
- `VC_PITCH_SEED_BYTES` (line 13)
- `VC_FORMANT_SEED_BYTES` (line 14)
- `VC_SPECTRAL_SEED_BYTES` (line 15)
- `VC_TOTAL_SEED_BYTES` (line 16)

#### `vc_dsp.h`
**Path:** `voicecloak/src/vc_dsp.h`
**File Doc:** *ifndef VC_DSP_H define VC_DSP_H  include <stddef.h> include <stdint.h>  ifdef __cplusplus*

**Macros:**
- `VC_DSP_H` (line 2)

#### `vc_fft.h`
**Path:** `voicecloak/src/vc_fft.h`
**File Doc:** *ifndef VC_FFT_H define VC_FFT_H  include <stddef.h>  ifdef __cplusplus*

**Macros:**
- `VC_FFT_H` (line 2)

#### `vc_rt.h`
**Path:** `voicecloak/src/vc_rt.h`
**File Doc:** *ifndef VC_RT_H define VC_RT_H  include <stddef.h> include <stdint.h>  ifdef __cplusplus*

**Macros:**
- `VC_RT_H` (line 2)

#### `vc_stft.h`
**Path:** `voicecloak/src/vc_stft.h`
**File Doc:** *ifndef VC_STFT_H define VC_STFT_H  include <stddef.h> include <stdint.h>  ifdef __cplusplus*

**Macros:**
- `VC_STFT_H` (line 2)

#### `vc_stream.h`
**Path:** `voicecloak/src/vc_stream.h`
**File Doc:** *ifndef VC_STREAM_H define VC_STREAM_H  include <stddef.h> include <stdint.h>  ifdef __cplusplus*

**Macros:**
- `VC_STREAM_H` (line 2)

#### `vc_wav.h`
**Path:** `voicecloak/src/vc_wav.h`
**File Doc:** *ifndef VC_WAV_H define VC_WAV_H  include <stddef.h> include <stdint.h>  ifdef __cplusplus*

**Macros:**
- `VC_WAV_H` (line 2)

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
**File Doc:** *PASO 1: (Fuera de este entorno) Capturar tráfico USB con Wireshark/usbmon Guardar como: audiobox_full_sweep.pcap  PASO 2: Ejecutar el analizador python3 vsl_protocol_analyzer.py audiobox_full_sweep.pcap*

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
**File Doc:** *SPDX-License-Identifier: GPL-2.0-or-later Thin wrapper that installs the build-time dependencies for the audiobox_vsl kernel module. All real build, install, and clean commands live in the top-level Makefile. This script is intentionally minimal: it only ensures the toolchain and kernel headers are present, then exits.*

*No symbols extracted*

#### `build-dkms.sh`
**Path:** `legacy/build-dkms.sh`
**File Doc:** *AudioBox 22 VSL Enhanced Driver - Installation Script Copyright (c) 2025 grisuno (LazyOwn Project) License: GPL-2.0-or-later  This script installs enhanced ALSA controls for PreSonus AudioBox 22 VSL using DKMS (Dynamic Kernel Module Support) for automatic kernel updates.*

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
**File Doc:** *==================================================================== VSL-DSP: Captura COMPLETA de tráfico USB del AudioBox ====================================================================*

*No symbols extracted*
