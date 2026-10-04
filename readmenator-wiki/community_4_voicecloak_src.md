# voicecloak/src

*Community 4 | 24 files | cohesion 0.92*

## Definition

This community groups 24 file(s) rooted at `voicecloak/src` with dominant language c (cohesion 0.92). Central symbols: `FFT`, `M_PI`, `NO_EFFECT`, `PI_F`, `SR`, `TEST_PI`, `TEST_RATE`, `VC_ALSA_H`. Core file: `voicecloak/src/vc_effects.c` (20 symbols). Documented purpose: @brief Accepted sample-rate interval for live effect engines..

## Files

### `voicecloak/src` (19 files)

| File | Language | Layer | Symbols | Doc |
|------|----------|-------|---------|-----|
| `voicecloak/src/vc_alsa.c` | c | utility | 8 | no |
| `voicecloak/src/vc_alsa.h` | h | utility | 5 | no |
| `voicecloak/src/vc_audio_config.h` | h | infrastructure | 12 | yes |
| `voicecloak/src/vc_effects.c` | c | utility | 20 | no |
| `voicecloak/src/vc_effects.h` | h | utility | 9 | no |
| `voicecloak/src/vc_fft.c` | c | utility | 4 | no |
| `voicecloak/src/vc_fft.h` | h | utility | 2 | no |
| `voicecloak/src/vc_level.c` | c | utility | 9 | no |
| `voicecloak/src/vc_level.h` | h | utility | 15 | no |
| `voicecloak/src/vc_presets.c` | c | utility | 3 | no |
| `voicecloak/src/vc_presets.h` | h | utility | 4 | no |
| `voicecloak/src/vc_rt.c` | c | utility | 9 | no |
| `voicecloak/src/vc_rt.h` | h | utility | 17 | no |
| `voicecloak/src/vc_rt_cli.c` | c | utility | 10 | no |
| `voicecloak/src/vc_rt_seed.c` | c | data_access | 1 | no |

### `voicecloak/tests` (5 files)

| File | Language | Layer | Symbols | Doc |
|------|----------|-------|---------|-----|
| `voicecloak/tests/test_vc_effects.c` | c | testing | 11 | no |
| `voicecloak/tests/test_vc_fft.c` | c | testing | 4 | no |
| `voicecloak/tests/test_vc_level.c` | c | testing | 10 | no |
| `voicecloak/tests/test_vc_presets.c` | c | testing | 10 | no |
| `voicecloak/tests/test_vc_stream.c` | c | testing | 17 | no |

*... and 4 more files in this community.*


## Key Symbols

