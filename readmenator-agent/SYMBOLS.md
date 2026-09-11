# Symbols

| Symbol | Kind | File:Line | Signature |
|--------|------|-----------|-----------|
| `AUDIOBOX_DRIVER_DESC` | macro | `audiobox_vsl.c:26` | `#define AUDIOBOX_DRIVER_DESC` |
| `AUDIOBOX_DRIVER_LIC` | macro | `audiobox_vsl.c:27` | `#define AUDIOBOX_DRIVER_LIC` |
| `AUDIOBOX_DRIVER_NAME` | macro | `audiobox_vsl.c:24` | `#define AUDIOBOX_DRIVER_NAME` |
| `MODULE_LICENSE` | function | `audiobox_vsl.c:80` | `MODULE_LICENSE(AUDIOBOX_DRIVER_LIC);` |
| `audiobox_disconnect` | function | `audiobox_vsl.c:58` | `static void audiobox_disconnect(struct usb_interface *intf)` |
| `audiobox_probe` | function | `audiobox_vsl.c:36` | `static int audiobox_probe(struct usb_interface *intf,
                          const struct usb_...` |
| `dev_info` | function | `audiobox_vsl.c:47` | `dev_info(&intf->dev, "audiobox_vsl: detected '%s' (%04x:%04x)\n", name, le16_to_cpu(udev->descriptor.idVendor), pid);` |
| `module_usb_driver` | function | `audiobox_vsl.c:78` | `module_usb_driver(audiobox_driver);` |
| `AUDIOBOX_VENDOR_ID` | macro | `audiobox_vsl.h:32` | `#define AUDIOBOX_VENDOR_ID` |
| `AUDIOBOX_VSL_H` | macro | `audiobox_vsl.h:21` | `#define AUDIOBOX_VSL_H` |
| `audiobox_lookup_model` | function | `audiobox_vsl.h:95` | `static inline const audiobox_model_info_t *
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
| `VSL_Build_And_Send_Packet` | function | `legacy/main.c:68` | `VSL_Build_And_Send_Packet(gain_id, encoded_gain_float);` |
| `main` | function | `legacy/main.c:4` | `int main()` |
| `printf` | function | `legacy/main.c:36` | `printf("--- Ganancia ---\n");` |
| `BIT` | function | `legacy/mixer_quirks.c:1726` | `BIT(chan + (chan % 2) * num_outs - 1);` |
| `CLASS` | function | `legacy/mixer_quirks.c:310` | `CLASS(snd_usb_lock, pm)(chip);` |
| `DECLARE_TLV_DB_RANGE` | function | `legacy/mixer_quirks.c:4465` | `static const DECLARE_TLV_DB_RANGE(scale, 0, 1, TLV_DB_MINMAX_ITEM(-5300, -4970), 2, 5, TLV_DB_MINMAX_ITEM(-4710, -4160),` |
| `HDA_VERB_CMD` | macro | `legacy/mixer_quirks.c:2171` | `#define HDA_VERB_CMD(V, N, D)` |
| `HDA_VERB_CMD` | function | `legacy/mixer_quirks.c:2239` | `HDA_VERB_CMD(AC_VERB_GET_PIN_SENSE, node_id, 0), &sense);` |
| `REALTEK_AUDIO_FUNCTION_GROUP` | macro | `legacy/mixer_quirks.c:2180` | `#define REALTEK_AUDIO_FUNCTION_GROUP` |
| `REALTEK_CBJ_CTRL2` | macro | `legacy/mixer_quirks.c:2185` | `#define REALTEK_CBJ_CTRL2` |
| `REALTEK_HDA_GET_IN` | macro | `legacy/mixer_quirks.c:2179` | `#define REALTEK_HDA_GET_IN` |
| `REALTEK_HDA_GET_OUT` | macro | `legacy/mixer_quirks.c:2178` | `#define REALTEK_HDA_GET_OUT` |
| `REALTEK_HDA_SET` | macro | `legacy/mixer_quirks.c:2175` | `#define REALTEK_HDA_SET` |
| `REALTEK_HDA_VALUE` | macro | `legacy/mixer_quirks.c:2173` | `#define REALTEK_HDA_VALUE` |
| `REALTEK_HP_OUT` | macro | `legacy/mixer_quirks.c:2184` | `#define REALTEK_HP_OUT` |
| `REALTEK_JACK_INTERRUPT_NODE` | macro | `legacy/mixer_quirks.c:2187` | `#define REALTEK_JACK_INTERRUPT_NODE` |
| `REALTEK_LINE1` | macro | `legacy/mixer_quirks.c:2182` | `#define REALTEK_LINE1` |
| `REALTEK_MANUAL_MODE` | macro | `legacy/mixer_quirks.c:2177` | `#define REALTEK_MANUAL_MODE` |
| `REALTEK_MIC_FLAG` | macro | `legacy/mixer_quirks.c:2189` | `#define REALTEK_MIC_FLAG` |
| `REALTEK_VENDOR_REGISTERS` | macro | `legacy/mixer_quirks.c:2183` | `#define REALTEK_VENDOR_REGISTERS` |
| `RME_DIGIFACE_CTL_REG1` | macro | `legacy/mixer_quirks.c:3307` | `#define RME_DIGIFACE_CTL_REG1` |
| `RME_DIGIFACE_CTL_REG2` | macro | `legacy/mixer_quirks.c:3309` | `#define RME_DIGIFACE_CTL_REG2` |
| `RME_DIGIFACE_INVERT` | macro | `legacy/mixer_quirks.c:3313` | `#define RME_DIGIFACE_INVERT` |
| `RME_DIGIFACE_READ_STATUS` | macro | `legacy/mixer_quirks.c:3297` | `#define RME_DIGIFACE_READ_STATUS` |
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
| `SND_BBFPRO_CTL_REG_MASK` | macro | `legacy/mixer_quirks.c:2743` | `#define SND_BBFPRO_CTL_REG_MASK` |
| `SND_BBFPRO_CTL_VAL_MASK` | macro | `legacy/mixer_quirks.c:2747` | `#define SND_BBFPRO_CTL_VAL_MASK` |
| `SND_BBFPRO_CTL_VAL_SHIFT` | macro | `legacy/mixer_quirks.c:2748` | `#define SND_BBFPRO_CTL_VAL_SHIFT` |
| `SND_BBFPRO_GAIN_CHANNEL_MASK` | macro | `legacy/mixer_quirks.c:2767` | `#define SND_BBFPRO_GAIN_CHANNEL_MASK` |
| `SND_BBFPRO_GAIN_CHANNEL_SHIFT` | macro | `legacy/mixer_quirks.c:2769` | `#define SND_BBFPRO_GAIN_CHANNEL_SHIFT` |
| `SND_BBFPRO_GAIN_VAL_LINE_MAX` | macro | `legacy/mixer_quirks.c:2773` | `#define SND_BBFPRO_GAIN_VAL_LINE_MAX` |
| `SND_BBFPRO_GAIN_VAL_MASK` | macro | `legacy/mixer_quirks.c:2770` | `#define SND_BBFPRO_GAIN_VAL_MASK` |
| `SND_BBFPRO_GAIN_VAL_MIC_MAX` | macro | `legacy/mixer_quirks.c:2772` | `#define SND_BBFPRO_GAIN_VAL_MIC_MAX` |
| `SND_BBFPRO_GAIN_VAL_MIN` | macro | `legacy/mixer_quirks.c:2771` | `#define SND_BBFPRO_GAIN_VAL_MIN` |
| `SND_BBFPRO_MIXER_IDX_MASK` | macro | `legacy/mixer_quirks.c:2762` | `#define SND_BBFPRO_MIXER_IDX_MASK` |
| `SND_BBFPRO_MIXER_MAIN_OUT_CH_OFFSET` | macro | `legacy/mixer_quirks.c:2760` | `#define SND_BBFPRO_MIXER_MAIN_OUT_CH_OFFSET` |
| `SND_BBFPRO_MIXER_VAL_MASK` | macro | `legacy/mixer_quirks.c:2763` | `#define SND_BBFPRO_MIXER_VAL_MASK` |
| `SND_BBFPRO_MIXER_VAL_MAX` | macro | `legacy/mixer_quirks.c:2766` | `#define SND_BBFPRO_MIXER_VAL_MAX` |
| `SND_BBFPRO_MIXER_VAL_MIN` | macro | `legacy/mixer_quirks.c:2765` | `#define SND_BBFPRO_MIXER_VAL_MIN` |
| `SND_BBFPRO_MIXER_VAL_SHIFT` | macro | `legacy/mixer_quirks.c:2764` | `#define SND_BBFPRO_MIXER_VAL_SHIFT` |
| `SND_BBFPRO_USBREQ_CTL_REG1` | macro | `legacy/mixer_quirks.c:2774` | `#define SND_BBFPRO_USBREQ_CTL_REG1` |
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
| `SND_DJM_CTL` | macro | `legacy/mixer_quirks.c:3766` | `#define SND_DJM_CTL(_name, suffix, _default_value, _windex)` |
| `SND_DJM_DEVICE` | macro | `legacy/mixer_quirks.c:3773` | `#define SND_DJM_DEVICE(suffix)` |
| `SND_DJM_DEVICE_MASK` | macro | `legacy/mixer_quirks.c:3752` | `#define SND_DJM_DEVICE_MASK` |
| `SND_DJM_DEVICE_SHIFT` | macro | `legacy/mixer_quirks.c:3754` | `#define SND_DJM_DEVICE_SHIFT` |
| `SND_DJM_GROUP_MASK` | macro | `legacy/mixer_quirks.c:3751` | `#define SND_DJM_GROUP_MASK` |
| `SND_DJM_GROUP_SHIFT` | macro | `legacy/mixer_quirks.c:3753` | `#define SND_DJM_GROUP_SHIFT` |
| `SND_DJM_PB_AUX` | macro | `legacy/mixer_quirks.c:3743` | `#define SND_DJM_PB_AUX` |
| `SND_DJM_PB_CH1` | macro | `legacy/mixer_quirks.c:3741` | `#define SND_DJM_PB_CH1` |
| `SND_DJM_PB_CH2` | macro | `legacy/mixer_quirks.c:3742` | `#define SND_DJM_PB_CH2` |
| `SND_DJM_V10_IDX` | macro | `legacy/mixer_quirks.c:3765` | `#define SND_DJM_V10_IDX` |
| `SND_DJM_VALUE_MASK` | macro | `legacy/mixer_quirks.c:3750` | `#define SND_DJM_VALUE_MASK` |
| `SND_DJM_WINDEX_CAP` | macro | `legacy/mixer_quirks.c:3744` | `#define SND_DJM_WINDEX_CAP` |
| `SND_DJM_WINDEX_CAPLVL` | macro | `legacy/mixer_quirks.c:3746` | `#define SND_DJM_WINDEX_CAPLVL` |
| `SND_DJM_WINDEX_PB` | macro | `legacy/mixer_quirks.c:3747` | `#define SND_DJM_WINDEX_PB` |
| `SND_DUALSENSE_JACK_IN_TERM_ID` | macro | `legacy/mixer_quirks.c:541` | `#define SND_DUALSENSE_JACK_IN_TERM_ID` |
| `SND_DUALSENSE_JACK_OUT_TERM_ID` | macro | `legacy/mixer_quirks.c:539` | `#define SND_DUALSENSE_JACK_OUT_TERM_ID` |
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
| `SND_RME_GET_STATUS1` | macro | `legacy/mixer_quirks.c:2362` | `#define SND_RME_GET_STATUS1` |
| `SND_RME_RATE_IDX_AES_SPDIF_NUM` | macro | `legacy/mixer_quirks.c:2405` | `#define SND_RME_RATE_IDX_AES_SPDIF_NUM` |
| `SND_RME_SPDIF_FORMAT` | macro | `legacy/mixer_quirks.c:2393` | `#define SND_RME_SPDIF_FORMAT(x)` |
| `SND_RME_SPDIF_FORMAT_SHIFT` | macro | `legacy/mixer_quirks.c:2389` | `#define SND_RME_SPDIF_FORMAT_SHIFT` |
| `SND_RME_SPDIF_IF` | macro | `legacy/mixer_quirks.c:2391` | `#define SND_RME_SPDIF_IF(x)` |
| `SND_RME_SPDIF_IF_SHIFT` | macro | `legacy/mixer_quirks.c:2388` | `#define SND_RME_SPDIF_IF_SHIFT` |
| `USB_ID` | function | `legacy/mixer_quirks.c:4249` | `case USB_ID(0x194f, 0x0101): err = snd_audiobox_vsl_init(mixer);` |
| `_MAKE_NI_CONTROL` | macro | `legacy/mixer_quirks.c:1118` | `#define _MAKE_NI_CONTROL(bRequest, wIndex)` |
| `add_single_ctl_with_resume` | function | `legacy/mixer_quirks.c:145` | `static int add_single_ctl_with_resume(struct usb_mixer_interface *mixer,
				      int id,
				  ...` |
| `dell_dock_init_vol` | function | `legacy/mixer_quirks.c:2338` | `static void dell_dock_init_vol(struct usb_mixer_interface *mixer, int ch, int id)` |
| `dell_dock_mixer_create` | function | `legacy/mixer_quirks.c:2306` | `static int dell_dock_mixer_create(struct usb_mixer_interface *mixer)` |
| `dell_dock_mixer_init` | function | `legacy/mixer_quirks.c:2350` | `static int dell_dock_mixer_init(struct usb_mixer_interface *mixer)` |
| `dev_err` | function | `legacy/mixer_quirks.c:1134` | `dev_err(&dev->dev, "unable to issue vendor read request (ret = %d)", err);` |
| `dev_warn` | function | `legacy/mixer_quirks.c:585` | `dev_warn(&snd_dev->dev, "Failed to get input dev path\n");` |
| `dualsense_mixer_elem_info` | struct | `legacy/mixer_quirks.c:543` | `` |
| `field_get` | macro | `legacy/mixer_quirks.c:3316` | `#define field_get(_mask, _reg)` |
| `field_get` | function | `legacy/mixer_quirks.c:3395` | `return field_get(mask, val);` |
| `field_prep` | macro | `legacy/mixer_quirks.c:3317` | `#define field_prep(_mask, _val)` |
| `init_waitqueue_head` | function | `legacy/mixer_quirks.c:262` | `init_waitqueue_head(&mixer->rc_waitq);` |
| `input_close_device` | function | `legacy/mixer_quirks.c:652` | `input_close_device(handle);` |
| `input_unregister_handle` | function | `legacy/mixer_quirks.c:642` | `err_unregister: input_unregister_handle(handle);` |
| `kfree` | function | `legacy/mixer_quirks.c:94` | `kfree(cval);` |
| `list_for_each_entry` | function | `legacy/mixer_quirks.c:1548` | `list_for_each_entry(mixer, &chip->mixer_list, list)` |
| `poll_wait` | function | `legacy/mixer_quirks.c:244` | `poll_wait(file, &mixer->rc_waitq, wait);` |
| `rc_config` | struct | `legacy/mixer_quirks.c:181` | `` |
| `realtek_add_jack` | function | `legacy/mixer_quirks.c:2279` | `static int realtek_add_jack(struct usb_mixer_interface *mixer,
			    char *name, u32 val)` |
| `realtek_ctl_connector_get` | function | `legacy/mixer_quirks.c:2222` | `static int realtek_ctl_connector_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...` |
| `realtek_hda_get` | function | `legacy/mixer_quirks.c:2201` | `static int realtek_hda_get(struct snd_usb_audio *chip, u32 cmd, u32 *value)` |
| `realtek_hda_set` | function | `legacy/mixer_quirks.c:2191` | `static int realtek_hda_set(struct snd_usb_audio *chip, u32 cmd)` |
| `realtek_resume_jack` | function | `legacy/mixer_quirks.c:2272` | `static int realtek_resume_jack(struct usb_mixer_elem_list *list)` |
| `sb_jack` | struct | `legacy/mixer_quirks.c:410` | `` |
| `snd_audigy2nx_controls_create` | function | `legacy/mixer_quirks.c:374` | `static int snd_audigy2nx_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_audigy2nx_led_get` | function | `legacy/mixer_quirks.c:298` | `static int snd_audigy2nx_led_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)` |
| `snd_audigy2nx_led_info` | macro | `legacy/mixer_quirks.c:296` | `#define snd_audigy2nx_led_info` |
| `snd_audigy2nx_led_put` | function | `legacy/mixer_quirks.c:333` | `static int snd_audigy2nx_led_put(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_value *u...` |
| `snd_audigy2nx_led_resume` | function | `legacy/mixer_quirks.c:352` | `static int snd_audigy2nx_led_resume(struct usb_mixer_elem_list *list)` |
| `snd_audigy2nx_led_update` | function | `legacy/mixer_quirks.c:304` | `static int snd_audigy2nx_led_update(struct usb_mixer_interface *mixer,
				    int value, int index)` |
| `snd_audigy2nx_proc_read` | function | `legacy/mixer_quirks.c:406` | `static void snd_audigy2nx_proc_read(struct snd_info_entry *entry,
				    struct snd_info_buffer ...` |
| `snd_bbfpro_controls_create` | function | `legacy/mixer_quirks.c:3170` | `static int snd_bbfpro_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_bbfpro_ctl_add` | function | `legacy/mixer_quirks.c:3132` | `static int snd_bbfpro_ctl_add(struct usb_mixer_interface *mixer, u8 reg,
			      u8 index, char ...` |
| `snd_bbfpro_ctl_get` | function | `legacy/mixer_quirks.c:2810` | `static int snd_bbfpro_ctl_get(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...` |
| `snd_bbfpro_ctl_info` | function | `legacy/mixer_quirks.c:2833` | `static int snd_bbfpro_ctl_info(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_info ...` |
| `snd_bbfpro_ctl_put` | function | `legacy/mixer_quirks.c:2867` | `static int snd_bbfpro_ctl_put(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...` |
| `snd_bbfpro_ctl_resume` | function | `legacy/mixer_quirks.c:2906` | `static int snd_bbfpro_ctl_resume(struct usb_mixer_elem_list *list)` |
| `snd_bbfpro_ctl_update` | function | `legacy/mixer_quirks.c:2779` | `static int snd_bbfpro_ctl_update(struct usb_mixer_interface *mixer, u8 reg,
				 u8 index, u8 value)` |
| `snd_bbfpro_gain_add` | function | `legacy/mixer_quirks.c:3146` | `static int snd_bbfpro_gain_add(struct usb_mixer_interface *mixer, u8 channel,
			       char *name)` |
| `snd_bbfpro_gain_get` | function | `legacy/mixer_quirks.c:2943` | `static int snd_bbfpro_gain_get(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_value...` |
| `snd_bbfpro_gain_info` | function | `legacy/mixer_quirks.c:2952` | `static int snd_bbfpro_gain_info(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_info *uinfo)` |
| `snd_bbfpro_gain_put` | function | `legacy/mixer_quirks.c:2973` | `static int snd_bbfpro_gain_put(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_value...` |
| `snd_bbfpro_gain_resume` | function | `legacy/mixer_quirks.c:3010` | `static int snd_bbfpro_gain_resume(struct usb_mixer_elem_list *list)` |
| `snd_bbfpro_gain_update` | function | `legacy/mixer_quirks.c:2919` | `static int snd_bbfpro_gain_update(struct usb_mixer_interface *mixer,
				  u8 channel, u8 gain)` |
| `snd_bbfpro_vol_add` | function | `legacy/mixer_quirks.c:3158` | `static int snd_bbfpro_vol_add(struct usb_mixer_interface *mixer, u16 index,
			      char *name)` |
| `snd_bbfpro_vol_get` | function | `legacy/mixer_quirks.c:3049` | `static int snd_bbfpro_vol_get(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...` |
| `snd_bbfpro_vol_info` | function | `legacy/mixer_quirks.c:3057` | `static int snd_bbfpro_vol_info(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_info ...` |
| `snd_bbfpro_vol_put` | function | `legacy/mixer_quirks.c:3067` | `static int snd_bbfpro_vol_put(struct snd_kcontrol *kcontrol,
			      struct snd_ctl_elem_value *...` |
| `snd_bbfpro_vol_resume` | function | `legacy/mixer_quirks.c:3095` | `static int snd_bbfpro_vol_resume(struct usb_mixer_elem_list *list)` |
| `snd_bbfpro_vol_update` | function | `legacy/mixer_quirks.c:3023` | `static int snd_bbfpro_vol_update(struct usb_mixer_interface *mixer, u16 index,
				 u32 value)` |
| `snd_c400_create_effect_duration_ctl` | function | `legacy/mixer_quirks.c:1625` | `static int snd_c400_create_effect_duration_ctl(struct usb_mixer_interface *mixer)` |
| `snd_c400_create_effect_feedback_ctl` | function | `legacy/mixer_quirks.c:1638` | `static int snd_c400_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)` |
| `snd_c400_create_effect_ret_vol_ctls` | function | `legacy/mixer_quirks.c:1694` | `static int snd_c400_create_effect_ret_vol_ctls(struct usb_mixer_interface *mixer)` |
| `snd_c400_create_effect_vol_ctls` | function | `legacy/mixer_quirks.c:1649` | `static int snd_c400_create_effect_vol_ctls(struct usb_mixer_interface *mixer)` |
| `snd_c400_create_effect_volume_ctl` | function | `legacy/mixer_quirks.c:1612` | `static int snd_c400_create_effect_volume_ctl(struct usb_mixer_interface *mixer)` |
| `snd_c400_create_mixer` | function | `legacy/mixer_quirks.c:1736` | `static int snd_c400_create_mixer(struct usb_mixer_interface *mixer)` |
| `snd_c400_create_vol_ctls` | function | `legacy/mixer_quirks.c:1563` | `static int snd_c400_create_vol_ctls(struct usb_mixer_interface *mixer)` |
| `snd_card_ro_proc_new` | function | `legacy/mixer_quirks.c:4264` | `snd_card_ro_proc_new(mixer->chip->card, "audigy2nx", mixer, snd_audigy2nx_proc_read);` |
| `snd_create_std_mono_ctl` | function | `legacy/mixer_quirks.c:112` | `static int snd_create_std_mono_ctl(struct usb_mixer_interface *mixer,
				   unsigned int unitid,...` |
| `snd_create_std_mono_ctl_offset` | function | `legacy/mixer_quirks.c:59` | `static int snd_create_std_mono_ctl_offset(struct usb_mixer_interface *mixer,
					  unsigned int ...` |
| `snd_create_std_mono_table` | function | `legacy/mixer_quirks.c:129` | `static int snd_create_std_mono_table(struct usb_mixer_interface *mixer,
				     const struct std...` |
| `snd_ctl_enum_info` | function | `legacy/mixer_quirks.c:461` | `return snd_ctl_enum_info(uinfo, 1, ARRAY_SIZE(texts), texts);` |
| `snd_ctl_notify` | function | `legacy/mixer_quirks.c:566` | `snd_ctl_notify(me->mixer->chip->card, SNDRV_CTL_EVENT_MASK_VALUE, &me->kctl->id);` |
| `snd_djm_controls_create` | function | `legacy/mixer_quirks.c:4203` | `static int snd_djm_controls_create(struct usb_mixer_interface *mixer,
				   const u8 device_idx)` |
| `snd_djm_controls_get` | function | `legacy/mixer_quirks.c:4169` | `static int snd_djm_controls_get(struct snd_kcontrol *kctl,
				struct snd_ctl_elem_value *elem)` |
| `snd_djm_controls_info` | function | `legacy/mixer_quirks.c:4116` | `static int snd_djm_controls_info(struct snd_kcontrol *kctl,
				 struct snd_ctl_elem_info *info)` |
| `snd_djm_controls_put` | function | `legacy/mixer_quirks.c:4176` | `static int snd_djm_controls_put(struct snd_kcontrol *kctl, struct snd_ctl_elem_value *elem)` |
| `snd_djm_controls_resume` | function | `legacy/mixer_quirks.c:4193` | `static int snd_djm_controls_resume(struct usb_mixer_elem_list *list)` |
| `snd_djm_controls_update` | function | `legacy/mixer_quirks.c:4148` | `static int snd_djm_controls_update(struct usb_mixer_interface *mixer,
				   u8 device_idx, u8 gr...` |
| `snd_djm_ctl` | struct | `legacy/mixer_quirks.c:3784` | `` |
| `snd_djm_device` | struct | `legacy/mixer_quirks.c:3778` | `` |
| `snd_djm_get_label` | function | `legacy/mixer_quirks.c:3884` | `static const char *snd_djm_get_label(u8 device_idx, u16 wvalue, u16 windex)` |
| `snd_djm_get_label_cap` | function | `legacy/mixer_quirks.c:3866` | `static const char *snd_djm_get_label_cap(u8 device_idx, u16 wvalue)` |
| `snd_djm_get_label_cap_850` | function | `legacy/mixer_quirks.c:3849` | `static const char *snd_djm_get_label_cap_850(u16 wvalue)` |
| `snd_djm_get_label_cap_common` | function | `legacy/mixer_quirks.c:3816` | `static const char *snd_djm_get_label_cap_common(u16 wvalue)` |
| `snd_djm_get_label_caplevel` | function | `legacy/mixer_quirks.c:3857` | `static const char *snd_djm_get_label_caplevel(u8 device_idx, u16 wvalue)` |
| `snd_djm_get_label_caplevel_common` | function | `legacy/mixer_quirks.c:3791` | `static const char *snd_djm_get_label_caplevel_common(u16 wvalue)` |
| `snd_djm_get_label_caplevel_high` | function | `legacy/mixer_quirks.c:3804` | `static const char *snd_djm_get_label_caplevel_high(u16 wvalue)` |
| `snd_djm_get_label_pb` | function | `legacy/mixer_quirks.c:3874` | `static const char *snd_djm_get_label_pb(u16 wvalue)` |
| `snd_dragonfly_quirk_db_scale` | function | `legacy/mixer_quirks.c:4457` | `static void snd_dragonfly_quirk_db_scale(struct usb_mixer_interface *mixer,
					 struct usb_mixe...` |
| `snd_dualsense_controls_create` | function | `legacy/mixer_quirks.c:777` | `static int snd_dualsense_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_dualsense_ih_connect` | function | `legacy/mixer_quirks.c:617` | `static int snd_dualsense_ih_connect(struct input_handler *handler,
				    struct input_dev *dev,...` |
| `snd_dualsense_ih_disconnect` | function | `legacy/mixer_quirks.c:649` | `static void snd_dualsense_ih_disconnect(struct input_handle *handle)` |
| `snd_dualsense_ih_event` | function | `legacy/mixer_quirks.c:549` | `static void snd_dualsense_ih_event(struct input_handle *handle,
				   unsigned int type, unsigne...` |
| `snd_dualsense_ih_match` | function | `legacy/mixer_quirks.c:570` | `static bool snd_dualsense_ih_match(struct input_handler *handler,
				   struct input_dev *dev)` |
| `snd_dualsense_ih_start` | function | `legacy/mixer_quirks.c:656` | `static void snd_dualsense_ih_start(struct input_handle *handle)` |
| `snd_dualsense_jack_create` | function | `legacy/mixer_quirks.c:713` | `static int snd_dualsense_jack_create(struct usb_mixer_interface *mixer,
				     const char *name...` |
| `snd_dualsense_jack_get` | function | `legacy/mixer_quirks.c:679` | `static int snd_dualsense_jack_get(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...` |
| `snd_dualsense_mixer_elem_free` | function | `legacy/mixer_quirks.c:703` | `static void snd_dualsense_mixer_elem_free(struct snd_kcontrol *kctl)` |
| `snd_dualsense_resume_jack` | function | `legacy/mixer_quirks.c:696` | `static int snd_dualsense_resume_jack(struct usb_mixer_elem_list *list)` |
| `snd_emu0204_ch_switch_get` | function | `legacy/mixer_quirks.c:464` | `static int snd_emu0204_ch_switch_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...` |
| `snd_emu0204_ch_switch_info` | function | `legacy/mixer_quirks.c:457` | `static int snd_emu0204_ch_switch_info(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_ele...` |
| `snd_emu0204_ch_switch_put` | function | `legacy/mixer_quirks.c:489` | `static int snd_emu0204_ch_switch_put(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...` |
| `snd_emu0204_ch_switch_resume` | function | `legacy/mixer_quirks.c:508` | `static int snd_emu0204_ch_switch_resume(struct usb_mixer_elem_list *list)` |
| `snd_emu0204_ch_switch_update` | function | `legacy/mixer_quirks.c:471` | `static int snd_emu0204_ch_switch_update(struct usb_mixer_interface *mixer,
					int value)` |
| `snd_emu0204_controls_create` | function | `legacy/mixer_quirks.c:523` | `static int snd_emu0204_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_emuusb_set_samplerate` | function | `legacy/mixer_quirks.c:1541` | `void snd_emuusb_set_samplerate(struct snd_usb_audio *chip,
			       unsigned char samplerate_id)` |
| `snd_fix_plt_name` | function | `legacy/mixer_quirks.c:4509` | `static void snd_fix_plt_name(struct snd_usb_audio *chip,
			     struct snd_ctl_elem_id *id)` |
| `snd_ftu_create_effect_duration_ctl` | function | `legacy/mixer_quirks.c:1425` | `static int snd_ftu_create_effect_duration_ctl(struct usb_mixer_interface *mixer)` |
| `snd_ftu_create_effect_feedback_ctl` | function | `legacy/mixer_quirks.c:1438` | `static int snd_ftu_create_effect_feedback_ctl(struct usb_mixer_interface *mixer)` |
| `snd_ftu_create_effect_return_ctls` | function | `legacy/mixer_quirks.c:1449` | `static int snd_ftu_create_effect_return_ctls(struct usb_mixer_interface *mixer)` |
| `snd_ftu_create_effect_send_ctls` | function | `legacy/mixer_quirks.c:1473` | `static int snd_ftu_create_effect_send_ctls(struct usb_mixer_interface *mixer)` |
| `snd_ftu_create_effect_switch` | function | `legacy/mixer_quirks.c:1346` | `static int snd_ftu_create_effect_switch(struct usb_mixer_interface *mixer,
					int validx, int b...` |
| `snd_ftu_create_effect_volume_ctl` | function | `legacy/mixer_quirks.c:1412` | `static int snd_ftu_create_effect_volume_ctl(struct usb_mixer_interface *mixer)` |
| `snd_ftu_create_mixer` | function | `legacy/mixer_quirks.c:1506` | `static int snd_ftu_create_mixer(struct usb_mixer_interface *mixer)` |
| `snd_ftu_create_volume_ctls` | function | `legacy/mixer_quirks.c:1373` | `static int snd_ftu_create_volume_ctls(struct usb_mixer_interface *mixer)` |
| `snd_ftu_eff_switch_get` | function | `legacy/mixer_quirks.c:1300` | `static int snd_ftu_eff_switch_get(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...` |
| `snd_ftu_eff_switch_info` | function | `legacy/mixer_quirks.c:1267` | `static int snd_ftu_eff_switch_info(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_info...` |
| `snd_ftu_eff_switch_init` | function | `legacy/mixer_quirks.c:1277` | `static int snd_ftu_eff_switch_init(struct usb_mixer_interface *mixer,
				   struct snd_kcontrol ...` |
| `snd_ftu_eff_switch_put` | function | `legacy/mixer_quirks.c:1328` | `static int snd_ftu_eff_switch_put(struct snd_kcontrol *kctl,
				  struct snd_ctl_elem_value *uco...` |
| `snd_ftu_eff_switch_update` | function | `legacy/mixer_quirks.c:1307` | `static int snd_ftu_eff_switch_update(struct usb_mixer_elem_list *list)` |
| `snd_iprintf` | function | `legacy/mixer_quirks.c:429` | `snd_iprintf(buffer, "%s jacks\n\n", mixer->chip->card->shortname);` |
| `snd_mbox1_clk_switch_get` | function | `legacy/mixer_quirks.c:933` | `static int snd_mbox1_clk_switch_get(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...` |
| `snd_mbox1_clk_switch_info` | function | `legacy/mixer_quirks.c:996` | `static int snd_mbox1_clk_switch_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...` |
| `snd_mbox1_clk_switch_put` | function | `legacy/mixer_quirks.c:978` | `static int snd_mbox1_clk_switch_put(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...` |
| `snd_mbox1_clk_switch_resume` | function | `legacy/mixer_quirks.c:1007` | `static int snd_mbox1_clk_switch_resume(struct usb_mixer_elem_list *list)` |
| `snd_mbox1_clk_switch_update` | function | `legacy/mixer_quirks.c:953` | `static int snd_mbox1_clk_switch_update(struct usb_mixer_interface *mixer, int is_spdif_sync)` |
| `snd_mbox1_controls_create` | function | `legacy/mixer_quirks.c:1101` | `static int snd_mbox1_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_mbox1_is_spdif_input` | function | `legacy/mixer_quirks.c:894` | `static int snd_mbox1_is_spdif_input(struct snd_usb_audio *chip)` |
| `snd_mbox1_is_spdif_synced` | function | `legacy/mixer_quirks.c:856` | `static int snd_mbox1_is_spdif_synced(struct snd_usb_audio *chip)` |
| `snd_mbox1_set_clk_source` | function | `legacy/mixer_quirks.c:876` | `static int snd_mbox1_set_clk_source(struct snd_usb_audio *chip, int rate_or_zero)` |
| `snd_mbox1_set_input_source` | function | `legacy/mixer_quirks.c:914` | `static int snd_mbox1_set_input_source(struct snd_usb_audio *chip, int is_spdif)` |
| `snd_mbox1_src_switch_get` | function | `legacy/mixer_quirks.c:1014` | `static int snd_mbox1_src_switch_get(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...` |
| `snd_mbox1_src_switch_info` | function | `legacy/mixer_quirks.c:1063` | `static int snd_mbox1_src_switch_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...` |
| `snd_mbox1_src_switch_put` | function | `legacy/mixer_quirks.c:1045` | `static int snd_mbox1_src_switch_put(struct snd_kcontrol *kctl,
				    struct snd_ctl_elem_value ...` |
| `snd_mbox1_src_switch_resume` | function | `legacy/mixer_quirks.c:1074` | `static int snd_mbox1_src_switch_resume(struct usb_mixer_elem_list *list)` |
| `snd_mbox1_src_switch_update` | function | `legacy/mixer_quirks.c:1021` | `static int snd_mbox1_src_switch_update(struct usb_mixer_interface *mixer, int is_spdif_input)` |
| `snd_microii_controls_create` | function | `legacy/mixer_quirks.c:2067` | `static int snd_microii_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_microii_spdif_default_get` | function | `legacy/mixer_quirks.c:1876` | `static int snd_microii_spdif_default_get(struct snd_kcontrol *kcontrol,
					 struct snd_ctl_elem...` |
| `snd_microii_spdif_default_put` | function | `legacy/mixer_quirks.c:1959` | `static int snd_microii_spdif_default_put(struct snd_kcontrol *kcontrol,
					 struct snd_ctl_elem...` |
| `snd_microii_spdif_default_update` | function | `legacy/mixer_quirks.c:1923` | `static int snd_microii_spdif_default_update(struct usb_mixer_elem_list *list)` |
| `snd_microii_spdif_info` | function | `legacy/mixer_quirks.c:1869` | `static int snd_microii_spdif_info(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_info *...` |
| `snd_microii_spdif_mask_get` | function | `legacy/mixer_quirks.c:1987` | `static int snd_microii_spdif_mask_get(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_ele...` |
| `snd_microii_spdif_switch_get` | function | `legacy/mixer_quirks.c:1998` | `static int snd_microii_spdif_switch_get(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_v...` |
| `snd_microii_spdif_switch_put` | function | `legacy/mixer_quirks.c:2025` | `static int snd_microii_spdif_switch_put(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_v...` |
| `snd_microii_spdif_switch_update` | function | `legacy/mixer_quirks.c:2006` | `static int snd_microii_spdif_switch_update(struct usb_mixer_elem_list *list)` |
| `snd_nativeinstruments_control_get` | function | `legacy/mixer_quirks.c:1142` | `static int snd_nativeinstruments_control_get(struct snd_kcontrol *kcontrol,
					     struct snd_...` |
| `snd_nativeinstruments_control_put` | function | `legacy/mixer_quirks.c:1163` | `static int snd_nativeinstruments_control_put(struct snd_kcontrol *kcontrol,
					     struct snd_...` |
| `snd_nativeinstruments_create_mixer` | function | `legacy/mixer_quirks.c:1234` | `static int snd_nativeinstruments_create_mixer(struct usb_mixer_interface *mixer,
					      const...` |
| `snd_ni_control_init_val` | function | `legacy/mixer_quirks.c:1120` | `static int snd_ni_control_init_val(struct usb_mixer_interface *mixer,
				   struct snd_kcontrol ...` |
| `snd_ni_update_cur_val` | function | `legacy/mixer_quirks.c:1149` | `static int snd_ni_update_cur_val(struct usb_mixer_elem_list *list)` |
| `snd_rme_clock_status` | enum | `legacy/mixer_quirks.c:2413` | `` |
| `snd_rme_controls_create` | function | `legacy/mixer_quirks.c:2713` | `static int snd_rme_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_rme_current_freq_get` | function | `legacy/mixer_quirks.c:2552` | `static int snd_rme_current_freq_get(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_va...` |
| `snd_rme_digiface_controls_create` | function | `legacy/mixer_quirks.c:3684` | `static int snd_rme_digiface_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_rme_digiface_current_sync_get` | function | `legacy/mixer_quirks.c:3438` | `static int snd_rme_digiface_current_sync_get(struct snd_kcontrol *kcontrol,
					     struct snd_...` |
| `snd_rme_digiface_enum_get` | function | `legacy/mixer_quirks.c:3412` | `static int snd_rme_digiface_enum_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...` |
| `snd_rme_digiface_enum_put` | function | `legacy/mixer_quirks.c:3424` | `static int snd_rme_digiface_enum_put(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...` |
| `snd_rme_digiface_format_info` | function | `legacy/mixer_quirks.c:3473` | `static int snd_rme_digiface_format_info(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_i...` |
| `snd_rme_digiface_get_status_val` | function | `legacy/mixer_quirks.c:3360` | `static int snd_rme_digiface_get_status_val(struct snd_kcontrol *kcontrol)` |
| `snd_rme_digiface_rate_get` | function | `legacy/mixer_quirks.c:3398` | `static int snd_rme_digiface_rate_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...` |
| `snd_rme_digiface_rate_info` | function | `legacy/mixer_quirks.c:3495` | `static int snd_rme_digiface_rate_info(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_ele...` |
| `snd_rme_digiface_read_status` | function | `legacy/mixer_quirks.c:3336` | `static int snd_rme_digiface_read_status(struct snd_kcontrol *kcontrol, u32 status[4])` |
| `snd_rme_digiface_sync_source_info` | function | `legacy/mixer_quirks.c:3484` | `static int snd_rme_digiface_sync_source_info(struct snd_kcontrol *kcontrol,
					     struct snd_...` |
| `snd_rme_digiface_sync_state_get` | function | `legacy/mixer_quirks.c:3450` | `static int snd_rme_digiface_sync_state_get(struct snd_kcontrol *kcontrol,
					   struct snd_ctl_...` |
| `snd_rme_digiface_write_reg` | function | `legacy/mixer_quirks.c:3318` | `static int snd_rme_digiface_write_reg(struct snd_kcontrol *kcontrol, int item, u16 mask, u16 val)` |
| `snd_rme_domain` | enum | `legacy/mixer_quirks.c:2407` | `` |
| `snd_rme_get_status1` | function | `legacy/mixer_quirks.c:2437` | `static int snd_rme_get_status1(struct snd_kcontrol *kcontrol,
			       u32 *status1)` |
| `snd_rme_rate_get` | function | `legacy/mixer_quirks.c:2449` | `static int snd_rme_rate_get(struct snd_kcontrol *kcontrol,
			    struct snd_ctl_elem_value *ucon...` |
| `snd_rme_rate_info` | function | `legacy/mixer_quirks.c:2578` | `static int snd_rme_rate_info(struct snd_kcontrol *kcontrol,
			     struct snd_ctl_elem_info *uinfo)` |
| `snd_rme_read_value` | function | `legacy/mixer_quirks.c:2418` | `static int snd_rme_read_value(struct snd_usb_audio *chip,
			      unsigned int item,
			      u3...` |
| `snd_rme_spdif_format_get` | function | `legacy/mixer_quirks.c:2526` | `static int snd_rme_spdif_format_get(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_va...` |
| `snd_rme_spdif_format_info` | function | `legacy/mixer_quirks.c:2620` | `static int snd_rme_spdif_format_info(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_...` |
| `snd_rme_spdif_if_get` | function | `legacy/mixer_quirks.c:2513` | `static int snd_rme_spdif_if_get(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *uco...` |
| `snd_rme_spdif_if_info` | function | `legacy/mixer_quirks.c:2609` | `static int snd_rme_spdif_if_info(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_info *ui...` |
| `snd_rme_sync_source_get` | function | `legacy/mixer_quirks.c:2539` | `static int snd_rme_sync_source_get(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...` |
| `snd_rme_sync_source_info` | function | `legacy/mixer_quirks.c:2631` | `static int snd_rme_sync_source_info(struct snd_kcontrol *kcontrol,
				    struct snd_ctl_elem_in...` |
| `snd_rme_sync_state_get` | function | `legacy/mixer_quirks.c:2483` | `static int snd_rme_sync_state_get(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_value ...` |
| `snd_rme_sync_state_info` | function | `legacy/mixer_quirks.c:2598` | `static int snd_rme_sync_state_info(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_info...` |
| `snd_soundblaster_e1_switch_create` | function | `legacy/mixer_quirks.c:2154` | `static int snd_soundblaster_e1_switch_create(struct usb_mixer_interface *mixer)` |
| `snd_soundblaster_e1_switch_get` | function | `legacy/mixer_quirks.c:2090` | `static int snd_soundblaster_e1_switch_get(struct snd_kcontrol *kcontrol,
					  struct snd_ctl_el...` |
| `snd_soundblaster_e1_switch_info` | function | `legacy/mixer_quirks.c:2135` | `static int snd_soundblaster_e1_switch_info(struct snd_kcontrol *kcontrol,
					   struct snd_ctl_...` |
| `snd_soundblaster_e1_switch_put` | function | `legacy/mixer_quirks.c:2115` | `static int snd_soundblaster_e1_switch_put(struct snd_kcontrol *kcontrol,
					  struct snd_ctl_el...` |
| `snd_soundblaster_e1_switch_resume` | function | `legacy/mixer_quirks.c:2129` | `static int snd_soundblaster_e1_switch_resume(struct usb_mixer_elem_list *list)` |
| `snd_soundblaster_e1_switch_update` | function | `legacy/mixer_quirks.c:2097` | `static int snd_soundblaster_e1_switch_update(struct usb_mixer_interface *mixer,
					     unsigne...` |
| `snd_usb_ctl_msg` | function | `legacy/mixer_quirks.c:484` | `return snd_usb_ctl_msg(chip->dev, usb_sndctrlpipe(chip->dev, 0), UAC_SET_CUR, USB_RECIP_INTERFACE \| USB_TYPE_CLASS \| U` |
| `snd_usb_ctrl_intf` | function | `legacy/mixer_quirks.c:1292` | `snd_usb_ctrl_intf(mixer->hostif) \| ((pval & 0xff) << 8), value, 2);` |
| `snd_usb_mixer_add_control` | function | `legacy/mixer_quirks.c:110` | `return snd_usb_mixer_add_control(&cval->head, kctl);` |
| `snd_usb_mixer_add_list` | function | `legacy/mixer_quirks.c:170` | `return snd_usb_mixer_add_list(list, kctl, false);` |
| `snd_usb_mixer_apply_create_quirk` | function | `legacy/mixer_quirks.c:4238` | `int snd_usb_mixer_apply_create_quirk(struct usb_mixer_interface *mixer)` |
| `snd_usb_mixer_elem_free` | function | `legacy/mixer_quirks.c:710` | `snd_usb_mixer_elem_free(kctl);` |
| `snd_usb_mixer_elem_init_std` | function | `legacy/mixer_quirks.c:74` | `snd_usb_mixer_elem_init_std(&cval->head, mixer, unitid);` |
| `snd_usb_mixer_fu_apply_quirk` | function | `legacy/mixer_quirks.c:4538` | `void snd_usb_mixer_fu_apply_quirk(struct usb_mixer_interface *mixer,
				  struct usb_mixer_elem_...` |
| `snd_usb_mixer_notify_id` | function | `legacy/mixer_quirks.c:1555` | `snd_usb_mixer_notify_id(mixer, unitid);` |
| `snd_usb_mixer_rc_memory_change` | function | `legacy/mixer_quirks.c:4429` | `void snd_usb_mixer_rc_memory_change(struct usb_mixer_interface *mixer,
				    int unitid)` |
| `snd_usb_mixer_resume_quirk` | function | `legacy/mixer_quirks.c:4420` | `void snd_usb_mixer_resume_quirk(struct usb_mixer_interface *mixer)` |
| `snd_usb_mixer_set_ctl_value` | function | `legacy/mixer_quirks.c:1552` | `snd_usb_mixer_set_ctl_value(cval, UAC_SET_CUR, cval->control << 8, samplerate_id);` |
| `snd_usb_sbrc_hwdep_poll` | function | `legacy/mixer_quirks.c:239` | `static __poll_t snd_usb_sbrc_hwdep_poll(struct snd_hwdep *hw, struct file *file,
					poll_table ...` |
| `snd_usb_sbrc_hwdep_read` | function | `legacy/mixer_quirks.c:219` | `static long snd_usb_sbrc_hwdep_read(struct snd_hwdep *hw, char __user *buf,
				    long count, l...` |
| `snd_usb_soundblaster_remote_complete` | function | `legacy/mixer_quirks.c:199` | `static void snd_usb_soundblaster_remote_complete(struct urb *urb)` |
| `snd_usb_soundblaster_remote_init` | function | `legacy/mixer_quirks.c:248` | `static int snd_usb_soundblaster_remote_init(struct usb_mixer_interface *mixer)` |
| `snd_xonar_u1_controls_create` | function | `legacy/mixer_quirks.c:847` | `static int snd_xonar_u1_controls_create(struct usb_mixer_interface *mixer)` |
| `snd_xonar_u1_switch_get` | function | `legacy/mixer_quirks.c:791` | `static int snd_xonar_u1_switch_get(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...` |
| `snd_xonar_u1_switch_put` | function | `legacy/mixer_quirks.c:812` | `static int snd_xonar_u1_switch_put(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_valu...` |
| `snd_xonar_u1_switch_resume` | function | `legacy/mixer_quirks.c:832` | `static int snd_xonar_u1_switch_resume(struct usb_mixer_elem_list *list)` |
| `snd_xonar_u1_switch_update` | function | `legacy/mixer_quirks.c:798` | `static int snd_xonar_u1_switch_update(struct usb_mixer_interface *mixer,
				      unsigned char ...` |
| `snprintf` | function | `legacy/mixer_quirks.c:99` | `snprintf(kctl->id.name, sizeof(kctl->id.name), name);` |
| `std_mono_table` | struct | `legacy/mixer_quirks.c:45` | `` |
| `strscpy` | function | `legacy/mixer_quirks.c:741` | `strscpy(kctl->id.name, name, sizeof(kctl->id.name));` |
| `usb_audio_dbg` | function | `legacy/mixer_quirks.c:4452` | `default: usb_audio_dbg(mixer->chip, "memory change in unknown unit %d\n", unitid);` |
| `usb_audio_info` | function | `legacy/mixer_quirks.c:4479` | `usb_audio_info(mixer->chip, "applying DragonFly dB scale quirk (0-50 variant)\n");` |
| `usb_control_msg` | function | `legacy/mixer_quirks.c:1158` | `return usb_control_msg(chip->dev, usb_sndctrlpipe(chip->dev, 0), (pval >> 16) & 0xff, USB_TYPE_VENDOR \| USB_RECIP_DEVIC` |
| `usb_fill_control_urb` | function | `legacy/mixer_quirks.c:290` | `usb_fill_control_urb(mixer->rc_urb, mixer->chip->dev, usb_rcvctrlpipe(mixer->chip->dev, 0), (u8 *)mixer->rc_setup_packet` |
| `usb_free_urb` | function | `legacy/mixer_quirks.c:280` | `usb_free_urb(mixer->rc_urb);` |
| `usb_rcvctrlpipe` | function | `legacy/mixer_quirks.c:445` | `usb_rcvctrlpipe(mixer->chip->dev, 0), UAC_GET_MEM, USB_DIR_IN \| USB_TYPE_CLASS \| USB_RECIP_INTERFACE, 0, jacks[i].unit` |
| `usb_sndctrlpipe` | function | `legacy/mixer_quirks.c:328` | `usb_sndctrlpipe(chip->dev, 0), 0x24, USB_DIR_OUT \| USB_TYPE_VENDOR \| USB_RECIP_OTHER, value, index + 2, NULL, 0);` |
| `usb_submit_urb` | function | `legacy/mixer_quirks.c:4439` | `usb_submit_urb(mixer->rc_urb, GFP_ATOMIC);` |
| `wake_up` | function | `legacy/mixer_quirks.c:217` | `wake_up(&mixer->rc_waitq);` |
| `VSL_Close_Device` | function | `legacy/test_connection.c:19` | `VSL_Close_Device();` |
| `main` | function | `legacy/test_connection.c:6` | `int main()` |
| `printf` | function | `legacy/test_connection.c:8` | `printf("Intentando conectar al dispositivo VSL %04X:%04X...\n", VSL_VENDOR_ID, VSL_PRODUCT_ID);` |
| `VSL_CONFIG_H` | macro | `legacy/vsl_config.h:4` | `#define VSL_CONFIG_H` |
| `VSL_MAX_ENCODED_INT` | macro | `legacy/vsl_config.h:23` | `#define VSL_MAX_ENCODED_INT` |
| `VSL_PACKET_SIZE` | macro | `legacy/vsl_config.h:24` | `#define VSL_PACKET_SIZE` |
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
| `exp2f` | function | `legacy/vsl_dsp_logic.c:46` | `return exp2f(log2_value);` |
| `VSL_DSP_LOGIC_H` | macro | `legacy/vsl_dsp_logic.h:2` | `#define VSL_DSP_LOGIC_H` |
| `VSL_Decode_Frequency` | function | `legacy/vsl_dsp_logic.h:73` | `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);` |
| `VSL_Encode_Gain` | function | `legacy/vsl_dsp_logic.h:42` | `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);` |
| `VSL_Final_Encode_To_Int` | function | `legacy/vsl_dsp_logic.h:60` | `uint32_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param);` |
| `VSL_INV_LN2` | macro | `legacy/vsl_dsp_logic.h:10` | `#define VSL_INV_LN2` |
| `VSL_Map_Frequency` | function | `legacy/vsl_dsp_logic.h:50` | `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);` |
| `VSL_Parameter` | struct | `legacy/vsl_dsp_logic.h:13` | `` |
| `FUN_Send_Packet` | function | `legacy/vsl_dsp_transport.c:97` | `void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length)` |
| `VSL_Build_And_Send_Packet` | function | `legacy/vsl_dsp_transport.c:140` | `void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float)` |
| `VSL_Close_Device` | function | `legacy/vsl_dsp_transport.c:69` | `void VSL_Close_Device(void)` |
| `VSL_Get_Device_Handle` | function | `legacy/vsl_dsp_transport.c:78` | `hid_device* VSL_Get_Device_Handle(void)` |
| `VSL_Init_Device` | function | `legacy/vsl_dsp_transport.c:22` | `int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)` |
| `fprintf` | function | `legacy/vsl_dsp_transport.c:28` | `fprintf(stderr, "Error: HIDAPI init failed\n");` |
| `free` | function | `legacy/vsl_dsp_transport.c:55` | `free(target_path);` |
| `hid_close` | function | `legacy/vsl_dsp_transport.c:72` | `hid_close(vsl_device_handle);` |
| `hid_exit` | function | `legacy/vsl_dsp_transport.c:62` | `hid_exit();` |
| `hid_free_enumeration` | function | `legacy/vsl_dsp_transport.c:49` | `hid_free_enumeration(devs);` |
| `memcpy` | function | `legacy/vsl_dsp_transport.c:121` | `memcpy(&buf[1], &net_id, sizeof(uint16_t));` |
| `printf` | function | `legacy/vsl_dsp_transport.c:65` | `printf("VSL Device handle opened successfully via path: %04X:%04X\n", vendor_id, product_id);` |
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
| `MAX_CHANNELS` | macro | `src/vsl_cli.c:47` | `#define MAX_CHANNELS` |
| `ParamEntry` | struct | `src/vsl_cli.c:15` | `` |
| `VSL_Close_Device` | function | `src/vsl_cli.c:163` | `VSL_Close_Device(dev);` |
| `do_send` | function | `src/vsl_cli.c:129` | `static int do_send(uint16_t product_id,
                   uint16_t param_id,
                   ...` |
| `do_send_freq` | function | `src/vsl_cli.c:167` | `static int do_send_freq(uint16_t product_id,
                        uint16_t param_id,
         ...` |
| `find_entry_by_name` | function | `src/vsl_cli.c:119` | `static const ParamEntry *
find_entry_by_name(const char *name)` |
| `fmaxf` | function | `src/vsl_cli.c:186` | `fmaxf(0.0f, fminf(freq_hz / coeffs->freq_max_hz, 1.0f)), coeffs);` |
| `fprintf` | function | `src/vsl_cli.c:60` | `fprintf(fp, "Usage: %s [OPTIONS] COMMAND [ARGS...]\n" "\n" "Options:\n" " -p, --pid <hex> USB product ID (default: 0x010` |
| `lookup_coeffs_by_param_id` | function | `src/vsl_cli.c:109` | `static const VSL_Parameter *
lookup_coeffs_by_param_id(uint16_t param_id)` |
| `main` | function | `src/vsl_cli.c:204` | `int main(int argc, char *argv[])` |
| `print_list` | function | `src/vsl_cli.c:90` | `static void print_list(uint16_t product_id)` |
| `print_usage` | function | `src/vsl_cli.c:57` | `static void print_usage(FILE *fp, const char *prog)` |
| `print_version` | function | `src/vsl_cli.c:83` | `static void print_version(void)` |
| `printf` | function | `src/vsl_cli.c:86` | `printf("vsl-cli 2.0.0\n" "PreSonus AudioBox VSL DSP control tool\n" "License: AGPL-3.0-or-later\n");` |
| `VSL_CONFIG_H` | macro | `src/vsl_config.h:2` | `#define VSL_CONFIG_H` |
| `VSL_EP_MIDI_OUT` | macro | `src/vsl_config.h:19` | `#define VSL_EP_MIDI_OUT` |
| `VSL_MIDI_IFACE` | macro | `src/vsl_config.h:18` | `#define VSL_MIDI_IFACE` |
| `VSL_ModelInfo` | struct | `src/vsl_config.h:21` | `` |
| `VSL_ModelLookup` | function | `src/vsl_config.h:35` | `static inline const VSL_ModelInfo *
VSL_ModelLookup(uint16_t pid)` |
| `VSL_ModelLookupByTag` | function | `src/vsl_config.h:47` | `static inline const VSL_ModelInfo *
VSL_ModelLookupByTag(const char *tag)` |
| `VSL_PACKET_SIZE` | macro | `src/vsl_config.h:17` | `#define VSL_PACKET_SIZE` |
| `VSL_PRODUCT_ID_1818VSL` | macro | `src/vsl_config.h:14` | `#define VSL_PRODUCT_ID_1818VSL` |
| `VSL_PRODUCT_ID_22VSL` | macro | `src/vsl_config.h:12` | `#define VSL_PRODUCT_ID_22VSL` |
| `VSL_PRODUCT_ID_44VSL` | macro | `src/vsl_config.h:13` | `#define VSL_PRODUCT_ID_44VSL` |
| `VSL_REPORT_ID` | macro | `src/vsl_config.h:15` | `#define VSL_REPORT_ID` |
| `VSL_VENDOR_ID` | macro | `src/vsl_config.h:10` | `#define VSL_VENDOR_ID` |
| `pid` | variable | `src/vsl_config.h:8` | `extern "C" { #endif #define VSL_VENDOR_ID 0x194fU #define VSL_PRODUCT_ID_22VSL 0x0101U #define VSL_PRODUCT_ID_44VSL 0x01` |
| `VSL_Decode_Frequency` | function | `src/vsl_dsp_logic.c:75` | `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param)` |
| `VSL_Decode_Gain` | function | `src/vsl_dsp_logic.c:15` | `float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param)` |
| `VSL_Encode_Gain` | function | `src/vsl_dsp_logic.c:2` | `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param)` |
| `VSL_Final_Encode_To_Int` | function | `src/vsl_dsp_logic.c:65` | `uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param)` |
| `VSL_Map_Frequency` | function | `src/vsl_dsp_logic.c:49` | `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param)` |
| `exp2f` | function | `src/vsl_dsp_logic.c:62` | `return exp2f(log2_value);` |
| `fmaxf` | function | `src/vsl_dsp_logic.c:20` | `return fmaxf(0.0f, fminf(r, 1.0f));` |
| `VSL_DSP_LOGIC_H` | macro | `src/vsl_dsp_logic.h:2` | `#define VSL_DSP_LOGIC_H` |
| `VSL_Decode_Frequency` | function | `src/vsl_dsp_logic.h:60` | `float VSL_Decode_Frequency(float freq_hz_value, const VSL_Parameter *param);` |
| `VSL_Decode_Gain` | function | `src/vsl_dsp_logic.h:42` | `float VSL_Decode_Gain(float encoded_float, const VSL_Parameter *param);` |
| `VSL_Encode_Gain` | function | `src/vsl_dsp_logic.h:33` | `float VSL_Encode_Gain(float linear_value, const VSL_Parameter *param);` |
| `VSL_Final_Encode_To_Int` | function | `src/vsl_dsp_logic.h:70` | `uint16_t VSL_Final_Encode_To_Int(float encoded_float, const VSL_Parameter *param);` |
| `VSL_INV_LN2` | macro | `src/vsl_dsp_logic.h:7` | `#define VSL_INV_LN2` |
| `VSL_MAX_ENCODED_FLOAT` | macro | `src/vsl_dsp_logic.h:9` | `#define VSL_MAX_ENCODED_FLOAT` |
| `VSL_Map_Frequency` | function | `src/vsl_dsp_logic.h:51` | `float VSL_Map_Frequency(float linear_position, const VSL_Parameter *param);` |
| `VSL_Parameter` | struct | `src/vsl_dsp_logic.h:11` | `` |
| `VSL_Close_Device` | function | `src/vsl_dsp_transport.c:44` | `void VSL_Close_Device(vsl_device_handle handle)` |
| `VSL_Init_Device` | function | `src/vsl_dsp_transport.c:12` | `vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)` |
| `VSL_Send_Parameter` | function | `src/vsl_dsp_transport.c:60` | `int VSL_Send_Parameter(vsl_device_handle handle,
                       uint16_t dsp_param_id,
  ...` |
| `fprintf` | function | `src/vsl_dsp_transport.c:83` | `fprintf(stderr, "VSL_Send_Parameter: bulk write failed: %s\n", libusb_error_name(ret));` |
| `free` | function | `src/vsl_dsp_transport.c:21` | `free(dev);` |
| `libusb_attach_kernel_driver` | function | `src/vsl_dsp_transport.c:54` | `libusb_attach_kernel_driver(dev->handle, VSL_MIDI_IFACE);` |
| `libusb_claim_interface` | function | `src/vsl_dsp_transport.c:40` | `libusb_claim_interface(dev->handle, VSL_MIDI_IFACE);` |
| `libusb_close` | function | `src/vsl_dsp_transport.c:55` | `libusb_close(dev->handle);` |
| `libusb_detach_kernel_driver` | function | `src/vsl_dsp_transport.c:38` | `libusb_detach_kernel_driver(dev->handle, VSL_MIDI_IFACE);` |
| `libusb_exit` | function | `src/vsl_dsp_transport.c:27` | `libusb_exit(NULL);` |
| `libusb_release_interface` | function | `src/vsl_dsp_transport.c:53` | `libusb_release_interface(dev->handle, VSL_MIDI_IFACE);` |
| `libusb_set_auto_detach_kernel_driver` | function | `src/vsl_dsp_transport.c:34` | `libusb_set_auto_detach_kernel_driver(dev->handle, 1);` |
| `memset` | function | `src/vsl_dsp_transport.c:72` | `memset(buf, 0, sizeof(buf));` |
| `vsl_device` | struct | `src/vsl_dsp_transport.c:7` | `` |
| `VSL_Close_Device` | function | `src/vsl_dsp_transport.h:26` | `void VSL_Close_Device(vsl_device_handle handle);` |
| `VSL_DSP_TRANSPORT_H` | macro | `src/vsl_dsp_transport.h:2` | `#define VSL_DSP_TRANSPORT_H` |
| `VSL_Init_Device` | function | `src/vsl_dsp_transport.h:20` | `vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id);` |
| `VSL_Send_Parameter` | function | `src/vsl_dsp_transport.h:35` | `int VSL_Send_Parameter(vsl_device_handle handle, uint16_t dsp_param_id, uint16_t encoded_value);` |
| `vsl_device_handle` | variable | `src/vsl_dsp_transport.h:9` | `extern "C" { #endif typedef void* vsl_device_handle;` |
| `vsl_device_handle` | type_alias | `src/vsl_dsp_transport.h:11` | `typedef void* vsl_device_handle;` |
| `assert_int_equal` | function | `tests/test_audiobox_vsl.c:28` | `assert_int_equal(AUDIOBOX_VENDOR_ID, 0x194fU);` |
| `assert_int_not_equal` | function | `tests/test_audiobox_vsl.c:121` | `assert_int_not_equal(audiobox_models[i].pid, audiobox_models[j].pid);` |
| `assert_non_null` | function | `tests/test_audiobox_vsl.c:60` | `assert_non_null(m);` |
| `assert_null` | function | `tests/test_audiobox_vsl.c:88` | `assert_null(audiobox_lookup_model(0x0000U));` |
| `assert_string_equal` | function | `tests/test_audiobox_vsl.c:39` | `assert_string_equal(m[0].product_name, "AudioBox 22 VSL");` |
| `assert_true` | function | `tests/test_audiobox_vsl.c:132` | `assert_true(audiobox_models[i].product_name[0] != '\0');` |
| `cmocka_run_group_tests` | function | `tests/test_audiobox_vsl.c:150` | `return cmocka_run_group_tests(tests, NULL, NULL);` |
| `main` | function | `tests/test_audiobox_vsl.c:135` | `int main(void)` |
| `test_lookup_handles_full_pid_range` | function | `tests/test_audiobox_vsl.c:94` | `static void test_lookup_handles_full_pid_range(void **state)` |
| `test_lookup_returns_1818_vsl` | function | `tests/test_audiobox_vsl.c:74` | `static void test_lookup_returns_1818_vsl(void **state)` |
| `test_lookup_returns_22_vsl` | function | `tests/test_audiobox_vsl.c:54` | `static void test_lookup_returns_22_vsl(void **state)` |
| `test_lookup_returns_44_vsl` | function | `tests/test_audiobox_vsl.c:64` | `static void test_lookup_returns_44_vsl(void **state)` |
| `test_lookup_returns_null_for_unknown_pid` | function | `tests/test_audiobox_vsl.c:84` | `static void test_lookup_returns_null_for_unknown_pid(void **state)` |
| `test_model_pids_match_table` | function | `tests/test_audiobox_vsl.c:45` | `static void test_model_pids_match_table(void **state)` |
| `test_supported_models_table_shape` | function | `tests/test_audiobox_vsl.c:30` | `static void test_supported_models_table_shape(void **state)` |
| `test_table_pids_are_unique` | function | `tests/test_audiobox_vsl.c:114` | `static void test_table_pids_are_unique(void **state)` |
| `test_table_product_names_non_empty` | function | `tests/test_audiobox_vsl.c:125` | `static void test_table_product_names_non_empty(void **state)` |
| `assert_float_equal` | function | `tests/test_vsl_dsp_logic.c:25` | `assert_float_equal(VSL_Encode_Gain(0.5f, &param), 1.6487212707f, 1e-5f);` |
| `assert_int_equal` | function | `tests/test_vsl_dsp_logic.c:116` | `assert_int_equal(VSL_Final_Encode_To_Int(0.75f, &param), 49);` |
| `assert_true` | function | `tests/test_vsl_dsp_logic.c:325` | `assert_true(result >= 0.0f);` |
| `cmocka_run_group_tests` | function | `tests/test_vsl_dsp_logic.c:346` | `return cmocka_run_group_tests(tests, NULL, NULL);` |
| `main` | function | `tests/test_vsl_dsp_logic.c:328` | `int main(void)` |
| `test_VSL_Decode_Frequency` | function | `tests/test_vsl_dsp_logic.c:67` | `static void test_VSL_Decode_Frequency(void **state)` |
| `test_VSL_Decode_Gain_c1_zero` | function | `tests/test_vsl_dsp_logic.c:127` | `static void test_VSL_Decode_Gain_c1_zero(void **state)` |
| `test_VSL_Decode_Gain_clamps_output` | function | `tests/test_vsl_dsp_logic.c:308` | `static void test_VSL_Decode_Gain_clamps_output(void **state)` |
| `test_VSL_Decode_Gain_custom_range_roundtrip` | function | `tests/test_vsl_dsp_logic.c:261` | `static void test_VSL_Decode_Gain_custom_range_roundtrip(void **state)` |
| `test_VSL_Decode_Gain_encoded_below_offset` | function | `tests/test_vsl_dsp_logic.c:163` | `static void test_VSL_Decode_Gain_encoded_below_offset(void **state)` |
| `test_VSL_Decode_Gain_encoded_equals_offset` | function | `tests/test_vsl_dsp_logic.c:289` | `static void test_VSL_Decode_Gain_encoded_equals_offset(void **state)` |
| `test_VSL_Decode_Gain_log_factor_zero` | function | `tests/test_vsl_dsp_logic.c:145` | `static void test_VSL_Decode_Gain_log_factor_zero(void **state)` |
| `test_VSL_Decode_Gain_range_zero` | function | `tests/test_vsl_dsp_logic.c:182` | `static void test_VSL_Decode_Gain_range_zero(void **state)` |
| `test_VSL_Decode_Gain_roundtrip_75` | function | `tests/test_vsl_dsp_logic.c:241` | `static void test_VSL_Decode_Gain_roundtrip_75(void **state)` |
| `test_VSL_Decode_Gain_roundtrip_extremes` | function | `tests/test_vsl_dsp_logic.c:220` | `static void test_VSL_Decode_Gain_roundtrip_extremes(void **state)` |
| `test_VSL_Decode_Gain_roundtrip_mid` | function | `tests/test_vsl_dsp_logic.c:200` | `static void test_VSL_Decode_Gain_roundtrip_mid(void **state)` |
| `test_VSL_Encode_Gain` | function | `tests/test_vsl_dsp_logic.c:8` | `static void test_VSL_Encode_Gain(void **state)` |
| `test_VSL_Final_Encode_To_Int` | function | `tests/test_vsl_dsp_logic.c:99` | `static void test_VSL_Final_Encode_To_Int(void **state)` |
| `test_VSL_Map_Frequency` | function | `tests/test_vsl_dsp_logic.c:35` | `static void test_VSL_Map_Frequency(void **state)` |
| `_GNU_SOURCE` | macro | `voicecloak/src/vc_alsa.c:1` | `#define _GNU_SOURCE` |
| `fmt_bps` | function | `voicecloak/src/vc_alsa.c:19` | `static size_t fmt_bps(snd_pcm_format_t f)` |
| `fprintf` | function | `voicecloak/src/vc_alsa.c:37` | `fprintf(stderr, "vc_alsa: cannot open %s device '%s': %s\n", tag, dev, snd_strerror(err));` |
| `free` | function | `voicecloak/src/vc_alsa.c:183` | `free(name);` |
| `memcpy` | function | `voicecloak/src/vc_alsa.c:108` | `memcpy(&x, base, sizeof(x));` |
| `memset` | function | `voicecloak/src/vc_alsa.c:236` | `memset(raw_out, 0, (size_t)period * play.channels * play.bps);` |
| `mono_to_raw` | function | `voicecloak/src/vc_alsa.c:129` | `static void mono_to_raw(unsigned char *raw, const float *mono,
                        snd_pcm_uf...` |
| `open_stream` | function | `voicecloak/src/vc_alsa.c:28` | `static int open_stream(vc_pcm_t *s, const char *dev, snd_pcm_stream_t dir,
                      ...` |
| `printf` | function | `voicecloak/src/vc_alsa.c:169` | `printf("Available ALSA PCM devices:\n");` |
| `raw_to_mono` | function | `voicecloak/src/vc_alsa.c:98` | `static void raw_to_mono(const unsigned char *raw, float *mono,
                        snd_pcm_uf...` |
| `snd_device_name_free_hint` | function | `voicecloak/src/vc_alsa.c:185` | `snd_device_name_free_hint(hints);` |
| `snd_pcm_hw_params_alloca` | function | `voicecloak/src/vc_alsa.c:43` | `snd_pcm_hw_params_alloca(&hw);` |
| `snd_pcm_hw_params_any` | function | `voicecloak/src/vc_alsa.c:44` | `snd_pcm_hw_params_any(s->pcm, hw);` |
| `snd_pcm_hw_params_current` | function | `voicecloak/src/vc_alsa.c:211` | `snd_pcm_hw_params_current(cap.pcm, hw);` |
| `snd_pcm_hw_params_get_rate` | function | `voicecloak/src/vc_alsa.c:212` | `snd_pcm_hw_params_get_rate(hw, &neg_rate, &dir);` |
| `snd_pcm_hw_params_set_buffer_size_near` | function | `voicecloak/src/vc_alsa.c:85` | `snd_pcm_hw_params_set_buffer_size_near(s->pcm, hw, &buffer);` |
| `snd_pcm_prepare` | function | `voicecloak/src/vc_alsa.c:231` | `snd_pcm_prepare(cap.pcm);` |
| `snd_pcm_start` | function | `voicecloak/src/vc_alsa.c:238` | `snd_pcm_start(cap.pcm);` |
| `snd_pcm_writei` | function | `voicecloak/src/vc_alsa.c:237` | `snd_pcm_writei(play.pcm, raw_out, period);` |
| `vc_alsa_list` | function | `voicecloak/src/vc_alsa.c:162` | `int vc_alsa_list(void)` |
| `vc_alsa_run` | function | `voicecloak/src/vc_alsa.c:188` | `int vc_alsa_run(const vc_alsa_cfg_t *cfg)` |
| `vc_pcm_t` | struct | `voicecloak/src/vc_alsa.c:13` | `` |
| `vc_stream_destroy` | function | `voicecloak/src/vc_alsa.c:286` | `vc_stream_destroy(st);` |
| `vc_stream_process` | function | `voicecloak/src/vc_alsa.c:258` | `vc_stream_process(st, mono_in, mono_out, (size_t)frames, cfg->fn, cfg->user);` |
| `VC_ALSA_H` | macro | `voicecloak/src/vc_alsa.h:2` | `#define VC_ALSA_H` |
| `runtime` | function | `voicecloak/src/vc_alsa.h:15` | `* * The capture and playback device names are ALSA PCM names discovered * at runtime (e.g. "hw:VSL", "plughw:2,0", "defa` |
| `vc_alsa_cfg_t` | struct | `voicecloak/src/vc_alsa.h:23` | `` |
| `vc_alsa_list` | function | `voicecloak/src/vc_alsa.h:40` | `int vc_alsa_list(void);` |
| `vc_alsa_run` | function | `voicecloak/src/vc_alsa.h:47` | `int vc_alsa_run(const vc_alsa_cfg_t *cfg);` |
| `cmd_cloak` | function | `voicecloak/src/vc_cli.c:52` | `static int cmd_cloak(const char *pubkey_path,
                     const char *in_path, const cha...` |
| `cmd_info` | function | `voicecloak/src/vc_cli.c:141` | `static int cmd_info(const char *path)` |
| `cmd_keygen` | function | `voicecloak/src/vc_cli.c:40` | `static int cmd_keygen(void)` |
| `fclose` | function | `voicecloak/src/vc_cli.c:76` | `fclose(ur);` |
| `fprintf` | function | `voicecloak/src/vc_cli.c:44` | `fprintf(stderr, "Error: key generation failed.\n");` |
| `free` | function | `voicecloak/src/vc_cli.c:74` | `free(samples);` |
| `fwrite` | function | `voicecloak/src/vc_cli.c:99` | `fwrite(enc_seed, 1, enc_len, sf);` |
| `main` | function | `voicecloak/src/vc_cli.c:176` | `int main(int argc, char *argv[])` |
| `print_usage` | function | `voicecloak/src/vc_cli.c:8` | `static void print_usage(const char *prog)` |
| `printf` | function | `voicecloak/src/vc_cli.c:10` | `printf( "VoiceCloak - cryptographically secure voice anonymizer\n" "\n" "Usage: %s <command> [options]\n" "\n" "Commands` |
| `snprintf` | function | `voicecloak/src/vc_cli.c:93` | `snprintf(sidecar_path, sizeof(sidecar_path), "%s.vc", out_path);` |
| `EVP_EncryptInit_ex` | function | `voicecloak/src/vc_crypto.c:152` | `EVP_EncryptInit_ex(p->ctx, EVP_aes_256_ctr(), NULL, seed, p->counter);` |
| `EVP_EncryptUpdate` | function | `voicecloak/src/vc_crypto.c:171` | `EVP_EncryptUpdate(p->ctx, p->keystream, &outlen, p->keystream, (int)sizeof(p->keystream));` |
| `EVP_PKEY_CTX_free` | function | `voicecloak/src/vc_crypto.c:67` | `EVP_PKEY_CTX_free(ctx);` |
| `EVP_PKEY_free` | function | `voicecloak/src/vc_crypto.c:63` | `EVP_PKEY_free(pkey);` |
| `fclose` | function | `voicecloak/src/vc_crypto.c:56` | `fclose(fp);` |
| `free` | function | `voicecloak/src/vc_crypto.c:161` | `free(p);` |
| `memcpy` | function | `voicecloak/src/vc_crypto.c:127` | `memcpy(data, infos[i], info_lens[i]);` |
| `memset` | function | `voicecloak/src/vc_crypto.c:150` | `memset(p->counter, 0, sizeof(p->counter));` |
| `openssl_init` | function | `voicecloak/src/vc_crypto.c:11` | `static void openssl_init(void)` |
| `vc_crypto_derive_seeds` | function | `voicecloak/src/vc_crypto.c:95` | `int vc_crypto_derive_seeds(const unsigned char *master_seed, size_t seed_len,
                   ...` |
| `vc_crypto_keygen` | function | `voicecloak/src/vc_crypto.c:16` | `int vc_crypto_keygen(const char *pubkey_path, const char *privkey_path)` |
| `vc_crypto_seal` | function | `voicecloak/src/vc_crypto.c:46` | `int vc_crypto_seal(const char *pubkey_path,
                   const unsigned char *seed, size_t ...` |
| `vc_crypto_unseal` | function | `voicecloak/src/vc_crypto.c:70` | `int vc_crypto_unseal(const char *privkey_path,
                     const unsigned char *enc, siz...` |
| `vc_prng_create` | function | `voicecloak/src/vc_crypto.c:142` | `vc_prng_t *vc_prng_create(const unsigned char *seed)` |
| `vc_prng_destroy` | function | `voicecloak/src/vc_crypto.c:156` | `void vc_prng_destroy(vc_prng_t *p)` |
| `vc_prng_fill` | function | `voicecloak/src/vc_crypto.c:163` | `void vc_prng_fill(vc_prng_t *p, unsigned char *buf, size_t len)` |
| `vc_prng_float` | function | `voicecloak/src/vc_crypto.c:183` | `float vc_prng_float(vc_prng_t *p, float low, float high)` |
| `vc_prng_s` | struct | `voicecloak/src/vc_crypto.c:136` | `` |
| `VC_CRYPTO_H` | macro | `voicecloak/src/vc_crypto.h:2` | `#define VC_CRYPTO_H` |
| `VC_CRYPTO_KEY_BYTES` | macro | `voicecloak/src/vc_crypto.h:12` | `#define VC_CRYPTO_KEY_BYTES` |
| `VC_CRYPTO_SEED_BYTES` | macro | `voicecloak/src/vc_crypto.h:10` | `#define VC_CRYPTO_SEED_BYTES` |
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
| `VC_FFT_SIZE` | macro | `voicecloak/src/vc_dsp.c:8` | `#define VC_FFT_SIZE` |
| `VC_HOP_SIZE` | macro | `voicecloak/src/vc_dsp.c:10` | `#define VC_HOP_SIZE` |
| `compute_out_len` | function | `voicecloak/src/vc_dsp.c:30` | `static size_t compute_out_len(size_t nframes, size_t hop)` |
| `free` | function | `voicecloak/src/vc_dsp.c:74` | `free(synth_phase);` |
| `memcpy` | function | `voicecloak/src/vc_dsp.c:54` | `memcpy(synth_phase, phase, nbins * sizeof(float));` |
| `memset` | function | `voicecloak/src/vc_dsp.c:113` | `memset(dst, 0, nbins * sizeof(float));` |
| `normalize_rms` | function | `voicecloak/src/vc_dsp.c:254` | `static void normalize_rms(const float *in, size_t in_len,
                          float *out, s...` |
| `stft_process` | function | `voicecloak/src/vc_dsp.c:11` | `static int stft_process(const float *samples, size_t num_samples,
                        float *...` |
| `stft_reconstruct` | function | `voicecloak/src/vc_dsp.c:20` | `static int stft_reconstruct(const float *mag, const float *phase,
                            siz...` |
| `trim_edges` | function | `voicecloak/src/vc_dsp.c:233` | `static void trim_edges(float **buf, size_t *len)` |
| `vc_dsp_cloak` | function | `voicecloak/src/vc_dsp.c:271` | `int vc_dsp_cloak(const float *samples, size_t num_samples,
                 uint32_t sample_rate,...` |
| `vc_dsp_formant_shift` | function | `voicecloak/src/vc_dsp.c:90` | `int vc_dsp_formant_shift(const float *samples, size_t num_samples,
                         uint3...` |
| `vc_dsp_pitch_shift` | function | `voicecloak/src/vc_dsp.c:34` | `int vc_dsp_pitch_shift(const float *samples, size_t num_samples,
                       uint32_t ...` |
| `vc_dsp_spectral_scramble` | function | `voicecloak/src/vc_dsp.c:160` | `int vc_dsp_spectral_scramble(const float *samples, size_t num_samples,
                          ...` |
| `vc_prng_destroy` | function | `voicecloak/src/vc_dsp.c:285` | `vc_prng_destroy(pp);` |
| `vc_stft_destroy` | function | `voicecloak/src/vc_dsp.c:17` | `vc_stft_destroy(st);` |
| `VC_DSP_H` | macro | `voicecloak/src/vc_dsp.h:2` | `#define VC_DSP_H` |
| `VcMode` | variable | `voicecloak/src/vc_dsp.h:8` | `extern "C" { #endif typedef enum { VC_MODE_SUBTLE = 0, VC_MODE_WITNESS = 1 } VcMode;` |
| `vc_dsp_cloak` | function | `voicecloak/src/vc_dsp.h:27` | `int vc_dsp_cloak(const float *samples, size_t num_samples, uint32_t sample_rate, const unsigned char *pitch_seed, const ` |
| `vc_dsp_formant_shift` | function | `voicecloak/src/vc_dsp.h:19` | `int vc_dsp_formant_shift(const float *samples, size_t num_samples, uint32_t sample_rate, float shift_factor, float **out` |
| `vc_dsp_pitch_shift` | function | `voicecloak/src/vc_dsp.h:15` | `int vc_dsp_pitch_shift(const float *samples, size_t num_samples, uint32_t sample_rate, float semitones, float **out, siz` |
| `vc_dsp_spectral_scramble` | function | `voicecloak/src/vc_dsp.h:23` | `int vc_dsp_spectral_scramble(const float *samples, size_t num_samples, uint32_t sample_rate, float intensity, float **ou` |
| `M_PI` | macro | `voicecloak/src/vc_fft.c:7` | `#define M_PI` |
| `bit_reverse` | function | `voicecloak/src/vc_fft.c:9` | `static unsigned int bit_reverse(unsigned int x, unsigned int bits)` |
| `bit_reverse_reorder` | function | `voicecloak/src/vc_fft.c:19` | `static void bit_reverse_reorder(size_t n, float *real, float *imag)` |
| `free` | function | `voicecloak/src/vc_fft.c:73` | `free(work_r);` |
| `vc_fft` | function | `voicecloak/src/vc_fft.c:35` | `void vc_fft(size_t n, float *real, float *imag, int inverse)` |
| `FFT` | function | `voicecloak/src/vc_fft.h:18` | `* FFT(IFFT(x)) == IFFT(FFT(x)) == x. */ void vc_fft(size_t n, float *real, float *imag, int inverse);` |
| `VC_FFT_H` | macro | `voicecloak/src/vc_fft.h:2` | `#define VC_FFT_H` |
| `M_PI` | macro | `voicecloak/src/vc_rt.c:7` | `#define M_PI` |
| `formant_warp` | function | `voicecloak/src/vc_rt.c:70` | `static void formant_warp(float *syn_mag, size_t nbins, float factor)` |
| `free` | function | `voicecloak/src/vc_rt.c:45` | `free(c->prev_phase);` |
| `memset` | function | `voicecloak/src/vc_rt.c:56` | `memset(c->prev_phase, 0, c->nbins * sizeof(double));` |
| `powf` | function | `voicecloak/src/vc_rt.c:62` | `return powf(2.0f, semitones / 12.0f);` |
| `vc_rt_create` | function | `voicecloak/src/vc_rt.c:22` | `vc_rt_ctx_t *vc_rt_create(size_t nbins, vc_rt_params_t params)` |
| `vc_rt_ctx_s` | struct | `voicecloak/src/vc_rt.c:10` | `` |
| `vc_rt_destroy` | function | `voicecloak/src/vc_rt.c:42` | `void vc_rt_destroy(vc_rt_ctx_t *c)` |
| `vc_rt_reset` | function | `voicecloak/src/vc_rt.c:53` | `void vc_rt_reset(vc_rt_ctx_t *c)` |
| `vc_rt_semitones_to_ratio` | function | `voicecloak/src/vc_rt.c:60` | `float vc_rt_semitones_to_ratio(float semitones)` |
| `vc_rt_transform` | function | `voicecloak/src/vc_rt.c:105` | `void vc_rt_transform(float *mag, float *phase, size_t nbins,
                     uint32_t sample...` |
| `wrap_pi` | function | `voicecloak/src/vc_rt.c:64` | `static double wrap_pi(double x)` |
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
| `cmd_live` | function | `voicecloak/src/vc_rt_cli.c:141` | `static int cmd_live(int argc, char *argv[])` |
| `cmd_selftest` | function | `voicecloak/src/vc_rt_cli.c:80` | `static int cmd_selftest(void)` |
| `dominant_freq` | function | `voicecloak/src/vc_rt_cli.c:57` | `static float dominant_freq(const float *x, size_t n, unsigned int sr)` |
| `fclose` | function | `voicecloak/src/vc_rt_cli.c:134` | `fclose(ur);` |
| `fprintf` | function | `voicecloak/src/vc_rt_cli.c:98` | `fprintf(stderr, "selftest: setup failed\n");` |
| `free` | function | `voicecloak/src/vc_rt_cli.c:77` | `free(re);` |
| `main` | function | `voicecloak/src/vc_rt_cli.c:222` | `int main(int argc, char *argv[])` |
| `memset` | function | `voicecloak/src/vc_rt_cli.c:199` | `memset(&sa, 0, sizeof(sa));` |
| `on_sigint` | function | `voicecloak/src/vc_rt_cli.c:20` | `static void on_sigint(int sig)` |
| `print_usage` | function | `voicecloak/src/vc_rt_cli.c:25` | `static void print_usage(const char *prog)` |
| `printf` | function | `voicecloak/src/vc_rt_cli.c:108` | `printf("selftest: input dominant = %.1f Hz (expected %.1f)\n", (double)got_in, (double)in_freq);` |
| `resolve_params` | function | `voicecloak/src/vc_rt_cli.c:118` | `static int resolve_params(int have_fixed, float semis, float formant,
                          f...` |
| `sigaction` | function | `voicecloak/src/vc_rt_cli.c:201` | `sigaction(SIGINT, &sa, NULL);` |
| `vc_fft` | function | `voicecloak/src/vc_rt_cli.c:70` | `vc_fft(nf, re, im, 0);` |
| `vc_rt_derive` | function | `voicecloak/src/vc_rt_cli.c:139` | `return vc_rt_derive(ps, fs, ss, witness, p);` |
| `vc_rt_destroy` | function | `voicecloak/src/vc_rt_cli.c:218` | `vc_rt_destroy(ctx);` |
| `vc_stream_destroy` | function | `voicecloak/src/vc_rt_cli.c:99` | `vc_stream_destroy(st);` |
| `vc_stream_process` | function | `voicecloak/src/vc_rt_cli.c:102` | `vc_stream_process(st, in, out, n, vc_rt_transform, ctx);` |
| `vc_prng_destroy` | function | `voicecloak/src/vc_rt_seed.c:15` | `vc_prng_destroy(pp);` |
| `vc_rt_derive` | function | `voicecloak/src/vc_rt_seed.c:4` | `int vc_rt_derive(const unsigned char *pitch_seed,
                 const unsigned char *formant_s...` |
| `M_PI` | macro | `voicecloak/src/vc_stft.c:8` | `#define M_PI` |
| `free` | function | `voicecloak/src/vc_stft.c:60` | `free(st->window);` |
| `memset` | function | `voicecloak/src/vc_stft.c:45` | `memset(st->win_sq_sum, 0, fft_size * sizeof(float));` |
| `vc_fft` | function | `voicecloak/src/vc_stft.c:101` | `vc_fft(fft_n, st->buf_r, st->buf_i, 0);` |
| `vc_stft_create` | function | `voicecloak/src/vc_stft.c:20` | `vc_stft_t *vc_stft_create(size_t fft_size, size_t hop_size)` |
| `vc_stft_destroy` | function | `voicecloak/src/vc_stft.c:57` | `void vc_stft_destroy(vc_stft_t *st)` |
| `vc_stft_forward` | function | `voicecloak/src/vc_stft.c:70` | `int vc_stft_forward(vc_stft_t *st,
                    const float *samples, size_t num_samples,
...` |
| `vc_stft_inverse` | function | `voicecloak/src/vc_stft.c:118` | `int vc_stft_inverse(vc_stft_t *st,
                    const float *mag, const float *phase,
    ...` |
| `vc_stft_inverse_hop` | function | `voicecloak/src/vc_stft.c:126` | `int vc_stft_inverse_hop(vc_stft_t *st,
                        const float *mag, const float *pha...` |
| `vc_stft_num_bins` | function | `voicecloak/src/vc_stft.c:66` | `size_t vc_stft_num_bins(const vc_stft_t *st)` |
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
| `free` | function | `voicecloak/src/vc_stream.c:96` | `free(st->window);` |
| `is_pow2` | function | `voicecloak/src/vc_stream.c:30` | `static int is_pow2(size_t v)` |
| `memmove` | function | `voicecloak/src/vc_stream.c:149` | `memmove(st->out_accum, st->out_accum + st->hop_size, (N - st->hop_size) * sizeof(float));` |
| `memset` | function | `voicecloak/src/vc_stream.c:152` | `memset(st->out_accum + (N - st->hop_size), 0, st->hop_size * sizeof(float));` |
| `process_frame` | function | `voicecloak/src/vc_stream.c:110` | `static void process_frame(vc_stream_t *st, vc_spectral_fn fn, void *user)` |
| `vc_fft` | function | `voicecloak/src/vc_stream.c:120` | `vc_fft(N, st->buf_r, st->buf_i, 0);` |
| `vc_stream_create` | function | `voicecloak/src/vc_stream.c:34` | `vc_stream_t *vc_stream_create(size_t fft_size, size_t hop_size,
                              uin...` |
| `vc_stream_destroy` | function | `voicecloak/src/vc_stream.c:93` | `void vc_stream_destroy(vc_stream_t *st)` |
| `vc_stream_latency_samples` | function | `voicecloak/src/vc_stream.c:106` | `size_t vc_stream_latency_samples(const vc_stream_t *st)` |
| `vc_stream_process` | function | `voicecloak/src/vc_stream.c:158` | `int vc_stream_process(vc_stream_t *st,
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
| `fclose` | function | `voicecloak/src/vc_wav.c:139` | `fclose(fp);` |
| `find_chunk` | function | `voicecloak/src/vc_wav.c:77` | `static int find_chunk(FILE *fp, const char *id, uint32_t *size)` |
| `float_to_sample` | function | `voicecloak/src/vc_wav.c:61` | `static void float_to_sample(float f, unsigned char *p, int bps)` |
| `free` | function | `voicecloak/src/vc_wav.c:155` | `free(raw);` |
| `fseek` | function | `voicecloak/src/vc_wav.c:89` | `fseek(fp, (long)sz, SEEK_CUR);` |
| `memcpy` | function | `voicecloak/src/vc_wav.c:44` | `memcpy(&v, p, 2);` |
| `memset` | function | `voicecloak/src/vc_wav.c:117` | `memset(&fmt, 0, sizeof(fmt));` |
| `read_bytes` | function | `voicecloak/src/vc_wav.c:29` | `static int read_bytes(FILE *fp, void *buf, size_t n)` |
| `sample_to_float` | function | `voicecloak/src/vc_wav.c:37` | `static float sample_to_float(const unsigned char *p, int bps)` |
| `vc_wav_read` | function | `voicecloak/src/vc_wav.c:92` | `int vc_wav_read(const char *path,
                float **samples_out, size_t *num_samples_out,
 ...` |
| `vc_wav_write` | function | `voicecloak/src/vc_wav.c:168` | `int vc_wav_write(const char *path,
                 const float *samples, size_t num_samples,
   ...` |
| `write_bytes` | function | `voicecloak/src/vc_wav.c:33` | `static int write_bytes(FILE *fp, const void *buf, size_t n)` |
| `VC_WAV_H` | macro | `voicecloak/src/vc_wav.h:2` | `#define VC_WAV_H` |
| `vc_wav_read` | function | `voicecloak/src/vc_wav.h:19` | `int vc_wav_read(const char *path, float **samples_out, size_t *num_samples_out, uint32_t *sample_rate_out);` |
| `vc_wav_write` | function | `voicecloak/src/vc_wav.h:31` | `int vc_wav_write(const char *path, const float *samples, size_t num_samples, uint32_t sample_rate);` |
| `assert_float_equal` | function | `voicecloak/tests/test_vc_fft.c:22` | `assert_float_equal(real[i], i == 0 ? 1.0f : 0.0f, 1e-4f);` |
| `assert_true` | function | `voicecloak/tests/test_vc_fft.c:70` | `assert_true(mag_k > mag_other * 10.0f);` |
| `cmocka_run_group_tests` | function | `voicecloak/tests/test_vc_fft.c:82` | `return cmocka_run_group_tests(tests, NULL, NULL);` |
| `free` | function | `voicecloak/tests/test_vc_fft.c:42` | `free(real);` |
| `main` | function | `voicecloak/tests/test_vc_fft.c:75` | `int main(void)` |
| `test_fft_dc_signal` | function | `voicecloak/tests/test_vc_fft.c:26` | `static void test_fft_dc_signal(void **state)` |
| `test_fft_identity` | function | `voicecloak/tests/test_vc_fft.c:9` | `static void test_fft_identity(void **state)` |
| `test_fft_sine` | function | `voicecloak/tests/test_vc_fft.c:46` | `static void test_fft_sine(void **state)` |
| `vc_fft` | function | `voicecloak/tests/test_vc_fft.c:16` | `vc_fft(n, real, imag, 0);` |
| `M_PI` | macro | `voicecloak/tests/test_vc_stream.c:15` | `#define M_PI` |
| `SR` | macro | `voicecloak/tests/test_vc_stream.c:17` | `#define SR` |
| `assert_false` | function | `voicecloak/tests/test_vc_stream.c:175` | `assert_false(isnan(out[i]));` |
| `assert_int_equal` | function | `voicecloak/tests/test_vc_stream.c:69` | `assert_int_equal(vc_stream_process(st, in + off, out + off, c, fn, user), 0);` |
| `assert_non_null` | function | `voicecloak/tests/test_vc_stream.c:81` | `assert_non_null(st);` |
| `assert_null` | function | `voicecloak/tests/test_vc_stream.c:76` | `assert_null(vc_stream_create(1000, 250, SR));` |
| `assert_true` | function | `voicecloak/tests/test_vc_stream.c:116` | `assert_true(best_err < 0.05f * in_rms);` |
| `cmocka_run_group_tests` | function | `voicecloak/tests/test_vc_stream.c:193` | `return cmocka_run_group_tests(tests, NULL, NULL);` |
| `dominant_freq` | function | `voicecloak/tests/test_vc_stream.c:31` | `static float dominant_freq(const float *x, size_t n, uint32_t sr)` |
| `free` | function | `voicecloak/tests/test_vc_stream.c:50` | `free(re);` |
| `gen_sines` | function | `voicecloak/tests/test_vc_stream.c:19` | `static void gen_sines(float *buf, size_t n, uint32_t sr,
                      const float *freqs...` |
| `main` | function | `voicecloak/tests/test_vc_stream.c:184` | `int main(void)` |
| `rms` | function | `voicecloak/tests/test_vc_stream.c:53` | `static float rms(const float *x, size_t n)` |
| `run_pitch` | function | `voicecloak/tests/test_vc_stream.c:121` | `static void run_pitch(float in_freq, float ratio, float expect_freq)` |
| `run_stream` | function | `voicecloak/tests/test_vc_stream.c:63` | `static void run_stream(vc_stream_t *st, const float *in, float *out, size_t n,
                  ...` |
| `srand` | function | `voicecloak/tests/test_vc_stream.c:161` | `srand(1234);` |
| `test_bounded_output` | function | `voicecloak/tests/test_vc_stream.c:155` | `static void test_bounded_output(void **state)` |
| `test_create_validation` | function | `voicecloak/tests/test_vc_stream.c:73` | `static void test_create_validation(void **state)` |
| `test_passthrough_identity` | function | `voicecloak/tests/test_vc_stream.c:85` | `static void test_passthrough_identity(void **state)` |
| `test_pitch_down_octave` | function | `voicecloak/tests/test_vc_stream.c:150` | `static void test_pitch_down_octave(void **state)` |
| `test_pitch_up_octave` | function | `voicecloak/tests/test_vc_stream.c:145` | `static void test_pitch_up_octave(void **state)` |
| `vc_fft` | function | `voicecloak/tests/test_vc_stream.c:43` | `vc_fft(nf, re, im, 0);` |
| `vc_rt_destroy` | function | `voicecloak/tests/test_vc_stream.c:140` | `vc_rt_destroy(ctx);` |
| `vc_stream_destroy` | function | `voicecloak/tests/test_vc_stream.c:83` | `vc_stream_destroy(st);` |
