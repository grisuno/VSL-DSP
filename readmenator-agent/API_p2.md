# API (page 2 of 2)
Previous: [API.md](API.md)

## voicecloak/src/vc_alsa.c
Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_stream.h`
- `fmt_bps` (function) `voicecloak/src/vc_alsa.c:20` `static size_t fmt_bps(snd_pcm_format_t f)`
- `open_stream` (function) `voicecloak/src/vc_alsa.c:29` `static int open_stream(vc_pcm_t *s, const char *dev, snd_pcm_stream_t dir,
                      ...`
- `raw_to_mono` (function) `voicecloak/src/vc_alsa.c:99` `static void raw_to_mono(const unsigned char *raw, float *mono,
                        snd_pcm_uf...`
- `mono_to_raw` (function) `voicecloak/src/vc_alsa.c:130` `static void mono_to_raw(unsigned char *raw, const float *mono,
                        snd_pcm_uf...`
- `vc_alsa_list` (function) `voicecloak/src/vc_alsa.c:163` `int vc_alsa_list(void)`
- `vc_alsa_run` (function) `voicecloak/src/vc_alsa.c:189` `int vc_alsa_run(const vc_alsa_cfg_t *cfg)`

## voicecloak/src/vc_alsa.h
Depends on: `voicecloak/src/vc_effects.h`, `voicecloak/src/vc_eq.h`, `voicecloak/src/vc_level.h`, `voicecloak/src/vc_stream.h`
Imported by: `voicecloak/src/vc_alsa.c`, `voicecloak/src/vc_rt_cli.c`
- `runtime` (function) `voicecloak/src/vc_alsa.h:20` `* * The capture and playback device names are ALSA PCM names discovered * at runtime (e.g. "hw:VSL", "plughw:2,0"...`
- `vc_alsa_list` (function) `voicecloak/src/vc_alsa.h:46` `int vc_alsa_list(void);` -- @brief Print the available ALSA PCM devices to stdout. @return 0 on success, -1 on error.
- `vc_alsa_run` (function) `voicecloak/src/vc_alsa.h:53` `int vc_alsa_run(const vc_alsa_cfg_t *cfg);` -- @brief Open capture and playback, run the processing loop until *cfg->stop becomes non-zero or a fatal error occurs....

## voicecloak/src/vc_cli.c
Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_wav.h`
- `print_usage` (function) `voicecloak/src/vc_cli.c:9` `static void print_usage(const char *prog)`
- `cmd_keygen` (function) `voicecloak/src/vc_cli.c:41` `static int cmd_keygen(void)`
- `cmd_cloak` (function) `voicecloak/src/vc_cli.c:53` `static int cmd_cloak(const char *pubkey_path,
                     const char *in_path, const cha...`
- `cmd_info` (function) `voicecloak/src/vc_cli.c:142` `static int cmd_info(const char *path)`
- `main` (function) `voicecloak/src/vc_cli.c:177` `int main(int argc, char *argv[])`

## voicecloak/src/vc_crypto.c
Depends on: `voicecloak/src/vc_crypto.h`
- `openssl_init` (function) `voicecloak/src/vc_crypto.c:12` `static void openssl_init(void)`
- `vc_crypto_keygen` (function) `voicecloak/src/vc_crypto.c:17` `int vc_crypto_keygen(const char *pubkey_path, const char *privkey_path)`
- `vc_crypto_seal` (function) `voicecloak/src/vc_crypto.c:47` `int vc_crypto_seal(const char *pubkey_path,
                   const unsigned char *seed, size_t ...`
- `vc_crypto_unseal` (function) `voicecloak/src/vc_crypto.c:71` `int vc_crypto_unseal(const char *privkey_path,
                     const unsigned char *enc, siz...`
- `vc_crypto_derive_seeds` (function) `voicecloak/src/vc_crypto.c:96` `int vc_crypto_derive_seeds(const unsigned char *master_seed, size_t seed_len,
                   ...`
- `vc_prng_create` (function) `voicecloak/src/vc_crypto.c:143` `vc_prng_t *vc_prng_create(const unsigned char *seed)`
- `vc_prng_destroy` (function) `voicecloak/src/vc_crypto.c:157` `void vc_prng_destroy(vc_prng_t *p)`
- `vc_prng_fill` (function) `voicecloak/src/vc_crypto.c:164` `void vc_prng_fill(vc_prng_t *p, unsigned char *buf, size_t len)`
- `vc_prng_float` (function) `voicecloak/src/vc_crypto.c:184` `float vc_prng_float(vc_prng_t *p, float low, float high)`

## voicecloak/src/vc_crypto.h
Imported by: `voicecloak/src/vc_cli.c`, `voicecloak/src/vc_crypto.c`, `voicecloak/src/vc_dsp.c`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/src/vc_rt_seed.c`
- `vc_crypto_keygen` (function) `voicecloak/src/vc_crypto.h:24` `int vc_crypto_keygen(const char *pubkey_path, const char *privkey_path);` -- @brief Generate an RSA-4096 keypair and write to PEM files. @param pubkey_path   Output path for public key. @param...
- `vc_crypto_seal` (function) `voicecloak/src/vc_crypto.h:35` `int vc_crypto_seal(const char *pubkey_path, const unsigned char *seed, size_t seed_len, unsigned char *enc_out...` -- @brief Encrypt a symmetric session seed using RSA-4096 public key. @param pubkey_path   Path to PEM public key....
- `vc_crypto_unseal` (function) `voicecloak/src/vc_crypto.h:48` `int vc_crypto_unseal(const char *privkey_path, const unsigned char *enc, size_t enc_len, unsigned char *seed, size_t...` -- @brief Decrypt the session seed using RSA-4096 private key. @param privkey_path  Path to PEM private key. @param enc...
- `vc_crypto_derive_seeds` (function) `voicecloak/src/vc_crypto.h:61` `int vc_crypto_derive_seeds(const unsigned char *master_seed, size_t seed_len, unsigned char *pitch_seed, unsigned...` -- @brief Derive sub-seeds from a master seed via HKDF-SHA256. @param master_seed   96-byte master seed. @param...
- `vc_prng_create` (function) `voicecloak/src/vc_crypto.h:77` `vc_prng_t *vc_prng_create(const unsigned char *seed);` -- @brief Create a PRNG from a 32-byte seed.
- `vc_prng_destroy` (function) `voicecloak/src/vc_crypto.h:82` `void vc_prng_destroy(vc_prng_t *p);` -- @brief Release PRNG.
- `vc_prng_fill` (function) `voicecloak/src/vc_crypto.h:87` `void vc_prng_fill(vc_prng_t *p, unsigned char *buf, size_t len);` -- @brief Fill buffer with deterministic pseudo-random bytes.
- `vc_prng_float` (function) `voicecloak/src/vc_crypto.h:92` `float vc_prng_float(vc_prng_t *p, float low, float high);` -- @brief Generate a float in [low, high] deterministically.

## voicecloak/src/vc_denoise.c
Depends on: `voicecloak/src/vc_denoise.h`
- `vc_denoise_params_defaults` (function) `voicecloak/src/vc_denoise.c:29` `void vc_denoise_params_defaults(vc_denoise_params_t *params)`
- `params_valid` (function) `voicecloak/src/vc_denoise.c:39` `static int params_valid(const vc_denoise_params_t *p)`
- `reset_tracking` (function) `voicecloak/src/vc_denoise.c:57` `static void reset_tracking(vc_denoise_t *dn)` -- Restart the per-bin gains and close the gate: right after a profile * appears the user is assumed silent, so nothing...
- `restart_learning` (function) `voicecloak/src/vc_denoise.c:64` `static void restart_learning(vc_denoise_t *dn)`
- `vc_denoise_create` (function) `voicecloak/src/vc_denoise.c:71` `vc_denoise_t *vc_denoise_create(size_t nbins,
                                const vc_denoise_pa...`
- `vc_denoise_destroy` (function) `voicecloak/src/vc_denoise.c:92` `void vc_denoise_destroy(vc_denoise_t *denoise)`
- `vc_denoise_is_ready` (function) `voicecloak/src/vc_denoise.c:100` `int vc_denoise_is_ready(const vc_denoise_t *denoise)`
- `mute` (function) `voicecloak/src/vc_denoise.c:104` `static void mute(float *mag, size_t nbins)`
- `install_profile` (function) `voicecloak/src/vc_denoise.c:108` `static void install_profile(vc_denoise_t *dn, uint32_t sample_rate)`
- `learn` (function) `voicecloak/src/vc_denoise.c:117` `static void learn(vc_denoise_t *dn, float *mag, uint32_t sample_rate,
                  size_t hop)`
- `update_gate` (function) `voicecloak/src/vc_denoise.c:136` `static void update_gate(vc_denoise_t *dn, double frame_power,
                        uint32_t sa...`
- `vc_denoise_transform` (function) `voicecloak/src/vc_denoise.c:158` `void vc_denoise_transform(float *mag, float *phase, size_t nbins,
                          uint3...`
- `parse_ulong` (function) `voicecloak/src/vc_denoise.c:196` `static int parse_ulong(const char **cursor, unsigned long *out)`
- `parse_header` (function) `voicecloak/src/vc_denoise.c:208` `static int parse_header(const char **cursor, unsigned long *rate,
                        unsigne...`
- `vc_denoise_profile_parse` (function) `voicecloak/src/vc_denoise.c:224` `int vc_denoise_profile_parse(vc_denoise_t *denoise, const char *text,
                           ...`
- `vc_denoise_save` (function) `voicecloak/src/vc_denoise.c:266` `int vc_denoise_save(const vc_denoise_t *denoise, const char *path)`
- `vc_denoise_load` (function) `voicecloak/src/vc_denoise.c:280` `int vc_denoise_load(vc_denoise_t *denoise, const char *path)`

## voicecloak/src/vc_denoise.h
Depends on: `voicecloak/src/vc_audio_config.h`
Imported by: `voicecloak/src/vc_denoise.c`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/tests/test_vc_denoise.c`
- `vc_denoise_params_defaults` (function) `voicecloak/src/vc_denoise.h:55` `void vc_denoise_params_defaults(vc_denoise_params_t *params);` -- loaded; output is muted while learning.  typedef struct { float reduction; float floor_db; float smoothing; float...
- `vc_denoise_create` (function) `voicecloak/src/vc_denoise.h:61` `vc_denoise_t *vc_denoise_create(size_t nbins, const vc_denoise_params_t *params);` -- @brief Create a noise reducer for @p nbins frequency bins. @return Context or NULL for invalid...
- `vc_denoise_destroy` (function) `voicecloak/src/vc_denoise.h:65` `void vc_denoise_destroy(vc_denoise_t *denoise);` -- @brief Create a noise reducer for @p nbins frequency bins. @return Context or NULL for invalid...
- `first` (function) `voicecloak/src/vc_denoise.h:70` `* * Learns the noise print first (muting those frames), then applies * power spectral subtraction and the spectral...`
- `vc_denoise_is_ready` (function) `voicecloak/src/vc_denoise.h:79` `int vc_denoise_is_ready(const vc_denoise_t *denoise);` -- @brief Per-frame spectral transform, compatible with vc_spectral_fn.
- `vc_denoise_profile_parse` (function) `voicecloak/src/vc_denoise.h:85` `int vc_denoise_profile_parse(vc_denoise_t *denoise, const char *text, size_t length);` -- @brief Parse a text noise profile (see spec for the format). @return 0 on success; -1 on any malformed input...
- `vc_denoise_save` (function) `voicecloak/src/vc_denoise.h:89` `int vc_denoise_save(const vc_denoise_t *denoise, const char *path);` -- @brief Parse a text noise profile (see spec for the format). @return 0 on success; -1 on any malformed input...
- `vc_denoise_load` (function) `voicecloak/src/vc_denoise.h:92` `int vc_denoise_load(vc_denoise_t *denoise, const char *path);` -- @brief Parse a text noise profile (see spec for the format). @return 0 on success; -1 on any malformed input...

## voicecloak/src/vc_dsp.c
Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_stft.h`
- `stft_process` (function) `voicecloak/src/vc_dsp.c:12` `static int stft_process(const float *samples, size_t num_samples,
                        float *...`
- `stft_reconstruct` (function) `voicecloak/src/vc_dsp.c:21` `static int stft_reconstruct(const float *mag, const float *phase,
                            siz...`
- `compute_out_len` (function) `voicecloak/src/vc_dsp.c:31` `static size_t compute_out_len(size_t nframes, size_t hop)`
- `vc_dsp_pitch_shift` (function) `voicecloak/src/vc_dsp.c:35` `int vc_dsp_pitch_shift(const float *samples, size_t num_samples,
                       uint32_t ...`
- `vc_dsp_formant_shift` (function) `voicecloak/src/vc_dsp.c:91` `int vc_dsp_formant_shift(const float *samples, size_t num_samples,
                         uint3...`
- `vc_dsp_spectral_scramble` (function) `voicecloak/src/vc_dsp.c:161` `int vc_dsp_spectral_scramble(const float *samples, size_t num_samples,
                          ...`
- `trim_edges` (function) `voicecloak/src/vc_dsp.c:234` `static void trim_edges(float **buf, size_t *len)`
- `normalize_rms` (function) `voicecloak/src/vc_dsp.c:255` `static void normalize_rms(const float *in, size_t in_len,
                          float *out, s...`
- `vc_dsp_cloak` (function) `voicecloak/src/vc_dsp.c:272` `int vc_dsp_cloak(const float *samples, size_t num_samples,
                 uint32_t sample_rate,...`

## voicecloak/src/vc_dsp.h
Imported by: `voicecloak/src/vc_cli.c`, `voicecloak/src/vc_dsp.c`
- `vc_dsp_pitch_shift` (function) `voicecloak/src/vc_dsp.h:16` `int vc_dsp_pitch_shift(const float *samples, size_t num_samples, uint32_t sample_rate, float semitones, float **out...`
- `vc_dsp_formant_shift` (function) `voicecloak/src/vc_dsp.h:20` `int vc_dsp_formant_shift(const float *samples, size_t num_samples, uint32_t sample_rate, float shift_factor, float...`
- `vc_dsp_spectral_scramble` (function) `voicecloak/src/vc_dsp.h:24` `int vc_dsp_spectral_scramble(const float *samples, size_t num_samples, uint32_t sample_rate, float intensity, float...`
- `vc_dsp_cloak` (function) `voicecloak/src/vc_dsp.h:28` `int vc_dsp_cloak(const float *samples, size_t num_samples, uint32_t sample_rate, const unsigned char *pitch_seed...`

## voicecloak/src/vc_effects.c
Depends on: `voicecloak/src/vc_effects.h`
- `finite_params` (function) `voicecloak/src/vc_effects.c:40` `static int finite_params(const vc_effects_params_t *p)`
- `ring_valid` (function) `voicecloak/src/vc_effects.c:53` `static int ring_valid(const vc_effects_params_t *p, float nyquist)`
- `params_valid` (function) `voicecloak/src/vc_effects.c:61` `static int params_valid(uint32_t sample_rate, const vc_effects_params_t *p)`
- `samples_from_ms` (function) `voicecloak/src/vc_effects.c:105` `static size_t samples_from_ms(float milliseconds, uint32_t sample_rate)`
- `alloc_comb` (function) `voicecloak/src/vc_effects.c:111` `static int alloc_comb(vc_comb_t *comb, float milliseconds,
                      uint32_t sample_...`
- `free_combs` (function) `voicecloak/src/vc_effects.c:121` `static void free_combs(vc_effects_t *fx)`
- `vc_effects_create` (function) `voicecloak/src/vc_effects.c:129` `vc_effects_t *vc_effects_create(uint32_t sample_rate,
                                const vc_ef...`
- `vc_effects_destroy` (function) `voicecloak/src/vc_effects.c:173` `void vc_effects_destroy(vc_effects_t *effects)`
- `reset_state` (function) `voicecloak/src/vc_effects.c:180` `static void reset_state(vc_effects_t *fx)`
- `process_space` (function) `voicecloak/src/vc_effects.c:197` `static float process_space(vc_effects_t *fx, float input, double lfo)`
- `process_reverb` (function) `voicecloak/src/vc_effects.c:214` `static float process_reverb(vc_effects_t *fx, float input)`
- `process_phaser` (function) `voicecloak/src/vc_effects.c:228` `static float process_phaser(vc_effects_t *fx, float input, double lfo)`
- `ring_modulate` (function) `voicecloak/src/vc_effects.c:249` `static float ring_modulate(const vc_effects_t *fx, float input)` -- Soft square: a hard edge multiplies the voice by infinitely many harmonics that alias; tanh(k sin) keeps the square...
- `process_metallic` (function) `voicecloak/src/vc_effects.c:260` `static float process_metallic(vc_effects_t *fx, float input)`
- `process_one` (function) `voicecloak/src/vc_effects.c:270` `static float process_one(vc_effects_t *fx, float input)`
- `vc_effects_process` (function) `voicecloak/src/vc_effects.c:309` `int vc_effects_process(vc_effects_t *effects, float *samples, size_t count)`

## voicecloak/src/vc_effects.h
Depends on: `voicecloak/src/vc_audio_config.h`
Imported by: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_effects.c`, `voicecloak/src/vc_presets.h`, `voicecloak/tests/test_vc_effects.c`
- `vc_effects_create` (function) `voicecloak/src/vc_effects.h:60` `vc_effects_t *vc_effects_create(uint32_t sample_rate, const vc_effects_params_t *params);` -- @brief Create one stateful, sample-domain effect context. @return Context or NULL for invalid sample...
- `vc_effects_destroy` (function) `voicecloak/src/vc_effects.h:64` `void vc_effects_destroy(vc_effects_t *effects);` -- @brief Create one stateful, sample-domain effect context. @return Context or NULL for invalid sample...
- `vc_effects_process` (function) `voicecloak/src/vc_effects.h:71` `int vc_effects_process(vc_effects_t *effects, float *samples, size_t count);` -- @brief Process mono samples in place, preserving state between blocks. @return 0 on success; nonzero on invalid input.

## voicecloak/src/vc_eq.c
Depends on: `voicecloak/src/vc_eq.h`
- `params_valid` (function) `voicecloak/src/vc_eq.c:24` `static int params_valid(uint32_t sample_rate, const vc_eq_params_t *p)`
- `normalize` (function) `voicecloak/src/vc_eq.c:39` `static void normalize(vc_biquad_t *f, double b0, double b1, double b2,
                      doub...`
- `design_highpass` (function) `voicecloak/src/vc_eq.c:49` `static void design_highpass(vc_biquad_t *f, double hz, double rate)`
- `design_peaking` (function) `voicecloak/src/vc_eq.c:57` `static void design_peaking(vc_biquad_t *f, double hz, double gain_db,
                           ...`
- `vc_eq_create` (function) `voicecloak/src/vc_eq.c:67` `vc_eq_t *vc_eq_create(uint32_t sample_rate, const vc_eq_params_t *params)`
- `vc_eq_destroy` (function) `voicecloak/src/vc_eq.c:81` `void vc_eq_destroy(vc_eq_t *eq)`
- `run_biquad` (function) `voicecloak/src/vc_eq.c:85` `static double run_biquad(vc_biquad_t *f, double x)`
- `fail_closed` (function) `voicecloak/src/vc_eq.c:93` `static void fail_closed(vc_eq_t *eq, float *samples, size_t count)`
- `vc_eq_process` (function) `voicecloak/src/vc_eq.c:99` `int vc_eq_process(vc_eq_t *eq, float *samples, size_t count)`

## voicecloak/src/vc_eq.h
Depends on: `voicecloak/src/vc_audio_config.h`
Imported by: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_eq.c`, `voicecloak/src/vc_presets.h`, `voicecloak/tests/test_vc_eq.c`, `voicecloak/tests/test_vc_presets.c`
- `vc_eq_create` (function) `voicecloak/src/vc_eq.h:36` `vc_eq_t *vc_eq_create(uint32_t sample_rate, const vc_eq_params_t *params);` -- @brief Create a high-pass + presence peaking equalizer. @return Context or NULL for invalid sample...
- `vc_eq_destroy` (function) `voicecloak/src/vc_eq.h:39` `void vc_eq_destroy(vc_eq_t *eq);` -- @brief Create a high-pass + presence peaking equalizer. @return Context or NULL for invalid sample...
- `vc_eq_process` (function) `voicecloak/src/vc_eq.h:46` `int vc_eq_process(vc_eq_t *eq, float *samples, size_t count);` -- @brief Equalize mono samples in place, keeping filter state. @return 0 on success; nonzero on invalid arguments/data.

## voicecloak/src/vc_fft.c
Depends on: `voicecloak/src/vc_fft.h`
- `bit_reverse` (function) `voicecloak/src/vc_fft.c:10` `static unsigned int bit_reverse(unsigned int x, unsigned int bits)`
- `bit_reverse_reorder` (function) `voicecloak/src/vc_fft.c:20` `static void bit_reverse_reorder(size_t n, float *real, float *imag)`
- `vc_fft` (function) `voicecloak/src/vc_fft.c:36` `void vc_fft(size_t n, float *real, float *imag, int inverse)`

## voicecloak/src/vc_fft.h
Imported by: `voicecloak/src/vc_fft.c`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/src/vc_stft.c`, `voicecloak/src/vc_stream.c`, `voicecloak/tests/test_vc_fft.c`, `voicecloak/tests/test_vc_stream.c`
- `FFT` (function) `voicecloak/src/vc_fft.h:18` `* FFT(IFFT(x)) == IFFT(FFT(x)) == x. */ void vc_fft(size_t n, float *real, float *imag, int inverse);`

## voicecloak/src/vc_level.c
Depends on: `voicecloak/src/vc_level.h`
- `config_valid` (function) `voicecloak/src/vc_level.c:22` `static int config_valid(uint32_t sample_rate, const vc_level_config_t *config)`
- `time_alpha` (function) `voicecloak/src/vc_level.c:50` `static float time_alpha(float milliseconds, uint32_t sample_rate)`
- `vc_level_config_defaults` (function) `voicecloak/src/vc_level.c:55` `void vc_level_config_defaults(vc_level_config_t *config)`
- `vc_level_create` (function) `voicecloak/src/vc_level.c:67` `vc_level_t *vc_level_create(uint32_t sample_rate,
                            const vc_level_conf...`
- `vc_level_destroy` (function) `voicecloak/src/vc_level.c:90` `void vc_level_destroy(vc_level_t *level)`
- `silence_block` (function) `voicecloak/src/vc_level.c:94` `static void silence_block(float *samples, size_t count)`
- `vc_level_process` (function) `voicecloak/src/vc_level.c:99` `int vc_level_process(vc_level_t *level, float *samples, size_t count)`
- `vc_level_current_gain_db` (function) `voicecloak/src/vc_level.c:169` `float vc_level_current_gain_db(const vc_level_t *level)`

## voicecloak/src/vc_level.h
Depends on: `voicecloak/src/vc_audio_config.h`
Imported by: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_level.c`, `voicecloak/tests/test_vc_level.c`, `voicecloak/tests/test_vc_presets.c`
- `vc_level_config_defaults` (function) `voicecloak/src/vc_level.h:40` `void vc_level_config_defaults(vc_level_config_t *config);` -- typedef struct { float target_dbfs; float max_gain_db; float ceiling_dbfs; float attack_ms; float release_ms; float...
- `vc_level_create` (function) `voicecloak/src/vc_level.h:46` `vc_level_t *vc_level_create(uint32_t sample_rate, const vc_level_config_t *config);` -- @brief Create smoothed RMS gain control and peak limiter state. @return Context or NULL if sample rate/configuration...
- `vc_level_destroy` (function) `voicecloak/src/vc_level.h:50` `void vc_level_destroy(vc_level_t *level);` -- @brief Create smoothed RMS gain control and peak limiter state. @return Context or NULL if sample rate/configuration...
- `vc_level_process` (function) `voicecloak/src/vc_level.h:58` `int vc_level_process(vc_level_t *level, float *samples, size_t count);` -- @brief Apply smoothed RMS gain, soft saturation, and peak limiting in place. @return 0 on success; nonzero on...
- `vc_level_current_gain_db` (function) `voicecloak/src/vc_level.h:61` `float vc_level_current_gain_db(const vc_level_t *level);` -- @brief Apply smoothed RMS gain, soft saturation, and peak limiting in place. @return 0 on success; nonzero on...

## voicecloak/src/vc_presets.c
Depends on: `voicecloak/src/vc_presets.h`
- `vc_preset_lookup` (function) `voicecloak/src/vc_presets.c:115` `int vc_preset_lookup(const char *name, vc_preset_t *out)`

## voicecloak/src/vc_presets.h
Depends on: `voicecloak/src/vc_effects.h`, `voicecloak/src/vc_eq.h`, `voicecloak/src/vc_rt.h`
Imported by: `voicecloak/src/vc_presets.c`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/tests/test_vc_presets.c`
- `vc_preset_lookup` (function) `voicecloak/src/vc_presets.h:28` `int vc_preset_lookup(const char *name, vc_preset_t *out);` -- @brief Resolve a named real-time voice/effect preset. @return 0 on match; -1 for unknown name or invalid arguments.

## voicecloak/src/vc_rt.c
Depends on: `voicecloak/src/vc_rt.h`
- `vc_rt_create` (function) `voicecloak/src/vc_rt.c:31` `vc_rt_ctx_t *vc_rt_create(size_t nbins, vc_rt_params_t params)`
- `vc_rt_destroy` (function) `voicecloak/src/vc_rt.c:70` `void vc_rt_destroy(vc_rt_ctx_t *c)`
- `vc_rt_reset` (function) `voicecloak/src/vc_rt.c:88` `void vc_rt_reset(vc_rt_ctx_t *c)`
- `vc_rt_semitones_to_ratio` (function) `voicecloak/src/vc_rt.c:95` `float vc_rt_semitones_to_ratio(float semitones)`
- `wrap_pi` (function) `voicecloak/src/vc_rt.c:99` `static double wrap_pi(double x)`
- `target` (function) `voicecloak/src/vc_rt.c:139` `* peak region are recorded per target (tgt_src/tgt_pk) so the final
 * stage can identity-lock no...`
- `vc_rt_transform` (function) `voicecloak/src/vc_rt.c:214` `void vc_rt_transform(float *mag, float *phase, size_t nbins,
                     uint32_t sample...`

## voicecloak/src/vc_rt.h
Imported by: `voicecloak/src/vc_presets.h`, `voicecloak/src/vc_rt.c`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/src/vc_rt_seed.c`, `voicecloak/tests/test_vc_denoise.c`, `voicecloak/tests/test_vc_stream.c`
- `vc_rt_create` (function) `voicecloak/src/vc_rt.h:43` `vc_rt_ctx_t *vc_rt_create(size_t nbins, vc_rt_params_t params);` -- @brief Create a transform context sized for @p nbins frequency bins. @return Context or NULL on allocation failure /...
- `vc_rt_destroy` (function) `voicecloak/src/vc_rt.h:46` `void vc_rt_destroy(vc_rt_ctx_t *c);` -- @brief Create a transform context sized for @p nbins frequency bins. @return Context or NULL on allocation failure /...
- `vc_rt_reset` (function) `voicecloak/src/vc_rt.h:49` `void vc_rt_reset(vc_rt_ctx_t *c);` -- @brief Create a transform context sized for @p nbins frequency bins. @return Context or NULL on allocation failure /...
- `vc_rt_transform` (function) `voicecloak/src/vc_rt.h:61` `void vc_rt_transform(float *mag, float *phase, size_t nbins, uint32_t sample_rate, size_t hop, void *user);` -- @brief Per-frame transform, compatible with vc_spectral_fn. @param user Must be a vc_rt_ctx_t* created with matching...
- `vc_rt_semitones_to_ratio` (function) `voicecloak/src/vc_rt.h:67` `float vc_rt_semitones_to_ratio(float semitones);` -- @brief Convert a semitone shift to a pitch ratio (2^(semitones/12)).
- `vc_rt_derive` (function) `voicecloak/src/vc_rt.h:78` `int vc_rt_derive(const unsigned char *pitch_seed, const unsigned char *formant_seed, const unsigned char...` -- @brief Derive cloak parameters from three 32-byte PRNG seeds. @param pitch_seed    32-byte seed. @param formant_seed...

## voicecloak/src/vc_rt_cli.c
Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_denoise.h`, `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_presets.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`
- `on_sigint` (function) `voicecloak/src/vc_rt_cli.c:24` `static void on_sigint(int sig)`
- `parse_float` (function) `voicecloak/src/vc_rt_cli.c:29` `static int parse_float(const char *text, float *out)`
- `print_usage` (function) `voicecloak/src/vc_rt_cli.c:40` `static void print_usage(const char *prog)`
- `dominant_freq` (function) `voicecloak/src/vc_rt_cli.c:94` `static float dominant_freq(const float *x, size_t n, unsigned int sr)`
- `cmd_selftest` (function) `voicecloak/src/vc_rt_cli.c:117` `static int cmd_selftest(void)`
- `resolve_params` (function) `voicecloak/src/vc_rt_cli.c:155` `static int resolve_params(int have_fixed, float semis, float formant,
                          f...`
- `cmd_live` (function) `voicecloak/src/vc_rt_cli.c:179` `static int cmd_live(int argc, char *argv[])`
- `main` (function) `voicecloak/src/vc_rt_cli.c:504` `int main(int argc, char *argv[])`

## voicecloak/src/vc_rt_seed.c
Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_rt.h`
- `vc_rt_derive` (function) `voicecloak/src/vc_rt_seed.c:5` `int vc_rt_derive(const unsigned char *pitch_seed,
                 const unsigned char *formant_s...`

## voicecloak/src/vc_stft.c
Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_stft.h`
- `vc_stft_create` (function) `voicecloak/src/vc_stft.c:21` `vc_stft_t *vc_stft_create(size_t fft_size, size_t hop_size)`
- `vc_stft_destroy` (function) `voicecloak/src/vc_stft.c:58` `void vc_stft_destroy(vc_stft_t *st)`
- `vc_stft_num_bins` (function) `voicecloak/src/vc_stft.c:67` `size_t vc_stft_num_bins(const vc_stft_t *st)`
- `vc_stft_forward` (function) `voicecloak/src/vc_stft.c:71` `int vc_stft_forward(vc_stft_t *st,
                    const float *samples, size_t num_samples,
...`
- `vc_stft_inverse` (function) `voicecloak/src/vc_stft.c:119` `int vc_stft_inverse(vc_stft_t *st,
                    const float *mag, const float *phase,
    ...`
- `vc_stft_inverse_hop` (function) `voicecloak/src/vc_stft.c:127` `int vc_stft_inverse_hop(vc_stft_t *st,
                        const float *mag, const float *pha...`

## voicecloak/src/vc_stft.h
Imported by: `voicecloak/src/vc_dsp.c`, `voicecloak/src/vc_stft.c`
- `vc_stft_create` (function) `voicecloak/src/vc_stft.h:25` `vc_stft_t *vc_stft_create(size_t fft_size, size_t hop_size);` -- @brief Allocate STFT context. @param fft_size  FFT size (power of 2, e.g.
- `vc_stft_destroy` (function) `voicecloak/src/vc_stft.h:30` `void vc_stft_destroy(vc_stft_t *st);` -- @brief Release STFT context.
- `vc_stft_forward` (function) `voicecloak/src/vc_stft.h:42` `int vc_stft_forward(vc_stft_t *st, const float *samples, size_t num_samples, float **mag, float **phase, size_t...` -- @brief Forward STFT: decompose a mono float buffer into complex frames. @param st       STFT context. @param samples...
- `vc_stft_inverse` (function) `voicecloak/src/vc_stft.h:57` `int vc_stft_inverse(vc_stft_t *st, const float *mag, const float *phase, size_t num_frames, float *samples_out...` -- @brief Inverse STFT: reconstruct signal from modified magnitude/phase. @param st        STFT context. @param mag...
- `vc_stft_inverse_hop` (function) `voicecloak/src/vc_stft.h:66` `int vc_stft_inverse_hop(vc_stft_t *st, const float *mag, const float *phase, size_t num_frames, float *samples_out...` -- @brief Inverse STFT with custom synthesis hop (for pitch shifting). @param synth_hop  Synthesis hop size in samples...
- `vc_stft_num_bins` (function) `voicecloak/src/vc_stft.h:75` `size_t vc_stft_num_bins(const vc_stft_t *st);` -- @brief Number of frequency bins (fft_size/2 + 1).

## voicecloak/src/vc_stream.c
Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_stream.h`
- `is_pow2` (function) `voicecloak/src/vc_stream.c:31` `static int is_pow2(size_t v)`
- `vc_stream_create` (function) `voicecloak/src/vc_stream.c:35` `vc_stream_t *vc_stream_create(size_t fft_size, size_t hop_size,
                              uin...`
- `vc_stream_destroy` (function) `voicecloak/src/vc_stream.c:94` `void vc_stream_destroy(vc_stream_t *st)`
- `vc_stream_latency_samples` (function) `voicecloak/src/vc_stream.c:107` `size_t vc_stream_latency_samples(const vc_stream_t *st)`
- `process_frame` (function) `voicecloak/src/vc_stream.c:111` `static void process_frame(vc_stream_t *st, vc_spectral_fn fn, void *user)`
- `vc_stream_process` (function) `voicecloak/src/vc_stream.c:159` `int vc_stream_process(vc_stream_t *st,
                      const float *in, float *out, size_t ...`
- `vc_spectral_chain_init` (function) `voicecloak/src/vc_stream.c:178` `void vc_spectral_chain_init(vc_spectral_chain_t *chain)`
- `vc_spectral_chain_add` (function) `voicecloak/src/vc_stream.c:182` `int vc_spectral_chain_add(vc_spectral_chain_t *chain, vc_spectral_fn fn,
                        ...`
- `vc_spectral_chain_run` (function) `voicecloak/src/vc_stream.c:191` `void vc_spectral_chain_run(float *mag, float *phase, size_t nbins,
                           uin...`

## voicecloak/src/vc_stream.h
Imported by: `voicecloak/src/vc_alsa.c`, `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/src/vc_stream.c`, `voicecloak/tests/test_vc_denoise.c`, `voicecloak/tests/test_vc_presets.c`, `voicecloak/tests/test_vc_stream.c`
- `frames` (function) `voicecloak/src/vc_stream.h:32` `* that must persist across frames (phase-vocoder accumulators) lives * in @p user, not in the engine. */ typedef...`
- `vc_spectral_chain_init` (function) `voicecloak/src/vc_stream.h:54` `void vc_spectral_chain_init(vc_spectral_chain_t *chain);` -- @brief Ordered list of spectral stages run as one vc_spectral_fn.
- `vc_spectral_chain_add` (function) `voicecloak/src/vc_stream.h:60` `int vc_spectral_chain_add(vc_spectral_chain_t *chain, vc_spectral_fn fn, void *user);` -- @brief Append a stage. @return 0 on success; -1 for NULL chain/fn or a full chain (unchanged).
- `vc_spectral_chain_run` (function) `voicecloak/src/vc_stream.h:67` `void vc_spectral_chain_run(float *mag, float *phase, size_t nbins, uint32_t sample_rate, size_t hop, void *user);` -- @brief vc_spectral_fn that runs every stage of the chain in @p user.
- `vc_stream_create` (function) `voicecloak/src/vc_stream.h:77` `vc_stream_t *vc_stream_create(size_t fft_size, size_t hop_size, uint32_t sample_rate);` -- @brief Create a streaming engine. @param fft_size  Power of two. @param hop_size  Must divide fft_size...
- `vc_stream_destroy` (function) `voicecloak/src/vc_stream.h:81` `void vc_stream_destroy(vc_stream_t *st);` -- @brief Create a streaming engine. @param fft_size  Power of two. @param hop_size  Must divide fft_size...
- `vc_stream_latency_samples` (function) `voicecloak/src/vc_stream.h:84` `size_t vc_stream_latency_samples(const vc_stream_t *st);` -- @brief Create a streaming engine. @param fft_size  Power of two. @param hop_size  Must divide fft_size...
- `vc_stream_process` (function) `voicecloak/src/vc_stream.h:96` `int vc_stream_process(vc_stream_t *st, const float *in, float *out, size_t n, vc_spectral_fn fn, void *user);` -- @brief Process a block, producing exactly @p n output samples. @param st   Engine. @param in   Input samples (length...

## voicecloak/src/vc_wav.c
Depends on: `voicecloak/src/vc_wav.h`
- `read_bytes` (function) `voicecloak/src/vc_wav.c:30` `static int read_bytes(FILE *fp, void *buf, size_t n)`
- `write_bytes` (function) `voicecloak/src/vc_wav.c:34` `static int write_bytes(FILE *fp, const void *buf, size_t n)`
- `sample_to_float` (function) `voicecloak/src/vc_wav.c:38` `static float sample_to_float(const unsigned char *p, int bps)`
- `float_to_sample` (function) `voicecloak/src/vc_wav.c:62` `static void float_to_sample(float f, unsigned char *p, int bps)`
- `find_chunk` (function) `voicecloak/src/vc_wav.c:78` `static int find_chunk(FILE *fp, const char *id, uint32_t *size)`
- `vc_wav_read` (function) `voicecloak/src/vc_wav.c:93` `int vc_wav_read(const char *path,
                float **samples_out, size_t *num_samples_out,
 ...`
- `vc_wav_write` (function) `voicecloak/src/vc_wav.c:169` `int vc_wav_write(const char *path,
                 const float *samples, size_t num_samples,
   ...`

## voicecloak/src/vc_wav.h
Imported by: `voicecloak/src/vc_cli.c`, `voicecloak/src/vc_wav.c`
- `vc_wav_read` (function) `voicecloak/src/vc_wav.h:19` `int vc_wav_read(const char *path, float **samples_out, size_t *num_samples_out, uint32_t *sample_rate_out);` -- @brief Read a mono PCM WAV file into a float buffer [-1.0, 1.0]. @param path         File path. @param samples_out...
- `vc_wav_write` (function) `voicecloak/src/vc_wav.h:31` `int vc_wav_write(const char *path, const float *samples, size_t num_samples, uint32_t sample_rate);` -- @brief Write a mono float buffer to a 16-bit PCM WAV file. @param path       File path. @param samples    Float...

