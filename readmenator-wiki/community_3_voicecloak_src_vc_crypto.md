# voicecloak/src: vc_crypto

*Community 3 | 10 files | cohesion 0.77*

## Definition

This community groups 10 file(s) rooted at `voicecloak/src` with dominant language c (cohesion 0.77). Central symbols: `M_PI`, `VC_CRYPTO_H`, `VC_CRYPTO_KEY_BYTES`, `VC_CRYPTO_SEED_BYTES`, `VC_DSP_H`, `VC_FFT_SIZE`, `VC_FORMANT_SEED_BYTES`, `VC_HOP_SIZE`. Core file: `voicecloak/src/vc_crypto.h` (16 symbols).

## Files

| File | Language | Layer | Symbols | Doc |
|------|----------|-------|---------|-----|
| `voicecloak/src/vc_cli.c` | c | utility | 5 | no |
| `voicecloak/src/vc_crypto.c` | c | utility | 10 | no |
| `voicecloak/src/vc_crypto.h` | h | utility | 16 | no |
| `voicecloak/src/vc_dsp.c` | c | utility | 11 | no |
| `voicecloak/src/vc_dsp.h` | h | utility | 6 | no |
| `voicecloak/src/vc_rt_seed.c` | c | data_access | 1 | no |
| `voicecloak/src/vc_stft.c` | c | utility | 8 | no |
| `voicecloak/src/vc_stft.h` | h | utility | 9 | no |
| `voicecloak/src/vc_wav.c` | c | utility | 10 | no |
| `voicecloak/src/vc_wav.h` | h | utility | 3 | no |

## Key Symbols

