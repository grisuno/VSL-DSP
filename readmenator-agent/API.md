# API (page 1 of 2)
Pages: [API.md](API.md), [API_p2.md](API_p2.md)

## audiobox_vsl.c
Depends on: `audiobox_vsl.h`
- `audiobox_probe` (function) `audiobox_vsl.c:37` `static int audiobox_probe(struct usb_interface *intf,
                           const struct usb...`
- `audiobox_disconnect` (function) `audiobox_vsl.c:64` `static void audiobox_disconnect(struct usb_interface *intf)`

## audiobox_vsl.h
Imported by: `audiobox_vsl.c`, `legacy/mixer_quirks.c`, `tests/test_audiobox_vsl.c`
- `audiobox_lookup_model` (function) `audiobox_vsl.h:107` `static inline const audiobox_model_info_t *
audiobox_lookup_model(uint16_t pid)`
- `audiobox_is_primary_interface` (function) `audiobox_vsl.h:131` `static inline int
audiobox_is_primary_interface(unsigned int ifnum)`
- `snd_audiobox_vsl_init` (function) `audiobox_vsl.h:150` `int snd_audiobox_vsl_init(struct usb_mixer_interface *mixer);` -- @brief ALSA mixer init hook for AudioBox VSL devices.

## avatar/avatar_logic.c
Depends on: `avatar/avatar_logic.h`
- `avatar_rms_f32` (function) `avatar/avatar_logic.c:5` `float avatar_rms_f32(const float *x, size_t n)`
- `avatar_rms_to_dbfs` (function) `avatar/avatar_logic.c:27` `float avatar_rms_to_dbfs(float rms)`
- `avatar_zcr_f32` (function) `avatar/avatar_logic.c:41` `float avatar_zcr_f32(const float *x, size_t n)`
- `avatar_hf_ratio_f32` (function) `avatar/avatar_logic.c:68` `float avatar_hf_ratio_f32(const float *x, size_t n)`
- `avatar_classify` (function) `avatar/avatar_logic.c:107` `avatar_state_t avatar_classify(float rms_db, float zcr, float hf,
                               ...`
- `avatar_smooth_init` (function) `avatar/avatar_logic.c:125` `void avatar_smooth_init(avatar_smooth_t *s, avatar_state_t init, uint64_t now_ms,
               ...`
- `avatar_smooth` (function) `avatar/avatar_logic.c:136` `avatar_state_t avatar_smooth(avatar_smooth_t *s, avatar_state_t inst,
                           ...`
- `avatar_state_name` (function) `avatar/avatar_logic.c:161` `const char *avatar_state_name(avatar_state_t st)`

## avatar/avatar_logic.h
Imported by: `avatar/avatar_logic.c`, `avatar/avatar_main.c`
- `avatar_rms_f32` (function) `avatar/avatar_logic.h:45` `float avatar_rms_f32(const float *x, size_t n);` -- @brief RMS of a mono float frame, 0..1. @param x frame or NULL. @param n frame length. @return RMS, 0 on...
- `avatar_rms_to_dbfs` (function) `avatar/avatar_logic.h:52` `float avatar_rms_to_dbfs(float rms);` -- @brief Convert RMS to dBFS with -120 dB floor. @param rms linear RMS. @return dBFS value.
- `avatar_zcr_f32` (function) `avatar/avatar_logic.h:60` `float avatar_zcr_f32(const float *x, size_t n);` -- @brief Zero-crossing rate 0..1. @param x frame or NULL. @param n frame length. @return crossing count / (n-1), 0 on...
- `avatar_hf_ratio_f32` (function) `avatar/avatar_logic.h:68` `float avatar_hf_ratio_f32(const float *x, size_t n);` -- @brief High-frequency ratio RMS(diff)/RMS, clamped 0..2. @param x frame or NULL. @param n frame length. @return...
- `avatar_classify` (function) `avatar/avatar_logic.h:78` `avatar_state_t avatar_classify(float rms_db, float zcr, float hf, const avatar_cfg_t *c);` -- @brief Instantaneous state without hysteresis, fail-closed. @param rms_db frame level in dBFS. @param zcr...
- `avatar_smooth_init` (function) `avatar/avatar_logic.h:85` `void avatar_smooth_init(avatar_smooth_t *s, avatar_state_t init, uint64_t now_ms, unsigned int hold_ms);` -- @brief Init hysteresis holder. @param hold_ms release delay for CLOSED in ms.
- `avatar_smooth` (function) `avatar/avatar_logic.h:95` `avatar_state_t avatar_smooth(avatar_smooth_t *s, avatar_state_t inst, uint64_t now_ms);` -- @brief Hysteresis: instant attack, delayed release to CLOSED. @param s holder or NULL (NULL yields CLOSED). @param...
- `avatar_state_name` (function) `avatar/avatar_logic.h:103` `const char *avatar_state_name(avatar_state_t st);` -- @brief State label for window title and headless output. @param st state value. @return static string, never NULL.

## avatar/avatar_main.c
Depends on: `avatar/avatar_config.h`, `avatar/avatar_logic.h`
- `on_sigint` (function) `avatar/avatar_main.c:24` `static void on_sigint(int sig)`
- `usage` (function) `avatar/avatar_main.c:30` `static void usage(const char *argv0)`
- `list_pcms` (function) `avatar/avatar_main.c:54` `static int list_pcms(void)`
- `env_or` (function) `avatar/avatar_main.c:79` `static const char *env_or(const char *name, const char *fallback)`
- `open_capture` (function) `avatar/avatar_main.c:85` `static snd_pcm_t *open_capture(const char *dev, unsigned int rate,
                              ...`
