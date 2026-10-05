#include "vc_presets.h"

#include <string.h>

typedef struct {
    const char *name;
    float semitones;
    float formant_factor;
    float scramble_intensity;
    int robotize;
    vc_effects_params_t effects;
    vc_eq_params_t eq;
    float saturation_drive;
} vc_preset_definition_t;

#define NO_EFFECT { .kind = VC_EFFECT_NONE }

static const vc_preset_definition_t presets[] = {
    {
        .name = "robot",
        .semitones = 0.0f,
        .formant_factor = 1.0f,
        .scramble_intensity = 0.0f,
        .robotize = 1,
        .effects = {
            .kind = VC_EFFECT_METALLIC,
            .amount = 0.45f,
            .delay_ms = 7.0f,
            .feedback = 0.6f,
            .ring_amount = 0.3f,
            .rate_hz = 93.75f,
            .waveform = VC_RING_WAVE_SQUARE
        },
        .eq = {
            .highpass_hz = 100.0f,
            .presence_hz = 3000.0f,
            .presence_gain_db = 5.0f,
            .presence_q = 1.0f
        },
        .saturation_drive = 2.0f
    },
    {
        .name = "monster",
        .semitones = -8.0f,
        .formant_factor = 0.78f,
        .scramble_intensity = 0.15f,
        .effects = NO_EFFECT
    },
    {
        .name = "woman",
        .semitones = 5.0f,
        .formant_factor = 1.15f,
        .scramble_intensity = 0.10f,
        .effects = NO_EFFECT
    },
    {
        .name = "man",
        .semitones = -3.0f,
        .formant_factor = 0.90f,
        .scramble_intensity = 0.08f,
        .effects = NO_EFFECT
    },
    {
        .name = "space",
        .semitones = 2.0f,
        .formant_factor = 1.05f,
        .scramble_intensity = 0.20f,
        .effects = {
            .kind = VC_EFFECT_SPACE,
            .amount = 0.45f,
            .rate_hz = 0.30f,
            .delay_ms = 24.0f,
            .depth_ms = 8.0f,
            .feedback = 0.25f
        }
    },
    {
        .name = "underwater",
        .semitones = -1.0f,
        .formant_factor = 0.82f,
        .scramble_intensity = 0.10f,
        .effects = {
            .kind = VC_EFFECT_UNDERWATER,
            .amount = 1.0f,
            .cutoff_hz = 900.0f
        }
    },
    {
        .name = "church",
        .semitones = 0.0f,
        .formant_factor = 1.0f,
        .scramble_intensity = 0.10f,
        .effects = {
            .kind = VC_EFFECT_REVERB,
            .amount = 0.42f,
            .decay_seconds = 2.4f,
            .comb_delay_ms = { 28.7f, 33.1f, 36.7f, 40.9f }
        }
    },
    {
        .name = "phaser",
        .semitones = 1.0f,
        .formant_factor = 1.0f,
        .scramble_intensity = 0.12f,
        .effects = {
            .kind = VC_EFFECT_PHASER,
            .amount = 0.70f,
            .rate_hz = 0.35f,
            .low_hz = 250.0f,
            .high_hz = 1600.0f
        }
    }
};

int vc_preset_lookup(const char *name, vc_preset_t *out) {
    if (!name || !out) return -1;
    size_t i;
    for (i = 0; i < sizeof(presets) / sizeof(presets[0]); ++i) {
        if (strcmp(name, presets[i].name) == 0) {
            out->name = presets[i].name;
            out->cloak.pitch_ratio = vc_rt_semitones_to_ratio(
                presets[i].semitones);
            out->cloak.formant_factor = presets[i].formant_factor;
            out->cloak.scramble_intensity = presets[i].scramble_intensity;
            out->cloak.robotize = presets[i].robotize;
            out->effects = presets[i].effects;
            out->eq = presets[i].eq;
            out->saturation_drive = presets[i].saturation_drive;
            return 0;
        }
    }
    return -1;
}
