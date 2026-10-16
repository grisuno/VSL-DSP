# GraphRAG Community Reports

Entities: 1119 | Relationships: 2012 | Communities: 8 | Themes: 6 | Text units: 962

Query with `readmenator . ask "<question>"` (local: BM25 + Personalized PageRank; global: map-reduce over these reports) or the MCP tool `readmenator.graphrag`.

## Project overview (`root`, root, rating 7.0)

69 files in 8 communities and 6 themes. Highest-impact communities: voicecloak/src: vc_effects (7.0), voicecloak/src: vc_denoise (5.0), legacy (4.4). God nodes: legacy/mixer_quirks.c, voicecloak/src/vc_stream.h, voicecloak/src/vc_rt_cli.c, legacy/vsl_config.h, voicecloak/src/vc_rt.h.

- [voicecloak/src: vc_effects] rating 7.0: `voicecloak/src/vc_audio_config.h` ranks 1 by PageRank, 4 importers, 13 symbols: @brief Accepted sample-rate interval for live effect engines.
- [voicecloak/src: vc_denoise] rating 5.0: `voicecloak/src/vc_fft.h` ranks 1 by PageRank, 6 importers, 2 symbols.
- [legacy] rating 4.4: `legacy/vsl_config.h` ranks 1 by PageRank, 10 importers, 8 symbols.
- [voicecloak/src: vc_crypto] rating 3.0: `voicecloak/src/vc_crypto.h` ranks 1 by PageRank, 5 importers, 16 symbols: vc_crypto_keygen: @brief Generate an RSA-4096 keypair and write to PEM files. @param pubkey_path   Output path for public key. @param privkey_path  Output path for private key. @return 0 on success, -1 on error.
- [src] rating 2.2: `src/vsl_dsp_logic.h` ranks 1 by PageRank, 3 importers, 13 symbols: VSL_Encode_Gain: @brief Encodes a linear gain value [0.0, 1.0] to the DSP exponential curve. @param linear_value Linear control position clamped to [0,1]. @param param Parameter coefficients from the DSP parameter database. @return...
- [unassigned files] rating 1.5: `install.sh` ranks 1 by PageRank, 0 importers, 0 symbols.
- [root] rating 1.4: `audiobox_vsl.h` ranks 1 by PageRank, 3 importers, 9 symbols: audiobox_model_info_t: @brief Pair of product ID and canonical human readable model name.
- [avatar] rating 1.2: `avatar/avatar_logic.h` ranks 1 by PageRank, 2 importers, 12 symbols: avatar_cfg_t: @brief Tunable classifier thresholds.
- Key entities: file:voicecloak/src/vc_effects.c, file:voicecloak/src/vc_level.h, file:voicecloak/src/vc_denoise.h, file:voicecloak/tests/test_vc_denoise.c, file:legacy/vsl_config.h, file:legacy/vsl_dsp_logic.h
- Children: t0, t1, t2, t3, t4, t5
- Root rating = highest community rating.

## voicecloak/src: vc_effects + voicecloak/src: vc_denoise +1 (`t0`, theme, rating 7.0)

Theme of 3 communities and 37 files: voicecloak/src: vc_effects (13 files, rating 7.0); voicecloak/src: vc_denoise (14 files, rating 5.0); voicecloak/src: vc_crypto (10 files, rating 3.0).

