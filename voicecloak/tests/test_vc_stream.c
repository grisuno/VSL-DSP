#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "vc_stream.h"
#include "vc_rt.h"
#include "vc_fft.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define SR 48000U

static void gen_sines(float *buf, size_t n, uint32_t sr,
                      const float *freqs, const float *amps, size_t nf) {
    size_t i, k;
    for (i = 0; i < n; ++i) {
        float s = 0.0f;
        for (k = 0; k < nf; ++k)
            s += amps[k] * sinf(2.0f * (float)M_PI * freqs[k] *
                                (float)i / (float)sr);
        buf[i] = s;
    }
}

static float dominant_freq(const float *x, size_t n, uint32_t sr) {
    size_t nf = 8192;
    if (n < nf) nf = 1024;
    float *re = (float *)calloc(nf, sizeof(float));
    float *im = (float *)calloc(nf, sizeof(float));
    size_t i;
    for (i = 0; i < nf; ++i) {
        float w = 0.5f * (1.0f - cosf(2.0f * (float)M_PI *
                                      (float)i / (float)(nf - 1)));
        re[i] = x[i] * w;
    }
    vc_fft(nf, re, im, 0);
    size_t best = 1;
    float bestmag = -1.0f;
    for (i = 1; i < nf / 2; ++i) {
        float m = re[i] * re[i] + im[i] * im[i];
        if (m > bestmag) { bestmag = m; best = i; }
    }
    free(re); free(im);
    return (float)best * (float)sr / (float)nf;
}

static float rms(const float *x, size_t n) {
    double s = 0.0;
    size_t i;
    for (i = 0; i < n; ++i) s += (double)x[i] * (double)x[i];
    return (float)sqrt(s / (double)n);
}

/* Stream a whole buffer through the engine in small, irregular chunks
 * to exercise arbitrary block sizes. */
static void run_stream(vc_stream_t *st, const float *in, float *out, size_t n,
                       vc_spectral_fn fn, void *user) {
    size_t off = 0;
    size_t chunk = 137;
    while (off < n) {
        size_t c = (n - off < chunk) ? (n - off) : chunk;
        assert_int_equal(vc_stream_process(st, in + off, out + off, c, fn, user), 0);
        off += c;
    }
}

static void test_create_validation(void **state) {
    (void)state;
    assert_null(vc_stream_create(1000, 250, SR)); /* not power of two */
    assert_null(vc_stream_create(1024, 300, SR)); /* hop does not divide */
    assert_null(vc_stream_create(1024, 128, SR)); /* osamp 8, not allowed */
    assert_null(vc_stream_create(1024, 256, 0));  /* zero rate */
    vc_stream_t *st = vc_stream_create(1024, 256, SR);
    assert_non_null(st);
    assert_int_equal((int)vc_stream_latency_samples(st), 1024 - 256);
    vc_stream_destroy(st);
}

static void test_passthrough_identity(void **state) {
    (void)state;
    size_t n = 16384;
    float *in = (float *)malloc(n * sizeof(float));
    float *out = (float *)malloc(n * sizeof(float));
    float freqs[3] = {700.0f, 1900.0f, 3300.0f};
    float amps[3]  = {0.3f, 0.3f, 0.3f};
    gen_sines(in, n, SR, freqs, amps, 3);

    vc_stream_t *st = vc_stream_create(1024, 256, SR);
    assert_non_null(st);
    run_stream(st, in, out, n, NULL, NULL);

    /* Find the delay minimizing error; passthrough must reconstruct the
     * input faithfully at some delay within one frame. */
    size_t region = 4096;
    size_t base = 6000;
    float in_rms = rms(in + base, region);
    float best_err = 1e30f;
    size_t d;
    for (d = 0; d <= 1024; ++d) {
        double s = 0.0;
        size_t i;
        for (i = 0; i < region; ++i) {
            float e = out[base + i] - in[base - d + i];
            s += (double)e * (double)e;
        }
        float err = (float)sqrt(s / (double)region);
        if (err < best_err) best_err = err;
    }
    assert_true(best_err < 0.05f * in_rms);

    vc_stream_destroy(st);
    free(in); free(out);
}

static void run_pitch(float in_freq, float ratio, float expect_freq) {
    size_t n = 24000;
    float *in = (float *)malloc(n * sizeof(float));
    float *out = (float *)malloc(n * sizeof(float));
    float f = in_freq, a = 0.6f;
    gen_sines(in, n, SR, &f, &a, 1);

    vc_stream_t *st = vc_stream_create(2048, 512, SR);
    assert_non_null(st);
    vc_rt_params_t p = { ratio, 1.0f, 0.0f };
    vc_rt_ctx_t *ctx = vc_rt_create(2048 / 2 + 1, p);
    assert_non_null(ctx);

    run_stream(st, in, out, n, vc_rt_transform, ctx);

    size_t skip = vc_stream_latency_samples(st) + 4096;
    float got = dominant_freq(out + skip, n - skip, SR);
    assert_true(fabsf(got - expect_freq) < 0.03f * expect_freq);

    vc_rt_destroy(ctx);
    vc_stream_destroy(st);
    free(in); free(out);
}

