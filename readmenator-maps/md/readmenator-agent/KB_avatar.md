# Subsystem: avatar

## avatar/avatar_config.h
- Layer: infrastructure
- Language: h
- Symbols:
  - `AVATAR_CONFIG_H` (macro, line 2) `#define AVATAR_CONFIG_H`
  - `AVATAR_DEFAULT_PCM` (macro, line 12) `#define AVATAR_DEFAULT_PCM`
  - `AVATAR_FALLBACK_PCM` (macro, line 13) `#define AVATAR_FALLBACK_PCM`
  - `AVATAR_IMG_CLOSED` (macro, line 15) `#define AVATAR_IMG_CLOSED`
  - `AVATAR_IMG_OPEN` (macro, line 16) `#define AVATAR_IMG_OPEN`
  - `AVATAR_IMG_SIBILANT` (macro, line 17) `#define AVATAR_IMG_SIBILANT`
  - `AVATAR_DEFAULT_SILENCE_DB` (macro, line 19) `#define AVATAR_DEFAULT_SILENCE_DB`
  - `AVATAR_DEFAULT_ZCR_THR` (macro, line 20) `#define AVATAR_DEFAULT_ZCR_THR`
  - `AVATAR_DEFAULT_HF_THR` (macro, line 21) `#define AVATAR_DEFAULT_HF_THR`
  - `AVATAR_DEFAULT_HOLD_MS` (macro, line 22) `#define AVATAR_DEFAULT_HOLD_MS`
  - `AVATAR_FRAME_SAMPLES` (macro, line 24) `#define AVATAR_FRAME_SAMPLES`
  - `AVATAR_DEFAULT_RATE` (macro, line 25) `#define AVATAR_DEFAULT_RATE`
  - `AVATAR_WIN_W` (macro, line 26) `#define AVATAR_WIN_W`
  - `AVATAR_WIN_H` (macro, line 27) `#define AVATAR_WIN_H`
- Imported by: `avatar/avatar_main.c`

## avatar/avatar_logic.c
- Layer: business_logic
- Language: c
- Symbols:
  - `avatar_rms_f32` (function, line 5) `float avatar_rms_f32(const float *x, size_t n)`
  - `avatar_rms_to_dbfs` (function, line 27) `float avatar_rms_to_dbfs(float rms)`
  - `avatar_zcr_f32` (function, line 41) `float avatar_zcr_f32(const float *x, size_t n)`
  - `avatar_hf_ratio_f32` (function, line 68) `float avatar_hf_ratio_f32(const float *x, size_t n)`
  - `avatar_classify` (function, line 107) `avatar_state_t avatar_classify(float rms_db, float zcr, float hf,
                               ...`
  - `avatar_smooth_init` (function, line 125) `void avatar_smooth_init(avatar_smooth_t *s, avatar_state_t init, uint64_t now_ms,
               ...`
  - `avatar_smooth` (function, line 136) `avatar_state_t avatar_smooth(avatar_smooth_t *s, avatar_state_t inst,
                           ...`
  - `avatar_state_name` (function, line 161) `const char *avatar_state_name(avatar_state_t st)`
- Depends on: `avatar/avatar_logic.h`

## avatar/avatar_logic.h
- Layer: business_logic
- Language: h
- Symbols:
  - `avatar_cfg_t` (struct, line 23)
  - `avatar_smooth_t` (struct, line 33)
  - `avatar_rms_f32` (function, line 45) `float avatar_rms_f32(const float *x, size_t n);`
  - `avatar_rms_to_dbfs` (function, line 52) `float avatar_rms_to_dbfs(float rms);`
  - `avatar_zcr_f32` (function, line 60) `float avatar_zcr_f32(const float *x, size_t n);`
  - `avatar_hf_ratio_f32` (function, line 68) `float avatar_hf_ratio_f32(const float *x, size_t n);`
  - `avatar_classify` (function, line 78) `avatar_state_t avatar_classify(float rms_db, float zcr, float hf, const avatar_cfg_t *c);`
  - `avatar_smooth_init` (function, line 85) `void avatar_smooth_init(avatar_smooth_t *s, avatar_state_t init, uint64_t now_ms, unsigned int hold_ms);`
  - `avatar_smooth` (function, line 95) `avatar_state_t avatar_smooth(avatar_smooth_t *s, avatar_state_t inst, uint64_t now_ms);`
  - `avatar_state_name` (function, line 103) `const char *avatar_state_name(avatar_state_t st);`
  - `avatar_state_t` (variable, line 8) `extern "C" { #endif /** * @brief Visible mouth state. */ typedef enum { AVATAR_CLOSED = 0, AVATAR_OPEN = 1, AVATAR_SIBILANT = 2 } avatar_state_t;`
  - `AVATAR_LOGIC_H` (macro, line 2) `#define AVATAR_LOGIC_H`
- Imported by: `avatar/avatar_logic.c`, `avatar/avatar_main.c`, `tests/test_avatar_logic.c`

## avatar/avatar_main.c
- Layer: utility
- Language: c
- Symbols:
  - `on_sigint` (function, line 24) `static void on_sigint(int sig)`
  - `usage` (function, line 30) `static void usage(const char *argv0)`
  - `list_pcms` (function, line 54) `static int list_pcms(void)`
  - `env_or` (function, line 79) `static const char *env_or(const char *name, const char *fallback)`
  - `open_capture` (function, line 85) `static snd_pcm_t *open_capture(const char *dev, unsigned int rate,
                              ...`
  - `to_mono_f32` (function, line 156) `static void to_mono_f32(const uint8_t *raw, float *out, size_t frames,
                        un...`
  - `main` (function, line 191) `int main(int argc, char **argv)`
- Depends on: `avatar/avatar_config.h`, `avatar/avatar_logic.h`