- [voicecloak/src: vc_effects] `voicecloak/src/vc_audio_config.h` ranks 1 by PageRank, 4 importers, 13 symbols: @brief Accepted sample-rate interval for live effect engines.
- [voicecloak/src: vc_effects] `voicecloak/src/vc_eq.h` ranks 2 by PageRank, 5 importers, 10 symbols: vc_eq_params_t: @brief Voice equalizer settings (supplied by the preset table).  highpass_hz 0 bypasses the high-pass section; presence_gain_db 0 bypasses the presence peak (presence_hz and presence_q are then ignored).
- [voicecloak/src: vc_denoise] `voicecloak/src/vc_fft.h` ranks 1 by PageRank, 6 importers, 2 symbols.
- [voicecloak/src: vc_denoise] `voicecloak/src/vc_rt.h` ranks 2 by PageRank, 6 importers, 17 symbols: vc_rt_params_t: @brief Real-time cloak parameters (already resolved to scalars).  pitch_ratio 1.0 = no shift; formant_factor 1.0 = no shift; scramble_intensity 0.0 = none; robotize 0 = off, 1 = every synthesis frame is rewritten with a...
- [voicecloak/src: vc_crypto] `voicecloak/src/vc_crypto.h` ranks 1 by PageRank, 5 importers, 16 symbols: vc_crypto_keygen: @brief Generate an RSA-4096 keypair and write to PEM files. @param pubkey_path   Output path for public key. @param privkey_path  Output path for private key. @return 0 on success, -1 on error.
- [voicecloak/src: vc_crypto] `voicecloak/src/vc_wav.h` ranks 2 by PageRank, 2 importers, 3 symbols: vc_wav_read: @brief Read a mono PCM WAV file into a float buffer [-1.0, 1.0]. @param path         File path. @param samples_out  Output: allocated float array. @param num_samples_out Output: number of samples. @param sample_rate_out...
- Key entities: file:voicecloak/src/vc_effects.c, file:voicecloak/src/vc_level.h, file:voicecloak/src/vc_denoise.h, file:voicecloak/tests/test_vc_denoise.c, file:voicecloak/src/vc_crypto.h, file:voicecloak/src/vc_crypto.c
- Children: c1, c0, c3
- Theme rating = highest child community rating.

## legacy (`t1`, theme, rating 4.4)

Theme of 1 communities and 11 files: legacy (11 files, rating 4.4).

- [legacy] `legacy/vsl_config.h` ranks 1 by PageRank, 10 importers, 8 symbols.
- [legacy] `legacy/vsl_dsp_logic.h` ranks 2 by PageRank, 2 importers, 7 symbols: Constante para la conversión de logaritmo natural (ln) a logaritmo base 2 (log2) 1 / ln(2) ≈ 1.442695  Estructura que almacena todos los coeficientes precalculados del DSP
- Key entities: file:legacy/vsl_config.h, file:legacy/vsl_dsp_logic.h
- Children: c2
- Theme rating = highest child community rating.

## src (`t3`, theme, rating 2.2)

Theme of 1 communities and 6 files: src (6 files, rating 2.2).

- [src] `src/vsl_dsp_logic.h` ranks 1 by PageRank, 3 importers, 13 symbols: VSL_Encode_Gain: @brief Encodes a linear gain value [0.0, 1.0] to the DSP exponential curve. @param linear_value Linear control position clamped to [0,1]. @param param Parameter coefficients from the DSP parameter database. @return...
- [src] `src/vsl_config.h` ranks 2 by PageRank, 2 importers, 14 symbols: pid: ifdef __cplusplus
- Key entities: file:src/vsl_dsp_logic.h, file:src/vsl_config.h
- Children: c4
- Theme rating = highest child community rating.

## unassigned files (`t2`, theme, rating 1.5)

Theme of 1 communities and 7 files: unassigned files (7 files, rating 1.5).

- [unassigned files] `install.sh` ranks 1 by PageRank, 0 importers, 0 symbols.
- [unassigned files] `legacy/app.py` ranks 2 by PageRank, 0 importers, 0 symbols: Autor: Gris Iscomeback Correo electrónico: grisiscomeback[at]gmail[dot]com Fecha de creación: xx/xx/xxxx Licencia: GPL v3  Descripción:
- Key entities: file:legacy/build-dkms.sh, file:legacy/vsl_protocol_analyzer.py
- Children: c7
- Theme rating = highest child community rating.

## root (`t4`, theme, rating 1.4)

Theme of 1 communities and 4 files: root (4 files, rating 1.4).

- [root] `audiobox_vsl.h` ranks 1 by PageRank, 3 importers, 9 symbols: audiobox_model_info_t: @brief Pair of product ID and canonical human readable model name.
- [root] `audiobox_vsl.c` ranks 2 by PageRank, 0 importers, 5 symbols.
- Key entities: file:legacy/mixer_quirks.c, file:audiobox_vsl.h
- Children: c5
- Theme rating = highest child community rating.

## avatar (`t5`, theme, rating 1.2)

Theme of 1 communities and 4 files: avatar (4 files, rating 1.2).

