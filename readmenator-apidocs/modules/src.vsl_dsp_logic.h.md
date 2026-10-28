# `src/vsl_dsp_logic.h`

> Source: [src/vsl_dsp_logic.h:1](../../src/vsl_dsp_logic.h#L1) | language `h` | coverage 61.5% | [API index](../index.md)

## Contents

- **Structs:** [`VSL_Parameter`](#vsl_parameter)
- **Functions:** [`VSL_Encode_Gain`](#vsl_encode_gain), [`VSL_Decode_Gain`](#vsl_decode_gain), [`VSL_Map_Frequency`](#vsl_map_frequency), [`VSL_Decode_Frequency`](#vsl_decode_frequency), [`VSL_Final_Encode_To_Int`](#vsl_final_encode_to_int), [`negative`](#negative), [`VSL_DB_To_Linear`](#vsl_db_to_linear)
- **Macros:** [`VSL_INV_LN2`](#vsl_inv_ln2), [`VSL_MAX_ENCODED_FLOAT`](#vsl_max_encoded_float), [`VSL_DB_NEG_INF`](#vsl_db_neg_inf), [`VSL_DB_FLOOR_LINEAR`](#vsl_db_floor_linear)

## Structs

<a id="vsl_parameter"></a>

### `VSL_Parameter`

`struct` | [src/vsl_dsp_logic.h:22](../../src/vsl_dsp_logic.h#L22)

```c
typedef struct
```

---

## Functions

<a id="vsl_encode_gain"></a>

### `VSL_Encode_Gain`

`function` | [src/vsl_dsp_logic.h:44](../../src/vsl_dsp_logic.h#L44)

```c
float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);
```

Encodes a linear gain value [0.0, 1.0] to the DSP exponential curve.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `linear_value` | `float` |  | Linear control position clamped to [0,1]. |
| `param` | `VSL_Parameter *` |  | Parameter coefficients from the DSP parameter database. |

**Returns:** `float` - Encoded float value ready for integer conversion. @source Reverse-engineered from FUN_00132c90 in the Android driver.

---

<a id="vsl_decode_gain"></a>

### `VSL_Decode_Gain`

`function` | [src/vsl_dsp_logic.h:53](../../src/vsl_dsp_logic.h#L53)

```c
float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param);
```

Decodes an encoded gain float back to a linear position [0.0, 1.0].

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `encoded_float` | `float` |  | Value received from the DSP or produced by VSL_Encode_Gain. |
| `param` | `VSL_Parameter *` |  | Same coefficients used during encoding. |

**Returns:** `float` - Linear control position clamped to [0,1]. @source Inverse of VSL_Encode_Gain (FUN_00132c90).

---

<a id="vsl_map_frequency"></a>

### `VSL_Map_Frequency`

`function` | [src/vsl_dsp_logic.h:62](../../src/vsl_dsp_logic.h#L62)

```c
float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);
```

Maps a linear position [0.0, 1.0] to a logarithmic frequency (Hz).

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `linear_position` | `float` |  | Linear control position clamped to [0,1]. |
| `param` | `VSL_Parameter *` |  | Parameter with freq_min_hz and freq_max_hz. |

**Returns:** `float` - Frequency in Hz. @source Reverse-engineered from FUN_00132d00 in the Android driver.

---

<a id="vsl_decode_frequency"></a>

### `VSL_Decode_Frequency`

`function` | [src/vsl_dsp_logic.h:71](../../src/vsl_dsp_logic.h#L71)

```c
float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);
```

Decodes a frequency (Hz) from the DSP to a linear position [0.0, 1.0].

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `freq_hz_value` | `float` |  | Frequency in Hz read from the DSP, clamped to range. |
| `param` | `VSL_Parameter *` |  | Parameter with freq_min_hz and freq_max_hz. |

**Returns:** `float` - Linear control position [0,1]. @source Reverse-engineered from FUN_00132da8 in the Android driver.

---

<a id="vsl_final_encode_to_int"></a>

### `VSL_Final_Encode_To_Int`

`function` | [src/vsl_dsp_logic.h:81](../../src/vsl_dsp_logic.h#L81)

```c
uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param);
```

Converts an encoded float to a 16-bit integer for the DSP firmware.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `encoded_float` | `float` |  | Value from VSL_Encode_Gain or VSL_Map_Frequency. |
| `param` | `VSL_Parameter *` |  | Parameter with max_encoded_int (typically 65535). |

**Returns:** `uint16_t` - Integer value clamped to [0, max_encoded_int] ready for the USB packet.

> **Note:** The scale factor VSL_MAX_ENCODED_FLOAT (1000.0f) is a hypothesis from the DSP scaling. Validated test: 0.75 -> 40793 (full pipeline).

---

<a id="negative"></a>

### `negative`

`function` | [src/vsl_dsp_logic.h:87](../../src/vsl_dsp_logic.h#L87)

```c
* when linear_value is zero or negative (the `db.inf` domain). */ float VSL_Linear_To_DB(float linear_value);
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `domain` | `` the `db.inf` `` |  |  |

**Returns:** `* when linear_value is zero or`

---

<a id="vsl_db_to_linear"></a>

### `VSL_DB_To_Linear`

`function` | [src/vsl_dsp_logic.h:97](../../src/vsl_dsp_logic.h#L97)

```c
float VSL_DB_To_Linear(float db_value);
```

Converts a decibel gain back to linear [0.0, 1.0].

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `db_value` | `float` |  | Gain in dB. |

**Returns:** `float` - Linear gain clamped to [0.0, 1.0]; exactly 0.0 when db_value is at or below VSL_DB_NEG_INF.

*Called by:* [`main`](src.vsl_cli.c.md#main)

---

## Macros

<a id="vsl_inv_ln2"></a>

### `VSL_INV_LN2`

`macro` | [src/vsl_dsp_logic.h:8](../../src/vsl_dsp_logic.h#L8)

```c
#define VSL_INV_LN2
```

Constante para la conversión de logaritmo natural (ln) a logaritmo base 2 (log2) 1 / ln(2) ≈ 1.442695

> **Inherited:** Documentation from [`VSL_INV_LN2`](#vsl_inv_ln2) (legacy/vsl_dsp_logic.h:10).

---

<a id="vsl_max_encoded_float"></a>

### `VSL_MAX_ENCODED_FLOAT`

`macro` | [src/vsl_dsp_logic.h:9](../../src/vsl_dsp_logic.h#L9)

```c
#define VSL_MAX_ENCODED_FLOAT
```

---

<a id="vsl_db_neg_inf"></a>

### `VSL_DB_NEG_INF`

`macro` | [src/vsl_dsp_logic.h:19](../../src/vsl_dsp_logic.h#L19)

```c
#define VSL_DB_NEG_INF
```

Decibel floor below which a gain is treated as negative infinity. Mirrors the vendor Fat Channel design where `db.inf` is a dedicated parameter with its own handler, separate from the `gain.db` curve (observed in libfatchannelplugins.so, _INIT_0 registry). Any dB value at or below this floor converts to a linear value of exactly 0.0.

---

<a id="vsl_db_floor_linear"></a>

### `VSL_DB_FLOOR_LINEAR`

`macro` | [src/vsl_dsp_logic.h:20](../../src/vsl_dsp_logic.h#L20)

```c
#define VSL_DB_FLOOR_LINEAR
```

---
