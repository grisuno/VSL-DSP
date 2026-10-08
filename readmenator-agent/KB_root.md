# Subsystem: root

## audiobox_vsl.c
- Layer: utility
- Language: c
- Symbols:
  - `audiobox_probe` (function, line 37) `static int audiobox_probe(struct usb_interface *intf,
                           const struct usb...`
  - `audiobox_disconnect` (function, line 64) `static void audiobox_disconnect(struct usb_interface *intf)`
  - `AUDIOBOX_DRIVER_NAME` (macro, line 25) `#define AUDIOBOX_DRIVER_NAME`
  - `AUDIOBOX_DRIVER_DESC` (macro, line 26) `#define AUDIOBOX_DRIVER_DESC`
  - `AUDIOBOX_DRIVER_LIC` (macro, line 27) `#define AUDIOBOX_DRIVER_LIC`
- Depends on: `audiobox_vsl.h`

## audiobox_vsl.h
- Doc: audiobox_model_info_t: @brief Pair of product ID and canonical human readable model name.
- Layer: utility
- Language: h
- Symbols:
  - `usb_mixer_interface` (struct, line 141)
  - `audiobox_model_info_t` (struct, line 64)
  - `audiobox_lookup_model` (function, line 107) `static inline const audiobox_model_info_t *
audiobox_lookup_model(uint16_t pid)`
  - `audiobox_is_primary_interface` (function, line 131) `static inline int
audiobox_is_primary_interface(unsigned int ifnum)`
  - `snd_audiobox_vsl_init` (function, line 150) `int snd_audiobox_vsl_init(struct usb_mixer_interface *mixer);`
  - `audiobox_model_pid_t` (variable, line 26) `extern "C" { #endif /** * @brief PreSonus USB vendor ID shared by every AudioBox VSL model. */ #define...`
  - `AUDIOBOX_VSL_H` (macro, line 21) `#define AUDIOBOX_VSL_H`
  - `AUDIOBOX_VENDOR_ID` (macro, line 32) `#define AUDIOBOX_VENDOR_ID`
  - `AUDIOBOX_VERSION_STRING` (macro, line 55) `#define AUDIOBOX_VERSION_STRING`
- Imported by: `audiobox_vsl.c`, `legacy/mixer_quirks.c`, `tests/test_audiobox_vsl.c`

## install.sh
- Layer: utility
- Language: sh
