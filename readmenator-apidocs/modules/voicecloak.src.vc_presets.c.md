# `voicecloak/src/vc_presets.c`

> Source: [voicecloak/src/vc_presets.c:1](../../voicecloak/src/vc_presets.c#L1) | language `c` | coverage 25.0% | [API index](../index.md)

## Contents

- **Structs:** [`vc_preset_definition_t`](#vc_preset_definition_t)
- **Functions:** [`vc_preset_lookup`](#vc_preset_lookup)
- **Macros:** [`NO_EFFECT`](#no_effect)

## Structs

<a id="vc_preset_definition_t"></a>

### `vc_preset_definition_t`

`struct` | [voicecloak/src/vc_presets.c:5](../../voicecloak/src/vc_presets.c#L5)

```c
typedef struct
```

---

## Functions

<a id="vc_preset_lookup"></a>

### `vc_preset_lookup`

`function` | [voicecloak/src/vc_presets.c:115](../../voicecloak/src/vc_presets.c#L115)

```c
int vc_preset_lookup(const char *name, vc_preset_t *out)
```

Resolve a named real-time voice/effect preset.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `name` | `char *` |  |  |
| `out` | `vc_preset_t *` |  |  |

**Returns:** `int` - 0 on match; -1 for unknown name or invalid arguments.

> **Inherited:** Documentation from [`vc_preset_lookup`](#vc_preset_lookup) (voicecloak/src/vc_presets.h:28).

---

## Macros

<a id="no_effect"></a>

### `NO_EFFECT`

`macro` | [voicecloak/src/vc_presets.c:16](../../voicecloak/src/vc_presets.c#L16)

```c
#define NO_EFFECT
```

---
