# Legacy

This directory preserves the early reverse-engineering artefacts of the
project. Files here are kept as a historical record of how the project
was bootstrapped from a Python proof-of-concept into the production
C kernel detector in the repository root.

The active code lives at the repository root and under `src/`. The
files in this directory are not built, not tested, and not installed by
`make`, `install.sh`, or `configure`. They are intentionally preserved
in source control so the trail of the reverse-engineering effort and
the evolution of the public API can still be audited.

## Contents

| File                        | Origin and why it was moved here                                                                                       |
| --------------------------- | --------------------------------------------------------------------------------------------------------------------- |
| `app.py`                    | Empty Python stub left over from project bootstrap.                                                                   |
| `build-dkms.sh`             | Alternative DKMS based installer that patches the upstream `snd-usb-audio` kernel module. Superseded by the in-tree `Makefile` + `install.sh` which only registers a passive detector. |
| `main.c`                    | Old C test program for the userspace DSP math library. Superseded by `tests/test_vsl_dsp_logic.c`.                   |
| `mixer_quirks.c`            | Vendored copy of the upstream Linux kernel `sound/usb/mixer_quirks.c` retained for reference of the ALSA mixer dispatch path. Not part of the build. |
| `requirements.txt`          | Python PoC dependencies. The active code is C only.                                                                   |
| `system-prompt-original.md` | The original system prompt that bootstrapped this repository.                                                          |
| `test.sh`                   | Older shell script that mixed USB packet capture and module load testing. Replaced by `tests/test_audiobox_vsl.c` and the CMocka test suite. |
| `test_connection.c`         | Stub C program for the HID transport. Superseded by `src/vsl_dsp_transport.c`.                                        |
| `tree.ini`                  | Old ASCII tree sketch of the Python PoC layout.                                                                        |
| `vsl_capture.pcap`          | Raw USB capture file used during the early reverse engineering phase.                                                 |
| `vsl_official_capture.pcap` | Raw USB capture file from the official driver.                                                                        |
| `vsl_official_complete.pcap`| Raw USB capture file from the official driver (long form).                                                            |
| `vsl_protocol_analysis.txt` | Outdated protocol analysis placeholder. The real protocol is documented in `spec/vsl_dsp_logic.md` and `src/vsl_dsp_logic.c`. |
| `vsl_config.h`              | Predecessor of `audiobox_vsl.h` with hardcoded constants.                                                              |
| `vsl_config.py`             | Python configuration module for the original PoC.                                                                      |
| `vsl_core.py`               | Python implementation of the DSP math.                                                                                |
| `vsl_dsp_logic.c` / `.h`    | Older C copy of the DSP math, kept verbatim from the first C port.                                                    |
| `vsl_dsp_transport.c` / `.h`| Older C copy of the HID transport with hardcoded constants and printf debugging.                                       |
| `vsl_hid_io.py`             | Python HID I/O wrapper for the PoC.                                                                                   |
| `vsl_poc_main.py`           | Main entry point of the original Python PoC.                                                                          |
| `vsl_protocol_analyzer.py`  | Python packet analyser used during the reverse engineering phase.                                                     |
| `vsl_transport.py`          | Python transport abstraction.                                                                                         |
| `workflows/`                | Sample GitHub Actions workflow kept for reference.                                                                    |

## How the project ended up with three supported product IDs

The VID `0x194f` (PreSonus Audio Electronics) covers the whole VSL
family. The original detector only matched the AudioBox 22 VSL
(`0x0101`). The reverse-engineering artefacts in this directory
established that the same UAC2 + HID control plane is shared by the
AudioBox 44 VSL (`0x0102`) and the AudioBox 1818 VSL (`0x0103`).
Adding the two extra product IDs to the device table in
`audiobox_vsl.h` is therefore enough to extend detection to the whole
family; no further protocol work is required at the kernel level.

The DSP control surface (volume, mute, EQ) is owned by the userspace
library in `src/`, which deliberately keeps the legacy Python PoC
out of the build path.
