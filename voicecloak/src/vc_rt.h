#ifndef VC_RT_H
#define VC_RT_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Real-time cloak parameters (already resolved to scalars).
 *
 * pitch_ratio 1.0 = no shift; formant_factor 1.0 = no shift;
 * scramble_intensity 0.0 = none.
 */
typedef struct {
    float pitch_ratio;
    float formant_factor;
    float scramble_intensity;
} vc_rt_params_t;

/**
 * @brief Phase-vocoder transform context (per-bin state across frames).
 */
typedef struct vc_rt_ctx_s vc_rt_ctx_t;

/**
 * @brief Create a transform context sized for @p nbins frequency bins.
 * @return Context or NULL on allocation failure / nbins < 2.
 */
vc_rt_ctx_t *vc_rt_create(size_t nbins, vc_rt_params_t params);

/** @brief Release a transform context. NULL-safe. */
void vc_rt_destroy(vc_rt_ctx_t *c);

/** @brief Reset cross-frame phase state (e.g. on stream restart). */
void vc_rt_reset(vc_rt_ctx_t *c);

/**
 * @brief Per-frame transform, compatible with vc_spectral_fn.
 * @param user Must be a vc_rt_ctx_t* created with matching nbins.
 *
 * Applies frequency-domain pitch shift (constant rate), formant
 * envelope scaling, and spectral scrambling, then rewrites mag/phase
 * to the synthesis spectrum.
 */
void vc_rt_transform(float *mag, float *phase, size_t nbins,
                     uint32_t sample_rate, size_t hop, void *user);

/**
 * @brief Convert a semitone shift to a pitch ratio (2^(semitones/12)).
 */
float vc_rt_semitones_to_ratio(float semitones);

/**
 * @brief Derive cloak parameters from three 32-byte PRNG seeds.
 * @param pitch_seed    32-byte seed.
 * @param formant_seed  32-byte seed.
 * @param spectral_seed 32-byte seed.
 * @param witness_mode  Non-zero for the aggressive witness ranges.
 * @param out           [out] resolved parameters.
 * @return 0 on success, -1 on error. Ranges mirror vc_dsp_cloak.
 */
int vc_rt_derive(const unsigned char *pitch_seed,
                 const unsigned char *formant_seed,
                 const unsigned char *spectral_seed,
                 int witness_mode, vc_rt_params_t *out);

#ifdef __cplusplus
}
#endif

#endif
