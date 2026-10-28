# `legacy/vsl_dsp_transport.h`

> Source: [legacy/vsl_dsp_transport.h:1](../../legacy/vsl_dsp_transport.h#L1) | language `h` | coverage 71.4% | [API index](../index.md)

vsl_dsp_transport.h (CORREGIDO)    Estructura de Paquete: Sin 'header' (lo quitaste en la estructura typedef)

## Contents

- **Structs:** [`VSL_DSP_Packet`](#vsl_dsp_packet)
- **Functions:** [`VSL_Init_Device`](#vsl_init_device), [`VSL_Close_Device`](#vsl_close_device), [`VSL_Get_Device_Handle`](#vsl_get_device_handle), [`FUN_Send_Packet`](#fun_send_packet), [`VSL_Build_And_Send_Packet`](#vsl_build_and_send_packet)

## Structs

<a id="vsl_dsp_packet"></a>

### `VSL_DSP_Packet`

`struct` | [legacy/vsl_dsp_transport.h:12](../../legacy/vsl_dsp_transport.h#L12)

```c
typedef struct
```

Estructura de Paquete: Sin 'header' (lo quitaste en la estructura typedef)

---

## Functions

<a id="vsl_init_device"></a>

### `VSL_Init_Device`

`function` | [legacy/vsl_dsp_transport.h:19](../../legacy/vsl_dsp_transport.h#L19)

```c
int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id);
```

1.

Funciones de Inicialización y Cierre (¡Ambas declaradas!)

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `vendor_id` | `uint16_t` |  |  |
| `product_id` | `uint16_t` |  |  |

**Returns:** `int`

---

<a id="vsl_close_device"></a>

### `VSL_Close_Device`

`function` | [legacy/vsl_dsp_transport.h:20](../../legacy/vsl_dsp_transport.h#L20)

```c
void VSL_Close_Device(void);
```

Release the MIDI interface and close the device.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `handle` |  |  | Handle from VSL_Init_Device. NULL is a safe no-op. |

> **Inherited:** Documentation from [`VSL_Close_Device`](#vsl_close_device) (src/vsl_dsp_transport.h:26).

---

<a id="vsl_get_device_handle"></a>

### `VSL_Get_Device_Handle`

`function` | [legacy/vsl_dsp_transport.h:21](../../legacy/vsl_dsp_transport.h#L21)

```c
hid_device* VSL_Get_Device_Handle(void);
```

**Returns:** `hid_device*`

---

<a id="fun_send_packet"></a>

### `FUN_Send_Packet`

`function` | [legacy/vsl_dsp_transport.h:24](../../legacy/vsl_dsp_transport.h#L24)

```c
void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length);
```

2.

Funciones de Envío

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `packet` | `VSL_DSP_Packet *` |  |  |
| `packet_length` | `size_t` |  |  |

---

<a id="vsl_build_and_send_packet"></a>

### `VSL_Build_And_Send_Packet`

`function` | [legacy/vsl_dsp_transport.h:25](../../legacy/vsl_dsp_transport.h#L25)

```c
void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float);
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `dsp_param_id` | `uint16_t` |  |  |
| `encoded_float` | `float` |  |  |

*Called by:* [`main`](legacy.main.c.md#main)

---
