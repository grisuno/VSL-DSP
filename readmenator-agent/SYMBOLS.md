# Symbols

| Symbol | Kind | File:Line | Signature |
|--------|------|-----------|-----------|
| `AUDIOBOX_DRIVER_DESC` | macro | `audiobox_vsl.c:26` | `#define AUDIOBOX_DRIVER_DESC` |
| `AUDIOBOX_DRIVER_LIC` | macro | `audiobox_vsl.c:27` | `#define AUDIOBOX_DRIVER_LIC` |
| `AUDIOBOX_DRIVER_NAME` | macro | `audiobox_vsl.c:25` | `#define AUDIOBOX_DRIVER_NAME` |
| `audiobox_disconnect` | function | `audiobox_vsl.c:59` | `static void audiobox_disconnect(struct usb_interface *intf)` |
| `audiobox_probe` | function | `audiobox_vsl.c:37` | `static int audiobox_probe(struct usb_interface *intf,
                          const struct usb_...` |
| `AUDIOBOX_VENDOR_ID` | macro | `audiobox_vsl.h:32` | `#define AUDIOBOX_VENDOR_ID` |
| `AUDIOBOX_VSL_H` | macro | `audiobox_vsl.h:21` | `#define AUDIOBOX_VSL_H` |
| `audiobox_lookup_model` | function | `audiobox_vsl.h:96` | `static inline const audiobox_model_info_t *
audiobox_lookup_model(uint16_t pid)` |
| `audiobox_model_info_t` | struct | `audiobox_vsl.h:53` | `` |
| `audiobox_model_pid_t` | variable | `audiobox_vsl.h:26` | `extern "C" { #endif /** * @brief PreSonus USB vendor ID shared by every AudioBox VSL model. */ #define AUDIOBOX_VENDOR_I` |
| `snd_audiobox_vsl_init` | function | `audiobox_vsl.h:122` | `int snd_audiobox_vsl_init(struct usb_mixer_interface *mixer);` |
| `usb_mixer_interface` | struct | `audiobox_vsl.h:113` | `` |
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
| `DECLARE_TLV_DB_RANGE` | function | `legacy/mixer_quirks.c:4465` | `static const DECLARE_TLV_DB_RANGE(scale, 0, 1, TLV_DB_MINMAX_ITEM(-5300, -4970), 2, 5, TLV_DB_MINMAX_ITEM(-4710, -4160),` |
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
| `add_single_ctl_with_resume` | function | `legacy/mixer_quirks.c:146` | `static int add_single_ctl_with_resume(struct usb_mixer_interface *mixer,
				      int id,
				  ...` |
| `dell_dock_init_vol` | function | `legacy/mixer_quirks.c:2339` | `static void dell_dock_init_vol(struct usb_mixer_interface *mixer, int ch, int id)` |
| `dell_dock_mixer_create` | function | `legacy/mixer_quirks.c:2307` | `static int dell_dock_mixer_create(struct usb_mixer_interface *mixer)` |
| `dell_dock_mixer_init` | function | `legacy/mixer_quirks.c:2351` | `static int dell_dock_mixer_init(struct usb_mixer_interface *mixer)` |
| `dualsense_mixer_elem_info` | struct | `legacy/mixer_quirks.c:543` | `` |
| `field_get` | macro | `legacy/mixer_quirks.c:3316` | `#define field_get(_mask, _reg)` |
| `field_prep` | macro | `legacy/mixer_quirks.c:3317` | `#define field_prep(_mask, _val)` |
| `list_for_each_entry` | function | `legacy/mixer_quirks.c:1549` | `list_for_each_entry(mixer, &chip->mixer_list, list)` |
| `rc_config` | struct | `legacy/mixer_quirks.c:181` | `` |
| `realtek_add_jack` | function | `legacy/mixer_quirks.c:2280` | `static int realtek_add_jack(struct usb_mixer_interface *mixer,
			    char *name, u32 val)` |
| `realtek_ctl_connector_get` | function | `legacy/mixer_quirks.c:2223` | `static int realtek_ctl_connector_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...` |
| `realtek_hda_get` | function | `legacy/mixer_quirks.c:2202` | `static int realtek_hda_get(struct snd_usb_audio *chip, u32 cmd, u32 *value)` |
| `realtek_hda_set` | function | `legacy/mixer_quirks.c:2192` | `static int realtek_hda_set(struct snd_usb_audio *chip, u32 cmd)` |
| `realtek_resume_jack` | function | `legacy/mixer_quirks.c:2273` | `static int realtek_resume_jack(struct usb_mixer_elem_list *list)` |
| `sb_jack` | struct | `legacy/mixer_quirks.c:410` | `` |
| `snd_audigy2nx_controls_create` | function | `legacy/mixer_quirks.c:375` | `static int snd_audigy2nx_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_audigy2nx_led_get` | function | `legacy/mixer_quirks.c:299` | `static int snd_audigy2nx_led_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)` |
| `snd_audigy2nx_led_info` | macro | `legacy/mixer_quirks.c:297` | `#define snd_audigy2nx_led_info` |
| `snd_audigy2nx_led_put` | function | `legacy/mixer_quirks.c:334` | `static int snd_audigy2nx_led_put(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_value *u...` |
| `snd_audigy2nx_led_resume` | function | `legacy/mixer_quirks.c:353` | `static int snd_audigy2nx_led_resume(struct usb_mixer_elem_list *list)` |
| `snd_audigy2nx_led_update` | function | `legacy/mixer_quirks.c:305` | `static int snd_audigy2nx_led_update(struct usb_mixer_interface *mixer,
				    int value, int index)` |
| `snd_audigy2nx_proc_read` | function | `legacy/mixer_quirks.c:407` | `static void snd_audigy2nx_proc_read(struct snd_info_entry *entry,
				    struct snd_info_buffer ...` |
| `snd_bbfpro_controls_create` | function | `legacy/mixer_quirks.c:3171` | `static int snd_bbfpro_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_bbfpro_ctl_add` | function | `legacy/mixer_quirks.c:3133` | `static int snd_bbfpro_ctl_add(struct usb_mixer_interface *mixer, u8 reg,
			      u8 index, char ...` |
| `snd_bbfpro_ctl_get` | function | `legacy/mixer_quirks.c:2811` | `static int snd_bbfpro_ctl_get(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...` |
| `snd_bbfpro_ctl_info` | function | `legacy/mixer_quirks.c:2834` | `static int snd_bbfpro_ctl_info(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_info ...` |
| `snd_bbfpro_ctl_put` | function | `legacy/mixer_quirks.c:2868` | `static int snd_bbfpro_ctl_put(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...` |
| `snd_bbfpro_ctl_resume` | function | `legacy/mixer_quirks.c:2907` | `static int snd_bbfpro_ctl_resume(struct usb_mixer_elem_list *list)` |
| `snd_bbfpro_ctl_update` | function | `legacy/mixer_quirks.c:2780` | `static int snd_bbfpro_ctl_update(struct usb_mixer_interface *mixer, u8 reg,
				 u8 index, u8 value)` |
| `snd_bbfpro_gain_add` | function | `legacy/mixer_quirks.c:3147` | `static int snd_bbfpro_gain_add(struct usb_mixer_interface *mixer, u8 channel,
			       char *name)` |
| `snd_bbfpro_gain_get` | function | `legacy/mixer_quirks.c:2944` | `static int snd_bbfpro_gain_get(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_value...` |
| `snd_bbfpro_gain_info` | function | `legacy/mixer_quirks.c:2953` | `static int snd_bbfpro_gain_info(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_info *uinfo)` |
| `snd_bbfpro_gain_put` | function | `legacy/mixer_quirks.c:2974` | `static int snd_bbfpro_gain_put(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_value...` |
| `snd_bbfpro_gain_resume` | function | `legacy/mixer_quirks.c:3011` | `static int snd_bbfpro_gain_resume(struct usb_mixer_elem_list *list)` |
| `snd_bbfpro_gain_update` | function | `legacy/mixer_quirks.c:2920` | `static int snd_bbfpro_gain_update(struct usb_mixer_interface *mixer,
				  u8 channel, u8 gain)` |
| `snd_bbfpro_vol_add` | function | `legacy/mixer_quirks.c:3159` | `static int snd_bbfpro_vol_add(struct usb_mixer_interface *mixer, u16 index,
			      char *name)` |
