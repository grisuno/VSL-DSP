# `voicecloak/src/vc_stft.h`

> Source: [voicecloak/src/vc_stft.h:1](../../voicecloak/src/vc_stft.h#L1) | language `h` | coverage 87.5% | [API index](../index.md)

## Contents

- **Type Aliases:** [`vc_stft_t`](#vc_stft_t)
- **Functions:** [`vc_stft_create`](#vc_stft_create), [`vc_stft_destroy`](#vc_stft_destroy), [`vc_stft_forward`](#vc_stft_forward), [`vc_stft_inverse`](#vc_stft_inverse), [`vc_stft_inverse_hop`](#vc_stft_inverse_hop), [`vc_stft_num_bins`](#vc_stft_num_bins)
- **Variables:** [`vc_stft_t`](#vc_stft_t)

## Type Aliases

<a id="vc_stft_t"></a>

### `vc_stft_t`

`type_alias` | [voicecloak/src/vc_stft.h:17](../../voicecloak/src/vc_stft.h#L17)

```c
typedef struct vc_stft_s vc_stft_t;
```

Short-Time Fourier Transform context. Allocated via vc_stft_create(). Window size and hop size are fixed at creation time. Window size must be a power of 2.

---

## Functions

<a id="vc_stft_create"></a>

### `vc_stft_create`

`function` | [voicecloak/src/vc_stft.h:25](../../voicecloak/src/vc_stft.h#L25)

```c
vc_stft_t *vc_stft_create(size_t fft_size, size_t hop_size);
```

Allocate STFT context.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `fft_size` | `size_t` |  | FFT size (power of 2, e.g. 2048). |
| `hop_size` | `size_t` |  | Hop size in samples (e.g. fft_size / 4). |

**Returns:** `vc_stft_t *` - Context pointer or NULL on failure.

*Called by:* [`VC_HOP_SIZE`](voicecloak.src.vc_dsp.c.md#vc_hop_size)

---

<a id="vc_stft_destroy"></a>

### `vc_stft_destroy`

`function` | [voicecloak/src/vc_stft.h:30](../../voicecloak/src/vc_stft.h#L30)

```c
void vc_stft_destroy(vc_stft_t *st);
```

Release STFT context.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `st` | `vc_stft_t *` |  |  |

*Called by:* [`VC_HOP_SIZE`](voicecloak.src.vc_dsp.c.md#vc_hop_size)

---

<a id="vc_stft_forward"></a>

### `vc_stft_forward`

`function` | [voicecloak/src/vc_stft.h:42](../../voicecloak/src/vc_stft.h#L42)

```c
int vc_stft_forward(vc_stft_t *st, const float *samples, size_t num_samples, float **mag, float **phase, size_t *num_frames_out);
```

Forward STFT: decompose a mono float buffer into complex frames.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `st` | `vc_stft_t *` |  | STFT context. |
| `samples` | `float *` |  | Input float samples, length = num_samples. |
| `num_samples` | `size_t` |  | Number of input samples. |
| `mag` | `float **` |  | Output: magnitude per bin per frame (row-major, num_frames * (fft_size/2+1)). |
| `phase` | `float **` |  | Output: phase per bin per frame (row-major, same layout as mag). |
| `num_frames_out` | `size_t *` |  | Output: number of frames produced. |

**Returns:** `int` - 0 on success, -1 on error.

*Called by:* [`VC_HOP_SIZE`](voicecloak.src.vc_dsp.c.md#vc_hop_size)

---

<a id="vc_stft_inverse"></a>

### `vc_stft_inverse`

`function` | [voicecloak/src/vc_stft.h:57](../../voicecloak/src/vc_stft.h#L57)

```c
int vc_stft_inverse(vc_stft_t *st, const float *mag, const float *phase, size_t num_frames, float *samples_out, size_t num_samples_out);
```

Inverse STFT: reconstruct signal from modified magnitude/phase.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `st` | `vc_stft_t *` |  | STFT context. |
| `mag` | `float *` |  | Input magnitude (row-major, num_frames * nbins). |
| `phase` | `float *` |  | Input phase (row-major, same layout). |
| `num_frames` | `size_t` |  | Number of frames. |
| `samples_out` | `float *` |  | Output: reconstructed float samples (caller must pre-allocate). |
| `num_samples_out` | `size_t` |  | Number of samples to reconstruct. |

**Returns:** `int` - 0 on success, -1 on error.

---

<a id="vc_stft_inverse_hop"></a>

### `vc_stft_inverse_hop`

`function` | [voicecloak/src/vc_stft.h:66](../../voicecloak/src/vc_stft.h#L66)

```c
int vc_stft_inverse_hop(vc_stft_t *st, const float *mag, const float *phase, size_t num_frames, float *samples_out, size_t num_samples_out, size_t synth_hop);
```

Inverse STFT with custom synthesis hop (for pitch shifting).

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `st` | `vc_stft_t *` |  |  |
| `mag` | `float *` |  |  |
| `phase` | `float *` |  |  |
| `num_frames` | `size_t` |  |  |
| `samples_out` | `float *` |  |  |
| `num_samples_out` | `size_t` |  |  |
| `synth_hop` | `size_t` |  | Synthesis hop size in samples (may differ from analysis hop). |

**Returns:** `int`

---

<a id="vc_stft_num_bins"></a>

### `vc_stft_num_bins`

`function` | [voicecloak/src/vc_stft.h:75](../../voicecloak/src/vc_stft.h#L75)

```c
size_t vc_stft_num_bins(const vc_stft_t *st);
```

Number of frequency bins (fft_size/2 + 1).

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `st` | `vc_stft_t *` |  |  |

**Returns:** `size_t`

---

## Variables

<a id="vc_stft_t"></a>

### `vc_stft_t`

`variable` `extern` | [voicecloak/src/vc_stft.h:8](../../voicecloak/src/vc_stft.h#L8)

```c
extern "C" { #endif /** * @brief Short-Time Fourier Transform context. * * Allocated via vc_stft_create(). Window size and hop size are fixed * at creation time. Window size must be a power of 2. */ t
```

ifdef __cplusplus

---
