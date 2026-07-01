# VSL-DSP Open Source Driver

Open source Linux kernel module for the PreSonus AudioBox VSL family
of USB audio interfaces.

The module detects any member of the AudioBox VSL family that is
plugged into the USB bus and logs the connection and disconnection to
the kernel ring buffer. It is a passive detector: it never claims the
audio interface, so the standard `snd-usb-audio` driver keeps owning
the device and ALSA playback, capture, and mixer continue to work
without re-plug. The driver is licensed under GPL-2.0-or-later.

## Supported hardware

| Model             | USB ID (vendor:product) | Bus       |
| ----------------- | ----------------------- | --------- |
| AudioBox 22 VSL   | `194f:0101`             | USB 2.0   |
| AudioBox 44 VSL   | `194f:0102`             | USB 2.0   |
| AudioBox 1818 VSL | `194f:0103`             | USB 2.0   |

The three models share the same UAC2 audio interface and the same HID
control plane. Adding support for a new product ID is a one-line
change in `audiobox_vsl.h`.

## Features

- Automatic detection of every AudioBox VSL model via USB VID/PID.
- Coexists with `snd-usb-audio` (no interface claim, no audio loss).
- Connection and disconnection logged to the kernel ring buffer.
- Optional auto-load at boot via `/etc/modules-load.d/`.
- Single source of truth in `audiobox_vsl.h` for every supported PID.
- CMocka unit test suite for the model lookup table and accessor.
- Hardening flags on every userspace test compile (`-Wall -Wextra
  -Werror -fstack-protector-strong -D_FORTIFY_SOURCE=2`).
- AddressSanitizer + UndefinedBehaviorSanitizer target (`make asan`).
- GPL-2.0-or-later.

## Requirements

- Linux kernel headers for the running kernel.
- GCC and GNU make.
- For the test suite: `libcmocka-dev` (Debian/Ubuntu/Kali).
- Root access to install and load the module.

## Quick start

### 1. Install build dependencies (one time, as root)

```sh
sudo ./install.sh
```

This installs `build-essential`, `perl`, `linux-headers-$(uname -r)`,
and (if available) `libcmocka-dev`.

### 2. Verify the build environment

```sh
./configure
```

### 3. Build the module and run the test suite

```sh
make
```

This produces `audiobox_vsl.ko` in the project directory and runs the
CMocka unit tests for the model lookup table.

### 4. Install the module

```sh
sudo make install
```

This copies the module to `/lib/modules/$(uname -r)/extra/`, runs
`depmod`, and (in a follow-up step you choose to enable) can register
it in `/etc/modules-load.d/` for automatic loading at boot.

### 5. Load the module

```sh
sudo make modprobe
```

or:

```sh
sudo modprobe audiobox_vsl
```

### 6. Verify detection

Plug in any AudioBox VSL device and watch the kernel log:

```sh
dmesg --follow | grep audiobox_vsl
```

Expected output:

```
audiobox_vsl: detected 'AudioBox 22 VSL' (194f:0101)
audiobox_vsl:   manufacturer=PreSonus Audio Electronics product=AudioBox 22 VSL serial=...
audiobox_vsl: disconnected 'AudioBox 22 VSL' (194f:0101)
```

The model name reflects the actual product ID of the plugged-in
device.

### 7. Uninstall

```sh
sudo make uninstall
```

## Test targets

```sh
make test    # build and run the CMocka unit test suite
make asan    # build and run the test suite under ASan+UBSan
make info    # print resolved build variables
make help    # list every available target
```

The test suite covers the model lookup table and accessor:
`audiobox_lookup_model(pid)` returns a pointer to the matching model
entry for every supported PID and `NULL` otherwise. The suite also
asserts that the model table is well formed: PIDs are unique, product
names are non-empty, and the count matches the array size.

## Adding a new product ID

To support another model that uses the same UAC2 control plane:

1. Add an enumerator to `audiobox_model_pid_t` in `audiobox_vsl.h`
   (for example `AUDIOBOX_MODEL_XX_VSL = 0x0104U`).
2. Append a matching entry to `audiobox_models[]` in the same file
   with the canonical product name.
3. The kernel device table in `audiobox_vsl.c` is generated from
   that single array; no other source change is required.
4. Add a unit test in `tests/test_audiobox_vsl.c` that asserts the
   new PID resolves to the new product name.

## Repository layout

```
.
├── audiobox_vsl.c                 kernel detector module
├── audiobox_vsl.h                 public interface and configuration
├── Makefile                       single source of truth for build, test, install
├── install.sh                     installs build dependencies (root only)
├── configure                      verifies the build environment
├── README.md                      this file
├── CLAUDE.md                      working contract for AI agents and maintainers
├── LICENSE                        GPL-2.0-or-later
├── spec/
│   └── audiobox_vsl.md            BDD specification for the detector
├── src/
│   ├── vsl_dsp_logic.c            userspace DSP math library
│   ├── vsl_dsp_logic.h
│   ├── vsl_dsp_transport.c        userspace HID transport
│   └── vsl_dsp_transport.h
├── tests/
│   └── test_audiobox_vsl.c        CMocka unit test suite
├── docs/                          auxiliary documentation
├── .github/                       issue and pull request templates
└── legacy/                        historical artefacts (Python PoC, DKMS
                                   installer, packet captures); see
                                   legacy/README.md
```

## How it works

`audiobox_vsl.c` registers a `struct usb_driver` whose device table
contains one entry per supported product ID. The table is built from
`audiobox_models[]` in `audiobox_vsl.h`, which is the only place
where the product IDs are listed.

When the USB core matches a device, `probe` is called. The handler:

1. Looks up the product ID with `audiobox_lookup_model()`.
2. Logs the model name, the raw VID/PID, and the USB string
   descriptors (manufacturer, product, serial) to the kernel ring
   buffer via `dev_info`.
3. Returns `-ENODEV` so the USB core does not bind the driver to the
   interface. The standard `snd-usb-audio` driver therefore remains
   the owner and ALSA continues to provide full audio functionality
   (playback, capture, mixer) without any re-plug.

When the device is unplugged, `disconnect` logs the model name and
the VID/PID and returns.

The detector never touches the HID control endpoint, never allocates
memory in the hot path, and never formats untrusted input. The
canonical product name comes from a `static const` table; the USB
string descriptors are logged verbatim by the kernel `dev_info` API
using `%s` with a NULL guard.

## License

GPL-2.0-or-later. See the `LICENSE` file for the full text.
