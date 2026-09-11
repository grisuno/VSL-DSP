# Polyglot Codebase Knowledge Graph

> Generated offline by **readmenator**. 49 files, 800 symbols, 221 imports. Supports C, C++, Python, Go, Rust, JS/TS, Java, C#, Shell, PHP, Dart, GDScript, Nim, ASM, Ruby, Swift, Kotlin, Scala, Lua, Elixir.
> No LLMs. No tokens. Pure static analysis. See more [here](https://github.com/grisuno/ReadMenator)

**Start here:** Statistics Dashboard for scope, God Nodes for blast radius, Architecture Reference for per-file API. Agents: prefer `readmenator-agent/INDEX.md` + `SYMBOLS.md`.

**Total Files Parsed:** 49 | **Total Symbols Extracted:** 800 | **Total Imports:** 221
 | **Resolved Imports:** 57

<!-- ranking_model: v1.0 | weights: {ppr:0.45,auth:0.2,test:0.15,doc:0.1,fresh:0.1} | alpha:0.85 | commit:b3ca3bb | date:2026-07-18 -->


## Table of Contents

1. [Statistics Dashboard](#statistics-dashboard)
2. [Architectural Layers](#architectural-layers)
3. [Ranked Context](#ranked-context)
4. [God Nodes](#god-nodes)
5. [Community Analysis](#community-analysis)
6. [Surprising Connections](#surprising-connections)
7. [Suggested Questions](#suggested-questions)
8. [Taint Propagation Map](#taint-propagation-map)
9. [Hotspot Analysis](#hotspot-analysis)
10. [Change Impact Analysis](#change-impact-analysis)
11. [Suggested Linting Rules](#suggested-linting-rules)
12. [Query Recipes](#query-recipes)
13. [Structural Knowledge Map](#structural-knowledge-map)
14. [UML Class Diagram](#uml-class-diagram)
15. [Code Property Graph](#code-property-graph)
16. [Architecture Reference](#architecture-reference)
    - [C (24 files)](#c-24-files)
    - [H (15 files)](#h-15-files)
    - [PY (7 files)](#py-7-files)
    - [SH (3 files)](#sh-3-files)

---

## Statistics Dashboard

| Metric | Value |
|--------|-------|
| Total Files | 49 |
| Total Symbols | 800 |
| Total Imports | 221 |
| Call Edges | 250 |
| Inheritance Edges | 1 |
| Languages | 4 |
| Avg Symbols/File | 16.3 |
| Avg Imports/File | 4.5 |
| Resolved Imports | 57 |

### Top Files by Import Count (Fan-Out)

| File | Imports | Symbols | Language |
|------|---------|---------|----------|
| `mixer_quirks.c` | 25 | 344 | c |
| `vc_crypto.c` | 10 | 18 | c |
| `vc_rt_cli.c` | 10 | 20 | c |
| `test_vc_stream.c` | 10 | 24 | c |
| `vsl_hid_io.py` | 8 | 9 | py |
| `vsl_cli.c` | 8 | 14 | c |
| `vc_alsa.c` | 8 | 24 | c |
| `test_vc_fft.c` | 8 | 9 | c |
| `vsl_dsp_transport.c` | 7 | 12 | c |
| `test_vsl_dsp_logic.c` | 7 | 19 | c |

### Top Files by Imported-By Count (Fan-In)

| File | Imported By | Symbols | Language |
|------|-------------|---------|----------|
| `audiobox_vsl.h` | 3 | 7 | h |

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

- `audiobox_vsl.c` (c, 8 symbols)
- `audiobox_vsl.h` (h, 7 symbols)
- `vsl_config.h` (h, 8 symbols)
- `vsl_config.py` (py, 3 symbols)
- `vsl_config.h` (h, 13 symbols)

### utility

- `install.sh` (sh, 0 symbols)
- `app.py` (py, 0 symbols)
- `main.c` (c, 3 symbols)
- `vsl_core.py` (py, 5 symbols)
- `vsl_dsp_transport.c` (c, 12 symbols)
- `vsl_dsp_transport.h` (h, 7 symbols)
- `vsl_hid_io.py` (py, 9 symbols)
- `vsl_poc_main.py` (py, 7 symbols)
- `vsl_protocol_analyzer.py` (py, 7 symbols)
- `vsl_transport.py` (py, 8 symbols)
- `vsl_cli.c` (c, 14 symbols)
- `vsl_dsp_transport.c` (c, 14 symbols)
- `vsl_dsp_transport.h` (h, 6 symbols)
- `vc_alsa.c` (c, 24 symbols)
- `vc_alsa.h` (h, 5 symbols)
- *... and 16 more*

### presentation

- `build-dkms.sh` (sh, 19 symbols)
- `mixer_quirks.c` (c, 344 symbols)

### testing

- `test.sh` (sh, 0 symbols)
- `test_connection.c` (c, 3 symbols)
- `test_audiobox_vsl.c` (c, 17 symbols)
- `test_vsl_dsp_logic.c` (c, 19 symbols)
- `test_vc_fft.c` (c, 9 symbols)
- `test_vc_stream.c` (c, 24 symbols)

### business_logic

- `vsl_dsp_logic.c` (c, 6 symbols)
- `vsl_dsp_logic.h` (h, 7 symbols)
- `vsl_dsp_logic.c` (c, 7 symbols)
- `vsl_dsp_logic.h` (h, 9 symbols)

### data_access

- `vc_rt_seed.c` (c, 2 symbols)

---

## Ranked Context

Files ranked by composite score for the current query context. The ranking combines Personalized PageRank (query relevance), global authority, test coverage, documentation coverage, and code freshness. Model: v1.0.

| Rank | File | Composite | PPR | Authority | Test | Doc |
|------|------|-----------|-----|-----------|------|-----|
| 1 | `vsl_dsp_logic.c` | 0.1258 | 0.0141 | 0.0141 | 0.00 | 1.17 |
| 2 | `vc_rt.h` | 0.1250 | 0.0385 | 0.0385 | 0.00 | 1.00 |
| 3 | `vc_stream.h` | 0.1210 | 0.0516 | 0.0516 | 0.00 | 0.88 |
| 4 | `vsl_dsp_transport.h` | 0.1196 | 0.0301 | 0.0301 | 0.00 | 1.00 |
| 5 | `vc_wav.h` | 0.1196 | 0.0301 | 0.0301 | 0.00 | 1.00 |
| 6 | `vc_stft.h` | 0.1157 | 0.0241 | 0.0241 | 0.00 | 1.00 |
| 7 | `vsl_core.py` | 0.1137 | 0.0211 | 0.0211 | 0.00 | 1.00 |
| 8 | `main.c` | 0.1092 | 0.0141 | 0.0141 | 0.00 | 1.00 |
| 9 | `vsl_poc_main.py` | 0.1092 | 0.0141 | 0.0141 | 0.00 | 1.00 |
| 10 | `vc_rt_seed.c` | 0.1092 | 0.0141 | 0.0141 | 0.00 | 1.00 |

---

## God Nodes

Most architecturally central files ranked by combined import/export degree and symbol richness.

| File | Score | Connections | PageRank |
|------|-------|-------------|----------|
| `mixer_quirks.c` | 36.4 | | 0.0000 |
| `vsl_config.h` | 14.8 | | 0.0000 |
| `vc_fft.h` | 12.2 | | 0.0000 |
| `vc_rt_cli.c` | 12.0 | | 0.0000 |
| `vc_crypto.h` | 11.6 | | 0.0000 |
| `vc_stream.h` | 10.8 | | 0.0516 |
| `vc_rt.h` | 9.0 | | 0.0385 |
| `vsl_dsp_transport.h` | 8.7 | | 0.0000 |
| `vsl_dsp_transport.h` | 8.6 | | 0.0301 |
| `test_vc_stream.c` | 8.4 | | 0.0000 |

---

## Community Analysis

Files grouped by import-based community detection. Cohesion measures how tightly connected each community is internally.

### root (Cohesion: 1.00)

**4 files** in this community:

- `audiobox_vsl.c` (c, 8 symbols)
- `audiobox_vsl.h` (h, 7 symbols)
- `mixer_quirks.c` (c, 344 symbols)
- `test_audiobox_vsl.c` (c, 17 symbols)

### legacy (Cohesion: 0.93)

**9 files** in this community:

- `main.c` (c, 3 symbols)
- `test_connection.c` (c, 3 symbols)
- `vsl_config.h` (h, 8 symbols)
- `vsl_core.py` (py, 5 symbols)
- `vsl_dsp_transport.c` (c, 12 symbols)
- `vsl_dsp_transport.h` (h, 7 symbols)
- `vsl_hid_io.py` (py, 9 symbols)
- `vsl_poc_main.py` (py, 7 symbols)
- `vsl_transport.py` (py, 8 symbols)

### legacy (Cohesion: 0.50)

**2 files** in this community:

- `vsl_dsp_logic.c` (c, 6 symbols)
- `vsl_dsp_logic.h` (h, 7 symbols)

### src (Cohesion: 1.00)

**6 files** in this community:

- `vsl_cli.c` (c, 14 symbols)
- `vsl_config.h` (h, 13 symbols)
- `vsl_dsp_logic.c` (c, 7 symbols)
- `vsl_dsp_logic.h` (h, 9 symbols)
- `vsl_dsp_transport.c` (c, 14 symbols)
- `vsl_dsp_transport.h` (h, 6 symbols)

### voicecloak/src (Cohesion: 0.83)

**11 files** in this community:

- `vc_alsa.c` (c, 24 symbols)
- `vc_alsa.h` (h, 5 symbols)
- `vc_fft.c` (c, 5 symbols)
- `vc_fft.h` (h, 2 symbols)
- `vc_rt.c` (c, 12 symbols)
- `vc_rt.h` (h, 10 symbols)
- `vc_rt_cli.c` (c, 20 symbols)
- `vc_stream.c` (c, 12 symbols)
- `vc_stream.h` (h, 8 symbols)
- `test_vc_fft.c` (c, 9 symbols)
- `test_vc_stream.c` (c, 24 symbols)

### voicecloak/src (Cohesion: 0.38)

**4 files** in this community:

- `vc_cli.c` (c, 11 symbols)
- `vc_crypto.c` (c, 18 symbols)
- `vc_crypto.h` (h, 16 symbols)
- `vc_rt_seed.c` (c, 2 symbols)

### voicecloak/src (Cohesion: 0.50)

**4 files** in this community:

- `vc_dsp.c` (c, 16 symbols)
- `vc_dsp.h` (h, 6 symbols)
- `vc_stft.c` (c, 11 symbols)
- `vc_stft.h` (h, 9 symbols)

### voicecloak/src (Cohesion: 0.50)

**2 files** in this community:

- `vc_wav.c` (c, 15 symbols)
- `vc_wav.h` (h, 3 symbols)

---

## Surprising Connections

Files in different communities connected through 3+ indirect hops.

- `vc_alsa.c` <-> `vc_wav.c` (6 hops, across 3 communities)
- `vc_fft.c` <-> `vc_wav.c` (6 hops, across 3 communities)
- `vc_rt.c` <-> `vc_wav.c` (6 hops, across 3 communities)
- `vc_stft.c` <-> `vc_wav.c` (6 hops, across 3 communities)
- `vc_stream.c` <-> `vc_wav.c` (6 hops, across 3 communities)

---

## Suggested Questions

Auto-generated exploration prompts based on graph structure:

- What does mixer_quirks.c depend on, and what depends on it? (1 connections)
- What does vsl_config.h depend on, and what depends on it? (7 connections)
- What does vc_fft.h depend on, and what depends on it? (6 connections)
- How are the 4 files in 'root' related to each other?
- Why are vc_alsa.c and vc_wav.c connected through 6 hops across 3 communities?

---

## Taint Propagation Map

Taint analysis traces how dangerous imports propagate through the codebase via transitive dependencies. Source files import dangerous modules directly; sink files receive the danger indirectly.

**Taint Sources:** 1 | **Taint Sinks:** 2 | **Propagation Paths:** 2

- `mixer_quirks.c` imports `input` (0 hop to `mixer_quirks.c`) [medium]
  Path: mixer_quirks.c
- `mixer_quirks.c` imports `input` (1 hop to `audiobox_vsl.h`) [medium]
  Path: mixer_quirks.c -> audiobox_vsl.h

---

## Hotspot Analysis

Files ranked by combined complexity (symbol count) and centrality (connection count). High-scoring files are architecturally critical and may need refactoring attention.

| File | Complexity | Centrality | Combined | Symbols | Connections |
|------|-----------|------------|----------|---------|-------------|
| `vsl_dsp_logic.c` | 0.017 | 0.077 | 0.053 | 6 | 2 |
| `vc_rt.h` | 0.029 | 0.231 | 0.150 | 10 | 6 |
| `vc_stream.h` | 0.023 | 0.269 | 0.171 | 8 | 7 |
| `vsl_dsp_transport.h` | 0.017 | 0.269 | 0.169 | 6 | 7 |
| `vc_wav.h` | 0.009 | 0.154 | 0.096 | 3 | 4 |
| `vc_stft.h` | 0.026 | 0.154 | 0.103 | 9 | 4 |
| `vsl_core.py` | 0.015 | 0.308 | 0.190 | 5 | 8 |
| `main.c` | 0.009 | 0.192 | 0.119 | 3 | 5 |
| `vsl_poc_main.py` | 0.020 | 0.346 | 0.216 | 7 | 9 |
| `vc_rt_seed.c` | 0.006 | 0.192 | 0.118 | 2 | 5 |
| `mixer_quirks.c` | 1.000 | 1.000 | 1.000 | 344 | 26 |
| `vc_rt_cli.c` | 0.058 | 0.577 | 0.369 | 20 | 15 |
| `test_vc_stream.c` | 0.070 | 0.500 | 0.328 | 24 | 13 |
| `vsl_hid_io.py` | 0.026 | 0.462 | 0.287 | 9 | 12 |
| `vc_crypto.c` | 0.052 | 0.423 | 0.275 | 18 | 11 |

---

## Change Impact Analysis

Files sorted by how many other files would be affected if they changed. High-impact files should be changed with caution.

| File | Direct Dependents | Transitive Dependents | Total Impact |
|------|------------------|----------------------|--------------|
| `vsl_config.h` | 7 | 1 | 8 |
| `vc_fft.h` | 6 | 0 | 6 |
| `vc_crypto.h` | 5 | 0 | 5 |
| `vc_stream.h` | 5 | 0 | 5 |
| `vsl_dsp_logic.h` | 3 | 1 | 4 |
| `vc_rt.h` | 4 | 0 | 4 |
| `audiobox_vsl.h` | 3 | 0 | 3 |
| `vsl_dsp_transport.h` | 3 | 0 | 3 |
| `vsl_config.h` | 2 | 1 | 3 |
| `vsl_core.py` | 2 | 0 | 2 |
| `vsl_dsp_logic.h` | 2 | 0 | 2 |
| `vsl_transport.py` | 2 | 0 | 2 |
| `vsl_dsp_transport.h` | 2 | 0 | 2 |
| `vc_alsa.h` | 2 | 0 | 2 |
| `vc_dsp.h` | 2 | 0 | 2 |

---

## Suggested Linting Rules

Automatically suggested linting and security rules based on patterns detected in the codebase. These can be exported as Semgrep rules using the `--export-rules` flag.

| Rule ID | Severity | Description | Language | Matches |
|---------|----------|-------------|----------|---------|
| `RM001` | info | Large number of functions in c: 458 total | c | 458 |
| `RM002` | info | Large number of functions in h: 56 total | h | 56 |
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
    subgraph community_4 ["voicecloak/src"]
    voicecloak_src_vc_rt_cli_c["vc_rt_cli.c (c)"]
    class voicecloak_src_vc_rt_cli_c mod;
    voicecloak_tests_test_vc_stream_c["test_vc_stream.c (c)"]
    class voicecloak_tests_test_vc_stream_c mod;
    end
    subgraph community_1 ["legacy"]
    legacy_vsl_hid_io_py["vsl_hid_io.py (py)"]
    class legacy_vsl_hid_io_py mod;
    end
    subgraph community_5 ["voicecloak/src"]
    voicecloak_src_vc_crypto_c["vc_crypto.c (c)"]
    class voicecloak_src_vc_crypto_c mod;
    end
    subgraph community_3 ["src"]
    src_vsl_cli_c["vsl_cli.c (c)"]
    class src_vsl_cli_c mod;
    voicecloak_src_vc_alsa_c["vc_alsa.c (c)"]
    class voicecloak_src_vc_alsa_c mod;
    end
    subgraph community_6 ["voicecloak/src"]
    voicecloak_src_vc_dsp_c["vc_dsp.c (c)"]
    class voicecloak_src_vc_dsp_c mod;
    voicecloak_src_vc_cli_c["vc_cli.c (c)"]
    class voicecloak_src_vc_cli_c mod;
    legacy_vsl_dsp_transport_c["vsl_dsp_transport.c (c)"]
    class legacy_vsl_dsp_transport_c mod;
    voicecloak_tests_test_vc_fft_c["test_vc_fft.c (c)"]
    class voicecloak_tests_test_vc_fft_c mod;
    legacy_vsl_poc_main_py["vsl_poc_main.py (py)"]
    class legacy_vsl_poc_main_py mod;
    tests_test_vsl_dsp_logic_c["test_vsl_dsp_logic.c (c)"]
    class tests_test_vsl_dsp_logic_c mod;
    tests_test_audiobox_vsl_c["test_audiobox_vsl.c (c)"]
    class tests_test_audiobox_vsl_c mod;
    end
    subgraph community_7 ["voicecloak/src"]
    voicecloak_src_vc_wav_c["vc_wav.c (c)"]
    class voicecloak_src_vc_wav_c mod;
    voicecloak_src_vc_stream_c["vc_stream.c (c)"]
    class voicecloak_src_vc_stream_c mod;
    voicecloak_src_vc_stft_c["vc_stft.c (c)"]
    class voicecloak_src_vc_stft_c mod;
    src_vsl_dsp_transport_c["vsl_dsp_transport.c (c)"]
    class src_vsl_dsp_transport_c mod;
    legacy_vsl_core_py["vsl_core.py (py)"]
    class legacy_vsl_core_py mod;
    voicecloak_src_vc_rt_c["vc_rt.c (c)"]
    class voicecloak_src_vc_rt_c mod;
    audiobox_vsl_c["audiobox_vsl.c (c)"]
    class audiobox_vsl_c mod;
    legacy_vsl_transport_py["vsl_transport.py (py)"]
    class legacy_vsl_transport_py mod;
    legacy_vsl_dsp_transport_h["vsl_dsp_transport.h (h)"]
    class legacy_vsl_dsp_transport_h mod;
    legacy_vsl_protocol_analyzer_py["vsl_protocol_analyzer.py (py)"]
    class legacy_vsl_protocol_analyzer_py mod;
    src_vsl_dsp_transport_h["vsl_dsp_transport.h (h)"]
    class src_vsl_dsp_transport_h mod;
    voicecloak_src_vc_alsa_h["vc_alsa.h (h)"]
    class voicecloak_src_vc_alsa_h mod;
    voicecloak_src_vc_fft_c["vc_fft.c (c)"]
    class voicecloak_src_vc_fft_c mod;
    legacy_main_c["main.c (c)"]
    class legacy_main_c mod;
    legacy_test_connection_c["test_connection.c (c)"]
    class legacy_test_connection_c mod;
    voicecloak_src_vc_rt_seed_c["vc_rt_seed.c (c)"]
    class voicecloak_src_vc_rt_seed_c mod;
    src_vsl_dsp_logic_h["vsl_dsp_logic.h (h)"]
    class src_vsl_dsp_logic_h mod;
    audiobox_vsl_h["audiobox_vsl.h (h)"]
    class audiobox_vsl_h mod;
    end
    subgraph community_2 ["legacy"]
    legacy_vsl_dsp_logic_h["vsl_dsp_logic.h (h)"]
    class legacy_vsl_dsp_logic_h mod;
    voicecloak_src_vc_crypto_h["vc_crypto.h (h)"]
    class voicecloak_src_vc_crypto_h mod;
    src_vsl_config_h["vsl_config.h (h)"]
    class src_vsl_config_h mod;
    voicecloak_src_vc_rt_h["vc_rt.h (h)"]
    class voicecloak_src_vc_rt_h mod;
    voicecloak_src_vc_stft_h["vc_stft.h (h)"]
    class voicecloak_src_vc_stft_h mod;
    voicecloak_src_vc_stream_h["vc_stream.h (h)"]
    class voicecloak_src_vc_stream_h mod;
    src_vsl_dsp_logic_c["vsl_dsp_logic.c (c)"]
    class src_vsl_dsp_logic_c mod;
    legacy_vsl_dsp_logic_c["vsl_dsp_logic.c (c)"]
    class legacy_vsl_dsp_logic_c mod;
    voicecloak_src_vc_dsp_h["vc_dsp.h (h)"]
    class voicecloak_src_vc_dsp_h mod;
    legacy_vsl_config_py["vsl_config.py (py)"]
    class legacy_vsl_config_py mod;
    voicecloak_src_vc_wav_h["vc_wav.h (h)"]
    class voicecloak_src_vc_wav_h mod;
    legacy_vsl_config_h["vsl_config.h (h)"]
    class legacy_vsl_config_h mod;
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
    audiobox_vsl_c -- resolved_imports --> audiobox_vsl_h
    legacy_main_c -- resolved_imports --> legacy_vsl_dsp_logic_h
    legacy_main_c -- resolved_imports --> legacy_vsl_dsp_transport_h
    legacy_mixer_quirks_c -- resolved_imports --> audiobox_vsl_h
    legacy_test_connection_c -- resolved_imports --> legacy_vsl_config_h
    legacy_test_connection_c -- resolved_imports --> legacy_vsl_dsp_transport_h
    legacy_vsl_core_py -- resolved_imports --> legacy_vsl_config_h
    legacy_vsl_core_py -- resolved_imports --> legacy_vsl_config_h
    legacy_vsl_dsp_logic_c -- resolved_imports --> legacy_vsl_dsp_logic_h
    legacy_vsl_dsp_transport_c -- resolved_imports --> legacy_vsl_config_h
    legacy_vsl_dsp_transport_c -- resolved_imports --> legacy_vsl_dsp_transport_h
    legacy_vsl_dsp_transport_h -- resolved_imports --> legacy_vsl_config_h
    legacy_vsl_hid_io_py -- resolved_imports --> legacy_vsl_config_h
    legacy_vsl_hid_io_py -- resolved_imports --> legacy_vsl_transport_py
    legacy_vsl_hid_io_py -- resolved_imports --> legacy_vsl_config_h
    legacy_vsl_hid_io_py -- resolved_imports --> legacy_vsl_core_py
    legacy_vsl_poc_main_py -- resolved_imports --> legacy_vsl_config_h
    legacy_vsl_poc_main_py -- resolved_imports --> legacy_vsl_core_py
    legacy_vsl_poc_main_py -- resolved_imports --> legacy_vsl_transport_py
    legacy_vsl_transport_py -- resolved_imports --> legacy_vsl_config_h
    legacy_vsl_transport_py -- resolved_imports --> legacy_vsl_config_h
    src_vsl_cli_c -- resolved_imports --> src_vsl_dsp_logic_h
    src_vsl_cli_c -- resolved_imports --> src_vsl_dsp_transport_h
    src_vsl_cli_c -- resolved_imports --> src_vsl_config_h
    src_vsl_dsp_logic_c -- resolved_imports --> src_vsl_dsp_logic_h
    src_vsl_dsp_transport_c -- resolved_imports --> src_vsl_dsp_transport_h
    src_vsl_dsp_transport_h -- resolved_imports --> src_vsl_dsp_logic_h
    src_vsl_dsp_transport_h -- resolved_imports --> src_vsl_config_h
    tests_test_audiobox_vsl_c -- resolved_imports --> audiobox_vsl_h
    voicecloak_src_vc_alsa_c -- resolved_imports --> voicecloak_src_vc_alsa_h
    voicecloak_src_vc_alsa_c -- resolved_imports --> voicecloak_src_vc_stream_h
    voicecloak_src_vc_alsa_h -- resolved_imports --> voicecloak_src_vc_stream_h
    voicecloak_src_vc_cli_c -- resolved_imports --> voicecloak_src_vc_wav_h
    voicecloak_src_vc_cli_c -- resolved_imports --> voicecloak_src_vc_dsp_h
    voicecloak_src_vc_cli_c -- resolved_imports --> voicecloak_src_vc_crypto_h
    voicecloak_src_vc_crypto_c -- resolved_imports --> voicecloak_src_vc_crypto_h
    voicecloak_src_vc_dsp_c -- resolved_imports --> voicecloak_src_vc_dsp_h
    voicecloak_src_vc_dsp_c -- resolved_imports --> voicecloak_src_vc_stft_h
    voicecloak_src_vc_dsp_c -- resolved_imports --> voicecloak_src_vc_crypto_h
    voicecloak_src_vc_fft_c -- resolved_imports --> voicecloak_src_vc_fft_h
    voicecloak_src_vc_rt_c -- resolved_imports --> voicecloak_src_vc_rt_h
    voicecloak_src_vc_rt_cli_c -- resolved_imports --> voicecloak_src_vc_alsa_h
    voicecloak_src_vc_rt_cli_c -- resolved_imports --> voicecloak_src_vc_stream_h
    voicecloak_src_vc_rt_cli_c -- resolved_imports --> voicecloak_src_vc_rt_h
    voicecloak_src_vc_rt_cli_c -- resolved_imports --> voicecloak_src_vc_fft_h
    voicecloak_src_vc_rt_cli_c -- resolved_imports --> voicecloak_src_vc_crypto_h
    voicecloak_src_vc_rt_seed_c -- resolved_imports --> voicecloak_src_vc_rt_h
    voicecloak_src_vc_rt_seed_c -- resolved_imports --> voicecloak_src_vc_crypto_h
    voicecloak_src_vc_stft_c -- resolved_imports --> voicecloak_src_vc_stft_h
    voicecloak_src_vc_stft_c -- resolved_imports --> voicecloak_src_vc_fft_h
    voicecloak_src_vc_stream_c -- resolved_imports --> voicecloak_src_vc_stream_h
    voicecloak_src_vc_stream_c -- resolved_imports --> voicecloak_src_vc_fft_h
    voicecloak_src_vc_wav_c -- resolved_imports --> voicecloak_src_vc_wav_h
    voicecloak_tests_test_vc_fft_c -- resolved_imports --> voicecloak_src_vc_fft_h
    voicecloak_tests_test_vc_stream_c -- resolved_imports --> voicecloak_src_vc_stream_h
    voicecloak_tests_test_vc_stream_c -- resolved_imports --> voicecloak_src_vc_rt_h
    voicecloak_tests_test_vc_stream_c -- resolved_imports --> voicecloak_src_vc_fft_h
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
    +snd_audiobox_vsl_init(struct usb_mixer_interface *mixer);
  }
  class audiobox_vsl_h_audiobox_model_info_t {
    <<struct>>
    +audiobox_lookup_model(uint16_t pid)
    +snd_audiobox_vsl_init(struct usb_mixer_interface *mixer);
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
  class mixer_quirks_c_snd_rme_domain {
    <<enum>>
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
  class mixer_quirks_c_snd_rme_clock_status {
    <<enum>>
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
  class vsl_dsp_logic_h_VSL_Parameter {
    <<struct>>
    +VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);
    +VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);
    +VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param);
    +VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);
  }
  class vsl_dsp_transport_h_VSL_DSP_Packet {
    <<struct>>
    +VSL_Init_Device(uint16_t vendor_id, uint16_t product_id);
    +VSL_Close_Device(void);
    +VSL_Get_Device_Handle(void);
    +FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length);
    +VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float);
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
  class vsl_cli_c_ParamEntry {
    <<struct>>
    +print_usage(FILE *fp, const char *prog)
    +print_version(void)
    +print_list(uint16_t product_id)
    +lookup_coeffs_by_param_id(uint16_t param_id)
    +find_entry_by_name(const char *name)
    +do_send(uint16_t product_id,
                   uint16_t param_id,
                   ...
    +do_send_freq(uint16_t product_id,
                        uint16_t param_id,
         ...
    +main(int argc, char *argv[])
    +fprintf(fp, "Usage: %s [OPTIONS] COMMAND [ARGS...]\n" "\n" "Options:\n" " -p, --pid <hex> USB product ID (default: 0x0101 = 22 VSL)\n" " -m, --model <tag> Model tag: 22vsl, 44vsl, 1818vsl\n" " -h, --h
    +printf("vsl-cli 2.0.0\n" "PreSonus AudioBox VSL DSP control tool\n" "License: AGPL-3.0-or-later\n");
  }
  class vsl_config_h_VSL_ModelInfo {
    <<struct>>
    +VSL_ModelLookup(uint16_t pid)
    +VSL_ModelLookupByTag(const char *tag)
  }
  class vsl_dsp_logic_h_VSL_Parameter {
    <<struct>>
    +VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);
    +VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param);
    +VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);
    +VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);
    +VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param);
  }
  class vsl_dsp_transport_c_vsl_device {
    <<struct>>
    +VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)
    +VSL_Close_Device(vsl_device_handle handle)
    +VSL_Send_Parameter(vsl_device_handle handle,
                       uint16_t dsp_param_id,
  ...
    +free(dev);
    +libusb_exit(NULL);
    +libusb_set_auto_detach_kernel_driver(dev->handle, 1);
    +libusb_detach_kernel_driver(dev->handle, VSL_MIDI_IFACE);
    +libusb_claim_interface(dev->handle, VSL_MIDI_IFACE);
    +libusb_release_interface(dev->handle, VSL_MIDI_IFACE);
    +libusb_attach_kernel_driver(dev->handle, VSL_MIDI_IFACE);
  }
  class vc_alsa_c_vc_pcm_t {
    <<struct>>
    +fmt_bps(snd_pcm_format_t f)
    +open_stream(vc_pcm_t *s, const char *dev, snd_pcm_stream_t dir,
                      ...
    +raw_to_mono(const unsigned char *raw, float *mono,
                        snd_pcm_uf...
    +mono_to_raw(unsigned char *raw, const float *mono,
                        snd_pcm_uf...
    +vc_alsa_list(void)
    +vc_alsa_run(const vc_alsa_cfg_t *cfg)
    +fprintf(stderr, "vc_alsa: cannot open %s device '%s': %s\n", tag, dev, snd_strerror(err));
    +snd_pcm_hw_params_alloca(&hw);
    +snd_pcm_hw_params_any(s->pcm, hw);
    +snd_pcm_hw_params_set_buffer_size_near(s->pcm, hw, &buffer);
  }
  class vc_alsa_h_vc_alsa_cfg_t {
    <<struct>>
    +runtime(e.g. "hw:VSL", "plughw:2,0", "default");
    +vc_alsa_list(void);
    +vc_alsa_run(const vc_alsa_cfg_t *cfg);
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
    +fclose(fp);
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
    +free(c->prev_phase);
    +memset(c->prev_phase, 0, c->nbins * sizeof(double));
    +powf(2.0f, semitones / 12.0f);
  }
  class vc_rt_h_vc_rt_params_t {
    <<struct>>
    +vc_rt_create(size_t nbins, vc_rt_params_t params);
    +vc_rt_destroy(vc_rt_ctx_t *c);
    +vc_rt_reset(vc_rt_ctx_t *c);
    +vc_rt_transform(float *mag, float *phase, size_t nbins, uint32_t sample_rate, size_t hop, void *user);
    +vc_rt_semitones_to_ratio(float semitones);
    +vc_rt_derive(const unsigned char *pitch_seed, const unsigned char *formant_seed, const unsigned char *spectral_seed, int witness_mode, vc_rt_params_t *out);
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
    +memset(st->win_sq_sum, 0, fft_size * sizeof(float));
    +free(st->window);
    +vc_fft(fft_n, st->buf_r, st->buf_i, 0);
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
    +free(st->window);
    +vc_fft(N, st->buf_r, st->buf_i, 0);
    +memmove(st->out_accum, st->out_accum + st->hop_size, (N - st->hop_size) * sizeof(float));
    +memset(st->out_accum + (N - st->hop_size), 0, st->hop_size * sizeof(float));
  }
  class vc_wav_c_WavHeader {
    <<struct>>
    +read_bytes(FILE *fp, void *buf, size_t n)
    +write_bytes(FILE *fp, const void *buf, size_t n)
    +sample_to_float(const unsigned char *p, int bps)
    +float_to_sample(float f, unsigned char *p, int bps)
    +find_chunk(FILE *fp, const char *id, uint32_t *size)
    +vc_wav_read(const char *path,
                float **samples_out, size_t *num_samples_out,
 ...
    +vc_wav_write(const char *path,
                 const float *samples, size_t num_samples,
   ...
    +memcpy(&v, p, 2);
    +fseek(fp, (long)sz, SEEK_CUR);
    +memset(&fmt, 0, sizeof(fmt));
  }
  class vc_wav_c_WavFmtBody {
    <<struct>>
    +read_bytes(FILE *fp, void *buf, size_t n)
    +write_bytes(FILE *fp, const void *buf, size_t n)
    +sample_to_float(const unsigned char *p, int bps)
    +float_to_sample(float f, unsigned char *p, int bps)
    +find_chunk(FILE *fp, const char *id, uint32_t *size)
    +vc_wav_read(const char *path,
                float **samples_out, size_t *num_samples_out,
 ...
    +vc_wav_write(const char *path,
                 const float *samples, size_t num_samples,
   ...
    +memcpy(&v, p, 2);
    +fseek(fp, (long)sz, SEEK_CUR);
    +memset(&fmt, 0, sizeof(fmt));
  }
  class vc_wav_c_WavDataChunk {
    <<struct>>
    +read_bytes(FILE *fp, void *buf, size_t n)
    +write_bytes(FILE *fp, const void *buf, size_t n)
    +sample_to_float(const unsigned char *p, int bps)
    +float_to_sample(float f, unsigned char *p, int bps)
    +find_chunk(FILE *fp, const char *id, uint32_t *size)
    +vc_wav_read(const char *path,
                float **samples_out, size_t *num_samples_out,
 ...
    +vc_wav_write(const char *path,
                 const float *samples, size_t num_samples,
   ...
    +memcpy(&v, p, 2);
    +fseek(fp, (long)sz, SEEK_CUR);
    +memset(&fmt, 0, sizeof(fmt));
  }
  mixer_quirks_c_dualsense_mixer_elem_info --> audiobox_vsl_h_audiobox_model_info_t : uses
  mixer_quirks_c_dualsense_mixer_elem_info --> audiobox_vsl_h_usb_mixer_interface : uses
  mixer_quirks_c_rc_config --> audiobox_vsl_h_audiobox_model_info_t : uses
  mixer_quirks_c_rc_config --> audiobox_vsl_h_usb_mixer_interface : uses
  mixer_quirks_c_sb_jack --> audiobox_vsl_h_audiobox_model_info_t : uses
  mixer_quirks_c_sb_jack --> audiobox_vsl_h_usb_mixer_interface : uses
  mixer_quirks_c_snd_djm_ctl --> audiobox_vsl_h_audiobox_model_info_t : uses
  mixer_quirks_c_snd_djm_ctl --> audiobox_vsl_h_usb_mixer_interface : uses
  mixer_quirks_c_snd_djm_device --> audiobox_vsl_h_audiobox_model_info_t : uses
  mixer_quirks_c_snd_djm_device --> audiobox_vsl_h_usb_mixer_interface : uses
  mixer_quirks_c_snd_rme_clock_status --> audiobox_vsl_h_audiobox_model_info_t : uses
  mixer_quirks_c_snd_rme_clock_status --> audiobox_vsl_h_usb_mixer_interface : uses
  mixer_quirks_c_snd_rme_domain --> audiobox_vsl_h_audiobox_model_info_t : uses
  mixer_quirks_c_snd_rme_domain --> audiobox_vsl_h_usb_mixer_interface : uses
  mixer_quirks_c_std_mono_table --> audiobox_vsl_h_audiobox_model_info_t : uses
  mixer_quirks_c_std_mono_table --> audiobox_vsl_h_usb_mixer_interface : uses
```

---

## Code Property Graph

Machine-readable Code Property Graph (CPG) in JSON-LD format. This block allows AI agents to parse the full structural graph without additional file reads. Compatible with GraphRAG pipelines.

```json
{"@context": "https://schema.org", "analysis": {"communities": [{"cohesion": 1.0, "id": 0, "label": "root", "size": 4}, {"cohesion": 0.933, "id": 1, "label": "legacy", "size": 9}, {"cohesion": 0.5, "id": 2, "label": "legacy", "size": 2}, {"cohesion": 1.0, "id": 3, "label": "src", "size": 6}, {"cohesion": 0.833, "id": 4, "label": "voicecloak/src", "size": 11}, {"cohesion": 0.375, "id": 5, "label": "voicecloak/src", "size": 4}, {"cohesion": 0.5, "id": 6, "label": "voicecloak/src", "size": 4}, {"cohesion": 0.5, "id": 7, "label": "voicecloak/src", "size": 2}], "god_nodes": [{"node_id": "legacy/mixer_quirks.c", "score": 36.4}, {"node_id": "legacy/vsl_config.h", "score": 14.8}, {"node_id": "voicecloak/src/vc_fft.h", "score": 12.2}, {"node_id": "voicecloak/src/vc_rt_cli.c", "score": 12.0}, {"node_id": "voicecloak/src/vc_crypto.h", "score": 11.6}, {"node_id": "voicecloak/src/vc_stream.h", "score": 10.8}, {"node_id": "voicecloak/src/vc_rt.h", "score": 9.0}, {"node_id": "legacy/vsl_dsp_transport.h", "score": 8.7}, {"node_id": "src/vsl_dsp_transport.h", "score": 8.6}, {"node_id": "voicecloak/tests/test_vc_stream.c", "score": 8.4}], "surprising_connections": [{"hops": 6, "source": "voicecloak/src/vc_alsa.c", "target": "voicecloak/src/vc_wav.c"}, {"hops": 6, "source": "voicecloak/src/vc_fft.c", "target": "voicecloak/src/vc_wav.c"}, {"hops": 6, "source": "voicecloak/src/vc_rt.c", "target": "voicecloak/src/vc_wav.c"}, {"hops": 6, "source": "voicecloak/src/vc_stft.c", "target": "voicecloak/src/vc_wav.c"}, {"hops": 6, "source": "voicecloak/src/vc_stream.c", "target": "voicecloak/src/vc_wav.c"}]}, "edges": [{"confidence": "EXTRACTED", "relation": "imports", "source": "audiobox_vsl.c", "target": "audiobox_vsl.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "audiobox_vsl.c", "target": "linux/module.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "audiobox_vsl.c", "target": "linux/printk.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "audiobox_vsl.c", "target": "linux/usb.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "audiobox_vsl.h", "target": "linux/types.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "audiobox_vsl.h", "target": "linux/usb.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "audiobox_vsl.h", "target": "sound/core.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/main.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/main.c", "target": "vsl_dsp_logic.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/main.c", "target": "vsl_dsp_transport.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "linux/bitfield.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "linux/hid.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "linux/init.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "linux/input.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "linux/math64.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "linux/slab.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "linux/usb.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "linux/usb/audio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "sound/asoundef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "sound/core.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "sound/control.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "sound/hda_verbs.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "sound/hwdep.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "sound/info.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "sound/tlv.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "usbaudio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "mixer.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "mixer_quirks.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "audiobox_vsl.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "mixer_scarlett.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "mixer_scarlett2.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "mixer_us16x08.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "mixer_s1810c.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "helper.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/mixer_quirks.c", "target": "fcp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/test_connection.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/test_connection.c", "target": "vsl_config.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/test_connection.c", "target": "vsl_dsp_transport.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_config.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_config.py", "target": "sys"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_config.py", "target": "typing"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_core.py", "target": "math"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_core.py", "target": "typing"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_core.py", "target": "vsl_config"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_core.py", "target": "vsl_config"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_logic.c", "target": "vsl_dsp_logic.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_logic.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_logic.h", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_logic.h", "target": "float.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_transport.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_transport.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_transport.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_transport.c", "target": "hidapi/hidapi.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_transport.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_transport.c", "target": "vsl_config.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_transport.c", "target": "vsl_dsp_transport.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_transport.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_transport.h", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_transport.h", "target": "hidapi/hidapi.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_dsp_transport.h", "target": "vsl_config.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_hid_io.py", "target": "typing"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_hid_io.py", "target": "sys"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_hid_io.py", "target": "vsl_config"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_hid_io.py", "target": "vsl_transport"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_hid_io.py", "target": "hid"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_hid_io.py", "target": "vsl_config"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_hid_io.py", "target": "vsl_core"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_hid_io.py", "target": "traceback"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_poc_main.py", "target": "sys"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_poc_main.py", "target": "typing"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_poc_main.py", "target": "vsl_config"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_poc_main.py", "target": "vsl_core"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_poc_main.py", "target": "vsl_transport"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_poc_main.py", "target": "traceback"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_protocol_analyzer.py", "target": "math"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_protocol_analyzer.py", "target": "sys"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_protocol_analyzer.py", "target": "json"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_protocol_analyzer.py", "target": "typing"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_protocol_analyzer.py", "target": "scapy.all"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_transport.py", "target": "typing"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_transport.py", "target": "vsl_config"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "legacy/vsl_transport.py", "target": "vsl_config"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_cli.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_cli.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_cli.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_cli.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_cli.c", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_cli.c", "target": "vsl_dsp_logic.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_cli.c", "target": "vsl_dsp_transport.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_cli.c", "target": "vsl_config.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_config.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_config.h", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_dsp_logic.c", "target": "vsl_dsp_logic.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_dsp_logic.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_dsp_logic.h", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_dsp_logic.h", "target": "float.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_dsp_transport.c", "target": "vsl_dsp_transport.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_dsp_transport.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_dsp_transport.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_dsp_transport.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_dsp_transport.c", "target": "libusb-1.0/libusb.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_dsp_transport.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_dsp_transport.h", "target": "vsl_dsp_logic.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "src/vsl_dsp_transport.h", "target": "vsl_config.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_audiobox_vsl.c", "target": "stdarg.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_audiobox_vsl.c", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_audiobox_vsl.c", "target": "setjmp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_audiobox_vsl.c", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_audiobox_vsl.c", "target": "cmocka.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_audiobox_vsl.c", "target": "audiobox_vsl.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_vsl_dsp_logic.c", "target": "stdarg.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_vsl_dsp_logic.c", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_vsl_dsp_logic.c", "target": "setjmp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_vsl_dsp_logic.c", "target": "cmocka.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_vsl_dsp_logic.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_vsl_dsp_logic.c", "target": "float.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "tests/test_vsl_dsp_logic.c", "target": "vsl_dsp_logic.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_alsa.c", "target": "vc_alsa.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_alsa.c", "target": "vc_stream.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_alsa.c", "target": "alloca.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_alsa.c", "target": "alsa/asoundlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_alsa.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_alsa.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_alsa.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_alsa.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_alsa.h", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_alsa.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_alsa.h", "target": "signal.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_alsa.h", "target": "vc_stream.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_cli.c", "target": "vc_wav.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_cli.c", "target": "vc_dsp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_cli.c", "target": "vc_crypto.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_cli.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_cli.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_cli.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_cli.c", "target": "time.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_crypto.c", "target": "vc_crypto.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_crypto.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_crypto.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_crypto.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_crypto.c", "target": "openssl/evp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_crypto.c", "target": "openssl/pem.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_crypto.c", "target": "openssl/rsa.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_crypto.c", "target": "openssl/rand.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_crypto.c", "target": "openssl/err.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_crypto.c", "target": "openssl/hmac.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_crypto.h", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_crypto.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_dsp.c", "target": "vc_dsp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_dsp.c", "target": "vc_stft.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_dsp.c", "target": "vc_crypto.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_dsp.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_dsp.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_dsp.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_dsp.c", "target": "float.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_dsp.h", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_dsp.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_fft.c", "target": "vc_fft.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_fft.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_fft.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_fft.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_fft.h", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt.c", "target": "vc_rt.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt.h", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "vc_alsa.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "vc_stream.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "vc_rt.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "vc_fft.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "vc_crypto.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "signal.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_seed.c", "target": "vc_rt.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_seed.c", "target": "vc_crypto.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_rt_seed.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stft.c", "target": "vc_stft.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stft.c", "target": "vc_fft.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stft.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stft.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stft.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stft.h", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stft.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stream.c", "target": "vc_stream.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stream.c", "target": "vc_fft.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stream.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stream.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stream.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stream.h", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_stream.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_wav.c", "target": "vc_wav.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_wav.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_wav.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_wav.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_wav.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_wav.c", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_wav.h", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/src/vc_wav.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_fft.c", "target": "stdarg.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_fft.c", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_fft.c", "target": "setjmp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_fft.c", "target": "cmocka.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_fft.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_fft.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_fft.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_fft.c", "target": "vc_fft.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_stream.c", "target": "stdarg.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_stream.c", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_stream.c", "target": "setjmp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_stream.c", "target": "cmocka.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_stream.c", "target": "vc_stream.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_stream.c", "target": "vc_rt.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_stream.c", "target": "vc_fft.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_stream.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_stream.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "voicecloak/tests/test_vc_stream.c", "target": "math.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "audiobox_vsl.c", "target": "audiobox_vsl.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/main.c", "target": "legacy/vsl_dsp_logic.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/main.c", "target": "legacy/vsl_dsp_transport.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/mixer_quirks.c", "target": "audiobox_vsl.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/test_connection.c", "target": "legacy/vsl_config.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/test_connection.c", "target": "legacy/vsl_dsp_transport.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_core.py", "target": "legacy/vsl_config.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_core.py", "target": "legacy/vsl_config.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_dsp_logic.c", "target": "legacy/vsl_dsp_logic.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_dsp_transport.c", "target": "legacy/vsl_config.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_dsp_transport.c", "target": "legacy/vsl_dsp_transport.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_dsp_transport.h", "target": "legacy/vsl_config.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_hid_io.py", "target": "legacy/vsl_config.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_hid_io.py", "target": "legacy/vsl_transport.py"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_hid_io.py", "target": "legacy/vsl_config.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_hid_io.py", "target": "legacy/vsl_core.py"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_poc_main.py", "target": "legacy/vsl_config.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_poc_main.py", "target": "legacy/vsl_core.py"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_poc_main.py", "target": "legacy/vsl_transport.py"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_transport.py", "target": "legacy/vsl_config.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "legacy/vsl_transport.py", "target": "legacy/vsl_config.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "src/vsl_cli.c", "target": "src/vsl_dsp_logic.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "src/vsl_cli.c", "target": "src/vsl_dsp_transport.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "src/vsl_cli.c", "target": "src/vsl_config.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "src/vsl_dsp_logic.c", "target": "src/vsl_dsp_logic.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "src/vsl_dsp_transport.c", "target": "src/vsl_dsp_transport.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "src/vsl_dsp_transport.h", "target": "src/vsl_dsp_logic.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "src/vsl_dsp_transport.h", "target": "src/vsl_config.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "tests/test_audiobox_vsl.c", "target": "audiobox_vsl.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/src/vc_alsa.c", "target": "voicecloak/src/vc_alsa.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/src/vc_alsa.c", "target": "voicecloak/src/vc_stream.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/src/vc_alsa.h", "target": "voicecloak/src/vc_stream.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/src/vc_cli.c", "target": "voicecloak/src/vc_wav.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/src/vc_cli.c", "target": "voicecloak/src/vc_dsp.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/src/vc_cli.c", "target": "voicecloak/src/vc_crypto.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/src/vc_crypto.c", "target": "voicecloak/src/vc_crypto.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/src/vc_dsp.c", "target": "voicecloak/src/vc_dsp.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/src/vc_dsp.c", "target": "voicecloak/src/vc_stft.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/src/vc_dsp.c", "target": "voicecloak/src/vc_crypto.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/src/vc_fft.c", "target": "voicecloak/src/vc_fft.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/src/vc_rt.c", "target": "voicecloak/src/vc_rt.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "voicecloak/src/vc_alsa.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "voicecloak/src/vc_stream.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "voicecloak/src/vc_rt.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "voicecloak/src/vc_fft.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/src/vc_rt_cli.c", "target": "voicecloak/src/vc_crypto.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/src/vc_rt_seed.c", "target": "voicecloak/src/vc_rt.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/src/vc_rt_seed.c", "target": "voicecloak/src/vc_crypto.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/src/vc_stft.c", "target": "voicecloak/src/vc_stft.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/src/vc_stft.c", "target": "voicecloak/src/vc_fft.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/src/vc_stream.c", "target": "voicecloak/src/vc_stream.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/src/vc_stream.c", "target": "voicecloak/src/vc_fft.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/src/vc_wav.c", "target": "voicecloak/src/vc_wav.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/tests/test_vc_fft.c", "target": "voicecloak/src/vc_fft.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/tests/test_vc_stream.c", "target": "voicecloak/src/vc_stream.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/tests/test_vc_stream.c", "target": "voicecloak/src/vc_rt.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "voicecloak/tests/test_vc_stream.c", "target": "voicecloak/src/vc_fft.h"}], "generator": "readmenator", "metadata": {"edge_count": 529, "file_count": 49, "language_count": 4, "symbol_count": 800}, "nodes": [{"doc": "SPDX-License-Identifier: GPL-2.0-or-later", "id": "audiobox_vsl.c", "kind": "module", "label": "audiobox_vsl.c", "language": "c", "sha256": "9d6a79da66d347fc", "symbol_count": 8, "symbols": [{"kind": "function", "line": 36, "name": "audiobox_probe", "signature": "static int audiobox_probe(struct usb_interface *intf,\n                          const struct usb_..."}, {"kind": "function", "line": 58, "name": "audiobox_disconnect", "signature": "static void audiobox_disconnect(struct usb_interface *intf)"}, {"kind": "function", "line": 47, "name": "dev_info", "signature": "dev_info(&intf->dev, \"audiobox_vsl: detected '%s' (%04x:%04x)\\n\", name, le16_to_cpu(udev->descriptor.idVendor), pid);"}, {"kind": "function", "line": 78, "name": "module_usb_driver", "signature": "module_usb_driver(audiobox_driver);"}, {"kind": "function", "line": 80, "name": "MODULE_LICENSE", "signature": "MODULE_LICENSE(AUDIOBOX_DRIVER_LIC);"}, {"kind": "macro", "line": 24, "name": "AUDIOBOX_DRIVER_NAME", "signature": "#define AUDIOBOX_DRIVER_NAME"}, {"kind": "macro", "line": 26, "name": "AUDIOBOX_DRIVER_DESC", "signature": "#define AUDIOBOX_DRIVER_DESC"}, {"kind": "macro", "line": 27, "name": "AUDIOBOX_DRIVER_LIC", "signature": "#define AUDIOBOX_DRIVER_LIC"}]}, {"doc": "SPDX-License-Identifier: GPL-2.0-or-later", "id": "audiobox_vsl.h", "kind": "module", "label": "audiobox_vsl.h", "language": "h", "sha256": "d60b1da571922696", "symbol_count": 7, "symbols": [{"kind": "struct", "line": 113, "name": "usb_mixer_interface"}, {"doc": "@brief Pair of product ID and canonical human readable model name.  The product_name field is a pointer to a static string literal that lives for the lifetime of the kernel. Callers must not free it.", "kind": "struct", "line": 53, "name": "audiobox_model_info_t"}, {"doc": "@brief Look up the model info entry for a given USB product ID.  @param pid 16-bit product ID reported by the USB device. @return Pointer to a const entry in audiobox_models[] on match. NULL if pid does not correspond to any supported model.  Pure function: no side effects, no allocation, safe to call from any context including the USB probe path. The returned pointer remains valid for the lifetime of the kernel. Defined as a static inline so both the kernel module and the userspace test suite can include this header and exercise the lookup without linking against kernel-only object files.", "kind": "function", "line": 95, "name": "audiobox_lookup_model", "signature": "static inline const audiobox_model_info_t *\naudiobox_lookup_model(uint16_t pid)"}, {"doc": "@brief ALSA mixer init hook for AudioBox VSL devices.  Optional entry point used by the upstream sound/usb/mixer_quirks.c dispatch table. Not invoked by the detector itself. Returns 0 on success, a negative errno on failure.", "kind": "function", "line": 122, "name": "snd_audiobox_vsl_init", "signature": "int snd_audiobox_vsl_init(struct usb_mixer_interface *mixer);"}, {"doc": "ifdef __cplusplus", "kind": "variable", "line": 26, "name": "audiobox_model_pid_t", "signature": "extern \"C\" { #endif /** * @brief PreSonus USB vendor ID shared by every AudioBox VSL model. */ #define AUDIOBOX_VENDOR_ID 0x194fU /** * @brief Product IDs of the AudioBox VSL family. * * The enumerato"}, {"kind": "macro", "line": 21, "name": "AUDIOBOX_VSL_H", "signature": "#define AUDIOBOX_VSL_H"}, {"kind": "macro", "line": 32, "name": "AUDIOBOX_VENDOR_ID", "signature": "#define AUDIOBOX_VENDOR_ID"}]}, {"doc": "SPDX-License-Identifier: GPL-2.0-or-later Thin wrapper that installs the build-time dependencies for the audiobox_vsl kernel module. All real build, install, and clean commands live in the top-level Makefile. This script is intentionally minimal: it only ensures the toolchain and kernel headers are present, then exits.", "id": "install.sh", "kind": "module", "label": "install.sh", "language": "sh", "sha256": "c907d80fd6734993", "symbol_count": 0, "symbols": []}, {"doc": "_*_ coding: utf8 _*_", "id": "legacy/app.py", "kind": "module", "label": "app.py", "language": "py", "sha256": "e13d4e20ecf11033", "symbol_count": 0, "symbols": []}, {"doc": "AudioBox 22 VSL Enhanced Driver - Installation Script Copyright (c) 2025 grisuno (LazyOwn Project) License: GPL-2.0-or-later  This script installs enhanced ALSA controls for PreSonus AudioBox 22 VSL using DKMS (Dynamic Kernel Module Support) for automatic kernel updates.", "id": "legacy/build-dkms.sh", "kind": "module", "label": "build-dkms.sh", "language": "sh", "sha256": "df6198c88ef13ca4", "symbol_count": 19, "symbols": [{"kind": "function", "line": 40, "name": "print_header"}, {"kind": "function", "line": 48, "name": "print_success"}, {"kind": "function", "line": 52, "name": "print_error"}, {"kind": "function", "line": 56, "name": "print_warning"}, {"kind": "function", "line": 60, "name": "print_info"}, {"kind": "function", "line": 64, "name": "check_root"}, {"kind": "function", "line": 72, "name": "check_dependencies"}, {"kind": "function", "line": 101, "name": "detect_audiobox"}, {"kind": "function", "line": 123, "name": "create_source_structure"}, {"kind": "function", "line": 138, "name": "copy_source_files"}, {"kind": "function", "line": 174, "name": "create_dkms_conf"}, {"kind": "function", "line": 193, "name": "create_makefile"}, {"kind": "function", "line": 252, "name": "verify_mixer_quirks"}, {"kind": "function", "line": 295, "name": "build_with_dkms"}, {"kind": "function", "line": 309, "name": "install_module"}, {"kind": "function", "line": 323, "name": "reload_module"}, {"kind": "function", "line": 344, "name": "verify_installation"}, {"kind": "function", "line": 394, "name": "show_usage_info"}, {"kind": "function", "line": 452, "name": "main"}]}, {"doc": "include <stdio.h> include \"vsl_dsp_logic.h\" include \"vsl_dsp_transport.h\"", "id": "legacy/main.c", "kind": "module", "label": "main.c", "language": "c", "sha256": "8a86348744408373", "symbol_count": 3, "symbols": [{"doc": "include <stdio.h> include \"vsl_dsp_logic.h\" include \"vsl_dsp_transport.h\"", "kind": "function", "line": 4, "name": "main", "signature": "int main()"}, {"kind": "function", "line": 36, "name": "printf", "signature": "printf(\"--- Ganancia ---\\n\");"}, {"doc": "*********************************************************** *** ¡Llamada para Enviar el Paquete DSP a través de HIDAPI! ***", "kind": "function", "line": 68, "name": "VSL_Build_And_Send_Packet", "signature": "VSL_Build_And_Send_Packet(gain_id, encoded_gain_float);"}]}, {"doc": "SPDX-License-Identifier: GPL-2.0-or-later", "id": "legacy/mixer_quirks.c", "kind": "module", "label": "mixer_quirks.c", "language": "c", "sha256": "aed5ad2a734b213e", "symbol_count": 344, "symbols": [{"kind": "struct", "line": 45, "name": "std_mono_table"}, {"doc": "Sound Blaster remote control configuration  format of remote control data: Extigy:       xx 00 Audigy 2 NX:  06 80 xx 00 00 00 Live! 24-bit: 06 80 xx yy 22 83", "kind": "struct", "line": 181, "name": "rc_config"}, {"kind": "struct", "line": 410, "name": "sb_jack"}, {"kind": "struct", "line": 543, "name": "dualsense_mixer_elem_info"}, {"kind": "struct", "line": 3778, "name": "snd_djm_device"}, {"kind": "struct", "line": 3784, "name": "snd_djm_ctl"}, {"kind": "enum", "line": 2407, "name": "snd_rme_domain"}, {"kind": "enum", "line": 2413, "name": "snd_rme_clock_status"}, {"doc": "This function allows for the creation of standard UAC controls. See the quirks for M-Audio FTUs or Ebox-44. If you don't want to set a TLV callback pass NULL.  Since there doesn't seem to be a devices that needs a multichannel version, we keep it mono for simplicity.", "kind": "function", "line": 59, "name": "snd_create_std_mono_ctl_offset", "signature": "static int snd_create_std_mono_ctl_offset(struct usb_mixer_interface *mixer,\n\t\t\t\t\t  unsigned int ..."}, {"kind": "function", "line": 112, "name": "snd_create_std_mono_ctl", "signature": "static int snd_create_std_mono_ctl(struct usb_mixer_interface *mixer,\n\t\t\t\t   unsigned int unitid,..."}, {"doc": "Create a set of standard UAC controls from a table", "kind": "function", "line": 129, "name": "snd_create_std_mono_table", "signature": "static int snd_create_std_mono_table(struct usb_mixer_interface *mixer,\n\t\t\t\t     const struct std..."}, {"kind": "function", "line": 145, "name": "add_single_ctl_with_resume", "signature": "static int add_single_ctl_with_resume(struct usb_mixer_interface *mixer,\n\t\t\t\t      int id,\n\t\t\t\t  ..."}, {"kind": "function", "line": 199, "name": "snd_usb_soundblaster_remote_complete", "signature": "static void snd_usb_soundblaster_remote_complete(struct urb *urb)"}, {"kind": "function", "line": 219, "name": "snd_usb_sbrc_hwdep_read", "signature": "static long snd_usb_sbrc_hwdep_read(struct snd_hwdep *hw, char __user *buf,\n\t\t\t\t    long count, l..."}, {"kind": "function", "line": 239, "name": "snd_usb_sbrc_hwdep_poll", "signature": "static __poll_t snd_usb_sbrc_hwdep_poll(struct snd_hwdep *hw, struct file *file,\n\t\t\t\t\tpoll_table ..."}, {"kind": "function", "line": 248, "name": "snd_usb_soundblaster_remote_init", "signature": "static int snd_usb_soundblaster_remote_init(struct usb_mixer_interface *mixer)"}, {"doc": "define snd_audigy2nx_led_info\t\tsnd_ctl_boolean_mono_info", "kind": "function", "line": 298, "name": "snd_audigy2nx_led_get", "signature": "static int snd_audigy2nx_led_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)"}, {"kind": "function", "line": 304, "name": "snd_audigy2nx_led_update", "signature": "static int snd_audigy2nx_led_update(struct usb_mixer_interface *mixer,\n\t\t\t\t    int value, int index)"}, {"kind": "function", "line": 333, "name": "snd_audigy2nx_led_put", "signature": "static int snd_audigy2nx_led_put(struct snd_kcontrol *kcontrol,\n\t\t\t\t struct snd_ctl_elem_value *u..."}, {"kind": "function", "line": 352, "name": "snd_audigy2nx_led_resume", "signature": "static int snd_audigy2nx_led_resume(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 374, "name": "snd_audigy2nx_controls_create", "signature": "static int snd_audigy2nx_controls_create(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 406, "name": "snd_audigy2nx_proc_read", "signature": "static void snd_audigy2nx_proc_read(struct snd_info_entry *entry,\n\t\t\t\t    struct snd_info_buffer ..."}, {"doc": "return; err = snd_usb_ctl_msg(mixer->chip->dev, usb_rcvctrlpipe(mixer->chip->dev, 0), UAC_GET_MEM, USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE, 0, jacks[i].unitid << 8, buf, 3); if (err == 3 && (buf[0] == 3 || buf[0] == 6)) snd_iprintf(buffer, \"%02x %02x\\n\", buf[1], buf[2]); else snd_iprintf(buffer, \"?\\n\"); } } /* EMU0204", "kind": "function", "line": 457, "name": "snd_emu0204_ch_switch_info", "signature": "static int snd_emu0204_ch_switch_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t      struct snd_ctl_ele..."}, {"kind": "function", "line": 464, "name": "snd_emu0204_ch_switch_get", "signature": "static int snd_emu0204_ch_switch_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t     struct snd_ctl_elem_..."}, {"kind": "function", "line": 471, "name": "snd_emu0204_ch_switch_update", "signature": "static int snd_emu0204_ch_switch_update(struct usb_mixer_interface *mixer,\n\t\t\t\t\tint value)"}, {"kind": "function", "line": 489, "name": "snd_emu0204_ch_switch_put", "signature": "static int snd_emu0204_ch_switch_put(struct snd_kcontrol *kcontrol,\n\t\t\t\t     struct snd_ctl_elem_..."}, {"kind": "function", "line": 508, "name": "snd_emu0204_ch_switch_resume", "signature": "static int snd_emu0204_ch_switch_resume(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 523, "name": "snd_emu0204_controls_create", "signature": "static int snd_emu0204_controls_create(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 549, "name": "snd_dualsense_ih_event", "signature": "static void snd_dualsense_ih_event(struct input_handle *handle,\n\t\t\t\t   unsigned int type, unsigne..."}, {"kind": "function", "line": 570, "name": "snd_dualsense_ih_match", "signature": "static bool snd_dualsense_ih_match(struct input_handler *handler,\n\t\t\t\t   struct input_dev *dev)"}, {"kind": "function", "line": 617, "name": "snd_dualsense_ih_connect", "signature": "static int snd_dualsense_ih_connect(struct input_handler *handler,\n\t\t\t\t    struct input_dev *dev,..."}, {"kind": "function", "line": 649, "name": "snd_dualsense_ih_disconnect", "signature": "static void snd_dualsense_ih_disconnect(struct input_handle *handle)"}, {"kind": "function", "line": 656, "name": "snd_dualsense_ih_start", "signature": "static void snd_dualsense_ih_start(struct input_handle *handle)"}, {"kind": "function", "line": 679, "name": "snd_dualsense_jack_get", "signature": "static int snd_dualsense_jack_get(struct snd_kcontrol *kctl,\n\t\t\t\t  struct snd_ctl_elem_value *uco..."}, {"kind": "function", "line": 696, "name": "snd_dualsense_resume_jack", "signature": "static int snd_dualsense_resume_jack(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 703, "name": "snd_dualsense_mixer_elem_free", "signature": "static void snd_dualsense_mixer_elem_free(struct snd_kcontrol *kctl)"}, {"kind": "function", "line": 713, "name": "snd_dualsense_jack_create", "signature": "static int snd_dualsense_jack_create(struct usb_mixer_interface *mixer,\n\t\t\t\t     const char *name..."}, {"kind": "function", "line": 777, "name": "snd_dualsense_controls_create", "signature": "static int snd_dualsense_controls_create(struct usb_mixer_interface *mixer)"}, {"doc": "static int snd_dualsense_controls_create(struct usb_mixer_interface *mixer) { int err; err = snd_dualsense_jack_create(mixer, \"Headphone Jack\", true); if (err < 0) return err; return snd_dualsense_jack_create(mixer, \"Headset Mic Jack\", false); } #endif /* IS_REACHABLE(CONFIG_INPUT) /* ASUS Xonar U1 / U3 controls", "kind": "function", "line": 791, "name": "snd_xonar_u1_switch_get", "signature": "static int snd_xonar_u1_switch_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t   struct snd_ctl_elem_valu..."}, {"kind": "function", "line": 798, "name": "snd_xonar_u1_switch_update", "signature": "static int snd_xonar_u1_switch_update(struct usb_mixer_interface *mixer,\n\t\t\t\t      unsigned char ..."}, {"kind": "function", "line": 812, "name": "snd_xonar_u1_switch_put", "signature": "static int snd_xonar_u1_switch_put(struct snd_kcontrol *kcontrol,\n\t\t\t\t   struct snd_ctl_elem_valu..."}, {"kind": "function", "line": 832, "name": "snd_xonar_u1_switch_resume", "signature": "static int snd_xonar_u1_switch_resume(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 847, "name": "snd_xonar_u1_controls_create", "signature": "static int snd_xonar_u1_controls_create(struct usb_mixer_interface *mixer)"}, {"doc": ".info = snd_ctl_boolean_mono_info, .get = snd_xonar_u1_switch_get, .put = snd_xonar_u1_switch_put, .private_value = 0x05, }; static int snd_xonar_u1_controls_create(struct usb_mixer_interface *mixer) { return add_single_ctl_with_resume(mixer, 0, snd_xonar_u1_switch_resume, &snd_xonar_u1_output_switch, NULL); } /* Digidesign Mbox 1 helper functions", "kind": "function", "line": 856, "name": "snd_mbox1_is_spdif_synced", "signature": "static int snd_mbox1_is_spdif_synced(struct snd_usb_audio *chip)"}, {"kind": "function", "line": 876, "name": "snd_mbox1_set_clk_source", "signature": "static int snd_mbox1_set_clk_source(struct snd_usb_audio *chip, int rate_or_zero)"}, {"kind": "function", "line": 894, "name": "snd_mbox1_is_spdif_input", "signature": "static int snd_mbox1_is_spdif_input(struct snd_usb_audio *chip)"}, {"kind": "function", "line": 914, "name": "snd_mbox1_set_input_source", "signature": "static int snd_mbox1_set_input_source(struct snd_usb_audio *chip, int is_spdif)"}, {"doc": "S/PDIF Source  -> 0x02  unsigned char buff[1]; buff[0] = (is_spdif & 1) + 1; /* Set input source return snd_usb_ctl_msg(chip->dev, usb_sndctrlpipe(chip->dev, 0), 0x1, USB_TYPE_CLASS | USB_RECIP_INTERFACE, 0x00, 0x500, buff, 1); } /* Digidesign Mbox 1 clock source switch (internal/spdif)", "kind": "function", "line": 933, "name": "snd_mbox1_clk_switch_get", "signature": "static int snd_mbox1_clk_switch_get(struct snd_kcontrol *kctl,\n\t\t\t\t    struct snd_ctl_elem_value ..."}, {"kind": "function", "line": 953, "name": "snd_mbox1_clk_switch_update", "signature": "static int snd_mbox1_clk_switch_update(struct usb_mixer_interface *mixer, int is_spdif_sync)"}, {"kind": "function", "line": 978, "name": "snd_mbox1_clk_switch_put", "signature": "static int snd_mbox1_clk_switch_put(struct snd_kcontrol *kctl,\n\t\t\t\t    struct snd_ctl_elem_value ..."}, {"kind": "function", "line": 996, "name": "snd_mbox1_clk_switch_info", "signature": "static int snd_mbox1_clk_switch_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t     struct snd_ctl_elem_..."}, {"kind": "function", "line": 1007, "name": "snd_mbox1_clk_switch_resume", "signature": "static int snd_mbox1_clk_switch_resume(struct usb_mixer_elem_list *list)"}, {"doc": "static const char *const texts[2] = { \"Internal\", \"S/PDIF\" }; return snd_ctl_enum_info(uinfo, 1, ARRAY_SIZE(texts), texts); } static int snd_mbox1_clk_switch_resume(struct usb_mixer_elem_list *list) { return snd_mbox1_clk_switch_update(list->mixer, list->kctl->private_value); } /* Digidesign Mbox 1 input source switch (analog/spdif)", "kind": "function", "line": 1014, "name": "snd_mbox1_src_switch_get", "signature": "static int snd_mbox1_src_switch_get(struct snd_kcontrol *kctl,\n\t\t\t\t    struct snd_ctl_elem_value ..."}, {"kind": "function", "line": 1021, "name": "snd_mbox1_src_switch_update", "signature": "static int snd_mbox1_src_switch_update(struct usb_mixer_interface *mixer, int is_spdif_input)"}, {"kind": "function", "line": 1045, "name": "snd_mbox1_src_switch_put", "signature": "static int snd_mbox1_src_switch_put(struct snd_kcontrol *kctl,\n\t\t\t\t    struct snd_ctl_elem_value ..."}, {"kind": "function", "line": 1063, "name": "snd_mbox1_src_switch_info", "signature": "static int snd_mbox1_src_switch_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t     struct snd_ctl_elem_..."}, {"kind": "function", "line": 1074, "name": "snd_mbox1_src_switch_resume", "signature": "static int snd_mbox1_src_switch_resume(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 1101, "name": "snd_mbox1_controls_create", "signature": "static int snd_mbox1_controls_create(struct usb_mixer_interface *mixer)"}, {"doc": "define _MAKE_NI_CONTROL(bRequest, wIndex) ((bRequest) << 16 | (wIndex))", "kind": "function", "line": 1120, "name": "snd_ni_control_init_val", "signature": "static int snd_ni_control_init_val(struct usb_mixer_interface *mixer,\n\t\t\t\t   struct snd_kcontrol ..."}, {"kind": "function", "line": 1142, "name": "snd_nativeinstruments_control_get", "signature": "static int snd_nativeinstruments_control_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t\t     struct snd_..."}, {"kind": "function", "line": 1149, "name": "snd_ni_update_cur_val", "signature": "static int snd_ni_update_cur_val(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 1163, "name": "snd_nativeinstruments_control_put", "signature": "static int snd_nativeinstruments_control_put(struct snd_kcontrol *kcontrol,\n\t\t\t\t\t     struct snd_..."}, {"kind": "function", "line": 1234, "name": "snd_nativeinstruments_create_mixer", "signature": "static int snd_nativeinstruments_create_mixer(struct usb_mixer_interface *mixer,\n\t\t\t\t\t      const..."}, {"doc": "err = add_single_ctl_with_resume(mixer, 0, snd_ni_update_cur_val, &template, &list); if (err < 0) break; snd_ni_control_init_val(mixer, list->kctl); } return err; } /* M-Audio FastTrack Ultra quirks /* FTU Effect switch (also used by C400/C600)", "kind": "function", "line": 1267, "name": "snd_ftu_eff_switch_info", "signature": "static int snd_ftu_eff_switch_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t   struct snd_ctl_elem_info..."}, {"kind": "function", "line": 1277, "name": "snd_ftu_eff_switch_init", "signature": "static int snd_ftu_eff_switch_init(struct usb_mixer_interface *mixer,\n\t\t\t\t   struct snd_kcontrol ..."}, {"kind": "function", "line": 1300, "name": "snd_ftu_eff_switch_get", "signature": "static int snd_ftu_eff_switch_get(struct snd_kcontrol *kctl,\n\t\t\t\t  struct snd_ctl_elem_value *uco..."}, {"kind": "function", "line": 1307, "name": "snd_ftu_eff_switch_update", "signature": "static int snd_ftu_eff_switch_update(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 1328, "name": "snd_ftu_eff_switch_put", "signature": "static int snd_ftu_eff_switch_put(struct snd_kcontrol *kctl,\n\t\t\t\t  struct snd_ctl_elem_value *uco..."}, {"kind": "function", "line": 1346, "name": "snd_ftu_create_effect_switch", "signature": "static int snd_ftu_create_effect_switch(struct usb_mixer_interface *mixer,\n\t\t\t\t\tint validx, int b..."}, {"doc": "struct usb_mixer_elem_list *list; int err; err = add_single_ctl_with_resume(mixer, bUnitID, snd_ftu_eff_switch_update, &template, &list); if (err < 0) return err; list->kctl->private_value = (validx << 8) | bUnitID; snd_ftu_eff_switch_init(mixer, list->kctl); return 0; } /* Create volume controls for FTU devices", "kind": "function", "line": 1373, "name": "snd_ftu_create_volume_ctls", "signature": "static int snd_ftu_create_volume_ctls(struct usb_mixer_interface *mixer)"}, {"doc": "\"DIn%d - Out%d Playback Volume\", in - 7, out + 1); err = snd_create_std_mono_ctl(mixer, id, control, cmask, val_type, name, &snd_usb_mixer_vol_tlv); if (err < 0) return err; } } return 0; } /* This control needs a volume quirk, see mixer.c", "kind": "function", "line": 1412, "name": "snd_ftu_create_effect_volume_ctl", "signature": "static int snd_ftu_create_effect_volume_ctl(struct usb_mixer_interface *mixer)"}, {"doc": "/* This control needs a volume quirk, see mixer.c static int snd_ftu_create_effect_volume_ctl(struct usb_mixer_interface *mixer) { static const char name[] = \"Effect Volume\"; const unsigned int id = 6; const int val_type = USB_MIXER_U8; const unsigned int control = 2; const unsigned int cmask = 0; return snd_create_std_mono_ctl(mixer, id, control, cmask, val_type, name, snd_usb_mixer_vol_tlv); } /* This control needs a volume quirk, see mixer.c", "kind": "function", "line": 1425, "name": "snd_ftu_create_effect_duration_ctl", "signature": "static int snd_ftu_create_effect_duration_ctl(struct usb_mixer_interface *mixer)"}, {"doc": "/* This control needs a volume quirk, see mixer.c static int snd_ftu_create_effect_duration_ctl(struct usb_mixer_interface *mixer) { static const char name[] = \"Effect Duration\"; const unsigned int id = 6; const int val_type = USB_MIXER_S16; const unsigned int control = 3; const unsigned int cmask = 0; return snd_create_std_mono_ctl(mixer, id, control, cmask, val_type, name, snd_usb_mixer_vol_tlv); } /* This control needs a volume quirk, see mixer.c", "kind": "function", "line": 1438, "name": "snd_ftu_create_effect_feedback_ctl", "signature": "static int snd_ftu_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 1449, "name": "snd_ftu_create_effect_return_ctls", "signature": "static int snd_ftu_create_effect_return_ctls(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 1473, "name": "snd_ftu_create_effect_send_ctls", "signature": "static int snd_ftu_create_effect_send_ctls(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 1506, "name": "snd_ftu_create_mixer", "signature": "static int snd_ftu_create_mixer(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 1541, "name": "snd_emuusb_set_samplerate", "signature": "void snd_emuusb_set_samplerate(struct snd_usb_audio *chip,\n\t\t\t       unsigned char samplerate_id)"}, {"doc": "err = snd_ftu_create_effect_send_ctls(mixer); if (err < 0) return err; return 0; } void snd_emuusb_set_samplerate(struct snd_usb_audio *chip, unsigned char samplerate_id) { struct usb_mixer_interface *mixer; struct usb_mixer_elem_info *cval; int unitid = 12; /* SampleRate ExtensionUnit ID", "kind": "function", "line": 1548, "name": "list_for_each_entry", "signature": "list_for_each_entry(mixer, &chip->mixer_list, list)"}, {"doc": "list_for_each_entry(mixer, &chip->mixer_list, list) { if (mixer->id_elems[unitid]) { cval = mixer_elem_list_to_info(mixer->id_elems[unitid]); snd_usb_mixer_set_ctl_value(cval, UAC_SET_CUR, cval->control << 8, samplerate_id); snd_usb_mixer_notify_id(mixer, unitid); break; } } } /* M-Audio Fast Track C400/C600 /* C400/C600 volume controls, this control needs a volume quirk, see mixer.c", "kind": "function", "line": 1563, "name": "snd_c400_create_vol_ctls", "signature": "static int snd_c400_create_vol_ctls(struct usb_mixer_interface *mixer)"}, {"doc": "cmask = (out == 0) ? 0 : BIT(out - 1); offset = chan * num_outs; err = snd_create_std_mono_ctl_offset(mixer, id, control, cmask, val_type, offset, name, &snd_usb_mixer_vol_tlv); if (err < 0) return err; } } return 0; } /* This control needs a volume quirk, see mixer.c", "kind": "function", "line": 1612, "name": "snd_c400_create_effect_volume_ctl", "signature": "static int snd_c400_create_effect_volume_ctl(struct usb_mixer_interface *mixer)"}, {"doc": "/* This control needs a volume quirk, see mixer.c static int snd_c400_create_effect_volume_ctl(struct usb_mixer_interface *mixer) { static const char name[] = \"Effect Volume\"; const unsigned int id = 0x43; const int val_type = USB_MIXER_U8; const unsigned int control = 3; const unsigned int cmask = 0; return snd_create_std_mono_ctl(mixer, id, control, cmask, val_type, name, snd_usb_mixer_vol_tlv); } /* This control needs a volume quirk, see mixer.c", "kind": "function", "line": 1625, "name": "snd_c400_create_effect_duration_ctl", "signature": "static int snd_c400_create_effect_duration_ctl(struct usb_mixer_interface *mixer)"}, {"doc": "/* This control needs a volume quirk, see mixer.c static int snd_c400_create_effect_duration_ctl(struct usb_mixer_interface *mixer) { static const char name[] = \"Effect Duration\"; const unsigned int id = 0x43; const int val_type = USB_MIXER_S16; const unsigned int control = 4; const unsigned int cmask = 0; return snd_create_std_mono_ctl(mixer, id, control, cmask, val_type, name, snd_usb_mixer_vol_tlv); } /* This control needs a volume quirk, see mixer.c", "kind": "function", "line": 1638, "name": "snd_c400_create_effect_feedback_ctl", "signature": "static int snd_c400_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 1649, "name": "snd_c400_create_effect_vol_ctls", "signature": "static int snd_c400_create_effect_vol_ctls(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 1694, "name": "snd_c400_create_effect_ret_vol_ctls", "signature": "static int snd_c400_create_effect_ret_vol_ctls(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 1736, "name": "snd_c400_create_mixer", "signature": "static int snd_c400_create_mixer(struct usb_mixer_interface *mixer)"}, {"doc": "power on values: r2: 0x10 r3: 0x20 (b7 is zeroed just before playback (except IEC61937) and set just after it to 0xa0, presumably it disables/mutes some analog parts when there is no audio.) r9: 0x28  Optical transmitter on/off: vendor register.bit: 9.1 0 - on (0x28 register value) 1 - off (0x2a register value)", "kind": "function", "line": 1869, "name": "snd_microii_spdif_info", "signature": "static int snd_microii_spdif_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t  struct snd_ctl_elem_info *..."}, {"kind": "function", "line": 1876, "name": "snd_microii_spdif_default_get", "signature": "static int snd_microii_spdif_default_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t\t struct snd_ctl_elem..."}, {"kind": "function", "line": 1923, "name": "snd_microii_spdif_default_update", "signature": "static int snd_microii_spdif_default_update(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 1959, "name": "snd_microii_spdif_default_put", "signature": "static int snd_microii_spdif_default_put(struct snd_kcontrol *kcontrol,\n\t\t\t\t\t struct snd_ctl_elem..."}, {"kind": "function", "line": 1987, "name": "snd_microii_spdif_mask_get", "signature": "static int snd_microii_spdif_mask_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t      struct snd_ctl_ele..."}, {"kind": "function", "line": 1998, "name": "snd_microii_spdif_switch_get", "signature": "static int snd_microii_spdif_switch_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t\tstruct snd_ctl_elem_v..."}, {"kind": "function", "line": 2006, "name": "snd_microii_spdif_switch_update", "signature": "static int snd_microii_spdif_switch_update(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 2025, "name": "snd_microii_spdif_switch_put", "signature": "static int snd_microii_spdif_switch_put(struct snd_kcontrol *kcontrol,\n\t\t\t\t\tstruct snd_ctl_elem_v..."}, {"kind": "function", "line": 2067, "name": "snd_microii_controls_create", "signature": "static int snd_microii_controls_create(struct usb_mixer_interface *mixer)"}, {"doc": "for (i = 0; i < ARRAY_SIZE(snd_microii_mixer_spdif); ++i) { err = add_single_ctl_with_resume(mixer, 0, resume_funcs[i], &snd_microii_mixer_spdif[i], NULL); if (err < 0) return err; } return 0; } /* Creative Sound Blaster E1", "kind": "function", "line": 2090, "name": "snd_soundblaster_e1_switch_get", "signature": "static int snd_soundblaster_e1_switch_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t\t  struct snd_ctl_el..."}, {"kind": "function", "line": 2097, "name": "snd_soundblaster_e1_switch_update", "signature": "static int snd_soundblaster_e1_switch_update(struct usb_mixer_interface *mixer,\n\t\t\t\t\t     unsigne..."}, {"kind": "function", "line": 2115, "name": "snd_soundblaster_e1_switch_put", "signature": "static int snd_soundblaster_e1_switch_put(struct snd_kcontrol *kcontrol,\n\t\t\t\t\t  struct snd_ctl_el..."}, {"kind": "function", "line": 2129, "name": "snd_soundblaster_e1_switch_resume", "signature": "static int snd_soundblaster_e1_switch_resume(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 2135, "name": "snd_soundblaster_e1_switch_info", "signature": "static int snd_soundblaster_e1_switch_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t\t   struct snd_ctl_..."}, {"kind": "function", "line": 2154, "name": "snd_soundblaster_e1_switch_create", "signature": "static int snd_soundblaster_e1_switch_create(struct usb_mixer_interface *mixer)"}, {"doc": "define REALTEK_MIC_FLAG 0x100", "kind": "function", "line": 2191, "name": "realtek_hda_set", "signature": "static int realtek_hda_set(struct snd_usb_audio *chip, u32 cmd)"}, {"kind": "function", "line": 2201, "name": "realtek_hda_get", "signature": "static int realtek_hda_get(struct snd_usb_audio *chip, u32 cmd, u32 *value)"}, {"kind": "function", "line": 2222, "name": "realtek_ctl_connector_get", "signature": "static int realtek_ctl_connector_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t     struct snd_ctl_elem_..."}, {"kind": "function", "line": 2272, "name": "realtek_resume_jack", "signature": "static int realtek_resume_jack(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 2279, "name": "realtek_add_jack", "signature": "static int realtek_add_jack(struct usb_mixer_interface *mixer,\n\t\t\t    char *name, u32 val)"}, {"kind": "function", "line": 2306, "name": "dell_dock_mixer_create", "signature": "static int dell_dock_mixer_create(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 2338, "name": "dell_dock_init_vol", "signature": "static void dell_dock_init_vol(struct usb_mixer_interface *mixer, int ch, int id)"}, {"kind": "function", "line": 2350, "name": "dell_dock_mixer_init", "signature": "static int dell_dock_mixer_init(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 2418, "name": "snd_rme_read_value", "signature": "static int snd_rme_read_value(struct snd_usb_audio *chip,\n\t\t\t      unsigned int item,\n\t\t\t      u3..."}, {"kind": "function", "line": 2437, "name": "snd_rme_get_status1", "signature": "static int snd_rme_get_status1(struct snd_kcontrol *kcontrol,\n\t\t\t       u32 *status1)"}, {"kind": "function", "line": 2449, "name": "snd_rme_rate_get", "signature": "static int snd_rme_rate_get(struct snd_kcontrol *kcontrol,\n\t\t\t    struct snd_ctl_elem_value *ucon..."}, {"kind": "function", "line": 2483, "name": "snd_rme_sync_state_get", "signature": "static int snd_rme_sync_state_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t  struct snd_ctl_elem_value ..."}, {"kind": "function", "line": 2513, "name": "snd_rme_spdif_if_get", "signature": "static int snd_rme_spdif_if_get(struct snd_kcontrol *kcontrol,\n\t\t\t\tstruct snd_ctl_elem_value *uco..."}, {"kind": "function", "line": 2526, "name": "snd_rme_spdif_format_get", "signature": "static int snd_rme_spdif_format_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t    struct snd_ctl_elem_va..."}, {"kind": "function", "line": 2539, "name": "snd_rme_sync_source_get", "signature": "static int snd_rme_sync_source_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t   struct snd_ctl_elem_valu..."}, {"kind": "function", "line": 2552, "name": "snd_rme_current_freq_get", "signature": "static int snd_rme_current_freq_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t    struct snd_ctl_elem_va..."}, {"kind": "function", "line": 2578, "name": "snd_rme_rate_info", "signature": "static int snd_rme_rate_info(struct snd_kcontrol *kcontrol,\n\t\t\t     struct snd_ctl_elem_info *uinfo)"}, {"kind": "function", "line": 2598, "name": "snd_rme_sync_state_info", "signature": "static int snd_rme_sync_state_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t   struct snd_ctl_elem_info..."}, {"kind": "function", "line": 2609, "name": "snd_rme_spdif_if_info", "signature": "static int snd_rme_spdif_if_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t struct snd_ctl_elem_info *ui..."}, {"kind": "function", "line": 2620, "name": "snd_rme_spdif_format_info", "signature": "static int snd_rme_spdif_format_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t     struct snd_ctl_elem_..."}, {"kind": "function", "line": 2631, "name": "snd_rme_sync_source_info", "signature": "static int snd_rme_sync_source_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t    struct snd_ctl_elem_in..."}, {"kind": "function", "line": 2713, "name": "snd_rme_controls_create", "signature": "static int snd_rme_controls_create(struct usb_mixer_interface *mixer)"}, {"doc": "define SND_BBFPRO_USBREQ_CTL_REG1 0x10 define SND_BBFPRO_USBREQ_CTL_REG2 0x17 define SND_BBFPRO_USBREQ_GAIN 0x1a define SND_BBFPRO_USBREQ_MIXER 0x12", "kind": "function", "line": 2779, "name": "snd_bbfpro_ctl_update", "signature": "static int snd_bbfpro_ctl_update(struct usb_mixer_interface *mixer, u8 reg,\n\t\t\t\t u8 index, u8 value)"}, {"kind": "function", "line": 2810, "name": "snd_bbfpro_ctl_get", "signature": "static int snd_bbfpro_ctl_get(struct snd_kcontrol *kcontrol,\n\t\t\t      struct snd_ctl_elem_value *..."}, {"kind": "function", "line": 2833, "name": "snd_bbfpro_ctl_info", "signature": "static int snd_bbfpro_ctl_info(struct snd_kcontrol *kcontrol,\n\t\t\t       struct snd_ctl_elem_info ..."}, {"kind": "function", "line": 2867, "name": "snd_bbfpro_ctl_put", "signature": "static int snd_bbfpro_ctl_put(struct snd_kcontrol *kcontrol,\n\t\t\t      struct snd_ctl_elem_value *..."}, {"kind": "function", "line": 2906, "name": "snd_bbfpro_ctl_resume", "signature": "static int snd_bbfpro_ctl_resume(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 2919, "name": "snd_bbfpro_gain_update", "signature": "static int snd_bbfpro_gain_update(struct usb_mixer_interface *mixer,\n\t\t\t\t  u8 channel, u8 gain)"}, {"kind": "function", "line": 2943, "name": "snd_bbfpro_gain_get", "signature": "static int snd_bbfpro_gain_get(struct snd_kcontrol *kcontrol,\n\t\t\t       struct snd_ctl_elem_value..."}, {"kind": "function", "line": 2952, "name": "snd_bbfpro_gain_info", "signature": "static int snd_bbfpro_gain_info(struct snd_kcontrol *kcontrol,\n\t\t\t\tstruct snd_ctl_elem_info *uinfo)"}, {"kind": "function", "line": 2973, "name": "snd_bbfpro_gain_put", "signature": "static int snd_bbfpro_gain_put(struct snd_kcontrol *kcontrol,\n\t\t\t       struct snd_ctl_elem_value..."}, {"kind": "function", "line": 3010, "name": "snd_bbfpro_gain_resume", "signature": "static int snd_bbfpro_gain_resume(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 3023, "name": "snd_bbfpro_vol_update", "signature": "static int snd_bbfpro_vol_update(struct usb_mixer_interface *mixer, u16 index,\n\t\t\t\t u32 value)"}, {"kind": "function", "line": 3049, "name": "snd_bbfpro_vol_get", "signature": "static int snd_bbfpro_vol_get(struct snd_kcontrol *kcontrol,\n\t\t\t      struct snd_ctl_elem_value *..."}, {"kind": "function", "line": 3057, "name": "snd_bbfpro_vol_info", "signature": "static int snd_bbfpro_vol_info(struct snd_kcontrol *kcontrol,\n\t\t\t       struct snd_ctl_elem_info ..."}, {"kind": "function", "line": 3067, "name": "snd_bbfpro_vol_put", "signature": "static int snd_bbfpro_vol_put(struct snd_kcontrol *kcontrol,\n\t\t\t      struct snd_ctl_elem_value *..."}, {"kind": "function", "line": 3095, "name": "snd_bbfpro_vol_resume", "signature": "static int snd_bbfpro_vol_resume(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 3132, "name": "snd_bbfpro_ctl_add", "signature": "static int snd_bbfpro_ctl_add(struct usb_mixer_interface *mixer, u8 reg,\n\t\t\t      u8 index, char ..."}, {"kind": "function", "line": 3146, "name": "snd_bbfpro_gain_add", "signature": "static int snd_bbfpro_gain_add(struct usb_mixer_interface *mixer, u8 channel,\n\t\t\t       char *name)"}, {"kind": "function", "line": 3158, "name": "snd_bbfpro_vol_add", "signature": "static int snd_bbfpro_vol_add(struct usb_mixer_interface *mixer, u16 index,\n\t\t\t      char *name)"}, {"kind": "function", "line": 3170, "name": "snd_bbfpro_controls_create", "signature": "static int snd_bbfpro_controls_create(struct usb_mixer_interface *mixer)"}, {"doc": "#define RME_DIGIFACE_STATUS_REG2H 5 #define RME_DIGIFACE_STATUS_REG3L 6 #define RME_DIGIFACE_STATUS_REG3H 7 #define RME_DIGIFACE_CTL_REG1 16 #define RME_DIGIFACE_CTL_REG2 18 /* Reg is overloaded, 0-7 for status halfwords or 16 or 18 for control registers #define RME_DIGIFACE_REGISTER(reg, mask) (((reg) << 16) | (mask)) #define RME_DIGIFACE_INVERT BIT(31) /* Nonconst helpers define field_get(_mask, _reg) (((_reg) & (_mask)) >> (ffs(_mask) - 1)) define field_prep(_mask, _val) (((_val) << (ffs(_mask) - 1)) & (_mask))", "kind": "function", "line": 3318, "name": "snd_rme_digiface_write_reg", "signature": "static int snd_rme_digiface_write_reg(struct snd_kcontrol *kcontrol, int item, u16 mask, u16 val)"}, {"kind": "function", "line": 3336, "name": "snd_rme_digiface_read_status", "signature": "static int snd_rme_digiface_read_status(struct snd_kcontrol *kcontrol, u32 status[4])"}, {"kind": "function", "line": 3360, "name": "snd_rme_digiface_get_status_val", "signature": "static int snd_rme_digiface_get_status_val(struct snd_kcontrol *kcontrol)"}, {"kind": "function", "line": 3398, "name": "snd_rme_digiface_rate_get", "signature": "static int snd_rme_digiface_rate_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t     struct snd_ctl_elem_..."}, {"kind": "function", "line": 3412, "name": "snd_rme_digiface_enum_get", "signature": "static int snd_rme_digiface_enum_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t     struct snd_ctl_elem_..."}, {"kind": "function", "line": 3424, "name": "snd_rme_digiface_enum_put", "signature": "static int snd_rme_digiface_enum_put(struct snd_kcontrol *kcontrol,\n\t\t\t\t     struct snd_ctl_elem_..."}, {"kind": "function", "line": 3438, "name": "snd_rme_digiface_current_sync_get", "signature": "static int snd_rme_digiface_current_sync_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t\t     struct snd_..."}, {"kind": "function", "line": 3450, "name": "snd_rme_digiface_sync_state_get", "signature": "static int snd_rme_digiface_sync_state_get(struct snd_kcontrol *kcontrol,\n\t\t\t\t\t   struct snd_ctl_..."}, {"kind": "function", "line": 3473, "name": "snd_rme_digiface_format_info", "signature": "static int snd_rme_digiface_format_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t\tstruct snd_ctl_elem_i..."}, {"kind": "function", "line": 3484, "name": "snd_rme_digiface_sync_source_info", "signature": "static int snd_rme_digiface_sync_source_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t\t     struct snd_..."}, {"kind": "function", "line": 3495, "name": "snd_rme_digiface_rate_info", "signature": "static int snd_rme_digiface_rate_info(struct snd_kcontrol *kcontrol,\n\t\t\t\t      struct snd_ctl_ele..."}, {"kind": "function", "line": 3684, "name": "snd_rme_digiface_controls_create", "signature": "static int snd_rme_digiface_controls_create(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 3791, "name": "snd_djm_get_label_caplevel_common", "signature": "static const char *snd_djm_get_label_caplevel_common(u16 wvalue)"}, {"doc": "Models like DJM-A9 or DJM-V10 have different capture levels than others", "kind": "function", "line": 3804, "name": "snd_djm_get_label_caplevel_high", "signature": "static const char *snd_djm_get_label_caplevel_high(u16 wvalue)"}, {"kind": "function", "line": 3816, "name": "snd_djm_get_label_cap_common", "signature": "static const char *snd_djm_get_label_cap_common(u16 wvalue)"}, {"doc": "The DJM-850 has different values for CD/LINE and LINE capture control options than the other DJM declared in this file.", "kind": "function", "line": 3849, "name": "snd_djm_get_label_cap_850", "signature": "static const char *snd_djm_get_label_cap_850(u16 wvalue)"}, {"kind": "function", "line": 3857, "name": "snd_djm_get_label_caplevel", "signature": "static const char *snd_djm_get_label_caplevel(u8 device_idx, u16 wvalue)"}, {"kind": "function", "line": 3866, "name": "snd_djm_get_label_cap", "signature": "static const char *snd_djm_get_label_cap(u8 device_idx, u16 wvalue)"}, {"kind": "function", "line": 3874, "name": "snd_djm_get_label_pb", "signature": "static const char *snd_djm_get_label_pb(u16 wvalue)"}, {"kind": "function", "line": 3884, "name": "snd_djm_get_label", "signature": "static const char *snd_djm_get_label(u8 device_idx, u16 wvalue, u16 windex)"}, {"kind": "function", "line": 4116, "name": "snd_djm_controls_info", "signature": "static int snd_djm_controls_info(struct snd_kcontrol *kctl,\n\t\t\t\t struct snd_ctl_elem_info *info)"}, {"kind": "function", "line": 4148, "name": "snd_djm_controls_update", "signature": "static int snd_djm_controls_update(struct usb_mixer_interface *mixer,\n\t\t\t\t   u8 device_idx, u8 gr..."}, {"kind": "function", "line": 4169, "name": "snd_djm_controls_get", "signature": "static int snd_djm_controls_get(struct snd_kcontrol *kctl,\n\t\t\t\tstruct snd_ctl_elem_value *elem)"}, {"kind": "function", "line": 4176, "name": "snd_djm_controls_put", "signature": "static int snd_djm_controls_put(struct snd_kcontrol *kctl, struct snd_ctl_elem_value *elem)"}, {"kind": "function", "line": 4193, "name": "snd_djm_controls_resume", "signature": "static int snd_djm_controls_resume(struct usb_mixer_elem_list *list)"}, {"kind": "function", "line": 4203, "name": "snd_djm_controls_create", "signature": "static int snd_djm_controls_create(struct usb_mixer_interface *mixer,\n\t\t\t\t   const u8 device_idx)"}, {"kind": "function", "line": 4238, "name": "snd_usb_mixer_apply_create_quirk", "signature": "int snd_usb_mixer_apply_create_quirk(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 4420, "name": "snd_usb_mixer_resume_quirk", "signature": "void snd_usb_mixer_resume_quirk(struct usb_mixer_interface *mixer)"}, {"kind": "function", "line": 4429, "name": "snd_usb_mixer_rc_memory_change", "signature": "void snd_usb_mixer_rc_memory_change(struct usb_mixer_interface *mixer,\n\t\t\t\t    int unitid)"}, {"kind": "function", "line": 4457, "name": "snd_dragonfly_quirk_db_scale", "signature": "static void snd_dragonfly_quirk_db_scale(struct usb_mixer_interface *mixer,\n\t\t\t\t\t struct usb_mixe..."}, {"doc": "standards. This function fixes nonstandard source names. By the time this function is called the control name should look like one of these: \"source names Playback Volume\" \"source names Playback Switch\" \"source names Capture Volume\" \"source names Capture Switch\" If any of the trigger words are found in the name then the name will be changed to: \"Headset Playback Volume\" \"Headset Playback Switch\" \"Headset Capture Volume\" \"Headset Capture Switch\" depending on the current suffix.", "kind": "function", "line": 4509, "name": "snd_fix_plt_name", "signature": "static void snd_fix_plt_name(struct snd_usb_audio *chip,\n\t\t\t     struct snd_ctl_elem_id *id)"}, {"kind": "function", "line": 4538, "name": "snd_usb_mixer_fu_apply_quirk", "signature": "void snd_usb_mixer_fu_apply_quirk(struct usb_mixer_interface *mixer,\n\t\t\t\t  struct usb_mixer_elem_..."}, {"kind": "function", "line": 74, "name": "snd_usb_mixer_elem_init_std", "signature": "snd_usb_mixer_elem_init_std(&cval->head, mixer, unitid);"}, {"kind": "function", "line": 94, "name": "kfree", "signature": "kfree(cval);"}, {"doc": "cval->min = 0; cval->max = 1; cval->res = 0; cval->dBmin = 0; cval->dBmax = 0; /* Create control kctl = snd_ctl_new1(snd_usb_feature_unit_ctl, cval); if (!kctl) { kfree(cval); return -ENOMEM; } /* Set name", "kind": "function", "line": 99, "name": "snprintf", "signature": "snprintf(kctl->id.name, sizeof(kctl->id.name), name);"}, {"doc": "} /* Set name snprintf(kctl->id.name, sizeof(kctl->id.name), name); kctl->private_free = snd_usb_mixer_elem_free; /* set TLV if (tlv_callback) { kctl->tlv.c = tlv_callback; kctl->vd[0].access |= SNDRV_CTL_ELEM_ACCESS_TLV_READ | SNDRV_CTL_ELEM_ACCESS_TLV_CALLBACK; } /* Add control to mixer", "kind": "function", "line": 110, "name": "snd_usb_mixer_add_control", "signature": "return snd_usb_mixer_add_control(&cval->head, kctl);"}, {"doc": "if (!list) return -ENOMEM; if (listp) listp = list; list->mixer = mixer; list->id = id; list->resume = resume; kctl = snd_ctl_new1(knew, list); if (!kctl) { kfree(list); return -ENOMEM; } kctl->private_free = snd_usb_mixer_elem_free; /* don't use snd_usb_mixer_add_control() here, this is a special list element", "kind": "function", "line": 170, "name": "snd_usb_mixer_add_list", "signature": "return snd_usb_mixer_add_list(list, kctl, false);"}, {"kind": "function", "line": 217, "name": "wake_up", "signature": "wake_up(&mixer->rc_waitq);"}, {"kind": "function", "line": 244, "name": "poll_wait", "signature": "poll_wait(file, &mixer->rc_waitq, wait);"}, {"kind": "function", "line": 262, "name": "init_waitqueue_head", "signature": "init_waitqueue_head(&mixer->rc_waitq);"}, {"kind": "function", "line": 280, "name": "usb_free_urb", "signature": "usb_free_urb(mixer->rc_urb);"}, {"kind": "function", "line": 290, "name": "usb_fill_control_urb", "signature": "usb_fill_control_urb(mixer->rc_urb, mixer->chip->dev, usb_rcvctrlpipe(mixer->chip->dev, 0), (u8 *)mixer->rc_setup_packet, mixer->rc_buffer, len, snd_usb_soundblaster_remote_complete, mixer);"}, {"kind": "function", "line": 310, "name": "CLASS", "signature": "CLASS(snd_usb_lock, pm)(chip);"}, {"kind": "function", "line": 328, "name": "usb_sndctrlpipe", "signature": "usb_sndctrlpipe(chip->dev, 0), 0x24, USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_OTHER, value, index + 2, NULL, 0);"}, {"kind": "function", "line": 429, "name": "snd_iprintf", "signature": "snd_iprintf(buffer, \"%s jacks\\n\\n\", mixer->chip->card->shortname);"}, {"kind": "function", "line": 445, "name": "usb_rcvctrlpipe", "signature": "usb_rcvctrlpipe(mixer->chip->dev, 0), UAC_GET_MEM, USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE, 0, jacks[i].unitid << 8, buf, 3);"}, {"kind": "function", "line": 461, "name": "snd_ctl_enum_info", "signature": "return snd_ctl_enum_info(uinfo, 1, ARRAY_SIZE(texts), texts);"}, {"kind": "function", "line": 484, "name": "snd_usb_ctl_msg", "signature": "return snd_usb_ctl_msg(chip->dev, usb_sndctrlpipe(chip->dev, 0), UAC_SET_CUR, USB_RECIP_INTERFACE | USB_TYPE_CLASS | USB_DIR_OUT, 0x0400, 0x0e00, buf, 2);"}, {"kind": "function", "line": 566, "name": "snd_ctl_notify", "signature": "snd_ctl_notify(me->mixer->chip->card, SNDRV_CTL_EVENT_MASK_VALUE, &me->kctl->id);"}, {"kind": "function", "line": 585, "name": "dev_warn", "signature": "dev_warn(&snd_dev->dev, \"Failed to get input dev path\\n\");"}, {"kind": "function", "line": 642, "name": "input_unregister_handle", "signature": "err_unregister: input_unregister_handle(handle);"}, {"kind": "function", "line": 652, "name": "input_close_device", "signature": "input_close_device(handle);"}, {"kind": "function", "line": 710, "name": "snd_usb_mixer_elem_free", "signature": "snd_usb_mixer_elem_free(kctl);"}, {"kind": "function", "line": 741, "name": "strscpy", "signature": "strscpy(kctl->id.name, name, sizeof(kctl->id.name));"}, {"kind": "function", "line": 1134, "name": "dev_err", "signature": "dev_err(&dev->dev, \"unable to issue vendor read request (ret = %d)\", err);"}, {"kind": "function", "line": 1158, "name": "usb_control_msg", "signature": "return usb_control_msg(chip->dev, usb_sndctrlpipe(chip->dev, 0), (pval >> 16) & 0xff, USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_OUT, pval >> 24, pval & 0xffff, NULL, 0, 1000);"}, {"kind": "function", "line": 1292, "name": "snd_usb_ctrl_intf", "signature": "snd_usb_ctrl_intf(mixer->hostif) | ((pval & 0xff) << 8), value, 2);"}, {"kind": "function", "line": 1552, "name": "snd_usb_mixer_set_ctl_value", "signature": "snd_usb_mixer_set_ctl_value(cval, UAC_SET_CUR, cval->control << 8, samplerate_id);"}, {"kind": "function", "line": 1555, "name": "snd_usb_mixer_notify_id", "signature": "snd_usb_mixer_notify_id(mixer, unitid);"}, {"kind": "function", "line": 1726, "name": "BIT", "signature": "BIT(chan + (chan % 2) * num_outs - 1);"}, {"kind": "function", "line": 2239, "name": "HDA_VERB_CMD", "signature": "HDA_VERB_CMD(AC_VERB_GET_PIN_SENSE, node_id, 0), &sense);"}, {"kind": "function", "line": 3395, "name": "field_get", "signature": "return field_get(mask, val);"}, {"doc": "} return 0; } int snd_usb_mixer_apply_create_quirk(struct usb_mixer_interface *mixer) { int err = 0; err = snd_usb_soundblaster_remote_init(mixer); if (err < 0) return err; switch (mixer->chip->usb_id) { /* PreSonus AudioBox 22 VSL", "kind": "function", "line": 4249, "name": "USB_ID", "signature": "case USB_ID(0x194f, 0x0101): err = snd_audiobox_vsl_init(mixer);"}, {"kind": "function", "line": 4264, "name": "snd_card_ro_proc_new", "signature": "snd_card_ro_proc_new(mixer->chip->card, \"audigy2nx\", mixer, snd_audigy2nx_proc_read);"}, {"kind": "function", "line": 4439, "name": "usb_submit_urb", "signature": "usb_submit_urb(mixer->rc_urb, GFP_ATOMIC);"}, {"kind": "function", "line": 4452, "name": "usb_audio_dbg", "signature": "default: usb_audio_dbg(mixer->chip, \"memory change in unknown unit %d\\n\", unitid);"}, {"doc": "Approximation using 10 ranges based on output measurement on hw v1.2. This seems close to the cubic mapping e.g. alsamixer uses.", "kind": "function", "line": 4465, "name": "DECLARE_TLV_DB_RANGE", "signature": "static const DECLARE_TLV_DB_RANGE(scale, 0, 1, TLV_DB_MINMAX_ITEM(-5300, -4970), 2, 5, TLV_DB_MINMAX_ITEM(-4710, -4160), 6, 7, TLV_DB_MINMAX_ITEM(-3884, -3710), 8, 14, TLV_DB_MINMAX_ITEM(-3443, -2560)"}, {"kind": "function", "line": 4479, "name": "usb_audio_info", "signature": "usb_audio_info(mixer->chip, \"applying DragonFly dB scale quirk (0-50 variant)\\n\");"}, {"kind": "macro", "line": 296, "name": "snd_audigy2nx_led_info", "signature": "#define snd_audigy2nx_led_info"}, {"kind": "macro", "line": 539, "name": "SND_DUALSENSE_JACK_OUT_TERM_ID", "signature": "#define SND_DUALSENSE_JACK_OUT_TERM_ID"}, {"kind": "macro", "line": 541, "name": "SND_DUALSENSE_JACK_IN_TERM_ID", "signature": "#define SND_DUALSENSE_JACK_IN_TERM_ID"}, {"kind": "macro", "line": 1118, "name": "_MAKE_NI_CONTROL", "signature": "#define _MAKE_NI_CONTROL(bRequest, wIndex)"}, {"kind": "macro", "line": 2171, "name": "HDA_VERB_CMD", "signature": "#define HDA_VERB_CMD(V, N, D)"}, {"kind": "macro", "line": 2173, "name": "REALTEK_HDA_VALUE", "signature": "#define REALTEK_HDA_VALUE"}, {"kind": "macro", "line": 2175, "name": "REALTEK_HDA_SET", "signature": "#define REALTEK_HDA_SET"}, {"kind": "macro", "line": 2177, "name": "REALTEK_MANUAL_MODE", "signature": "#define REALTEK_MANUAL_MODE"}, {"kind": "macro", "line": 2178, "name": "REALTEK_HDA_GET_OUT", "signature": "#define REALTEK_HDA_GET_OUT"}, {"kind": "macro", "line": 2179, "name": "REALTEK_HDA_GET_IN", "signature": "#define REALTEK_HDA_GET_IN"}, {"kind": "macro", "line": 2180, "name": "REALTEK_AUDIO_FUNCTION_GROUP", "signature": "#define REALTEK_AUDIO_FUNCTION_GROUP"}, {"kind": "macro", "line": 2182, "name": "REALTEK_LINE1", "signature": "#define REALTEK_LINE1"}, {"kind": "macro", "line": 2183, "name": "REALTEK_VENDOR_REGISTERS", "signature": "#define REALTEK_VENDOR_REGISTERS"}, {"kind": "macro", "line": 2184, "name": "REALTEK_HP_OUT", "signature": "#define REALTEK_HP_OUT"}, {"kind": "macro", "line": 2185, "name": "REALTEK_CBJ_CTRL2", "signature": "#define REALTEK_CBJ_CTRL2"}, {"kind": "macro", "line": 2187, "name": "REALTEK_JACK_INTERRUPT_NODE", "signature": "#define REALTEK_JACK_INTERRUPT_NODE"}, {"kind": "macro", "line": 2189, "name": "REALTEK_MIC_FLAG", "signature": "#define REALTEK_MIC_FLAG"}, {"kind": "macro", "line": 2362, "name": "SND_RME_GET_STATUS1", "signature": "#define SND_RME_GET_STATUS1"}, {"kind": "macro", "line": 2364, "name": "SND_RME_GET_CURRENT_FREQ", "signature": "#define SND_RME_GET_CURRENT_FREQ"}, {"kind": "macro", "line": 2365, "name": "SND_RME_CLK_SYSTEM_SHIFT", "signature": "#define SND_RME_CLK_SYSTEM_SHIFT"}, {"kind": "macro", "line": 2366, "name": "SND_RME_CLK_SYSTEM_MASK", "signature": "#define SND_RME_CLK_SYSTEM_MASK"}, {"kind": "macro", "line": 2367, "name": "SND_RME_CLK_AES_SHIFT", "signature": "#define SND_RME_CLK_AES_SHIFT"}, {"kind": "macro", "line": 2368, "name": "SND_RME_CLK_SPDIF_SHIFT", "signature": "#define SND_RME_CLK_SPDIF_SHIFT"}, {"kind": "macro", "line": 2369, "name": "SND_RME_CLK_AES_SPDIF_MASK", "signature": "#define SND_RME_CLK_AES_SPDIF_MASK"}, {"kind": "macro", "line": 2370, "name": "SND_RME_CLK_SYNC_SHIFT", "signature": "#define SND_RME_CLK_SYNC_SHIFT"}, {"kind": "macro", "line": 2371, "name": "SND_RME_CLK_SYNC_MASK", "signature": "#define SND_RME_CLK_SYNC_MASK"}, {"kind": "macro", "line": 2372, "name": "SND_RME_CLK_FREQMUL_SHIFT", "signature": "#define SND_RME_CLK_FREQMUL_SHIFT"}, {"kind": "macro", "line": 2373, "name": "SND_RME_CLK_FREQMUL_MASK", "signature": "#define SND_RME_CLK_FREQMUL_MASK"}, {"kind": "macro", "line": 2374, "name": "SND_RME_CLK_SYSTEM", "signature": "#define SND_RME_CLK_SYSTEM(x)"}, {"kind": "macro", "line": 2376, "name": "SND_RME_CLK_AES", "signature": "#define SND_RME_CLK_AES(x)"}, {"kind": "macro", "line": 2378, "name": "SND_RME_CLK_SPDIF", "signature": "#define SND_RME_CLK_SPDIF(x)"}, {"kind": "macro", "line": 2380, "name": "SND_RME_CLK_SYNC", "signature": "#define SND_RME_CLK_SYNC(x)"}, {"kind": "macro", "line": 2382, "name": "SND_RME_CLK_FREQMUL", "signature": "#define SND_RME_CLK_FREQMUL(x)"}, {"kind": "macro", "line": 2384, "name": "SND_RME_CLK_AES_LOCK", "signature": "#define SND_RME_CLK_AES_LOCK"}, {"kind": "macro", "line": 2385, "name": "SND_RME_CLK_AES_SYNC", "signature": "#define SND_RME_CLK_AES_SYNC"}, {"kind": "macro", "line": 2386, "name": "SND_RME_CLK_SPDIF_LOCK", "signature": "#define SND_RME_CLK_SPDIF_LOCK"}, {"kind": "macro", "line": 2387, "name": "SND_RME_CLK_SPDIF_SYNC", "signature": "#define SND_RME_CLK_SPDIF_SYNC"}, {"kind": "macro", "line": 2388, "name": "SND_RME_SPDIF_IF_SHIFT", "signature": "#define SND_RME_SPDIF_IF_SHIFT"}, {"kind": "macro", "line": 2389, "name": "SND_RME_SPDIF_FORMAT_SHIFT", "signature": "#define SND_RME_SPDIF_FORMAT_SHIFT"}, {"kind": "macro", "line": 2390, "name": "SND_RME_BINARY_MASK", "signature": "#define SND_RME_BINARY_MASK"}, {"kind": "macro", "line": 2391, "name": "SND_RME_SPDIF_IF", "signature": "#define SND_RME_SPDIF_IF(x)"}, {"kind": "macro", "line": 2393, "name": "SND_RME_SPDIF_FORMAT", "signature": "#define SND_RME_SPDIF_FORMAT(x)"}, {"kind": "macro", "line": 2405, "name": "SND_RME_RATE_IDX_AES_SPDIF_NUM", "signature": "#define SND_RME_RATE_IDX_AES_SPDIF_NUM"}, {"kind": "macro", "line": 2743, "name": "SND_BBFPRO_CTL_REG_MASK", "signature": "#define SND_BBFPRO_CTL_REG_MASK"}, {"kind": "macro", "line": 2745, "name": "SND_BBFPRO_CTL_IDX_MASK", "signature": "#define SND_BBFPRO_CTL_IDX_MASK"}, {"kind": "macro", "line": 2746, "name": "SND_BBFPRO_CTL_IDX_SHIFT", "signature": "#define SND_BBFPRO_CTL_IDX_SHIFT"}, {"kind": "macro", "line": 2747, "name": "SND_BBFPRO_CTL_VAL_MASK", "signature": "#define SND_BBFPRO_CTL_VAL_MASK"}, {"kind": "macro", "line": 2748, "name": "SND_BBFPRO_CTL_VAL_SHIFT", "signature": "#define SND_BBFPRO_CTL_VAL_SHIFT"}, {"kind": "macro", "line": 2749, "name": "SND_BBFPRO_CTL_REG1_CLK_MASTER", "signature": "#define SND_BBFPRO_CTL_REG1_CLK_MASTER"}, {"kind": "macro", "line": 2750, "name": "SND_BBFPRO_CTL_REG1_CLK_OPTICAL", "signature": "#define SND_BBFPRO_CTL_REG1_CLK_OPTICAL"}, {"kind": "macro", "line": 2751, "name": "SND_BBFPRO_CTL_REG1_SPDIF_PRO", "signature": "#define SND_BBFPRO_CTL_REG1_SPDIF_PRO"}, {"kind": "macro", "line": 2752, "name": "SND_BBFPRO_CTL_REG1_SPDIF_EMPH", "signature": "#define SND_BBFPRO_CTL_REG1_SPDIF_EMPH"}, {"kind": "macro", "line": 2753, "name": "SND_BBFPRO_CTL_REG1_SPDIF_OPTICAL", "signature": "#define SND_BBFPRO_CTL_REG1_SPDIF_OPTICAL"}, {"kind": "macro", "line": 2754, "name": "SND_BBFPRO_CTL_REG2_48V_AN1", "signature": "#define SND_BBFPRO_CTL_REG2_48V_AN1"}, {"kind": "macro", "line": 2755, "name": "SND_BBFPRO_CTL_REG2_48V_AN2", "signature": "#define SND_BBFPRO_CTL_REG2_48V_AN2"}, {"kind": "macro", "line": 2756, "name": "SND_BBFPRO_CTL_REG2_SENS_IN3", "signature": "#define SND_BBFPRO_CTL_REG2_SENS_IN3"}, {"kind": "macro", "line": 2757, "name": "SND_BBFPRO_CTL_REG2_SENS_IN4", "signature": "#define SND_BBFPRO_CTL_REG2_SENS_IN4"}, {"kind": "macro", "line": 2758, "name": "SND_BBFPRO_CTL_REG2_PAD_AN1", "signature": "#define SND_BBFPRO_CTL_REG2_PAD_AN1"}, {"kind": "macro", "line": 2759, "name": "SND_BBFPRO_CTL_REG2_PAD_AN2", "signature": "#define SND_BBFPRO_CTL_REG2_PAD_AN2"}, {"kind": "macro", "line": 2760, "name": "SND_BBFPRO_MIXER_MAIN_OUT_CH_OFFSET", "signature": "#define SND_BBFPRO_MIXER_MAIN_OUT_CH_OFFSET"}, {"kind": "macro", "line": 2762, "name": "SND_BBFPRO_MIXER_IDX_MASK", "signature": "#define SND_BBFPRO_MIXER_IDX_MASK"}, {"kind": "macro", "line": 2763, "name": "SND_BBFPRO_MIXER_VAL_MASK", "signature": "#define SND_BBFPRO_MIXER_VAL_MASK"}, {"kind": "macro", "line": 2764, "name": "SND_BBFPRO_MIXER_VAL_SHIFT", "signature": "#define SND_BBFPRO_MIXER_VAL_SHIFT"}, {"kind": "macro", "line": 2765, "name": "SND_BBFPRO_MIXER_VAL_MIN", "signature": "#define SND_BBFPRO_MIXER_VAL_MIN"}, {"kind": "macro", "line": 2766, "name": "SND_BBFPRO_MIXER_VAL_MAX", "signature": "#define SND_BBFPRO_MIXER_VAL_MAX"}, {"kind": "macro", "line": 2767, "name": "SND_BBFPRO_GAIN_CHANNEL_MASK", "signature": "#define SND_BBFPRO_GAIN_CHANNEL_MASK"}, {"kind": "macro", "line": 2769, "name": "SND_BBFPRO_GAIN_CHANNEL_SHIFT", "signature": "#define SND_BBFPRO_GAIN_CHANNEL_SHIFT"}, {"kind": "macro", "line": 2770, "name": "SND_BBFPRO_GAIN_VAL_MASK", "signature": "#define SND_BBFPRO_GAIN_VAL_MASK"}, {"kind": "macro", "line": 2771, "name": "SND_BBFPRO_GAIN_VAL_MIN", "signature": "#define SND_BBFPRO_GAIN_VAL_MIN"}, {"kind": "macro", "line": 2772, "name": "SND_BBFPRO_GAIN_VAL_MIC_MAX", "signature": "#define SND_BBFPRO_GAIN_VAL_MIC_MAX"}, {"kind": "macro", "line": 2773, "name": "SND_BBFPRO_GAIN_VAL_LINE_MAX", "signature": "#define SND_BBFPRO_GAIN_VAL_LINE_MAX"}, {"kind": "macro", "line": 2774, "name": "SND_BBFPRO_USBREQ_CTL_REG1", "signature": "#define SND_BBFPRO_USBREQ_CTL_REG1"}, {"kind": "macro", "line": 2776, "name": "SND_BBFPRO_USBREQ_CTL_REG2", "signature": "#define SND_BBFPRO_USBREQ_CTL_REG2"}, {"kind": "macro", "line": 2777, "name": "SND_BBFPRO_USBREQ_GAIN", "signature": "#define SND_BBFPRO_USBREQ_GAIN"}, {"kind": "macro", "line": 2778, "name": "SND_BBFPRO_USBREQ_MIXER", "signature": "#define SND_BBFPRO_USBREQ_MIXER"}, {"kind": "macro", "line": 3297, "name": "RME_DIGIFACE_READ_STATUS", "signature": "#define RME_DIGIFACE_READ_STATUS"}, {"kind": "macro", "line": 3299, "name": "RME_DIGIFACE_STATUS_REG0L", "signature": "#define RME_DIGIFACE_STATUS_REG0L"}, {"kind": "macro", "line": 3300, "name": "RME_DIGIFACE_STATUS_REG0H", "signature": "#define RME_DIGIFACE_STATUS_REG0H"}, {"kind": "macro", "line": 3301, "name": "RME_DIGIFACE_STATUS_REG1L", "signature": "#define RME_DIGIFACE_STATUS_REG1L"}, {"kind": "macro", "line": 3302, "name": "RME_DIGIFACE_STATUS_REG1H", "signature": "#define RME_DIGIFACE_STATUS_REG1H"}, {"kind": "macro", "line": 3303, "name": "RME_DIGIFACE_STATUS_REG2L", "signature": "#define RME_DIGIFACE_STATUS_REG2L"}, {"kind": "macro", "line": 3304, "name": "RME_DIGIFACE_STATUS_REG2H", "signature": "#define RME_DIGIFACE_STATUS_REG2H"}, {"kind": "macro", "line": 3305, "name": "RME_DIGIFACE_STATUS_REG3L", "signature": "#define RME_DIGIFACE_STATUS_REG3L"}, {"kind": "macro", "line": 3306, "name": "RME_DIGIFACE_STATUS_REG3H", "signature": "#define RME_DIGIFACE_STATUS_REG3H"}, {"kind": "macro", "line": 3307, "name": "RME_DIGIFACE_CTL_REG1", "signature": "#define RME_DIGIFACE_CTL_REG1"}, {"kind": "macro", "line": 3309, "name": "RME_DIGIFACE_CTL_REG2", "signature": "#define RME_DIGIFACE_CTL_REG2"}, {"kind": "macro", "line": 3312, "name": "RME_DIGIFACE_REGISTER", "signature": "#define RME_DIGIFACE_REGISTER(reg, mask)"}, {"kind": "macro", "line": 3313, "name": "RME_DIGIFACE_INVERT", "signature": "#define RME_DIGIFACE_INVERT"}, {"kind": "macro", "line": 3316, "name": "field_get", "signature": "#define field_get(_mask, _reg)"}, {"kind": "macro", "line": 3317, "name": "field_prep", "signature": "#define field_prep(_mask, _val)"}, {"kind": "macro", "line": 3715, "name": "SND_DJM_CAP_LINE", "signature": "#define SND_DJM_CAP_LINE"}, {"kind": "macro", "line": 3716, "name": "SND_DJM_CAP_CDLINE", "signature": "#define SND_DJM_CAP_CDLINE"}, {"kind": "macro", "line": 3717, "name": "SND_DJM_CAP_DIGITAL", "signature": "#define SND_DJM_CAP_DIGITAL"}, {"kind": "macro", "line": 3718, "name": "SND_DJM_CAP_PHONO", "signature": "#define SND_DJM_CAP_PHONO"}, {"kind": "macro", "line": 3719, "name": "SND_DJM_CAP_PREFADER", "signature": "#define SND_DJM_CAP_PREFADER"}, {"kind": "macro", "line": 3720, "name": "SND_DJM_CAP_PFADER", "signature": "#define SND_DJM_CAP_PFADER"}, {"kind": "macro", "line": 3721, "name": "SND_DJM_CAP_XFADERA", "signature": "#define SND_DJM_CAP_XFADERA"}, {"kind": "macro", "line": 3722, "name": "SND_DJM_CAP_XFADERB", "signature": "#define SND_DJM_CAP_XFADERB"}, {"kind": "macro", "line": 3723, "name": "SND_DJM_CAP_MIC", "signature": "#define SND_DJM_CAP_MIC"}, {"kind": "macro", "line": 3724, "name": "SND_DJM_CAP_AUX", "signature": "#define SND_DJM_CAP_AUX"}, {"kind": "macro", "line": 3725, "name": "SND_DJM_CAP_RECOUT", "signature": "#define SND_DJM_CAP_RECOUT"}, {"kind": "macro", "line": 3726, "name": "SND_DJM_CAP_RECOUT_NOMIC", "signature": "#define SND_DJM_CAP_RECOUT_NOMIC"}, {"kind": "macro", "line": 3727, "name": "SND_DJM_CAP_NONE", "signature": "#define SND_DJM_CAP_NONE"}, {"kind": "macro", "line": 3728, "name": "SND_DJM_CAP_FXSEND", "signature": "#define SND_DJM_CAP_FXSEND"}, {"kind": "macro", "line": 3729, "name": "SND_DJM_CAP_CH1PFADER", "signature": "#define SND_DJM_CAP_CH1PFADER"}, {"kind": "macro", "line": 3730, "name": "SND_DJM_CAP_CH2PFADER", "signature": "#define SND_DJM_CAP_CH2PFADER"}, {"kind": "macro", "line": 3731, "name": "SND_DJM_CAP_CH3PFADER", "signature": "#define SND_DJM_CAP_CH3PFADER"}, {"kind": "macro", "line": 3732, "name": "SND_DJM_CAP_CH4PFADER", "signature": "#define SND_DJM_CAP_CH4PFADER"}, {"kind": "macro", "line": 3733, "name": "SND_DJM_CAP_EXT1SEND", "signature": "#define SND_DJM_CAP_EXT1SEND"}, {"kind": "macro", "line": 3734, "name": "SND_DJM_CAP_EXT2SEND", "signature": "#define SND_DJM_CAP_EXT2SEND"}, {"kind": "macro", "line": 3735, "name": "SND_DJM_CAP_CH1PREFADER", "signature": "#define SND_DJM_CAP_CH1PREFADER"}, {"kind": "macro", "line": 3736, "name": "SND_DJM_CAP_CH2PREFADER", "signature": "#define SND_DJM_CAP_CH2PREFADER"}, {"kind": "macro", "line": 3737, "name": "SND_DJM_CAP_CH3PREFADER", "signature": "#define SND_DJM_CAP_CH3PREFADER"}, {"kind": "macro", "line": 3738, "name": "SND_DJM_CAP_CH4PREFADER", "signature": "#define SND_DJM_CAP_CH4PREFADER"}, {"kind": "macro", "line": 3741, "name": "SND_DJM_PB_CH1", "signature": "#define SND_DJM_PB_CH1"}, {"kind": "macro", "line": 3742, "name": "SND_DJM_PB_CH2", "signature": "#define SND_DJM_PB_CH2"}, {"kind": "macro", "line": 3743, "name": "SND_DJM_PB_AUX", "signature": "#define SND_DJM_PB_AUX"}, {"kind": "macro", "line": 3744, "name": "SND_DJM_WINDEX_CAP", "signature": "#define SND_DJM_WINDEX_CAP"}, {"kind": "macro", "line": 3746, "name": "SND_DJM_WINDEX_CAPLVL", "signature": "#define SND_DJM_WINDEX_CAPLVL"}, {"kind": "macro", "line": 3747, "name": "SND_DJM_WINDEX_PB", "signature": "#define SND_DJM_WINDEX_PB"}, {"kind": "macro", "line": 3750, "name": "SND_DJM_VALUE_MASK", "signature": "#define SND_DJM_VALUE_MASK"}, {"kind": "macro", "line": 3751, "name": "SND_DJM_GROUP_MASK", "signature": "#define SND_DJM_GROUP_MASK"}, {"kind": "macro", "line": 3752, "name": "SND_DJM_DEVICE_MASK", "signature": "#define SND_DJM_DEVICE_MASK"}, {"kind": "macro", "line": 3753, "name": "SND_DJM_GROUP_SHIFT", "signature": "#define SND_DJM_GROUP_SHIFT"}, {"kind": "macro", "line": 3754, "name": "SND_DJM_DEVICE_SHIFT", "signature": "#define SND_DJM_DEVICE_SHIFT"}, {"kind": "macro", "line": 3758, "name": "SND_DJM_250MK2_IDX", "signature": "#define SND_DJM_250MK2_IDX"}, {"kind": "macro", "line": 3759, "name": "SND_DJM_750_IDX", "signature": "#define SND_DJM_750_IDX"}, {"kind": "macro", "line": 3760, "name": "SND_DJM_850_IDX", "signature": "#define SND_DJM_850_IDX"}, {"kind": "macro", "line": 3761, "name": "SND_DJM_900NXS2_IDX", "signature": "#define SND_DJM_900NXS2_IDX"}, {"kind": "macro", "line": 3762, "name": "SND_DJM_750MK2_IDX", "signature": "#define SND_DJM_750MK2_IDX"}, {"kind": "macro", "line": 3763, "name": "SND_DJM_450_IDX", "signature": "#define SND_DJM_450_IDX"}, {"kind": "macro", "line": 3764, "name": "SND_DJM_A9_IDX", "signature": "#define SND_DJM_A9_IDX"}, {"kind": "macro", "line": 3765, "name": "SND_DJM_V10_IDX", "signature": "#define SND_DJM_V10_IDX"}, {"kind": "macro", "line": 3766, "name": "SND_DJM_CTL", "signature": "#define SND_DJM_CTL(_name, suffix, _default_value, _windex)"}, {"kind": "macro", "line": 3773, "name": "SND_DJM_DEVICE", "signature": "#define SND_DJM_DEVICE(suffix)"}]}, {"doc": "==================================================================== VSL-DSP: Captura COMPLETA de tráfico USB del AudioBox ====================================================================", "id": "legacy/test.sh", "kind": "module", "label": "test.sh", "language": "sh", "sha256": "f0947b318a5d14e9", "symbol_count": 0, "symbols": []}, {"doc": "test_connection.c  include <stdio.h> include \"vsl_config.h\" include \"vsl_dsp_transport.h\" // Asumiendo que esta es la plantilla B", "id": "legacy/test_connection.c", "kind": "module", "label": "test_connection.c", "language": "c", "sha256": "3ae44723d5e8a018", "symbol_count": 3, "symbols": [{"doc": "include <stdio.h> include \"vsl_config.h\" include \"vsl_dsp_transport.h\" // Asumiendo que esta es la plantilla B", "kind": "function", "line": 6, "name": "main", "signature": "int main()"}, {"kind": "function", "line": 8, "name": "printf", "signature": "printf(\"Intentando conectar al dispositivo VSL %04X:%04X...\\n\", VSL_VENDOR_ID, VSL_PRODUCT_ID);"}, {"kind": "function", "line": 19, "name": "VSL_Close_Device", "signature": "VSL_Close_Device();"}]}, {"doc": "vsl_config.h (VERSION CORREGIDA)  ifndef VSL_CONFIG_H define VSL_CONFIG_H  include <stdint.h>  ======================================================= BLOQUEADORES CRÍTICOS (Hardware) ======================================================= define VSL_VENDOR_ID   0x194f define VSL_PRODUCT_ID  0x0101 define VSL_REPORT_ID   0x06  ======================================================= CONSTANTES CRÍTICAS VSL-DSP (Necesarias para la lógica) =======================================================  Factor de escala usado en la fórmula VSL (Confirmado en la PoC Python) define VSL_SCALE_FACTOR        1000.0f  Máximo valor codificado de 16 bits (0xFFFF) define VSL_MAX_ENCODED_INT     65535  define VSL_PACKET_SIZE         64      // 0x40 bytes define VSL_PAYLOAD_SIZE        5       // Byte 1 (ID LSB) a Byte 4 (Value MSB)  endif // VSL_CONFIG_H", "id": "legacy/vsl_config.h", "kind": "module", "label": "vsl_config.h", "language": "h", "sha256": "508da740df2b3805", "symbol_count": 8, "symbols": [{"kind": "macro", "line": 4, "name": "VSL_CONFIG_H", "signature": "#define VSL_CONFIG_H"}, {"kind": "macro", "line": 11, "name": "VSL_VENDOR_ID", "signature": "#define VSL_VENDOR_ID"}, {"kind": "macro", "line": 12, "name": "VSL_PRODUCT_ID", "signature": "#define VSL_PRODUCT_ID"}, {"kind": "macro", "line": 13, "name": "VSL_REPORT_ID", "signature": "#define VSL_REPORT_ID"}, {"kind": "macro", "line": 20, "name": "VSL_SCALE_FACTOR", "signature": "#define VSL_SCALE_FACTOR"}, {"kind": "macro", "line": 23, "name": "VSL_MAX_ENCODED_INT", "signature": "#define VSL_MAX_ENCODED_INT"}, {"kind": "macro", "line": 24, "name": "VSL_PACKET_SIZE", "signature": "#define VSL_PACKET_SIZE"}, {"kind": "macro", "line": 26, "name": "VSL_PAYLOAD_SIZE", "signature": "#define VSL_PAYLOAD_SIZE"}]}, {"id": "legacy/vsl_config.py", "kind": "module", "label": "vsl_config.py", "language": "py", "sha256": "f497ee94aa7dcc87", "symbol_count": 3, "symbols": [{"doc": "Estructura que replica exactamente VSL_Parameter del código C.\nTodos los campos están confirmados del desensamblado.", "kind": "class", "line": 40, "name": "VSLParameter", "signature": "class VSLParameter(NamedTuple)"}, {"doc": "Valida que todos los valores críticos estén configurados.\n\nReturns:\n    (is_valid, error_message)", "kind": "method", "line": 92, "name": "validate_configuration", "signature": "def validate_configuration()"}, {"doc": "Imprime el estado de la configuración con formato.", "kind": "method", "line": 116, "name": "print_configuration_status", "signature": "def print_configuration_status()"}]}, {"id": "legacy/vsl_core.py", "kind": "module", "label": "vsl_core.py", "language": "py", "sha256": "8a0f062d0a3852e1", "symbol_count": 5, "symbols": [{"doc": "Traducción de FUN_00132c90 (VSL_Encode_Gain en C).\n\nConvierte un valor lineal (0.0 - 1.0) a la escala exponencial del DSP.\n\nFórmula:\n    encoded = coeff_offset_A + coeff_C1 * exp(norm_factor * log_factor)\n\nArgs:\n    linear_value: Valor lineal de entrada (0.0 a 1.0)\n    param: Estructura de parámetros con coeficientes\n    \nReturns:\n    Valor codificado en float (rango: ~-10.0 a ~1000.0)\n    \nRaises:\n    ValueError: Si param es inválido", "kind": "function", "line": 16, "name": "vsl_encode_gain", "signature": "def vsl_encode_gain(linear_value, param)"}, {"doc": "Traducción de FUN_00132d00 (VSL_Map_Frequency en C).\n\nConvierte una posición lineal (0.0 - 1.0) a frecuencia logarítmica (Hz).\n\nArgs:\n    linear_position: Posición lineal (0.0 a 1.0)\n    param: Estructura de parámetros con rangos de frecuencia\n    \nReturns:\n    Frecuencia en Hz (ej: 20.0 a 20000.0)\n    \nRaises:\n    ValueError: Si las frecuencias son inválidas", "kind": "function", "line": 58, "name": "vsl_map_frequency", "signature": "def vsl_map_frequency(linear_position, param)"}, {"doc": "Traducción de VSL_Final_Encode_To_Int en C.\n\nConvierte el valor codificado float a entero de 16-bit para el DSP.\n\nArgs:\n    encoded_float: Valor float codificado (ej: -10.0 a 1000.0)\n    param: Estructura de parámetros con max_encoded_int\n    \nReturns:\n    Valor entero (0 a 65535)", "kind": "function", "line": 94, "name": "vsl_final_encode_to_int", "signature": "def vsl_final_encode_to_int(encoded_float, param)"}, {"doc": "Traducción de FUN_00132da8 (VSL_Decode_Frequency en C).\n\nConvierte una frecuencia real (Hz) a su posición lineal (0.0 - 1.0).\n\nArgs:\n    freq_hz_value: Frecuencia en Hz\n    param: Estructura de parámetros con rangos\n    \nReturns:\n    Posición lineal (0.0 a 1.0)\n    \nRaises:\n    ValueError: Si las frecuencias son inválidas", "kind": "function", "line": 127, "name": "vsl_decode_frequency", "signature": "def vsl_decode_frequency(freq_hz_value, param)"}, {"doc": "Valida la integridad de un VSLParameter.\n\nReturns:\n    (is_valid, error_message)", "kind": "function", "line": 170, "name": "validate_parameter", "signature": "def validate_parameter(param)"}]}, {"doc": "include \"vsl_dsp_logic.h\"  Declaración de la nueva función de envío", "id": "legacy/vsl_dsp_logic.c", "kind": "module", "label": "vsl_dsp_logic.c", "language": "c", "sha256": "def9d8443c1a7cfe", "symbol_count": 6, "symbols": [{"doc": "Implementación de FUN_00132c90", "kind": "function", "line": 11, "name": "VSL_Encode_Gain", "signature": "float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)"}, {"doc": "Implementación de FUN_00132d00", "kind": "function", "line": 29, "name": "VSL_Map_Frequency", "signature": "float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)"}, {"doc": "@brief Convierte el valor codificado en float a un entero sin signo para el firmware. @note Basado en la hipótesis común de DSP donde el rango flotante es 0.0 - 1000.0. Si el valor real es diferente, solo se debe cambiar la constante VSL_MAX_ENCODED_FLOAT.", "kind": "function", "line": 58, "name": "VSL_Final_Encode_To_Int", "signature": "uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)"}, {"doc": "Implementación de FUN_00132da8", "kind": "function", "line": 78, "name": "VSL_Decode_Frequency", "signature": "float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)"}, {"doc": "Declaración de la nueva función de envío", "kind": "function", "line": 4, "name": "VSL_Build_And_Send_Packet", "signature": "void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float);"}, {"doc": "4. Conversión a frecuencia lineal (exp2f)", "kind": "function", "line": 46, "name": "exp2f", "signature": "return exp2f(log2_value);"}]}, {"doc": "ifndef VSL_DSP_LOGIC_H define VSL_DSP_LOGIC_H  include <stdint.h> include <math.h> include <float.h> // Para fmaxf, fminf  Constante para la conversión de logaritmo natural (ln) a logaritmo base 2 (log2) 1 / ln(2) ≈ 1.442695 define VSL_INV_LN2 1.442695f  Estructura que almacena todos los coeficientes precalculados del DSP", "id": "legacy/vsl_dsp_logic.h", "kind": "module", "label": "vsl_dsp_logic.h", "language": "h", "sha256": "92477980c64a3050", "symbol_count": 7, "symbols": [{"doc": "Estructura que almacena todos los coeficientes precalculados del DSP", "kind": "struct", "line": 13, "name": "VSL_Parameter"}, {"doc": "@brief Codifica un valor lineal (ej. 0.5) a la escala exponencial/logarítmica del DSP (Ganancia/Volumen). @param linear_value El valor lineal de entrada (ej. la posición del slider, 0.0 a 1.0). @param param La estructura del parámetro con sus coeficientes. @return El valor codificado en formato float (listo para la conversión final a int).", "kind": "function", "line": 42, "name": "VSL_Encode_Gain", "signature": "float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);"}, {"doc": "@brief Convierte una posición lineal (ej. 0.5) a su frecuencia logarítmica (Hz) real. @param linear_position La posición lineal de entrada (0.0 a 1.0). @param param La estructura del parámetro con sus coeficientes. @return La frecuencia mapeada en Hertz (Hz).", "kind": "function", "line": 50, "name": "VSL_Map_Frequency", "signature": "float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);"}, {"doc": "@brief Convierte el valor codificado en float a un entero sin signo para el firmware. @note ESTA FUNCIÓN ES UN MARCADOR DE POSICIÓN. El factor de escala final (la fórmula interna) aún debe ser determinado con ingeniería inversa. @param encoded_float El valor float retornado por VSL_Encode_Gain o VSL_Map_Frequency. @param param La estructura del parámetro con la precisión máxima entera. @return El valor binario final (uint32_t) listo para ser enviado en el paquete DSP.", "kind": "function", "line": 60, "name": "VSL_Final_Encode_To_Int", "signature": "uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param);"}, {"doc": "@brief Decodifica una frecuencia real (Hz) del DSP a su posición lineal de control (0.0 a 1.0). @param freq_hz_value La frecuencia real en Hertz leída del DSP. @param param La estructura del parámetro con sus rangos. @return La posición lineal (0.0 a 1.0) para actualizar el control de la GUI.", "kind": "function", "line": 73, "name": "VSL_Decode_Frequency", "signature": "float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);"}, {"kind": "macro", "line": 2, "name": "VSL_DSP_LOGIC_H", "signature": "#define VSL_DSP_LOGIC_H"}, {"kind": "macro", "line": 10, "name": "VSL_INV_LN2", "signature": "#define VSL_INV_LN2"}]}, {"doc": "vsl_dsp_transport.c (Añadir la Plantilla B completa aquí)  include <stdio.h> include <string.h> include <math.h> include <hidapi/hidapi.h> include <stdlib.h> include \"vsl_config.h\" include \"vsl_dsp_transport.h\"  Handle de Singleton (Regla #5: Diseño Escalable)", "id": "legacy/vsl_dsp_transport.c", "kind": "module", "label": "vsl_dsp_transport.c", "language": "c", "sha256": "a80b5b159dcff298", "symbol_count": 12, "symbols": [{"doc": "... (las inclusiones y el singleton handle) ...", "kind": "function", "line": 22, "name": "VSL_Init_Device", "signature": "int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)"}, {"kind": "function", "line": 69, "name": "VSL_Close_Device", "signature": "void VSL_Close_Device(void)"}, {"kind": "function", "line": 78, "name": "VSL_Get_Device_Handle", "signature": "hid_device* VSL_Get_Device_Handle(void)"}, {"doc": "@brief Función de I/O real usando HIDAPI. @note DEBE SER REEMPLAZADA con la lógica específica de tu dispositivo (Report ID, longitud, etc.)", "kind": "function", "line": 97, "name": "FUN_Send_Packet", "signature": "void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length)"}, {"doc": "Implementación de la función de construcción y envío", "kind": "function", "line": 140, "name": "VSL_Build_And_Send_Packet", "signature": "void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float)"}, {"kind": "function", "line": 28, "name": "fprintf", "signature": "fprintf(stderr, \"Error: HIDAPI init failed\\n\");"}, {"kind": "function", "line": 49, "name": "hid_free_enumeration", "signature": "hid_free_enumeration(devs);"}, {"kind": "function", "line": 55, "name": "free", "signature": "free(target_path);"}, {"kind": "function", "line": 62, "name": "hid_exit", "signature": "hid_exit();"}, {"kind": "function", "line": 65, "name": "printf", "signature": "printf(\"VSL Device handle opened successfully via path: %04X:%04X\\n\", vendor_id, product_id);"}, {"kind": "function", "line": 72, "name": "hid_close", "signature": "hid_close(vsl_device_handle);"}, {"doc": "Copiar ID (2 bytes) y Value (2 bytes) al buffer, iniciando en buf[1] (después del Report ID)", "kind": "function", "line": 121, "name": "memcpy", "signature": "memcpy(&buf[1], &net_id, sizeof(uint16_t));"}]}, {"doc": "vsl_dsp_transport.h (CORREGIDO)  ifndef VSL_DSP_TRANSPORT_H define VSL_DSP_TRANSPORT_H  include <stdint.h> include <stddef.h> include <hidapi/hidapi.h> include \"vsl_config.h\" // Solo incluye la configuración  Estructura de Paquete: Sin 'header' (lo quitaste en la estructura typedef)", "id": "legacy/vsl_dsp_transport.h", "kind": "module", "label": "vsl_dsp_transport.h", "language": "h", "sha256": "7410356491c9230c", "symbol_count": 7, "symbols": [{"doc": "Estructura de Paquete: Sin 'header' (lo quitaste en la estructura typedef)", "kind": "struct", "line": 12, "name": "VSL_DSP_Packet"}, {"doc": "1. Funciones de Inicialización y Cierre (¡Ambas declaradas!)", "kind": "function", "line": 19, "name": "VSL_Init_Device", "signature": "int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id);"}, {"kind": "function", "line": 20, "name": "VSL_Close_Device", "signature": "void VSL_Close_Device(void);"}, {"kind": "function", "line": 21, "name": "VSL_Get_Device_Handle", "signature": "hid_device* VSL_Get_Device_Handle(void);"}, {"doc": "2. Funciones de Envío", "kind": "function", "line": 24, "name": "FUN_Send_Packet", "signature": "void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length);"}, {"kind": "function", "line": 25, "name": "VSL_Build_And_Send_Packet", "signature": "void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float);"}, {"kind": "macro", "line": 4, "name": "VSL_DSP_TRANSPORT_H", "signature": "#define VSL_DSP_TRANSPORT_H"}]}, {"id": "legacy/vsl_hid_io.py", "kind": "module", "label": "vsl_hid_io.py", "language": "py", "sha256": "a7edc02a249a85db", "symbol_count": 9, "symbols": [{"doc": "Gestor de dispositivo VSL-DSP con patrón Singleton.\nManeja la conexión HID y envío de paquetes.", "kind": "class", "line": 31, "name": "VSLDevice", "signature": "class VSLDevice"}, {"doc": "Enumera todos los dispositivos HID conectados.\nÚtil para descubrir VID/PID del hardware.", "kind": "method", "line": 149, "name": "enumerate_vsl_devices", "signature": "def enumerate_vsl_devices()"}, {"kind": "method", "line": 39, "name": "__new__", "signature": "def __new__(cls)"}, {"kind": "method", "line": 45, "name": "__init__", "signature": "def __init__(self)"}, {"doc": "Abre la conexión con el dispositivo VSL.\n\nReturns:\n    True si la conexión fue exitosa, False en caso contrario", "kind": "method", "line": 59, "name": "open", "signature": "def open(self)"}, {"doc": "Cierra la conexión con el dispositivo.", "kind": "method", "line": 90, "name": "close", "signature": "def close(self)"}, {"doc": "Envía un paquete VSL al dispositivo.\n\nArgs:\n    packet: VSLPacket a enviar\n    \nReturns:\n    True si el envío fue exitoso", "kind": "method", "line": 101, "name": "send_packet", "signature": "def send_packet(self, packet)"}, {"doc": "Context manager entry.", "kind": "method", "line": 139, "name": "__enter__", "signature": "def __enter__(self)"}, {"doc": "Context manager exit.", "kind": "method", "line": 144, "name": "__exit__", "signature": "def __exit__(self, exc_type, exc_val, exc_tb)"}]}, {"id": "legacy/vsl_poc_main.py", "kind": "module", "label": "vsl_poc_main.py", "language": "py", "sha256": "8723ac23990f418d", "symbol_count": 7, "symbols": [{"doc": "Test de codificación de ganancia con tabla de validación.", "kind": "function", "line": 43, "name": "test_gain_encoding", "signature": "def test_gain_encoding()"}, {"doc": "Test de mapeo logarítmico de frecuencias.", "kind": "function", "line": 72, "name": "test_frequency_mapping", "signature": "def test_frequency_mapping()"}, {"doc": "Test de construcción de paquetes HID.", "kind": "function", "line": 92, "name": "test_packet_construction", "signature": "def test_packet_construction()"}, {"doc": "Test de casos extremos y validación de errores.", "kind": "function", "line": 150, "name": "test_edge_cases", "signature": "def test_edge_cases()"}, {"doc": "Simula el flujo completo: Usuario → Encoding → Paquete.", "kind": "function", "line": 197, "name": "run_full_workflow", "signature": "def run_full_workflow()"}, {"doc": "Imprime resumen del estado del proyecto.", "kind": "function", "line": 229, "name": "print_summary", "signature": "def print_summary()"}, {"doc": "Función principal de la PoC.", "kind": "function", "line": 266, "name": "main", "signature": "def main()"}]}, {"doc": "PASO 1: (Fuera de este entorno) Capturar tráfico USB con Wireshark/usbmon Guardar como: audiobox_full_sweep.pcap  PASO 2: Ejecutar el analizador python3 vsl_protocol_analyzer.py audiobox_full_sweep.pcap", "id": "legacy/vsl_protocol_analyzer.py", "kind": "module", "label": "vsl_protocol_analyzer.py", "language": "py", "sha256": "f87cb90ff4e9b30f", "symbol_count": 7, "symbols": [{"doc": "Parámetros DSP descifrados con coeficientes y rangos.", "kind": "class", "line": 28, "name": "VSLParameter", "signature": "class VSLParameter"}, {"doc": "Simula VSL_Decode_Gain. Convierte un entero a un valor de usuario (dB).\n\nFórmula inversa confirmada: \nuser_value = (log2(encoded_float * range_span) / log_factor) + min_db\n\nUsaremos la simplificación de mapeo lineal para la PoC, ya que el valor \nconfirmado (40793) implica que no es un simple mapeo lineal \n(40793 / 65535 = 0.6225). La fórmula real de decodificación logarítmica\nes más compleja. Para la PoC, aplicamos la inversa de la fórmula \nlogarítmica simplificada que nos dio los resultados válidos:", "kind": "method", "line": 67, "name": "reverse_map_gain", "signature": "def reverse_map_gain(encoded_value, param)"}, {"doc": "Simula VSL_Decode_Frequency. Convierte un entero a frecuencia (Hz).\n\nFórmula inversa: exp2f(log2_min + pos * (log2_max - log2_min))", "kind": "method", "line": 95, "name": "reverse_map_frequency", "signature": "def reverse_map_frequency(encoded_value, param)"}, {"doc": "Dirige la decodificación al motor DSP correcto.", "kind": "method", "line": 115, "name": "get_decoded_value", "signature": "def get_decoded_value(encoded_value, param_id)"}, {"doc": "Decodifica el payload de 64 bytes. (Regla #3: Seguridad)", "kind": "method", "line": 140, "name": "decode_vsl_packet", "signature": "def decode_vsl_packet(data)"}, {"doc": "Carga un archivo PCAP y filtra los paquetes USB VSL.", "kind": "method", "line": 173, "name": "analyze_pcap", "signature": "def analyze_pcap(pcap_file)"}, {"kind": "method", "line": 30, "name": "__init__", "signature": "def __init__(self, dsp_id, name, type_unit, min_map, max_map, coeff_A, coeff_C1, log_factor)"}]}, {"id": "legacy/vsl_transport.py", "kind": "module", "label": "vsl_transport.py", "language": "py", "sha256": "df5d1b7a52953df7", "symbol_count": 8, "symbols": [{"doc": "Representa un paquete HID VSL-DSP de 64 bytes.\nImplementa construcción y validación con seguridad de tipos.", "kind": "class", "line": 15, "name": "VSLPacket", "signature": "class VSLPacket"}, {"doc": "Construye un paquete con manejo de errores.\n\nArgs:\n    param: Parámetro DSP\n    encoded_value: Valor codificado (0-65535)\n    \nReturns:\n    VSLPacket o None si hay error", "kind": "method", "line": 141, "name": "build_packet_safe", "signature": "def build_packet_safe(param, encoded_value)"}, {"doc": "Construye un paquete VSL-DSP.\n\nArgs:\n    param_id: ID del parámetro DSP (16-bit, ej: 0x1A01)\n    encoded_value: Valor codificado (16-bit, 0-65535)\n    report_id: Report ID HID (8-bit, None usa configuración global)\n    \nRaises:\n    ValueError: Si los valores están fuera de rango\n    RuntimeError: Si VSL_REPORT_ID no está configurado y report_id es None", "kind": "method", "line": 21, "name": "__init__", "signature": "def __init__(self, param_id, encoded_value, report_id)"}, {"doc": "Construye el buffer de 64 bytes según el protocolo VSL-DSP.\n\nEstructura (Little-Endian):\n  [0]    : Report ID\n  [1-2]  : Parameter ID (LSB, MSB)\n  [3-4]  : Encoded Value (LSB, MSB)\n  [5-63] : Padding (0x00)\n\nReturns:\n    bytearray de 64 bytes", "kind": "method", "line": 58, "name": "_build_buffer", "signature": "def _build_buffer(self)"}, {"doc": "Retorna el buffer como bytes inmutables.", "kind": "method", "line": 89, "name": "buffer", "signature": "def buffer(self)"}, {"doc": "Genera un hex dump del paquete para debugging.\n\nArgs:\n    num_bytes: Número de bytes a mostrar (default: 8)\n    \nReturns:\n    String con formato hexadecimal", "kind": "method", "line": 93, "name": "hex_dump", "signature": "def hex_dump(self, num_bytes)"}, {"doc": "Valida la integridad del paquete.\n\nReturns:\n    (is_valid, message)", "kind": "method", "line": 106, "name": "validate", "signature": "def validate(self)"}, {"kind": "method", "line": 133, "name": "__repr__", "signature": "def __repr__(self)"}]}, {"doc": "include <stdio.h> include <stdlib.h> include <string.h> include <math.h> include <stdint.h> include \"vsl_dsp_logic.h\" include \"vsl_dsp_transport.h\" include \"vsl_config.h\"", "id": "src/vsl_cli.c", "kind": "module", "label": "vsl_cli.c", "language": "c", "sha256": "fa51dde3473d2fb6", "symbol_count": 14, "symbols": [{"kind": "struct", "line": 15, "name": "ParamEntry"}, {"kind": "function", "line": 57, "name": "print_usage", "signature": "static void print_usage(FILE *fp, const char *prog)"}, {"kind": "function", "line": 83, "name": "print_version", "signature": "static void print_version(void)"}, {"kind": "function", "line": 90, "name": "print_list", "signature": "static void print_list(uint16_t product_id)"}, {"kind": "function", "line": 109, "name": "lookup_coeffs_by_param_id", "signature": "static const VSL_Parameter *\nlookup_coeffs_by_param_id(uint16_t param_id)"}, {"kind": "function", "line": 119, "name": "find_entry_by_name", "signature": "static const ParamEntry *\nfind_entry_by_name(const char *name)"}, {"kind": "function", "line": 129, "name": "do_send", "signature": "static int do_send(uint16_t product_id,\n                   uint16_t param_id,\n                   ..."}, {"kind": "function", "line": 167, "name": "do_send_freq", "signature": "static int do_send_freq(uint16_t product_id,\n                        uint16_t param_id,\n         ..."}, {"kind": "function", "line": 204, "name": "main", "signature": "int main(int argc, char *argv[])"}, {"kind": "function", "line": 60, "name": "fprintf", "signature": "fprintf(fp, \"Usage: %s [OPTIONS] COMMAND [ARGS...]\\n\" \"\\n\" \"Options:\\n\" \" -p, --pid <hex> USB product ID (default: 0x0101 = 22 VSL)\\n\" \" -m, --model <tag> Model tag: 22vsl, 44vsl, 1818vsl\\n\" \" -h, --h"}, {"kind": "function", "line": 86, "name": "printf", "signature": "printf(\"vsl-cli 2.0.0\\n\" \"PreSonus AudioBox VSL DSP control tool\\n\" \"License: AGPL-3.0-or-later\\n\");"}, {"kind": "function", "line": 163, "name": "VSL_Close_Device", "signature": "VSL_Close_Device(dev);"}, {"kind": "function", "line": 186, "name": "fmaxf", "signature": "fmaxf(0.0f, fminf(freq_hz / coeffs->freq_max_hz, 1.0f)), coeffs);"}, {"kind": "macro", "line": 47, "name": "MAX_CHANNELS", "signature": "#define MAX_CHANNELS"}]}, {"doc": "ifndef VSL_CONFIG_H define VSL_CONFIG_H  include <stdint.h> include <stddef.h>  ifdef __cplusplus", "id": "src/vsl_config.h", "kind": "module", "label": "vsl_config.h", "language": "h", "sha256": "40c921fe6426d537", "symbol_count": 13, "symbols": [{"kind": "struct", "line": 21, "name": "VSL_ModelInfo"}, {"kind": "function", "line": 35, "name": "VSL_ModelLookup", "signature": "static inline const VSL_ModelInfo *\nVSL_ModelLookup(uint16_t pid)"}, {"kind": "function", "line": 47, "name": "VSL_ModelLookupByTag", "signature": "static inline const VSL_ModelInfo *\nVSL_ModelLookupByTag(const char *tag)"}, {"doc": "ifdef __cplusplus", "kind": "variable", "line": 8, "name": "pid", "signature": "extern \"C\" { #endif #define VSL_VENDOR_ID 0x194fU #define VSL_PRODUCT_ID_22VSL 0x0101U #define VSL_PRODUCT_ID_44VSL 0x0102U #define VSL_PRODUCT_ID_1818VSL 0x0103U #define VSL_REPORT_ID 0x06U #define V"}, {"kind": "macro", "line": 2, "name": "VSL_CONFIG_H", "signature": "#define VSL_CONFIG_H"}, {"kind": "macro", "line": 10, "name": "VSL_VENDOR_ID", "signature": "#define VSL_VENDOR_ID"}, {"kind": "macro", "line": 12, "name": "VSL_PRODUCT_ID_22VSL", "signature": "#define VSL_PRODUCT_ID_22VSL"}, {"kind": "macro", "line": 13, "name": "VSL_PRODUCT_ID_44VSL", "signature": "#define VSL_PRODUCT_ID_44VSL"}, {"kind": "macro", "line": 14, "name": "VSL_PRODUCT_ID_1818VSL", "signature": "#define VSL_PRODUCT_ID_1818VSL"}, {"kind": "macro", "line": 15, "name": "VSL_REPORT_ID", "signature": "#define VSL_REPORT_ID"}, {"kind": "macro", "line": 17, "name": "VSL_PACKET_SIZE", "signature": "#define VSL_PACKET_SIZE"}, {"kind": "macro", "line": 18, "name": "VSL_MIDI_IFACE", "signature": "#define VSL_MIDI_IFACE"}, {"kind": "macro", "line": 19, "name": "VSL_EP_MIDI_OUT", "signature": "#define VSL_EP_MIDI_OUT"}]}, {"doc": "include \"vsl_dsp_logic.h\"", "id": "src/vsl_dsp_logic.c", "kind": "module", "label": "vsl_dsp_logic.c", "language": "c", "sha256": "241642e165780062", "symbol_count": 7, "symbols": [{"doc": "include \"vsl_dsp_logic.h\"", "kind": "function", "line": 2, "name": "VSL_Encode_Gain", "signature": "float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)"}, {"kind": "function", "line": 15, "name": "VSL_Decode_Gain", "signature": "float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param)"}, {"kind": "function", "line": 49, "name": "VSL_Map_Frequency", "signature": "float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)"}, {"kind": "function", "line": 65, "name": "VSL_Final_Encode_To_Int", "signature": "uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)"}, {"kind": "function", "line": 75, "name": "VSL_Decode_Frequency", "signature": "float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)"}, {"kind": "function", "line": 20, "name": "fmaxf", "signature": "return fmaxf(0.0f, fminf(r, 1.0f));"}, {"kind": "function", "line": 62, "name": "exp2f", "signature": "return exp2f(log2_value);"}]}, {"doc": "ifndef VSL_DSP_LOGIC_H define VSL_DSP_LOGIC_H  include <stdint.h> include <math.h> include <float.h>  define VSL_INV_LN2            1.442695f define VSL_MAX_ENCODED_FLOAT  1000.0f", "id": "src/vsl_dsp_logic.h", "kind": "module", "label": "vsl_dsp_logic.h", "language": "h", "sha256": "22c426b1274513e2", "symbol_count": 9, "symbols": [{"kind": "struct", "line": 11, "name": "VSL_Parameter"}, {"doc": "@brief Encodes a linear gain value [0.0, 1.0] to the DSP exponential curve. @param linear_value Linear control position clamped to [0,1]. @param param Parameter coefficients from the DSP parameter database. @return Encoded float value ready for integer conversion. @source Reverse-engineered from FUN_00132c90 in the Android driver.", "kind": "function", "line": 33, "name": "VSL_Encode_Gain", "signature": "float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);"}, {"doc": "@brief Decodes an encoded gain float back to a linear position [0.0, 1.0]. @param encoded_float Value received from the DSP or produced by VSL_Encode_Gain. @param param Same coefficients used during encoding. @return Linear control position clamped to [0,1]. @source Inverse of VSL_Encode_Gain (FUN_00132c90).", "kind": "function", "line": 42, "name": "VSL_Decode_Gain", "signature": "float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param);"}, {"doc": "@brief Maps a linear position [0.0, 1.0] to a logarithmic frequency (Hz). @param linear_position Linear control position clamped to [0,1]. @param param Parameter with freq_min_hz and freq_max_hz. @return Frequency in Hz. @source Reverse-engineered from FUN_00132d00 in the Android driver.", "kind": "function", "line": 51, "name": "VSL_Map_Frequency", "signature": "float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);"}, {"doc": "@brief Decodes a frequency (Hz) from the DSP to a linear position [0.0, 1.0]. @param freq_hz_value Frequency in Hz read from the DSP, clamped to range. @param param Parameter with freq_min_hz and freq_max_hz. @return Linear control position [0,1]. @source Reverse-engineered from FUN_00132da8 in the Android driver.", "kind": "function", "line": 60, "name": "VSL_Decode_Frequency", "signature": "float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);"}, {"doc": "@brief Converts an encoded float to a 16-bit integer for the DSP firmware. @param encoded_float Value from VSL_Encode_Gain or VSL_Map_Frequency. @param param Parameter with max_encoded_int (typically 65535). @return Integer value clamped to [0, max_encoded_int] ready for the USB packet. @note The scale factor VSL_MAX_ENCODED_FLOAT (1000.0f) is a hypothesis from the DSP scaling. Validated test: 0.75 -> 40793 (full pipeline).", "kind": "function", "line": 70, "name": "VSL_Final_Encode_To_Int", "signature": "uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param);"}, {"kind": "macro", "line": 2, "name": "VSL_DSP_LOGIC_H", "signature": "#define VSL_DSP_LOGIC_H"}, {"kind": "macro", "line": 7, "name": "VSL_INV_LN2", "signature": "#define VSL_INV_LN2"}, {"kind": "macro", "line": 9, "name": "VSL_MAX_ENCODED_FLOAT", "signature": "#define VSL_MAX_ENCODED_FLOAT"}]}, {"doc": "include \"vsl_dsp_transport.h\" include <stdio.h> include <stdlib.h> include <string.h> include <libusb-1.0/libusb.h>", "id": "src/vsl_dsp_transport.c", "kind": "module", "label": "vsl_dsp_transport.c", "language": "c", "sha256": "8bb2ad9e937c25c7", "symbol_count": 14, "symbols": [{"kind": "struct", "line": 7, "name": "vsl_device"}, {"kind": "function", "line": 12, "name": "VSL_Init_Device", "signature": "vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)"}, {"kind": "function", "line": 44, "name": "VSL_Close_Device", "signature": "void VSL_Close_Device(vsl_device_handle handle)"}, {"kind": "function", "line": 60, "name": "VSL_Send_Parameter", "signature": "int VSL_Send_Parameter(vsl_device_handle handle,\n                       uint16_t dsp_param_id,\n  ..."}, {"kind": "function", "line": 21, "name": "free", "signature": "free(dev);"}, {"kind": "function", "line": 27, "name": "libusb_exit", "signature": "libusb_exit(NULL);"}, {"kind": "function", "line": 34, "name": "libusb_set_auto_detach_kernel_driver", "signature": "libusb_set_auto_detach_kernel_driver(dev->handle, 1);"}, {"kind": "function", "line": 38, "name": "libusb_detach_kernel_driver", "signature": "libusb_detach_kernel_driver(dev->handle, VSL_MIDI_IFACE);"}, {"kind": "function", "line": 40, "name": "libusb_claim_interface", "signature": "libusb_claim_interface(dev->handle, VSL_MIDI_IFACE);"}, {"kind": "function", "line": 53, "name": "libusb_release_interface", "signature": "libusb_release_interface(dev->handle, VSL_MIDI_IFACE);"}, {"kind": "function", "line": 54, "name": "libusb_attach_kernel_driver", "signature": "libusb_attach_kernel_driver(dev->handle, VSL_MIDI_IFACE);"}, {"kind": "function", "line": 55, "name": "libusb_close", "signature": "libusb_close(dev->handle);"}, {"kind": "function", "line": 72, "name": "memset", "signature": "memset(buf, 0, sizeof(buf));"}, {"kind": "function", "line": 83, "name": "fprintf", "signature": "fprintf(stderr, \"VSL_Send_Parameter: bulk write failed: %s\\n\", libusb_error_name(ret));"}]}, {"doc": "ifndef VSL_DSP_TRANSPORT_H define VSL_DSP_TRANSPORT_H  include <stdint.h> include \"vsl_dsp_logic.h\" include \"vsl_config.h\"  ifdef __cplusplus", "id": "src/vsl_dsp_transport.h", "kind": "module", "label": "vsl_dsp_transport.h", "language": "h", "sha256": "d25755488640b4f0", "symbol_count": 6, "symbols": [{"doc": "endif", "kind": "type_alias", "line": 11, "name": "vsl_device_handle", "signature": "typedef void* vsl_device_handle;"}, {"doc": "@brief Open a VSL device by USB VID/PID and claim the MIDI control interface. @param vendor_id USB vendor ID (typically VSL_VENDOR_ID). @param product_id USB product ID for the specific VSL model. @return Opaque handle on success, NULL on failure.", "kind": "function", "line": 20, "name": "VSL_Init_Device", "signature": "vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id);"}, {"doc": "@brief Release the MIDI interface and close the device. @param handle Handle from VSL_Init_Device. NULL is a safe no-op.", "kind": "function", "line": 26, "name": "VSL_Close_Device", "signature": "void VSL_Close_Device(vsl_device_handle handle);"}, {"doc": "@brief Send a DSP parameter value to the device via USB bulk transfer. @param handle Handle from VSL_Init_Device. @param dsp_param_id 16-bit DSP parameter identifier. @param encoded_value 16-bit encoded integer value. @return 0 on success, negative on error.", "kind": "function", "line": 35, "name": "VSL_Send_Parameter", "signature": "int VSL_Send_Parameter(vsl_device_handle handle, uint16_t dsp_param_id, uint16_t encoded_value);"}, {"doc": "ifdef __cplusplus", "kind": "variable", "line": 9, "name": "vsl_device_handle", "signature": "extern \"C\" { #endif typedef void* vsl_device_handle;"}, {"kind": "macro", "line": 2, "name": "VSL_DSP_TRANSPORT_H", "signature": "#define VSL_DSP_TRANSPORT_H"}]}, {"doc": "SPDX-License-Identifier: GPL-2.0-or-later", "id": "tests/test_audiobox_vsl.c", "kind": "module", "label": "test_audiobox_vsl.c", "language": "c", "sha256": "e79e578712001b98", "symbol_count": 17, "symbols": [{"kind": "function", "line": 30, "name": "test_supported_models_table_shape", "signature": "static void test_supported_models_table_shape(void **state)"}, {"kind": "function", "line": 45, "name": "test_model_pids_match_table", "signature": "static void test_model_pids_match_table(void **state)"}, {"kind": "function", "line": 54, "name": "test_lookup_returns_22_vsl", "signature": "static void test_lookup_returns_22_vsl(void **state)"}, {"kind": "function", "line": 64, "name": "test_lookup_returns_44_vsl", "signature": "static void test_lookup_returns_44_vsl(void **state)"}, {"kind": "function", "line": 74, "name": "test_lookup_returns_1818_vsl", "signature": "static void test_lookup_returns_1818_vsl(void **state)"}, {"kind": "function", "line": 84, "name": "test_lookup_returns_null_for_unknown_pid", "signature": "static void test_lookup_returns_null_for_unknown_pid(void **state)"}, {"kind": "function", "line": 94, "name": "test_lookup_handles_full_pid_range", "signature": "static void test_lookup_handles_full_pid_range(void **state)"}, {"kind": "function", "line": 114, "name": "test_table_pids_are_unique", "signature": "static void test_table_pids_are_unique(void **state)"}, {"kind": "function", "line": 125, "name": "test_table_product_names_non_empty", "signature": "static void test_table_product_names_non_empty(void **state)"}, {"kind": "function", "line": 135, "name": "main", "signature": "int main(void)"}, {"kind": "function", "line": 28, "name": "assert_int_equal", "signature": "assert_int_equal(AUDIOBOX_VENDOR_ID, 0x194fU);"}, {"kind": "function", "line": 39, "name": "assert_string_equal", "signature": "assert_string_equal(m[0].product_name, \"AudioBox 22 VSL\");"}, {"kind": "function", "line": 60, "name": "assert_non_null", "signature": "assert_non_null(m);"}, {"kind": "function", "line": 88, "name": "assert_null", "signature": "assert_null(audiobox_lookup_model(0x0000U));"}, {"kind": "function", "line": 121, "name": "assert_int_not_equal", "signature": "assert_int_not_equal(audiobox_models[i].pid, audiobox_models[j].pid);"}, {"kind": "function", "line": 132, "name": "assert_true", "signature": "assert_true(audiobox_models[i].product_name[0] != '\\0');"}, {"kind": "function", "line": 150, "name": "cmocka_run_group_tests", "signature": "return cmocka_run_group_tests(tests, NULL, NULL);"}]}, {"doc": "include <stdarg.h> include <stddef.h> include <setjmp.h> include <cmocka.h> include <math.h> include <float.h> include \"vsl_dsp_logic.h\"", "id": "tests/test_vsl_dsp_logic.c", "kind": "module", "label": "test_vsl_dsp_logic.c", "language": "c", "sha256": "837d878bf01a421a", "symbol_count": 19, "symbols": [{"doc": "include <stdarg.h> include <stddef.h> include <setjmp.h> include <cmocka.h> include <math.h> include <float.h> include \"vsl_dsp_logic.h\"", "kind": "function", "line": 8, "name": "test_VSL_Encode_Gain", "signature": "static void test_VSL_Encode_Gain(void **state)"}, {"kind": "function", "line": 35, "name": "test_VSL_Map_Frequency", "signature": "static void test_VSL_Map_Frequency(void **state)"}, {"kind": "function", "line": 67, "name": "test_VSL_Decode_Frequency", "signature": "static void test_VSL_Decode_Frequency(void **state)"}, {"kind": "function", "line": 99, "name": "test_VSL_Final_Encode_To_Int", "signature": "static void test_VSL_Final_Encode_To_Int(void **state)"}, {"kind": "function", "line": 127, "name": "test_VSL_Decode_Gain_c1_zero", "signature": "static void test_VSL_Decode_Gain_c1_zero(void **state)"}, {"kind": "function", "line": 145, "name": "test_VSL_Decode_Gain_log_factor_zero", "signature": "static void test_VSL_Decode_Gain_log_factor_zero(void **state)"}, {"kind": "function", "line": 163, "name": "test_VSL_Decode_Gain_encoded_below_offset", "signature": "static void test_VSL_Decode_Gain_encoded_below_offset(void **state)"}, {"kind": "function", "line": 182, "name": "test_VSL_Decode_Gain_range_zero", "signature": "static void test_VSL_Decode_Gain_range_zero(void **state)"}, {"kind": "function", "line": 200, "name": "test_VSL_Decode_Gain_roundtrip_mid", "signature": "static void test_VSL_Decode_Gain_roundtrip_mid(void **state)"}, {"kind": "function", "line": 220, "name": "test_VSL_Decode_Gain_roundtrip_extremes", "signature": "static void test_VSL_Decode_Gain_roundtrip_extremes(void **state)"}, {"kind": "function", "line": 241, "name": "test_VSL_Decode_Gain_roundtrip_75", "signature": "static void test_VSL_Decode_Gain_roundtrip_75(void **state)"}, {"kind": "function", "line": 261, "name": "test_VSL_Decode_Gain_custom_range_roundtrip", "signature": "static void test_VSL_Decode_Gain_custom_range_roundtrip(void **state)"}, {"kind": "function", "line": 289, "name": "test_VSL_Decode_Gain_encoded_equals_offset", "signature": "static void test_VSL_Decode_Gain_encoded_equals_offset(void **state)"}, {"kind": "function", "line": 308, "name": "test_VSL_Decode_Gain_clamps_output", "signature": "static void test_VSL_Decode_Gain_clamps_output(void **state)"}, {"kind": "function", "line": 328, "name": "main", "signature": "int main(void)"}, {"doc": "VSL_Parameter param = { .coeff_offset_A = 0.0f, .coeff_C1 = 1.0f, .log_factor = 1.0f, .curve_min_map = 0.0f, .curve_max_map = 1.0f, .freq_min_hz = 0.0f, /* unused .freq_max_hz = 0.0f, /* unused .dsp_param_id = 0,   /* unused .max_encoded_int = 0 /* unused }; /* Test clamping and basic computation", "kind": "function", "line": 25, "name": "assert_float_equal", "signature": "assert_float_equal(VSL_Encode_Gain(0.5f, &param), 1.6487212707f, 1e-5f);"}, {"doc": "VSL_Parameter param = { .coeff_offset_A = 0.0f, /* unused .coeff_C1 = 0.0f,     /* unused .log_factor = 0.0f,   /* unused .curve_min_map = 0.0f,/* unused .curve_max_map = 0.0f,/* unused .freq_min_hz = 0.0f,  /* unused .freq_max_hz = 0.0f,  /* unused .dsp_param_id = 0,    /* unused .max_encoded_int = 65535 /* max uint16 }; /* Test scaling: encoded_float = 0.75 -> 0.75 * 65535/1000 = 49.15125 -> round -> 49", "kind": "function", "line": 116, "name": "assert_int_equal", "signature": "assert_int_equal(VSL_Final_Encode_To_Int(0.75f, &param), 49);"}, {"kind": "function", "line": 325, "name": "assert_true", "signature": "assert_true(result >= 0.0f);"}, {"kind": "function", "line": 346, "name": "cmocka_run_group_tests", "signature": "return cmocka_run_group_tests(tests, NULL, NULL);"}]}, {"doc": "define _GNU_SOURCE  include \"vc_alsa.h\" include \"vc_stream.h\"  include <alloca.h> include <alsa/asoundlib.h> include <stdio.h> include <stdlib.h> include <string.h> include <math.h>", "id": "voicecloak/src/vc_alsa.c", "kind": "module", "label": "vc_alsa.c", "language": "c", "sha256": "f1f03b4b0bc88f16", "symbol_count": 24, "symbols": [{"kind": "struct", "line": 13, "name": "vc_pcm_t"}, {"kind": "function", "line": 19, "name": "fmt_bps", "signature": "static size_t fmt_bps(snd_pcm_format_t f)"}, {"kind": "function", "line": 28, "name": "open_stream", "signature": "static int open_stream(vc_pcm_t *s, const char *dev, snd_pcm_stream_t dir,\n                      ..."}, {"kind": "function", "line": 98, "name": "raw_to_mono", "signature": "static void raw_to_mono(const unsigned char *raw, float *mono,\n                        snd_pcm_uf..."}, {"kind": "function", "line": 129, "name": "mono_to_raw", "signature": "static void mono_to_raw(unsigned char *raw, const float *mono,\n                        snd_pcm_uf..."}, {"kind": "function", "line": 162, "name": "vc_alsa_list", "signature": "int vc_alsa_list(void)"}, {"kind": "function", "line": 188, "name": "vc_alsa_run", "signature": "int vc_alsa_run(const vc_alsa_cfg_t *cfg)"}, {"kind": "function", "line": 37, "name": "fprintf", "signature": "fprintf(stderr, \"vc_alsa: cannot open %s device '%s': %s\\n\", tag, dev, snd_strerror(err));"}, {"kind": "function", "line": 43, "name": "snd_pcm_hw_params_alloca", "signature": "snd_pcm_hw_params_alloca(&hw);"}, {"kind": "function", "line": 44, "name": "snd_pcm_hw_params_any", "signature": "snd_pcm_hw_params_any(s->pcm, hw);"}, {"kind": "function", "line": 85, "name": "snd_pcm_hw_params_set_buffer_size_near", "signature": "snd_pcm_hw_params_set_buffer_size_near(s->pcm, hw, &buffer);"}, {"kind": "function", "line": 108, "name": "memcpy", "signature": "memcpy(&x, base, sizeof(x));"}, {"kind": "function", "line": 169, "name": "printf", "signature": "printf(\"Available ALSA PCM devices:\\n\");"}, {"kind": "function", "line": 183, "name": "free", "signature": "free(name);"}, {"kind": "function", "line": 185, "name": "snd_device_name_free_hint", "signature": "snd_device_name_free_hint(hints);"}, {"kind": "function", "line": 211, "name": "snd_pcm_hw_params_current", "signature": "snd_pcm_hw_params_current(cap.pcm, hw);"}, {"kind": "function", "line": 212, "name": "snd_pcm_hw_params_get_rate", "signature": "snd_pcm_hw_params_get_rate(hw, &neg_rate, &dir);"}, {"kind": "function", "line": 231, "name": "snd_pcm_prepare", "signature": "snd_pcm_prepare(cap.pcm);"}, {"doc": "snd_pcm_uframes_t period = cfg->period_frames; raw_in   = (unsigned char *)malloc((size_t)period * cap.channels * cap.bps); raw_out  = (unsigned char *)malloc((size_t)period * play.channels * play.bps); mono_in  = (float *)malloc((size_t)period * sizeof(float)); mono_out = (float *)malloc((size_t)period * sizeof(float)); if (!raw_in || !raw_out || !mono_in || !mono_out) { fprintf(stderr, \"vc_alsa: out of memory\\n\"); goto done; } snd_pcm_prepare(cap.pcm); snd_pcm_prepare(play.pcm); /* Prime playback with one period of silence to build a buffer margin.", "kind": "function", "line": 236, "name": "memset", "signature": "memset(raw_out, 0, (size_t)period * play.channels * play.bps);"}, {"kind": "function", "line": 237, "name": "snd_pcm_writei", "signature": "snd_pcm_writei(play.pcm, raw_out, period);"}, {"kind": "function", "line": 238, "name": "snd_pcm_start", "signature": "snd_pcm_start(cap.pcm);"}, {"kind": "function", "line": 258, "name": "vc_stream_process", "signature": "vc_stream_process(st, mono_in, mono_out, (size_t)frames, cfg->fn, cfg->user);"}, {"kind": "function", "line": 286, "name": "vc_stream_destroy", "signature": "vc_stream_destroy(st);"}, {"kind": "macro", "line": 1, "name": "_GNU_SOURCE", "signature": "#define _GNU_SOURCE"}]}, {"doc": "ifndef VC_ALSA_H define VC_ALSA_H  include <stddef.h> include <stdint.h> include <signal.h> include \"vc_stream.h\"  ifdef __cplusplus", "id": "voicecloak/src/vc_alsa.h", "kind": "module", "label": "vc_alsa.h", "language": "h", "sha256": "067ae0b8898bc451", "symbol_count": 5, "symbols": [{"doc": "@brief Configuration for a real-time ALSA processing session.  The capture and playback device names are ALSA PCM names discovered at runtime (e.g. \"hw:VSL\", \"plughw:2,0\", \"default\"); nothing is hardcoded. Rate and channel count are requested but the negotiated values from the device win. The DSP engine is created internally with the negotiated rate; the transform callback and its context are supplied by the caller.", "kind": "struct", "line": 23, "name": "vc_alsa_cfg_t"}, {"kind": "function", "line": 15, "name": "runtime", "signature": "* * The capture and playback device names are ALSA PCM names discovered * at runtime (e.g. \"hw:VSL\", \"plughw:2,0\", \"default\");"}, {"doc": "@brief Print the available ALSA PCM devices to stdout. @return 0 on success, -1 on error.", "kind": "function", "line": 40, "name": "vc_alsa_list", "signature": "int vc_alsa_list(void);"}, {"doc": "@brief Open capture and playback, run the processing loop until *cfg->stop becomes non-zero or a fatal error occurs. @return 0 on clean stop, -1 on error.", "kind": "function", "line": 47, "name": "vc_alsa_run", "signature": "int vc_alsa_run(const vc_alsa_cfg_t *cfg);"}, {"kind": "macro", "line": 2, "name": "VC_ALSA_H", "signature": "#define VC_ALSA_H"}]}, {"doc": "include \"vc_wav.h\" include \"vc_dsp.h\" include \"vc_crypto.h\" include <stdio.h> include <stdlib.h> include <string.h> include <time.h>", "id": "voicecloak/src/vc_cli.c", "kind": "module", "label": "vc_cli.c", "language": "c", "sha256": "8b56f438edf73c45", "symbol_count": 11, "symbols": [{"doc": "include \"vc_wav.h\" include \"vc_dsp.h\" include \"vc_crypto.h\" include <stdio.h> include <stdlib.h> include <string.h> include <time.h>", "kind": "function", "line": 8, "name": "print_usage", "signature": "static void print_usage(const char *prog)"}, {"kind": "function", "line": 40, "name": "cmd_keygen", "signature": "static int cmd_keygen(void)"}, {"kind": "function", "line": 52, "name": "cmd_cloak", "signature": "static int cmd_cloak(const char *pubkey_path,\n                     const char *in_path, const cha..."}, {"kind": "function", "line": 141, "name": "cmd_info", "signature": "static int cmd_info(const char *path)"}, {"kind": "function", "line": 176, "name": "main", "signature": "int main(int argc, char *argv[])"}, {"kind": "function", "line": 10, "name": "printf", "signature": "printf( \"VoiceCloak - cryptographically secure voice anonymizer\\n\" \"\\n\" \"Usage: %s <command> [options]\\n\" \"\\n\" \"Commands:\\n\" \" keygen Generate RSA-4096 keypair\\n\" \" cloak -k <pubkey> <in.wav> <out.wav"}, {"kind": "function", "line": 44, "name": "fprintf", "signature": "fprintf(stderr, \"Error: key generation failed.\\n\");"}, {"kind": "function", "line": 74, "name": "free", "signature": "free(samples);"}, {"kind": "function", "line": 76, "name": "fclose", "signature": "fclose(ur);"}, {"kind": "function", "line": 93, "name": "snprintf", "signature": "snprintf(sidecar_path, sizeof(sidecar_path), \"%s.vc\", out_path);"}, {"kind": "function", "line": 99, "name": "fwrite", "signature": "fwrite(enc_seed, 1, enc_len, sf);"}]}, {"doc": "include \"vc_crypto.h\" include <stdio.h> include <stdlib.h> include <string.h> include <openssl/evp.h> include <openssl/pem.h> include <openssl/rsa.h> include <openssl/rand.h> include <openssl/err.h> include <openssl/hmac.h>", "id": "voicecloak/src/vc_crypto.c", "kind": "module", "label": "vc_crypto.c", "language": "c", "sha256": "4251a30b17074023", "symbol_count": 18, "symbols": [{"doc": "int i; for (i = 0; i < 3; ++i) { unsigned int outlen = 32; unsigned char data[64]; size_t data_len = info_lens[i] + 1; memcpy(data, infos[i], info_lens[i]); data[info_lens[i]] = (unsigned char)0x01; if (!HMAC(EVP_sha256(), prk, 32, data, data_len, outputs[i], &outlen)) return -1; } return 0; } /* PRNG: AES-256-CTR using OpenSSL EVP", "kind": "struct", "line": 136, "name": "vc_prng_s"}, {"doc": "include \"vc_crypto.h\" include <stdio.h> include <stdlib.h> include <string.h> include <openssl/evp.h> include <openssl/pem.h> include <openssl/rsa.h> include <openssl/rand.h> include <openssl/err.h> include <openssl/hmac.h>", "kind": "function", "line": 11, "name": "openssl_init", "signature": "static void openssl_init(void)"}, {"kind": "function", "line": 16, "name": "vc_crypto_keygen", "signature": "int vc_crypto_keygen(const char *pubkey_path, const char *privkey_path)"}, {"kind": "function", "line": 46, "name": "vc_crypto_seal", "signature": "int vc_crypto_seal(const char *pubkey_path,\n                   const unsigned char *seed, size_t ..."}, {"kind": "function", "line": 70, "name": "vc_crypto_unseal", "signature": "int vc_crypto_unseal(const char *privkey_path,\n                     const unsigned char *enc, siz..."}, {"kind": "function", "line": 95, "name": "vc_crypto_derive_seeds", "signature": "int vc_crypto_derive_seeds(const unsigned char *master_seed, size_t seed_len,\n                   ..."}, {"kind": "function", "line": 142, "name": "vc_prng_create", "signature": "vc_prng_t *vc_prng_create(const unsigned char *seed)"}, {"kind": "function", "line": 156, "name": "vc_prng_destroy", "signature": "void vc_prng_destroy(vc_prng_t *p)"}, {"kind": "function", "line": 163, "name": "vc_prng_fill", "signature": "void vc_prng_fill(vc_prng_t *p, unsigned char *buf, size_t len)"}, {"kind": "function", "line": 183, "name": "vc_prng_float", "signature": "float vc_prng_float(vc_prng_t *p, float low, float high)"}, {"kind": "function", "line": 56, "name": "fclose", "signature": "fclose(fp);"}, {"kind": "function", "line": 63, "name": "EVP_PKEY_free", "signature": "EVP_PKEY_free(pkey);"}, {"kind": "function", "line": 67, "name": "EVP_PKEY_CTX_free", "signature": "EVP_PKEY_CTX_free(ctx);"}, {"kind": "function", "line": 127, "name": "memcpy", "signature": "memcpy(data, infos[i], info_lens[i]);"}, {"kind": "function", "line": 150, "name": "memset", "signature": "memset(p->counter, 0, sizeof(p->counter));"}, {"kind": "function", "line": 152, "name": "EVP_EncryptInit_ex", "signature": "EVP_EncryptInit_ex(p->ctx, EVP_aes_256_ctr(), NULL, seed, p->counter);"}, {"kind": "function", "line": 161, "name": "free", "signature": "free(p);"}, {"kind": "function", "line": 171, "name": "EVP_EncryptUpdate", "signature": "EVP_EncryptUpdate(p->ctx, p->keystream, &outlen, p->keystream, (int)sizeof(p->keystream));"}]}, {"doc": "ifndef VC_CRYPTO_H define VC_CRYPTO_H  include <stddef.h> include <stdint.h>  ifdef __cplusplus", "id": "voicecloak/src/vc_crypto.h", "kind": "module", "label": "vc_crypto.h", "language": "h", "sha256": "141226b9365f5a21", "symbol_count": 16, "symbols": [{"doc": "@brief Deterministic PRNG seeded from crypto key material.  Internally uses AES-256-CTR with the given seed as key and a zero IV. Produces the same stream for the same seed every time.", "kind": "type_alias", "line": 72, "name": "vc_prng_t", "signature": "typedef struct vc_prng_s vc_prng_t;"}, {"doc": "@brief Generate an RSA-4096 keypair and write to PEM files. @param pubkey_path   Output path for public key. @param privkey_path  Output path for private key. @return 0 on success, -1 on error.", "kind": "function", "line": 24, "name": "vc_crypto_keygen", "signature": "int vc_crypto_keygen(const char *pubkey_path, const char *privkey_path);"}, {"doc": "@brief Encrypt a symmetric session seed using RSA-4096 public key. @param pubkey_path   Path to PEM public key. @param seed          [in] 96-byte seed (pitch+formant+spectral). @param seed_len      Must be VC_TOTAL_SEED_BYTES (96). @param enc_out       [out] Buffer for RSA ciphertext (512 bytes). @param enc_len       [out] Length of ciphertext. @return 0 on success, -1 on error.", "kind": "function", "line": 35, "name": "vc_crypto_seal", "signature": "int vc_crypto_seal(const char *pubkey_path, const unsigned char *seed, size_t seed_len, unsigned char *enc_out, size_t *enc_len);"}, {"doc": "@brief Decrypt the session seed using RSA-4096 private key. @param privkey_path  Path to PEM private key. @param enc           [in]  RSA ciphertext. @param enc_len       Length of ciphertext. @param seed          [out] 96-byte recovered seed. @param seed_len      Must be VC_TOTAL_SEED_BYTES. @return 0 on success, -1 on error.", "kind": "function", "line": 48, "name": "vc_crypto_unseal", "signature": "int vc_crypto_unseal(const char *privkey_path, const unsigned char *enc, size_t enc_len, unsigned char *seed, size_t seed_len);"}, {"doc": "@brief Derive sub-seeds from a master seed via HKDF-SHA256. @param master_seed   96-byte master seed. @param seed_len      VC_TOTAL_SEED_BYTES. @param pitch_seed    [out] 32-byte pitch PRNG seed. @param formant_seed  [out] 32-byte formant PRNG seed. @param spectral_seed [out] 32-byte spectral PRNG seed. @return 0 on success, -1 on error.", "kind": "function", "line": 61, "name": "vc_crypto_derive_seeds", "signature": "int vc_crypto_derive_seeds(const unsigned char *master_seed, size_t seed_len, unsigned char *pitch_seed, unsigned char *formant_seed, unsigned char *spectral_seed);"}, {"doc": "@brief Create a PRNG from a 32-byte seed.", "kind": "function", "line": 77, "name": "vc_prng_create", "signature": "vc_prng_t *vc_prng_create(const unsigned char *seed);"}, {"doc": "@brief Release PRNG.", "kind": "function", "line": 82, "name": "vc_prng_destroy", "signature": "void vc_prng_destroy(vc_prng_t *p);"}, {"doc": "@brief Fill buffer with deterministic pseudo-random bytes.", "kind": "function", "line": 87, "name": "vc_prng_fill", "signature": "void vc_prng_fill(vc_prng_t *p, unsigned char *buf, size_t len);"}, {"doc": "@brief Generate a float in [low, high] deterministically.", "kind": "function", "line": 92, "name": "vc_prng_float", "signature": "float vc_prng_float(vc_prng_t *p, float low, float high);"}, {"kind": "macro", "line": 2, "name": "VC_CRYPTO_H", "signature": "#define VC_CRYPTO_H"}, {"kind": "macro", "line": 10, "name": "VC_CRYPTO_SEED_BYTES", "signature": "#define VC_CRYPTO_SEED_BYTES"}, {"kind": "macro", "line": 12, "name": "VC_CRYPTO_KEY_BYTES", "signature": "#define VC_CRYPTO_KEY_BYTES"}, {"kind": "macro", "line": 13, "name": "VC_PITCH_SEED_BYTES", "signature": "#define VC_PITCH_SEED_BYTES"}, {"kind": "macro", "line": 14, "name": "VC_FORMANT_SEED_BYTES", "signature": "#define VC_FORMANT_SEED_BYTES"}, {"kind": "macro", "line": 15, "name": "VC_SPECTRAL_SEED_BYTES", "signature": "#define VC_SPECTRAL_SEED_BYTES"}, {"kind": "macro", "line": 16, "name": "VC_TOTAL_SEED_BYTES", "signature": "#define VC_TOTAL_SEED_BYTES"}]}, {"doc": "include \"vc_dsp.h\" include \"vc_stft.h\" include \"vc_crypto.h\" include <stdlib.h> include <string.h> include <math.h> include <float.h>  define VC_FFT_SIZE 2048U define VC_HOP_SIZE  (VC_FFT_SIZE / 4)", "id": "voicecloak/src/vc_dsp.c", "kind": "module", "label": "vc_dsp.c", "language": "c", "sha256": "f60c9fddd788dec4", "symbol_count": 16, "symbols": [{"doc": "define VC_FFT_SIZE 2048U define VC_HOP_SIZE  (VC_FFT_SIZE / 4)", "kind": "function", "line": 11, "name": "stft_process", "signature": "static int stft_process(const float *samples, size_t num_samples,\n                        float *..."}, {"kind": "function", "line": 20, "name": "stft_reconstruct", "signature": "static int stft_reconstruct(const float *mag, const float *phase,\n                            siz..."}, {"kind": "function", "line": 30, "name": "compute_out_len", "signature": "static size_t compute_out_len(size_t nframes, size_t hop)"}, {"kind": "function", "line": 34, "name": "vc_dsp_pitch_shift", "signature": "int vc_dsp_pitch_shift(const float *samples, size_t num_samples,\n                       uint32_t ..."}, {"kind": "function", "line": 90, "name": "vc_dsp_formant_shift", "signature": "int vc_dsp_formant_shift(const float *samples, size_t num_samples,\n                         uint3..."}, {"kind": "function", "line": 160, "name": "vc_dsp_spectral_scramble", "signature": "int vc_dsp_spectral_scramble(const float *samples, size_t num_samples,\n                          ..."}, {"kind": "function", "line": 233, "name": "trim_edges", "signature": "static void trim_edges(float **buf, size_t *len)"}, {"kind": "function", "line": 254, "name": "normalize_rms", "signature": "static void normalize_rms(const float *in, size_t in_len,\n                          float *out, s..."}, {"kind": "function", "line": 271, "name": "vc_dsp_cloak", "signature": "int vc_dsp_cloak(const float *samples, size_t num_samples,\n                 uint32_t sample_rate,..."}, {"kind": "function", "line": 17, "name": "vc_stft_destroy", "signature": "vc_stft_destroy(st);"}, {"kind": "function", "line": 54, "name": "memcpy", "signature": "memcpy(synth_phase, phase, nbins * sizeof(float));"}, {"kind": "function", "line": 74, "name": "free", "signature": "free(synth_phase);"}, {"kind": "function", "line": 113, "name": "memset", "signature": "memset(dst, 0, nbins * sizeof(float));"}, {"kind": "function", "line": 285, "name": "vc_prng_destroy", "signature": "vc_prng_destroy(pp);"}, {"kind": "macro", "line": 8, "name": "VC_FFT_SIZE", "signature": "#define VC_FFT_SIZE"}, {"kind": "macro", "line": 10, "name": "VC_HOP_SIZE", "signature": "#define VC_HOP_SIZE"}]}, {"doc": "ifndef VC_DSP_H define VC_DSP_H  include <stddef.h> include <stdint.h>  ifdef __cplusplus", "id": "voicecloak/src/vc_dsp.h", "kind": "module", "label": "vc_dsp.h", "language": "h", "sha256": "81fcfdbd47541be3", "symbol_count": 6, "symbols": [{"kind": "function", "line": 15, "name": "vc_dsp_pitch_shift", "signature": "int vc_dsp_pitch_shift(const float *samples, size_t num_samples, uint32_t sample_rate, float semitones, float **out, size_t *out_len);"}, {"kind": "function", "line": 19, "name": "vc_dsp_formant_shift", "signature": "int vc_dsp_formant_shift(const float *samples, size_t num_samples, uint32_t sample_rate, float shift_factor, float **out, size_t *out_len);"}, {"kind": "function", "line": 23, "name": "vc_dsp_spectral_scramble", "signature": "int vc_dsp_spectral_scramble(const float *samples, size_t num_samples, uint32_t sample_rate, float intensity, float **out, size_t *out_len);"}, {"kind": "function", "line": 27, "name": "vc_dsp_cloak", "signature": "int vc_dsp_cloak(const float *samples, size_t num_samples, uint32_t sample_rate, const unsigned char *pitch_seed, const unsigned char *formant_seed, const unsigned char *spectral_seed, VcMode mode, fl"}, {"doc": "ifdef __cplusplus", "kind": "variable", "line": 8, "name": "VcMode", "signature": "extern \"C\" { #endif typedef enum { VC_MODE_SUBTLE = 0, VC_MODE_WITNESS = 1 } VcMode;"}, {"kind": "macro", "line": 2, "name": "VC_DSP_H", "signature": "#define VC_DSP_H"}]}, {"doc": "include \"vc_fft.h\" include <math.h> include <string.h> include <stdlib.h>  ifndef M_PI define M_PI 3.14159265358979323846f endif", "id": "voicecloak/src/vc_fft.c", "kind": "module", "label": "vc_fft.c", "language": "c", "sha256": "4727af7e9debbaa7", "symbol_count": 5, "symbols": [{"doc": "ifndef M_PI define M_PI 3.14159265358979323846f endif", "kind": "function", "line": 9, "name": "bit_reverse", "signature": "static unsigned int bit_reverse(unsigned int x, unsigned int bits)"}, {"kind": "function", "line": 19, "name": "bit_reverse_reorder", "signature": "static void bit_reverse_reorder(size_t n, float *real, float *imag)"}, {"kind": "function", "line": 35, "name": "vc_fft", "signature": "void vc_fft(size_t n, float *real, float *imag, int inverse)"}, {"kind": "function", "line": 73, "name": "free", "signature": "free(work_r);"}, {"kind": "macro", "line": 7, "name": "M_PI", "signature": "#define M_PI"}]}, {"doc": "ifndef VC_FFT_H define VC_FFT_H  include <stddef.h>  ifdef __cplusplus", "id": "voicecloak/src/vc_fft.h", "kind": "module", "label": "vc_fft.h", "language": "h", "sha256": "fab6b3ac544dcd6a", "symbol_count": 2, "symbols": [{"kind": "function", "line": 18, "name": "FFT", "signature": "* FFT(IFFT(x)) == IFFT(FFT(x)) == x. */ void vc_fft(size_t n, float *real, float *imag, int inverse);"}, {"kind": "macro", "line": 2, "name": "VC_FFT_H", "signature": "#define VC_FFT_H"}]}, {"doc": "include \"vc_rt.h\" include <stdlib.h> include <string.h> include <math.h>  ifndef M_PI define M_PI 3.14159265358979323846 endif", "id": "voicecloak/src/vc_rt.c", "kind": "module", "label": "vc_rt.c", "language": "c", "sha256": "af0e9c65c5c417e4", "symbol_count": 12, "symbols": [{"kind": "struct", "line": 10, "name": "vc_rt_ctx_s"}, {"kind": "function", "line": 22, "name": "vc_rt_create", "signature": "vc_rt_ctx_t *vc_rt_create(size_t nbins, vc_rt_params_t params)"}, {"kind": "function", "line": 42, "name": "vc_rt_destroy", "signature": "void vc_rt_destroy(vc_rt_ctx_t *c)"}, {"kind": "function", "line": 53, "name": "vc_rt_reset", "signature": "void vc_rt_reset(vc_rt_ctx_t *c)"}, {"kind": "function", "line": 60, "name": "vc_rt_semitones_to_ratio", "signature": "float vc_rt_semitones_to_ratio(float semitones)"}, {"kind": "function", "line": 64, "name": "wrap_pi", "signature": "static double wrap_pi(double x)"}, {"kind": "function", "line": 70, "name": "formant_warp", "signature": "static void formant_warp(float *syn_mag, size_t nbins, float factor)"}, {"kind": "function", "line": 105, "name": "vc_rt_transform", "signature": "void vc_rt_transform(float *mag, float *phase, size_t nbins,\n                     uint32_t sample..."}, {"kind": "function", "line": 45, "name": "free", "signature": "free(c->prev_phase);"}, {"kind": "function", "line": 56, "name": "memset", "signature": "memset(c->prev_phase, 0, c->nbins * sizeof(double));"}, {"kind": "function", "line": 62, "name": "powf", "signature": "return powf(2.0f, semitones / 12.0f);"}, {"kind": "macro", "line": 7, "name": "M_PI", "signature": "#define M_PI"}]}, {"doc": "ifndef VC_RT_H define VC_RT_H  include <stddef.h> include <stdint.h>  ifdef __cplusplus", "id": "voicecloak/src/vc_rt.h", "kind": "module", "label": "vc_rt.h", "language": "h", "sha256": "ede36e40900387ee", "symbol_count": 10, "symbols": [{"doc": "@brief Real-time cloak parameters (already resolved to scalars).  pitch_ratio 1.0 = no shift; formant_factor 1.0 = no shift; scramble_intensity 0.0 = none.", "kind": "struct", "line": 17, "name": "vc_rt_params_t"}, {"doc": "@brief Phase-vocoder transform context (per-bin state across frames).", "kind": "type_alias", "line": 26, "name": "vc_rt_ctx_t", "signature": "typedef struct vc_rt_ctx_s vc_rt_ctx_t;"}, {"doc": "@brief Create a transform context sized for @p nbins frequency bins. @return Context or NULL on allocation failure / nbins < 2.", "kind": "function", "line": 32, "name": "vc_rt_create", "signature": "vc_rt_ctx_t *vc_rt_create(size_t nbins, vc_rt_params_t params);"}, {"doc": "@brief Create a transform context sized for @p nbins frequency bins. @return Context or NULL on allocation failure / nbins < 2.  vc_rt_ctx_t *vc_rt_create(size_t nbins, vc_rt_params_t params); /** @brief Release a transform context. NULL-safe.", "kind": "function", "line": 35, "name": "vc_rt_destroy", "signature": "void vc_rt_destroy(vc_rt_ctx_t *c);"}, {"doc": "@brief Create a transform context sized for @p nbins frequency bins. @return Context or NULL on allocation failure / nbins < 2.  vc_rt_ctx_t *vc_rt_create(size_t nbins, vc_rt_params_t params); /** @brief Release a transform context. NULL-safe. void vc_rt_destroy(vc_rt_ctx_t *c); /** @brief Reset cross-frame phase state (e.g. on stream restart).", "kind": "function", "line": 38, "name": "vc_rt_reset", "signature": "void vc_rt_reset(vc_rt_ctx_t *c);"}, {"doc": "@brief Per-frame transform, compatible with vc_spectral_fn. @param user Must be a vc_rt_ctx_t* created with matching nbins.  Applies frequency-domain pitch shift (constant rate), formant envelope scaling, and spectral scrambling, then rewrites mag/phase to the synthesis spectrum.", "kind": "function", "line": 48, "name": "vc_rt_transform", "signature": "void vc_rt_transform(float *mag, float *phase, size_t nbins, uint32_t sample_rate, size_t hop, void *user);"}, {"doc": "@brief Convert a semitone shift to a pitch ratio (2^(semitones/12)).", "kind": "function", "line": 54, "name": "vc_rt_semitones_to_ratio", "signature": "float vc_rt_semitones_to_ratio(float semitones);"}, {"doc": "@brief Derive cloak parameters from three 32-byte PRNG seeds. @param pitch_seed    32-byte seed. @param formant_seed  32-byte seed. @param spectral_seed 32-byte seed. @param witness_mode  Non-zero for the aggressive witness ranges. @param out           [out] resolved parameters. @return 0 on success, -1 on error. Ranges mirror vc_dsp_cloak.", "kind": "function", "line": 65, "name": "vc_rt_derive", "signature": "int vc_rt_derive(const unsigned char *pitch_seed, const unsigned char *formant_seed, const unsigned char *spectral_seed, int witness_mode, vc_rt_params_t *out);"}, {"doc": "ifdef __cplusplus", "kind": "variable", "line": 8, "name": "shift", "signature": "extern \"C\" { #endif /** * @brief Real-time cloak parameters (already resolved to scalars). * * pitch_ratio 1.0 = no shift;"}, {"kind": "macro", "line": 2, "name": "VC_RT_H", "signature": "#define VC_RT_H"}]}, {"doc": "define _POSIX_C_SOURCE 200809L  include \"vc_alsa.h\" include \"vc_stream.h\" include \"vc_rt.h\" include \"vc_fft.h\" include \"vc_crypto.h\"  include <stdio.h> include <stdlib.h> include <string.h> include <signal.h> include <math.h>  ifndef M_PI define M_PI 3.14159265358979323846 endif", "id": "voicecloak/src/vc_rt_cli.c", "kind": "module", "label": "vc_rt_cli.c", "language": "c", "sha256": "af98d3fb84efaefc", "symbol_count": 20, "symbols": [{"kind": "function", "line": 20, "name": "on_sigint", "signature": "static void on_sigint(int sig)"}, {"kind": "function", "line": 25, "name": "print_usage", "signature": "static void print_usage(const char *prog)"}, {"kind": "function", "line": 57, "name": "dominant_freq", "signature": "static float dominant_freq(const float *x, size_t n, unsigned int sr)"}, {"kind": "function", "line": 80, "name": "cmd_selftest", "signature": "static int cmd_selftest(void)"}, {"kind": "function", "line": 118, "name": "resolve_params", "signature": "static int resolve_params(int have_fixed, float semis, float formant,\n                          f..."}, {"kind": "function", "line": 141, "name": "cmd_live", "signature": "static int cmd_live(int argc, char *argv[])"}, {"kind": "function", "line": 222, "name": "main", "signature": "int main(int argc, char *argv[])"}, {"kind": "function", "line": 70, "name": "vc_fft", "signature": "vc_fft(nf, re, im, 0);"}, {"kind": "function", "line": 77, "name": "free", "signature": "free(re);"}, {"kind": "function", "line": 98, "name": "fprintf", "signature": "fprintf(stderr, \"selftest: setup failed\\n\");"}, {"kind": "function", "line": 99, "name": "vc_stream_destroy", "signature": "vc_stream_destroy(st);"}, {"kind": "function", "line": 102, "name": "vc_stream_process", "signature": "vc_stream_process(st, in, out, n, vc_rt_transform, ctx);"}, {"kind": "function", "line": 108, "name": "printf", "signature": "printf(\"selftest: input dominant = %.1f Hz (expected %.1f)\\n\", (double)got_in, (double)in_freq);"}, {"kind": "function", "line": 134, "name": "fclose", "signature": "fclose(ur);"}, {"kind": "function", "line": 139, "name": "vc_rt_derive", "signature": "return vc_rt_derive(ps, fs, ss, witness, p);"}, {"kind": "function", "line": 199, "name": "memset", "signature": "memset(&sa, 0, sizeof(sa));"}, {"kind": "function", "line": 201, "name": "sigaction", "signature": "sigaction(SIGINT, &sa, NULL);"}, {"kind": "function", "line": 218, "name": "vc_rt_destroy", "signature": "vc_rt_destroy(ctx);"}, {"kind": "macro", "line": 1, "name": "_POSIX_C_SOURCE", "signature": "#define _POSIX_C_SOURCE"}, {"kind": "macro", "line": 16, "name": "M_PI", "signature": "#define M_PI"}]}, {"doc": "include \"vc_rt.h\" include \"vc_crypto.h\" include <math.h>", "id": "voicecloak/src/vc_rt_seed.c", "kind": "module", "label": "vc_rt_seed.c", "language": "c", "sha256": "4c947948b8abb29f", "symbol_count": 2, "symbols": [{"doc": "include \"vc_rt.h\" include \"vc_crypto.h\" include <math.h>", "kind": "function", "line": 4, "name": "vc_rt_derive", "signature": "int vc_rt_derive(const unsigned char *pitch_seed,\n                 const unsigned char *formant_s..."}, {"kind": "function", "line": 15, "name": "vc_prng_destroy", "signature": "vc_prng_destroy(pp);"}]}, {"doc": "include \"vc_stft.h\" include \"vc_fft.h\" include <stdlib.h> include <string.h> include <math.h>  ifndef M_PI define M_PI 3.14159265358979323846f endif", "id": "voicecloak/src/vc_stft.c", "kind": "module", "label": "vc_stft.c", "language": "c", "sha256": "28b054e4e755c2be", "symbol_count": 11, "symbols": [{"kind": "struct", "line": 11, "name": "vc_stft_s"}, {"kind": "function", "line": 20, "name": "vc_stft_create", "signature": "vc_stft_t *vc_stft_create(size_t fft_size, size_t hop_size)"}, {"kind": "function", "line": 57, "name": "vc_stft_destroy", "signature": "void vc_stft_destroy(vc_stft_t *st)"}, {"kind": "function", "line": 66, "name": "vc_stft_num_bins", "signature": "size_t vc_stft_num_bins(const vc_stft_t *st)"}, {"kind": "function", "line": 70, "name": "vc_stft_forward", "signature": "int vc_stft_forward(vc_stft_t *st,\n                    const float *samples, size_t num_samples,\n..."}, {"kind": "function", "line": 118, "name": "vc_stft_inverse", "signature": "int vc_stft_inverse(vc_stft_t *st,\n                    const float *mag, const float *phase,\n    ..."}, {"kind": "function", "line": 126, "name": "vc_stft_inverse_hop", "signature": "int vc_stft_inverse_hop(vc_stft_t *st,\n                        const float *mag, const float *pha..."}, {"doc": "st->buf_r    = (float *)malloc(fft_size * sizeof(float)); st->buf_i    = (float *)malloc(fft_size * sizeof(float)); if (!st->window || !st->win_sq_sum || !st->buf_r || !st->buf_i) { vc_stft_destroy(st); return NULL; } size_t i; for (i = 0; i < fft_size; ++i) { st->window[i] = 0.5f * (1.0f - cosf(2.0f * (float)M_PI * (float)i / (float)(fft_size - 1))); } /* Compute overlap-add normalization for synthesis hop", "kind": "function", "line": 45, "name": "memset", "signature": "memset(st->win_sq_sum, 0, fft_size * sizeof(float));"}, {"kind": "function", "line": 60, "name": "free", "signature": "free(st->window);"}, {"kind": "function", "line": 101, "name": "vc_fft", "signature": "vc_fft(fft_n, st->buf_r, st->buf_i, 0);"}, {"kind": "macro", "line": 8, "name": "M_PI", "signature": "#define M_PI"}]}, {"doc": "ifndef VC_STFT_H define VC_STFT_H  include <stddef.h> include <stdint.h>  ifdef __cplusplus", "id": "voicecloak/src/vc_stft.h", "kind": "module", "label": "vc_stft.h", "language": "h", "sha256": "d2d6ea440b21e56e", "symbol_count": 9, "symbols": [{"doc": "@brief Short-Time Fourier Transform context.  Allocated via vc_stft_create(). Window size and hop size are fixed at creation time. Window size must be a power of 2.", "kind": "type_alias", "line": 17, "name": "vc_stft_t", "signature": "typedef struct vc_stft_s vc_stft_t;"}, {"doc": "@brief Allocate STFT context. @param fft_size  FFT size (power of 2, e.g. 2048). @param hop_size  Hop size in samples (e.g. fft_size / 4). @return Context pointer or NULL on failure.", "kind": "function", "line": 25, "name": "vc_stft_create", "signature": "vc_stft_t *vc_stft_create(size_t fft_size, size_t hop_size);"}, {"doc": "@brief Release STFT context.", "kind": "function", "line": 30, "name": "vc_stft_destroy", "signature": "void vc_stft_destroy(vc_stft_t *st);"}, {"doc": "@brief Forward STFT: decompose a mono float buffer into complex frames. @param st       STFT context. @param samples  Input float samples, length = num_samples. @param num_samples  Number of input samples. @param mag      Output: magnitude per bin per frame (row-major, num_frames * (fft_size/2+1)). @param phase    Output: phase per bin per frame (row-major, same layout as mag). @param num_frames_out  Output: number of frames produced. @return 0 on success, -1 on error.", "kind": "function", "line": 42, "name": "vc_stft_forward", "signature": "int vc_stft_forward(vc_stft_t *st, const float *samples, size_t num_samples, float **mag, float **phase, size_t *num_frames_out);"}, {"doc": "@brief Inverse STFT: reconstruct signal from modified magnitude/phase. @param st        STFT context. @param mag       Input magnitude (row-major, num_frames * nbins). @param phase     Input phase (row-major, same layout). @param num_frames Number of frames. @param samples_out  Output: reconstructed float samples (caller must pre-allocate). @param num_samples_out  Number of samples to reconstruct. @return 0 on success, -1 on error.", "kind": "function", "line": 57, "name": "vc_stft_inverse", "signature": "int vc_stft_inverse(vc_stft_t *st, const float *mag, const float *phase, size_t num_frames, float *samples_out, size_t num_samples_out);"}, {"doc": "@brief Inverse STFT with custom synthesis hop (for pitch shifting). @param synth_hop  Synthesis hop size in samples (may differ from analysis hop).", "kind": "function", "line": 66, "name": "vc_stft_inverse_hop", "signature": "int vc_stft_inverse_hop(vc_stft_t *st, const float *mag, const float *phase, size_t num_frames, float *samples_out, size_t num_samples_out, size_t synth_hop);"}, {"doc": "@brief Number of frequency bins (fft_size/2 + 1).", "kind": "function", "line": 75, "name": "vc_stft_num_bins", "signature": "size_t vc_stft_num_bins(const vc_stft_t *st);"}, {"doc": "ifdef __cplusplus", "kind": "variable", "line": 8, "name": "vc_stft_t", "signature": "extern \"C\" { #endif /** * @brief Short-Time Fourier Transform context. * * Allocated via vc_stft_create(). Window size and hop size are fixed * at creation time. Window size must be a power of 2. */ t"}, {"kind": "macro", "line": 2, "name": "VC_STFT_H", "signature": "#define VC_STFT_H"}]}, {"doc": "include \"vc_stream.h\" include \"vc_fft.h\" include <stdlib.h> include <string.h> include <math.h>  ifndef M_PI define M_PI 3.14159265358979323846 endif", "id": "voicecloak/src/vc_stream.c", "kind": "module", "label": "vc_stream.c", "language": "c", "sha256": "d9c02a4f5b7f585e", "symbol_count": 12, "symbols": [{"kind": "struct", "line": 11, "name": "vc_stream_s"}, {"kind": "function", "line": 30, "name": "is_pow2", "signature": "static int is_pow2(size_t v)"}, {"kind": "function", "line": 34, "name": "vc_stream_create", "signature": "vc_stream_t *vc_stream_create(size_t fft_size, size_t hop_size,\n                              uin..."}, {"kind": "function", "line": 93, "name": "vc_stream_destroy", "signature": "void vc_stream_destroy(vc_stream_t *st)"}, {"kind": "function", "line": 106, "name": "vc_stream_latency_samples", "signature": "size_t vc_stream_latency_samples(const vc_stream_t *st)"}, {"kind": "function", "line": 110, "name": "process_frame", "signature": "static void process_frame(vc_stream_t *st, vc_spectral_fn fn, void *user)"}, {"kind": "function", "line": 158, "name": "vc_stream_process", "signature": "int vc_stream_process(vc_stream_t *st,\n                      const float *in, float *out, size_t ..."}, {"kind": "function", "line": 96, "name": "free", "signature": "free(st->window);"}, {"kind": "function", "line": 120, "name": "vc_fft", "signature": "vc_fft(N, st->buf_r, st->buf_i, 0);"}, {"kind": "function", "line": 149, "name": "memmove", "signature": "memmove(st->out_accum, st->out_accum + st->hop_size, (N - st->hop_size) * sizeof(float));"}, {"kind": "function", "line": 152, "name": "memset", "signature": "memset(st->out_accum + (N - st->hop_size), 0, st->hop_size * sizeof(float));"}, {"kind": "macro", "line": 8, "name": "M_PI", "signature": "#define M_PI"}]}, {"doc": "ifndef VC_STREAM_H define VC_STREAM_H  include <stddef.h> include <stdint.h>  ifdef __cplusplus", "id": "voicecloak/src/vc_stream.h", "kind": "module", "label": "vc_stream.h", "language": "h", "sha256": "cc0808a0e10772b4", "symbol_count": 8, "symbols": [{"doc": "@brief Streaming STFT overlap-add engine for real-time processing.  Unlike the offline vc_stft, this engine keeps constant sample rate: it emits exactly as many output samples as input samples consumed, which is mandatory for a live audio stream. Analysis hop equals synthesis hop; a per-frame spectral callback modifies magnitude and phase in place. Latency is one FFT frame.", "kind": "type_alias", "line": 20, "name": "vc_stream_t", "signature": "typedef struct vc_stream_s vc_stream_t;"}, {"kind": "function", "line": 32, "name": "frames", "signature": "* that must persist across frames (phase-vocoder accumulators) lives * in @p user, not in the engine. */ typedef void (*vc_spectral_fn)(float *mag, float *phase, size_t nbins, uint32_t sample_rate, si"}, {"doc": "@brief Create a streaming engine. @param fft_size  Power of two. @param hop_size  Must divide fft_size; fft_size/hop_size in {2,4}. @param sample_rate  Stream sample rate in Hz (> 0). @return Context or NULL on invalid arguments / allocation failure.", "kind": "function", "line": 46, "name": "vc_stream_create", "signature": "vc_stream_t *vc_stream_create(size_t fft_size, size_t hop_size, uint32_t sample_rate);"}, {"doc": "@brief Create a streaming engine. @param fft_size  Power of two. @param hop_size  Must divide fft_size; fft_size/hop_size in {2,4}. @param sample_rate  Stream sample rate in Hz (> 0). @return Context or NULL on invalid arguments / allocation failure.  vc_stream_t *vc_stream_create(size_t fft_size, size_t hop_size, uint32_t sample_rate); /** @brief Release a streaming engine. NULL-safe.", "kind": "function", "line": 50, "name": "vc_stream_destroy", "signature": "void vc_stream_destroy(vc_stream_t *st);"}, {"doc": "@brief Create a streaming engine. @param fft_size  Power of two. @param hop_size  Must divide fft_size; fft_size/hop_size in {2,4}. @param sample_rate  Stream sample rate in Hz (> 0). @return Context or NULL on invalid arguments / allocation failure.  vc_stream_t *vc_stream_create(size_t fft_size, size_t hop_size, uint32_t sample_rate); /** @brief Release a streaming engine. NULL-safe. void vc_stream_destroy(vc_stream_t *st); /** @brief Algorithmic latency in samples (one FFT frame).", "kind": "function", "line": 53, "name": "vc_stream_latency_samples", "signature": "size_t vc_stream_latency_samples(const vc_stream_t *st);"}, {"doc": "@brief Process a block, producing exactly @p n output samples. @param st   Engine. @param in   Input samples (length n). @param out  Output samples (length n). May alias @p in. @param n    Number of samples. @param fn   Spectral transform, or NULL for identity passthrough. @param user Context passed to @p fn. @return 0 on success, -1 on invalid arguments.", "kind": "function", "line": 65, "name": "vc_stream_process", "signature": "int vc_stream_process(vc_stream_t *st, const float *in, float *out, size_t n, vc_spectral_fn fn, void *user);"}, {"doc": "ifdef __cplusplus", "kind": "variable", "line": 8, "name": "hop", "signature": "extern \"C\" { #endif /** * @brief Streaming STFT overlap-add engine for real-time processing. * * Unlike the offline vc_stft, this engine keeps constant sample rate: * it emits exactly as many output s"}, {"kind": "macro", "line": 2, "name": "VC_STREAM_H", "signature": "#define VC_STREAM_H"}]}, {"doc": "include \"vc_wav.h\" include <stdio.h> include <stdlib.h> include <string.h> include <math.h> include <stdint.h>  pragma pack(push, 1)", "id": "voicecloak/src/vc_wav.c", "kind": "module", "label": "vc_wav.c", "language": "c", "sha256": "2ffe797d4e47830d", "symbol_count": 15, "symbols": [{"doc": "pragma pack(push, 1)", "kind": "struct", "line": 9, "name": "WavHeader"}, {"kind": "struct", "line": 15, "name": "WavFmtBody"}, {"kind": "struct", "line": 24, "name": "WavDataChunk"}, {"doc": "pragma pack(pop)", "kind": "function", "line": 29, "name": "read_bytes", "signature": "static int read_bytes(FILE *fp, void *buf, size_t n)"}, {"kind": "function", "line": 33, "name": "write_bytes", "signature": "static int write_bytes(FILE *fp, const void *buf, size_t n)"}, {"kind": "function", "line": 37, "name": "sample_to_float", "signature": "static float sample_to_float(const unsigned char *p, int bps)"}, {"kind": "function", "line": 61, "name": "float_to_sample", "signature": "static void float_to_sample(float f, unsigned char *p, int bps)"}, {"kind": "function", "line": 77, "name": "find_chunk", "signature": "static int find_chunk(FILE *fp, const char *id, uint32_t *size)"}, {"kind": "function", "line": 92, "name": "vc_wav_read", "signature": "int vc_wav_read(const char *path,\n                float **samples_out, size_t *num_samples_out,\n ..."}, {"kind": "function", "line": 168, "name": "vc_wav_write", "signature": "int vc_wav_write(const char *path,\n                 const float *samples, size_t num_samples,\n   ..."}, {"kind": "function", "line": 44, "name": "memcpy", "signature": "memcpy(&v, p, 2);"}, {"kind": "function", "line": 89, "name": "fseek", "signature": "fseek(fp, (long)sz, SEEK_CUR);"}, {"kind": "function", "line": 117, "name": "memset", "signature": "memset(&fmt, 0, sizeof(fmt));"}, {"kind": "function", "line": 139, "name": "fclose", "signature": "fclose(fp);"}, {"kind": "function", "line": 155, "name": "free", "signature": "free(raw);"}]}, {"doc": "ifndef VC_WAV_H define VC_WAV_H  include <stddef.h> include <stdint.h>  ifdef __cplusplus", "id": "voicecloak/src/vc_wav.h", "kind": "module", "label": "vc_wav.h", "language": "h", "sha256": "f7a16e9cd014fb9f", "symbol_count": 3, "symbols": [{"doc": "@brief Read a mono PCM WAV file into a float buffer [-1.0, 1.0]. @param path         File path. @param samples_out  Output: allocated float array. @param num_samples_out Output: number of samples. @param sample_rate_out Output: sample rate (Hz). @return 0 on success, -1 on error.", "kind": "function", "line": 19, "name": "vc_wav_read", "signature": "int vc_wav_read(const char *path, float **samples_out, size_t *num_samples_out, uint32_t *sample_rate_out);"}, {"doc": "@brief Write a mono float buffer to a 16-bit PCM WAV file. @param path       File path. @param samples    Float samples in [-1.0, 1.0]. @param num_samples Number of samples. @param sample_rate Sample rate (Hz). @return 0 on success, -1 on error.", "kind": "function", "line": 31, "name": "vc_wav_write", "signature": "int vc_wav_write(const char *path, const float *samples, size_t num_samples, uint32_t sample_rate);"}, {"kind": "macro", "line": 2, "name": "VC_WAV_H", "signature": "#define VC_WAV_H"}]}, {"doc": "include <stdarg.h> include <stddef.h> include <setjmp.h> include <cmocka.h> include <stdlib.h> include <math.h> include <string.h> include \"vc_fft.h\"", "id": "voicecloak/tests/test_vc_fft.c", "kind": "module", "label": "test_vc_fft.c", "language": "c", "sha256": "7568bc24295c9688", "symbol_count": 9, "symbols": [{"doc": "include <stdarg.h> include <stddef.h> include <setjmp.h> include <cmocka.h> include <stdlib.h> include <math.h> include <string.h> include \"vc_fft.h\"", "kind": "function", "line": 9, "name": "test_fft_identity", "signature": "static void test_fft_identity(void **state)"}, {"kind": "function", "line": 26, "name": "test_fft_dc_signal", "signature": "static void test_fft_dc_signal(void **state)"}, {"kind": "function", "line": 46, "name": "test_fft_sine", "signature": "static void test_fft_sine(void **state)"}, {"kind": "function", "line": 75, "name": "main", "signature": "int main(void)"}, {"kind": "function", "line": 16, "name": "vc_fft", "signature": "vc_fft(n, real, imag, 0);"}, {"kind": "function", "line": 22, "name": "assert_float_equal", "signature": "assert_float_equal(real[i], i == 0 ? 1.0f : 0.0f, 1e-4f);"}, {"kind": "function", "line": 42, "name": "free", "signature": "free(real);"}, {"kind": "function", "line": 70, "name": "assert_true", "signature": "assert_true(mag_k > mag_other * 10.0f);"}, {"kind": "function", "line": 82, "name": "cmocka_run_group_tests", "signature": "return cmocka_run_group_tests(tests, NULL, NULL);"}]}, {"doc": "include <stdarg.h> include <stddef.h> include <setjmp.h> include <cmocka.h>  include \"vc_stream.h\" include \"vc_rt.h\" include \"vc_fft.h\"  include <stdlib.h> include <string.h> include <math.h>  ifndef M_PI define M_PI 3.14159265358979323846 endif  define SR 48000U", "id": "voicecloak/tests/test_vc_stream.c", "kind": "module", "label": "test_vc_stream.c", "language": "c", "sha256": "ab6bd3064917dc9f", "symbol_count": 24, "symbols": [{"doc": "define SR 48000U", "kind": "function", "line": 19, "name": "gen_sines", "signature": "static void gen_sines(float *buf, size_t n, uint32_t sr,\n                      const float *freqs..."}, {"kind": "function", "line": 31, "name": "dominant_freq", "signature": "static float dominant_freq(const float *x, size_t n, uint32_t sr)"}, {"kind": "function", "line": 53, "name": "rms", "signature": "static float rms(const float *x, size_t n)"}, {"doc": "Stream a whole buffer through the engine in small, irregular chunks * to exercise arbitrary block sizes.", "kind": "function", "line": 63, "name": "run_stream", "signature": "static void run_stream(vc_stream_t *st, const float *in, float *out, size_t n,\n                  ..."}, {"kind": "function", "line": 73, "name": "test_create_validation", "signature": "static void test_create_validation(void **state)"}, {"kind": "function", "line": 85, "name": "test_passthrough_identity", "signature": "static void test_passthrough_identity(void **state)"}, {"kind": "function", "line": 121, "name": "run_pitch", "signature": "static void run_pitch(float in_freq, float ratio, float expect_freq)"}, {"kind": "function", "line": 145, "name": "test_pitch_up_octave", "signature": "static void test_pitch_up_octave(void **state)"}, {"kind": "function", "line": 150, "name": "test_pitch_down_octave", "signature": "static void test_pitch_down_octave(void **state)"}, {"kind": "function", "line": 155, "name": "test_bounded_output", "signature": "static void test_bounded_output(void **state)"}, {"kind": "function", "line": 184, "name": "main", "signature": "int main(void)"}, {"kind": "function", "line": 43, "name": "vc_fft", "signature": "vc_fft(nf, re, im, 0);"}, {"kind": "function", "line": 50, "name": "free", "signature": "free(re);"}, {"kind": "function", "line": 69, "name": "assert_int_equal", "signature": "assert_int_equal(vc_stream_process(st, in + off, out + off, c, fn, user), 0);"}, {"kind": "function", "line": 76, "name": "assert_null", "signature": "assert_null(vc_stream_create(1000, 250, SR));"}, {"kind": "function", "line": 81, "name": "assert_non_null", "signature": "assert_non_null(st);"}, {"kind": "function", "line": 83, "name": "vc_stream_destroy", "signature": "vc_stream_destroy(st);"}, {"kind": "function", "line": 116, "name": "assert_true", "signature": "assert_true(best_err < 0.05f * in_rms);"}, {"kind": "function", "line": 140, "name": "vc_rt_destroy", "signature": "vc_rt_destroy(ctx);"}, {"kind": "function", "line": 161, "name": "srand", "signature": "srand(1234);"}, {"kind": "function", "line": 175, "name": "assert_false", "signature": "assert_false(isnan(out[i]));"}, {"kind": "function", "line": 193, "name": "cmocka_run_group_tests", "signature": "return cmocka_run_group_tests(tests, NULL, NULL);"}, {"kind": "macro", "line": 15, "name": "M_PI", "signature": "#define M_PI"}, {"kind": "macro", "line": 17, "name": "SR", "signature": "#define SR"}]}], "type": "CodePropertyGraph", "version": "1.0"}
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
- `dev_info` (line 47) `dev_info(&intf->dev, "audiobox_vsl: detected '%s' (%04x:%04x)\n", name, le16_to_cpu(udev->descriptor.idVendor), pid);`
- `module_usb_driver` (line 78) `module_usb_driver(audiobox_driver);`
- `MODULE_LICENSE` (line 80) `MODULE_LICENSE(AUDIOBOX_DRIVER_LIC);`

**Macros:**
- `AUDIOBOX_DRIVER_NAME` (line 24) `#define AUDIOBOX_DRIVER_NAME`
- `AUDIOBOX_DRIVER_DESC` (line 26) `#define AUDIOBOX_DRIVER_DESC`
- `AUDIOBOX_DRIVER_LIC` (line 27) `#define AUDIOBOX_DRIVER_LIC`

#### `main.c`
**Path:** `legacy/main.c`
**File Doc:** *include <stdio.h> include "vsl_dsp_logic.h" include "vsl_dsp_transport.h"*

**Functions:**
- `main` (line 4) `int main()` - *include <stdio.h> include "vsl_dsp_logic.h" include "vsl_dsp_transport.h"*
- `printf` (line 36) `printf("--- Ganancia ---\n");`
- `VSL_Build_And_Send_Packet` (line 68) `VSL_Build_And_Send_Packet(gain_id, encoded_gain_float);` - ************************************************************ *** ¡Llamada para Enviar el Paquete DSP a través de HIDAPI! ****

#### `mixer_quirks.c`
**Path:** `legacy/mixer_quirks.c`
**File Doc:** *SPDX-License-Identifier: GPL-2.0-or-later*

**Enums:**
- `snd_rme_domain` (line 2407)
- `snd_rme_clock_status` (line 2413)

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
- `snd_usb_mixer_elem_init_std` (line 74) `snd_usb_mixer_elem_init_std(&cval->head, mixer, unitid);`
- `kfree` (line 94) `kfree(cval);`
- `snprintf` (line 99) `snprintf(kctl->id.name, sizeof(kctl->id.name), name);` - *cval->min = 0; cval->max = 1; cval->res = 0; cval->dBmin = 0; cval->dBmax = 0; /* Create control kctl = snd_ctl_new1(snd_usb_feature_unit_ctl, cval); if (!kctl) { kfree(cval); return -ENOMEM; } /* Set name*
- `snd_usb_mixer_add_control` (line 110) `return snd_usb_mixer_add_control(&cval->head, kctl);` - *} /* Set name snprintf(kctl->id.name, sizeof(kctl->id.name), name); kctl->private_free = snd_usb_mixer_elem_free; /* set TLV if (tlv_callback) { kctl->tlv.c = tlv_callback; kctl->vd[0].access |= SNDRV_CTL_ELEM_ACCESS_TLV_READ | SNDRV_CTL_ELEM_ACCESS_TLV_CALLBACK; } /* Add control to mixer*
- `snd_usb_mixer_add_list` (line 170) `return snd_usb_mixer_add_list(list, kctl, false);` - *if (!list) return -ENOMEM; if (listp) listp = list; list->mixer = mixer; list->id = id; list->resume = resume; kctl = snd_ctl_new1(knew, list); if (!kctl) { kfree(list); return -ENOMEM; } kctl->private_free = snd_usb_mixer_elem_free; /* don't use snd_usb_mixer_add_control() here, this is a special list element*
- `wake_up` (line 217) `wake_up(&mixer->rc_waitq);`
- `poll_wait` (line 244) `poll_wait(file, &mixer->rc_waitq, wait);`
- `init_waitqueue_head` (line 262) `init_waitqueue_head(&mixer->rc_waitq);`
- `usb_free_urb` (line 280) `usb_free_urb(mixer->rc_urb);`
- `usb_fill_control_urb` (line 290) `usb_fill_control_urb(mixer->rc_urb, mixer->chip->dev, usb_rcvctrlpipe(mixer->chip->dev, 0), (u8 *)mixer->rc_setup_packet, mixer->rc_buffer, len, snd_usb_soundblaster_remote_complete, mixer);`
- `CLASS` (line 310) `CLASS(snd_usb_lock, pm)(chip);`
- `usb_sndctrlpipe` (line 328) `usb_sndctrlpipe(chip->dev, 0), 0x24, USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_OTHER, value, index + 2, NULL, 0);`
- `snd_iprintf` (line 429) `snd_iprintf(buffer, "%s jacks\n\n", mixer->chip->card->shortname);`
- `usb_rcvctrlpipe` (line 445) `usb_rcvctrlpipe(mixer->chip->dev, 0), UAC_GET_MEM, USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE, 0, jacks[i].unitid << 8, buf, 3);`
- `snd_ctl_enum_info` (line 461) `return snd_ctl_enum_info(uinfo, 1, ARRAY_SIZE(texts), texts);`
- `snd_usb_ctl_msg` (line 484) `return snd_usb_ctl_msg(chip->dev, usb_sndctrlpipe(chip->dev, 0), UAC_SET_CUR, USB_RECIP_INTERFACE | USB_TYPE_CLASS | USB_DIR_OUT, 0x0400, 0x0e00, buf, 2);`
- `snd_ctl_notify` (line 566) `snd_ctl_notify(me->mixer->chip->card, SNDRV_CTL_EVENT_MASK_VALUE, &me->kctl->id);`
- `dev_warn` (line 585) `dev_warn(&snd_dev->dev, "Failed to get input dev path\n");`
- `input_unregister_handle` (line 642) `err_unregister: input_unregister_handle(handle);`
- `input_close_device` (line 652) `input_close_device(handle);`
- `snd_usb_mixer_elem_free` (line 710) `snd_usb_mixer_elem_free(kctl);`
- `strscpy` (line 741) `strscpy(kctl->id.name, name, sizeof(kctl->id.name));`
- `dev_err` (line 1134) `dev_err(&dev->dev, "unable to issue vendor read request (ret = %d)", err);`
- `usb_control_msg` (line 1158) `return usb_control_msg(chip->dev, usb_sndctrlpipe(chip->dev, 0), (pval >> 16) & 0xff, USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_OUT, pval >> 24, pval & 0xffff, NULL, 0, 1000);`
- `snd_usb_ctrl_intf` (line 1292) `snd_usb_ctrl_intf(mixer->hostif) | ((pval & 0xff) << 8), value, 2);`
- `snd_usb_mixer_set_ctl_value` (line 1552) `snd_usb_mixer_set_ctl_value(cval, UAC_SET_CUR, cval->control << 8, samplerate_id);`
- `snd_usb_mixer_notify_id` (line 1555) `snd_usb_mixer_notify_id(mixer, unitid);`
- `BIT` (line 1726) `BIT(chan + (chan % 2) * num_outs - 1);`
- `HDA_VERB_CMD` (line 2239) `HDA_VERB_CMD(AC_VERB_GET_PIN_SENSE, node_id, 0), &sense);`
- `field_get` (line 3395) `return field_get(mask, val);`
- `USB_ID` (line 4249) `case USB_ID(0x194f, 0x0101): err = snd_audiobox_vsl_init(mixer);` - *} return 0; } int snd_usb_mixer_apply_create_quirk(struct usb_mixer_interface *mixer) { int err = 0; err = snd_usb_soundblaster_remote_init(mixer); if (err < 0) return err; switch (mixer->chip->usb_id) { /* PreSonus AudioBox 22 VSL*
- `snd_card_ro_proc_new` (line 4264) `snd_card_ro_proc_new(mixer->chip->card, "audigy2nx", mixer, snd_audigy2nx_proc_read);`
- `usb_submit_urb` (line 4439) `usb_submit_urb(mixer->rc_urb, GFP_ATOMIC);`
- `usb_audio_dbg` (line 4452) `default: usb_audio_dbg(mixer->chip, "memory change in unknown unit %d\n", unitid);`
- `DECLARE_TLV_DB_RANGE` (line 4465) `static const DECLARE_TLV_DB_RANGE(scale, 0, 1, TLV_DB_MINMAX_ITEM(-5300, -4970), 2, 5, TLV_DB_MINMAX_ITEM(-4710, -4160), 6, 7, TLV_DB_MINMAX_ITEM(-3884, -3710), 8, 14, TLV_DB_MINMAX_ITEM(-3443, -2560)` - *Approximation using 10 ranges based on output measurement on hw v1.2. This seems close to the cubic mapping e.g. alsamixer uses.*
- `usb_audio_info` (line 4479) `usb_audio_info(mixer->chip, "applying DragonFly dB scale quirk (0-50 variant)\n");`

**Macros:**
- `snd_audigy2nx_led_info` (line 296) `#define snd_audigy2nx_led_info`
- `SND_DUALSENSE_JACK_OUT_TERM_ID` (line 539) `#define SND_DUALSENSE_JACK_OUT_TERM_ID`
- `SND_DUALSENSE_JACK_IN_TERM_ID` (line 541) `#define SND_DUALSENSE_JACK_IN_TERM_ID`
- `_MAKE_NI_CONTROL` (line 1118) `#define _MAKE_NI_CONTROL(bRequest, wIndex)`
- `HDA_VERB_CMD` (line 2171) `#define HDA_VERB_CMD(V, N, D)`
- `REALTEK_HDA_VALUE` (line 2173) `#define REALTEK_HDA_VALUE`
- `REALTEK_HDA_SET` (line 2175) `#define REALTEK_HDA_SET`
- `REALTEK_MANUAL_MODE` (line 2177) `#define REALTEK_MANUAL_MODE`
- `REALTEK_HDA_GET_OUT` (line 2178) `#define REALTEK_HDA_GET_OUT`
- `REALTEK_HDA_GET_IN` (line 2179) `#define REALTEK_HDA_GET_IN`
- `REALTEK_AUDIO_FUNCTION_GROUP` (line 2180) `#define REALTEK_AUDIO_FUNCTION_GROUP`
- `REALTEK_LINE1` (line 2182) `#define REALTEK_LINE1`
- `REALTEK_VENDOR_REGISTERS` (line 2183) `#define REALTEK_VENDOR_REGISTERS`
- `REALTEK_HP_OUT` (line 2184) `#define REALTEK_HP_OUT`
- `REALTEK_CBJ_CTRL2` (line 2185) `#define REALTEK_CBJ_CTRL2`
- `REALTEK_JACK_INTERRUPT_NODE` (line 2187) `#define REALTEK_JACK_INTERRUPT_NODE`
- `REALTEK_MIC_FLAG` (line 2189) `#define REALTEK_MIC_FLAG`
- `SND_RME_GET_STATUS1` (line 2362) `#define SND_RME_GET_STATUS1`
- `SND_RME_GET_CURRENT_FREQ` (line 2364) `#define SND_RME_GET_CURRENT_FREQ`
- `SND_RME_CLK_SYSTEM_SHIFT` (line 2365) `#define SND_RME_CLK_SYSTEM_SHIFT`
- `SND_RME_CLK_SYSTEM_MASK` (line 2366) `#define SND_RME_CLK_SYSTEM_MASK`
- `SND_RME_CLK_AES_SHIFT` (line 2367) `#define SND_RME_CLK_AES_SHIFT`
- `SND_RME_CLK_SPDIF_SHIFT` (line 2368) `#define SND_RME_CLK_SPDIF_SHIFT`
- `SND_RME_CLK_AES_SPDIF_MASK` (line 2369) `#define SND_RME_CLK_AES_SPDIF_MASK`
- `SND_RME_CLK_SYNC_SHIFT` (line 2370) `#define SND_RME_CLK_SYNC_SHIFT`
- `SND_RME_CLK_SYNC_MASK` (line 2371) `#define SND_RME_CLK_SYNC_MASK`
- `SND_RME_CLK_FREQMUL_SHIFT` (line 2372) `#define SND_RME_CLK_FREQMUL_SHIFT`
- `SND_RME_CLK_FREQMUL_MASK` (line 2373) `#define SND_RME_CLK_FREQMUL_MASK`
- `SND_RME_CLK_SYSTEM` (line 2374) `#define SND_RME_CLK_SYSTEM(x)`
- `SND_RME_CLK_AES` (line 2376) `#define SND_RME_CLK_AES(x)`
- `SND_RME_CLK_SPDIF` (line 2378) `#define SND_RME_CLK_SPDIF(x)`
- `SND_RME_CLK_SYNC` (line 2380) `#define SND_RME_CLK_SYNC(x)`
- `SND_RME_CLK_FREQMUL` (line 2382) `#define SND_RME_CLK_FREQMUL(x)`
- `SND_RME_CLK_AES_LOCK` (line 2384) `#define SND_RME_CLK_AES_LOCK`
- `SND_RME_CLK_AES_SYNC` (line 2385) `#define SND_RME_CLK_AES_SYNC`
- `SND_RME_CLK_SPDIF_LOCK` (line 2386) `#define SND_RME_CLK_SPDIF_LOCK`
- `SND_RME_CLK_SPDIF_SYNC` (line 2387) `#define SND_RME_CLK_SPDIF_SYNC`
- `SND_RME_SPDIF_IF_SHIFT` (line 2388) `#define SND_RME_SPDIF_IF_SHIFT`
- `SND_RME_SPDIF_FORMAT_SHIFT` (line 2389) `#define SND_RME_SPDIF_FORMAT_SHIFT`
- `SND_RME_BINARY_MASK` (line 2390) `#define SND_RME_BINARY_MASK`
- `SND_RME_SPDIF_IF` (line 2391) `#define SND_RME_SPDIF_IF(x)`
- `SND_RME_SPDIF_FORMAT` (line 2393) `#define SND_RME_SPDIF_FORMAT(x)`
- `SND_RME_RATE_IDX_AES_SPDIF_NUM` (line 2405) `#define SND_RME_RATE_IDX_AES_SPDIF_NUM`
- `SND_BBFPRO_CTL_REG_MASK` (line 2743) `#define SND_BBFPRO_CTL_REG_MASK`
- `SND_BBFPRO_CTL_IDX_MASK` (line 2745) `#define SND_BBFPRO_CTL_IDX_MASK`
- `SND_BBFPRO_CTL_IDX_SHIFT` (line 2746) `#define SND_BBFPRO_CTL_IDX_SHIFT`
- `SND_BBFPRO_CTL_VAL_MASK` (line 2747) `#define SND_BBFPRO_CTL_VAL_MASK`
- `SND_BBFPRO_CTL_VAL_SHIFT` (line 2748) `#define SND_BBFPRO_CTL_VAL_SHIFT`
- `SND_BBFPRO_CTL_REG1_CLK_MASTER` (line 2749) `#define SND_BBFPRO_CTL_REG1_CLK_MASTER`
- `SND_BBFPRO_CTL_REG1_CLK_OPTICAL` (line 2750) `#define SND_BBFPRO_CTL_REG1_CLK_OPTICAL`
- `SND_BBFPRO_CTL_REG1_SPDIF_PRO` (line 2751) `#define SND_BBFPRO_CTL_REG1_SPDIF_PRO`
- `SND_BBFPRO_CTL_REG1_SPDIF_EMPH` (line 2752) `#define SND_BBFPRO_CTL_REG1_SPDIF_EMPH`
- `SND_BBFPRO_CTL_REG1_SPDIF_OPTICAL` (line 2753) `#define SND_BBFPRO_CTL_REG1_SPDIF_OPTICAL`
- `SND_BBFPRO_CTL_REG2_48V_AN1` (line 2754) `#define SND_BBFPRO_CTL_REG2_48V_AN1`
- `SND_BBFPRO_CTL_REG2_48V_AN2` (line 2755) `#define SND_BBFPRO_CTL_REG2_48V_AN2`
- `SND_BBFPRO_CTL_REG2_SENS_IN3` (line 2756) `#define SND_BBFPRO_CTL_REG2_SENS_IN3`
- `SND_BBFPRO_CTL_REG2_SENS_IN4` (line 2757) `#define SND_BBFPRO_CTL_REG2_SENS_IN4`
- `SND_BBFPRO_CTL_REG2_PAD_AN1` (line 2758) `#define SND_BBFPRO_CTL_REG2_PAD_AN1`
- `SND_BBFPRO_CTL_REG2_PAD_AN2` (line 2759) `#define SND_BBFPRO_CTL_REG2_PAD_AN2`
- `SND_BBFPRO_MIXER_MAIN_OUT_CH_OFFSET` (line 2760) `#define SND_BBFPRO_MIXER_MAIN_OUT_CH_OFFSET`
- `SND_BBFPRO_MIXER_IDX_MASK` (line 2762) `#define SND_BBFPRO_MIXER_IDX_MASK`
- `SND_BBFPRO_MIXER_VAL_MASK` (line 2763) `#define SND_BBFPRO_MIXER_VAL_MASK`
- `SND_BBFPRO_MIXER_VAL_SHIFT` (line 2764) `#define SND_BBFPRO_MIXER_VAL_SHIFT`
- `SND_BBFPRO_MIXER_VAL_MIN` (line 2765) `#define SND_BBFPRO_MIXER_VAL_MIN`
- `SND_BBFPRO_MIXER_VAL_MAX` (line 2766) `#define SND_BBFPRO_MIXER_VAL_MAX`
- `SND_BBFPRO_GAIN_CHANNEL_MASK` (line 2767) `#define SND_BBFPRO_GAIN_CHANNEL_MASK`
- `SND_BBFPRO_GAIN_CHANNEL_SHIFT` (line 2769) `#define SND_BBFPRO_GAIN_CHANNEL_SHIFT`
- `SND_BBFPRO_GAIN_VAL_MASK` (line 2770) `#define SND_BBFPRO_GAIN_VAL_MASK`
- `SND_BBFPRO_GAIN_VAL_MIN` (line 2771) `#define SND_BBFPRO_GAIN_VAL_MIN`
- `SND_BBFPRO_GAIN_VAL_MIC_MAX` (line 2772) `#define SND_BBFPRO_GAIN_VAL_MIC_MAX`
- `SND_BBFPRO_GAIN_VAL_LINE_MAX` (line 2773) `#define SND_BBFPRO_GAIN_VAL_LINE_MAX`
- `SND_BBFPRO_USBREQ_CTL_REG1` (line 2774) `#define SND_BBFPRO_USBREQ_CTL_REG1`
- `SND_BBFPRO_USBREQ_CTL_REG2` (line 2776) `#define SND_BBFPRO_USBREQ_CTL_REG2`
- `SND_BBFPRO_USBREQ_GAIN` (line 2777) `#define SND_BBFPRO_USBREQ_GAIN`
- `SND_BBFPRO_USBREQ_MIXER` (line 2778) `#define SND_BBFPRO_USBREQ_MIXER`
- `RME_DIGIFACE_READ_STATUS` (line 3297) `#define RME_DIGIFACE_READ_STATUS`
- `RME_DIGIFACE_STATUS_REG0L` (line 3299) `#define RME_DIGIFACE_STATUS_REG0L`
- `RME_DIGIFACE_STATUS_REG0H` (line 3300) `#define RME_DIGIFACE_STATUS_REG0H`
- `RME_DIGIFACE_STATUS_REG1L` (line 3301) `#define RME_DIGIFACE_STATUS_REG1L`
- `RME_DIGIFACE_STATUS_REG1H` (line 3302) `#define RME_DIGIFACE_STATUS_REG1H`
- `RME_DIGIFACE_STATUS_REG2L` (line 3303) `#define RME_DIGIFACE_STATUS_REG2L`
- `RME_DIGIFACE_STATUS_REG2H` (line 3304) `#define RME_DIGIFACE_STATUS_REG2H`
- `RME_DIGIFACE_STATUS_REG3L` (line 3305) `#define RME_DIGIFACE_STATUS_REG3L`
- `RME_DIGIFACE_STATUS_REG3H` (line 3306) `#define RME_DIGIFACE_STATUS_REG3H`
- `RME_DIGIFACE_CTL_REG1` (line 3307) `#define RME_DIGIFACE_CTL_REG1`
- `RME_DIGIFACE_CTL_REG2` (line 3309) `#define RME_DIGIFACE_CTL_REG2`
- `RME_DIGIFACE_REGISTER` (line 3312) `#define RME_DIGIFACE_REGISTER(reg, mask)`
- `RME_DIGIFACE_INVERT` (line 3313) `#define RME_DIGIFACE_INVERT`
- `field_get` (line 3316) `#define field_get(_mask, _reg)`
- `field_prep` (line 3317) `#define field_prep(_mask, _val)`
- `SND_DJM_CAP_LINE` (line 3715) `#define SND_DJM_CAP_LINE`
- `SND_DJM_CAP_CDLINE` (line 3716) `#define SND_DJM_CAP_CDLINE`
- `SND_DJM_CAP_DIGITAL` (line 3717) `#define SND_DJM_CAP_DIGITAL`
- `SND_DJM_CAP_PHONO` (line 3718) `#define SND_DJM_CAP_PHONO`
- `SND_DJM_CAP_PREFADER` (line 3719) `#define SND_DJM_CAP_PREFADER`
- `SND_DJM_CAP_PFADER` (line 3720) `#define SND_DJM_CAP_PFADER`
- `SND_DJM_CAP_XFADERA` (line 3721) `#define SND_DJM_CAP_XFADERA`
- `SND_DJM_CAP_XFADERB` (line 3722) `#define SND_DJM_CAP_XFADERB`
- `SND_DJM_CAP_MIC` (line 3723) `#define SND_DJM_CAP_MIC`
- `SND_DJM_CAP_AUX` (line 3724) `#define SND_DJM_CAP_AUX`
- `SND_DJM_CAP_RECOUT` (line 3725) `#define SND_DJM_CAP_RECOUT`
- `SND_DJM_CAP_RECOUT_NOMIC` (line 3726) `#define SND_DJM_CAP_RECOUT_NOMIC`
- `SND_DJM_CAP_NONE` (line 3727) `#define SND_DJM_CAP_NONE`
- `SND_DJM_CAP_FXSEND` (line 3728) `#define SND_DJM_CAP_FXSEND`
- `SND_DJM_CAP_CH1PFADER` (line 3729) `#define SND_DJM_CAP_CH1PFADER`
- `SND_DJM_CAP_CH2PFADER` (line 3730) `#define SND_DJM_CAP_CH2PFADER`
- `SND_DJM_CAP_CH3PFADER` (line 3731) `#define SND_DJM_CAP_CH3PFADER`
- `SND_DJM_CAP_CH4PFADER` (line 3732) `#define SND_DJM_CAP_CH4PFADER`
- `SND_DJM_CAP_EXT1SEND` (line 3733) `#define SND_DJM_CAP_EXT1SEND`
- `SND_DJM_CAP_EXT2SEND` (line 3734) `#define SND_DJM_CAP_EXT2SEND`
- `SND_DJM_CAP_CH1PREFADER` (line 3735) `#define SND_DJM_CAP_CH1PREFADER`
- `SND_DJM_CAP_CH2PREFADER` (line 3736) `#define SND_DJM_CAP_CH2PREFADER`
- `SND_DJM_CAP_CH3PREFADER` (line 3737) `#define SND_DJM_CAP_CH3PREFADER`
- `SND_DJM_CAP_CH4PREFADER` (line 3738) `#define SND_DJM_CAP_CH4PREFADER`
- `SND_DJM_PB_CH1` (line 3741) `#define SND_DJM_PB_CH1`
- `SND_DJM_PB_CH2` (line 3742) `#define SND_DJM_PB_CH2`
- `SND_DJM_PB_AUX` (line 3743) `#define SND_DJM_PB_AUX`
- `SND_DJM_WINDEX_CAP` (line 3744) `#define SND_DJM_WINDEX_CAP`
- `SND_DJM_WINDEX_CAPLVL` (line 3746) `#define SND_DJM_WINDEX_CAPLVL`
- `SND_DJM_WINDEX_PB` (line 3747) `#define SND_DJM_WINDEX_PB`
- `SND_DJM_VALUE_MASK` (line 3750) `#define SND_DJM_VALUE_MASK`
- `SND_DJM_GROUP_MASK` (line 3751) `#define SND_DJM_GROUP_MASK`
- `SND_DJM_DEVICE_MASK` (line 3752) `#define SND_DJM_DEVICE_MASK`
- `SND_DJM_GROUP_SHIFT` (line 3753) `#define SND_DJM_GROUP_SHIFT`
- `SND_DJM_DEVICE_SHIFT` (line 3754) `#define SND_DJM_DEVICE_SHIFT`
- `SND_DJM_250MK2_IDX` (line 3758) `#define SND_DJM_250MK2_IDX`
- `SND_DJM_750_IDX` (line 3759) `#define SND_DJM_750_IDX`
- `SND_DJM_850_IDX` (line 3760) `#define SND_DJM_850_IDX`
- `SND_DJM_900NXS2_IDX` (line 3761) `#define SND_DJM_900NXS2_IDX`
- `SND_DJM_750MK2_IDX` (line 3762) `#define SND_DJM_750MK2_IDX`
- `SND_DJM_450_IDX` (line 3763) `#define SND_DJM_450_IDX`
- `SND_DJM_A9_IDX` (line 3764) `#define SND_DJM_A9_IDX`
- `SND_DJM_V10_IDX` (line 3765) `#define SND_DJM_V10_IDX`
- `SND_DJM_CTL` (line 3766) `#define SND_DJM_CTL(_name, suffix, _default_value, _windex)`
- `SND_DJM_DEVICE` (line 3773) `#define SND_DJM_DEVICE(suffix)`

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
- `printf` (line 8) `printf("Intentando conectar al dispositivo VSL %04X:%04X...\n", VSL_VENDOR_ID, VSL_PRODUCT_ID);`
- `VSL_Close_Device` (line 19) `VSL_Close_Device();`

#### `vsl_dsp_logic.c`
**Path:** `legacy/vsl_dsp_logic.c`
**File Doc:** *include "vsl_dsp_logic.h"  Declaración de la nueva función de envío*

**Functions:**
- `VSL_Encode_Gain` (line 11) `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)` - *Implementación de FUN_00132c90*
- `VSL_Map_Frequency` (line 29) `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)` - *Implementación de FUN_00132d00*
- `VSL_Final_Encode_To_Int` (line 58) `uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)` - *@brief Convierte el valor codificado en float a un entero sin signo para el firmware. @note Basado en la hipótesis común de DSP donde el rango flotante es 0.0 - 1000.0. Si el valor real es diferente, solo se debe cambiar la constante VSL_MAX_ENCODED_FLOAT.*
- `VSL_Decode_Frequency` (line 78) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)` - *Implementación de FUN_00132da8*
- `VSL_Build_And_Send_Packet` (line 4) `void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float);` - *Declaración de la nueva función de envío*
- `exp2f` (line 46) `return exp2f(log2_value);` - *4. Conversión a frecuencia lineal (exp2f)*

#### `vsl_dsp_transport.c`
**Path:** `legacy/vsl_dsp_transport.c`
**File Doc:** *vsl_dsp_transport.c (Añadir la Plantilla B completa aquí)  include <stdio.h> include <string.h> include <math.h> include <hidapi/hidapi.h> include <stdlib.h> include "vsl_config.h" include "vsl_dsp_transport.h"  Handle de Singleton (Regla #5: Diseño Escalable)*

**Functions:**
- `VSL_Init_Device` (line 22) `int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)` - *... (las inclusiones y el singleton handle) ...*
- `VSL_Close_Device` (line 69) `void VSL_Close_Device(void)`
- `VSL_Get_Device_Handle` (line 78) `hid_device* VSL_Get_Device_Handle(void)`
- `FUN_Send_Packet` (line 97) `void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length)` - *@brief Función de I/O real usando HIDAPI. @note DEBE SER REEMPLAZADA con la lógica específica de tu dispositivo (Report ID, longitud, etc.)*
- `VSL_Build_And_Send_Packet` (line 140) `void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float)` - *Implementación de la función de construcción y envío*
- `fprintf` (line 28) `fprintf(stderr, "Error: HIDAPI init failed\n");`
- `hid_free_enumeration` (line 49) `hid_free_enumeration(devs);`
- `free` (line 55) `free(target_path);`
- `hid_exit` (line 62) `hid_exit();`
- `printf` (line 65) `printf("VSL Device handle opened successfully via path: %04X:%04X\n", vendor_id, product_id);`
- `hid_close` (line 72) `hid_close(vsl_device_handle);`
- `memcpy` (line 121) `memcpy(&buf[1], &net_id, sizeof(uint16_t));` - *Copiar ID (2 bytes) y Value (2 bytes) al buffer, iniciando en buf[1] (después del Report ID)*

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
- `fprintf` (line 60) `fprintf(fp, "Usage: %s [OPTIONS] COMMAND [ARGS...]\n" "\n" "Options:\n" " -p, --pid <hex> USB product ID (default: 0x0101 = 22 VSL)\n" " -m, --model <tag> Model tag: 22vsl, 44vsl, 1818vsl\n" " -h, --h`
- `printf` (line 86) `printf("vsl-cli 2.0.0\n" "PreSonus AudioBox VSL DSP control tool\n" "License: AGPL-3.0-or-later\n");`
- `VSL_Close_Device` (line 163) `VSL_Close_Device(dev);`
- `fmaxf` (line 186) `fmaxf(0.0f, fminf(freq_hz / coeffs->freq_max_hz, 1.0f)), coeffs);`

**Macros:**
- `MAX_CHANNELS` (line 47) `#define MAX_CHANNELS`

**Structs:**
- `ParamEntry` (line 15)

#### `vsl_dsp_logic.c`
**Path:** `src/vsl_dsp_logic.c`
**File Doc:** *include "vsl_dsp_logic.h"*

**Functions:**
- `VSL_Encode_Gain` (line 2) `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)` - *include "vsl_dsp_logic.h"*
- `VSL_Decode_Gain` (line 15) `float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param)`
- `VSL_Map_Frequency` (line 49) `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)`
- `VSL_Final_Encode_To_Int` (line 65) `uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)`
- `VSL_Decode_Frequency` (line 75) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)`
- `fmaxf` (line 20) `return fmaxf(0.0f, fminf(r, 1.0f));`
- `exp2f` (line 62) `return exp2f(log2_value);`

#### `vsl_dsp_transport.c`
**Path:** `src/vsl_dsp_transport.c`
**File Doc:** *include "vsl_dsp_transport.h" include <stdio.h> include <stdlib.h> include <string.h> include <libusb-1.0/libusb.h>*

**Functions:**
- `VSL_Init_Device` (line 12) `vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)`
- `VSL_Close_Device` (line 44) `void VSL_Close_Device(vsl_device_handle handle)`
- `VSL_Send_Parameter` (line 60) `int VSL_Send_Parameter(vsl_device_handle handle,
                       uint16_t dsp_param_id,
  ...`
- `free` (line 21) `free(dev);`
- `libusb_exit` (line 27) `libusb_exit(NULL);`
- `libusb_set_auto_detach_kernel_driver` (line 34) `libusb_set_auto_detach_kernel_driver(dev->handle, 1);`
- `libusb_detach_kernel_driver` (line 38) `libusb_detach_kernel_driver(dev->handle, VSL_MIDI_IFACE);`
- `libusb_claim_interface` (line 40) `libusb_claim_interface(dev->handle, VSL_MIDI_IFACE);`
- `libusb_release_interface` (line 53) `libusb_release_interface(dev->handle, VSL_MIDI_IFACE);`
- `libusb_attach_kernel_driver` (line 54) `libusb_attach_kernel_driver(dev->handle, VSL_MIDI_IFACE);`
- `libusb_close` (line 55) `libusb_close(dev->handle);`
- `memset` (line 72) `memset(buf, 0, sizeof(buf));`
- `fprintf` (line 83) `fprintf(stderr, "VSL_Send_Parameter: bulk write failed: %s\n", libusb_error_name(ret));`

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
- `assert_int_equal` (line 28) `assert_int_equal(AUDIOBOX_VENDOR_ID, 0x194fU);`
- `assert_string_equal` (line 39) `assert_string_equal(m[0].product_name, "AudioBox 22 VSL");`
- `assert_non_null` (line 60) `assert_non_null(m);`
- `assert_null` (line 88) `assert_null(audiobox_lookup_model(0x0000U));`
- `assert_int_not_equal` (line 121) `assert_int_not_equal(audiobox_models[i].pid, audiobox_models[j].pid);`
- `assert_true` (line 132) `assert_true(audiobox_models[i].product_name[0] != '\0');`
- `cmocka_run_group_tests` (line 150) `return cmocka_run_group_tests(tests, NULL, NULL);`

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
- `assert_float_equal` (line 25) `assert_float_equal(VSL_Encode_Gain(0.5f, &param), 1.6487212707f, 1e-5f);` - *VSL_Parameter param = { .coeff_offset_A = 0.0f, .coeff_C1 = 1.0f, .log_factor = 1.0f, .curve_min_map = 0.0f, .curve_max_map = 1.0f, .freq_min_hz = 0.0f, /* unused .freq_max_hz = 0.0f, /* unused .dsp_param_id = 0,   /* unused .max_encoded_int = 0 /* unused }; /* Test clamping and basic computation*
- `assert_int_equal` (line 116) `assert_int_equal(VSL_Final_Encode_To_Int(0.75f, &param), 49);` - *VSL_Parameter param = { .coeff_offset_A = 0.0f, /* unused .coeff_C1 = 0.0f,     /* unused .log_factor = 0.0f,   /* unused .curve_min_map = 0.0f,/* unused .curve_max_map = 0.0f,/* unused .freq_min_hz = 0.0f,  /* unused .freq_max_hz = 0.0f,  /* unused .dsp_param_id = 0,    /* unused .max_encoded_int = 65535 /* max uint16 }; /* Test scaling: encoded_float = 0.75 -> 0.75 * 65535/1000 = 49.15125 -> round -> 49*
- `assert_true` (line 325) `assert_true(result >= 0.0f);`
- `cmocka_run_group_tests` (line 346) `return cmocka_run_group_tests(tests, NULL, NULL);`

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
- `fprintf` (line 37) `fprintf(stderr, "vc_alsa: cannot open %s device '%s': %s\n", tag, dev, snd_strerror(err));`
- `snd_pcm_hw_params_alloca` (line 43) `snd_pcm_hw_params_alloca(&hw);`
- `snd_pcm_hw_params_any` (line 44) `snd_pcm_hw_params_any(s->pcm, hw);`
- `snd_pcm_hw_params_set_buffer_size_near` (line 85) `snd_pcm_hw_params_set_buffer_size_near(s->pcm, hw, &buffer);`
- `memcpy` (line 108) `memcpy(&x, base, sizeof(x));`
- `printf` (line 169) `printf("Available ALSA PCM devices:\n");`
- `free` (line 183) `free(name);`
- `snd_device_name_free_hint` (line 185) `snd_device_name_free_hint(hints);`
- `snd_pcm_hw_params_current` (line 211) `snd_pcm_hw_params_current(cap.pcm, hw);`
- `snd_pcm_hw_params_get_rate` (line 212) `snd_pcm_hw_params_get_rate(hw, &neg_rate, &dir);`
- `snd_pcm_prepare` (line 231) `snd_pcm_prepare(cap.pcm);`
- `memset` (line 236) `memset(raw_out, 0, (size_t)period * play.channels * play.bps);` - *snd_pcm_uframes_t period = cfg->period_frames; raw_in   = (unsigned char *)malloc((size_t)period * cap.channels * cap.bps); raw_out  = (unsigned char *)malloc((size_t)period * play.channels * play.bps); mono_in  = (float *)malloc((size_t)period * sizeof(float)); mono_out = (float *)malloc((size_t)period * sizeof(float)); if (!raw_in || !raw_out || !mono_in || !mono_out) { fprintf(stderr, "vc_alsa: out of memory\n"); goto done; } snd_pcm_prepare(cap.pcm); snd_pcm_prepare(play.pcm); /* Prime playback with one period of silence to build a buffer margin.*
- `snd_pcm_writei` (line 237) `snd_pcm_writei(play.pcm, raw_out, period);`
- `snd_pcm_start` (line 238) `snd_pcm_start(cap.pcm);`
- `vc_stream_process` (line 258) `vc_stream_process(st, mono_in, mono_out, (size_t)frames, cfg->fn, cfg->user);`
- `vc_stream_destroy` (line 286) `vc_stream_destroy(st);`

**Macros:**
- `_GNU_SOURCE` (line 1) `#define _GNU_SOURCE`

**Structs:**
- `vc_pcm_t` (line 13)

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
- `printf` (line 10) `printf( "VoiceCloak - cryptographically secure voice anonymizer\n" "\n" "Usage: %s <command> [options]\n" "\n" "Commands:\n" " keygen Generate RSA-4096 keypair\n" " cloak -k <pubkey> <in.wav> <out.wav`
- `fprintf` (line 44) `fprintf(stderr, "Error: key generation failed.\n");`
- `free` (line 74) `free(samples);`
- `fclose` (line 76) `fclose(ur);`
- `snprintf` (line 93) `snprintf(sidecar_path, sizeof(sidecar_path), "%s.vc", out_path);`
- `fwrite` (line 99) `fwrite(enc_seed, 1, enc_len, sf);`

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
- `fclose` (line 56) `fclose(fp);`
- `EVP_PKEY_free` (line 63) `EVP_PKEY_free(pkey);`
- `EVP_PKEY_CTX_free` (line 67) `EVP_PKEY_CTX_free(ctx);`
- `memcpy` (line 127) `memcpy(data, infos[i], info_lens[i]);`
- `memset` (line 150) `memset(p->counter, 0, sizeof(p->counter));`
- `EVP_EncryptInit_ex` (line 152) `EVP_EncryptInit_ex(p->ctx, EVP_aes_256_ctr(), NULL, seed, p->counter);`
- `free` (line 161) `free(p);`
- `EVP_EncryptUpdate` (line 171) `EVP_EncryptUpdate(p->ctx, p->keystream, &outlen, p->keystream, (int)sizeof(p->keystream));`

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
- `vc_stft_destroy` (line 17) `vc_stft_destroy(st);`
- `memcpy` (line 54) `memcpy(synth_phase, phase, nbins * sizeof(float));`
- `free` (line 74) `free(synth_phase);`
- `memset` (line 113) `memset(dst, 0, nbins * sizeof(float));`
- `vc_prng_destroy` (line 285) `vc_prng_destroy(pp);`

**Macros:**
- `VC_FFT_SIZE` (line 8) `#define VC_FFT_SIZE`
- `VC_HOP_SIZE` (line 10) `#define VC_HOP_SIZE`

#### `vc_fft.c`
**Path:** `voicecloak/src/vc_fft.c`
**File Doc:** *include "vc_fft.h" include <math.h> include <string.h> include <stdlib.h>  ifndef M_PI define M_PI 3.14159265358979323846f endif*

**Functions:**
- `bit_reverse` (line 9) `static unsigned int bit_reverse(unsigned int x, unsigned int bits)` - *ifndef M_PI define M_PI 3.14159265358979323846f endif*
- `bit_reverse_reorder` (line 19) `static void bit_reverse_reorder(size_t n, float *real, float *imag)`
- `vc_fft` (line 35) `void vc_fft(size_t n, float *real, float *imag, int inverse)`
- `free` (line 73) `free(work_r);`

**Macros:**
- `M_PI` (line 7) `#define M_PI`

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
- `free` (line 45) `free(c->prev_phase);`
- `memset` (line 56) `memset(c->prev_phase, 0, c->nbins * sizeof(double));`
- `powf` (line 62) `return powf(2.0f, semitones / 12.0f);`

**Macros:**
- `M_PI` (line 7) `#define M_PI`

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
- `vc_fft` (line 70) `vc_fft(nf, re, im, 0);`
- `free` (line 77) `free(re);`
- `fprintf` (line 98) `fprintf(stderr, "selftest: setup failed\n");`
- `vc_stream_destroy` (line 99) `vc_stream_destroy(st);`
- `vc_stream_process` (line 102) `vc_stream_process(st, in, out, n, vc_rt_transform, ctx);`
- `printf` (line 108) `printf("selftest: input dominant = %.1f Hz (expected %.1f)\n", (double)got_in, (double)in_freq);`
- `fclose` (line 134) `fclose(ur);`
- `vc_rt_derive` (line 139) `return vc_rt_derive(ps, fs, ss, witness, p);`
- `memset` (line 199) `memset(&sa, 0, sizeof(sa));`
- `sigaction` (line 201) `sigaction(SIGINT, &sa, NULL);`
- `vc_rt_destroy` (line 218) `vc_rt_destroy(ctx);`

**Macros:**
- `_POSIX_C_SOURCE` (line 1) `#define _POSIX_C_SOURCE`
- `M_PI` (line 16) `#define M_PI`

#### `vc_rt_seed.c`
**Path:** `voicecloak/src/vc_rt_seed.c`
**File Doc:** *include "vc_rt.h" include "vc_crypto.h" include <math.h>*

**Functions:**
- `vc_rt_derive` (line 4) `int vc_rt_derive(const unsigned char *pitch_seed,
                 const unsigned char *formant_s...` - *include "vc_rt.h" include "vc_crypto.h" include <math.h>*
- `vc_prng_destroy` (line 15) `vc_prng_destroy(pp);`

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
- `memset` (line 45) `memset(st->win_sq_sum, 0, fft_size * sizeof(float));` - *st->buf_r    = (float *)malloc(fft_size * sizeof(float)); st->buf_i    = (float *)malloc(fft_size * sizeof(float)); if (!st->window || !st->win_sq_sum || !st->buf_r || !st->buf_i) { vc_stft_destroy(st); return NULL; } size_t i; for (i = 0; i < fft_size; ++i) { st->window[i] = 0.5f * (1.0f - cosf(2.0f * (float)M_PI * (float)i / (float)(fft_size - 1))); } /* Compute overlap-add normalization for synthesis hop*
- `free` (line 60) `free(st->window);`
- `vc_fft` (line 101) `vc_fft(fft_n, st->buf_r, st->buf_i, 0);`

**Macros:**
- `M_PI` (line 8) `#define M_PI`

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
- `free` (line 96) `free(st->window);`
- `vc_fft` (line 120) `vc_fft(N, st->buf_r, st->buf_i, 0);`
- `memmove` (line 149) `memmove(st->out_accum, st->out_accum + st->hop_size, (N - st->hop_size) * sizeof(float));`
- `memset` (line 152) `memset(st->out_accum + (N - st->hop_size), 0, st->hop_size * sizeof(float));`

**Macros:**
- `M_PI` (line 8) `#define M_PI`

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
- `memcpy` (line 44) `memcpy(&v, p, 2);`
- `fseek` (line 89) `fseek(fp, (long)sz, SEEK_CUR);`
- `memset` (line 117) `memset(&fmt, 0, sizeof(fmt));`
- `fclose` (line 139) `fclose(fp);`
- `free` (line 155) `free(raw);`

**Structs:**
- `WavHeader` (line 9) - *pragma pack(push, 1)*
- `WavFmtBody` (line 15)
- `WavDataChunk` (line 24)

#### `test_vc_fft.c`
**Path:** `voicecloak/tests/test_vc_fft.c`
**File Doc:** *include <stdarg.h> include <stddef.h> include <setjmp.h> include <cmocka.h> include <stdlib.h> include <math.h> include <string.h> include "vc_fft.h"*

**Functions:**
- `test_fft_identity` (line 9) `static void test_fft_identity(void **state)` - *include <stdarg.h> include <stddef.h> include <setjmp.h> include <cmocka.h> include <stdlib.h> include <math.h> include <string.h> include "vc_fft.h"*
- `test_fft_dc_signal` (line 26) `static void test_fft_dc_signal(void **state)`
- `test_fft_sine` (line 46) `static void test_fft_sine(void **state)`
- `main` (line 75) `int main(void)`
- `vc_fft` (line 16) `vc_fft(n, real, imag, 0);`
- `assert_float_equal` (line 22) `assert_float_equal(real[i], i == 0 ? 1.0f : 0.0f, 1e-4f);`
- `free` (line 42) `free(real);`
- `assert_true` (line 70) `assert_true(mag_k > mag_other * 10.0f);`
- `cmocka_run_group_tests` (line 82) `return cmocka_run_group_tests(tests, NULL, NULL);`

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
- `vc_fft` (line 43) `vc_fft(nf, re, im, 0);`
- `free` (line 50) `free(re);`
- `assert_int_equal` (line 69) `assert_int_equal(vc_stream_process(st, in + off, out + off, c, fn, user), 0);`
- `assert_null` (line 76) `assert_null(vc_stream_create(1000, 250, SR));`
- `assert_non_null` (line 81) `assert_non_null(st);`
- `vc_stream_destroy` (line 83) `vc_stream_destroy(st);`
- `assert_true` (line 116) `assert_true(best_err < 0.05f * in_rms);`
- `vc_rt_destroy` (line 140) `vc_rt_destroy(ctx);`
- `srand` (line 161) `srand(1234);`
- `assert_false` (line 175) `assert_false(isnan(out[i]));`
- `cmocka_run_group_tests` (line 193) `return cmocka_run_group_tests(tests, NULL, NULL);`

**Macros:**
- `M_PI` (line 15) `#define M_PI`
- `SR` (line 17) `#define SR`

### H (15 files)

#### `audiobox_vsl.h`
**Path:** `audiobox_vsl.h`
**File Doc:** *SPDX-License-Identifier: GPL-2.0-or-later*

**Imported by:** `audiobox_vsl.c`, `mixer_quirks.c`, `test_audiobox_vsl.c`

**Functions:**
- `audiobox_lookup_model` (line 95) `static inline const audiobox_model_info_t *
audiobox_lookup_model(uint16_t pid)` - *@brief Look up the model info entry for a given USB product ID.  @param pid 16-bit product ID reported by the USB device. @return Pointer to a const entry in audiobox_models[] on match. NULL if pid does not correspond to any supported model.  Pure function: no side effects, no allocation, safe to call from any context including the USB probe path. The returned pointer remains valid for the lifetime of the kernel. Defined as a static inline so both the kernel module and the userspace test suite can include this header and exercise the lookup without linking against kernel-only object files.*
- `snd_audiobox_vsl_init` (line 122) `int snd_audiobox_vsl_init(struct usb_mixer_interface *mixer);` - *@brief ALSA mixer init hook for AudioBox VSL devices.  Optional entry point used by the upstream sound/usb/mixer_quirks.c dispatch table. Not invoked by the detector itself. Returns 0 on success, a negative errno on failure.*

**Macros:**
- `AUDIOBOX_VSL_H` (line 21) `#define AUDIOBOX_VSL_H`
- `AUDIOBOX_VENDOR_ID` (line 32) `#define AUDIOBOX_VENDOR_ID`

**Structs:**
- `usb_mixer_interface` (line 113)
- `audiobox_model_info_t` (line 53) - *@brief Pair of product ID and canonical human readable model name.  The product_name field is a pointer to a static string literal that lives for the lifetime of the kernel. Callers must not free it.*

**Variables:**
- `audiobox_model_pid_t` (line 26) `extern "C" { #endif /** * @brief PreSonus USB vendor ID shared by every AudioBox VSL model. */ #define AUDIOBOX_VENDOR_ID 0x194fU /** * @brief Product IDs of the AudioBox VSL family. * * The enumerato` - *ifdef __cplusplus*

#### `vsl_config.h`
**Path:** `legacy/vsl_config.h`
**File Doc:** *vsl_config.h (VERSION CORREGIDA)  ifndef VSL_CONFIG_H define VSL_CONFIG_H  include <stdint.h>  ======================================================= BLOQUEADORES CRÍTICOS (Hardware) ======================================================= define VSL_VENDOR_ID   0x194f define VSL_PRODUCT_ID  0x0101 define VSL_REPORT_ID   0x06  ======================================================= CONSTANTES CRÍTICAS VSL-DSP (Necesarias para la lógica) =======================================================  Factor de escala usado en la fórmula VSL (Confirmado en la PoC Python) define VSL_SCALE_FACTOR        1000.0f  Máximo valor codificado de 16 bits (0xFFFF) define VSL_MAX_ENCODED_INT     65535  define VSL_PACKET_SIZE         64      // 0x40 bytes define VSL_PAYLOAD_SIZE        5       // Byte 1 (ID LSB) a Byte 4 (Value MSB)  endif // VSL_CONFIG_H*

**Macros:**
- `VSL_CONFIG_H` (line 4) `#define VSL_CONFIG_H`
- `VSL_VENDOR_ID` (line 11) `#define VSL_VENDOR_ID`
- `VSL_PRODUCT_ID` (line 12) `#define VSL_PRODUCT_ID`
- `VSL_REPORT_ID` (line 13) `#define VSL_REPORT_ID`
- `VSL_SCALE_FACTOR` (line 20) `#define VSL_SCALE_FACTOR`
- `VSL_MAX_ENCODED_INT` (line 23) `#define VSL_MAX_ENCODED_INT`
- `VSL_PACKET_SIZE` (line 24) `#define VSL_PACKET_SIZE`
- `VSL_PAYLOAD_SIZE` (line 26) `#define VSL_PAYLOAD_SIZE`

#### `vsl_dsp_logic.h`
**Path:** `legacy/vsl_dsp_logic.h`
**File Doc:** *ifndef VSL_DSP_LOGIC_H define VSL_DSP_LOGIC_H  include <stdint.h> include <math.h> include <float.h> // Para fmaxf, fminf  Constante para la conversión de logaritmo natural (ln) a logaritmo base 2 (log2) 1 / ln(2) ≈ 1.442695 define VSL_INV_LN2 1.442695f  Estructura que almacena todos los coeficientes precalculados del DSP*

**Functions:**
- `VSL_Encode_Gain` (line 42) `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);` - *@brief Codifica un valor lineal (ej. 0.5) a la escala exponencial/logarítmica del DSP (Ganancia/Volumen). @param linear_value El valor lineal de entrada (ej. la posición del slider, 0.0 a 1.0). @param param La estructura del parámetro con sus coeficientes. @return El valor codificado en formato float (listo para la conversión final a int).*
- `VSL_Map_Frequency` (line 50) `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);` - *@brief Convierte una posición lineal (ej. 0.5) a su frecuencia logarítmica (Hz) real. @param linear_position La posición lineal de entrada (0.0 a 1.0). @param param La estructura del parámetro con sus coeficientes. @return La frecuencia mapeada en Hertz (Hz).*
- `VSL_Final_Encode_To_Int` (line 60) `uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param);` - *@brief Convierte el valor codificado en float a un entero sin signo para el firmware. @note ESTA FUNCIÓN ES UN MARCADOR DE POSICIÓN. El factor de escala final (la fórmula interna) aún debe ser determinado con ingeniería inversa. @param encoded_float El valor float retornado por VSL_Encode_Gain o VSL_Map_Frequency. @param param La estructura del parámetro con la precisión máxima entera. @return El valor binario final (uint32_t) listo para ser enviado en el paquete DSP.*
- `VSL_Decode_Frequency` (line 73) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);` - *@brief Decodifica una frecuencia real (Hz) del DSP a su posición lineal de control (0.0 a 1.0). @param freq_hz_value La frecuencia real en Hertz leída del DSP. @param param La estructura del parámetro con sus rangos. @return La posición lineal (0.0 a 1.0) para actualizar el control de la GUI.*

**Macros:**
- `VSL_DSP_LOGIC_H` (line 2) `#define VSL_DSP_LOGIC_H`
- `VSL_INV_LN2` (line 10) `#define VSL_INV_LN2`

**Structs:**
- `VSL_Parameter` (line 13) - *Estructura que almacena todos los coeficientes precalculados del DSP*

#### `vsl_dsp_transport.h`
**Path:** `legacy/vsl_dsp_transport.h`
**File Doc:** *vsl_dsp_transport.h (CORREGIDO)  ifndef VSL_DSP_TRANSPORT_H define VSL_DSP_TRANSPORT_H  include <stdint.h> include <stddef.h> include <hidapi/hidapi.h> include "vsl_config.h" // Solo incluye la configuración  Estructura de Paquete: Sin 'header' (lo quitaste en la estructura typedef)*

**Functions:**
- `VSL_Init_Device` (line 19) `int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id);` - *1. Funciones de Inicialización y Cierre (¡Ambas declaradas!)*
- `VSL_Close_Device` (line 20) `void VSL_Close_Device(void);`
- `VSL_Get_Device_Handle` (line 21) `hid_device* VSL_Get_Device_Handle(void);`
- `FUN_Send_Packet` (line 24) `void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length);` - *2. Funciones de Envío*
- `VSL_Build_And_Send_Packet` (line 25) `void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float);`

**Macros:**
- `VSL_DSP_TRANSPORT_H` (line 4) `#define VSL_DSP_TRANSPORT_H`

**Structs:**
- `VSL_DSP_Packet` (line 12) - *Estructura de Paquete: Sin 'header' (lo quitaste en la estructura typedef)*

#### `vsl_config.h`
**Path:** `src/vsl_config.h`
**File Doc:** *ifndef VSL_CONFIG_H define VSL_CONFIG_H  include <stdint.h> include <stddef.h>  ifdef __cplusplus*

**Functions:**
- `VSL_ModelLookup` (line 35) `static inline const VSL_ModelInfo *
VSL_ModelLookup(uint16_t pid)`
- `VSL_ModelLookupByTag` (line 47) `static inline const VSL_ModelInfo *
VSL_ModelLookupByTag(const char *tag)`

**Macros:**
- `VSL_CONFIG_H` (line 2) `#define VSL_CONFIG_H`
- `VSL_VENDOR_ID` (line 10) `#define VSL_VENDOR_ID`
- `VSL_PRODUCT_ID_22VSL` (line 12) `#define VSL_PRODUCT_ID_22VSL`
- `VSL_PRODUCT_ID_44VSL` (line 13) `#define VSL_PRODUCT_ID_44VSL`
- `VSL_PRODUCT_ID_1818VSL` (line 14) `#define VSL_PRODUCT_ID_1818VSL`
- `VSL_REPORT_ID` (line 15) `#define VSL_REPORT_ID`
- `VSL_PACKET_SIZE` (line 17) `#define VSL_PACKET_SIZE`
- `VSL_MIDI_IFACE` (line 18) `#define VSL_MIDI_IFACE`
- `VSL_EP_MIDI_OUT` (line 19) `#define VSL_EP_MIDI_OUT`

**Structs:**
- `VSL_ModelInfo` (line 21)

**Variables:**
- `pid` (line 8) `extern "C" { #endif #define VSL_VENDOR_ID 0x194fU #define VSL_PRODUCT_ID_22VSL 0x0101U #define VSL_PRODUCT_ID_44VSL 0x0102U #define VSL_PRODUCT_ID_1818VSL 0x0103U #define VSL_REPORT_ID 0x06U #define V` - *ifdef __cplusplus*

#### `vsl_dsp_logic.h`
**Path:** `src/vsl_dsp_logic.h`
**File Doc:** *ifndef VSL_DSP_LOGIC_H define VSL_DSP_LOGIC_H  include <stdint.h> include <math.h> include <float.h>  define VSL_INV_LN2            1.442695f define VSL_MAX_ENCODED_FLOAT  1000.0f*

**Functions:**
- `VSL_Encode_Gain` (line 33) `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);` - *@brief Encodes a linear gain value [0.0, 1.0] to the DSP exponential curve. @param linear_value Linear control position clamped to [0,1]. @param param Parameter coefficients from the DSP parameter database. @return Encoded float value ready for integer conversion. @source Reverse-engineered from FUN_00132c90 in the Android driver.*
- `VSL_Decode_Gain` (line 42) `float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param);` - *@brief Decodes an encoded gain float back to a linear position [0.0, 1.0]. @param encoded_float Value received from the DSP or produced by VSL_Encode_Gain. @param param Same coefficients used during encoding. @return Linear control position clamped to [0,1]. @source Inverse of VSL_Encode_Gain (FUN_00132c90).*
- `VSL_Map_Frequency` (line 51) `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);` - *@brief Maps a linear position [0.0, 1.0] to a logarithmic frequency (Hz). @param linear_position Linear control position clamped to [0,1]. @param param Parameter with freq_min_hz and freq_max_hz. @return Frequency in Hz. @source Reverse-engineered from FUN_00132d00 in the Android driver.*
- `VSL_Decode_Frequency` (line 60) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);` - *@brief Decodes a frequency (Hz) from the DSP to a linear position [0.0, 1.0]. @param freq_hz_value Frequency in Hz read from the DSP, clamped to range. @param param Parameter with freq_min_hz and freq_max_hz. @return Linear control position [0,1]. @source Reverse-engineered from FUN_00132da8 in the Android driver.*
- `VSL_Final_Encode_To_Int` (line 70) `uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param);` - *@brief Converts an encoded float to a 16-bit integer for the DSP firmware. @param encoded_float Value from VSL_Encode_Gain or VSL_Map_Frequency. @param param Parameter with max_encoded_int (typically 65535). @return Integer value clamped to [0, max_encoded_int] ready for the USB packet. @note The scale factor VSL_MAX_ENCODED_FLOAT (1000.0f) is a hypothesis from the DSP scaling. Validated test: 0.75 -> 40793 (full pipeline).*

**Macros:**
- `VSL_DSP_LOGIC_H` (line 2) `#define VSL_DSP_LOGIC_H`
- `VSL_INV_LN2` (line 7) `#define VSL_INV_LN2`
- `VSL_MAX_ENCODED_FLOAT` (line 9) `#define VSL_MAX_ENCODED_FLOAT`

**Structs:**
- `VSL_Parameter` (line 11)

#### `vsl_dsp_transport.h`
**Path:** `src/vsl_dsp_transport.h`
**File Doc:** *ifndef VSL_DSP_TRANSPORT_H define VSL_DSP_TRANSPORT_H  include <stdint.h> include "vsl_dsp_logic.h" include "vsl_config.h"  ifdef __cplusplus*

**Functions:**
- `VSL_Init_Device` (line 20) `vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id);` - *@brief Open a VSL device by USB VID/PID and claim the MIDI control interface. @param vendor_id USB vendor ID (typically VSL_VENDOR_ID). @param product_id USB product ID for the specific VSL model. @return Opaque handle on success, NULL on failure.*
- `VSL_Close_Device` (line 26) `void VSL_Close_Device(vsl_device_handle handle);` - *@brief Release the MIDI interface and close the device. @param handle Handle from VSL_Init_Device. NULL is a safe no-op.*
- `VSL_Send_Parameter` (line 35) `int VSL_Send_Parameter(vsl_device_handle handle, uint16_t dsp_param_id, uint16_t encoded_value);` - *@brief Send a DSP parameter value to the device via USB bulk transfer. @param handle Handle from VSL_Init_Device. @param dsp_param_id 16-bit DSP parameter identifier. @param encoded_value 16-bit encoded integer value. @return 0 on success, negative on error.*

**Macros:**
- `VSL_DSP_TRANSPORT_H` (line 2) `#define VSL_DSP_TRANSPORT_H`

**Type_Aliases:**
- `vsl_device_handle` (line 11) `typedef void* vsl_device_handle;` - *endif*

**Variables:**
- `vsl_device_handle` (line 9) `extern "C" { #endif typedef void* vsl_device_handle;` - *ifdef __cplusplus*

#### `vc_alsa.h`
**Path:** `voicecloak/src/vc_alsa.h`
**File Doc:** *ifndef VC_ALSA_H define VC_ALSA_H  include <stddef.h> include <stdint.h> include <signal.h> include "vc_stream.h"  ifdef __cplusplus*

**Functions:**
- `runtime` (line 15) `* * The capture and playback device names are ALSA PCM names discovered * at runtime (e.g. "hw:VSL", "plughw:2,0", "default");`
- `vc_alsa_list` (line 40) `int vc_alsa_list(void);` - *@brief Print the available ALSA PCM devices to stdout. @return 0 on success, -1 on error.*
- `vc_alsa_run` (line 47) `int vc_alsa_run(const vc_alsa_cfg_t *cfg);` - *@brief Open capture and playback, run the processing loop until *cfg->stop becomes non-zero or a fatal error occurs. @return 0 on clean stop, -1 on error.*

**Macros:**
- `VC_ALSA_H` (line 2) `#define VC_ALSA_H`

**Structs:**
- `vc_alsa_cfg_t` (line 23) - *@brief Configuration for a real-time ALSA processing session.  The capture and playback device names are ALSA PCM names discovered at runtime (e.g. "hw:VSL", "plughw:2,0", "default"); nothing is hardcoded. Rate and channel count are requested but the negotiated values from the device win. The DSP engine is created internally with the negotiated rate; the transform callback and its context are supplied by the caller.*

#### `vc_crypto.h`
**Path:** `voicecloak/src/vc_crypto.h`
**File Doc:** *ifndef VC_CRYPTO_H define VC_CRYPTO_H  include <stddef.h> include <stdint.h>  ifdef __cplusplus*

**Functions:**
- `vc_crypto_keygen` (line 24) `int vc_crypto_keygen(const char *pubkey_path, const char *privkey_path);` - *@brief Generate an RSA-4096 keypair and write to PEM files. @param pubkey_path   Output path for public key. @param privkey_path  Output path for private key. @return 0 on success, -1 on error.*
- `vc_crypto_seal` (line 35) `int vc_crypto_seal(const char *pubkey_path, const unsigned char *seed, size_t seed_len, unsigned char *enc_out, size_t *enc_len);` - *@brief Encrypt a symmetric session seed using RSA-4096 public key. @param pubkey_path   Path to PEM public key. @param seed          [in] 96-byte seed (pitch+formant+spectral). @param seed_len      Must be VC_TOTAL_SEED_BYTES (96). @param enc_out       [out] Buffer for RSA ciphertext (512 bytes). @param enc_len       [out] Length of ciphertext. @return 0 on success, -1 on error.*
- `vc_crypto_unseal` (line 48) `int vc_crypto_unseal(const char *privkey_path, const unsigned char *enc, size_t enc_len, unsigned char *seed, size_t seed_len);` - *@brief Decrypt the session seed using RSA-4096 private key. @param privkey_path  Path to PEM private key. @param enc           [in]  RSA ciphertext. @param enc_len       Length of ciphertext. @param seed          [out] 96-byte recovered seed. @param seed_len      Must be VC_TOTAL_SEED_BYTES. @return 0 on success, -1 on error.*
- `vc_crypto_derive_seeds` (line 61) `int vc_crypto_derive_seeds(const unsigned char *master_seed, size_t seed_len, unsigned char *pitch_seed, unsigned char *formant_seed, unsigned char *spectral_seed);` - *@brief Derive sub-seeds from a master seed via HKDF-SHA256. @param master_seed   96-byte master seed. @param seed_len      VC_TOTAL_SEED_BYTES. @param pitch_seed    [out] 32-byte pitch PRNG seed. @param formant_seed  [out] 32-byte formant PRNG seed. @param spectral_seed [out] 32-byte spectral PRNG seed. @return 0 on success, -1 on error.*
- `vc_prng_create` (line 77) `vc_prng_t *vc_prng_create(const unsigned char *seed);` - *@brief Create a PRNG from a 32-byte seed.*
- `vc_prng_destroy` (line 82) `void vc_prng_destroy(vc_prng_t *p);` - *@brief Release PRNG.*
- `vc_prng_fill` (line 87) `void vc_prng_fill(vc_prng_t *p, unsigned char *buf, size_t len);` - *@brief Fill buffer with deterministic pseudo-random bytes.*
- `vc_prng_float` (line 92) `float vc_prng_float(vc_prng_t *p, float low, float high);` - *@brief Generate a float in [low, high] deterministically.*

**Macros:**
- `VC_CRYPTO_H` (line 2) `#define VC_CRYPTO_H`
- `VC_CRYPTO_SEED_BYTES` (line 10) `#define VC_CRYPTO_SEED_BYTES`
- `VC_CRYPTO_KEY_BYTES` (line 12) `#define VC_CRYPTO_KEY_BYTES`
- `VC_PITCH_SEED_BYTES` (line 13) `#define VC_PITCH_SEED_BYTES`
- `VC_FORMANT_SEED_BYTES` (line 14) `#define VC_FORMANT_SEED_BYTES`
- `VC_SPECTRAL_SEED_BYTES` (line 15) `#define VC_SPECTRAL_SEED_BYTES`
- `VC_TOTAL_SEED_BYTES` (line 16) `#define VC_TOTAL_SEED_BYTES`

**Type_Aliases:**
- `vc_prng_t` (line 72) `typedef struct vc_prng_s vc_prng_t;` - *@brief Deterministic PRNG seeded from crypto key material.  Internally uses AES-256-CTR with the given seed as key and a zero IV. Produces the same stream for the same seed every time.*

#### `vc_dsp.h`
**Path:** `voicecloak/src/vc_dsp.h`
**File Doc:** *ifndef VC_DSP_H define VC_DSP_H  include <stddef.h> include <stdint.h>  ifdef __cplusplus*

**Functions:**
- `vc_dsp_pitch_shift` (line 15) `int vc_dsp_pitch_shift(const float *samples, size_t num_samples, uint32_t sample_rate, float semitones, float **out, size_t *out_len);`
- `vc_dsp_formant_shift` (line 19) `int vc_dsp_formant_shift(const float *samples, size_t num_samples, uint32_t sample_rate, float shift_factor, float **out, size_t *out_len);`
- `vc_dsp_spectral_scramble` (line 23) `int vc_dsp_spectral_scramble(const float *samples, size_t num_samples, uint32_t sample_rate, float intensity, float **out, size_t *out_len);`
- `vc_dsp_cloak` (line 27) `int vc_dsp_cloak(const float *samples, size_t num_samples, uint32_t sample_rate, const unsigned char *pitch_seed, const unsigned char *formant_seed, const unsigned char *spectral_seed, VcMode mode, fl`

**Macros:**
- `VC_DSP_H` (line 2) `#define VC_DSP_H`

**Variables:**
- `VcMode` (line 8) `extern "C" { #endif typedef enum { VC_MODE_SUBTLE = 0, VC_MODE_WITNESS = 1 } VcMode;` - *ifdef __cplusplus*

#### `vc_fft.h`
**Path:** `voicecloak/src/vc_fft.h`
**File Doc:** *ifndef VC_FFT_H define VC_FFT_H  include <stddef.h>  ifdef __cplusplus*

**Functions:**
- `FFT` (line 18) `* FFT(IFFT(x)) == IFFT(FFT(x)) == x. */ void vc_fft(size_t n, float *real, float *imag, int inverse);`

**Macros:**
- `VC_FFT_H` (line 2) `#define VC_FFT_H`

#### `vc_rt.h`
**Path:** `voicecloak/src/vc_rt.h`
**File Doc:** *ifndef VC_RT_H define VC_RT_H  include <stddef.h> include <stdint.h>  ifdef __cplusplus*

**Functions:**
- `vc_rt_create` (line 32) `vc_rt_ctx_t *vc_rt_create(size_t nbins, vc_rt_params_t params);` - *@brief Create a transform context sized for @p nbins frequency bins. @return Context or NULL on allocation failure / nbins < 2.*
- `vc_rt_destroy` (line 35) `void vc_rt_destroy(vc_rt_ctx_t *c);` - *@brief Create a transform context sized for @p nbins frequency bins. @return Context or NULL on allocation failure / nbins < 2.  vc_rt_ctx_t *vc_rt_create(size_t nbins, vc_rt_params_t params); /** @brief Release a transform context. NULL-safe.*
- `vc_rt_reset` (line 38) `void vc_rt_reset(vc_rt_ctx_t *c);` - *@brief Create a transform context sized for @p nbins frequency bins. @return Context or NULL on allocation failure / nbins < 2.  vc_rt_ctx_t *vc_rt_create(size_t nbins, vc_rt_params_t params); /** @brief Release a transform context. NULL-safe. void vc_rt_destroy(vc_rt_ctx_t *c); /** @brief Reset cross-frame phase state (e.g. on stream restart).*
- `vc_rt_transform` (line 48) `void vc_rt_transform(float *mag, float *phase, size_t nbins, uint32_t sample_rate, size_t hop, void *user);` - *@brief Per-frame transform, compatible with vc_spectral_fn. @param user Must be a vc_rt_ctx_t* created with matching nbins.  Applies frequency-domain pitch shift (constant rate), formant envelope scaling, and spectral scrambling, then rewrites mag/phase to the synthesis spectrum.*
- `vc_rt_semitones_to_ratio` (line 54) `float vc_rt_semitones_to_ratio(float semitones);` - *@brief Convert a semitone shift to a pitch ratio (2^(semitones/12)).*
- `vc_rt_derive` (line 65) `int vc_rt_derive(const unsigned char *pitch_seed, const unsigned char *formant_seed, const unsigned char *spectral_seed, int witness_mode, vc_rt_params_t *out);` - *@brief Derive cloak parameters from three 32-byte PRNG seeds. @param pitch_seed    32-byte seed. @param formant_seed  32-byte seed. @param spectral_seed 32-byte seed. @param witness_mode  Non-zero for the aggressive witness ranges. @param out           [out] resolved parameters. @return 0 on success, -1 on error. Ranges mirror vc_dsp_cloak.*

**Macros:**
- `VC_RT_H` (line 2) `#define VC_RT_H`

**Structs:**
- `vc_rt_params_t` (line 17) - *@brief Real-time cloak parameters (already resolved to scalars).  pitch_ratio 1.0 = no shift; formant_factor 1.0 = no shift; scramble_intensity 0.0 = none.*

**Type_Aliases:**
- `vc_rt_ctx_t` (line 26) `typedef struct vc_rt_ctx_s vc_rt_ctx_t;` - *@brief Phase-vocoder transform context (per-bin state across frames).*

**Variables:**
- `shift` (line 8) `extern "C" { #endif /** * @brief Real-time cloak parameters (already resolved to scalars). * * pitch_ratio 1.0 = no shift;` - *ifdef __cplusplus*

#### `vc_stft.h`
**Path:** `voicecloak/src/vc_stft.h`
**File Doc:** *ifndef VC_STFT_H define VC_STFT_H  include <stddef.h> include <stdint.h>  ifdef __cplusplus*

**Functions:**
- `vc_stft_create` (line 25) `vc_stft_t *vc_stft_create(size_t fft_size, size_t hop_size);` - *@brief Allocate STFT context. @param fft_size  FFT size (power of 2, e.g. 2048). @param hop_size  Hop size in samples (e.g. fft_size / 4). @return Context pointer or NULL on failure.*
- `vc_stft_destroy` (line 30) `void vc_stft_destroy(vc_stft_t *st);` - *@brief Release STFT context.*
- `vc_stft_forward` (line 42) `int vc_stft_forward(vc_stft_t *st, const float *samples, size_t num_samples, float **mag, float **phase, size_t *num_frames_out);` - *@brief Forward STFT: decompose a mono float buffer into complex frames. @param st       STFT context. @param samples  Input float samples, length = num_samples. @param num_samples  Number of input samples. @param mag      Output: magnitude per bin per frame (row-major, num_frames * (fft_size/2+1)). @param phase    Output: phase per bin per frame (row-major, same layout as mag). @param num_frames_out  Output: number of frames produced. @return 0 on success, -1 on error.*
- `vc_stft_inverse` (line 57) `int vc_stft_inverse(vc_stft_t *st, const float *mag, const float *phase, size_t num_frames, float *samples_out, size_t num_samples_out);` - *@brief Inverse STFT: reconstruct signal from modified magnitude/phase. @param st        STFT context. @param mag       Input magnitude (row-major, num_frames * nbins). @param phase     Input phase (row-major, same layout). @param num_frames Number of frames. @param samples_out  Output: reconstructed float samples (caller must pre-allocate). @param num_samples_out  Number of samples to reconstruct. @return 0 on success, -1 on error.*
- `vc_stft_inverse_hop` (line 66) `int vc_stft_inverse_hop(vc_stft_t *st, const float *mag, const float *phase, size_t num_frames, float *samples_out, size_t num_samples_out, size_t synth_hop);` - *@brief Inverse STFT with custom synthesis hop (for pitch shifting). @param synth_hop  Synthesis hop size in samples (may differ from analysis hop).*
- `vc_stft_num_bins` (line 75) `size_t vc_stft_num_bins(const vc_stft_t *st);` - *@brief Number of frequency bins (fft_size/2 + 1).*

**Macros:**
- `VC_STFT_H` (line 2) `#define VC_STFT_H`

**Type_Aliases:**
- `vc_stft_t` (line 17) `typedef struct vc_stft_s vc_stft_t;` - *@brief Short-Time Fourier Transform context.  Allocated via vc_stft_create(). Window size and hop size are fixed at creation time. Window size must be a power of 2.*

**Variables:**
- `vc_stft_t` (line 8) `extern "C" { #endif /** * @brief Short-Time Fourier Transform context. * * Allocated via vc_stft_create(). Window size and hop size are fixed * at creation time. Window size must be a power of 2. */ t` - *ifdef __cplusplus*

#### `vc_stream.h`
**Path:** `voicecloak/src/vc_stream.h`
**File Doc:** *ifndef VC_STREAM_H define VC_STREAM_H  include <stddef.h> include <stdint.h>  ifdef __cplusplus*

**Functions:**
- `frames` (line 32) `* that must persist across frames (phase-vocoder accumulators) lives * in @p user, not in the engine. */ typedef void (*vc_spectral_fn)(float *mag, float *phase, size_t nbins, uint32_t sample_rate, si`
- `vc_stream_create` (line 46) `vc_stream_t *vc_stream_create(size_t fft_size, size_t hop_size, uint32_t sample_rate);` - *@brief Create a streaming engine. @param fft_size  Power of two. @param hop_size  Must divide fft_size; fft_size/hop_size in {2,4}. @param sample_rate  Stream sample rate in Hz (> 0). @return Context or NULL on invalid arguments / allocation failure.*
- `vc_stream_destroy` (line 50) `void vc_stream_destroy(vc_stream_t *st);` - *@brief Create a streaming engine. @param fft_size  Power of two. @param hop_size  Must divide fft_size; fft_size/hop_size in {2,4}. @param sample_rate  Stream sample rate in Hz (> 0). @return Context or NULL on invalid arguments / allocation failure.  vc_stream_t *vc_stream_create(size_t fft_size, size_t hop_size, uint32_t sample_rate); /** @brief Release a streaming engine. NULL-safe.*
- `vc_stream_latency_samples` (line 53) `size_t vc_stream_latency_samples(const vc_stream_t *st);` - *@brief Create a streaming engine. @param fft_size  Power of two. @param hop_size  Must divide fft_size; fft_size/hop_size in {2,4}. @param sample_rate  Stream sample rate in Hz (> 0). @return Context or NULL on invalid arguments / allocation failure.  vc_stream_t *vc_stream_create(size_t fft_size, size_t hop_size, uint32_t sample_rate); /** @brief Release a streaming engine. NULL-safe. void vc_stream_destroy(vc_stream_t *st); /** @brief Algorithmic latency in samples (one FFT frame).*
- `vc_stream_process` (line 65) `int vc_stream_process(vc_stream_t *st, const float *in, float *out, size_t n, vc_spectral_fn fn, void *user);` - *@brief Process a block, producing exactly @p n output samples. @param st   Engine. @param in   Input samples (length n). @param out  Output samples (length n). May alias @p in. @param n    Number of samples. @param fn   Spectral transform, or NULL for identity passthrough. @param user Context passed to @p fn. @return 0 on success, -1 on invalid arguments.*

**Macros:**
- `VC_STREAM_H` (line 2) `#define VC_STREAM_H`

**Type_Aliases:**
- `vc_stream_t` (line 20) `typedef struct vc_stream_s vc_stream_t;` - *@brief Streaming STFT overlap-add engine for real-time processing.  Unlike the offline vc_stft, this engine keeps constant sample rate: it emits exactly as many output samples as input samples consumed, which is mandatory for a live audio stream. Analysis hop equals synthesis hop; a per-frame spectral callback modifies magnitude and phase in place. Latency is one FFT frame.*

**Variables:**
- `hop` (line 8) `extern "C" { #endif /** * @brief Streaming STFT overlap-add engine for real-time processing. * * Unlike the offline vc_stft, this engine keeps constant sample rate: * it emits exactly as many output s` - *ifdef __cplusplus*

#### `vc_wav.h`
**Path:** `voicecloak/src/vc_wav.h`
**File Doc:** *ifndef VC_WAV_H define VC_WAV_H  include <stddef.h> include <stdint.h>  ifdef __cplusplus*

**Functions:**
- `vc_wav_read` (line 19) `int vc_wav_read(const char *path, float **samples_out, size_t *num_samples_out, uint32_t *sample_rate_out);` - *@brief Read a mono PCM WAV file into a float buffer [-1.0, 1.0]. @param path         File path. @param samples_out  Output: allocated float array. @param num_samples_out Output: number of samples. @param sample_rate_out Output: sample rate (Hz). @return 0 on success, -1 on error.*
- `vc_wav_write` (line 31) `int vc_wav_write(const char *path, const float *samples, size_t num_samples, uint32_t sample_rate);` - *@brief Write a mono float buffer to a 16-bit PCM WAV file. @param path       File path. @param samples    Float samples in [-1.0, 1.0]. @param num_samples Number of samples. @param sample_rate Sample rate (Hz). @return 0 on success, -1 on error.*

**Macros:**
- `VC_WAV_H` (line 2) `#define VC_WAV_H`

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