- [avatar] `avatar/avatar_logic.h` ranks 1 by PageRank, 2 importers, 12 symbols: avatar_cfg_t: @brief Tunable classifier thresholds.
- [avatar] `avatar/avatar_config.h` ranks 2 by PageRank, 1 importers, 14 symbols.
- Key entities: file:avatar/avatar_logic.h, file:avatar/avatar_config.h
- Children: c6
- Theme rating = highest child community rating.

## voicecloak/src: vc_effects (`c1`, community, rating 7.0)

13 files under voicecloak/src (c 8, h 5), mostly utility. Core file voicecloak/src/vc_audio_config.h (PageRank 0.0996, imported by 4 files): @brief Accepted sample-rate interval for live effect engines. Key abstractions: VC_AUDIO_CONFIG_H, VC_AUDIO_MIN_SAMPLE_RATE, VC_AUDIO_MAX_SAMPLE_RATE, VC_AUDIO_MAX_INTERNAL_SAMPLE, VC_LEVEL_MIN_TARGET_DBFS, VC_LEVEL_MAX_TARGET_DBFS. Depends on voicecloak/src: vc_denoise (2). Used by voicecloak/src: vc_denoise (5).

- `voicecloak/src/vc_audio_config.h` ranks 1 by PageRank, 4 importers, 13 symbols: @brief Accepted sample-rate interval for live effect engines.
- `voicecloak/src/vc_eq.h` ranks 2 by PageRank, 5 importers, 10 symbols: vc_eq_params_t: @brief Voice equalizer settings (supplied by the preset table).  highpass_hz 0 bypasses the high-pass section; presence_gain_db 0 bypasses the presence peak (presence_hz and presence_q are then ignored).
- `voicecloak/src/vc_effects.h` ranks 3 by PageRank, 4 importers, 9 symbols: vc_effects_params_t: @brief Effect selection and values (supplied by the preset table).
- Hotspot `voicecloak/tests/test_vc_presets.c`: 12 symbols, 15 connections (score 0.36).
- Hotspot `voicecloak/tests/test_vc_level.c`: 14 symbols, 9 connections (score 0.23).
- Surprising bridge: vc_effects.c <-> vc_wav.c (7 hops across communities).
- Key entities: file:voicecloak/src/vc_effects.c, file:voicecloak/src/vc_level.h, file:voicecloak/tests/test_vc_level.c, file:voicecloak/src/vc_eq.h, file:voicecloak/tests/test_vc_effects.c, file:voicecloak/tests/test_vc_presets.c, file:voicecloak/src/vc_audio_config.h, file:voicecloak/src/vc_effects.h
- Rating 7.0/10 = 7 x PageRank share 1.00 + 3 x risk 0.00. Internal imports: 15.

## voicecloak/src: vc_denoise (`c0`, community, rating 5.0)

14 files under voicecloak/src (c 9, h 5), mostly utility. Core file voicecloak/src/vc_fft.h (PageRank 0.0327, imported by 6 files). Key abstractions: VC_FFT_H, FFT, vc_rt_params_t, VC_RT_H, VC_RT_MIN_SEMITONES, VC_RT_MAX_SEMITONES. Depends on voicecloak/src: vc_effects (5), voicecloak/src: vc_crypto (1). Used by voicecloak/src: vc_effects (2), voicecloak/src: vc_crypto (2).

- `voicecloak/src/vc_fft.h` ranks 1 by PageRank, 6 importers, 2 symbols.
- `voicecloak/src/vc_rt.h` ranks 2 by PageRank, 6 importers, 17 symbols: vc_rt_params_t: @brief Real-time cloak parameters (already resolved to scalars).  pitch_ratio 1.0 = no shift; formant_factor 1.0 = no shift; scramble_intensity 0.0 = none; robotize 0 = off, 1 = every synthesis frame is rewritten with a...
- `voicecloak/src/vc_stream.h` ranks 3 by PageRank, 7 importers, 13 symbols: vc_spectral_chain_t: @brief Ordered list of spectral stages run as one vc_spectral_fn.
- Hotspot `voicecloak/src/vc_rt_cli.c`: 10 symbols, 20 connections (score 0.47).
- Hotspot `voicecloak/tests/test_vc_denoise.c`: 23 symbols, 16 connections (score 0.40).
- Dataflow: 14 INFERRED issues (first: UNCHECKED_ALLOC in test_fft_dc_signal).
- Key entities: file:voicecloak/src/vc_denoise.h, file:voicecloak/tests/test_vc_denoise.c, file:voicecloak/tests/test_vc_stream.c, file:voicecloak/src/vc_rt.h, file:voicecloak/src/vc_stream.h, file:voicecloak/src/vc_denoise.c, file:voicecloak/src/vc_rt_cli.c, file:voicecloak/src/vc_stream.c
- Rating 5.0/10 = 7 x PageRank share 0.71 + 3 x risk 0.00. Internal imports: 20.

