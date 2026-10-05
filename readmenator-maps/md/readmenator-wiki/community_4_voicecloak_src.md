# voicecloak/src

*Community 4 | 37 files | cohesion 1.00*

## Definition

This community groups 37 file(s) rooted at `voicecloak/src` with dominant language c (cohesion 1.00). Central symbols: `FFT`, `HOP`, `M_PI`, `NBINS`, `NO_EFFECT`, `PI_F`, `SR`, `TEST_PI`. Core file: `voicecloak/src/vc_denoise.h` (29 symbols). Documented purpose: @brief Accepted sample-rate interval for live effect engines..

## Files

### `voicecloak/src` (30 files)

| File | Language | Layer | Symbols | Doc |
|------|----------|-------|---------|-----|
| `voicecloak/src/vc_alsa.c` | c | utility | 8 | no |
| `voicecloak/src/vc_alsa.h` | h | utility | 5 | no |
| `voicecloak/src/vc_audio_config.h` | h | infrastructure | 13 | yes |
| `voicecloak/src/vc_cli.c` | c | utility | 5 | no |
| `voicecloak/src/vc_crypto.c` | c | utility | 10 | no |
| `voicecloak/src/vc_crypto.h` | h | utility | 16 | no |
| `voicecloak/src/vc_denoise.c` | c | utility | 20 | no |
| `voicecloak/src/vc_denoise.h` | h | utility | 29 | no |
| `voicecloak/src/vc_dsp.c` | c | utility | 11 | no |
| `voicecloak/src/vc_dsp.h` | h | utility | 6 | no |
| `voicecloak/src/vc_effects.c` | c | utility | 27 | no |
| `voicecloak/src/vc_effects.h` | h | utility | 9 | no |
| `voicecloak/src/vc_eq.c` | c | utility | 13 | no |

### `voicecloak/tests` (7 files)

| File | Language | Layer | Symbols | Doc |
|------|----------|-------|---------|-----|
| `voicecloak/tests/test_vc_denoise.c` | c | testing | 23 | no |
| `voicecloak/tests/test_vc_effects.c` | c | testing | 15 | no |
| `voicecloak/tests/test_vc_eq.c` | c | testing | 9 | no |
| `voicecloak/tests/test_vc_fft.c` | c | testing | 4 | no |
| `voicecloak/tests/test_vc_level.c` | c | testing | 14 | no |
| `voicecloak/tests/test_vc_presets.c` | c | testing | 12 | no |
| `voicecloak/tests/test_vc_stream.c` | c | testing | 23 | no |

*... and 17 more files in this community.*


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
- `runtime` (function, `voicecloak/src/vc_alsa.h:20`) `* * The capture and playback device names are ALSA PCM names discovered * at run`
- `vc_alsa_cfg_t` (struct, `voicecloak/src/vc_alsa.h:26`) - @brief Configuration for a real-time ALSA processing session.  The capture and playback device names
- `vc_alsa_list` (function, `voicecloak/src/vc_alsa.h:46`) `int vc_alsa_list(void);` - @brief Print the available ALSA PCM devices to stdout. @return 0 on success, -1 on error.
- `vc_alsa_run` (function, `voicecloak/src/vc_alsa.h:53`) `int vc_alsa_run(const vc_alsa_cfg_t *cfg);` - @brief Open capture and playback, run the processing loop until *cfg->stop becomes non-zero or a fat
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
- `VC_LEVEL_MAX_SATURATION_DRIVE` (macro, `voicecloak/src/vc_audio_config.h:19`) `#define VC_LEVEL_MAX_SATURATION_DRIVE`
- `print_usage` (function, `voicecloak/src/vc_cli.c:9`) `static void print_usage(const char *prog)`
- `cmd_keygen` (function, `voicecloak/src/vc_cli.c:41`) `static int cmd_keygen(void)`
- `cmd_cloak` (function, `voicecloak/src/vc_cli.c:53`) `static int cmd_cloak(const char *pubkey_path,                      const char *i`
- `cmd_info` (function, `voicecloak/src/vc_cli.c:142`) `static int cmd_info(const char *path)`

