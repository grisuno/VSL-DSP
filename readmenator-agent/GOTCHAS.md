# Gotchas

## God Nodes (high connectivity)

These files have the most connections. Changes here have high blast radius.

- `legacy/mixer_quirks.c` (score: 32.90)
- `legacy/vsl_config.h` (score: 14.80)
- `voicecloak/src/vc_fft.h` (score: 12.20)
- `voicecloak/src/vc_crypto.h` (score: 11.60)
- `voicecloak/src/vc_rt_cli.c` (score: 10.90)
- `voicecloak/src/vc_stream.h` (score: 10.80)
- `voicecloak/src/vc_rt.h` (score: 9.00)
- `legacy/vsl_dsp_transport.h` (score: 8.70)
- `src/vsl_dsp_transport.h` (score: 8.50)
- `voicecloak/tests/test_vc_stream.c` (score: 7.30)

## Hotspots (complexity + centrality)

- `legacy/mixer_quirks.c` -- complexity: 1.0, centrality: 1.0, combined: 1.0
- `voicecloak/src/vc_rt_cli.c` -- complexity: 0.0, centrality: 0.6, combined: 0.4
- `voicecloak/tests/test_vc_stream.c` -- complexity: 0.0, centrality: 0.5, combined: 0.3
- `legacy/vsl_hid_io.py` -- complexity: 0.0, centrality: 0.5, combined: 0.3
- `src/vsl_cli.c` -- complexity: 0.0, centrality: 0.4, combined: 0.3
- `voicecloak/src/vc_crypto.c` -- complexity: 0.0, centrality: 0.4, combined: 0.3
- `legacy/vsl_config.h` -- complexity: 0.0, centrality: 0.4, combined: 0.3
- `voicecloak/src/vc_dsp.c` -- complexity: 0.0, centrality: 0.4, combined: 0.2
- `voicecloak/src/vc_alsa.c` -- complexity: 0.0, centrality: 0.4, combined: 0.2
- `voicecloak/src/vc_cli.c` -- complexity: 0.0, centrality: 0.4, combined: 0.2

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
