#define _POSIX_C_SOURCE 200809L

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "vc_denoise.h"
#include "vc_rt.h"
#include "vc_stream.h"

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SR 48000U
#define FFT 1024U
#define HOP 256U
#define NBINS (FFT / 2U + 1U)
#define TEST_PI 3.14159265358979323846

static uint32_t noise_state;

static float white(float amplitude) {
    noise_state = noise_state * 1664525U + 1013904223U;
    return amplitude * (2.0f * (float)(noise_state >> 8) / 16777215.0f - 1.0f);
}

static float rms(const float *x, size_t n) {
    double sum = 0.0;
    size_t i;
    for (i = 0; i < n; ++i) sum += (double)x[i] * (double)x[i];
    return (float)sqrt(sum / (double)n);
}

static float harmonic(size_t i) {
    double value = 0.0;
    int k;
    for (k = 1; k <= 12; ++k)
        value += sin(2.0 * TEST_PI * 140.0 * (double)k * (double)i /
                     (double)SR) / (double)k;
    return (float)(0.1 * value);
}

static void run_chunks(vc_stream_t *st, const float *in, float *out, size_t n,
                       vc_spectral_fn fn, void *user) {
    size_t off;
    for (off = 0; off < n; off += HOP) {
        size_t c = n - off < HOP ? n - off : HOP;
        assert_int_equal(vc_stream_process(st, in + off, out + off, c,
                                           fn, user), 0);
    }
}

/* Learn on one second of noise, then process `count` samples of `in`. */
static void learn_then_process(vc_denoise_t *dn, const float *in, float *out,
                               size_t count) {
    const size_t learn = (size_t)SR + (size_t)SR / 4U;
    float *noise = (float *)malloc(learn * sizeof(float));
    float *scratch = (float *)malloc(learn * sizeof(float));
    assert_non_null(noise);
    assert_non_null(scratch);
    vc_stream_t *st = vc_stream_create(FFT, HOP, SR);
    assert_non_null(st);
    size_t i;
    for (i = 0; i < learn; ++i) noise[i] = white(0.01f);
    run_chunks(st, noise, scratch, learn, vc_denoise_transform, dn);
    assert_int_equal(vc_denoise_is_ready(dn), 1);
    run_chunks(st, in, out, count, vc_denoise_transform, dn);
    vc_stream_destroy(st);
    free(noise);
    free(scratch);
}

static vc_denoise_t *make_denoise(float learn_ms) {
    vc_denoise_params_t p;
    vc_denoise_params_defaults(&p);
    p.learn_ms = learn_ms;
    vc_denoise_t *dn = vc_denoise_create(NBINS, &p);
    assert_non_null(dn);
    return dn;
}

static void test_defaults_and_invalid_params(void **state) {
    (void)state;
    vc_denoise_params_t p;
    vc_denoise_params_defaults(&p);
    assert_float_equal(p.reduction, 2.0f, 0.0f);
    assert_float_equal(p.floor_db, -24.0f, 0.0f);
    assert_float_equal(p.learn_ms, 1500.0f, 0.0f);
    assert_null(vc_denoise_create(1U, &p));
    assert_null(vc_denoise_create(NBINS, NULL));
    vc_denoise_params_t bad = p;
    bad.reduction = 0.5f;
    assert_null(vc_denoise_create(NBINS, &bad));
    bad = p; bad.floor_db = 1.0f;
    assert_null(vc_denoise_create(NBINS, &bad));
    bad = p; bad.smoothing = 0.99f;
    assert_null(vc_denoise_create(NBINS, &bad));
    bad = p; bad.gate_snr_db = NAN;
    assert_null(vc_denoise_create(NBINS, &bad));
    bad = p; bad.gate_range_db = 61.0f;
    assert_null(vc_denoise_create(NBINS, &bad));
    bad = p; bad.learn_ms = 50.0f;
    assert_null(vc_denoise_create(NBINS, &bad));
    vc_denoise_destroy(NULL);
}

