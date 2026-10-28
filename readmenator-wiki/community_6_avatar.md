# avatar

*Community 6 | 4 files | cohesion 1.00*

## Definition

This community groups 4 file(s) rooted at `avatar` with dominant language h (cohesion 1.00). Central symbols: `AVATAR_CONFIG_H`, `AVATAR_DEFAULT_HF_THR`, `AVATAR_DEFAULT_HOLD_MS`, `AVATAR_DEFAULT_PCM`, `AVATAR_DEFAULT_RATE`, `AVATAR_DEFAULT_SILENCE_DB`, `AVATAR_DEFAULT_ZCR_THR`, `AVATAR_FALLBACK_PCM`. Core file: `avatar/avatar_config.h` (14 symbols).

## Files

| File | Language | Layer | Symbols | Doc |
|------|----------|-------|---------|-----|
| `avatar/avatar_config.h` | h | infrastructure | 14 | no |
| `avatar/avatar_logic.c` | c | business_logic | 8 | no |
| `avatar/avatar_logic.h` | h | business_logic | 12 | no |
| `avatar/avatar_main.c` | c | utility | 7 | no |

## Key Symbols

- `AVATAR_CONFIG_H` (macro, `avatar/avatar_config.h:2`) `#define AVATAR_CONFIG_H`
- `AVATAR_DEFAULT_PCM` (macro, `avatar/avatar_config.h:12`) `#define AVATAR_DEFAULT_PCM`
- `AVATAR_FALLBACK_PCM` (macro, `avatar/avatar_config.h:13`) `#define AVATAR_FALLBACK_PCM`
- `AVATAR_IMG_CLOSED` (macro, `avatar/avatar_config.h:15`) `#define AVATAR_IMG_CLOSED`
- `AVATAR_IMG_OPEN` (macro, `avatar/avatar_config.h:16`) `#define AVATAR_IMG_OPEN`
- `AVATAR_IMG_SIBILANT` (macro, `avatar/avatar_config.h:17`) `#define AVATAR_IMG_SIBILANT`
- `AVATAR_DEFAULT_SILENCE_DB` (macro, `avatar/avatar_config.h:19`) `#define AVATAR_DEFAULT_SILENCE_DB`
- `AVATAR_DEFAULT_ZCR_THR` (macro, `avatar/avatar_config.h:20`) `#define AVATAR_DEFAULT_ZCR_THR`
- `AVATAR_DEFAULT_HF_THR` (macro, `avatar/avatar_config.h:21`) `#define AVATAR_DEFAULT_HF_THR`
- `AVATAR_DEFAULT_HOLD_MS` (macro, `avatar/avatar_config.h:22`) `#define AVATAR_DEFAULT_HOLD_MS`
- `AVATAR_FRAME_SAMPLES` (macro, `avatar/avatar_config.h:24`) `#define AVATAR_FRAME_SAMPLES`
- `AVATAR_DEFAULT_RATE` (macro, `avatar/avatar_config.h:25`) `#define AVATAR_DEFAULT_RATE`
- `AVATAR_WIN_W` (macro, `avatar/avatar_config.h:26`) `#define AVATAR_WIN_W`
- `AVATAR_WIN_H` (macro, `avatar/avatar_config.h:27`) `#define AVATAR_WIN_H`
- `avatar_rms_f32` (function, `avatar/avatar_logic.c:5`) `float avatar_rms_f32(const float *x, size_t n)`
- `avatar_rms_to_dbfs` (function, `avatar/avatar_logic.c:27`) `float avatar_rms_to_dbfs(float rms)`
- `avatar_zcr_f32` (function, `avatar/avatar_logic.c:41`) `float avatar_zcr_f32(const float *x, size_t n)`
- `avatar_hf_ratio_f32` (function, `avatar/avatar_logic.c:68`) `float avatar_hf_ratio_f32(const float *x, size_t n)`
- `avatar_classify` (function, `avatar/avatar_logic.c:107`) `avatar_state_t avatar_classify(float rms_db, float zcr, float hf,`
- `avatar_smooth_init` (function, `avatar/avatar_logic.c:125`) `void avatar_smooth_init(avatar_smooth_t *s, avatar_state_t init, uint64_t now_ms`
- `avatar_smooth` (function, `avatar/avatar_logic.c:136`) `avatar_state_t avatar_smooth(avatar_smooth_t *s, avatar_state_t inst,`
- `avatar_state_name` (function, `avatar/avatar_logic.c:161`) `const char *avatar_state_name(avatar_state_t st)`
- `AVATAR_LOGIC_H` (macro, `avatar/avatar_logic.h:2`) `#define AVATAR_LOGIC_H`
- `avatar_state_t` (variable, `avatar/avatar_logic.h:8`) `extern "C" { #endif /** * @brief Visible mouth state. */ typedef enum { AVATAR_C` - ifdef __cplusplus
- `avatar_cfg_t` (struct, `avatar/avatar_logic.h:23`) - @brief Tunable classifier thresholds.
- `avatar_smooth_t` (struct, `avatar/avatar_logic.h:33`) - @brief Hysteresis holder for flicker-free display.
- `avatar_rms_f32` (function, `avatar/avatar_logic.h:45`) `float avatar_rms_f32(const float *x, size_t n);` - @brief RMS of a mono float frame, 0..1. @param x frame or NULL. @param n frame length. @return RMS,
- `avatar_rms_to_dbfs` (function, `avatar/avatar_logic.h:52`) `float avatar_rms_to_dbfs(float rms);` - @brief Convert RMS to dBFS with -120 dB floor. @param rms linear RMS. @return dBFS value.
- `avatar_zcr_f32` (function, `avatar/avatar_logic.h:60`) `float avatar_zcr_f32(const float *x, size_t n);` - @brief Zero-crossing rate 0..1. @param x frame or NULL. @param n frame length. @return crossing coun
- `avatar_hf_ratio_f32` (function, `avatar/avatar_logic.h:68`) `float avatar_hf_ratio_f32(const float *x, size_t n);` - @brief High-frequency ratio RMS(diff)/RMS, clamped 0..2. @param x frame or NULL. @param n frame leng

## Internal vs External Edges

- Internal resolved imports (EXTRACTED): 3
- Cross-boundary resolved imports (EXTRACTED): 0

## Connections

- No cross-community bridges recorded. This community is self-contained.

## Risks

- No scoped security, taint, cycle, or layer risks.

## Open Questions

- Why do 4 file(s) lack file-level docs (e.g. `avatar/avatar_config.h`)? What purpose do they serve?
- What would break if the most connected file in avatar changed?
- Should avatar be split, given cohesion 1.00?

## Sources

- `avatar/avatar_config.h`
- `avatar/avatar_logic.c`
- `avatar/avatar_logic.h`
- `avatar/avatar_main.c`