- `_GNU_SOURCE` (macro, `voicecloak/src/vc_alsa.c:1`) `#define _GNU_SOURCE`
- `vc_pcm_t` (struct, `voicecloak/src/vc_alsa.c:13`)
- `fmt_bps` (function, `voicecloak/src/vc_alsa.c:20`) `static size_t fmt_bps(snd_pcm_format_t f)`
- `open_stream` (function, `voicecloak/src/vc_alsa.c:29`) `static int open_stream(vc_pcm_t *s, const char *dev, snd_pcm_stream_t dir,`
- `raw_to_mono` (function, `voicecloak/src/vc_alsa.c:99`) `static void raw_to_mono(const unsigned char *raw, float *mono,`
- `mono_to_raw` (function, `voicecloak/src/vc_alsa.c:130`) `static void mono_to_raw(unsigned char *raw, const float *mono,`
- `vc_alsa_list` (function, `voicecloak/src/vc_alsa.c:163`) `int vc_alsa_list(void)`
- `vc_alsa_run` (function, `voicecloak/src/vc_alsa.c:189`) `int vc_alsa_run(const vc_alsa_cfg_t *cfg)`
- `VC_ALSA_H` (macro, `voicecloak/src/vc_alsa.h:2`) `#define VC_ALSA_H`
- `runtime` (function, `voicecloak/src/vc_alsa.h:19`) `* * The capture and playback device names are ALSA PCM names discovered * at run`
- `vc_alsa_cfg_t` (struct, `voicecloak/src/vc_alsa.h:25`) - @brief Configuration for a real-time ALSA processing session.  The capture and playback device names
- `vc_alsa_list` (function, `voicecloak/src/vc_alsa.h:44`) `int vc_alsa_list(void);` - @brief Print the available ALSA PCM devices to stdout. @return 0 on success, -1 on error.
- `vc_alsa_run` (function, `voicecloak/src/vc_alsa.h:51`) `int vc_alsa_run(const vc_alsa_cfg_t *cfg);` - @brief Open capture and playback, run the processing loop until *cfg->stop becomes non-zero or a fat
- `VC_AUDIO_CONFIG_H` (macro, `voicecloak/src/vc_audio_config.h:2`) `#define VC_AUDIO_CONFIG_H`
- `VC_AUDIO_MIN_SAMPLE_RATE` (macro, `voicecloak/src/vc_audio_config.h:5`) `#define VC_AUDIO_MIN_SAMPLE_RATE`
- `VC_AUDIO_MAX_SAMPLE_RATE` (macro, `voicecloak/src/vc_audio_config.h:6`) `#define VC_AUDIO_MAX_SAMPLE_RATE`
- `VC_AUDIO_MAX_INTERNAL_SAMPLE` (macro, `voicecloak/src/vc_audio_config.h:9`) `#define VC_AUDIO_MAX_INTERNAL_SAMPLE`
- `VC_LEVEL_MIN_TARGET_DBFS` (macro, `voicecloak/src/vc_audio_config.h:11`) `#define VC_LEVEL_MIN_TARGET_DBFS`
- `VC_LEVEL_MAX_TARGET_DBFS` (macro, `voicecloak/src/vc_audio_config.h:12`) `#define VC_LEVEL_MAX_TARGET_DBFS`
- `VC_LEVEL_MIN_CEILING_DBFS` (macro, `voicecloak/src/vc_audio_config.h:13`) `#define VC_LEVEL_MIN_CEILING_DBFS`
- `VC_LEVEL_MAX_CEILING_DBFS` (macro, `voicecloak/src/vc_audio_config.h:14`) `#define VC_LEVEL_MAX_CEILING_DBFS`
- `VC_LEVEL_MAX_GAIN_DB` (macro, `voicecloak/src/vc_audio_config.h:15`) `#define VC_LEVEL_MAX_GAIN_DB`
- `VC_LEVEL_MIN_TIME_MS` (macro, `voicecloak/src/vc_audio_config.h:16`) `#define VC_LEVEL_MIN_TIME_MS`
- `VC_LEVEL_MAX_TIME_MS` (macro, `voicecloak/src/vc_audio_config.h:17`) `#define VC_LEVEL_MAX_TIME_MS`
- `VC_LEVEL_RMS_FLOOR` (macro, `voicecloak/src/vc_audio_config.h:18`) `#define VC_LEVEL_RMS_FLOOR`
- `M_PI` (macro, `voicecloak/src/vc_effects.c:8`) `#define M_PI`
- `VC_EFFECT_MAX_DELAY_MS` (macro, `voicecloak/src/vc_effects.c:11`) `#define VC_EFFECT_MAX_DELAY_MS`
- `VC_REVERB_MAX_COMB_DELAY_MS` (macro, `voicecloak/src/vc_effects.c:12`) `#define VC_REVERB_MAX_COMB_DELAY_MS`
- `VC_REVERB_MIN_DECAY_SECONDS` (macro, `voicecloak/src/vc_effects.c:13`) `#define VC_REVERB_MIN_DECAY_SECONDS`
- `VC_REVERB_MAX_DECAY_SECONDS` (macro, `voicecloak/src/vc_effects.c:14`) `#define VC_REVERB_MAX_DECAY_SECONDS`

## Internal vs External Edges

- Internal resolved imports (EXTRACTED): 33
- Cross-boundary resolved imports (EXTRACTED): 3

## Connections

