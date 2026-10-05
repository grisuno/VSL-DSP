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
make test   # run all CMocka suites (7 suites, 55 scenarios)
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
│   ├── vc_stream.h        Streaming STFT overlap-add engine (constant rate) + spectral chain
│   ├── vc_stream.c
│   ├── vc_rt.h            Real-time phase-vocoder transform (pitch/formant/scramble/robotize)
│   ├── vc_rt.c
│   ├── vc_rt_seed.c       Seed-based parameter derivation (HKDF/AES PRNG)
│   ├── vc_denoise.h/.c    Noise print, spectral subtraction, spectral gate, profile files
│   ├── vc_effects.h/.c    Ring modulation, metallic comb, filters, delay/reverb, phaser
│   ├── vc_eq.h/.c         High-pass + presence peaking equalizer (RBJ biquads)
│   ├── vc_presets.h/.c    Named real-time voice/effect profiles
│   ├── vc_level.h/.c      Smoothed RMS gain, soft saturation, peak limiter
│   ├── vc_audio_config.h  Live sample-rate and inter-stage bounds
│   ├── vc_alsa.h          ALSA capture/playback orchestration
│   ├── vc_alsa.c
│   └── vc_rt_cli.c        Real-time CLI (list, selftest, live)
├── spec/
│   └── voicecloak_realtime.md
└── tests/
    ├── test_vc_fft.c      FFT unit tests (CMocka, 3 scenarios)
    ├── test_vc_stream.c   Streaming/robotize/chain tests (CMocka, 11 scenarios)
    ├── test_vc_level.c    RMS/saturation/limiter tests (CMocka, 9 scenarios)
    ├── test_vc_effects.c  Stateful effects tests (CMocka, 10 scenarios)
    ├── test_vc_eq.c       Equalizer tests (CMocka, 5 scenarios)
    ├── test_vc_denoise.c  Noise reduction tests (CMocka, 9 scenarios)
    └── test_vc_presets.c  Presets/live chain tests (CMocka, 8 scenarios)
```

## Real-time (live voice changer)

The original ALSA capture/playback path was verified on an AudioBox 22
VSL (`194f:0101`) at 48 kHz / S32_LE / 2ch, and the robot preset was
listened to on that device. The newest stages (noise reduction, the
robot clarity chain) pass unit tests, ASan/UBSan, fuzzing, and the
synthetic streaming selftest; a listening check of the noise reduction
on physical hardware is still pending.

The offline `cloak` command reads a WAV and writes a WAV. The
`voicecloak-rt` applies noise reduction, pitch shift, formant scaling,
spectral scramble or robotization, and optional sample-domain effects
to a **live** stream. An equalizer adds clarity, a smoothed RMS gain
controller compensates for level loss, an optional soft saturation
adds loudness, and a peak limiter caps output at -1 dBFS by default.

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
     -> vc_stream (streaming STFT, CPU), spectral chain per frame:
          vc_denoise (noise print subtraction + gate, optional)
          -> vc_rt   (pitch / formant / scramble / robotize)
     -> vc_effects (selected voice/effect profile)
     -> vc_eq      (high-pass + presence peak, robot preset)
     -> vc_level   (smoothed RMS gain -> soft saturation -> peak limiter)
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

# Robot without background hum: stay silent ~1.5 s at start
./src/voicecloak-rt live -D plughw:CARD=VSL -P plughw:CARD=VSL --preset robot --denoise
```

`live` negotiates rate, format, and channel count from the device
(nothing hardcoded), processes channel 0, and writes the result to
all playback channels. Stop with Ctrl-C. `plughw:` is recommended so
ALSA handles any needed format/rate conversion.

All `live` options:

| Group | Options |
|-------|---------|
| Devices and stream | `-D DEV`, `-P DEV`, `--rate R`, `--channels C`, `--period P`, `--fft N`, `--hop N` |
| Voice transform | `--mode subtle\|witness`, `--preset NAME`, `--semitones N` (-24..24), `--formant F` (0.3-3), `--scramble S` (0-1) |
| Level | `--target-dbfs DB`, `--max-gain-db DB`, `--ceiling-dbfs DB`, `--attack-ms MS`, `--release-ms MS`, `--limiter-release-ms MS`, `--no-agc`, `--drive D` (0-8) |
| Ring modulation | `--ring-amount A` (0-1), `--ring-hz F`, `--ring-wave sine\|square` |
| Noise reduction | `--denoise`, `--noise-learn-ms MS`, `--noise-profile FILE`, `--noise-save FILE`, `--noise-reduction R`, `--noise-floor-db DB`, `--noise-gate-snr-db DB`, `--noise-gate-range-db DB` |