static void test_learning_mutes_then_ready(void **state) {
    (void)state;
    vc_denoise_t *dn = make_denoise(100.0f);
    const size_t frames = (size_t)ceil(100.0 * SR / (1000.0 * HOP));
    float mag[NBINS], phase[NBINS];
    size_t f, b;
    for (f = 0; f < frames; ++f) {
        for (b = 0; b < NBINS; ++b) { mag[b] = 1.0f; phase[b] = 0.0f; }
        assert_int_equal(vc_denoise_is_ready(dn), 0);
        vc_denoise_transform(mag, phase, NBINS, SR, HOP, dn);
        for (b = 0; b < NBINS; ++b) assert_float_equal(mag[b], 0.0f, 0.0f);
    }
    assert_int_equal(vc_denoise_is_ready(dn), 1);
    vc_denoise_destroy(dn);
}

static void test_stationary_noise_removed(void **state) {
    (void)state;
    noise_state = 0x2468ACEU;
    vc_denoise_t *dn = make_denoise(1000.0f);
    const size_t n = (size_t)SR;
    float *in = (float *)malloc(n * sizeof(float));
    float *out = (float *)malloc(n * sizeof(float));
    assert_non_null(in);
    assert_non_null(out);
    size_t i;
    for (i = 0; i < n; ++i) in[i] = white(0.01f);
    learn_then_process(dn, in, out, n);
    size_t skip = n / 2U;
    float reduction_db = 20.0f * log10f(rms(out + skip, n - skip) /
                                        rms(in + skip, n - skip));
    assert_true(reduction_db < -20.0f);
    vc_denoise_destroy(dn);
    free(in);
    free(out);
}

static void test_speech_like_content_survives(void **state) {
    (void)state;
    noise_state = 0x1357U;
    vc_denoise_t *dn = make_denoise(1000.0f);
    const size_t n = (size_t)SR;
    float *clean = (float *)malloc(n * sizeof(float));
    float *in = (float *)malloc(n * sizeof(float));
    float *out = (float *)malloc(n * sizeof(float));
    assert_non_null(clean);
    assert_non_null(in);
    assert_non_null(out);
    size_t i;
    for (i = 0; i < n; ++i) {
        clean[i] = harmonic(i);
        in[i] = clean[i] + white(0.01f);
    }
    learn_then_process(dn, in, out, n);
    size_t skip = n / 2U;
    float diff_db = 20.0f * log10f(rms(out + skip, n - skip) /
                                   rms(clean + skip, n - skip));
    assert_true(fabsf(diff_db) < 3.0f);
    vc_denoise_destroy(dn);
    free(clean);
    free(in);
    free(out);
}

static float robot_noise_rms(int with_denoise) {
    noise_state = 0xBEEFU;
    const size_t learn = (size_t)SR, n = (size_t)SR;
    float *in = (float *)malloc((learn + n) * sizeof(float));
    float *out = (float *)malloc((learn + n) * sizeof(float));
    assert_non_null(in);
    assert_non_null(out);
    size_t i;
    for (i = 0; i < learn + n; ++i) in[i] = white(0.01f);
    vc_rt_params_t rp = { 1.0f, 1.0f, 0.0f, 1 };
    vc_rt_ctx_t *rt = vc_rt_create(NBINS, rp);
    vc_denoise_t *dn = make_denoise(1000.0f);
    vc_stream_t *st = vc_stream_create(FFT, HOP, SR);
    assert_non_null(rt);
    assert_non_null(st);
    vc_spectral_chain_t chain;
    vc_spectral_chain_init(&chain);
    if (with_denoise)
        assert_int_equal(vc_spectral_chain_add(&chain, vc_denoise_transform, dn), 0);
    assert_int_equal(vc_spectral_chain_add(&chain, vc_rt_transform, rt), 0);
    run_chunks(st, in, out, learn + n, vc_spectral_chain_run, &chain);
    float value = rms(out + learn + n / 2U, n / 2U);
    vc_stream_destroy(st);
    vc_denoise_destroy(dn);
    vc_rt_destroy(rt);
    free(in);
    free(out);
    return value;
}