- [EXTRACTED] depends_on community 5 <-> 4 (strength 0.9): Extracted import edge crosses communities: voicecloak/src/vc_dsp.c imports voicecloak/src/vc_stft.h.
- [INFERRED] shares_context community 0 <-> 4 (strength 0.5): Inferred shared context (language c) with no import path between community 0 (root) and community 4 (voicecloak/src).
- [INFERRED] shares_context community 1 <-> 4 (strength 0.5): Inferred shared context (language c) with no import path between community 1 (avatar) and community 4 (voicecloak/src).
- [INFERRED] shares_context community 2 <-> 4 (strength 0.5): Inferred shared context (layer utility) with no import path between community 2 (legacy) and community 4 (voicecloak/src).
- [INFERRED] shares_context community 3 <-> 4 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 3 (src) and community 4 (voicecloak/src).
- [INFERRED] shares_context community 4 <-> 6 (strength 0.5): Inferred shared context (layer utility) with no import path between community 4 (voicecloak/src) and community 6 (orphans).
- [INFERRED] bridges community 4 <-> 5 (strength 0.4): Inferred cross-community bridge: voicecloak/src/vc_audio_config.h reaches voicecloak/src/vc_wav.c in 7 hops.
- [INFERRED] bridges community 4 <-> 5 (strength 0.4): Inferred cross-community bridge: voicecloak/src/vc_effects.c reaches voicecloak/src/vc_wav.c in 7 hops.
- [INFERRED] bridges community 4 <-> 5 (strength 0.4): Inferred cross-community bridge: voicecloak/src/vc_level.c reaches voicecloak/src/vc_wav.c in 7 hops.

## Risks

- [dataflow DEAD_STORE] `voicecloak/src/vc_stft.c:105` `vc_stft_forward` `m`: `m` assigned at line 105 but never read afterwards.
- [dataflow DEAD_STORE] `voicecloak/src/vc_stft.c:106` `vc_stft_forward` `p`: `p` assigned at line 106 but never read afterwards.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_fft.c:32` `test_fft_dc_signal` `imag`: Result of allocator stored in `imag` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_fft.c:51` `test_fft_sine` `real`: Result of allocator stored in `real` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_fft.c:52` `test_fft_sine` `imag`: Result of allocator stored in `imag` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_stream.c:35` `dominant_freq` `re`: Result of allocator stored in `re` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_stream.c:36` `dominant_freq` `im`: Result of allocator stored in `im` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_stream.c:106` `test_passthrough_identity` `in`: Result of allocator stored in `in` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_stream.c:107` `test_passthrough_identity` `out`: Result of allocator stored in `out` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_stream.c:141` `run_pitch` `in`: Result of allocator stored in `in` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_stream.c:142` `run_pitch` `out`: Result of allocator stored in `out` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_stream.c:176` `test_bounded_output` `in`: Result of allocator stored in `in` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_stream.c:205` `run_level` `in`: Result of allocator stored in `in` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_stream.c:206` `run_level` `out`: Result of allocator stored in `out` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_stream.c:251` `test_level_preserved_witness` `in`: Result of allocator stored in `in` is never checked against NULL.

## Open Questions

- Why do 23 file(s) lack file-level docs (e.g. `voicecloak/src/vc_alsa.c`)? What purpose do they serve?
- What would break if the most connected file in voicecloak/src changed?
- Should voicecloak/src be split, given cohesion 0.92?

## Sources

- `voicecloak/src/vc_alsa.c`
- `voicecloak/src/vc_alsa.h`
- `voicecloak/src/vc_audio_config.h`
- `voicecloak/src/vc_effects.c`
- `voicecloak/src/vc_effects.h`
- `voicecloak/src/vc_fft.c`
- `voicecloak/src/vc_fft.h`
- `voicecloak/src/vc_level.c`
- `voicecloak/src/vc_level.h`
- `voicecloak/src/vc_presets.c`
- `voicecloak/src/vc_presets.h`
- `voicecloak/src/vc_rt.c`
- `voicecloak/src/vc_rt.h`
- `voicecloak/src/vc_rt_cli.c`
- `voicecloak/src/vc_rt_seed.c`
- `voicecloak/src/vc_stft.c`
- `voicecloak/src/vc_stft.h`
- `voicecloak/src/vc_stream.c`
- `voicecloak/src/vc_stream.h`
- `voicecloak/tests/test_vc_effects.c`
- *... and 4 more*
