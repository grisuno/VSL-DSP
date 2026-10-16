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

The project is licensed under GPL-3.0-or-later (see `LICENSE`).
The kernel detector sources carry a GPL-2.0-or-later SPDX header
for compatibility with the Linux kernel module licensing.

## Supported hardware

| Model             | USB ID (vendor:product) | Bus       |
| ----------------- | ----------------------- | --------- |
| AudioBox 22 VSL   | `194f:0101`             | USB 2.0   |
| AudioBox 44 VSL   | `194f:0102`             | USB 2.0   |
| AudioBox 1818 VSL | `194f:0103`             | USB 2.0   |

The three models share the same UAC2 audio interface and the same
USB bulk control plane (MIDI interface; the device exposes no HID
interface). Adding a new product ID is a one-line change in
`audiobox_vsl.h`.

## Reverse engineering with [LazyOwn](https://github.com/grisuno/LazyOwn) and REA

The vendor reference findings behind the DSP improvements below
were obtained with the [LazyOwn](https://github.com/grisuno/LazyOwn) RedTeam Framework and its `rea`
lazyaddon, which drives REA (Reverse Engineer Anything) with
Ghidra 12.1.4 against the vendor control application libraries.

Verified findings, each with a REA evidence envelope:

- The application is PreSonus Universal Control: `libucnet.so`
  implements UCNET discovery over UDP (bind `INADDR_ANY:47809`,
  alive/leave/query/timeout session events) with mDNS peer
  discovery and a TCP control channel. See
  `spec/ucnet_discovery.md`.
- `libfatchannelplugins.so` builds a static parameter registry
  (`_INIT_0`) of `{handler, name, channel_index, flags}` entries.
  The `gain.db` / `gain.N` / `db.inf` split showed that decibel
  gain and negative infinity are separate domains with dedicated
  handlers, not points on one curve. See
  `spec/fatchannel_registry.md`.

Improvements derived from these findings:

- `vsl_cli db <ch> <dB>` command and `db1`/`db2` table entries
  following the vendor `gain.db` naming.
- `VSL_Linear_To_DB` / `VSL_DB_To_Linear` converters with the vendor
  floor (`VSL_DB_NEG_INF = -144.0 dB`, linear `6.309573e-08`, from
  `FUN_0011ccfc`/`FUN_0011f5b8`), covered by CMocka tests.
- The vendor mute wire code was not recovered, so no mute code
  is invented: a non-finite `-inf` CLI input maps to linear `0.0`
  explicitly and is documented as not-a-mute.

Thanks to the REA project (https://github.com/morluto/rea) for
the open source reverse engineering workflow that made this
analysis possible.

## Features

- Automatic detection of every AudioBox VSL model via USB VID/PID.
- Coexists with `snd-usb-audio` (no interface claim, no audio loss).
- Connection and disconnection logged to the kernel ring buffer.
- Optional auto-load at boot via `/etc/modules-load.d/`.
- Single source of truth in `audiobox_vsl.h` for every supported PID.
- CMocka unit test suite (34 tests: 12 detector + 17 DSP + 5 transport).
- Hardening flags on every compile (`-Wall -Wextra -Werror
  -fstack-protector-strong -D_FORTIFY_SOURCE=2`).
- AddressSanitizer + UndefinedBehaviorSanitizer target (`make asan`).
- Userspace DSP control library (`src/vsl_dsp_*`) for gain encoding,
  frequency mapping, and parameter transport via USB bulk.
- CLI tool (`src/vsl_cli`) to send DSP commands to the device.
- **VoiceCloak** (`voicecloak/`) — cryptographically secure voice
  anonymizer with RSA-4096 and spectral scrambling for witness-style
  voice protection. Works with any WAV recording, and in **real time**
  (`voicecloak-rt`) using the AudioBox VSL as a live ALSA interface,
  with noise reduction (learned noise print), a presence equalizer,
  smoothed RMS gain, soft saturation, a peak limiter, and
  robot/monster/woman/man/space/underwater/church/phaser presets for
  OBS.

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
make test-dsp # build and run the DSP logic unit tests (17 tests)
make test-transport # build and run the DSP transport unit tests (5 tests)
make asan    # build and run the test suite under ASan+UBSan
make info    # print resolved build variables
make deb     # build Debian package (.deb) for the kernel module
make help    # list every available target
```

The detector test suite covers the model lookup table: 12 tests
asserting PID-to-model-name resolution, uniqueness, and NULL for
unknown products.

The DSP unit test suite (`make test-dsp`) covers:
- `VSL_Encode_Gain` and `VSL_Decode_Gain` (round-trip identity)
- `VSL_Map_Frequency` and `VSL_Decode_Frequency`
- `VSL_Final_Encode_To_Int` (validated test: `0.75 -> 40793`)

The transport unit test suite (`make test-transport`) covers the pure
`VSL_Build_Packet` datagram builder (layout, zero/max values, NULL
fail-closed) and the NULL-handle `VSL_Send_Parameter` guard. The bulk
I/O path itself needs hardware fault injection (Phase 5).

All tests pass under ASan + UBSan and mutation testing.

## VSL CLI

The CLI tool sends DSP parameter changes to the device:

```sh
./src/vsl_cli --model 22vsl gain 1 0.75   # Set channel 1 gain to 75%
./src/vsl_cli --pid 0x0102 gain 3 0.5     # Gain ch3 on 44 VSL
./src/vsl_cli db 1 -6.0                   # Gain ch1 at -6 dB (Fat Channel gain.db)
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
make -C voicecloak pulse-robot                 # route processed mic into OBS
make -C voicecloak pulse-robot VC_NOISE_SAVE=room.vcn     # learn the noise print once
make -C voicecloak pulse-robot VC_NOISE_PROFILE=room.vcn  # reuse it, no pause
```

The live chain is noise reduction -> phase vocoder -> named effect ->
presence equalizer -> smoothed RMS gain -> soft saturation -> peak
limiter. Noise reduction learns a noise print while you stay silent
for about 1.5 s at start (or loads a saved one), subtracts it from
every frame, and gates frames that hold only noise, so the background
hiss is not turned into a robot buzz and boosted by the AGC (about
42 dB less noise in the unit tests). The gain stage compensates for
the level lost to spectral scrambling (up to a bounded maximum boost)
and the limiter keeps peaks under the configured ceiling instead of
clipping. The `robot` profile robotizes the voice (pitch locked to
`rate / hop`, 187.5 Hz by default) and adds a metallic comb, a light
ring modulation, a presence boost, and soft saturation. Named
profiles (`robot`, `monster`, `woman`, `man`, `space`, `underwater`,
`church`, `phaser`) are selectable from the CLI with `--preset` and
from the Makefile with `VC_PRESET=` or the `pulse-<preset>` and
`alsa-<preset>` shortcuts. Level defaults are `-18 dBFS` target RMS,
`+12 dB` maximum gain, `-1 dBFS` ceiling.

See **[`voicecloak/README.md`](voicecloak/README.md)** for full
documentation, including the real-time engine, the robot voice, noise
reduction, the level controls, and all `voicecloak-rt` options and
Make variables.

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
├── LICENSE                        GPL-3.0-or-later (kernel sources: GPL-2.0-or-later SPDX)
├── spec/
│   ├── audiobox_vsl.md            BDD specification for the detector
│   ├── vsl_dsp_logic.md           BDD specification for the DSP library
│   ├── vsl_dsp_transport.md       BDD specification for the USB transport
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
│   ├── test_audiobox_vsl.c        CMocka test suite (detector, 12 tests)
│   ├── test_vsl_dsp_logic.c       CMocka test suite (DSP, 17 tests)
│   └── test_vsl_dsp_transport.c   CMocka test suite (transport, 5 tests)
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
│   │   ├── vc_stream.c            real-time streaming STFT engine + spectral chain
│   │   ├── vc_denoise.c           noise print, spectral subtraction, spectral gate
│   │   ├── vc_rt.c                real-time phase vocoder (pitch/formant/scramble/robotize)
│   │   ├── vc_rt_seed.c           seed-based parameter derivation
│   │   ├── vc_effects.c           ring mod, metallic comb, filters, delay/reverb, phaser
│   │   ├── vc_eq.c                high-pass + presence peaking equalizer
│   │   ├── vc_presets.c           named voice/effect profiles
│   │   ├── vc_level.c             smoothed RMS gain, soft saturation, peak limiter
│   │   ├── vc_audio_config.h      live sample-rate and inter-stage bounds
│   │   ├── vc_alsa.c              ALSA capture/playback for the AudioBox
│   │   └── vc_rt_cli.c            real-time CLI: list, selftest, live
│   └── tests/
│       ├── test_vc_fft.c          FFT unit tests (3 scenarios)
│       ├── test_vc_stream.c       streaming, robotize, chain tests (11 scenarios)
│       ├── test_vc_level.c        RMS gain, saturation, limiter tests (9 scenarios)
│       ├── test_vc_effects.c      stateful effect tests (10 scenarios)
│       ├── test_vc_eq.c           equalizer tests (5 scenarios)
│       ├── test_vc_denoise.c      noise reduction tests (9 scenarios)
│       └── test_vc_presets.c      presets and live chain tests (8 scenarios)
├── legacy/                         historical artefacts (Python PoC, captures)
└── docs/                           additional documentation
```

## Why this is the only driver

PreSonus never released a Linux driver for the AudioBox VSL
family. The devices ship with proprietary Windows and macOS
software only. On Linux, `snd-usb-audio` provides basic UAC2
audio I/O, but the VSL DSP processing (Fat Channel effects,
mixer routing, parameter control) is accessed through a
proprietary USB bulk control plane on the MIDI interface (no HID
interface on the device) that no other open source
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
2. Logs the canonical model name and VID/PID via `dev_info`,
   once per plug (interface 0 only). Raw USB string descriptors
   are never logged.
3. Returns `-ENODEV` so the USB core does not bind the driver.
   The standard `snd-usb-audio` driver remains the owner and
   ALSA continues to provide full audio functionality.

The detector never touches the DSP bulk endpoint, never
allocates memory in the hot path, and never formats untrusted
input.

## License

GPL-3.0-or-later. See the `LICENSE` file for the full text.
The kernel detector files use GPL-2.0-or-later SPDX headers
so the module stays compatible with the Linux kernel.

<!-- readmenator-kb-link -->
## Knowledge Base

This project has been analyzed by [ReadMenator](https://github.com/grisuno/ReadMenator),
a zero-token polyglot static analysis tool. Analysis outputs are available:

- **[KNOWLEDGE_BASE.md](./KNOWLEDGE_BASE.md)** -- Full architecture reference with all
  classes, functions, imports, dependency graphs, UML class diagrams, security
  audit findings, community analysis, and more.
- **[readmenator-agent/](./readmenator-agent/)** -- Agent-friendly, grep-optimized index.
  - `INDEX.md` -- Quick reference: what each file does
  - `API.md` -- Public function contracts
  - `GOTCHAS.md` -- Change warnings
  - `SECURITY.md` -- Findings by severity
- **[readmenator-wiki/](./readmenator-wiki/)** -- Navigable wiki (start here for the big picture).
  - `index.md` -- Entry point: overview, reading order, god nodes, connections
  - `community_*.md` -- One synthesis page per code community
  - `REPORT.md` -- Honest audit: coverage, confidence, limits

AI agents: Read `readmenator-wiki/index.md` first for the big picture, then `readmenator-agent/INDEX.md` for grep-friendly lookup.
Developers: Read `KNOWLEDGE_BASE.md` for full architecture reference.
<!-- /readmenator-kb-link -->

