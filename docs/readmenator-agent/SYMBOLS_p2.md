# Symbols (page 2 of 2)
Previous: [SYMBOLS.md](SYMBOLS.md)

| Symbol | Kind | File:Line | Signature |
|--------|------|-----------|-----------|
| `VSL_Encode_Gain` | function | `src/vsl_dsp_logic.h:44` | `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);` |
| `VSL_Final_Encode_To_Int` | function | `src/vsl_dsp_logic.h:81` | `uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param);` |
| `VSL_INV_LN2` | macro | `src/vsl_dsp_logic.h:8` | `#define VSL_INV_LN2` |
| `VSL_MAX_ENCODED_FLOAT` | macro | `src/vsl_dsp_logic.h:9` | `#define VSL_MAX_ENCODED_FLOAT` |
| `VSL_Map_Frequency` | function | `src/vsl_dsp_logic.h:62` | `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);` |
| `VSL_Parameter` | struct | `src/vsl_dsp_logic.h:22` | `` |
| `negative` | function | `src/vsl_dsp_logic.h:87` | `* when linear_value is zero or negative (the `db.inf` domain). */ float VSL_Linear_To_DB(float linear_value);` |
| `VSL_Build_Packet` | function | `src/vsl_dsp_transport.c:79` | `int VSL_Build_Packet(uint16_t dsp_param_id,                      uint16_t encoded_value,         ...` |
| `VSL_Close_Device` | function | `src/vsl_dsp_transport.c:50` | `void VSL_Close_Device(vsl_device_handle handle)` |
| `VSL_Init_Device` | function | `src/vsl_dsp_transport.c:13` | `vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)` |
| `VSL_Send_Parameter` | function | `src/vsl_dsp_transport.c:96` | `int VSL_Send_Parameter(vsl_device_handle handle,                        uint16_t dsp_param_id,   ...` |
| `vsl_device` | struct | `src/vsl_dsp_transport.c:7` | `` |
| `VSL_Build_Packet` | function | `src/vsl_dsp_transport.h:39` | `int VSL_Build_Packet(uint16_t dsp_param_id, uint16_t encoded_value, unsigned char *out);` |
| `VSL_Close_Device` | function | `src/vsl_dsp_transport.h:26` | `void VSL_Close_Device(vsl_device_handle handle);` |
| `VSL_DSP_TRANSPORT_H` | macro | `src/vsl_dsp_transport.h:2` | `#define VSL_DSP_TRANSPORT_H` |
| `VSL_Send_Parameter` | function | `src/vsl_dsp_transport.h:50` | `int VSL_Send_Parameter(vsl_device_handle handle, uint16_t dsp_param_id, uint16_t encoded_value);` |
| `evidence` | function | `src/vsl_dsp_transport.h:37` | `* evidence (blockers #2/#3);` |
| `vsl_device_handle` | variable | `src/vsl_dsp_transport.h:9` | `extern "C" { #endif typedef void* vsl_device_handle;` |
| `vsl_device_handle` | type_alias | `src/vsl_dsp_transport.h:11` | `typedef void* vsl_device_handle;` |
| `bad` | function | `tests/bdd_driver_gate.sh:30` | `` |
| `ok` | function | `tests/bdd_driver_gate.sh:29` | `` |
| `main` | function | `tests/test_audiobox_vsl.c:155` | `int main(void)` |
| `test_lookup_handles_full_pid_range` | function | `tests/test_audiobox_vsl.c:95` | `static void test_lookup_handles_full_pid_range(void **state)` |
| `test_lookup_returns_1818_vsl` | function | `tests/test_audiobox_vsl.c:75` | `static void test_lookup_returns_1818_vsl(void **state)` |
| `test_lookup_returns_22_vsl` | function | `tests/test_audiobox_vsl.c:55` | `static void test_lookup_returns_22_vsl(void **state)` |
| `test_lookup_returns_44_vsl` | function | `tests/test_audiobox_vsl.c:65` | `static void test_lookup_returns_44_vsl(void **state)` |
| `test_lookup_returns_null_for_unknown_pid` | function | `tests/test_audiobox_vsl.c:85` | `static void test_lookup_returns_null_for_unknown_pid(void **state)` |
| `test_model_pids_match_table` | function | `tests/test_audiobox_vsl.c:46` | `static void test_model_pids_match_table(void **state)` |
| `test_primary_interface_announces_once` | function | `tests/test_audiobox_vsl.c:143` | `static void test_primary_interface_announces_once(void **state)` |
| `test_supported_models_table_shape` | function | `tests/test_audiobox_vsl.c:31` | `static void test_supported_models_table_shape(void **state)` |
| `test_table_pids_are_unique` | function | `tests/test_audiobox_vsl.c:115` | `static void test_table_pids_are_unique(void **state)` |
| `test_table_product_names_non_empty` | function | `tests/test_audiobox_vsl.c:126` | `static void test_table_product_names_non_empty(void **state)` |
| `test_version_string_is_release` | function | `tests/test_audiobox_vsl.c:136` | `static void test_version_string_is_release(void **state)` |
| `_GNU_SOURCE` | macro | `voicecloak/src/vc_alsa.c:1` | `#define _GNU_SOURCE` |
| `fmt_bps` | function | `voicecloak/src/vc_alsa.c:20` | `static size_t fmt_bps(snd_pcm_format_t f)` |
| `mono_to_raw` | function | `voicecloak/src/vc_alsa.c:130` | `static void mono_to_raw(unsigned char *raw, const float *mono,                         snd_pcm_uf...` |
| `open_stream` | function | `voicecloak/src/vc_alsa.c:29` | `static int open_stream(vc_pcm_t *s, const char *dev, snd_pcm_stream_t dir,                       ...` |
| `raw_to_mono` | function | `voicecloak/src/vc_alsa.c:99` | `static void raw_to_mono(const unsigned char *raw, float *mono,                         snd_pcm_uf...` |
| `vc_alsa_list` | function | `voicecloak/src/vc_alsa.c:163` | `int vc_alsa_list(void)` |
| `vc_alsa_run` | function | `voicecloak/src/vc_alsa.c:189` | `int vc_alsa_run(const vc_alsa_cfg_t *cfg)` |
| `vc_pcm_t` | struct | `voicecloak/src/vc_alsa.c:13` | `` |
| `VC_ALSA_H` | macro | `voicecloak/src/vc_alsa.h:2` | `#define VC_ALSA_H` |
| `runtime` | function | `voicecloak/src/vc_alsa.h:20` | `* * The capture and playback device names are ALSA PCM names discovered * at runtime (e.g. "hw:VSL", "plughw:2,0"...` |
| `vc_alsa_cfg_t` | struct | `voicecloak/src/vc_alsa.h:26` | `` |
| `vc_alsa_list` | function | `voicecloak/src/vc_alsa.h:46` | `int vc_alsa_list(void);` |
| `vc_alsa_run` | function | `voicecloak/src/vc_alsa.h:53` | `int vc_alsa_run(const vc_alsa_cfg_t *cfg);` |
| `VC_AUDIO_CONFIG_H` | macro | `voicecloak/src/vc_audio_config.h:2` | `#define VC_AUDIO_CONFIG_H` |
| `VC_AUDIO_MAX_INTERNAL_SAMPLE` | macro | `voicecloak/src/vc_audio_config.h:9` | `#define VC_AUDIO_MAX_INTERNAL_SAMPLE` |
| `VC_AUDIO_MAX_SAMPLE_RATE` | macro | `voicecloak/src/vc_audio_config.h:6` | `#define VC_AUDIO_MAX_SAMPLE_RATE` |
| `VC_AUDIO_MIN_SAMPLE_RATE` | macro | `voicecloak/src/vc_audio_config.h:5` | `#define VC_AUDIO_MIN_SAMPLE_RATE` |
| `VC_LEVEL_MAX_CEILING_DBFS` | macro | `voicecloak/src/vc_audio_config.h:14` | `#define VC_LEVEL_MAX_CEILING_DBFS` |
| `VC_LEVEL_MAX_GAIN_DB` | macro | `voicecloak/src/vc_audio_config.h:15` | `#define VC_LEVEL_MAX_GAIN_DB` |
| `VC_LEVEL_MAX_SATURATION_DRIVE` | macro | `voicecloak/src/vc_audio_config.h:19` | `#define VC_LEVEL_MAX_SATURATION_DRIVE` |
| `VC_LEVEL_MAX_TARGET_DBFS` | macro | `voicecloak/src/vc_audio_config.h:12` | `#define VC_LEVEL_MAX_TARGET_DBFS` |
| `VC_LEVEL_MAX_TIME_MS` | macro | `voicecloak/src/vc_audio_config.h:17` | `#define VC_LEVEL_MAX_TIME_MS` |
| `VC_LEVEL_MIN_CEILING_DBFS` | macro | `voicecloak/src/vc_audio_config.h:13` | `#define VC_LEVEL_MIN_CEILING_DBFS` |
| `VC_LEVEL_MIN_TARGET_DBFS` | macro | `voicecloak/src/vc_audio_config.h:11` | `#define VC_LEVEL_MIN_TARGET_DBFS` |
| `VC_LEVEL_MIN_TIME_MS` | macro | `voicecloak/src/vc_audio_config.h:16` | `#define VC_LEVEL_MIN_TIME_MS` |
| `VC_LEVEL_RMS_FLOOR` | macro | `voicecloak/src/vc_audio_config.h:18` | `#define VC_LEVEL_RMS_FLOOR` |
| `cmd_cloak` | function | `voicecloak/src/vc_cli.c:53` | `static int cmd_cloak(const char *pubkey_path,                      const char *in_path, const cha...` |
| `cmd_info` | function | `voicecloak/src/vc_cli.c:142` | `static int cmd_info(const char *path)` |
| `cmd_keygen` | function | `voicecloak/src/vc_cli.c:41` | `static int cmd_keygen(void)` |
| `main` | function | `voicecloak/src/vc_cli.c:177` | `int main(int argc, char *argv[])` |
| `print_usage` | function | `voicecloak/src/vc_cli.c:9` | `static void print_usage(const char *prog)` |
| `openssl_init` | function | `voicecloak/src/vc_crypto.c:12` | `static void openssl_init(void)` |
| `vc_crypto_derive_seeds` | function | `voicecloak/src/vc_crypto.c:96` | `int vc_crypto_derive_seeds(const unsigned char *master_seed, size_t seed_len,                    ...` |
| `vc_crypto_keygen` | function | `voicecloak/src/vc_crypto.c:17` | `int vc_crypto_keygen(const char *pubkey_path, const char *privkey_path)` |
| `vc_crypto_seal` | function | `voicecloak/src/vc_crypto.c:47` | `int vc_crypto_seal(const char *pubkey_path,                    const unsigned char *seed, size_t ...` |
| `vc_crypto_unseal` | function | `voicecloak/src/vc_crypto.c:71` | `int vc_crypto_unseal(const char *privkey_path,                      const unsigned char *enc, siz...` |
| `vc_prng_create` | function | `voicecloak/src/vc_crypto.c:143` | `vc_prng_t *vc_prng_create(const unsigned char *seed)` |
| `vc_prng_destroy` | function | `voicecloak/src/vc_crypto.c:157` | `void vc_prng_destroy(vc_prng_t *p)` |
| `vc_prng_fill` | function | `voicecloak/src/vc_crypto.c:164` | `void vc_prng_fill(vc_prng_t *p, unsigned char *buf, size_t len)` |
| `vc_prng_float` | function | `voicecloak/src/vc_crypto.c:184` | `float vc_prng_float(vc_prng_t *p, float low, float high)` |
| `vc_prng_s` | struct | `voicecloak/src/vc_crypto.c:136` | `` |
| `VC_CRYPTO_H` | macro | `voicecloak/src/vc_crypto.h:2` | `#define VC_CRYPTO_H` |
| `VC_CRYPTO_KEY_BYTES` | macro | `voicecloak/src/vc_crypto.h:12` | `#define VC_CRYPTO_KEY_BYTES` |
| `VC_CRYPTO_SEED_BYTES` | macro | `voicecloak/src/vc_crypto.h:11` | `#define VC_CRYPTO_SEED_BYTES` |
| `VC_FORMANT_SEED_BYTES` | macro | `voicecloak/src/vc_crypto.h:14` | `#define VC_FORMANT_SEED_BYTES` |
| `VC_PITCH_SEED_BYTES` | macro | `voicecloak/src/vc_crypto.h:13` | `#define VC_PITCH_SEED_BYTES` |
| `VC_SPECTRAL_SEED_BYTES` | macro | `voicecloak/src/vc_crypto.h:15` | `#define VC_SPECTRAL_SEED_BYTES` |
| `VC_TOTAL_SEED_BYTES` | macro | `voicecloak/src/vc_crypto.h:16` | `#define VC_TOTAL_SEED_BYTES` |
| `vc_crypto_derive_seeds` | function | `voicecloak/src/vc_crypto.h:61` | `int vc_crypto_derive_seeds(const unsigned char *master_seed, size_t seed_len, unsigned char *pitch_seed, unsigned...` |
| `vc_crypto_keygen` | function | `voicecloak/src/vc_crypto.h:24` | `int vc_crypto_keygen(const char *pubkey_path, const char *privkey_path);` |
| `vc_crypto_seal` | function | `voicecloak/src/vc_crypto.h:35` | `int vc_crypto_seal(const char *pubkey_path, const unsigned char *seed, size_t seed_len, unsigned char *enc_out...` |
| `vc_crypto_unseal` | function | `voicecloak/src/vc_crypto.h:48` | `int vc_crypto_unseal(const char *privkey_path, const unsigned char *enc, size_t enc_len, unsigned char *seed, size_t...` |
| `vc_prng_create` | function | `voicecloak/src/vc_crypto.h:77` | `vc_prng_t *vc_prng_create(const unsigned char *seed);` |
| `vc_prng_destroy` | function | `voicecloak/src/vc_crypto.h:82` | `void vc_prng_destroy(vc_prng_t *p);` |
| `vc_prng_fill` | function | `voicecloak/src/vc_crypto.h:87` | `void vc_prng_fill(vc_prng_t *p, unsigned char *buf, size_t len);` |
| `vc_prng_float` | function | `voicecloak/src/vc_crypto.h:92` | `float vc_prng_float(vc_prng_t *p, float low, float high);` |
| `vc_prng_t` | type_alias | `voicecloak/src/vc_crypto.h:72` | `typedef struct vc_prng_s vc_prng_t;` |
| `VC_DENOISE_MAGIC` | macro | `voicecloak/src/vc_denoise.c:9` | `#define VC_DENOISE_MAGIC` |
| `VC_DENOISE_VERSION` | macro | `voicecloak/src/vc_denoise.c:10` | `#define VC_DENOISE_VERSION` |
| `install_profile` | function | `voicecloak/src/vc_denoise.c:108` | `static void install_profile(vc_denoise_t *dn, uint32_t sample_rate)` |
| `learn` | function | `voicecloak/src/vc_denoise.c:117` | `static void learn(vc_denoise_t *dn, float *mag, uint32_t sample_rate,                   size_t hop)` |
| `mute` | function | `voicecloak/src/vc_denoise.c:104` | `static void mute(float *mag, size_t nbins)` |
| `params_valid` | function | `voicecloak/src/vc_denoise.c:39` | `static int params_valid(const vc_denoise_params_t *p)` |
| `parse_header` | function | `voicecloak/src/vc_denoise.c:208` | `static int parse_header(const char **cursor, unsigned long *rate,                         unsigne...` |
| `parse_ulong` | function | `voicecloak/src/vc_denoise.c:196` | `static int parse_ulong(const char **cursor, unsigned long *out)` |
| `reset_tracking` | function | `voicecloak/src/vc_denoise.c:57` | `static void reset_tracking(vc_denoise_t *dn)` |
| `restart_learning` | function | `voicecloak/src/vc_denoise.c:64` | `static void restart_learning(vc_denoise_t *dn)` |
| `update_gate` | function | `voicecloak/src/vc_denoise.c:136` | `static void update_gate(vc_denoise_t *dn, double frame_power,                         uint32_t sa...` |
| `vc_denoise_create` | function | `voicecloak/src/vc_denoise.c:71` | `vc_denoise_t *vc_denoise_create(size_t nbins,                                 const vc_denoise_pa...` |
| `vc_denoise_destroy` | function | `voicecloak/src/vc_denoise.c:92` | `void vc_denoise_destroy(vc_denoise_t *denoise)` |
| `vc_denoise_is_ready` | function | `voicecloak/src/vc_denoise.c:100` | `int vc_denoise_is_ready(const vc_denoise_t *denoise)` |
| `vc_denoise_load` | function | `voicecloak/src/vc_denoise.c:280` | `int vc_denoise_load(vc_denoise_t *denoise, const char *path)` |
| `vc_denoise_params_defaults` | function | `voicecloak/src/vc_denoise.c:29` | `void vc_denoise_params_defaults(vc_denoise_params_t *params)` |
| `vc_denoise_profile_parse` | function | `voicecloak/src/vc_denoise.c:224` | `int vc_denoise_profile_parse(vc_denoise_t *denoise, const char *text,                            ...` |
| `vc_denoise_s` | struct | `voicecloak/src/vc_denoise.c:12` | `` |
| `vc_denoise_save` | function | `voicecloak/src/vc_denoise.c:266` | `int vc_denoise_save(const vc_denoise_t *denoise, const char *path)` |
| `vc_denoise_transform` | function | `voicecloak/src/vc_denoise.c:158` | `void vc_denoise_transform(float *mag, float *phase, size_t nbins,                           uint3...` |
| `VC_DENOISE_DEFAULT_FLOOR_DB` | macro | `voicecloak/src/vc_denoise.h:13` | `#define VC_DENOISE_DEFAULT_FLOOR_DB` |
| `VC_DENOISE_DEFAULT_GATE_RANGE_DB` | macro | `voicecloak/src/vc_denoise.h:16` | `#define VC_DENOISE_DEFAULT_GATE_RANGE_DB` |
| `VC_DENOISE_DEFAULT_GATE_SNR_DB` | macro | `voicecloak/src/vc_denoise.h:15` | `#define VC_DENOISE_DEFAULT_GATE_SNR_DB` |
| `VC_DENOISE_DEFAULT_LEARN_MS` | macro | `voicecloak/src/vc_denoise.h:17` | `#define VC_DENOISE_DEFAULT_LEARN_MS` |
| `VC_DENOISE_DEFAULT_REDUCTION` | macro | `voicecloak/src/vc_denoise.h:12` | `#define VC_DENOISE_DEFAULT_REDUCTION` |
| `VC_DENOISE_DEFAULT_SMOOTHING` | macro | `voicecloak/src/vc_denoise.h:14` | `#define VC_DENOISE_DEFAULT_SMOOTHING` |
| `VC_DENOISE_GATE_HYSTERESIS_DB` | macro | `voicecloak/src/vc_denoise.h:27` | `#define VC_DENOISE_GATE_HYSTERESIS_DB` |
| `VC_DENOISE_GATE_RELEASE_MS` | macro | `voicecloak/src/vc_denoise.h:28` | `#define VC_DENOISE_GATE_RELEASE_MS` |
| `VC_DENOISE_H` | macro | `voicecloak/src/vc_denoise.h:2` | `#define VC_DENOISE_H` |
| `VC_DENOISE_MAX_GATE_RANGE_DB` | macro | `voicecloak/src/vc_denoise.h:24` | `#define VC_DENOISE_MAX_GATE_RANGE_DB` |
| `VC_DENOISE_MAX_GATE_SNR_DB` | macro | `voicecloak/src/vc_denoise.h:23` | `#define VC_DENOISE_MAX_GATE_SNR_DB` |
| `VC_DENOISE_MAX_LEARN_MS` | macro | `voicecloak/src/vc_denoise.h:26` | `#define VC_DENOISE_MAX_LEARN_MS` |
| `VC_DENOISE_MAX_PROFILE_BYTES` | macro | `voicecloak/src/vc_denoise.h:29` | `#define VC_DENOISE_MAX_PROFILE_BYTES` |
| `VC_DENOISE_MAX_REDUCTION` | macro | `voicecloak/src/vc_denoise.h:20` | `#define VC_DENOISE_MAX_REDUCTION` |
| `VC_DENOISE_MAX_SMOOTHING` | macro | `voicecloak/src/vc_denoise.h:22` | `#define VC_DENOISE_MAX_SMOOTHING` |
| `VC_DENOISE_MIN_FLOOR_DB` | macro | `voicecloak/src/vc_denoise.h:21` | `#define VC_DENOISE_MIN_FLOOR_DB` |
| `VC_DENOISE_MIN_LEARN_MS` | macro | `voicecloak/src/vc_denoise.h:25` | `#define VC_DENOISE_MIN_LEARN_MS` |
| `VC_DENOISE_MIN_REDUCTION` | macro | `voicecloak/src/vc_denoise.h:19` | `#define VC_DENOISE_MIN_REDUCTION` |
| `first` | function | `voicecloak/src/vc_denoise.h:70` | `* * Learns the noise print first (muting those frames), then applies * power spectral subtraction and the spectral...` |
| `loaded` | variable | `voicecloak/src/vc_denoise.h:9` | `extern "C" { #endif #define VC_DENOISE_DEFAULT_REDUCTION 2.0f #define VC_DENOISE_DEFAULT_FLOOR_DB (-24.0f) #define...` |
| `vc_denoise_create` | function | `voicecloak/src/vc_denoise.h:61` | `vc_denoise_t *vc_denoise_create(size_t nbins, const vc_denoise_params_t *params);` |
| `vc_denoise_destroy` | function | `voicecloak/src/vc_denoise.h:65` | `void vc_denoise_destroy(vc_denoise_t *denoise);` |
| `vc_denoise_is_ready` | function | `voicecloak/src/vc_denoise.h:79` | `int vc_denoise_is_ready(const vc_denoise_t *denoise);` |
| `vc_denoise_load` | function | `voicecloak/src/vc_denoise.h:92` | `int vc_denoise_load(vc_denoise_t *denoise, const char *path);` |
| `vc_denoise_params_defaults` | function | `voicecloak/src/vc_denoise.h:55` | `void vc_denoise_params_defaults(vc_denoise_params_t *params);` |
| `vc_denoise_params_t` | struct | `voicecloak/src/vc_denoise.h:43` | `` |
| `vc_denoise_profile_parse` | function | `voicecloak/src/vc_denoise.h:85` | `int vc_denoise_profile_parse(vc_denoise_t *denoise, const char *text, size_t length);` |
| `vc_denoise_save` | function | `voicecloak/src/vc_denoise.h:89` | `int vc_denoise_save(const vc_denoise_t *denoise, const char *path);` |
| `vc_denoise_t` | type_alias | `voicecloak/src/vc_denoise.h:51` | `typedef struct vc_denoise_s vc_denoise_t;` |
| `VC_FFT_SIZE` | macro | `voicecloak/src/vc_dsp.c:9` | `#define VC_FFT_SIZE` |
| `VC_HOP_SIZE` | macro | `voicecloak/src/vc_dsp.c:10` | `#define VC_HOP_SIZE` |
| `compute_out_len` | function | `voicecloak/src/vc_dsp.c:31` | `static size_t compute_out_len(size_t nframes, size_t hop)` |
| `normalize_rms` | function | `voicecloak/src/vc_dsp.c:255` | `static void normalize_rms(const float *in, size_t in_len,                           float *out, s...` |
| `stft_process` | function | `voicecloak/src/vc_dsp.c:12` | `static int stft_process(const float *samples, size_t num_samples,                         float *...` |
| `stft_reconstruct` | function | `voicecloak/src/vc_dsp.c:21` | `static int stft_reconstruct(const float *mag, const float *phase,                             siz...` |
| `trim_edges` | function | `voicecloak/src/vc_dsp.c:234` | `static void trim_edges(float **buf, size_t *len)` |
| `vc_dsp_cloak` | function | `voicecloak/src/vc_dsp.c:272` | `int vc_dsp_cloak(const float *samples, size_t num_samples,                  uint32_t sample_rate,...` |
| `vc_dsp_formant_shift` | function | `voicecloak/src/vc_dsp.c:91` | `int vc_dsp_formant_shift(const float *samples, size_t num_samples,                          uint3...` |
| `vc_dsp_pitch_shift` | function | `voicecloak/src/vc_dsp.c:35` | `int vc_dsp_pitch_shift(const float *samples, size_t num_samples,                        uint32_t ...` |
| `vc_dsp_spectral_scramble` | function | `voicecloak/src/vc_dsp.c:161` | `int vc_dsp_spectral_scramble(const float *samples, size_t num_samples,                           ...` |
| `VC_DSP_H` | macro | `voicecloak/src/vc_dsp.h:2` | `#define VC_DSP_H` |
| `VcMode` | variable | `voicecloak/src/vc_dsp.h:8` | `extern "C" { #endif typedef enum { VC_MODE_SUBTLE = 0, VC_MODE_WITNESS = 1 } VcMode;` |
| `vc_dsp_cloak` | function | `voicecloak/src/vc_dsp.h:28` | `int vc_dsp_cloak(const float *samples, size_t num_samples, uint32_t sample_rate, const unsigned char *pitch_seed...` |
| `vc_dsp_formant_shift` | function | `voicecloak/src/vc_dsp.h:20` | `int vc_dsp_formant_shift(const float *samples, size_t num_samples, uint32_t sample_rate, float shift_factor, float...` |
| `vc_dsp_pitch_shift` | function | `voicecloak/src/vc_dsp.h:16` | `int vc_dsp_pitch_shift(const float *samples, size_t num_samples, uint32_t sample_rate, float semitones, float **out...` |
| `vc_dsp_spectral_scramble` | function | `voicecloak/src/vc_dsp.h:24` | `int vc_dsp_spectral_scramble(const float *samples, size_t num_samples, uint32_t sample_rate, float intensity, float...` |
| `M_PI` | macro | `voicecloak/src/vc_effects.c:8` | `#define M_PI` |
| `VC_EFFECT_MAX_DELAY_MS` | macro | `voicecloak/src/vc_effects.c:11` | `#define VC_EFFECT_MAX_DELAY_MS` |
| `VC_METALLIC_MAX_DELAY_MS` | macro | `voicecloak/src/vc_effects.c:16` | `#define VC_METALLIC_MAX_DELAY_MS` |
| `VC_METALLIC_MAX_FEEDBACK` | macro | `voicecloak/src/vc_effects.c:17` | `#define VC_METALLIC_MAX_FEEDBACK` |
| `VC_REVERB_MAX_COMB_DELAY_MS` | macro | `voicecloak/src/vc_effects.c:12` | `#define VC_REVERB_MAX_COMB_DELAY_MS` |
| `VC_REVERB_MAX_DECAY_SECONDS` | macro | `voicecloak/src/vc_effects.c:14` | `#define VC_REVERB_MAX_DECAY_SECONDS` |
| `VC_REVERB_MAX_FEEDBACK` | macro | `voicecloak/src/vc_effects.c:15` | `#define VC_REVERB_MAX_FEEDBACK` |
| `VC_REVERB_MIN_DECAY_SECONDS` | macro | `voicecloak/src/vc_effects.c:13` | `#define VC_REVERB_MIN_DECAY_SECONDS` |
| `VC_RING_SQUARE_SHARPNESS` | macro | `voicecloak/src/vc_effects.c:18` | `#define VC_RING_SQUARE_SHARPNESS` |
| `alloc_comb` | function | `voicecloak/src/vc_effects.c:111` | `static int alloc_comb(vc_comb_t *comb, float milliseconds,                       uint32_t sample_...` |
| `finite_params` | function | `voicecloak/src/vc_effects.c:40` | `static int finite_params(const vc_effects_params_t *p)` |
| `free_combs` | function | `voicecloak/src/vc_effects.c:121` | `static void free_combs(vc_effects_t *fx)` |
| `params_valid` | function | `voicecloak/src/vc_effects.c:61` | `static int params_valid(uint32_t sample_rate, const vc_effects_params_t *p)` |
| `process_metallic` | function | `voicecloak/src/vc_effects.c:260` | `static float process_metallic(vc_effects_t *fx, float input)` |
| `process_one` | function | `voicecloak/src/vc_effects.c:270` | `static float process_one(vc_effects_t *fx, float input)` |
| `process_phaser` | function | `voicecloak/src/vc_effects.c:228` | `static float process_phaser(vc_effects_t *fx, float input, double lfo)` |
| `process_reverb` | function | `voicecloak/src/vc_effects.c:214` | `static float process_reverb(vc_effects_t *fx, float input)` |
| `process_space` | function | `voicecloak/src/vc_effects.c:197` | `static float process_space(vc_effects_t *fx, float input, double lfo)` |
| `reset_state` | function | `voicecloak/src/vc_effects.c:180` | `static void reset_state(vc_effects_t *fx)` |
| `ring_modulate` | function | `voicecloak/src/vc_effects.c:249` | `static float ring_modulate(const vc_effects_t *fx, float input)` |
| `ring_valid` | function | `voicecloak/src/vc_effects.c:53` | `static int ring_valid(const vc_effects_params_t *p, float nyquist)` |
| `samples_from_ms` | function | `voicecloak/src/vc_effects.c:105` | `static size_t samples_from_ms(float milliseconds, uint32_t sample_rate)` |
| `vc_comb_t` | struct | `voicecloak/src/vc_effects.c:20` | `` |
| `vc_effects_create` | function | `voicecloak/src/vc_effects.c:129` | `vc_effects_t *vc_effects_create(uint32_t sample_rate,                                 const vc_ef...` |
| `vc_effects_destroy` | function | `voicecloak/src/vc_effects.c:173` | `void vc_effects_destroy(vc_effects_t *effects)` |
| `vc_effects_process` | function | `voicecloak/src/vc_effects.c:309` | `int vc_effects_process(vc_effects_t *effects, float *samples, size_t count)` |
| `vc_effects_s` | struct | `voicecloak/src/vc_effects.c:27` | `` |
| `VC_EFFECTS_H` | macro | `voicecloak/src/vc_effects.h:2` | `#define VC_EFFECTS_H` |
| `VC_PHASER_STAGE_COUNT` | macro | `voicecloak/src/vc_effects.h:13` | `#define VC_PHASER_STAGE_COUNT` |
| `VC_REVERB_COMB_COUNT` | macro | `voicecloak/src/vc_effects.h:12` | `#define VC_REVERB_COMB_COUNT` |
| `vc_effect_kind_t` | variable | `voicecloak/src/vc_effects.h:9` | `extern "C" { #endif #define VC_REVERB_COMB_COUNT 4U #define VC_PHASER_STAGE_COUNT 6U typedef enum { VC_EFFECT_NONE =...` |
| `vc_effects_create` | function | `voicecloak/src/vc_effects.h:60` | `vc_effects_t *vc_effects_create(uint32_t sample_rate, const vc_effects_params_t *params);` |
| `vc_effects_destroy` | function | `voicecloak/src/vc_effects.h:64` | `void vc_effects_destroy(vc_effects_t *effects);` |
| `vc_effects_params_t` | struct | `voicecloak/src/vc_effects.h:38` | `` |
| `vc_effects_process` | function | `voicecloak/src/vc_effects.h:71` | `int vc_effects_process(vc_effects_t *effects, float *samples, size_t count);` |
| `vc_effects_t` | type_alias | `voicecloak/src/vc_effects.h:53` | `typedef struct vc_effects_s vc_effects_t;` |
| `M_PI` | macro | `voicecloak/src/vc_eq.c:8` | `#define M_PI` |
| `VC_EQ_BUTTERWORTH_Q` | macro | `voicecloak/src/vc_eq.c:11` | `#define VC_EQ_BUTTERWORTH_Q` |
| `design_highpass` | function | `voicecloak/src/vc_eq.c:49` | `static void design_highpass(vc_biquad_t *f, double hz, double rate)` |
| `design_peaking` | function | `voicecloak/src/vc_eq.c:57` | `static void design_peaking(vc_biquad_t *f, double hz, double gain_db,                            ...` |
| `fail_closed` | function | `voicecloak/src/vc_eq.c:93` | `static void fail_closed(vc_eq_t *eq, float *samples, size_t count)` |
| `normalize` | function | `voicecloak/src/vc_eq.c:39` | `static void normalize(vc_biquad_t *f, double b0, double b1, double b2,                       doub...` |
| `params_valid` | function | `voicecloak/src/vc_eq.c:24` | `static int params_valid(uint32_t sample_rate, const vc_eq_params_t *p)` |
| `run_biquad` | function | `voicecloak/src/vc_eq.c:85` | `static double run_biquad(vc_biquad_t *f, double x)` |
| `vc_biquad_t` | struct | `voicecloak/src/vc_eq.c:13` | `` |
| `vc_eq_create` | function | `voicecloak/src/vc_eq.c:67` | `vc_eq_t *vc_eq_create(uint32_t sample_rate, const vc_eq_params_t *params)` |
| `vc_eq_destroy` | function | `voicecloak/src/vc_eq.c:81` | `void vc_eq_destroy(vc_eq_t *eq)` |
| `vc_eq_process` | function | `voicecloak/src/vc_eq.c:99` | `int vc_eq_process(vc_eq_t *eq, float *samples, size_t count)` |
| `vc_eq_s` | struct | `voicecloak/src/vc_eq.c:19` | `` |
| `VC_EQ_H` | macro | `voicecloak/src/vc_eq.h:2` | `#define VC_EQ_H` |
| `VC_EQ_MAX_GAIN_DB` | macro | `voicecloak/src/vc_eq.h:12` | `#define VC_EQ_MAX_GAIN_DB` |
| `VC_EQ_MAX_Q` | macro | `voicecloak/src/vc_eq.h:14` | `#define VC_EQ_MAX_Q` |
| `VC_EQ_MIN_Q` | macro | `voicecloak/src/vc_eq.h:13` | `#define VC_EQ_MIN_Q` |
| `section` | variable | `voicecloak/src/vc_eq.h:9` | `extern "C" { #endif #define VC_EQ_MAX_GAIN_DB 12.0f #define VC_EQ_MIN_Q 0.1f #define VC_EQ_MAX_Q 10.0f /** * @brief...` |
| `vc_eq_create` | function | `voicecloak/src/vc_eq.h:36` | `vc_eq_t *vc_eq_create(uint32_t sample_rate, const vc_eq_params_t *params);` |
| `vc_eq_destroy` | function | `voicecloak/src/vc_eq.h:39` | `void vc_eq_destroy(vc_eq_t *eq);` |
| `vc_eq_params_t` | struct | `voicecloak/src/vc_eq.h:23` | `` |
| `vc_eq_process` | function | `voicecloak/src/vc_eq.h:46` | `int vc_eq_process(vc_eq_t *eq, float *samples, size_t count);` |
| `vc_eq_t` | type_alias | `voicecloak/src/vc_eq.h:29` | `typedef struct vc_eq_s vc_eq_t;` |
| `M_PI` | macro | `voicecloak/src/vc_fft.c:7` | `#define M_PI` |
| `bit_reverse` | function | `voicecloak/src/vc_fft.c:10` | `static unsigned int bit_reverse(unsigned int x, unsigned int bits)` |
| `bit_reverse_reorder` | function | `voicecloak/src/vc_fft.c:20` | `static void bit_reverse_reorder(size_t n, float *real, float *imag)` |
| `vc_fft` | function | `voicecloak/src/vc_fft.c:36` | `void vc_fft(size_t n, float *real, float *imag, int inverse)` |
| `FFT` | function | `voicecloak/src/vc_fft.h:18` | `* FFT(IFFT(x)) == IFFT(FFT(x)) == x. */ void vc_fft(size_t n, float *real, float *imag, int inverse);` |
| `VC_FFT_H` | macro | `voicecloak/src/vc_fft.h:2` | `#define VC_FFT_H` |
| `config_valid` | function | `voicecloak/src/vc_level.c:22` | `static int config_valid(uint32_t sample_rate, const vc_level_config_t *config)` |
| `silence_block` | function | `voicecloak/src/vc_level.c:94` | `static void silence_block(float *samples, size_t count)` |
| `time_alpha` | function | `voicecloak/src/vc_level.c:50` | `static float time_alpha(float milliseconds, uint32_t sample_rate)` |
| `vc_level_config_defaults` | function | `voicecloak/src/vc_level.c:55` | `void vc_level_config_defaults(vc_level_config_t *config)` |
| `vc_level_create` | function | `voicecloak/src/vc_level.c:67` | `vc_level_t *vc_level_create(uint32_t sample_rate,                             const vc_level_conf...` |
| `vc_level_current_gain_db` | function | `voicecloak/src/vc_level.c:169` | `float vc_level_current_gain_db(const vc_level_t *level)` |
| `vc_level_destroy` | function | `voicecloak/src/vc_level.c:90` | `void vc_level_destroy(vc_level_t *level)` |
| `vc_level_process` | function | `voicecloak/src/vc_level.c:99` | `int vc_level_process(vc_level_t *level, float *samples, size_t count)` |
| `vc_level_s` | struct | `voicecloak/src/vc_level.c:6` | `` |
| `VC_LEVEL_DEFAULT_ATTACK_MS` | macro | `voicecloak/src/vc_level.h:15` | `#define VC_LEVEL_DEFAULT_ATTACK_MS` |
| `VC_LEVEL_DEFAULT_CEILING_DBFS` | macro | `voicecloak/src/vc_level.h:14` | `#define VC_LEVEL_DEFAULT_CEILING_DBFS` |
| `VC_LEVEL_DEFAULT_LIMITER_RELEASE_MS` | macro | `voicecloak/src/vc_level.h:17` | `#define VC_LEVEL_DEFAULT_LIMITER_RELEASE_MS` |
| `VC_LEVEL_DEFAULT_MAX_GAIN_DB` | macro | `voicecloak/src/vc_level.h:13` | `#define VC_LEVEL_DEFAULT_MAX_GAIN_DB` |
| `VC_LEVEL_DEFAULT_RELEASE_MS` | macro | `voicecloak/src/vc_level.h:16` | `#define VC_LEVEL_DEFAULT_RELEASE_MS` |
| `VC_LEVEL_DEFAULT_SATURATION_DRIVE` | macro | `voicecloak/src/vc_level.h:18` | `#define VC_LEVEL_DEFAULT_SATURATION_DRIVE` |
| `VC_LEVEL_DEFAULT_TARGET_DBFS` | macro | `voicecloak/src/vc_level.h:12` | `#define VC_LEVEL_DEFAULT_TARGET_DBFS` |
| `VC_LEVEL_H` | macro | `voicecloak/src/vc_level.h:2` | `#define VC_LEVEL_H` |
| `saturation` | variable | `voicecloak/src/vc_level.h:9` | `extern "C" { #endif #define VC_LEVEL_DEFAULT_TARGET_DBFS (-18.0f) #define VC_LEVEL_DEFAULT_MAX_GAIN_DB 12.0f #define...` |
| `vc_level_config_defaults` | function | `voicecloak/src/vc_level.h:40` | `void vc_level_config_defaults(vc_level_config_t *config);` |
| `vc_level_config_t` | struct | `voicecloak/src/vc_level.h:26` | `` |
| `vc_level_create` | function | `voicecloak/src/vc_level.h:46` | `vc_level_t *vc_level_create(uint32_t sample_rate, const vc_level_config_t *config);` |
| `vc_level_current_gain_db` | function | `voicecloak/src/vc_level.h:61` | `float vc_level_current_gain_db(const vc_level_t *level);` |
| `vc_level_destroy` | function | `voicecloak/src/vc_level.h:50` | `void vc_level_destroy(vc_level_t *level);` |
| `vc_level_process` | function | `voicecloak/src/vc_level.h:58` | `int vc_level_process(vc_level_t *level, float *samples, size_t count);` |
| `vc_level_t` | type_alias | `voicecloak/src/vc_level.h:36` | `typedef struct vc_level_s vc_level_t;` |
| `NO_EFFECT` | macro | `voicecloak/src/vc_presets.c:16` | `#define NO_EFFECT` |
| `vc_preset_definition_t` | struct | `voicecloak/src/vc_presets.c:5` | `` |
| `vc_preset_lookup` | function | `voicecloak/src/vc_presets.c:115` | `int vc_preset_lookup(const char *name, vc_preset_t *out)` |
| `VC_PRESETS_H` | macro | `voicecloak/src/vc_presets.h:2` | `#define VC_PRESETS_H` |
| `name` | variable | `voicecloak/src/vc_presets.h:9` | `extern "C" { #endif /** * @brief Resolved preset: spectral transform, sample-domain effect, * equalizer, and the...` |
| `vc_preset_lookup` | function | `voicecloak/src/vc_presets.h:28` | `int vc_preset_lookup(const char *name, vc_preset_t *out);` |
| `vc_preset_t` | struct | `voicecloak/src/vc_presets.h:16` | `` |
| `M_PI` | macro | `voicecloak/src/vc_rt.c:7` | `#define M_PI` |
| `target` | function | `voicecloak/src/vc_rt.c:139` | `* peak region are recorded per target (tgt_src/tgt_pk) so the final  * stage can identity-lock no...` |
| `vc_rt_create` | function | `voicecloak/src/vc_rt.c:31` | `vc_rt_ctx_t *vc_rt_create(size_t nbins, vc_rt_params_t params)` |
| `vc_rt_ctx_s` | struct | `voicecloak/src/vc_rt.c:10` | `` |
| `vc_rt_destroy` | function | `voicecloak/src/vc_rt.c:70` | `void vc_rt_destroy(vc_rt_ctx_t *c)` |
| `vc_rt_reset` | function | `voicecloak/src/vc_rt.c:88` | `void vc_rt_reset(vc_rt_ctx_t *c)` |
| `vc_rt_semitones_to_ratio` | function | `voicecloak/src/vc_rt.c:95` | `float vc_rt_semitones_to_ratio(float semitones)` |
| `vc_rt_transform` | function | `voicecloak/src/vc_rt.c:214` | `void vc_rt_transform(float *mag, float *phase, size_t nbins,                      uint32_t sample...` |
| `wrap_pi` | function | `voicecloak/src/vc_rt.c:99` | `static double wrap_pi(double x)` |
| `VC_RT_H` | macro | `voicecloak/src/vc_rt.h:2` | `#define VC_RT_H` |
| `VC_RT_MAX_FORMANT_FACTOR` | macro | `voicecloak/src/vc_rt.h:12` | `#define VC_RT_MAX_FORMANT_FACTOR` |
| `VC_RT_MAX_PITCH_RATIO` | macro | `voicecloak/src/vc_rt.h:10` | `#define VC_RT_MAX_PITCH_RATIO` |
| `VC_RT_MAX_SCRAMBLE_INTENSITY` | macro | `voicecloak/src/vc_rt.h:13` | `#define VC_RT_MAX_SCRAMBLE_INTENSITY` |
| `VC_RT_MAX_SEMITONES` | macro | `voicecloak/src/vc_rt.h:8` | `#define VC_RT_MAX_SEMITONES` |
| `VC_RT_MIN_FORMANT_FACTOR` | macro | `voicecloak/src/vc_rt.h:11` | `#define VC_RT_MIN_FORMANT_FACTOR` |
| `VC_RT_MIN_PITCH_RATIO` | macro | `voicecloak/src/vc_rt.h:9` | `#define VC_RT_MIN_PITCH_RATIO` |
| `VC_RT_MIN_SEMITONES` | macro | `voicecloak/src/vc_rt.h:7` | `#define VC_RT_MIN_SEMITONES` |
| `shift` | variable | `voicecloak/src/vc_rt.h:16` | `extern "C" { #endif /** * @brief Real-time cloak parameters (already resolved to scalars). * * pitch_ratio 1.0 = no...` |
| `vc_rt_create` | function | `voicecloak/src/vc_rt.h:43` | `vc_rt_ctx_t *vc_rt_create(size_t nbins, vc_rt_params_t params);` |
| `vc_rt_ctx_t` | type_alias | `voicecloak/src/vc_rt.h:37` | `typedef struct vc_rt_ctx_s vc_rt_ctx_t;` |
| `vc_rt_derive` | function | `voicecloak/src/vc_rt.h:78` | `int vc_rt_derive(const unsigned char *pitch_seed, const unsigned char *formant_seed, const unsigned char...` |
| `vc_rt_destroy` | function | `voicecloak/src/vc_rt.h:46` | `void vc_rt_destroy(vc_rt_ctx_t *c);` |
| `vc_rt_params_t` | struct | `voicecloak/src/vc_rt.h:27` | `` |
| `vc_rt_reset` | function | `voicecloak/src/vc_rt.h:49` | `void vc_rt_reset(vc_rt_ctx_t *c);` |
| `vc_rt_semitones_to_ratio` | function | `voicecloak/src/vc_rt.h:67` | `float vc_rt_semitones_to_ratio(float semitones);` |
| `vc_rt_transform` | function | `voicecloak/src/vc_rt.h:61` | `void vc_rt_transform(float *mag, float *phase, size_t nbins, uint32_t sample_rate, size_t hop, void *user);` |
| `M_PI` | macro | `voicecloak/src/vc_rt_cli.c:19` | `#define M_PI` |
| `_POSIX_C_SOURCE` | macro | `voicecloak/src/vc_rt_cli.c:1` | `#define _POSIX_C_SOURCE` |
| `cmd_live` | function | `voicecloak/src/vc_rt_cli.c:179` | `static int cmd_live(int argc, char *argv[])` |
| `cmd_selftest` | function | `voicecloak/src/vc_rt_cli.c:117` | `static int cmd_selftest(void)` |
| `dominant_freq` | function | `voicecloak/src/vc_rt_cli.c:94` | `static float dominant_freq(const float *x, size_t n, unsigned int sr)` |
| `main` | function | `voicecloak/src/vc_rt_cli.c:504` | `int main(int argc, char *argv[])` |
| `on_sigint` | function | `voicecloak/src/vc_rt_cli.c:24` | `static void on_sigint(int sig)` |
| `parse_float` | function | `voicecloak/src/vc_rt_cli.c:29` | `static int parse_float(const char *text, float *out)` |
| `print_usage` | function | `voicecloak/src/vc_rt_cli.c:40` | `static void print_usage(const char *prog)` |
| `resolve_params` | function | `voicecloak/src/vc_rt_cli.c:155` | `static int resolve_params(int have_fixed, float semis, float formant,                           f...` |
| `vc_rt_derive` | function | `voicecloak/src/vc_rt_seed.c:5` | `int vc_rt_derive(const unsigned char *pitch_seed,                  const unsigned char *formant_s...` |
| `M_PI` | macro | `voicecloak/src/vc_stft.c:8` | `#define M_PI` |
| `vc_stft_create` | function | `voicecloak/src/vc_stft.c:21` | `vc_stft_t *vc_stft_create(size_t fft_size, size_t hop_size)` |
| `vc_stft_destroy` | function | `voicecloak/src/vc_stft.c:58` | `void vc_stft_destroy(vc_stft_t *st)` |
| `vc_stft_forward` | function | `voicecloak/src/vc_stft.c:71` | `int vc_stft_forward(vc_stft_t *st,                     const float *samples, size_t num_samples, ...` |
| `vc_stft_inverse` | function | `voicecloak/src/vc_stft.c:119` | `int vc_stft_inverse(vc_stft_t *st,                     const float *mag, const float *phase,     ...` |
| `vc_stft_inverse_hop` | function | `voicecloak/src/vc_stft.c:127` | `int vc_stft_inverse_hop(vc_stft_t *st,                         const float *mag, const float *pha...` |
| `vc_stft_num_bins` | function | `voicecloak/src/vc_stft.c:67` | `size_t vc_stft_num_bins(const vc_stft_t *st)` |
| `vc_stft_s` | struct | `voicecloak/src/vc_stft.c:11` | `` |
| `VC_STFT_H` | macro | `voicecloak/src/vc_stft.h:2` | `#define VC_STFT_H` |
| `vc_stft_create` | function | `voicecloak/src/vc_stft.h:25` | `vc_stft_t *vc_stft_create(size_t fft_size, size_t hop_size);` |
| `vc_stft_destroy` | function | `voicecloak/src/vc_stft.h:30` | `void vc_stft_destroy(vc_stft_t *st);` |
| `vc_stft_forward` | function | `voicecloak/src/vc_stft.h:42` | `int vc_stft_forward(vc_stft_t *st, const float *samples, size_t num_samples, float **mag, float **phase, size_t...` |
| `vc_stft_inverse` | function | `voicecloak/src/vc_stft.h:57` | `int vc_stft_inverse(vc_stft_t *st, const float *mag, const float *phase, size_t num_frames, float *samples_out...` |
| `vc_stft_inverse_hop` | function | `voicecloak/src/vc_stft.h:66` | `int vc_stft_inverse_hop(vc_stft_t *st, const float *mag, const float *phase, size_t num_frames, float *samples_out...` |
| `vc_stft_num_bins` | function | `voicecloak/src/vc_stft.h:75` | `size_t vc_stft_num_bins(const vc_stft_t *st);` |
| `vc_stft_t` | variable | `voicecloak/src/vc_stft.h:8` | `extern "C" { #endif /** * @brief Short-Time Fourier Transform context. * * Allocated via vc_stft_create(). Window...` |
| `vc_stft_t` | type_alias | `voicecloak/src/vc_stft.h:17` | `typedef struct vc_stft_s vc_stft_t;` |
| `M_PI` | macro | `voicecloak/src/vc_stream.c:8` | `#define M_PI` |
| `is_pow2` | function | `voicecloak/src/vc_stream.c:31` | `static int is_pow2(size_t v)` |
| `process_frame` | function | `voicecloak/src/vc_stream.c:111` | `static void process_frame(vc_stream_t *st, vc_spectral_fn fn, void *user)` |
| `vc_spectral_chain_add` | function | `voicecloak/src/vc_stream.c:182` | `int vc_spectral_chain_add(vc_spectral_chain_t *chain, vc_spectral_fn fn,                         ...` |
| `vc_spectral_chain_init` | function | `voicecloak/src/vc_stream.c:178` | `void vc_spectral_chain_init(vc_spectral_chain_t *chain)` |
| `vc_spectral_chain_run` | function | `voicecloak/src/vc_stream.c:191` | `void vc_spectral_chain_run(float *mag, float *phase, size_t nbins,                            uin...` |
| `vc_stream_create` | function | `voicecloak/src/vc_stream.c:35` | `vc_stream_t *vc_stream_create(size_t fft_size, size_t hop_size,                               uin...` |
| `vc_stream_destroy` | function | `voicecloak/src/vc_stream.c:94` | `void vc_stream_destroy(vc_stream_t *st)` |
| `vc_stream_latency_samples` | function | `voicecloak/src/vc_stream.c:107` | `size_t vc_stream_latency_samples(const vc_stream_t *st)` |
| `vc_stream_process` | function | `voicecloak/src/vc_stream.c:159` | `int vc_stream_process(vc_stream_t *st,                       const float *in, float *out, size_t ...` |
| `vc_stream_s` | struct | `voicecloak/src/vc_stream.c:11` | `` |
| `VC_SPECTRAL_CHAIN_MAX` | macro | `voicecloak/src/vc_stream.h:39` | `#define VC_SPECTRAL_CHAIN_MAX` |
| `VC_STREAM_H` | macro | `voicecloak/src/vc_stream.h:2` | `#define VC_STREAM_H` |
| `frames` | function | `voicecloak/src/vc_stream.h:32` | `* that must persist across frames (phase-vocoder accumulators) lives * in @p user, not in the engine. */ typedef...` |
| `hop` | variable | `voicecloak/src/vc_stream.h:8` | `extern "C" { #endif /** * @brief Streaming STFT overlap-add engine for real-time processing. * * Unlike the offline...` |
| `vc_spectral_chain_add` | function | `voicecloak/src/vc_stream.h:60` | `int vc_spectral_chain_add(vc_spectral_chain_t *chain, vc_spectral_fn fn, void *user);` |
| `vc_spectral_chain_init` | function | `voicecloak/src/vc_stream.h:54` | `void vc_spectral_chain_init(vc_spectral_chain_t *chain);` |
| `vc_spectral_chain_run` | function | `voicecloak/src/vc_stream.h:67` | `void vc_spectral_chain_run(float *mag, float *phase, size_t nbins, uint32_t sample_rate, size_t hop, void *user);` |
| `vc_spectral_chain_t` | struct | `voicecloak/src/vc_stream.h:47` | `` |
| `vc_stream_create` | function | `voicecloak/src/vc_stream.h:77` | `vc_stream_t *vc_stream_create(size_t fft_size, size_t hop_size, uint32_t sample_rate);` |
| `vc_stream_destroy` | function | `voicecloak/src/vc_stream.h:81` | `void vc_stream_destroy(vc_stream_t *st);` |
| `vc_stream_latency_samples` | function | `voicecloak/src/vc_stream.h:84` | `size_t vc_stream_latency_samples(const vc_stream_t *st);` |
| `vc_stream_process` | function | `voicecloak/src/vc_stream.h:96` | `int vc_stream_process(vc_stream_t *st, const float *in, float *out, size_t n, vc_spectral_fn fn, void *user);` |
| `vc_stream_t` | type_alias | `voicecloak/src/vc_stream.h:20` | `typedef struct vc_stream_s vc_stream_t;` |
| `WavDataChunk` | struct | `voicecloak/src/vc_wav.c:24` | `` |
| `WavFmtBody` | struct | `voicecloak/src/vc_wav.c:15` | `` |
| `WavHeader` | struct | `voicecloak/src/vc_wav.c:9` | `` |
| `find_chunk` | function | `voicecloak/src/vc_wav.c:78` | `static int find_chunk(FILE *fp, const char *id, uint32_t *size)` |
| `float_to_sample` | function | `voicecloak/src/vc_wav.c:62` | `static void float_to_sample(float f, unsigned char *p, int bps)` |
| `read_bytes` | function | `voicecloak/src/vc_wav.c:30` | `static int read_bytes(FILE *fp, void *buf, size_t n)` |
| `sample_to_float` | function | `voicecloak/src/vc_wav.c:38` | `static float sample_to_float(const unsigned char *p, int bps)` |
| `vc_wav_read` | function | `voicecloak/src/vc_wav.c:93` | `int vc_wav_read(const char *path,                 float **samples_out, size_t *num_samples_out,  ...` |
| `vc_wav_write` | function | `voicecloak/src/vc_wav.c:169` | `int vc_wav_write(const char *path,                  const float *samples, size_t num_samples,    ...` |
| `write_bytes` | function | `voicecloak/src/vc_wav.c:34` | `static int write_bytes(FILE *fp, const void *buf, size_t n)` |
| `VC_WAV_H` | macro | `voicecloak/src/vc_wav.h:2` | `#define VC_WAV_H` |
| `vc_wav_read` | function | `voicecloak/src/vc_wav.h:19` | `int vc_wav_read(const char *path, float **samples_out, size_t *num_samples_out, uint32_t *sample_rate_out);` |
| `vc_wav_write` | function | `voicecloak/src/vc_wav.h:31` | `int vc_wav_write(const char *path, const float *samples, size_t num_samples, uint32_t sample_rate);` |
| `FFT` | macro | `voicecloak/tests/test_vc_denoise.c:20` | `#define FFT` |
| `HOP` | macro | `voicecloak/tests/test_vc_denoise.c:21` | `#define HOP` |
| `NBINS` | macro | `voicecloak/tests/test_vc_denoise.c:22` | `#define NBINS` |
| `SR` | macro | `voicecloak/tests/test_vc_denoise.c:19` | `#define SR` |
| `TEST_PI` | macro | `voicecloak/tests/test_vc_denoise.c:23` | `#define TEST_PI` |
| `_POSIX_C_SOURCE` | macro | `voicecloak/tests/test_vc_denoise.c:1` | `#define _POSIX_C_SOURCE` |
| `harmonic` | function | `voicecloak/tests/test_vc_denoise.c:39` | `static float harmonic(size_t i)` |
| `learn_then_process` | function | `voicecloak/tests/test_vc_denoise.c:59` | `static void learn_then_process(vc_denoise_t *dn, const float *in, float *out,                    ...` |
| `main` | function | `voicecloak/tests/test_vc_denoise.c:347` | `int main(void)` |
| `make_denoise` | function | `voicecloak/tests/test_vc_denoise.c:78` | `static vc_denoise_t *make_denoise(float learn_ms)` |
| `rms` | function | `voicecloak/tests/test_vc_denoise.c:32` | `static float rms(const float *x, size_t n)` |
| `robot_noise_rms` | function | `voicecloak/tests/test_vc_denoise.c:176` | `static float robot_noise_rms(int with_denoise)` |
| `run_chunks` | function | `voicecloak/tests/test_vc_denoise.c:48` | `static void run_chunks(vc_stream_t *st, const float *in, float *out, size_t n,                   ...` |
| `test_defaults_and_invalid_params` | function | `voicecloak/tests/test_vc_denoise.c:87` | `static void test_defaults_and_invalid_params(void **state)` |
| `test_learning_mutes_then_ready` | function | `voicecloak/tests/test_vc_denoise.c:112` | `static void test_learning_mutes_then_ready(void **state)` |
| `test_malformed_profiles_rejected` | function | `voicecloak/tests/test_vc_denoise.c:279` | `static void test_malformed_profiles_rejected(void **state)` |
| `test_non_finite_frame_muted` | function | `voicecloak/tests/test_vc_denoise.c:329` | `static void test_non_finite_frame_muted(void **state)` |
| `test_profile_round_trip` | function | `voicecloak/tests/test_vc_denoise.c:214` | `static void test_profile_round_trip(void **state)` |
| `test_rate_mismatch_relearns` | function | `voicecloak/tests/test_vc_denoise.c:313` | `static void test_rate_mismatch_relearns(void **state)` |
| `test_robot_hum_on_silence_suppressed` | function | `voicecloak/tests/test_vc_denoise.c:206` | `static void test_robot_hum_on_silence_suppressed(void **state)` |
| `test_speech_like_content_survives` | function | `voicecloak/tests/test_vc_denoise.c:149` | `static void test_speech_like_content_survives(void **state)` |
| `test_stationary_noise_removed` | function | `voicecloak/tests/test_vc_denoise.c:128` | `static void test_stationary_noise_removed(void **state)` |
| `white` | function | `voicecloak/tests/test_vc_denoise.c:27` | `static float white(float amplitude)` |
| `PI_F` | macro | `voicecloak/tests/test_vc_effects.c:12` | `#define PI_F` |
| `TEST_RATE` | macro | `voicecloak/tests/test_vc_effects.c:11` | `#define TEST_RATE` |
| `assert_finite` | function | `voicecloak/tests/test_vc_effects.c:22` | `static void assert_finite(const float *samples, size_t count)` |
| `main` | function | `voicecloak/tests/test_vc_effects.c:257` | `int main(void)` |
| `rms` | function | `voicecloak/tests/test_vc_effects.c:14` | `static float rms(const float *samples, size_t count)` |
| `test_invalid_rate_and_parameters_rejected` | function | `voicecloak/tests/test_vc_effects.c:245` | `static void test_invalid_rate_and_parameters_rejected(void **state)` |
| `test_metallic_bounds_rejected` | function | `voicecloak/tests/test_vc_effects.c:120` | `static void test_metallic_bounds_rejected(void **state)` |
| `test_metallic_comb_echoes_with_feedback_ratio` | function | `voicecloak/tests/test_vc_effects.c:99` | `static void test_metallic_comb_echoes_with_feedback_ratio(void **state)` |
| `test_phaser_bounded_and_non_identity` | function | `voicecloak/tests/test_vc_effects.c:223` | `static void test_phaser_bounded_and_non_identity(void **state)` |
| `test_reverb_has_tail` | function | `voicecloak/tests/test_vc_effects.c:175` | `static void test_reverb_has_tail(void **state)` |
| `test_ring_amount_zero_is_identity` | function | `voicecloak/tests/test_vc_effects.c:48` | `static void test_ring_amount_zero_is_identity(void **state)` |
| `test_ring_modulation_changes_tone` | function | `voicecloak/tests/test_vc_effects.c:27` | `static void test_ring_modulation_changes_tone(void **state)` |
| `test_space_delay_adds_echo_without_unbounded_feedback` | function | `voicecloak/tests/test_vc_effects.c:198` | `static void test_space_delay_adds_echo_without_unbounded_feedback(void **state)` |
| `test_square_carrier_is_soft_and_bounded` | function | `voicecloak/tests/test_vc_effects.c:70` | `static void test_square_carrier_is_soft_and_bounded(void **state)` |
| `test_underwater_lowpass_reduces_high_tone` | function | `voicecloak/tests/test_vc_effects.c:149` | `static void test_underwater_lowpass_reduces_high_tone(void **state)` |
| `PI_F` | macro | `voicecloak/tests/test_vc_eq.c:13` | `#define PI_F` |
| `TEST_RATE` | macro | `voicecloak/tests/test_vc_eq.c:12` | `#define TEST_RATE` |
| `main` | function | `voicecloak/tests/test_vc_eq.c:115` | `int main(void)` |
| `test_bad_samples_fail_closed` | function | `voicecloak/tests/test_vc_eq.c:98` | `static void test_bad_samples_fail_closed(void **state)` |
| `test_highpass_removes_rumble` | function | `voicecloak/tests/test_vc_eq.c:44` | `static void test_highpass_removes_rumble(void **state)` |
| `test_invalid_params_rejected` | function | `voicecloak/tests/test_vc_eq.c:75` | `static void test_invalid_params_rejected(void **state)` |
| `test_presence_peak_boosts_consonant_band` | function | `voicecloak/tests/test_vc_eq.c:49` | `static void test_presence_peak_boosts_consonant_band(void **state)` |
| `test_zero_params_bypass` | function | `voicecloak/tests/test_vc_eq.c:57` | `static void test_zero_params_bypass(void **state)` |
| `tone_gain_db` | function | `voicecloak/tests/test_vc_eq.c:22` | `static float tone_gain_db(const vc_eq_params_t *params, float frequency)` |
| `main` | function | `voicecloak/tests/test_vc_fft.c:76` | `int main(void)` |
| `test_fft_dc_signal` | function | `voicecloak/tests/test_vc_fft.c:27` | `static void test_fft_dc_signal(void **state)` |
| `test_fft_identity` | function | `voicecloak/tests/test_vc_fft.c:10` | `static void test_fft_identity(void **state)` |
| `test_fft_sine` | function | `voicecloak/tests/test_vc_fft.c:47` | `static void test_fft_sine(void **state)` |
| `PI_F` | macro | `voicecloak/tests/test_vc_level.c:13` | `#define PI_F` |
| `TEST_RATE` | macro | `voicecloak/tests/test_vc_level.c:12` | `#define TEST_RATE` |
| `main` | function | `voicecloak/tests/test_vc_level.c:228` | `int main(void)` |
| `rms` | function | `voicecloak/tests/test_vc_level.c:15` | `static float rms(const float *samples, size_t count)` |
| `run_constant_level` | function | `voicecloak/tests/test_vc_level.c:148` | `static void run_constant_level(float drive, float input, float *output)` |
| `test_default_config_and_rms_target` | function | `voicecloak/tests/test_vc_level.c:23` | `static void test_default_config_and_rms_target(void **state)` |
| `test_gain_changes_smoothly_between_periods` | function | `voicecloak/tests/test_vc_level.c:74` | `static void test_gain_changes_smoothly_between_periods(void **state)` |
| `test_invalid_rate_and_excessive_input_fail_closed` | function | `voicecloak/tests/test_vc_level.c:132` | `static void test_invalid_rate_and_excessive_input_fail_closed(void **state)` |
| `test_invalid_saturation_drive_rejected` | function | `voicecloak/tests/test_vc_level.c:212` | `static void test_invalid_saturation_drive_rejected(void **state)` |
| `test_limiter_ceiling_and_agc_off` | function | `voicecloak/tests/test_vc_level.c:53` | `static void test_limiter_ceiling_and_agc_off(void **state)` |
| `test_non_finite_block_fails_closed` | function | `voicecloak/tests/test_vc_level.c:119` | `static void test_non_finite_block_fails_closed(void **state)` |
| `test_saturation_curve_and_bypass` | function | `voicecloak/tests/test_vc_level.c:160` | `static void test_saturation_curve_and_bypass(void **state)` |
| `test_saturation_raises_loudness_within_ceiling` | function | `voicecloak/tests/test_vc_level.c:175` | `static void test_saturation_raises_loudness_within_ceiling(void **state)` |
| `test_silence_stays_silent` | function | `voicecloak/tests/test_vc_level.c:104` | `static void test_silence_stays_silent(void **state)` |
| `TEST_PI` | macro | `voicecloak/tests/test_vc_presets.c:16` | `#define TEST_PI` |
| `TEST_RATE` | macro | `voicecloak/tests/test_vc_presets.c:15` | `#define TEST_RATE` |
| `main` | function | `voicecloak/tests/test_vc_presets.c:311` | `int main(void)` |
| `rms` | function | `voicecloak/tests/test_vc_presets.c:18` | `static float rms(const float *samples, size_t count)` |
| `test_all_named_presets_resolve` | function | `voicecloak/tests/test_vc_presets.c:26` | `static void test_all_named_presets_resolve(void **state)` |
| `test_full_live_chain_tracks_rms_and_ceiling` | function | `voicecloak/tests/test_vc_presets.c:150` | `static void test_full_live_chain_tracks_rms_and_ceiling(void **state)` |
| `test_lookup_rejects_unknown_and_invalid_output` | function | `voicecloak/tests/test_vc_presets.c:93` | `static void test_lookup_rejects_unknown_and_invalid_output(void **state)` |
| `test_preset_pipeline_on_deterministic_noise` | function | `voicecloak/tests/test_vc_presets.c:100` | `static void test_preset_pipeline_on_deterministic_noise(void **state)` |
| `test_robot_live_chain_is_loud_and_bounded` | function | `voicecloak/tests/test_vc_presets.c:250` | `static void test_robot_live_chain_is_loud_and_bounded(void **state)` |
| `test_robot_preset_is_clear_robotization` | function | `voicecloak/tests/test_vc_presets.c:58` | `static void test_robot_preset_is_clear_robotization(void **state)` |
| `test_voice_profiles_are_distinct` | function | `voicecloak/tests/test_vc_presets.c:81` | `static void test_voice_profiles_are_distinct(void **state)` |
| `test_witness_loss_is_compensated_in_live_chain` | function | `voicecloak/tests/test_vc_presets.c:196` | `static void test_witness_loss_is_compensated_in_live_chain(void **state)` |
| `M_PI` | macro | `voicecloak/tests/test_vc_stream.c:15` | `#define M_PI` |
| `SR` | macro | `voicecloak/tests/test_vc_stream.c:18` | `#define SR` |
| `add_one` | function | `voicecloak/tests/test_vc_stream.c:200` | `static void add_one(float *mag, float *phase, size_t nbins,                     uint32_t sample_r...` |
| `dominant_freq` | function | `voicecloak/tests/test_vc_stream.c:32` | `static float dominant_freq(const float *x, size_t n, uint32_t sr)` |
| `gen_sines` | function | `voicecloak/tests/test_vc_stream.c:20` | `static void gen_sines(float *buf, size_t n, uint32_t sr,                       const float *freqs...` |
| `main` | function | `voicecloak/tests/test_vc_stream.c:382` | `int main(void)` |
| `normalized_autocorrelation` | function | `voicecloak/tests/test_vc_stream.c:148` | `static float normalized_autocorrelation(const float *x, size_t n,                                ...` |
| `rms` | function | `voicecloak/tests/test_vc_stream.c:54` | `static float rms(const float *x, size_t n)` |
| `run_level` | function | `voicecloak/tests/test_vc_stream.c:303` | `static void run_level(float semis, float formant, float scramble,                       float max...` |
| `run_pitch` | function | `voicecloak/tests/test_vc_stream.c:240` | `static void run_pitch(float in_freq, float ratio, float expect_freq)` |
| `run_stream` | function | `voicecloak/tests/test_vc_stream.c:63` | `static void run_stream(vc_stream_t *st, const float *in, float *out, size_t n,                   ...` |
| `scale_by_two` | function | `voicecloak/tests/test_vc_stream.c:191` | `static void scale_by_two(float *mag, float *phase, size_t nbins,                          uint32_...` |
| `test_bounded_output` | function | `voicecloak/tests/test_vc_stream.c:274` | `static void test_bounded_output(void **state)` |
| `test_create_validation` | function | `voicecloak/tests/test_vc_stream.c:74` | `static void test_create_validation(void **state)` |
| `test_level_preserved_fixed` | function | `voicecloak/tests/test_vc_stream.c:336` | `static void test_level_preserved_fixed(void **state)` |
| `test_level_preserved_witness` | function | `voicecloak/tests/test_vc_stream.c:341` | `static void test_level_preserved_witness(void **state)` |
| `test_passthrough_identity` | function | `voicecloak/tests/test_vc_stream.c:112` | `static void test_passthrough_identity(void **state)` |
| `test_pitch_down_octave` | function | `voicecloak/tests/test_vc_stream.c:269` | `static void test_pitch_down_octave(void **state)` |
| `test_pitch_up_octave` | function | `voicecloak/tests/test_vc_stream.c:264` | `static void test_pitch_up_octave(void **state)` |
| `test_robotize_locks_pitch_to_frame_rate` | function | `voicecloak/tests/test_vc_stream.c:161` | `static void test_robotize_locks_pitch_to_frame_rate(void **state)` |
| `test_spectral_chain_rejects_null_and_overflow` | function | `voicecloak/tests/test_vc_stream.c:224` | `static void test_spectral_chain_rejects_null_and_overflow(void **state)` |
| `test_spectral_chain_runs_in_order` | function | `voicecloak/tests/test_vc_stream.c:209` | `static void test_spectral_chain_runs_in_order(void **state)` |
| `test_transform_parameter_validation` | function | `voicecloak/tests/test_vc_stream.c:86` | `static void test_transform_parameter_validation(void **state)` |

