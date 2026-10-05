# Spec: VoiceCloak real-time engine (`vc_stream`, `voicecloak-rt`)

## 1. Purpose

Provide a real-time voice-changer that reuses the VoiceCloak DSP
concepts (pitch shift, formant scaling, spectral scramble) on a live
audio stream captured from and played back to the PreSonus AudioBox
VSL, using the interface as a standard ALSA class-compliant device.
The live path also provides smoothed RMS gain control, a peak limiter,
and named voice/effect presets selectable from the CLI and Makefile.

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
  is recovered or the session aborts. No unchecked buffer writes. Every
  DSP stage return code is checked too; a rejected block is silenced and
  the session continues.

## 3. Architecture

```
mic -> AudioBox ADC -> USB -> snd-usb-audio (ALSA capture, hw:VSL)
     -> vc_alsa capture loop (interleaved int16/int32 -> float mono)
     -> vc_stream_process  (streaming STFT, CPU) running the spectral
                            chain: vc_denoise (optional) -> vc_rt
     -> vc_effects_process (named sample-domain effect)
     -> vc_eq_process      (high-pass + presence peak, before the AGC)
     -> vc_level_process   (smoothed RMS gain, soft saturation, then
                            peak limiter)
     -> vc_alsa playback loop (float mono -> interleaved)
     -> snd-usb-audio (ALSA playback, hw:VSL) -> DAC -> headphones
```

Stage order is strict: the spectral transform runs first, the effect
shapes the transformed signal, the equalizer removes rumble and adds
presence before any gain is computed, and level control runs last so it
compensates for the total loss of the stages before it. Inside
`vc_level`, the optional soft saturation sits between the AGC gain and
the limiter, so the limiter always has the last word on the ceiling.

Layers:

| File            | Responsibility                                           | Testable surface |
|-----------------|----------------------------------------------------------|------------------|
| `vc_stream.[ch]`| Pure DSP: streaming STFT + phase vocoder, no I/O         | Unit (CMocka)    |
| `vc_rt.[ch]`    | Pitch/formant/scramble/robotize spectral transform       | Unit (CMocka)    |
| `vc_denoise.[ch]`| Noise-profile spectral subtraction + spectral gate, profile file I/O | Unit (CMocka) + fuzz |
| `vc_effects.[ch]`| Stateful sample-domain effects (ring mod, metallic comb, filters, delay/reverb, phaser) | Unit (CMocka) |
| `vc_eq.[ch]`    | Biquad high-pass and presence peaking equalizer          | Unit (CMocka)    |
| `vc_presets.[ch]`| Named preset definitions and lookup                     | Unit (CMocka)    |
| `vc_level.[ch]` | Smoothed RMS gain, soft saturation, peak limiting       | Unit (CMocka)    |
| `vc_alsa.[ch]`  | ALSA capture/playback orchestration (thin)               | Live only        |
| `vc_rt_cli.c`   | `voicecloak-rt` entry point (list/selftest/live)         | CLI + live       |

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

### Scenario: witness level floor at the spectral stage
- Given the same signal with aggressive witness parameters
  (`-8 st / 0.5 / 1.0`)
- When measured after the spectral transform only, before level control
- Then output RMS sits near -7 dB (pinned by test to [-8.5, -5.5]).
- Rationale: uniform random phase noise makes overlap-add sum powers
  instead of amplitudes (4 overlapping frames -> ~-6 dB floor), plus
  permutation misplacement attenuation. Both are inherent to
  intentional spectral destruction; the test guards regressions, it
  does not promise transparency in witness mode. `vc_level` restores
  the level downstream when the configured maximum gain allows it (see
  the next scenario).

### Scenario: live RMS compensation
- Given non-silent transformed audio below the configured target RMS
- When it passes through the live level controller
- Then gain approaches the target smoothly, with no block-boundary jump,
  and boost never exceeds the configured maximum.
- Defaults: target -18 dBFS, attack 10 ms, release 250 ms, maximum boost
  +12 dB, limiter release 50 ms, ceiling -1 dBFS. These are VoiceCloak
  product defaults in `vc_level.h`, not hardware or cryptographic constants.