Any of
`--semitones/--formant/--scramble` selects a fixed deterministic
transform; otherwise a random session seed is drawn within the selected
mode's ranges (same ranges as offline `cloak`). `--preset` chooses a
deterministic profile and cannot be combined with those voice options.
Numeric values are parsed strictly; out-of-range values and unknown
preset names are rejected instead of being silently clamped.

### Named profiles

| Profile      | Voice transform                | Sample-domain effect              |
|--------------|--------------------------------|-----------------------------------|
| `robot`      | robotized (pitch locked to rate/hop, 187.5 Hz by default), no scramble | 7 ms metallic comb + light 93.75 Hz soft-square ring mod; 100 Hz high-pass, +5 dB @ 3 kHz; drive 2 |
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

### Robot voice

The `robot` preset is built for a clear, loud, metallic voice:

1. **Robotization** (`vc_rt`): every synthesis frame gets a centered
   zero phase, so each frame overlap-adds as one pulse shaped by your
   spectral envelope. Words stay intelligible while the pitch becomes a
   fixed `rate / hop` tone (187.5 Hz at 48 kHz / hop 256) whatever your
   intonation. Because the pitch contour is erased, scramble is 0: the
   bin permutation was what made the old robot sound blurry.
2. **Metallic comb** (`vc_effects`, `METALLIC`): a 7 ms feedback comb
   (feedback 0.6, 45% wet) adds the tin-can resonance.
3. **Ring modulation**: light (0.3) soft-square carrier at 93.75 Hz,
   half the robot pitch, so its sidebands stay on the robot harmonics
   instead of adding dissonance.
4. **Presence equalizer** (`vc_eq`): 100 Hz high-pass removes rumble
   that wastes headroom; +5 dB at 3 kHz (Q 1) brings consonants forward.
5. **Soft saturation** (`vc_level`, drive 2): `tanh(d x) / tanh(d)`
   after the AGC raises quiet passages by up to 6 dB and rounds peaks
   before the limiter, so the robot sounds louder without pumping.

Tweaks, from the CLI or Make (empty Make variables keep the preset value):

| Want | CLI | Make |
|------|-----|------|
| More grit and loudness | `--drive 3` | `VC_DRIVE=3` |
| No ring modulation | `--ring-amount 0` | `VC_RING_AMOUNT=0` |
| Smoother carrier | `--ring-wave sine` | `VC_RING_WAVE=sine` |
| Different carrier | `--ring-hz 120` | `VC_RING_HZ=120` |
| Deeper robot (93.75 Hz) | `--hop 512 --fft 2048` | `VC_HOP=512 VC_FFT=2048` |
| Higher robot (375 Hz) | `--hop 128 --fft 512` | `VC_HOP=128 VC_FFT=512` |

The robot pitch always equals `rate / hop`; `live` prints it at start.
`--ring-*` also works without a preset (it enables a plain ring
modulator, `--ring-amount` and `--ring-hz` required) and is rejected
with presets whose effect is not a ring modulator.

### Noise reduction (noise print)

Without noise reduction, the microphone hiss and room noise you make
while *not* speaking go through the whole chain: the robotizer turns
them into a steady buzz at the robot pitch, the AGC raises it up to
+12 dB, and the saturation adds another few dB. `--denoise` removes the
noise **before** the voice transform, the same idea as the noise print
of classic audio editors:

1. **Learn**: during the first `--noise-learn-ms` (default 1500 ms) you
   stay silent. VoiceCloak averages the noise power of every frequency
   bin into a *noise profile*. Output is muted meanwhile, and `live`
   prints a reminder.
2. **Subtract**: for each frame and bin, the gain is
   `sqrt(max(1 - reduction * noise / signal, floor^2))`, smoothed over
   time so the residue does not turn into "musical noise" (chirps).
3. **Gate**: when a whole frame is no louder than the noise profile
   plus 6 dB (you are not speaking), it is attenuated by a further
   30 dB, with a 120 ms release so word endings are not chopped. The
   threshold is relative to the learned profile, so it adapts to your
   microphone gain automatically.

The measured effect in the unit tests: stationary noise drops by about
42 dB, the robot buzz on silence by about 42 dB, and a voice-like signal
keeps its level. Denoising runs on the spectrum the stream already
computes, so it adds no latency.

Save and reuse a profile, so you do not need to stay silent at every
start (the profile is a small text file tied to the FFT size; a sample
rate change makes VoiceCloak learn again):

