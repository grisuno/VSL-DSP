#include "vc_level.h"

#include <math.h>
#include <stdlib.h>

struct vc_level_s {
    uint32_t sample_rate;
    float target_rms;
    float max_gain;
    float ceiling;
    float attack_alpha;
    float release_alpha;
    float limiter_release_alpha;
    float rms_squared;
    float gain;
    float limiter_gain;
    int agc_enabled;
};

static int config_valid(uint32_t sample_rate, const vc_level_config_t *config) {
    if (sample_rate < VC_AUDIO_MIN_SAMPLE_RATE ||
        sample_rate > VC_AUDIO_MAX_SAMPLE_RATE || !config) return 0;
    if (!isfinite(config->target_dbfs) ||
        !isfinite(config->max_gain_db) ||
        !isfinite(config->ceiling_dbfs) ||
        !isfinite(config->attack_ms) ||
        !isfinite(config->release_ms) ||
        !isfinite(config->limiter_release_ms)) return 0;
    if (config->target_dbfs < VC_LEVEL_MIN_TARGET_DBFS ||
        config->target_dbfs > VC_LEVEL_MAX_TARGET_DBFS ||
        config->max_gain_db < 0.0f ||
        config->max_gain_db > VC_LEVEL_MAX_GAIN_DB ||
        config->ceiling_dbfs < VC_LEVEL_MIN_CEILING_DBFS ||
        config->ceiling_dbfs > VC_LEVEL_MAX_CEILING_DBFS ||
        config->target_dbfs > config->ceiling_dbfs ||
        config->attack_ms < VC_LEVEL_MIN_TIME_MS ||
        config->attack_ms > VC_LEVEL_MAX_TIME_MS ||
        config->release_ms < VC_LEVEL_MIN_TIME_MS ||
        config->release_ms > VC_LEVEL_MAX_TIME_MS ||
        config->limiter_release_ms < VC_LEVEL_MIN_TIME_MS ||
        config->limiter_release_ms > VC_LEVEL_MAX_TIME_MS) return 0;
    return config->agc_enabled == 0 || config->agc_enabled == 1;
}

static float time_alpha(float milliseconds, uint32_t sample_rate) {
    double seconds = (double)milliseconds / 1000.0;
    return (float)exp(-1.0 / (seconds * (double)sample_rate));
}

void vc_level_config_defaults(vc_level_config_t *config) {
    if (!config) return;
    config->target_dbfs = VC_LEVEL_DEFAULT_TARGET_DBFS;
    config->max_gain_db = VC_LEVEL_DEFAULT_MAX_GAIN_DB;
    config->ceiling_dbfs = VC_LEVEL_DEFAULT_CEILING_DBFS;
    config->attack_ms = VC_LEVEL_DEFAULT_ATTACK_MS;
    config->release_ms = VC_LEVEL_DEFAULT_RELEASE_MS;
    config->limiter_release_ms = VC_LEVEL_DEFAULT_LIMITER_RELEASE_MS;
    config->agc_enabled = 1;
}

vc_level_t *vc_level_create(uint32_t sample_rate,
                            const vc_level_config_t *config) {
    if (!config_valid(sample_rate, config)) return NULL;
    vc_level_t *level = (vc_level_t *)calloc(1, sizeof(*level));
    if (!level) return NULL;

    level->sample_rate = sample_rate;
    level->target_rms = powf(10.0f, config->target_dbfs / 20.0f);
    level->max_gain = powf(10.0f, config->max_gain_db / 20.0f);
    level->ceiling = powf(10.0f, config->ceiling_dbfs / 20.0f);
    level->attack_alpha = time_alpha(config->attack_ms, sample_rate);
    level->release_alpha = time_alpha(config->release_ms, sample_rate);
    level->limiter_release_alpha = time_alpha(config->limiter_release_ms,
                                              sample_rate);
    level->rms_squared = level->target_rms * level->target_rms;
    level->gain = 1.0f;
    level->limiter_gain = 1.0f;
    level->agc_enabled = config->agc_enabled;
    return level;
}

void vc_level_destroy(vc_level_t *level) {
    free(level);
}

static void silence_block(float *samples, size_t count) {
    size_t i;
    for (i = 0; i < count; ++i) samples[i] = 0.0f;
}

int vc_level_process(vc_level_t *level, float *samples, size_t count) {
    if (!level || (!samples && count != 0U)) return -1;
    if (count == 0U) return 0;

    size_t i;
    double block_power = 0.0;
    for (i = 0; i < count; ++i) {
        if (!isfinite(samples[i]) ||
            fabsf(samples[i]) > VC_AUDIO_MAX_INTERNAL_SAMPLE) {
            silence_block(samples, count);
            level->rms_squared = level->target_rms * level->target_rms;
            level->gain = 1.0f;
            level->limiter_gain = 1.0f;
            return -1;
        }
        block_power += (double)samples[i] * (double)samples[i];
    }

    if (level->agc_enabled) {
        float block_rms_squared = (float)(block_power / (double)count);
        float detector_alpha = block_rms_squared > level->rms_squared
                             ? level->attack_alpha
                             : level->release_alpha;
        detector_alpha = powf(detector_alpha, (float)count);
        level->rms_squared = detector_alpha * level->rms_squared +
            (1.0f - detector_alpha) * block_rms_squared;
    }
    float desired_gain = 1.0f;
    if (level->agc_enabled) {
        float rms = sqrtf(level->rms_squared);
        if (rms > VC_LEVEL_RMS_FLOOR)
            desired_gain = level->target_rms / rms;
        if (desired_gain > level->max_gain) desired_gain = level->max_gain;
    }

    for (i = 0; i < count; ++i) {
        float input = samples[i];
        if (level->agc_enabled) {
            float gain_alpha = desired_gain < level->gain
                             ? level->attack_alpha
                             : level->release_alpha;
            level->gain = gain_alpha * level->gain +
                (1.0f - gain_alpha) * desired_gain;
        } else {
            level->gain = 1.0f;
        }

        float gained = input * level->gain;
        float magnitude = fabsf(gained);
        float desired_limiter = magnitude > level->ceiling
                              ? level->ceiling / magnitude : 1.0f;
        if (desired_limiter < level->limiter_gain) {
            level->limiter_gain = desired_limiter;
        } else {
            level->limiter_gain = level->limiter_release_alpha *
                level->limiter_gain +
                (1.0f - level->limiter_release_alpha) * desired_limiter;
        }
        float output = gained * level->limiter_gain;
        if (fabsf(output) > level->ceiling) {
            level->limiter_gain *= level->ceiling / fabsf(output);
            output = gained * level->limiter_gain;
        }
        samples[i] = output;
    }
    return 0;
}

float vc_level_current_gain_db(const vc_level_t *level) {
    if (!level || level->gain <= 0.0f) return 0.0f;
    return 20.0f * log10f(level->gain);
}
