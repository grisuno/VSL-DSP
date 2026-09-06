# API

## audiobox_vsl.c

### audiobox_probe `static int audiobox_probe(struct usb_interface *intf,
                          const struct usb_...`
- Defined: `audiobox_vsl.c:36`

### audiobox_disconnect `static void audiobox_disconnect(struct usb_interface *intf)`
- Defined: `audiobox_vsl.c:58`

## audiobox_vsl.h

### audiobox_lookup_model `static inline const audiobox_model_info_t *
audiobox_lookup_model(uint16_t pid)`
- Defined: `audiobox_vsl.h:95`
- Doc: @brief Look up the model info entry for a given USB product ID.  @param pid 16-bit product ID reported by the USB device

## legacy/build-dkms.sh

### print_header
- Defined: `legacy/build-dkms.sh:40`

### print_success
- Defined: `legacy/build-dkms.sh:48`

### print_error
- Defined: `legacy/build-dkms.sh:52`

### print_warning
- Defined: `legacy/build-dkms.sh:56`

### print_info
- Defined: `legacy/build-dkms.sh:60`

### check_root
- Defined: `legacy/build-dkms.sh:64`

### check_dependencies
- Defined: `legacy/build-dkms.sh:72`

### detect_audiobox
- Defined: `legacy/build-dkms.sh:101`

### create_source_structure
- Defined: `legacy/build-dkms.sh:123`

### copy_source_files
- Defined: `legacy/build-dkms.sh:138`

### create_dkms_conf
- Defined: `legacy/build-dkms.sh:174`

### create_makefile
- Defined: `legacy/build-dkms.sh:193`

### verify_mixer_quirks
- Defined: `legacy/build-dkms.sh:252`

### build_with_dkms
- Defined: `legacy/build-dkms.sh:295`

### install_module
- Defined: `legacy/build-dkms.sh:309`

### reload_module
- Defined: `legacy/build-dkms.sh:323`

### verify_installation
- Defined: `legacy/build-dkms.sh:344`

### show_usage_info
- Defined: `legacy/build-dkms.sh:394`

### main
- Defined: `legacy/build-dkms.sh:452`

## legacy/main.c

### main `int main()`
- Defined: `legacy/main.c:4`
- Doc: include <stdio.h> include "vsl_dsp_logic.h" include "vsl_dsp_transport.h"

## legacy/mixer_quirks.c

### snd_create_std_mono_ctl_offset `static int snd_create_std_mono_ctl_offset(struct usb_mixer_interface *mixer,
					  unsigned int ...`
- Defined: `legacy/mixer_quirks.c:59`
- Doc: This function allows for the creation of standard UAC controls. See the quirks for M-Audio FTUs or Ebox-44. If you don't

### snd_create_std_mono_ctl `static int snd_create_std_mono_ctl(struct usb_mixer_interface *mixer,
				   unsigned int unitid,...`
- Defined: `legacy/mixer_quirks.c:112`

### snd_create_std_mono_table `static int snd_create_std_mono_table(struct usb_mixer_interface *mixer,
				     const struct std...`
- Defined: `legacy/mixer_quirks.c:129`
- Doc: Create a set of standard UAC controls from a table

### add_single_ctl_with_resume `static int add_single_ctl_with_resume(struct usb_mixer_interface *mixer,
				      int id,
				  ...`
- Defined: `legacy/mixer_quirks.c:145`

### snd_usb_soundblaster_remote_complete `static void snd_usb_soundblaster_remote_complete(struct urb *urb)`
- Defined: `legacy/mixer_quirks.c:199`

### snd_usb_sbrc_hwdep_read `static long snd_usb_sbrc_hwdep_read(struct snd_hwdep *hw, char __user *buf,
				    long count, l...`
- Defined: `legacy/mixer_quirks.c:219`

### snd_usb_sbrc_hwdep_poll `static __poll_t snd_usb_sbrc_hwdep_poll(struct snd_hwdep *hw, struct file *file,
					poll_table ...`
- Defined: `legacy/mixer_quirks.c:239`

### snd_usb_soundblaster_remote_init `static int snd_usb_soundblaster_remote_init(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:248`

### snd_audigy2nx_led_get `static int snd_audigy2nx_led_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)`
- Defined: `legacy/mixer_quirks.c:298`
- Doc: define snd_audigy2nx_led_info		snd_ctl_boolean_mono_info

### snd_audigy2nx_led_update `static int snd_audigy2nx_led_update(struct usb_mixer_interface *mixer,
				    int value, int index)`
- Defined: `legacy/mixer_quirks.c:304`

### snd_audigy2nx_led_put `static int snd_audigy2nx_led_put(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_value *u...`
- Defined: `legacy/mixer_quirks.c:333`

### snd_audigy2nx_led_resume `static int snd_audigy2nx_led_resume(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:352`

### snd_audigy2nx_controls_create `static int snd_audigy2nx_controls_create(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:374`

### snd_audigy2nx_proc_read `static void snd_audigy2nx_proc_read(struct snd_info_entry *entry,
				    struct snd_info_buffer ...`
- Defined: `legacy/mixer_quirks.c:406`

### snd_emu0204_ch_switch_info `static int snd_emu0204_ch_switch_info(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_ele...`
- Defined: `legacy/mixer_quirks.c:457`
- Doc: return; err = snd_usb_ctl_msg(mixer->chip->dev, usb_rcvctrlpipe(mixer->chip->dev, 0), UAC_GET_MEM, USB_DIR_IN | USB_TYPE

### snd_emu0204_ch_switch_get `static int snd_emu0204_ch_switch_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- Defined: `legacy/mixer_quirks.c:464`

### snd_emu0204_ch_switch_update `static int snd_emu0204_ch_switch_update(struct usb_mixer_interface *mixer,
					int value)`
- Defined: `legacy/mixer_quirks.c:471`

### snd_emu0204_ch_switch_put `static int snd_emu0204_ch_switch_put(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- Defined: `legacy/mixer_quirks.c:489`

### snd_emu0204_ch_switch_resume `static int snd_emu0204_ch_switch_resume(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:508`

### snd_emu0204_controls_create `static int snd_emu0204_controls_create(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:523`

### snd_dualsense_ih_event `static void snd_dualsense_ih_event(struct input_handle *handle,
				   unsigned int type, unsigne...`
- Defined: `legacy/mixer_quirks.c:549`

### snd_dualsense_ih_match `static bool snd_dualsense_ih_match(struct input_handler *handler,
				   struct input_dev *dev)`
- Defined: `legacy/mixer_quirks.c:570`

### snd_dualsense_ih_connect `static int snd_dualsense_ih_connect(struct input_handler *handler,
				    struct input_dev *dev,...`
- Defined: `legacy/mixer_quirks.c:617`

### snd_dualsense_ih_disconnect `static void snd_dualsense_ih_disconnect(struct input_handle *handle)`
- Defined: `legacy/mixer_quirks.c:649`

### snd_dualsense_ih_start `static void snd_dualsense_ih_start(struct input_handle *handle)`
- Defined: `legacy/mixer_quirks.c:656`

### snd_dualsense_jack_get `static int snd_dualsense_jack_get(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...`
- Defined: `legacy/mixer_quirks.c:679`

### snd_dualsense_resume_jack `static int snd_dualsense_resume_jack(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:696`

### snd_dualsense_mixer_elem_free `static void snd_dualsense_mixer_elem_free(struct snd_kcontrol *kctl)`
- Defined: `legacy/mixer_quirks.c:703`

### snd_dualsense_jack_create `static int snd_dualsense_jack_create(struct usb_mixer_interface *mixer,
				     const char *name...`
- Defined: `legacy/mixer_quirks.c:713`

### snd_dualsense_controls_create `static int snd_dualsense_controls_create(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:777`

### snd_xonar_u1_switch_get `static int snd_xonar_u1_switch_get(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...`
- Defined: `legacy/mixer_quirks.c:791`
- Doc: static int snd_dualsense_controls_create(struct usb_mixer_interface *mixer) { int err; err = snd_dualsense_jack_create(m

### snd_xonar_u1_switch_update `static int snd_xonar_u1_switch_update(struct usb_mixer_interface *mixer,
				      unsigned char ...`
- Defined: `legacy/mixer_quirks.c:798`

### snd_xonar_u1_switch_put `static int snd_xonar_u1_switch_put(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...`
- Defined: `legacy/mixer_quirks.c:812`

### snd_xonar_u1_switch_resume `static int snd_xonar_u1_switch_resume(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:832`

### snd_xonar_u1_controls_create `static int snd_xonar_u1_controls_create(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:847`

### snd_mbox1_is_spdif_synced `static int snd_mbox1_is_spdif_synced(struct snd_usb_audio *chip)`
- Defined: `legacy/mixer_quirks.c:856`
- Doc: .info = snd_ctl_boolean_mono_info, .get = snd_xonar_u1_switch_get, .put = snd_xonar_u1_switch_put, .private_value = 0x05

### snd_mbox1_set_clk_source `static int snd_mbox1_set_clk_source(struct snd_usb_audio *chip, int rate_or_zero)`
- Defined: `legacy/mixer_quirks.c:876`

### snd_mbox1_is_spdif_input `static int snd_mbox1_is_spdif_input(struct snd_usb_audio *chip)`
- Defined: `legacy/mixer_quirks.c:894`

### snd_mbox1_set_input_source `static int snd_mbox1_set_input_source(struct snd_usb_audio *chip, int is_spdif)`
- Defined: `legacy/mixer_quirks.c:914`

### snd_mbox1_clk_switch_get `static int snd_mbox1_clk_switch_get(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...`
- Defined: `legacy/mixer_quirks.c:933`
- Doc: S/PDIF Source  -> 0x02  unsigned char buff[1]; buff[0] = (is_spdif & 1) + 1; /* Set input source return snd_usb_ctl_msg(

### snd_mbox1_clk_switch_update `static int snd_mbox1_clk_switch_update(struct usb_mixer_interface *mixer, int is_spdif_sync)`
- Defined: `legacy/mixer_quirks.c:953`

### snd_mbox1_clk_switch_put `static int snd_mbox1_clk_switch_put(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...`
- Defined: `legacy/mixer_quirks.c:978`

### snd_mbox1_clk_switch_info `static int snd_mbox1_clk_switch_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- Defined: `legacy/mixer_quirks.c:996`

### snd_mbox1_clk_switch_resume `static int snd_mbox1_clk_switch_resume(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:1007`

### snd_mbox1_src_switch_get `static int snd_mbox1_src_switch_get(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...`
- Defined: `legacy/mixer_quirks.c:1014`
- Doc: static const char *const texts[2] = { "Internal", "S/PDIF" }; return snd_ctl_enum_info(uinfo, 1, ARRAY_SIZE(texts), text

### snd_mbox1_src_switch_update `static int snd_mbox1_src_switch_update(struct usb_mixer_interface *mixer, int is_spdif_input)`
- Defined: `legacy/mixer_quirks.c:1021`

### snd_mbox1_src_switch_put `static int snd_mbox1_src_switch_put(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...`
- Defined: `legacy/mixer_quirks.c:1045`

### snd_mbox1_src_switch_info `static int snd_mbox1_src_switch_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- Defined: `legacy/mixer_quirks.c:1063`

### snd_mbox1_src_switch_resume `static int snd_mbox1_src_switch_resume(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:1074`

### snd_mbox1_controls_create `static int snd_mbox1_controls_create(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1101`

### snd_ni_control_init_val `static int snd_ni_control_init_val(struct usb_mixer_interface *mixer,
				   struct snd_kcontrol ...`
- Defined: `legacy/mixer_quirks.c:1120`
- Doc: define _MAKE_NI_CONTROL(bRequest, wIndex) ((bRequest) << 16 | (wIndex))

### snd_nativeinstruments_control_get `static int snd_nativeinstruments_control_get(struct snd_kcontrol *kcontrol,
					     struct snd_...`
- Defined: `legacy/mixer_quirks.c:1142`

### snd_ni_update_cur_val `static int snd_ni_update_cur_val(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:1149`

### snd_nativeinstruments_control_put `static int snd_nativeinstruments_control_put(struct snd_kcontrol *kcontrol,
					     struct snd_...`
- Defined: `legacy/mixer_quirks.c:1163`

### snd_nativeinstruments_create_mixer `static int snd_nativeinstruments_create_mixer(struct usb_mixer_interface *mixer,
					      const...`
- Defined: `legacy/mixer_quirks.c:1234`

### snd_ftu_eff_switch_info `static int snd_ftu_eff_switch_info(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_info...`
- Defined: `legacy/mixer_quirks.c:1267`
- Doc: err = add_single_ctl_with_resume(mixer, 0, snd_ni_update_cur_val, &template, &list); if (err < 0) break; snd_ni_control_

### snd_ftu_eff_switch_init `static int snd_ftu_eff_switch_init(struct usb_mixer_interface *mixer,
				   struct snd_kcontrol ...`
- Defined: `legacy/mixer_quirks.c:1277`

### snd_ftu_eff_switch_get `static int snd_ftu_eff_switch_get(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...`
- Defined: `legacy/mixer_quirks.c:1300`

### snd_ftu_eff_switch_update `static int snd_ftu_eff_switch_update(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:1307`

### snd_ftu_eff_switch_put `static int snd_ftu_eff_switch_put(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...`
- Defined: `legacy/mixer_quirks.c:1328`

### snd_ftu_create_effect_switch `static int snd_ftu_create_effect_switch(struct usb_mixer_interface *mixer,
					int validx, int b...`
- Defined: `legacy/mixer_quirks.c:1346`

### snd_ftu_create_volume_ctls `static int snd_ftu_create_volume_ctls(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1373`
- Doc: struct usb_mixer_elem_list *list; int err; err = add_single_ctl_with_resume(mixer, bUnitID, snd_ftu_eff_switch_update, &

### snd_ftu_create_effect_volume_ctl `static int snd_ftu_create_effect_volume_ctl(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1412`
- Doc: "DIn%d - Out%d Playback Volume", in - 7, out + 1); err = snd_create_std_mono_ctl(mixer, id, control, cmask, val_type, na

### snd_ftu_create_effect_duration_ctl `static int snd_ftu_create_effect_duration_ctl(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1425`
- Doc: /* This control needs a volume quirk, see mixer.c static int snd_ftu_create_effect_volume_ctl(struct usb_mixer_interface

### snd_ftu_create_effect_feedback_ctl `static int snd_ftu_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1438`
- Doc: /* This control needs a volume quirk, see mixer.c static int snd_ftu_create_effect_duration_ctl(struct usb_mixer_interfa

### snd_ftu_create_effect_return_ctls `static int snd_ftu_create_effect_return_ctls(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1449`

### snd_ftu_create_effect_send_ctls `static int snd_ftu_create_effect_send_ctls(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1473`

### snd_ftu_create_mixer `static int snd_ftu_create_mixer(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1506`

### snd_emuusb_set_samplerate `void snd_emuusb_set_samplerate(struct snd_usb_audio *chip,
			       unsigned char samplerate_id)`
- Defined: `legacy/mixer_quirks.c:1541`

### list_for_each_entry `list_for_each_entry(mixer, &chip->mixer_list, list)`
- Defined: `legacy/mixer_quirks.c:1548`
- Doc: err = snd_ftu_create_effect_send_ctls(mixer); if (err < 0) return err; return 0; } void snd_emuusb_set_samplerate(struct

### snd_c400_create_vol_ctls `static int snd_c400_create_vol_ctls(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1563`
- Doc: list_for_each_entry(mixer, &chip->mixer_list, list) { if (mixer->id_elems[unitid]) { cval = mixer_elem_list_to_info(mixe

### snd_c400_create_effect_volume_ctl `static int snd_c400_create_effect_volume_ctl(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1612`
- Doc: cmask = (out == 0) ? 0 : BIT(out - 1); offset = chan * num_outs; err = snd_create_std_mono_ctl_offset(mixer, id, control

### snd_c400_create_effect_duration_ctl `static int snd_c400_create_effect_duration_ctl(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1625`
- Doc: /* This control needs a volume quirk, see mixer.c static int snd_c400_create_effect_volume_ctl(struct usb_mixer_interfac

### snd_c400_create_effect_feedback_ctl `static int snd_c400_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1638`
- Doc: /* This control needs a volume quirk, see mixer.c static int snd_c400_create_effect_duration_ctl(struct usb_mixer_interf

### snd_c400_create_effect_vol_ctls `static int snd_c400_create_effect_vol_ctls(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1649`

### snd_c400_create_effect_ret_vol_ctls `static int snd_c400_create_effect_ret_vol_ctls(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1694`

### snd_c400_create_mixer `static int snd_c400_create_mixer(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1736`

### snd_microii_spdif_info `static int snd_microii_spdif_info(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_info *...`
- Defined: `legacy/mixer_quirks.c:1869`
- Doc: power on values: r2: 0x10 r3: 0x20 (b7 is zeroed just before playback (except IEC61937) and set just after it to 0xa0, p

### snd_microii_spdif_default_get `static int snd_microii_spdif_default_get(struct snd_kcontrol *kcontrol,
					 struct snd_ctl_elem...`
- Defined: `legacy/mixer_quirks.c:1876`

### snd_microii_spdif_default_update `static int snd_microii_spdif_default_update(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:1923`

### snd_microii_spdif_default_put `static int snd_microii_spdif_default_put(struct snd_kcontrol *kcontrol,
					 struct snd_ctl_elem...`
- Defined: `legacy/mixer_quirks.c:1959`

### snd_microii_spdif_mask_get `static int snd_microii_spdif_mask_get(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_ele...`
- Defined: `legacy/mixer_quirks.c:1987`

### snd_microii_spdif_switch_get `static int snd_microii_spdif_switch_get(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_v...`
- Defined: `legacy/mixer_quirks.c:1998`

### snd_microii_spdif_switch_update `static int snd_microii_spdif_switch_update(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:2006`

### snd_microii_spdif_switch_put `static int snd_microii_spdif_switch_put(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_v...`
- Defined: `legacy/mixer_quirks.c:2025`

### snd_microii_controls_create `static int snd_microii_controls_create(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:2067`

### snd_soundblaster_e1_switch_get `static int snd_soundblaster_e1_switch_get(struct snd_kcontrol *kcontrol,
					  struct snd_ctl_el...`
- Defined: `legacy/mixer_quirks.c:2090`
- Doc: for (i = 0; i < ARRAY_SIZE(snd_microii_mixer_spdif); ++i) { err = add_single_ctl_with_resume(mixer, 0, resume_funcs[i], 

### snd_soundblaster_e1_switch_update `static int snd_soundblaster_e1_switch_update(struct usb_mixer_interface *mixer,
					     unsigne...`
- Defined: `legacy/mixer_quirks.c:2097`

### snd_soundblaster_e1_switch_put `static int snd_soundblaster_e1_switch_put(struct snd_kcontrol *kcontrol,
					  struct snd_ctl_el...`
- Defined: `legacy/mixer_quirks.c:2115`

### snd_soundblaster_e1_switch_resume `static int snd_soundblaster_e1_switch_resume(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:2129`

### snd_soundblaster_e1_switch_info `static int snd_soundblaster_e1_switch_info(struct snd_kcontrol *kcontrol,
					   struct snd_ctl_...`
- Defined: `legacy/mixer_quirks.c:2135`

### snd_soundblaster_e1_switch_create `static int snd_soundblaster_e1_switch_create(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:2154`

### realtek_hda_set `static int realtek_hda_set(struct snd_usb_audio *chip, u32 cmd)`
- Defined: `legacy/mixer_quirks.c:2191`
- Doc: define REALTEK_MIC_FLAG 0x100

### realtek_hda_get `static int realtek_hda_get(struct snd_usb_audio *chip, u32 cmd, u32 *value)`
- Defined: `legacy/mixer_quirks.c:2201`

### realtek_ctl_connector_get `static int realtek_ctl_connector_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- Defined: `legacy/mixer_quirks.c:2222`

### realtek_resume_jack `static int realtek_resume_jack(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:2272`

### realtek_add_jack `static int realtek_add_jack(struct usb_mixer_interface *mixer,
			    char *name, u32 val)`
- Defined: `legacy/mixer_quirks.c:2279`

### dell_dock_mixer_create `static int dell_dock_mixer_create(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:2306`

### dell_dock_init_vol `static void dell_dock_init_vol(struct usb_mixer_interface *mixer, int ch, int id)`
- Defined: `legacy/mixer_quirks.c:2338`

### dell_dock_mixer_init `static int dell_dock_mixer_init(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:2350`

### snd_rme_read_value `static int snd_rme_read_value(struct snd_usb_audio *chip,
			      unsigned int item,
			      u3...`
- Defined: `legacy/mixer_quirks.c:2418`

### snd_rme_get_status1 `static int snd_rme_get_status1(struct snd_kcontrol *kcontrol,
			       u32 *status1)`
- Defined: `legacy/mixer_quirks.c:2437`

### snd_rme_rate_get `static int snd_rme_rate_get(struct snd_kcontrol *kcontrol,
			    struct snd_ctl_elem_value *ucon...`
- Defined: `legacy/mixer_quirks.c:2449`

### snd_rme_sync_state_get `static int snd_rme_sync_state_get(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_value ...`
- Defined: `legacy/mixer_quirks.c:2483`

### snd_rme_spdif_if_get `static int snd_rme_spdif_if_get(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *uco...`
- Defined: `legacy/mixer_quirks.c:2513`

### snd_rme_spdif_format_get `static int snd_rme_spdif_format_get(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_va...`
- Defined: `legacy/mixer_quirks.c:2526`

### snd_rme_sync_source_get `static int snd_rme_sync_source_get(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...`
- Defined: `legacy/mixer_quirks.c:2539`

### snd_rme_current_freq_get `static int snd_rme_current_freq_get(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_va...`
- Defined: `legacy/mixer_quirks.c:2552`

### snd_rme_rate_info `static int snd_rme_rate_info(struct snd_kcontrol *kcontrol,
			     struct snd_ctl_elem_info *uinfo)`
- Defined: `legacy/mixer_quirks.c:2578`

### snd_rme_sync_state_info `static int snd_rme_sync_state_info(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_info...`
- Defined: `legacy/mixer_quirks.c:2598`

### snd_rme_spdif_if_info `static int snd_rme_spdif_if_info(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_info *ui...`
- Defined: `legacy/mixer_quirks.c:2609`

### snd_rme_spdif_format_info `static int snd_rme_spdif_format_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- Defined: `legacy/mixer_quirks.c:2620`

### snd_rme_sync_source_info `static int snd_rme_sync_source_info(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_in...`
- Defined: `legacy/mixer_quirks.c:2631`

### snd_rme_controls_create `static int snd_rme_controls_create(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:2713`

### snd_bbfpro_ctl_update `static int snd_bbfpro_ctl_update(struct usb_mixer_interface *mixer, u8 reg,
				 u8 index, u8 value)`
- Defined: `legacy/mixer_quirks.c:2779`
- Doc: define SND_BBFPRO_USBREQ_CTL_REG1 0x10 define SND_BBFPRO_USBREQ_CTL_REG2 0x17 define SND_BBFPRO_USBREQ_GAIN 0x1a define 

### snd_bbfpro_ctl_get `static int snd_bbfpro_ctl_get(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...`
- Defined: `legacy/mixer_quirks.c:2810`

### snd_bbfpro_ctl_info `static int snd_bbfpro_ctl_info(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_info ...`
- Defined: `legacy/mixer_quirks.c:2833`

### snd_bbfpro_ctl_put `static int snd_bbfpro_ctl_put(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...`
- Defined: `legacy/mixer_quirks.c:2867`

### snd_bbfpro_ctl_resume `static int snd_bbfpro_ctl_resume(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:2906`

### snd_bbfpro_gain_update `static int snd_bbfpro_gain_update(struct usb_mixer_interface *mixer,
				  u8 channel, u8 gain)`
- Defined: `legacy/mixer_quirks.c:2919`

### snd_bbfpro_gain_get `static int snd_bbfpro_gain_get(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_value...`
- Defined: `legacy/mixer_quirks.c:2943`

### snd_bbfpro_gain_info `static int snd_bbfpro_gain_info(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_info *uinfo)`
- Defined: `legacy/mixer_quirks.c:2952`

### snd_bbfpro_gain_put `static int snd_bbfpro_gain_put(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_value...`
- Defined: `legacy/mixer_quirks.c:2973`

### snd_bbfpro_gain_resume `static int snd_bbfpro_gain_resume(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:3010`

### snd_bbfpro_vol_update `static int snd_bbfpro_vol_update(struct usb_mixer_interface *mixer, u16 index,
				 u32 value)`
- Defined: `legacy/mixer_quirks.c:3023`

### snd_bbfpro_vol_get `static int snd_bbfpro_vol_get(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...`
- Defined: `legacy/mixer_quirks.c:3049`

### snd_bbfpro_vol_info `static int snd_bbfpro_vol_info(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_info ...`
- Defined: `legacy/mixer_quirks.c:3057`

### snd_bbfpro_vol_put `static int snd_bbfpro_vol_put(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...`
- Defined: `legacy/mixer_quirks.c:3067`

### snd_bbfpro_vol_resume `static int snd_bbfpro_vol_resume(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:3095`

### snd_bbfpro_ctl_add `static int snd_bbfpro_ctl_add(struct usb_mixer_interface *mixer, u8 reg,
			      u8 index, char ...`
- Defined: `legacy/mixer_quirks.c:3132`

### snd_bbfpro_gain_add `static int snd_bbfpro_gain_add(struct usb_mixer_interface *mixer, u8 channel,
			       char *name)`
- Defined: `legacy/mixer_quirks.c:3146`

### snd_bbfpro_vol_add `static int snd_bbfpro_vol_add(struct usb_mixer_interface *mixer, u16 index,
			      char *name)`
- Defined: `legacy/mixer_quirks.c:3158`

### snd_bbfpro_controls_create `static int snd_bbfpro_controls_create(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:3170`

### snd_rme_digiface_write_reg `static int snd_rme_digiface_write_reg(struct snd_kcontrol *kcontrol, int item, u16 mask, u16 val)`
- Defined: `legacy/mixer_quirks.c:3318`
- Doc: #define RME_DIGIFACE_STATUS_REG2H 5 #define RME_DIGIFACE_STATUS_REG3L 6 #define RME_DIGIFACE_STATUS_REG3H 7 #define RME_

### snd_rme_digiface_read_status `static int snd_rme_digiface_read_status(struct snd_kcontrol *kcontrol, u32 status[4])`
- Defined: `legacy/mixer_quirks.c:3336`

### snd_rme_digiface_get_status_val `static int snd_rme_digiface_get_status_val(struct snd_kcontrol *kcontrol)`
- Defined: `legacy/mixer_quirks.c:3360`

### snd_rme_digiface_rate_get `static int snd_rme_digiface_rate_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- Defined: `legacy/mixer_quirks.c:3398`

### snd_rme_digiface_enum_get `static int snd_rme_digiface_enum_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- Defined: `legacy/mixer_quirks.c:3412`

### snd_rme_digiface_enum_put `static int snd_rme_digiface_enum_put(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- Defined: `legacy/mixer_quirks.c:3424`

### snd_rme_digiface_current_sync_get `static int snd_rme_digiface_current_sync_get(struct snd_kcontrol *kcontrol,
					     struct snd_...`
- Defined: `legacy/mixer_quirks.c:3438`

### snd_rme_digiface_sync_state_get `static int snd_rme_digiface_sync_state_get(struct snd_kcontrol *kcontrol,
					   struct snd_ctl_...`
- Defined: `legacy/mixer_quirks.c:3450`

### snd_rme_digiface_format_info `static int snd_rme_digiface_format_info(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_i...`
- Defined: `legacy/mixer_quirks.c:3473`

### snd_rme_digiface_sync_source_info `static int snd_rme_digiface_sync_source_info(struct snd_kcontrol *kcontrol,
					     struct snd_...`
- Defined: `legacy/mixer_quirks.c:3484`

### snd_rme_digiface_rate_info `static int snd_rme_digiface_rate_info(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_ele...`
- Defined: `legacy/mixer_quirks.c:3495`

### snd_rme_digiface_controls_create `static int snd_rme_digiface_controls_create(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:3684`

### snd_djm_get_label_caplevel_common `static const char *snd_djm_get_label_caplevel_common(u16 wvalue)`
- Defined: `legacy/mixer_quirks.c:3791`

### snd_djm_get_label_caplevel_high `static const char *snd_djm_get_label_caplevel_high(u16 wvalue)`
- Defined: `legacy/mixer_quirks.c:3804`
- Doc: Models like DJM-A9 or DJM-V10 have different capture levels than others

### snd_djm_get_label_cap_common `static const char *snd_djm_get_label_cap_common(u16 wvalue)`
- Defined: `legacy/mixer_quirks.c:3816`

### snd_djm_get_label_cap_850 `static const char *snd_djm_get_label_cap_850(u16 wvalue)`
- Defined: `legacy/mixer_quirks.c:3849`
- Doc: The DJM-850 has different values for CD/LINE and LINE capture control options than the other DJM declared in this file.

### snd_djm_get_label_caplevel `static const char *snd_djm_get_label_caplevel(u8 device_idx, u16 wvalue)`
- Defined: `legacy/mixer_quirks.c:3857`

### snd_djm_get_label_cap `static const char *snd_djm_get_label_cap(u8 device_idx, u16 wvalue)`
- Defined: `legacy/mixer_quirks.c:3866`

### snd_djm_get_label_pb `static const char *snd_djm_get_label_pb(u16 wvalue)`
- Defined: `legacy/mixer_quirks.c:3874`

### snd_djm_get_label `static const char *snd_djm_get_label(u8 device_idx, u16 wvalue, u16 windex)`
- Defined: `legacy/mixer_quirks.c:3884`

### snd_djm_controls_info `static int snd_djm_controls_info(struct snd_kcontrol *kctl,
				 struct snd_ctl_elem_info *info)`
- Defined: `legacy/mixer_quirks.c:4116`

### snd_djm_controls_update `static int snd_djm_controls_update(struct usb_mixer_interface *mixer,
				   u8 device_idx, u8 gr...`
- Defined: `legacy/mixer_quirks.c:4148`

### snd_djm_controls_get `static int snd_djm_controls_get(struct snd_kcontrol *kctl,
				struct snd_ctl_elem_value *elem)`
- Defined: `legacy/mixer_quirks.c:4169`

### snd_djm_controls_put `static int snd_djm_controls_put(struct snd_kcontrol *kctl, struct snd_ctl_elem_value *elem)`
- Defined: `legacy/mixer_quirks.c:4176`

### snd_djm_controls_resume `static int snd_djm_controls_resume(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:4193`

### snd_djm_controls_create `static int snd_djm_controls_create(struct usb_mixer_interface *mixer,
				   const u8 device_idx)`
- Defined: `legacy/mixer_quirks.c:4203`

### snd_usb_mixer_apply_create_quirk `int snd_usb_mixer_apply_create_quirk(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:4238`

### snd_usb_mixer_resume_quirk `void snd_usb_mixer_resume_quirk(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:4420`

### snd_usb_mixer_rc_memory_change `void snd_usb_mixer_rc_memory_change(struct usb_mixer_interface *mixer,
				    int unitid)`
- Defined: `legacy/mixer_quirks.c:4429`

### snd_dragonfly_quirk_db_scale `static void snd_dragonfly_quirk_db_scale(struct usb_mixer_interface *mixer,
					 struct usb_mixe...`
- Defined: `legacy/mixer_quirks.c:4457`

### snd_fix_plt_name `static void snd_fix_plt_name(struct snd_usb_audio *chip,
			     struct snd_ctl_elem_id *id)`
- Defined: `legacy/mixer_quirks.c:4509`
- Doc: standards. This function fixes nonstandard source names. By the time this function is called the control name should loo

### snd_usb_mixer_fu_apply_quirk `void snd_usb_mixer_fu_apply_quirk(struct usb_mixer_interface *mixer,
				  struct usb_mixer_elem_...`
- Defined: `legacy/mixer_quirks.c:4538`

## legacy/test_connection.c

### main `int main()`
- Defined: `legacy/test_connection.c:6`
- Doc: include <stdio.h> include "vsl_config.h" include "vsl_dsp_transport.h" // Asumiendo que esta es la plantilla B

## legacy/vsl_config.py

### validate_configuration `def validate_configuration()`
- Defined: `legacy/vsl_config.py:92`
- Doc: Valida que todos los valores críticos estén configurados.
- Imported by: `legacy/vsl_core.py`, `legacy/vsl_core.py`, `legacy/vsl_hid_io.py`, `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`, `legacy/vsl_transport.py`, `legacy/vsl_transport.py`

### print_configuration_status `def print_configuration_status()`
- Defined: `legacy/vsl_config.py:116`
- Doc: Imprime el estado de la configuración con formato.
- Imported by: `legacy/vsl_core.py`, `legacy/vsl_core.py`, `legacy/vsl_hid_io.py`, `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`, `legacy/vsl_transport.py`, `legacy/vsl_transport.py`

## legacy/vsl_core.py

### vsl_encode_gain `def vsl_encode_gain(linear_value, param)`
- Defined: `legacy/vsl_core.py:16`
- Doc: Traducción de FUN_00132c90 (VSL_Encode_Gain en C).
- Depends on: `legacy/vsl_config.py`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

### vsl_map_frequency `def vsl_map_frequency(linear_position, param)`
- Defined: `legacy/vsl_core.py:58`
- Doc: Traducción de FUN_00132d00 (VSL_Map_Frequency en C).
- Depends on: `legacy/vsl_config.py`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

### vsl_final_encode_to_int `def vsl_final_encode_to_int(encoded_float, param)`
- Defined: `legacy/vsl_core.py:94`
- Doc: Traducción de VSL_Final_Encode_To_Int en C.
- Depends on: `legacy/vsl_config.py`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

### vsl_decode_frequency `def vsl_decode_frequency(freq_hz_value, param)`
- Defined: `legacy/vsl_core.py:127`
- Doc: Traducción de FUN_00132da8 (VSL_Decode_Frequency en C).
- Depends on: `legacy/vsl_config.py`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

### validate_parameter `def validate_parameter(param)`
- Defined: `legacy/vsl_core.py:170`
- Doc: Valida la integridad de un VSLParameter.
- Depends on: `legacy/vsl_config.py`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

## legacy/vsl_dsp_logic.c

### VSL_Encode_Gain `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)`
- Defined: `legacy/vsl_dsp_logic.c:11`
- Doc: Implementación de FUN_00132c90

### VSL_Map_Frequency `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)`
- Defined: `legacy/vsl_dsp_logic.c:29`
- Doc: Implementación de FUN_00132d00

### VSL_Final_Encode_To_Int `uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)`
- Defined: `legacy/vsl_dsp_logic.c:58`
- Doc: @brief Convierte el valor codificado en float a un entero sin signo para el firmware. @note Basado en la hipótesis común

### VSL_Decode_Frequency `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)`
- Defined: `legacy/vsl_dsp_logic.c:78`
- Doc: Implementación de FUN_00132da8

## legacy/vsl_dsp_transport.c

### VSL_Init_Device `int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)`
- Defined: `legacy/vsl_dsp_transport.c:22`
- Doc: ... (las inclusiones y el singleton handle) ...

### VSL_Close_Device `void VSL_Close_Device(void)`
- Defined: `legacy/vsl_dsp_transport.c:69`

### VSL_Get_Device_Handle `hid_device* VSL_Get_Device_Handle(void)`
- Defined: `legacy/vsl_dsp_transport.c:78`

### FUN_Send_Packet `void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length)`
- Defined: `legacy/vsl_dsp_transport.c:97`
- Doc: @brief Función de I/O real usando HIDAPI. @note DEBE SER REEMPLAZADA con la lógica específica de tu dispositivo (Report 

### VSL_Build_And_Send_Packet `void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float)`
- Defined: `legacy/vsl_dsp_transport.c:140`
- Doc: Implementación de la función de construcción y envío

## legacy/vsl_hid_io.py

### enumerate_vsl_devices `def enumerate_vsl_devices()`
- Defined: `legacy/vsl_hid_io.py:149`
- Doc: Enumera todos los dispositivos HID conectados.
- Depends on: `legacy/vsl_config.py`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### __new__ `def __new__(cls)`
- Defined: `legacy/vsl_hid_io.py:39`
- Depends on: `legacy/vsl_config.py`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### __init__ `def __init__(self)`
- Defined: `legacy/vsl_hid_io.py:45`
- Depends on: `legacy/vsl_config.py`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### open `def open(self)`
- Defined: `legacy/vsl_hid_io.py:59`
- Doc: Abre la conexión con el dispositivo VSL.
- Depends on: `legacy/vsl_config.py`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### close `def close(self)`
- Defined: `legacy/vsl_hid_io.py:90`
- Doc: Cierra la conexión con el dispositivo.
- Depends on: `legacy/vsl_config.py`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### send_packet `def send_packet(self, packet)`
- Defined: `legacy/vsl_hid_io.py:101`
- Doc: Envía un paquete VSL al dispositivo.
- Depends on: `legacy/vsl_config.py`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### __enter__ `def __enter__(self)`
- Defined: `legacy/vsl_hid_io.py:139`
- Doc: Context manager entry.
- Depends on: `legacy/vsl_config.py`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### __exit__ `def __exit__(self, exc_type, exc_val, exc_tb)`
- Defined: `legacy/vsl_hid_io.py:144`
- Doc: Context manager exit.
- Depends on: `legacy/vsl_config.py`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

## legacy/vsl_poc_main.py

### test_gain_encoding `def test_gain_encoding()`
- Defined: `legacy/vsl_poc_main.py:43`
- Doc: Test de codificación de ganancia con tabla de validación.
- Depends on: `legacy/vsl_config.py`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### test_frequency_mapping `def test_frequency_mapping()`
- Defined: `legacy/vsl_poc_main.py:72`
- Doc: Test de mapeo logarítmico de frecuencias.
- Depends on: `legacy/vsl_config.py`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### test_packet_construction `def test_packet_construction()`
- Defined: `legacy/vsl_poc_main.py:92`
- Doc: Test de construcción de paquetes HID.
- Depends on: `legacy/vsl_config.py`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### test_edge_cases `def test_edge_cases()`
- Defined: `legacy/vsl_poc_main.py:150`
- Doc: Test de casos extremos y validación de errores.
- Depends on: `legacy/vsl_config.py`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### run_full_workflow `def run_full_workflow()`
- Defined: `legacy/vsl_poc_main.py:197`
- Doc: Simula el flujo completo: Usuario → Encoding → Paquete.
- Depends on: `legacy/vsl_config.py`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### print_summary `def print_summary()`
- Defined: `legacy/vsl_poc_main.py:229`
- Doc: Imprime resumen del estado del proyecto.
- Depends on: `legacy/vsl_config.py`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### main `def main()`
- Defined: `legacy/vsl_poc_main.py:266`
- Doc: Función principal de la PoC.
- Depends on: `legacy/vsl_config.py`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

## legacy/vsl_protocol_analyzer.py

### reverse_map_gain `def reverse_map_gain(encoded_value, param)`
- Defined: `legacy/vsl_protocol_analyzer.py:67`
- Doc: Simula VSL_Decode_Gain. Convierte un entero a un valor de usuario (dB).

### reverse_map_frequency `def reverse_map_frequency(encoded_value, param)`
- Defined: `legacy/vsl_protocol_analyzer.py:95`
- Doc: Simula VSL_Decode_Frequency. Convierte un entero a frecuencia (Hz).

### get_decoded_value `def get_decoded_value(encoded_value, param_id)`
- Defined: `legacy/vsl_protocol_analyzer.py:115`
- Doc: Dirige la decodificación al motor DSP correcto.

### decode_vsl_packet `def decode_vsl_packet(data)`
- Defined: `legacy/vsl_protocol_analyzer.py:140`
- Doc: Decodifica el payload de 64 bytes. (Regla #3: Seguridad)

### analyze_pcap `def analyze_pcap(pcap_file)`
- Defined: `legacy/vsl_protocol_analyzer.py:173`
- Doc: Carga un archivo PCAP y filtra los paquetes USB VSL.

### __init__ `def __init__(self, dsp_id, name, type_unit, min_map, max_map, coeff_A, coeff_C1, log_factor)`
- Defined: `legacy/vsl_protocol_analyzer.py:30`

## legacy/vsl_transport.py

### build_packet_safe `def build_packet_safe(param, encoded_value)`
- Defined: `legacy/vsl_transport.py:141`
- Doc: Construye un paquete con manejo de errores.
- Depends on: `legacy/vsl_config.py`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

### __init__ `def __init__(self, param_id, encoded_value, report_id)`
- Defined: `legacy/vsl_transport.py:21`
- Doc: Construye un paquete VSL-DSP.
- Depends on: `legacy/vsl_config.py`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

### _build_buffer `def _build_buffer(self)`
- Defined: `legacy/vsl_transport.py:58`
- Doc: Construye el buffer de 64 bytes según el protocolo VSL-DSP.
- Depends on: `legacy/vsl_config.py`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

### buffer `def buffer(self)`
- Defined: `legacy/vsl_transport.py:89`
- Doc: Retorna el buffer como bytes inmutables.
- Depends on: `legacy/vsl_config.py`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

### hex_dump `def hex_dump(self, num_bytes)`
- Defined: `legacy/vsl_transport.py:93`
- Doc: Genera un hex dump del paquete para debugging.
- Depends on: `legacy/vsl_config.py`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

### validate `def validate(self)`
- Defined: `legacy/vsl_transport.py:106`
- Doc: Valida la integridad del paquete.
- Depends on: `legacy/vsl_config.py`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

### __repr__ `def __repr__(self)`
- Defined: `legacy/vsl_transport.py:133`
- Depends on: `legacy/vsl_config.py`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

## src/vsl_cli.c

### print_usage `static void print_usage(FILE *fp, const char *prog)`
- Defined: `src/vsl_cli.c:57`

### print_version `static void print_version(void)`
- Defined: `src/vsl_cli.c:83`

### print_list `static void print_list(uint16_t product_id)`
- Defined: `src/vsl_cli.c:90`

### lookup_coeffs_by_param_id `static const VSL_Parameter *
lookup_coeffs_by_param_id(uint16_t param_id)`
- Defined: `src/vsl_cli.c:109`

### find_entry_by_name `static const ParamEntry *
find_entry_by_name(const char *name)`
- Defined: `src/vsl_cli.c:119`

### do_send `static int do_send(uint16_t product_id,
                   uint16_t param_id,
                   ...`
- Defined: `src/vsl_cli.c:129`

### do_send_freq `static int do_send_freq(uint16_t product_id,
                        uint16_t param_id,
         ...`
- Defined: `src/vsl_cli.c:167`

### main `int main(int argc, char *argv[])`
- Defined: `src/vsl_cli.c:204`

## src/vsl_config.h

### VSL_ModelLookup `static inline const VSL_ModelInfo *
VSL_ModelLookup(uint16_t pid)`
- Defined: `src/vsl_config.h:35`

### VSL_ModelLookupByTag `static inline const VSL_ModelInfo *
VSL_ModelLookupByTag(const char *tag)`
- Defined: `src/vsl_config.h:47`

## src/vsl_dsp_logic.c

### VSL_Encode_Gain `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)`
- Defined: `src/vsl_dsp_logic.c:2`
- Doc: include "vsl_dsp_logic.h"

### VSL_Decode_Gain `float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param)`
- Defined: `src/vsl_dsp_logic.c:15`

### VSL_Map_Frequency `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)`
- Defined: `src/vsl_dsp_logic.c:49`

### VSL_Final_Encode_To_Int `uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)`
- Defined: `src/vsl_dsp_logic.c:65`

### VSL_Decode_Frequency `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)`
- Defined: `src/vsl_dsp_logic.c:75`

## src/vsl_dsp_transport.c

### VSL_Init_Device `vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)`
- Defined: `src/vsl_dsp_transport.c:12`

### VSL_Close_Device `void VSL_Close_Device(vsl_device_handle handle)`
- Defined: `src/vsl_dsp_transport.c:44`

### VSL_Send_Parameter `int VSL_Send_Parameter(vsl_device_handle handle,
                       uint16_t dsp_param_id,
  ...`
- Defined: `src/vsl_dsp_transport.c:60`

## tests/test_audiobox_vsl.c

### test_supported_models_table_shape `static void test_supported_models_table_shape(void **state)`
- Defined: `tests/test_audiobox_vsl.c:30`

### test_model_pids_match_table `static void test_model_pids_match_table(void **state)`
- Defined: `tests/test_audiobox_vsl.c:45`

### test_lookup_returns_22_vsl `static void test_lookup_returns_22_vsl(void **state)`
- Defined: `tests/test_audiobox_vsl.c:54`

### test_lookup_returns_44_vsl `static void test_lookup_returns_44_vsl(void **state)`
- Defined: `tests/test_audiobox_vsl.c:64`

### test_lookup_returns_1818_vsl `static void test_lookup_returns_1818_vsl(void **state)`
- Defined: `tests/test_audiobox_vsl.c:74`

### test_lookup_returns_null_for_unknown_pid `static void test_lookup_returns_null_for_unknown_pid(void **state)`
- Defined: `tests/test_audiobox_vsl.c:84`

### test_lookup_handles_full_pid_range `static void test_lookup_handles_full_pid_range(void **state)`
- Defined: `tests/test_audiobox_vsl.c:94`

### test_table_pids_are_unique `static void test_table_pids_are_unique(void **state)`
- Defined: `tests/test_audiobox_vsl.c:114`

### test_table_product_names_non_empty `static void test_table_product_names_non_empty(void **state)`
- Defined: `tests/test_audiobox_vsl.c:125`

### main `int main(void)`
- Defined: `tests/test_audiobox_vsl.c:135`

## tests/test_vsl_dsp_logic.c

### test_VSL_Encode_Gain `static void test_VSL_Encode_Gain(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:8`
- Doc: include <stdarg.h> include <stddef.h> include <setjmp.h> include <cmocka.h> include <math.h> include <float.h> include "

### test_VSL_Map_Frequency `static void test_VSL_Map_Frequency(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:35`

### test_VSL_Decode_Frequency `static void test_VSL_Decode_Frequency(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:67`

### test_VSL_Final_Encode_To_Int `static void test_VSL_Final_Encode_To_Int(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:99`

### test_VSL_Decode_Gain_c1_zero `static void test_VSL_Decode_Gain_c1_zero(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:127`

### test_VSL_Decode_Gain_log_factor_zero `static void test_VSL_Decode_Gain_log_factor_zero(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:145`

### test_VSL_Decode_Gain_encoded_below_offset `static void test_VSL_Decode_Gain_encoded_below_offset(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:163`

### test_VSL_Decode_Gain_range_zero `static void test_VSL_Decode_Gain_range_zero(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:182`

### test_VSL_Decode_Gain_roundtrip_mid `static void test_VSL_Decode_Gain_roundtrip_mid(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:200`

### test_VSL_Decode_Gain_roundtrip_extremes `static void test_VSL_Decode_Gain_roundtrip_extremes(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:220`

### test_VSL_Decode_Gain_roundtrip_75 `static void test_VSL_Decode_Gain_roundtrip_75(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:241`

### test_VSL_Decode_Gain_custom_range_roundtrip `static void test_VSL_Decode_Gain_custom_range_roundtrip(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:261`

### test_VSL_Decode_Gain_encoded_equals_offset `static void test_VSL_Decode_Gain_encoded_equals_offset(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:289`

### test_VSL_Decode_Gain_clamps_output `static void test_VSL_Decode_Gain_clamps_output(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:308`

### main `int main(void)`
- Defined: `tests/test_vsl_dsp_logic.c:328`

## voicecloak/src/vc_alsa.c

### fmt_bps `static size_t fmt_bps(snd_pcm_format_t f)`
- Defined: `voicecloak/src/vc_alsa.c:19`

### open_stream `static int open_stream(vc_pcm_t *s, const char *dev, snd_pcm_stream_t dir,
                      ...`
- Defined: `voicecloak/src/vc_alsa.c:28`

### raw_to_mono `static void raw_to_mono(const unsigned char *raw, float *mono,
                        snd_pcm_uf...`
- Defined: `voicecloak/src/vc_alsa.c:98`

### mono_to_raw `static void mono_to_raw(unsigned char *raw, const float *mono,
                        snd_pcm_uf...`
- Defined: `voicecloak/src/vc_alsa.c:129`

### vc_alsa_list `int vc_alsa_list(void)`
- Defined: `voicecloak/src/vc_alsa.c:162`

### vc_alsa_run `int vc_alsa_run(const vc_alsa_cfg_t *cfg)`
- Defined: `voicecloak/src/vc_alsa.c:188`

## voicecloak/src/vc_cli.c

### print_usage `static void print_usage(const char *prog)`
- Defined: `voicecloak/src/vc_cli.c:8`
- Doc: include "vc_wav.h" include "vc_dsp.h" include "vc_crypto.h" include <stdio.h> include <stdlib.h> include <string.h> incl

### cmd_keygen `static int cmd_keygen(void)`
- Defined: `voicecloak/src/vc_cli.c:40`

### cmd_cloak `static int cmd_cloak(const char *pubkey_path,
                     const char *in_path, const cha...`
- Defined: `voicecloak/src/vc_cli.c:52`

### cmd_info `static int cmd_info(const char *path)`
- Defined: `voicecloak/src/vc_cli.c:141`

### main `int main(int argc, char *argv[])`
- Defined: `voicecloak/src/vc_cli.c:176`

## voicecloak/src/vc_crypto.c

### openssl_init `static void openssl_init(void)`
- Defined: `voicecloak/src/vc_crypto.c:11`
- Doc: include "vc_crypto.h" include <stdio.h> include <stdlib.h> include <string.h> include <openssl/evp.h> include <openssl/p

### vc_crypto_keygen `int vc_crypto_keygen(const char *pubkey_path, const char *privkey_path)`
- Defined: `voicecloak/src/vc_crypto.c:16`

### vc_crypto_seal `int vc_crypto_seal(const char *pubkey_path,
                   const unsigned char *seed, size_t ...`
- Defined: `voicecloak/src/vc_crypto.c:46`

### vc_crypto_unseal `int vc_crypto_unseal(const char *privkey_path,
                     const unsigned char *enc, siz...`
- Defined: `voicecloak/src/vc_crypto.c:70`

### vc_crypto_derive_seeds `int vc_crypto_derive_seeds(const unsigned char *master_seed, size_t seed_len,
                   ...`
- Defined: `voicecloak/src/vc_crypto.c:95`

### vc_prng_create `vc_prng_t *vc_prng_create(const unsigned char *seed)`
- Defined: `voicecloak/src/vc_crypto.c:142`

### vc_prng_destroy `void vc_prng_destroy(vc_prng_t *p)`
- Defined: `voicecloak/src/vc_crypto.c:156`

### vc_prng_fill `void vc_prng_fill(vc_prng_t *p, unsigned char *buf, size_t len)`
- Defined: `voicecloak/src/vc_crypto.c:163`

### vc_prng_float `float vc_prng_float(vc_prng_t *p, float low, float high)`
- Defined: `voicecloak/src/vc_crypto.c:183`

## voicecloak/src/vc_dsp.c

### stft_process `static int stft_process(const float *samples, size_t num_samples,
                        float *...`
- Defined: `voicecloak/src/vc_dsp.c:11`
- Doc: define VC_FFT_SIZE 2048U define VC_HOP_SIZE  (VC_FFT_SIZE / 4)

### stft_reconstruct `static int stft_reconstruct(const float *mag, const float *phase,
                            siz...`
- Defined: `voicecloak/src/vc_dsp.c:20`

### compute_out_len `static size_t compute_out_len(size_t nframes, size_t hop)`
- Defined: `voicecloak/src/vc_dsp.c:30`

### vc_dsp_pitch_shift `int vc_dsp_pitch_shift(const float *samples, size_t num_samples,
                       uint32_t ...`
- Defined: `voicecloak/src/vc_dsp.c:34`

### vc_dsp_formant_shift `int vc_dsp_formant_shift(const float *samples, size_t num_samples,
                         uint3...`
- Defined: `voicecloak/src/vc_dsp.c:90`

### vc_dsp_spectral_scramble `int vc_dsp_spectral_scramble(const float *samples, size_t num_samples,
                          ...`
- Defined: `voicecloak/src/vc_dsp.c:160`

### trim_edges `static void trim_edges(float **buf, size_t *len)`
- Defined: `voicecloak/src/vc_dsp.c:233`

### normalize_rms `static void normalize_rms(const float *in, size_t in_len,
                          float *out, s...`
- Defined: `voicecloak/src/vc_dsp.c:254`

### vc_dsp_cloak `int vc_dsp_cloak(const float *samples, size_t num_samples,
                 uint32_t sample_rate,...`
- Defined: `voicecloak/src/vc_dsp.c:271`

## voicecloak/src/vc_fft.c

### bit_reverse `static unsigned int bit_reverse(unsigned int x, unsigned int bits)`
- Defined: `voicecloak/src/vc_fft.c:9`
- Doc: ifndef M_PI define M_PI 3.14159265358979323846f endif

### bit_reverse_reorder `static void bit_reverse_reorder(size_t n, float *real, float *imag)`
- Defined: `voicecloak/src/vc_fft.c:19`

### vc_fft `void vc_fft(size_t n, float *real, float *imag, int inverse)`
- Defined: `voicecloak/src/vc_fft.c:35`

## voicecloak/src/vc_rt.c

### vc_rt_create `vc_rt_ctx_t *vc_rt_create(size_t nbins, vc_rt_params_t params)`
- Defined: `voicecloak/src/vc_rt.c:22`

### vc_rt_destroy `void vc_rt_destroy(vc_rt_ctx_t *c)`
- Defined: `voicecloak/src/vc_rt.c:42`

### vc_rt_reset `void vc_rt_reset(vc_rt_ctx_t *c)`
- Defined: `voicecloak/src/vc_rt.c:53`

### vc_rt_semitones_to_ratio `float vc_rt_semitones_to_ratio(float semitones)`
- Defined: `voicecloak/src/vc_rt.c:60`

### wrap_pi `static double wrap_pi(double x)`
- Defined: `voicecloak/src/vc_rt.c:64`

### formant_warp `static void formant_warp(float *syn_mag, size_t nbins, float factor)`
- Defined: `voicecloak/src/vc_rt.c:70`

### vc_rt_transform `void vc_rt_transform(float *mag, float *phase, size_t nbins,
                     uint32_t sample...`
- Defined: `voicecloak/src/vc_rt.c:105`

## voicecloak/src/vc_rt_cli.c

### on_sigint `static void on_sigint(int sig)`
- Defined: `voicecloak/src/vc_rt_cli.c:20`

### print_usage `static void print_usage(const char *prog)`
- Defined: `voicecloak/src/vc_rt_cli.c:25`

### dominant_freq `static float dominant_freq(const float *x, size_t n, unsigned int sr)`
- Defined: `voicecloak/src/vc_rt_cli.c:57`

### cmd_selftest `static int cmd_selftest(void)`
- Defined: `voicecloak/src/vc_rt_cli.c:80`

### resolve_params `static int resolve_params(int have_fixed, float semis, float formant,
                          f...`
- Defined: `voicecloak/src/vc_rt_cli.c:118`

### cmd_live `static int cmd_live(int argc, char *argv[])`
- Defined: `voicecloak/src/vc_rt_cli.c:141`

### main `int main(int argc, char *argv[])`
- Defined: `voicecloak/src/vc_rt_cli.c:222`

## voicecloak/src/vc_rt_seed.c

### vc_rt_derive `int vc_rt_derive(const unsigned char *pitch_seed,
                 const unsigned char *formant_s...`
- Defined: `voicecloak/src/vc_rt_seed.c:4`
- Doc: include "vc_rt.h" include "vc_crypto.h" include <math.h>

## voicecloak/src/vc_stft.c

### vc_stft_create `vc_stft_t *vc_stft_create(size_t fft_size, size_t hop_size)`
- Defined: `voicecloak/src/vc_stft.c:20`

### vc_stft_destroy `void vc_stft_destroy(vc_stft_t *st)`
- Defined: `voicecloak/src/vc_stft.c:57`

### vc_stft_num_bins `size_t vc_stft_num_bins(const vc_stft_t *st)`
- Defined: `voicecloak/src/vc_stft.c:66`

### vc_stft_forward `int vc_stft_forward(vc_stft_t *st,
                    const float *samples, size_t num_samples,
...`
- Defined: `voicecloak/src/vc_stft.c:70`

### vc_stft_inverse `int vc_stft_inverse(vc_stft_t *st,
                    const float *mag, const float *phase,
    ...`
- Defined: `voicecloak/src/vc_stft.c:118`

### vc_stft_inverse_hop `int vc_stft_inverse_hop(vc_stft_t *st,
                        const float *mag, const float *pha...`
- Defined: `voicecloak/src/vc_stft.c:126`

## voicecloak/src/vc_stream.c

### is_pow2 `static int is_pow2(size_t v)`
- Defined: `voicecloak/src/vc_stream.c:30`

### vc_stream_create `vc_stream_t *vc_stream_create(size_t fft_size, size_t hop_size,
                              uin...`
- Defined: `voicecloak/src/vc_stream.c:34`

### vc_stream_destroy `void vc_stream_destroy(vc_stream_t *st)`
- Defined: `voicecloak/src/vc_stream.c:93`

### vc_stream_latency_samples `size_t vc_stream_latency_samples(const vc_stream_t *st)`
- Defined: `voicecloak/src/vc_stream.c:106`

### process_frame `static void process_frame(vc_stream_t *st, vc_spectral_fn fn, void *user)`
- Defined: `voicecloak/src/vc_stream.c:110`

### vc_stream_process `int vc_stream_process(vc_stream_t *st,
                      const float *in, float *out, size_t ...`
- Defined: `voicecloak/src/vc_stream.c:158`

## voicecloak/src/vc_wav.c

### read_bytes `static int read_bytes(FILE *fp, void *buf, size_t n)`
- Defined: `voicecloak/src/vc_wav.c:29`
- Doc: pragma pack(pop)

### write_bytes `static int write_bytes(FILE *fp, const void *buf, size_t n)`
- Defined: `voicecloak/src/vc_wav.c:33`

### sample_to_float `static float sample_to_float(const unsigned char *p, int bps)`
- Defined: `voicecloak/src/vc_wav.c:37`

### float_to_sample `static void float_to_sample(float f, unsigned char *p, int bps)`
- Defined: `voicecloak/src/vc_wav.c:61`

### find_chunk `static int find_chunk(FILE *fp, const char *id, uint32_t *size)`
- Defined: `voicecloak/src/vc_wav.c:77`

### vc_wav_read `int vc_wav_read(const char *path,
                float **samples_out, size_t *num_samples_out,
 ...`
- Defined: `voicecloak/src/vc_wav.c:92`

### vc_wav_write `int vc_wav_write(const char *path,
                 const float *samples, size_t num_samples,
   ...`
- Defined: `voicecloak/src/vc_wav.c:168`

## voicecloak/tests/test_vc_fft.c

### test_fft_identity `static void test_fft_identity(void **state)`
- Defined: `voicecloak/tests/test_vc_fft.c:9`
- Doc: include <stdarg.h> include <stddef.h> include <setjmp.h> include <cmocka.h> include <stdlib.h> include <math.h> include 

### test_fft_dc_signal `static void test_fft_dc_signal(void **state)`
- Defined: `voicecloak/tests/test_vc_fft.c:26`

### test_fft_sine `static void test_fft_sine(void **state)`
- Defined: `voicecloak/tests/test_vc_fft.c:46`

### main `int main(void)`
- Defined: `voicecloak/tests/test_vc_fft.c:75`

## voicecloak/tests/test_vc_stream.c

### gen_sines `static void gen_sines(float *buf, size_t n, uint32_t sr,
                      const float *freqs...`
- Defined: `voicecloak/tests/test_vc_stream.c:19`
- Doc: define SR 48000U

### dominant_freq `static float dominant_freq(const float *x, size_t n, uint32_t sr)`
- Defined: `voicecloak/tests/test_vc_stream.c:31`

### rms `static float rms(const float *x, size_t n)`
- Defined: `voicecloak/tests/test_vc_stream.c:53`

### run_stream `static void run_stream(vc_stream_t *st, const float *in, float *out, size_t n,
                  ...`
- Defined: `voicecloak/tests/test_vc_stream.c:63`
- Doc: Stream a whole buffer through the engine in small, irregular chunks * to exercise arbitrary block sizes.

### test_create_validation `static void test_create_validation(void **state)`
- Defined: `voicecloak/tests/test_vc_stream.c:73`

### test_passthrough_identity `static void test_passthrough_identity(void **state)`
- Defined: `voicecloak/tests/test_vc_stream.c:85`

### run_pitch `static void run_pitch(float in_freq, float ratio, float expect_freq)`
- Defined: `voicecloak/tests/test_vc_stream.c:121`

### test_pitch_up_octave `static void test_pitch_up_octave(void **state)`
- Defined: `voicecloak/tests/test_vc_stream.c:145`

### test_pitch_down_octave `static void test_pitch_down_octave(void **state)`
- Defined: `voicecloak/tests/test_vc_stream.c:150`

### test_bounded_output `static void test_bounded_output(void **state)`
- Defined: `voicecloak/tests/test_vc_stream.c:155`

### main `int main(void)`
- Defined: `voicecloak/tests/test_vc_stream.c:184`