### Scenario: compensate witness-mode attenuation
- Given the fixed witness transform (`-8 st / 0.5 / 1.0`) on a harmonic
  voice signal whose RMS is within the configured maximum-gain range
- When processed after startup settling by the live gain stage
- Then output RMS is within +/-3 dB of the configured target while the
  peak limiter still enforces the ceiling.

### Scenario: peak limiting
- Given any finite transformed sample, including a transient above full
  scale after gain compensation
- When it passes through the limiter
- Then output magnitude never exceeds the configured ceiling (-1 dBFS).
- The limiter attenuates peaks immediately and releases smoothly; it
  must not hard-clip at 0 dBFS.

### Scenario: silence is not amplified
- Given digital silence
- When processed by RMS gain control and limiting
- Then output remains digital silence and all output samples are finite.

### Scenario: named realtime effects
- Given any preset name `robot`, `monster`, `woman`, `man`, `space`,
  `underwater`, `church`, or `phaser`
- When selected with `voicecloak-rt --preset` or `make pulse/alsa`
- Then the preset resolves its pitch/formant/scramble and sample-domain
  effect parameters from the single preset table in `vc_presets.c`.
- Robot uses phase-vocoder robotization plus the metallic comb with a
  light ring modulation, the presence equalizer, and soft saturation
  (see the robot scenarios below); monster/woman/man use distinct pitch and
  formant shifts; space uses modulated delay; underwater uses low-pass
  filtering; church uses reverberation; phaser uses modulated all-pass
  stages. Named DSP values are creative starting points, not claims of
  universally correct voice characteristics.
- Unknown preset names fail closed with usage information.

### Scenario: robotization locks the pitch to the frame rate
- Given the engine with `fft=1024`, `hop=256`, `sr=48000`
- And a steady 1 kHz sine (5.33 periods per hop, so its own normalized
  autocorrelation at lag `hop` is about -0.5)
- When processed with `robotize = 1`
- Then, past the latency region, the normalized autocorrelation of the
  output at lag `hop` is above 0.9: the output is periodic at
  `sr / hop` = 187.5 Hz whatever the input pitch.
- Mechanism: every synthesis frame gets the linear phase `pi * bin`
  (zero phase centered in the frame, where the Hann window peaks), so
  each frame overlap-adds as one zero-phase pulse shaped by the input
  spectral envelope. Magnitudes are untouched, so the envelope (what is
  said) survives while the pitch contour (who says it) is erased.
- `robotize` accepts only 0 or 1; anything else is rejected at create.

### Scenario: metallic comb resonance
- Given the `METALLIC` effect with comb delay `D` ms, feedback `g`, and
  wet mix `a`
- When a unit impulse is processed
- Then the output holds echoes at multiples of `D` whose successive
  ratio is `g` (feedback comb `y[n] = x[n] + g * y[n - D]`).
- Delay is limited to (0, 50] ms and feedback to [0, 0.9]; out-of-range
  values are rejected at create, so the comb gain is bounded by 10.

### Scenario: ring modulation is optional and selectable
- Given `RING_MOD` or `METALLIC` with `ring_amount` in [0, 1], carrier
  `rate_hz` below Nyquist, and waveform `SINE` or `SQUARE`
- When `ring_amount` is 0 the ring stage is an identity
- And when the waveform is `SQUARE` the carrier is a soft square
  `tanh(4 sin) / tanh(4)` (limits the alias products of a hard edge).
- The gain applied is `(1 - ring_amount) + ring_amount * carrier`.

### Scenario: presence equalizer
- Given `vc_eq` with high-pass 100 Hz and a +5 dB presence peak at
  3 kHz (Q 1.0), at 48 kHz
- When steady sines are processed
- Then a 40 Hz tone is attenuated by at least 12 dB, a 1 kHz tone stays
  within the presence skirt (between -1 and +3 dB), and a 3 kHz tone is
  boosted by 5 +/- 0.5 dB.
- High-pass 0 Hz and presence gain 0 dB bypass their sections. Cut-offs
  must lie in (0, Nyquist), gain within +/-12 dB, Q within [0.1, 10].
  Coefficients follow the RBJ Audio EQ Cookbook (Butterworth high-pass,
  Q = 1/sqrt(2); peaking EQ).

