#ifndef VC_DENOISE_H
#define VC_DENOISE_H

#include <stddef.h>
#include <stdint.h>
#include "vc_audio_config.h"

#ifdef __cplusplus
extern "C" {
#endif

#define VC_DENOISE_DEFAULT_REDUCTION 2.0f
#define VC_DENOISE_DEFAULT_FLOOR_DB (-24.0f)
#define VC_DENOISE_DEFAULT_SMOOTHING 0.5f
#define VC_DENOISE_DEFAULT_GATE_SNR_DB 6.0f
#define VC_DENOISE_DEFAULT_GATE_RANGE_DB 30.0f
#define VC_DENOISE_DEFAULT_LEARN_MS 1500.0f

#define VC_DENOISE_MIN_REDUCTION 1.0f
#define VC_DENOISE_MAX_REDUCTION 6.0f
#define VC_DENOISE_MIN_FLOOR_DB (-60.0f)
#define VC_DENOISE_MAX_SMOOTHING 0.95f
#define VC_DENOISE_MAX_GATE_SNR_DB 30.0f
#define VC_DENOISE_MAX_GATE_RANGE_DB 60.0f
#define VC_DENOISE_MIN_LEARN_MS 100.0f
#define VC_DENOISE_MAX_LEARN_MS 10000.0f
#define VC_DENOISE_GATE_HYSTERESIS_DB 3.0f
#define VC_DENOISE_GATE_RELEASE_MS 120.0f
#define VC_DENOISE_MAX_PROFILE_BYTES (2U * 1024U * 1024U)

/**
 * @brief Noise reduction settings.
 *
 * reduction: over-subtraction factor applied to the noise power.
 * floor_db: lowest per-bin gain (limits musical noise).
 * smoothing: per-bin gain smoothing across frames (0 = none).
 * gate_snr_db: frames whose power is below the profile power plus this
 *              margin are treated as silence.
 * gate_range_db: attenuation of silent frames (0 disables the gate).
 * learn_ms: noise print length captured at start when no profile is
 *           loaded; output is muted while learning.
 */
typedef struct {
    float reduction;
    float floor_db;
    float smoothing;
    float gate_snr_db;
    float gate_range_db;
    float learn_ms;
} vc_denoise_params_t;

typedef struct vc_denoise_s vc_denoise_t;

/** @brief Fill parameters with the documented defaults. NULL-safe. */
void vc_denoise_params_defaults(vc_denoise_params_t *params);

/**
 * @brief Create a noise reducer for @p nbins frequency bins.
 * @return Context or NULL for invalid bins/parameters/allocation.
 */
vc_denoise_t *vc_denoise_create(size_t nbins,
                                const vc_denoise_params_t *params);

/** @brief Release a noise reducer. NULL-safe. */
void vc_denoise_destroy(vc_denoise_t *denoise);

/**
 * @brief Per-frame spectral transform, compatible with vc_spectral_fn.
 *
 * Learns the noise print first (muting those frames), then applies
 * power spectral subtraction and the spectral gate to @p mag. Phases
 * are untouched. Frames with a bin count mismatch or non-finite or
 * negative magnitudes are muted.
 */
void vc_denoise_transform(float *mag, float *phase, size_t nbins,
                          uint32_t sample_rate, size_t hop, void *user);

/** @brief 1 when a noise profile is available, 0 otherwise. */
int vc_denoise_is_ready(const vc_denoise_t *denoise);

/**
 * @brief Parse a text noise profile (see spec for the format).
 * @return 0 on success; -1 on any malformed input (context unchanged).
 */
int vc_denoise_profile_parse(vc_denoise_t *denoise, const char *text,
                             size_t length);

/** @brief Write the ready profile to @p path. @return 0 or -1. */
int vc_denoise_save(const vc_denoise_t *denoise, const char *path);

/** @brief Load a profile file (at most 2 MiB). @return 0 or -1. */
int vc_denoise_load(vc_denoise_t *denoise, const char *path);

#ifdef __cplusplus
}
#endif

#endif
