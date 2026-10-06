# VSL DSP Transport Specification

## Module: vsl_dsp_transport

### Purpose
Own the userspace USB path that carries an already-encoded DSP parameter
value to the AudioBox VSL device. Pure packet layout lives in
`VSL_Build_Packet` (no I/O, directly unit testable); libusb orchestration
(`VSL_Init_Device`, `VSL_Close_Device`, `VSL_Send_Parameter`) only wires the
pure builder to the bulk endpoint. The kernel detector (`.ko`) never sends;
all control traffic stays in userspace.

### Hardware evidence (AudioBox 22 VSL, 194f:0101, verified 2026-10-06)
- `lsusb -v`: interface 4 is Audio / MIDI Streaming with EP 2 OUT bulk
  (`0x02`, wMaxPacketSize 512) and EP 3 IN bulk (`0x83`). No HID interface
  exists on the device (`usbhid-dump -m 194f`: no matching HID interfaces),
  so the control plane is MIDI bulk, not HID.
- Interface 5 is Application Specific / Device Firmware Update, not DSP.
- `VSL_MIDI_IFACE = 4` and `VSL_EP_MIDI_OUT = 0x02` in `src/vsl_config.h`
  match the descriptor above. Single source of truth stays in that header.
- `snd-usb-audio` keeps owning audio while the detector module is loaded
  (`aplay -l` shows card 2 VSL with playback and capture, mixer controls
  `Mic` and `AudioBox 22 VSL Output` present). Non-interference holds.

### Functions

#### VSL_Build_Packet
- **Description**: Fill a caller-provided `VSL_PACKET_SIZE` buffer with the
  DSP parameter datagram. Pure function, no I/O.
- **Inputs**:
  - `dsp_param_id`: uint16_t DSP parameter identifier.
  - `encoded_value`: uint16_t encoded integer from `VSL_Final_Encode_To_Int`.
  - `out`: pointer to a `VSL_PACKET_SIZE` byte buffer.
- **Output**: 0 on success, negative on error.
- **Error handling**:
  - `out == NULL` returns -1 and writes nothing (fail closed).
- **Layout hypothesis** (unverified on the wire, blockers #2/#3):
  - `out[0]` = `VSL_REPORT_ID`, bytes 1-2 = param id little-endian,
    bytes 3-4 = value little-endian, bytes 5-63 = zero.
  - Endianness and Report ID are working hypotheses from the legacy PoC,
    not disassembly facts. A Ghidra pass over `FUN_00412345` (via the
    `ghidramcp` lazyaddon or `rea --provider ghidra` with Ghidra 12.1.4 +
    JDK 21) or a usbmon capture during a vendor-app control move must
    confirm them before Phase 5 closes.

#### VSL_Init_Device
- **Inputs**: `vendor_id`, `product_id` (typically `VSL_VENDOR_ID` + model PID).
- **Output**: opaque handle on success, NULL on any failure.
- **Error handling** (fail closed): `malloc`, `libusb_init`, device open, or
  interface claim failure releases everything acquired and returns NULL.
  A failed claim is never reported as success.

#### VSL_Close_Device
- **Inputs**: handle from `VSL_Init_Device`; NULL is a safe no-op.
- **Guarantee**: every `malloc`/`libusb_open` has its idempotent releaser.

#### VSL_Send_Parameter
- **Inputs**: handle, `dsp_param_id`, `encoded_value`.
- **Output**: 0 on success, negative on error.
- **Error handling**: NULL handle (or closed inner handle) returns -1;
  bulk failure returns -1; a short transfer
  (`transferred != VSL_PACKET_SIZE`) returns -1 instead of success.
- **Timeout**: `VSL_USB_TIMEOUT_MS` (single named constant, no magic number).

### Error table
| Condition | Result |
| --------- | ------ |
| `VSL_Build_Packet(..., NULL)` | -1, no write |
| `VSL_Init_Device` claim fails | NULL, all resources released |
| `VSL_Send_Parameter(NULL, ...)` | -1 |
| bulk error or short write | -1 |

### Non-goals
- No DSP math here (lives in `vsl_dsp_logic.c`, already tested).
- No kernel code, no audio streaming, no mixer ioctls.
- No invented Report ID, endianness, or param-id database; unknowns stay
  marked `FIXME` with the blocker number until Ghidra/usbmon evidence lands.

### BDD scenarios
- Given a 64-byte buffer, when `VSL_Build_Packet(0x1A01, 0x9F69, buf)` runs,
  then it returns 0, `buf[0] == VSL_REPORT_ID`, and bytes 1-4 hold the
  little-endian id/value pairs with the tail zeroed.
- Given NULL output, when `VSL_Build_Packet` runs, then it returns -1.
- Given a failed interface claim, when `VSL_Init_Device` runs, then it
  returns NULL with no leaked handle.
- Given a short bulk write, when `VSL_Send_Parameter` runs, then it
  returns -1 (covered by code review: libusb I/O needs hardware fault
  injection, pending a mock harness).

### Source of constants
- VID/PIDs, MIDI iface, EP address: `lsusb -v -d 194f:0101` (this spec).
- `VSL_PACKET_SIZE = 64 (0x40)`: disassembly `FUN_00412345`, wire-unverified.
- `VSL_REPORT_ID = 0x06`: legacy PoC hypothesis, wire-unverified (blocker #2).
- Param ids in `vsl_cli list` (e.g. gain `0x1A01`, HPF `0x2B05`): CLI table,
  pending per-parameter Ghidra/usbmon confirmation (Phase 6).
