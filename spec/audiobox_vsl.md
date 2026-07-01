# audiobox_vsl Specification

## Module: `audiobox_vsl` (Linux kernel USB detector)

### Purpose

Detect the PreSonus AudioBox VSL family of USB audio interfaces (22 VSL,
44 VSL, 1818 VSL) and log connection and disconnection events to the
kernel ring buffer. The module is a passive detector and logger. It
never claims the USB interface: `probe` returns `-ENODEV` so the standard
`snd-usb-audio` driver owns the device and continues to provide full
audio (playback, capture, mixer) without interference.

### Supported Devices

| Model           | Product ID | Notes                                         |
| --------------- | ---------- | --------------------------------------------- |
| AudioBox 22 VSL | `0x0101`   | 2x2 USB audio interface. Reference unit.      |
| AudioBox 44 VSL | `0x0102`   | 4x4 VSL model.                                |
| AudioBox 1818 VSL | `0x0103` | 18x8 VSL model. Verified in the wild.         |

Vendor ID for the whole family is `0x194f` (PreSonus Audio Electronics).

### Public API (header `audiobox_vsl.h`)

#### `audiobox_vendor_id_t`

```c
#define AUDIOBOX_VENDOR_ID 0x194fU
```

Single source of truth for the PreSonus vendor ID.

#### `audiobox_model_pid_t`

```c
typedef enum {
    AUDIOBOX_MODEL_22_VSL   = 0x0101U,
    AUDIOBOX_MODEL_44_VSL   = 0x0102U,
    AUDIOBOX_MODEL_1818_VSL = 0x0103U,
} audiobox_model_pid_t;
```

Enumeration of every supported model. The integer value is the product
ID reported by the USB device. The enum gives a typed, named alias to
the literal `0x0101` etc., eliminating magic numbers in call sites.

#### `audiobox_model_info_t`

```c
typedef struct {
    uint16_t    pid;
    const char *product_name;
} audiobox_model_info_t;
```

Pair of a 16-bit product ID and a human readable model name. The
`product_name` is a static string literal that lives for the lifetime
of the kernel.

#### `audiobox_models[]`

```c
static const audiobox_model_info_t audiobox_models[] = { ... };
static const size_t audiobox_models_count = ...;
```

Authoritative table of supported models. Indexed by the kernel module
when matching against a `usb_device_id` and used by the test suite to
assert the configuration. The table is the single source of truth: any
new model is added here exactly once.

#### `audiobox_lookup_model(uint16_t pid)`

```c
const audiobox_model_info_t *audiobox_lookup_model(uint16_t pid);
```

Pure function (no side effects, no kernel state) that returns a pointer
to the entry in `audiobox_models[]` whose `pid` field equals `pid`, or
`NULL` if no supported model matches. Safe to call from probe context.

#### `snd_audiobox_vsl_init(struct usb_mixer_interface *mixer)`

```c
int snd_audiobox_vsl_init(struct usb_mixer_interface *mixer);
```

Optional ALSA mixer hook. Declared so the upstream
`sound/usb/mixer_quirks.c` can dispatch into AudioBox VSL specific
mixer initialization. Not used by the detector itself. Only declared
under `#ifdef __KERNEL__` because `<sound/...>` headers are not
available in userspace.

### Behavior (BDD)

#### Scenario: every supported model is detected

```
Given a USB device with vendor 0x194f and product 0x0101
When the device is plugged in
Then dev_info "audiobox_vsl: detected 'AudioBox 22 VSL' (194f:0101) ..." is logged
And probe returns -ENODEV

Given a USB device with vendor 0x194f and product 0x0102
When the device is plugged in
Then dev_info "audiobox_vsl: detected 'AudioBox 44 VSL' (194f:0102) ..." is logged
And probe returns -ENODEV

Given a USB device with vendor 0x194f and product 0x0103
When the device is plugged in
Then dev_info "audiobox_vsl: detected 'AudioBox 1818 VSL' (194f:0103) ..." is logged
And probe returns -ENODEV
```

