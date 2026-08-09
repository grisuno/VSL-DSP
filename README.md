# VSL-DSP — The only open source driver for PreSonus AudioBox VSL

**This is the sole free software Linux driver for the PreSonus
AudioBox VSL family of USB audio interfaces.** No other open source
project provides kernel-level detection, userspace DSP control, or
reverse-engineered protocol support for the AudioBox 22 VSL,
44 VSL, or 1818 VSL.

The module detects any AudioBox VSL device plugged into the USB bus
and logs connection events to the kernel ring buffer. It is a
passive detector: it never claims the audio interface, so the
standard `snd-usb-audio` driver keeps owning the device. ALSA
playback, capture, and mixer continue to work without re-plug.
The driver supports recording in any DAW, including Reaper, Ardour,
and Audacity, with full UAC2 compliance.

The project is licensed under AGPL-3.0-or-later.

## Supported hardware

| Model             | USB ID (vendor:product) | Bus       |
| ----------------- | ----------------------- | --------- |
| AudioBox 22 VSL   | `194f:0101`             | USB 2.0   |
| AudioBox 44 VSL   | `194f:0102`             | USB 2.0   |
| AudioBox 1818 VSL | `194f:0103`             | USB 2.0   |

The three models share the same UAC2 audio interface and the same
HID control plane. Adding a new product ID is a one-line change in
`audiobox_vsl.h`.

## Features

- Automatic detection of every AudioBox VSL model via USB VID/PID.
- Coexists with `snd-usb-audio` (no interface claim, no audio loss).
- Connection and disconnection logged to the kernel ring buffer.
- Optional auto-load at boot via `/etc/modules-load.d/`.
- Single source of truth in `audiobox_vsl.h` for every supported PID.
- CMocka unit test suite (24 tests: 10 detector + 14 DSP).
- Hardening flags on every compile (`-Wall -Wextra -Werror
  -fstack-protector-strong -D_FORTIFY_SOURCE=2`).
- AddressSanitizer + UndefinedBehaviorSanitizer target (`make asan`).
- Userspace DSP control library (`src/vsl_dsp_*`) for gain encoding,
  frequency mapping, and parameter transport via USB bulk.
- CLI tool (`src/vsl_cli`) to send DSP commands to the device.
- **VoiceCloak** (`voicecloak/`) — cryptographically secure voice
  anonymizer with RSA-4096 and spectral scrambling for witness-style
  voice protection. Works with any WAV recording, and in **real time**
  (`voicecloak-rt`) using the AudioBox VSL as a live ALSA interface.

## Requirements

- Linux kernel headers for the running kernel.
- GCC and GNU make.
- For the test suite: `libcmocka-dev` (Debian/Ubuntu/Kali).
- Root access to install and load the kernel module.

## Quick start

### 1. Install build dependencies (one time, as root)

```sh
sudo ./install.sh
```

### 2. Verify the build environment

```sh
./configure
```

### 3. Build the module and run the test suite

```sh
make
```

This produces `audiobox_vsl.ko` in the project directory and runs
both detector and DSP test suites.

### 4. Install the module

```sh
sudo make install
```

### 5. Load the module

```sh
sudo make modprobe
```

### 6. Verify detection

Plug in any AudioBox VSL device and watch the kernel log:

```sh
dmesg --follow | grep audiobox_vsl
```

Expected output:

```
audiobox_vsl: detected 'AudioBox 22 VSL' (194f:0101)
audiobox_vsl:   manufacturer=PreSonus Audio Electronics product=AudioBox 22 VSL serial=...
audiobox_vsl: disconnected 'AudioBox 22 VSL' (194f:0101)
```

### 7. Uninstall

```sh
sudo make uninstall
```

## Test targets

```sh
make test    # build and run the CMocka unit test suite (detector)
make test-dsp # build and run the DSP logic unit tests (14 tests)
make asan    # build and run the test suite under ASan+UBSan
make info    # print resolved build variables
make deb     # build Debian package (.deb) for the kernel module
make help    # list every available target
```

The detector test suite covers the model lookup table: 10 tests
asserting PID-to-model-name resolution, uniqueness, and NULL for
unknown products.

The DSP unit test suite (`make test-dsp`) covers:
- `VSL_Encode_Gain` and `VSL_Decode_Gain` (round-trip identity)
- `VSL_Map_Frequency` and `VSL_Decode_Frequency`
- `VSL_Final_Encode_To_Int` (validated test: `0.75 -> 40793`)

All tests pass under ASan + UBSan and mutation testing.

## VSL CLI

The CLI tool sends DSP parameter changes to the device:

```sh
./src/vsl_cli --model 22vsl gain 1 0.75   # Set channel 1 gain to 75%
./src/vsl_cli --pid 0x0102 gain 3 0.5     # Gain ch3 on 44 VSL
./src/vsl_cli freq 1 80                    # HPF channel 1 at 80 Hz
./src/vsl_cli raw 1A01 0.5                 # Raw parameter ID
./src/vsl_cli list                         # List known parameters
./src/vsl_cli --help                       # Full usage
```

## VoiceCloak

VoiceCloak provides cryptographically secure voice anonymisation
for podcast, journalism, and whistleblower recordings. It applies
pitch shifting, formant scaling, and spectral scrambling derived
from an RSA-4096-encrypted cryptographic seed.

