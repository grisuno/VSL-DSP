# `voicecloak/src/vc_fft.h`

> Source: [voicecloak/src/vc_fft.h:1](../../voicecloak/src/vc_fft.h#L1) | language `h` | coverage 0.0% | [API index](../index.md)

## Contents

- **Functions:** [`FFT`](#fft)

## Functions

<a id="fft"></a>

### `FFT`

`function` | [voicecloak/src/vc_fft.h:18](../../voicecloak/src/vc_fft.h#L18)

```c
* FFT(IFFT(x)) == IFFT(FFT(x)) == x. */ void vc_fft(size_t n, float *real, float *imag, int inverse);
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `x` | `IFFT( )` |  |  |

**Returns:** `*`

---
