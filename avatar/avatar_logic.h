#ifndef AVATAR_LOGIC_H
#define AVATAR_LOGIC_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Visible mouth state.
 */
typedef enum {
    AVATAR_CLOSED = 0,
    AVATAR_OPEN = 1,
    AVATAR_SIBILANT = 2
} avatar_state_t;

/**
 * @brief Tunable classifier thresholds.
 */
typedef struct {
    float silence_db;
    float zcr_thr;
    float hf_thr;
    unsigned int hold_ms;
} avatar_cfg_t;

/**
 * @brief Hysteresis holder for flicker-free display.
 */
typedef struct {
    avatar_state_t shown;
    uint64_t last_change_ms;
    unsigned int hold_ms;
} avatar_smooth_t;

/**
 * @brief RMS of a mono float frame, 0..1.
 * @param x frame or NULL.
 * @param n frame length.
 * @return RMS, 0 on NULL/empty/non-finite.
 */
float avatar_rms_f32(const float *x, size_t n);

/**
 * @brief Convert RMS to dBFS with -120 dB floor.
 * @param rms linear RMS.
 * @return dBFS value.
 */
float avatar_rms_to_dbfs(float rms);

/**
 * @brief Zero-crossing rate 0..1.
 * @param x frame or NULL.
 * @param n frame length.
 * @return crossing count / (n-1), 0 on NULL/n<2.
 */
float avatar_zcr_f32(const float *x, size_t n);

/**
 * @brief High-frequency ratio RMS(diff)/RMS, clamped 0..2.
 * @param x frame or NULL.
 * @param n frame length.
 * @return ratio, 0 on NULL/n<2.
 */
float avatar_hf_ratio_f32(const float *x, size_t n);

/**
 * @brief Instantaneous state without hysteresis, fail-closed.
 * @param rms_db frame level in dBFS.
 * @param zcr zero-crossing rate.
 * @param hf high-frequency ratio.
 * @param c thresholds or NULL (NULL yields CLOSED).
 * @return CLOSED on silence, SIBILANT when both gates pass, else OPEN.
 */
avatar_state_t avatar_classify(float rms_db, float zcr, float hf,
                               const avatar_cfg_t *c);

/**
 * @brief Init hysteresis holder.
 * @param hold_ms release delay for CLOSED in ms.
 */
void avatar_smooth_init(avatar_smooth_t *s, avatar_state_t init, uint64_t now_ms,
                        unsigned int hold_ms);

/**
 * @brief Hysteresis: instant attack, delayed release to CLOSED.
 * @param s holder or NULL (NULL yields CLOSED).
 * @param inst instantaneous state from avatar_classify.
 * @param now_ms monotonic clock in ms.
 * @return state to display.
 */
avatar_state_t avatar_smooth(avatar_smooth_t *s, avatar_state_t inst,
                             uint64_t now_ms);

/**
 * @brief State label for window title and headless output.
 * @param st state value.
 * @return static string, never NULL.
 */
const char *avatar_state_name(avatar_state_t st);

#ifdef __cplusplus
}
#endif

#endif
