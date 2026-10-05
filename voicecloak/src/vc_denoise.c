#include "vc_denoise.h"

#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VC_DENOISE_MAGIC "VCNOISE"
#define VC_DENOISE_VERSION 1UL

struct vc_denoise_s {
    size_t nbins;
    vc_denoise_params_t p;
    float floor_power;
    float gate_range;
    float *noise_power;
    double *accum;
    float *gain;
    double noise_sum;
    size_t learned_frames;
    size_t learn_target;
    uint32_t profile_rate;
    int ready;
    int gate_open;
    float gate_gain;
};

void vc_denoise_params_defaults(vc_denoise_params_t *params) {
    if (!params) return;
    params->reduction = VC_DENOISE_DEFAULT_REDUCTION;
    params->floor_db = VC_DENOISE_DEFAULT_FLOOR_DB;
    params->smoothing = VC_DENOISE_DEFAULT_SMOOTHING;
    params->gate_snr_db = VC_DENOISE_DEFAULT_GATE_SNR_DB;
    params->gate_range_db = VC_DENOISE_DEFAULT_GATE_RANGE_DB;
    params->learn_ms = VC_DENOISE_DEFAULT_LEARN_MS;
}

static int params_valid(const vc_denoise_params_t *p) {
    if (!p || !isfinite(p->reduction) || !isfinite(p->floor_db) ||
        !isfinite(p->smoothing) || !isfinite(p->gate_snr_db) ||
        !isfinite(p->gate_range_db) || !isfinite(p->learn_ms)) return 0;
    return p->reduction >= VC_DENOISE_MIN_REDUCTION &&
           p->reduction <= VC_DENOISE_MAX_REDUCTION &&
           p->floor_db >= VC_DENOISE_MIN_FLOOR_DB && p->floor_db <= 0.0f &&
           p->smoothing >= 0.0f && p->smoothing <= VC_DENOISE_MAX_SMOOTHING &&
           p->gate_snr_db >= 0.0f &&
           p->gate_snr_db <= VC_DENOISE_MAX_GATE_SNR_DB &&
           p->gate_range_db >= 0.0f &&
           p->gate_range_db <= VC_DENOISE_MAX_GATE_RANGE_DB &&
           p->learn_ms >= VC_DENOISE_MIN_LEARN_MS &&
           p->learn_ms <= VC_DENOISE_MAX_LEARN_MS;
}

/* Restart the per-bin gains and close the gate: right after a profile
 * appears the user is assumed silent, so nothing leaks out. */
static void reset_tracking(vc_denoise_t *dn) {
    size_t b;
    for (b = 0; b < dn->nbins; ++b) dn->gain[b] = 1.0f;
    dn->gate_open = 0;
    dn->gate_gain = dn->gate_range;
}

static void restart_learning(vc_denoise_t *dn) {
    memset(dn->accum, 0, dn->nbins * sizeof(double));
    dn->learned_frames = 0U;
    dn->learn_target = 0U;
    dn->ready = 0;
}

vc_denoise_t *vc_denoise_create(size_t nbins,
                                const vc_denoise_params_t *params) {
    if (nbins < 2U || !params_valid(params)) return NULL;
    vc_denoise_t *dn = (vc_denoise_t *)calloc(1, sizeof(*dn));
    if (!dn) return NULL;
    dn->nbins = nbins;
    dn->p = *params;
    dn->floor_power = powf(10.0f, params->floor_db / 10.0f);
    dn->gate_range = powf(10.0f, -params->gate_range_db / 20.0f);
    dn->noise_power = (float *)calloc(nbins, sizeof(float));
    dn->accum = (double *)calloc(nbins, sizeof(double));
    dn->gain = (float *)calloc(nbins, sizeof(float));
    if (!dn->noise_power || !dn->accum || !dn->gain) {
        vc_denoise_destroy(dn);
        return NULL;
    }
    restart_learning(dn);
    reset_tracking(dn);
    return dn;
}

void vc_denoise_destroy(vc_denoise_t *denoise) {
    if (!denoise) return;
    free(denoise->noise_power);
    free(denoise->accum);
    free(denoise->gain);
    free(denoise);
}

