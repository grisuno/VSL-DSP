# VSL-DSP API Reference

> Generated offline by readmenator: 58 modules, 643 documented entities, documentation coverage 39.9% (242/606 public items). Deterministic, zero tokens: signatures from source, docs parsed from Google, NumPy, reST, Javadoc/JSDoc/Doxygen, C# XML, and Rustdoc comments.

Navigate: [Interactive architecture and flows](flows.html) | [Architecture and flows (Mermaid)](architecture.md) | [Class hierarchy](classes.md) | [General index](genindex.md) | [Coverage and warnings](COVERAGE.md) | [`api/index.json`](api/index.json) | [HTML browser](index.html)

Languages: c (26), h (23), py (7), sh (2)

## Modules

### `.`

| Module | Summary | Types | Callables | Coverage |
|---|---|---|---|---|
| [`audiobox_vsl.c`](modules/audiobox_vsl.c.md) | SPDX-License-Identifier: GPL-2.0-or-later | 0 | 3 | 25.0% |
| [`audiobox_vsl.h`](modules/audiobox_vsl.h.md) | SPDX-License-Identifier: GPL-2.0-or-later | 2 | 5 | 50.0% |
| [`install.sh`](modules/install.sh.md) | SPDX-License-Identifier: GPL-2.0-or-later Thin wrapper that installs the build-time dependencies for the audiobox_vsl kernel module. | 0 | 0 | 100.0% |

### `avatar`

| Module | Summary | Types | Callables | Coverage |
|---|---|---|---|---|
| [`avatar/avatar_config.h`](modules/avatar.avatar_config.h.md) |  | 0 | 12 | 0.0% |
| [`avatar/avatar_logic.c`](modules/avatar.avatar_logic.c.md) |  | 0 | 8 | 88.9% |
| [`avatar/avatar_logic.h`](modules/avatar.avatar_logic.h.md) |  | 2 | 8 | 90.9% |
| [`avatar/avatar_main.c`](modules/avatar.avatar_main.c.md) |  | 0 | 1 | 0.0% |

### `legacy`