| `snd_bbfpro_vol_get` | function | `legacy/mixer_quirks.c:3050` | `static int snd_bbfpro_vol_get(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...` |
| `snd_bbfpro_vol_info` | function | `legacy/mixer_quirks.c:3058` | `static int snd_bbfpro_vol_info(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_info ...` |
| `snd_bbfpro_vol_put` | function | `legacy/mixer_quirks.c:3068` | `static int snd_bbfpro_vol_put(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...` |
| `snd_bbfpro_vol_resume` | function | `legacy/mixer_quirks.c:3096` | `static int snd_bbfpro_vol_resume(struct usb_mixer_elem_list *list)` |
| `snd_bbfpro_vol_update` | function | `legacy/mixer_quirks.c:3024` | `static int snd_bbfpro_vol_update(struct usb_mixer_interface *mixer, u16 index,
				 u32 value)` |
| `snd_c400_create_effect_duration_ctl` | function | `legacy/mixer_quirks.c:1625` | `static int snd_c400_create_effect_duration_ctl(struct usb_mixer_interface *mixer)` |
| `snd_c400_create_effect_feedback_ctl` | function | `legacy/mixer_quirks.c:1638` | `static int snd_c400_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)` |
| `snd_c400_create_effect_ret_vol_ctls` | function | `legacy/mixer_quirks.c:1695` | `static int snd_c400_create_effect_ret_vol_ctls(struct usb_mixer_interface *mixer)` |
| `snd_c400_create_effect_vol_ctls` | function | `legacy/mixer_quirks.c:1650` | `static int snd_c400_create_effect_vol_ctls(struct usb_mixer_interface *mixer)` |
| `snd_c400_create_effect_volume_ctl` | function | `legacy/mixer_quirks.c:1612` | `static int snd_c400_create_effect_volume_ctl(struct usb_mixer_interface *mixer)` |
| `snd_c400_create_mixer` | function | `legacy/mixer_quirks.c:1737` | `static int snd_c400_create_mixer(struct usb_mixer_interface *mixer)` |
| `snd_c400_create_vol_ctls` | function | `legacy/mixer_quirks.c:1563` | `static int snd_c400_create_vol_ctls(struct usb_mixer_interface *mixer)` |
| `snd_create_std_mono_ctl` | function | `legacy/mixer_quirks.c:113` | `static int snd_create_std_mono_ctl(struct usb_mixer_interface *mixer,
				   unsigned int unitid,...` |
| `snd_create_std_mono_ctl_offset` | function | `legacy/mixer_quirks.c:59` | `static int snd_create_std_mono_ctl_offset(struct usb_mixer_interface *mixer,
					  unsigned int ...` |
| `snd_create_std_mono_table` | function | `legacy/mixer_quirks.c:129` | `static int snd_create_std_mono_table(struct usb_mixer_interface *mixer,
				     const struct std...` |
| `snd_djm_controls_create` | function | `legacy/mixer_quirks.c:4204` | `static int snd_djm_controls_create(struct usb_mixer_interface *mixer,
				   const u8 device_idx)` |
| `snd_djm_controls_get` | function | `legacy/mixer_quirks.c:4170` | `static int snd_djm_controls_get(struct snd_kcontrol *kctl,
				struct snd_ctl_elem_value *elem)` |
| `snd_djm_controls_info` | function | `legacy/mixer_quirks.c:4117` | `static int snd_djm_controls_info(struct snd_kcontrol *kctl,
				 struct snd_ctl_elem_info *info)` |
| `snd_djm_controls_put` | function | `legacy/mixer_quirks.c:4177` | `static int snd_djm_controls_put(struct snd_kcontrol *kctl, struct snd_ctl_elem_value *elem)` |
| `snd_djm_controls_resume` | function | `legacy/mixer_quirks.c:4194` | `static int snd_djm_controls_resume(struct usb_mixer_elem_list *list)` |
| `snd_djm_controls_update` | function | `legacy/mixer_quirks.c:4149` | `static int snd_djm_controls_update(struct usb_mixer_interface *mixer,
				   u8 device_idx, u8 gr...` |
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
| `snd_dragonfly_quirk_db_scale` | function | `legacy/mixer_quirks.c:4458` | `static void snd_dragonfly_quirk_db_scale(struct usb_mixer_interface *mixer,
					 struct usb_mixe...` |
| `snd_dualsense_controls_create` | function | `legacy/mixer_quirks.c:778` | `static int snd_dualsense_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_dualsense_ih_connect` | function | `legacy/mixer_quirks.c:618` | `static int snd_dualsense_ih_connect(struct input_handler *handler,
				    struct input_dev *dev,...` |
| `snd_dualsense_ih_disconnect` | function | `legacy/mixer_quirks.c:650` | `static void snd_dualsense_ih_disconnect(struct input_handle *handle)` |
| `snd_dualsense_ih_event` | function | `legacy/mixer_quirks.c:550` | `static void snd_dualsense_ih_event(struct input_handle *handle,
				   unsigned int type, unsigne...` |
| `snd_dualsense_ih_match` | function | `legacy/mixer_quirks.c:571` | `static bool snd_dualsense_ih_match(struct input_handler *handler,
				   struct input_dev *dev)` |
| `snd_dualsense_ih_start` | function | `legacy/mixer_quirks.c:657` | `static void snd_dualsense_ih_start(struct input_handle *handle)` |
| `snd_dualsense_jack_create` | function | `legacy/mixer_quirks.c:714` | `static int snd_dualsense_jack_create(struct usb_mixer_interface *mixer,
				     const char *name...` |
| `snd_dualsense_jack_get` | function | `legacy/mixer_quirks.c:680` | `static int snd_dualsense_jack_get(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...` |
| `snd_dualsense_mixer_elem_free` | function | `legacy/mixer_quirks.c:704` | `static void snd_dualsense_mixer_elem_free(struct snd_kcontrol *kctl)` |
| `snd_dualsense_resume_jack` | function | `legacy/mixer_quirks.c:697` | `static int snd_dualsense_resume_jack(struct usb_mixer_elem_list *list)` |
| `snd_emu0204_ch_switch_get` | function | `legacy/mixer_quirks.c:465` | `static int snd_emu0204_ch_switch_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...` |
| `snd_emu0204_ch_switch_info` | function | `legacy/mixer_quirks.c:457` | `static int snd_emu0204_ch_switch_info(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_ele...` |
| `snd_emu0204_ch_switch_put` | function | `legacy/mixer_quirks.c:490` | `static int snd_emu0204_ch_switch_put(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...` |
| `snd_emu0204_ch_switch_resume` | function | `legacy/mixer_quirks.c:509` | `static int snd_emu0204_ch_switch_resume(struct usb_mixer_elem_list *list)` |
| `snd_emu0204_ch_switch_update` | function | `legacy/mixer_quirks.c:472` | `static int snd_emu0204_ch_switch_update(struct usb_mixer_interface *mixer,
					int value)` |
| `snd_emu0204_controls_create` | function | `legacy/mixer_quirks.c:524` | `static int snd_emu0204_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_emuusb_set_samplerate` | function | `legacy/mixer_quirks.c:1542` | `void snd_emuusb_set_samplerate(struct snd_usb_audio *chip,
			       unsigned char samplerate_id)` |
| `snd_fix_plt_name` | function | `legacy/mixer_quirks.c:4509` | `static void snd_fix_plt_name(struct snd_usb_audio *chip,
			     struct snd_ctl_elem_id *id)` |
| `snd_ftu_create_effect_duration_ctl` | function | `legacy/mixer_quirks.c:1425` | `static int snd_ftu_create_effect_duration_ctl(struct usb_mixer_interface *mixer)` |
| `snd_ftu_create_effect_feedback_ctl` | function | `legacy/mixer_quirks.c:1438` | `static int snd_ftu_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)` |
| `snd_ftu_create_effect_return_ctls` | function | `legacy/mixer_quirks.c:1450` | `static int snd_ftu_create_effect_return_ctls(struct usb_mixer_interface *mixer)` |
| `snd_ftu_create_effect_send_ctls` | function | `legacy/mixer_quirks.c:1474` | `static int snd_ftu_create_effect_send_ctls(struct usb_mixer_interface *mixer)` |
| `snd_ftu_create_effect_switch` | function | `legacy/mixer_quirks.c:1347` | `static int snd_ftu_create_effect_switch(struct usb_mixer_interface *mixer,
					int validx, int b...` |
