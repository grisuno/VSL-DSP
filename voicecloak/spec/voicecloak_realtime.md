# Spec: VoiceCloak real-time engine (`vc_stream`, `voicecloak-rt`)

## 1. Purpose

Provide a real-time voice-changer that reuses the VoiceCloak DSP
concepts (pitch shift, formant scaling, spectral scramble) on a live
audio stream captured from and played back to the PreSonus AudioBox
VSL, using the interface as a standard ALSA class-compliant device.

The transformation runs on the **CPU** as an ALSA client. It does
**not** run on the AudioBox onboard VSL DSP: that DSP is a
fixed-function mixer (gain/EQ/dynamics/reverb) exposed only through
the HID control plane, and cannot execute a phase vocoder. The VSL
HID driver of this repository is **not modified** by this feature and
plays no role in moving audio samples.

Non-goal: reversibility, cryptographic sealing of a sidecar (the
offline `cloak` command keeps that responsibility), zero-latency
monitoring, multichannel mixing.

## 2. Doctrine compliance

- The kernel detector still returns `-ENODEV`; `snd-usb-audio` owns
  the audio stream. This feature is a userspace ALSA client that
  reads capture and writes playback. It never touches the `.ko`.
- Zero Assumption: the audio device is discovered from ALSA at
  runtime (`hw:` name or index), never hardcoded. Sample rate and
  channel count are queried from the device, not assumed.
- Fail closed: every ALSA return code is checked; on xrun the stream
  is recovered or the session aborts. No unchecked buffer writes.

## 3. Architecture

```
mic -> AudioBox ADC -> USB -> snd-usb-audio (ALSA capture, hw:VSL)
     -> vc_alsa capture loop (interleaved int16/int32 -> float mono)
     -> vc_stream_process  (streaming phase vocoder, CPU)
     -> vc_alsa playback loop (float mono -> interleaved)
     -> snd-usb-audio (ALSA playback, hw:VSL) -> DAC -> headphones
```

Layers:

| File            | Responsibility                                           | Testable surface |
|-----------------|----------------------------------------------------------|------------------|
| `vc_stream.[ch]`| Pure DSP: streaming STFT + phase vocoder, no I/O         | Unit (CMocka)    |
| `vc_rt.[ch]`    | Derive pitch/formant/scramble scalars from a seed        | Unit (CMocka)    |
| `vc_alsa.[ch]`  | ALSA capture/playback orchestration (thin)               | Live only        |
| `vc_rt_cli.c`   | `voicecloak-rt` entry point (list/selftest/live)         | Live only        |

## 4. Streaming engine contract (`vc_stream`)

Constant-rate requirement: a real-time stream must produce exactly as
many output samples as it consumes input samples per unit time. The
offline pitch shift changes duration (analysis hop != synthesis hop)
and therefore cannot be streamed as-is. The streaming engine uses a
**frequency-domain** pitch shift (analysis hop == synthesis hop == H),
remapping each analysis bin to `bin * ratio` and propagating the
per-bin instantaneous frequency, so input and output rates match.

API:

```c
typedef struct vc_stream_s vc_stream_t;

typedef void (*vc_spectral_fn)(float *mag, float *phase, size_t nbins,
                               uint32_t sample_rate, size_t hop,
                               void *user);

vc_stream_t *vc_stream_create(size_t fft_size, size_t hop_size,
                              uint32_t sample_rate);
void         vc_stream_destroy(vc_stream_t *st);
size_t       vc_stream_latency_samples(const vc_stream_t *st);
int          vc_stream_process(vc_stream_t *st,
                               const float *in, float *out, size_t n,
                               vc_spectral_fn fn, void *user);
```

Constraints (fail closed if violated):

- `fft_size` power of two; `hop_size` divides `fft_size`; overlap
  factor `fft_size/hop_size` in {2,4} so the Hann window satisfies
  COLA.
- `vc_stream_process` writes exactly `n` output samples for `n`
  inputs. `in` and `out` may alias.
- `fn == NULL` means identity (passthrough). The engine holds no
  transform state; per-bin phase-vocoder state that must persist
  across frames lives in the `user` context of the transform.

Reconstruction gain: for Hann analysis+synthesis windowing with COLA
hop, passthrough output equals the input scaled by the steady-state
window-overlap constant `W2 = sum_j w(k + jH)^2`; the engine divides
by `W2`, so passthrough is unity (after the fixed latency ramp).

