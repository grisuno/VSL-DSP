# `src/vsl_dsp_transport.c`

> Source: [src/vsl_dsp_transport.c:1](../../src/vsl_dsp_transport.c#L1) | language `c` | coverage 71.4% | [API index](../index.md)

## Contents

- **Structs:** [`vsl_device`](#vsl_device)
- **Functions:** [`VSL_Init_Device`](#vsl_init_device), [`VSL_Close_Device`](#vsl_close_device), [`VSL_Probe_Device`](#vsl_probe_device), [`VSL_Build_Packet`](#vsl_build_packet), [`VSL_Send_Parameter`](#vsl_send_parameter)

## Call Graph

Solid arrows stay in this module, dashed arrows leave it.

```mermaid
flowchart LR
    n_src_vsl_dsp_transport_c__VSL_Send_Parameter(["VSL_Send_Parameter"])
    n_src_vsl_dsp_transport_c__VSL_Build_Packet(["VSL_Build_Packet"])
    n_src_vsl_dsp_transport_c__VSL_Send_Parameter --> n_src_vsl_dsp_transport_c__VSL_Build_Packet
```

## Structs

<a id="vsl_device"></a>

### `vsl_device`

`struct` | [src/vsl_dsp_transport.c:7](../../src/vsl_dsp_transport.c#L7)

```c
struct vsl_device
```

---

## Functions

<a id="vsl_init_device"></a>

### `VSL_Init_Device`

`function` | [src/vsl_dsp_transport.c:13](../../src/vsl_dsp_transport.c#L13)

```c
vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)
```

1.

Funciones de Inicialización y Cierre (¡Ambas declaradas!)

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `vendor_id` | `uint16_t` |  |  |
| `product_id` | `uint16_t` |  |  |

**Returns:** `vsl_device_handle`

> **Inherited:** Documentation from [`VSL_Init_Device`](#vsl_init_device) (legacy/vsl_dsp_transport.h:19).

---

<a id="vsl_close_device"></a>

### `VSL_Close_Device`

`function` | [src/vsl_dsp_transport.c:50](../../src/vsl_dsp_transport.c#L50)

```c
void VSL_Close_Device(vsl_device_handle handle)
```

Release the MIDI interface and close the device.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `handle` | `vsl_device_handle` |  | Handle from VSL_Init_Device. NULL is a safe no-op. |

> **Inherited:** Documentation from [`VSL_Close_Device`](#vsl_close_device) (src/vsl_dsp_transport.h:26).

---

<a id="vsl_probe_device"></a>

### `VSL_Probe_Device`

`function` | [src/vsl_dsp_transport.c:79](../../src/vsl_dsp_transport.c#L79)

```c
int VSL_Probe_Device(uint16_t vendor_id, uint16_t product_id, char *out, size_t out_len)
```

Read USB identification strings without claiming any interface.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `vendor_id` | `uint16_t` |  | USB vendor ID (typically VSL_VENDOR_ID). |
| `product_id` | `uint16_t` |  | USB product ID for the specific VSL model. |
| `out` | `char *` |  | Caller-provided buffer receiving a human-readable summary. |
| `out_len` | `size_t` |  | Size of out in bytes; must be non-zero. |

**Returns:** `int` - 0 with out populated on success, negative when out is NULL, out_len is zero, the device is absent, or a descriptor read fails. Open-only probe: never detaches or claims drivers, sends no DSP traffic. Safe to run while audio is streaming.

> **Inherited:** Documentation from [`VSL_Probe_Device`](#vsl_probe_device) (src/vsl_dsp_transport.h:40).

---

<a id="vsl_build_packet"></a>

### `VSL_Build_Packet`

`function` | [src/vsl_dsp_transport.c:145](../../src/vsl_dsp_transport.c#L145)

```c
int VSL_Build_Packet(uint16_t dsp_param_id, uint16_t encoded_value, unsigned char *out)
```

Fill a VSL_PACKET_SIZE buffer with a DSP parameter datagram.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `dsp_param_id` | `uint16_t` |  | 16-bit DSP parameter identifier. |
| `encoded_value` | `uint16_t` |  | 16-bit encoded integer value. |
| `out` | `unsigned char *` |  | Caller-provided VSL_PACKET_SIZE buffer. |

**Returns:** `int` - 0 on success, negative when out is NULL (fail closed). Pure function without I/O. Byte layout (Report ID first, id/value little-endian, zero tail) is a working hypothesis pending Ghidra/usbmon evidence (blockers #2/#3); see spec/vsl_dsp_transport.md.

> **Inherited:** Documentation from [`VSL_Build_Packet`](#vsl_build_packet) (src/vsl_dsp_transport.h:56).

*Called by:* [`VSL_Send_Parameter`](#vsl_send_parameter)

---

<a id="vsl_send_parameter"></a>

### `VSL_Send_Parameter`

`function` | [src/vsl_dsp_transport.c:162](../../src/vsl_dsp_transport.c#L162)

```c
int VSL_Send_Parameter(vsl_device_handle handle, uint16_t dsp_param_id, uint16_t encoded_value)
```

Send a DSP parameter value to the device via USB bulk transfer.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `handle` | `vsl_device_handle` |  | Handle from VSL_Init_Device. |
| `dsp_param_id` | `uint16_t` |  | 16-bit DSP parameter identifier. |
| `encoded_value` | `uint16_t` |  | 16-bit encoded integer value. |

**Returns:** `int` - 0 on success, negative on error.

> **Inherited:** Documentation from [`VSL_Send_Parameter`](#vsl_send_parameter) (src/vsl_dsp_transport.h:67).

*Calls:* [`VSL_Build_Packet`](#vsl_build_packet)

---