| `snd_ftu_create_effect_volume_ctl` | function | `legacy/mixer_quirks.c:1412` | `static int snd_ftu_create_effect_volume_ctl(struct usb_mixer_interface *mixer)` |
| `snd_ftu_create_mixer` | function | `legacy/mixer_quirks.c:1507` | `static int snd_ftu_create_mixer(struct usb_mixer_interface *mixer)` |
| `snd_ftu_create_volume_ctls` | function | `legacy/mixer_quirks.c:1373` | `static int snd_ftu_create_volume_ctls(struct usb_mixer_interface *mixer)` |
| `snd_ftu_eff_switch_get` | function | `legacy/mixer_quirks.c:1301` | `static int snd_ftu_eff_switch_get(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...` |
| `snd_ftu_eff_switch_info` | function | `legacy/mixer_quirks.c:1267` | `static int snd_ftu_eff_switch_info(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_info...` |
| `snd_ftu_eff_switch_init` | function | `legacy/mixer_quirks.c:1278` | `static int snd_ftu_eff_switch_init(struct usb_mixer_interface *mixer,
				   struct snd_kcontrol ...` |
| `snd_ftu_eff_switch_put` | function | `legacy/mixer_quirks.c:1329` | `static int snd_ftu_eff_switch_put(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...` |
| `snd_ftu_eff_switch_update` | function | `legacy/mixer_quirks.c:1308` | `static int snd_ftu_eff_switch_update(struct usb_mixer_elem_list *list)` |
| `snd_mbox1_clk_switch_get` | function | `legacy/mixer_quirks.c:934` | `static int snd_mbox1_clk_switch_get(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...` |
| `snd_mbox1_clk_switch_info` | function | `legacy/mixer_quirks.c:997` | `static int snd_mbox1_clk_switch_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...` |
| `snd_mbox1_clk_switch_put` | function | `legacy/mixer_quirks.c:979` | `static int snd_mbox1_clk_switch_put(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...` |
| `snd_mbox1_clk_switch_resume` | function | `legacy/mixer_quirks.c:1008` | `static int snd_mbox1_clk_switch_resume(struct usb_mixer_elem_list *list)` |
| `snd_mbox1_clk_switch_update` | function | `legacy/mixer_quirks.c:954` | `static int snd_mbox1_clk_switch_update(struct usb_mixer_interface *mixer, int is_spdif_sync)` |
| `snd_mbox1_controls_create` | function | `legacy/mixer_quirks.c:1102` | `static int snd_mbox1_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_mbox1_is_spdif_input` | function | `legacy/mixer_quirks.c:895` | `static int snd_mbox1_is_spdif_input(struct snd_usb_audio *chip)` |
| `snd_mbox1_is_spdif_synced` | function | `legacy/mixer_quirks.c:857` | `static int snd_mbox1_is_spdif_synced(struct snd_usb_audio *chip)` |
| `snd_mbox1_set_clk_source` | function | `legacy/mixer_quirks.c:877` | `static int snd_mbox1_set_clk_source(struct snd_usb_audio *chip, int rate_or_zero)` |
| `snd_mbox1_set_input_source` | function | `legacy/mixer_quirks.c:915` | `static int snd_mbox1_set_input_source(struct snd_usb_audio *chip, int is_spdif)` |
| `snd_mbox1_src_switch_get` | function | `legacy/mixer_quirks.c:1015` | `static int snd_mbox1_src_switch_get(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...` |
| `snd_mbox1_src_switch_info` | function | `legacy/mixer_quirks.c:1064` | `static int snd_mbox1_src_switch_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...` |
| `snd_mbox1_src_switch_put` | function | `legacy/mixer_quirks.c:1046` | `static int snd_mbox1_src_switch_put(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...` |
| `snd_mbox1_src_switch_resume` | function | `legacy/mixer_quirks.c:1075` | `static int snd_mbox1_src_switch_resume(struct usb_mixer_elem_list *list)` |
| `snd_mbox1_src_switch_update` | function | `legacy/mixer_quirks.c:1022` | `static int snd_mbox1_src_switch_update(struct usb_mixer_interface *mixer, int is_spdif_input)` |
| `snd_microii_controls_create` | function | `legacy/mixer_quirks.c:2068` | `static int snd_microii_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_microii_spdif_default_get` | function | `legacy/mixer_quirks.c:1877` | `static int snd_microii_spdif_default_get(struct snd_kcontrol *kcontrol,
					 struct snd_ctl_elem...` |
| `snd_microii_spdif_default_put` | function | `legacy/mixer_quirks.c:1960` | `static int snd_microii_spdif_default_put(struct snd_kcontrol *kcontrol,
					 struct snd_ctl_elem...` |
| `snd_microii_spdif_default_update` | function | `legacy/mixer_quirks.c:1924` | `static int snd_microii_spdif_default_update(struct usb_mixer_elem_list *list)` |
| `snd_microii_spdif_info` | function | `legacy/mixer_quirks.c:1869` | `static int snd_microii_spdif_info(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_info *...` |
| `snd_microii_spdif_mask_get` | function | `legacy/mixer_quirks.c:1988` | `static int snd_microii_spdif_mask_get(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_ele...` |
| `snd_microii_spdif_switch_get` | function | `legacy/mixer_quirks.c:1999` | `static int snd_microii_spdif_switch_get(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_v...` |
| `snd_microii_spdif_switch_put` | function | `legacy/mixer_quirks.c:2026` | `static int snd_microii_spdif_switch_put(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_v...` |
| `snd_microii_spdif_switch_update` | function | `legacy/mixer_quirks.c:2007` | `static int snd_microii_spdif_switch_update(struct usb_mixer_elem_list *list)` |
| `snd_nativeinstruments_control_get` | function | `legacy/mixer_quirks.c:1143` | `static int snd_nativeinstruments_control_get(struct snd_kcontrol *kcontrol,
					     struct snd_...` |
| `snd_nativeinstruments_control_put` | function | `legacy/mixer_quirks.c:1164` | `static int snd_nativeinstruments_control_put(struct snd_kcontrol *kcontrol,
					     struct snd_...` |
| `snd_nativeinstruments_create_mixer` | function | `legacy/mixer_quirks.c:1235` | `static int snd_nativeinstruments_create_mixer(struct usb_mixer_interface *mixer,
					      const...` |
| `snd_ni_control_init_val` | function | `legacy/mixer_quirks.c:1121` | `static int snd_ni_control_init_val(struct usb_mixer_interface *mixer,
				   struct snd_kcontrol ...` |
| `snd_ni_update_cur_val` | function | `legacy/mixer_quirks.c:1150` | `static int snd_ni_update_cur_val(struct usb_mixer_elem_list *list)` |
| `snd_rme_clock_status` | enum | `legacy/mixer_quirks.c:2413` | `` |
| `snd_rme_controls_create` | function | `legacy/mixer_quirks.c:2714` | `static int snd_rme_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_rme_current_freq_get` | function | `legacy/mixer_quirks.c:2553` | `static int snd_rme_current_freq_get(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_va...` |
| `snd_rme_digiface_controls_create` | function | `legacy/mixer_quirks.c:3685` | `static int snd_rme_digiface_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_rme_digiface_current_sync_get` | function | `legacy/mixer_quirks.c:3439` | `static int snd_rme_digiface_current_sync_get(struct snd_kcontrol *kcontrol,
					     struct snd_...` |
| `snd_rme_digiface_enum_get` | function | `legacy/mixer_quirks.c:3413` | `static int snd_rme_digiface_enum_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...` |
| `snd_rme_digiface_enum_put` | function | `legacy/mixer_quirks.c:3425` | `static int snd_rme_digiface_enum_put(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...` |
| `snd_rme_digiface_format_info` | function | `legacy/mixer_quirks.c:3474` | `static int snd_rme_digiface_format_info(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_i...` |
| `snd_rme_digiface_get_status_val` | function | `legacy/mixer_quirks.c:3361` | `static int snd_rme_digiface_get_status_val(struct snd_kcontrol *kcontrol)` |
| `snd_rme_digiface_rate_get` | function | `legacy/mixer_quirks.c:3399` | `static int snd_rme_digiface_rate_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...` |
| `snd_rme_digiface_rate_info` | function | `legacy/mixer_quirks.c:3496` | `static int snd_rme_digiface_rate_info(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_ele...` |
| `snd_rme_digiface_read_status` | function | `legacy/mixer_quirks.c:3337` | `static int snd_rme_digiface_read_status(struct snd_kcontrol *kcontrol, u32 status[4])` |
| `snd_rme_digiface_sync_source_info` | function | `legacy/mixer_quirks.c:3485` | `static int snd_rme_digiface_sync_source_info(struct snd_kcontrol *kcontrol,
					     struct snd_...` |