- `to_mono_f32` (function) `avatar/avatar_main.c:156` `static void to_mono_f32(const uint8_t *raw, float *out, size_t frames,
                        un...` -- if (snd_pcm_hw_params(pcm, hw) < 0) { fprintf(stderr, "avatar: '%s' cannot apply hw params\n", dev)...
- `main` (function) `avatar/avatar_main.c:191` `int main(int argc, char **argv)`

## legacy/build-dkms.sh
- `print_header` (function) `legacy/build-dkms.sh:40`
- `print_success` (function) `legacy/build-dkms.sh:48`
- `print_error` (function) `legacy/build-dkms.sh:52`
- `print_warning` (function) `legacy/build-dkms.sh:56`
- `print_info` (function) `legacy/build-dkms.sh:60`
- `check_root` (function) `legacy/build-dkms.sh:64`
- `check_dependencies` (function) `legacy/build-dkms.sh:72`
- `detect_audiobox` (function) `legacy/build-dkms.sh:101`
- `create_source_structure` (function) `legacy/build-dkms.sh:123`
- `copy_source_files` (function) `legacy/build-dkms.sh:138`
- `create_dkms_conf` (function) `legacy/build-dkms.sh:174`
- `create_makefile` (function) `legacy/build-dkms.sh:193`
- `verify_mixer_quirks` (function) `legacy/build-dkms.sh:252`
- `build_with_dkms` (function) `legacy/build-dkms.sh:295`
- `install_module` (function) `legacy/build-dkms.sh:309`
- `reload_module` (function) `legacy/build-dkms.sh:323`
- `verify_installation` (function) `legacy/build-dkms.sh:344`
- `show_usage_info` (function) `legacy/build-dkms.sh:394`
- `main` (function) `legacy/build-dkms.sh:452`

## legacy/main.c
Depends on: `legacy/vsl_dsp_logic.h`, `legacy/vsl_dsp_transport.h`
- `main` (function) `legacy/main.c:5` `int main()`

## legacy/mixer_quirks.c
Depends on: `audiobox_vsl.h`
- `snd_create_std_mono_ctl_offset` (function) `legacy/mixer_quirks.c:59` `static int snd_create_std_mono_ctl_offset(struct usb_mixer_interface *mixer,
					  unsigned int ...` -- This function allows for the creation of standard UAC controls.
- `snd_create_std_mono_ctl` (function) `legacy/mixer_quirks.c:113` `static int snd_create_std_mono_ctl(struct usb_mixer_interface *mixer,
				   unsigned int unitid,...`
- `snd_create_std_mono_table` (function) `legacy/mixer_quirks.c:129` `static int snd_create_std_mono_table(struct usb_mixer_interface *mixer,
				     const struct std...` -- Create a set of standard UAC controls from a table
- `add_single_ctl_with_resume` (function) `legacy/mixer_quirks.c:146` `static int add_single_ctl_with_resume(struct usb_mixer_interface *mixer,
				      int id,
				  ...`
- `snd_usb_soundblaster_remote_complete` (function) `legacy/mixer_quirks.c:200` `static void snd_usb_soundblaster_remote_complete(struct urb *urb)`
- `snd_usb_sbrc_hwdep_read` (function) `legacy/mixer_quirks.c:220` `static long snd_usb_sbrc_hwdep_read(struct snd_hwdep *hw, char __user *buf,
				    long count, l...`
- `snd_usb_sbrc_hwdep_poll` (function) `legacy/mixer_quirks.c:240` `static __poll_t snd_usb_sbrc_hwdep_poll(struct snd_hwdep *hw, struct file *file,
					poll_table ...`
- `snd_usb_soundblaster_remote_init` (function) `legacy/mixer_quirks.c:249` `static int snd_usb_soundblaster_remote_init(struct usb_mixer_interface *mixer)`
- `snd_audigy2nx_led_get` (function) `legacy/mixer_quirks.c:299` `static int snd_audigy2nx_led_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)`
- `snd_audigy2nx_led_update` (function) `legacy/mixer_quirks.c:305` `static int snd_audigy2nx_led_update(struct usb_mixer_interface *mixer,
				    int value, int index)`
- `snd_audigy2nx_led_put` (function) `legacy/mixer_quirks.c:334` `static int snd_audigy2nx_led_put(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_value *u...`
- `snd_audigy2nx_led_resume` (function) `legacy/mixer_quirks.c:353` `static int snd_audigy2nx_led_resume(struct usb_mixer_elem_list *list)`
- `snd_audigy2nx_controls_create` (function) `legacy/mixer_quirks.c:375` `static int snd_audigy2nx_controls_create(struct usb_mixer_interface *mixer)`
- `snd_audigy2nx_proc_read` (function) `legacy/mixer_quirks.c:407` `static void snd_audigy2nx_proc_read(struct snd_info_entry *entry,
				    struct snd_info_buffer ...`
- `snd_emu0204_ch_switch_info` (function) `legacy/mixer_quirks.c:457` `static int snd_emu0204_ch_switch_info(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_ele...` -- return; err = snd_usb_ctl_msg(mixer->chip->dev, usb_rcvctrlpipe(mixer->chip->dev, 0), UAC_GET_MEM, USB_DIR_IN |...
- `snd_emu0204_ch_switch_get` (function) `legacy/mixer_quirks.c:465` `static int snd_emu0204_ch_switch_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- `snd_emu0204_ch_switch_update` (function) `legacy/mixer_quirks.c:472` `static int snd_emu0204_ch_switch_update(struct usb_mixer_interface *mixer,
					int value)`
- `snd_emu0204_ch_switch_put` (function) `legacy/mixer_quirks.c:490` `static int snd_emu0204_ch_switch_put(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- `snd_emu0204_ch_switch_resume` (function) `legacy/mixer_quirks.c:509` `static int snd_emu0204_ch_switch_resume(struct usb_mixer_elem_list *list)`
- `snd_emu0204_controls_create` (function) `legacy/mixer_quirks.c:524` `static int snd_emu0204_controls_create(struct usb_mixer_interface *mixer)`
- `snd_dualsense_ih_event` (function) `legacy/mixer_quirks.c:550` `static void snd_dualsense_ih_event(struct input_handle *handle,
				   unsigned int type, unsigne...`
- `snd_dualsense_ih_match` (function) `legacy/mixer_quirks.c:571` `static bool snd_dualsense_ih_match(struct input_handler *handler,
				   struct input_dev *dev)`
- `snd_dualsense_ih_connect` (function) `legacy/mixer_quirks.c:618` `static int snd_dualsense_ih_connect(struct input_handler *handler,
				    struct input_dev *dev,...`
- `snd_dualsense_ih_disconnect` (function) `legacy/mixer_quirks.c:650` `static void snd_dualsense_ih_disconnect(struct input_handle *handle)`
- `snd_dualsense_ih_start` (function) `legacy/mixer_quirks.c:657` `static void snd_dualsense_ih_start(struct input_handle *handle)`
- `snd_dualsense_jack_get` (function) `legacy/mixer_quirks.c:680` `static int snd_dualsense_jack_get(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...`
- `snd_dualsense_resume_jack` (function) `legacy/mixer_quirks.c:697` `static int snd_dualsense_resume_jack(struct usb_mixer_elem_list *list)`
- `snd_dualsense_mixer_elem_free` (function) `legacy/mixer_quirks.c:704` `static void snd_dualsense_mixer_elem_free(struct snd_kcontrol *kctl)`
- `snd_dualsense_jack_create` (function) `legacy/mixer_quirks.c:714` `static int snd_dualsense_jack_create(struct usb_mixer_interface *mixer,
				     const char *name...`
- `snd_dualsense_controls_create` (function) `legacy/mixer_quirks.c:778` `static int snd_dualsense_controls_create(struct usb_mixer_interface *mixer)`
- `snd_xonar_u1_switch_get` (function) `legacy/mixer_quirks.c:792` `static int snd_xonar_u1_switch_get(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...`
- `snd_xonar_u1_switch_update` (function) `legacy/mixer_quirks.c:799` `static int snd_xonar_u1_switch_update(struct usb_mixer_interface *mixer,
				      unsigned char ...`
- `snd_xonar_u1_switch_put` (function) `legacy/mixer_quirks.c:813` `static int snd_xonar_u1_switch_put(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...`
- `snd_xonar_u1_switch_resume` (function) `legacy/mixer_quirks.c:833` `static int snd_xonar_u1_switch_resume(struct usb_mixer_elem_list *list)`
- `snd_xonar_u1_controls_create` (function) `legacy/mixer_quirks.c:848` `static int snd_xonar_u1_controls_create(struct usb_mixer_interface *mixer)`
- `snd_mbox1_is_spdif_synced` (function) `legacy/mixer_quirks.c:857` `static int snd_mbox1_is_spdif_synced(struct snd_usb_audio *chip)`
- `snd_mbox1_set_clk_source` (function) `legacy/mixer_quirks.c:877` `static int snd_mbox1_set_clk_source(struct snd_usb_audio *chip, int rate_or_zero)`
- `snd_mbox1_is_spdif_input` (function) `legacy/mixer_quirks.c:895` `static int snd_mbox1_is_spdif_input(struct snd_usb_audio *chip)`
- `snd_mbox1_set_input_source` (function) `legacy/mixer_quirks.c:915` `static int snd_mbox1_set_input_source(struct snd_usb_audio *chip, int is_spdif)`
- `snd_mbox1_clk_switch_get` (function) `legacy/mixer_quirks.c:934` `static int snd_mbox1_clk_switch_get(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...`
- `snd_mbox1_clk_switch_update` (function) `legacy/mixer_quirks.c:954` `static int snd_mbox1_clk_switch_update(struct usb_mixer_interface *mixer, int is_spdif_sync)`
- `snd_mbox1_clk_switch_put` (function) `legacy/mixer_quirks.c:979` `static int snd_mbox1_clk_switch_put(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...`
- `snd_mbox1_clk_switch_info` (function) `legacy/mixer_quirks.c:997` `static int snd_mbox1_clk_switch_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- `snd_mbox1_clk_switch_resume` (function) `legacy/mixer_quirks.c:1008` `static int snd_mbox1_clk_switch_resume(struct usb_mixer_elem_list *list)`
- `snd_mbox1_src_switch_get` (function) `legacy/mixer_quirks.c:1015` `static int snd_mbox1_src_switch_get(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...`
- `snd_mbox1_src_switch_update` (function) `legacy/mixer_quirks.c:1022` `static int snd_mbox1_src_switch_update(struct usb_mixer_interface *mixer, int is_spdif_input)`
- `snd_mbox1_src_switch_put` (function) `legacy/mixer_quirks.c:1046` `static int snd_mbox1_src_switch_put(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...`
- `snd_mbox1_src_switch_info` (function) `legacy/mixer_quirks.c:1064` `static int snd_mbox1_src_switch_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- `snd_mbox1_src_switch_resume` (function) `legacy/mixer_quirks.c:1075` `static int snd_mbox1_src_switch_resume(struct usb_mixer_elem_list *list)`
- `snd_mbox1_controls_create` (function) `legacy/mixer_quirks.c:1102` `static int snd_mbox1_controls_create(struct usb_mixer_interface *mixer)`
- `snd_ni_control_init_val` (function) `legacy/mixer_quirks.c:1121` `static int snd_ni_control_init_val(struct usb_mixer_interface *mixer,
				   struct snd_kcontrol ...`
- `snd_nativeinstruments_control_get` (function) `legacy/mixer_quirks.c:1143` `static int snd_nativeinstruments_control_get(struct snd_kcontrol *kcontrol,
					     struct snd_...`
- `snd_ni_update_cur_val` (function) `legacy/mixer_quirks.c:1150` `static int snd_ni_update_cur_val(struct usb_mixer_elem_list *list)`
- `snd_nativeinstruments_control_put` (function) `legacy/mixer_quirks.c:1164` `static int snd_nativeinstruments_control_put(struct snd_kcontrol *kcontrol,
					     struct snd_...`
- `snd_nativeinstruments_create_mixer` (function) `legacy/mixer_quirks.c:1235` `static int snd_nativeinstruments_create_mixer(struct usb_mixer_interface *mixer,
					      const...`
- `snd_ftu_eff_switch_info` (function) `legacy/mixer_quirks.c:1267` `static int snd_ftu_eff_switch_info(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_info...` -- err = add_single_ctl_with_resume(mixer, 0, snd_ni_update_cur_val, &template, &list); if (err < 0) break...
- `snd_ftu_eff_switch_init` (function) `legacy/mixer_quirks.c:1278` `static int snd_ftu_eff_switch_init(struct usb_mixer_interface *mixer,
				   struct snd_kcontrol ...`
- `snd_ftu_eff_switch_get` (function) `legacy/mixer_quirks.c:1301` `static int snd_ftu_eff_switch_get(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...`
- `snd_ftu_eff_switch_update` (function) `legacy/mixer_quirks.c:1308` `static int snd_ftu_eff_switch_update(struct usb_mixer_elem_list *list)`
- `snd_ftu_eff_switch_put` (function) `legacy/mixer_quirks.c:1329` `static int snd_ftu_eff_switch_put(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...`
- `snd_ftu_create_effect_switch` (function) `legacy/mixer_quirks.c:1347` `static int snd_ftu_create_effect_switch(struct usb_mixer_interface *mixer,
					int validx, int b...`
- `snd_ftu_create_volume_ctls` (function) `legacy/mixer_quirks.c:1373` `static int snd_ftu_create_volume_ctls(struct usb_mixer_interface *mixer)` -- struct usb_mixer_elem_list *list; int err; err = add_single_ctl_with_resume(mixer, bUnitID...
- `snd_ftu_create_effect_volume_ctl` (function) `legacy/mixer_quirks.c:1412` `static int snd_ftu_create_effect_volume_ctl(struct usb_mixer_interface *mixer)` -- "DIn%d - Out%d Playback Volume", in - 7, out + 1); err = snd_create_std_mono_ctl(mixer, id, control, cmask...
- `snd_ftu_create_effect_duration_ctl` (function) `legacy/mixer_quirks.c:1425` `static int snd_ftu_create_effect_duration_ctl(struct usb_mixer_interface *mixer)` -- /* This control needs a volume quirk, see mixer.c static int snd_ftu_create_effect_volume_ctl(struct...
- `snd_ftu_create_effect_feedback_ctl` (function) `legacy/mixer_quirks.c:1438` `static int snd_ftu_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)` -- /* This control needs a volume quirk, see mixer.c static int snd_ftu_create_effect_duration_ctl(struct...
- `snd_ftu_create_effect_return_ctls` (function) `legacy/mixer_quirks.c:1450` `static int snd_ftu_create_effect_return_ctls(struct usb_mixer_interface *mixer)`
- `snd_ftu_create_effect_send_ctls` (function) `legacy/mixer_quirks.c:1474` `static int snd_ftu_create_effect_send_ctls(struct usb_mixer_interface *mixer)`
- `snd_ftu_create_mixer` (function) `legacy/mixer_quirks.c:1507` `static int snd_ftu_create_mixer(struct usb_mixer_interface *mixer)`
- `snd_emuusb_set_samplerate` (function) `legacy/mixer_quirks.c:1542` `void snd_emuusb_set_samplerate(struct snd_usb_audio *chip,
			       unsigned char samplerate_id)`
- `list_for_each_entry` (function) `legacy/mixer_quirks.c:1549` `list_for_each_entry(mixer, &chip->mixer_list, list)`
- `snd_c400_create_vol_ctls` (function) `legacy/mixer_quirks.c:1563` `static int snd_c400_create_vol_ctls(struct usb_mixer_interface *mixer)` -- list_for_each_entry(mixer, &chip->mixer_list, list) { if (mixer->id_elems[unitid]) { cval =...
- `snd_c400_create_effect_volume_ctl` (function) `legacy/mixer_quirks.c:1612` `static int snd_c400_create_effect_volume_ctl(struct usb_mixer_interface *mixer)` -- cmask = (out == 0) ?
- `snd_c400_create_effect_duration_ctl` (function) `legacy/mixer_quirks.c:1625` `static int snd_c400_create_effect_duration_ctl(struct usb_mixer_interface *mixer)` -- /* This control needs a volume quirk, see mixer.c static int snd_c400_create_effect_volume_ctl(struct...
- `snd_c400_create_effect_feedback_ctl` (function) `legacy/mixer_quirks.c:1638` `static int snd_c400_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)` -- /* This control needs a volume quirk, see mixer.c static int snd_c400_create_effect_duration_ctl(struct...
- `snd_c400_create_effect_vol_ctls` (function) `legacy/mixer_quirks.c:1650` `static int snd_c400_create_effect_vol_ctls(struct usb_mixer_interface *mixer)`
- `snd_c400_create_effect_ret_vol_ctls` (function) `legacy/mixer_quirks.c:1695` `static int snd_c400_create_effect_ret_vol_ctls(struct usb_mixer_interface *mixer)`
- `snd_c400_create_mixer` (function) `legacy/mixer_quirks.c:1737` `static int snd_c400_create_mixer(struct usb_mixer_interface *mixer)`
- `snd_microii_spdif_info` (function) `legacy/mixer_quirks.c:1869` `static int snd_microii_spdif_info(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_info *...` -- power on values: r2: 0x10 r3: 0x20 (b7 is zeroed just before playback (except IEC61937) and set just after it to...
- `snd_microii_spdif_default_get` (function) `legacy/mixer_quirks.c:1877` `static int snd_microii_spdif_default_get(struct snd_kcontrol *kcontrol,
					 struct snd_ctl_elem...`
- `snd_microii_spdif_default_update` (function) `legacy/mixer_quirks.c:1924` `static int snd_microii_spdif_default_update(struct usb_mixer_elem_list *list)`
- `snd_microii_spdif_default_put` (function) `legacy/mixer_quirks.c:1960` `static int snd_microii_spdif_default_put(struct snd_kcontrol *kcontrol,
					 struct snd_ctl_elem...`
- `snd_microii_spdif_mask_get` (function) `legacy/mixer_quirks.c:1988` `static int snd_microii_spdif_mask_get(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_ele...`
- `snd_microii_spdif_switch_get` (function) `legacy/mixer_quirks.c:1999` `static int snd_microii_spdif_switch_get(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_v...`
- `snd_microii_spdif_switch_update` (function) `legacy/mixer_quirks.c:2007` `static int snd_microii_spdif_switch_update(struct usb_mixer_elem_list *list)`
- `snd_microii_spdif_switch_put` (function) `legacy/mixer_quirks.c:2026` `static int snd_microii_spdif_switch_put(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_v...`
- `snd_microii_controls_create` (function) `legacy/mixer_quirks.c:2068` `static int snd_microii_controls_create(struct usb_mixer_interface *mixer)`
- `snd_soundblaster_e1_switch_get` (function) `legacy/mixer_quirks.c:2091` `static int snd_soundblaster_e1_switch_get(struct snd_kcontrol *kcontrol,
					  struct snd_ctl_el...`
- `snd_soundblaster_e1_switch_update` (function) `legacy/mixer_quirks.c:2098` `static int snd_soundblaster_e1_switch_update(struct usb_mixer_interface *mixer,
					     unsigne...`
- `snd_soundblaster_e1_switch_put` (function) `legacy/mixer_quirks.c:2116` `static int snd_soundblaster_e1_switch_put(struct snd_kcontrol *kcontrol,
					  struct snd_ctl_el...`
- `snd_soundblaster_e1_switch_resume` (function) `legacy/mixer_quirks.c:2130` `static int snd_soundblaster_e1_switch_resume(struct usb_mixer_elem_list *list)`
- `snd_soundblaster_e1_switch_info` (function) `legacy/mixer_quirks.c:2136` `static int snd_soundblaster_e1_switch_info(struct snd_kcontrol *kcontrol,
					   struct snd_ctl_...`
- `snd_soundblaster_e1_switch_create` (function) `legacy/mixer_quirks.c:2155` `static int snd_soundblaster_e1_switch_create(struct usb_mixer_interface *mixer)`
- `realtek_hda_set` (function) `legacy/mixer_quirks.c:2192` `static int realtek_hda_set(struct snd_usb_audio *chip, u32 cmd)`
- `realtek_hda_get` (function) `legacy/mixer_quirks.c:2202` `static int realtek_hda_get(struct snd_usb_audio *chip, u32 cmd, u32 *value)`
- `realtek_ctl_connector_get` (function) `legacy/mixer_quirks.c:2223` `static int realtek_ctl_connector_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- `realtek_resume_jack` (function) `legacy/mixer_quirks.c:2273` `static int realtek_resume_jack(struct usb_mixer_elem_list *list)`
- `realtek_add_jack` (function) `legacy/mixer_quirks.c:2280` `static int realtek_add_jack(struct usb_mixer_interface *mixer,
			    char *name, u32 val)`
- `dell_dock_mixer_create` (function) `legacy/mixer_quirks.c:2307` `static int dell_dock_mixer_create(struct usb_mixer_interface *mixer)`
- `dell_dock_init_vol` (function) `legacy/mixer_quirks.c:2339` `static void dell_dock_init_vol(struct usb_mixer_interface *mixer, int ch, int id)`
- `dell_dock_mixer_init` (function) `legacy/mixer_quirks.c:2351` `static int dell_dock_mixer_init(struct usb_mixer_interface *mixer)`
- `snd_rme_read_value` (function) `legacy/mixer_quirks.c:2419` `static int snd_rme_read_value(struct snd_usb_audio *chip,
			      unsigned int item,
			      u3...`
- `snd_rme_get_status1` (function) `legacy/mixer_quirks.c:2438` `static int snd_rme_get_status1(struct snd_kcontrol *kcontrol,
			       u32 *status1)`
- `snd_rme_rate_get` (function) `legacy/mixer_quirks.c:2450` `static int snd_rme_rate_get(struct snd_kcontrol *kcontrol,
			    struct snd_ctl_elem_value *ucon...`
- `snd_rme_sync_state_get` (function) `legacy/mixer_quirks.c:2484` `static int snd_rme_sync_state_get(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_value ...`
- `snd_rme_spdif_if_get` (function) `legacy/mixer_quirks.c:2514` `static int snd_rme_spdif_if_get(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *uco...`
- `snd_rme_spdif_format_get` (function) `legacy/mixer_quirks.c:2527` `static int snd_rme_spdif_format_get(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_va...`
- `snd_rme_sync_source_get` (function) `legacy/mixer_quirks.c:2540` `static int snd_rme_sync_source_get(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...`
- `snd_rme_current_freq_get` (function) `legacy/mixer_quirks.c:2553` `static int snd_rme_current_freq_get(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_va...`
- `snd_rme_rate_info` (function) `legacy/mixer_quirks.c:2579` `static int snd_rme_rate_info(struct snd_kcontrol *kcontrol,
			     struct snd_ctl_elem_info *uinfo)`
- `snd_rme_sync_state_info` (function) `legacy/mixer_quirks.c:2599` `static int snd_rme_sync_state_info(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_info...`
- `snd_rme_spdif_if_info` (function) `legacy/mixer_quirks.c:2610` `static int snd_rme_spdif_if_info(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_info *ui...`
- `snd_rme_spdif_format_info` (function) `legacy/mixer_quirks.c:2621` `static int snd_rme_spdif_format_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- `snd_rme_sync_source_info` (function) `legacy/mixer_quirks.c:2632` `static int snd_rme_sync_source_info(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_in...`
- `snd_rme_controls_create` (function) `legacy/mixer_quirks.c:2714` `static int snd_rme_controls_create(struct usb_mixer_interface *mixer)`
- `snd_bbfpro_ctl_update` (function) `legacy/mixer_quirks.c:2780` `static int snd_bbfpro_ctl_update(struct usb_mixer_interface *mixer, u8 reg,
				 u8 index, u8 value)`
- `snd_bbfpro_ctl_get` (function) `legacy/mixer_quirks.c:2811` `static int snd_bbfpro_ctl_get(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...`
- `snd_bbfpro_ctl_info` (function) `legacy/mixer_quirks.c:2834` `static int snd_bbfpro_ctl_info(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_info ...`
- `snd_bbfpro_ctl_put` (function) `legacy/mixer_quirks.c:2868` `static int snd_bbfpro_ctl_put(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...`
- `snd_bbfpro_ctl_resume` (function) `legacy/mixer_quirks.c:2907` `static int snd_bbfpro_ctl_resume(struct usb_mixer_elem_list *list)`
- `snd_bbfpro_gain_update` (function) `legacy/mixer_quirks.c:2920` `static int snd_bbfpro_gain_update(struct usb_mixer_interface *mixer,
				  u8 channel, u8 gain)`
- `snd_bbfpro_gain_get` (function) `legacy/mixer_quirks.c:2944` `static int snd_bbfpro_gain_get(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_value...`
- `snd_bbfpro_gain_info` (function) `legacy/mixer_quirks.c:2953` `static int snd_bbfpro_gain_info(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_info *uinfo)`
- `snd_bbfpro_gain_put` (function) `legacy/mixer_quirks.c:2974` `static int snd_bbfpro_gain_put(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_value...`
- `snd_bbfpro_gain_resume` (function) `legacy/mixer_quirks.c:3011` `static int snd_bbfpro_gain_resume(struct usb_mixer_elem_list *list)`
- `snd_bbfpro_vol_update` (function) `legacy/mixer_quirks.c:3024` `static int snd_bbfpro_vol_update(struct usb_mixer_interface *mixer, u16 index,
				 u32 value)`
- `snd_bbfpro_vol_get` (function) `legacy/mixer_quirks.c:3050` `static int snd_bbfpro_vol_get(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...`
- `snd_bbfpro_vol_info` (function) `legacy/mixer_quirks.c:3058` `static int snd_bbfpro_vol_info(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_info ...`
- `snd_bbfpro_vol_put` (function) `legacy/mixer_quirks.c:3068` `static int snd_bbfpro_vol_put(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...`
- `snd_bbfpro_vol_resume` (function) `legacy/mixer_quirks.c:3096` `static int snd_bbfpro_vol_resume(struct usb_mixer_elem_list *list)`
- `snd_bbfpro_ctl_add` (function) `legacy/mixer_quirks.c:3133` `static int snd_bbfpro_ctl_add(struct usb_mixer_interface *mixer, u8 reg,
			      u8 index, char ...`
- `snd_bbfpro_gain_add` (function) `legacy/mixer_quirks.c:3147` `static int snd_bbfpro_gain_add(struct usb_mixer_interface *mixer, u8 channel,
			       char *name)`
- `snd_bbfpro_vol_add` (function) `legacy/mixer_quirks.c:3159` `static int snd_bbfpro_vol_add(struct usb_mixer_interface *mixer, u16 index,
			      char *name)`
- `snd_bbfpro_controls_create` (function) `legacy/mixer_quirks.c:3171` `static int snd_bbfpro_controls_create(struct usb_mixer_interface *mixer)`
- `snd_rme_digiface_write_reg` (function) `legacy/mixer_quirks.c:3319` `static int snd_rme_digiface_write_reg(struct snd_kcontrol *kcontrol, int item, u16 mask, u16 val)`
- `snd_rme_digiface_read_status` (function) `legacy/mixer_quirks.c:3337` `static int snd_rme_digiface_read_status(struct snd_kcontrol *kcontrol, u32 status[4])`
- `snd_rme_digiface_get_status_val` (function) `legacy/mixer_quirks.c:3361` `static int snd_rme_digiface_get_status_val(struct snd_kcontrol *kcontrol)`
- `snd_rme_digiface_rate_get` (function) `legacy/mixer_quirks.c:3399` `static int snd_rme_digiface_rate_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- `snd_rme_digiface_enum_get` (function) `legacy/mixer_quirks.c:3413` `static int snd_rme_digiface_enum_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- `snd_rme_digiface_enum_put` (function) `legacy/mixer_quirks.c:3425` `static int snd_rme_digiface_enum_put(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...`
- `snd_rme_digiface_current_sync_get` (function) `legacy/mixer_quirks.c:3439` `static int snd_rme_digiface_current_sync_get(struct snd_kcontrol *kcontrol,
					     struct snd_...`
- `snd_rme_digiface_sync_state_get` (function) `legacy/mixer_quirks.c:3451` `static int snd_rme_digiface_sync_state_get(struct snd_kcontrol *kcontrol,
					   struct snd_ctl_...`
- `snd_rme_digiface_format_info` (function) `legacy/mixer_quirks.c:3474` `static int snd_rme_digiface_format_info(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_i...`
- `snd_rme_digiface_sync_source_info` (function) `legacy/mixer_quirks.c:3485` `static int snd_rme_digiface_sync_source_info(struct snd_kcontrol *kcontrol,
					     struct snd_...`
- `snd_rme_digiface_rate_info` (function) `legacy/mixer_quirks.c:3496` `static int snd_rme_digiface_rate_info(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_ele...`
- `snd_rme_digiface_controls_create` (function) `legacy/mixer_quirks.c:3685` `static int snd_rme_digiface_controls_create(struct usb_mixer_interface *mixer)`
- `snd_djm_get_label_caplevel_common` (function) `legacy/mixer_quirks.c:3792` `static const char *snd_djm_get_label_caplevel_common(u16 wvalue)`
- `snd_djm_get_label_caplevel_high` (function) `legacy/mixer_quirks.c:3804` `static const char *snd_djm_get_label_caplevel_high(u16 wvalue)` -- Models like DJM-A9 or DJM-V10 have different capture levels than others
- `snd_djm_get_label_cap_common` (function) `legacy/mixer_quirks.c:3817` `static const char *snd_djm_get_label_cap_common(u16 wvalue)`
- `snd_djm_get_label_cap_850` (function) `legacy/mixer_quirks.c:3849` `static const char *snd_djm_get_label_cap_850(u16 wvalue)` -- The DJM-850 has different values for CD/LINE and LINE capture control options than the other DJM declared in this file.
- `snd_djm_get_label_caplevel` (function) `legacy/mixer_quirks.c:3858` `static const char *snd_djm_get_label_caplevel(u8 device_idx, u16 wvalue)`
- `snd_djm_get_label_cap` (function) `legacy/mixer_quirks.c:3867` `static const char *snd_djm_get_label_cap(u8 device_idx, u16 wvalue)`
- `snd_djm_get_label_pb` (function) `legacy/mixer_quirks.c:3875` `static const char *snd_djm_get_label_pb(u16 wvalue)`
- `snd_djm_get_label` (function) `legacy/mixer_quirks.c:3885` `static const char *snd_djm_get_label(u8 device_idx, u16 wvalue, u16 windex)`
- `snd_djm_controls_info` (function) `legacy/mixer_quirks.c:4117` `static int snd_djm_controls_info(struct snd_kcontrol *kctl,
				 struct snd_ctl_elem_info *info)`
- `snd_djm_controls_update` (function) `legacy/mixer_quirks.c:4149` `static int snd_djm_controls_update(struct usb_mixer_interface *mixer,
				   u8 device_idx, u8 gr...`
- `snd_djm_controls_get` (function) `legacy/mixer_quirks.c:4170` `static int snd_djm_controls_get(struct snd_kcontrol *kctl,
				struct snd_ctl_elem_value *elem)`
- `snd_djm_controls_put` (function) `legacy/mixer_quirks.c:4177` `static int snd_djm_controls_put(struct snd_kcontrol *kctl, struct snd_ctl_elem_value *elem)`
- `snd_djm_controls_resume` (function) `legacy/mixer_quirks.c:4194` `static int snd_djm_controls_resume(struct usb_mixer_elem_list *list)`
- `snd_djm_controls_create` (function) `legacy/mixer_quirks.c:4204` `static int snd_djm_controls_create(struct usb_mixer_interface *mixer,
				   const u8 device_idx)`
- `snd_usb_mixer_apply_create_quirk` (function) `legacy/mixer_quirks.c:4239` `int snd_usb_mixer_apply_create_quirk(struct usb_mixer_interface *mixer)`
- `snd_usb_mixer_resume_quirk` (function) `legacy/mixer_quirks.c:4421` `void snd_usb_mixer_resume_quirk(struct usb_mixer_interface *mixer)`
- `snd_usb_mixer_rc_memory_change` (function) `legacy/mixer_quirks.c:4430` `void snd_usb_mixer_rc_memory_change(struct usb_mixer_interface *mixer,
				    int unitid)`
- `snd_dragonfly_quirk_db_scale` (function) `legacy/mixer_quirks.c:4458` `static void snd_dragonfly_quirk_db_scale(struct usb_mixer_interface *mixer,
					 struct usb_mixe...`
- `DECLARE_TLV_DB_RANGE` (function) `legacy/mixer_quirks.c:4465` `static const DECLARE_TLV_DB_RANGE(scale, 0, 1, TLV_DB_MINMAX_ITEM(-5300, -4970), 2, 5, TLV_DB_MINMAX_ITEM(-4710...` -- Approximation using 10 ranges based on output measurement on hw v1.2.
- `snd_fix_plt_name` (function) `legacy/mixer_quirks.c:4509` `static void snd_fix_plt_name(struct snd_usb_audio *chip,
			     struct snd_ctl_elem_id *id)` -- standards.
- `snd_usb_mixer_fu_apply_quirk` (function) `legacy/mixer_quirks.c:4539` `void snd_usb_mixer_fu_apply_quirk(struct usb_mixer_interface *mixer,
				  struct usb_mixer_elem_...`

## legacy/vsl_config.py
- `VSLParameter.validate_configuration` (method) `legacy/vsl_config.py:92` `def validate_configuration()` -- Valida que todos los valores críticos estén configurados.
- `VSLParameter.print_configuration_status` (method) `legacy/vsl_config.py:116` `def print_configuration_status()` -- Imprime el estado de la configuración con formato.

## legacy/vsl_core.py
Depends on: `legacy/vsl_config.h`
Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`
- `vsl_encode_gain` (function) `legacy/vsl_core.py:16` `def vsl_encode_gain(linear_value, param)` -- Traducción de FUN_00132c90 (VSL_Encode_Gain en C).
- `vsl_map_frequency` (function) `legacy/vsl_core.py:58` `def vsl_map_frequency(linear_position, param)` -- Traducción de FUN_00132d00 (VSL_Map_Frequency en C).
- `vsl_final_encode_to_int` (function) `legacy/vsl_core.py:94` `def vsl_final_encode_to_int(encoded_float, param)` -- Traducción de VSL_Final_Encode_To_Int en C.
- `vsl_decode_frequency` (function) `legacy/vsl_core.py:127` `def vsl_decode_frequency(freq_hz_value, param)` -- Traducción de FUN_00132da8 (VSL_Decode_Frequency en C).
- `validate_parameter` (function) `legacy/vsl_core.py:170` `def validate_parameter(param)` -- Valida la integridad de un VSLParameter.

## legacy/vsl_dsp_logic.c
Depends on: `legacy/vsl_dsp_logic.h`
- `VSL_Build_And_Send_Packet` (function) `legacy/vsl_dsp_logic.c:4` `void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float);` -- Declaración de la nueva función de envío
- `VSL_Encode_Gain` (function) `legacy/vsl_dsp_logic.c:11` `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)` -- Implementación de FUN_00132c90
- `VSL_Map_Frequency` (function) `legacy/vsl_dsp_logic.c:29` `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)` -- Implementación de FUN_00132d00
- `VSL_Final_Encode_To_Int` (function) `legacy/vsl_dsp_logic.c:58` `uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)` -- @brief Convierte el valor codificado en float a un entero sin signo para el firmware. @note Basado en la hipótesis...
- `VSL_Decode_Frequency` (function) `legacy/vsl_dsp_logic.c:78` `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)` -- Implementación de FUN_00132da8

## legacy/vsl_dsp_logic.h
Imported by: `legacy/main.c`, `legacy/vsl_dsp_logic.c`
- `VSL_Encode_Gain` (function) `legacy/vsl_dsp_logic.h:42` `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);` -- @brief Codifica un valor lineal (ej.
- `VSL_Map_Frequency` (function) `legacy/vsl_dsp_logic.h:50` `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);` -- @brief Convierte una posición lineal (ej.
- `VSL_Final_Encode_To_Int` (function) `legacy/vsl_dsp_logic.h:60` `uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param);` -- @brief Convierte el valor codificado en float a un entero sin signo para el firmware. @note ESTA FUNCIÓN ES UN...
- `VSL_Decode_Frequency` (function) `legacy/vsl_dsp_logic.h:73` `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);` -- @brief Decodifica una frecuencia real (Hz) del DSP a su posición lineal de control (0.0 a 1.0). @param freq_hz_value...

## legacy/vsl_dsp_transport.c
Depends on: `legacy/vsl_config.h`, `legacy/vsl_dsp_transport.h`
- `VSL_Init_Device` (function) `legacy/vsl_dsp_transport.c:23` `int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)`
- `VSL_Close_Device` (function) `legacy/vsl_dsp_transport.c:70` `void VSL_Close_Device(void)`
- `VSL_Get_Device_Handle` (function) `legacy/vsl_dsp_transport.c:79` `hid_device* VSL_Get_Device_Handle(void)`
- `FUN_Send_Packet` (function) `legacy/vsl_dsp_transport.c:97` `void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length)` -- @brief Función de I/O real usando HIDAPI. @note DEBE SER REEMPLAZADA con la lógica específica de tu dispositivo...
- `VSL_Build_And_Send_Packet` (function) `legacy/vsl_dsp_transport.c:140` `void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float)` -- Implementación de la función de construcción y envío

## legacy/vsl_dsp_transport.h
Depends on: `legacy/vsl_config.h`
Imported by: `legacy/main.c`, `legacy/test_connection.c`, `legacy/vsl_dsp_transport.c`
- `VSL_Init_Device` (function) `legacy/vsl_dsp_transport.h:19` `int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id);` -- 1.
- `VSL_Close_Device` (function) `legacy/vsl_dsp_transport.h:20` `void VSL_Close_Device(void);`
- `VSL_Get_Device_Handle` (function) `legacy/vsl_dsp_transport.h:21` `hid_device* VSL_Get_Device_Handle(void);`
- `FUN_Send_Packet` (function) `legacy/vsl_dsp_transport.h:24` `void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length);` -- 2.
- `VSL_Build_And_Send_Packet` (function) `legacy/vsl_dsp_transport.h:25` `void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float);`

## legacy/vsl_hid_io.py
Depends on: `legacy/vsl_config.h`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`
- `VSLDevice.__init__` (method) `legacy/vsl_hid_io.py:45` `def __init__(self)`
- `VSLDevice.open` (method) `legacy/vsl_hid_io.py:59` `def open(self)` -- Abre la conexión con el dispositivo VSL.
- `VSLDevice.close` (method) `legacy/vsl_hid_io.py:90` `def close(self)` -- Cierra la conexión con el dispositivo.
- `VSLDevice.send_packet` (method) `legacy/vsl_hid_io.py:101` `def send_packet(self, packet)` -- Envía un paquete VSL al dispositivo.
- `VSLDevice.enumerate_vsl_devices` (method) `legacy/vsl_hid_io.py:149` `def enumerate_vsl_devices()` -- Enumera todos los dispositivos HID conectados. Útil para descubrir VID/PID del hardware.

## legacy/vsl_poc_main.py
Depends on: `legacy/vsl_config.h`, `legacy/vsl_core.py`, `legacy/vsl_transport.py`
- `test_gain_encoding` (function) `legacy/vsl_poc_main.py:43` `def test_gain_encoding()` -- Test de codificación de ganancia con tabla de validación.
- `test_frequency_mapping` (function) `legacy/vsl_poc_main.py:72` `def test_frequency_mapping()` -- Test de mapeo logarítmico de frecuencias.
- `test_packet_construction` (function) `legacy/vsl_poc_main.py:92` `def test_packet_construction()` -- Test de construcción de paquetes HID.
- `test_edge_cases` (function) `legacy/vsl_poc_main.py:150` `def test_edge_cases()` -- Test de casos extremos y validación de errores.
- `run_full_workflow` (function) `legacy/vsl_poc_main.py:197` `def run_full_workflow()` -- Simula el flujo completo: Usuario → Encoding → Paquete.
- `print_summary` (function) `legacy/vsl_poc_main.py:229` `def print_summary()` -- Imprime resumen del estado del proyecto.
- `main` (function) `legacy/vsl_poc_main.py:266` `def main()` -- Función principal de la PoC.

## legacy/vsl_protocol_analyzer.py
- `VSLParameter.__init__` (method) `legacy/vsl_protocol_analyzer.py:30` `def __init__(self, dsp_id, name, type_unit, min_map, max_map, coeff_A, coeff_C1, log_factor)`
- `VSLParameter.reverse_map_gain` (method) `legacy/vsl_protocol_analyzer.py:67` `def reverse_map_gain(encoded_value, param)` -- Simula VSL_Decode_Gain.
- `VSLParameter.reverse_map_frequency` (method) `legacy/vsl_protocol_analyzer.py:95` `def reverse_map_frequency(encoded_value, param)` -- Simula VSL_Decode_Frequency.
- `VSLParameter.get_decoded_value` (method) `legacy/vsl_protocol_analyzer.py:115` `def get_decoded_value(encoded_value, param_id)` -- Dirige la decodificación al motor DSP correcto.
- `VSLParameter.decode_vsl_packet` (method) `legacy/vsl_protocol_analyzer.py:140` `def decode_vsl_packet(data)` -- Decodifica el payload de 64 bytes.
- `VSLParameter.analyze_pcap` (method) `legacy/vsl_protocol_analyzer.py:173` `def analyze_pcap(pcap_file)` -- Carga un archivo PCAP y filtra los paquetes USB VSL.

## legacy/vsl_transport.py
Depends on: `legacy/vsl_config.h`
Imported by: `legacy/vsl_hid_io.py`, `legacy/vsl_poc_main.py`
- `VSLPacket.__init__` (method) `legacy/vsl_transport.py:21` `def __init__(self, param_id, encoded_value, report_id)` -- Construye un paquete VSL-DSP.
- `VSLPacket.buffer` (method) `legacy/vsl_transport.py:89` `def buffer(self)` -- Retorna el buffer como bytes inmutables.
- `VSLPacket.hex_dump` (method) `legacy/vsl_transport.py:93` `def hex_dump(self, num_bytes)` -- Genera un hex dump del paquete para debugging.
- `VSLPacket.validate` (method) `legacy/vsl_transport.py:106` `def validate(self)` -- Valida la integridad del paquete.
- `VSLPacket.build_packet_safe` (method) `legacy/vsl_transport.py:141` `def build_packet_safe(param, encoded_value)` -- Construye un paquete con manejo de errores.

## src/vsl_cli.c
Depends on: `src/vsl_config.h`, `src/vsl_dsp_logic.h`, `src/vsl_dsp_transport.h`
- `print_usage` (function) `src/vsl_cli.c:61` `static void print_usage(FILE *fp, const char *prog)`
- `print_version` (function) `src/vsl_cli.c:88` `static void print_version(void)`
- `print_list` (function) `src/vsl_cli.c:95` `static void print_list(uint16_t product_id)`
- `lookup_coeffs_by_param_id` (function) `src/vsl_cli.c:115` `static const VSL_Parameter *
lookup_coeffs_by_param_id(uint16_t param_id)`
- `find_entry_by_name` (function) `src/vsl_cli.c:125` `static const ParamEntry *
find_entry_by_name(const char *name)`
- `do_send` (function) `src/vsl_cli.c:134` `static int do_send(uint16_t product_id,
                   uint16_t param_id,
                   ...`
- `do_send_freq` (function) `src/vsl_cli.c:172` `static int do_send_freq(uint16_t product_id,
                        uint16_t param_id,
         ...`
- `main` (function) `src/vsl_cli.c:209` `int main(int argc, char *argv[])`

## src/vsl_config.h
Imported by: `src/vsl_cli.c`, `src/vsl_dsp_transport.h`
- `VSL_ModelLookup` (function) `src/vsl_config.h:38` `static inline const VSL_ModelInfo *
VSL_ModelLookup(uint16_t pid)`
- `VSL_ModelLookupByTag` (function) `src/vsl_config.h:50` `static inline const VSL_ModelInfo *
VSL_ModelLookupByTag(const char *tag)`

## src/vsl_dsp_logic.c
Depends on: `src/vsl_dsp_logic.h`
- `VSL_Encode_Gain` (function) `src/vsl_dsp_logic.c:3` `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)`
- `VSL_Decode_Gain` (function) `src/vsl_dsp_logic.c:16` `float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param)`
- `VSL_Map_Frequency` (function) `src/vsl_dsp_logic.c:50` `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)`
- `VSL_Final_Encode_To_Int` (function) `src/vsl_dsp_logic.c:66` `uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)`
- `VSL_Decode_Frequency` (function) `src/vsl_dsp_logic.c:76` `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)`
- `VSL_Linear_To_DB` (function) `src/vsl_dsp_logic.c:95` `float VSL_Linear_To_DB(float linear_value)`
- `VSL_DB_To_Linear` (function) `src/vsl_dsp_logic.c:105` `float VSL_DB_To_Linear(float db_value)`

## src/vsl_dsp_logic.h
Imported by: `src/vsl_cli.c`, `src/vsl_dsp_logic.c`, `src/vsl_dsp_transport.h`
- `VSL_Encode_Gain` (function) `src/vsl_dsp_logic.h:44` `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);` -- @brief Encodes a linear gain value [0.0, 1.0] to the DSP exponential curve. @param linear_value Linear control...
- `VSL_Decode_Gain` (function) `src/vsl_dsp_logic.h:53` `float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param);` -- @brief Decodes an encoded gain float back to a linear position [0.0, 1.0]. @param encoded_float Value received from...
- `VSL_Map_Frequency` (function) `src/vsl_dsp_logic.h:62` `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);` -- @brief Maps a linear position [0.0, 1.0] to a logarithmic frequency (Hz). @param linear_position Linear control...
- `VSL_Decode_Frequency` (function) `src/vsl_dsp_logic.h:71` `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);` -- @brief Decodes a frequency (Hz) from the DSP to a linear position [0.0, 1.0]. @param freq_hz_value Frequency in Hz...
- `VSL_Final_Encode_To_Int` (function) `src/vsl_dsp_logic.h:81` `uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param);` -- @brief Converts an encoded float to a 16-bit integer for the DSP firmware. @param encoded_float Value from...
- `negative` (function) `src/vsl_dsp_logic.h:87` `* when linear_value is zero or negative (the `db.inf` domain). */ float VSL_Linear_To_DB(float linear_value);`
- `VSL_DB_To_Linear` (function) `src/vsl_dsp_logic.h:97` `float VSL_DB_To_Linear(float db_value);` -- @brief Converts a decibel gain back to linear [0.0, 1.0]. @param db_value Gain in dB. @return Linear gain clamped to...

## src/vsl_dsp_transport.c
Depends on: `src/vsl_dsp_transport.h`
- `VSL_Init_Device` (function) `src/vsl_dsp_transport.c:13` `vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)`
- `VSL_Close_Device` (function) `src/vsl_dsp_transport.c:50` `void VSL_Close_Device(vsl_device_handle handle)`
- `VSL_Build_Packet` (function) `src/vsl_dsp_transport.c:79` `int VSL_Build_Packet(uint16_t dsp_param_id,
                     uint16_t encoded_value,
        ...`
- `VSL_Send_Parameter` (function) `src/vsl_dsp_transport.c:96` `int VSL_Send_Parameter(vsl_device_handle handle,
                       uint16_t dsp_param_id,
  ...`

## src/vsl_dsp_transport.h
Depends on: `src/vsl_config.h`, `src/vsl_dsp_logic.h`
Imported by: `src/vsl_cli.c`, `src/vsl_dsp_transport.c`
- `VSL_Close_Device` (function) `src/vsl_dsp_transport.h:26` `void VSL_Close_Device(vsl_device_handle handle);` -- @brief Release the MIDI interface and close the device. @param handle Handle from VSL_Init_Device.
- `evidence` (function) `src/vsl_dsp_transport.h:37` `* evidence (blockers #2/#3);`
- `VSL_Build_Packet` (function) `src/vsl_dsp_transport.h:39` `int VSL_Build_Packet(uint16_t dsp_param_id, uint16_t encoded_value, unsigned char *out);` -- @brief Fill a VSL_PACKET_SIZE buffer with a DSP parameter datagram. @param dsp_param_id 16-bit DSP parameter...
- `VSL_Send_Parameter` (function) `src/vsl_dsp_transport.h:50` `int VSL_Send_Parameter(vsl_device_handle handle, uint16_t dsp_param_id, uint16_t encoded_value);` -- @brief Send a DSP parameter value to the device via USB bulk transfer. @param handle Handle from VSL_Init_Device....

## tests/bdd_driver_gate.sh
- `ok` (function) `tests/bdd_driver_gate.sh:29`
- `bad` (function) `tests/bdd_driver_gate.sh:30`


Next: [API_p2.md](API_p2.md)
