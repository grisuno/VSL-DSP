# API

## audiobox_vsl.c

### audiobox_probe (function) `static int audiobox_probe(struct usb_interface *intf,
                          const struct usb_...`
- Defined: `audiobox_vsl.c:36`
- Depends on: `audiobox_vsl.h`

### audiobox_disconnect (function) `static void audiobox_disconnect(struct usb_interface *intf)`
- Defined: `audiobox_vsl.c:58`
- Depends on: `audiobox_vsl.h`

### dev_info (function) `dev_info(&intf->dev, "audiobox_vsl: detected '%s' (%04x:%04x)\n", name, le16_to_cpu(udev->descriptor.idVendor), pid);`
- Defined: `audiobox_vsl.c:47`
- Depends on: `audiobox_vsl.h`

### module_usb_driver (function) `module_usb_driver(audiobox_driver);`
- Defined: `audiobox_vsl.c:78`
- Depends on: `audiobox_vsl.h`

### MODULE_LICENSE (function) `MODULE_LICENSE(AUDIOBOX_DRIVER_LIC);`
- Defined: `audiobox_vsl.c:80`
- Depends on: `audiobox_vsl.h`

## audiobox_vsl.h

### audiobox_lookup_model (function) `static inline const audiobox_model_info_t *
audiobox_lookup_model(uint16_t pid)`
- Defined: `audiobox_vsl.h:95`
- Doc: @brief Look up the model info entry for a given USB product ID.  @param pid 16-bit product ID reported by the USB device
- Imported by: `audiobox_vsl.c`, `legacy/mixer_quirks.c`, `tests/test_audiobox_vsl.c`

### snd_audiobox_vsl_init (function) `int snd_audiobox_vsl_init(struct usb_mixer_interface *mixer);`
- Defined: `audiobox_vsl.h:122`
- Doc: @brief ALSA mixer init hook for AudioBox VSL devices.  Optional entry point used by the upstream sound/usb/mixer_quirks.
- Imported by: `audiobox_vsl.c`, `legacy/mixer_quirks.c`, `tests/test_audiobox_vsl.c`

## legacy/build-dkms.sh

### print_header (function)
- Defined: `legacy/build-dkms.sh:40`

### print_success (function)
- Defined: `legacy/build-dkms.sh:48`

### print_error (function)
- Defined: `legacy/build-dkms.sh:52`

### print_warning (function)
- Defined: `legacy/build-dkms.sh:56`

### print_info (function)
- Defined: `legacy/build-dkms.sh:60`

### check_root (function)
- Defined: `legacy/build-dkms.sh:64`

### check_dependencies (function)
- Defined: `legacy/build-dkms.sh:72`

### detect_audiobox (function)
- Defined: `legacy/build-dkms.sh:101`

### create_source_structure (function)
- Defined: `legacy/build-dkms.sh:123`

### copy_source_files (function)
- Defined: `legacy/build-dkms.sh:138`

### create_dkms_conf (function)
- Defined: `legacy/build-dkms.sh:174`

### create_makefile (function)
- Defined: `legacy/build-dkms.sh:193`

### verify_mixer_quirks (function)
- Defined: `legacy/build-dkms.sh:252`

### build_with_dkms (function)
- Defined: `legacy/build-dkms.sh:295`

### install_module (function)
- Defined: `legacy/build-dkms.sh:309`

### reload_module (function)
- Defined: `legacy/build-dkms.sh:323`

### verify_installation (function)
- Defined: `legacy/build-dkms.sh:344`

### show_usage_info (function)
- Defined: `legacy/build-dkms.sh:394`

### main (function)
- Defined: `legacy/build-dkms.sh:452`

## legacy/main.c

### main (function) `int main()`
- Defined: `legacy/main.c:4`
- Doc: include <stdio.h> include "vsl_dsp_logic.h" include "vsl_dsp_transport.h"
- Depends on: `legacy/vsl_dsp_logic.h`, `legacy/vsl_dsp_transport.h`

### printf (function) `printf("--- Ganancia ---\n");`
- Defined: `legacy/main.c:36`
- Depends on: `legacy/vsl_dsp_logic.h`, `legacy/vsl_dsp_transport.h`

### VSL_Build_And_Send_Packet (function) `VSL_Build_And_Send_Packet(gain_id, encoded_gain_float);`
- Defined: `legacy/main.c:68`
- Doc: *********************************************************** *** ¡Llamada para Enviar el Paquete DSP a través de HIDAPI! 
- Depends on: `legacy/vsl_dsp_logic.h`, `legacy/vsl_dsp_transport.h`

## legacy/mixer_quirks.c

### snd_create_std_mono_ctl_offset (function) `static int snd_create_std_mono_ctl_offset(struct usb_mixer_interface *mixer,
					  unsigned int ...`
- Defined: `legacy/mixer_quirks.c:59`
- Doc: This function allows for the creation of standard UAC controls. See the quirks for M-Audio FTUs or Ebox-44. If you don't
- Depends on: `audiobox_vsl.h`

### snd_create_std_mono_ctl (function) `static int snd_create_std_mono_ctl(struct usb_mixer_interface *mixer,
				   unsigned int unitid,...`
- Defined: `legacy/mixer_quirks.c:112`
- Depends on: `audiobox_vsl.h`

### snd_create_std_mono_table (function) `static int snd_create_std_mono_table(struct usb_mixer_interface *mixer,
				     const struct std...`
- Defined: `legacy/mixer_quirks.c:129`
- Doc: Create a set of standard UAC controls from a table
- Depends on: `audiobox_vsl.h`

### add_single_ctl_with_resume (function) `static int add_single_ctl_with_resume(struct usb_mixer_interface *mixer,
				      int id,
				  ...`
- Defined: `legacy/mixer_quirks.c:145`
- Depends on: `audiobox_vsl.h`

### snd_usb_soundblaster_remote_complete (function) `static void snd_usb_soundblaster_remote_complete(struct urb *urb)`
- Defined: `legacy/mixer_quirks.c:199`
- Depends on: `audiobox_vsl.h`

### snd_usb_sbrc_hwdep_read (function) `static long snd_usb_sbrc_hwdep_read(struct snd_hwdep *hw, char __user *buf,
				    long count, l...`
- Defined: `legacy/mixer_quirks.c:219`
- Depends on: `audiobox_vsl.h`

### snd_usb_sbrc_hwdep_poll (function) `static __poll_t snd_usb_sbrc_hwdep_poll(struct snd_hwdep *hw, struct file *file,
					poll_table ...`
- Defined: `legacy/mixer_quirks.c:239`
- Depends on: `audiobox_vsl.h`

### snd_usb_soundblaster_remote_init (function) `static int snd_usb_soundblaster_remote_init(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:248`
- Depends on: `audiobox_vsl.h`

### snd_audigy2nx_led_get (function) `static int snd_audigy2nx_led_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)`
- Defined: `legacy/mixer_quirks.c:298`
- Doc: define snd_audigy2nx_led_info		snd_ctl_boolean_mono_info
- Depends on: `audiobox_vsl.h`

### snd_audigy2nx_led_update (function) `static int snd_audigy2nx_led_update(struct usb_mixer_interface *mixer,
				    int value, int index)`
- Defined: `legacy/mixer_quirks.c:304`
- Depends on: `audiobox_vsl.h`

### snd_audigy2nx_led_put (function) `static int snd_audigy2nx_led_put(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_value *u...`
- Defined: `legacy/mixer_quirks.c:333`
- Depends on: `audiobox_vsl.h`

### snd_audigy2nx_led_resume (function) `static int snd_audigy2nx_led_resume(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:352`
- Depends on: `audiobox_vsl.h`

### snd_audigy2nx_controls_create (function) `static int snd_audigy2nx_controls_create(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:374`
- Depends on: `audiobox_vsl.h`

### snd_audigy2nx_proc_read (function) `static void snd_audigy2nx_proc_read(struct snd_info_entry *entry,
				    struct snd_info_buffer ...`
- Defined: `legacy/mixer_quirks.c:406`
- Depends on: `audiobox_vsl.h`

### snd_emu0204_ch_switch_info (function) `static int snd_emu0204_ch_switch_info(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_ele...`
- Defined: `legacy/mixer_quirks.c:457`
- Doc: return; err = snd_usb_ctl_msg(mixer->chip->dev, usb_rcvctrlpipe(mixer->chip->dev, 0), UAC_GET_MEM, USB_DIR_IN | USB_TYPE
- Depends on: `audiobox_vsl.h`

### snd_emu0204_ch_switch_get (function) `static int snd_emu0204_ch_switch_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- Defined: `legacy/mixer_quirks.c:464`
- Depends on: `audiobox_vsl.h`

### snd_emu0204_ch_switch_update (function) `static int snd_emu0204_ch_switch_update(struct usb_mixer_interface *mixer,
					int value)`
- Defined: `legacy/mixer_quirks.c:471`
- Depends on: `audiobox_vsl.h`

### snd_emu0204_ch_switch_put (function) `static int snd_emu0204_ch_switch_put(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- Defined: `legacy/mixer_quirks.c:489`
- Depends on: `audiobox_vsl.h`

### snd_emu0204_ch_switch_resume (function) `static int snd_emu0204_ch_switch_resume(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:508`
- Depends on: `audiobox_vsl.h`

### snd_emu0204_controls_create (function) `static int snd_emu0204_controls_create(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:523`
- Depends on: `audiobox_vsl.h`

### snd_dualsense_ih_event (function) `static void snd_dualsense_ih_event(struct input_handle *handle,
				   unsigned int type, unsigne...`
- Defined: `legacy/mixer_quirks.c:549`
- Depends on: `audiobox_vsl.h`

### snd_dualsense_ih_match (function) `static bool snd_dualsense_ih_match(struct input_handler *handler,
				   struct input_dev *dev)`
- Defined: `legacy/mixer_quirks.c:570`
- Depends on: `audiobox_vsl.h`

### snd_dualsense_ih_connect (function) `static int snd_dualsense_ih_connect(struct input_handler *handler,
				    struct input_dev *dev,...`
- Defined: `legacy/mixer_quirks.c:617`
- Depends on: `audiobox_vsl.h`

### snd_dualsense_ih_disconnect (function) `static void snd_dualsense_ih_disconnect(struct input_handle *handle)`
- Defined: `legacy/mixer_quirks.c:649`
- Depends on: `audiobox_vsl.h`

### snd_dualsense_ih_start (function) `static void snd_dualsense_ih_start(struct input_handle *handle)`
- Defined: `legacy/mixer_quirks.c:656`
- Depends on: `audiobox_vsl.h`

### snd_dualsense_jack_get (function) `static int snd_dualsense_jack_get(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...`
- Defined: `legacy/mixer_quirks.c:679`
- Depends on: `audiobox_vsl.h`

### snd_dualsense_resume_jack (function) `static int snd_dualsense_resume_jack(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:696`
- Depends on: `audiobox_vsl.h`

### snd_dualsense_mixer_elem_free (function) `static void snd_dualsense_mixer_elem_free(struct snd_kcontrol *kctl)`
- Defined: `legacy/mixer_quirks.c:703`
- Depends on: `audiobox_vsl.h`

### snd_dualsense_jack_create (function) `static int snd_dualsense_jack_create(struct usb_mixer_interface *mixer,
				     const char *name...`
- Defined: `legacy/mixer_quirks.c:713`
- Depends on: `audiobox_vsl.h`

### snd_dualsense_controls_create (function) `static int snd_dualsense_controls_create(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:777`
- Depends on: `audiobox_vsl.h`

### snd_xonar_u1_switch_get (function) `static int snd_xonar_u1_switch_get(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...`
- Defined: `legacy/mixer_quirks.c:791`
- Doc: static int snd_dualsense_controls_create(struct usb_mixer_interface *mixer) { int err; err = snd_dualsense_jack_create(m
- Depends on: `audiobox_vsl.h`

### snd_xonar_u1_switch_update (function) `static int snd_xonar_u1_switch_update(struct usb_mixer_interface *mixer,
				      unsigned char ...`
- Defined: `legacy/mixer_quirks.c:798`
- Depends on: `audiobox_vsl.h`

### snd_xonar_u1_switch_put (function) `static int snd_xonar_u1_switch_put(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...`
- Defined: `legacy/mixer_quirks.c:812`
- Depends on: `audiobox_vsl.h`

### snd_xonar_u1_switch_resume (function) `static int snd_xonar_u1_switch_resume(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:832`
- Depends on: `audiobox_vsl.h`

### snd_xonar_u1_controls_create (function) `static int snd_xonar_u1_controls_create(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:847`
- Depends on: `audiobox_vsl.h`

### snd_mbox1_is_spdif_synced (function) `static int snd_mbox1_is_spdif_synced(struct snd_usb_audio *chip)`
- Defined: `legacy/mixer_quirks.c:856`
- Doc: .info = snd_ctl_boolean_mono_info, .get = snd_xonar_u1_switch_get, .put = snd_xonar_u1_switch_put, .private_value = 0x05
- Depends on: `audiobox_vsl.h`

### snd_mbox1_set_clk_source (function) `static int snd_mbox1_set_clk_source(struct snd_usb_audio *chip, int rate_or_zero)`
- Defined: `legacy/mixer_quirks.c:876`
- Depends on: `audiobox_vsl.h`

### snd_mbox1_is_spdif_input (function) `static int snd_mbox1_is_spdif_input(struct snd_usb_audio *chip)`
- Defined: `legacy/mixer_quirks.c:894`
- Depends on: `audiobox_vsl.h`

### snd_mbox1_set_input_source (function) `static int snd_mbox1_set_input_source(struct snd_usb_audio *chip, int is_spdif)`
- Defined: `legacy/mixer_quirks.c:914`
- Depends on: `audiobox_vsl.h`

### snd_mbox1_clk_switch_get (function) `static int snd_mbox1_clk_switch_get(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...`
- Defined: `legacy/mixer_quirks.c:933`
- Doc: S/PDIF Source  -> 0x02  unsigned char buff[1]; buff[0] = (is_spdif & 1) + 1; /* Set input source return snd_usb_ctl_msg(
- Depends on: `audiobox_vsl.h`

### snd_mbox1_clk_switch_update (function) `static int snd_mbox1_clk_switch_update(struct usb_mixer_interface *mixer, int is_spdif_sync)`
- Defined: `legacy/mixer_quirks.c:953`
- Depends on: `audiobox_vsl.h`

### snd_mbox1_clk_switch_put (function) `static int snd_mbox1_clk_switch_put(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...`
- Defined: `legacy/mixer_quirks.c:978`
- Depends on: `audiobox_vsl.h`

### snd_mbox1_clk_switch_info (function) `static int snd_mbox1_clk_switch_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- Defined: `legacy/mixer_quirks.c:996`
- Depends on: `audiobox_vsl.h`

### snd_mbox1_clk_switch_resume (function) `static int snd_mbox1_clk_switch_resume(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:1007`
- Depends on: `audiobox_vsl.h`

### snd_mbox1_src_switch_get (function) `static int snd_mbox1_src_switch_get(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...`
- Defined: `legacy/mixer_quirks.c:1014`
- Doc: static const char *const texts[2] = { "Internal", "S/PDIF" }; return snd_ctl_enum_info(uinfo, 1, ARRAY_SIZE(texts), text
- Depends on: `audiobox_vsl.h`

### snd_mbox1_src_switch_update (function) `static int snd_mbox1_src_switch_update(struct usb_mixer_interface *mixer, int is_spdif_input)`
- Defined: `legacy/mixer_quirks.c:1021`
- Depends on: `audiobox_vsl.h`

### snd_mbox1_src_switch_put (function) `static int snd_mbox1_src_switch_put(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...`
- Defined: `legacy/mixer_quirks.c:1045`
- Depends on: `audiobox_vsl.h`

### snd_mbox1_src_switch_info (function) `static int snd_mbox1_src_switch_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- Defined: `legacy/mixer_quirks.c:1063`
- Depends on: `audiobox_vsl.h`

### snd_mbox1_src_switch_resume (function) `static int snd_mbox1_src_switch_resume(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:1074`
- Depends on: `audiobox_vsl.h`

### snd_mbox1_controls_create (function) `static int snd_mbox1_controls_create(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1101`
- Depends on: `audiobox_vsl.h`

### snd_ni_control_init_val (function) `static int snd_ni_control_init_val(struct usb_mixer_interface *mixer,
				   struct snd_kcontrol ...`
- Defined: `legacy/mixer_quirks.c:1120`
- Doc: define _MAKE_NI_CONTROL(bRequest, wIndex) ((bRequest) << 16 | (wIndex))
- Depends on: `audiobox_vsl.h`

### snd_nativeinstruments_control_get (function) `static int snd_nativeinstruments_control_get(struct snd_kcontrol *kcontrol,
					     struct snd_...`
- Defined: `legacy/mixer_quirks.c:1142`
- Depends on: `audiobox_vsl.h`

### snd_ni_update_cur_val (function) `static int snd_ni_update_cur_val(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:1149`
- Depends on: `audiobox_vsl.h`

### snd_nativeinstruments_control_put (function) `static int snd_nativeinstruments_control_put(struct snd_kcontrol *kcontrol,
					     struct snd_...`
- Defined: `legacy/mixer_quirks.c:1163`
- Depends on: `audiobox_vsl.h`

### snd_nativeinstruments_create_mixer (function) `static int snd_nativeinstruments_create_mixer(struct usb_mixer_interface *mixer,
					      const...`
- Defined: `legacy/mixer_quirks.c:1234`
- Depends on: `audiobox_vsl.h`

### snd_ftu_eff_switch_info (function) `static int snd_ftu_eff_switch_info(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_info...`
- Defined: `legacy/mixer_quirks.c:1267`
- Doc: err = add_single_ctl_with_resume(mixer, 0, snd_ni_update_cur_val, &template, &list); if (err < 0) break; snd_ni_control_
- Depends on: `audiobox_vsl.h`

### snd_ftu_eff_switch_init (function) `static int snd_ftu_eff_switch_init(struct usb_mixer_interface *mixer,
				   struct snd_kcontrol ...`
- Defined: `legacy/mixer_quirks.c:1277`
- Depends on: `audiobox_vsl.h`

### snd_ftu_eff_switch_get (function) `static int snd_ftu_eff_switch_get(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...`
- Defined: `legacy/mixer_quirks.c:1300`
- Depends on: `audiobox_vsl.h`

### snd_ftu_eff_switch_update (function) `static int snd_ftu_eff_switch_update(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:1307`
- Depends on: `audiobox_vsl.h`

### snd_ftu_eff_switch_put (function) `static int snd_ftu_eff_switch_put(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...`
- Defined: `legacy/mixer_quirks.c:1328`
- Depends on: `audiobox_vsl.h`

### snd_ftu_create_effect_switch (function) `static int snd_ftu_create_effect_switch(struct usb_mixer_interface *mixer,
					int validx, int b...`
- Defined: `legacy/mixer_quirks.c:1346`
- Depends on: `audiobox_vsl.h`

### snd_ftu_create_volume_ctls (function) `static int snd_ftu_create_volume_ctls(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1373`
- Doc: struct usb_mixer_elem_list *list; int err; err = add_single_ctl_with_resume(mixer, bUnitID, snd_ftu_eff_switch_update, &
- Depends on: `audiobox_vsl.h`

### snd_ftu_create_effect_volume_ctl (function) `static int snd_ftu_create_effect_volume_ctl(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1412`
- Doc: "DIn%d - Out%d Playback Volume", in - 7, out + 1); err = snd_create_std_mono_ctl(mixer, id, control, cmask, val_type, na
- Depends on: `audiobox_vsl.h`

### snd_ftu_create_effect_duration_ctl (function) `static int snd_ftu_create_effect_duration_ctl(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1425`
- Doc: /* This control needs a volume quirk, see mixer.c static int snd_ftu_create_effect_volume_ctl(struct usb_mixer_interface
- Depends on: `audiobox_vsl.h`

### snd_ftu_create_effect_feedback_ctl (function) `static int snd_ftu_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1438`
- Doc: /* This control needs a volume quirk, see mixer.c static int snd_ftu_create_effect_duration_ctl(struct usb_mixer_interfa
- Depends on: `audiobox_vsl.h`

### snd_ftu_create_effect_return_ctls (function) `static int snd_ftu_create_effect_return_ctls(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1449`
- Depends on: `audiobox_vsl.h`

### snd_ftu_create_effect_send_ctls (function) `static int snd_ftu_create_effect_send_ctls(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1473`
- Depends on: `audiobox_vsl.h`

### snd_ftu_create_mixer (function) `static int snd_ftu_create_mixer(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1506`
- Depends on: `audiobox_vsl.h`

### snd_emuusb_set_samplerate (function) `void snd_emuusb_set_samplerate(struct snd_usb_audio *chip,
			       unsigned char samplerate_id)`
- Defined: `legacy/mixer_quirks.c:1541`
- Depends on: `audiobox_vsl.h`

### list_for_each_entry (function) `list_for_each_entry(mixer, &chip->mixer_list, list)`
- Defined: `legacy/mixer_quirks.c:1548`
- Doc: err = snd_ftu_create_effect_send_ctls(mixer); if (err < 0) return err; return 0; } void snd_emuusb_set_samplerate(struct
- Depends on: `audiobox_vsl.h`

### snd_c400_create_vol_ctls (function) `static int snd_c400_create_vol_ctls(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1563`
- Doc: list_for_each_entry(mixer, &chip->mixer_list, list) { if (mixer->id_elems[unitid]) { cval = mixer_elem_list_to_info(mixe
- Depends on: `audiobox_vsl.h`

### snd_c400_create_effect_volume_ctl (function) `static int snd_c400_create_effect_volume_ctl(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1612`
- Doc: cmask = (out == 0) ? 0 : BIT(out - 1); offset = chan * num_outs; err = snd_create_std_mono_ctl_offset(mixer, id, control
- Depends on: `audiobox_vsl.h`

### snd_c400_create_effect_duration_ctl (function) `static int snd_c400_create_effect_duration_ctl(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1625`
- Doc: /* This control needs a volume quirk, see mixer.c static int snd_c400_create_effect_volume_ctl(struct usb_mixer_interfac
- Depends on: `audiobox_vsl.h`

### snd_c400_create_effect_feedback_ctl (function) `static int snd_c400_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1638`
- Doc: /* This control needs a volume quirk, see mixer.c static int snd_c400_create_effect_duration_ctl(struct usb_mixer_interf
- Depends on: `audiobox_vsl.h`

### snd_c400_create_effect_vol_ctls (function) `static int snd_c400_create_effect_vol_ctls(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1649`
- Depends on: `audiobox_vsl.h`

### snd_c400_create_effect_ret_vol_ctls (function) `static int snd_c400_create_effect_ret_vol_ctls(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1694`
- Depends on: `audiobox_vsl.h`

### snd_c400_create_mixer (function) `static int snd_c400_create_mixer(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:1736`
- Depends on: `audiobox_vsl.h`

### snd_microii_spdif_info (function) `static int snd_microii_spdif_info(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_info *...`
- Defined: `legacy/mixer_quirks.c:1869`
- Doc: power on values: r2: 0x10 r3: 0x20 (b7 is zeroed just before playback (except IEC61937) and set just after it to 0xa0, p
- Depends on: `audiobox_vsl.h`

### snd_microii_spdif_default_get (function) `static int snd_microii_spdif_default_get(struct snd_kcontrol *kcontrol,
					 struct snd_ctl_elem...`
- Defined: `legacy/mixer_quirks.c:1876`
- Depends on: `audiobox_vsl.h`

### snd_microii_spdif_default_update (function) `static int snd_microii_spdif_default_update(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:1923`
- Depends on: `audiobox_vsl.h`

### snd_microii_spdif_default_put (function) `static int snd_microii_spdif_default_put(struct snd_kcontrol *kcontrol,
					 struct snd_ctl_elem...`
- Defined: `legacy/mixer_quirks.c:1959`
- Depends on: `audiobox_vsl.h`

### snd_microii_spdif_mask_get (function) `static int snd_microii_spdif_mask_get(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_ele...`
- Defined: `legacy/mixer_quirks.c:1987`
- Depends on: `audiobox_vsl.h`

### snd_microii_spdif_switch_get (function) `static int snd_microii_spdif_switch_get(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_v...`
- Defined: `legacy/mixer_quirks.c:1998`
- Depends on: `audiobox_vsl.h`

### snd_microii_spdif_switch_update (function) `static int snd_microii_spdif_switch_update(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:2006`
- Depends on: `audiobox_vsl.h`

### snd_microii_spdif_switch_put (function) `static int snd_microii_spdif_switch_put(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_v...`
- Defined: `legacy/mixer_quirks.c:2025`
- Depends on: `audiobox_vsl.h`

### snd_microii_controls_create (function) `static int snd_microii_controls_create(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:2067`
- Depends on: `audiobox_vsl.h`

### snd_soundblaster_e1_switch_get (function) `static int snd_soundblaster_e1_switch_get(struct snd_kcontrol *kcontrol,
					  struct snd_ctl_el...`
- Defined: `legacy/mixer_quirks.c:2090`
- Doc: for (i = 0; i < ARRAY_SIZE(snd_microii_mixer_spdif); ++i) { err = add_single_ctl_with_resume(mixer, 0, resume_funcs[i], 
- Depends on: `audiobox_vsl.h`

### snd_soundblaster_e1_switch_update (function) `static int snd_soundblaster_e1_switch_update(struct usb_mixer_interface *mixer,
					     unsigne...`
- Defined: `legacy/mixer_quirks.c:2097`
- Depends on: `audiobox_vsl.h`

### snd_soundblaster_e1_switch_put (function) `static int snd_soundblaster_e1_switch_put(struct snd_kcontrol *kcontrol,
					  struct snd_ctl_el...`
- Defined: `legacy/mixer_quirks.c:2115`
- Depends on: `audiobox_vsl.h`

### snd_soundblaster_e1_switch_resume (function) `static int snd_soundblaster_e1_switch_resume(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:2129`
- Depends on: `audiobox_vsl.h`

### snd_soundblaster_e1_switch_info (function) `static int snd_soundblaster_e1_switch_info(struct snd_kcontrol *kcontrol,
					   struct snd_ctl_...`
- Defined: `legacy/mixer_quirks.c:2135`
- Depends on: `audiobox_vsl.h`

### snd_soundblaster_e1_switch_create (function) `static int snd_soundblaster_e1_switch_create(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:2154`
- Depends on: `audiobox_vsl.h`

### realtek_hda_set (function) `static int realtek_hda_set(struct snd_usb_audio *chip, u32 cmd)`
- Defined: `legacy/mixer_quirks.c:2191`
- Doc: define REALTEK_MIC_FLAG 0x100
- Depends on: `audiobox_vsl.h`

### realtek_hda_get (function) `static int realtek_hda_get(struct snd_usb_audio *chip, u32 cmd, u32 *value)`
- Defined: `legacy/mixer_quirks.c:2201`
- Depends on: `audiobox_vsl.h`

### realtek_ctl_connector_get (function) `static int realtek_ctl_connector_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- Defined: `legacy/mixer_quirks.c:2222`
- Depends on: `audiobox_vsl.h`

### realtek_resume_jack (function) `static int realtek_resume_jack(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:2272`
- Depends on: `audiobox_vsl.h`

### realtek_add_jack (function) `static int realtek_add_jack(struct usb_mixer_interface *mixer,
			    char *name, u32 val)`
- Defined: `legacy/mixer_quirks.c:2279`
- Depends on: `audiobox_vsl.h`

### dell_dock_mixer_create (function) `static int dell_dock_mixer_create(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:2306`
- Depends on: `audiobox_vsl.h`

### dell_dock_init_vol (function) `static void dell_dock_init_vol(struct usb_mixer_interface *mixer, int ch, int id)`
- Defined: `legacy/mixer_quirks.c:2338`
- Depends on: `audiobox_vsl.h`

### dell_dock_mixer_init (function) `static int dell_dock_mixer_init(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:2350`
- Depends on: `audiobox_vsl.h`

### snd_rme_read_value (function) `static int snd_rme_read_value(struct snd_usb_audio *chip,
			      unsigned int item,
			      u3...`
- Defined: `legacy/mixer_quirks.c:2418`
- Depends on: `audiobox_vsl.h`

### snd_rme_get_status1 (function) `static int snd_rme_get_status1(struct snd_kcontrol *kcontrol,
			       u32 *status1)`
- Defined: `legacy/mixer_quirks.c:2437`
- Depends on: `audiobox_vsl.h`

### snd_rme_rate_get (function) `static int snd_rme_rate_get(struct snd_kcontrol *kcontrol,
			    struct snd_ctl_elem_value *ucon...`
- Defined: `legacy/mixer_quirks.c:2449`
- Depends on: `audiobox_vsl.h`

### snd_rme_sync_state_get (function) `static int snd_rme_sync_state_get(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_value ...`
- Defined: `legacy/mixer_quirks.c:2483`
- Depends on: `audiobox_vsl.h`

### snd_rme_spdif_if_get (function) `static int snd_rme_spdif_if_get(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *uco...`
- Defined: `legacy/mixer_quirks.c:2513`
- Depends on: `audiobox_vsl.h`

### snd_rme_spdif_format_get (function) `static int snd_rme_spdif_format_get(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_va...`
- Defined: `legacy/mixer_quirks.c:2526`
- Depends on: `audiobox_vsl.h`

### snd_rme_sync_source_get (function) `static int snd_rme_sync_source_get(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...`
- Defined: `legacy/mixer_quirks.c:2539`
- Depends on: `audiobox_vsl.h`

### snd_rme_current_freq_get (function) `static int snd_rme_current_freq_get(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_va...`
- Defined: `legacy/mixer_quirks.c:2552`
- Depends on: `audiobox_vsl.h`

### snd_rme_rate_info (function) `static int snd_rme_rate_info(struct snd_kcontrol *kcontrol,
			     struct snd_ctl_elem_info *uinfo)`
- Defined: `legacy/mixer_quirks.c:2578`
- Depends on: `audiobox_vsl.h`

### snd_rme_sync_state_info (function) `static int snd_rme_sync_state_info(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_info...`
- Defined: `legacy/mixer_quirks.c:2598`
- Depends on: `audiobox_vsl.h`

### snd_rme_spdif_if_info (function) `static int snd_rme_spdif_if_info(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_info *ui...`
- Defined: `legacy/mixer_quirks.c:2609`
- Depends on: `audiobox_vsl.h`

### snd_rme_spdif_format_info (function) `static int snd_rme_spdif_format_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- Defined: `legacy/mixer_quirks.c:2620`
- Depends on: `audiobox_vsl.h`

### snd_rme_sync_source_info (function) `static int snd_rme_sync_source_info(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_in...`
- Defined: `legacy/mixer_quirks.c:2631`
- Depends on: `audiobox_vsl.h`

### snd_rme_controls_create (function) `static int snd_rme_controls_create(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:2713`
- Depends on: `audiobox_vsl.h`

### snd_bbfpro_ctl_update (function) `static int snd_bbfpro_ctl_update(struct usb_mixer_interface *mixer, u8 reg,
				 u8 index, u8 value)`
- Defined: `legacy/mixer_quirks.c:2779`
- Doc: define SND_BBFPRO_USBREQ_CTL_REG1 0x10 define SND_BBFPRO_USBREQ_CTL_REG2 0x17 define SND_BBFPRO_USBREQ_GAIN 0x1a define 
- Depends on: `audiobox_vsl.h`

### snd_bbfpro_ctl_get (function) `static int snd_bbfpro_ctl_get(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...`
- Defined: `legacy/mixer_quirks.c:2810`
- Depends on: `audiobox_vsl.h`

### snd_bbfpro_ctl_info (function) `static int snd_bbfpro_ctl_info(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_info ...`
- Defined: `legacy/mixer_quirks.c:2833`
- Depends on: `audiobox_vsl.h`

### snd_bbfpro_ctl_put (function) `static int snd_bbfpro_ctl_put(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...`
- Defined: `legacy/mixer_quirks.c:2867`
- Depends on: `audiobox_vsl.h`

### snd_bbfpro_ctl_resume (function) `static int snd_bbfpro_ctl_resume(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:2906`
- Depends on: `audiobox_vsl.h`

### snd_bbfpro_gain_update (function) `static int snd_bbfpro_gain_update(struct usb_mixer_interface *mixer,
				  u8 channel, u8 gain)`
- Defined: `legacy/mixer_quirks.c:2919`
- Depends on: `audiobox_vsl.h`

### snd_bbfpro_gain_get (function) `static int snd_bbfpro_gain_get(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_value...`
- Defined: `legacy/mixer_quirks.c:2943`
- Depends on: `audiobox_vsl.h`

### snd_bbfpro_gain_info (function) `static int snd_bbfpro_gain_info(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_info *uinfo)`
- Defined: `legacy/mixer_quirks.c:2952`
- Depends on: `audiobox_vsl.h`

### snd_bbfpro_gain_put (function) `static int snd_bbfpro_gain_put(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_value...`
- Defined: `legacy/mixer_quirks.c:2973`
- Depends on: `audiobox_vsl.h`

### snd_bbfpro_gain_resume (function) `static int snd_bbfpro_gain_resume(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:3010`
- Depends on: `audiobox_vsl.h`

### snd_bbfpro_vol_update (function) `static int snd_bbfpro_vol_update(struct usb_mixer_interface *mixer, u16 index,
				 u32 value)`
- Defined: `legacy/mixer_quirks.c:3023`
- Depends on: `audiobox_vsl.h`

### snd_bbfpro_vol_get (function) `static int snd_bbfpro_vol_get(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...`
- Defined: `legacy/mixer_quirks.c:3049`
- Depends on: `audiobox_vsl.h`

### snd_bbfpro_vol_info (function) `static int snd_bbfpro_vol_info(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_info ...`
- Defined: `legacy/mixer_quirks.c:3057`
- Depends on: `audiobox_vsl.h`

### snd_bbfpro_vol_put (function) `static int snd_bbfpro_vol_put(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...`
- Defined: `legacy/mixer_quirks.c:3067`
- Depends on: `audiobox_vsl.h`

### snd_bbfpro_vol_resume (function) `static int snd_bbfpro_vol_resume(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:3095`
- Depends on: `audiobox_vsl.h`

### snd_bbfpro_ctl_add (function) `static int snd_bbfpro_ctl_add(struct usb_mixer_interface *mixer, u8 reg,
			      u8 index, char ...`
- Defined: `legacy/mixer_quirks.c:3132`
- Depends on: `audiobox_vsl.h`

### snd_bbfpro_gain_add (function) `static int snd_bbfpro_gain_add(struct usb_mixer_interface *mixer, u8 channel,
			       char *name)`
- Defined: `legacy/mixer_quirks.c:3146`
- Depends on: `audiobox_vsl.h`

### snd_bbfpro_vol_add (function) `static int snd_bbfpro_vol_add(struct usb_mixer_interface *mixer, u16 index,
			      char *name)`
- Defined: `legacy/mixer_quirks.c:3158`
- Depends on: `audiobox_vsl.h`

### snd_bbfpro_controls_create (function) `static int snd_bbfpro_controls_create(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:3170`
- Depends on: `audiobox_vsl.h`

### snd_rme_digiface_write_reg (function) `static int snd_rme_digiface_write_reg(struct snd_kcontrol *kcontrol, int item, u16 mask, u16 val)`
- Defined: `legacy/mixer_quirks.c:3318`
- Doc: #define RME_DIGIFACE_STATUS_REG2H 5 #define RME_DIGIFACE_STATUS_REG3L 6 #define RME_DIGIFACE_STATUS_REG3H 7 #define RME_
- Depends on: `audiobox_vsl.h`

### snd_rme_digiface_read_status (function) `static int snd_rme_digiface_read_status(struct snd_kcontrol *kcontrol, u32 status[4])`
- Defined: `legacy/mixer_quirks.c:3336`
- Depends on: `audiobox_vsl.h`

### snd_rme_digiface_get_status_val (function) `static int snd_rme_digiface_get_status_val(struct snd_kcontrol *kcontrol)`
- Defined: `legacy/mixer_quirks.c:3360`
- Depends on: `audiobox_vsl.h`

### snd_rme_digiface_rate_get (function) `static int snd_rme_digiface_rate_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- Defined: `legacy/mixer_quirks.c:3398`
- Depends on: `audiobox_vsl.h`

### snd_rme_digiface_enum_get (function) `static int snd_rme_digiface_enum_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- Defined: `legacy/mixer_quirks.c:3412`
- Depends on: `audiobox_vsl.h`

### snd_rme_digiface_enum_put (function) `static int snd_rme_digiface_enum_put(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- Defined: `legacy/mixer_quirks.c:3424`
- Depends on: `audiobox_vsl.h`

### snd_rme_digiface_current_sync_get (function) `static int snd_rme_digiface_current_sync_get(struct snd_kcontrol *kcontrol,
					     struct snd_...`
- Defined: `legacy/mixer_quirks.c:3438`
- Depends on: `audiobox_vsl.h`

### snd_rme_digiface_sync_state_get (function) `static int snd_rme_digiface_sync_state_get(struct snd_kcontrol *kcontrol,
					   struct snd_ctl_...`
- Defined: `legacy/mixer_quirks.c:3450`
- Depends on: `audiobox_vsl.h`

### snd_rme_digiface_format_info (function) `static int snd_rme_digiface_format_info(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_i...`
- Defined: `legacy/mixer_quirks.c:3473`
- Depends on: `audiobox_vsl.h`

### snd_rme_digiface_sync_source_info (function) `static int snd_rme_digiface_sync_source_info(struct snd_kcontrol *kcontrol,
					     struct snd_...`
- Defined: `legacy/mixer_quirks.c:3484`
- Depends on: `audiobox_vsl.h`

### snd_rme_digiface_rate_info (function) `static int snd_rme_digiface_rate_info(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_ele...`
- Defined: `legacy/mixer_quirks.c:3495`
- Depends on: `audiobox_vsl.h`

### snd_rme_digiface_controls_create (function) `static int snd_rme_digiface_controls_create(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:3684`
- Depends on: `audiobox_vsl.h`

### snd_djm_get_label_caplevel_common (function) `static const char *snd_djm_get_label_caplevel_common(u16 wvalue)`
- Defined: `legacy/mixer_quirks.c:3791`
- Depends on: `audiobox_vsl.h`

### snd_djm_get_label_caplevel_high (function) `static const char *snd_djm_get_label_caplevel_high(u16 wvalue)`
- Defined: `legacy/mixer_quirks.c:3804`
- Doc: Models like DJM-A9 or DJM-V10 have different capture levels than others
- Depends on: `audiobox_vsl.h`

### snd_djm_get_label_cap_common (function) `static const char *snd_djm_get_label_cap_common(u16 wvalue)`
- Defined: `legacy/mixer_quirks.c:3816`
- Depends on: `audiobox_vsl.h`

### snd_djm_get_label_cap_850 (function) `static const char *snd_djm_get_label_cap_850(u16 wvalue)`
- Defined: `legacy/mixer_quirks.c:3849`
- Doc: The DJM-850 has different values for CD/LINE and LINE capture control options than the other DJM declared in this file.
- Depends on: `audiobox_vsl.h`

### snd_djm_get_label_caplevel (function) `static const char *snd_djm_get_label_caplevel(u8 device_idx, u16 wvalue)`
- Defined: `legacy/mixer_quirks.c:3857`
- Depends on: `audiobox_vsl.h`

### snd_djm_get_label_cap (function) `static const char *snd_djm_get_label_cap(u8 device_idx, u16 wvalue)`
- Defined: `legacy/mixer_quirks.c:3866`
- Depends on: `audiobox_vsl.h`

### snd_djm_get_label_pb (function) `static const char *snd_djm_get_label_pb(u16 wvalue)`
- Defined: `legacy/mixer_quirks.c:3874`
- Depends on: `audiobox_vsl.h`

### snd_djm_get_label (function) `static const char *snd_djm_get_label(u8 device_idx, u16 wvalue, u16 windex)`
- Defined: `legacy/mixer_quirks.c:3884`
- Depends on: `audiobox_vsl.h`

### snd_djm_controls_info (function) `static int snd_djm_controls_info(struct snd_kcontrol *kctl,
				 struct snd_ctl_elem_info *info)`
- Defined: `legacy/mixer_quirks.c:4116`
- Depends on: `audiobox_vsl.h`

### snd_djm_controls_update (function) `static int snd_djm_controls_update(struct usb_mixer_interface *mixer,
				   u8 device_idx, u8 gr...`
- Defined: `legacy/mixer_quirks.c:4148`
- Depends on: `audiobox_vsl.h`

### snd_djm_controls_get (function) `static int snd_djm_controls_get(struct snd_kcontrol *kctl,
				struct snd_ctl_elem_value *elem)`
- Defined: `legacy/mixer_quirks.c:4169`
- Depends on: `audiobox_vsl.h`

### snd_djm_controls_put (function) `static int snd_djm_controls_put(struct snd_kcontrol *kctl, struct snd_ctl_elem_value *elem)`
- Defined: `legacy/mixer_quirks.c:4176`
- Depends on: `audiobox_vsl.h`

### snd_djm_controls_resume (function) `static int snd_djm_controls_resume(struct usb_mixer_elem_list *list)`
- Defined: `legacy/mixer_quirks.c:4193`
- Depends on: `audiobox_vsl.h`

### snd_djm_controls_create (function) `static int snd_djm_controls_create(struct usb_mixer_interface *mixer,
				   const u8 device_idx)`
- Defined: `legacy/mixer_quirks.c:4203`
- Depends on: `audiobox_vsl.h`

### snd_usb_mixer_apply_create_quirk (function) `int snd_usb_mixer_apply_create_quirk(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:4238`
- Depends on: `audiobox_vsl.h`

### snd_usb_mixer_resume_quirk (function) `void snd_usb_mixer_resume_quirk(struct usb_mixer_interface *mixer)`
- Defined: `legacy/mixer_quirks.c:4420`
- Depends on: `audiobox_vsl.h`

### snd_usb_mixer_rc_memory_change (function) `void snd_usb_mixer_rc_memory_change(struct usb_mixer_interface *mixer,
				    int unitid)`
- Defined: `legacy/mixer_quirks.c:4429`
- Depends on: `audiobox_vsl.h`

### snd_dragonfly_quirk_db_scale (function) `static void snd_dragonfly_quirk_db_scale(struct usb_mixer_interface *mixer,
					 struct usb_mixe...`
- Defined: `legacy/mixer_quirks.c:4457`
- Depends on: `audiobox_vsl.h`

### snd_fix_plt_name (function) `static void snd_fix_plt_name(struct snd_usb_audio *chip,
			     struct snd_ctl_elem_id *id)`
- Defined: `legacy/mixer_quirks.c:4509`
- Doc: standards. This function fixes nonstandard source names. By the time this function is called the control name should loo
- Depends on: `audiobox_vsl.h`

### snd_usb_mixer_fu_apply_quirk (function) `void snd_usb_mixer_fu_apply_quirk(struct usb_mixer_interface *mixer,
				  struct usb_mixer_elem_...`
- Defined: `legacy/mixer_quirks.c:4538`
- Depends on: `audiobox_vsl.h`

### snd_usb_mixer_elem_init_std (function) `snd_usb_mixer_elem_init_std(&cval->head, mixer, unitid);`
- Defined: `legacy/mixer_quirks.c:74`
- Depends on: `audiobox_vsl.h`

### kfree (function) `kfree(cval);`
- Defined: `legacy/mixer_quirks.c:94`
- Depends on: `audiobox_vsl.h`

### snprintf (function) `snprintf(kctl->id.name, sizeof(kctl->id.name), name);`
- Defined: `legacy/mixer_quirks.c:99`
- Doc: cval->min = 0; cval->max = 1; cval->res = 0; cval->dBmin = 0; cval->dBmax = 0; /* Create control kctl = snd_ctl_new1(snd
- Depends on: `audiobox_vsl.h`

### snd_usb_mixer_add_control (function) `return snd_usb_mixer_add_control(&cval->head, kctl);`
- Defined: `legacy/mixer_quirks.c:110`
- Doc: } /* Set name snprintf(kctl->id.name, sizeof(kctl->id.name), name); kctl->private_free = snd_usb_mixer_elem_free; /* set
- Depends on: `audiobox_vsl.h`

### snd_usb_mixer_add_list (function) `return snd_usb_mixer_add_list(list, kctl, false);`
- Defined: `legacy/mixer_quirks.c:170`
- Doc: if (!list) return -ENOMEM; if (listp) listp = list; list->mixer = mixer; list->id = id; list->resume = resume; kctl = sn
- Depends on: `audiobox_vsl.h`

### wake_up (function) `wake_up(&mixer->rc_waitq);`
- Defined: `legacy/mixer_quirks.c:217`
- Depends on: `audiobox_vsl.h`

### poll_wait (function) `poll_wait(file, &mixer->rc_waitq, wait);`
- Defined: `legacy/mixer_quirks.c:244`
- Depends on: `audiobox_vsl.h`

### init_waitqueue_head (function) `init_waitqueue_head(&mixer->rc_waitq);`
- Defined: `legacy/mixer_quirks.c:262`
- Depends on: `audiobox_vsl.h`

### usb_free_urb (function) `usb_free_urb(mixer->rc_urb);`
- Defined: `legacy/mixer_quirks.c:280`
- Depends on: `audiobox_vsl.h`

### usb_fill_control_urb (function) `usb_fill_control_urb(mixer->rc_urb, mixer->chip->dev, usb_rcvctrlpipe(mixer->chip->dev, 0), (u8 *)mixer->rc_setup_packet, mixer->rc_buffer, len, snd_usb_soundblaster_remote_complete, mixer);`
- Defined: `legacy/mixer_quirks.c:290`
- Depends on: `audiobox_vsl.h`

### CLASS (function) `CLASS(snd_usb_lock, pm)(chip);`
- Defined: `legacy/mixer_quirks.c:310`
- Depends on: `audiobox_vsl.h`

### usb_sndctrlpipe (function) `usb_sndctrlpipe(chip->dev, 0), 0x24, USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_OTHER, value, index + 2, NULL, 0);`
- Defined: `legacy/mixer_quirks.c:328`
- Depends on: `audiobox_vsl.h`

### snd_iprintf (function) `snd_iprintf(buffer, "%s jacks\n\n", mixer->chip->card->shortname);`
- Defined: `legacy/mixer_quirks.c:429`
- Depends on: `audiobox_vsl.h`

### usb_rcvctrlpipe (function) `usb_rcvctrlpipe(mixer->chip->dev, 0), UAC_GET_MEM, USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE, 0, jacks[i].unitid << 8, buf, 3);`
- Defined: `legacy/mixer_quirks.c:445`
- Depends on: `audiobox_vsl.h`

### snd_ctl_enum_info (function) `return snd_ctl_enum_info(uinfo, 1, ARRAY_SIZE(texts), texts);`
- Defined: `legacy/mixer_quirks.c:461`
- Depends on: `audiobox_vsl.h`

### snd_usb_ctl_msg (function) `return snd_usb_ctl_msg(chip->dev, usb_sndctrlpipe(chip->dev, 0), UAC_SET_CUR, USB_RECIP_INTERFACE | USB_TYPE_CLASS | USB_DIR_OUT, 0x0400, 0x0e00, buf, 2);`
- Defined: `legacy/mixer_quirks.c:484`
- Depends on: `audiobox_vsl.h`

### snd_ctl_notify (function) `snd_ctl_notify(me->mixer->chip->card, SNDRV_CTL_EVENT_MASK_VALUE, &me->kctl->id);`
- Defined: `legacy/mixer_quirks.c:566`
- Depends on: `audiobox_vsl.h`

### dev_warn (function) `dev_warn(&snd_dev->dev, "Failed to get input dev path\n");`
- Defined: `legacy/mixer_quirks.c:585`
- Depends on: `audiobox_vsl.h`

### input_unregister_handle (function) `err_unregister: input_unregister_handle(handle);`
- Defined: `legacy/mixer_quirks.c:642`
- Depends on: `audiobox_vsl.h`

### input_close_device (function) `input_close_device(handle);`
- Defined: `legacy/mixer_quirks.c:652`
- Depends on: `audiobox_vsl.h`

### snd_usb_mixer_elem_free (function) `snd_usb_mixer_elem_free(kctl);`
- Defined: `legacy/mixer_quirks.c:710`
- Depends on: `audiobox_vsl.h`

### strscpy (function) `strscpy(kctl->id.name, name, sizeof(kctl->id.name));`
- Defined: `legacy/mixer_quirks.c:741`
- Depends on: `audiobox_vsl.h`

### dev_err (function) `dev_err(&dev->dev, "unable to issue vendor read request (ret = %d)", err);`
- Defined: `legacy/mixer_quirks.c:1134`
- Depends on: `audiobox_vsl.h`

### usb_control_msg (function) `return usb_control_msg(chip->dev, usb_sndctrlpipe(chip->dev, 0), (pval >> 16) & 0xff, USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_OUT, pval >> 24, pval & 0xffff, NULL, 0, 1000);`
- Defined: `legacy/mixer_quirks.c:1158`
- Depends on: `audiobox_vsl.h`

### snd_usb_ctrl_intf (function) `snd_usb_ctrl_intf(mixer->hostif) | ((pval & 0xff) << 8), value, 2);`
- Defined: `legacy/mixer_quirks.c:1292`
- Depends on: `audiobox_vsl.h`

### snd_usb_mixer_set_ctl_value (function) `snd_usb_mixer_set_ctl_value(cval, UAC_SET_CUR, cval->control << 8, samplerate_id);`
- Defined: `legacy/mixer_quirks.c:1552`
- Depends on: `audiobox_vsl.h`

### snd_usb_mixer_notify_id (function) `snd_usb_mixer_notify_id(mixer, unitid);`
- Defined: `legacy/mixer_quirks.c:1555`
- Depends on: `audiobox_vsl.h`

### BIT (function) `BIT(chan + (chan % 2) * num_outs - 1);`
- Defined: `legacy/mixer_quirks.c:1726`
- Depends on: `audiobox_vsl.h`

### HDA_VERB_CMD (function) `HDA_VERB_CMD(AC_VERB_GET_PIN_SENSE, node_id, 0), &sense);`
- Defined: `legacy/mixer_quirks.c:2239`
- Depends on: `audiobox_vsl.h`

### field_get (function) `return field_get(mask, val);`
- Defined: `legacy/mixer_quirks.c:3395`
- Depends on: `audiobox_vsl.h`

### USB_ID (function) `case USB_ID(0x194f, 0x0101): err = snd_audiobox_vsl_init(mixer);`
- Defined: `legacy/mixer_quirks.c:4249`
- Doc: } return 0; } int snd_usb_mixer_apply_create_quirk(struct usb_mixer_interface *mixer) { int err = 0; err = snd_usb_sound
- Depends on: `audiobox_vsl.h`

### snd_card_ro_proc_new (function) `snd_card_ro_proc_new(mixer->chip->card, "audigy2nx", mixer, snd_audigy2nx_proc_read);`
- Defined: `legacy/mixer_quirks.c:4264`
- Depends on: `audiobox_vsl.h`

### usb_submit_urb (function) `usb_submit_urb(mixer->rc_urb, GFP_ATOMIC);`
- Defined: `legacy/mixer_quirks.c:4439`
- Depends on: `audiobox_vsl.h`

### usb_audio_dbg (function) `default: usb_audio_dbg(mixer->chip, "memory change in unknown unit %d\n", unitid);`
- Defined: `legacy/mixer_quirks.c:4452`
- Depends on: `audiobox_vsl.h`

### DECLARE_TLV_DB_RANGE (function) `static const DECLARE_TLV_DB_RANGE(scale, 0, 1, TLV_DB_MINMAX_ITEM(-5300, -4970), 2, 5, TLV_DB_MINMAX_ITEM(-4710, -4160), 6, 7, TLV_DB_MINMAX_ITEM(-3884, -3710), 8, 14, TLV_DB_MINMAX_ITEM(-3443, -2560)`
- Defined: `legacy/mixer_quirks.c:4465`
- Doc: Approximation using 10 ranges based on output measurement on hw v1.2. This seems close to the cubic mapping e.g. alsamix
- Depends on: `audiobox_vsl.h`

### usb_audio_info (function) `usb_audio_info(mixer->chip, "applying DragonFly dB scale quirk (0-50 variant)\n");`
- Defined: `legacy/mixer_quirks.c:4479`
- Depends on: `audiobox_vsl.h`

## legacy/test_connection.c

### main (function) `int main()`
- Defined: `legacy/test_connection.c:6`
- Doc: include <stdio.h> include "vsl_config.h" include "vsl_dsp_transport.h" // Asumiendo que esta es la plantilla B
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_dsp_transport.h`

### printf (function) `printf("Intentando conectar al dispositivo VSL %04X:%04X...\n", VSL_VENDOR_ID, VSL_PRODUCT_ID);`
- Defined: `legacy/test_connection.c:8`
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_dsp_transport.h`

### VSL_Close_Device (function) `VSL_Close_Device();`
- Defined: `legacy/test_connection.c:19`
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_dsp_transport.h`

## legacy/vsl_config.py

### validate_configuration (method) `def validate_configuration()`
- Defined: `legacy/vsl_config.py:92`
- Doc: Valida que todos los valores críticos estén configurados.

### print_configuration_status (method) `def print_configuration_status()`
- Defined: `legacy/vsl_config.py:116`
- Doc: Imprime el estado de la configuración con formato.

## legacy/vsl_core.py

### vsl_encode_gain (function) `def vsl_encode_gain(linear_value, param)`
- Defined: `legacy/vsl_core.py:16`
- Doc: Traducción de FUN_00132c90 (VSL_Encode_Gain en C).
- Depends on: `legacy/vsl_config.h`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

### vsl_map_frequency (function) `def vsl_map_frequency(linear_position, param)`
- Defined: `legacy/vsl_core.py:58`
- Doc: Traducción de FUN_00132d00 (VSL_Map_Frequency en C).
- Depends on: `legacy/vsl_config.h`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

### vsl_final_encode_to_int (function) `def vsl_final_encode_to_int(encoded_float, param)`
- Defined: `legacy/vsl_core.py:94`
- Doc: Traducción de VSL_Final_Encode_To_Int en C.
- Depends on: `legacy/vsl_config.h`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

### vsl_decode_frequency (function) `def vsl_decode_frequency(freq_hz_value, param)`
- Defined: `legacy/vsl_core.py:127`
- Doc: Traducción de FUN_00132da8 (VSL_Decode_Frequency en C).
- Depends on: `legacy/vsl_config.h`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

### validate_parameter (function) `def validate_parameter(param)`
- Defined: `legacy/vsl_core.py:170`
- Doc: Valida la integridad de un VSLParameter.
- Depends on: `legacy/vsl_config.h`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

## legacy/vsl_dsp_logic.c

### VSL_Encode_Gain (function) `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)`
- Defined: `legacy/vsl_dsp_logic.c:11`
- Doc: Implementación de FUN_00132c90
- Depends on: `legacy/vsl_dsp_logic.h`

### VSL_Map_Frequency (function) `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)`
- Defined: `legacy/vsl_dsp_logic.c:29`
- Doc: Implementación de FUN_00132d00
- Depends on: `legacy/vsl_dsp_logic.h`

### VSL_Final_Encode_To_Int (function) `uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)`
- Defined: `legacy/vsl_dsp_logic.c:58`
- Doc: @brief Convierte el valor codificado en float a un entero sin signo para el firmware. @note Basado en la hipótesis común
- Depends on: `legacy/vsl_dsp_logic.h`

### VSL_Decode_Frequency (function) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)`
- Defined: `legacy/vsl_dsp_logic.c:78`
- Doc: Implementación de FUN_00132da8
- Depends on: `legacy/vsl_dsp_logic.h`

### VSL_Build_And_Send_Packet (function) `void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float);`
- Defined: `legacy/vsl_dsp_logic.c:4`
- Doc: Declaración de la nueva función de envío
- Depends on: `legacy/vsl_dsp_logic.h`

### exp2f (function) `return exp2f(log2_value);`
- Defined: `legacy/vsl_dsp_logic.c:46`
- Doc: 4. Conversión a frecuencia lineal (exp2f)
- Depends on: `legacy/vsl_dsp_logic.h`

## legacy/vsl_dsp_logic.h

### VSL_Encode_Gain (function) `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);`
- Defined: `legacy/vsl_dsp_logic.h:42`
- Doc: @brief Codifica un valor lineal (ej. 0.5) a la escala exponencial/logarítmica del DSP (Ganancia/Volumen). @param linear_
- Imported by: `legacy/main.c`, `legacy/vsl_dsp_logic.c`

### VSL_Map_Frequency (function) `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);`
- Defined: `legacy/vsl_dsp_logic.h:50`
- Doc: @brief Convierte una posición lineal (ej. 0.5) a su frecuencia logarítmica (Hz) real. @param linear_position La posición
- Imported by: `legacy/main.c`, `legacy/vsl_dsp_logic.c`

### VSL_Final_Encode_To_Int (function) `uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param);`
- Defined: `legacy/vsl_dsp_logic.h:60`
- Doc: @brief Convierte el valor codificado en float a un entero sin signo para el firmware. @note ESTA FUNCIÓN ES UN MARCADOR 
- Imported by: `legacy/main.c`, `legacy/vsl_dsp_logic.c`

### VSL_Decode_Frequency (function) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);`
- Defined: `legacy/vsl_dsp_logic.h:73`
- Doc: @brief Decodifica una frecuencia real (Hz) del DSP a su posición lineal de control (0.0 a 1.0). @param freq_hz_value La 
- Imported by: `legacy/main.c`, `legacy/vsl_dsp_logic.c`

## legacy/vsl_dsp_transport.c

### VSL_Init_Device (function) `int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)`
- Defined: `legacy/vsl_dsp_transport.c:22`
- Doc: ... (las inclusiones y el singleton handle) ...
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_dsp_transport.h`

### VSL_Close_Device (function) `void VSL_Close_Device(void)`
- Defined: `legacy/vsl_dsp_transport.c:69`
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_dsp_transport.h`

### VSL_Get_Device_Handle (function) `hid_device* VSL_Get_Device_Handle(void)`
- Defined: `legacy/vsl_dsp_transport.c:78`
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_dsp_transport.h`

### FUN_Send_Packet (function) `void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length)`
- Defined: `legacy/vsl_dsp_transport.c:97`
- Doc: @brief Función de I/O real usando HIDAPI. @note DEBE SER REEMPLAZADA con la lógica específica de tu dispositivo (Report 
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_dsp_transport.h`

### VSL_Build_And_Send_Packet (function) `void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float)`
- Defined: `legacy/vsl_dsp_transport.c:140`
- Doc: Implementación de la función de construcción y envío
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_dsp_transport.h`

### fprintf (function) `fprintf(stderr, "Error: HIDAPI init failed\n");`
- Defined: `legacy/vsl_dsp_transport.c:28`
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_dsp_transport.h`

### hid_free_enumeration (function) `hid_free_enumeration(devs);`
- Defined: `legacy/vsl_dsp_transport.c:49`
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_dsp_transport.h`

### free (function) `free(target_path);`
- Defined: `legacy/vsl_dsp_transport.c:55`
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_dsp_transport.h`

### hid_exit (function) `hid_exit();`
- Defined: `legacy/vsl_dsp_transport.c:62`
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_dsp_transport.h`

### printf (function) `printf("VSL Device handle opened successfully via path: %04X:%04X\n", vendor_id, product_id);`
- Defined: `legacy/vsl_dsp_transport.c:65`
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_dsp_transport.h`

### hid_close (function) `hid_close(vsl_device_handle);`
- Defined: `legacy/vsl_dsp_transport.c:72`
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_dsp_transport.h`

### memcpy (function) `memcpy(&buf[1], &net_id, sizeof(uint16_t));`
- Defined: `legacy/vsl_dsp_transport.c:121`
- Doc: Copiar ID (2 bytes) y Value (2 bytes) al buffer, iniciando en buf[1] (después del Report ID)
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_dsp_transport.h`

## legacy/vsl_dsp_transport.h

### VSL_Init_Device (function) `int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id);`
- Defined: `legacy/vsl_dsp_transport.h:19`
- Doc: 1. Funciones de Inicialización y Cierre (¡Ambas declaradas!)
- Depends on: `legacy/vsl_config.h`
- Imported by: `legacy/main.c`, `legacy/test_connection.c`, `legacy/vsl_dsp_transport.c`

### VSL_Close_Device (function) `void VSL_Close_Device(void);`
- Defined: `legacy/vsl_dsp_transport.h:20`
- Depends on: `legacy/vsl_config.h`
- Imported by: `legacy/main.c`, `legacy/test_connection.c`, `legacy/vsl_dsp_transport.c`

### VSL_Get_Device_Handle (function) `hid_device* VSL_Get_Device_Handle(void);`
- Defined: `legacy/vsl_dsp_transport.h:21`
- Depends on: `legacy/vsl_config.h`
- Imported by: `legacy/main.c`, `legacy/test_connection.c`, `legacy/vsl_dsp_transport.c`

### FUN_Send_Packet (function) `void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length);`
- Defined: `legacy/vsl_dsp_transport.h:24`
- Doc: 2. Funciones de Envío
- Depends on: `legacy/vsl_config.h`
- Imported by: `legacy/main.c`, `legacy/test_connection.c`, `legacy/vsl_dsp_transport.c`

### VSL_Build_And_Send_Packet (function) `void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float);`
- Defined: `legacy/vsl_dsp_transport.h:25`
- Depends on: `legacy/vsl_config.h`
- Imported by: `legacy/main.c`, `legacy/test_connection.c`, `legacy/vsl_dsp_transport.c`

## legacy/vsl_hid_io.py

### enumerate_vsl_devices (method) `def enumerate_vsl_devices()`
- Defined: `legacy/vsl_hid_io.py:149`
- Doc: Enumera todos los dispositivos HID conectados.
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### __new__ (method) `def __new__(cls)`
- Defined: `legacy/vsl_hid_io.py:39`
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### __init__ (method) `def __init__(self)`
- Defined: `legacy/vsl_hid_io.py:45`
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### open (method) `def open(self)`
- Defined: `legacy/vsl_hid_io.py:59`
- Doc: Abre la conexión con el dispositivo VSL.
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### close (method) `def close(self)`
- Defined: `legacy/vsl_hid_io.py:90`
- Doc: Cierra la conexión con el dispositivo.
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### send_packet (method) `def send_packet(self, packet)`
- Defined: `legacy/vsl_hid_io.py:101`
- Doc: Envía un paquete VSL al dispositivo.
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### __enter__ (method) `def __enter__(self)`
- Defined: `legacy/vsl_hid_io.py:139`
- Doc: Context manager entry.
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### __exit__ (method) `def __exit__(self, exc_type, exc_val, exc_tb)`
- Defined: `legacy/vsl_hid_io.py:144`
- Doc: Context manager exit.
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

## legacy/vsl_poc_main.py

### test_gain_encoding (function) `def test_gain_encoding()`
- Defined: `legacy/vsl_poc_main.py:43`
- Doc: Test de codificación de ganancia con tabla de validación.
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### test_frequency_mapping (function) `def test_frequency_mapping()`
- Defined: `legacy/vsl_poc_main.py:72`
- Doc: Test de mapeo logarítmico de frecuencias.
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### test_packet_construction (function) `def test_packet_construction()`
- Defined: `legacy/vsl_poc_main.py:92`
- Doc: Test de construcción de paquetes HID.
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### test_edge_cases (function) `def test_edge_cases()`
- Defined: `legacy/vsl_poc_main.py:150`
- Doc: Test de casos extremos y validación de errores.
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### run_full_workflow (function) `def run_full_workflow()`
- Defined: `legacy/vsl_poc_main.py:197`
- Doc: Simula el flujo completo: Usuario → Encoding → Paquete.
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### print_summary (function) `def print_summary()`
- Defined: `legacy/vsl_poc_main.py:229`
- Doc: Imprime resumen del estado del proyecto.
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

### main (function) `def main()`
- Defined: `legacy/vsl_poc_main.py:266`
- Doc: Función principal de la PoC.
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

## legacy/vsl_protocol_analyzer.py

### reverse_map_gain (method) `def reverse_map_gain(encoded_value, param)`
- Defined: `legacy/vsl_protocol_analyzer.py:67`
- Doc: Simula VSL_Decode_Gain. Convierte un entero a un valor de usuario (dB).

### reverse_map_frequency (method) `def reverse_map_frequency(encoded_value, param)`
- Defined: `legacy/vsl_protocol_analyzer.py:95`
- Doc: Simula VSL_Decode_Frequency. Convierte un entero a frecuencia (Hz).

### get_decoded_value (method) `def get_decoded_value(encoded_value, param_id)`
- Defined: `legacy/vsl_protocol_analyzer.py:115`
- Doc: Dirige la decodificación al motor DSP correcto.

### decode_vsl_packet (method) `def decode_vsl_packet(data)`
- Defined: `legacy/vsl_protocol_analyzer.py:140`
- Doc: Decodifica el payload de 64 bytes. (Regla #3: Seguridad)

### analyze_pcap (method) `def analyze_pcap(pcap_file)`
- Defined: `legacy/vsl_protocol_analyzer.py:173`
- Doc: Carga un archivo PCAP y filtra los paquetes USB VSL.

### __init__ (method) `def __init__(self, dsp_id, name, type_unit, min_map, max_map, coeff_A, coeff_C1, log_factor)`
- Defined: `legacy/vsl_protocol_analyzer.py:30`

## legacy/vsl_transport.py

### build_packet_safe (method) `def build_packet_safe(param, encoded_value)`
- Defined: `legacy/vsl_transport.py:141`
- Doc: Construye un paquete con manejo de errores.
- Depends on: `legacy/vsl_config.h`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

### __init__ (method) `def __init__(self, param_id, encoded_value, report_id)`
- Defined: `legacy/vsl_transport.py:21`
- Doc: Construye un paquete VSL-DSP.
- Depends on: `legacy/vsl_config.h`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

### _build_buffer (method) `def _build_buffer(self)`
- Defined: `legacy/vsl_transport.py:58`
- Doc: Construye el buffer de 64 bytes según el protocolo VSL-DSP.
- Depends on: `legacy/vsl_config.h`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

### buffer (method) `def buffer(self)`
- Defined: `legacy/vsl_transport.py:89`
- Doc: Retorna el buffer como bytes inmutables.
- Depends on: `legacy/vsl_config.h`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

### hex_dump (method) `def hex_dump(self, num_bytes)`
- Defined: `legacy/vsl_transport.py:93`
- Doc: Genera un hex dump del paquete para debugging.
- Depends on: `legacy/vsl_config.h`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

### validate (method) `def validate(self)`
- Defined: `legacy/vsl_transport.py:106`
- Doc: Valida la integridad del paquete.
- Depends on: `legacy/vsl_config.h`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

### __repr__ (method) `def __repr__(self)`
- Defined: `legacy/vsl_transport.py:133`
- Depends on: `legacy/vsl_config.h`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

## src/vsl_cli.c

### print_usage (function) `static void print_usage(FILE *fp, const char *prog)`
- Defined: `src/vsl_cli.c:57`
- Depends on: `src/vsl_config.h`, `src/vsl_dsp_logic.h`, `src/vsl_dsp_transport.h`

### print_version (function) `static void print_version(void)`
- Defined: `src/vsl_cli.c:83`
- Depends on: `src/vsl_config.h`, `src/vsl_dsp_logic.h`, `src/vsl_dsp_transport.h`

### print_list (function) `static void print_list(uint16_t product_id)`
- Defined: `src/vsl_cli.c:90`
- Depends on: `src/vsl_config.h`, `src/vsl_dsp_logic.h`, `src/vsl_dsp_transport.h`

### lookup_coeffs_by_param_id (function) `static const VSL_Parameter *
lookup_coeffs_by_param_id(uint16_t param_id)`
- Defined: `src/vsl_cli.c:109`
- Depends on: `src/vsl_config.h`, `src/vsl_dsp_logic.h`, `src/vsl_dsp_transport.h`

### find_entry_by_name (function) `static const ParamEntry *
find_entry_by_name(const char *name)`
- Defined: `src/vsl_cli.c:119`
- Depends on: `src/vsl_config.h`, `src/vsl_dsp_logic.h`, `src/vsl_dsp_transport.h`

### do_send (function) `static int do_send(uint16_t product_id,
                   uint16_t param_id,
                   ...`
- Defined: `src/vsl_cli.c:129`
- Depends on: `src/vsl_config.h`, `src/vsl_dsp_logic.h`, `src/vsl_dsp_transport.h`

### do_send_freq (function) `static int do_send_freq(uint16_t product_id,
                        uint16_t param_id,
         ...`
- Defined: `src/vsl_cli.c:167`
- Depends on: `src/vsl_config.h`, `src/vsl_dsp_logic.h`, `src/vsl_dsp_transport.h`

### main (function) `int main(int argc, char *argv[])`
- Defined: `src/vsl_cli.c:204`
- Depends on: `src/vsl_config.h`, `src/vsl_dsp_logic.h`, `src/vsl_dsp_transport.h`

### fprintf (function) `fprintf(fp, "Usage: %s [OPTIONS] COMMAND [ARGS...]\n" "\n" "Options:\n" " -p, --pid <hex> USB product ID (default: 0x0101 = 22 VSL)\n" " -m, --model <tag> Model tag: 22vsl, 44vsl, 1818vsl\n" " -h, --h`
- Defined: `src/vsl_cli.c:60`
- Depends on: `src/vsl_config.h`, `src/vsl_dsp_logic.h`, `src/vsl_dsp_transport.h`

### printf (function) `printf("vsl-cli 2.0.0\n" "PreSonus AudioBox VSL DSP control tool\n" "License: AGPL-3.0-or-later\n");`
- Defined: `src/vsl_cli.c:86`
- Depends on: `src/vsl_config.h`, `src/vsl_dsp_logic.h`, `src/vsl_dsp_transport.h`

### VSL_Close_Device (function) `VSL_Close_Device(dev);`
- Defined: `src/vsl_cli.c:163`
- Depends on: `src/vsl_config.h`, `src/vsl_dsp_logic.h`, `src/vsl_dsp_transport.h`

### fmaxf (function) `fmaxf(0.0f, fminf(freq_hz / coeffs->freq_max_hz, 1.0f)), coeffs);`
- Defined: `src/vsl_cli.c:186`
- Depends on: `src/vsl_config.h`, `src/vsl_dsp_logic.h`, `src/vsl_dsp_transport.h`

## src/vsl_config.h

### VSL_ModelLookup (function) `static inline const VSL_ModelInfo *
VSL_ModelLookup(uint16_t pid)`
- Defined: `src/vsl_config.h:35`
- Imported by: `src/vsl_cli.c`, `src/vsl_dsp_transport.h`

### VSL_ModelLookupByTag (function) `static inline const VSL_ModelInfo *
VSL_ModelLookupByTag(const char *tag)`
- Defined: `src/vsl_config.h:47`
- Imported by: `src/vsl_cli.c`, `src/vsl_dsp_transport.h`

## src/vsl_dsp_logic.c

### VSL_Encode_Gain (function) `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)`
- Defined: `src/vsl_dsp_logic.c:2`
- Doc: include "vsl_dsp_logic.h"
- Depends on: `src/vsl_dsp_logic.h`

### VSL_Decode_Gain (function) `float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param)`
- Defined: `src/vsl_dsp_logic.c:15`
- Depends on: `src/vsl_dsp_logic.h`

### VSL_Map_Frequency (function) `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)`
- Defined: `src/vsl_dsp_logic.c:49`
- Depends on: `src/vsl_dsp_logic.h`

### VSL_Final_Encode_To_Int (function) `uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)`
- Defined: `src/vsl_dsp_logic.c:65`
- Depends on: `src/vsl_dsp_logic.h`

### VSL_Decode_Frequency (function) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)`
- Defined: `src/vsl_dsp_logic.c:75`
- Depends on: `src/vsl_dsp_logic.h`

### fmaxf (function) `return fmaxf(0.0f, fminf(r, 1.0f));`
- Defined: `src/vsl_dsp_logic.c:20`
- Depends on: `src/vsl_dsp_logic.h`

### exp2f (function) `return exp2f(log2_value);`
- Defined: `src/vsl_dsp_logic.c:62`
- Depends on: `src/vsl_dsp_logic.h`

## src/vsl_dsp_logic.h

### VSL_Encode_Gain (function) `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);`
- Defined: `src/vsl_dsp_logic.h:33`
- Doc: @brief Encodes a linear gain value [0.0, 1.0] to the DSP exponential curve. @param linear_value Linear control position 
- Imported by: `src/vsl_cli.c`, `src/vsl_dsp_logic.c`, `src/vsl_dsp_transport.h`

### VSL_Decode_Gain (function) `float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param);`
- Defined: `src/vsl_dsp_logic.h:42`
- Doc: @brief Decodes an encoded gain float back to a linear position [0.0, 1.0]. @param encoded_float Value received from the 
- Imported by: `src/vsl_cli.c`, `src/vsl_dsp_logic.c`, `src/vsl_dsp_transport.h`

### VSL_Map_Frequency (function) `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);`
- Defined: `src/vsl_dsp_logic.h:51`
- Doc: @brief Maps a linear position [0.0, 1.0] to a logarithmic frequency (Hz). @param linear_position Linear control position
- Imported by: `src/vsl_cli.c`, `src/vsl_dsp_logic.c`, `src/vsl_dsp_transport.h`

### VSL_Decode_Frequency (function) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);`
- Defined: `src/vsl_dsp_logic.h:60`
- Doc: @brief Decodes a frequency (Hz) from the DSP to a linear position [0.0, 1.0]. @param freq_hz_value Frequency in Hz read 
- Imported by: `src/vsl_cli.c`, `src/vsl_dsp_logic.c`, `src/vsl_dsp_transport.h`

### VSL_Final_Encode_To_Int (function) `uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param);`
- Defined: `src/vsl_dsp_logic.h:70`
- Doc: @brief Converts an encoded float to a 16-bit integer for the DSP firmware. @param encoded_float Value from VSL_Encode_Ga
- Imported by: `src/vsl_cli.c`, `src/vsl_dsp_logic.c`, `src/vsl_dsp_transport.h`

## src/vsl_dsp_transport.c

### VSL_Init_Device (function) `vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)`
- Defined: `src/vsl_dsp_transport.c:12`
- Depends on: `src/vsl_dsp_transport.h`

### VSL_Close_Device (function) `void VSL_Close_Device(vsl_device_handle handle)`
- Defined: `src/vsl_dsp_transport.c:44`
- Depends on: `src/vsl_dsp_transport.h`

### VSL_Send_Parameter (function) `int VSL_Send_Parameter(vsl_device_handle handle,
                       uint16_t dsp_param_id,
  ...`
- Defined: `src/vsl_dsp_transport.c:60`
- Depends on: `src/vsl_dsp_transport.h`

### free (function) `free(dev);`
- Defined: `src/vsl_dsp_transport.c:21`
- Depends on: `src/vsl_dsp_transport.h`

### libusb_exit (function) `libusb_exit(NULL);`
- Defined: `src/vsl_dsp_transport.c:27`
- Depends on: `src/vsl_dsp_transport.h`

### libusb_set_auto_detach_kernel_driver (function) `libusb_set_auto_detach_kernel_driver(dev->handle, 1);`
- Defined: `src/vsl_dsp_transport.c:34`
- Depends on: `src/vsl_dsp_transport.h`

### libusb_detach_kernel_driver (function) `libusb_detach_kernel_driver(dev->handle, VSL_MIDI_IFACE);`
- Defined: `src/vsl_dsp_transport.c:38`
- Depends on: `src/vsl_dsp_transport.h`

### libusb_claim_interface (function) `libusb_claim_interface(dev->handle, VSL_MIDI_IFACE);`
- Defined: `src/vsl_dsp_transport.c:40`
- Depends on: `src/vsl_dsp_transport.h`

### libusb_release_interface (function) `libusb_release_interface(dev->handle, VSL_MIDI_IFACE);`
- Defined: `src/vsl_dsp_transport.c:53`
- Depends on: `src/vsl_dsp_transport.h`

### libusb_attach_kernel_driver (function) `libusb_attach_kernel_driver(dev->handle, VSL_MIDI_IFACE);`
- Defined: `src/vsl_dsp_transport.c:54`
- Depends on: `src/vsl_dsp_transport.h`

### libusb_close (function) `libusb_close(dev->handle);`
- Defined: `src/vsl_dsp_transport.c:55`
- Depends on: `src/vsl_dsp_transport.h`

### memset (function) `memset(buf, 0, sizeof(buf));`
- Defined: `src/vsl_dsp_transport.c:72`
- Depends on: `src/vsl_dsp_transport.h`

### fprintf (function) `fprintf(stderr, "VSL_Send_Parameter: bulk write failed: %s\n", libusb_error_name(ret));`
- Defined: `src/vsl_dsp_transport.c:83`
- Depends on: `src/vsl_dsp_transport.h`

## src/vsl_dsp_transport.h

### VSL_Init_Device (function) `vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id);`
- Defined: `src/vsl_dsp_transport.h:20`
- Doc: @brief Open a VSL device by USB VID/PID and claim the MIDI control interface. @param vendor_id USB vendor ID (typically 
- Depends on: `src/vsl_config.h`, `src/vsl_dsp_logic.h`
- Imported by: `src/vsl_cli.c`, `src/vsl_dsp_transport.c`

### VSL_Close_Device (function) `void VSL_Close_Device(vsl_device_handle handle);`
- Defined: `src/vsl_dsp_transport.h:26`
- Doc: @brief Release the MIDI interface and close the device. @param handle Handle from VSL_Init_Device. NULL is a safe no-op.
- Depends on: `src/vsl_config.h`, `src/vsl_dsp_logic.h`
- Imported by: `src/vsl_cli.c`, `src/vsl_dsp_transport.c`

### VSL_Send_Parameter (function) `int VSL_Send_Parameter(vsl_device_handle handle, uint16_t dsp_param_id, uint16_t encoded_value);`
- Defined: `src/vsl_dsp_transport.h:35`
- Doc: @brief Send a DSP parameter value to the device via USB bulk transfer. @param handle Handle from VSL_Init_Device. @param
- Depends on: `src/vsl_config.h`, `src/vsl_dsp_logic.h`
- Imported by: `src/vsl_cli.c`, `src/vsl_dsp_transport.c`

## tests/test_audiobox_vsl.c

### test_supported_models_table_shape (function) `static void test_supported_models_table_shape(void **state)`
- Defined: `tests/test_audiobox_vsl.c:30`
- Depends on: `audiobox_vsl.h`

### test_model_pids_match_table (function) `static void test_model_pids_match_table(void **state)`
- Defined: `tests/test_audiobox_vsl.c:45`
- Depends on: `audiobox_vsl.h`

### test_lookup_returns_22_vsl (function) `static void test_lookup_returns_22_vsl(void **state)`
- Defined: `tests/test_audiobox_vsl.c:54`
- Depends on: `audiobox_vsl.h`

### test_lookup_returns_44_vsl (function) `static void test_lookup_returns_44_vsl(void **state)`
- Defined: `tests/test_audiobox_vsl.c:64`
- Depends on: `audiobox_vsl.h`

### test_lookup_returns_1818_vsl (function) `static void test_lookup_returns_1818_vsl(void **state)`
- Defined: `tests/test_audiobox_vsl.c:74`
- Depends on: `audiobox_vsl.h`

### test_lookup_returns_null_for_unknown_pid (function) `static void test_lookup_returns_null_for_unknown_pid(void **state)`
- Defined: `tests/test_audiobox_vsl.c:84`
- Depends on: `audiobox_vsl.h`

### test_lookup_handles_full_pid_range (function) `static void test_lookup_handles_full_pid_range(void **state)`
- Defined: `tests/test_audiobox_vsl.c:94`
- Depends on: `audiobox_vsl.h`

### test_table_pids_are_unique (function) `static void test_table_pids_are_unique(void **state)`
- Defined: `tests/test_audiobox_vsl.c:114`
- Depends on: `audiobox_vsl.h`

### test_table_product_names_non_empty (function) `static void test_table_product_names_non_empty(void **state)`
- Defined: `tests/test_audiobox_vsl.c:125`
- Depends on: `audiobox_vsl.h`

### main (function) `int main(void)`
- Defined: `tests/test_audiobox_vsl.c:135`
- Depends on: `audiobox_vsl.h`

### assert_int_equal (function) `assert_int_equal(AUDIOBOX_VENDOR_ID, 0x194fU);`
- Defined: `tests/test_audiobox_vsl.c:28`
- Depends on: `audiobox_vsl.h`

### assert_string_equal (function) `assert_string_equal(m[0].product_name, "AudioBox 22 VSL");`
- Defined: `tests/test_audiobox_vsl.c:39`
- Depends on: `audiobox_vsl.h`

### assert_non_null (function) `assert_non_null(m);`
- Defined: `tests/test_audiobox_vsl.c:60`
- Depends on: `audiobox_vsl.h`

### assert_null (function) `assert_null(audiobox_lookup_model(0x0000U));`
- Defined: `tests/test_audiobox_vsl.c:88`
- Depends on: `audiobox_vsl.h`

### assert_int_not_equal (function) `assert_int_not_equal(audiobox_models[i].pid, audiobox_models[j].pid);`
- Defined: `tests/test_audiobox_vsl.c:121`
- Depends on: `audiobox_vsl.h`

### assert_true (function) `assert_true(audiobox_models[i].product_name[0] != '\0');`
- Defined: `tests/test_audiobox_vsl.c:132`
- Depends on: `audiobox_vsl.h`

### cmocka_run_group_tests (function) `return cmocka_run_group_tests(tests, NULL, NULL);`
- Defined: `tests/test_audiobox_vsl.c:150`
- Depends on: `audiobox_vsl.h`

## tests/test_vsl_dsp_logic.c

### test_VSL_Encode_Gain (function) `static void test_VSL_Encode_Gain(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:8`
- Doc: include <stdarg.h> include <stddef.h> include <setjmp.h> include <cmocka.h> include <math.h> include <float.h> include "

### test_VSL_Map_Frequency (function) `static void test_VSL_Map_Frequency(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:35`

### test_VSL_Decode_Frequency (function) `static void test_VSL_Decode_Frequency(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:67`

### test_VSL_Final_Encode_To_Int (function) `static void test_VSL_Final_Encode_To_Int(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:99`

### test_VSL_Decode_Gain_c1_zero (function) `static void test_VSL_Decode_Gain_c1_zero(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:127`

### test_VSL_Decode_Gain_log_factor_zero (function) `static void test_VSL_Decode_Gain_log_factor_zero(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:145`

### test_VSL_Decode_Gain_encoded_below_offset (function) `static void test_VSL_Decode_Gain_encoded_below_offset(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:163`

### test_VSL_Decode_Gain_range_zero (function) `static void test_VSL_Decode_Gain_range_zero(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:182`

### test_VSL_Decode_Gain_roundtrip_mid (function) `static void test_VSL_Decode_Gain_roundtrip_mid(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:200`

### test_VSL_Decode_Gain_roundtrip_extremes (function) `static void test_VSL_Decode_Gain_roundtrip_extremes(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:220`

### test_VSL_Decode_Gain_roundtrip_75 (function) `static void test_VSL_Decode_Gain_roundtrip_75(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:241`

### test_VSL_Decode_Gain_custom_range_roundtrip (function) `static void test_VSL_Decode_Gain_custom_range_roundtrip(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:261`

### test_VSL_Decode_Gain_encoded_equals_offset (function) `static void test_VSL_Decode_Gain_encoded_equals_offset(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:289`

### test_VSL_Decode_Gain_clamps_output (function) `static void test_VSL_Decode_Gain_clamps_output(void **state)`
- Defined: `tests/test_vsl_dsp_logic.c:308`

### main (function) `int main(void)`
- Defined: `tests/test_vsl_dsp_logic.c:328`

### assert_float_equal (function) `assert_float_equal(VSL_Encode_Gain(0.5f, &param), 1.6487212707f, 1e-5f);`
- Defined: `tests/test_vsl_dsp_logic.c:25`
- Doc: VSL_Parameter param = { .coeff_offset_A = 0.0f, .coeff_C1 = 1.0f, .log_factor = 1.0f, .curve_min_map = 0.0f, .curve_max_

### assert_int_equal (function) `assert_int_equal(VSL_Final_Encode_To_Int(0.75f, &param), 49);`
- Defined: `tests/test_vsl_dsp_logic.c:116`
- Doc: VSL_Parameter param = { .coeff_offset_A = 0.0f, /* unused .coeff_C1 = 0.0f,     /* unused .log_factor = 0.0f,   /* unuse

### assert_true (function) `assert_true(result >= 0.0f);`
- Defined: `tests/test_vsl_dsp_logic.c:325`

### cmocka_run_group_tests (function) `return cmocka_run_group_tests(tests, NULL, NULL);`
- Defined: `tests/test_vsl_dsp_logic.c:346`

## voicecloak/src/vc_alsa.c

### fmt_bps (function) `static size_t fmt_bps(snd_pcm_format_t f)`
- Defined: `voicecloak/src/vc_alsa.c:19`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_stream.h`

### open_stream (function) `static int open_stream(vc_pcm_t *s, const char *dev, snd_pcm_stream_t dir,
                      ...`
- Defined: `voicecloak/src/vc_alsa.c:28`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_stream.h`

### raw_to_mono (function) `static void raw_to_mono(const unsigned char *raw, float *mono,
                        snd_pcm_uf...`
- Defined: `voicecloak/src/vc_alsa.c:98`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_stream.h`

### mono_to_raw (function) `static void mono_to_raw(unsigned char *raw, const float *mono,
                        snd_pcm_uf...`
- Defined: `voicecloak/src/vc_alsa.c:129`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_stream.h`

### vc_alsa_list (function) `int vc_alsa_list(void)`
- Defined: `voicecloak/src/vc_alsa.c:162`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_stream.h`

### vc_alsa_run (function) `int vc_alsa_run(const vc_alsa_cfg_t *cfg)`
- Defined: `voicecloak/src/vc_alsa.c:188`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_stream.h`

### fprintf (function) `fprintf(stderr, "vc_alsa: cannot open %s device '%s': %s\n", tag, dev, snd_strerror(err));`
- Defined: `voicecloak/src/vc_alsa.c:37`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_stream.h`

### snd_pcm_hw_params_alloca (function) `snd_pcm_hw_params_alloca(&hw);`
- Defined: `voicecloak/src/vc_alsa.c:43`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_stream.h`

### snd_pcm_hw_params_any (function) `snd_pcm_hw_params_any(s->pcm, hw);`
- Defined: `voicecloak/src/vc_alsa.c:44`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_stream.h`

### snd_pcm_hw_params_set_buffer_size_near (function) `snd_pcm_hw_params_set_buffer_size_near(s->pcm, hw, &buffer);`
- Defined: `voicecloak/src/vc_alsa.c:85`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_stream.h`

### memcpy (function) `memcpy(&x, base, sizeof(x));`
- Defined: `voicecloak/src/vc_alsa.c:108`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_stream.h`

### printf (function) `printf("Available ALSA PCM devices:\n");`
- Defined: `voicecloak/src/vc_alsa.c:169`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_stream.h`

### free (function) `free(name);`
- Defined: `voicecloak/src/vc_alsa.c:183`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_stream.h`

### snd_device_name_free_hint (function) `snd_device_name_free_hint(hints);`
- Defined: `voicecloak/src/vc_alsa.c:185`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_stream.h`

### snd_pcm_hw_params_current (function) `snd_pcm_hw_params_current(cap.pcm, hw);`
- Defined: `voicecloak/src/vc_alsa.c:211`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_stream.h`

### snd_pcm_hw_params_get_rate (function) `snd_pcm_hw_params_get_rate(hw, &neg_rate, &dir);`
- Defined: `voicecloak/src/vc_alsa.c:212`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_stream.h`

### snd_pcm_prepare (function) `snd_pcm_prepare(cap.pcm);`
- Defined: `voicecloak/src/vc_alsa.c:231`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_stream.h`

### memset (function) `memset(raw_out, 0, (size_t)period * play.channels * play.bps);`
- Defined: `voicecloak/src/vc_alsa.c:236`
- Doc: snd_pcm_uframes_t period = cfg->period_frames; raw_in   = (unsigned char *)malloc((size_t)period * cap.channels * cap.bp
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_stream.h`

### snd_pcm_writei (function) `snd_pcm_writei(play.pcm, raw_out, period);`
- Defined: `voicecloak/src/vc_alsa.c:237`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_stream.h`

### snd_pcm_start (function) `snd_pcm_start(cap.pcm);`
- Defined: `voicecloak/src/vc_alsa.c:238`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_stream.h`

### vc_stream_process (function) `vc_stream_process(st, mono_in, mono_out, (size_t)frames, cfg->fn, cfg->user);`
- Defined: `voicecloak/src/vc_alsa.c:258`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_stream.h`

### vc_stream_destroy (function) `vc_stream_destroy(st);`
- Defined: `voicecloak/src/vc_alsa.c:286`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_stream.h`

## voicecloak/src/vc_alsa.h

### runtime (function) `* * The capture and playback device names are ALSA PCM names discovered * at runtime (e.g. "hw:VSL", "plughw:2,0", "default");`
- Defined: `voicecloak/src/vc_alsa.h:15`
- Depends on: `voicecloak/src/vc_stream.h`
- Imported by: `voicecloak/src/vc_alsa.c`, `voicecloak/src/vc_rt_cli.c`

### vc_alsa_list (function) `int vc_alsa_list(void);`
- Defined: `voicecloak/src/vc_alsa.h:40`
- Doc: @brief Print the available ALSA PCM devices to stdout. @return 0 on success, -1 on error.
- Depends on: `voicecloak/src/vc_stream.h`
- Imported by: `voicecloak/src/vc_alsa.c`, `voicecloak/src/vc_rt_cli.c`

### vc_alsa_run (function) `int vc_alsa_run(const vc_alsa_cfg_t *cfg);`
- Defined: `voicecloak/src/vc_alsa.h:47`
- Doc: @brief Open capture and playback, run the processing loop until *cfg->stop becomes non-zero or a fatal error occurs. @re
- Depends on: `voicecloak/src/vc_stream.h`
- Imported by: `voicecloak/src/vc_alsa.c`, `voicecloak/src/vc_rt_cli.c`

## voicecloak/src/vc_cli.c

### print_usage (function) `static void print_usage(const char *prog)`
- Defined: `voicecloak/src/vc_cli.c:8`
- Doc: include "vc_wav.h" include "vc_dsp.h" include "vc_crypto.h" include <stdio.h> include <stdlib.h> include <string.h> incl
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_wav.h`

### cmd_keygen (function) `static int cmd_keygen(void)`
- Defined: `voicecloak/src/vc_cli.c:40`
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_wav.h`

### cmd_cloak (function) `static int cmd_cloak(const char *pubkey_path,
                     const char *in_path, const cha...`
- Defined: `voicecloak/src/vc_cli.c:52`
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_wav.h`

### cmd_info (function) `static int cmd_info(const char *path)`
- Defined: `voicecloak/src/vc_cli.c:141`
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_wav.h`

### main (function) `int main(int argc, char *argv[])`
- Defined: `voicecloak/src/vc_cli.c:176`
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_wav.h`

### printf (function) `printf( "VoiceCloak - cryptographically secure voice anonymizer\n" "\n" "Usage: %s <command> [options]\n" "\n" "Commands:\n" " keygen Generate RSA-4096 keypair\n" " cloak -k <pubkey> <in.wav> <out.wav`
- Defined: `voicecloak/src/vc_cli.c:10`
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_wav.h`

### fprintf (function) `fprintf(stderr, "Error: key generation failed.\n");`
- Defined: `voicecloak/src/vc_cli.c:44`
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_wav.h`

### free (function) `free(samples);`
- Defined: `voicecloak/src/vc_cli.c:74`
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_wav.h`

### fclose (function) `fclose(ur);`
- Defined: `voicecloak/src/vc_cli.c:76`
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_wav.h`

### snprintf (function) `snprintf(sidecar_path, sizeof(sidecar_path), "%s.vc", out_path);`
- Defined: `voicecloak/src/vc_cli.c:93`
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_wav.h`

### fwrite (function) `fwrite(enc_seed, 1, enc_len, sf);`
- Defined: `voicecloak/src/vc_cli.c:99`
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_wav.h`

## voicecloak/src/vc_crypto.c

### openssl_init (function) `static void openssl_init(void)`
- Defined: `voicecloak/src/vc_crypto.c:11`
- Doc: include "vc_crypto.h" include <stdio.h> include <stdlib.h> include <string.h> include <openssl/evp.h> include <openssl/p
- Depends on: `voicecloak/src/vc_crypto.h`

### vc_crypto_keygen (function) `int vc_crypto_keygen(const char *pubkey_path, const char *privkey_path)`
- Defined: `voicecloak/src/vc_crypto.c:16`
- Depends on: `voicecloak/src/vc_crypto.h`

### vc_crypto_seal (function) `int vc_crypto_seal(const char *pubkey_path,
                   const unsigned char *seed, size_t ...`
- Defined: `voicecloak/src/vc_crypto.c:46`
- Depends on: `voicecloak/src/vc_crypto.h`

### vc_crypto_unseal (function) `int vc_crypto_unseal(const char *privkey_path,
                     const unsigned char *enc, siz...`
- Defined: `voicecloak/src/vc_crypto.c:70`
- Depends on: `voicecloak/src/vc_crypto.h`

### vc_crypto_derive_seeds (function) `int vc_crypto_derive_seeds(const unsigned char *master_seed, size_t seed_len,
                   ...`
- Defined: `voicecloak/src/vc_crypto.c:95`
- Depends on: `voicecloak/src/vc_crypto.h`

### vc_prng_create (function) `vc_prng_t *vc_prng_create(const unsigned char *seed)`
- Defined: `voicecloak/src/vc_crypto.c:142`
- Depends on: `voicecloak/src/vc_crypto.h`

### vc_prng_destroy (function) `void vc_prng_destroy(vc_prng_t *p)`
- Defined: `voicecloak/src/vc_crypto.c:156`
- Depends on: `voicecloak/src/vc_crypto.h`

### vc_prng_fill (function) `void vc_prng_fill(vc_prng_t *p, unsigned char *buf, size_t len)`
- Defined: `voicecloak/src/vc_crypto.c:163`
- Depends on: `voicecloak/src/vc_crypto.h`

### vc_prng_float (function) `float vc_prng_float(vc_prng_t *p, float low, float high)`
- Defined: `voicecloak/src/vc_crypto.c:183`
- Depends on: `voicecloak/src/vc_crypto.h`

### fclose (function) `fclose(fp);`
- Defined: `voicecloak/src/vc_crypto.c:56`
- Depends on: `voicecloak/src/vc_crypto.h`

### EVP_PKEY_free (function) `EVP_PKEY_free(pkey);`
- Defined: `voicecloak/src/vc_crypto.c:63`
- Depends on: `voicecloak/src/vc_crypto.h`

### EVP_PKEY_CTX_free (function) `EVP_PKEY_CTX_free(ctx);`
- Defined: `voicecloak/src/vc_crypto.c:67`
- Depends on: `voicecloak/src/vc_crypto.h`

### memcpy (function) `memcpy(data, infos[i], info_lens[i]);`
- Defined: `voicecloak/src/vc_crypto.c:127`
- Depends on: `voicecloak/src/vc_crypto.h`

### memset (function) `memset(p->counter, 0, sizeof(p->counter));`
- Defined: `voicecloak/src/vc_crypto.c:150`
- Depends on: `voicecloak/src/vc_crypto.h`

### EVP_EncryptInit_ex (function) `EVP_EncryptInit_ex(p->ctx, EVP_aes_256_ctr(), NULL, seed, p->counter);`
- Defined: `voicecloak/src/vc_crypto.c:152`
- Depends on: `voicecloak/src/vc_crypto.h`

### free (function) `free(p);`
- Defined: `voicecloak/src/vc_crypto.c:161`
- Depends on: `voicecloak/src/vc_crypto.h`

### EVP_EncryptUpdate (function) `EVP_EncryptUpdate(p->ctx, p->keystream, &outlen, p->keystream, (int)sizeof(p->keystream));`
- Defined: `voicecloak/src/vc_crypto.c:171`
- Depends on: `voicecloak/src/vc_crypto.h`

## voicecloak/src/vc_crypto.h

### vc_crypto_keygen (function) `int vc_crypto_keygen(const char *pubkey_path, const char *privkey_path);`
- Defined: `voicecloak/src/vc_crypto.h:24`
- Doc: @brief Generate an RSA-4096 keypair and write to PEM files. @param pubkey_path   Output path for public key. @param priv
- Imported by: `voicecloak/src/vc_cli.c`, `voicecloak/src/vc_crypto.c`, `voicecloak/src/vc_dsp.c`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/src/vc_rt_seed.c`

### vc_crypto_seal (function) `int vc_crypto_seal(const char *pubkey_path, const unsigned char *seed, size_t seed_len, unsigned char *enc_out, size_t *enc_len);`
- Defined: `voicecloak/src/vc_crypto.h:35`
- Doc: @brief Encrypt a symmetric session seed using RSA-4096 public key. @param pubkey_path   Path to PEM public key. @param s
- Imported by: `voicecloak/src/vc_cli.c`, `voicecloak/src/vc_crypto.c`, `voicecloak/src/vc_dsp.c`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/src/vc_rt_seed.c`

### vc_crypto_unseal (function) `int vc_crypto_unseal(const char *privkey_path, const unsigned char *enc, size_t enc_len, unsigned char *seed, size_t seed_len);`
- Defined: `voicecloak/src/vc_crypto.h:48`
- Doc: @brief Decrypt the session seed using RSA-4096 private key. @param privkey_path  Path to PEM private key. @param enc    
- Imported by: `voicecloak/src/vc_cli.c`, `voicecloak/src/vc_crypto.c`, `voicecloak/src/vc_dsp.c`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/src/vc_rt_seed.c`

### vc_crypto_derive_seeds (function) `int vc_crypto_derive_seeds(const unsigned char *master_seed, size_t seed_len, unsigned char *pitch_seed, unsigned char *formant_seed, unsigned char *spectral_seed);`
- Defined: `voicecloak/src/vc_crypto.h:61`
- Doc: @brief Derive sub-seeds from a master seed via HKDF-SHA256. @param master_seed   96-byte master seed. @param seed_len   
- Imported by: `voicecloak/src/vc_cli.c`, `voicecloak/src/vc_crypto.c`, `voicecloak/src/vc_dsp.c`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/src/vc_rt_seed.c`

### vc_prng_create (function) `vc_prng_t *vc_prng_create(const unsigned char *seed);`
- Defined: `voicecloak/src/vc_crypto.h:77`
- Doc: @brief Create a PRNG from a 32-byte seed.
- Imported by: `voicecloak/src/vc_cli.c`, `voicecloak/src/vc_crypto.c`, `voicecloak/src/vc_dsp.c`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/src/vc_rt_seed.c`

### vc_prng_destroy (function) `void vc_prng_destroy(vc_prng_t *p);`
- Defined: `voicecloak/src/vc_crypto.h:82`
- Doc: @brief Release PRNG.
- Imported by: `voicecloak/src/vc_cli.c`, `voicecloak/src/vc_crypto.c`, `voicecloak/src/vc_dsp.c`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/src/vc_rt_seed.c`

### vc_prng_fill (function) `void vc_prng_fill(vc_prng_t *p, unsigned char *buf, size_t len);`
- Defined: `voicecloak/src/vc_crypto.h:87`
- Doc: @brief Fill buffer with deterministic pseudo-random bytes.
- Imported by: `voicecloak/src/vc_cli.c`, `voicecloak/src/vc_crypto.c`, `voicecloak/src/vc_dsp.c`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/src/vc_rt_seed.c`

### vc_prng_float (function) `float vc_prng_float(vc_prng_t *p, float low, float high);`
- Defined: `voicecloak/src/vc_crypto.h:92`
- Doc: @brief Generate a float in [low, high] deterministically.
- Imported by: `voicecloak/src/vc_cli.c`, `voicecloak/src/vc_crypto.c`, `voicecloak/src/vc_dsp.c`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/src/vc_rt_seed.c`

## voicecloak/src/vc_dsp.c

### stft_process (function) `static int stft_process(const float *samples, size_t num_samples,
                        float *...`
- Defined: `voicecloak/src/vc_dsp.c:11`
- Doc: define VC_FFT_SIZE 2048U define VC_HOP_SIZE  (VC_FFT_SIZE / 4)
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_stft.h`

### stft_reconstruct (function) `static int stft_reconstruct(const float *mag, const float *phase,
                            siz...`
- Defined: `voicecloak/src/vc_dsp.c:20`
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_stft.h`

### compute_out_len (function) `static size_t compute_out_len(size_t nframes, size_t hop)`
- Defined: `voicecloak/src/vc_dsp.c:30`
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_stft.h`

### vc_dsp_pitch_shift (function) `int vc_dsp_pitch_shift(const float *samples, size_t num_samples,
                       uint32_t ...`
- Defined: `voicecloak/src/vc_dsp.c:34`
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_stft.h`

### vc_dsp_formant_shift (function) `int vc_dsp_formant_shift(const float *samples, size_t num_samples,
                         uint3...`
- Defined: `voicecloak/src/vc_dsp.c:90`
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_stft.h`

### vc_dsp_spectral_scramble (function) `int vc_dsp_spectral_scramble(const float *samples, size_t num_samples,
                          ...`
- Defined: `voicecloak/src/vc_dsp.c:160`
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_stft.h`

### trim_edges (function) `static void trim_edges(float **buf, size_t *len)`
- Defined: `voicecloak/src/vc_dsp.c:233`
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_stft.h`

### normalize_rms (function) `static void normalize_rms(const float *in, size_t in_len,
                          float *out, s...`
- Defined: `voicecloak/src/vc_dsp.c:254`
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_stft.h`

### vc_dsp_cloak (function) `int vc_dsp_cloak(const float *samples, size_t num_samples,
                 uint32_t sample_rate,...`
- Defined: `voicecloak/src/vc_dsp.c:271`
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_stft.h`

### vc_stft_destroy (function) `vc_stft_destroy(st);`
- Defined: `voicecloak/src/vc_dsp.c:17`
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_stft.h`

### memcpy (function) `memcpy(synth_phase, phase, nbins * sizeof(float));`
- Defined: `voicecloak/src/vc_dsp.c:54`
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_stft.h`

### free (function) `free(synth_phase);`
- Defined: `voicecloak/src/vc_dsp.c:74`
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_stft.h`

### memset (function) `memset(dst, 0, nbins * sizeof(float));`
- Defined: `voicecloak/src/vc_dsp.c:113`
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_stft.h`

### vc_prng_destroy (function) `vc_prng_destroy(pp);`
- Defined: `voicecloak/src/vc_dsp.c:285`
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_dsp.h`, `voicecloak/src/vc_stft.h`

## voicecloak/src/vc_dsp.h

### vc_dsp_pitch_shift (function) `int vc_dsp_pitch_shift(const float *samples, size_t num_samples, uint32_t sample_rate, float semitones, float **out, size_t *out_len);`
- Defined: `voicecloak/src/vc_dsp.h:15`
- Imported by: `voicecloak/src/vc_cli.c`, `voicecloak/src/vc_dsp.c`

### vc_dsp_formant_shift (function) `int vc_dsp_formant_shift(const float *samples, size_t num_samples, uint32_t sample_rate, float shift_factor, float **out, size_t *out_len);`
- Defined: `voicecloak/src/vc_dsp.h:19`
- Imported by: `voicecloak/src/vc_cli.c`, `voicecloak/src/vc_dsp.c`

### vc_dsp_spectral_scramble (function) `int vc_dsp_spectral_scramble(const float *samples, size_t num_samples, uint32_t sample_rate, float intensity, float **out, size_t *out_len);`
- Defined: `voicecloak/src/vc_dsp.h:23`
- Imported by: `voicecloak/src/vc_cli.c`, `voicecloak/src/vc_dsp.c`

### vc_dsp_cloak (function) `int vc_dsp_cloak(const float *samples, size_t num_samples, uint32_t sample_rate, const unsigned char *pitch_seed, const unsigned char *formant_seed, const unsigned char *spectral_seed, VcMode mode, fl`
- Defined: `voicecloak/src/vc_dsp.h:27`
- Imported by: `voicecloak/src/vc_cli.c`, `voicecloak/src/vc_dsp.c`

## voicecloak/src/vc_fft.c

### bit_reverse (function) `static unsigned int bit_reverse(unsigned int x, unsigned int bits)`
- Defined: `voicecloak/src/vc_fft.c:9`
- Doc: ifndef M_PI define M_PI 3.14159265358979323846f endif
- Depends on: `voicecloak/src/vc_fft.h`

### bit_reverse_reorder (function) `static void bit_reverse_reorder(size_t n, float *real, float *imag)`
- Defined: `voicecloak/src/vc_fft.c:19`
- Depends on: `voicecloak/src/vc_fft.h`

### vc_fft (function) `void vc_fft(size_t n, float *real, float *imag, int inverse)`
- Defined: `voicecloak/src/vc_fft.c:35`
- Depends on: `voicecloak/src/vc_fft.h`

### free (function) `free(work_r);`
- Defined: `voicecloak/src/vc_fft.c:73`
- Depends on: `voicecloak/src/vc_fft.h`

## voicecloak/src/vc_fft.h

### FFT (function) `* FFT(IFFT(x)) == IFFT(FFT(x)) == x. */ void vc_fft(size_t n, float *real, float *imag, int inverse);`
- Defined: `voicecloak/src/vc_fft.h:18`
- Imported by: `voicecloak/src/vc_fft.c`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/src/vc_stft.c`, `voicecloak/src/vc_stream.c`, `voicecloak/tests/test_vc_fft.c`, `voicecloak/tests/test_vc_stream.c`

## voicecloak/src/vc_rt.c

### vc_rt_create (function) `vc_rt_ctx_t *vc_rt_create(size_t nbins, vc_rt_params_t params)`
- Defined: `voicecloak/src/vc_rt.c:22`
- Depends on: `voicecloak/src/vc_rt.h`

### vc_rt_destroy (function) `void vc_rt_destroy(vc_rt_ctx_t *c)`
- Defined: `voicecloak/src/vc_rt.c:42`
- Depends on: `voicecloak/src/vc_rt.h`

### vc_rt_reset (function) `void vc_rt_reset(vc_rt_ctx_t *c)`
- Defined: `voicecloak/src/vc_rt.c:53`
- Depends on: `voicecloak/src/vc_rt.h`

### vc_rt_semitones_to_ratio (function) `float vc_rt_semitones_to_ratio(float semitones)`
- Defined: `voicecloak/src/vc_rt.c:60`
- Depends on: `voicecloak/src/vc_rt.h`

### wrap_pi (function) `static double wrap_pi(double x)`
- Defined: `voicecloak/src/vc_rt.c:64`
- Depends on: `voicecloak/src/vc_rt.h`

### formant_warp (function) `static void formant_warp(float *syn_mag, size_t nbins, float factor)`
- Defined: `voicecloak/src/vc_rt.c:70`
- Depends on: `voicecloak/src/vc_rt.h`

### vc_rt_transform (function) `void vc_rt_transform(float *mag, float *phase, size_t nbins,
                     uint32_t sample...`
- Defined: `voicecloak/src/vc_rt.c:105`
- Depends on: `voicecloak/src/vc_rt.h`

### free (function) `free(c->prev_phase);`
- Defined: `voicecloak/src/vc_rt.c:45`
- Depends on: `voicecloak/src/vc_rt.h`

### memset (function) `memset(c->prev_phase, 0, c->nbins * sizeof(double));`
- Defined: `voicecloak/src/vc_rt.c:56`
- Depends on: `voicecloak/src/vc_rt.h`

### powf (function) `return powf(2.0f, semitones / 12.0f);`
- Defined: `voicecloak/src/vc_rt.c:62`
- Depends on: `voicecloak/src/vc_rt.h`

## voicecloak/src/vc_rt.h

### vc_rt_create (function) `vc_rt_ctx_t *vc_rt_create(size_t nbins, vc_rt_params_t params);`
- Defined: `voicecloak/src/vc_rt.h:32`
- Doc: @brief Create a transform context sized for @p nbins frequency bins. @return Context or NULL on allocation failure / nbi
- Imported by: `voicecloak/src/vc_rt.c`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/src/vc_rt_seed.c`, `voicecloak/tests/test_vc_stream.c`

### vc_rt_destroy (function) `void vc_rt_destroy(vc_rt_ctx_t *c);`
- Defined: `voicecloak/src/vc_rt.h:35`
- Doc: @brief Create a transform context sized for @p nbins frequency bins. @return Context or NULL on allocation failure / nbi
- Imported by: `voicecloak/src/vc_rt.c`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/src/vc_rt_seed.c`, `voicecloak/tests/test_vc_stream.c`

### vc_rt_reset (function) `void vc_rt_reset(vc_rt_ctx_t *c);`
- Defined: `voicecloak/src/vc_rt.h:38`
- Doc: @brief Create a transform context sized for @p nbins frequency bins. @return Context or NULL on allocation failure / nbi
- Imported by: `voicecloak/src/vc_rt.c`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/src/vc_rt_seed.c`, `voicecloak/tests/test_vc_stream.c`

### vc_rt_transform (function) `void vc_rt_transform(float *mag, float *phase, size_t nbins, uint32_t sample_rate, size_t hop, void *user);`
- Defined: `voicecloak/src/vc_rt.h:48`
- Doc: @brief Per-frame transform, compatible with vc_spectral_fn. @param user Must be a vc_rt_ctx_t* created with matching nbi
- Imported by: `voicecloak/src/vc_rt.c`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/src/vc_rt_seed.c`, `voicecloak/tests/test_vc_stream.c`

### vc_rt_semitones_to_ratio (function) `float vc_rt_semitones_to_ratio(float semitones);`
- Defined: `voicecloak/src/vc_rt.h:54`
- Doc: @brief Convert a semitone shift to a pitch ratio (2^(semitones/12)).
- Imported by: `voicecloak/src/vc_rt.c`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/src/vc_rt_seed.c`, `voicecloak/tests/test_vc_stream.c`

### vc_rt_derive (function) `int vc_rt_derive(const unsigned char *pitch_seed, const unsigned char *formant_seed, const unsigned char *spectral_seed, int witness_mode, vc_rt_params_t *out);`
- Defined: `voicecloak/src/vc_rt.h:65`
- Doc: @brief Derive cloak parameters from three 32-byte PRNG seeds. @param pitch_seed    32-byte seed. @param formant_seed  32
- Imported by: `voicecloak/src/vc_rt.c`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/src/vc_rt_seed.c`, `voicecloak/tests/test_vc_stream.c`

## voicecloak/src/vc_rt_cli.c

### on_sigint (function) `static void on_sigint(int sig)`
- Defined: `voicecloak/src/vc_rt_cli.c:20`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### print_usage (function) `static void print_usage(const char *prog)`
- Defined: `voicecloak/src/vc_rt_cli.c:25`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### dominant_freq (function) `static float dominant_freq(const float *x, size_t n, unsigned int sr)`
- Defined: `voicecloak/src/vc_rt_cli.c:57`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### cmd_selftest (function) `static int cmd_selftest(void)`
- Defined: `voicecloak/src/vc_rt_cli.c:80`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### resolve_params (function) `static int resolve_params(int have_fixed, float semis, float formant,
                          f...`
- Defined: `voicecloak/src/vc_rt_cli.c:118`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### cmd_live (function) `static int cmd_live(int argc, char *argv[])`
- Defined: `voicecloak/src/vc_rt_cli.c:141`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### main (function) `int main(int argc, char *argv[])`
- Defined: `voicecloak/src/vc_rt_cli.c:222`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### vc_fft (function) `vc_fft(nf, re, im, 0);`
- Defined: `voicecloak/src/vc_rt_cli.c:70`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### free (function) `free(re);`
- Defined: `voicecloak/src/vc_rt_cli.c:77`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### fprintf (function) `fprintf(stderr, "selftest: setup failed\n");`
- Defined: `voicecloak/src/vc_rt_cli.c:98`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### vc_stream_destroy (function) `vc_stream_destroy(st);`
- Defined: `voicecloak/src/vc_rt_cli.c:99`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### vc_stream_process (function) `vc_stream_process(st, in, out, n, vc_rt_transform, ctx);`
- Defined: `voicecloak/src/vc_rt_cli.c:102`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### printf (function) `printf("selftest: input dominant = %.1f Hz (expected %.1f)\n", (double)got_in, (double)in_freq);`
- Defined: `voicecloak/src/vc_rt_cli.c:108`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### fclose (function) `fclose(ur);`
- Defined: `voicecloak/src/vc_rt_cli.c:134`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### vc_rt_derive (function) `return vc_rt_derive(ps, fs, ss, witness, p);`
- Defined: `voicecloak/src/vc_rt_cli.c:139`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### memset (function) `memset(&sa, 0, sizeof(sa));`
- Defined: `voicecloak/src/vc_rt_cli.c:199`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### sigaction (function) `sigaction(SIGINT, &sa, NULL);`
- Defined: `voicecloak/src/vc_rt_cli.c:201`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### vc_rt_destroy (function) `vc_rt_destroy(ctx);`
- Defined: `voicecloak/src/vc_rt_cli.c:218`
- Depends on: `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

## voicecloak/src/vc_rt_seed.c

### vc_rt_derive (function) `int vc_rt_derive(const unsigned char *pitch_seed,
                 const unsigned char *formant_s...`
- Defined: `voicecloak/src/vc_rt_seed.c:4`
- Doc: include "vc_rt.h" include "vc_crypto.h" include <math.h>
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_rt.h`

### vc_prng_destroy (function) `vc_prng_destroy(pp);`
- Defined: `voicecloak/src/vc_rt_seed.c:15`
- Depends on: `voicecloak/src/vc_crypto.h`, `voicecloak/src/vc_rt.h`

## voicecloak/src/vc_stft.c

### vc_stft_create (function) `vc_stft_t *vc_stft_create(size_t fft_size, size_t hop_size)`
- Defined: `voicecloak/src/vc_stft.c:20`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_stft.h`

### vc_stft_destroy (function) `void vc_stft_destroy(vc_stft_t *st)`
- Defined: `voicecloak/src/vc_stft.c:57`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_stft.h`

### vc_stft_num_bins (function) `size_t vc_stft_num_bins(const vc_stft_t *st)`
- Defined: `voicecloak/src/vc_stft.c:66`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_stft.h`

### vc_stft_forward (function) `int vc_stft_forward(vc_stft_t *st,
                    const float *samples, size_t num_samples,
...`
- Defined: `voicecloak/src/vc_stft.c:70`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_stft.h`

### vc_stft_inverse (function) `int vc_stft_inverse(vc_stft_t *st,
                    const float *mag, const float *phase,
    ...`
- Defined: `voicecloak/src/vc_stft.c:118`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_stft.h`

### vc_stft_inverse_hop (function) `int vc_stft_inverse_hop(vc_stft_t *st,
                        const float *mag, const float *pha...`
- Defined: `voicecloak/src/vc_stft.c:126`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_stft.h`

### memset (function) `memset(st->win_sq_sum, 0, fft_size * sizeof(float));`
- Defined: `voicecloak/src/vc_stft.c:45`
- Doc: st->buf_r    = (float *)malloc(fft_size * sizeof(float)); st->buf_i    = (float *)malloc(fft_size * sizeof(float)); if (
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_stft.h`

### free (function) `free(st->window);`
- Defined: `voicecloak/src/vc_stft.c:60`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_stft.h`

### vc_fft (function) `vc_fft(fft_n, st->buf_r, st->buf_i, 0);`
- Defined: `voicecloak/src/vc_stft.c:101`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_stft.h`

## voicecloak/src/vc_stft.h

### vc_stft_create (function) `vc_stft_t *vc_stft_create(size_t fft_size, size_t hop_size);`
- Defined: `voicecloak/src/vc_stft.h:25`
- Doc: @brief Allocate STFT context. @param fft_size  FFT size (power of 2, e.g. 2048). @param hop_size  Hop size in samples (e
- Imported by: `voicecloak/src/vc_dsp.c`, `voicecloak/src/vc_stft.c`

### vc_stft_destroy (function) `void vc_stft_destroy(vc_stft_t *st);`
- Defined: `voicecloak/src/vc_stft.h:30`
- Doc: @brief Release STFT context.
- Imported by: `voicecloak/src/vc_dsp.c`, `voicecloak/src/vc_stft.c`

### vc_stft_forward (function) `int vc_stft_forward(vc_stft_t *st, const float *samples, size_t num_samples, float **mag, float **phase, size_t *num_frames_out);`
- Defined: `voicecloak/src/vc_stft.h:42`
- Doc: @brief Forward STFT: decompose a mono float buffer into complex frames. @param st       STFT context. @param samples  In
- Imported by: `voicecloak/src/vc_dsp.c`, `voicecloak/src/vc_stft.c`

### vc_stft_inverse (function) `int vc_stft_inverse(vc_stft_t *st, const float *mag, const float *phase, size_t num_frames, float *samples_out, size_t num_samples_out);`
- Defined: `voicecloak/src/vc_stft.h:57`
- Doc: @brief Inverse STFT: reconstruct signal from modified magnitude/phase. @param st        STFT context. @param mag       I
- Imported by: `voicecloak/src/vc_dsp.c`, `voicecloak/src/vc_stft.c`

### vc_stft_inverse_hop (function) `int vc_stft_inverse_hop(vc_stft_t *st, const float *mag, const float *phase, size_t num_frames, float *samples_out, size_t num_samples_out, size_t synth_hop);`
- Defined: `voicecloak/src/vc_stft.h:66`
- Doc: @brief Inverse STFT with custom synthesis hop (for pitch shifting). @param synth_hop  Synthesis hop size in samples (may
- Imported by: `voicecloak/src/vc_dsp.c`, `voicecloak/src/vc_stft.c`

### vc_stft_num_bins (function) `size_t vc_stft_num_bins(const vc_stft_t *st);`
- Defined: `voicecloak/src/vc_stft.h:75`
- Doc: @brief Number of frequency bins (fft_size/2 + 1).
- Imported by: `voicecloak/src/vc_dsp.c`, `voicecloak/src/vc_stft.c`

## voicecloak/src/vc_stream.c

### is_pow2 (function) `static int is_pow2(size_t v)`
- Defined: `voicecloak/src/vc_stream.c:30`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_stream.h`

### vc_stream_create (function) `vc_stream_t *vc_stream_create(size_t fft_size, size_t hop_size,
                              uin...`
- Defined: `voicecloak/src/vc_stream.c:34`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_stream.h`

### vc_stream_destroy (function) `void vc_stream_destroy(vc_stream_t *st)`
- Defined: `voicecloak/src/vc_stream.c:93`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_stream.h`

### vc_stream_latency_samples (function) `size_t vc_stream_latency_samples(const vc_stream_t *st)`
- Defined: `voicecloak/src/vc_stream.c:106`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_stream.h`

### process_frame (function) `static void process_frame(vc_stream_t *st, vc_spectral_fn fn, void *user)`
- Defined: `voicecloak/src/vc_stream.c:110`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_stream.h`

### vc_stream_process (function) `int vc_stream_process(vc_stream_t *st,
                      const float *in, float *out, size_t ...`
- Defined: `voicecloak/src/vc_stream.c:158`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_stream.h`

### free (function) `free(st->window);`
- Defined: `voicecloak/src/vc_stream.c:96`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_stream.h`

### vc_fft (function) `vc_fft(N, st->buf_r, st->buf_i, 0);`
- Defined: `voicecloak/src/vc_stream.c:120`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_stream.h`

### memmove (function) `memmove(st->out_accum, st->out_accum + st->hop_size, (N - st->hop_size) * sizeof(float));`
- Defined: `voicecloak/src/vc_stream.c:149`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_stream.h`

### memset (function) `memset(st->out_accum + (N - st->hop_size), 0, st->hop_size * sizeof(float));`
- Defined: `voicecloak/src/vc_stream.c:152`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_stream.h`

## voicecloak/src/vc_stream.h

### frames (function) `* that must persist across frames (phase-vocoder accumulators) lives * in @p user, not in the engine. */ typedef void (*vc_spectral_fn)(float *mag, float *phase, size_t nbins, uint32_t sample_rate, si`
- Defined: `voicecloak/src/vc_stream.h:32`
- Imported by: `voicecloak/src/vc_alsa.c`, `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/src/vc_stream.c`, `voicecloak/tests/test_vc_stream.c`

### vc_stream_create (function) `vc_stream_t *vc_stream_create(size_t fft_size, size_t hop_size, uint32_t sample_rate);`
- Defined: `voicecloak/src/vc_stream.h:46`
- Doc: @brief Create a streaming engine. @param fft_size  Power of two. @param hop_size  Must divide fft_size; fft_size/hop_siz
- Imported by: `voicecloak/src/vc_alsa.c`, `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/src/vc_stream.c`, `voicecloak/tests/test_vc_stream.c`

### vc_stream_destroy (function) `void vc_stream_destroy(vc_stream_t *st);`
- Defined: `voicecloak/src/vc_stream.h:50`
- Doc: @brief Create a streaming engine. @param fft_size  Power of two. @param hop_size  Must divide fft_size; fft_size/hop_siz
- Imported by: `voicecloak/src/vc_alsa.c`, `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/src/vc_stream.c`, `voicecloak/tests/test_vc_stream.c`

### vc_stream_latency_samples (function) `size_t vc_stream_latency_samples(const vc_stream_t *st);`
- Defined: `voicecloak/src/vc_stream.h:53`
- Doc: @brief Create a streaming engine. @param fft_size  Power of two. @param hop_size  Must divide fft_size; fft_size/hop_siz
- Imported by: `voicecloak/src/vc_alsa.c`, `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/src/vc_stream.c`, `voicecloak/tests/test_vc_stream.c`

### vc_stream_process (function) `int vc_stream_process(vc_stream_t *st, const float *in, float *out, size_t n, vc_spectral_fn fn, void *user);`
- Defined: `voicecloak/src/vc_stream.h:65`
- Doc: @brief Process a block, producing exactly @p n output samples. @param st   Engine. @param in   Input samples (length n).
- Imported by: `voicecloak/src/vc_alsa.c`, `voicecloak/src/vc_alsa.h`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/src/vc_stream.c`, `voicecloak/tests/test_vc_stream.c`

## voicecloak/src/vc_wav.c

### read_bytes (function) `static int read_bytes(FILE *fp, void *buf, size_t n)`
- Defined: `voicecloak/src/vc_wav.c:29`
- Doc: pragma pack(pop)
- Depends on: `voicecloak/src/vc_wav.h`

### write_bytes (function) `static int write_bytes(FILE *fp, const void *buf, size_t n)`
- Defined: `voicecloak/src/vc_wav.c:33`
- Depends on: `voicecloak/src/vc_wav.h`

### sample_to_float (function) `static float sample_to_float(const unsigned char *p, int bps)`
- Defined: `voicecloak/src/vc_wav.c:37`
- Depends on: `voicecloak/src/vc_wav.h`

### float_to_sample (function) `static void float_to_sample(float f, unsigned char *p, int bps)`
- Defined: `voicecloak/src/vc_wav.c:61`
- Depends on: `voicecloak/src/vc_wav.h`

### find_chunk (function) `static int find_chunk(FILE *fp, const char *id, uint32_t *size)`
- Defined: `voicecloak/src/vc_wav.c:77`
- Depends on: `voicecloak/src/vc_wav.h`

### vc_wav_read (function) `int vc_wav_read(const char *path,
                float **samples_out, size_t *num_samples_out,
 ...`
- Defined: `voicecloak/src/vc_wav.c:92`
- Depends on: `voicecloak/src/vc_wav.h`

### vc_wav_write (function) `int vc_wav_write(const char *path,
                 const float *samples, size_t num_samples,
   ...`
- Defined: `voicecloak/src/vc_wav.c:168`
- Depends on: `voicecloak/src/vc_wav.h`

### memcpy (function) `memcpy(&v, p, 2);`
- Defined: `voicecloak/src/vc_wav.c:44`
- Depends on: `voicecloak/src/vc_wav.h`

### fseek (function) `fseek(fp, (long)sz, SEEK_CUR);`
- Defined: `voicecloak/src/vc_wav.c:89`
- Depends on: `voicecloak/src/vc_wav.h`

### memset (function) `memset(&fmt, 0, sizeof(fmt));`
- Defined: `voicecloak/src/vc_wav.c:117`
- Depends on: `voicecloak/src/vc_wav.h`

### fclose (function) `fclose(fp);`
- Defined: `voicecloak/src/vc_wav.c:139`
- Depends on: `voicecloak/src/vc_wav.h`

### free (function) `free(raw);`
- Defined: `voicecloak/src/vc_wav.c:155`
- Depends on: `voicecloak/src/vc_wav.h`

## voicecloak/src/vc_wav.h

### vc_wav_read (function) `int vc_wav_read(const char *path, float **samples_out, size_t *num_samples_out, uint32_t *sample_rate_out);`
- Defined: `voicecloak/src/vc_wav.h:19`
- Doc: @brief Read a mono PCM WAV file into a float buffer [-1.0, 1.0]. @param path         File path. @param samples_out  Outp
- Imported by: `voicecloak/src/vc_cli.c`, `voicecloak/src/vc_wav.c`

### vc_wav_write (function) `int vc_wav_write(const char *path, const float *samples, size_t num_samples, uint32_t sample_rate);`
- Defined: `voicecloak/src/vc_wav.h:31`
- Doc: @brief Write a mono float buffer to a 16-bit PCM WAV file. @param path       File path. @param samples    Float samples 
- Imported by: `voicecloak/src/vc_cli.c`, `voicecloak/src/vc_wav.c`

## voicecloak/tests/test_vc_fft.c

### test_fft_identity (function) `static void test_fft_identity(void **state)`
- Defined: `voicecloak/tests/test_vc_fft.c:9`
- Doc: include <stdarg.h> include <stddef.h> include <setjmp.h> include <cmocka.h> include <stdlib.h> include <math.h> include 
- Depends on: `voicecloak/src/vc_fft.h`

### test_fft_dc_signal (function) `static void test_fft_dc_signal(void **state)`
- Defined: `voicecloak/tests/test_vc_fft.c:26`
- Depends on: `voicecloak/src/vc_fft.h`

### test_fft_sine (function) `static void test_fft_sine(void **state)`
- Defined: `voicecloak/tests/test_vc_fft.c:46`
- Depends on: `voicecloak/src/vc_fft.h`

### main (function) `int main(void)`
- Defined: `voicecloak/tests/test_vc_fft.c:75`
- Depends on: `voicecloak/src/vc_fft.h`

### vc_fft (function) `vc_fft(n, real, imag, 0);`
- Defined: `voicecloak/tests/test_vc_fft.c:16`
- Depends on: `voicecloak/src/vc_fft.h`

### assert_float_equal (function) `assert_float_equal(real[i], i == 0 ? 1.0f : 0.0f, 1e-4f);`
- Defined: `voicecloak/tests/test_vc_fft.c:22`
- Depends on: `voicecloak/src/vc_fft.h`

### free (function) `free(real);`
- Defined: `voicecloak/tests/test_vc_fft.c:42`
- Depends on: `voicecloak/src/vc_fft.h`

### assert_true (function) `assert_true(mag_k > mag_other * 10.0f);`
- Defined: `voicecloak/tests/test_vc_fft.c:70`
- Depends on: `voicecloak/src/vc_fft.h`

### cmocka_run_group_tests (function) `return cmocka_run_group_tests(tests, NULL, NULL);`
- Defined: `voicecloak/tests/test_vc_fft.c:82`
- Depends on: `voicecloak/src/vc_fft.h`

## voicecloak/tests/test_vc_stream.c

### gen_sines (function) `static void gen_sines(float *buf, size_t n, uint32_t sr,
                      const float *freqs...`
- Defined: `voicecloak/tests/test_vc_stream.c:19`
- Doc: define SR 48000U
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### dominant_freq (function) `static float dominant_freq(const float *x, size_t n, uint32_t sr)`
- Defined: `voicecloak/tests/test_vc_stream.c:31`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### rms (function) `static float rms(const float *x, size_t n)`
- Defined: `voicecloak/tests/test_vc_stream.c:53`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### run_stream (function) `static void run_stream(vc_stream_t *st, const float *in, float *out, size_t n,
                  ...`
- Defined: `voicecloak/tests/test_vc_stream.c:63`
- Doc: Stream a whole buffer through the engine in small, irregular chunks * to exercise arbitrary block sizes.
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### test_create_validation (function) `static void test_create_validation(void **state)`
- Defined: `voicecloak/tests/test_vc_stream.c:73`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### test_passthrough_identity (function) `static void test_passthrough_identity(void **state)`
- Defined: `voicecloak/tests/test_vc_stream.c:85`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### run_pitch (function) `static void run_pitch(float in_freq, float ratio, float expect_freq)`
- Defined: `voicecloak/tests/test_vc_stream.c:121`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### test_pitch_up_octave (function) `static void test_pitch_up_octave(void **state)`
- Defined: `voicecloak/tests/test_vc_stream.c:145`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### test_pitch_down_octave (function) `static void test_pitch_down_octave(void **state)`
- Defined: `voicecloak/tests/test_vc_stream.c:150`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### test_bounded_output (function) `static void test_bounded_output(void **state)`
- Defined: `voicecloak/tests/test_vc_stream.c:155`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### main (function) `int main(void)`
- Defined: `voicecloak/tests/test_vc_stream.c:184`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### vc_fft (function) `vc_fft(nf, re, im, 0);`
- Defined: `voicecloak/tests/test_vc_stream.c:43`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### free (function) `free(re);`
- Defined: `voicecloak/tests/test_vc_stream.c:50`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### assert_int_equal (function) `assert_int_equal(vc_stream_process(st, in + off, out + off, c, fn, user), 0);`
- Defined: `voicecloak/tests/test_vc_stream.c:69`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### assert_null (function) `assert_null(vc_stream_create(1000, 250, SR));`
- Defined: `voicecloak/tests/test_vc_stream.c:76`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### assert_non_null (function) `assert_non_null(st);`
- Defined: `voicecloak/tests/test_vc_stream.c:81`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### vc_stream_destroy (function) `vc_stream_destroy(st);`
- Defined: `voicecloak/tests/test_vc_stream.c:83`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### assert_true (function) `assert_true(best_err < 0.05f * in_rms);`
- Defined: `voicecloak/tests/test_vc_stream.c:116`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### vc_rt_destroy (function) `vc_rt_destroy(ctx);`
- Defined: `voicecloak/tests/test_vc_stream.c:140`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### srand (function) `srand(1234);`
- Defined: `voicecloak/tests/test_vc_stream.c:161`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### assert_false (function) `assert_false(isnan(out[i]));`
- Defined: `voicecloak/tests/test_vc_stream.c:175`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`

### cmocka_run_group_tests (function) `return cmocka_run_group_tests(tests, NULL, NULL);`
- Defined: `voicecloak/tests/test_vc_stream.c:193`
- Depends on: `voicecloak/src/vc_fft.h`, `voicecloak/src/vc_rt.h`, `voicecloak/src/vc_stream.h`
