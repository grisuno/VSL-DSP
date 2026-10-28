# `legacy/vsl_dsp_logic.h`

> Source: [legacy/vsl_dsp_logic.h:1](../../legacy/vsl_dsp_logic.h#L1) | language `h` | coverage 85.7% | [API index](../index.md)

## Contents

- **Structs:** [`VSL_Parameter`](#vsl_parameter)
- **Functions:** [`VSL_Encode_Gain`](#vsl_encode_gain), [`VSL_Map_Frequency`](#vsl_map_frequency), [`VSL_Final_Encode_To_Int`](#vsl_final_encode_to_int), [`VSL_Decode_Frequency`](#vsl_decode_frequency)
- **Macros:** [`VSL_INV_LN2`](#vsl_inv_ln2)

## Structs

<a id="vsl_parameter"></a>

### `VSL_Parameter`

`struct` | [legacy/vsl_dsp_logic.h:13](../../legacy/vsl_dsp_logic.h#L13)

```c
typedef struct
```

Estructura que almacena todos los coeficientes precalculados del DSP

---

## Functions

<a id="vsl_encode_gain"></a>

### `VSL_Encode_Gain`

`function` | [legacy/vsl_dsp_logic.h:42](../../legacy/vsl_dsp_logic.h#L42)

```c
float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);
```

Codifica un valor lineal (ej. 0.5) a la escala exponencial/logarítmica del DSP (Ganancia/Volumen).

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `linear_value` | `float` |  | El valor lineal de entrada (ej. la posición del slider, 0.0 a 1.0). |
| `param` | `VSL_Parameter *` |  | La estructura del parámetro con sus coeficientes. |

**Returns:** `float` - El valor codificado en formato float (listo para la conversión final a int).

*Called by:* [`main`](legacy.main.c.md#main)

---

<a id="vsl_map_frequency"></a>

### `VSL_Map_Frequency`

`function` | [legacy/vsl_dsp_logic.h:50](../../legacy/vsl_dsp_logic.h#L50)

```c
float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);
```

Convierte una posición lineal (ej. 0.5) a su frecuencia logarítmica (Hz) real.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `linear_position` | `float` |  | La posición lineal de entrada (0.0 a 1.0). |
| `param` | `VSL_Parameter *` |  | La estructura del parámetro con sus coeficientes. |

**Returns:** `float` - La frecuencia mapeada en Hertz (Hz).

*Called by:* [`main`](legacy.main.c.md#main)

---

<a id="vsl_final_encode_to_int"></a>

### `VSL_Final_Encode_To_Int`

`function` | [legacy/vsl_dsp_logic.h:60](../../legacy/vsl_dsp_logic.h#L60)

```c
uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param);
```

Convierte el valor codificado en float a un entero sin signo para el firmware.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `encoded_float` | `float` |  | El valor float retornado por VSL_Encode_Gain o VSL_Map_Frequency. |
| `param` | `VSL_Parameter *` |  | La estructura del parámetro con la precisión máxima entera. |

**Returns:** `uint32_t` - El valor binario final (uint32_t) listo para ser enviado en el paquete DSP.

> **Note:** ESTA FUNCIÓN ES UN MARCADOR DE POSICIÓN. El factor de escala final (la fórmula interna) aún debe ser determinado con ingeniería inversa.

*Called by:* [`main`](legacy.main.c.md#main)

---

<a id="vsl_decode_frequency"></a>

### `VSL_Decode_Frequency`

`function` | [legacy/vsl_dsp_logic.h:73](../../legacy/vsl_dsp_logic.h#L73)

```c
float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);
```

Decodifica una frecuencia real (Hz) del DSP a su posición lineal de control (0.0 a 1.0).

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `freq_hz_value` | `float` |  | La frecuencia real en Hertz leída del DSP. |
| `param` | `VSL_Parameter *` |  | La estructura del parámetro con sus rangos. |

**Returns:** `float` - La posición lineal (0.0 a 1.0) para actualizar el control de la GUI.

*Called by:* [`main`](legacy.main.c.md#main)

---

## Macros

<a id="vsl_inv_ln2"></a>

### `VSL_INV_LN2`

`macro` | [legacy/vsl_dsp_logic.h:10](../../legacy/vsl_dsp_logic.h#L10)

```c
#define VSL_INV_LN2
```

Constante para la conversión de logaritmo natural (ln) a logaritmo base 2 (log2) 1 / ln(2) ≈ 1.442695

---
