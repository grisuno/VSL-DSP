# `legacy.vsl_core`

> Source: [legacy/vsl_core.py:1](../../legacy/vsl_core.py#L1) | language `py` | coverage 100.0% | [API index](../index.md)

VSL-DSP Core Logic Module Implementa las funciones matemáticas de encoding/decoding.

Traducción 1:1 del código C desensamblado.

## Contents

- **Functions:** [`vsl_encode_gain`](#vsl_encode_gain), [`vsl_map_frequency`](#vsl_map_frequency), [`vsl_final_encode_to_int`](#vsl_final_encode_to_int), [`vsl_decode_frequency`](#vsl_decode_frequency), [`validate_parameter`](#validate_parameter)

## Functions

<a id="vsl_encode_gain"></a>

### `vsl_encode_gain`

`function` | [legacy/vsl_core.py:16](../../legacy/vsl_core.py#L16)

```python
def vsl_encode_gain(linear_value: float, param: VSLParameter) -> float
```

Traducción de FUN_00132c90 (VSL_Encode_Gain en C).

Convierte un valor lineal (0.0 - 1.0) a la escala exponencial del DSP.

Fórmula:
    encoded = coeff_offset_A + coeff_C1 * exp(norm_factor * log_factor)

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `linear_value` | `float` |  | Valor lineal de entrada (0.0 a 1.0) |
| `param` | `VSLParameter` |  | Estructura de parámetros con coeficientes |

**Returns:** `float` - Valor codificado en float (rango: ~-10.0 a ~1000.0)

**Raises**

- `ValueError`: Si param es inválido

*Called by:* [`run_full_workflow`](legacy.vsl_poc_main.py.md#run_full_workflow), [`test_edge_cases`](legacy.vsl_poc_main.py.md#test_edge_cases), [`test_gain_encoding`](legacy.vsl_poc_main.py.md#test_gain_encoding), [`test_packet_construction`](legacy.vsl_poc_main.py.md#test_packet_construction)

---

<a id="vsl_map_frequency"></a>

### `vsl_map_frequency`

`function` | [legacy/vsl_core.py:58](../../legacy/vsl_core.py#L58)

```python
def vsl_map_frequency(linear_position: float, param: VSLParameter) -> float
```

Traducción de FUN_00132d00 (VSL_Map_Frequency en C).

Convierte una posición lineal (0.0 - 1.0) a frecuencia logarítmica (Hz).

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `linear_position` | `float` |  | Posición lineal (0.0 a 1.0) |
| `param` | `VSLParameter` |  | Estructura de parámetros con rangos de frecuencia |

**Returns:** `float` - Frecuencia en Hz (ej: 20.0 a 20000.0)

**Raises**

- `ValueError`: Si las frecuencias son inválidas

*Called by:* [`test_edge_cases`](legacy.vsl_poc_main.py.md#test_edge_cases), [`test_frequency_mapping`](legacy.vsl_poc_main.py.md#test_frequency_mapping)

---

<a id="vsl_final_encode_to_int"></a>

### `vsl_final_encode_to_int`

`function` | [legacy/vsl_core.py:94](../../legacy/vsl_core.py#L94)

```python
def vsl_final_encode_to_int(encoded_float: float, param: VSLParameter) -> int
```

Traducción de VSL_Final_Encode_To_Int en C.

Convierte el valor codificado float a entero de 16-bit para el DSP.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `encoded_float` | `float` |  | Valor float codificado (ej: -10.0 a 1000.0) |
| `param` | `VSLParameter` |  | Estructura de parámetros con max_encoded_int |

**Returns:** `int` - Valor entero (0 a 65535)

**Raises**

- `ValueError`: (raised in the body, not documented)

*Called by:* [`run_full_workflow`](legacy.vsl_poc_main.py.md#run_full_workflow), [`test_edge_cases`](legacy.vsl_poc_main.py.md#test_edge_cases), [`test_gain_encoding`](legacy.vsl_poc_main.py.md#test_gain_encoding), [`test_packet_construction`](legacy.vsl_poc_main.py.md#test_packet_construction)

---

<a id="vsl_decode_frequency"></a>

### `vsl_decode_frequency`

`function` | [legacy/vsl_core.py:127](../../legacy/vsl_core.py#L127)

```python
def vsl_decode_frequency(freq_hz_value: float, param: VSLParameter) -> float
```

Traducción de FUN_00132da8 (VSL_Decode_Frequency en C).

Convierte una frecuencia real (Hz) a su posición lineal (0.0 - 1.0).

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `freq_hz_value` | `float` |  | Frecuencia en Hz |
| `param` | `VSLParameter` |  | Estructura de parámetros con rangos |

**Returns:** `float` - Posición lineal (0.0 a 1.0)

**Raises**

- `ValueError`: Si las frecuencias son inválidas

*Called by:* [`test_frequency_mapping`](legacy.vsl_poc_main.py.md#test_frequency_mapping)

---

<a id="validate_parameter"></a>

### `validate_parameter`

`function` | [legacy/vsl_core.py:170](../../legacy/vsl_core.py#L170)

```python
def validate_parameter(param: VSLParameter) -> tuple[bool, str]
```

Valida la integridad de un VSLParameter.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `param` | `VSLParameter` |  |  |

**Returns:** `tuple[bool, str]` - (is_valid, error_message)

---
