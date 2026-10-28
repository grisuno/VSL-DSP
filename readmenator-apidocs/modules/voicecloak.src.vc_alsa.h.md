# `voicecloak/src/vc_alsa.h`

> Source: [voicecloak/src/vc_alsa.h:1](../../voicecloak/src/vc_alsa.h#L1) | language `h` | coverage 60.0% | [API index](../index.md)

## Contents

- **Structs:** [`vc_alsa_cfg_t`](#vc_alsa_cfg_t)
- **Functions:** [`runtime`](#runtime), [`vc_alsa_list`](#vc_alsa_list), [`vc_alsa_run`](#vc_alsa_run)

## Structs

<a id="vc_alsa_cfg_t"></a>

### `vc_alsa_cfg_t`

`struct` | [voicecloak/src/vc_alsa.h:26](../../voicecloak/src/vc_alsa.h#L26)

```c
typedef struct
```

Configuration for a real-time ALSA processing session. The capture and playback device names are ALSA PCM names discovered at runtime (e.g. "hw:VSL", "plughw:2,0", "default"); nothing is hardcoded. Rate and channel count are requested but the negotiated values from the device win. The DSP engine is created internally with the negotiated rate; the transform callback and its context are supplied by the caller.

---

## Functions

<a id="runtime"></a>

### `runtime`

`function` | [voicecloak/src/vc_alsa.h:20](../../voicecloak/src/vc_alsa.h#L20)

```c
* * The capture and playback device names are ALSA PCM names discovered * at runtime (e.g. "hw:VSL", "plughw:2,0", "default");
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `VSL` | `e.g. "hw: "` |  |  |
| `plughw` |  |  |  |
| `default` |  |  |  |

**Returns:** `* * The capture and playback device names are ALSA PCM names discovered * at`

---

<a id="vc_alsa_list"></a>

### `vc_alsa_list`

`function` | [voicecloak/src/vc_alsa.h:46](../../voicecloak/src/vc_alsa.h#L46)

```c
int vc_alsa_list(void);
```

Print the available ALSA PCM devices to stdout.

**Returns:** `int` - 0 on success, -1 on error.

*Called by:* [`main`](voicecloak.src.vc_rt_cli.c.md#main)

---

<a id="vc_alsa_run"></a>

### `vc_alsa_run`

`function` | [voicecloak/src/vc_alsa.h:53](../../voicecloak/src/vc_alsa.h#L53)

```c
int vc_alsa_run(const vc_alsa_cfg_t *cfg);
```

Open capture and playback, run the processing loop until *cfg->stop becomes non-zero or a fatal error occurs.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `cfg` | `vc_alsa_cfg_t *` |  |  |

**Returns:** `int` - 0 on clean stop, -1 on error.

---