#### Scenario: probe never claims the interface

```
Given any supported AudioBox VSL device
When probe() returns
Then snd-usb-audio is still the bound driver for the audio interface
And the device appears as an ALSA sound card
And aplay/arecord continue to work without re-plug
```

#### Scenario: unknown product from same vendor is ignored

```
Given a USB device with vendor 0x194f and product 0x9999
When the device is plugged in
Then probe is not called
And no log line is produced
```

#### Scenario: disconnect is logged

```
Given a previously detected AudioBox VSL device
When the device is unplugged
Then dev_info "audiobox_vsl: disconnected '<model>'" is logged
```

#### Scenario: model name lookup is total

```
Given the audiobox_models table
When audiobox_lookup_model is called with any of {0x0101, 0x0102, 0x0103}
Then a non-NULL pointer to the matching entry is returned
And the returned entry's product_name matches the canonical model string

When audiobox_lookup_model is called with 0x0000 or 0xFFFF
Then NULL is returned
And the function is safe to call from any context (no side effects)
```

### Safety and Security Guarantees

- **No claim of the audio interface.** `probe` returns `-ENODEV` for
  every supported PID. The standard `snd-usb-audio` driver remains the
  owner of the device. ALSA playback and capture are never disturbed
  by loading the module.
- **No dynamic allocation in the hot path.** The model table is a
  `static const` array of literals; `lookup` is a bounded linear scan
  over at most three entries.
- **Bounded loops.** `audiobox_models_count` is computed by the
  compiler (`sizeof`); no user-controlled iteration count.
- **Read-only access to the model table.** `lookup` returns a pointer
  to `const` data; callers cannot mutate the table.
- **NULL handling.** `audiobox_lookup_model` returns `NULL` for unknown
  PIDs; callers are required to check for `NULL` before dereferencing.
- **No string formatting of untrusted input in the hot path.** Probe
  logs the canonical product name from the static table, never the raw
  USB string descriptors (which can be attacker controlled).
- **No use of unsafe functions.** No `strcpy`, no `sprintf` without
  bound, no `gets`. Kernel string APIs (`snprintf`) are used where
  formatting is required.
- **GPL-2.0-or-later.** Module is licensed under GPL-2.0-or-later to
  remain compatible with the Linux kernel.

### Error Table

| Condition                               | Behavior                                   |
| --------------------------------------- | ------------------------------------------ |
| Known PID, normal hotplug               | `dev_info` line, `probe` returns `-ENODEV` |
| Known PID, normal unplug                | `dev_info` line, `disconnect` returns void |
| Unknown PID from supported vendor       | Probe never fires; no log                  |
| `audiobox_lookup_model` with bad PID    | Returns `NULL`                             |
| `audiobox_lookup_model` with `pid==0`   | Returns `NULL`                             |
| NULL `intf` in `probe` or `disconnect`  | Caller (USB core) never passes NULL        |

### Non-Goals (Out of Scope)

- ALSA mixer control registration is delegated to the optional
  `snd_audiobox_vsl_init` declaration; the detector does not implement
  mixer logic itself.
- USB-HID control of the DSP is implemented in the userspace library
  under `src/vsl_dsp_*`. The kernel module is read-only over USB.
- Reverse engineering of the UAC2 protocol, Report ID, packet layout,
  and DSP control surfaces is documented in `legacy/` and
  `spec/vsl_dsp_logic.md`; the kernel detector only needs the VID/PID.
- Power management (`suspend`/`resume`) callbacks. The detector does
  not claim the interface, so the USB core does not invoke them.
- Firmware upload. The AudioBox VSL family ships with no upgradeable
  firmware blob.

### Configuration Sources

The detector has exactly one configuration source: the `audiobox_models`
table in `audiobox_vsl.h`. The kernel device table is generated from
that table. There are no other compile-time or runtime configuration
files, environment variables, or sysfs knobs.
