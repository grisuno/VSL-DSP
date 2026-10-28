# `voicecloak/src/vc_presets.h`

> Source: [voicecloak/src/vc_presets.h:1](../../voicecloak/src/vc_presets.h#L1) | language `h` | coverage 66.7% | [API index](../index.md)

## Contents

- **Structs:** [`vc_preset_t`](#vc_preset_t)
- **Functions:** [`vc_preset_lookup`](#vc_preset_lookup)
- **Variables:** [`name`](#name)

## Structs

<a id="vc_preset_t"></a>

### `vc_preset_t`

`struct` | [voicecloak/src/vc_presets.h:16](../../voicecloak/src/vc_presets.h#L16)

```c
typedef struct
```

Resolved preset: spectral transform, sample-domain effect, equalizer, and the saturation drive for the level stage.

---

## Functions

<a id="vc_preset_lookup"></a>

### `vc_preset_lookup`

`function` | [voicecloak/src/vc_presets.h:28](../../voicecloak/src/vc_presets.h#L28)

```c
int vc_preset_lookup(const char *name, vc_preset_t *out);
```

Resolve a named real-time voice/effect preset.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `name` | `char *` |  |  |
| `out` | `vc_preset_t *` |  |  |

**Returns:** `int` - 0 on match; -1 for unknown name or invalid arguments.

---

## Variables

<a id="name"></a>

### `name`

`variable` `extern` | [voicecloak/src/vc_presets.h:9](../../voicecloak/src/vc_presets.h#L9)

```c
extern "C" { #endif /** * @brief Resolved preset: spectral transform, sample-domain effect, * equalizer, and the saturation drive for the level stage. */ typedef struct { const char *name;
```

ifdef __cplusplus

---
