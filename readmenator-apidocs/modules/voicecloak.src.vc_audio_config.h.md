# `voicecloak/src/vc_audio_config.h`

> Source: [voicecloak/src/vc_audio_config.h:1](../../voicecloak/src/vc_audio_config.h#L1) | language `h` | coverage 15.4% | [API index](../index.md)

## Contents

- **Macros:** [`VC_AUDIO_MIN_SAMPLE_RATE`](#vc_audio_min_sample_rate), [`VC_AUDIO_MAX_SAMPLE_RATE`](#vc_audio_max_sample_rate), [`VC_AUDIO_MAX_INTERNAL_SAMPLE`](#vc_audio_max_internal_sample), [`VC_LEVEL_MIN_TARGET_DBFS`](#vc_level_min_target_dbfs), [`VC_LEVEL_MAX_TARGET_DBFS`](#vc_level_max_target_dbfs), [`VC_LEVEL_MIN_CEILING_DBFS`](#vc_level_min_ceiling_dbfs), [`VC_LEVEL_MAX_CEILING_DBFS`](#vc_level_max_ceiling_dbfs), [`VC_LEVEL_MAX_GAIN_DB`](#vc_level_max_gain_db), [`VC_LEVEL_MIN_TIME_MS`](#vc_level_min_time_ms), [`VC_LEVEL_MAX_TIME_MS`](#vc_level_max_time_ms), [`VC_LEVEL_RMS_FLOOR`](#vc_level_rms_floor), [`VC_LEVEL_MAX_SATURATION_DRIVE`](#vc_level_max_saturation_drive)

## Macros

<a id="vc_audio_min_sample_rate"></a>

### `VC_AUDIO_MIN_SAMPLE_RATE`

`macro` | [voicecloak/src/vc_audio_config.h:5](../../voicecloak/src/vc_audio_config.h#L5)

```c
#define VC_AUDIO_MIN_SAMPLE_RATE
```

Accepted sample-rate interval for live effect engines.

---

<a id="vc_audio_max_sample_rate"></a>

### `VC_AUDIO_MAX_SAMPLE_RATE`

`macro` | [voicecloak/src/vc_audio_config.h:6](../../voicecloak/src/vc_audio_config.h#L6)

```c
#define VC_AUDIO_MAX_SAMPLE_RATE
```

---

<a id="vc_audio_max_internal_sample"></a>

### `VC_AUDIO_MAX_INTERNAL_SAMPLE`

`macro` | [voicecloak/src/vc_audio_config.h:9](../../voicecloak/src/vc_audio_config.h#L9)

```c
#define VC_AUDIO_MAX_INTERNAL_SAMPLE
```

Fail-closed bound between DSP stages, before final limiting.

---

<a id="vc_level_min_target_dbfs"></a>

### `VC_LEVEL_MIN_TARGET_DBFS`

`macro` | [voicecloak/src/vc_audio_config.h:11](../../voicecloak/src/vc_audio_config.h#L11)

```c
#define VC_LEVEL_MIN_TARGET_DBFS
```

---

<a id="vc_level_max_target_dbfs"></a>

### `VC_LEVEL_MAX_TARGET_DBFS`

`macro` | [voicecloak/src/vc_audio_config.h:12](../../voicecloak/src/vc_audio_config.h#L12)

```c
#define VC_LEVEL_MAX_TARGET_DBFS
```

---

<a id="vc_level_min_ceiling_dbfs"></a>

### `VC_LEVEL_MIN_CEILING_DBFS`

`macro` | [voicecloak/src/vc_audio_config.h:13](../../voicecloak/src/vc_audio_config.h#L13)

```c
#define VC_LEVEL_MIN_CEILING_DBFS
```

---

<a id="vc_level_max_ceiling_dbfs"></a>

### `VC_LEVEL_MAX_CEILING_DBFS`

`macro` | [voicecloak/src/vc_audio_config.h:14](../../voicecloak/src/vc_audio_config.h#L14)

```c
#define VC_LEVEL_MAX_CEILING_DBFS
```

---

<a id="vc_level_max_gain_db"></a>

### `VC_LEVEL_MAX_GAIN_DB`

`macro` | [voicecloak/src/vc_audio_config.h:15](../../voicecloak/src/vc_audio_config.h#L15)

```c
#define VC_LEVEL_MAX_GAIN_DB
```

---

<a id="vc_level_min_time_ms"></a>

### `VC_LEVEL_MIN_TIME_MS`

`macro` | [voicecloak/src/vc_audio_config.h:16](../../voicecloak/src/vc_audio_config.h#L16)

```c
#define VC_LEVEL_MIN_TIME_MS
```

---

<a id="vc_level_max_time_ms"></a>

### `VC_LEVEL_MAX_TIME_MS`

`macro` | [voicecloak/src/vc_audio_config.h:17](../../voicecloak/src/vc_audio_config.h#L17)

```c
#define VC_LEVEL_MAX_TIME_MS
```

---

<a id="vc_level_rms_floor"></a>

### `VC_LEVEL_RMS_FLOOR`

`macro` | [voicecloak/src/vc_audio_config.h:18](../../voicecloak/src/vc_audio_config.h#L18)

```c
#define VC_LEVEL_RMS_FLOOR
```

---

<a id="vc_level_max_saturation_drive"></a>

### `VC_LEVEL_MAX_SATURATION_DRIVE`

`macro` | [voicecloak/src/vc_audio_config.h:19](../../voicecloak/src/vc_audio_config.h#L19)

```c
#define VC_LEVEL_MAX_SATURATION_DRIVE
```

---