static void test_robot_hum_on_silence_suppressed(void **state) {
    (void)state;
    float plain = robot_noise_rms(0);
    float denoised = robot_noise_rms(1);
    assert_true(plain > 0.0f);
    assert_true(20.0f * log10f((denoised + 1e-12f) / plain) < -20.0f);
}

static void test_profile_round_trip(void **state) {
    (void)state;
    noise_state = 0x5151U;
    vc_denoise_t *learned = make_denoise(1000.0f);
    const size_t n = (size_t)SR / 2U;
    float *in = (float *)malloc(n * sizeof(float));
    float *out_a = (float *)malloc(n * sizeof(float));
    float *out_b = (float *)malloc(n * sizeof(float));
    assert_non_null(in);
    assert_non_null(out_a);
    assert_non_null(out_b);
    size_t i;
    for (i = 0; i < n; ++i) in[i] = harmonic(i) + white(0.01f);

    char path[] = "/tmp/vc_noise_test_XXXXXX";
    int fd = mkstemp(path);
    assert_true(fd >= 0);
    close(fd);
    assert_int_not_equal(vc_denoise_save(learned, path), 0);
    learn_then_process(learned, in, out_a, 0U);
    assert_int_equal(vc_denoise_save(learned, path), 0);

    vc_denoise_t *loaded = make_denoise(1000.0f);
    assert_int_equal(vc_denoise_load(loaded, path), 0);
    assert_int_equal(vc_denoise_is_ready(loaded), 1);
    unlink(path);

    vc_stream_t *sa = vc_stream_create(FFT, HOP, SR);
    vc_stream_t *sb = vc_stream_create(FFT, HOP, SR);
    assert_non_null(sa);
    assert_non_null(sb);
    vc_denoise_t *fresh = make_denoise(1000.0f);
    assert_int_equal(vc_denoise_load(fresh, "/nonexistent/vc_noise"), -1);
    vc_denoise_destroy(fresh);
    vc_denoise_t *again = make_denoise(1000.0f);
    char text[64];
    snprintf(text, sizeof(text), "VCNOISE 1 %u %u\n", SR, (unsigned)NBINS);
    assert_int_not_equal(vc_denoise_profile_parse(again, text, strlen(text)), 0);
    vc_denoise_destroy(again);

    run_chunks(sa, in, out_a, n, vc_denoise_transform, learned);
    vc_denoise_t *copy = make_denoise(1000.0f);
    char path2[] = "/tmp/vc_noise_test_XXXXXX";
    fd = mkstemp(path2);
    assert_true(fd >= 0);
    close(fd);
    assert_int_equal(vc_denoise_save(loaded, path2), 0);
    assert_int_equal(vc_denoise_load(copy, path2), 0);
    unlink(path2);
    run_chunks(sb, in, out_b, n, vc_denoise_transform, copy);
    size_t skip = n / 2U;
    float diff_db = 20.0f * log10f(rms(out_b + skip, n - skip) /
                                   rms(out_a + skip, n - skip));
    assert_true(fabsf(diff_db) < 0.5f);

    vc_stream_destroy(sa);
    vc_stream_destroy(sb);
    vc_denoise_destroy(copy);
    vc_denoise_destroy(loaded);
    vc_denoise_destroy(learned);
    free(in);
    free(out_a);
    free(out_b);
}