## legacy (`c2`, community, rating 4.4)

11 files under legacy (c 4, py 4, h 3), mostly utility. Core file legacy/vsl_config.h (PageRank 0.0582, imported by 10 files). Key abstractions: VSL_CONFIG_H, VSL_VENDOR_ID, VSL_PRODUCT_ID, VSL_REPORT_ID, VSL_SCALE_FACTOR, VSL_MAX_ENCODED_INT.

- `legacy/vsl_config.h` ranks 1 by PageRank, 10 importers, 8 symbols.
- `legacy/vsl_dsp_logic.h` ranks 2 by PageRank, 2 importers, 7 symbols: Constante para la conversión de logaritmo natural (ln) a logaritmo base 2 (log2) 1 / ln(2) ≈ 1.442695  Estructura que almacena todos los coeficientes precalculados del DSP
- `legacy/vsl_dsp_transport.h` ranks 3 by PageRank, 3 importers, 7 symbols: VSL_DSP_Packet: Estructura de Paquete: Sin 'header' (lo quitaste en la estructura typedef)
- Hotspot `legacy/vsl_hid_io.py`: 9 symbols, 12 connections (score 0.29).
- Hotspot `legacy/vsl_config.h`: 8 symbols, 11 connections (score 0.26).
- Key entities: file:legacy/vsl_config.h, file:legacy/vsl_dsp_logic.h, file:legacy/vsl_hid_io.py, file:legacy/vsl_dsp_transport.h, file:legacy/vsl_dsp_transport.c, file:legacy/vsl_core.py, file:legacy/vsl_transport.py, file:legacy/vsl_poc_main.py
- Rating 4.4/10 = 7 x PageRank share 0.62 + 3 x risk 0.00. Internal imports: 19.

## voicecloak/src: vc_crypto (`c3`, community, rating 3.0)

10 files under voicecloak/src (c 6, h 4), mostly utility. Core file voicecloak/src/vc_crypto.h (PageRank 0.0245, imported by 5 files): vc_crypto_keygen: @brief Generate an RSA-4096 keypair and write to PEM files. @param pubkey_path   Output path for public key. @param privkey_path  Output path for private key. @return 0 on success, -1 on error. Key abstractions: VC_CRYPTO_H, VC_CRYPTO_SEED_BYTES, VC_CRYPTO_KEY_BYTES, VC_PITCH_SEED_BYTES, VC_FORMANT_SEED_BYTES, VC_SPECTRAL_SEED_BYTES. Depends on voicecloak/src: vc_denoise (2). Used by voicecloak/src: vc_denoise (1).