| `snd_rme_digiface_sync_state_get` | function | `legacy/mixer_quirks.c:3451` | `static int snd_rme_digiface_sync_state_get(struct snd_kcontrol *kcontrol,
					   struct snd_ctl_...` |
| `snd_rme_digiface_write_reg` | function | `legacy/mixer_quirks.c:3319` | `static int snd_rme_digiface_write_reg(struct snd_kcontrol *kcontrol, int item, u16 mask, u16 val)` |
| `snd_rme_domain` | enum | `legacy/mixer_quirks.c:2407` | `` |
| `snd_rme_get_status1` | function | `legacy/mixer_quirks.c:2438` | `static int snd_rme_get_status1(struct snd_kcontrol *kcontrol,
			       u32 *status1)` |
| `snd_rme_rate_get` | function | `legacy/mixer_quirks.c:2450` | `static int snd_rme_rate_get(struct snd_kcontrol *kcontrol,
			    struct snd_ctl_elem_value *ucon...` |
| `snd_rme_rate_info` | function | `legacy/mixer_quirks.c:2579` | `static int snd_rme_rate_info(struct snd_kcontrol *kcontrol,
			     struct snd_ctl_elem_info *uinfo)` |
| `snd_rme_read_value` | function | `legacy/mixer_quirks.c:2419` | `static int snd_rme_read_value(struct snd_usb_audio *chip,
			      unsigned int item,
			      u3...` |
| `snd_rme_spdif_format_get` | function | `legacy/mixer_quirks.c:2527` | `static int snd_rme_spdif_format_get(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_va...` |
| `snd_rme_spdif_format_info` | function | `legacy/mixer_quirks.c:2621` | `static int snd_rme_spdif_format_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...` |
| `snd_rme_spdif_if_get` | function | `legacy/mixer_quirks.c:2514` | `static int snd_rme_spdif_if_get(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *uco...` |
| `snd_rme_spdif_if_info` | function | `legacy/mixer_quirks.c:2610` | `static int snd_rme_spdif_if_info(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_info *ui...` |
| `snd_rme_sync_source_get` | function | `legacy/mixer_quirks.c:2540` | `static int snd_rme_sync_source_get(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...` |
| `snd_rme_sync_source_info` | function | `legacy/mixer_quirks.c:2632` | `static int snd_rme_sync_source_info(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_in...` |
| `snd_rme_sync_state_get` | function | `legacy/mixer_quirks.c:2484` | `static int snd_rme_sync_state_get(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_value ...` |
| `snd_rme_sync_state_info` | function | `legacy/mixer_quirks.c:2599` | `static int snd_rme_sync_state_info(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_info...` |
| `snd_soundblaster_e1_switch_create` | function | `legacy/mixer_quirks.c:2155` | `static int snd_soundblaster_e1_switch_create(struct usb_mixer_interface *mixer)` |
| `snd_soundblaster_e1_switch_get` | function | `legacy/mixer_quirks.c:2091` | `static int snd_soundblaster_e1_switch_get(struct snd_kcontrol *kcontrol,
					  struct snd_ctl_el...` |
| `snd_soundblaster_e1_switch_info` | function | `legacy/mixer_quirks.c:2136` | `static int snd_soundblaster_e1_switch_info(struct snd_kcontrol *kcontrol,
					   struct snd_ctl_...` |
| `snd_soundblaster_e1_switch_put` | function | `legacy/mixer_quirks.c:2116` | `static int snd_soundblaster_e1_switch_put(struct snd_kcontrol *kcontrol,
					  struct snd_ctl_el...` |
| `snd_soundblaster_e1_switch_resume` | function | `legacy/mixer_quirks.c:2130` | `static int snd_soundblaster_e1_switch_resume(struct usb_mixer_elem_list *list)` |
| `snd_soundblaster_e1_switch_update` | function | `legacy/mixer_quirks.c:2098` | `static int snd_soundblaster_e1_switch_update(struct usb_mixer_interface *mixer,
					     unsigne...` |
| `snd_usb_mixer_apply_create_quirk` | function | `legacy/mixer_quirks.c:4239` | `int snd_usb_mixer_apply_create_quirk(struct usb_mixer_interface *mixer)` |
| `snd_usb_mixer_fu_apply_quirk` | function | `legacy/mixer_quirks.c:4539` | `void snd_usb_mixer_fu_apply_quirk(struct usb_mixer_interface *mixer,
				  struct usb_mixer_elem_...` |
| `snd_usb_mixer_rc_memory_change` | function | `legacy/mixer_quirks.c:4430` | `void snd_usb_mixer_rc_memory_change(struct usb_mixer_interface *mixer,
				    int unitid)` |
| `snd_usb_mixer_resume_quirk` | function | `legacy/mixer_quirks.c:4421` | `void snd_usb_mixer_resume_quirk(struct usb_mixer_interface *mixer)` |
| `snd_usb_sbrc_hwdep_poll` | function | `legacy/mixer_quirks.c:240` | `static __poll_t snd_usb_sbrc_hwdep_poll(struct snd_hwdep *hw, struct file *file,
					poll_table ...` |
| `snd_usb_sbrc_hwdep_read` | function | `legacy/mixer_quirks.c:220` | `static long snd_usb_sbrc_hwdep_read(struct snd_hwdep *hw, char __user *buf,
				    long count, l...` |
| `snd_usb_soundblaster_remote_complete` | function | `legacy/mixer_quirks.c:200` | `static void snd_usb_soundblaster_remote_complete(struct urb *urb)` |
| `snd_usb_soundblaster_remote_init` | function | `legacy/mixer_quirks.c:249` | `static int snd_usb_soundblaster_remote_init(struct usb_mixer_interface *mixer)` |
| `snd_xonar_u1_controls_create` | function | `legacy/mixer_quirks.c:848` | `static int snd_xonar_u1_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_xonar_u1_switch_get` | function | `legacy/mixer_quirks.c:792` | `static int snd_xonar_u1_switch_get(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...` |
| `snd_xonar_u1_switch_put` | function | `legacy/mixer_quirks.c:813` | `static int snd_xonar_u1_switch_put(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...` |
| `snd_xonar_u1_switch_resume` | function | `legacy/mixer_quirks.c:833` | `static int snd_xonar_u1_switch_resume(struct usb_mixer_elem_list *list)` |
| `snd_xonar_u1_switch_update` | function | `legacy/mixer_quirks.c:799` | `static int snd_xonar_u1_switch_update(struct usb_mixer_interface *mixer,
				      unsigned char ...` |
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
| `MAX_CHANNELS` | macro | `src/vsl_cli.c:48` | `#define MAX_CHANNELS` |
| `ParamEntry` | struct | `src/vsl_cli.c:15` | `` |
| `do_send` | function | `src/vsl_cli.c:130` | `static int do_send(uint16_t product_id,
                   uint16_t param_id,
                   ...` |
| `do_send_freq` | function | `src/vsl_cli.c:168` | `static int do_send_freq(uint16_t product_id,
                        uint16_t param_id,
         ...` |