int vc_denoise_is_ready(const vc_denoise_t *denoise) {
    return denoise && denoise->ready ? 1 : 0;
}

static void mute(float *mag, size_t nbins) {
    memset(mag, 0, nbins * sizeof(float));
}

static void install_profile(vc_denoise_t *dn, uint32_t sample_rate) {
    size_t b;
    dn->noise_sum = 0.0;
    for (b = 0; b < dn->nbins; ++b) dn->noise_sum += dn->noise_power[b];
    dn->profile_rate = sample_rate;
    dn->ready = 1;
    reset_tracking(dn);
}

static void learn(vc_denoise_t *dn, float *mag, uint32_t sample_rate,
                  size_t hop) {
    size_t b;
    if (dn->learn_target == 0U) {
        double frames = ceil((double)dn->p.learn_ms * (double)sample_rate /
                             (1000.0 * (double)hop));
        dn->learn_target = frames < 1.0 ? 1U : (size_t)frames;
    }
    for (b = 0; b < dn->nbins; ++b)
        dn->accum[b] += (double)mag[b] * (double)mag[b];
    dn->learned_frames++;
    mute(mag, dn->nbins);
    if (dn->learned_frames < dn->learn_target) return;
    for (b = 0; b < dn->nbins; ++b)
        dn->noise_power[b] = (float)(dn->accum[b] /
                                     (double)dn->learned_frames);
    install_profile(dn, sample_rate);
}

static void update_gate(vc_denoise_t *dn, double frame_power,
                        uint32_t sample_rate, size_t hop) {
    if (dn->p.gate_range_db == 0.0f) {
        dn->gate_gain = 1.0f;
        return;
    }
    double open_at = dn->noise_sum * pow(10.0, (double)dn->p.gate_snr_db / 10.0);
    double close_at = open_at *
        pow(10.0, -(double)VC_DENOISE_GATE_HYSTERESIS_DB / 10.0);
    if (frame_power >= open_at) dn->gate_open = 1;
    else if (frame_power < close_at) dn->gate_open = 0;
    float target = dn->gate_open ? 1.0f : dn->gate_range;
    if (target >= dn->gate_gain) {
        dn->gate_gain = target;
        return;
    }
    float release = (float)exp(-(double)hop /
        ((double)sample_rate * (double)VC_DENOISE_GATE_RELEASE_MS / 1000.0));
    dn->gate_gain *= release;
    if (dn->gate_gain < target) dn->gate_gain = target;
}

void vc_denoise_transform(float *mag, float *phase, size_t nbins,
                          uint32_t sample_rate, size_t hop, void *user) {
    (void)phase;
    vc_denoise_t *dn = (vc_denoise_t *)user;
    if (!mag || nbins == 0U) return;
    if (!dn || nbins != dn->nbins || sample_rate == 0U || hop == 0U) {
        mute(mag, nbins);
        return;
    }
    size_t b;
    double frame_power = 0.0;
    for (b = 0; b < nbins; ++b) {
        if (!isfinite(mag[b]) || mag[b] < 0.0f) {
            mute(mag, nbins);
            return;
        }
        frame_power += (double)mag[b] * (double)mag[b];
    }
    if (dn->ready && dn->profile_rate != sample_rate) restart_learning(dn);
    if (!dn->ready) {
        learn(dn, mag, sample_rate, hop);
        return;
    }

    update_gate(dn, frame_power, sample_rate, hop);
    float s = dn->p.smoothing;
    for (b = 0; b < nbins; ++b) {
        float power = mag[b] * mag[b];
        float raw = dn->floor_power;
        if (power > 0.0f) {
            float kept = 1.0f - dn->p.reduction * dn->noise_power[b] / power;
            if (kept > raw) raw = kept;
        }
        dn->gain[b] = s * dn->gain[b] + (1.0f - s) * sqrtf(raw);
        mag[b] *= dn->gain[b] * dn->gate_gain;
    }
}

