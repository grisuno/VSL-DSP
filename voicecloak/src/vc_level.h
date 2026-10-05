#ifndef VC_LEVEL_H
#define VC_LEVEL_H

#include <stddef.h>
#include <stdint.h>
#include "vc_audio_config.h"

#ifdef __cplusplus
extern "C" {
#endif

#define VC_LEVEL_DEFAULT_TARGET_DBFS (-18.0f)
#define VC_LEVEL_DEFAULT_MAX_GAIN_DB 12.0f
#define VC_LEVEL_DEFAULT_CEILING_DBFS (-1.0f)
#define VC_LEVEL_DEFAULT_ATTACK_MS 10.0f
#define VC_LEVEL_DEFAULT_RELEASE_MS 250.0f
#define VC_LEVEL_DEFAULT_LIMITER_RELEASE_MS 50.0f
#define VC_LEVEL_DEFAULT_SATURATION_DRIVE 0.0f

/**
 * @brief Level-stage configuration.
 *
 * saturation_drive 0 bypasses the soft saturation; a drive d in (0, 8]
 * maps each post-AGC sample x to tanh(d x) / tanh(d) before the limiter.
 */
typedef struct {
    float target_dbfs;
    float max_gain_db;
    float ceiling_dbfs;
    float attack_ms;
    float release_ms;
    float limiter_release_ms;
    int agc_enabled;
    float saturation_drive;
} vc_level_config_t;

typedef struct vc_level_s vc_level_t;

/** @brief Fill configuration with documented VoiceCloak defaults. */
void vc_level_config_defaults(vc_level_config_t *config);

/**
 * @brief Create smoothed RMS gain control and peak limiter state.
 * @return Context or NULL if sample rate/configuration is invalid.
 */
vc_level_t *vc_level_create(uint32_t sample_rate,
                            const vc_level_config_t *config);

/** @brief Release level-control state. NULL-safe. */
void vc_level_destroy(vc_level_t *level);

/**
 * @brief Apply smoothed RMS gain, soft saturation, and peak limiting
 *        in place.
 * @return 0 on success; nonzero on invalid arguments/data. Invalid
 *         blocks are silenced fail-closed.
 */
int vc_level_process(vc_level_t *level, float *samples, size_t count);

/** @brief Return the current AGC gain in dB, or 0 for a NULL context. */
float vc_level_current_gain_db(const vc_level_t *level);

#ifdef __cplusplus
}
#endif

#endif
