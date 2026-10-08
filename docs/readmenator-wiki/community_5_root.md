# root

*Community 5 | 4 files | cohesion 1.00*

## Definition

This community groups 4 file(s) rooted at `root` with dominant language c (cohesion 1.00). Central symbols: `AUDIOBOX_DRIVER_DESC`, `AUDIOBOX_DRIVER_LIC`, `AUDIOBOX_DRIVER_NAME`, `AUDIOBOX_VENDOR_ID`, `AUDIOBOX_VERSION_STRING`, `AUDIOBOX_VSL_H`, `DECLARE_TLV_DB_RANGE`, `HDA_VERB_CMD`. Core file: `legacy/mixer_quirks.c` (309 symbols).

## Files

| File | Language | Layer | Symbols | Doc |
|------|----------|-------|---------|-----|
| `audiobox_vsl.c` | c | utility | 5 | yes |
| `audiobox_vsl.h` | h | utility | 9 | yes |
| `legacy/mixer_quirks.c` | c | utility | 309 | yes |
| `tests/test_audiobox_vsl.c` | c | testing | 12 | yes |

## Key Symbols

- `AUDIOBOX_DRIVER_NAME` (macro, `audiobox_vsl.c:25`) `#define AUDIOBOX_DRIVER_NAME`
- `AUDIOBOX_DRIVER_DESC` (macro, `audiobox_vsl.c:26`) `#define AUDIOBOX_DRIVER_DESC`
- `AUDIOBOX_DRIVER_LIC` (macro, `audiobox_vsl.c:27`) `#define AUDIOBOX_DRIVER_LIC`
- `audiobox_probe` (function, `audiobox_vsl.c:37`) `static int audiobox_probe(struct usb_interface *intf,`
- `audiobox_disconnect` (function, `audiobox_vsl.c:64`) `static void audiobox_disconnect(struct usb_interface *intf)`
- `AUDIOBOX_VSL_H` (macro, `audiobox_vsl.h:21`) `#define AUDIOBOX_VSL_H`
- `audiobox_model_pid_t` (variable, `audiobox_vsl.h:26`) `extern "C" { #endif /** * @brief PreSonus USB vendor ID shared by every AudioBox` - ifdef __cplusplus
- `AUDIOBOX_VENDOR_ID` (macro, `audiobox_vsl.h:32`) `#define AUDIOBOX_VENDOR_ID`
- `AUDIOBOX_VERSION_STRING` (macro, `audiobox_vsl.h:55`) `#define AUDIOBOX_VERSION_STRING`
- `audiobox_model_info_t` (struct, `audiobox_vsl.h:64`) - @brief Pair of product ID and canonical human readable model name.  The product_name field is a poin
- `audiobox_lookup_model` (function, `audiobox_vsl.h:107`) `static inline const audiobox_model_info_t * audiobox_lookup_model(uint16_t pid)`
- `audiobox_is_primary_interface` (function, `audiobox_vsl.h:131`) `static inline int audiobox_is_primary_interface(unsigned int ifnum)`
- `usb_mixer_interface` (struct, `audiobox_vsl.h:141`)
- `snd_audiobox_vsl_init` (function, `audiobox_vsl.h:150`) `int snd_audiobox_vsl_init(struct usb_mixer_interface *mixer);` - @brief ALSA mixer init hook for AudioBox VSL devices.  Optional entry point used by the upstream sou
- `std_mono_table` (struct, `legacy/mixer_quirks.c:45`)
- `snd_create_std_mono_ctl_offset` (function, `legacy/mixer_quirks.c:59`) `static int snd_create_std_mono_ctl_offset(struct usb_mixer_interface *mixer,` - This function allows for the creation of standard UAC controls. See the quirks for M-Audio FTUs or E
- `snd_create_std_mono_ctl` (function, `legacy/mixer_quirks.c:113`) `static int snd_create_std_mono_ctl(struct usb_mixer_interface *mixer, 				   uns`
- `snd_create_std_mono_table` (function, `legacy/mixer_quirks.c:129`) `static int snd_create_std_mono_table(struct usb_mixer_interface *mixer,` - Create a set of standard UAC controls from a table
- `add_single_ctl_with_resume` (function, `legacy/mixer_quirks.c:146`) `static int add_single_ctl_with_resume(struct usb_mixer_interface *mixer,`
- `rc_config` (struct, `legacy/mixer_quirks.c:181`) - Sound Blaster remote control configuration  format of remote control data: Extigy:       xx 00 Audig
- `snd_usb_soundblaster_remote_complete` (function, `legacy/mixer_quirks.c:200`) `static void snd_usb_soundblaster_remote_complete(struct urb *urb)`
- `snd_usb_sbrc_hwdep_read` (function, `legacy/mixer_quirks.c:220`) `static long snd_usb_sbrc_hwdep_read(struct snd_hwdep *hw, char __user *buf,`
- `snd_usb_sbrc_hwdep_poll` (function, `legacy/mixer_quirks.c:240`) `static __poll_t snd_usb_sbrc_hwdep_poll(struct snd_hwdep *hw, struct file *file,`
- `snd_usb_soundblaster_remote_init` (function, `legacy/mixer_quirks.c:249`) `static int snd_usb_soundblaster_remote_init(struct usb_mixer_interface *mixer)`
- `snd_audigy2nx_led_info` (macro, `legacy/mixer_quirks.c:297`) `#define snd_audigy2nx_led_info`
- `snd_audigy2nx_led_get` (function, `legacy/mixer_quirks.c:299`) `static int snd_audigy2nx_led_get(struct snd_kcontrol *kcontrol, struct snd_ctl_e`
- `snd_audigy2nx_led_update` (function, `legacy/mixer_quirks.c:305`) `static int snd_audigy2nx_led_update(struct usb_mixer_interface *mixer, 				    i`
- `snd_audigy2nx_led_put` (function, `legacy/mixer_quirks.c:334`) `static int snd_audigy2nx_led_put(struct snd_kcontrol *kcontrol, 				 struct snd_`
- `snd_audigy2nx_led_resume` (function, `legacy/mixer_quirks.c:353`) `static int snd_audigy2nx_led_resume(struct usb_mixer_elem_list *list)`
- `snd_audigy2nx_controls_create` (function, `legacy/mixer_quirks.c:375`) `static int snd_audigy2nx_controls_create(struct usb_mixer_interface *mixer)`

