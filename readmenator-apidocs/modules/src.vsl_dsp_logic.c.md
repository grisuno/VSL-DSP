# `src/vsl_dsp_logic.c`

> Source: [src/vsl_dsp_logic.c:1](../../src/vsl_dsp_logic.c#L1) | language `c` | coverage 75.0% | [API index](../index.md)

## Contents

- **Functions:** [`VSL_Encode_Gain`](#vsl_encode_gain), [`VSL_Decode_Gain`](#vsl_decode_gain), [`VSL_Map_Frequency`](#vsl_map_frequency), [`VSL_Final_Encode_To_Int`](#vsl_final_encode_to_int), [`VSL_Decode_Frequency`](#vsl_decode_frequency), [`VSL_Linear_To_DB`](#vsl_linear_to_db), [`VSL_DB_To_Linear`](#vsl_db_to_linear)

## Functions

<a id="vsl_encode_gain"></a>

### `VSL_Encode_Gain`

`function` | [src/vsl_dsp_logic.c:3](../../src/vsl_dsp_logic.c#L3)

```c
float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)
```

Codifica un valor lineal (ej. 0.5) a la escala exponencial/logarítmica del DSP (Ganancia/Volumen).

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `linear_value` | `float` |  | El valor lineal de entrada (ej. la posición del slider, 0.0 a 1.0). |
| `param` | `VSL_Parameter *` |  | La estructura del parámetro con sus coeficientes. |

**Returns:** `float` - El valor codificado en formato float (listo para la conversión final a int).

> **Inherited:** Documentation from [`VSL_Encode_Gain`](#vsl_encode_gain) (legacy/vsl_dsp_logic.h:42).

---

<a id="vsl_decode_gain"></a>

### `VSL_Decode_Gain`

`function` | [src/vsl_dsp_logic.c:16](../../src/vsl_dsp_logic.c#L16)

```c
float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param)
```

Decodes an encoded gain float back to a linear position [0.0, 1.0].

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `encoded_float` | `float` |  | Value received from the DSP or produced by VSL_Encode_Gain. |
| `param` | `VSL_Parameter *` |  | Same coefficients used during encoding. |

**Returns:** `float` - Linear control position clamped to [0,1]. @source Inverse of VSL_Encode_Gain (FUN_00132c90).

> **Inherited:** Documentation from [`VSL_Decode_Gain`](#vsl_decode_gain) (src/vsl_dsp_logic.h:53).

---

<a id="vsl_map_frequency"></a>

### `VSL_Map_Frequency`

`function` | [src/vsl_dsp_logic.c:50](../../src/vsl_dsp_logic.c#L50)

```c
float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)
```

Convierte una posición lineal (ej. 0.5) a su frecuencia logarítmica (Hz) real.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `linear_position` | `float` |  | La posición lineal de entrada (0.0 a 1.0). |
| `param` | `VSL_Parameter *` |  | La estructura del parámetro con sus coeficientes. |

**Returns:** `float` - La frecuencia mapeada en Hertz (Hz).

> **Inherited:** Documentation from [`VSL_Map_Frequency`](#vsl_map_frequency) (legacy/vsl_dsp_logic.h:50).

---

<a id="vsl_final_encode_to_int"></a>

### `VSL_Final_Encode_To_Int`

`function` | [src/vsl_dsp_logic.c:66](../../src/vsl_dsp_logic.c#L66)

```c
uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)
```

Convierte el valor codificado en float a un entero sin signo para el firmware.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `encoded_float` | `float` |  | El valor float retornado por VSL_Encode_Gain o VSL_Map_Frequency. |
| `param` | `VSL_Parameter *` |  | La estructura del parámetro con la precisión máxima entera. |

**Returns:** `uint16_t` - El valor binario final (uint32_t) listo para ser enviado en el paquete DSP.

> **Note:** ESTA FUNCIÓN ES UN MARCADOR DE POSICIÓN. El factor de escala final (la fórmula interna) aún debe ser determinado con ingeniería inversa.

> **Inherited:** Documentation from [`VSL_Final_Encode_To_Int`](#vsl_final_encode_to_int) (legacy/vsl_dsp_logic.h:60).

---

<a id="vsl_decode_frequency"></a>

### `VSL_Decode_Frequency`

`function` | [src/vsl_dsp_logic.c:76](../../src/vsl_dsp_logic.c#L76)

```c
float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)
```

Decodifica una frecuencia real (Hz) del DSP a su posición lineal de control (0.0 a 1.0).

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `freq_hz_value` | `float` |  | La frecuencia real en Hertz leída del DSP. |
| `param` | `VSL_Parameter *` |  | La estructura del parámetro con sus rangos. |

**Returns:** `float` - La posición lineal (0.0 a 1.0) para actualizar el control de la GUI.

> **Inherited:** Documentation from [`VSL_Decode_Frequency`](#vsl_decode_frequency) (legacy/vsl_dsp_logic.h:73).

---

<a id="vsl_linear_to_db"></a>

### `VSL_Linear_To_DB`

`function` | [src/vsl_dsp_logic.c:95](../../src/vsl_dsp_logic.c#L95)

```c
float VSL_Linear_To_DB(float linear_value)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `linear_value` | `float` |  |  |

**Returns:** `float`

---

<a id="vsl_db_to_linear"></a>

### `VSL_DB_To_Linear`

`function` | [src/vsl_dsp_logic.c:105](../../src/vsl_dsp_logic.c#L105)

```c
float VSL_DB_To_Linear(float db_value)
```

Converts a decibel gain back to linear [0.0, 1.0].

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `db_value` | `float` |  | Gain in dB. |

**Returns:** `float` - Linear gain clamped to [0.0, 1.0]; exactly 0.0 when db_value is at or below VSL_DB_NEG_INF.

> **Inherited:** Documentation from [`VSL_DB_To_Linear`](#vsl_db_to_linear) (src/vsl_dsp_logic.h:97).

---