### Scenario: soft saturation before the limiter
- Given `saturation_drive = d` in (0, 8]
- When a sample `x` leaves the AGC gain
- Then it becomes `tanh(d * x) / tanh(d)` before the limiter: unity at
  full scale, small-signal gain `d / tanh(d)` (+6.3 dB at `d = 2`), so
  perceived loudness rises and peaks are rounded instead of clipped.
- `saturation_drive = 0` bypasses the stage (default, all presets but
  robot). Values below 0, above 8, or non-finite are rejected.
- The limiter still enforces the ceiling after saturation.

### Scenario: robot preset is clear and loud
- Given the `robot` preset on a harmonic voice signal
- When processed by the full live chain (transform, effect, equalizer,
  level with the default AGC target)
- Then every output sample is finite and within the ceiling, and the
  output RMS is at least 2 dB above the AGC target, because the robot
  preset sets `saturation_drive = 2`.
- The robot preset uses `scramble = 0`: robotization alone removes the
  pitch contour, and the scramble bin permutation is what blurred the
  previous robot sound.

### Scenario: spectral chain
- Given `vc_spectral_chain_t` holding up to 4 `(fn, user)` stages
- When it is passed to `vc_stream_process` as the transform
- Then every frame runs the stages in insertion order on the same
  magnitude/phase buffers.
- Adding a NULL function or a fifth stage fails (returns -1) and leaves
  the chain unchanged.

### Scenario: noise profile learning (noise print)
- Given `vc_denoise` with `learn_ms = L` and no loaded profile
- When the first `ceil(L * sr / (1000 * hop))` frames arrive
- Then each of those frames is muted (magnitudes zeroed) while the
  per-bin mean noise power is accumulated, and afterwards
  `vc_denoise_is_ready` reports 1.
- Rationale: nothing is published before the profile exists; the user
  stays silent for that window (default 1.5 s), as with the noise print
  capture of classic editors.

### Scenario: stationary noise is removed
- Given a learned profile of white noise at 48 kHz, `fft=1024`,
  `hop=256`
- When a fresh realization of the same noise is processed
- Then the steady-state output RMS is at least 20 dB below the input.

### Scenario: speech-like content survives
- Given the same profile and a harmonic signal (140 Hz + harmonics,
  about 15 dB above the noise) mixed with that noise
- When processed
- Then the output RMS is within 3 dB of the clean harmonic RMS.

### Scenario: robot hum on silence is suppressed
- Given the spectral chain `vc_denoise -> vc_rt (robotize = 1)` with a
  learned noise profile
- When noise alone (the user not speaking) is processed
- Then the output RMS is at least 20 dB below the same chain without
  `vc_denoise`.

### Scenario: subtraction rule
- Given per-bin noise power `N`, frame power `X`, over-subtraction
  `alpha` (`reduction`, 1-6, default 2), floor `f` (`floor_db`, -60..0,
  default -24 dB)
- Then the raw gain is `sqrt(max(1 - alpha * N / X, f^2))`, smoothed
  across frames by `smoothing` (0-0.95, default 0.5):
  `g = smoothing * g_prev + (1 - smoothing) * g_raw` (limits musical
  noise).
- Spectral gate: when the frame power sum is below
  `N_sum * 10^(gate_snr_db / 10)` (default 6 dB, 0-30) the whole frame
  is attenuated by `gate_range_db` (default 30 dB, 0-60, 0 disables);
  it reopens immediately and closes with a 3 dB hysteresis and a
  120 ms release. The threshold is relative to the learned profile, so
  it does not depend on the microphone gain.

### Scenario: profile file round trip
- Given a ready profile
- When `vc_denoise_save` writes it and `vc_denoise_load` reads it into a
  fresh context with the same `nbins`
- Then the context is ready without learning and processes identically.
- Format (text, portable across endianness):
  `VCNOISE 1 <sample_rate> <nbins>` then exactly `nbins` lines, one
  non-negative finite float per line. Files above 2 MiB, wrong magic or
  version, `nbins` mismatch, negative/non-finite/garbage values, missing
  or extra lines are rejected and leave the context unchanged.
