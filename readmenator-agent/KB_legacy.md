# Subsystem: legacy

## legacy/app.py
- Layer: utility
- Doc: _*_ coding: utf8 _*_
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
- Doc: include <stdio.h> include "vsl_dsp_logic.h" include "vsl_dsp_transport.h"
- Language: c
- Symbols:
  - `main` (function, line 4) `int main()`

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
  - `snd_create_std_mono_ctl_offset` (function, line 59) `static int snd_create_std_mono_ctl_offset(struct usb_mixer_interface *mixer,
					  unsigned int ...`
  - `snd_create_std_mono_ctl` (function, line 112) `static int snd_create_std_mono_ctl(struct usb_mixer_interface *mixer,
				   unsigned int unitid,...`
  - `snd_create_std_mono_table` (function, line 129) `static int snd_create_std_mono_table(struct usb_mixer_interface *mixer,
				     const struct std...`
  - `add_single_ctl_with_resume` (function, line 145) `static int add_single_ctl_with_resume(struct usb_mixer_interface *mixer,
				      int id,
				  ...`
  - `snd_usb_soundblaster_remote_complete` (function, line 199) `static void snd_usb_soundblaster_remote_complete(struct urb *urb)`
  - `snd_usb_sbrc_hwdep_read` (function, line 219) `static long snd_usb_sbrc_hwdep_read(struct snd_hwdep *hw, char __user *buf,
				    long count, l...`
  - `snd_usb_sbrc_hwdep_poll` (function, line 239) `static __poll_t snd_usb_sbrc_hwdep_poll(struct snd_hwdep *hw, struct file *file,
					poll_table ...`
  - `snd_usb_soundblaster_remote_init` (function, line 248) `static int snd_usb_soundblaster_remote_init(struct usb_mixer_interface *mixer)`
  - `snd_audigy2nx_led_get` (function, line 298) `static int snd_audigy2nx_led_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)`
  - `snd_audigy2nx_led_update` (function, line 304) `static int snd_audigy2nx_led_update(struct usb_mixer_interface *mixer,
				    int value, int index)`
  - `snd_audigy2nx_led_put` (function, line 333) `static int snd_audigy2nx_led_put(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_value *u...`
  - `snd_audigy2nx_led_resume` (function, line 352) `static int snd_audigy2nx_led_resume(struct usb_mixer_elem_list *list)`
  - `snd_audigy2nx_controls_create` (function, line 374) `static int snd_audigy2nx_controls_create(struct usb_mixer_interface *mixer)`
  - `snd_audigy2nx_proc_read` (function, line 406) `static void snd_audigy2nx_proc_read(struct snd_info_entry *entry,
				    struct snd_info_buffer ...`
  - `snd_emu0204_ch_switch_info` (function, line 457) `static int snd_emu0204_ch_switch_info(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_ele...`
  - `snd_emu0204_ch_switch_get` (function, line 464) `static int snd_emu0204_ch_switch_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
  - `snd_emu0204_ch_switch_update` (function, line 471) `static int snd_emu0204_ch_switch_update(struct usb_mixer_interface *mixer,
					int value)`
  - `snd_emu0204_ch_switch_put` (function, line 489) `static int snd_emu0204_ch_switch_put(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
  - `snd_emu0204_ch_switch_resume` (function, line 508) `static int snd_emu0204_ch_switch_resume(struct usb_mixer_elem_list *list)`
  - `snd_emu0204_controls_create` (function, line 523) `static int snd_emu0204_controls_create(struct usb_mixer_interface *mixer)`
  - `snd_dualsense_ih_event` (function, line 549) `static void snd_dualsense_ih_event(struct input_handle *handle,
				   unsigned int type, unsigne...`
  - `snd_dualsense_ih_match` (function, line 570) `static bool snd_dualsense_ih_match(struct input_handler *handler,
				   struct input_dev *dev)`
  - `snd_dualsense_ih_connect` (function, line 617) `static int snd_dualsense_ih_connect(struct input_handler *handler,
				    struct input_dev *dev,...`
  - `snd_dualsense_ih_disconnect` (function, line 649) `static void snd_dualsense_ih_disconnect(struct input_handle *handle)`
  - `snd_dualsense_ih_start` (function, line 656) `static void snd_dualsense_ih_start(struct input_handle *handle)`
  - `snd_dualsense_jack_get` (function, line 679) `static int snd_dualsense_jack_get(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...`
  - `snd_dualsense_resume_jack` (function, line 696) `static int snd_dualsense_resume_jack(struct usb_mixer_elem_list *list)`
  - `snd_dualsense_mixer_elem_free` (function, line 703) `static void snd_dualsense_mixer_elem_free(struct snd_kcontrol *kctl)`
  - `snd_dualsense_jack_create` (function, line 713) `static int snd_dualsense_jack_create(struct usb_mixer_interface *mixer,
				     const char *name...`
  - `snd_dualsense_controls_create` (function, line 777) `static int snd_dualsense_controls_create(struct usb_mixer_interface *mixer)`
  - `snd_xonar_u1_switch_get` (function, line 791) `static int snd_xonar_u1_switch_get(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...`
  - `snd_xonar_u1_switch_update` (function, line 798) `static int snd_xonar_u1_switch_update(struct usb_mixer_interface *mixer,
				      unsigned char ...`
  - `snd_xonar_u1_switch_put` (function, line 812) `static int snd_xonar_u1_switch_put(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...`
  - `snd_xonar_u1_switch_resume` (function, line 832) `static int snd_xonar_u1_switch_resume(struct usb_mixer_elem_list *list)`
  - `snd_xonar_u1_controls_create` (function, line 847) `static int snd_xonar_u1_controls_create(struct usb_mixer_interface *mixer)`
  - `snd_mbox1_is_spdif_synced` (function, line 856) `static int snd_mbox1_is_spdif_synced(struct snd_usb_audio *chip)`
  - `snd_mbox1_set_clk_source` (function, line 876) `static int snd_mbox1_set_clk_source(struct snd_usb_audio *chip, int rate_or_zero)`
  - `snd_mbox1_is_spdif_input` (function, line 894) `static int snd_mbox1_is_spdif_input(struct snd_usb_audio *chip)`
  - `snd_mbox1_set_input_source` (function, line 914) `static int snd_mbox1_set_input_source(struct snd_usb_audio *chip, int is_spdif)`
  - `snd_mbox1_clk_switch_get` (function, line 933) `static int snd_mbox1_clk_switch_get(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...`
  - `snd_mbox1_clk_switch_update` (function, line 953) `static int snd_mbox1_clk_switch_update(struct usb_mixer_interface *mixer, int is_spdif_sync)`
  - `snd_mbox1_clk_switch_put` (function, line 978) `static int snd_mbox1_clk_switch_put(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...`
  - `snd_mbox1_clk_switch_info` (function, line 996) `static int snd_mbox1_clk_switch_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
  - `snd_mbox1_clk_switch_resume` (function, line 1007) `static int snd_mbox1_clk_switch_resume(struct usb_mixer_elem_list *list)`
  - `snd_mbox1_src_switch_get` (function, line 1014) `static int snd_mbox1_src_switch_get(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...`
  - `snd_mbox1_src_switch_update` (function, line 1021) `static int snd_mbox1_src_switch_update(struct usb_mixer_interface *mixer, int is_spdif_input)`
  - `snd_mbox1_src_switch_put` (function, line 1045) `static int snd_mbox1_src_switch_put(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...`
  - `snd_mbox1_src_switch_info` (function, line 1063) `static int snd_mbox1_src_switch_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
  - `snd_mbox1_src_switch_resume` (function, line 1074) `static int snd_mbox1_src_switch_resume(struct usb_mixer_elem_list *list)`
  - `snd_mbox1_controls_create` (function, line 1101) `static int snd_mbox1_controls_create(struct usb_mixer_interface *mixer)`
  - `snd_ni_control_init_val` (function, line 1120) `static int snd_ni_control_init_val(struct usb_mixer_interface *mixer,
				   struct snd_kcontrol ...`
  - `snd_nativeinstruments_control_get` (function, line 1142) `static int snd_nativeinstruments_control_get(struct snd_kcontrol *kcontrol,
					     struct snd_...`
  - `snd_ni_update_cur_val` (function, line 1149) `static int snd_ni_update_cur_val(struct usb_mixer_elem_list *list)`
  - `snd_nativeinstruments_control_put` (function, line 1163) `static int snd_nativeinstruments_control_put(struct snd_kcontrol *kcontrol,
					     struct snd_...`
  - `snd_nativeinstruments_create_mixer` (function, line 1234) `static int snd_nativeinstruments_create_mixer(struct usb_mixer_interface *mixer,
					      const...`
  - `snd_ftu_eff_switch_info` (function, line 1267) `static int snd_ftu_eff_switch_info(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_info...`
  - `snd_ftu_eff_switch_init` (function, line 1277) `static int snd_ftu_eff_switch_init(struct usb_mixer_interface *mixer,
				   struct snd_kcontrol ...`
  - `snd_ftu_eff_switch_get` (function, line 1300) `static int snd_ftu_eff_switch_get(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...`
  - `snd_ftu_eff_switch_update` (function, line 1307) `static int snd_ftu_eff_switch_update(struct usb_mixer_elem_list *list)`
  - `snd_ftu_eff_switch_put` (function, line 1328) `static int snd_ftu_eff_switch_put(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...`
  - `snd_ftu_create_effect_switch` (function, line 1346) `static int snd_ftu_create_effect_switch(struct usb_mixer_interface *mixer,
					int validx, int b...`
  - `snd_ftu_create_volume_ctls` (function, line 1373) `static int snd_ftu_create_volume_ctls(struct usb_mixer_interface *mixer)`
  - `snd_ftu_create_effect_volume_ctl` (function, line 1412) `static int snd_ftu_create_effect_volume_ctl(struct usb_mixer_interface *mixer)`
  - `snd_ftu_create_effect_duration_ctl` (function, line 1425) `static int snd_ftu_create_effect_duration_ctl(struct usb_mixer_interface *mixer)`
  - `snd_ftu_create_effect_feedback_ctl` (function, line 1438) `static int snd_ftu_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)`
  - `snd_ftu_create_effect_return_ctls` (function, line 1449) `static int snd_ftu_create_effect_return_ctls(struct usb_mixer_interface *mixer)`
  - `snd_ftu_create_effect_send_ctls` (function, line 1473) `static int snd_ftu_create_effect_send_ctls(struct usb_mixer_interface *mixer)`
  - `snd_ftu_create_mixer` (function, line 1506) `static int snd_ftu_create_mixer(struct usb_mixer_interface *mixer)`
  - `snd_emuusb_set_samplerate` (function, line 1541) `void snd_emuusb_set_samplerate(struct snd_usb_audio *chip,
			       unsigned char samplerate_id)`
  - `list_for_each_entry` (function, line 1548) `list_for_each_entry(mixer, &chip->mixer_list, list)`
  - `snd_c400_create_vol_ctls` (function, line 1563) `static int snd_c400_create_vol_ctls(struct usb_mixer_interface *mixer)`
  - `snd_c400_create_effect_volume_ctl` (function, line 1612) `static int snd_c400_create_effect_volume_ctl(struct usb_mixer_interface *mixer)`
  - `snd_c400_create_effect_duration_ctl` (function, line 1625) `static int snd_c400_create_effect_duration_ctl(struct usb_mixer_interface *mixer)`
  - `snd_c400_create_effect_feedback_ctl` (function, line 1638) `static int snd_c400_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)`
  - `snd_c400_create_effect_vol_ctls` (function, line 1649) `static int snd_c400_create_effect_vol_ctls(struct usb_mixer_interface *mixer)`
  - `snd_c400_create_effect_ret_vol_ctls` (function, line 1694) `static int snd_c400_create_effect_ret_vol_ctls(struct usb_mixer_interface *mixer)`
  - `snd_c400_create_mixer` (function, line 1736) `static int snd_c400_create_mixer(struct usb_mixer_interface *mixer)`
  - `snd_microii_spdif_info` (function, line 1869) `static int snd_microii_spdif_info(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_info *...`
  - `snd_microii_spdif_default_get` (function, line 1876) `static int snd_microii_spdif_default_get(struct snd_kcontrol *kcontrol,
					 struct snd_ctl_elem...`
  - `snd_microii_spdif_default_update` (function, line 1923) `static int snd_microii_spdif_default_update(struct usb_mixer_elem_list *list)`
  - `snd_microii_spdif_default_put` (function, line 1959) `static int snd_microii_spdif_default_put(struct snd_kcontrol *kcontrol,
					 struct snd_ctl_elem...`
  - `snd_microii_spdif_mask_get` (function, line 1987) `static int snd_microii_spdif_mask_get(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_ele...`
  - `snd_microii_spdif_switch_get` (function, line 1998) `static int snd_microii_spdif_switch_get(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_v...`
  - `snd_microii_spdif_switch_update` (function, line 2006) `static int snd_microii_spdif_switch_update(struct usb_mixer_elem_list *list)`
  - `snd_microii_spdif_switch_put` (function, line 2025) `static int snd_microii_spdif_switch_put(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_v...`
  - `snd_microii_controls_create` (function, line 2067) `static int snd_microii_controls_create(struct usb_mixer_interface *mixer)`
  - `snd_soundblaster_e1_switch_get` (function, line 2090) `static int snd_soundblaster_e1_switch_get(struct snd_kcontrol *kcontrol,
					  struct snd_ctl_el...`
  - `snd_soundblaster_e1_switch_update` (function, line 2097) `static int snd_soundblaster_e1_switch_update(struct usb_mixer_interface *mixer,
					     unsigne...`
  - `snd_soundblaster_e1_switch_put` (function, line 2115) `static int snd_soundblaster_e1_switch_put(struct snd_kcontrol *kcontrol,
					  struct snd_ctl_el...`
  - `snd_soundblaster_e1_switch_resume` (function, line 2129) `static int snd_soundblaster_e1_switch_resume(struct usb_mixer_elem_list *list)`
  - `snd_soundblaster_e1_switch_info` (function, line 2135) `static int snd_soundblaster_e1_switch_info(struct snd_kcontrol *kcontrol,
					   struct snd_ctl_...`
  - `snd_soundblaster_e1_switch_create` (function, line 2154) `static int snd_soundblaster_e1_switch_create(struct usb_mixer_interface *mixer)`
  - `realtek_hda_set` (function, line 2191) `static int realtek_hda_set(struct snd_usb_audio *chip, u32 cmd)`
  - `realtek_hda_get` (function, line 2201) `static int realtek_hda_get(struct snd_usb_audio *chip, u32 cmd, u32 *value)`
  - `realtek_ctl_connector_get` (function, line 2222) `static int realtek_ctl_connector_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
  - `realtek_resume_jack` (function, line 2272) `static int realtek_resume_jack(struct usb_mixer_elem_list *list)`
  - `realtek_add_jack` (function, line 2279) `static int realtek_add_jack(struct usb_mixer_interface *mixer,
			    char *name, u32 val)`
  - `dell_dock_mixer_create` (function, line 2306) `static int dell_dock_mixer_create(struct usb_mixer_interface *mixer)`
  - `dell_dock_init_vol` (function, line 2338) `static void dell_dock_init_vol(struct usb_mixer_interface *mixer, int ch, int id)`
  - `dell_dock_mixer_init` (function, line 2350) `static int dell_dock_mixer_init(struct usb_mixer_interface *mixer)`
  - `snd_rme_read_value` (function, line 2418) `static int snd_rme_read_value(struct snd_usb_audio *chip,
			      unsigned int item,
			      u3...`
  - `snd_rme_get_status1` (function, line 2437) `static int snd_rme_get_status1(struct snd_kcontrol *kcontrol,
			       u32 *status1)`
  - `snd_rme_rate_get` (function, line 2449) `static int snd_rme_rate_get(struct snd_kcontrol *kcontrol,
			    struct snd_ctl_elem_value *ucon...`
  - `snd_rme_sync_state_get` (function, line 2483) `static int snd_rme_sync_state_get(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_value ...`
  - `snd_rme_spdif_if_get` (function, line 2513) `static int snd_rme_spdif_if_get(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *uco...`
  - `snd_rme_spdif_format_get` (function, line 2526) `static int snd_rme_spdif_format_get(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_va...`
  - `snd_rme_sync_source_get` (function, line 2539) `static int snd_rme_sync_source_get(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...`
  - `snd_rme_current_freq_get` (function, line 2552) `static int snd_rme_current_freq_get(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_va...`
  - `snd_rme_rate_info` (function, line 2578) `static int snd_rme_rate_info(struct snd_kcontrol *kcontrol,
			     struct snd_ctl_elem_info *uinfo)`
  - `snd_rme_sync_state_info` (function, line 2598) `static int snd_rme_sync_state_info(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_info...`
  - `snd_rme_spdif_if_info` (function, line 2609) `static int snd_rme_spdif_if_info(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_info *ui...`
  - `snd_rme_spdif_format_info` (function, line 2620) `static int snd_rme_spdif_format_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
  - `snd_rme_sync_source_info` (function, line 2631) `static int snd_rme_sync_source_info(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_in...`
  - `snd_rme_controls_create` (function, line 2713) `static int snd_rme_controls_create(struct usb_mixer_interface *mixer)`
  - `snd_bbfpro_ctl_update` (function, line 2779) `static int snd_bbfpro_ctl_update(struct usb_mixer_interface *mixer, u8 reg,
				 u8 index, u8 value)`
  - `snd_bbfpro_ctl_get` (function, line 2810) `static int snd_bbfpro_ctl_get(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...`
  - `snd_bbfpro_ctl_info` (function, line 2833) `static int snd_bbfpro_ctl_info(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_info ...`
  - `snd_bbfpro_ctl_put` (function, line 2867) `static int snd_bbfpro_ctl_put(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...`
  - `snd_bbfpro_ctl_resume` (function, line 2906) `static int snd_bbfpro_ctl_resume(struct usb_mixer_elem_list *list)`
  - `snd_bbfpro_gain_update` (function, line 2919) `static int snd_bbfpro_gain_update(struct usb_mixer_interface *mixer,
				  u8 channel, u8 gain)`
  - `snd_bbfpro_gain_get` (function, line 2943) `static int snd_bbfpro_gain_get(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_value...`
  - `snd_bbfpro_gain_info` (function, line 2952) `static int snd_bbfpro_gain_info(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_info *uinfo)`
  - `snd_bbfpro_gain_put` (function, line 2973) `static int snd_bbfpro_gain_put(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_value...`
  - `snd_bbfpro_gain_resume` (function, line 3010) `static int snd_bbfpro_gain_resume(struct usb_mixer_elem_list *list)`
  - `snd_bbfpro_vol_update` (function, line 3023) `static int snd_bbfpro_vol_update(struct usb_mixer_interface *mixer, u16 index,
				 u32 value)`
  - `snd_bbfpro_vol_get` (function, line 3049) `static int snd_bbfpro_vol_get(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...`
  - `snd_bbfpro_vol_info` (function, line 3057) `static int snd_bbfpro_vol_info(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_info ...`
  - `snd_bbfpro_vol_put` (function, line 3067) `static int snd_bbfpro_vol_put(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...`
  - `snd_bbfpro_vol_resume` (function, line 3095) `static int snd_bbfpro_vol_resume(struct usb_mixer_elem_list *list)`
  - `snd_bbfpro_ctl_add` (function, line 3132) `static int snd_bbfpro_ctl_add(struct usb_mixer_interface *mixer, u8 reg,
			      u8 index, char ...`
  - `snd_bbfpro_gain_add` (function, line 3146) `static int snd_bbfpro_gain_add(struct usb_mixer_interface *mixer, u8 channel,
			       char *name)`
  - `snd_bbfpro_vol_add` (function, line 3158) `static int snd_bbfpro_vol_add(struct usb_mixer_interface *mixer, u16 index,
			      char *name)`
  - `snd_bbfpro_controls_create` (function, line 3170) `static int snd_bbfpro_controls_create(struct usb_mixer_interface *mixer)`
  - `snd_rme_digiface_write_reg` (function, line 3318) `static int snd_rme_digiface_write_reg(struct snd_kcontrol *kcontrol, int item, u16 mask, u16 val)`
  - `snd_rme_digiface_read_status` (function, line 3336) `static int snd_rme_digiface_read_status(struct snd_kcontrol *kcontrol, u32 status[4])`
  - `snd_rme_digiface_get_status_val` (function, line 3360) `static int snd_rme_digiface_get_status_val(struct snd_kcontrol *kcontrol)`
  - `snd_rme_digiface_rate_get` (function, line 3398) `static int snd_rme_digiface_rate_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
  - `snd_rme_digiface_enum_get` (function, line 3412) `static int snd_rme_digiface_enum_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
  - `snd_rme_digiface_enum_put` (function, line 3424) `static int snd_rme_digiface_enum_put(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
  - `snd_rme_digiface_current_sync_get` (function, line 3438) `static int snd_rme_digiface_current_sync_get(struct snd_kcontrol *kcontrol,
					     struct snd_...`
  - `snd_rme_digiface_sync_state_get` (function, line 3450) `static int snd_rme_digiface_sync_state_get(struct snd_kcontrol *kcontrol,
					   struct snd_ctl_...`
  - `snd_rme_digiface_format_info` (function, line 3473) `static int snd_rme_digiface_format_info(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_i...`
  - `snd_rme_digiface_sync_source_info` (function, line 3484) `static int snd_rme_digiface_sync_source_info(struct snd_kcontrol *kcontrol,
					     struct snd_...`
  - `snd_rme_digiface_rate_info` (function, line 3495) `static int snd_rme_digiface_rate_info(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_ele...`
  - `snd_rme_digiface_controls_create` (function, line 3684) `static int snd_rme_digiface_controls_create(struct usb_mixer_interface *mixer)`
  - `snd_djm_get_label_caplevel_common` (function, line 3791) `static const char *snd_djm_get_label_caplevel_common(u16 wvalue)`
  - `snd_djm_get_label_caplevel_high` (function, line 3804) `static const char *snd_djm_get_label_caplevel_high(u16 wvalue)`
  - `snd_djm_get_label_cap_common` (function, line 3816) `static const char *snd_djm_get_label_cap_common(u16 wvalue)`
  - `snd_djm_get_label_cap_850` (function, line 3849) `static const char *snd_djm_get_label_cap_850(u16 wvalue)`
  - `snd_djm_get_label_caplevel` (function, line 3857) `static const char *snd_djm_get_label_caplevel(u8 device_idx, u16 wvalue)`
  - `snd_djm_get_label_cap` (function, line 3866) `static const char *snd_djm_get_label_cap(u8 device_idx, u16 wvalue)`
  - `snd_djm_get_label_pb` (function, line 3874) `static const char *snd_djm_get_label_pb(u16 wvalue)`
  - `snd_djm_get_label` (function, line 3884) `static const char *snd_djm_get_label(u8 device_idx, u16 wvalue, u16 windex)`
  - `snd_djm_controls_info` (function, line 4116) `static int snd_djm_controls_info(struct snd_kcontrol *kctl,
				 struct snd_ctl_elem_info *info)`
  - `snd_djm_controls_update` (function, line 4148) `static int snd_djm_controls_update(struct usb_mixer_interface *mixer,
				   u8 device_idx, u8 gr...`
  - `snd_djm_controls_get` (function, line 4169) `static int snd_djm_controls_get(struct snd_kcontrol *kctl,
				struct snd_ctl_elem_value *elem)`
  - `snd_djm_controls_put` (function, line 4176) `static int snd_djm_controls_put(struct snd_kcontrol *kctl, struct snd_ctl_elem_value *elem)`
  - `snd_djm_controls_resume` (function, line 4193) `static int snd_djm_controls_resume(struct usb_mixer_elem_list *list)`
  - `snd_djm_controls_create` (function, line 4203) `static int snd_djm_controls_create(struct usb_mixer_interface *mixer,
				   const u8 device_idx)`
  - `snd_usb_mixer_apply_create_quirk` (function, line 4238) `int snd_usb_mixer_apply_create_quirk(struct usb_mixer_interface *mixer)`
  - `snd_usb_mixer_resume_quirk` (function, line 4420) `void snd_usb_mixer_resume_quirk(struct usb_mixer_interface *mixer)`
  - `snd_usb_mixer_rc_memory_change` (function, line 4429) `void snd_usb_mixer_rc_memory_change(struct usb_mixer_interface *mixer,
				    int unitid)`
  - `snd_dragonfly_quirk_db_scale` (function, line 4457) `static void snd_dragonfly_quirk_db_scale(struct usb_mixer_interface *mixer,
					 struct usb_mixe...`
  - `snd_fix_plt_name` (function, line 4509) `static void snd_fix_plt_name(struct snd_usb_audio *chip,
			     struct snd_ctl_elem_id *id)`
  - `snd_usb_mixer_fu_apply_quirk` (function, line 4538) `void snd_usb_mixer_fu_apply_quirk(struct usb_mixer_interface *mixer,
				  struct usb_mixer_elem_...`
  - `snd_audigy2nx_led_info` (macro, line 296)
  - `SND_DUALSENSE_JACK_OUT_TERM_ID` (macro, line 539)
  - `SND_DUALSENSE_JACK_IN_TERM_ID` (macro, line 541)
  - `_MAKE_NI_CONTROL` (macro, line 1118)
  - `HDA_VERB_CMD` (macro, line 2171)
  - `REALTEK_HDA_VALUE` (macro, line 2173)
  - `REALTEK_HDA_SET` (macro, line 2175)
  - `REALTEK_MANUAL_MODE` (macro, line 2177)
  - `REALTEK_HDA_GET_OUT` (macro, line 2178)
  - `REALTEK_HDA_GET_IN` (macro, line 2179)
  - `REALTEK_AUDIO_FUNCTION_GROUP` (macro, line 2180)
  - `REALTEK_LINE1` (macro, line 2182)
  - `REALTEK_VENDOR_REGISTERS` (macro, line 2183)
  - `REALTEK_HP_OUT` (macro, line 2184)
  - `REALTEK_CBJ_CTRL2` (macro, line 2185)
  - `REALTEK_JACK_INTERRUPT_NODE` (macro, line 2187)
  - `REALTEK_MIC_FLAG` (macro, line 2189)
  - `SND_RME_GET_STATUS1` (macro, line 2362)
  - `SND_RME_GET_CURRENT_FREQ` (macro, line 2364)
  - `SND_RME_CLK_SYSTEM_SHIFT` (macro, line 2365)
  - `SND_RME_CLK_SYSTEM_MASK` (macro, line 2366)
  - `SND_RME_CLK_AES_SHIFT` (macro, line 2367)
  - `SND_RME_CLK_SPDIF_SHIFT` (macro, line 2368)
  - `SND_RME_CLK_AES_SPDIF_MASK` (macro, line 2369)
  - `SND_RME_CLK_SYNC_SHIFT` (macro, line 2370)
  - `SND_RME_CLK_SYNC_MASK` (macro, line 2371)
  - `SND_RME_CLK_FREQMUL_SHIFT` (macro, line 2372)
  - `SND_RME_CLK_FREQMUL_MASK` (macro, line 2373)
  - `SND_RME_CLK_SYSTEM` (macro, line 2374)
  - `SND_RME_CLK_AES` (macro, line 2376)
  - `SND_RME_CLK_SPDIF` (macro, line 2378)
  - `SND_RME_CLK_SYNC` (macro, line 2380)
  - `SND_RME_CLK_FREQMUL` (macro, line 2382)
  - `SND_RME_CLK_AES_LOCK` (macro, line 2384)
  - `SND_RME_CLK_AES_SYNC` (macro, line 2385)
  - `SND_RME_CLK_SPDIF_LOCK` (macro, line 2386)
  - `SND_RME_CLK_SPDIF_SYNC` (macro, line 2387)
  - `SND_RME_SPDIF_IF_SHIFT` (macro, line 2388)
  - `SND_RME_SPDIF_FORMAT_SHIFT` (macro, line 2389)
  - `SND_RME_BINARY_MASK` (macro, line 2390)
  - `SND_RME_SPDIF_IF` (macro, line 2391)
  - `SND_RME_SPDIF_FORMAT` (macro, line 2393)
  - `SND_RME_RATE_IDX_AES_SPDIF_NUM` (macro, line 2405)
  - `SND_BBFPRO_CTL_REG_MASK` (macro, line 2743)
  - `SND_BBFPRO_CTL_IDX_MASK` (macro, line 2745)
  - `SND_BBFPRO_CTL_IDX_SHIFT` (macro, line 2746)
  - `SND_BBFPRO_CTL_VAL_MASK` (macro, line 2747)
  - `SND_BBFPRO_CTL_VAL_SHIFT` (macro, line 2748)
  - `SND_BBFPRO_CTL_REG1_CLK_MASTER` (macro, line 2749)
  - `SND_BBFPRO_CTL_REG1_CLK_OPTICAL` (macro, line 2750)
  - `SND_BBFPRO_CTL_REG1_SPDIF_PRO` (macro, line 2751)
  - `SND_BBFPRO_CTL_REG1_SPDIF_EMPH` (macro, line 2752)
  - `SND_BBFPRO_CTL_REG1_SPDIF_OPTICAL` (macro, line 2753)
  - `SND_BBFPRO_CTL_REG2_48V_AN1` (macro, line 2754)
  - `SND_BBFPRO_CTL_REG2_48V_AN2` (macro, line 2755)
  - `SND_BBFPRO_CTL_REG2_SENS_IN3` (macro, line 2756)
  - `SND_BBFPRO_CTL_REG2_SENS_IN4` (macro, line 2757)
  - `SND_BBFPRO_CTL_REG2_PAD_AN1` (macro, line 2758)
  - `SND_BBFPRO_CTL_REG2_PAD_AN2` (macro, line 2759)
  - `SND_BBFPRO_MIXER_MAIN_OUT_CH_OFFSET` (macro, line 2760)
  - `SND_BBFPRO_MIXER_IDX_MASK` (macro, line 2762)
  - `SND_BBFPRO_MIXER_VAL_MASK` (macro, line 2763)
  - `SND_BBFPRO_MIXER_VAL_SHIFT` (macro, line 2764)
  - `SND_BBFPRO_MIXER_VAL_MIN` (macro, line 2765)
  - `SND_BBFPRO_MIXER_VAL_MAX` (macro, line 2766)
  - `SND_BBFPRO_GAIN_CHANNEL_MASK` (macro, line 2767)
  - `SND_BBFPRO_GAIN_CHANNEL_SHIFT` (macro, line 2769)
  - `SND_BBFPRO_GAIN_VAL_MASK` (macro, line 2770)
  - `SND_BBFPRO_GAIN_VAL_MIN` (macro, line 2771)
  - `SND_BBFPRO_GAIN_VAL_MIC_MAX` (macro, line 2772)
  - `SND_BBFPRO_GAIN_VAL_LINE_MAX` (macro, line 2773)
  - `SND_BBFPRO_USBREQ_CTL_REG1` (macro, line 2774)
  - `SND_BBFPRO_USBREQ_CTL_REG2` (macro, line 2776)
  - `SND_BBFPRO_USBREQ_GAIN` (macro, line 2777)
  - `SND_BBFPRO_USBREQ_MIXER` (macro, line 2778)
  - `RME_DIGIFACE_READ_STATUS` (macro, line 3297)
  - `RME_DIGIFACE_STATUS_REG0L` (macro, line 3299)
  - `RME_DIGIFACE_STATUS_REG0H` (macro, line 3300)
  - `RME_DIGIFACE_STATUS_REG1L` (macro, line 3301)
  - `RME_DIGIFACE_STATUS_REG1H` (macro, line 3302)
  - `RME_DIGIFACE_STATUS_REG2L` (macro, line 3303)
  - `RME_DIGIFACE_STATUS_REG2H` (macro, line 3304)
  - `RME_DIGIFACE_STATUS_REG3L` (macro, line 3305)
  - `RME_DIGIFACE_STATUS_REG3H` (macro, line 3306)
  - `RME_DIGIFACE_CTL_REG1` (macro, line 3307)
  - `RME_DIGIFACE_CTL_REG2` (macro, line 3309)
  - `RME_DIGIFACE_REGISTER` (macro, line 3312)
  - `RME_DIGIFACE_INVERT` (macro, line 3313)
  - `field_get` (macro, line 3316)
  - `field_prep` (macro, line 3317)
  - `SND_DJM_CAP_LINE` (macro, line 3715)
  - `SND_DJM_CAP_CDLINE` (macro, line 3716)
  - `SND_DJM_CAP_DIGITAL` (macro, line 3717)
  - `SND_DJM_CAP_PHONO` (macro, line 3718)
  - `SND_DJM_CAP_PREFADER` (macro, line 3719)
  - `SND_DJM_CAP_PFADER` (macro, line 3720)
  - `SND_DJM_CAP_XFADERA` (macro, line 3721)
  - `SND_DJM_CAP_XFADERB` (macro, line 3722)
  - `SND_DJM_CAP_MIC` (macro, line 3723)
  - `SND_DJM_CAP_AUX` (macro, line 3724)
  - `SND_DJM_CAP_RECOUT` (macro, line 3725)
  - `SND_DJM_CAP_RECOUT_NOMIC` (macro, line 3726)
  - `SND_DJM_CAP_NONE` (macro, line 3727)
  - `SND_DJM_CAP_FXSEND` (macro, line 3728)
  - `SND_DJM_CAP_CH1PFADER` (macro, line 3729)
  - `SND_DJM_CAP_CH2PFADER` (macro, line 3730)
  - `SND_DJM_CAP_CH3PFADER` (macro, line 3731)
  - `SND_DJM_CAP_CH4PFADER` (macro, line 3732)
  - `SND_DJM_CAP_EXT1SEND` (macro, line 3733)
  - `SND_DJM_CAP_EXT2SEND` (macro, line 3734)
  - `SND_DJM_CAP_CH1PREFADER` (macro, line 3735)
  - `SND_DJM_CAP_CH2PREFADER` (macro, line 3736)
  - `SND_DJM_CAP_CH3PREFADER` (macro, line 3737)
  - `SND_DJM_CAP_CH4PREFADER` (macro, line 3738)
  - `SND_DJM_PB_CH1` (macro, line 3741)
  - `SND_DJM_PB_CH2` (macro, line 3742)
  - `SND_DJM_PB_AUX` (macro, line 3743)
  - `SND_DJM_WINDEX_CAP` (macro, line 3744)
  - `SND_DJM_WINDEX_CAPLVL` (macro, line 3746)
  - `SND_DJM_WINDEX_PB` (macro, line 3747)
  - `SND_DJM_VALUE_MASK` (macro, line 3750)
  - `SND_DJM_GROUP_MASK` (macro, line 3751)
  - `SND_DJM_DEVICE_MASK` (macro, line 3752)
  - `SND_DJM_GROUP_SHIFT` (macro, line 3753)
  - `SND_DJM_DEVICE_SHIFT` (macro, line 3754)
  - `SND_DJM_250MK2_IDX` (macro, line 3758)
  - `SND_DJM_750_IDX` (macro, line 3759)
  - `SND_DJM_850_IDX` (macro, line 3760)
  - `SND_DJM_900NXS2_IDX` (macro, line 3761)
  - `SND_DJM_750MK2_IDX` (macro, line 3762)
  - `SND_DJM_450_IDX` (macro, line 3763)
  - `SND_DJM_A9_IDX` (macro, line 3764)
  - `SND_DJM_V10_IDX` (macro, line 3765)
  - `SND_DJM_CTL` (macro, line 3766)
  - `SND_DJM_DEVICE` (macro, line 3773)

## legacy/test.sh
- Layer: testing
- Doc: ==================================================================== VSL-DSP: Captura COMPLETA de tráfico USB del AudioB
- Language: sh

## legacy/test_connection.c
- Layer: testing
- Doc: test_connection.c  include <stdio.h> include "vsl_config.h" include "vsl_dsp_transport.h" // Asumiendo que esta es la pl
- Language: c
- Symbols:
  - `main` (function, line 6) `int main()`

## legacy/vsl_config.h
- Layer: infrastructure
- Doc: vsl_config.h (VERSION CORREGIDA)  ifndef VSL_CONFIG_H define VSL_CONFIG_H  include <stdint.h>  =========================
- Language: h
- Symbols:
  - `VSL_CONFIG_H` (macro, line 4)
  - `VSL_VENDOR_ID` (macro, line 11)
  - `VSL_PRODUCT_ID` (macro, line 12)
  - `VSL_REPORT_ID` (macro, line 13)
  - `VSL_SCALE_FACTOR` (macro, line 20)
  - `VSL_MAX_ENCODED_INT` (macro, line 23)
  - `VSL_PACKET_SIZE` (macro, line 24)
  - `VSL_PAYLOAD_SIZE` (macro, line 26)

## legacy/vsl_config.py
- Layer: infrastructure
- Language: py
- Symbols:
  - `VSLParameter` (class, line 40) `class VSLParameter(NamedTuple)`
  - `validate_configuration` (method, line 92) `def validate_configuration()`
  - `print_configuration_status` (method, line 116) `def print_configuration_status()`
- Imported by: `legacy/vsl_core.py`, `legacy/vsl_core.py`, `legacy/vsl_hid_io.py`, `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`, `legacy/vsl_transport.py`, `legacy/vsl_transport.py`

## legacy/vsl_core.py
- Layer: utility
- Language: py
- Symbols:
  - `vsl_encode_gain` (function, line 16) `def vsl_encode_gain(linear_value, param)`
  - `vsl_map_frequency` (function, line 58) `def vsl_map_frequency(linear_position, param)`
  - `vsl_final_encode_to_int` (function, line 94) `def vsl_final_encode_to_int(encoded_float, param)`
  - `vsl_decode_frequency` (function, line 127) `def vsl_decode_frequency(freq_hz_value, param)`
  - `validate_parameter` (function, line 170) `def validate_parameter(param)`
- Depends on: `legacy/vsl_config.py`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`

## legacy/vsl_dsp_logic.c
- Layer: business_logic
- Doc: include "vsl_dsp_logic.h"  Declaración de la nueva función de envío
- Language: c
- Symbols:
  - `VSL_Encode_Gain` (function, line 11) `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)`
  - `VSL_Map_Frequency` (function, line 29) `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)`
  - `VSL_Final_Encode_To_Int` (function, line 58) `uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)`
  - `VSL_Decode_Frequency` (function, line 78) `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)`

## legacy/vsl_dsp_logic.h
- Layer: business_logic
- Doc: ifndef VSL_DSP_LOGIC_H define VSL_DSP_LOGIC_H  include <stdint.h> include <math.h> include <float.h> // Para fmaxf, fmin
- Language: h
- Symbols:
  - `VSL_DSP_LOGIC_H` (macro, line 2)
  - `VSL_INV_LN2` (macro, line 10)

## legacy/vsl_dsp_transport.c
- Layer: utility
- Doc: vsl_dsp_transport.c (Añadir la Plantilla B completa aquí)  include <stdio.h> include <string.h> include <math.h> include
- Language: c
- Symbols:
  - `VSL_Init_Device` (function, line 22) `int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)`
  - `VSL_Close_Device` (function, line 69) `void VSL_Close_Device(void)`
  - `VSL_Get_Device_Handle` (function, line 78) `hid_device* VSL_Get_Device_Handle(void)`
  - `FUN_Send_Packet` (function, line 97) `void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length)`
  - `VSL_Build_And_Send_Packet` (function, line 140) `void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float)`

## legacy/vsl_dsp_transport.h
- Layer: utility
- Doc: vsl_dsp_transport.h (CORREGIDO)  ifndef VSL_DSP_TRANSPORT_H define VSL_DSP_TRANSPORT_H  include <stdint.h> include <stdd
- Language: h
- Symbols:
  - `VSL_DSP_TRANSPORT_H` (macro, line 4)

## legacy/vsl_hid_io.py
- Layer: utility
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
- Depends on: `legacy/vsl_config.py`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

## legacy/vsl_poc_main.py
- Layer: utility
- Language: py
- Symbols:
  - `test_gain_encoding` (function, line 43) `def test_gain_encoding()`
  - `test_frequency_mapping` (function, line 72) `def test_frequency_mapping()`
  - `test_packet_construction` (function, line 92) `def test_packet_construction()`
  - `test_edge_cases` (function, line 150) `def test_edge_cases()`
  - `run_full_workflow` (function, line 197) `def run_full_workflow()`
  - `print_summary` (function, line 229) `def print_summary()`
  - `main` (function, line 266) `def main()`
- Depends on: `legacy/vsl_config.py`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`

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
- Depends on: `legacy/vsl_config.py`
- Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`
