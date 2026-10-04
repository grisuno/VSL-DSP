# VoiceCloak

Cryptographically secure voice anonymizer for the VSL-DSP project.

VoiceCloak applies three non-reversible DSP transformations to a
monophonic WAV recording, each parametrised by a unique 96-byte
cryptographic seed. The seed is encrypted with RSA-4096 and stored
alongside the output. Without the private key the transformation
parameters cannot be recovered. The process is one-way: even
possession of the private key does not enable reversal of the
anonymised audio.

**Warning: this is a proof of concept.** The DSP pipeline has not
been audited against state-of-the-art speaker identification
systems. Do not rely on VoiceCloak for life-critical anonymity
without an independent security assessment.

## Modes

VoiceCloak ships with two operational modes selected via `--mode`:

| Parameter          | `subtle` (default)      | `witness`                          |
|--------------------|-------------------------|------------------------------------|
| Pitch shift        | +/-3 semitones          | +/-10 semitones (near full octave) |
| Formant scaling    | 85-115% (barely audible)| 50-180% (vocal tract deformation)  |
| Spectral scramble  | light phase noise       | aggressive bin permutation in 8 bands + phase randomisation |
| Use case           | podcast anonymisation   | witness-protection-style anonymity |

The witness mode destroys the spectral envelope structure by
permuting frequency bins within logarithmically-spaced bands,
breaking harmonic relationships while preserving broadband energy.
The result is a voice that is clearly different from the original
speaker.

## DSP pipeline

