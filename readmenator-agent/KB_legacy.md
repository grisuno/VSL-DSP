# Subsystem: legacy

## legacy/app.py
- Layer: utility
- Doc: app.py  Autor: Gris Iscomeback Correo electrónico: grisiscomeback[at]gmail[dot]com Fecha de creación: xx/xx/xxxx Licenci
- Language: py

## legacy/build-dkms.sh
- Layer: presentation
- Doc: AudioBox 22 VSL Enhanced Driver - Installation Script Copyright (c) 2025 grisuno (LazyOwn Project) License: GPL-2.0-or-l
- Language: sh
- Symbols:
  - `print_header` (function, line 40)
  - `print_success` (function, line 48)
  - `print_error` (function, line 52)
  - `print_warning` (function, line 56)
  - `print_info` (function, line 60)
  - `check_root` (function, line 64)
  - `check_dependencies` (function, line 72)
  - `detect_audiobox` (function, line 101)
  - `create_source_structure` (function, line 123)
  - `copy_source_files` (function, line 138)
  - `create_dkms_conf` (function, line 174)
  - `create_makefile` (function, line 193)
  - `verify_mixer_quirks` (function, line 252)
  - `build_with_dkms` (function, line 295)
  - `install_module` (function, line 309)
  - `reload_module` (function, line 323)
  - `verify_installation` (function, line 344)
  - `show_usage_info` (function, line 394)
  - `main` (function, line 452)

## legacy/main.c
- Layer: utility
- Language: c
- Symbols:
  - `main` (function, line 5) `int main()`
- Depends on: `legacy/vsl_dsp_logic.h`, `legacy/vsl_dsp_transport.h`

