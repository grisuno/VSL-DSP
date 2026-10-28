# `src/vsl_dsp_transport.h`

> Source: [src/vsl_dsp_transport.h:1](../../src/vsl_dsp_transport.h#L1) | language `h` | coverage 71.4% | [API index](../index.md)

## Contents

- **Type Aliases:** [`vsl_device_handle`](#vsl_device_handle)
- **Functions:** [`VSL_Close_Device`](#vsl_close_device), [`VSL_Probe_Device`](#vsl_probe_device), [`evidence`](#evidence), [`VSL_Build_Packet`](#vsl_build_packet), [`VSL_Send_Parameter`](#vsl_send_parameter)
- **Variables:** [`vsl_device_handle`](#vsl_device_handle)

## Type Aliases

<a id="vsl_device_handle"></a>

### `vsl_device_handle`

`type_alias` | [src/vsl_dsp_transport.h:11](../../src/vsl_dsp_transport.h#L11)

```c
typedef void* vsl_device_handle;
```

endif

---

## Functions

<a id="vsl_close_device"></a>

### `VSL_Close_Device`

`function` | [src/vsl_dsp_transport.h:26](../../src/vsl_dsp_transport.h#L26)

```c
void VSL_Close_Device(vsl_device_handle handle);
```

Release the MIDI interface and close the device.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `handle` | `vsl_device_handle` |  | Handle from VSL_Init_Device. NULL is a safe no-op. |

---

<a id="vsl_probe_device"></a>

### `VSL_Probe_Device`

`function` | [src/vsl_dsp_transport.h:40](../../src/vsl_dsp_transport.h#L40)

```c
int VSL_Probe_Device(uint16_t vendor_id, uint16_t product_id, char *out, size_t out_len);
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

---

<a id="evidence"></a>

### `evidence`

`function` | [src/vsl_dsp_transport.h:54](../../src/vsl_dsp_transport.h#L54)

```c
* evidence (blockers #2/#3);
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `blockers` |  |  |  |

**Returns:** `*`

---

<a id="vsl_build_packet"></a>

### `VSL_Build_Packet`

`function` | [src/vsl_dsp_transport.h:56](../../src/vsl_dsp_transport.h#L56)

```c
int VSL_Build_Packet(uint16_t dsp_param_id, uint16_t encoded_value, unsigned char *out);
```

Fill a VSL_PACKET_SIZE buffer with a DSP parameter datagram.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `dsp_param_id` | `uint16_t` |  | 16-bit DSP parameter identifier. |
| `encoded_value` | `uint16_t` |  | 16-bit encoded integer value. |
| `out` | `unsigned char *` |  | Caller-provided VSL_PACKET_SIZE buffer. |

**Returns:** `int` - 0 on success, negative when out is NULL (fail closed). Pure function without I/O. Byte layout (Report ID first, id/value little-endian, zero tail) is a working hypothesis pending Ghidra/usbmon evidence (blockers #2/#3); see spec/vsl_dsp_transport.md.

---

<a id="vsl_send_parameter"></a>

### `VSL_Send_Parameter`

`function` | [src/vsl_dsp_transport.h:67](../../src/vsl_dsp_transport.h#L67)

```c
int VSL_Send_Parameter(vsl_device_handle handle, uint16_t dsp_param_id, uint16_t encoded_value);
```

Send a DSP parameter value to the device via USB bulk transfer.

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `handle` | `vsl_device_handle` |  | Handle from VSL_Init_Device. |
| `dsp_param_id` | `uint16_t` |  | 16-bit DSP parameter identifier. |
| `encoded_value` | `uint16_t` |  | 16-bit encoded integer value. |

**Returns:** `int` - 0 on success, negative on error.

---

## Variables

<a id="vsl_device_handle"></a>

### `vsl_device_handle`

`variable` `extern` | [src/vsl_dsp_transport.h:9](../../src/vsl_dsp_transport.h#L9)

```c
extern "C" { #endif typedef void* vsl_device_handle;
```

ifdef __cplusplus

---
