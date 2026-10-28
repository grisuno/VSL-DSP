# `voicecloak/src/vc_wav.h`

> Source: [voicecloak/src/vc_wav.h:1](../../voicecloak/src/vc_wav.h#L1) | language `h` | coverage 66.7% | [API index](../index.md)

## Contents

- **Functions:** [`vc_wav_read`](#vc_wav_read), [`vc_wav_write`](#vc_wav_write)

## Functions

<a id="vc_wav_read"></a>

### `vc_wav_read`

`function` | [voicecloak/src/vc_wav.h:19](../../voicecloak/src/vc_wav.h#L19)

```c
int vc_wav_read(const char *path, float **samples_out, size_t *num_samples_out, uint32_t *sample_rate_out);
```

Read a mono PCM WAV file into a float buffer [-1.0, 1.0].

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `path` | `char *` |  | File path. |
| `samples_out` | `float **` |  | Output: allocated float array. |
| `num_samples_out` | `size_t *` |  | Output: number of samples. |
| `sample_rate_out` | `uint32_t *` |  | Output: sample rate (Hz). |

**Returns:** `int` - 0 on success, -1 on error.

---

<a id="vc_wav_write"></a>

### `vc_wav_write`

`function` | [voicecloak/src/vc_wav.h:31](../../voicecloak/src/vc_wav.h#L31)

```c
int vc_wav_write(const char *path, const float *samples, size_t num_samples, uint32_t sample_rate);
```

Write a mono float buffer to a 16-bit PCM WAV file.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `path` | `char *` |  | File path. |
| `samples` | `float *` |  | Float samples in [-1.0, 1.0]. |
| `num_samples` | `size_t` |  | Number of samples. |
| `sample_rate` | `uint32_t` |  | Sample rate (Hz). |

**Returns:** `int` - 0 on success, -1 on error.

---
