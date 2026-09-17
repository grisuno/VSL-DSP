# Subsystem: tests

## voicecloak/tests/test_vc_fft.c
- Layer: testing
- Language: c
- Symbols:
  - `test_fft_identity` (function, line 10) `static void test_fft_identity(void **state)`
  - `test_fft_dc_signal` (function, line 27) `static void test_fft_dc_signal(void **state)`
  - `test_fft_sine` (function, line 47) `static void test_fft_sine(void **state)`
  - `main` (function, line 76) `int main(void)`
- Depends on: `voicecloak/src/vc_fft.h`

## voicecloak/tests/test_vc_stream.c
- Layer: testing
- Language: c
- Symbols:
  - `gen_sines` (function, line 20) `static void gen_sines(float *buf, size_t n, uint32_t sr,
                      const float *freqs...`
  - `dominant_freq` (function, line 32) `static float dominant_freq(const float *x, size_t n, uint32_t sr)`
  - `rms` (function, line 54) `static float rms(const float *x, size_t n)`
  - `run_stream` (function, line 63) `static void run_stream(vc_stream_t *st, const float *in, float *out, size_t n,
                  ...`
  - `test_create_validation` (function, line 74) `static void test_create_validation(void **state)`
  - `test_passthrough_identity` (function, line 86) `static void test_passthrough_identity(void **state)`
  - `run_pitch` (function, line 122) `static void run_pitch(float in_freq, float ratio, float expect_freq)`
  - `test_pitch_up_octave` (function, line 146) `static void test_pitch_up_octave(void **state)`
  - `test_pitch_down_octave` (function, line 151) `static void test_pitch_down_octave(void **state)`
  - `test_bounded_output` (function, line 156) `static void test_bounded_output(void **state)`
  - `main` (function, line 185) `int main(void)`
  - `M_PI` (macro, line 15) `#define M_PI`
  - `SR` (macro, line 18) `#define SR`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`
