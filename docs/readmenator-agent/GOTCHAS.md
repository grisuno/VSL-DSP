# Gotchas

## God Nodes (high connectivity)

These files have the most connections. Changes here have high blast radius.

- `legacy/mixer_quirks.c` (score: 32.90)
- `voicecloak/src/vc_stream.h` (score: 15.30, imported by 7 files)
- `voicecloak/src/vc_rt_cli.c` (score: 15.00)
- `legacy/vsl_config.h` (score: 14.80, imported by 7 files)
- `voicecloak/src/vc_rt.h` (score: 13.70, imported by 6 files)
- `voicecloak/src/vc_eq.h` (score: 13.00, imported by 5 files)
- `voicecloak/src/vc_alsa.h` (score: 12.50, imported by 2 files)
- `voicecloak/src/vc_presets.h` (score: 12.40, imported by 3 files)
- `voicecloak/src/vc_fft.h` (score: 12.20, imported by 6 files)
- `voicecloak/src/vc_crypto.h` (score: 11.60, imported by 5 files)

## Blast Radius (change impact)

Editing these files can break the listed number of dependents. Run their tests after any change.

- `voicecloak/src/vc_audio_config.h` -- 4 direct, 18 total dependents
- `legacy/vsl_config.h` -- 7 direct, 8 total dependents
- `voicecloak/src/vc_effects.h` -- 4 direct, 8 total dependents
- `voicecloak/src/vc_eq.h` -- 5 direct, 8 total dependents
- `voicecloak/src/vc_rt.h` -- 6 direct, 8 total dependents
- `voicecloak/src/vc_stream.h` -- 7 direct, 7 total dependents
- `voicecloak/src/vc_fft.h` -- 6 direct, 6 total dependents
- `voicecloak/src/vc_level.h` -- 4 direct, 6 total dependents
- `voicecloak/src/vc_crypto.h` -- 5 direct, 5 total dependents
- `src/vsl_dsp_logic.h` -- 3 direct, 4 total dependents

## Hotspots (complexity + centrality)

- `legacy/mixer_quirks.c` -- complexity: 1.0, centrality: 1.0, combined: 1.0
- `voicecloak/src/vc_rt_cli.c` -- complexity: 0.0, centrality: 0.8, combined: 0.5
- `avatar/avatar_main.c` -- complexity: 0.0, centrality: 0.5, combined: 0.3
- `voicecloak/src/vc_alsa.h` -- complexity: 0.0, centrality: 0.5, combined: 0.3
- `legacy/vsl_hid_io.py` -- complexity: 0.0, centrality: 0.5, combined: 0.3
- `src/vsl_cli.c` -- complexity: 0.0, centrality: 0.4, combined: 0.3
- `voicecloak/src/vc_crypto.c` -- complexity: 0.0, centrality: 0.4, combined: 0.3
- `legacy/vsl_config.h` -- complexity: 0.0, centrality: 0.4, combined: 0.3
- `voicecloak/src/vc_dsp.c` -- complexity: 0.0, centrality: 0.4, combined: 0.2
- `voicecloak/src/vc_alsa.c` -- complexity: 0.0, centrality: 0.4, combined: 0.2

## Dataflow Issues (INFERRED, review each lead)

- `legacy/mixer_quirks.c:1547` `snd_emuusb_set_samplerate` [DEAD_STORE] `unitid`: `unitid` assigned at line 1547 but never read afterwards.
- `legacy/mixer_quirks.c:2947` `snd_bbfpro_gain_get` [DEAD_STORE] `value`: `value` assigned at line 2947 but never read afterwards.
- `voicecloak/src/vc_cli.c:109` `cmd_cloak` [UNINIT_USE] `pitch_seed`: `pitch_seed` may be read before initialization (declared line 105).
- `voicecloak/src/vc_cli.c:109` `cmd_cloak` [UNINIT_USE] `formant_seed`: `formant_seed` may be read before initialization (declared line 106).
- `voicecloak/src/vc_cli.c:109` `cmd_cloak` [UNINIT_USE] `spectral_seed`: `spectral_seed` may be read before initialization (declared line 107).
- `voicecloak/src/vc_stft.c:105` `vc_stft_forward` [DEAD_STORE] `m`: `m` assigned at line 105 but never read afterwards.
- `voicecloak/src/vc_stft.c:106` `vc_stft_forward` [DEAD_STORE] `p`: `p` assigned at line 106 but never read afterwards.
- `voicecloak/tests/test_vc_fft.c:32` `test_fft_dc_signal` [UNCHECKED_ALLOC] `imag`: Result of allocator stored in `imag` is never checked against NULL.
- `voicecloak/tests/test_vc_fft.c:51` `test_fft_sine` [UNCHECKED_ALLOC] `real`: Result of allocator stored in `real` is never checked against NULL.
- `voicecloak/tests/test_vc_fft.c:52` `test_fft_sine` [UNCHECKED_ALLOC] `imag`: Result of allocator stored in `imag` is never checked against NULL.
