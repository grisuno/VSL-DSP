# `voicecloak/src/vc_crypto.c`

> Source: [voicecloak/src/vc_crypto.c:1](../../voicecloak/src/vc_crypto.c#L1) | language `c` | coverage 90.0% | [API index](../index.md)

## Contents

- **Structs:** [`vc_prng_s`](#vc_prng_s)
- **Functions:** [`vc_crypto_keygen`](#vc_crypto_keygen), [`vc_crypto_seal`](#vc_crypto_seal), [`vc_crypto_unseal`](#vc_crypto_unseal), [`vc_crypto_derive_seeds`](#vc_crypto_derive_seeds), [`vc_prng_create`](#vc_prng_create), [`vc_prng_destroy`](#vc_prng_destroy), [`vc_prng_fill`](#vc_prng_fill), [`vc_prng_float`](#vc_prng_float)

## Call Graph

Solid arrows stay in this module, dashed arrows leave it.

```mermaid
flowchart LR
    n_voicecloak_src_vc_crypto_c__vc_prng_float(["vc_prng_float"])
    n_voicecloak_src_vc_crypto_c__vc_prng_fill(["vc_prng_fill"])
    n_voicecloak_src_vc_crypto_c__vc_prng_float --> n_voicecloak_src_vc_crypto_c__vc_prng_fill
```

## Structs

<a id="vc_prng_s"></a>

### `vc_prng_s`

`struct` | [voicecloak/src/vc_crypto.c:136](../../voicecloak/src/vc_crypto.c#L136)

```c
struct vc_prng_s
```

PRNG: AES-256-CTR using OpenSSL EVP

---

## Functions

<a id="vc_crypto_keygen"></a>

### `vc_crypto_keygen`

`function` | [voicecloak/src/vc_crypto.c:17](../../voicecloak/src/vc_crypto.c#L17)

```c
int vc_crypto_keygen(const char *pubkey_path, const char *privkey_path)
```

Generate an RSA-4096 keypair and write to PEM files.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `pubkey_path` | `char *` |  | Output path for public key. |
| `privkey_path` | `char *` |  | Output path for private key. |

**Returns:** `int` - 0 on success, -1 on error.

> **Inherited:** Documentation from [`vc_crypto_keygen`](#vc_crypto_keygen) (voicecloak/src/vc_crypto.h:24).

---

<a id="vc_crypto_seal"></a>

### `vc_crypto_seal`

`function` | [voicecloak/src/vc_crypto.c:47](../../voicecloak/src/vc_crypto.c#L47)

```c
int vc_crypto_seal(const char *pubkey_path, const unsigned char *seed, size_t seed_len, unsigned char *enc_out, size_t *enc_len)
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

> **Inherited:** Documentation from [`vc_crypto_seal`](#vc_crypto_seal) (voicecloak/src/vc_crypto.h:35).

---

<a id="vc_crypto_unseal"></a>

### `vc_crypto_unseal`

`function` | [voicecloak/src/vc_crypto.c:71](../../voicecloak/src/vc_crypto.c#L71)

```c
int vc_crypto_unseal(const char *privkey_path, const unsigned char *enc, size_t enc_len, unsigned char *seed, size_t seed_len)
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

> **Inherited:** Documentation from [`vc_crypto_unseal`](#vc_crypto_unseal) (voicecloak/src/vc_crypto.h:48).

---

<a id="vc_crypto_derive_seeds"></a>

### `vc_crypto_derive_seeds`

`function` | [voicecloak/src/vc_crypto.c:96](../../voicecloak/src/vc_crypto.c#L96)

```c
int vc_crypto_derive_seeds(const unsigned char *master_seed, size_t seed_len, unsigned char *pitch_seed, unsigned char *formant_seed, unsigned char *spectral_seed)
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

> **Inherited:** Documentation from [`vc_crypto_derive_seeds`](#vc_crypto_derive_seeds) (voicecloak/src/vc_crypto.h:61).

---

<a id="vc_prng_create"></a>

### `vc_prng_create`

`function` | [voicecloak/src/vc_crypto.c:143](../../voicecloak/src/vc_crypto.c#L143)

```c
vc_prng_t *vc_prng_create(const unsigned char *seed)
```

Create a PRNG from a 32-byte seed.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `seed` | `unsigned char *` |  |  |

**Returns:** `vc_prng_t *`

> **Inherited:** Documentation from [`vc_prng_create`](#vc_prng_create) (voicecloak/src/vc_crypto.h:77).

---

<a id="vc_prng_destroy"></a>

### `vc_prng_destroy`

`function` | [voicecloak/src/vc_crypto.c:157](../../voicecloak/src/vc_crypto.c#L157)

```c
void vc_prng_destroy(vc_prng_t *p)
```

Release PRNG.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `p` | `vc_prng_t *` |  |  |

> **Inherited:** Documentation from [`vc_prng_destroy`](#vc_prng_destroy) (voicecloak/src/vc_crypto.h:82).

---

<a id="vc_prng_fill"></a>

### `vc_prng_fill`

`function` | [voicecloak/src/vc_crypto.c:164](../../voicecloak/src/vc_crypto.c#L164)

```c
void vc_prng_fill(vc_prng_t *p, unsigned char *buf, size_t len)
```

Fill buffer with deterministic pseudo-random bytes.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `p` | `vc_prng_t *` |  |  |
| `buf` | `unsigned char *` |  |  |
| `len` | `size_t` |  |  |

> **Inherited:** Documentation from [`vc_prng_fill`](#vc_prng_fill) (voicecloak/src/vc_crypto.h:87).

*Called by:* [`vc_prng_float`](#vc_prng_float)

---

<a id="vc_prng_float"></a>

### `vc_prng_float`

`function` | [voicecloak/src/vc_crypto.c:184](../../voicecloak/src/vc_crypto.c#L184)

```c
float vc_prng_float(vc_prng_t *p, float low, float high)
```

Generate a float in [low, high] deterministically.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `p` | `vc_prng_t *` |  |  |
| `low` | `float` |  |  |
| `high` | `float` |  |  |

**Returns:** `float`

> **Inherited:** Documentation from [`vc_prng_float`](#vc_prng_float) (voicecloak/src/vc_crypto.h:92).

*Calls:* [`vc_prng_fill`](#vc_prng_fill)

---
