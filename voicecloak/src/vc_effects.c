#include "vc_effects.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define VC_EFFECT_MAX_DELAY_MS 2000.0f
#define VC_REVERB_MAX_COMB_DELAY_MS 250.0f
#define VC_REVERB_MIN_DECAY_SECONDS 0.1f
#define VC_REVERB_MAX_DECAY_SECONDS 10.0f
#define VC_REVERB_MAX_FEEDBACK 0.95f

typedef struct {
    float *buffer;
    size_t length;
    size_t cursor;
    float feedback;
} vc_comb_t;

struct vc_effects_s {
    uint32_t sample_rate;
    vc_effects_params_t params;
    double phase;
    float lowpass_state;
    float *delay_buffer;
    size_t delay_length;
    size_t delay_cursor;
    vc_comb_t combs[VC_REVERB_COMB_COUNT];
    float phaser_x[VC_PHASER_STAGE_COUNT];
    float phaser_y[VC_PHASER_STAGE_COUNT];
};

static int finite_params(const vc_effects_params_t *p) {
    if (!p || !isfinite(p->amount) || !isfinite(p->rate_hz) ||
        !isfinite(p->low_hz) || !isfinite(p->high_hz) ||
        !isfinite(p->cutoff_hz) || !isfinite(p->delay_ms) ||
        !isfinite(p->depth_ms) || !isfinite(p->feedback) ||
        !isfinite(p->decay_seconds)) return 0;
    size_t i;
    for (i = 0; i < VC_REVERB_COMB_COUNT; ++i)
        if (!isfinite(p->comb_delay_ms[i])) return 0;
    return 1;
}

static int params_valid(uint32_t sample_rate, const vc_effects_params_t *p) {
    if (sample_rate < VC_AUDIO_MIN_SAMPLE_RATE ||
        sample_rate > VC_AUDIO_MAX_SAMPLE_RATE || !finite_params(p) ||
        p->amount < 0.0f ||
        p->amount > 1.0f) return 0;
    float nyquist = (float)sample_rate * 0.5f;
    switch (p->kind) {
        case VC_EFFECT_NONE:
            return 1;
        case VC_EFFECT_RING_MOD:
            return p->rate_hz > 0.0f && p->rate_hz < nyquist;
        case VC_EFFECT_UNDERWATER:
            return p->cutoff_hz > 0.0f && p->cutoff_hz < nyquist;
        case VC_EFFECT_PHASER:
            return p->rate_hz > 0.0f && p->rate_hz < nyquist &&
                   p->low_hz > 0.0f && p->high_hz > p->low_hz &&
                   p->high_hz < nyquist;
        case VC_EFFECT_SPACE:
            return p->rate_hz > 0.0f && p->rate_hz < nyquist &&
                   p->delay_ms > 0.0f && p->depth_ms >= 0.0f &&
                   p->delay_ms + p->depth_ms < VC_EFFECT_MAX_DELAY_MS &&
                   p->feedback >= 0.0f && p->feedback <= VC_REVERB_MAX_FEEDBACK;
        case VC_EFFECT_REVERB: {
            if (p->decay_seconds < VC_REVERB_MIN_DECAY_SECONDS ||
                p->decay_seconds > VC_REVERB_MAX_DECAY_SECONDS) return 0;
            size_t i;
            for (i = 0; i < VC_REVERB_COMB_COUNT; ++i) {
                if (p->comb_delay_ms[i] <= 0.0f ||
                    p->comb_delay_ms[i] > VC_REVERB_MAX_COMB_DELAY_MS)
                    return 0;
            }
            return 1;
        }
        default:
            return 0;
    }
}

static size_t samples_from_ms(float milliseconds, uint32_t sample_rate) {
    double count = ceil((double)milliseconds * (double)sample_rate / 1000.0);
    if (count < 1.0 || count > (double)(SIZE_MAX / sizeof(float))) return 0;
    return (size_t)count;
}

static void free_combs(vc_effects_t *fx) {
    size_t i;
    for (i = 0; i < VC_REVERB_COMB_COUNT; ++i) {
        free(fx->combs[i].buffer);
        fx->combs[i].buffer = NULL;
    }
}

vc_effects_t *vc_effects_create(uint32_t sample_rate,
                                const vc_effects_params_t *params) {
    if (!params_valid(sample_rate, params)) return NULL;
    vc_effects_t *fx = (vc_effects_t *)calloc(1, sizeof(*fx));
    if (!fx) return NULL;
    fx->sample_rate = sample_rate;
    fx->params = *params;

    if (params->kind == VC_EFFECT_SPACE) {
        size_t maximum = samples_from_ms(params->delay_ms + params->depth_ms,
                                         sample_rate);
        if (maximum == 0U || maximum > SIZE_MAX - 2U) {
            vc_effects_destroy(fx);
            return NULL;
        }
        fx->delay_length = maximum + 2U;
        fx->delay_buffer = (float *)calloc(fx->delay_length, sizeof(float));
        if (!fx->delay_buffer) {
            vc_effects_destroy(fx);
            return NULL;
        }
    } else if (params->kind == VC_EFFECT_REVERB) {
        size_t i;
        for (i = 0; i < VC_REVERB_COMB_COUNT; ++i) {
            size_t length = samples_from_ms(params->comb_delay_ms[i],
                                            sample_rate);
            if (length == 0U) {
                vc_effects_destroy(fx);
                return NULL;
            }
            fx->combs[i].buffer = (float *)calloc(length, sizeof(float));
            if (!fx->combs[i].buffer) {
                vc_effects_destroy(fx);
                return NULL;
            }
            fx->combs[i].length = length;
            double delay_seconds = (double)length / (double)sample_rate;
            fx->combs[i].feedback = (float)pow(
                10.0, -3.0 * delay_seconds / (double)params->decay_seconds);
        }
    }
    return fx;
}

