#ifndef VC_EFFECTS_H
#define VC_EFFECTS_H

#include <stddef.h>
#include <stdint.h>
#include "vc_audio_config.h"

#ifdef __cplusplus
extern "C" {
#endif

#define VC_REVERB_COMB_COUNT 4U
#define VC_PHASER_STAGE_COUNT 6U

typedef enum {
    VC_EFFECT_NONE = 0,
    VC_EFFECT_RING_MOD,
    VC_EFFECT_UNDERWATER,
    VC_EFFECT_PHASER,
    VC_EFFECT_SPACE,
    VC_EFFECT_REVERB,
    VC_EFFECT_METALLIC
} vc_effect_kind_t;

/** @brief Ring-modulation carrier shape (SQUARE is a soft square). */
typedef enum {
    VC_RING_WAVE_SINE = 0,
    VC_RING_WAVE_SQUARE
} vc_ring_waveform_t;

/**
 * @brief Effect selection and values (supplied by the preset table).
 *
 * RING_MOD reads ring_amount/rate_hz/waveform. METALLIC is a short
 * feedback comb (delay_ms, feedback, wet mix amount) followed by the
 * same optional ring modulation (ring_amount 0 disables it).
 */
typedef struct {
    vc_effect_kind_t kind;
    float amount;
    float ring_amount;
    vc_ring_waveform_t waveform;
    float rate_hz;
    float low_hz;
    float high_hz;
    float cutoff_hz;
    float delay_ms;
    float depth_ms;
    float feedback;
    float decay_seconds;
    float comb_delay_ms[VC_REVERB_COMB_COUNT];
} vc_effects_params_t;

typedef struct vc_effects_s vc_effects_t;

/**
 * @brief Create one stateful, sample-domain effect context.
 * @return Context or NULL for invalid sample rate/parameters/allocation.
 */
vc_effects_t *vc_effects_create(uint32_t sample_rate,
                                const vc_effects_params_t *params);

/** @brief Release effect state and delay lines. NULL-safe. */
void vc_effects_destroy(vc_effects_t *effects);

/**
 * @brief Process mono samples in place, preserving state between blocks.
 * @return 0 on success; nonzero on invalid input. Invalid blocks are
 *         silenced fail-closed.
 */
int vc_effects_process(vc_effects_t *effects, float *samples, size_t count);

#ifdef __cplusplus
}
#endif

#endif