## Internal vs External Edges

- Internal resolved imports (EXTRACTED): 3
- Cross-boundary resolved imports (EXTRACTED): 0

## Connections

- [INFERRED] shares_context community 0 <-> 5 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 0 (voicecloak/src: vc_denoise) and community 5 (root).
- [INFERRED] shares_context community 1 <-> 5 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 1 (voicecloak/src: vc_effects) and community 5 (root).
- [INFERRED] shares_context community 2 <-> 5 (strength 0.5): Inferred shared context (layer utility) with no import path between community 2 (legacy) and community 5 (root).
- [INFERRED] shares_context community 3 <-> 5 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 3 (voicecloak/src: vc_crypto) and community 5 (root).
- [INFERRED] shares_context community 4 <-> 5 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 4 (src) and community 5 (root).
- [INFERRED] shares_context community 5 <-> 7 (strength 0.5): Inferred shared context (layer utility) with no import path between community 5 (root) and community 7 (orphans).

## Risks

- [taint medium] `legacy/mixer_quirks.c` -> `legacy/mixer_quirks.c` via `input` (0 hops)
- [taint medium] `legacy/mixer_quirks.c` -> `audiobox_vsl.h` via `input` (1 hops)
- [dataflow DEAD_STORE] `legacy/mixer_quirks.c:1547` `snd_emuusb_set_samplerate` `unitid`: `unitid` assigned at line 1547 but never read afterwards.
- [dataflow DEAD_STORE] `legacy/mixer_quirks.c:2947` `snd_bbfpro_gain_get` `value`: `value` assigned at line 2947 but never read afterwards.

## Open Questions

- Is the dangerous import `input` in `legacy/mixer_quirks.c` still required, or can it be isolated?
- What would break if the most connected file in root changed?
- Should root be split, given cohesion 1.00?

## Sources

- `audiobox_vsl.c`
- `audiobox_vsl.h`
- `legacy/mixer_quirks.c`
- `tests/test_audiobox_vsl.c`
