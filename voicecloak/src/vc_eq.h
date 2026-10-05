#ifndef VC_EQ_H
#define VC_EQ_H

#include <stddef.h>
#include <stdint.h>
#include "vc_audio_config.h"

#ifdef __cplusplus
extern "C" {
#endif

#define VC_EQ_MAX_GAIN_DB 12.0f
#define VC_EQ_MIN_Q 0.1f
#define VC_EQ_MAX_Q 10.0f

/**
 * @brief Voice equalizer settings (supplied by the preset table).
 *
 * highpass_hz 0 bypasses the high-pass section; presence_gain_db 0
 * bypasses the presence peak (presence_hz and presence_q are then
 * ignored). Coefficients follow the RBJ Audio EQ Cookbook.
 */
typedef struct {
    float highpass_hz;
    float presence_hz;
    float presence_gain_db;
    float presence_q;
} vc_eq_params_t;

typedef struct vc_eq_s vc_eq_t;

/**
 * @brief Create a high-pass + presence peaking equalizer.
 * @return Context or NULL for invalid sample rate/parameters/allocation.
 */
vc_eq_t *vc_eq_create(uint32_t sample_rate, const vc_eq_params_t *params);

/** @brief Release equalizer state. NULL-safe. */
void vc_eq_destroy(vc_eq_t *eq);

/**
 * @brief Equalize mono samples in place, keeping filter state.
 * @return 0 on success; nonzero on invalid arguments/data. Invalid
 *         blocks are silenced and the filter state is reset.
 */
int vc_eq_process(vc_eq_t *eq, float *samples, size_t count);

#ifdef __cplusplus
}
#endif

#endif
