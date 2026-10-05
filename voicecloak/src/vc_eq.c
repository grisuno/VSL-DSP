#include "vc_eq.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define VC_EQ_BUTTERWORTH_Q 0.70710678118654752440

typedef struct {
    int active;
    double b0, b1, b2, a1, a2;
    double z1, z2;
} vc_biquad_t;

struct vc_eq_s {
    vc_biquad_t highpass;
    vc_biquad_t presence;
};

static int params_valid(uint32_t sample_rate, const vc_eq_params_t *p) {
    if (!p || sample_rate < VC_AUDIO_MIN_SAMPLE_RATE ||
        sample_rate > VC_AUDIO_MAX_SAMPLE_RATE) return 0;
    if (!isfinite(p->highpass_hz) || !isfinite(p->presence_hz) ||
        !isfinite(p->presence_gain_db) || !isfinite(p->presence_q))
        return 0;
    float nyquist = (float)sample_rate * 0.5f;
    if (p->highpass_hz < 0.0f || p->highpass_hz >= nyquist) return 0;
    if (p->presence_gain_db < -VC_EQ_MAX_GAIN_DB ||
        p->presence_gain_db > VC_EQ_MAX_GAIN_DB) return 0;
    if (p->presence_gain_db == 0.0f) return 1;
    return p->presence_hz > 0.0f && p->presence_hz < nyquist &&
           p->presence_q >= VC_EQ_MIN_Q && p->presence_q <= VC_EQ_MAX_Q;
}

static void normalize(vc_biquad_t *f, double b0, double b1, double b2,
                      double a0, double a1, double a2) {
    f->active = 1;
    f->b0 = b0 / a0;
    f->b1 = b1 / a0;
    f->b2 = b2 / a0;
    f->a1 = a1 / a0;
    f->a2 = a2 / a0;
}

static void design_highpass(vc_biquad_t *f, double hz, double rate) {
    double w0 = 2.0 * M_PI * hz / rate;
    double cw = cos(w0);
    double alpha = sin(w0) / (2.0 * VC_EQ_BUTTERWORTH_Q);
    normalize(f, (1.0 + cw) / 2.0, -(1.0 + cw), (1.0 + cw) / 2.0,
              1.0 + alpha, -2.0 * cw, 1.0 - alpha);
}

static void design_peaking(vc_biquad_t *f, double hz, double gain_db,
                           double q, double rate) {
    double a = pow(10.0, gain_db / 40.0);
    double w0 = 2.0 * M_PI * hz / rate;
    double cw = cos(w0);
    double alpha = sin(w0) / (2.0 * q);
    normalize(f, 1.0 + alpha * a, -2.0 * cw, 1.0 - alpha * a,
              1.0 + alpha / a, -2.0 * cw, 1.0 - alpha / a);
}

vc_eq_t *vc_eq_create(uint32_t sample_rate, const vc_eq_params_t *params) {
    if (!params_valid(sample_rate, params)) return NULL;
    vc_eq_t *eq = (vc_eq_t *)calloc(1, sizeof(*eq));
    if (!eq) return NULL;
    double rate = (double)sample_rate;
    if (params->highpass_hz > 0.0f)
        design_highpass(&eq->highpass, (double)params->highpass_hz, rate);
    if (params->presence_gain_db != 0.0f)
        design_peaking(&eq->presence, (double)params->presence_hz,
                       (double)params->presence_gain_db,
                       (double)params->presence_q, rate);
    return eq;
}

void vc_eq_destroy(vc_eq_t *eq) {
    free(eq);
}

static double run_biquad(vc_biquad_t *f, double x) {
    if (!f->active) return x;
    double y = f->b0 * x + f->z1;
    f->z1 = f->b1 * x - f->a1 * y + f->z2;
    f->z2 = f->b2 * x - f->a2 * y;
    return y;
}

static void fail_closed(vc_eq_t *eq, float *samples, size_t count) {
    memset(samples, 0, count * sizeof(float));
    eq->highpass.z1 = eq->highpass.z2 = 0.0;
    eq->presence.z1 = eq->presence.z2 = 0.0;
}

int vc_eq_process(vc_eq_t *eq, float *samples, size_t count) {
    if (!eq || (!samples && count != 0U)) return -1;
    size_t i;
    for (i = 0; i < count; ++i) {
        if (!isfinite(samples[i]) ||
            fabsf(samples[i]) > VC_AUDIO_MAX_INTERNAL_SAMPLE) {
            fail_closed(eq, samples, count);
            return -1;
        }
    }
    for (i = 0; i < count; ++i) {
        double y = run_biquad(&eq->presence,
                              run_biquad(&eq->highpass, (double)samples[i]));
        if (!isfinite(y) || fabs(y) > (double)VC_AUDIO_MAX_INTERNAL_SAMPLE) {
            fail_closed(eq, samples, count);
            return -1;
        }
        samples[i] = (float)y;
    }
    return 0;
}