void vc_effects_destroy(vc_effects_t *effects) {
    if (!effects) return;
    free(effects->delay_buffer);
    free_combs(effects);
    free(effects);
}

static void reset_state(vc_effects_t *fx) {
    fx->phase = 0.0;
    fx->lowpass_state = 0.0f;
    fx->delay_cursor = 0U;
    if (fx->delay_buffer)
        memset(fx->delay_buffer, 0, fx->delay_length * sizeof(float));
    size_t i;
    for (i = 0; i < VC_REVERB_COMB_COUNT; ++i) {
        fx->combs[i].cursor = 0U;
        if (fx->combs[i].buffer)
            memset(fx->combs[i].buffer, 0,
                   fx->combs[i].length * sizeof(float));
    }
    memset(fx->phaser_x, 0, sizeof(fx->phaser_x));
    memset(fx->phaser_y, 0, sizeof(fx->phaser_y));
}

static float process_space(vc_effects_t *fx, float input, double lfo) {
    const vc_effects_params_t *p = &fx->params;
    float delay = (p->delay_ms + p->depth_ms * (float)lfo) *
                  (float)fx->sample_rate / 1000.0f;
    if (delay < 1.0f) delay = 1.0f;
    size_t whole = (size_t)delay;
    float fraction = delay - (float)whole;
    size_t read0 = (fx->delay_cursor + fx->delay_length - whole) %
                   fx->delay_length;
    size_t read1 = read0 == 0U ? fx->delay_length - 1U : read0 - 1U;
    float delayed = fx->delay_buffer[read0] * (1.0f - fraction) +
                    fx->delay_buffer[read1] * fraction;
    fx->delay_buffer[fx->delay_cursor] = input + delayed * p->feedback;
    fx->delay_cursor = (fx->delay_cursor + 1U) % fx->delay_length;
    return input * (1.0f - p->amount) + delayed * p->amount;
}

static float process_reverb(vc_effects_t *fx, float input) {
    float wet = 0.0f;
    size_t i;
    for (i = 0; i < VC_REVERB_COMB_COUNT; ++i) {
        vc_comb_t *comb = &fx->combs[i];
        float delayed = comb->buffer[comb->cursor];
        comb->buffer[comb->cursor] = input + delayed * comb->feedback;
        comb->cursor = (comb->cursor + 1U) % comb->length;
        wet += delayed;
    }
    wet /= (float)VC_REVERB_COMB_COUNT;
    return input * (1.0f - fx->params.amount) + wet * fx->params.amount;
}

static float process_phaser(vc_effects_t *fx, float input, double lfo) {
    const vc_effects_params_t *p = &fx->params;
    float frequency = p->low_hz +
        (p->high_hz - p->low_hz) * (float)(0.5 + 0.5 * lfo);
    double tangent = tan(M_PI * (double)frequency / (double)fx->sample_rate);
    float coefficient = (float)((1.0 - tangent) / (1.0 + tangent));
    float phased = input;
    size_t i;
    for (i = 0; i < VC_PHASER_STAGE_COUNT; ++i) {
        float output = coefficient * phased + fx->phaser_x[i] -
                       coefficient * fx->phaser_y[i];
        fx->phaser_x[i] = phased;
        fx->phaser_y[i] = output;
        phased = output;
    }
    return input * (1.0f - p->amount) + phased * p->amount;
}

static float process_one(vc_effects_t *fx, float input) {
    const vc_effects_params_t *p = &fx->params;
    double lfo = sin(fx->phase);
    float output = input;
    switch (p->kind) {
        case VC_EFFECT_NONE:
            break;
        case VC_EFFECT_RING_MOD: {
            float carrier = (float)sin(fx->phase);
            output = input * ((1.0f - p->amount) + p->amount * carrier);
            break;
        }
        case VC_EFFECT_UNDERWATER: {
            float alpha = 1.0f - expf(-2.0f * (float)M_PI * p->cutoff_hz /
                                      (float)fx->sample_rate);
            fx->lowpass_state += alpha * (input - fx->lowpass_state);
            output = input * (1.0f - p->amount) +
                     fx->lowpass_state * p->amount;
            break;
        }
        case VC_EFFECT_PHASER:
            output = process_phaser(fx, input, lfo);
            break;
        case VC_EFFECT_SPACE:
            output = process_space(fx, input, lfo);
            break;
        case VC_EFFECT_REVERB:
            output = process_reverb(fx, input);
            break;
        default:
            return NAN;
    }
    fx->phase += 2.0 * M_PI * (double)p->rate_hz /
                 (double)fx->sample_rate;
    if (fx->phase >= 2.0 * M_PI) fx->phase -= 2.0 * M_PI;
    return output;
}

int vc_effects_process(vc_effects_t *effects, float *samples, size_t count) {
    if (!effects || (!samples && count != 0U)) return -1;
    if (count == 0U) return 0;
    size_t i;
    for (i = 0; i < count; ++i) {
        if (!isfinite(samples[i]) ||
            fabsf(samples[i]) > VC_AUDIO_MAX_INTERNAL_SAMPLE) {
            size_t j;
            for (j = 0; j < count; ++j) samples[j] = 0.0f;
            reset_state(effects);
            return -1;
        }
    }
    for (i = 0; i < count; ++i) {
        float output = process_one(effects, samples[i]);
        if (!isfinite(output) ||
            fabsf(output) > VC_AUDIO_MAX_INTERNAL_SAMPLE) {
            size_t j;
            for (j = 0; j < count; ++j) samples[j] = 0.0f;
            reset_state(effects);
            return -1;
        }
        samples[i] = output;
    }
    return 0;
}
