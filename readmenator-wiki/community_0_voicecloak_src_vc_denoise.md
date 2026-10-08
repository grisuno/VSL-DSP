# voicecloak/src: vc_denoise

*Community 0 | 14 files | cohesion 0.67*

## Definition

This community groups 14 file(s) rooted at `voicecloak/src` with dominant language c (cohesion 0.67). Central symbols: `FFT`, `HOP`, `M_PI`, `NBINS`, `SR`, `TEST_PI`, `VC_ALSA_H`, `VC_DENOISE_DEFAULT_FLOOR_DB`. Core file: `voicecloak/src/vc_denoise.h` (29 symbols).

## Files

| File | Language | Layer | Symbols | Doc |
|------|----------|-------|---------|-----|
| `voicecloak/src/vc_alsa.c` | c | utility | 8 | no |
| `voicecloak/src/vc_alsa.h` | h | utility | 5 | no |
| `voicecloak/src/vc_denoise.c` | c | utility | 20 | no |
| `voicecloak/src/vc_denoise.h` | h | utility | 29 | no |
| `voicecloak/src/vc_fft.c` | c | utility | 4 | no |
| `voicecloak/src/vc_fft.h` | h | utility | 2 | no |
| `voicecloak/src/vc_rt.c` | c | utility | 9 | no |
| `voicecloak/src/vc_rt.h` | h | utility | 17 | no |
| `voicecloak/src/vc_rt_cli.c` | c | utility | 10 | no |
| `voicecloak/src/vc_stream.c` | c | utility | 11 | no |
| `voicecloak/src/vc_stream.h` | h | utility | 13 | no |
| `voicecloak/tests/test_vc_denoise.c` | c | testing | 23 | no |
| `voicecloak/tests/test_vc_fft.c` | c | testing | 4 | no |
| `voicecloak/tests/test_vc_stream.c` | c | testing | 23 | no |

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
- `VC_DENOISE_MAGIC` (macro, `voicecloak/src/vc_denoise.c:9`) `#define VC_DENOISE_MAGIC`
- `VC_DENOISE_VERSION` (macro, `voicecloak/src/vc_denoise.c:10`) `#define VC_DENOISE_VERSION`
- `vc_denoise_s` (struct, `voicecloak/src/vc_denoise.c:12`)
- `vc_denoise_params_defaults` (function, `voicecloak/src/vc_denoise.c:29`) `void vc_denoise_params_defaults(vc_denoise_params_t *params)`
- `params_valid` (function, `voicecloak/src/vc_denoise.c:39`) `static int params_valid(const vc_denoise_params_t *p)`
- `reset_tracking` (function, `voicecloak/src/vc_denoise.c:57`) `static void reset_tracking(vc_denoise_t *dn)` - Restart the per-bin gains and close the gate: right after a profile * appears the user is assumed si
- `restart_learning` (function, `voicecloak/src/vc_denoise.c:64`) `static void restart_learning(vc_denoise_t *dn)`
- `vc_denoise_create` (function, `voicecloak/src/vc_denoise.c:71`) `vc_denoise_t *vc_denoise_create(size_t nbins,                                 co`
- `vc_denoise_destroy` (function, `voicecloak/src/vc_denoise.c:92`) `void vc_denoise_destroy(vc_denoise_t *denoise)`
- `vc_denoise_is_ready` (function, `voicecloak/src/vc_denoise.c:100`) `int vc_denoise_is_ready(const vc_denoise_t *denoise)`
- `mute` (function, `voicecloak/src/vc_denoise.c:104`) `static void mute(float *mag, size_t nbins)`
- `install_profile` (function, `voicecloak/src/vc_denoise.c:108`) `static void install_profile(vc_denoise_t *dn, uint32_t sample_rate)`
- `learn` (function, `voicecloak/src/vc_denoise.c:117`) `static void learn(vc_denoise_t *dn, float *mag, uint32_t sample_rate,`
- `update_gate` (function, `voicecloak/src/vc_denoise.c:136`) `static void update_gate(vc_denoise_t *dn, double frame_power,`
- `vc_denoise_transform` (function, `voicecloak/src/vc_denoise.c:158`) `void vc_denoise_transform(float *mag, float *phase, size_t nbins,`
- `parse_ulong` (function, `voicecloak/src/vc_denoise.c:196`) `static int parse_ulong(const char **cursor, unsigned long *out)`
- `parse_header` (function, `voicecloak/src/vc_denoise.c:208`) `static int parse_header(const char **cursor, unsigned long *rate,`

## Internal vs External Edges

- Internal resolved imports (EXTRACTED): 20
- Cross-boundary resolved imports (EXTRACTED): 10

## Connections

- [EXTRACTED] depends_on community 0 <-> 1 (strength 0.9): Extracted import edge crosses communities: voicecloak/src/vc_alsa.h imports voicecloak/src/vc_effects.h.
- [EXTRACTED] depends_on community 0 <-> 3 (strength 0.9): Extracted import edge crosses communities: voicecloak/src/vc_rt_cli.c imports voicecloak/src/vc_crypto.h.
- [INFERRED] shares_context community 0 <-> 2 (strength 0.5): Inferred shared context (layer utility) with no import path between community 0 (voicecloak/src: vc_denoise) and community 2 (legacy).
- [INFERRED] shares_context community 0 <-> 4 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 0 (voicecloak/src: vc_denoise) and community 4 (src).
- [INFERRED] shares_context community 0 <-> 5 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 0 (voicecloak/src: vc_denoise) and community 5 (root).
- [INFERRED] shares_context community 0 <-> 7 (strength 0.5): Inferred shared context (layer utility) with no import path between community 0 (voicecloak/src: vc_denoise) and community 7 (orphans).

## Risks

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
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_stream.c:306` `run_level` `in`: Result of allocator stored in `in` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_stream.c:307` `run_level` `out`: Result of allocator stored in `out` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_stream.c:352` `test_level_preserved_witness` `in`: Result of allocator stored in `in` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `voicecloak/tests/test_vc_stream.c:353` `test_level_preserved_witness` `out`: Result of allocator stored in `out` is never checked against NULL.

## Open Questions

- Why do 14 file(s) lack file-level docs (e.g. `voicecloak/src/vc_alsa.c`)? What purpose do they serve?
- What would break if the most connected file in voicecloak/src: vc_denoise changed?
- Should voicecloak/src: vc_denoise be split, given cohesion 0.67?

## Sources

- `voicecloak/src/vc_alsa.c`
- `voicecloak/src/vc_alsa.h`
- `voicecloak/src/vc_denoise.c`
- `voicecloak/src/vc_denoise.h`
- `voicecloak/src/vc_fft.c`
- `voicecloak/src/vc_fft.h`
- `voicecloak/src/vc_rt.c`
- `voicecloak/src/vc_rt.h`
- `voicecloak/src/vc_rt_cli.c`
- `voicecloak/src/vc_stream.c`
- `voicecloak/src/vc_stream.h`
- `voicecloak/tests/test_vc_denoise.c`
- `voicecloak/tests/test_vc_fft.c`
- `voicecloak/tests/test_vc_stream.c`
