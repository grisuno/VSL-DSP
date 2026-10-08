# Symbols (page 1 of 2)
Pages: [SYMBOLS.md](SYMBOLS.md), [SYMBOLS_p2.md](SYMBOLS_p2.md)

| Symbol | Kind | File:Line | Signature |
|--------|------|-----------|-----------|
| `AUDIOBOX_DRIVER_DESC` | macro | `audiobox_vsl.c:26` | `#define AUDIOBOX_DRIVER_DESC` |
| `AUDIOBOX_DRIVER_LIC` | macro | `audiobox_vsl.c:27` | `#define AUDIOBOX_DRIVER_LIC` |
| `AUDIOBOX_DRIVER_NAME` | macro | `audiobox_vsl.c:25` | `#define AUDIOBOX_DRIVER_NAME` |
| `audiobox_disconnect` | function | `audiobox_vsl.c:64` | `static void audiobox_disconnect(struct usb_interface *intf)` |
| `audiobox_probe` | function | `audiobox_vsl.c:37` | `static int audiobox_probe(struct usb_interface *intf,                            const struct usb...` |
| `AUDIOBOX_VENDOR_ID` | macro | `audiobox_vsl.h:32` | `#define AUDIOBOX_VENDOR_ID` |
| `AUDIOBOX_VERSION_STRING` | macro | `audiobox_vsl.h:55` | `#define AUDIOBOX_VERSION_STRING` |
| `AUDIOBOX_VSL_H` | macro | `audiobox_vsl.h:21` | `#define AUDIOBOX_VSL_H` |
| `audiobox_is_primary_interface` | function | `audiobox_vsl.h:131` | `static inline int audiobox_is_primary_interface(unsigned int ifnum)` |
| `audiobox_lookup_model` | function | `audiobox_vsl.h:107` | `static inline const audiobox_model_info_t * audiobox_lookup_model(uint16_t pid)` |
| `audiobox_model_info_t` | struct | `audiobox_vsl.h:64` | `` |
| `audiobox_model_pid_t` | variable | `audiobox_vsl.h:26` | `extern "C" { #endif /** * @brief PreSonus USB vendor ID shared by every AudioBox VSL model. */ #define...` |
| `snd_audiobox_vsl_init` | function | `audiobox_vsl.h:150` | `int snd_audiobox_vsl_init(struct usb_mixer_interface *mixer);` |
| `usb_mixer_interface` | struct | `audiobox_vsl.h:141` | `` |
| `AVATAR_CONFIG_H` | macro | `avatar/avatar_config.h:2` | `#define AVATAR_CONFIG_H` |
| `AVATAR_DEFAULT_HF_THR` | macro | `avatar/avatar_config.h:21` | `#define AVATAR_DEFAULT_HF_THR` |
| `AVATAR_DEFAULT_HOLD_MS` | macro | `avatar/avatar_config.h:22` | `#define AVATAR_DEFAULT_HOLD_MS` |
| `AVATAR_DEFAULT_PCM` | macro | `avatar/avatar_config.h:12` | `#define AVATAR_DEFAULT_PCM` |
| `AVATAR_DEFAULT_RATE` | macro | `avatar/avatar_config.h:25` | `#define AVATAR_DEFAULT_RATE` |
| `AVATAR_DEFAULT_SILENCE_DB` | macro | `avatar/avatar_config.h:19` | `#define AVATAR_DEFAULT_SILENCE_DB` |
| `AVATAR_DEFAULT_ZCR_THR` | macro | `avatar/avatar_config.h:20` | `#define AVATAR_DEFAULT_ZCR_THR` |
| `AVATAR_FALLBACK_PCM` | macro | `avatar/avatar_config.h:13` | `#define AVATAR_FALLBACK_PCM` |
| `AVATAR_FRAME_SAMPLES` | macro | `avatar/avatar_config.h:24` | `#define AVATAR_FRAME_SAMPLES` |
| `AVATAR_IMG_CLOSED` | macro | `avatar/avatar_config.h:15` | `#define AVATAR_IMG_CLOSED` |
| `AVATAR_IMG_OPEN` | macro | `avatar/avatar_config.h:16` | `#define AVATAR_IMG_OPEN` |
| `AVATAR_IMG_SIBILANT` | macro | `avatar/avatar_config.h:17` | `#define AVATAR_IMG_SIBILANT` |
| `AVATAR_WIN_H` | macro | `avatar/avatar_config.h:27` | `#define AVATAR_WIN_H` |
| `AVATAR_WIN_W` | macro | `avatar/avatar_config.h:26` | `#define AVATAR_WIN_W` |
| `avatar_classify` | function | `avatar/avatar_logic.c:107` | `avatar_state_t avatar_classify(float rms_db, float zcr, float hf,                                ...` |
| `avatar_hf_ratio_f32` | function | `avatar/avatar_logic.c:68` | `float avatar_hf_ratio_f32(const float *x, size_t n)` |
| `avatar_rms_f32` | function | `avatar/avatar_logic.c:5` | `float avatar_rms_f32(const float *x, size_t n)` |
| `avatar_rms_to_dbfs` | function | `avatar/avatar_logic.c:27` | `float avatar_rms_to_dbfs(float rms)` |
| `avatar_smooth` | function | `avatar/avatar_logic.c:136` | `avatar_state_t avatar_smooth(avatar_smooth_t *s, avatar_state_t inst,                            ...` |
| `avatar_smooth_init` | function | `avatar/avatar_logic.c:125` | `void avatar_smooth_init(avatar_smooth_t *s, avatar_state_t init, uint64_t now_ms,                ...` |
| `avatar_state_name` | function | `avatar/avatar_logic.c:161` | `const char *avatar_state_name(avatar_state_t st)` |
| `avatar_zcr_f32` | function | `avatar/avatar_logic.c:41` | `float avatar_zcr_f32(const float *x, size_t n)` |
| `AVATAR_LOGIC_H` | macro | `avatar/avatar_logic.h:2` | `#define AVATAR_LOGIC_H` |
| `avatar_cfg_t` | struct | `avatar/avatar_logic.h:23` | `` |
| `avatar_classify` | function | `avatar/avatar_logic.h:78` | `avatar_state_t avatar_classify(float rms_db, float zcr, float hf, const avatar_cfg_t *c);` |
| `avatar_hf_ratio_f32` | function | `avatar/avatar_logic.h:68` | `float avatar_hf_ratio_f32(const float *x, size_t n);` |
| `avatar_rms_f32` | function | `avatar/avatar_logic.h:45` | `float avatar_rms_f32(const float *x, size_t n);` |
| `avatar_rms_to_dbfs` | function | `avatar/avatar_logic.h:52` | `float avatar_rms_to_dbfs(float rms);` |
| `avatar_smooth` | function | `avatar/avatar_logic.h:95` | `avatar_state_t avatar_smooth(avatar_smooth_t *s, avatar_state_t inst, uint64_t now_ms);` |
| `avatar_smooth_init` | function | `avatar/avatar_logic.h:85` | `void avatar_smooth_init(avatar_smooth_t *s, avatar_state_t init, uint64_t now_ms, unsigned int hold_ms);` |
| `avatar_smooth_t` | struct | `avatar/avatar_logic.h:33` | `` |
| `avatar_state_name` | function | `avatar/avatar_logic.h:103` | `const char *avatar_state_name(avatar_state_t st);` |
| `avatar_state_t` | variable | `avatar/avatar_logic.h:8` | `extern "C" { #endif /** * @brief Visible mouth state. */ typedef enum { AVATAR_CLOSED = 0, AVATAR_OPEN = 1...` |
| `avatar_zcr_f32` | function | `avatar/avatar_logic.h:60` | `float avatar_zcr_f32(const float *x, size_t n);` |
| `env_or` | function | `avatar/avatar_main.c:79` | `static const char *env_or(const char *name, const char *fallback)` |
| `list_pcms` | function | `avatar/avatar_main.c:54` | `static int list_pcms(void)` |
| `main` | function | `avatar/avatar_main.c:191` | `int main(int argc, char **argv)` |
| `on_sigint` | function | `avatar/avatar_main.c:24` | `static void on_sigint(int sig)` |
| `open_capture` | function | `avatar/avatar_main.c:85` | `static snd_pcm_t *open_capture(const char *dev, unsigned int rate,                               ...` |
| `to_mono_f32` | function | `avatar/avatar_main.c:156` | `static void to_mono_f32(const uint8_t *raw, float *out, size_t frames,                         un...` |
| `usage` | function | `avatar/avatar_main.c:30` | `static void usage(const char *argv0)` |
| `build_with_dkms` | function | `legacy/build-dkms.sh:295` | `` |
| `check_dependencies` | function | `legacy/build-dkms.sh:72` | `` |
| `check_root` | function | `legacy/build-dkms.sh:64` | `` |
| `copy_source_files` | function | `legacy/build-dkms.sh:138` | `` |
| `create_dkms_conf` | function | `legacy/build-dkms.sh:174` | `` |
| `create_makefile` | function | `legacy/build-dkms.sh:193` | `` |
| `create_source_structure` | function | `legacy/build-dkms.sh:123` | `` |
| `detect_audiobox` | function | `legacy/build-dkms.sh:101` | `` |
| `install_module` | function | `legacy/build-dkms.sh:309` | `` |
| `main` | function | `legacy/build-dkms.sh:452` | `` |
| `print_error` | function | `legacy/build-dkms.sh:52` | `` |
| `print_header` | function | `legacy/build-dkms.sh:40` | `` |
| `print_info` | function | `legacy/build-dkms.sh:60` | `` |
| `print_success` | function | `legacy/build-dkms.sh:48` | `` |
| `print_warning` | function | `legacy/build-dkms.sh:56` | `` |
| `reload_module` | function | `legacy/build-dkms.sh:323` | `` |
| `show_usage_info` | function | `legacy/build-dkms.sh:394` | `` |
| `verify_installation` | function | `legacy/build-dkms.sh:344` | `` |
| `verify_mixer_quirks` | function | `legacy/build-dkms.sh:252` | `` |
| `main` | function | `legacy/main.c:5` | `int main()` |
| `DECLARE_TLV_DB_RANGE` | function | `legacy/mixer_quirks.c:4465` | `static const DECLARE_TLV_DB_RANGE(scale, 0, 1, TLV_DB_MINMAX_ITEM(-5300, -4970), 2, 5, TLV_DB_MINMAX_ITEM(-4710...` |
| `HDA_VERB_CMD` | macro | `legacy/mixer_quirks.c:2172` | `#define HDA_VERB_CMD(V, N, D)` |
| `REALTEK_AUDIO_FUNCTION_GROUP` | macro | `legacy/mixer_quirks.c:2181` | `#define REALTEK_AUDIO_FUNCTION_GROUP` |
| `REALTEK_CBJ_CTRL2` | macro | `legacy/mixer_quirks.c:2186` | `#define REALTEK_CBJ_CTRL2` |
| `REALTEK_HDA_GET_IN` | macro | `legacy/mixer_quirks.c:2179` | `#define REALTEK_HDA_GET_IN` |
| `REALTEK_HDA_GET_OUT` | macro | `legacy/mixer_quirks.c:2178` | `#define REALTEK_HDA_GET_OUT` |
| `REALTEK_HDA_SET` | macro | `legacy/mixer_quirks.c:2176` | `#define REALTEK_HDA_SET` |
| `REALTEK_HDA_VALUE` | macro | `legacy/mixer_quirks.c:2174` | `#define REALTEK_HDA_VALUE` |
| `REALTEK_HP_OUT` | macro | `legacy/mixer_quirks.c:2184` | `#define REALTEK_HP_OUT` |
| `REALTEK_JACK_INTERRUPT_NODE` | macro | `legacy/mixer_quirks.c:2188` | `#define REALTEK_JACK_INTERRUPT_NODE` |
| `REALTEK_LINE1` | macro | `legacy/mixer_quirks.c:2182` | `#define REALTEK_LINE1` |
| `REALTEK_MANUAL_MODE` | macro | `legacy/mixer_quirks.c:2177` | `#define REALTEK_MANUAL_MODE` |
| `REALTEK_MIC_FLAG` | macro | `legacy/mixer_quirks.c:2190` | `#define REALTEK_MIC_FLAG` |
| `REALTEK_VENDOR_REGISTERS` | macro | `legacy/mixer_quirks.c:2183` | `#define REALTEK_VENDOR_REGISTERS` |
| `RME_DIGIFACE_CTL_REG1` | macro | `legacy/mixer_quirks.c:3308` | `#define RME_DIGIFACE_CTL_REG1` |
| `RME_DIGIFACE_CTL_REG2` | macro | `legacy/mixer_quirks.c:3309` | `#define RME_DIGIFACE_CTL_REG2` |
| `RME_DIGIFACE_INVERT` | macro | `legacy/mixer_quirks.c:3313` | `#define RME_DIGIFACE_INVERT` |
| `RME_DIGIFACE_READ_STATUS` | macro | `legacy/mixer_quirks.c:3298` | `#define RME_DIGIFACE_READ_STATUS` |
| `RME_DIGIFACE_REGISTER` | macro | `legacy/mixer_quirks.c:3312` | `#define RME_DIGIFACE_REGISTER(reg, mask)` |
| `RME_DIGIFACE_STATUS_REG0H` | macro | `legacy/mixer_quirks.c:3300` | `#define RME_DIGIFACE_STATUS_REG0H` |
| `RME_DIGIFACE_STATUS_REG0L` | macro | `legacy/mixer_quirks.c:3299` | `#define RME_DIGIFACE_STATUS_REG0L` |
| `RME_DIGIFACE_STATUS_REG1H` | macro | `legacy/mixer_quirks.c:3302` | `#define RME_DIGIFACE_STATUS_REG1H` |
| `RME_DIGIFACE_STATUS_REG1L` | macro | `legacy/mixer_quirks.c:3301` | `#define RME_DIGIFACE_STATUS_REG1L` |
| `RME_DIGIFACE_STATUS_REG2H` | macro | `legacy/mixer_quirks.c:3304` | `#define RME_DIGIFACE_STATUS_REG2H` |
| `RME_DIGIFACE_STATUS_REG2L` | macro | `legacy/mixer_quirks.c:3303` | `#define RME_DIGIFACE_STATUS_REG2L` |
| `RME_DIGIFACE_STATUS_REG3H` | macro | `legacy/mixer_quirks.c:3306` | `#define RME_DIGIFACE_STATUS_REG3H` |
| `RME_DIGIFACE_STATUS_REG3L` | macro | `legacy/mixer_quirks.c:3305` | `#define RME_DIGIFACE_STATUS_REG3L` |
| `SND_BBFPRO_CTL_IDX_MASK` | macro | `legacy/mixer_quirks.c:2745` | `#define SND_BBFPRO_CTL_IDX_MASK` |
| `SND_BBFPRO_CTL_IDX_SHIFT` | macro | `legacy/mixer_quirks.c:2746` | `#define SND_BBFPRO_CTL_IDX_SHIFT` |
| `SND_BBFPRO_CTL_REG1_CLK_MASTER` | macro | `legacy/mixer_quirks.c:2749` | `#define SND_BBFPRO_CTL_REG1_CLK_MASTER` |
| `SND_BBFPRO_CTL_REG1_CLK_OPTICAL` | macro | `legacy/mixer_quirks.c:2750` | `#define SND_BBFPRO_CTL_REG1_CLK_OPTICAL` |
| `SND_BBFPRO_CTL_REG1_SPDIF_EMPH` | macro | `legacy/mixer_quirks.c:2752` | `#define SND_BBFPRO_CTL_REG1_SPDIF_EMPH` |
| `SND_BBFPRO_CTL_REG1_SPDIF_OPTICAL` | macro | `legacy/mixer_quirks.c:2753` | `#define SND_BBFPRO_CTL_REG1_SPDIF_OPTICAL` |
| `SND_BBFPRO_CTL_REG1_SPDIF_PRO` | macro | `legacy/mixer_quirks.c:2751` | `#define SND_BBFPRO_CTL_REG1_SPDIF_PRO` |
| `SND_BBFPRO_CTL_REG2_48V_AN1` | macro | `legacy/mixer_quirks.c:2754` | `#define SND_BBFPRO_CTL_REG2_48V_AN1` |
| `SND_BBFPRO_CTL_REG2_48V_AN2` | macro | `legacy/mixer_quirks.c:2755` | `#define SND_BBFPRO_CTL_REG2_48V_AN2` |
| `SND_BBFPRO_CTL_REG2_PAD_AN1` | macro | `legacy/mixer_quirks.c:2758` | `#define SND_BBFPRO_CTL_REG2_PAD_AN1` |
| `SND_BBFPRO_CTL_REG2_PAD_AN2` | macro | `legacy/mixer_quirks.c:2759` | `#define SND_BBFPRO_CTL_REG2_PAD_AN2` |
| `SND_BBFPRO_CTL_REG2_SENS_IN3` | macro | `legacy/mixer_quirks.c:2756` | `#define SND_BBFPRO_CTL_REG2_SENS_IN3` |
| `SND_BBFPRO_CTL_REG2_SENS_IN4` | macro | `legacy/mixer_quirks.c:2757` | `#define SND_BBFPRO_CTL_REG2_SENS_IN4` |
| `SND_BBFPRO_CTL_REG_MASK` | macro | `legacy/mixer_quirks.c:2744` | `#define SND_BBFPRO_CTL_REG_MASK` |
| `SND_BBFPRO_CTL_VAL_MASK` | macro | `legacy/mixer_quirks.c:2747` | `#define SND_BBFPRO_CTL_VAL_MASK` |
| `SND_BBFPRO_CTL_VAL_SHIFT` | macro | `legacy/mixer_quirks.c:2748` | `#define SND_BBFPRO_CTL_VAL_SHIFT` |
| `SND_BBFPRO_GAIN_CHANNEL_MASK` | macro | `legacy/mixer_quirks.c:2768` | `#define SND_BBFPRO_GAIN_CHANNEL_MASK` |
| `SND_BBFPRO_GAIN_CHANNEL_SHIFT` | macro | `legacy/mixer_quirks.c:2769` | `#define SND_BBFPRO_GAIN_CHANNEL_SHIFT` |
| `SND_BBFPRO_GAIN_VAL_LINE_MAX` | macro | `legacy/mixer_quirks.c:2773` | `#define SND_BBFPRO_GAIN_VAL_LINE_MAX` |
| `SND_BBFPRO_GAIN_VAL_MASK` | macro | `legacy/mixer_quirks.c:2770` | `#define SND_BBFPRO_GAIN_VAL_MASK` |
| `SND_BBFPRO_GAIN_VAL_MIC_MAX` | macro | `legacy/mixer_quirks.c:2772` | `#define SND_BBFPRO_GAIN_VAL_MIC_MAX` |
| `SND_BBFPRO_GAIN_VAL_MIN` | macro | `legacy/mixer_quirks.c:2771` | `#define SND_BBFPRO_GAIN_VAL_MIN` |
| `SND_BBFPRO_MIXER_IDX_MASK` | macro | `legacy/mixer_quirks.c:2762` | `#define SND_BBFPRO_MIXER_IDX_MASK` |
| `SND_BBFPRO_MIXER_MAIN_OUT_CH_OFFSET` | macro | `legacy/mixer_quirks.c:2761` | `#define SND_BBFPRO_MIXER_MAIN_OUT_CH_OFFSET` |
| `SND_BBFPRO_MIXER_VAL_MASK` | macro | `legacy/mixer_quirks.c:2763` | `#define SND_BBFPRO_MIXER_VAL_MASK` |
| `SND_BBFPRO_MIXER_VAL_MAX` | macro | `legacy/mixer_quirks.c:2766` | `#define SND_BBFPRO_MIXER_VAL_MAX` |
| `SND_BBFPRO_MIXER_VAL_MIN` | macro | `legacy/mixer_quirks.c:2765` | `#define SND_BBFPRO_MIXER_VAL_MIN` |
| `SND_BBFPRO_MIXER_VAL_SHIFT` | macro | `legacy/mixer_quirks.c:2764` | `#define SND_BBFPRO_MIXER_VAL_SHIFT` |
| `SND_BBFPRO_USBREQ_CTL_REG1` | macro | `legacy/mixer_quirks.c:2775` | `#define SND_BBFPRO_USBREQ_CTL_REG1` |
| `SND_BBFPRO_USBREQ_CTL_REG2` | macro | `legacy/mixer_quirks.c:2776` | `#define SND_BBFPRO_USBREQ_CTL_REG2` |
| `SND_BBFPRO_USBREQ_GAIN` | macro | `legacy/mixer_quirks.c:2777` | `#define SND_BBFPRO_USBREQ_GAIN` |
| `SND_BBFPRO_USBREQ_MIXER` | macro | `legacy/mixer_quirks.c:2778` | `#define SND_BBFPRO_USBREQ_MIXER` |
| `SND_DJM_250MK2_IDX` | macro | `legacy/mixer_quirks.c:3758` | `#define SND_DJM_250MK2_IDX` |
| `SND_DJM_450_IDX` | macro | `legacy/mixer_quirks.c:3763` | `#define SND_DJM_450_IDX` |
| `SND_DJM_750MK2_IDX` | macro | `legacy/mixer_quirks.c:3762` | `#define SND_DJM_750MK2_IDX` |
| `SND_DJM_750_IDX` | macro | `legacy/mixer_quirks.c:3759` | `#define SND_DJM_750_IDX` |
| `SND_DJM_850_IDX` | macro | `legacy/mixer_quirks.c:3760` | `#define SND_DJM_850_IDX` |
| `SND_DJM_900NXS2_IDX` | macro | `legacy/mixer_quirks.c:3761` | `#define SND_DJM_900NXS2_IDX` |
| `SND_DJM_A9_IDX` | macro | `legacy/mixer_quirks.c:3764` | `#define SND_DJM_A9_IDX` |
| `SND_DJM_CAP_AUX` | macro | `legacy/mixer_quirks.c:3724` | `#define SND_DJM_CAP_AUX` |
| `SND_DJM_CAP_CDLINE` | macro | `legacy/mixer_quirks.c:3716` | `#define SND_DJM_CAP_CDLINE` |
| `SND_DJM_CAP_CH1PFADER` | macro | `legacy/mixer_quirks.c:3729` | `#define SND_DJM_CAP_CH1PFADER` |
| `SND_DJM_CAP_CH1PREFADER` | macro | `legacy/mixer_quirks.c:3735` | `#define SND_DJM_CAP_CH1PREFADER` |
| `SND_DJM_CAP_CH2PFADER` | macro | `legacy/mixer_quirks.c:3730` | `#define SND_DJM_CAP_CH2PFADER` |
| `SND_DJM_CAP_CH2PREFADER` | macro | `legacy/mixer_quirks.c:3736` | `#define SND_DJM_CAP_CH2PREFADER` |
| `SND_DJM_CAP_CH3PFADER` | macro | `legacy/mixer_quirks.c:3731` | `#define SND_DJM_CAP_CH3PFADER` |
| `SND_DJM_CAP_CH3PREFADER` | macro | `legacy/mixer_quirks.c:3737` | `#define SND_DJM_CAP_CH3PREFADER` |
| `SND_DJM_CAP_CH4PFADER` | macro | `legacy/mixer_quirks.c:3732` | `#define SND_DJM_CAP_CH4PFADER` |
| `SND_DJM_CAP_CH4PREFADER` | macro | `legacy/mixer_quirks.c:3738` | `#define SND_DJM_CAP_CH4PREFADER` |
| `SND_DJM_CAP_DIGITAL` | macro | `legacy/mixer_quirks.c:3717` | `#define SND_DJM_CAP_DIGITAL` |
| `SND_DJM_CAP_EXT1SEND` | macro | `legacy/mixer_quirks.c:3733` | `#define SND_DJM_CAP_EXT1SEND` |
| `SND_DJM_CAP_EXT2SEND` | macro | `legacy/mixer_quirks.c:3734` | `#define SND_DJM_CAP_EXT2SEND` |
| `SND_DJM_CAP_FXSEND` | macro | `legacy/mixer_quirks.c:3728` | `#define SND_DJM_CAP_FXSEND` |
| `SND_DJM_CAP_LINE` | macro | `legacy/mixer_quirks.c:3715` | `#define SND_DJM_CAP_LINE` |
| `SND_DJM_CAP_MIC` | macro | `legacy/mixer_quirks.c:3723` | `#define SND_DJM_CAP_MIC` |
| `SND_DJM_CAP_NONE` | macro | `legacy/mixer_quirks.c:3727` | `#define SND_DJM_CAP_NONE` |
| `SND_DJM_CAP_PFADER` | macro | `legacy/mixer_quirks.c:3720` | `#define SND_DJM_CAP_PFADER` |
| `SND_DJM_CAP_PHONO` | macro | `legacy/mixer_quirks.c:3718` | `#define SND_DJM_CAP_PHONO` |
| `SND_DJM_CAP_PREFADER` | macro | `legacy/mixer_quirks.c:3719` | `#define SND_DJM_CAP_PREFADER` |
| `SND_DJM_CAP_RECOUT` | macro | `legacy/mixer_quirks.c:3725` | `#define SND_DJM_CAP_RECOUT` |
| `SND_DJM_CAP_RECOUT_NOMIC` | macro | `legacy/mixer_quirks.c:3726` | `#define SND_DJM_CAP_RECOUT_NOMIC` |
| `SND_DJM_CAP_XFADERA` | macro | `legacy/mixer_quirks.c:3721` | `#define SND_DJM_CAP_XFADERA` |
| `SND_DJM_CAP_XFADERB` | macro | `legacy/mixer_quirks.c:3722` | `#define SND_DJM_CAP_XFADERB` |
| `SND_DJM_CTL` | macro | `legacy/mixer_quirks.c:3767` | `#define SND_DJM_CTL(_name, suffix, _default_value, _windex)` |
| `SND_DJM_DEVICE` | macro | `legacy/mixer_quirks.c:3774` | `#define SND_DJM_DEVICE(suffix)` |
| `SND_DJM_DEVICE_MASK` | macro | `legacy/mixer_quirks.c:3752` | `#define SND_DJM_DEVICE_MASK` |
| `SND_DJM_DEVICE_SHIFT` | macro | `legacy/mixer_quirks.c:3754` | `#define SND_DJM_DEVICE_SHIFT` |
| `SND_DJM_GROUP_MASK` | macro | `legacy/mixer_quirks.c:3751` | `#define SND_DJM_GROUP_MASK` |
| `SND_DJM_GROUP_SHIFT` | macro | `legacy/mixer_quirks.c:3753` | `#define SND_DJM_GROUP_SHIFT` |
| `SND_DJM_PB_AUX` | macro | `legacy/mixer_quirks.c:3743` | `#define SND_DJM_PB_AUX` |
| `SND_DJM_PB_CH1` | macro | `legacy/mixer_quirks.c:3741` | `#define SND_DJM_PB_CH1` |
| `SND_DJM_PB_CH2` | macro | `legacy/mixer_quirks.c:3742` | `#define SND_DJM_PB_CH2` |
| `SND_DJM_V10_IDX` | macro | `legacy/mixer_quirks.c:3765` | `#define SND_DJM_V10_IDX` |
| `SND_DJM_VALUE_MASK` | macro | `legacy/mixer_quirks.c:3750` | `#define SND_DJM_VALUE_MASK` |
| `SND_DJM_WINDEX_CAP` | macro | `legacy/mixer_quirks.c:3745` | `#define SND_DJM_WINDEX_CAP` |
| `SND_DJM_WINDEX_CAPLVL` | macro | `legacy/mixer_quirks.c:3746` | `#define SND_DJM_WINDEX_CAPLVL` |
| `SND_DJM_WINDEX_PB` | macro | `legacy/mixer_quirks.c:3747` | `#define SND_DJM_WINDEX_PB` |
| `SND_DUALSENSE_JACK_IN_TERM_ID` | macro | `legacy/mixer_quirks.c:541` | `#define SND_DUALSENSE_JACK_IN_TERM_ID` |
| `SND_DUALSENSE_JACK_OUT_TERM_ID` | macro | `legacy/mixer_quirks.c:540` | `#define SND_DUALSENSE_JACK_OUT_TERM_ID` |
| `SND_RME_BINARY_MASK` | macro | `legacy/mixer_quirks.c:2390` | `#define SND_RME_BINARY_MASK` |
| `SND_RME_CLK_AES` | macro | `legacy/mixer_quirks.c:2376` | `#define SND_RME_CLK_AES(x)` |
| `SND_RME_CLK_AES_LOCK` | macro | `legacy/mixer_quirks.c:2384` | `#define SND_RME_CLK_AES_LOCK` |
| `SND_RME_CLK_AES_SHIFT` | macro | `legacy/mixer_quirks.c:2367` | `#define SND_RME_CLK_AES_SHIFT` |
| `SND_RME_CLK_AES_SPDIF_MASK` | macro | `legacy/mixer_quirks.c:2369` | `#define SND_RME_CLK_AES_SPDIF_MASK` |
| `SND_RME_CLK_AES_SYNC` | macro | `legacy/mixer_quirks.c:2385` | `#define SND_RME_CLK_AES_SYNC` |
| `SND_RME_CLK_FREQMUL` | macro | `legacy/mixer_quirks.c:2382` | `#define SND_RME_CLK_FREQMUL(x)` |
| `SND_RME_CLK_FREQMUL_MASK` | macro | `legacy/mixer_quirks.c:2373` | `#define SND_RME_CLK_FREQMUL_MASK` |
| `SND_RME_CLK_FREQMUL_SHIFT` | macro | `legacy/mixer_quirks.c:2372` | `#define SND_RME_CLK_FREQMUL_SHIFT` |
| `SND_RME_CLK_SPDIF` | macro | `legacy/mixer_quirks.c:2378` | `#define SND_RME_CLK_SPDIF(x)` |
| `SND_RME_CLK_SPDIF_LOCK` | macro | `legacy/mixer_quirks.c:2386` | `#define SND_RME_CLK_SPDIF_LOCK` |
| `SND_RME_CLK_SPDIF_SHIFT` | macro | `legacy/mixer_quirks.c:2368` | `#define SND_RME_CLK_SPDIF_SHIFT` |
| `SND_RME_CLK_SPDIF_SYNC` | macro | `legacy/mixer_quirks.c:2387` | `#define SND_RME_CLK_SPDIF_SYNC` |
| `SND_RME_CLK_SYNC` | macro | `legacy/mixer_quirks.c:2380` | `#define SND_RME_CLK_SYNC(x)` |
| `SND_RME_CLK_SYNC_MASK` | macro | `legacy/mixer_quirks.c:2371` | `#define SND_RME_CLK_SYNC_MASK` |
| `SND_RME_CLK_SYNC_SHIFT` | macro | `legacy/mixer_quirks.c:2370` | `#define SND_RME_CLK_SYNC_SHIFT` |
| `SND_RME_CLK_SYSTEM` | macro | `legacy/mixer_quirks.c:2374` | `#define SND_RME_CLK_SYSTEM(x)` |
| `SND_RME_CLK_SYSTEM_MASK` | macro | `legacy/mixer_quirks.c:2366` | `#define SND_RME_CLK_SYSTEM_MASK` |
| `SND_RME_CLK_SYSTEM_SHIFT` | macro | `legacy/mixer_quirks.c:2365` | `#define SND_RME_CLK_SYSTEM_SHIFT` |
| `SND_RME_GET_CURRENT_FREQ` | macro | `legacy/mixer_quirks.c:2364` | `#define SND_RME_GET_CURRENT_FREQ` |
| `SND_RME_GET_STATUS1` | macro | `legacy/mixer_quirks.c:2363` | `#define SND_RME_GET_STATUS1` |
| `SND_RME_RATE_IDX_AES_SPDIF_NUM` | macro | `legacy/mixer_quirks.c:2405` | `#define SND_RME_RATE_IDX_AES_SPDIF_NUM` |
| `SND_RME_SPDIF_FORMAT` | macro | `legacy/mixer_quirks.c:2393` | `#define SND_RME_SPDIF_FORMAT(x)` |
| `SND_RME_SPDIF_FORMAT_SHIFT` | macro | `legacy/mixer_quirks.c:2389` | `#define SND_RME_SPDIF_FORMAT_SHIFT` |
| `SND_RME_SPDIF_IF` | macro | `legacy/mixer_quirks.c:2391` | `#define SND_RME_SPDIF_IF(x)` |
| `SND_RME_SPDIF_IF_SHIFT` | macro | `legacy/mixer_quirks.c:2388` | `#define SND_RME_SPDIF_IF_SHIFT` |
| `_MAKE_NI_CONTROL` | macro | `legacy/mixer_quirks.c:1119` | `#define _MAKE_NI_CONTROL(bRequest, wIndex)` |
| `add_single_ctl_with_resume` | function | `legacy/mixer_quirks.c:146` | `static int add_single_ctl_with_resume(struct usb_mixer_interface *mixer, 				      int id, 				  ...` |
| `dell_dock_init_vol` | function | `legacy/mixer_quirks.c:2339` | `static void dell_dock_init_vol(struct usb_mixer_interface *mixer, int ch, int id)` |
| `dell_dock_mixer_create` | function | `legacy/mixer_quirks.c:2307` | `static int dell_dock_mixer_create(struct usb_mixer_interface *mixer)` |
| `dell_dock_mixer_init` | function | `legacy/mixer_quirks.c:2351` | `static int dell_dock_mixer_init(struct usb_mixer_interface *mixer)` |
| `dualsense_mixer_elem_info` | struct | `legacy/mixer_quirks.c:543` | `` |
| `field_get` | macro | `legacy/mixer_quirks.c:3316` | `#define field_get(_mask, _reg)` |
| `field_prep` | macro | `legacy/mixer_quirks.c:3317` | `#define field_prep(_mask, _val)` |
| `list_for_each_entry` | function | `legacy/mixer_quirks.c:1549` | `list_for_each_entry(mixer, &chip->mixer_list, list)` |
| `rc_config` | struct | `legacy/mixer_quirks.c:181` | `` |
| `realtek_add_jack` | function | `legacy/mixer_quirks.c:2280` | `static int realtek_add_jack(struct usb_mixer_interface *mixer, 			    char *name, u32 val)` |
| `realtek_ctl_connector_get` | function | `legacy/mixer_quirks.c:2223` | `static int realtek_ctl_connector_get(struct snd_kcontrol *kcontrol, 				     struct snd_ctl_elem_...` |
| `realtek_hda_get` | function | `legacy/mixer_quirks.c:2202` | `static int realtek_hda_get(struct snd_usb_audio *chip, u32 cmd, u32 *value)` |
| `realtek_hda_set` | function | `legacy/mixer_quirks.c:2192` | `static int realtek_hda_set(struct snd_usb_audio *chip, u32 cmd)` |
| `realtek_resume_jack` | function | `legacy/mixer_quirks.c:2273` | `static int realtek_resume_jack(struct usb_mixer_elem_list *list)` |
| `sb_jack` | struct | `legacy/mixer_quirks.c:410` | `` |
| `snd_audigy2nx_controls_create` | function | `legacy/mixer_quirks.c:375` | `static int snd_audigy2nx_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_audigy2nx_led_get` | function | `legacy/mixer_quirks.c:299` | `static int snd_audigy2nx_led_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)` |
| `snd_audigy2nx_led_info` | macro | `legacy/mixer_quirks.c:297` | `#define snd_audigy2nx_led_info` |
| `snd_audigy2nx_led_put` | function | `legacy/mixer_quirks.c:334` | `static int snd_audigy2nx_led_put(struct snd_kcontrol *kcontrol, 				 struct snd_ctl_elem_value *u...` |
| `snd_audigy2nx_led_resume` | function | `legacy/mixer_quirks.c:353` | `static int snd_audigy2nx_led_resume(struct usb_mixer_elem_list *list)` |
| `snd_audigy2nx_led_update` | function | `legacy/mixer_quirks.c:305` | `static int snd_audigy2nx_led_update(struct usb_mixer_interface *mixer, 				    int value, int index)` |
| `snd_audigy2nx_proc_read` | function | `legacy/mixer_quirks.c:407` | `static void snd_audigy2nx_proc_read(struct snd_info_entry *entry, 				    struct snd_info_buffer ...` |
| `snd_bbfpro_controls_create` | function | `legacy/mixer_quirks.c:3171` | `static int snd_bbfpro_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_bbfpro_ctl_add` | function | `legacy/mixer_quirks.c:3133` | `static int snd_bbfpro_ctl_add(struct usb_mixer_interface *mixer, u8 reg, 			      u8 index, char ...` |
| `snd_bbfpro_ctl_get` | function | `legacy/mixer_quirks.c:2811` | `static int snd_bbfpro_ctl_get(struct snd_kcontrol *kcontrol, 			      struct snd_ctl_elem_value *...` |
| `snd_bbfpro_ctl_info` | function | `legacy/mixer_quirks.c:2834` | `static int snd_bbfpro_ctl_info(struct snd_kcontrol *kcontrol, 			       struct snd_ctl_elem_info ...` |
| `snd_bbfpro_ctl_put` | function | `legacy/mixer_quirks.c:2868` | `static int snd_bbfpro_ctl_put(struct snd_kcontrol *kcontrol, 			      struct snd_ctl_elem_value *...` |
| `snd_bbfpro_ctl_resume` | function | `legacy/mixer_quirks.c:2907` | `static int snd_bbfpro_ctl_resume(struct usb_mixer_elem_list *list)` |
| `snd_bbfpro_ctl_update` | function | `legacy/mixer_quirks.c:2780` | `static int snd_bbfpro_ctl_update(struct usb_mixer_interface *mixer, u8 reg, 				 u8 index, u8 value)` |
| `snd_bbfpro_gain_add` | function | `legacy/mixer_quirks.c:3147` | `static int snd_bbfpro_gain_add(struct usb_mixer_interface *mixer, u8 channel, 			       char *name)` |
| `snd_bbfpro_gain_get` | function | `legacy/mixer_quirks.c:2944` | `static int snd_bbfpro_gain_get(struct snd_kcontrol *kcontrol, 			       struct snd_ctl_elem_value...` |
| `snd_bbfpro_gain_info` | function | `legacy/mixer_quirks.c:2953` | `static int snd_bbfpro_gain_info(struct snd_kcontrol *kcontrol, 				struct snd_ctl_elem_info *uinfo)` |
| `snd_bbfpro_gain_put` | function | `legacy/mixer_quirks.c:2974` | `static int snd_bbfpro_gain_put(struct snd_kcontrol *kcontrol, 			       struct snd_ctl_elem_value...` |
| `snd_bbfpro_gain_resume` | function | `legacy/mixer_quirks.c:3011` | `static int snd_bbfpro_gain_resume(struct usb_mixer_elem_list *list)` |
| `snd_bbfpro_gain_update` | function | `legacy/mixer_quirks.c:2920` | `static int snd_bbfpro_gain_update(struct usb_mixer_interface *mixer, 				  u8 channel, u8 gain)` |
| `snd_bbfpro_vol_add` | function | `legacy/mixer_quirks.c:3159` | `static int snd_bbfpro_vol_add(struct usb_mixer_interface *mixer, u16 index, 			      char *name)` |
| `snd_bbfpro_vol_get` | function | `legacy/mixer_quirks.c:3050` | `static int snd_bbfpro_vol_get(struct snd_kcontrol *kcontrol, 			      struct snd_ctl_elem_value *...` |
| `snd_bbfpro_vol_info` | function | `legacy/mixer_quirks.c:3058` | `static int snd_bbfpro_vol_info(struct snd_kcontrol *kcontrol, 			       struct snd_ctl_elem_info ...` |
| `snd_bbfpro_vol_put` | function | `legacy/mixer_quirks.c:3068` | `static int snd_bbfpro_vol_put(struct snd_kcontrol *kcontrol, 			      struct snd_ctl_elem_value *...` |
| `snd_bbfpro_vol_resume` | function | `legacy/mixer_quirks.c:3096` | `static int snd_bbfpro_vol_resume(struct usb_mixer_elem_list *list)` |
| `snd_bbfpro_vol_update` | function | `legacy/mixer_quirks.c:3024` | `static int snd_bbfpro_vol_update(struct usb_mixer_interface *mixer, u16 index, 				 u32 value)` |
| `snd_c400_create_effect_duration_ctl` | function | `legacy/mixer_quirks.c:1625` | `static int snd_c400_create_effect_duration_ctl(struct usb_mixer_interface *mixer)` |
| `snd_c400_create_effect_feedback_ctl` | function | `legacy/mixer_quirks.c:1638` | `static int snd_c400_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)` |
| `snd_c400_create_effect_ret_vol_ctls` | function | `legacy/mixer_quirks.c:1695` | `static int snd_c400_create_effect_ret_vol_ctls(struct usb_mixer_interface *mixer)` |
| `snd_c400_create_effect_vol_ctls` | function | `legacy/mixer_quirks.c:1650` | `static int snd_c400_create_effect_vol_ctls(struct usb_mixer_interface *mixer)` |
| `snd_c400_create_effect_volume_ctl` | function | `legacy/mixer_quirks.c:1612` | `static int snd_c400_create_effect_volume_ctl(struct usb_mixer_interface *mixer)` |
| `snd_c400_create_mixer` | function | `legacy/mixer_quirks.c:1737` | `static int snd_c400_create_mixer(struct usb_mixer_interface *mixer)` |
| `snd_c400_create_vol_ctls` | function | `legacy/mixer_quirks.c:1563` | `static int snd_c400_create_vol_ctls(struct usb_mixer_interface *mixer)` |
| `snd_create_std_mono_ctl` | function | `legacy/mixer_quirks.c:113` | `static int snd_create_std_mono_ctl(struct usb_mixer_interface *mixer, 				   unsigned int unitid,...` |
| `snd_create_std_mono_ctl_offset` | function | `legacy/mixer_quirks.c:59` | `static int snd_create_std_mono_ctl_offset(struct usb_mixer_interface *mixer, 					  unsigned int ...` |
| `snd_create_std_mono_table` | function | `legacy/mixer_quirks.c:129` | `static int snd_create_std_mono_table(struct usb_mixer_interface *mixer, 				     const struct std...` |
| `snd_djm_controls_create` | function | `legacy/mixer_quirks.c:4204` | `static int snd_djm_controls_create(struct usb_mixer_interface *mixer, 				   const u8 device_idx)` |
| `snd_djm_controls_get` | function | `legacy/mixer_quirks.c:4170` | `static int snd_djm_controls_get(struct snd_kcontrol *kctl, 				struct snd_ctl_elem_value *elem)` |
| `snd_djm_controls_info` | function | `legacy/mixer_quirks.c:4117` | `static int snd_djm_controls_info(struct snd_kcontrol *kctl, 				 struct snd_ctl_elem_info *info)` |
| `snd_djm_controls_put` | function | `legacy/mixer_quirks.c:4177` | `static int snd_djm_controls_put(struct snd_kcontrol *kctl, struct snd_ctl_elem_value *elem)` |
| `snd_djm_controls_resume` | function | `legacy/mixer_quirks.c:4194` | `static int snd_djm_controls_resume(struct usb_mixer_elem_list *list)` |
| `snd_djm_controls_update` | function | `legacy/mixer_quirks.c:4149` | `static int snd_djm_controls_update(struct usb_mixer_interface *mixer, 				   u8 device_idx, u8 gr...` |
| `snd_djm_ctl` | struct | `legacy/mixer_quirks.c:3784` | `` |
| `snd_djm_device` | struct | `legacy/mixer_quirks.c:3778` | `` |
| `snd_djm_get_label` | function | `legacy/mixer_quirks.c:3885` | `static const char *snd_djm_get_label(u8 device_idx, u16 wvalue, u16 windex)` |
| `snd_djm_get_label_cap` | function | `legacy/mixer_quirks.c:3867` | `static const char *snd_djm_get_label_cap(u8 device_idx, u16 wvalue)` |
| `snd_djm_get_label_cap_850` | function | `legacy/mixer_quirks.c:3849` | `static const char *snd_djm_get_label_cap_850(u16 wvalue)` |
| `snd_djm_get_label_cap_common` | function | `legacy/mixer_quirks.c:3817` | `static const char *snd_djm_get_label_cap_common(u16 wvalue)` |
| `snd_djm_get_label_caplevel` | function | `legacy/mixer_quirks.c:3858` | `static const char *snd_djm_get_label_caplevel(u8 device_idx, u16 wvalue)` |
| `snd_djm_get_label_caplevel_common` | function | `legacy/mixer_quirks.c:3792` | `static const char *snd_djm_get_label_caplevel_common(u16 wvalue)` |
| `snd_djm_get_label_caplevel_high` | function | `legacy/mixer_quirks.c:3804` | `static const char *snd_djm_get_label_caplevel_high(u16 wvalue)` |
| `snd_djm_get_label_pb` | function | `legacy/mixer_quirks.c:3875` | `static const char *snd_djm_get_label_pb(u16 wvalue)` |
| `snd_dragonfly_quirk_db_scale` | function | `legacy/mixer_quirks.c:4458` | `static void snd_dragonfly_quirk_db_scale(struct usb_mixer_interface *mixer, 					 struct usb_mixe...` |
| `snd_dualsense_controls_create` | function | `legacy/mixer_quirks.c:778` | `static int snd_dualsense_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_dualsense_ih_connect` | function | `legacy/mixer_quirks.c:618` | `static int snd_dualsense_ih_connect(struct input_handler *handler, 				    struct input_dev *dev,...` |
| `snd_dualsense_ih_disconnect` | function | `legacy/mixer_quirks.c:650` | `static void snd_dualsense_ih_disconnect(struct input_handle *handle)` |
| `snd_dualsense_ih_event` | function | `legacy/mixer_quirks.c:550` | `static void snd_dualsense_ih_event(struct input_handle *handle, 				   unsigned int type, unsigne...` |
| `snd_dualsense_ih_match` | function | `legacy/mixer_quirks.c:571` | `static bool snd_dualsense_ih_match(struct input_handler *handler, 				   struct input_dev *dev)` |
| `snd_dualsense_ih_start` | function | `legacy/mixer_quirks.c:657` | `static void snd_dualsense_ih_start(struct input_handle *handle)` |
| `snd_dualsense_jack_create` | function | `legacy/mixer_quirks.c:714` | `static int snd_dualsense_jack_create(struct usb_mixer_interface *mixer, 				     const char *name...` |
| `snd_dualsense_jack_get` | function | `legacy/mixer_quirks.c:680` | `static int snd_dualsense_jack_get(struct snd_kcontrol *kctl, 				  struct snd_ctl_elem_value *uco...` |
| `snd_dualsense_mixer_elem_free` | function | `legacy/mixer_quirks.c:704` | `static void snd_dualsense_mixer_elem_free(struct snd_kcontrol *kctl)` |
| `snd_dualsense_resume_jack` | function | `legacy/mixer_quirks.c:697` | `static int snd_dualsense_resume_jack(struct usb_mixer_elem_list *list)` |
| `snd_emu0204_ch_switch_get` | function | `legacy/mixer_quirks.c:465` | `static int snd_emu0204_ch_switch_get(struct snd_kcontrol *kcontrol, 				     struct snd_ctl_elem_...` |
| `snd_emu0204_ch_switch_info` | function | `legacy/mixer_quirks.c:457` | `static int snd_emu0204_ch_switch_info(struct snd_kcontrol *kcontrol, 				      struct snd_ctl_ele...` |
| `snd_emu0204_ch_switch_put` | function | `legacy/mixer_quirks.c:490` | `static int snd_emu0204_ch_switch_put(struct snd_kcontrol *kcontrol, 				     struct snd_ctl_elem_...` |
| `snd_emu0204_ch_switch_resume` | function | `legacy/mixer_quirks.c:509` | `static int snd_emu0204_ch_switch_resume(struct usb_mixer_elem_list *list)` |
| `snd_emu0204_ch_switch_update` | function | `legacy/mixer_quirks.c:472` | `static int snd_emu0204_ch_switch_update(struct usb_mixer_interface *mixer, 					int value)` |
| `snd_emu0204_controls_create` | function | `legacy/mixer_quirks.c:524` | `static int snd_emu0204_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_emuusb_set_samplerate` | function | `legacy/mixer_quirks.c:1542` | `void snd_emuusb_set_samplerate(struct snd_usb_audio *chip, 			       unsigned char samplerate_id)` |
| `snd_fix_plt_name` | function | `legacy/mixer_quirks.c:4509` | `static void snd_fix_plt_name(struct snd_usb_audio *chip, 			     struct snd_ctl_elem_id *id)` |
| `snd_ftu_create_effect_duration_ctl` | function | `legacy/mixer_quirks.c:1425` | `static int snd_ftu_create_effect_duration_ctl(struct usb_mixer_interface *mixer)` |
| `snd_ftu_create_effect_feedback_ctl` | function | `legacy/mixer_quirks.c:1438` | `static int snd_ftu_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)` |
| `snd_ftu_create_effect_return_ctls` | function | `legacy/mixer_quirks.c:1450` | `static int snd_ftu_create_effect_return_ctls(struct usb_mixer_interface *mixer)` |
| `snd_ftu_create_effect_send_ctls` | function | `legacy/mixer_quirks.c:1474` | `static int snd_ftu_create_effect_send_ctls(struct usb_mixer_interface *mixer)` |
| `snd_ftu_create_effect_switch` | function | `legacy/mixer_quirks.c:1347` | `static int snd_ftu_create_effect_switch(struct usb_mixer_interface *mixer, 					int validx, int b...` |
| `snd_ftu_create_effect_volume_ctl` | function | `legacy/mixer_quirks.c:1412` | `static int snd_ftu_create_effect_volume_ctl(struct usb_mixer_interface *mixer)` |
| `snd_ftu_create_mixer` | function | `legacy/mixer_quirks.c:1507` | `static int snd_ftu_create_mixer(struct usb_mixer_interface *mixer)` |
| `snd_ftu_create_volume_ctls` | function | `legacy/mixer_quirks.c:1373` | `static int snd_ftu_create_volume_ctls(struct usb_mixer_interface *mixer)` |
| `snd_ftu_eff_switch_get` | function | `legacy/mixer_quirks.c:1301` | `static int snd_ftu_eff_switch_get(struct snd_kcontrol *kctl, 				  struct snd_ctl_elem_value *uco...` |
| `snd_ftu_eff_switch_info` | function | `legacy/mixer_quirks.c:1267` | `static int snd_ftu_eff_switch_info(struct snd_kcontrol *kcontrol, 				   struct snd_ctl_elem_info...` |
| `snd_ftu_eff_switch_init` | function | `legacy/mixer_quirks.c:1278` | `static int snd_ftu_eff_switch_init(struct usb_mixer_interface *mixer, 				   struct snd_kcontrol ...` |
| `snd_ftu_eff_switch_put` | function | `legacy/mixer_quirks.c:1329` | `static int snd_ftu_eff_switch_put(struct snd_kcontrol *kctl, 				  struct snd_ctl_elem_value *uco...` |
| `snd_ftu_eff_switch_update` | function | `legacy/mixer_quirks.c:1308` | `static int snd_ftu_eff_switch_update(struct usb_mixer_elem_list *list)` |
| `snd_mbox1_clk_switch_get` | function | `legacy/mixer_quirks.c:934` | `static int snd_mbox1_clk_switch_get(struct snd_kcontrol *kctl, 				    struct snd_ctl_elem_value ...` |
| `snd_mbox1_clk_switch_info` | function | `legacy/mixer_quirks.c:997` | `static int snd_mbox1_clk_switch_info(struct snd_kcontrol *kcontrol, 				     struct snd_ctl_elem_...` |
| `snd_mbox1_clk_switch_put` | function | `legacy/mixer_quirks.c:979` | `static int snd_mbox1_clk_switch_put(struct snd_kcontrol *kctl, 				    struct snd_ctl_elem_value ...` |
| `snd_mbox1_clk_switch_resume` | function | `legacy/mixer_quirks.c:1008` | `static int snd_mbox1_clk_switch_resume(struct usb_mixer_elem_list *list)` |
| `snd_mbox1_clk_switch_update` | function | `legacy/mixer_quirks.c:954` | `static int snd_mbox1_clk_switch_update(struct usb_mixer_interface *mixer, int is_spdif_sync)` |
| `snd_mbox1_controls_create` | function | `legacy/mixer_quirks.c:1102` | `static int snd_mbox1_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_mbox1_is_spdif_input` | function | `legacy/mixer_quirks.c:895` | `static int snd_mbox1_is_spdif_input(struct snd_usb_audio *chip)` |
| `snd_mbox1_is_spdif_synced` | function | `legacy/mixer_quirks.c:857` | `static int snd_mbox1_is_spdif_synced(struct snd_usb_audio *chip)` |
| `snd_mbox1_set_clk_source` | function | `legacy/mixer_quirks.c:877` | `static int snd_mbox1_set_clk_source(struct snd_usb_audio *chip, int rate_or_zero)` |
| `snd_mbox1_set_input_source` | function | `legacy/mixer_quirks.c:915` | `static int snd_mbox1_set_input_source(struct snd_usb_audio *chip, int is_spdif)` |
| `snd_mbox1_src_switch_get` | function | `legacy/mixer_quirks.c:1015` | `static int snd_mbox1_src_switch_get(struct snd_kcontrol *kctl, 				    struct snd_ctl_elem_value ...` |
| `snd_mbox1_src_switch_info` | function | `legacy/mixer_quirks.c:1064` | `static int snd_mbox1_src_switch_info(struct snd_kcontrol *kcontrol, 				     struct snd_ctl_elem_...` |
| `snd_mbox1_src_switch_put` | function | `legacy/mixer_quirks.c:1046` | `static int snd_mbox1_src_switch_put(struct snd_kcontrol *kctl, 				    struct snd_ctl_elem_value ...` |
| `snd_mbox1_src_switch_resume` | function | `legacy/mixer_quirks.c:1075` | `static int snd_mbox1_src_switch_resume(struct usb_mixer_elem_list *list)` |
| `snd_mbox1_src_switch_update` | function | `legacy/mixer_quirks.c:1022` | `static int snd_mbox1_src_switch_update(struct usb_mixer_interface *mixer, int is_spdif_input)` |
| `snd_microii_controls_create` | function | `legacy/mixer_quirks.c:2068` | `static int snd_microii_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_microii_spdif_default_get` | function | `legacy/mixer_quirks.c:1877` | `static int snd_microii_spdif_default_get(struct snd_kcontrol *kcontrol, 					 struct snd_ctl_elem...` |
| `snd_microii_spdif_default_put` | function | `legacy/mixer_quirks.c:1960` | `static int snd_microii_spdif_default_put(struct snd_kcontrol *kcontrol, 					 struct snd_ctl_elem...` |
| `snd_microii_spdif_default_update` | function | `legacy/mixer_quirks.c:1924` | `static int snd_microii_spdif_default_update(struct usb_mixer_elem_list *list)` |
| `snd_microii_spdif_info` | function | `legacy/mixer_quirks.c:1869` | `static int snd_microii_spdif_info(struct snd_kcontrol *kcontrol, 				  struct snd_ctl_elem_info *...` |
| `snd_microii_spdif_mask_get` | function | `legacy/mixer_quirks.c:1988` | `static int snd_microii_spdif_mask_get(struct snd_kcontrol *kcontrol, 				      struct snd_ctl_ele...` |
| `snd_microii_spdif_switch_get` | function | `legacy/mixer_quirks.c:1999` | `static int snd_microii_spdif_switch_get(struct snd_kcontrol *kcontrol, 					struct snd_ctl_elem_v...` |
| `snd_microii_spdif_switch_put` | function | `legacy/mixer_quirks.c:2026` | `static int snd_microii_spdif_switch_put(struct snd_kcontrol *kcontrol, 					struct snd_ctl_elem_v...` |
| `snd_microii_spdif_switch_update` | function | `legacy/mixer_quirks.c:2007` | `static int snd_microii_spdif_switch_update(struct usb_mixer_elem_list *list)` |
| `snd_nativeinstruments_control_get` | function | `legacy/mixer_quirks.c:1143` | `static int snd_nativeinstruments_control_get(struct snd_kcontrol *kcontrol, 					     struct snd_...` |
| `snd_nativeinstruments_control_put` | function | `legacy/mixer_quirks.c:1164` | `static int snd_nativeinstruments_control_put(struct snd_kcontrol *kcontrol, 					     struct snd_...` |
| `snd_nativeinstruments_create_mixer` | function | `legacy/mixer_quirks.c:1235` | `static int snd_nativeinstruments_create_mixer(struct usb_mixer_interface *mixer, 					      const...` |
| `snd_ni_control_init_val` | function | `legacy/mixer_quirks.c:1121` | `static int snd_ni_control_init_val(struct usb_mixer_interface *mixer, 				   struct snd_kcontrol ...` |
| `snd_ni_update_cur_val` | function | `legacy/mixer_quirks.c:1150` | `static int snd_ni_update_cur_val(struct usb_mixer_elem_list *list)` |
| `snd_rme_clock_status` | enum | `legacy/mixer_quirks.c:2413` | `` |
| `snd_rme_controls_create` | function | `legacy/mixer_quirks.c:2714` | `static int snd_rme_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_rme_current_freq_get` | function | `legacy/mixer_quirks.c:2553` | `static int snd_rme_current_freq_get(struct snd_kcontrol *kcontrol, 				    struct snd_ctl_elem_va...` |
| `snd_rme_digiface_controls_create` | function | `legacy/mixer_quirks.c:3685` | `static int snd_rme_digiface_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_rme_digiface_current_sync_get` | function | `legacy/mixer_quirks.c:3439` | `static int snd_rme_digiface_current_sync_get(struct snd_kcontrol *kcontrol, 					     struct snd_...` |
| `snd_rme_digiface_enum_get` | function | `legacy/mixer_quirks.c:3413` | `static int snd_rme_digiface_enum_get(struct snd_kcontrol *kcontrol, 				     struct snd_ctl_elem_...` |
| `snd_rme_digiface_enum_put` | function | `legacy/mixer_quirks.c:3425` | `static int snd_rme_digiface_enum_put(struct snd_kcontrol *kcontrol, 				     struct snd_ctl_elem_...` |
| `snd_rme_digiface_format_info` | function | `legacy/mixer_quirks.c:3474` | `static int snd_rme_digiface_format_info(struct snd_kcontrol *kcontrol, 					struct snd_ctl_elem_i...` |
| `snd_rme_digiface_get_status_val` | function | `legacy/mixer_quirks.c:3361` | `static int snd_rme_digiface_get_status_val(struct snd_kcontrol *kcontrol)` |
| `snd_rme_digiface_rate_get` | function | `legacy/mixer_quirks.c:3399` | `static int snd_rme_digiface_rate_get(struct snd_kcontrol *kcontrol, 				     struct snd_ctl_elem_...` |
| `snd_rme_digiface_rate_info` | function | `legacy/mixer_quirks.c:3496` | `static int snd_rme_digiface_rate_info(struct snd_kcontrol *kcontrol, 				      struct snd_ctl_ele...` |
| `snd_rme_digiface_read_status` | function | `legacy/mixer_quirks.c:3337` | `static int snd_rme_digiface_read_status(struct snd_kcontrol *kcontrol, u32 status[4])` |
| `snd_rme_digiface_sync_source_info` | function | `legacy/mixer_quirks.c:3485` | `static int snd_rme_digiface_sync_source_info(struct snd_kcontrol *kcontrol, 					     struct snd_...` |
| `snd_rme_digiface_sync_state_get` | function | `legacy/mixer_quirks.c:3451` | `static int snd_rme_digiface_sync_state_get(struct snd_kcontrol *kcontrol, 					   struct snd_ctl_...` |
| `snd_rme_digiface_write_reg` | function | `legacy/mixer_quirks.c:3319` | `static int snd_rme_digiface_write_reg(struct snd_kcontrol *kcontrol, int item, u16 mask, u16 val)` |
| `snd_rme_domain` | enum | `legacy/mixer_quirks.c:2407` | `` |
| `snd_rme_get_status1` | function | `legacy/mixer_quirks.c:2438` | `static int snd_rme_get_status1(struct snd_kcontrol *kcontrol, 			       u32 *status1)` |
| `snd_rme_rate_get` | function | `legacy/mixer_quirks.c:2450` | `static int snd_rme_rate_get(struct snd_kcontrol *kcontrol, 			    struct snd_ctl_elem_value *ucon...` |
| `snd_rme_rate_info` | function | `legacy/mixer_quirks.c:2579` | `static int snd_rme_rate_info(struct snd_kcontrol *kcontrol, 			     struct snd_ctl_elem_info *uinfo)` |
| `snd_rme_read_value` | function | `legacy/mixer_quirks.c:2419` | `static int snd_rme_read_value(struct snd_usb_audio *chip, 			      unsigned int item, 			      u3...` |
| `snd_rme_spdif_format_get` | function | `legacy/mixer_quirks.c:2527` | `static int snd_rme_spdif_format_get(struct snd_kcontrol *kcontrol, 				    struct snd_ctl_elem_va...` |
| `snd_rme_spdif_format_info` | function | `legacy/mixer_quirks.c:2621` | `static int snd_rme_spdif_format_info(struct snd_kcontrol *kcontrol, 				     struct snd_ctl_elem_...` |
| `snd_rme_spdif_if_get` | function | `legacy/mixer_quirks.c:2514` | `static int snd_rme_spdif_if_get(struct snd_kcontrol *kcontrol, 				struct snd_ctl_elem_value *uco...` |
| `snd_rme_spdif_if_info` | function | `legacy/mixer_quirks.c:2610` | `static int snd_rme_spdif_if_info(struct snd_kcontrol *kcontrol, 				 struct snd_ctl_elem_info *ui...` |
| `snd_rme_sync_source_get` | function | `legacy/mixer_quirks.c:2540` | `static int snd_rme_sync_source_get(struct snd_kcontrol *kcontrol, 				   struct snd_ctl_elem_valu...` |
| `snd_rme_sync_source_info` | function | `legacy/mixer_quirks.c:2632` | `static int snd_rme_sync_source_info(struct snd_kcontrol *kcontrol, 				    struct snd_ctl_elem_in...` |
| `snd_rme_sync_state_get` | function | `legacy/mixer_quirks.c:2484` | `static int snd_rme_sync_state_get(struct snd_kcontrol *kcontrol, 				  struct snd_ctl_elem_value ...` |
| `snd_rme_sync_state_info` | function | `legacy/mixer_quirks.c:2599` | `static int snd_rme_sync_state_info(struct snd_kcontrol *kcontrol, 				   struct snd_ctl_elem_info...` |
| `snd_soundblaster_e1_switch_create` | function | `legacy/mixer_quirks.c:2155` | `static int snd_soundblaster_e1_switch_create(struct usb_mixer_interface *mixer)` |
| `snd_soundblaster_e1_switch_get` | function | `legacy/mixer_quirks.c:2091` | `static int snd_soundblaster_e1_switch_get(struct snd_kcontrol *kcontrol, 					  struct snd_ctl_el...` |
| `snd_soundblaster_e1_switch_info` | function | `legacy/mixer_quirks.c:2136` | `static int snd_soundblaster_e1_switch_info(struct snd_kcontrol *kcontrol, 					   struct snd_ctl_...` |
| `snd_soundblaster_e1_switch_put` | function | `legacy/mixer_quirks.c:2116` | `static int snd_soundblaster_e1_switch_put(struct snd_kcontrol *kcontrol, 					  struct snd_ctl_el...` |
| `snd_soundblaster_e1_switch_resume` | function | `legacy/mixer_quirks.c:2130` | `static int snd_soundblaster_e1_switch_resume(struct usb_mixer_elem_list *list)` |
| `snd_soundblaster_e1_switch_update` | function | `legacy/mixer_quirks.c:2098` | `static int snd_soundblaster_e1_switch_update(struct usb_mixer_interface *mixer, 					     unsigne...` |
| `snd_usb_mixer_apply_create_quirk` | function | `legacy/mixer_quirks.c:4239` | `int snd_usb_mixer_apply_create_quirk(struct usb_mixer_interface *mixer)` |
| `snd_usb_mixer_fu_apply_quirk` | function | `legacy/mixer_quirks.c:4539` | `void snd_usb_mixer_fu_apply_quirk(struct usb_mixer_interface *mixer, 				  struct usb_mixer_elem_...` |
| `snd_usb_mixer_rc_memory_change` | function | `legacy/mixer_quirks.c:4430` | `void snd_usb_mixer_rc_memory_change(struct usb_mixer_interface *mixer, 				    int unitid)` |
| `snd_usb_mixer_resume_quirk` | function | `legacy/mixer_quirks.c:4421` | `void snd_usb_mixer_resume_quirk(struct usb_mixer_interface *mixer)` |
| `snd_usb_sbrc_hwdep_poll` | function | `legacy/mixer_quirks.c:240` | `static __poll_t snd_usb_sbrc_hwdep_poll(struct snd_hwdep *hw, struct file *file, 					poll_table ...` |
| `snd_usb_sbrc_hwdep_read` | function | `legacy/mixer_quirks.c:220` | `static long snd_usb_sbrc_hwdep_read(struct snd_hwdep *hw, char __user *buf, 				    long count, l...` |
| `snd_usb_soundblaster_remote_complete` | function | `legacy/mixer_quirks.c:200` | `static void snd_usb_soundblaster_remote_complete(struct urb *urb)` |
| `snd_usb_soundblaster_remote_init` | function | `legacy/mixer_quirks.c:249` | `static int snd_usb_soundblaster_remote_init(struct usb_mixer_interface *mixer)` |
| `snd_xonar_u1_controls_create` | function | `legacy/mixer_quirks.c:848` | `static int snd_xonar_u1_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_xonar_u1_switch_get` | function | `legacy/mixer_quirks.c:792` | `static int snd_xonar_u1_switch_get(struct snd_kcontrol *kcontrol, 				   struct snd_ctl_elem_valu...` |
| `snd_xonar_u1_switch_put` | function | `legacy/mixer_quirks.c:813` | `static int snd_xonar_u1_switch_put(struct snd_kcontrol *kcontrol, 				   struct snd_ctl_elem_valu...` |
| `snd_xonar_u1_switch_resume` | function | `legacy/mixer_quirks.c:833` | `static int snd_xonar_u1_switch_resume(struct usb_mixer_elem_list *list)` |
| `snd_xonar_u1_switch_update` | function | `legacy/mixer_quirks.c:799` | `static int snd_xonar_u1_switch_update(struct usb_mixer_interface *mixer, 				      unsigned char ...` |
| `std_mono_table` | struct | `legacy/mixer_quirks.c:45` | `` |
| `main` | function | `legacy/test_connection.c:7` | `int main()` |
| `VSL_CONFIG_H` | macro | `legacy/vsl_config.h:4` | `#define VSL_CONFIG_H` |
| `VSL_MAX_ENCODED_INT` | macro | `legacy/vsl_config.h:23` | `#define VSL_MAX_ENCODED_INT` |
| `VSL_PACKET_SIZE` | macro | `legacy/vsl_config.h:25` | `#define VSL_PACKET_SIZE` |
| `VSL_PAYLOAD_SIZE` | macro | `legacy/vsl_config.h:26` | `#define VSL_PAYLOAD_SIZE` |
| `VSL_PRODUCT_ID` | macro | `legacy/vsl_config.h:12` | `#define VSL_PRODUCT_ID` |
| `VSL_REPORT_ID` | macro | `legacy/vsl_config.h:13` | `#define VSL_REPORT_ID` |
| `VSL_SCALE_FACTOR` | macro | `legacy/vsl_config.h:20` | `#define VSL_SCALE_FACTOR` |
| `VSL_VENDOR_ID` | macro | `legacy/vsl_config.h:11` | `#define VSL_VENDOR_ID` |
| `VSLParameter` | class | `legacy/vsl_config.py:40` | `class VSLParameter(NamedTuple)` |
| `print_configuration_status` | method | `legacy/vsl_config.py:116` | `def print_configuration_status()` |
| `validate_configuration` | method | `legacy/vsl_config.py:92` | `def validate_configuration()` |
| `validate_parameter` | function | `legacy/vsl_core.py:170` | `def validate_parameter(param)` |
| `vsl_decode_frequency` | function | `legacy/vsl_core.py:127` | `def vsl_decode_frequency(freq_hz_value, param)` |
| `vsl_encode_gain` | function | `legacy/vsl_core.py:16` | `def vsl_encode_gain(linear_value, param)` |
| `vsl_final_encode_to_int` | function | `legacy/vsl_core.py:94` | `def vsl_final_encode_to_int(encoded_float, param)` |
| `vsl_map_frequency` | function | `legacy/vsl_core.py:58` | `def vsl_map_frequency(linear_position, param)` |
| `VSL_Build_And_Send_Packet` | function | `legacy/vsl_dsp_logic.c:4` | `void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float);` |
| `VSL_Decode_Frequency` | function | `legacy/vsl_dsp_logic.c:78` | `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)` |
| `VSL_Encode_Gain` | function | `legacy/vsl_dsp_logic.c:11` | `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)` |
| `VSL_Final_Encode_To_Int` | function | `legacy/vsl_dsp_logic.c:58` | `uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)` |
| `VSL_Map_Frequency` | function | `legacy/vsl_dsp_logic.c:29` | `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)` |
| `VSL_DSP_LOGIC_H` | macro | `legacy/vsl_dsp_logic.h:2` | `#define VSL_DSP_LOGIC_H` |
| `VSL_Decode_Frequency` | function | `legacy/vsl_dsp_logic.h:73` | `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);` |
| `VSL_Encode_Gain` | function | `legacy/vsl_dsp_logic.h:42` | `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);` |
| `VSL_Final_Encode_To_Int` | function | `legacy/vsl_dsp_logic.h:60` | `uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param);` |
| `VSL_INV_LN2` | macro | `legacy/vsl_dsp_logic.h:10` | `#define VSL_INV_LN2` |
| `VSL_Map_Frequency` | function | `legacy/vsl_dsp_logic.h:50` | `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);` |
| `VSL_Parameter` | struct | `legacy/vsl_dsp_logic.h:13` | `` |
| `FUN_Send_Packet` | function | `legacy/vsl_dsp_transport.c:97` | `void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length)` |
| `VSL_Build_And_Send_Packet` | function | `legacy/vsl_dsp_transport.c:140` | `void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float)` |
| `VSL_Close_Device` | function | `legacy/vsl_dsp_transport.c:70` | `void VSL_Close_Device(void)` |
| `VSL_Get_Device_Handle` | function | `legacy/vsl_dsp_transport.c:79` | `hid_device* VSL_Get_Device_Handle(void)` |
| `VSL_Init_Device` | function | `legacy/vsl_dsp_transport.c:23` | `int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)` |
| `FUN_Send_Packet` | function | `legacy/vsl_dsp_transport.h:24` | `void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length);` |
| `VSL_Build_And_Send_Packet` | function | `legacy/vsl_dsp_transport.h:25` | `void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float);` |
| `VSL_Close_Device` | function | `legacy/vsl_dsp_transport.h:20` | `void VSL_Close_Device(void);` |
| `VSL_DSP_Packet` | struct | `legacy/vsl_dsp_transport.h:12` | `` |
| `VSL_DSP_TRANSPORT_H` | macro | `legacy/vsl_dsp_transport.h:4` | `#define VSL_DSP_TRANSPORT_H` |
| `VSL_Get_Device_Handle` | function | `legacy/vsl_dsp_transport.h:21` | `hid_device* VSL_Get_Device_Handle(void);` |
| `VSL_Init_Device` | function | `legacy/vsl_dsp_transport.h:19` | `int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id);` |
| `VSLDevice` | class | `legacy/vsl_hid_io.py:31` | `class VSLDevice` |
| `__enter__` | method | `legacy/vsl_hid_io.py:139` | `def __enter__(self)` |
| `__exit__` | method | `legacy/vsl_hid_io.py:144` | `def __exit__(self, exc_type, exc_val, exc_tb)` |
| `__init__` | method | `legacy/vsl_hid_io.py:45` | `def __init__(self)` |
| `__new__` | method | `legacy/vsl_hid_io.py:39` | `def __new__(cls)` |
| `close` | method | `legacy/vsl_hid_io.py:90` | `def close(self)` |
| `enumerate_vsl_devices` | method | `legacy/vsl_hid_io.py:149` | `def enumerate_vsl_devices()` |
| `open` | method | `legacy/vsl_hid_io.py:59` | `def open(self)` |
| `send_packet` | method | `legacy/vsl_hid_io.py:101` | `def send_packet(self, packet)` |
| `main` | function | `legacy/vsl_poc_main.py:266` | `def main()` |
| `print_summary` | function | `legacy/vsl_poc_main.py:229` | `def print_summary()` |
| `run_full_workflow` | function | `legacy/vsl_poc_main.py:197` | `def run_full_workflow()` |
| `test_edge_cases` | function | `legacy/vsl_poc_main.py:150` | `def test_edge_cases()` |
| `test_frequency_mapping` | function | `legacy/vsl_poc_main.py:72` | `def test_frequency_mapping()` |
| `test_gain_encoding` | function | `legacy/vsl_poc_main.py:43` | `def test_gain_encoding()` |
| `test_packet_construction` | function | `legacy/vsl_poc_main.py:92` | `def test_packet_construction()` |
| `VSLParameter` | class | `legacy/vsl_protocol_analyzer.py:28` | `class VSLParameter` |
| `__init__` | method | `legacy/vsl_protocol_analyzer.py:30` | `def __init__(self, dsp_id, name, type_unit, min_map, max_map, coeff_A, coeff_C1, log_factor)` |
| `analyze_pcap` | method | `legacy/vsl_protocol_analyzer.py:173` | `def analyze_pcap(pcap_file)` |
| `decode_vsl_packet` | method | `legacy/vsl_protocol_analyzer.py:140` | `def decode_vsl_packet(data)` |
| `get_decoded_value` | method | `legacy/vsl_protocol_analyzer.py:115` | `def get_decoded_value(encoded_value, param_id)` |
| `reverse_map_frequency` | method | `legacy/vsl_protocol_analyzer.py:95` | `def reverse_map_frequency(encoded_value, param)` |
| `reverse_map_gain` | method | `legacy/vsl_protocol_analyzer.py:67` | `def reverse_map_gain(encoded_value, param)` |
| `VSLPacket` | class | `legacy/vsl_transport.py:15` | `class VSLPacket` |
| `__init__` | method | `legacy/vsl_transport.py:21` | `def __init__(self, param_id, encoded_value, report_id)` |
| `__repr__` | method | `legacy/vsl_transport.py:133` | `def __repr__(self)` |
| `_build_buffer` | method | `legacy/vsl_transport.py:58` | `def _build_buffer(self)` |
| `buffer` | method | `legacy/vsl_transport.py:89` | `def buffer(self)` |
| `build_packet_safe` | method | `legacy/vsl_transport.py:141` | `def build_packet_safe(param, encoded_value)` |
| `hex_dump` | method | `legacy/vsl_transport.py:93` | `def hex_dump(self, num_bytes)` |
| `validate` | method | `legacy/vsl_transport.py:106` | `def validate(self)` |
| `MAX_CHANNELS` | macro | `src/vsl_cli.c:49` | `#define MAX_CHANNELS` |
| `ParamEntry` | struct | `src/vsl_cli.c:16` | `` |
| `do_send` | function | `src/vsl_cli.c:134` | `static int do_send(uint16_t product_id,                    uint16_t param_id,                    ...` |
| `do_send_freq` | function | `src/vsl_cli.c:172` | `static int do_send_freq(uint16_t product_id,                         uint16_t param_id,          ...` |
| `find_entry_by_name` | function | `src/vsl_cli.c:125` | `static const ParamEntry * find_entry_by_name(const char *name)` |
| `lookup_coeffs_by_param_id` | function | `src/vsl_cli.c:115` | `static const VSL_Parameter * lookup_coeffs_by_param_id(uint16_t param_id)` |
| `main` | function | `src/vsl_cli.c:209` | `int main(int argc, char *argv[])` |
| `print_list` | function | `src/vsl_cli.c:95` | `static void print_list(uint16_t product_id)` |
| `print_usage` | function | `src/vsl_cli.c:61` | `static void print_usage(FILE *fp, const char *prog)` |
| `print_version` | function | `src/vsl_cli.c:88` | `static void print_version(void)` |
| `VSL_CONFIG_H` | macro | `src/vsl_config.h:2` | `#define VSL_CONFIG_H` |
| `VSL_EP_MIDI_OUT` | macro | `src/vsl_config.h:19` | `#define VSL_EP_MIDI_OUT` |
| `VSL_MIDI_IFACE` | macro | `src/vsl_config.h:18` | `#define VSL_MIDI_IFACE` |
| `VSL_ModelInfo` | struct | `src/vsl_config.h:22` | `` |
| `VSL_ModelLookup` | function | `src/vsl_config.h:38` | `static inline const VSL_ModelInfo * VSL_ModelLookup(uint16_t pid)` |
| `VSL_ModelLookupByTag` | function | `src/vsl_config.h:50` | `static inline const VSL_ModelInfo * VSL_ModelLookupByTag(const char *tag)` |
| `VSL_PACKET_SIZE` | macro | `src/vsl_config.h:17` | `#define VSL_PACKET_SIZE` |
| `VSL_PRODUCT_ID_1818VSL` | macro | `src/vsl_config.h:14` | `#define VSL_PRODUCT_ID_1818VSL` |
| `VSL_PRODUCT_ID_22VSL` | macro | `src/vsl_config.h:12` | `#define VSL_PRODUCT_ID_22VSL` |
| `VSL_PRODUCT_ID_44VSL` | macro | `src/vsl_config.h:13` | `#define VSL_PRODUCT_ID_44VSL` |
| `VSL_REPORT_ID` | macro | `src/vsl_config.h:16` | `#define VSL_REPORT_ID` |
| `VSL_USB_TIMEOUT_MS` | macro | `src/vsl_config.h:20` | `#define VSL_USB_TIMEOUT_MS` |
| `VSL_VENDOR_ID` | macro | `src/vsl_config.h:11` | `#define VSL_VENDOR_ID` |
| `pid` | variable | `src/vsl_config.h:8` | `extern "C" { #endif #define VSL_VENDOR_ID 0x194fU #define VSL_PRODUCT_ID_22VSL 0x0101U #define VSL_PRODUCT_ID_44VSL...` |
| `VSL_DB_To_Linear` | function | `src/vsl_dsp_logic.c:105` | `float VSL_DB_To_Linear(float db_value)` |
| `VSL_Decode_Frequency` | function | `src/vsl_dsp_logic.c:76` | `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)` |
| `VSL_Decode_Gain` | function | `src/vsl_dsp_logic.c:16` | `float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param)` |
| `VSL_Encode_Gain` | function | `src/vsl_dsp_logic.c:3` | `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)` |
| `VSL_Final_Encode_To_Int` | function | `src/vsl_dsp_logic.c:66` | `uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)` |
| `VSL_Linear_To_DB` | function | `src/vsl_dsp_logic.c:95` | `float VSL_Linear_To_DB(float linear_value)` |
| `VSL_Map_Frequency` | function | `src/vsl_dsp_logic.c:50` | `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)` |
| `VSL_DB_FLOOR_LINEAR` | macro | `src/vsl_dsp_logic.h:20` | `#define VSL_DB_FLOOR_LINEAR` |
| `VSL_DB_NEG_INF` | macro | `src/vsl_dsp_logic.h:19` | `#define VSL_DB_NEG_INF` |
| `VSL_DB_To_Linear` | function | `src/vsl_dsp_logic.h:97` | `float VSL_DB_To_Linear(float db_value);` |
| `VSL_DSP_LOGIC_H` | macro | `src/vsl_dsp_logic.h:2` | `#define VSL_DSP_LOGIC_H` |
| `VSL_Decode_Frequency` | function | `src/vsl_dsp_logic.h:71` | `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);` |
| `VSL_Decode_Gain` | function | `src/vsl_dsp_logic.h:53` | `float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param);` |

Next: [SYMBOLS_p2.md](SYMBOLS_p2.md)