- A loaded profile whose sample rate differs from the stream rate is
  discarded at the first frame and the context re-learns.

### Scenario: denoise fails closed
- Given any frame with a non-finite magnitude
- When it reaches `vc_denoise_transform`
- Then the whole frame is muted.
- Invalid parameters (`nbins < 2`, non-finite or out-of-range values,
  `learn_ms` outside 100-10000) are rejected at create.

### Scenario: independent processing stages
- Given a live stream
- When VoiceCloak processes it
- Then the order is noise reduction (optional), phase-vocoder
  transform, named sample-domain effect,
  equalizer, smoothed RMS gain, soft saturation, peak limiter, and PCM
  conversion.
- Each stateful DSP stage keeps state across ALSA periods and resets at
  session creation; no per-period allocation is allowed.

### C API contracts

`vc_level_config_t` carries target dBFS, maximum gain dB, ceiling dBFS,
AGC attack/release milliseconds, limiter release milliseconds, and an
AGC enable flag, and the soft saturation drive (0 = bypass, up to 8).
Target must not exceed ceiling. `vc_level_create`
validates finite values and sample rate. `vc_level_process` operates
in-place and returns an error for invalid pointers or sample data; invalid
data blocks and inputs outside +/-16 are silenced fail-closed. Sample
rates outside 8–384 kHz are rejected. The limiter remains active when
AGC is disabled. `vc_level_current_gain_db` is a read-only test/diagnostic
query.

`vc_effects_params_t` selects `NONE`, `RING_MOD`, `UNDERWATER`, `PHASER`,
`SPACE`, `REVERB`, or `METALLIC`, with effect values supplied by the
preset table. Ring modulation (in `RING_MOD` and `METALLIC`) reads
`ring_amount`, `rate_hz`, and `waveform`; the metallic comb reads
`delay_ms`, `feedback`, and the wet mix `amount`.

`vc_eq_params_t` carries `highpass_hz`, `presence_hz`,
`presence_gain_db`, and `presence_q`. The context is allocated once per
session; processing is in place, allocation-free, and fails closed on
non-finite or out-of-bound (+/-16) samples by silencing the block and
resetting the filter state.
The opaque effects context is allocated once per session; processing is
in-place and allocation-free. Invalid parameters or non-finite input are
rejected and the affected block is silenced. The same 8–384 kHz rate
range and +/-16 inter-stage sample bound apply.

`vc_preset_lookup(name, out)` returns 0 only for a known preset and fills
the `vc_rt_params_t`, the sample-domain effects config, the equalizer
config, and the preset saturation drive. The
preset table is the single source of truth for names and parameters.
`vc_rt_create` rejects non-finite/out-of-range parameters: pitch ratio
0.25–4, formant factor 0.3–3, scramble intensity 0–1, and robotize
0 or 1.

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
(`vc_dsp_cloak`) and must stay in sync. The live fixed-pitch CLI accepts
-24 to +24 semitones; formant factor is 0.3–3 and scramble is 0–1.

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
- `voicecloak-rt live ... --preset <name>` selects a deterministic
  named preset. `--target-dbfs`, `--max-gain-db`, `--ceiling-dbfs`,
  `--attack-ms`, `--release-ms`, and `--limiter-release-ms` override
  level defaults; `--no-agc` disables RMS gain while retaining the
  peak limiter. `--drive D` overrides the preset saturation drive.
  `--ring-amount A`, `--ring-hz F`, and `--ring-wave sine|square`
  override the ring modulation of `RING_MOD`/`METALLIC` effects; without
  a preset effect they enable a plain `RING_MOD`; with any other effect
  they are rejected.
- `--denoise` enables `vc_denoise` (learning for `--noise-learn-ms`,
  default 1500, unless `--noise-profile FILE` loads one).
  `--noise-save FILE` writes the learned profile when the session ends.
  `--noise-reduction`, `--noise-floor-db`, `--noise-gate-snr-db`, and
  `--noise-gate-range-db` override the defaults.
- Make entry points accept `VC_PRESET=<name>` for both PulseAudio/PipeWire
  and ALSA loopback routes. `VC_PRESET=cloak` keeps the existing seeded
  `VC_MODE` behavior. Preset shorthand targets are also provided.
