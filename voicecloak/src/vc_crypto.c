#include "vc_crypto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/rand.h>
#include <openssl/err.h>
#include <openssl/hmac.h>

static void openssl_init(void) {
    static int done = 0;
    if (!done) { OpenSSL_add_all_algorithms(); ERR_load_crypto_strings(); done = 1; }
}

int vc_crypto_keygen(const char *pubkey_path, const char *privkey_path) {
    openssl_init();
    EVP_PKEY *pkey = NULL;
    FILE *fp_pub = NULL, *fp_priv = NULL;
    int ret = -1;

    EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, NULL);
    if (!ctx) goto cleanup;
    if (EVP_PKEY_keygen_init(ctx) <= 0) goto cleanup;
    if (EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, 4096) <= 0) goto cleanup;
    if (EVP_PKEY_keygen(ctx, &pkey) <= 0) goto cleanup;

    fp_pub = fopen(pubkey_path, "wb");
    if (!fp_pub) goto cleanup;
    if (!PEM_write_PUBKEY(fp_pub, pkey)) goto cleanup;

    fp_priv = fopen(privkey_path, "wb");
    if (!fp_priv) goto cleanup;
    if (!PEM_write_PrivateKey(fp_priv, pkey, NULL, NULL, 0, NULL, NULL)) goto cleanup;

    ret = 0;

cleanup:
    if (fp_pub) fclose(fp_pub);
    if (fp_priv) fclose(fp_priv);
    if (pkey) EVP_PKEY_free(pkey);
    if (ctx) EVP_PKEY_CTX_free(ctx);
    return ret;
}

int vc_crypto_seal(const char *pubkey_path,
                   const unsigned char *seed, size_t seed_len,
                   unsigned char *enc_out, size_t *enc_len) {
    openssl_init();
    if (!seed || seed_len != VC_TOTAL_SEED_BYTES || !enc_out || !enc_len) return -1;

    FILE *fp = fopen(pubkey_path, "rb");
    if (!fp) return -1;
    EVP_PKEY *pkey = PEM_read_PUBKEY(fp, NULL, NULL, NULL);
    fclose(fp);
    if (!pkey) return -1;

    EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new(pkey, NULL);
    if (!ctx || EVP_PKEY_encrypt_init(ctx) <= 0) { EVP_PKEY_free(pkey); EVP_PKEY_CTX_free(ctx); return -1; }

    if (EVP_PKEY_encrypt(ctx, enc_out, enc_len, seed, seed_len) <= 0) {
        EVP_PKEY_free(pkey); EVP_PKEY_CTX_free(ctx); return -1;
    }

    EVP_PKEY_free(pkey);
    EVP_PKEY_CTX_free(ctx);
    return 0;
}

int vc_crypto_unseal(const char *privkey_path,
                     const unsigned char *enc, size_t enc_len,
                     unsigned char *seed, size_t seed_len) {
    openssl_init();
    if (!enc || !enc_len || !seed || seed_len != VC_TOTAL_SEED_BYTES) return -1;

    FILE *fp = fopen(privkey_path, "rb");
    if (!fp) return -1;
    EVP_PKEY *pkey = PEM_read_PrivateKey(fp, NULL, NULL, NULL);
    fclose(fp);
    if (!pkey) return -1;

    EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new(pkey, NULL);
    if (!ctx || EVP_PKEY_decrypt_init(ctx) <= 0) { EVP_PKEY_free(pkey); EVP_PKEY_CTX_free(ctx); return -1; }

    size_t outlen = seed_len;
    if (EVP_PKEY_decrypt(ctx, seed, &outlen, enc, enc_len) <= 0) {
        EVP_PKEY_free(pkey); EVP_PKEY_CTX_free(ctx); return -1;
    }

    EVP_PKEY_free(pkey);
    EVP_PKEY_CTX_free(ctx);
    return 0;
}

int vc_crypto_derive_seeds(const unsigned char *master_seed, size_t seed_len,
                           unsigned char *pitch_seed,
                           unsigned char *formant_seed,
                           unsigned char *spectral_seed) {
    if (!master_seed || seed_len < VC_TOTAL_SEED_BYTES) return -1;
    openssl_init();

    static const char *infos[3] = {
        "voicecloak-pitch",
        "voicecloak-formant",
        "voicecloak-spectral"
    };
    static const size_t info_lens[3] = { 16, 18, 20 };
    unsigned char *outputs[3] = { pitch_seed, formant_seed, spectral_seed };

    /* HMAC-based HKDF: PRK = HMAC-SHA256(salt=NULL=zeros, IKM=master_seed) */
    unsigned char prk[32];
    {
        unsigned char zeros[32] = {0};
        unsigned int prklen = 32U;
        unsigned int sl = (unsigned int)seed_len;
        if (!HMAC(EVP_sha256(), zeros, 32, master_seed, sl, prk, &prklen))
            return -1;
    }

    /* HKDF-Expand: OKM_i = HMAC-SHA256(PRK, OKM_{i-1} || info || i) */
    int i;
    for (i = 0; i < 3; ++i) {
        unsigned int outlen = 32;
        unsigned char data[64];
        size_t data_len = info_lens[i] + 1;
        memcpy(data, infos[i], info_lens[i]);
        data[info_lens[i]] = (unsigned char)0x01;
        if (!HMAC(EVP_sha256(), prk, 32, data, data_len, outputs[i], &outlen))
            return -1;
    }
    return 0;
}

/* PRNG: AES-256-CTR using OpenSSL EVP */
struct vc_prng_s {
    EVP_CIPHER_CTX *ctx;
    unsigned char keystream[64];
    size_t keystream_pos;
    unsigned char counter[16];
};

vc_prng_t *vc_prng_create(const unsigned char *seed) {
    vc_prng_t *p = (vc_prng_t *)calloc(1, sizeof(vc_prng_t));
    if (!p) return NULL;

    openssl_init();
    p->ctx = EVP_CIPHER_CTX_new();
    if (!p->ctx) { free(p); return NULL; }

    memset(p->counter, 0, sizeof(p->counter));
    EVP_EncryptInit_ex(p->ctx, EVP_aes_256_ctr(), NULL, seed, p->counter);
    p->keystream_pos = sizeof(p->keystream);
    return p;
}

void vc_prng_destroy(vc_prng_t *p) {
    if (!p) return;
    if (p->ctx) EVP_CIPHER_CTX_free(p->ctx);
    memset(p, 0, sizeof(*p));
    free(p);
}

void vc_prng_fill(vc_prng_t *p, unsigned char *buf, size_t len) {
    if (!p || !buf || !len) return;

    size_t remaining = len;
    while (remaining > 0) {
        if (p->keystream_pos >= sizeof(p->keystream)) {
            int outlen = 0;
            EVP_EncryptUpdate(p->ctx, p->keystream, &outlen,
                              p->keystream, (int)sizeof(p->keystream));
            p->keystream_pos = 0;
        }
        size_t take = sizeof(p->keystream) - p->keystream_pos;
        if (take > remaining) take = remaining;
        memcpy(buf, p->keystream + p->keystream_pos, take);
        p->keystream_pos += take;
        buf += take;
        remaining -= take;
    }
}

float vc_prng_float(vc_prng_t *p, float low, float high) {
    unsigned char buf[4];
    vc_prng_fill(p, buf, 4);
    uint32_t v;
    memcpy(&v, buf, 4);
    float t = (float)v / (float)UINT32_MAX;
    return low + t * (high - low);
}
