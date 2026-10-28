# `voicecloak/src/vc_crypto.h`

> Source: [voicecloak/src/vc_crypto.h:1](../../voicecloak/src/vc_crypto.h#L1) | language `h` | coverage 56.2% | [API index](../index.md)

## Contents

- **Type Aliases:** [`vc_prng_t`](#vc_prng_t)
- **Functions:** [`vc_crypto_keygen`](#vc_crypto_keygen), [`vc_crypto_seal`](#vc_crypto_seal), [`vc_crypto_unseal`](#vc_crypto_unseal), [`vc_crypto_derive_seeds`](#vc_crypto_derive_seeds), [`vc_prng_create`](#vc_prng_create), [`vc_prng_destroy`](#vc_prng_destroy), [`vc_prng_fill`](#vc_prng_fill), [`vc_prng_float`](#vc_prng_float)
- **Macros:** [`VC_CRYPTO_SEED_BYTES`](#vc_crypto_seed_bytes), [`VC_CRYPTO_KEY_BYTES`](#vc_crypto_key_bytes), [`VC_PITCH_SEED_BYTES`](#vc_pitch_seed_bytes), [`VC_FORMANT_SEED_BYTES`](#vc_formant_seed_bytes), [`VC_SPECTRAL_SEED_BYTES`](#vc_spectral_seed_bytes), [`VC_TOTAL_SEED_BYTES`](#vc_total_seed_bytes)

## Type Aliases

<a id="vc_prng_t"></a>

### `vc_prng_t`

`type_alias` | [voicecloak/src/vc_crypto.h:72](../../voicecloak/src/vc_crypto.h#L72)

```c
typedef struct vc_prng_s vc_prng_t;
```

Deterministic PRNG seeded from crypto key material. Internally uses AES-256-CTR with the given seed as key and a zero IV. Produces the same stream for the same seed every time.

---

## Functions

<a id="vc_crypto_keygen"></a>

### `vc_crypto_keygen`

`function` | [voicecloak/src/vc_crypto.h:24](../../voicecloak/src/vc_crypto.h#L24)

```c
int vc_crypto_keygen(const char *pubkey_path, const char *privkey_path);
```

Generate an RSA-4096 keypair and write to PEM files.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `pubkey_path` | `char *` |  | Output path for public key. |
| `privkey_path` | `char *` |  | Output path for private key. |

**Returns:** `int` - 0 on success, -1 on error.

---

<a id="vc_crypto_seal"></a>

### `vc_crypto_seal`

`function` | [voicecloak/src/vc_crypto.h:35](../../voicecloak/src/vc_crypto.h#L35)

```c
int vc_crypto_seal(const char *pubkey_path, const unsigned char *seed, size_t seed_len, unsigned char *enc_out, size_t *enc_len);
```

Encrypt a symmetric session seed using RSA-4096 public key.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `pubkey_path` | `char *` |  | Path to PEM public key. |
| `seed` | `unsigned char *` |  | [in] 96-byte seed (pitch+formant+spectral). |
| `seed_len` | `size_t` |  | Must be VC_TOTAL_SEED_BYTES (96). |
| `enc_out` | `unsigned char *` |  | [out] Buffer for RSA ciphertext (512 bytes). |
| `enc_len` | `size_t *` |  | [out] Length of ciphertext. |

**Returns:** `int` - 0 on success, -1 on error.

---

<a id="vc_crypto_unseal"></a>

### `vc_crypto_unseal`

`function` | [voicecloak/src/vc_crypto.h:48](../../voicecloak/src/vc_crypto.h#L48)

```c
int vc_crypto_unseal(const char *privkey_path, const unsigned char *enc, size_t enc_len, unsigned char *seed, size_t seed_len);
```

Decrypt the session seed using RSA-4096 private key.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `privkey_path` | `char *` |  | Path to PEM private key. |
| `enc` | `unsigned char *` |  | [in] RSA ciphertext. |
| `enc_len` | `size_t` |  | Length of ciphertext. |
| `seed` | `unsigned char *` |  | [out] 96-byte recovered seed. |
| `seed_len` | `size_t` |  | Must be VC_TOTAL_SEED_BYTES. |

**Returns:** `int` - 0 on success, -1 on error.

---

<a id="vc_crypto_derive_seeds"></a>

### `vc_crypto_derive_seeds`

`function` | [voicecloak/src/vc_crypto.h:61](../../voicecloak/src/vc_crypto.h#L61)

```c
int vc_crypto_derive_seeds(const unsigned char *master_seed, size_t seed_len, unsigned char *pitch_seed, unsigned char *formant_seed, unsigned char *spectral_seed);
```

Derive sub-seeds from a master seed via HKDF-SHA256.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `master_seed` | `unsigned char *` |  | 96-byte master seed. |
| `seed_len` | `size_t` |  | VC_TOTAL_SEED_BYTES. |
| `pitch_seed` | `unsigned char *` |  | [out] 32-byte pitch PRNG seed. |
| `formant_seed` | `unsigned char *` |  | [out] 32-byte formant PRNG seed. |
| `spectral_seed` | `unsigned char *` |  | [out] 32-byte spectral PRNG seed. |

**Returns:** `int` - 0 on success, -1 on error.

---

<a id="vc_prng_create"></a>

### `vc_prng_create`

`function` | [voicecloak/src/vc_crypto.h:77](../../voicecloak/src/vc_crypto.h#L77)

```c
vc_prng_t *vc_prng_create(const unsigned char *seed);
```

Create a PRNG from a 32-byte seed.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `seed` | `unsigned char *` |  |  |

**Returns:** `vc_prng_t *`

*Called by:* [`vc_dsp_cloak`](voicecloak.src.vc_dsp.c.md#vc_dsp_cloak), [`vc_rt_derive`](voicecloak.src.vc_rt_seed.c.md#vc_rt_derive)

---

<a id="vc_prng_destroy"></a>

### `vc_prng_destroy`

`function` | [voicecloak/src/vc_crypto.h:82](../../voicecloak/src/vc_crypto.h#L82)

```c
void vc_prng_destroy(vc_prng_t *p);
```

Release PRNG.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `p` | `vc_prng_t *` |  |  |

*Called by:* [`vc_dsp_cloak`](voicecloak.src.vc_dsp.c.md#vc_dsp_cloak), [`vc_rt_derive`](voicecloak.src.vc_rt_seed.c.md#vc_rt_derive)

---

<a id="vc_prng_fill"></a>

### `vc_prng_fill`

`function` | [voicecloak/src/vc_crypto.h:87](../../voicecloak/src/vc_crypto.h#L87)

```c
void vc_prng_fill(vc_prng_t *p, unsigned char *buf, size_t len);
```

Fill buffer with deterministic pseudo-random bytes.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `p` | `vc_prng_t *` |  |  |
| `buf` | `unsigned char *` |  |  |
| `len` | `size_t` |  |  |

---

<a id="vc_prng_float"></a>

### `vc_prng_float`

`function` | [voicecloak/src/vc_crypto.h:92](../../voicecloak/src/vc_crypto.h#L92)

```c
float vc_prng_float(vc_prng_t *p, float low, float high);
```

Generate a float in [low, high] deterministically.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `p` | `vc_prng_t *` |  |  |
| `low` | `float` |  |  |
| `high` | `float` |  |  |

**Returns:** `float`

*Called by:* [`vc_dsp_cloak`](voicecloak.src.vc_dsp.c.md#vc_dsp_cloak), [`vc_rt_derive`](voicecloak.src.vc_rt_seed.c.md#vc_rt_derive)

---

## Macros

<a id="vc_crypto_seed_bytes"></a>

### `VC_CRYPTO_SEED_BYTES`

`macro` | [voicecloak/src/vc_crypto.h:11](../../voicecloak/src/vc_crypto.h#L11)

```c
#define VC_CRYPTO_SEED_BYTES
```

---

<a id="vc_crypto_key_bytes"></a>

### `VC_CRYPTO_KEY_BYTES`

`macro` | [voicecloak/src/vc_crypto.h:12](../../voicecloak/src/vc_crypto.h#L12)

```c
#define VC_CRYPTO_KEY_BYTES
```

---

<a id="vc_pitch_seed_bytes"></a>

### `VC_PITCH_SEED_BYTES`

`macro` | [voicecloak/src/vc_crypto.h:13](../../voicecloak/src/vc_crypto.h#L13)

```c
#define VC_PITCH_SEED_BYTES
```

---

<a id="vc_formant_seed_bytes"></a>

### `VC_FORMANT_SEED_BYTES`

`macro` | [voicecloak/src/vc_crypto.h:14](../../voicecloak/src/vc_crypto.h#L14)

```c
#define VC_FORMANT_SEED_BYTES
```

---

<a id="vc_spectral_seed_bytes"></a>

### `VC_SPECTRAL_SEED_BYTES`

`macro` | [voicecloak/src/vc_crypto.h:15](../../voicecloak/src/vc_crypto.h#L15)

```c
#define VC_SPECTRAL_SEED_BYTES
```

---

<a id="vc_total_seed_bytes"></a>

### `VC_TOTAL_SEED_BYTES`

`macro` | [voicecloak/src/vc_crypto.h:16](../../voicecloak/src/vc_crypto.h#L16)

```c
#define VC_TOTAL_SEED_BYTES
```

---