| `find_entry_by_name` | function | `src/vsl_cli.c:121` | `static const ParamEntry *
find_entry_by_name(const char *name)` |
| `lookup_coeffs_by_param_id` | function | `src/vsl_cli.c:111` | `static const VSL_Parameter *
lookup_coeffs_by_param_id(uint16_t param_id)` |
| `main` | function | `src/vsl_cli.c:205` | `int main(int argc, char *argv[])` |
| `print_list` | function | `src/vsl_cli.c:91` | `static void print_list(uint16_t product_id)` |
| `print_usage` | function | `src/vsl_cli.c:58` | `static void print_usage(FILE *fp, const char *prog)` |
| `print_version` | function | `src/vsl_cli.c:84` | `static void print_version(void)` |
| `VSL_CONFIG_H` | macro | `src/vsl_config.h:2` | `#define VSL_CONFIG_H` |
| `VSL_EP_MIDI_OUT` | macro | `src/vsl_config.h:19` | `#define VSL_EP_MIDI_OUT` |
| `VSL_MIDI_IFACE` | macro | `src/vsl_config.h:18` | `#define VSL_MIDI_IFACE` |
| `VSL_ModelInfo` | struct | `src/vsl_config.h:21` | `` |
| `VSL_ModelLookup` | function | `src/vsl_config.h:37` | `static inline const VSL_ModelInfo *
VSL_ModelLookup(uint16_t pid)` |
| `VSL_ModelLookupByTag` | function | `src/vsl_config.h:49` | `static inline const VSL_ModelInfo *
VSL_ModelLookupByTag(const char *tag)` |
| `VSL_PACKET_SIZE` | macro | `src/vsl_config.h:17` | `#define VSL_PACKET_SIZE` |
| `VSL_PRODUCT_ID_1818VSL` | macro | `src/vsl_config.h:14` | `#define VSL_PRODUCT_ID_1818VSL` |
| `VSL_PRODUCT_ID_22VSL` | macro | `src/vsl_config.h:12` | `#define VSL_PRODUCT_ID_22VSL` |
| `VSL_PRODUCT_ID_44VSL` | macro | `src/vsl_config.h:13` | `#define VSL_PRODUCT_ID_44VSL` |
| `VSL_REPORT_ID` | macro | `src/vsl_config.h:16` | `#define VSL_REPORT_ID` |
| `VSL_VENDOR_ID` | macro | `src/vsl_config.h:11` | `#define VSL_VENDOR_ID` |
| `pid` | variable | `src/vsl_config.h:8` | `extern "C" { #endif #define VSL_VENDOR_ID 0x194fU #define VSL_PRODUCT_ID_22VSL 0x0101U #define VSL_PRODUCT_ID_44VSL 0x01` |
| `VSL_Decode_Frequency` | function | `src/vsl_dsp_logic.c:76` | `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)` |
| `VSL_Decode_Gain` | function | `src/vsl_dsp_logic.c:16` | `float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param)` |
| `VSL_Encode_Gain` | function | `src/vsl_dsp_logic.c:3` | `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)` |
| `VSL_Final_Encode_To_Int` | function | `src/vsl_dsp_logic.c:66` | `uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)` |
| `VSL_Map_Frequency` | function | `src/vsl_dsp_logic.c:50` | `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)` |
| `VSL_DSP_LOGIC_H` | macro | `src/vsl_dsp_logic.h:2` | `#define VSL_DSP_LOGIC_H` |
| `VSL_Decode_Frequency` | function | `src/vsl_dsp_logic.h:60` | `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);` |
| `VSL_Decode_Gain` | function | `src/vsl_dsp_logic.h:42` | `float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param);` |
| `VSL_Encode_Gain` | function | `src/vsl_dsp_logic.h:33` | `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);` |
| `VSL_Final_Encode_To_Int` | function | `src/vsl_dsp_logic.h:70` | `uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param);` |
| `VSL_INV_LN2` | macro | `src/vsl_dsp_logic.h:8` | `#define VSL_INV_LN2` |
| `VSL_MAX_ENCODED_FLOAT` | macro | `src/vsl_dsp_logic.h:9` | `#define VSL_MAX_ENCODED_FLOAT` |
| `VSL_Map_Frequency` | function | `src/vsl_dsp_logic.h:51` | `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);` |
| `VSL_Parameter` | struct | `src/vsl_dsp_logic.h:11` | `` |
| `VSL_Close_Device` | function | `src/vsl_dsp_transport.c:45` | `void VSL_Close_Device(vsl_device_handle handle)` |
| `VSL_Init_Device` | function | `src/vsl_dsp_transport.c:13` | `vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)` |
| `VSL_Send_Parameter` | function | `src/vsl_dsp_transport.c:61` | `int VSL_Send_Parameter(vsl_device_handle handle,
                       uint16_t dsp_param_id,
  ...` |
| `vsl_device` | struct | `src/vsl_dsp_transport.c:7` | `` |
| `VSL_Close_Device` | function | `src/vsl_dsp_transport.h:26` | `void VSL_Close_Device(vsl_device_handle handle);` |
| `VSL_DSP_TRANSPORT_H` | macro | `src/vsl_dsp_transport.h:2` | `#define VSL_DSP_TRANSPORT_H` |
| `VSL_Send_Parameter` | function | `src/vsl_dsp_transport.h:35` | `int VSL_Send_Parameter(vsl_device_handle handle, uint16_t dsp_param_id, uint16_t encoded_value);` |
| `vsl_device_handle` | variable | `src/vsl_dsp_transport.h:9` | `extern "C" { #endif typedef void* vsl_device_handle;` |
| `vsl_device_handle` | type_alias | `src/vsl_dsp_transport.h:11` | `typedef void* vsl_device_handle;` |
| `main` | function | `tests/test_audiobox_vsl.c:136` | `int main(void)` |
| `test_lookup_handles_full_pid_range` | function | `tests/test_audiobox_vsl.c:95` | `static void test_lookup_handles_full_pid_range(void **state)` |
| `test_lookup_returns_1818_vsl` | function | `tests/test_audiobox_vsl.c:75` | `static void test_lookup_returns_1818_vsl(void **state)` |
| `test_lookup_returns_22_vsl` | function | `tests/test_audiobox_vsl.c:55` | `static void test_lookup_returns_22_vsl(void **state)` |
| `test_lookup_returns_44_vsl` | function | `tests/test_audiobox_vsl.c:65` | `static void test_lookup_returns_44_vsl(void **state)` |
| `test_lookup_returns_null_for_unknown_pid` | function | `tests/test_audiobox_vsl.c:85` | `static void test_lookup_returns_null_for_unknown_pid(void **state)` |
| `test_model_pids_match_table` | function | `tests/test_audiobox_vsl.c:46` | `static void test_model_pids_match_table(void **state)` |
| `test_supported_models_table_shape` | function | `tests/test_audiobox_vsl.c:31` | `static void test_supported_models_table_shape(void **state)` |
| `test_table_pids_are_unique` | function | `tests/test_audiobox_vsl.c:115` | `static void test_table_pids_are_unique(void **state)` |
| `test_table_product_names_non_empty` | function | `tests/test_audiobox_vsl.c:126` | `static void test_table_product_names_non_empty(void **state)` |
| `main` | function | `tests/test_vsl_dsp_logic.c:329` | `int main(void)` |
| `test_VSL_Decode_Frequency` | function | `tests/test_vsl_dsp_logic.c:68` | `static void test_VSL_Decode_Frequency(void **state)` |
| `test_VSL_Decode_Gain_c1_zero` | function | `tests/test_vsl_dsp_logic.c:128` | `static void test_VSL_Decode_Gain_c1_zero(void **state)` |
| `test_VSL_Decode_Gain_clamps_output` | function | `tests/test_vsl_dsp_logic.c:309` | `static void test_VSL_Decode_Gain_clamps_output(void **state)` |
| `test_VSL_Decode_Gain_custom_range_roundtrip` | function | `tests/test_vsl_dsp_logic.c:262` | `static void test_VSL_Decode_Gain_custom_range_roundtrip(void **state)` |
| `test_VSL_Decode_Gain_encoded_below_offset` | function | `tests/test_vsl_dsp_logic.c:164` | `static void test_VSL_Decode_Gain_encoded_below_offset(void **state)` |
| `test_VSL_Decode_Gain_encoded_equals_offset` | function | `tests/test_vsl_dsp_logic.c:290` | `static void test_VSL_Decode_Gain_encoded_equals_offset(void **state)` |
| `test_VSL_Decode_Gain_log_factor_zero` | function | `tests/test_vsl_dsp_logic.c:146` | `static void test_VSL_Decode_Gain_log_factor_zero(void **state)` |
| `test_VSL_Decode_Gain_range_zero` | function | `tests/test_vsl_dsp_logic.c:183` | `static void test_VSL_Decode_Gain_range_zero(void **state)` |
| `test_VSL_Decode_Gain_roundtrip_75` | function | `tests/test_vsl_dsp_logic.c:242` | `static void test_VSL_Decode_Gain_roundtrip_75(void **state)` |
| `test_VSL_Decode_Gain_roundtrip_extremes` | function | `tests/test_vsl_dsp_logic.c:221` | `static void test_VSL_Decode_Gain_roundtrip_extremes(void **state)` |
| `test_VSL_Decode_Gain_roundtrip_mid` | function | `tests/test_vsl_dsp_logic.c:201` | `static void test_VSL_Decode_Gain_roundtrip_mid(void **state)` |
| `test_VSL_Encode_Gain` | function | `tests/test_vsl_dsp_logic.c:9` | `static void test_VSL_Encode_Gain(void **state)` |
| `test_VSL_Final_Encode_To_Int` | function | `tests/test_vsl_dsp_logic.c:100` | `static void test_VSL_Final_Encode_To_Int(void **state)` |
| `test_VSL_Map_Frequency` | function | `tests/test_vsl_dsp_logic.c:36` | `static void test_VSL_Map_Frequency(void **state)` |
| `_GNU_SOURCE` | macro | `voicecloak/src/vc_alsa.c:1` | `#define _GNU_SOURCE` |
| `fmt_bps` | function | `voicecloak/src/vc_alsa.c:20` | `static size_t fmt_bps(snd_pcm_format_t f)` |
| `mono_to_raw` | function | `voicecloak/src/vc_alsa.c:130` | `static void mono_to_raw(unsigned char *raw, const float *mono,
                        snd_pcm_uf...` |
