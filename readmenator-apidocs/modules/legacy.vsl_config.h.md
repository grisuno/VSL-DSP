# `legacy/vsl_config.h`

> Source: [legacy/vsl_config.h:1](../../legacy/vsl_config.h#L1) | language `h` | coverage 62.5% | [API index](../index.md)

vsl_config.h (VERSION CORREGIDA)    ======================================================= BLOQUEADORES CRÍTICOS (Hardware) =======================================================  ======================================================= CONSTANTES CRÍTICAS VSL-DSP (Necesarias para la lógica) =======================================================  Factor de escala usado en la fórmula VSL (Confirmado en la PoC Python)  Máximo valor codificado de 16 bits (0xFFFF)

## Contents

- **Macros:** [`VSL_VENDOR_ID`](#vsl_vendor_id), [`VSL_PRODUCT_ID`](#vsl_product_id), [`VSL_REPORT_ID`](#vsl_report_id), [`VSL_SCALE_FACTOR`](#vsl_scale_factor), [`VSL_MAX_ENCODED_INT`](#vsl_max_encoded_int), [`VSL_PACKET_SIZE`](#vsl_packet_size), [`VSL_PAYLOAD_SIZE`](#vsl_payload_size)

## Macros

<a id="vsl_vendor_id"></a>

### `VSL_VENDOR_ID`

`macro` | [legacy/vsl_config.h:11](../../legacy/vsl_config.h#L11)

```c
#define VSL_VENDOR_ID
```

BLOQUEADORES CRÍTICOS (Hardware)

---

<a id="vsl_product_id"></a>

### `VSL_PRODUCT_ID`

`macro` | [legacy/vsl_config.h:12](../../legacy/vsl_config.h#L12)

```c
#define VSL_PRODUCT_ID
```

---

<a id="vsl_report_id"></a>

### `VSL_REPORT_ID`

`macro` | [legacy/vsl_config.h:13](../../legacy/vsl_config.h#L13)

```c
#define VSL_REPORT_ID
```

---

<a id="vsl_scale_factor"></a>

### `VSL_SCALE_FACTOR`

`macro` | [legacy/vsl_config.h:20](../../legacy/vsl_config.h#L20)

```c
#define VSL_SCALE_FACTOR
```

Factor de escala usado en la fórmula VSL (Confirmado en la PoC Python)

---

<a id="vsl_max_encoded_int"></a>

### `VSL_MAX_ENCODED_INT`

`macro` | [legacy/vsl_config.h:23](../../legacy/vsl_config.h#L23)

```c
#define VSL_MAX_ENCODED_INT
```

Máximo valor codificado de 16 bits (0xFFFF)

---

<a id="vsl_packet_size"></a>

### `VSL_PACKET_SIZE`

`macro` | [legacy/vsl_config.h:25](../../legacy/vsl_config.h#L25)

```c
#define VSL_PACKET_SIZE
```

FIXME blocker #2: legacy hypothesis, unverified on wire/Ghidra

> **Inherited:** Documentation from [`VSL_PACKET_SIZE`](#vsl_packet_size) (src/vsl_config.h:17).

---

<a id="vsl_payload_size"></a>

### `VSL_PAYLOAD_SIZE`

`macro` | [legacy/vsl_config.h:26](../../legacy/vsl_config.h#L26)

```c
#define VSL_PAYLOAD_SIZE
```

---
