# `legacy/vsl_dsp_logic.c`

> Source: [legacy/vsl_dsp_logic.c:1](../../legacy/vsl_dsp_logic.c#L1) | language `c` | coverage 83.3% | [API index](../index.md)

## Contents

- **Functions:** [`VSL_Build_And_Send_Packet`](#vsl_build_and_send_packet), [`VSL_Encode_Gain`](#vsl_encode_gain), [`VSL_Map_Frequency`](#vsl_map_frequency), [`VSL_Final_Encode_To_Int`](#vsl_final_encode_to_int), [`VSL_Decode_Frequency`](#vsl_decode_frequency)

## Functions

<a id="vsl_build_and_send_packet"></a>

### `VSL_Build_And_Send_Packet`

`function` | [legacy/vsl_dsp_logic.c:4](../../legacy/vsl_dsp_logic.c#L4)

```c
void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float);
```

Declaración de la nueva función de envío

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `dsp_param_id` | `uint16_t` |  |  |
| `encoded_float` | `float` |  |  |

---

<a id="vsl_encode_gain"></a>

### `VSL_Encode_Gain`

`function` | [legacy/vsl_dsp_logic.c:11](../../legacy/vsl_dsp_logic.c#L11)

```c
float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)
```

Implementación de FUN_00132c90

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `linear_value` | `float` |  |  |
| `param` | `VSL_Parameter *` |  |  |

**Returns:** `float`

---

<a id="vsl_map_frequency"></a>

### `VSL_Map_Frequency`

`function` | [legacy/vsl_dsp_logic.c:29](../../legacy/vsl_dsp_logic.c#L29)

```c
float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)
```

Implementación de FUN_00132d00

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `linear_position` | `float` |  |  |
| `param` | `VSL_Parameter *` |  |  |

**Returns:** `float`

---

<a id="vsl_final_encode_to_int"></a>

### `VSL_Final_Encode_To_Int`

`function` | [legacy/vsl_dsp_logic.c:58](../../legacy/vsl_dsp_logic.c#L58)

```c
uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)
```

Convierte el valor codificado en float a un entero sin signo para el firmware.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `encoded_float` | `float` |  |  |
| `param` | `VSL_Parameter *` |  |  |

**Returns:** `uint32_t`

> **Note:** Basado en la hipótesis común de DSP donde el rango flotante es 0.0 - 1000.0. Si el valor real es diferente, solo se debe cambiar la constante VSL_MAX_ENCODED_FLOAT.

---

<a id="vsl_decode_frequency"></a>

### `VSL_Decode_Frequency`

`function` | [legacy/vsl_dsp_logic.c:78](../../legacy/vsl_dsp_logic.c#L78)

```c
float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)
```

Implementación de FUN_00132da8

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `freq_hz_value` | `float` |  |  |
| `param` | `VSL_Parameter *` |  |  |

**Returns:** `float`

---
