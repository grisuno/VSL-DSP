#ifndef VC_CRYPTO_H
#define VC_CRYPTO_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define VC_CRYPTO_SEED_BYTES  32U
#define VC_CRYPTO_KEY_BYTES   32U
#define VC_PITCH_SEED_BYTES   32U
#define VC_FORMANT_SEED_BYTES 32U
#define VC_SPECTRAL_SEED_BYTES 32U
#define VC_TOTAL_SEED_BYTES (VC_PITCH_SEED_BYTES + VC_FORMANT_SEED_BYTES + VC_SPECTRAL_SEED_BYTES)

/**
 * @brief Generate an RSA-4096 keypair and write to PEM files.
 * @param pubkey_path   Output path for public key.
 * @param privkey_path  Output path for private key.
 * @return 0 on success, -1 on error.
 */
int vc_crypto_keygen(const char *pubkey_path, const char *privkey_path);

/**
 * @brief Encrypt a symmetric session seed using RSA-4096 public key.
 * @param pubkey_path   Path to PEM public key.
 * @param seed          [in] 96-byte seed (pitch+formant+spectral).
 * @param seed_len      Must be VC_TOTAL_SEED_BYTES (96).
 * @param enc_out       [out] Buffer for RSA ciphertext (512 bytes).
 * @param enc_len       [out] Length of ciphertext.
 * @return 0 on success, -1 on error.
 */
int vc_crypto_seal(const char *pubkey_path,
                   const unsigned char *seed, size_t seed_len,
                   unsigned char *enc_out, size_t *enc_len);

/**
 * @brief Decrypt the session seed using RSA-4096 private key.
 * @param privkey_path  Path to PEM private key.
 * @param enc           [in]  RSA ciphertext.
 * @param enc_len       Length of ciphertext.
 * @param seed          [out] 96-byte recovered seed.
 * @param seed_len      Must be VC_TOTAL_SEED_BYTES.
 * @return 0 on success, -1 on error.
 */
int vc_crypto_unseal(const char *privkey_path,
                     const unsigned char *enc, size_t enc_len,
                     unsigned char *seed, size_t seed_len);

/**
 * @brief Derive sub-seeds from a master seed via HKDF-SHA256.
 * @param master_seed   96-byte master seed.
 * @param seed_len      VC_TOTAL_SEED_BYTES.
 * @param pitch_seed    [out] 32-byte pitch PRNG seed.
 * @param formant_seed  [out] 32-byte formant PRNG seed.
 * @param spectral_seed [out] 32-byte spectral PRNG seed.
 * @return 0 on success, -1 on error.
 */
int vc_crypto_derive_seeds(const unsigned char *master_seed, size_t seed_len,
                           unsigned char *pitch_seed,
                           unsigned char *formant_seed,
                           unsigned char *spectral_seed);

/**
 * @brief Deterministic PRNG seeded from crypto key material.
 *
 * Internally uses AES-256-CTR with the given seed as key and a zero IV.
 * Produces the same stream for the same seed every time.
 */
typedef struct vc_prng_s vc_prng_t;

/**
 * @brief Create a PRNG from a 32-byte seed.
 */
vc_prng_t *vc_prng_create(const unsigned char *seed);

/**
 * @brief Release PRNG.
 */
void vc_prng_destroy(vc_prng_t *p);

/**
 * @brief Fill buffer with deterministic pseudo-random bytes.
 */
void vc_prng_fill(vc_prng_t *p, unsigned char *buf, size_t len);

/**
 * @brief Generate a float in [low, high] deterministically.
 */
float vc_prng_float(vc_prng_t *p, float low, float high);

#ifdef __cplusplus
}
#endif

#endif