- `print_usage` (function, `voicecloak/src/vc_cli.c:9`) `static void print_usage(const char *prog)`
- `cmd_keygen` (function, `voicecloak/src/vc_cli.c:41`) `static int cmd_keygen(void)`
- `cmd_cloak` (function, `voicecloak/src/vc_cli.c:53`) `static int cmd_cloak(const char *pubkey_path,                      const char *i`
- `cmd_info` (function, `voicecloak/src/vc_cli.c:142`) `static int cmd_info(const char *path)`
- `main` (function, `voicecloak/src/vc_cli.c:177`) `int main(int argc, char *argv[])`
- `openssl_init` (function, `voicecloak/src/vc_crypto.c:12`) `static void openssl_init(void)`
- `vc_crypto_keygen` (function, `voicecloak/src/vc_crypto.c:17`) `int vc_crypto_keygen(const char *pubkey_path, const char *privkey_path)`
- `vc_crypto_seal` (function, `voicecloak/src/vc_crypto.c:47`) `int vc_crypto_seal(const char *pubkey_path,                    const unsigned ch`
- `vc_crypto_unseal` (function, `voicecloak/src/vc_crypto.c:71`) `int vc_crypto_unseal(const char *privkey_path,                      const unsign`
- `vc_crypto_derive_seeds` (function, `voicecloak/src/vc_crypto.c:96`) `int vc_crypto_derive_seeds(const unsigned char *master_seed, size_t seed_len,`
- `vc_prng_s` (struct, `voicecloak/src/vc_crypto.c:136`) - int i; for (i = 0; i < 3; ++i) { unsigned int outlen = 32; unsigned char data[64]; size_t data_len =
- `vc_prng_create` (function, `voicecloak/src/vc_crypto.c:143`) `vc_prng_t *vc_prng_create(const unsigned char *seed)`
- `vc_prng_destroy` (function, `voicecloak/src/vc_crypto.c:157`) `void vc_prng_destroy(vc_prng_t *p)`
- `vc_prng_fill` (function, `voicecloak/src/vc_crypto.c:164`) `void vc_prng_fill(vc_prng_t *p, unsigned char *buf, size_t len)`
- `vc_prng_float` (function, `voicecloak/src/vc_crypto.c:184`) `float vc_prng_float(vc_prng_t *p, float low, float high)`
- `VC_CRYPTO_H` (macro, `voicecloak/src/vc_crypto.h:2`) `#define VC_CRYPTO_H`
- `VC_CRYPTO_SEED_BYTES` (macro, `voicecloak/src/vc_crypto.h:11`) `#define VC_CRYPTO_SEED_BYTES`
- `VC_CRYPTO_KEY_BYTES` (macro, `voicecloak/src/vc_crypto.h:12`) `#define VC_CRYPTO_KEY_BYTES`
- `VC_PITCH_SEED_BYTES` (macro, `voicecloak/src/vc_crypto.h:13`) `#define VC_PITCH_SEED_BYTES`
- `VC_FORMANT_SEED_BYTES` (macro, `voicecloak/src/vc_crypto.h:14`) `#define VC_FORMANT_SEED_BYTES`
- `VC_SPECTRAL_SEED_BYTES` (macro, `voicecloak/src/vc_crypto.h:15`) `#define VC_SPECTRAL_SEED_BYTES`
- `VC_TOTAL_SEED_BYTES` (macro, `voicecloak/src/vc_crypto.h:16`) `#define VC_TOTAL_SEED_BYTES`
- `vc_crypto_keygen` (function, `voicecloak/src/vc_crypto.h:24`) `int vc_crypto_keygen(const char *pubkey_path, const char *privkey_path);` - @brief Generate an RSA-4096 keypair and write to PEM files. @param pubkey_path   Output path for pub
- `vc_crypto_seal` (function, `voicecloak/src/vc_crypto.h:35`) `int vc_crypto_seal(const char *pubkey_path, const unsigned char *seed, size_t se` - @brief Encrypt a symmetric session seed using RSA-4096 public key. @param pubkey_path   Path to PEM
- `vc_crypto_unseal` (function, `voicecloak/src/vc_crypto.h:48`) `int vc_crypto_unseal(const char *privkey_path, const unsigned char *enc, size_t` - @brief Decrypt the session seed using RSA-4096 private key. @param privkey_path  Path to PEM private
- `vc_crypto_derive_seeds` (function, `voicecloak/src/vc_crypto.h:61`) `int vc_crypto_derive_seeds(const unsigned char *master_seed, size_t seed_len, un` - @brief Derive sub-seeds from a master seed via HKDF-SHA256. @param master_seed   96-byte master seed
- `vc_prng_t` (type_alias, `voicecloak/src/vc_crypto.h:72`) `typedef struct vc_prng_s vc_prng_t;` - @brief Deterministic PRNG seeded from crypto key material.  Internally uses AES-256-CTR with the giv
- `vc_prng_create` (function, `voicecloak/src/vc_crypto.h:77`) `vc_prng_t *vc_prng_create(const unsigned char *seed);` - @brief Create a PRNG from a 32-byte seed.
- `vc_prng_destroy` (function, `voicecloak/src/vc_crypto.h:82`) `void vc_prng_destroy(vc_prng_t *p);` - @brief Release PRNG.
- `vc_prng_fill` (function, `voicecloak/src/vc_crypto.h:87`) `void vc_prng_fill(vc_prng_t *p, unsigned char *buf, size_t len);` - @brief Fill buffer with deterministic pseudo-random bytes.

## Internal vs External Edges

- Internal resolved imports (EXTRACTED): 10
- Cross-boundary resolved imports (EXTRACTED): 3

## Connections

- [EXTRACTED] depends_on community 0 <-> 3 (strength 0.9): Extracted import edge crosses communities: voicecloak/src/vc_rt_cli.c imports voicecloak/src/vc_crypto.h.
- [INFERRED] shares_context community 2 <-> 3 (strength 0.5): Inferred shared context (layer utility) with no import path between community 2 (legacy) and community 3 (voicecloak/src: vc_crypto).
- [INFERRED] shares_context community 3 <-> 4 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 3 (voicecloak/src: vc_crypto) and community 4 (src).
- [INFERRED] shares_context community 3 <-> 5 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 3 (voicecloak/src: vc_crypto) and community 5 (root).
- [INFERRED] shares_context community 3 <-> 7 (strength 0.5): Inferred shared context (layer utility) with no import path between community 3 (voicecloak/src: vc_crypto) and community 7 (orphans).

## Risks

- [dataflow UNINIT_USE] `voicecloak/src/vc_cli.c:109` `cmd_cloak` `pitch_seed`: `pitch_seed` may be read before initialization (declared line 105).
- [dataflow UNINIT_USE] `voicecloak/src/vc_cli.c:109` `cmd_cloak` `formant_seed`: `formant_seed` may be read before initialization (declared line 106).
- [dataflow UNINIT_USE] `voicecloak/src/vc_cli.c:109` `cmd_cloak` `spectral_seed`: `spectral_seed` may be read before initialization (declared line 107).
- [dataflow DEAD_STORE] `voicecloak/src/vc_stft.c:105` `vc_stft_forward` `m`: `m` assigned at line 105 but never read afterwards.
- [dataflow DEAD_STORE] `voicecloak/src/vc_stft.c:106` `vc_stft_forward` `p`: `p` assigned at line 106 but never read afterwards.

## Open Questions

- Why do 10 file(s) lack file-level docs (e.g. `voicecloak/src/vc_cli.c`)? What purpose do they serve?
- What would break if the most connected file in voicecloak/src: vc_crypto changed?
- Should voicecloak/src: vc_crypto be split, given cohesion 0.77?

## Sources

- `voicecloak/src/vc_cli.c`
- `voicecloak/src/vc_crypto.c`
- `voicecloak/src/vc_crypto.h`
- `voicecloak/src/vc_dsp.c`
- `voicecloak/src/vc_dsp.h`
- `voicecloak/src/vc_rt_seed.c`
- `voicecloak/src/vc_stft.c`
- `voicecloak/src/vc_stft.h`
- `voicecloak/src/vc_wav.c`
- `voicecloak/src/vc_wav.h`