| `open_stream` | function | `voicecloak/src/vc_alsa.c:29` | `static int open_stream(vc_pcm_t *s, const char *dev, snd_pcm_stream_t dir,
                      ...` |
| `raw_to_mono` | function | `voicecloak/src/vc_alsa.c:99` | `static void raw_to_mono(const unsigned char *raw, float *mono,
                        snd_pcm_uf...` |
| `vc_alsa_list` | function | `voicecloak/src/vc_alsa.c:163` | `int vc_alsa_list(void)` |
| `vc_alsa_run` | function | `voicecloak/src/vc_alsa.c:189` | `int vc_alsa_run(const vc_alsa_cfg_t *cfg)` |
| `vc_pcm_t` | struct | `voicecloak/src/vc_alsa.c:13` | `` |
| `VC_ALSA_H` | macro | `voicecloak/src/vc_alsa.h:2` | `#define VC_ALSA_H` |
| `runtime` | function | `voicecloak/src/vc_alsa.h:17` | `* * The capture and playback device names are ALSA PCM names discovered * at runtime (e.g. "hw:VSL", "plughw:2,0", "defa` |
| `vc_alsa_cfg_t` | struct | `voicecloak/src/vc_alsa.h:23` | `` |
| `vc_alsa_list` | function | `voicecloak/src/vc_alsa.h:40` | `int vc_alsa_list(void);` |
| `vc_alsa_run` | function | `voicecloak/src/vc_alsa.h:47` | `int vc_alsa_run(const vc_alsa_cfg_t *cfg);` |
| `cmd_cloak` | function | `voicecloak/src/vc_cli.c:53` | `static int cmd_cloak(const char *pubkey_path,
                     const char *in_path, const cha...` |
| `cmd_info` | function | `voicecloak/src/vc_cli.c:142` | `static int cmd_info(const char *path)` |
| `cmd_keygen` | function | `voicecloak/src/vc_cli.c:41` | `static int cmd_keygen(void)` |
| `main` | function | `voicecloak/src/vc_cli.c:177` | `int main(int argc, char *argv[])` |
| `print_usage` | function | `voicecloak/src/vc_cli.c:9` | `static void print_usage(const char *prog)` |
| `openssl_init` | function | `voicecloak/src/vc_crypto.c:12` | `static void openssl_init(void)` |
| `vc_crypto_derive_seeds` | function | `voicecloak/src/vc_crypto.c:96` | `int vc_crypto_derive_seeds(const unsigned char *master_seed, size_t seed_len,
                   ...` |
| `vc_crypto_keygen` | function | `voicecloak/src/vc_crypto.c:17` | `int vc_crypto_keygen(const char *pubkey_path, const char *privkey_path)` |
| `vc_crypto_seal` | function | `voicecloak/src/vc_crypto.c:47` | `int vc_crypto_seal(const char *pubkey_path,
                   const unsigned char *seed, size_t ...` |
| `vc_crypto_unseal` | function | `voicecloak/src/vc_crypto.c:71` | `int vc_crypto_unseal(const char *privkey_path,
                     const unsigned char *enc, siz...` |
| `vc_prng_create` | function | `voicecloak/src/vc_crypto.c:143` | `vc_prng_t *vc_prng_create(const unsigned char *seed)` |
| `vc_prng_destroy` | function | `voicecloak/src/vc_crypto.c:157` | `void vc_prng_destroy(vc_prng_t *p)` |
| `vc_prng_fill` | function | `voicecloak/src/vc_crypto.c:164` | `void vc_prng_fill(vc_prng_t *p, unsigned char *buf, size_t len)` |
| `vc_prng_float` | function | `voicecloak/src/vc_crypto.c:184` | `float vc_prng_float(vc_prng_t *p, float low, float high)` |
| `vc_prng_s` | struct | `voicecloak/src/vc_crypto.c:136` | `` |
| `VC_CRYPTO_H` | macro | `voicecloak/src/vc_crypto.h:2` | `#define VC_CRYPTO_H` |
| `VC_CRYPTO_KEY_BYTES` | macro | `voicecloak/src/vc_crypto.h:12` | `#define VC_CRYPTO_KEY_BYTES` |
| `VC_CRYPTO_SEED_BYTES` | macro | `voicecloak/src/vc_crypto.h:11` | `#define VC_CRYPTO_SEED_BYTES` |
| `VC_FORMANT_SEED_BYTES` | macro | `voicecloak/src/vc_crypto.h:14` | `#define VC_FORMANT_SEED_BYTES` |
| `VC_PITCH_SEED_BYTES` | macro | `voicecloak/src/vc_crypto.h:13` | `#define VC_PITCH_SEED_BYTES` |
| `VC_SPECTRAL_SEED_BYTES` | macro | `voicecloak/src/vc_crypto.h:15` | `#define VC_SPECTRAL_SEED_BYTES` |
| `VC_TOTAL_SEED_BYTES` | macro | `voicecloak/src/vc_crypto.h:16` | `#define VC_TOTAL_SEED_BYTES` |
| `vc_crypto_derive_seeds` | function | `voicecloak/src/vc_crypto.h:61` | `int vc_crypto_derive_seeds(const unsigned char *master_seed, size_t seed_len, unsigned char *pitch_seed, unsigned char *` |
| `vc_crypto_keygen` | function | `voicecloak/src/vc_crypto.h:24` | `int vc_crypto_keygen(const char *pubkey_path, const char *privkey_path);` |
| `vc_crypto_seal` | function | `voicecloak/src/vc_crypto.h:35` | `int vc_crypto_seal(const char *pubkey_path, const unsigned char *seed, size_t seed_len, unsigned char *enc_out, size_t *` |
| `vc_crypto_unseal` | function | `voicecloak/src/vc_crypto.h:48` | `int vc_crypto_unseal(const char *privkey_path, const unsigned char *enc, size_t enc_len, unsigned char *seed, size_t see` |
| `vc_prng_create` | function | `voicecloak/src/vc_crypto.h:77` | `vc_prng_t *vc_prng_create(const unsigned char *seed);` |
| `vc_prng_destroy` | function | `voicecloak/src/vc_crypto.h:82` | `void vc_prng_destroy(vc_prng_t *p);` |
| `vc_prng_fill` | function | `voicecloak/src/vc_crypto.h:87` | `void vc_prng_fill(vc_prng_t *p, unsigned char *buf, size_t len);` |
| `vc_prng_float` | function | `voicecloak/src/vc_crypto.h:92` | `float vc_prng_float(vc_prng_t *p, float low, float high);` |
| `vc_prng_t` | type_alias | `voicecloak/src/vc_crypto.h:72` | `typedef struct vc_prng_s vc_prng_t;` |
| `VC_FFT_SIZE` | macro | `voicecloak/src/vc_dsp.c:9` | `#define VC_FFT_SIZE` |
| `VC_HOP_SIZE` | macro | `voicecloak/src/vc_dsp.c:10` | `#define VC_HOP_SIZE` |
| `compute_out_len` | function | `voicecloak/src/vc_dsp.c:31` | `static size_t compute_out_len(size_t nframes, size_t hop)` |
| `normalize_rms` | function | `voicecloak/src/vc_dsp.c:255` | `static void normalize_rms(const float *in, size_t in_len,
                          float *out, s...` |
| `stft_process` | function | `voicecloak/src/vc_dsp.c:12` | `static int stft_process(const float *samples, size_t num_samples,
                        float *...` |
| `stft_reconstruct` | function | `voicecloak/src/vc_dsp.c:21` | `static int stft_reconstruct(const float *mag, const float *phase,
                            siz...` |
| `trim_edges` | function | `voicecloak/src/vc_dsp.c:234` | `static void trim_edges(float **buf, size_t *len)` |
| `vc_dsp_cloak` | function | `voicecloak/src/vc_dsp.c:272` | `int vc_dsp_cloak(const float *samples, size_t num_samples,
                 uint32_t sample_rate,...` |
