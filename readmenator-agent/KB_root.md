# Subsystem: root

## audiobox_vsl.c
- Layer: infrastructure
- Doc: SPDX-License-Identifier: GPL-2.0-or-later
- Language: c
- Symbols:
  - `audiobox_probe` (function, line 36) `static int audiobox_probe(struct usb_interface *intf,
                          const struct usb_...`
  - `audiobox_disconnect` (function, line 58) `static void audiobox_disconnect(struct usb_interface *intf)`
  - `dev_info` (function, line 47) `dev_info(&intf->dev, "audiobox_vsl: detected '%s' (%04x:%04x)\n", name, le16_to_cpu(udev->descriptor.idVendor), pid);`
  - `module_usb_driver` (function, line 78) `module_usb_driver(audiobox_driver);`
  - `MODULE_LICENSE` (function, line 80) `MODULE_LICENSE(AUDIOBOX_DRIVER_LIC);`
  - `AUDIOBOX_DRIVER_NAME` (macro, line 24) `#define AUDIOBOX_DRIVER_NAME`
  - `AUDIOBOX_DRIVER_DESC` (macro, line 26) `#define AUDIOBOX_DRIVER_DESC`
  - `AUDIOBOX_DRIVER_LIC` (macro, line 27) `#define AUDIOBOX_DRIVER_LIC`
- Depends on: `audiobox_vsl.h`

## audiobox_vsl.h
- Layer: infrastructure
- Doc: SPDX-License-Identifier: GPL-2.0-or-later
- Language: h
- Symbols:
  - `usb_mixer_interface` (struct, line 113)
  - `audiobox_model_info_t` (struct, line 53)
  - `audiobox_lookup_model` (function, line 95) `static inline const audiobox_model_info_t *
audiobox_lookup_model(uint16_t pid)`
  - `snd_audiobox_vsl_init` (function, line 122) `int snd_audiobox_vsl_init(struct usb_mixer_interface *mixer);`
  - `audiobox_model_pid_t` (variable, line 26) `extern "C" { #endif /** * @brief PreSonus USB vendor ID shared by every AudioBox VSL model. */ #define AUDIOBOX_VENDOR_ID 0x194fU /** * @brief Product IDs of the AudioBox VSL family. * * The enumerato`
  - `AUDIOBOX_VSL_H` (macro, line 21) `#define AUDIOBOX_VSL_H`
  - `AUDIOBOX_VENDOR_ID` (macro, line 32) `#define AUDIOBOX_VENDOR_ID`
- Imported by: `audiobox_vsl.c`, `legacy/mixer_quirks.c`, `tests/test_audiobox_vsl.c`

## install.sh
- Layer: utility
- Doc: SPDX-License-Identifier: GPL-2.0-or-later Thin wrapper that installs the build-time dependencies for the audiobox_vsl ke
- Language: sh