This section describes the offline `cloak` command. The real-time
`voicecloak-rt` path uses a constant-rate streaming variant plus
additional stages; see [Real-time](#real-time-live-voice-changer).

1. **Pitch shift** — phase vocoder with variable synthesis hop.
   Preserves duration while changing perceived pitch.
2. **Formant scaling** — frequency-axis scaling of the magnitude
   spectrum independent of pitch. Shifts vocal tract resonances
   without changing fundamental frequency.
3. **Spectral scrambling** — bin permutation within 8 mel-spaced
   bands plus pseudo-random phase noise. Destroys the harmonic
   structure that speaker identification systems rely on.

All parameters are deterministic for a given seed.

## Cryptographic design

- **Key encapsulation**: RSA-4096 (OpenSSL `EVP_PKEY_encrypt`).
- **Key derivation**: HKDF-SHA256 with info labels
  `voicecloak-pitch`, `voicecloak-formant`, `voicecloak-spectral`.
- **Pseudo-random number generator**: AES-256-CTR, seeded from
  the HKDF output, producing deterministic float values in
  arbitrary ranges.

Kyber-512 hybrid encapsulation is planned as an optional
compile-time feature once `liboqs` integration is complete.

## Usage

```sh
cd voicecloak && make

./src/voicecloak keygen

./src/voicecloak cloak -k voicecloak_key.pub input.wav output.wav

./src/voicecloak cloak -k voicecloak_key.pub --mode witness input.wav output.wav

./src/voicecloak info output.wav
```

- `keygen` produces `voicecloak_key.pub` (public) and
  `voicecloak_key.pem` (private, 4096-bit RSA).
- `cloak` reads a mono WAV (8/16/24/32-bit PCM), generates a
  96-byte random session seed, encrypts it with the public key,
  applies the DSP pipeline, writes a 16-bit anonymised WAV, and
  stores the ciphertext in `output.wav.vc`.
- `info` displays sample count, duration, and sidecar metadata.

## Build

```sh
make        # build voicecloak and voicecloak-rt
make rt     # build only the real-time binary
make test   # run all CMocka suites (29 scenarios)
make asan   # run the suites under ASan + UBSan with leak detection
make clean  # remove build artefacts
```

Requirements:

- C11 compiler (GCC or Clang)
- OpenSSL development headers (`libssl-dev`)
- ALSA development headers (`libasound2-dev`), for `voicecloak-rt`
- CMocka (`libcmocka-dev`), for the test target only

The FFT (`vc_fft.c`) and WAV parser (`vc_wav.c`) are self-contained
implementations with no external library dependencies beyond
`libm`.

## Architecture

```
voicecloak/
├── README.md
├── Makefile
├── src/
│   ├── vc_fft.h           Radix-2 Cooley-Tukey FFT (float, in-place)
│   ├── vc_fft.c
│   ├── vc_stft.h          STFT / ISTFT with Hann window and overlap-add
│   ├── vc_stft.c
│   ├── vc_wav.h           WAV PCM read (8/16/24/32-bit) / write (16-bit)
│   ├── vc_wav.c
│   ├── vc_crypto.h        RSA-4096 keygen/seal/unseal, HKDF, AES-CTR PRNG
│   ├── vc_crypto.c
│   ├── vc_dsp.h           Pitch shift, formant scaling, spectral scramble, cloak()
│   ├── vc_dsp.c
│   ├── vc_cli.c           Offline CLI (keygen, cloak, info)
│   ├── vc_stream.h        Streaming STFT overlap-add engine (constant rate)
│   ├── vc_stream.c
│   ├── vc_rt.h            Real-time phase-vocoder transform (pitch/formant/scramble)
│   ├── vc_rt.c
│   ├── vc_rt_seed.c       Seed-based parameter derivation (HKDF/AES PRNG)
│   ├── vc_effects.h/.c    Ring modulation, filters, delay/reverb, phaser
│   ├── vc_presets.h/.c    Named real-time voice/effect profiles
│   ├── vc_level.h/.c      Smoothed RMS gain and peak limiter
│   ├── vc_audio_config.h  Live sample-rate and inter-stage bounds
│   ├── vc_alsa.h          ALSA capture/playback orchestration
│   ├── vc_alsa.c
│   └── vc_rt_cli.c        Real-time CLI (list, selftest, live)
├── spec/
│   └── voicecloak_realtime.md
└── tests/
    ├── test_vc_fft.c      FFT unit tests (CMocka, 3 scenarios)
    ├── test_vc_stream.c   Streaming tests (CMocka, 8 scenarios)
    ├── test_vc_level.c    RMS/limiter tests (CMocka, 6 scenarios)
    ├── test_vc_effects.c  Stateful effects tests (CMocka, 6 scenarios)
    └── test_vc_presets.c  Presets/live chain tests (CMocka, 6 scenarios)
```

## Real-time (live voice changer)

The original ALSA capture/playback path was verified on an AudioBox 22
VSL (`194f:0101`) at 48 kHz / S32_LE / 2ch. RMS gain, limiting, and the
new named effects pass unit tests, ASan/UBSan, and the synthetic
streaming selftest. Live verification of these newest DSP stages on
physical hardware remains pending.

The offline `cloak` command reads a WAV and writes a WAV. The
`voicecloak-rt` applies pitch shift, formant scaling, spectral scramble,
and optional sample-domain effects to a **live** stream. A smoothed RMS
gain controller compensates for level loss; a peak limiter caps output
at -1 dBFS by default.

Important: the transformation runs on the **CPU** as an ALSA client.
It does **not** run on the AudioBox onboard VSL DSP. That DSP is a
fixed-function mixer (gain, EQ, dynamics, reverb) exposed only through
the HID control plane; it cannot execute a phase vocoder. The VSL HID
driver in the parent repository is not involved in moving audio
samples and is not modified by this feature: `snd-usb-audio` (ALSA)
owns the stream, exactly as required by the project non-interference
doctrine.

Signal path:

```
mic -> AudioBox ADC -> USB -> snd-usb-audio (ALSA capture)
     -> vc_stream / vc_rt (phase vocoder, CPU)
     -> vc_effects (selected voice/effect profile)
     -> vc_level (smoothed RMS gain + peak limiter)
     -> snd-usb-audio (ALSA playback) -> AudioBox DAC -> headphones
```

Unlike the offline engine, the streaming engine keeps a **constant
sample rate** (it emits exactly as many samples as it consumes),
which is mandatory for live audio. Pitch shifting is done in the
frequency domain (analysis hop equals synthesis hop) with per-bin
instantaneous-frequency tracking. Algorithmic latency is one FFT
frame (e.g. `fft=1024`, `hop=256` -> 768 samples, ~16 ms at 48 kHz),
plus ALSA period buffering.

### Usage

```sh
cd voicecloak && make        # builds voicecloak and voicecloak-rt

./src/voicecloak-rt list      # find the AudioBox PCM name (e.g. hw:CARD=VSL)
./src/voicecloak-rt selftest  # verify the engine on a synthetic tone (no device)

# Fixed transform (deterministic):
./src/voicecloak-rt live -D plughw:CARD=VSL -P plughw:CARD=VSL --semitones 7 --formant 1.3

# Random transform within a mode's ranges:
./src/voicecloak-rt live -D plughw:CARD=VSL -P plughw:CARD=VSL --mode witness

# Deterministic named effects:
./src/voicecloak-rt live -D plughw:CARD=VSL -P plughw:CARD=VSL --preset robot
./src/voicecloak-rt live -D plughw:CARD=VSL -P plughw:CARD=VSL --preset church
```

`live` negotiates rate, format, and channel count from the device
(nothing hardcoded), processes channel 0, and writes the result to
all playback channels. Stop with Ctrl-C. `plughw:` is recommended so
ALSA handles any needed format/rate conversion.

Options: `--mode subtle|witness`, `--preset NAME`, `--semitones N`
(-24..24), `--formant F`, `--scramble S`, `--fft N`, `--hop N`, `--rate R`,
`--channels C`, `--period P`, `--target-dbfs DB`, `--max-gain-db DB`,
`--ceiling-dbfs DB`, `--attack-ms MS`, `--release-ms MS`,
`--limiter-release-ms MS`, and `--no-agc`. Any of
`--semitones/--formant/--scramble` selects a fixed deterministic
transform; otherwise a random session seed is drawn within the selected
mode's ranges (same ranges as offline `cloak`). `--preset` chooses a
deterministic profile and cannot be combined with those voice options.
Numeric values are parsed strictly; out-of-range values and unknown
preset names are rejected instead of being silently clamped.

### Named profiles

| Profile      | Voice transform                | Sample-domain effect              |
|--------------|--------------------------------|-----------------------------------|
| `robot`      | neutral pitch, light scramble  | 42 Hz ring modulation             |
| `monster`    | -8 semitones, 0.78x formant    | none                              |
| `woman`      | +5 semitones, 1.15x formant    | none                              |
| `man`        | -3 semitones, 0.90x formant    | none                              |
| `space`      | +2 semitones, 1.05x formant    | modulated delay (24 ms / 8 ms)    |
| `underwater` | -1 semitone, 0.82x formant    | 900 Hz low-pass                   |
| `church`     | neutral, light scramble        | reverb, 2.4 s decay               |
| `phaser`     | +1 semitone                    | 6 modulated all-pass stages       |

These are stylized starting points for voice and effect character, not
measurements of how any real speaker sounds. Results vary with the
speaker, microphone, and room. All values live in one table in
`src/vc_presets.c`; adding a profile is one table entry plus a unit
test.

### Level control

Spectral scrambling loses level: aggressive scramble makes overlap-add
sum powers instead of amplitudes and costs roughly 7 dB. The live chain
compensates for that with two stages, both configurable:

| Control        | CLI flag                 | Make variable           | Default |
|----------------|--------------------------|-------------------------|---------|
| RMS target     | `--target-dbfs`          | `VC_TARGET_DBFS`        | `-18`   |
| Maximum gain   | `--max-gain-db`          | `VC_MAX_GAIN_DB`        | `12`    |
| Peak ceiling   | `--ceiling-dbfs`         | `VC_CEILING_DBFS`       | `-1`    |
| AGC attack     | `--attack-ms`            | `VC_ATTACK_MS`          | `10`    |
| AGC release    | `--release-ms`           | `VC_RELEASE_MS`         | `250`   |
| Limiter release| `--limiter-release-ms`   | `VC_LIMITER_RELEASE_MS` | `50`    |
| AGC switch     | `--no-agc`               | `VC_AGC=0`              | `1`     |

The AGC gain follows a smoothed RMS estimate and is capped at the
maximum gain, so quiet input is boosted only up to that limit and the
output is intentionally quieter rather than amplified without bound.
The peak limiter attenuates transients immediately and releases over
the limiter release time, keeping every sample under the ceiling
instead of hard-clipping at 0 dBFS. Digital silence stays silent.
`--no-agc` (or `VC_AGC=0`) disables the gain stage and keeps the
limiter. These levels are VoiceCloak product defaults, not values
recovered from the Android driver.

The offline `cloak` command is unaffected: it already normalises its
output RMS inside `vc_dsp_cloak`.

The real-time binary requires the ALSA development headers
(`libasound2-dev`) in addition to the offline requirements. Build it
alone with `make rt`.

### Streaming with OBS

An ALSA `hw:`/`plughw:` device can be opened by one application at a
time. If `voicecloak-rt` holds the AudioBox, OBS cannot open it too
(`Device busy`), and vice versa. The fix is routing: OBS must never
open the AudioBox directly. Only `voicecloak-rt` captures from the
hardware; it emits the processed voice to a virtual device, and OBS
uses that virtual device as its microphone. That way OBS receives the
distorted voice, not the clean one.

Pick exactly one route:

#### Route A: PulseAudio / PipeWire (`make pulse`, recommended)

Requirements: `pactl` (`pulseaudio-utils` or `pipewire-pulse`).

```sh
cd voicecloak && make pulse
# equivalent manual form:
#   pactl load-module module-null-sink sink_name=vc_out sink_properties=device.description=VoiceCloak
#   PULSE_SINK=vc_out ./src/voicecloak-rt live -D plughw:CARD=VSL -P pulse --mode witness

# Named profile; shorthand `make pulse-robot` is equivalent:
make pulse VC_PRESET=robot
make pulse VC_PRESET=woman VC_TARGET_DBFS=-20
```

OBS configuration:

1. Sources -> Add -> Audio Input Capture (PulseAudio).
2. Select `Monitor of VoiceCloak` (`Monitor of vc_out`) as the device.
3. Do not add the AudioBox as a source in any scene.

To hear yourself, set that source to `Monitor and Output` in
Advanced Audio Properties and route OBS monitoring to the AudioBox
headphones.

#### Route B: pure ALSA loopback (`make alsa`)

Requirements: `alsa-utils`, permission to run `sudo modprobe snd-aloop`.

```sh
cd voicecloak && make alsa
# equivalent manual form:
#   sudo modprobe snd-aloop index=1
#   ./src/voicecloak-rt live -D plughw:CARD=VSL -P hw:Loopback,0,0 --mode witness

# Named profile:
make alsa-church
```

OBS configuration:

1. Sources -> Add -> Audio Input Capture (ALSA).
2. Select `hw:Loopback,1,0` as the device.
3. Do not add the AudioBox as a source in any scene.

`make setup-pulse` and `make setup-alsa` prepare only the virtual
device without starting `live`. All routes accept the same overrides
without editing files:

```sh
make pulse VC_MODE=subtle
make pulse VC_EXTRA="--semitones 7 --formant 1.3"
make pulse VC_PRESET=space VC_TARGET_DBFS=-20 VC_MAX_GAIN_DB=10
make pulse-underwater
make alsa-phaser
make alsa VSL_CAPTURE=hw:CARD=VSL ALOOP_PB=hw:Loopback,0,0
make help  # full variable list
make test
make asan
```

| Variable      | Default            | Meaning                                  |
|---------------|--------------------|------------------------------------------|
| `VSL_CAPTURE` | `plughw:CARD=VSL`  | ALSA capture device (the AudioBox)       |
| `PULSE_SINK`  | `vc_out`           | Null-sink name OBS monitors (route A)    |
| `PULSE_PCM`   | `pulse`            | ALSA PCM used for Pulse/PipeWire output  |
| `ALOOP_PB`    | `hw:Loopback,0,0`  | Loopback endpoint voicecloak writes (B)  |
| `ALOOP_CAP`   | `hw:Loopback,1,0`  | Loopback endpoint OBS reads (route B)    |
| `VC_MODE`     | `witness`          | `subtle` or `witness`                    |
| `VC_PRESET`   | `cloak`            | `cloak` or one of the eight named profiles |
| `VC_AGC`      | `1`                | `1` enables RMS gain; `0` disables it (limiter stays on) |
| `VC_TARGET_DBFS` | `-18`            | RMS target level                         |
| `VC_MAX_GAIN_DB` | `12`             | Maximum RMS compensation                 |
| `VC_CEILING_DBFS` | `-1`            | Peak limiter ceiling                     |
| `VC_ATTACK_MS` / `VC_RELEASE_MS` | `10` / `250` | RMS gain smoothing times          |
| `VC_LIMITER_RELEASE_MS` | `50`      | Limiter release time                     |
| `VC_RATE` / `VC_CHANNELS` / `VC_PERIOD` / `VC_FFT` / `VC_HOP` | `48000` / `2` / `256` / `1024` / `256` | Stream parameters |
| `VC_EXTRA`    | empty              | Extra `live` flags, e.g. fixed transform |

## License

AGPL-3.0-or-later. See the parent project LICENSE file.
