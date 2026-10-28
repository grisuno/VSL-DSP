# `voicecloak/src/vc_fft.c`

> Source: [voicecloak/src/vc_fft.c:1](../../voicecloak/src/vc_fft.c#L1) | language `c` | coverage 0.0% | [API index](../index.md)

## Contents

- **Functions:** [`vc_fft`](#vc_fft)
- **Macros:** [`M_PI`](#m_pi)

## Functions

<a id="vc_fft"></a>

### `vc_fft`

`function` | [voicecloak/src/vc_fft.c:36](../../voicecloak/src/vc_fft.c#L36)

```c
void vc_fft(size_t n, float *real, float *imag, int inverse)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `n` | `size_t` |  |  |
| `real` | `float *` |  |  |
| `imag` | `float *` |  |  |
| `inverse` | `int` |  |  |

*Called by:* [`vc_stft_forward`](voicecloak.src.vc_stft.c.md#vc_stft_forward), [`vc_stft_inverse_hop`](voicecloak.src.vc_stft.c.md#vc_stft_inverse_hop)

---

## Macros

<a id="m_pi"></a>

### `M_PI`

`macro` | [voicecloak/src/vc_fft.c:7](../../voicecloak/src/vc_fft.c#L7)

```c
#define M_PI
```

---
