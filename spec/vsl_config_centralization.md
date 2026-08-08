# vsl_config_centralization Specification

## Module: vsl_config.h (shared userspace configuration)

### Purpose

Eliminate duplicated VID/PID/Report-ID/interface/endpoint/constants across
`vsl_dsp_transport.c`, `vsl_cli.c`, and `legacy/`. Every magic number is
exactly one location. The kernel detector (`audiobox_vsl.h`) is NOT affected;
it has its own source of truth for the USB device table.

### Context

Currently `VSL_VENDOR_ID`, `VSL_PRODUCT_ID`, and `VSL_REPORT_ID` are
copy-pasted in:
- `src/vsl_dsp_transport.c` (lines 22-24)
- `src/vsl_cli.c` (lines 23-24)
- `legacy/vsl_config.h`

The target is a single `src/vsl_config.h` that every userspace `.c` includes.

### Contract

| Symbol                  | Value    | Source                                     |
| ----------------------- | -------- | ------------------------------------------ |
| `VSL_VENDOR_ID`         | `0x194f` | `lsusb`, `audiobox_vsl.h`                  |
| `VSL_PRODUCT_ID_22VSL`  | `0x0101` | `lsusb`, `audiobox_vsl.h`                  |
| `VSL_PRODUCT_ID_44VSL`  | `0x0102` | `lsusb`, `audiobox_vsl.h`                  |
| `VSL_PRODUCT_ID_1818VSL`| `0x0103` | `lsusb`, `audiobox_vsl.h`                  |
| `VSL_REPORT_ID`         | `0x06`   | `legacy/vsl_config.h` (pending Ghidra)      |
| `VSL_PACKET_SIZE`       | `64`     | `FUN_00412345` (`0x40`)                    |
| `VSL_MIDI_IFACE`        | `4`      | USB capture analysis                       |
| `VSL_EP_MIDI_OUT`       | `0x02`   | USB capture analysis                       |
| `VSL_MAX_ENCODED_FLOAT` | `1000.0f`| Hypothesis from DSP scaling                |

### Model Map

A compile-time lookup that translates a product ID to a human-readable
model tag for the CLI:

```c
typedef struct { uint16_t pid; const char *tag; const char *name; } VSL_ModelInfo;
static const VSL_ModelInfo VSL_MODELS[] = {
    {VSL_PRODUCT_ID_22VSL,   "22vsl",   "AudioBox 22 VSL"},
    {VSL_PRODUCT_ID_44VSL,   "44vsl",   "AudioBox 44 VSL"},
    {VSL_PRODUCT_ID_1818VSL, "1818vsl", "AudioBox 1818 VSL"},
};
```

### Behavior (BDD)

#### Scenario: transport compile without local defines

```
Given vsl_dsp_transport.c includes only vsl_config.h
When the translation unit is compiled
Then VSL_VENDOR_ID, VSL_PRODUCT_ID_22VSL, VSL_REPORT_ID, VSL_PACKET_SIZE,
     VSL_MIDI_IFACE, VSL_EP_MIDI_OUT are all resolved
And no diagnostic about redefined macros is emitted
```

#### Scenario: CLI compiles without local defines

```
Given vsl_cli.c includes only vsl_config.h for hardware constants
When the translation unit is compiled
Then all VSL_ constants used by the CLI are resolved
And no duplicate definition warning is emitted
```

#### Scenario: model lookup returns correct tag

```
Given VSL_MODELS table in vsl_config.h
When VSL_ModelLookup(0x0101) is called
Then tag is "22vsl" and name is "AudioBox 22 VSL"

When VSL_ModelLookup(0x0102) is called
Then tag is "44vsl"

When VSL_ModelLookup(0x0103) is called
Then tag is "1818vsl"

When VSL_ModelLookup(0x0000) is called
Then NULL is returned
```

#### Scenario: model lookup is const and reentrant

```
Given VSL_ModelLookup is called concurrently
Then no static mutable state is used
And no allocation occurs
And the returned pointer is valid for the program lifetime
```

### Non-Goals

- Does NOT replace `audiobox_vsl.h` (kernel header with its own USB table).
- Does NOT add runtime configuration (zero syscalls, zero env vars, zero
  config files).
- Does NOT add I/O (pure compile-time constants + lookup).

### Safety

- All data is `static const`; no writable global state.
- `VSL_ModelLookup` returns `NULL` for unknown PIDs; callers check.
- Bounded scan over 3 entries.
- Header is guarded with `#ifndef VSL_CONFIG_H`.
