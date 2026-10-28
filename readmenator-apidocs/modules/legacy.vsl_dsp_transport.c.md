# `legacy/vsl_dsp_transport.c`

> Source: [legacy/vsl_dsp_transport.c:1](../../legacy/vsl_dsp_transport.c#L1) | language `c` | coverage 83.3% | [API index](../index.md)

vsl_dsp_transport.c (Añadir la Plantilla B completa aquí)   Handle de Singleton (Regla #5: Diseño Escalable)

## Contents

- **Functions:** [`VSL_Init_Device`](#vsl_init_device), [`VSL_Close_Device`](#vsl_close_device), [`VSL_Get_Device_Handle`](#vsl_get_device_handle), [`FUN_Send_Packet`](#fun_send_packet), [`VSL_Build_And_Send_Packet`](#vsl_build_and_send_packet)

## Call Graph

Solid arrows stay in this module, dashed arrows leave it.

```mermaid
flowchart LR
    n_legacy_vsl_dsp_transport_c__FUN_Send_Packet(["FUN_Send_Packet"])
    n_legacy_vsl_dsp_transport_c__VSL_Get_Device_Handle(["VSL_Get_Device_Handle"])
    n_legacy_vsl_dsp_transport_c__VSL_Build_And_Send_Packet(["VSL_Build_And_Send_Packet"])
    n_legacy_vsl_dsp_transport_c__FUN_Send_Packet --> n_legacy_vsl_dsp_transport_c__VSL_Get_Device_Handle
    n_legacy_vsl_dsp_transport_c__VSL_Build_And_Send_Packet --> n_legacy_vsl_dsp_transport_c__FUN_Send_Packet
```

## Functions

<a id="vsl_init_device"></a>

### `VSL_Init_Device`

`function` | [legacy/vsl_dsp_transport.c:23](../../legacy/vsl_dsp_transport.c#L23)

```c
int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)
```

1.

Funciones de Inicialización y Cierre (¡Ambas declaradas!)

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `vendor_id` | `uint16_t` |  |  |
| `product_id` | `uint16_t` |  |  |

**Returns:** `int`

> **Inherited:** Documentation from [`VSL_Init_Device`](#vsl_init_device) (legacy/vsl_dsp_transport.h:19).

---

<a id="vsl_close_device"></a>

### `VSL_Close_Device`

`function` | [legacy/vsl_dsp_transport.c:70](../../legacy/vsl_dsp_transport.c#L70)

```c
void VSL_Close_Device(void)
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

`function` | [legacy/vsl_dsp_transport.c:79](../../legacy/vsl_dsp_transport.c#L79)

```c
hid_device* VSL_Get_Device_Handle(void)
```

**Returns:** `hid_device*`

*Called by:* [`FUN_Send_Packet`](#fun_send_packet)

---

<a id="fun_send_packet"></a>

### `FUN_Send_Packet`

`function` | [legacy/vsl_dsp_transport.c:97](../../legacy/vsl_dsp_transport.c#L97)

```c
void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length)
```

Función de I/O real usando HIDAPI.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `packet` | `VSL_DSP_Packet *` |  |  |
| `packet_length` | `size_t` |  |  |

> **Note:** DEBE SER REEMPLAZADA con la lógica específica de tu dispositivo (Report ID, longitud, etc.)

*Calls:* [`VSL_Get_Device_Handle`](#vsl_get_device_handle)

*Called by:* [`VSL_Build_And_Send_Packet`](#vsl_build_and_send_packet)

---

<a id="vsl_build_and_send_packet"></a>

### `VSL_Build_And_Send_Packet`

`function` | [legacy/vsl_dsp_transport.c:140](../../legacy/vsl_dsp_transport.c#L140)

```c
void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float)
```

Implementación de la función de construcción y envío

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `dsp_param_id` | `uint16_t` |  |  |
| `encoded_float` | `float` |  |  |

*Calls:* [`FUN_Send_Packet`](#fun_send_packet)

---
