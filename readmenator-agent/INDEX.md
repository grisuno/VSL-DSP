# Index

| File | Purpose | Subsystem | Symbols | Used by |
|------|---------|-----------|---------|---------|
| `audiobox_vsl.c` | - | root | 5 | 0 |
| `audiobox_vsl.h` | audiobox_model_info_t: @brief Pair of product ID and canonical human readable model name. | root | 9 | 3 |
| `avatar/avatar_config.h` | - | avatar | 14 | 1 |
| `avatar/avatar_logic.c` | - | avatar | 8 | 0 |
| `avatar/avatar_logic.h` | avatar_cfg_t: @brief Tunable classifier thresholds. | avatar | 12 | 2 |
| `avatar/avatar_main.c` | to_mono_f32: if (snd_pcm_hw_params(pcm, hw) < 0) { fprintf(stderr, "avatar: '%s' cannot apply hw... | avatar | 7 | 0 |
| `install.sh` | - | root | 0 | 0 |
| `legacy/app.py` | Autor: Gris Iscomeback Correo electrónico: grisiscomeback[at]gmail[dot]com Fecha de creación... | legacy | 0 | 0 |
| `legacy/build-dkms.sh` | AudioBox 22 VSL Enhanced Driver - Installation Script Copyright (c) 2025 grisuno (LazyOwn... | legacy | 19 | 0 |
| `legacy/main.c` | - | legacy | 1 | 0 |
| `legacy/mixer_quirks.c` | rc_config: Sound Blaster remote control configuration  format of remote control data: Extigy... | legacy | 309 | 0 |
| `legacy/test.sh` | - | legacy | 0 | 0 |
| `legacy/test_connection.c` | - | legacy | 1 | 0 |
| `legacy/vsl_config.h` | - | legacy | 8 | 7 |
| `legacy/vsl_config.py` | VSL-DSP Configuration Module Contiene todas las constantes y configuraciones del protocolo.  ⚠️... | legacy | 3 | 0 |
| `legacy/vsl_core.py` | VSL-DSP Core Logic Module Implementa las funciones matemáticas de encoding/decoding. | legacy | 5 | 2 |
| `legacy/vsl_dsp_logic.c` | Declaración de la nueva función de envío | legacy | 5 | 0 |
| `legacy/vsl_dsp_logic.h` | Constante para la conversión de logaritmo natural (ln) a logaritmo base 2 (log2) 1 / ln(2) ≈... | legacy | 7 | 2 |
| `legacy/vsl_dsp_transport.c` | FUN_Send_Packet: @brief Función de I/O real usando HIDAPI. @note DEBE SER REEMPLAZADA con la... | legacy | 5 | 0 |
| `legacy/vsl_dsp_transport.h` | VSL_DSP_Packet: Estructura de Paquete: Sin 'header' (lo quitaste en la estructura typedef) | legacy | 7 | 3 |
| `legacy/vsl_hid_io.py` | VSL-DSP HID I/O Module (OPCIONAL) Comunicación real con hardware via hidapi. | legacy | 9 | 0 |
| `legacy/vsl_poc_main.py` | VSL-DSP Proof of Concept - Main Program Programa principal de pruebas y validación. | legacy | 7 | 0 |
| `legacy/vsl_protocol_analyzer.py` | PASO 1: (Fuera de este entorno) Capturar tráfico USB con Wireshark/usbmon Guardar como... | legacy | 7 | 0 |
| `legacy/vsl_transport.py` | VSL-DSP Transport Module Construcción y validación de paquetes HID. | legacy | 8 | 2 |
| `src/vsl_cli.c` | - | src | 10 | 0 |
| `src/vsl_config.h` | pid: ifdef __cplusplus | src | 14 | 2 |
| `src/vsl_dsp_logic.c` | - | src | 7 | 0 |
| `src/vsl_dsp_logic.h` | VSL_Encode_Gain: @brief Encodes a linear gain value [0.0, 1.0] to the DSP exponential curve.... | src | 13 | 3 |
| `src/vsl_dsp_transport.c` | - | src | 5 | 0 |
| `src/vsl_dsp_transport.h` | VSL_Close_Device: @brief Release the MIDI interface and close the device. @param handle Handle... | src | 7 | 2 |
| `tests/bdd_driver_gate.sh` | BDD hardware gate for audiobox_vsl. | tests | 2 | 0 |
| `tests/test_audiobox_vsl.c` | - | tests | 12 | 0 |
| `voicecloak/src/vc_alsa.c` | - | - | 8 | 0 |
| `voicecloak/src/vc_alsa.h` | vc_alsa_cfg_t: @brief Configuration for a real-time ALSA processing session. | - | 5 | 2 |
| `voicecloak/src/vc_audio_config.h` | @brief Accepted sample-rate interval for live effect engines. | - | 13 | 4 |
| `voicecloak/src/vc_cli.c` | - | - | 5 | 0 |
| `voicecloak/src/vc_crypto.c` | vc_prng_s: int i; for (i = 0; i < 3; ++i) { unsigned int outlen = 32; unsigned char data[64]... | - | 10 | 0 |
| `voicecloak/src/vc_crypto.h` | vc_crypto_keygen: @brief Generate an RSA-4096 keypair and write to PEM files. @param pubkey_path... | - | 16 | 5 |
| `voicecloak/src/vc_denoise.c` | reset_tracking: Restart the per-bin gains and close the gate: right after a profile * appears... | - | 20 | 0 |
| `voicecloak/src/vc_denoise.h` | vc_denoise_params_t: @brief Noise reduction settings.  reduction: over-subtraction factor... | - | 29 | 3 |
| `voicecloak/src/vc_dsp.c` | - | - | 11 | 0 |
| `voicecloak/src/vc_dsp.h` | VcMode: ifdef __cplusplus | - | 6 | 2 |
| `voicecloak/src/vc_effects.c` | ring_modulate: Soft square: a hard edge multiplies the voice by infinitely many harmonics that... | - | 27 | 0 |
| `voicecloak/src/vc_effects.h` | vc_effects_params_t: @brief Effect selection and values (supplied by the preset table). | - | 9 | 4 |
| `voicecloak/src/vc_eq.c` | - | - | 13 | 0 |
| `voicecloak/src/vc_eq.h` | vc_eq_params_t: @brief Voice equalizer settings (supplied by the preset table).  highpass_hz 0... | - | 10 | 5 |
| `voicecloak/src/vc_fft.c` | - | - | 4 | 0 |
| `voicecloak/src/vc_fft.h` | - | - | 2 | 6 |
| `voicecloak/src/vc_level.c` | - | - | 9 | 0 |
| `voicecloak/src/vc_level.h` | vc_level_config_t: @brief Level-stage configuration.  saturation_drive 0 bypasses the soft... | - | 16 | 4 |
| `voicecloak/src/vc_presets.c` | - | - | 3 | 0 |
| `voicecloak/src/vc_presets.h` | vc_preset_t: @brief Resolved preset: spectral transform, sample-domain effect, equalizer, and... | - | 4 | 3 |
| `voicecloak/src/vc_rt.c` | - | - | 9 | 0 |
| `voicecloak/src/vc_rt.h` | vc_rt_params_t: @brief Real-time cloak parameters (already resolved to scalars).  pitch_ratio... | - | 17 | 6 |
| `voicecloak/src/vc_rt_cli.c` | - | - | 10 | 0 |
| `voicecloak/src/vc_rt_seed.c` | - | - | 1 | 0 |
| `voicecloak/src/vc_stft.c` | - | - | 8 | 0 |
| `voicecloak/src/vc_stft.h` | vc_stft_create: @brief Allocate STFT context. @param fft_size  FFT size (power of 2, e.g. | - | 9 | 2 |
| `voicecloak/src/vc_stream.c` | - | - | 11 | 0 |
| `voicecloak/src/vc_stream.h` | vc_spectral_chain_t: @brief Ordered list of spectral stages run as one vc_spectral_fn. | - | 13 | 7 |
| `voicecloak/src/vc_wav.c` | WavHeader: pragma pack(push, 1) | - | 10 | 0 |
| `voicecloak/src/vc_wav.h` | vc_wav_read: @brief Read a mono PCM WAV file into a float buffer [-1.0, 1.0]. @param path... | - | 3 | 2 |
| `voicecloak/tests/test_vc_denoise.c` | learn_then_process: return (float)(0.1 * value); } static void run_chunks(vc_stream_t *st, const... | - | 23 | 0 |
| `voicecloak/tests/test_vc_effects.c` | - | - | 15 | 0 |
| `voicecloak/tests/test_vc_eq.c` | - | - | 9 | 0 |
| `voicecloak/tests/test_vc_fft.c` | - | - | 4 | 0 |
| `voicecloak/tests/test_vc_level.c` | - | - | 14 | 0 |
| `voicecloak/tests/test_vc_presets.c` | - | - | 12 | 0 |
| `voicecloak/tests/test_vc_stream.c` | run_stream: Stream a whole buffer through the engine in small, irregular chunks * to exercise... | - | 23 | 0 |