static int parse_ulong(const char **cursor, unsigned long *out) {
    const char *p = *cursor;
    if (*p < '0' || *p > '9') return -1;
    errno = 0;
    char *end = NULL;
    unsigned long value = strtoul(p, &end, 10);
    if (errno != 0 || end == p) return -1;
    *out = value;
    *cursor = end;
    return 0;
}

static int parse_header(const char **cursor, unsigned long *rate,
                        unsigned long *nbins) {
    const size_t magic_len = sizeof(VC_DENOISE_MAGIC) - 1U;
    const char *p = *cursor;
    unsigned long version = 0UL;
    if (strncmp(p, VC_DENOISE_MAGIC, magic_len) != 0) return -1;
    p += magic_len;
    if (*p++ != ' ' || parse_ulong(&p, &version) != 0 ||
        version != VC_DENOISE_VERSION) return -1;
    if (*p++ != ' ' || parse_ulong(&p, rate) != 0) return -1;
    if (*p++ != ' ' || parse_ulong(&p, nbins) != 0) return -1;
    if (*p++ != '\n') return -1;
    *cursor = p;
    return 0;
}

int vc_denoise_profile_parse(vc_denoise_t *denoise, const char *text,
                             size_t length) {
    if (!denoise || !text || length == 0U ||
        length > VC_DENOISE_MAX_PROFILE_BYTES) return -1;
    char *copy = (char *)malloc(length + 1U);
    float *values = (float *)malloc(denoise->nbins * sizeof(float));
    int rc = -1;
    if (!copy || !values) goto done;
    memcpy(copy, text, length);
    copy[length] = '\0';
    if (strlen(copy) != length) goto done;

    const char *p = copy;
    unsigned long rate = 0UL, nbins = 0UL;
    if (parse_header(&p, &rate, &nbins) != 0) goto done;
    if (rate < VC_AUDIO_MIN_SAMPLE_RATE || rate > VC_AUDIO_MAX_SAMPLE_RATE ||
        nbins != (unsigned long)denoise->nbins) goto done;

    size_t b;
    for (b = 0; b < denoise->nbins; ++b) {
        if ((*p < '0' || *p > '9') && *p != '.') goto done;
        errno = 0;
        char *end = NULL;
        float value = strtof(p, &end);
        if (errno != 0 || end == p || !isfinite(value) || value < 0.0f)
            goto done;
        if (*end != '\n' && !(*end == '\0' && b + 1U == denoise->nbins))
            goto done;
        values[b] = value;
        p = *end == '\n' ? end + 1 : end;
    }
    if (*p != '\0') goto done;

    memcpy(denoise->noise_power, values, denoise->nbins * sizeof(float));
    install_profile(denoise, (uint32_t)rate);
    rc = 0;
done:
    free(copy);
    free(values);
    return rc;
}

int vc_denoise_save(const vc_denoise_t *denoise, const char *path) {
    if (!denoise || !denoise->ready || !path) return -1;
    FILE *f = fopen(path, "w");
    if (!f) return -1;
    int ok = fprintf(f, "%s %lu %lu %lu\n", VC_DENOISE_MAGIC,
                     VC_DENOISE_VERSION, (unsigned long)denoise->profile_rate,
                     (unsigned long)denoise->nbins) > 0;
    size_t b;
    for (b = 0; ok && b < denoise->nbins; ++b)
        ok = fprintf(f, "%.9g\n", (double)denoise->noise_power[b]) > 0;
    if (fclose(f) != 0) ok = 0;
    return ok ? 0 : -1;
}

int vc_denoise_load(vc_denoise_t *denoise, const char *path) {
    if (!denoise || !path) return -1;
    FILE *f = fopen(path, "rb");
    if (!f) return -1;
    char *buffer = (char *)malloc(VC_DENOISE_MAX_PROFILE_BYTES + 1U);
    int rc = -1;
    if (buffer) {
        size_t got = fread(buffer, 1U, VC_DENOISE_MAX_PROFILE_BYTES + 1U, f);
        if (!ferror(f) && got <= VC_DENOISE_MAX_PROFILE_BYTES)
            rc = vc_denoise_profile_parse(denoise, buffer, got);
    }
    free(buffer);
    fclose(f);
    return rc;
}