| `vc_dsp_formant_shift` | function | `voicecloak/src/vc_dsp.c:91` | `int vc_dsp_formant_shift(const float *samples, size_t num_samples,
                         uint3...` |
| `vc_dsp_pitch_shift` | function | `voicecloak/src/vc_dsp.c:35` | `int vc_dsp_pitch_shift(const float *samples, size_t num_samples,
                       uint32_t ...` |
| `vc_dsp_spectral_scramble` | function | `voicecloak/src/vc_dsp.c:161` | `int vc_dsp_spectral_scramble(const float *samples, size_t num_samples,
                          ...` |
| `VC_DSP_H` | macro | `voicecloak/src/vc_dsp.h:2` | `#define VC_DSP_H` |
| `VcMode` | variable | `voicecloak/src/vc_dsp.h:8` | `extern "C" { #endif typedef enum { VC_MODE_SUBTLE = 0, VC_MODE_WITNESS = 1 } VcMode;` |
| `vc_dsp_cloak` | function | `voicecloak/src/vc_dsp.h:28` | `int vc_dsp_cloak(const float *samples, size_t num_samples, uint32_t sample_rate, const unsigned char *pitch_seed, const ` |
| `vc_dsp_formant_shift` | function | `voicecloak/src/vc_dsp.h:20` | `int vc_dsp_formant_shift(const float *samples, size_t num_samples, uint32_t sample_rate, float shift_factor, float **out` |
| `vc_dsp_pitch_shift` | function | `voicecloak/src/vc_dsp.h:16` | `int vc_dsp_pitch_shift(const float *samples, size_t num_samples, uint32_t sample_rate, float semitones, float **out, siz` |
| `vc_dsp_spectral_scramble` | function | `voicecloak/src/vc_dsp.h:24` | `int vc_dsp_spectral_scramble(const float *samples, size_t num_samples, uint32_t sample_rate, float intensity, float **ou` |
| `M_PI` | macro | `voicecloak/src/vc_fft.c:7` | `#define M_PI` |
| `bit_reverse` | function | `voicecloak/src/vc_fft.c:10` | `static unsigned int bit_reverse(unsigned int x, unsigned int bits)` |
| `bit_reverse_reorder` | function | `voicecloak/src/vc_fft.c:20` | `static void bit_reverse_reorder(size_t n, float *real, float *imag)` |
| `vc_fft` | function | `voicecloak/src/vc_fft.c:36` | `void vc_fft(size_t n, float *real, float *imag, int inverse)` |
| `FFT` | function | `voicecloak/src/vc_fft.h:18` | `* FFT(IFFT(x)) == IFFT(FFT(x)) == x. */ void vc_fft(size_t n, float *real, float *imag, int inverse);` |
| `VC_FFT_H` | macro | `voicecloak/src/vc_fft.h:2` | `#define VC_FFT_H` |
| `M_PI` | macro | `voicecloak/src/vc_rt.c:7` | `#define M_PI` |
| `formant_warp` | function | `voicecloak/src/vc_rt.c:71` | `static void formant_warp(float *syn_mag, size_t nbins, float factor)` |
| `vc_rt_create` | function | `voicecloak/src/vc_rt.c:23` | `vc_rt_ctx_t *vc_rt_create(size_t nbins, vc_rt_params_t params)` |
| `vc_rt_ctx_s` | struct | `voicecloak/src/vc_rt.c:10` | `` |
| `vc_rt_destroy` | function | `voicecloak/src/vc_rt.c:43` | `void vc_rt_destroy(vc_rt_ctx_t *c)` |
| `vc_rt_reset` | function | `voicecloak/src/vc_rt.c:54` | `void vc_rt_reset(vc_rt_ctx_t *c)` |
| `vc_rt_semitones_to_ratio` | function | `voicecloak/src/vc_rt.c:61` | `float vc_rt_semitones_to_ratio(float semitones)` |
| `vc_rt_transform` | function | `voicecloak/src/vc_rt.c:106` | `void vc_rt_transform(float *mag, float *phase, size_t nbins,
                     uint32_t sample...` |
| `wrap_pi` | function | `voicecloak/src/vc_rt.c:65` | `static double wrap_pi(double x)` |
| `VC_RT_H` | macro | `voicecloak/src/vc_rt.h:2` | `#define VC_RT_H` |
| `shift` | variable | `voicecloak/src/vc_rt.h:8` | `extern "C" { #endif /** * @brief Real-time cloak parameters (already resolved to scalars). * * pitch_ratio 1.0 = no shif` |
| `vc_rt_create` | function | `voicecloak/src/vc_rt.h:32` | `vc_rt_ctx_t *vc_rt_create(size_t nbins, vc_rt_params_t params);` |
| `vc_rt_ctx_t` | type_alias | `voicecloak/src/vc_rt.h:26` | `typedef struct vc_rt_ctx_s vc_rt_ctx_t;` |
| `vc_rt_derive` | function | `voicecloak/src/vc_rt.h:65` | `int vc_rt_derive(const unsigned char *pitch_seed, const unsigned char *formant_seed, const unsigned char *spectral_seed,` |
| `vc_rt_destroy` | function | `voicecloak/src/vc_rt.h:35` | `void vc_rt_destroy(vc_rt_ctx_t *c);` |
| `vc_rt_params_t` | struct | `voicecloak/src/vc_rt.h:17` | `` |
| `vc_rt_reset` | function | `voicecloak/src/vc_rt.h:38` | `void vc_rt_reset(vc_rt_ctx_t *c);` |
| `vc_rt_semitones_to_ratio` | function | `voicecloak/src/vc_rt.h:54` | `float vc_rt_semitones_to_ratio(float semitones);` |
| `vc_rt_transform` | function | `voicecloak/src/vc_rt.h:48` | `void vc_rt_transform(float *mag, float *phase, size_t nbins, uint32_t sample_rate, size_t hop, void *user);` |
| `M_PI` | macro | `voicecloak/src/vc_rt_cli.c:16` | `#define M_PI` |
| `_POSIX_C_SOURCE` | macro | `voicecloak/src/vc_rt_cli.c:1` | `#define _POSIX_C_SOURCE` |
| `cmd_live` | function | `voicecloak/src/vc_rt_cli.c:142` | `static int cmd_live(int argc, char *argv[])` |
| `cmd_selftest` | function | `voicecloak/src/vc_rt_cli.c:81` | `static int cmd_selftest(void)` |
| `dominant_freq` | function | `voicecloak/src/vc_rt_cli.c:58` | `static float dominant_freq(const float *x, size_t n, unsigned int sr)` |
| `main` | function | `voicecloak/src/vc_rt_cli.c:223` | `int main(int argc, char *argv[])` |
| `on_sigint` | function | `voicecloak/src/vc_rt_cli.c:21` | `static void on_sigint(int sig)` |
| `print_usage` | function | `voicecloak/src/vc_rt_cli.c:26` | `static void print_usage(const char *prog)` |
| `resolve_params` | function | `voicecloak/src/vc_rt_cli.c:119` | `static int resolve_params(int have_fixed, float semis, float formant,
                          f...` |
| `vc_rt_derive` | function | `voicecloak/src/vc_rt_seed.c:5` | `int vc_rt_derive(const unsigned char *pitch_seed,
                 const unsigned char *formant_s...` |
| `M_PI` | macro | `voicecloak/src/vc_stft.c:8` | `#define M_PI` |
| `vc_stft_create` | function | `voicecloak/src/vc_stft.c:21` | `vc_stft_t *vc_stft_create(size_t fft_size, size_t hop_size)` |
| `vc_stft_destroy` | function | `voicecloak/src/vc_stft.c:58` | `void vc_stft_destroy(vc_stft_t *st)` |
| `vc_stft_forward` | function | `voicecloak/src/vc_stft.c:71` | `int vc_stft_forward(vc_stft_t *st,
                    const float *samples, size_t num_samples,
...` |
| `vc_stft_inverse` | function | `voicecloak/src/vc_stft.c:119` | `int vc_stft_inverse(vc_stft_t *st,
                    const float *mag, const float *phase,
    ...` |
| `vc_stft_inverse_hop` | function | `voicecloak/src/vc_stft.c:127` | `int vc_stft_inverse_hop(vc_stft_t *st,
                        const float *mag, const float *pha...` |