- `voicecloak/src/vc_crypto.h` ranks 1 by PageRank, 5 importers, 16 symbols: vc_crypto_keygen: @brief Generate an RSA-4096 keypair and write to PEM files. @param pubkey_path   Output path for public key. @param privkey_path  Output path for private key. @return 0 on success, -1 on error.
- `voicecloak/src/vc_wav.h` ranks 2 by PageRank, 2 importers, 3 symbols: vc_wav_read: @brief Read a mono PCM WAV file into a float buffer [-1.0, 1.0]. @param path         File path. @param samples_out  Output: allocated float array. @param num_samples_out Output: number of samples. @param sample_rate_out...
- `voicecloak/src/vc_stft.h` ranks 3 by PageRank, 2 importers, 9 symbols: vc_stft_create: @brief Allocate STFT context. @param fft_size  FFT size (power of 2, e.g.
- Hotspot `voicecloak/src/vc_crypto.c`: 10 symbols, 11 connections (score 0.27).
- Hotspot `voicecloak/src/vc_dsp.c`: 11 symbols, 10 connections (score 0.24).
- Dataflow: 5 INFERRED issues (first: UNINIT_USE in cmd_cloak).
- Surprising bridge: vc_effects.c <-> vc_wav.c (7 hops across communities).
- Key entities: file:voicecloak/src/vc_crypto.h, file:voicecloak/src/vc_crypto.c, file:voicecloak/src/vc_stft.h, file:voicecloak/src/vc_dsp.c, file:voicecloak/src/vc_wav.c, file:voicecloak/src/vc_stft.c, file:voicecloak/src/vc_cli.c, file:voicecloak/src/vc_dsp.h
- Rating 3.0/10 = 7 x PageRank share 0.44 + 3 x risk 0.00. Internal imports: 10.

## src (`c4`, community, rating 2.2)

6 files under src (c 3, h 3), mostly utility. Core file src/vsl_dsp_logic.h (PageRank 0.0251, imported by 3 files): VSL_Encode_Gain: @brief Encodes a linear gain value [0.0, 1.0] to the DSP exponential curve. @param linear_value Linear control position clamped to [0,1]. @param param Parameter coefficients from the DSP parameter database. @return... Key abstractions: VSL_Parameter, VSL_DSP_LOGIC_H, VSL_INV_LN2, VSL_MAX_ENCODED_FLOAT, VSL_DB_NEG_INF, VSL_DB_FLOOR_LINEAR.

- `src/vsl_dsp_logic.h` ranks 1 by PageRank, 3 importers, 13 symbols: VSL_Encode_Gain: @brief Encodes a linear gain value [0.0, 1.0] to the DSP exponential curve. @param linear_value Linear control position clamped to [0,1]. @param param Parameter coefficients from the DSP parameter database. @return...
- `src/vsl_config.h` ranks 2 by PageRank, 2 importers, 14 symbols: pid: ifdef __cplusplus
- `src/vsl_dsp_transport.h` ranks 3 by PageRank, 2 importers, 8 symbols: VSL_Close_Device: @brief Release the MIDI interface and close the device. @param handle Handle from VSL_Init_Device.
- Hotspot `src/vsl_cli.c`: 11 symbols, 11 connections (score 0.27).
- Hotspot `src/vsl_dsp_transport.h`: 8 symbols, 7 connections (score 0.17).
- Key entities: file:src/vsl_dsp_logic.h, file:src/vsl_config.h, file:src/vsl_cli.c, file:src/vsl_dsp_transport.h, file:src/vsl_dsp_transport.c, file:src/vsl_dsp_logic.c, sym:src/vsl_dsp_logic.c::VSL_DB_To_Linear@105, sym:src/vsl_dsp_logic.c::VSL_Decode_Frequency@76
- Rating 2.2/10 = 7 x PageRank share 0.31 + 3 x risk 0.00. Internal imports: 7.

## unassigned files (`c7`, community, rating 1.5)

7 files under legacy (sh 4, py 3), mostly utility. Core file install.sh (PageRank 0.0083, imported by 0 files). Key abstractions: print_header, print_success, print_error, print_warning, print_info, check_root.

- `install.sh` ranks 1 by PageRank, 0 importers, 0 symbols.
- `legacy/app.py` ranks 2 by PageRank, 0 importers, 0 symbols: Autor: Gris Iscomeback Correo electrónico: grisiscomeback[at]gmail[dot]com Fecha de creación: xx/xx/xxxx Licencia: GPL v3  Descripción:
- `legacy/build-dkms.sh` ranks 3 by PageRank, 0 importers, 19 symbols: AudioBox 22 VSL Enhanced Driver - Installation Script Copyright (c) 2025 grisuno (LazyOwn Project) License: GPL-2.0-or-later  This script installs enhanced ALSA controls for PreSonus AudioBox 22 VSL using DKMS (Dynamic Kernel Module...
- Hotspot `legacy/vsl_protocol_analyzer.py`: 7 symbols, 5 connections (score 0.12).
- Hotspot `legacy/vsl_config.py`: 3 symbols, 2 connections (score 0.05).
- Key entities: file:legacy/build-dkms.sh, file:legacy/vsl_protocol_analyzer.py, file:legacy/vsl_config.py, file:tests/bdd_driver_gate.sh, sym:legacy/vsl_protocol_analyzer.py::get_decoded_value@115, sym:legacy/vsl_config.py::validate_configuration@92, sym:legacy/vsl_protocol_analyzer.py::decode_vsl_packet@140, sym:legacy/vsl_config.py::print_configuration_status@116
- Rating 1.5/10 = 7 x PageRank share 0.21 + 3 x risk 0.00. Internal imports: 0.

## root (`c5`, community, rating 1.4)

4 files under root (c 3, h 1), mostly utility. Core file audiobox_vsl.h (PageRank 0.0293, imported by 3 files): audiobox_model_info_t: @brief Pair of product ID and canonical human readable model name. Key abstractions: audiobox_model_info_t, usb_mixer_interface, AUDIOBOX_VSL_H, audiobox_model_pid_t, AUDIOBOX_VENDOR_ID, AUDIOBOX_VERSION_STRING.

- `audiobox_vsl.h` ranks 1 by PageRank, 3 importers, 9 symbols: audiobox_model_info_t: @brief Pair of product ID and canonical human readable model name.
- `audiobox_vsl.c` ranks 2 by PageRank, 0 importers, 5 symbols.
- `legacy/mixer_quirks.c` ranks 3 by PageRank, 0 importers, 309 symbols: rc_config: Sound Blaster remote control configuration  format of remote control data: Extigy:       xx 00 Audigy 2 NX:  06 80 xx 00 00 00 Live!
- Hotspot `legacy/mixer_quirks.c`: 309 symbols, 26 connections (score 1.00).
- Hotspot `audiobox_vsl.h`: 9 symbols, 9 connections (score 0.22).
- Taint: 2 paths reach this group via input.
- Dataflow: 2 INFERRED issues (first: DEAD_STORE in snd_emuusb_set_samplerate).
- Key entities: file:legacy/mixer_quirks.c, file:audiobox_vsl.h, file:tests/test_audiobox_vsl.c, file:audiobox_vsl.c, sym:legacy/mixer_quirks.c::DECLARE_TLV_DB_RANGE@4465, sym:legacy/mixer_quirks.c::HDA_VERB_CMD@2172, sym:legacy/mixer_quirks.c::REALTEK_AUDIO_FUNCTION_GROUP@2181, sym:legacy/mixer_quirks.c::REALTEK_CBJ_CTRL2@2186
- Rating 1.4/10 = 7 x PageRank share 0.20 + 3 x risk 0.00. Internal imports: 3.

## avatar (`c6`, community, rating 1.2)

4 files under avatar (c 2, h 2), mostly business_logic. Core file avatar/avatar_logic.h (PageRank 0.0188, imported by 2 files): avatar_cfg_t: @brief Tunable classifier thresholds. Key abstractions: avatar_cfg_t, avatar_smooth_t, AVATAR_LOGIC_H, avatar_state_t, avatar_rms_f32, avatar_rms_to_dbfs.

- `avatar/avatar_logic.h` ranks 1 by PageRank, 2 importers, 12 symbols: avatar_cfg_t: @brief Tunable classifier thresholds.
- `avatar/avatar_config.h` ranks 2 by PageRank, 1 importers, 14 symbols.
- `avatar/avatar_logic.c` ranks 3 by PageRank, 0 importers, 8 symbols.
- Hotspot `avatar/avatar_main.c`: 7 symbols, 13 connections (score 0.31).
- Hotspot `avatar/avatar_logic.h`: 12 symbols, 4 connections (score 0.11).
- Key entities: file:avatar/avatar_logic.h, file:avatar/avatar_config.h, file:avatar/avatar_main.c, file:avatar/avatar_logic.c, sym:avatar/avatar_config.h::AVATAR_CONFIG_H@2, sym:avatar/avatar_config.h::AVATAR_DEFAULT_HF_THR@21, sym:avatar/avatar_config.h::AVATAR_DEFAULT_HOLD_MS@22, sym:avatar/avatar_config.h::AVATAR_DEFAULT_PCM@12
- Rating 1.2/10 = 7 x PageRank share 0.17 + 3 x risk 0.00. Internal imports: 3.