## legacy/mixer_quirks.c
- Layer: presentation
- Doc: SPDX-License-Identifier: GPL-2.0-or-later
- Language: c
- Symbols:
  - `std_mono_table` (struct, line 45)
  - `rc_config` (struct, line 181)
  - `sb_jack` (struct, line 410)
  - `dualsense_mixer_elem_info` (struct, line 543)
  - `snd_djm_device` (struct, line 3778)
  - `snd_djm_ctl` (struct, line 3784)
  - `snd_rme_domain` (enum, line 2407)
  - `snd_rme_clock_status` (enum, line 2413)
  - `snd_create_std_mono_ctl_offset` (function, line 59) `static int snd_create_std_mono_ctl_offset(struct usb_mixer_interface *mixer,
					  unsigned int ...`
  - `snd_create_std_mono_ctl` (function, line 113) `static int snd_create_std_mono_ctl(struct usb_mixer_interface *mixer,
				   unsigned int unitid,...`
  - `snd_create_std_mono_table` (function, line 129) `static int snd_create_std_mono_table(struct usb_mixer_interface *mixer,
				     const struct std...`
  - `add_single_ctl_with_resume` (function, line 146) `static int add_single_ctl_with_resume(struct usb_mixer_interface *mixer,
				      int id,
				  ...`
  - `snd_usb_soundblaster_remote_complete` (function, line 200) `static void snd_usb_soundblaster_remote_complete(struct urb *urb)`
  - `snd_usb_sbrc_hwdep_read` (function, line 220) `static long snd_usb_sbrc_hwdep_read(struct snd_hwdep *hw, char __user *buf,
				    long count, l...`
  - `snd_usb_sbrc_hwdep_poll` (function, line 240) `static __poll_t snd_usb_sbrc_hwdep_poll(struct snd_hwdep *hw, struct file *file,
					poll_table ...`
  - `snd_usb_soundblaster_remote_init` (function, line 249) `static int snd_usb_soundblaster_remote_init(struct usb_mixer_interface *mixer)`
  - `snd_audigy2nx_led_get` (function, line 299) `static int snd_audigy2nx_led_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)`
  - `snd_audigy2nx_led_update` (function, line 305) `static int snd_audigy2nx_led_update(struct usb_mixer_interface *mixer,
				    int value, int index)`
  - `snd_audigy2nx_led_put` (function, line 334) `static int snd_audigy2nx_led_put(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_value *u...`
  - `snd_audigy2nx_led_resume` (function, line 353) `static int snd_audigy2nx_led_resume(struct usb_mixer_elem_list *list)`
  - `snd_audigy2nx_controls_create` (function, line 375) `static int snd_audigy2nx_controls_create(struct usb_mixer_interface *mixer)`
  - `snd_audigy2nx_proc_read` (function, line 407) `static void snd_audigy2nx_proc_read(struct snd_info_entry *entry,
				    struct snd_info_buffer ...`
  - `snd_emu0204_ch_switch_info` (function, line 457) `static int snd_emu0204_ch_switch_info(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_ele...`
  - `snd_emu0204_ch_switch_get` (function, line 465) `static int snd_emu0204_ch_switch_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
  - `snd_emu0204_ch_switch_update` (function, line 472) `static int snd_emu0204_ch_switch_update(struct usb_mixer_interface *mixer,
					int value)`
  - `snd_emu0204_ch_switch_put` (function, line 490) `static int snd_emu0204_ch_switch_put(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
  - `snd_emu0204_ch_switch_resume` (function, line 509) `static int snd_emu0204_ch_switch_resume(struct usb_mixer_elem_list *list)`
  - `snd_emu0204_controls_create` (function, line 524) `static int snd_emu0204_controls_create(struct usb_mixer_interface *mixer)`
  - `snd_dualsense_ih_event` (function, line 550) `static void snd_dualsense_ih_event(struct input_handle *handle,
				   unsigned int type, unsigne...`
  - `snd_dualsense_ih_match` (function, line 571) `static bool snd_dualsense_ih_match(struct input_handler *handler,
				   struct input_dev *dev)`
  - `snd_dualsense_ih_connect` (function, line 618) `static int snd_dualsense_ih_connect(struct input_handler *handler,
				    struct input_dev *dev,...`
  - `snd_dualsense_ih_disconnect` (function, line 650) `static void snd_dualsense_ih_disconnect(struct input_handle *handle)`
  - `snd_dualsense_ih_start` (function, line 657) `static void snd_dualsense_ih_start(struct input_handle *handle)`
  - `snd_dualsense_jack_get` (function, line 680) `static int snd_dualsense_jack_get(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...`
  - `snd_dualsense_resume_jack` (function, line 697) `static int snd_dualsense_resume_jack(struct usb_mixer_elem_list *list)`
  - `snd_dualsense_mixer_elem_free` (function, line 704) `static void snd_dualsense_mixer_elem_free(struct snd_kcontrol *kctl)`
  - `snd_dualsense_jack_create` (function, line 714) `static int snd_dualsense_jack_create(struct usb_mixer_interface *mixer,
				     const char *name...`
  - `snd_dualsense_controls_create` (function, line 778) `static int snd_dualsense_controls_create(struct usb_mixer_interface *mixer)`
  - `snd_xonar_u1_switch_get` (function, line 792) `static int snd_xonar_u1_switch_get(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...`
  - `snd_xonar_u1_switch_update` (function, line 799) `static int snd_xonar_u1_switch_update(struct usb_mixer_interface *mixer,
				      unsigned char ...`
  - `snd_xonar_u1_switch_put` (function, line 813) `static int snd_xonar_u1_switch_put(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...`
  - `snd_xonar_u1_switch_resume` (function, line 833) `static int snd_xonar_u1_switch_resume(struct usb_mixer_elem_list *list)`
  - `snd_xonar_u1_controls_create` (function, line 848) `static int snd_xonar_u1_controls_create(struct usb_mixer_interface *mixer)`
  - `snd_mbox1_is_spdif_synced` (function, line 857) `static int snd_mbox1_is_spdif_synced(struct snd_usb_audio *chip)`
  - `snd_mbox1_set_clk_source` (function, line 877) `static int snd_mbox1_set_clk_source(struct snd_usb_audio *chip, int rate_or_zero)`
  - `snd_mbox1_is_spdif_input` (function, line 895) `static int snd_mbox1_is_spdif_input(struct snd_usb_audio *chip)`
  - `snd_mbox1_set_input_source` (function, line 915) `static int snd_mbox1_set_input_source(struct snd_usb_audio *chip, int is_spdif)`
  - `snd_mbox1_clk_switch_get` (function, line 934) `static int snd_mbox1_clk_switch_get(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...`
  - `snd_mbox1_clk_switch_update` (function, line 954) `static int snd_mbox1_clk_switch_update(struct usb_mixer_interface *mixer, int is_spdif_sync)`
  - `snd_mbox1_clk_switch_put` (function, line 979) `static int snd_mbox1_clk_switch_put(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...`
  - `snd_mbox1_clk_switch_info` (function, line 997) `static int snd_mbox1_clk_switch_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
  - `snd_mbox1_clk_switch_resume` (function, line 1008) `static int snd_mbox1_clk_switch_resume(struct usb_mixer_elem_list *list)`
  - `snd_mbox1_src_switch_get` (function, line 1015) `static int snd_mbox1_src_switch_get(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...`
  - `snd_mbox1_src_switch_update` (function, line 1022) `static int snd_mbox1_src_switch_update(struct usb_mixer_interface *mixer, int is_spdif_input)`
  - `snd_mbox1_src_switch_put` (function, line 1046) `static int snd_mbox1_src_switch_put(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...`
  - `snd_mbox1_src_switch_info` (function, line 1064) `static int snd_mbox1_src_switch_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
  - `snd_mbox1_src_switch_resume` (function, line 1075) `static int snd_mbox1_src_switch_resume(struct usb_mixer_elem_list *list)`
  - `snd_mbox1_controls_create` (function, line 1102) `static int snd_mbox1_controls_create(struct usb_mixer_interface *mixer)`
  - `snd_ni_control_init_val` (function, line 1121) `static int snd_ni_control_init_val(struct usb_mixer_interface *mixer,
				   struct snd_kcontrol ...`
  - `snd_nativeinstruments_control_get` (function, line 1143) `static int snd_nativeinstruments_control_get(struct snd_kcontrol *kcontrol,
					     struct snd_...`
  - `snd_ni_update_cur_val` (function, line 1150) `static int snd_ni_update_cur_val(struct usb_mixer_elem_list *list)`
  - `snd_nativeinstruments_control_put` (function, line 1164) `static int snd_nativeinstruments_control_put(struct snd_kcontrol *kcontrol,
					     struct snd_...`
  - `snd_nativeinstruments_create_mixer` (function, line 1235) `static int snd_nativeinstruments_create_mixer(struct usb_mixer_interface *mixer,
					      const...`
  - `snd_ftu_eff_switch_info` (function, line 1267) `static int snd_ftu_eff_switch_info(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_info...`
  - `snd_ftu_eff_switch_init` (function, line 1278) `static int snd_ftu_eff_switch_init(struct usb_mixer_interface *mixer,
				   struct snd_kcontrol ...`
  - `snd_ftu_eff_switch_get` (function, line 1301) `static int snd_ftu_eff_switch_get(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...`
  - `snd_ftu_eff_switch_update` (function, line 1308) `static int snd_ftu_eff_switch_update(struct usb_mixer_elem_list *list)`
  - `snd_ftu_eff_switch_put` (function, line 1329) `static int snd_ftu_eff_switch_put(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...`
  - `snd_ftu_create_effect_switch` (function, line 1347) `static int snd_ftu_create_effect_switch(struct usb_mixer_interface *mixer,
					int validx, int b...`
  - `snd_ftu_create_volume_ctls` (function, line 1373) `static int snd_ftu_create_volume_ctls(struct usb_mixer_interface *mixer)`
  - `snd_ftu_create_effect_volume_ctl` (function, line 1412) `static int snd_ftu_create_effect_volume_ctl(struct usb_mixer_interface *mixer)`
  - `snd_ftu_create_effect_duration_ctl` (function, line 1425) `static int snd_ftu_create_effect_duration_ctl(struct usb_mixer_interface *mixer)`
  - `snd_ftu_create_effect_feedback_ctl` (function, line 1438) `static int snd_ftu_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)`
  - `snd_ftu_create_effect_return_ctls` (function, line 1450) `static int snd_ftu_create_effect_return_ctls(struct usb_mixer_interface *mixer)`
  - `snd_ftu_create_effect_send_ctls` (function, line 1474) `static int snd_ftu_create_effect_send_ctls(struct usb_mixer_interface *mixer)`
  - `snd_ftu_create_mixer` (function, line 1507) `static int snd_ftu_create_mixer(struct usb_mixer_interface *mixer)`
  - `snd_emuusb_set_samplerate` (function, line 1542) `void snd_emuusb_set_samplerate(struct snd_usb_audio *chip,
			       unsigned char samplerate_id)`
  - `list_for_each_entry` (function, line 1549) `list_for_each_entry(mixer, &chip->mixer_list, list)`
  - `snd_c400_create_vol_ctls` (function, line 1563) `static int snd_c400_create_vol_ctls(struct usb_mixer_interface *mixer)`
  - `snd_c400_create_effect_volume_ctl` (function, line 1612) `static int snd_c400_create_effect_volume_ctl(struct usb_mixer_interface *mixer)`
  - `snd_c400_create_effect_duration_ctl` (function, line 1625) `static int snd_c400_create_effect_duration_ctl(struct usb_mixer_interface *mixer)`
  - `snd_c400_create_effect_feedback_ctl` (function, line 1638) `static int snd_c400_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)`
  - `snd_c400_create_effect_vol_ctls` (function, line 1650) `static int snd_c400_create_effect_vol_ctls(struct usb_mixer_interface *mixer)`
  - `snd_c400_create_effect_ret_vol_ctls` (function, line 1695) `static int snd_c400_create_effect_ret_vol_ctls(struct usb_mixer_interface *mixer)`
  - `snd_c400_create_mixer` (function, line 1737) `static int snd_c400_create_mixer(struct usb_mixer_interface *mixer)`
  - `snd_microii_spdif_info` (function, line 1869) `static int snd_microii_spdif_info(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_info *...`
  - `snd_microii_spdif_default_get` (function, line 1877) `static int snd_microii_spdif_default_get(struct snd_kcontrol *kcontrol,
					 struct snd_ctl_elem...`
  - `snd_microii_spdif_default_update` (function, line 1924) `static int snd_microii_spdif_default_update(struct usb_mixer_elem_list *list)`
  - `snd_microii_spdif_default_put` (function, line 1960) `static int snd_microii_spdif_default_put(struct snd_kcontrol *kcontrol,
					 struct snd_ctl_elem...`
  - `snd_microii_spdif_mask_get` (function, line 1988) `static int snd_microii_spdif_mask_get(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_ele...`
  - `snd_microii_spdif_switch_get` (function, line 1999) `static int snd_microii_spdif_switch_get(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_v...`
  - `snd_microii_spdif_switch_update` (function, line 2007) `static int snd_microii_spdif_switch_update(struct usb_mixer_elem_list *list)`
  - `snd_microii_spdif_switch_put` (function, line 2026) `static int snd_microii_spdif_switch_put(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_v...`
  - `snd_microii_controls_create` (function, line 2068) `static int snd_microii_controls_create(struct usb_mixer_interface *mixer)`
  - `snd_soundblaster_e1_switch_get` (function, line 2091) `static int snd_soundblaster_e1_switch_get(struct snd_kcontrol *kcontrol,
					  struct snd_ctl_el...`
  - `snd_soundblaster_e1_switch_update` (function, line 2098) `static int snd_soundblaster_e1_switch_update(struct usb_mixer_interface *mixer,
					     unsigne...`
  - `snd_soundblaster_e1_switch_put` (function, line 2116) `static int snd_soundblaster_e1_switch_put(struct snd_kcontrol *kcontrol,
					  struct snd_ctl_el...`
  - `snd_soundblaster_e1_switch_resume` (function, line 2130) `static int snd_soundblaster_e1_switch_resume(struct usb_mixer_elem_list *list)`
  - `snd_soundblaster_e1_switch_info` (function, line 2136) `static int snd_soundblaster_e1_switch_info(struct snd_kcontrol *kcontrol,
					   struct snd_ctl_...`
  - `snd_soundblaster_e1_switch_create` (function, line 2155) `static int snd_soundblaster_e1_switch_create(struct usb_mixer_interface *mixer)`
  - `realtek_hda_set` (function, line 2192) `static int realtek_hda_set(struct snd_usb_audio *chip, u32 cmd)`
  - `realtek_hda_get` (function, line 2202) `static int realtek_hda_get(struct snd_usb_audio *chip, u32 cmd, u32 *value)`
  - `realtek_ctl_connector_get` (function, line 2223) `static int realtek_ctl_connector_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
  - `realtek_resume_jack` (function, line 2273) `static int realtek_resume_jack(struct usb_mixer_elem_list *list)`
  - `realtek_add_jack` (function, line 2280) `static int realtek_add_jack(struct usb_mixer_interface *mixer,
			    char *name, u32 val)`
  - `dell_dock_mixer_create` (function, line 2307) `static int dell_dock_mixer_create(struct usb_mixer_interface *mixer)`
  - `dell_dock_init_vol` (function, line 2339) `static void dell_dock_init_vol(struct usb_mixer_interface *mixer, int ch, int id)`
  - `dell_dock_mixer_init` (function, line 2351) `static int dell_dock_mixer_init(struct usb_mixer_interface *mixer)`
  - `snd_rme_read_value` (function, line 2419) `static int snd_rme_read_value(struct snd_usb_audio *chip,
			      unsigned int item,
			      u3...`
  - `snd_rme_get_status1` (function, line 2438) `static int snd_rme_get_status1(struct snd_kcontrol *kcontrol,
			       u32 *status1)`
  - `snd_rme_rate_get` (function, line 2450) `static int snd_rme_rate_get(struct snd_kcontrol *kcontrol,
			    struct snd_ctl_elem_value *ucon...`
  - `snd_rme_sync_state_get` (function, line 2484) `static int snd_rme_sync_state_get(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_value ...`
  - `snd_rme_spdif_if_get` (function, line 2514) `static int snd_rme_spdif_if_get(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *uco...`
  - `snd_rme_spdif_format_get` (function, line 2527) `static int snd_rme_spdif_format_get(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_va...`
  - `snd_rme_sync_source_get` (function, line 2540) `static int snd_rme_sync_source_get(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...`
  - `snd_rme_current_freq_get` (function, line 2553) `static int snd_rme_current_freq_get(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_va...`
  - `snd_rme_rate_info` (function, line 2579) `static int snd_rme_rate_info(struct snd_kcontrol *kcontrol,
			     struct snd_ctl_elem_info *uinfo)`
  - `snd_rme_sync_state_info` (function, line 2599) `static int snd_rme_sync_state_info(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_info...`
  - `snd_rme_spdif_if_info` (function, line 2610) `static int snd_rme_spdif_if_info(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_info *ui...`
  - `snd_rme_spdif_format_info` (function, line 2621) `static int snd_rme_spdif_format_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
  - `snd_rme_sync_source_info` (function, line 2632) `static int snd_rme_sync_source_info(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_in...`
  - `snd_rme_controls_create` (function, line 2714) `static int snd_rme_controls_create(struct usb_mixer_interface *mixer)`
  - `snd_bbfpro_ctl_update` (function, line 2780) `static int snd_bbfpro_ctl_update(struct usb_mixer_interface *mixer, u8 reg,
				 u8 index, u8 value)`
  - `snd_bbfpro_ctl_get` (function, line 2811) `static int snd_bbfpro_ctl_get(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...`
  - `snd_bbfpro_ctl_info` (function, line 2834) `static int snd_bbfpro_ctl_info(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_info ...`
  - `snd_bbfpro_ctl_put` (function, line 2868) `static int snd_bbfpro_ctl_put(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...`
  - `snd_bbfpro_ctl_resume` (function, line 2907) `static int snd_bbfpro_ctl_resume(struct usb_mixer_elem_list *list)`
  - `snd_bbfpro_gain_update` (function, line 2920) `static int snd_bbfpro_gain_update(struct usb_mixer_interface *mixer,
				  u8 channel, u8 gain)`
  - `snd_bbfpro_gain_get` (function, line 2944) `static int snd_bbfpro_gain_get(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_value...`
  - `snd_bbfpro_gain_info` (function, line 2953) `static int snd_bbfpro_gain_info(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_info *uinfo)`
  - `snd_bbfpro_gain_put` (function, line 2974) `static int snd_bbfpro_gain_put(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_value...`
  - `snd_bbfpro_gain_resume` (function, line 3011) `static int snd_bbfpro_gain_resume(struct usb_mixer_elem_list *list)`
  - `snd_bbfpro_vol_update` (function, line 3024) `static int snd_bbfpro_vol_update(struct usb_mixer_interface *mixer, u16 index,
				 u32 value)`
  - `snd_bbfpro_vol_get` (function, line 3050) `static int snd_bbfpro_vol_get(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...`
  - `snd_bbfpro_vol_info` (function, line 3058) `static int snd_bbfpro_vol_info(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_info ...`
  - `snd_bbfpro_vol_put` (function, line 3068) `static int snd_bbfpro_vol_put(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...`
  - `snd_bbfpro_vol_resume` (function, line 3096) `static int snd_bbfpro_vol_resume(struct usb_mixer_elem_list *list)`
  - `snd_bbfpro_ctl_add` (function, line 3133) `static int snd_bbfpro_ctl_add(struct usb_mixer_interface *mixer, u8 reg,
			      u8 index, char ...`
  - `snd_bbfpro_gain_add` (function, line 3147) `static int snd_bbfpro_gain_add(struct usb_mixer_interface *mixer, u8 channel,
			       char *name)`
  - `snd_bbfpro_vol_add` (function, line 3159) `static int snd_bbfpro_vol_add(struct usb_mixer_interface *mixer, u16 index,
			      char *name)`
  - `snd_bbfpro_controls_create` (function, line 3171) `static int snd_bbfpro_controls_create(struct usb_mixer_interface *mixer)`
  - `snd_rme_digiface_write_reg` (function, line 3319) `static int snd_rme_digiface_write_reg(struct snd_kcontrol *kcontrol, int item, u16 mask, u16 val)`
  - `snd_rme_digiface_read_status` (function, line 3337) `static int snd_rme_digiface_read_status(struct snd_kcontrol *kcontrol, u32 status[4])`
  - `snd_rme_digiface_get_status_val` (function, line 3361) `static int snd_rme_digiface_get_status_val(struct snd_kcontrol *kcontrol)`
  - `snd_rme_digiface_rate_get` (function, line 3399) `static int snd_rme_digiface_rate_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
  - `snd_rme_digiface_enum_get` (function, line 3413) `static int snd_rme_digiface_enum_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
  - `snd_rme_digiface_enum_put` (function, line 3425) `static int snd_rme_digiface_enum_put(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
  - `snd_rme_digiface_current_sync_get` (function, line 3439) `static int snd_rme_digiface_current_sync_get(struct snd_kcontrol *kcontrol,
					     struct snd_...`
  - `snd_rme_digiface_sync_state_get` (function, line 3451) `static int snd_rme_digiface_sync_state_get(struct snd_kcontrol *kcontrol,
					   struct snd_ctl_...`
  - `snd_rme_digiface_format_info` (function, line 3474) `static int snd_rme_digiface_format_info(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_i...`
  - `snd_rme_digiface_sync_source_info` (function, line 3485) `static int snd_rme_digiface_sync_source_info(struct snd_kcontrol *kcontrol,
					     struct snd_...`
  - `snd_rme_digiface_rate_info` (function, line 3496) `static int snd_rme_digiface_rate_info(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_ele...`
  - `snd_rme_digiface_controls_create` (function, line 3685) `static int snd_rme_digiface_controls_create(struct usb_mixer_interface *mixer)`
  - `snd_djm_get_label_caplevel_common` (function, line 3792) `static const char *snd_djm_get_label_caplevel_common(u16 wvalue)`
  - `snd_djm_get_label_caplevel_high` (function, line 3804) `static const char *snd_djm_get_label_caplevel_high(u16 wvalue)`
  - `snd_djm_get_label_cap_common` (function, line 3817) `static const char *snd_djm_get_label_cap_common(u16 wvalue)`
  - `snd_djm_get_label_cap_850` (function, line 3849) `static const char *snd_djm_get_label_cap_850(u16 wvalue)`
  - `snd_djm_get_label_caplevel` (function, line 3858) `static const char *snd_djm_get_label_caplevel(u8 device_idx, u16 wvalue)`
  - `snd_djm_get_label_cap` (function, line 3867) `static const char *snd_djm_get_label_cap(u8 device_idx, u16 wvalue)`
  - `snd_djm_get_label_pb` (function, line 3875) `static const char *snd_djm_get_label_pb(u16 wvalue)`
  - `snd_djm_get_label` (function, line 3885) `static const char *snd_djm_get_label(u8 device_idx, u16 wvalue, u16 windex)`
  - `snd_djm_controls_info` (function, line 4117) `static int snd_djm_controls_info(struct snd_kcontrol *kctl,
				 struct snd_ctl_elem_info *info)`
  - `snd_djm_controls_update` (function, line 4149) `static int snd_djm_controls_update(struct usb_mixer_interface *mixer,
				   u8 device_idx, u8 gr...`
  - `snd_djm_controls_get` (function, line 4170) `static int snd_djm_controls_get(struct snd_kcontrol *kctl,
				struct snd_ctl_elem_value *elem)`
  - `snd_djm_controls_put` (function, line 4177) `static int snd_djm_controls_put(struct snd_kcontrol *kctl, struct snd_ctl_elem_value *elem)`
  - `snd_djm_controls_resume` (function, line 4194) `static int snd_djm_controls_resume(struct usb_mixer_elem_list *list)`
  - `snd_djm_controls_create` (function, line 4204) `static int snd_djm_controls_create(struct usb_mixer_interface *mixer,
				   const u8 device_idx)`
  - `snd_usb_mixer_apply_create_quirk` (function, line 4239) `int snd_usb_mixer_apply_create_quirk(struct usb_mixer_interface *mixer)`
  - `snd_usb_mixer_resume_quirk` (function, line 4421) `void snd_usb_mixer_resume_quirk(struct usb_mixer_interface *mixer)`
  - `snd_usb_mixer_rc_memory_change` (function, line 4430) `void snd_usb_mixer_rc_memory_change(struct usb_mixer_interface *mixer,
				    int unitid)`
  - `snd_dragonfly_quirk_db_scale` (function, line 4458) `static void snd_dragonfly_quirk_db_scale(struct usb_mixer_interface *mixer,
					 struct usb_mixe...`
  - `snd_fix_plt_name` (function, line 4509) `static void snd_fix_plt_name(struct snd_usb_audio *chip,
			     struct snd_ctl_elem_id *id)`
  - `snd_usb_mixer_fu_apply_quirk` (function, line 4539) `void snd_usb_mixer_fu_apply_quirk(struct usb_mixer_interface *mixer,
				  struct usb_mixer_elem_...`
  - `DECLARE_TLV_DB_RANGE` (function, line 4465) `static const DECLARE_TLV_DB_RANGE(scale, 0, 1, TLV_DB_MINMAX_ITEM(-5300, -4970), 2, 5, TLV_DB_MINMAX_ITEM(-4710, -4160), 6, 7, TLV_DB_MINMAX_ITEM(-3884, -3710), 8, 14, TLV_DB_MINMAX_ITEM(-3443, -2560)`
  - `snd_audigy2nx_led_info` (macro, line 297) `#define snd_audigy2nx_led_info`
  - `SND_DUALSENSE_JACK_OUT_TERM_ID` (macro, line 540) `#define SND_DUALSENSE_JACK_OUT_TERM_ID`
  - `SND_DUALSENSE_JACK_IN_TERM_ID` (macro, line 541) `#define SND_DUALSENSE_JACK_IN_TERM_ID`
  - `_MAKE_NI_CONTROL` (macro, line 1119) `#define _MAKE_NI_CONTROL(bRequest, wIndex)`
  - `HDA_VERB_CMD` (macro, line 2172) `#define HDA_VERB_CMD(V, N, D)`
  - `REALTEK_HDA_VALUE` (macro, line 2174) `#define REALTEK_HDA_VALUE`
  - `REALTEK_HDA_SET` (macro, line 2176) `#define REALTEK_HDA_SET`
  - `REALTEK_MANUAL_MODE` (macro, line 2177) `#define REALTEK_MANUAL_MODE`
  - `REALTEK_HDA_GET_OUT` (macro, line 2178) `#define REALTEK_HDA_GET_OUT`
  - `REALTEK_HDA_GET_IN` (macro, line 2179) `#define REALTEK_HDA_GET_IN`
  - `REALTEK_AUDIO_FUNCTION_GROUP` (macro, line 2181) `#define REALTEK_AUDIO_FUNCTION_GROUP`
  - `REALTEK_LINE1` (macro, line 2182) `#define REALTEK_LINE1`
  - `REALTEK_VENDOR_REGISTERS` (macro, line 2183) `#define REALTEK_VENDOR_REGISTERS`
  - `REALTEK_HP_OUT` (macro, line 2184) `#define REALTEK_HP_OUT`
  - `REALTEK_CBJ_CTRL2` (macro, line 2186) `#define REALTEK_CBJ_CTRL2`
  - `REALTEK_JACK_INTERRUPT_NODE` (macro, line 2188) `#define REALTEK_JACK_INTERRUPT_NODE`
  - `REALTEK_MIC_FLAG` (macro, line 2190) `#define REALTEK_MIC_FLAG`
  - `SND_RME_GET_STATUS1` (macro, line 2363) `#define SND_RME_GET_STATUS1`
  - `SND_RME_GET_CURRENT_FREQ` (macro, line 2364) `#define SND_RME_GET_CURRENT_FREQ`
  - `SND_RME_CLK_SYSTEM_SHIFT` (macro, line 2365) `#define SND_RME_CLK_SYSTEM_SHIFT`
  - `SND_RME_CLK_SYSTEM_MASK` (macro, line 2366) `#define SND_RME_CLK_SYSTEM_MASK`
  - `SND_RME_CLK_AES_SHIFT` (macro, line 2367) `#define SND_RME_CLK_AES_SHIFT`
  - `SND_RME_CLK_SPDIF_SHIFT` (macro, line 2368) `#define SND_RME_CLK_SPDIF_SHIFT`
  - `SND_RME_CLK_AES_SPDIF_MASK` (macro, line 2369) `#define SND_RME_CLK_AES_SPDIF_MASK`
  - `SND_RME_CLK_SYNC_SHIFT` (macro, line 2370) `#define SND_RME_CLK_SYNC_SHIFT`
  - `SND_RME_CLK_SYNC_MASK` (macro, line 2371) `#define SND_RME_CLK_SYNC_MASK`
  - `SND_RME_CLK_FREQMUL_SHIFT` (macro, line 2372) `#define SND_RME_CLK_FREQMUL_SHIFT`
  - `SND_RME_CLK_FREQMUL_MASK` (macro, line 2373) `#define SND_RME_CLK_FREQMUL_MASK`
  - `SND_RME_CLK_SYSTEM` (macro, line 2374) `#define SND_RME_CLK_SYSTEM(x)`
  - `SND_RME_CLK_AES` (macro, line 2376) `#define SND_RME_CLK_AES(x)`
  - `SND_RME_CLK_SPDIF` (macro, line 2378) `#define SND_RME_CLK_SPDIF(x)`
  - `SND_RME_CLK_SYNC` (macro, line 2380) `#define SND_RME_CLK_SYNC(x)`
  - `SND_RME_CLK_FREQMUL` (macro, line 2382) `#define SND_RME_CLK_FREQMUL(x)`
  - `SND_RME_CLK_AES_LOCK` (macro, line 2384) `#define SND_RME_CLK_AES_LOCK`
  - `SND_RME_CLK_AES_SYNC` (macro, line 2385) `#define SND_RME_CLK_AES_SYNC`
  - `SND_RME_CLK_SPDIF_LOCK` (macro, line 2386) `#define SND_RME_CLK_SPDIF_LOCK`
  - `SND_RME_CLK_SPDIF_SYNC` (macro, line 2387) `#define SND_RME_CLK_SPDIF_SYNC`
  - `SND_RME_SPDIF_IF_SHIFT` (macro, line 2388) `#define SND_RME_SPDIF_IF_SHIFT`
  - `SND_RME_SPDIF_FORMAT_SHIFT` (macro, line 2389) `#define SND_RME_SPDIF_FORMAT_SHIFT`
  - `SND_RME_BINARY_MASK` (macro, line 2390) `#define SND_RME_BINARY_MASK`
  - `SND_RME_SPDIF_IF` (macro, line 2391) `#define SND_RME_SPDIF_IF(x)`
  - `SND_RME_SPDIF_FORMAT` (macro, line 2393) `#define SND_RME_SPDIF_FORMAT(x)`
  - `SND_RME_RATE_IDX_AES_SPDIF_NUM` (macro, line 2405) `#define SND_RME_RATE_IDX_AES_SPDIF_NUM`
  - `SND_BBFPRO_CTL_REG_MASK` (macro, line 2744) `#define SND_BBFPRO_CTL_REG_MASK`
  - `SND_BBFPRO_CTL_IDX_MASK` (macro, line 2745) `#define SND_BBFPRO_CTL_IDX_MASK`
  - `SND_BBFPRO_CTL_IDX_SHIFT` (macro, line 2746) `#define SND_BBFPRO_CTL_IDX_SHIFT`
  - `SND_BBFPRO_CTL_VAL_MASK` (macro, line 2747) `#define SND_BBFPRO_CTL_VAL_MASK`
  - `SND_BBFPRO_CTL_VAL_SHIFT` (macro, line 2748) `#define SND_BBFPRO_CTL_VAL_SHIFT`
  - `SND_BBFPRO_CTL_REG1_CLK_MASTER` (macro, line 2749) `#define SND_BBFPRO_CTL_REG1_CLK_MASTER`
  - `SND_BBFPRO_CTL_REG1_CLK_OPTICAL` (macro, line 2750) `#define SND_BBFPRO_CTL_REG1_CLK_OPTICAL`
  - `SND_BBFPRO_CTL_REG1_SPDIF_PRO` (macro, line 2751) `#define SND_BBFPRO_CTL_REG1_SPDIF_PRO`
  - `SND_BBFPRO_CTL_REG1_SPDIF_EMPH` (macro, line 2752) `#define SND_BBFPRO_CTL_REG1_SPDIF_EMPH`
  - `SND_BBFPRO_CTL_REG1_SPDIF_OPTICAL` (macro, line 2753) `#define SND_BBFPRO_CTL_REG1_SPDIF_OPTICAL`
  - `SND_BBFPRO_CTL_REG2_48V_AN1` (macro, line 2754) `#define SND_BBFPRO_CTL_REG2_48V_AN1`
  - `SND_BBFPRO_CTL_REG2_48V_AN2` (macro, line 2755) `#define SND_BBFPRO_CTL_REG2_48V_AN2`
  - `SND_BBFPRO_CTL_REG2_SENS_IN3` (macro, line 2756) `#define SND_BBFPRO_CTL_REG2_SENS_IN3`
  - `SND_BBFPRO_CTL_REG2_SENS_IN4` (macro, line 2757) `#define SND_BBFPRO_CTL_REG2_SENS_IN4`
  - `SND_BBFPRO_CTL_REG2_PAD_AN1` (macro, line 2758) `#define SND_BBFPRO_CTL_REG2_PAD_AN1`
  - `SND_BBFPRO_CTL_REG2_PAD_AN2` (macro, line 2759) `#define SND_BBFPRO_CTL_REG2_PAD_AN2`
  - `SND_BBFPRO_MIXER_MAIN_OUT_CH_OFFSET` (macro, line 2761) `#define SND_BBFPRO_MIXER_MAIN_OUT_CH_OFFSET`
  - `SND_BBFPRO_MIXER_IDX_MASK` (macro, line 2762) `#define SND_BBFPRO_MIXER_IDX_MASK`
  - `SND_BBFPRO_MIXER_VAL_MASK` (macro, line 2763) `#define SND_BBFPRO_MIXER_VAL_MASK`
  - `SND_BBFPRO_MIXER_VAL_SHIFT` (macro, line 2764) `#define SND_BBFPRO_MIXER_VAL_SHIFT`
  - `SND_BBFPRO_MIXER_VAL_MIN` (macro, line 2765) `#define SND_BBFPRO_MIXER_VAL_MIN`
  - `SND_BBFPRO_MIXER_VAL_MAX` (macro, line 2766) `#define SND_BBFPRO_MIXER_VAL_MAX`
  - `SND_BBFPRO_GAIN_CHANNEL_MASK` (macro, line 2768) `#define SND_BBFPRO_GAIN_CHANNEL_MASK`
  - `SND_BBFPRO_GAIN_CHANNEL_SHIFT` (macro, line 2769) `#define SND_BBFPRO_GAIN_CHANNEL_SHIFT`
  - `SND_BBFPRO_GAIN_VAL_MASK` (macro, line 2770) `#define SND_BBFPRO_GAIN_VAL_MASK`
  - `SND_BBFPRO_GAIN_VAL_MIN` (macro, line 2771) `#define SND_BBFPRO_GAIN_VAL_MIN`
  - `SND_BBFPRO_GAIN_VAL_MIC_MAX` (macro, line 2772) `#define SND_BBFPRO_GAIN_VAL_MIC_MAX`
  - `SND_BBFPRO_GAIN_VAL_LINE_MAX` (macro, line 2773) `#define SND_BBFPRO_GAIN_VAL_LINE_MAX`
  - `SND_BBFPRO_USBREQ_CTL_REG1` (macro, line 2775) `#define SND_BBFPRO_USBREQ_CTL_REG1`
  - `SND_BBFPRO_USBREQ_CTL_REG2` (macro, line 2776) `#define SND_BBFPRO_USBREQ_CTL_REG2`
  - `SND_BBFPRO_USBREQ_GAIN` (macro, line 2777) `#define SND_BBFPRO_USBREQ_GAIN`
  - `SND_BBFPRO_USBREQ_MIXER` (macro, line 2778) `#define SND_BBFPRO_USBREQ_MIXER`
  - `RME_DIGIFACE_READ_STATUS` (macro, line 3298) `#define RME_DIGIFACE_READ_STATUS`
  - `RME_DIGIFACE_STATUS_REG0L` (macro, line 3299) `#define RME_DIGIFACE_STATUS_REG0L`
  - `RME_DIGIFACE_STATUS_REG0H` (macro, line 3300) `#define RME_DIGIFACE_STATUS_REG0H`
  - `RME_DIGIFACE_STATUS_REG1L` (macro, line 3301) `#define RME_DIGIFACE_STATUS_REG1L`
  - `RME_DIGIFACE_STATUS_REG1H` (macro, line 3302) `#define RME_DIGIFACE_STATUS_REG1H`
  - `RME_DIGIFACE_STATUS_REG2L` (macro, line 3303) `#define RME_DIGIFACE_STATUS_REG2L`
  - `RME_DIGIFACE_STATUS_REG2H` (macro, line 3304) `#define RME_DIGIFACE_STATUS_REG2H`
  - `RME_DIGIFACE_STATUS_REG3L` (macro, line 3305) `#define RME_DIGIFACE_STATUS_REG3L`
  - `RME_DIGIFACE_STATUS_REG3H` (macro, line 3306) `#define RME_DIGIFACE_STATUS_REG3H`
  - `RME_DIGIFACE_CTL_REG1` (macro, line 3308) `#define RME_DIGIFACE_CTL_REG1`
  - `RME_DIGIFACE_CTL_REG2` (macro, line 3309) `#define RME_DIGIFACE_CTL_REG2`
  - `RME_DIGIFACE_REGISTER` (macro, line 3312) `#define RME_DIGIFACE_REGISTER(reg, mask)`
  - `RME_DIGIFACE_INVERT` (macro, line 3313) `#define RME_DIGIFACE_INVERT`
  - `field_get` (macro, line 3316) `#define field_get(_mask, _reg)`
  - `field_prep` (macro, line 3317) `#define field_prep(_mask, _val)`
  - `SND_DJM_CAP_LINE` (macro, line 3715) `#define SND_DJM_CAP_LINE`
  - `SND_DJM_CAP_CDLINE` (macro, line 3716) `#define SND_DJM_CAP_CDLINE`
  - `SND_DJM_CAP_DIGITAL` (macro, line 3717) `#define SND_DJM_CAP_DIGITAL`
  - `SND_DJM_CAP_PHONO` (macro, line 3718) `#define SND_DJM_CAP_PHONO`
  - `SND_DJM_CAP_PREFADER` (macro, line 3719) `#define SND_DJM_CAP_PREFADER`
  - `SND_DJM_CAP_PFADER` (macro, line 3720) `#define SND_DJM_CAP_PFADER`
  - `SND_DJM_CAP_XFADERA` (macro, line 3721) `#define SND_DJM_CAP_XFADERA`
  - `SND_DJM_CAP_XFADERB` (macro, line 3722) `#define SND_DJM_CAP_XFADERB`
  - `SND_DJM_CAP_MIC` (macro, line 3723) `#define SND_DJM_CAP_MIC`
  - `SND_DJM_CAP_AUX` (macro, line 3724) `#define SND_DJM_CAP_AUX`
  - `SND_DJM_CAP_RECOUT` (macro, line 3725) `#define SND_DJM_CAP_RECOUT`
  - `SND_DJM_CAP_RECOUT_NOMIC` (macro, line 3726) `#define SND_DJM_CAP_RECOUT_NOMIC`
  - `SND_DJM_CAP_NONE` (macro, line 3727) `#define SND_DJM_CAP_NONE`
  - `SND_DJM_CAP_FXSEND` (macro, line 3728) `#define SND_DJM_CAP_FXSEND`
  - `SND_DJM_CAP_CH1PFADER` (macro, line 3729) `#define SND_DJM_CAP_CH1PFADER`
  - `SND_DJM_CAP_CH2PFADER` (macro, line 3730) `#define SND_DJM_CAP_CH2PFADER`
  - `SND_DJM_CAP_CH3PFADER` (macro, line 3731) `#define SND_DJM_CAP_CH3PFADER`
  - `SND_DJM_CAP_CH4PFADER` (macro, line 3732) `#define SND_DJM_CAP_CH4PFADER`
  - `SND_DJM_CAP_EXT1SEND` (macro, line 3733) `#define SND_DJM_CAP_EXT1SEND`
  - `SND_DJM_CAP_EXT2SEND` (macro, line 3734) `#define SND_DJM_CAP_EXT2SEND`
  - `SND_DJM_CAP_CH1PREFADER` (macro, line 3735) `#define SND_DJM_CAP_CH1PREFADER`
  - `SND_DJM_CAP_CH2PREFADER` (macro, line 3736) `#define SND_DJM_CAP_CH2PREFADER`
  - `SND_DJM_CAP_CH3PREFADER` (macro, line 3737) `#define SND_DJM_CAP_CH3PREFADER`
  - `SND_DJM_CAP_CH4PREFADER` (macro, line 3738) `#define SND_DJM_CAP_CH4PREFADER`
  - `SND_DJM_PB_CH1` (macro, line 3741) `#define SND_DJM_PB_CH1`
  - `SND_DJM_PB_CH2` (macro, line 3742) `#define SND_DJM_PB_CH2`
  - `SND_DJM_PB_AUX` (macro, line 3743) `#define SND_DJM_PB_AUX`
  - `SND_DJM_WINDEX_CAP` (macro, line 3745) `#define SND_DJM_WINDEX_CAP`
  - `SND_DJM_WINDEX_CAPLVL` (macro, line 3746) `#define SND_DJM_WINDEX_CAPLVL`
  - `SND_DJM_WINDEX_PB` (macro, line 3747) `#define SND_DJM_WINDEX_PB`
  - `SND_DJM_VALUE_MASK` (macro, line 3750) `#define SND_DJM_VALUE_MASK`
  - `SND_DJM_GROUP_MASK` (macro, line 3751) `#define SND_DJM_GROUP_MASK`
  - `SND_DJM_DEVICE_MASK` (macro, line 3752) `#define SND_DJM_DEVICE_MASK`
  - `SND_DJM_GROUP_SHIFT` (macro, line 3753) `#define SND_DJM_GROUP_SHIFT`
  - `SND_DJM_DEVICE_SHIFT` (macro, line 3754) `#define SND_DJM_DEVICE_SHIFT`
  - `SND_DJM_250MK2_IDX` (macro, line 3758) `#define SND_DJM_250MK2_IDX`
  - `SND_DJM_750_IDX` (macro, line 3759) `#define SND_DJM_750_IDX`
  - `SND_DJM_850_IDX` (macro, line 3760) `#define SND_DJM_850_IDX`
  - `SND_DJM_900NXS2_IDX` (macro, line 3761) `#define SND_DJM_900NXS2_IDX`
  - `SND_DJM_750MK2_IDX` (macro, line 3762) `#define SND_DJM_750MK2_IDX`
  - `SND_DJM_450_IDX` (macro, line 3763) `#define SND_DJM_450_IDX`
  - `SND_DJM_A9_IDX` (macro, line 3764) `#define SND_DJM_A9_IDX`
  - `SND_DJM_V10_IDX` (macro, line 3765) `#define SND_DJM_V10_IDX`
  - `SND_DJM_CTL` (macro, line 3767) `#define SND_DJM_CTL(_name, suffix, _default_value, _windex)`
  - `SND_DJM_DEVICE` (macro, line 3774) `#define SND_DJM_DEVICE(suffix)`
- Depends on: `audiobox_vsl.h`

## legacy/test.sh
- Layer: testing
- Doc: ==================================================================== VSL-DSP: Captura COMPLETA de tráfico USB del AudioB
- Language: sh

## legacy/test_connection.c
- Layer: testing
- Doc: test_connection.c
- Language: c
- Symbols:
  - `main` (function, line 7) `int main()`
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_dsp_transport.h`

## legacy/vsl_config.h
- Layer: infrastructure
- Doc: vsl_config.h (VERSION CORREGIDA)    ======================================================= BLOQUEADORES CRÍTICOS (Hardw
- Language: h
- Symbols:
  - `VSL_CONFIG_H` (macro, line 4) `#define VSL_CONFIG_H`
  - `VSL_VENDOR_ID` (macro, line 11) `#define VSL_VENDOR_ID`
  - `VSL_PRODUCT_ID` (macro, line 12) `#define VSL_PRODUCT_ID`
  - `VSL_REPORT_ID` (macro, line 13) `#define VSL_REPORT_ID`
  - `VSL_SCALE_FACTOR` (macro, line 20) `#define VSL_SCALE_FACTOR`
  - `VSL_MAX_ENCODED_INT` (macro, line 23) `#define VSL_MAX_ENCODED_INT`
  - `VSL_PACKET_SIZE` (macro, line 25) `#define VSL_PACKET_SIZE`
  - `VSL_PAYLOAD_SIZE` (macro, line 26) `#define VSL_PAYLOAD_SIZE`
- Imported by: `legacy/test_connection.c`, `legacy/vsl_core.py`, `legacy/vsl_core.py`, `legacy/vsl_dsp_transport.c`, `legacy/vsl_dsp_transport.h`, `legacy/vsl_hid_io.py`, `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`, `legacy/vsl_transport.py`, `legacy/vsl_transport.py`

## legacy/vsl_config.py
- Layer: infrastructure
- Doc: VSL-DSP Configuration Module Contiene todas las constantes y configuraciones del protocolo.  ⚠️ BLOQUEADORES CRÍTICOS (P
- Language: py
- Symbols:
  - `VSLParameter` (class, line 40) `class VSLParameter(NamedTuple)`
  - `validate_configuration` (method, line 92) `def validate_configuration()`
  - `print_configuration_status` (method, line 116) `def print_configuration_status()`

## legacy/vsl_core.py
- Layer: utility
- Doc: VSL-DSP Core Logic Module Implementa las funciones matemáticas de encoding/decoding. Traducción 1:1 del código C desensa
- Language: py
- Symbols:
  - `vsl_encode_gain` (function, line 16) `def vsl_encode_gain(linear_value, param)`
  - `vsl_map_frequency` (function, line 58) `def vsl_map_frequency(linear_position, param)`
  - `vsl_final_encode_to_int` (function, line 94) `def vsl_final_encode_to_int(encoded_float, param)`
  - `vsl_decode_frequency` (function, line 127) `def vsl_decode_frequency(freq_hz_value, param)`
  - `validate_parameter` (function, line 170) `def validate_parameter(param)`
- Depends on: `legacy/vsl_config.h`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

## legacy/vsl_dsp_logic.c
- Layer: business_logic
- Doc: Declaración de la nueva función de envío
- Language: c
- Symbols:
  - `VSL_Encode_Gain` (function, line 11) `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)`
  - `VSL_Map_Frequency` (function, line 29) `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)`
  - `VSL_Final_Encode_To_Int` (function, line 58) `uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)`
  - `VSL_Decode_Frequency` (function, line 78) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)`
  - `VSL_Build_And_Send_Packet` (function, line 4) `void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float);`
- Depends on: `legacy/vsl_dsp_logic.h`

## legacy/vsl_dsp_logic.h
- Layer: business_logic
- Doc: Constante para la conversión de logaritmo natural (ln) a logaritmo base 2 (log2) 1 / ln(2) ≈ 1.442695  Estructura que al
- Language: h
- Symbols:
  - `VSL_Parameter` (struct, line 13)
  - `VSL_Encode_Gain` (function, line 42) `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);`
  - `VSL_Map_Frequency` (function, line 50) `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);`
  - `VSL_Final_Encode_To_Int` (function, line 60) `uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param);`
  - `VSL_Decode_Frequency` (function, line 73) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);`
  - `VSL_DSP_LOGIC_H` (macro, line 2) `#define VSL_DSP_LOGIC_H`
  - `VSL_INV_LN2` (macro, line 10) `#define VSL_INV_LN2`
- Imported by: `legacy/main.c`, `legacy/vsl_dsp_logic.c`

## legacy/vsl_dsp_transport.c
- Layer: utility
- Doc: vsl_dsp_transport.c (Añadir la Plantilla B completa aquí)   Handle de Singleton (Regla #5: Diseño Escalable)
- Language: c
- Symbols:
  - `VSL_Init_Device` (function, line 23) `int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)`
  - `VSL_Close_Device` (function, line 70) `void VSL_Close_Device(void)`
  - `VSL_Get_Device_Handle` (function, line 79) `hid_device* VSL_Get_Device_Handle(void)`
  - `FUN_Send_Packet` (function, line 97) `void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length)`
  - `VSL_Build_And_Send_Packet` (function, line 140) `void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float)`
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_dsp_transport.h`

## legacy/vsl_dsp_transport.h
- Layer: utility
- Doc: vsl_dsp_transport.h (CORREGIDO)    Estructura de Paquete: Sin 'header' (lo quitaste en la estructura typedef)
- Language: h
- Symbols:
  - `VSL_DSP_Packet` (struct, line 12)
  - `VSL_Init_Device` (function, line 19) `int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id);`
  - `VSL_Close_Device` (function, line 20) `void VSL_Close_Device(void);`
  - `VSL_Get_Device_Handle` (function, line 21) `hid_device* VSL_Get_Device_Handle(void);`
  - `FUN_Send_Packet` (function, line 24) `void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length);`
  - `VSL_Build_And_Send_Packet` (function, line 25) `void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float);`
  - `VSL_DSP_TRANSPORT_H` (macro, line 4) `#define VSL_DSP_TRANSPORT_H`
- Depends on: `legacy/vsl_config.h`
- Imported by: `legacy/main.c`, `legacy/test_connection.c`, `legacy/vsl_dsp_transport.c`

## legacy/vsl_hid_io.py
- Layer: utility
- Doc: VSL-DSP HID I/O Module (OPCIONAL) Comunicación real con hardware via hidapi. Requiere: pip install hidapi  ⚠️ Este módul
- Language: py
- Symbols:
  - `VSLDevice` (class, line 31) `class VSLDevice`
  - `enumerate_vsl_devices` (method, line 149) `def enumerate_vsl_devices()`
  - `__new__` (method, line 39) `def __new__(cls)`
  - `__init__` (method, line 45) `def __init__(self)`
  - `open` (method, line 59) `def open(self)`
  - `close` (method, line 90) `def close(self)`
  - `send_packet` (method, line 101) `def send_packet(self, packet)`
  - `__enter__` (method, line 139) `def __enter__(self)`
  - `__exit__` (method, line 144) `def __exit__(self, exc_type, exc_val, exc_tb)`
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

## legacy/vsl_poc_main.py
- Layer: utility
- Doc: VSL-DSP Proof of Concept - Main Program Programa principal de pruebas y validación.
- Language: py
- Symbols:
  - `test_gain_encoding` (function, line 43) `def test_gain_encoding()`
  - `test_frequency_mapping` (function, line 72) `def test_frequency_mapping()`
  - `test_packet_construction` (function, line 92) `def test_packet_construction()`
  - `test_edge_cases` (function, line 150) `def test_edge_cases()`
  - `run_full_workflow` (function, line 197) `def run_full_workflow()`
  - `print_summary` (function, line 229) `def print_summary()`
  - `main` (function, line 266) `def main()`
- Depends on: `legacy/vsl_config.h`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

## legacy/vsl_protocol_analyzer.py
- Layer: utility
- Doc: PASO 1: (Fuera de este entorno) Capturar tráfico USB con Wireshark/usbmon Guardar como: audiobox_full_sweep.pcap  PASO 2
- Language: py
- Symbols:
  - `VSLParameter` (class, line 28) `class VSLParameter`
  - `reverse_map_gain` (method, line 67) `def reverse_map_gain(encoded_value, param)`
  - `reverse_map_frequency` (method, line 95) `def reverse_map_frequency(encoded_value, param)`
  - `get_decoded_value` (method, line 115) `def get_decoded_value(encoded_value, param_id)`
  - `decode_vsl_packet` (method, line 140) `def decode_vsl_packet(data)`
  - `analyze_pcap` (method, line 173) `def analyze_pcap(pcap_file)`
  - `__init__` (method, line 30) `def __init__(self, dsp_id, name, type_unit, min_map, max_map, coeff_A, coeff_C1, log_factor)`

## legacy/vsl_transport.py
- Layer: utility
- Doc: VSL-DSP Transport Module Construcción y validación de paquetes HID.
- Language: py
- Symbols:
  - `VSLPacket` (class, line 15) `class VSLPacket`
  - `build_packet_safe` (method, line 141) `def build_packet_safe(param, encoded_value)`
  - `__init__` (method, line 21) `def __init__(self, param_id, encoded_value, report_id)`
  - `_build_buffer` (method, line 58) `def _build_buffer(self)`
  - `buffer` (method, line 89) `def buffer(self)`
  - `hex_dump` (method, line 93) `def hex_dump(self, num_bytes)`
  - `validate` (method, line 106) `def validate(self)`
  - `__repr__` (method, line 133) `def __repr__(self)`
- Depends on: `legacy/vsl_config.h`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`