static void test_malformed_profiles_rejected(void **state) {
    (void)state;
    static const char *const bad[] = {
        "",
        "VCNOISE",
        "XXNOISE 1 48000 3\n1\n2\n3\n",
        "VCNOISE 2 48000 3\n1\n2\n3\n",
        "VCNOISE 1 48000 4\n1\n2\n3\n4\n",
        "VCNOISE 1 48000 3\n1\n2\n",
        "VCNOISE 1 48000 3\n1\n2\n3\n4\n",
        "VCNOISE 1 48000 3\n1\n-2\n3\n",
        "VCNOISE 1 48000 3\n1\nnan\n3\n",
        "VCNOISE 1 48000 3\n1\ninf\n3\n",
        "VCNOISE 1 48000 3\n1\n2x\n3\n",
        "VCNOISE 1 0 3\n1\n2\n3\n",
        "VCNOISE 1 48000 3 junk\n1\n2\n3\n",
    };
    vc_denoise_params_t p;
    vc_denoise_params_defaults(&p);
    vc_denoise_t *dn = vc_denoise_create(3U, &p);
    assert_non_null(dn);
    size_t i;
    for (i = 0; i < sizeof(bad) / sizeof(bad[0]); ++i) {
        assert_int_not_equal(vc_denoise_profile_parse(dn, bad[i],
                                                      strlen(bad[i])), 0);
        assert_int_equal(vc_denoise_is_ready(dn), 0);
    }
    assert_int_not_equal(vc_denoise_profile_parse(dn, NULL, 4U), 0);
    const char good[] = "VCNOISE 1 48000 3\n1\n2.5\n0\n";
    assert_int_equal(vc_denoise_profile_parse(dn, good, strlen(good)), 0);
    assert_int_equal(vc_denoise_is_ready(dn), 1);
    vc_denoise_destroy(dn);
}

static void test_rate_mismatch_relearns(void **state) {
    (void)state;
    vc_denoise_params_t p;
    vc_denoise_params_defaults(&p);
    p.learn_ms = 100.0f;
    vc_denoise_t *dn = vc_denoise_create(3U, &p);
    assert_non_null(dn);
    const char profile[] = "VCNOISE 1 44100 3\n1\n1\n1\n";
    assert_int_equal(vc_denoise_profile_parse(dn, profile, strlen(profile)), 0);
    float mag[3] = {5.0f, 5.0f, 5.0f}, phase[3] = {0.0f, 0.0f, 0.0f};
    vc_denoise_transform(mag, phase, 3U, SR, HOP, dn);
    assert_int_equal(vc_denoise_is_ready(dn), 0);
    assert_float_equal(mag[0], 0.0f, 0.0f);
    vc_denoise_destroy(dn);
}

static void test_non_finite_frame_muted(void **state) {
    (void)state;
    vc_denoise_params_t p;
    vc_denoise_params_defaults(&p);
    vc_denoise_t *dn = vc_denoise_create(3U, &p);
    assert_non_null(dn);
    const char profile[] = "VCNOISE 1 48000 3\n0.0001\n0.0001\n0.0001\n";
    assert_int_equal(vc_denoise_profile_parse(dn, profile, strlen(profile)), 0);
    float mag[3] = {1.0f, NAN, 1.0f}, phase[3] = {0.0f, 0.0f, 0.0f};
    vc_denoise_transform(mag, phase, 3U, SR, HOP, dn);
    size_t b;
    for (b = 0; b < 3U; ++b) assert_float_equal(mag[b], 0.0f, 0.0f);
    float wrong[4] = {1.0f, 1.0f, 1.0f, 1.0f}, ph4[4] = {0};
    vc_denoise_transform(wrong, ph4, 4U, SR, HOP, dn);
    for (b = 0; b < 4U; ++b) assert_float_equal(wrong[b], 0.0f, 0.0f);
    vc_denoise_destroy(dn);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_defaults_and_invalid_params),
        cmocka_unit_test(test_learning_mutes_then_ready),
        cmocka_unit_test(test_stationary_noise_removed),
        cmocka_unit_test(test_speech_like_content_survives),
        cmocka_unit_test(test_robot_hum_on_silence_suppressed),
        cmocka_unit_test(test_profile_round_trip),
        cmocka_unit_test(test_malformed_profiles_rejected),
        cmocka_unit_test(test_rate_mismatch_relearns),
        cmocka_unit_test(test_non_finite_frame_muted),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
