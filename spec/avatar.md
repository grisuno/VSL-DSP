# Avatar PNGTuber Specification

## Module: avatar

### Purpose
Small window that shows 1 of 3 images from `img/` synchronised with
the AudioBox microphone (or with the VoiceCloak processed voice),
simulating a PNGTuber: mouth closed, mouth open, sibilant teeth.

Image contract (immutable paths, repository root relative):
- `img/cgoblin.png` bouche fermee -> state `AVATAR_CLOSED` (silence / low energy).
- `img/cgobling.png` bouche ouverte -> state `AVATAR_OPEN` (voiced: vowels, sonorants).
- `img/cgoblin2.png` sibilant dents visibles -> state `AVATAR_SIBILANT` (fricatives: s, f, sh, z, ch).

Inspiration: https://github.com/OpenPNGStudio/OpenPNGStudio.
Scope here is deliberately smaller: no skeleton, no tracking, only
a 3-state mouth driven by audio envelope plus sibilance. No network,
no model download.

### Inputs
- ALSA capture PCM, device selectable via `-D` (default
  `plughw:CARD=VSL`, fallback `default` if absent). Format
  negotiated S32_LE / S16_LE / FLOAT_LE, rate negotiated
  (requested 48000), channels 1-2 mixed to mono. Frame 1024 samples
  (~21 ms at 48 kHz).
- CLI: `-D <pcm>`, `--silence <dbfs>` (default -50.0),
  `--zcr <f>` (default 0.25), `--hf <f>` (default 0.60),
  `--hold <ms>` (default 120), `--list` (list PCMs, exit 0),
  `--no-gui` (stdout state printer, no SDL window, for headless test).
- ENV overrides: `AVATAR_PCM`, `AVATAR_IMG_CLOSED/OPEN/SIBILANT`.

### Outputs
- SDL2 window 512x512 resizable showing current PNG, texture switch
  only on state change, minimum 30 fps poll, hold time 120 ms to
  avoid flicker. Window title `avatar - <STATE>`.
- `--no-gui`: one line per frame `CLOSED|OPEN|SIBILANT rms=<db> zcr=<f> hf=<f>`.
- Exit 0 clean (Ctrl-C / window close), non-zero with stderr reason
  on: unknown PCM, unsupported format, missing PNG, SDL/ALSA init fail.

### Pure logic (directly verifiable surface, no I/O)
Prefix `avatar_`, pure C C11, no malloc, no static state:

- `float avatar_rms_f32(const float *x, size_t n)` RMS 0..1. NULL/0 -> 0.
- `float avatar_rms_to_dbfs(float rms)` 20*log10(rms), floor -120 dB.
- `float avatar_zcr_f32(const float *x, size_t n)` rate 0..1 of sign changes. NULL/0 -> 0.
- `float avatar_hf_ratio_f32(const float *x, size_t n)` RMS(first difference) / (RMS+1e-9), clamped 0..2. High for sibilants. NULL/0 -> 0.
- `avatar_state_t avatar_classify(float rms_db, float zcr, float hf, const avatar_cfg_t *c)` fail-closed: NULL cfg -> CLOSED. Order: silence first, then sibilant, else open.
- `avatar_state_t avatar_smooth(avatar_smooth_t *s, avatar_state_t inst, uint64_t now_ms)` hysteresis: instant attack OPEN/SIBILANT, delayed release to CLOSED after `s->hold_ms`; SIBILANT<->OPEN switches instantly. NULL -> CLOSED.

`avatar_cfg_t`: `{silence_db, zcr_thr, hf_thr, hold_ms}`. Defaults in
`avatar/avatar_config.h` single source of truth, tunable pending
hardware calibration (see blockers).

### Error table
| Condition | Behaviour |
|---|---|
| NULL frame / n==0 | metric 0, classify CLOSED |
| NULL cfg / NULL smooth | CLOSED, no crash |
| rms NaN/inf | treated as 0 -> CLOSED |
| PNG missing/unreadable | stderr + exit 1, no invented fallback image |
| ALSA open fail | stderr with `snd_strerror`, exit 1 |
| ALSA xrun | recover via `snd_pcm_recover`, counter, continue |
| SDL init fail | stderr + exit 1; `--no-gui` still works headless |

### Security guarantees
- Fail closed. Pointer validation on every pure function.
- `sizeof` buffer bounds, no `strcpy`, no overflow, int16/int32/float conversion via explicit clamp.
- No absolute system paths in code; image paths configurable, defaults relative to repo root.
- Capture-only: never claims HID/USB interface, never writes to the AudioBox DSP. Non-interference with `snd-usb-audio` preserved.

### Non-goals
- No pitch/f0 tracking, no phoneme recognition, no ML model.
- No DSP write to the AudioBox (HID plane untouched).
- No network, no config file format, no C++ wrapper (Phase 7 covers bindings).

### Source of constants
- Image mapping: user requirement + `img/` inventory (3 files verified 2026-09-22).
- Packet/window sizes: SDL default 512, frame 1024 (~21 ms) from voicecloak `vc_stream` practice (fft 1024 hop 256), not from disassembly.
- Threshold defaults (`-50 dB, zcr 0.25, hf 0.60, hold 120 ms`): working hypothesis tunable via CLI; must be calibrated with real AudioBox hardware before contract closure. Left explicit, never hidden.
- VID/PID untouched (kernel detector owns them).

### BDD scenarios (Given-When-Then)
1. Silence: Given rms -70 dB When classify Then CLOSED regardless of zcr/hf.
2. Vowel: Given rms -20 dB, zcr 0.08, hf 0.25 When classify Then OPEN.
3. Sibilant /s/: Given rms -25 dB, zcr 0.45, hf 0.90 When classify Then SIBILANT.
4. Borderline fricative with low hf: Given rms -25 dB, zcr 0.45, hf 0.30 Then OPEN (both gates required).
5. Hold: Given state OPEN at t=0, instant CLOSED at t=30 ms, hold 120 ms When smooth Then still OPEN; at t=150 ms Then CLOSED.
6. Headless: Given `--no-gui` and WAV/ALSA frame When run Then stdout line matches state of direct classify.
7. VoiceCloak route: Given `voicecloak-rt` publishing to `pulse`/`Loopback` When avatar `-D pulse` Then animates from processed voice, never opens AudioBox directly.
8. Missing PNG: Given unreadable image When start Then exit 1 with stderr.

### Validation
- `make avatar-test` CMocka green, `make avatar-asan` ASan+UBSan clean.
- `avatar --no-gui` on synthetic WAVs (silence/vowel/noise) matches table above.
- Real hardware pending: AudioBox 22 VSL `194f:0101` + `aplay/arecord` still work while avatar captures; calibration table GUI->value->state->match resolved.
- Fuzz: libFuzzer on `avatar_classify` + metric parsers, zero crash before closure.