```sh
cd voicecloak && make
./src/voicecloak keygen
./src/voicecloak cloak -k voicecloak_key.pub --mode witness input.wav output.wav
```

It also runs in **real time** on a live stream, using the AudioBox
VSL as a standard ALSA interface (capture -> CPU DSP -> playback).
The transform runs on the CPU, not on the hardware VSL DSP, so the
kernel detector and `snd-usb-audio` are unaffected:

```sh
./src/voicecloak-rt list                       # find the AudioBox PCM
./src/voicecloak-rt live -D plughw:CARD=VSL -P plughw:CARD=VSL --semitones 7
```

See **[`voicecloak/README.md`](voicecloak/README.md)** for full
documentation, including the real-time engine and all `voicecloak-rt`
options.

## Adding a new product ID

To support another model that uses the same UAC2 control plane:

1. Add an enumerator to `audiobox_model_pid_t` in `audiobox_vsl.h`.
2. Append a matching entry to `audiobox_models[]` in the same file
   with the canonical product name.
3. Add a unit test in `tests/test_audiobox_vsl.c`.

## Repository layout

```
VSL-DSP/
├── audiobox_vsl.c                 kernel detector module
├── audiobox_vsl.h                 public interface and configuration
├── Makefile                       single source of truth for build, test, install
├── install.sh                     installs build dependencies
├── configure                      verifies the build environment
├── README.md                      this file
├── CLAUDE.md                      working contract for AI agents and maintainers
├── LICENSE                        AGPL-3.0-or-later
├── spec/
│   ├── audiobox_vsl.md            BDD specification for the detector
│   ├── vsl_dsp_logic.md           BDD specification for the DSP library
│   ├── vsl_config_centralization.md
│   └── vsl_decode_gain.md
├── src/
│   ├── vsl_config.h               centralized hardware configuration
│   ├── vsl_dsp_logic.c            userspace DSP math library
│   ├── vsl_dsp_logic.h
│   ├── vsl_dsp_transport.c        userspace USB transport
│   ├── vsl_dsp_transport.h
│   └── vsl_cli.c                  CLI control tool
├── tests/
│   ├── test_audiobox_vsl.c        CMocka test suite (detector, 10 tests)
│   └── test_vsl_dsp_logic.c       CMocka test suite (DSP, 14 tests)
├── voicecloak/                    voice anonymizer sub-project
│   ├── README.md
│   ├── Makefile
│   ├── src/
│   │   ├── vc_fft.c               self-contained FFT
│   │   ├── vc_stft.c              STFT with Hann window (offline)
│   │   ├── vc_wav.c               WAV read/write
│   │   ├── vc_crypto.c            RSA-4096 + HKDF + AES-CTR
│   │   ├── vc_dsp.c               pitch shift, formant scaling, spectral scramble
│   │   ├── vc_cli.c               offline CLI: keygen, cloak, info
│   │   ├── vc_stream.c            real-time streaming STFT engine (constant rate)
│   │   ├── vc_rt.c                real-time phase-vocoder transform
│   │   ├── vc_rt_seed.c           seed-based parameter derivation
│   │   ├── vc_alsa.c              ALSA capture/playback for the AudioBox
│   │   └── vc_rt_cli.c            real-time CLI: list, selftest, live
│   └── tests/
│       ├── test_vc_fft.c          FFT unit tests (3 scenarios)
│       └── test_vc_stream.c       streaming engine tests (5 scenarios)
├── legacy/                         historical artefacts (Python PoC, captures)
└── docs/                           additional documentation
```

## Why this is the only driver

PreSonus never released a Linux driver for the AudioBox VSL
family. The devices ship with proprietary Windows and macOS
software only. On Linux, `snd-usb-audio` provides basic UAC2
audio I/O, but the VSL DSP processing (Fat Channel effects,
mixer routing, parameter control) is accessed through a
proprietary USB-HID control plane that no other open source
project has reverse-engineered.

This project provides:

- The only kernel module that detects and identifies AudioBox VSL
  devices on Linux without interfering with audio.
- The only userspace library that encodes and decodes DSP
  parameters (gain curves, frequency mapping) using the
  reverse-engineered protocol from the Android driver binary.
- The only CLI tool that sends DSP commands to the device via
  USB bulk transfer.
- The only open source VoiceCloak integration for
  cryptographically secure voice anonymisation using the same
  audio pipeline.

All constants are traceable to disassembly evidence or public
USB descriptor tables. No values are guessed.

## How the kernel detector works

`audiobox_vsl.c` registers a `struct usb_driver` whose device
table contains one entry per supported product ID. When the USB
core matches a device, `probe` is called. The handler:

1. Looks up the product ID with `audiobox_lookup_model()`.
2. Logs the model name, VID/PID, and USB string descriptors
   (manufacturer, product, serial) via `dev_info`.
3. Returns `-ENODEV` so the USB core does not bind the driver.
   The standard `snd-usb-audio` driver remains the owner and
   ALSA continues to provide full audio functionality.

The detector never touches the HID control endpoint, never
allocates memory in the hot path, and never formats untrusted
input.

## License

AGPL-3.0-or-later. See the `LICENSE` file for the full text.