```sh
# First session: learn while silent, save on Ctrl-C
make pulse-robot VC_NOISE_SAVE=my_room.vcn
# Later sessions: load it, no learning pause
make pulse-robot VC_NOISE_PROFILE=my_room.vcn
```

| Control | CLI flag | Make variable | Default |
|---------|----------|---------------|---------|
| Enable | `--denoise` | `VC_DENOISE` | off in the CLI, `1` in Make routes |
| Learning time | `--noise-learn-ms` | `VC_NOISE_LEARN_MS` | `1500` (100-10000) |
| Load profile | `--noise-profile FILE` | `VC_NOISE_PROFILE` | none |
| Save profile on exit | `--noise-save FILE` | `VC_NOISE_SAVE` | none |
| Over-subtraction | `--noise-reduction` | `VC_NOISE_REDUCTION` | `2` (1-6) |
| Per-bin floor | `--noise-floor-db` | via `VC_EXTRA` | `-24` (-60..0) |
| Gate threshold | `--noise-gate-snr-db` | via `VC_EXTRA` | `6` (0-30) |
| Gate attenuation | `--noise-gate-range-db` | `VC_NOISE_GATE_RANGE_DB` | `30` (0-60, 0 = off) |

Tips: if a hum remains, raise `--noise-reduction` (3-4) or relearn in
the real conditions (fans on, same gain). If quiet syllables get cut,
lower `--noise-gate-snr-db` or `--noise-gate-range-db`. The profile is
static: if the room noise changes, learn again. A malformed or
mismatched profile file is rejected at start instead of being guessed.

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
| Soft saturation| `--drive`                | `VC_DRIVE`              | preset (`2` robot, `0` others) |

The AGC gain follows a smoothed RMS estimate and is capped at the
maximum gain, so quiet input is boosted only up to that limit and the
output is intentionally quieter rather than amplified without bound.
The peak limiter attenuates transients immediately and releases over
the limiter release time, keeping every sample under the ceiling
instead of hard-clipping at 0 dBFS. Digital silence stays silent.
`--no-agc` (or `VC_AGC=0`) disables the gain stage and keeps the
limiter. The soft saturation sits between the AGC and the limiter
(`tanh(d x) / tanh(d)`, unity at full scale); drive 0 bypasses it.
These levels are VoiceCloak product defaults, not values recovered
from the Android driver.

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
# Robot tweaks: more drive, no ring modulation, or a sine carrier
make pulse-robot VC_DRIVE=3
make pulse-robot VC_RING_AMOUNT=0
make pulse-robot VC_RING_WAVE=sine VC_RING_HZ=120
# Robot pitch follows the hop: 48000/512 = 93.75 Hz (deeper robot)
make pulse-robot VC_HOP=512 VC_FFT=2048
# Noise reduction is on in routes: stay silent ~1.5 s at start
make pulse-robot VC_NOISE_SAVE=my_room.vcn    # learn once and save
make pulse-robot VC_NOISE_PROFILE=my_room.vcn # reuse, no pause
make pulse-robot VC_DENOISE=0                 # disable
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
| `VC_DRIVE`    | empty (preset)     | Soft saturation drive 0-8                |
| `VC_RING_AMOUNT` / `VC_RING_HZ` / `VC_RING_WAVE` | empty (preset) | Ring modulation overrides |
| `VC_DENOISE`  | `1`                | `1` enables noise reduction, `0` disables |
| `VC_NOISE_LEARN_MS` | empty (`1500`) | Silent learning time at start          |
| `VC_NOISE_PROFILE` / `VC_NOISE_SAVE` | empty | Load / save a noise profile file |
| `VC_NOISE_REDUCTION` / `VC_NOISE_GATE_RANGE_DB` | empty (`2` / `30`) | Subtraction strength / gate attenuation |
| `VC_MONITOR`  | `1`                | Pulse route: copy output to the AudioBox headphones |
| `VC_MONITOR_LATENCY_MS` | `20`     | Headphone monitor loopback latency       |
| `PULSE_MONITOR_SINK` | auto (AudioBox sink) | Sink used by the headphone monitor |
| `VC_RATE` / `VC_CHANNELS` / `VC_PERIOD` / `VC_FFT` / `VC_HOP` | `48000` / `2` / `256` / `1024` / `256` | Stream parameters |
| `VC_EXTRA`    | empty              | Extra `live` flags, e.g. fixed transform |

## License

AGPL-3.0-or-later. See the parent project LICENSE file.