| `vc_stft_num_bins` | function | `voicecloak/src/vc_stft.c:67` | `size_t vc_stft_num_bins(const vc_stft_t *st)` |
| `vc_stft_s` | struct | `voicecloak/src/vc_stft.c:11` | `` |
| `VC_STFT_H` | macro | `voicecloak/src/vc_stft.h:2` | `#define VC_STFT_H` |
| `vc_stft_create` | function | `voicecloak/src/vc_stft.h:25` | `vc_stft_t *vc_stft_create(size_t fft_size, size_t hop_size);` |
| `vc_stft_destroy` | function | `voicecloak/src/vc_stft.h:30` | `void vc_stft_destroy(vc_stft_t *st);` |
| `vc_stft_forward` | function | `voicecloak/src/vc_stft.h:42` | `int vc_stft_forward(vc_stft_t *st, const float *samples, size_t num_samples, float **mag, float **phase, size_t *num_fra` |
| `vc_stft_inverse` | function | `voicecloak/src/vc_stft.h:57` | `int vc_stft_inverse(vc_stft_t *st, const float *mag, const float *phase, size_t num_frames, float *samples_out, size_t n` |
| `vc_stft_inverse_hop` | function | `voicecloak/src/vc_stft.h:66` | `int vc_stft_inverse_hop(vc_stft_t *st, const float *mag, const float *phase, size_t num_frames, float *samples_out, size` |
| `vc_stft_num_bins` | function | `voicecloak/src/vc_stft.h:75` | `size_t vc_stft_num_bins(const vc_stft_t *st);` |
| `vc_stft_t` | variable | `voicecloak/src/vc_stft.h:8` | `extern "C" { #endif /** * @brief Short-Time Fourier Transform context. * * Allocated via vc_stft_create(). Window size a` |
| `vc_stft_t` | type_alias | `voicecloak/src/vc_stft.h:17` | `typedef struct vc_stft_s vc_stft_t;` |
| `M_PI` | macro | `voicecloak/src/vc_stream.c:8` | `#define M_PI` |
| `is_pow2` | function | `voicecloak/src/vc_stream.c:31` | `static int is_pow2(size_t v)` |
| `process_frame` | function | `voicecloak/src/vc_stream.c:111` | `static void process_frame(vc_stream_t *st, vc_spectral_fn fn, void *user)` |
| `vc_stream_create` | function | `voicecloak/src/vc_stream.c:35` | `vc_stream_t *vc_stream_create(size_t fft_size, size_t hop_size,
                              uin...` |
| `vc_stream_destroy` | function | `voicecloak/src/vc_stream.c:94` | `void vc_stream_destroy(vc_stream_t *st)` |
| `vc_stream_latency_samples` | function | `voicecloak/src/vc_stream.c:107` | `size_t vc_stream_latency_samples(const vc_stream_t *st)` |
| `vc_stream_process` | function | `voicecloak/src/vc_stream.c:159` | `int vc_stream_process(vc_stream_t *st,
                      const float *in, float *out, size_t ...` |
| `vc_stream_s` | struct | `voicecloak/src/vc_stream.c:11` | `` |
| `VC_STREAM_H` | macro | `voicecloak/src/vc_stream.h:2` | `#define VC_STREAM_H` |
| `frames` | function | `voicecloak/src/vc_stream.h:32` | `* that must persist across frames (phase-vocoder accumulators) lives * in @p user, not in the engine. */ typedef void (*` |
| `hop` | variable | `voicecloak/src/vc_stream.h:8` | `extern "C" { #endif /** * @brief Streaming STFT overlap-add engine for real-time processing. * * Unlike the offline vc_s` |
| `vc_stream_create` | function | `voicecloak/src/vc_stream.h:46` | `vc_stream_t *vc_stream_create(size_t fft_size, size_t hop_size, uint32_t sample_rate);` |
| `vc_stream_destroy` | function | `voicecloak/src/vc_stream.h:50` | `void vc_stream_destroy(vc_stream_t *st);` |
| `vc_stream_latency_samples` | function | `voicecloak/src/vc_stream.h:53` | `size_t vc_stream_latency_samples(const vc_stream_t *st);` |
| `vc_stream_process` | function | `voicecloak/src/vc_stream.h:65` | `int vc_stream_process(vc_stream_t *st, const float *in, float *out, size_t n, vc_spectral_fn fn, void *user);` |
| `vc_stream_t` | type_alias | `voicecloak/src/vc_stream.h:20` | `typedef struct vc_stream_s vc_stream_t;` |
| `WavDataChunk` | struct | `voicecloak/src/vc_wav.c:24` | `` |
| `WavFmtBody` | struct | `voicecloak/src/vc_wav.c:15` | `` |
| `WavHeader` | struct | `voicecloak/src/vc_wav.c:9` | `` |
| `find_chunk` | function | `voicecloak/src/vc_wav.c:78` | `static int find_chunk(FILE *fp, const char *id, uint32_t *size)` |
| `float_to_sample` | function | `voicecloak/src/vc_wav.c:62` | `static void float_to_sample(float f, unsigned char *p, int bps)` |
| `read_bytes` | function | `voicecloak/src/vc_wav.c:30` | `static int read_bytes(FILE *fp, void *buf, size_t n)` |
| `sample_to_float` | function | `voicecloak/src/vc_wav.c:38` | `static float sample_to_float(const unsigned char *p, int bps)` |
| `vc_wav_read` | function | `voicecloak/src/vc_wav.c:93` | `int vc_wav_read(const char *path,
                float **samples_out, size_t *num_samples_out,
 ...` |
| `vc_wav_write` | function | `voicecloak/src/vc_wav.c:169` | `int vc_wav_write(const char *path,
                 const float *samples, size_t num_samples,
   ...` |
| `write_bytes` | function | `voicecloak/src/vc_wav.c:34` | `static int write_bytes(FILE *fp, const void *buf, size_t n)` |
| `VC_WAV_H` | macro | `voicecloak/src/vc_wav.h:2` | `#define VC_WAV_H` |
| `vc_wav_read` | function | `voicecloak/src/vc_wav.h:19` | `int vc_wav_read(const char *path, float **samples_out, size_t *num_samples_out, uint32_t *sample_rate_out);` |
| `vc_wav_write` | function | `voicecloak/src/vc_wav.h:31` | `int vc_wav_write(const char *path, const float *samples, size_t num_samples, uint32_t sample_rate);` |
| `main` | function | `voicecloak/tests/test_vc_fft.c:76` | `int main(void)` |
| `test_fft_dc_signal` | function | `voicecloak/tests/test_vc_fft.c:27` | `static void test_fft_dc_signal(void **state)` |
| `test_fft_identity` | function | `voicecloak/tests/test_vc_fft.c:10` | `static void test_fft_identity(void **state)` |
| `test_fft_sine` | function | `voicecloak/tests/test_vc_fft.c:47` | `static void test_fft_sine(void **state)` |
| `M_PI` | macro | `voicecloak/tests/test_vc_stream.c:15` | `#define M_PI` |
| `SR` | macro | `voicecloak/tests/test_vc_stream.c:18` | `#define SR` |
| `dominant_freq` | function | `voicecloak/tests/test_vc_stream.c:32` | `static float dominant_freq(const float *x, size_t n, uint32_t sr)` |
| `gen_sines` | function | `voicecloak/tests/test_vc_stream.c:20` | `static void gen_sines(float *buf, size_t n, uint32_t sr,
                      const float *freqs...` |
| `main` | function | `voicecloak/tests/test_vc_stream.c:185` | `int main(void)` |
| `rms` | function | `voicecloak/tests/test_vc_stream.c:54` | `static float rms(const float *x, size_t n)` |
| `run_pitch` | function | `voicecloak/tests/test_vc_stream.c:122` | `static void run_pitch(float in_freq, float ratio, float expect_freq)` |
| `run_stream` | function | `voicecloak/tests/test_vc_stream.c:63` | `static void run_stream(vc_stream_t *st, const float *in, float *out, size_t n,
                  ...` |
| `test_bounded_output` | function | `voicecloak/tests/test_vc_stream.c:156` | `static void test_bounded_output(void **state)` |
| `test_create_validation` | function | `voicecloak/tests/test_vc_stream.c:74` | `static void test_create_validation(void **state)` |
| `test_passthrough_identity` | function | `voicecloak/tests/test_vc_stream.c:86` | `static void test_passthrough_identity(void **state)` |
| `test_pitch_down_octave` | function | `voicecloak/tests/test_vc_stream.c:151` | `static void test_pitch_down_octave(void **state)` |
| `test_pitch_up_octave` | function | `voicecloak/tests/test_vc_stream.c:146` | `static void test_pitch_up_octave(void **state)` |
