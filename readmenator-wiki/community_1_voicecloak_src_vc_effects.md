# voicecloak/src: vc_effects

*Community 1 | 13 files | cohesion 0.68*

## Definition

This community groups 13 file(s) rooted at `voicecloak/src` with dominant language c (cohesion 0.68). Central symbols: `M_PI`, `NO_EFFECT`, `PI_F`, `TEST_PI`, `TEST_RATE`, `VC_AUDIO_CONFIG_H`, `VC_AUDIO_MAX_INTERNAL_SAMPLE`, `VC_AUDIO_MAX_SAMPLE_RATE`. Core file: `voicecloak/src/vc_effects.c` (27 symbols). Documented purpose: @brief Accepted sample-rate interval for live effect engines..

## Files

| File | Language | Layer | Symbols | Doc |
|------|----------|-------|---------|-----|
| `voicecloak/src/vc_audio_config.h` | h | infrastructure | 13 | yes |
| `voicecloak/src/vc_effects.c` | c | utility | 27 | no |
| `voicecloak/src/vc_effects.h` | h | utility | 9 | no |
| `voicecloak/src/vc_eq.c` | c | utility | 13 | no |
| `voicecloak/src/vc_eq.h` | h | utility | 10 | no |
| `voicecloak/src/vc_level.c` | c | utility | 9 | no |
| `voicecloak/src/vc_level.h` | h | utility | 16 | no |
| `voicecloak/src/vc_presets.c` | c | utility | 3 | no |
| `voicecloak/src/vc_presets.h` | h | utility | 4 | no |
| `voicecloak/tests/test_vc_effects.c` | c | testing | 15 | no |
| `voicecloak/tests/test_vc_eq.c` | c | testing | 9 | no |
| `voicecloak/tests/test_vc_level.c` | c | testing | 14 | no |
| `voicecloak/tests/test_vc_presets.c` | c | testing | 12 | no |

## Key Symbols

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
- `M_PI` (macro, `voicecloak/src/vc_effects.c:8`) `#define M_PI`
- `VC_EFFECT_MAX_DELAY_MS` (macro, `voicecloak/src/vc_effects.c:11`) `#define VC_EFFECT_MAX_DELAY_MS`
- `VC_REVERB_MAX_COMB_DELAY_MS` (macro, `voicecloak/src/vc_effects.c:12`) `#define VC_REVERB_MAX_COMB_DELAY_MS`
- `VC_REVERB_MIN_DECAY_SECONDS` (macro, `voicecloak/src/vc_effects.c:13`) `#define VC_REVERB_MIN_DECAY_SECONDS`
- `VC_REVERB_MAX_DECAY_SECONDS` (macro, `voicecloak/src/vc_effects.c:14`) `#define VC_REVERB_MAX_DECAY_SECONDS`
- `VC_REVERB_MAX_FEEDBACK` (macro, `voicecloak/src/vc_effects.c:15`) `#define VC_REVERB_MAX_FEEDBACK`
- `VC_METALLIC_MAX_DELAY_MS` (macro, `voicecloak/src/vc_effects.c:16`) `#define VC_METALLIC_MAX_DELAY_MS`
- `VC_METALLIC_MAX_FEEDBACK` (macro, `voicecloak/src/vc_effects.c:17`) `#define VC_METALLIC_MAX_FEEDBACK`
- `VC_RING_SQUARE_SHARPNESS` (macro, `voicecloak/src/vc_effects.c:18`) `#define VC_RING_SQUARE_SHARPNESS`
- `vc_comb_t` (struct, `voicecloak/src/vc_effects.c:20`)
- `vc_effects_s` (struct, `voicecloak/src/vc_effects.c:27`)
- `finite_params` (function, `voicecloak/src/vc_effects.c:40`) `static int finite_params(const vc_effects_params_t *p)`
- `ring_valid` (function, `voicecloak/src/vc_effects.c:53`) `static int ring_valid(const vc_effects_params_t *p, float nyquist)`
- `params_valid` (function, `voicecloak/src/vc_effects.c:61`) `static int params_valid(uint32_t sample_rate, const vc_effects_params_t *p)`
- `samples_from_ms` (function, `voicecloak/src/vc_effects.c:105`) `static size_t samples_from_ms(float milliseconds, uint32_t sample_rate)`
- `alloc_comb` (function, `voicecloak/src/vc_effects.c:111`) `static int alloc_comb(vc_comb_t *comb, float milliseconds,`
- `free_combs` (function, `voicecloak/src/vc_effects.c:121`) `static void free_combs(vc_effects_t *fx)`

## Internal vs External Edges

- Internal resolved imports (EXTRACTED): 15
- Cross-boundary resolved imports (EXTRACTED): 7

## Connections

- [EXTRACTED] depends_on community 0 <-> 1 (strength 0.9): Extracted import edge crosses communities: voicecloak/src/vc_alsa.h imports voicecloak/src/vc_effects.h.
- [INFERRED] shares_context community 1 <-> 2 (strength 0.5): Inferred shared context (layer utility) with no import path between community 1 (voicecloak/src: vc_effects) and community 2 (legacy).
- [INFERRED] shares_context community 1 <-> 4 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 1 (voicecloak/src: vc_effects) and community 4 (src).
- [INFERRED] shares_context community 1 <-> 5 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 1 (voicecloak/src: vc_effects) and community 5 (root).
- [INFERRED] shares_context community 1 <-> 7 (strength 0.5): Inferred shared context (layer utility) with no import path between community 1 (voicecloak/src: vc_effects) and community 7 (orphans).

## Risks

- No scoped security, taint, cycle, or layer risks.

## Open Questions

- Why do 12 file(s) lack file-level docs (e.g. `voicecloak/src/vc_effects.c`)? What purpose do they serve?
- What would break if the most connected file in voicecloak/src: vc_effects changed?
- Should voicecloak/src: vc_effects be split, given cohesion 0.68?

## Sources

- `voicecloak/src/vc_audio_config.h`
- `voicecloak/src/vc_effects.c`
- `voicecloak/src/vc_effects.h`
- `voicecloak/src/vc_eq.c`
- `voicecloak/src/vc_eq.h`
- `voicecloak/src/vc_level.c`
- `voicecloak/src/vc_level.h`
- `voicecloak/src/vc_presets.c`
- `voicecloak/src/vc_presets.h`
- `voicecloak/tests/test_vc_effects.c`
- `voicecloak/tests/test_vc_eq.c`
- `voicecloak/tests/test_vc_level.c`
- `voicecloak/tests/test_vc_presets.c`