| Module | Summary | Types | Callables | Coverage |
|---|---|---|---|---|
| [`legacy.app`](modules/legacy.app.py.md) | app.py | 0 | 0 | 100.0% |
| [`legacy/build-dkms.sh`](modules/legacy.build-dkms.sh.md) | AudioBox 22 VSL Enhanced Driver - Installation Script Copyright (c) 2025 grisuno (LazyOwn Project) License: GPL-2.0-or-later This script installs enhanced ALSA... | 0 | 19 | 5.0% |
| [`legacy/main.c`](modules/legacy.main.c.md) |  | 0 | 1 | 0.0% |
| [`legacy/mixer_quirks.c`](modules/legacy.mixer_quirks.c.md) | SPDX-License-Identifier: GPL-2.0-or-later | 6 | 141 | 5.4% |
| [`legacy/vsl_config.h`](modules/legacy.vsl_config.h.md) | vsl_config.h (VERSION CORREGIDA) ======================================================= BLOQUEADORES CRÍTICOS (Hardware)... | 0 | 7 | 62.5% |
| [`legacy.vsl_config`](modules/legacy.vsl_config.py.md) | VSL-DSP Configuration Module Contiene todas las constantes y configuraciones del protocolo. | 1 | 2 | 100.0% |
| [`legacy.vsl_core`](modules/legacy.vsl_core.py.md) | VSL-DSP Core Logic Module Implementa las funciones matemáticas de encoding/decoding. | 0 | 5 | 100.0% |
| [`legacy/vsl_dsp_logic.c`](modules/legacy.vsl_dsp_logic.c.md) |  | 0 | 5 | 83.3% |
| [`legacy/vsl_dsp_logic.h`](modules/legacy.vsl_dsp_logic.h.md) |  | 1 | 5 | 85.7% |
| [`legacy/vsl_dsp_transport.c`](modules/legacy.vsl_dsp_transport.c.md) | vsl_dsp_transport.c (Añadir la Plantilla B completa aquí) Handle de Singleton (Regla #5: Diseño Escalable) | 0 | 5 | 83.3% |
| [`legacy/vsl_dsp_transport.h`](modules/legacy.vsl_dsp_transport.h.md) | vsl_dsp_transport.h (CORREGIDO) Estructura de Paquete: Sin 'header' (lo quitaste en la estructura typedef) | 1 | 5 | 71.4% |
| [`legacy.vsl_hid_io`](modules/legacy.vsl_hid_io.py.md) | VSL-DSP HID I/O Module (OPCIONAL) Comunicación real con hardware via hidapi. | 1 | 8 | 80.0% |
| [`legacy.vsl_poc_main`](modules/legacy.vsl_poc_main.py.md) | VSL-DSP Proof of Concept - Main Program Programa principal de pruebas y validación. | 0 | 7 | 100.0% |
| [`legacy.vsl_protocol_analyzer`](modules/legacy.vsl_protocol_analyzer.py.md) | PASO 1: (Fuera de este entorno) Capturar tráfico USB con Wireshark/usbmon Guardar como: audiobox_full_sweep.pcap PASO 2: Ejecutar el analizador python3... | 1 | 6 | 87.5% |
| [`legacy.vsl_transport`](modules/legacy.vsl_transport.py.md) | VSL-DSP Transport Module Construcción y validación de paquetes HID. | 1 | 5 | 100.0% |

### `src`

| Module | Summary | Types | Callables | Coverage |
|---|---|---|---|---|
| [`src/vsl_cli.c`](modules/src.vsl_cli.c.md) |  | 1 | 4 | 0.0% |
| [`src/vsl_config.h`](modules/src.vsl_config.h.md) |  | 1 | 11 | 15.4% |
| [`src/vsl_dsp_logic.c`](modules/src.vsl_dsp_logic.c.md) |  | 0 | 7 | 75.0% |
| [`src/vsl_dsp_logic.h`](modules/src.vsl_dsp_logic.h.md) |  | 1 | 11 | 61.5% |
| [`src/vsl_dsp_transport.c`](modules/src.vsl_dsp_transport.c.md) |  | 1 | 5 | 71.4% |
| [`src/vsl_dsp_transport.h`](modules/src.vsl_dsp_transport.h.md) |  | 1 | 5 | 71.4% |

### `voicecloak/src`

| Module | Summary | Types | Callables | Coverage |
|---|---|---|---|---|
| [`voicecloak/src/vc_alsa.c`](modules/voicecloak.src.vc_alsa.c.md) |  | 1 | 3 | 40.0% |
| [`voicecloak/src/vc_alsa.h`](modules/voicecloak.src.vc_alsa.h.md) |  | 1 | 3 | 60.0% |
| [`voicecloak/src/vc_audio_config.h`](modules/voicecloak.src.vc_audio_config.h.md) |  | 0 | 12 | 15.4% |
| [`voicecloak/src/vc_cli.c`](modules/voicecloak.src.vc_cli.c.md) |  | 0 | 1 | 0.0% |
| [`voicecloak/src/vc_crypto.c`](modules/voicecloak.src.vc_crypto.c.md) |  | 1 | 8 | 90.0% |
| [`voicecloak/src/vc_crypto.h`](modules/voicecloak.src.vc_crypto.h.md) |  | 1 | 14 | 56.2% |
| [`voicecloak/src/vc_denoise.c`](modules/voicecloak.src.vc_denoise.c.md) |  | 1 | 10 | 58.3% |
| [`voicecloak/src/vc_denoise.h`](modules/voicecloak.src.vc_denoise.h.md) |  | 2 | 25 | 28.6% |
| [`voicecloak/src/vc_dsp.c`](modules/voicecloak.src.vc_dsp.c.md) |  | 0 | 6 | 0.0% |
| [`voicecloak/src/vc_dsp.h`](modules/voicecloak.src.vc_dsp.h.md) |  | 0 | 4 | 0.0% |
| [`voicecloak/src/vc_effects.c`](modules/voicecloak.src.vc_effects.c.md) |  | 2 | 12 | 20.0% |
| [`voicecloak/src/vc_effects.h`](modules/voicecloak.src.vc_effects.h.md) |  | 2 | 5 | 50.0% |
| [`voicecloak/src/vc_eq.c`](modules/voicecloak.src.vc_eq.c.md) |  | 2 | 5 | 37.5% |
| [`voicecloak/src/vc_eq.h`](modules/voicecloak.src.vc_eq.h.md) |  | 2 | 6 | 44.4% |
| [`voicecloak/src/vc_fft.c`](modules/voicecloak.src.vc_fft.c.md) |  | 0 | 2 | 0.0% |
| [`voicecloak/src/vc_fft.h`](modules/voicecloak.src.vc_fft.h.md) |  | 0 | 1 | 0.0% |
| [`voicecloak/src/vc_level.c`](modules/voicecloak.src.vc_level.c.md) |  | 1 | 5 | 71.4% |
| [`voicecloak/src/vc_level.h`](modules/voicecloak.src.vc_level.h.md) |  | 2 | 12 | 40.0% |
| [`voicecloak/src/vc_presets.c`](modules/voicecloak.src.vc_presets.c.md) |  | 1 | 2 | 25.0% |
| [`voicecloak/src/vc_presets.h`](modules/voicecloak.src.vc_presets.h.md) |  | 1 | 1 | 66.7% |
| [`voicecloak/src/vc_rt.c`](modules/voicecloak.src.vc_rt.c.md) |  | 1 | 7 | 55.6% |
| [`voicecloak/src/vc_rt.h`](modules/voicecloak.src.vc_rt.h.md) |  | 2 | 13 | 50.0% |
| [`voicecloak/src/vc_rt_cli.c`](modules/voicecloak.src.vc_rt_cli.c.md) |  | 0 | 3 | 0.0% |
| [`voicecloak/src/vc_rt_seed.c`](modules/voicecloak.src.vc_rt_seed.c.md) |  | 0 | 1 | 50.0% |
| [`voicecloak/src/vc_stft.c`](modules/voicecloak.src.vc_stft.c.md) |  | 1 | 7 | 66.7% |
| [`voicecloak/src/vc_stft.h`](modules/voicecloak.src.vc_stft.h.md) |  | 1 | 6 | 87.5% |
| [`voicecloak/src/vc_stream.c`](modules/voicecloak.src.vc_stream.c.md) |  | 1 | 8 | 70.0% |
| [`voicecloak/src/vc_stream.h`](modules/voicecloak.src.vc_stream.h.md) |  | 2 | 9 | 75.0% |
| [`voicecloak/src/vc_wav.c`](modules/voicecloak.src.vc_wav.c.md) |  | 3 | 2 | 50.0% |
| [`voicecloak/src/vc_wav.h`](modules/voicecloak.src.vc_wav.h.md) |  | 0 | 2 | 66.7% |
