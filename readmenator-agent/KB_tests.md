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
  - `M_PI` (macro, line 15)
  - `SR` (macro, line 17)
