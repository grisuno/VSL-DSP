# Subsystem: root

## audiobox_vsl.c
- Layer: infrastructure
- Doc: SPDX-License-Identifier: GPL-2.0-or-later
- Language: c
- Symbols:
  - `audiobox_probe` (function, line 36) `static int audiobox_probe(struct usb_interface *intf,
                          const struct usb_...`
  - `audiobox_disconnect` (function, line 58) `static void audiobox_disconnect(struct usb_interface *intf)`
  - `AUDIOBOX_DRIVER_NAME` (macro, line 24)
  - `AUDIOBOX_DRIVER_DESC` (macro, line 26)
  - `AUDIOBOX_DRIVER_LIC` (macro, line 27)

## audiobox_vsl.h
- Layer: infrastructure
- Doc: SPDX-License-Identifier: GPL-2.0-or-later
- Language: h
- Symbols:
  - `usb_mixer_interface` (struct, line 113)
  - `audiobox_lookup_model` (function, line 95) `static inline const audiobox_model_info_t *
audiobox_lookup_model(uint16_t pid)`
  - `AUDIOBOX_VSL_H` (macro, line 21)
  - `AUDIOBOX_VENDOR_ID` (macro, line 32)

## install.sh
- Layer: utility
- Doc: SPDX-License-Identifier: GPL-2.0-or-later Thin wrapper that installs the build-time dependencies for the audiobox_vsl ke
- Language: sh
