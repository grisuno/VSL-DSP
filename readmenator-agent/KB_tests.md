# Subsystem: tests

## voicecloak/tests/test_vc_fft.c
- Layer: testing
- Doc: include <stdarg.h> include <stddef.h> include <setjmp.h> include <cmocka.h> include <stdlib.h> include <math.h> include 
- Language: c
- Symbols:
  - `test_fft_identity` (function, line 9) `static void test_fft_identity(void **state)`
  - `test_fft_dc_signal` (function, line 26) `static void test_fft_dc_signal(void **state)`
  - `test_fft_sine` (function, line 46) `static void test_fft_sine(void **state)`
  - `main` (function, line 75) `int main(void)`
  - `vc_fft` (function, line 16) `vc_fft(n, real, imag, 0);`
  - `assert_float_equal` (function, line 22) `assert_float_equal(real[i], i == 0 ? 1.0f : 0.0f, 1e-4f);`
  - `free` (function, line 42) `free(real);`
  - `assert_true` (function, line 70) `assert_true(mag_k > mag_other * 10.0f);`
  - `cmocka_run_group_tests` (function, line 82) `return cmocka_run_group_tests(tests, NULL, NULL);`
- Depends on: `voicecloak/src/vc_fft.h`

## voicecloak/tests/test_vc_stream.c
- Layer: testing
- Doc: include <stdarg.h> include <stddef.h> include <setjmp.h> include <cmocka.h>  include "vc_stream.h" include "vc_rt.h" inc
- Language: c
- Symbols:
  - `gen_sines` (function, line 19) `static void gen_sines(float *buf, size_t n, uint32_t sr,
                      const float *freqs...`
  - `dominant_freq` (function, line 31) `static float dominant_freq(const float *x, size_t n, uint32_t sr)`
  - `rms` (function, line 53) `static float rms(const float *x, size_t n)`
  - `run_stream` (function, line 63) `static void run_stream(vc_stream_t *st, const float *in, float *out, size_t n,
                  ...`
  - `test_create_validation` (function, line 73) `static void test_create_validation(void **state)`
  - `test_passthrough_identity` (function, line 85) `static void test_passthrough_identity(void **state)`
  - `run_pitch` (function, line 121) `static void run_pitch(float in_freq, float ratio, float expect_freq)`
  - `test_pitch_up_octave` (function, line 145) `static void test_pitch_up_octave(void **state)`
  - `test_pitch_down_octave` (function, line 150) `static void test_pitch_down_octave(void **state)`
  - `test_bounded_output` (function, line 155) `static void test_bounded_output(void **state)`
  - `main` (function, line 184) `int main(void)`
  - `vc_fft` (function, line 43) `vc_fft(nf, re, im, 0);`
  - `free` (function, line 50) `free(re);`
  - `assert_int_equal` (function, line 69) `assert_int_equal(vc_stream_process(st, in + off, out + off, c, fn, user), 0);`
  - `assert_null` (function, line 76) `assert_null(vc_stream_create(1000, 250, SR));`
  - `assert_non_null` (function, line 81) `assert_non_null(st);`
  - `vc_stream_destroy` (function, line 83) `vc_stream_destroy(st);`
  - `assert_true` (function, line 116) `assert_true(best_err < 0.05f * in_rms);`
  - `vc_rt_destroy` (function, line 140) `vc_rt_destroy(ctx);`
  - `srand` (function, line 161) `srand(1234);`
  - `assert_false` (function, line 175) `assert_false(isnan(out[i]));`
  - `cmocka_run_group_tests` (function, line 193) `return cmocka_run_group_tests(tests, NULL, NULL);`
  - `M_PI` (macro, line 15) `#define M_PI`
  - `SR` (macro, line 17) `#define SR`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`