static void test_pitch_up_octave(void **state) {
    (void)state;
    run_pitch(1000.0f, 2.0f, 2000.0f);
}

static void test_pitch_down_octave(void **state) {
    (void)state;
    run_pitch(2000.0f, 0.5f, 1000.0f);
}

static void test_bounded_output(void **state) {
    (void)state;
    size_t n = 20000;
    float *in = (float *)malloc(n * sizeof(float));
    float *out = (float *)malloc(n * sizeof(float));
    srand(1234);
    size_t i;
    for (i = 0; i < n; ++i)
        in[i] = 2.0f * ((float)rand() / (float)RAND_MAX) - 1.0f;

    vc_stream_t *st = vc_stream_create(1024, 256, SR);
    assert_non_null(st);
    vc_rt_params_t p = { vc_rt_semitones_to_ratio(-8.0f), 1.6f, 0.9f };
    vc_rt_ctx_t *ctx = vc_rt_create(1024 / 2 + 1, p);
    assert_non_null(ctx);

    run_stream(st, in, out, n, vc_rt_transform, ctx);

    for (i = 0; i < n; ++i) {
        assert_false(isnan(out[i]));
        assert_false(isinf(out[i]));
        assert_true(out[i] <= 4.0f && out[i] >= -4.0f);
    }

    vc_rt_destroy(ctx);
    vc_stream_destroy(st);
    free(in); free(out);
}

static void run_level(float semis, float formant, float scramble,
                      float max_loss_db) {
    size_t n = 48000;
    float *in = (float *)malloc(n * sizeof(float));
    float *out = (float *)malloc(n * sizeof(float));
    size_t i;
    int h;
    for (i = 0; i < n; ++i) {
        double v = 0.0;
        for (h = 1; h <= 12; ++h)
            v += sin(2.0 * M_PI * 120.0 * h * (double)i / (double)SR) / h;
        in[i] = (float)(v * 0.25);
    }

    vc_stream_t *st = vc_stream_create(1024, 256, SR);
    assert_non_null(st);
    vc_rt_params_t p = { vc_rt_semitones_to_ratio(semis), formant, scramble };
    vc_rt_ctx_t *ctx = vc_rt_create(1024 / 2 + 1, p);
    assert_non_null(ctx);

    run_stream(st, in, out, n, vc_rt_transform, ctx);

    size_t skip = vc_stream_latency_samples(st) + 4096;
    float in_rms = rms(in + skip, n - skip);
    float out_rms = rms(out + skip, n - skip);
    float gain_db = 20.0f * log10f(out_rms / (in_rms + 1e-12f) + 1e-12f);
    assert_true(fabsf(gain_db) <= max_loss_db);

    vc_rt_destroy(ctx);
    vc_stream_destroy(st);
    free(in); free(out);
}

static void test_level_preserved_fixed(void **state) {
    (void)state;
    run_level(7.0f, 1.3f, 0.0f, 3.0f);
}

static void test_level_preserved_witness(void **state) {
    /* Witness floor, not a preservation target: uniform random phase
     * noise (intensity 1.0) makes overlap-add sum powers instead of
     * amplitudes (4 overlapping frames -> ~-6 dB), plus permutation
     * misplacement attenuation. Measured -7.0 dB on the reference
     * harmonic signal; the window guards regressions (e.g. a return
     * of the -37 dB cancellation bug) without pretending physics
     * allows 0 dB here. Deterministic: fixed signal, params, hashes.
     */
    (void)state;
    size_t n = 48000;
    float *in = (float *)malloc(n * sizeof(float));
    float *out = (float *)malloc(n * sizeof(float));
    size_t i;
    int h;
    for (i = 0; i < n; ++i) {
        double v = 0.0;
        for (h = 1; h <= 12; ++h)
            v += sin(2.0 * M_PI * 120.0 * h * (double)i / (double)SR) / h;
        in[i] = (float)(v * 0.25);
    }

    vc_stream_t *st = vc_stream_create(1024, 256, SR);
    assert_non_null(st);
    vc_rt_params_t p = { vc_rt_semitones_to_ratio(-8.0f), 0.5f, 1.0f };
    vc_rt_ctx_t *ctx = vc_rt_create(1024 / 2 + 1, p);
    assert_non_null(ctx);

    run_stream(st, in, out, n, vc_rt_transform, ctx);

    size_t skip = vc_stream_latency_samples(st) + 4096;
    float in_rms = rms(in + skip, n - skip);
    float out_rms = rms(out + skip, n - skip);
    float gain_db = 20.0f * log10f(out_rms / (in_rms + 1e-12f) + 1e-12f);
    assert_true(gain_db <= -5.5f && gain_db >= -8.5f);

    vc_rt_destroy(ctx);
    vc_stream_destroy(st);
    free(in); free(out);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_create_validation),
        cmocka_unit_test(test_passthrough_identity),
        cmocka_unit_test(test_pitch_up_octave),
        cmocka_unit_test(test_pitch_down_octave),
        cmocka_unit_test(test_bounded_output),
        cmocka_unit_test(test_level_preserved_fixed),
        cmocka_unit_test(test_level_preserved_witness),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