- Level defaults are configurable from Make with `VC_TARGET_DBFS`,
  `VC_MAX_GAIN_DB`, `VC_CEILING_DBFS`, `VC_ATTACK_MS`, `VC_RELEASE_MS`,
  `VC_LIMITER_RELEASE_MS`, and `VC_AGC`; `VC_DRIVE`, `VC_RING_AMOUNT`,
  `VC_RING_HZ`, and `VC_RING_WAVE` are empty by default (the preset
  value wins) and forward the matching CLI flags when set. CLI equivalents are accepted by
  direct `live` invocations.
- Make routes enable the denoiser by default (`VC_DENOISE=1`, set
  `VC_DENOISE=0` to disable); `VC_NOISE_LEARN_MS`, `VC_NOISE_PROFILE`,
  `VC_NOISE_SAVE`, `VC_NOISE_REDUCTION`, and `VC_NOISE_GATE_RANGE_DB`
  forward the matching flags when set.
- Latency target: `fft=1024`, `hop=256` -> ~21 ms window at 48 kHz
  plus ALSA period buffering; acceptable for anonymization, audible
  for self-monitoring.

## 8. Source of constants

| Constant | Source |
|---|---|
| 96-byte seed, RSA-4096, HKDF/AES-CTR | Offline cryptographic design (`vc_crypto.c`); not from the AudioBox disassembly. |
| Mode ranges (subtle/witness) | `vc_dsp_cloak` in `vc_dsp.c`, shared with the live path. |
| Level defaults (-18 dBFS, +12 dB, 10/250 ms, -1 dBFS, 50 ms) | VoiceCloak product defaults in `vc_level.h`. Creative choices for comfortable speech, not hardware measurements. |
| Preset values (semitones, formants, effect rates, EQ, drive) | Single table in `vc_presets.c`. Stylized voice/effect characters, not measured vocal characteristics. Robot ring carrier 93.75 Hz is half the default robot pitch (48000 / 256 / 2), so its sidebands stay on the robot harmonic grid. |
| Robot pitch `sr / hop` | Phase-reset robotization (pi-per-bin linear phase per frame); 187.5 Hz at the default 48 kHz / hop 256. |
| Denoise defaults (alpha 2, floor -24 dB, smoothing 0.5, gate 6 dB / 30 dB / 120 ms, hysteresis 3 dB, learn 1.5 s) | VoiceCloak product defaults in `vc_denoise.h`; power spectral subtraction with over-subtraction (Berouti et al., 1979). Not hardware measurements. |
| Profile file limits (2 MiB, 4 stages per chain) | Fail-closed guards in `vc_denoise.h`, `vc_stream.h`. |
| EQ coefficients | RBJ Audio EQ Cookbook (Butterworth high-pass, peaking EQ). |
| Metallic limits (50 ms, 0.9), EQ limits (+/-12 dB, Q 0.1-10), drive limit 8, soft-square sharpness 4 | Fail-closed guards in `vc_effects.c`, `vc_eq.h`, `vc_audio_config.h`. |
| Sample-rate range 8-384 kHz, inter-stage bound 16.0 | Fail-closed guards in `vc_audio_config.h`. |
| Latency (`fft=1024`, `hop=256`) | Engineering choice in this module; the AudioBox latency target is ~21 ms. |

## 9. Validation

- `make -C voicecloak test` includes CMocka coverage for stream,
  effects, equalizer, noise reduction, presets, the full live chain,
  robotization, and level control (seven suites).
- The profile parser is fuzzed with random and mutated profile texts
  under ASan+UBSan: zero crashes, zero leaks.
- `make -C voicecloak asan` clean under ASan+UBSan with leak detection.
- `cppcheck` clean on the changed sources.
- `voicecloak-rt selftest` reports the expected pitch ratio.
- CLI hardening verified with 150 arbitrary argument strings plus
  out-of-range pitch/formant/scramble values: all rejected, no crash.
- Live proof (requires the operator to speak into the AudioBox):
  transformed voice is heard on the AudioBox output; ALSA still owns
  the device (`snd-usb-audio` not displaced); no xrun storm.
