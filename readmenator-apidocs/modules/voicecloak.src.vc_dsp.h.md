# `voicecloak/src/vc_dsp.h`

> Source: [voicecloak/src/vc_dsp.h:1](../../voicecloak/src/vc_dsp.h#L1) | language `h` | coverage 0.0% | [API index](../index.md)

## Contents

- **Functions:** [`vc_dsp_pitch_shift`](#vc_dsp_pitch_shift), [`vc_dsp_formant_shift`](#vc_dsp_formant_shift), [`vc_dsp_spectral_scramble`](#vc_dsp_spectral_scramble), [`vc_dsp_cloak`](#vc_dsp_cloak)
- **Variables:** [`VcMode`](#vcmode)

## Functions

<a id="vc_dsp_pitch_shift"></a>

### `vc_dsp_pitch_shift`

`function` | [voicecloak/src/vc_dsp.h:16](../../voicecloak/src/vc_dsp.h#L16)

```c
int vc_dsp_pitch_shift(const float *samples, size_t num_samples, uint32_t sample_rate, float semitones, float **out, size_t *out_len);
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `samples` | `float *` |  |  |
| `num_samples` | `size_t` |  |  |
| `sample_rate` | `uint32_t` |  |  |
| `semitones` | `float` |  |  |
| `out` | `float **` |  |  |
| `out_len` | `size_t *` |  |  |

**Returns:** `int`

---

<a id="vc_dsp_formant_shift"></a>

### `vc_dsp_formant_shift`

`function` | [voicecloak/src/vc_dsp.h:20](../../voicecloak/src/vc_dsp.h#L20)

```c
int vc_dsp_formant_shift(const float *samples, size_t num_samples, uint32_t sample_rate, float shift_factor, float **out, size_t *out_len);
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `samples` | `float *` |  |  |
| `num_samples` | `size_t` |  |  |
| `sample_rate` | `uint32_t` |  |  |
| `shift_factor` | `float` |  |  |
| `out` | `float **` |  |  |
| `out_len` | `size_t *` |  |  |

**Returns:** `int`

---

<a id="vc_dsp_spectral_scramble"></a>

### `vc_dsp_spectral_scramble`

`function` | [voicecloak/src/vc_dsp.h:24](../../voicecloak/src/vc_dsp.h#L24)

```c
int vc_dsp_spectral_scramble(const float *samples, size_t num_samples, uint32_t sample_rate, float intensity, float **out, size_t *out_len);
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `samples` | `float *` |  |  |
| `num_samples` | `size_t` |  |  |
| `sample_rate` | `uint32_t` |  |  |
| `intensity` | `float` |  |  |
| `out` | `float **` |  |  |
| `out_len` | `size_t *` |  |  |

**Returns:** `int`

---

<a id="vc_dsp_cloak"></a>

### `vc_dsp_cloak`

`function` | [voicecloak/src/vc_dsp.h:28](../../voicecloak/src/vc_dsp.h#L28)

```c
int vc_dsp_cloak(const float *samples, size_t num_samples, uint32_t sample_rate, const unsigned char *pitch_seed, const unsigned char *formant_seed, const unsigned char *spectral_seed, VcMode mode, float **out, size_t *out_len)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `samples` | `float *` |  |  |
| `num_samples` | `size_t` |  |  |
| `sample_rate` | `uint32_t` |  |  |
| `pitch_seed` | `unsigned char *` |  |  |
| `formant_seed` | `unsigned char *` |  |  |
| `spectral_seed` | `unsigned char *` |  |  |
| `mode` | `VcMode` |  |  |
| `out` | `float **` |  |  |
| `out_len` | `size_t *` |  |  |

**Returns:** `int`

---

## Variables

<a id="vcmode"></a>

### `VcMode`

`variable` `extern` | [voicecloak/src/vc_dsp.h:8](../../voicecloak/src/vc_dsp.h#L8)

```c
extern "C" { #endif typedef enum { VC_MODE_SUBTLE = 0, VC_MODE_WITNESS = 1 } VcMode;
```

ifdef __cplusplus

---