## 5. BDD scenarios (Given-When-Then)

### Scenario: passthrough identity
- Given an engine with `fft=1024`, `hop=256`, `sr=48000`
- And a 1 kHz sine input of 8192 samples
- When processed with `fn == NULL`
- Then, past the latency region, output equals input within 1e-2 RMS.

Source of constants: Hann COLA identity `y = x * W2 / W2`.

### Scenario: pitch shift up one octave
- Given the same engine and a steady 1 kHz sine
- When processed with the pitch transform, `ratio = 2.0`
- Then the dominant frequency of the steady-state output is
  2 kHz +/- 3%.

### Scenario: pitch shift down
- Given a 2 kHz sine and `ratio = 0.5`
- Then the dominant output frequency is 1 kHz +/- 3%.

### Scenario: bounded output (no NaN/Inf)
- Given random noise in [-1, 1]
- When processed by the full cloak transform (pitch+formant+scramble)
- Then every output sample is finite and within [-4, 4].

### Scenario: constant rate
- Given any input of length `n`
- When processed
- Then exactly `n` samples are written to `out`.

### Scenario: level preservation (energy-normalized pitch shift)
- Given a harmonic signal (120 Hz + harmonics) at fixed RMS
- When processed with a fixed cloak transform (`+7 st / 1.3 / 0.0`)
- Then, past the latency region, output RMS is within +/-3 dB of
  input RMS.
- Rationale: bins shifted out of range must not silently drop the
  level; the pitch-mapping stage renormalizes energy, partials move
  as rigid (magnitude, true frequency) pairs, and non-peak bins
  identity-lock to their peak (measured pi-structured analysis
  phases), so adjacent bins cannot cancel in overlap-add. Silence
  passes through untouched (fail closed, no scaling).

### Scenario: witness level floor (documented, not preserved)
- Given the same signal with aggressive witness parameters
  (`-8 st / 0.5 / 1.0`)
- Then output RMS sits near -7 dB (pinned by test to [-8.5, -5.5]).
- Rationale: uniform random phase noise makes overlap-add sum powers
  instead of amplitudes (4 overlapping frames -> ~-6 dB floor), plus
  permutation misplacement attenuation. Both are inherent to
  intentional spectral destruction; the test guards regressions, it
  does not promise transparency in witness mode.

## 6. Parameter derivation (`vc_rt`)

Reuses `vc_prng` (AES-256-CTR) exactly as the offline pipeline. From a
32-byte seed per stage derive the three scalars with the same ranges
as `vc_dsp_cloak`:

| Parameter          | subtle           | witness          |
|--------------------|------------------|------------------|
| pitch (semitones)  | [-3, 3]          | [-10, 10]        |
| formant factor     | [0.85, 1.15]     | [0.5, 1.8]       |
| scramble intensity | [0.1, 0.3]       | [0.6, 1.0]       |

A fixed pitch (e.g. `--semitones N`) may override the seed for
predictable live use. Ranges are the source of truth in `vc_dsp.c`
(`vc_dsp_cloak`) and must stay in sync.

## 7. ALSA layer (`vc_alsa`) and CLI

- `voicecloak-rt list` enumerates ALSA PCM devices so the user picks
  the AudioBox (`hw:VSL` / index), never hardcoded.
- `voicecloak-rt selftest` runs the engine on an internally generated
  tone (no device) and prints measured input/output dominant
  frequency; used for CI-less smoke verification.
- `voicecloak-rt live -D <capture> -P <playback> [--mode|--semitones]`
  opens capture and playback, negotiates rate/format/channels from the
  device, and runs the loop until interrupted. Channel 0 is processed;
  output is written to all playback channels.
- Latency target: `fft=1024`, `hop=256` -> ~21 ms window at 48 kHz
  plus ALSA period buffering; acceptable for anonymization, audible
  for self-monitoring.

## 8. Validation

- `make -C voicecloak test` includes `test_vc_stream` (CMocka):
  passthrough, pitch up/down, bounded output, constant rate.
- ASan/UBSan clean on the test binary.
- `voicecloak-rt selftest` reports the expected pitch ratio.
- Live proof (requires the operator to speak into the AudioBox):
  transformed voice is heard on the AudioBox output; ALSA still owns
  the device (`snd-usb-audio` not displaced); no xrun storm.
