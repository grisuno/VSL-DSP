#include "avatar_logic.h"

#include <math.h>

float avatar_rms_f32(const float *x, size_t n)
{
    double acc;
    size_t i;

    if (x == NULL || n == 0U) {
        return 0.0f;
    }
    acc = 0.0;
    for (i = 0U; i < n; i++) {
        double v = (double)x[i];
        if (!isfinite(v)) {
            continue;
        }
        acc += v * v;
    }
    if (!isfinite(acc) || acc <= 0.0) {
        return 0.0f;
    }
    return (float)sqrt(acc / (double)n);
}

float avatar_rms_to_dbfs(float rms)
{
    double v = (double)rms;

    if (!isfinite(v) || v <= 0.0) {
        return -120.0f;
    }
    v = 20.0 * log10(v);
    if (!isfinite(v) || v < -120.0) {
        return -120.0f;
    }
    return (float)v;
}

float avatar_zcr_f32(const float *x, size_t n)
{
    size_t crosses;
    size_t i;

    if (x == NULL || n < 2U) {
        return 0.0f;
    }
    crosses = 0U;
    for (i = 1U; i < n; i++) {
        double a = (double)x[i - 1U];
        double b = (double)x[i];
        int sa;
        int sb;

        if (!isfinite(a) || !isfinite(b)) {
            continue;
        }
        sa = (a >= 0.0) ? 1 : -1;
        sb = (b >= 0.0) ? 1 : -1;
        if (sa != sb) {
            crosses++;
        }
    }
    return (float)crosses / (float)(n - 1U);
}

float avatar_hf_ratio_f32(const float *x, size_t n)
{
    double rms;
    double rms_d;
    double acc_d;
    size_t i;

    if (x == NULL || n < 2U) {
        return 0.0f;
    }
    rms = (double)avatar_rms_f32(x, n);
    acc_d = 0.0;
    for (i = 1U; i < n; i++) {
        double a = (double)x[i - 1U];
        double b = (double)x[i];
        double d;

        if (!isfinite(a) || !isfinite(b)) {
            continue;
        }
        d = b - a;
        acc_d += d * d;
    }
    if (!isfinite(acc_d)) {
        return 0.0f;
    }
    rms_d = sqrt(acc_d / (double)(n - 1U));
    {
        double ratio = rms_d / (rms + 1e-9);
        if (!isfinite(ratio) || ratio < 0.0) {
            return 0.0f;
        }
        if (ratio > 2.0) {
            return 2.0f;
        }
        return (float)ratio;
    }
}

avatar_state_t avatar_classify(float rms_db, float zcr, float hf,
                               const avatar_cfg_t *c)
{
    if (c == NULL) {
        return AVATAR_CLOSED;
    }
    if (!isfinite((double)rms_db) || rms_db < c->silence_db) {
        return AVATAR_CLOSED;
    }
    if (!isfinite((double)zcr) || !isfinite((double)hf)) {
        return AVATAR_OPEN;
    }
    if (zcr >= c->zcr_thr && hf >= c->hf_thr) {
        return AVATAR_SIBILANT;
    }
    return AVATAR_OPEN;
}

void avatar_smooth_init(avatar_smooth_t *s, avatar_state_t init, uint64_t now_ms,
                        unsigned int hold_ms)
{
    if (s == NULL) {
        return;
    }
    s->shown = init;
    s->last_change_ms = now_ms;
    s->hold_ms = hold_ms;
}

avatar_state_t avatar_smooth(avatar_smooth_t *s, avatar_state_t inst,
                             uint64_t now_ms)
{
    if (s == NULL) {
        return AVATAR_CLOSED;
    }
    if (inst != AVATAR_CLOSED) {
        s->shown = inst;
        s->last_change_ms = now_ms;
        return s->shown;
    }
    if (s->shown == AVATAR_CLOSED) {
        return AVATAR_CLOSED;
    }
    if (now_ms < s->last_change_ms) {
        s->last_change_ms = now_ms;
        return s->shown;
    }
    if ((now_ms - s->last_change_ms) >= (uint64_t)s->hold_ms) {
        s->shown = AVATAR_CLOSED;
        s->last_change_ms = now_ms;
    }
    return s->shown;
}

const char *avatar_state_name(avatar_state_t st)
{
    switch (st) {
    case AVATAR_OPEN:
        return "OPEN";
    case AVATAR_SIBILANT:
        return "SIBILANT";
    case AVATAR_CLOSED:
    default:
        return "CLOSED";
    }
}
