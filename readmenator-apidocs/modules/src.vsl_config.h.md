# `src/vsl_config.h`

> Source: [src/vsl_config.h:1](../../src/vsl_config.h#L1) | language `h` | coverage 15.4% | [API index](../index.md)

## Contents

- **Structs:** [`VSL_ModelInfo`](#vsl_modelinfo)
- **Functions:** [`VSL_ModelLookup`](#vsl_modellookup), [`VSL_ModelLookupByTag`](#vsl_modellookupbytag)
- **Macros:** [`VSL_VENDOR_ID`](#vsl_vendor_id), [`VSL_PRODUCT_ID_22VSL`](#vsl_product_id_22vsl), [`VSL_PRODUCT_ID_44VSL`](#vsl_product_id_44vsl), [`VSL_PRODUCT_ID_1818VSL`](#vsl_product_id_1818vsl), [`VSL_REPORT_ID`](#vsl_report_id), [`VSL_PACKET_SIZE`](#vsl_packet_size), [`VSL_MIDI_IFACE`](#vsl_midi_iface), [`VSL_EP_MIDI_OUT`](#vsl_ep_midi_out), [`VSL_USB_TIMEOUT_MS`](#vsl_usb_timeout_ms)
- **Variables:** [`pid`](#pid)

## Structs

<a id="vsl_modelinfo"></a>

### `VSL_ModelInfo`

`struct` | [src/vsl_config.h:22](../../src/vsl_config.h#L22)

```c
typedef struct
```

---

## Functions

<a id="vsl_modellookup"></a>

### `VSL_ModelLookup`

`function` | [src/vsl_config.h:38](../../src/vsl_config.h#L38)

```c
static inline const VSL_ModelInfo * VSL_ModelLookup(uint16_t pid)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `pid` | `uint16_t` |  |  |

**Returns:** `VSL_ModelInfo *`

---

<a id="vsl_modellookupbytag"></a>

### `VSL_ModelLookupByTag`

`function` | [src/vsl_config.h:50](../../src/vsl_config.h#L50)

```c
static inline const VSL_ModelInfo * VSL_ModelLookupByTag(const char *tag)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `tag` | `char *` |  |  |

**Returns:** `VSL_ModelInfo *`

*Called by:* [`main`](src.vsl_cli.c.md#main)

---

## Macros

<a id="vsl_vendor_id"></a>

### `VSL_VENDOR_ID`

`macro` | [src/vsl_config.h:11](../../src/vsl_config.h#L11)

```c
#define VSL_VENDOR_ID
```

BLOQUEADORES CRÍTICOS (Hardware)

> **Inherited:** Documentation from [`VSL_VENDOR_ID`](#vsl_vendor_id) (legacy/vsl_config.h:11).

---

<a id="vsl_product_id_22vsl"></a>

### `VSL_PRODUCT_ID_22VSL`

`macro` | [src/vsl_config.h:12](../../src/vsl_config.h#L12)

```c
#define VSL_PRODUCT_ID_22VSL
```

---

<a id="vsl_product_id_44vsl"></a>

### `VSL_PRODUCT_ID_44VSL`

`macro` | [src/vsl_config.h:13](../../src/vsl_config.h#L13)

```c
#define VSL_PRODUCT_ID_44VSL
```

---

<a id="vsl_product_id_1818vsl"></a>

### `VSL_PRODUCT_ID_1818VSL`

`macro` | [src/vsl_config.h:14](../../src/vsl_config.h#L14)

```c
#define VSL_PRODUCT_ID_1818VSL
```

---

<a id="vsl_report_id"></a>

### `VSL_REPORT_ID`

`macro` | [src/vsl_config.h:16](../../src/vsl_config.h#L16)

```c
#define VSL_REPORT_ID
```

---

<a id="vsl_packet_size"></a>

### `VSL_PACKET_SIZE`

`macro` | [src/vsl_config.h:17](../../src/vsl_config.h#L17)

```c
#define VSL_PACKET_SIZE
```

FIXME blocker #2: legacy hypothesis, unverified on wire/Ghidra

---

<a id="vsl_midi_iface"></a>

### `VSL_MIDI_IFACE`

`macro` | [src/vsl_config.h:18](../../src/vsl_config.h#L18)

```c
#define VSL_MIDI_IFACE
```

---

<a id="vsl_ep_midi_out"></a>

### `VSL_EP_MIDI_OUT`

`macro` | [src/vsl_config.h:19](../../src/vsl_config.h#L19)

```c
#define VSL_EP_MIDI_OUT
```

---

<a id="vsl_usb_timeout_ms"></a>

### `VSL_USB_TIMEOUT_MS`

`macro` | [src/vsl_config.h:20](../../src/vsl_config.h#L20)

```c
#define VSL_USB_TIMEOUT_MS
```

---

## Variables

<a id="pid"></a>

### `pid`

`variable` `extern` | [src/vsl_config.h:8](../../src/vsl_config.h#L8)

```c
extern "C" { #endif #define VSL_VENDOR_ID 0x194fU #define VSL_PRODUCT_ID_22VSL 0x0101U #define VSL_PRODUCT_ID_44VSL 0x0102U #define VSL_PRODUCT_ID_1818VSL 0x0103U #define VSL_REPORT_ID 0x06U /* FIXME
```

ifdef __cplusplus

---