## Internal vs External Edges

- Internal resolved imports (EXTRACTED): 55
- Cross-boundary resolved imports (EXTRACTED): 0

## Connections

- [INFERRED] shares_context community 0 <-> 4 (strength 0.5): Inferred shared context (language c) with no import path between community 0 (root) and community 4 (voicecloak/src).
- [INFERRED] shares_context community 1 <-> 4 (strength 0.5): Inferred shared context (language c) with no import path between community 1 (avatar) and community 4 (voicecloak/src).
- [INFERRED] shares_context community 2 <-> 4 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 2 (legacy) and community 4 (voicecloak/src).
- [INFERRED] shares_context community 3 <-> 4 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 3 (src) and community 4 (voicecloak/src).
- [INFERRED] shares_context community 4 <-> 5 (strength 0.5): Inferred shared context (layer utility) with no import path between community 4 (voicecloak/src) and community 5 (orphans).

## Risks

- [dataflow UNINIT_USE] `voicecloak/src/vc_cli.c:109` `cmd_cloak` `pitch_seed`: `pitch_seed` may be read before initialization (declared line 105).
- [dataflow UNINIT_USE] `voicecloak/src/vc_cli.c:109` `cmd_cloak` `formant_seed`: `formant_seed` may be read before initialization (declared line 106).
- [dataflow UNINIT_USE] `voicecloak/src/vc_cli.c:109` `cmd_cloak` `spectral_seed`: `spectral_seed` may be read before initialization (declared line 107).
- [dataflow DEAD_STORE] `voicecloak/src/vc_stft.c:105` `vc_stft_forward` `m`: `m` assigned at line 105 but never read afterwards.
- [dataflow DEAD_STORE] `voicecloak/src/vc_stft.c:106` `vc_stft_forward` `p`: `p` assigned at line 106 but never read afterwards.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_fft.c:32` `test_fft_dc_signal` `imag`: Result of allocator stored in `imag` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_fft.c:51` `test_fft_sine` `real`: Result of allocator stored in `real` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_fft.c:52` `test_fft_sine` `imag`: Result of allocator stored in `imag` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_stream.c:35` `dominant_freq` `re`: Result of allocator stored in `re` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_stream.c:36` `dominant_freq` `im`: Result of allocator stored in `im` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_stream.c:115` `test_passthrough_identity` `in`: Result of allocator stored in `in` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_stream.c:116` `test_passthrough_identity` `out`: Result of allocator stored in `out` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_stream.c:242` `run_pitch` `in`: Result of allocator stored in `in` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_stream.c:243` `run_pitch` `out`: Result of allocator stored in `out` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_stream.c:277` `test_bounded_output` `in`: Result of allocator stored in `in` is never checked against NULL.

## Open Questions

- Why do 36 file(s) lack file-level docs (e.g. `voicecloak/src/vc_alsa.c`)? What purpose do they serve?
- What would break if the most connected file in voicecloak/src changed?
- Should voicecloak/src be split, given cohesion 1.00?

## Sources

- `voicecloak/src/vc_alsa.c`
- `voicecloak/src/vc_alsa.h`
- `voicecloak/src/vc_audio_config.h`
- `voicecloak/src/vc_cli.c`
- `voicecloak/src/vc_crypto.c`
- `voicecloak/src/vc_crypto.h`
- `voicecloak/src/vc_denoise.c`
- `voicecloak/src/vc_denoise.h`
- `voicecloak/src/vc_dsp.c`
- `voicecloak/src/vc_dsp.h`
- `voicecloak/src/vc_effects.c`
- `voicecloak/src/vc_effects.h`
- `voicecloak/src/vc_eq.c`
- `voicecloak/src/vc_eq.h`
- `voicecloak/src/vc_fft.c`
- `voicecloak/src/vc_fft.h`
- `voicecloak/src/vc_level.c`
- `voicecloak/src/vc_level.h`
- `voicecloak/src/vc_presets.c`
- `voicecloak/src/vc_presets.h`
- *... and 17 more*
