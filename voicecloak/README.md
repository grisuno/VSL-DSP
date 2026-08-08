# VoiceCloak

Cryptographically secure voice anonymizer.

VoiceCloak applies three non-reversible DSP transformations to a
monophonic WAV recording, each parametrised by a unique 96-byte
cryptographic seed. The seed is encrypted with RSA-4096 and stored
alongside the output. Without the private key the transformation
parameters cannot be recovered. The process is one-way: even
possession of the private key does not enable reversal of the
anonymised audio.

**Warning: this is a proof of concept.** The DSP pipeline has not
been audited against state-of-the-art speaker identification
systems. Do not rely on VoiceCloak for life-critical anonymity
without an independent security assessment.

## Threat model

| Adversary capability              | Countermeasure                       |
|-----------------------------------|--------------------------------------|
| Speaker embedding (ECAPA-TDNN, ResNet) | STFT phase randomisation          |
| Formant matching (forensic voice analysis) | Independent formant warping    |
| Brute-force seed recovery         | 96-byte seed (2^768 search space)    |
| Post-quantum attack on RSA-4096   | Planned: Kyber-512 hybrid KEM        |
| Re-identification via phonemes    | Pitch shift preserves intelligibility but alters F0 |

## DSP pipeline

1. **Pitch shift** — phase vocoder with variable synthesis hop.
   Shift amount: +/- 4 semitones, derived from `vc_prng_float()`.
2. **Formant warp** — frequency-axis warping of the magnitude
   spectrum independent of pitch. Warp factor: +/- 0.3.
3. **Phase scramble** — Gaussian noise injection in the STFT
   phase domain. Standard deviation: 0.15 to 0.5.

All parameters are deterministic for a given seed, but
probabilistically distributed across the allowed range for
different seeds.

## Cryptographic design

- **Key encapsulation**: RSA-4096 (OpenSSL `EVP_PKEY_encrypt`).
- **Key derivation**: HKDF-SHA256 with info labels
  `voicecloak-pitch`, `voicecloak-formant`, `voicecloak-spectral`.
- **Pseudo-random number generator**: AES-256-CTR, seeded from
  the HKDF output, producing deterministic float values in
  arbitrary ranges.

Kyber-512 hybrid encapsulation is planned as an optional
compile-time feature once `liboqs` integration is complete.

## Usage

```sh
cd voicecloak && make

./src/voicecloak keygen

./src/voicecloak cloak -k voicecloak_key.pub input.wav output.wav

./src/voicecloak info output.wav
```

- `keygen` produces `voicecloak_key.pub` (public) and
  `voicecloak_key.pem` (private, 4096-bit RSA).
- `cloak` reads a mono 16-bit PCM WAV, generates a 96-byte random
  session seed, encrypts it with the public key, applies the DSP
  pipeline, writes the anonymised WAV, and stores the ciphertext
  in `output.wav.vc`.
- `info` displays metadata including sample count, duration, and
  sidecar presence.

## Build

```sh
make        # build voicecloak binary
make test   # run FFT unit tests (CMocka)
make clean  # remove build artefacts
```

Requirements:

- C11 compiler (GCC or Clang)
- OpenSSL development headers (`libssl-dev`)
- CMocka (`libcmocka-dev`), for the test target only

The FFT (`vc_fft.c`) and WAV parser (`vc_wav.c`) are self-contained
implementations with no external library dependencies beyond
`libm`. The entire project links against `libssl`, `libcrypto`,
and `libm`.

## Verification

```
$ ./src/voicecloak cloak -k voicecloak_key.pub test.wav test_cloaked.wav
Loading: test.wav
  Samples: 132300, Rate: 44100 Hz, Duration: 3.0s
Encrypting session seed with RSA-4096...
  Seed encrypted: 512 bytes
  Sidecar: test_cloaked.wav.vc
Applying voice cloaking transforms...
  Output samples: 135424 (3.1s)
Writing: test_cloaked.wav
Done. Voice cloaked successfully.
```

Signal statistics before and after:

| Metric          | Original | Cloaked |
|-----------------|----------|---------|
| Samples         | 132300   | 135424  |
| Duration (s)    | 3.00     | 3.07    |
| RMS amplitude   | 0.6042   | 0.2319  |

## Architecture

```
voicecloak/
├── README.md
├── Makefile
├── src/
│   ├── vc_fft.h           Radix-2 Cooley-Tukey FFT (float, in-place)
│   ├── vc_fft.c
│   ├── vc_stft.h          STFT / ISTFT with Hann window and overlap-add
│   ├── vc_stft.c
│   ├── vc_wav.h           WAV PCM read / write (mono, 16-bit)
│   ├── vc_wav.c
│   ├── vc_crypto.h        RSA-4096 keygen/seal/unseal, HKDF, AES-CTR PRNG
│   ├── vc_crypto.c
│   ├── vc_dsp.h           Pitch shift, formant warp, phase scramble, cloak()
│   ├── vc_dsp.c
│   └── vc_cli.c           Command-line interface
└── tests/
    └── test_vc_fft.c      FFT unit tests (CMocka, 3 scenarios)
```

## License

AGPL-3.0-or-later. See the parent project LICENSE file.
