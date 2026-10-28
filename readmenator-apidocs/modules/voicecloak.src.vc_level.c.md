# `voicecloak/src/vc_level.c`

> Source: [voicecloak/src/vc_level.c:1](../../voicecloak/src/vc_level.c#L1) | language `c` | coverage 71.4% | [API index](../index.md)

## Contents

- **Structs:** [`vc_level_s`](#vc_level_s)
- **Functions:** [`vc_level_config_defaults`](#vc_level_config_defaults), [`vc_level_create`](#vc_level_create), [`vc_level_destroy`](#vc_level_destroy), [`vc_level_process`](#vc_level_process), [`vc_level_current_gain_db`](#vc_level_current_gain_db)

## Structs

<a id="vc_level_s"></a>

### `vc_level_s`

`struct` | [voicecloak/src/vc_level.c:6](../../voicecloak/src/vc_level.c#L6)

```c
struct vc_level_s
```

---

## Functions

<a id="vc_level_config_defaults"></a>

### `vc_level_config_defaults`

`function` | [voicecloak/src/vc_level.c:55](../../voicecloak/src/vc_level.c#L55)

```c
void vc_level_config_defaults(vc_level_config_t *config)
```

Fill configuration with documented VoiceCloak defaults.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `config` | `vc_level_config_t *` |  |  |

> **Inherited:** Documentation from [`vc_level_config_defaults`](#vc_level_config_defaults) (voicecloak/src/vc_level.h:40).

---

<a id="vc_level_create"></a>

### `vc_level_create`

`function` | [voicecloak/src/vc_level.c:67](../../voicecloak/src/vc_level.c#L67)

```c
vc_level_t *vc_level_create(uint32_t sample_rate, const vc_level_config_t *config)
```

Create smoothed RMS gain control and peak limiter state.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `sample_rate` | `uint32_t` |  |  |
| `config` | `vc_level_config_t *` |  |  |

**Returns:** `vc_level_t *` - Context or NULL if sample rate/configuration is invalid.

> **Inherited:** Documentation from [`vc_level_create`](#vc_level_create) (voicecloak/src/vc_level.h:46).

---

<a id="vc_level_destroy"></a>

### `vc_level_destroy`

`function` | [voicecloak/src/vc_level.c:90](../../voicecloak/src/vc_level.c#L90)

```c
void vc_level_destroy(vc_level_t *level)
```

Release level-control state. NULL-safe.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `level` | `vc_level_t *` |  |  |

> **Inherited:** Documentation from [`vc_level_destroy`](#vc_level_destroy) (voicecloak/src/vc_level.h:50).

---

<a id="vc_level_process"></a>

### `vc_level_process`

`function` | [voicecloak/src/vc_level.c:99](../../voicecloak/src/vc_level.c#L99)

```c
int vc_level_process(vc_level_t *level, float *samples, size_t count)
```

Apply smoothed RMS gain, soft saturation, and peak limiting in place.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `level` | `vc_level_t *` |  |  |
| `samples` | `float *` |  |  |
| `count` | `size_t` |  |  |

**Returns:** `int` - 0 on success; nonzero on invalid arguments/data. Invalid blocks are silenced fail-closed.

> **Inherited:** Documentation from [`vc_level_process`](#vc_level_process) (voicecloak/src/vc_level.h:58).

---

<a id="vc_level_current_gain_db"></a>

### `vc_level_current_gain_db`

`function` | [voicecloak/src/vc_level.c:169](../../voicecloak/src/vc_level.c#L169)

```c
float vc_level_current_gain_db(const vc_level_t *level)
```

Return the current AGC gain in dB, or 0 for a NULL context.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `level` | `vc_level_t *` |  |  |

**Returns:** `float`

> **Inherited:** Documentation from [`vc_level_current_gain_db`](#vc_level_current_gain_db) (voicecloak/src/vc_level.h:61).

---
