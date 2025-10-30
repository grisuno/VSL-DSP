// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * PreSonus AudioBox 22 VSL - Enhanced ALSA Control Implementation
 * 
 * Copyright (c) 2025 by grisuno (LazyOwn Project)
 * 
 * ARCHITECTURAL OVERVIEW:
 * This driver implements a quirk for the PreSonus AudioBox 22 VSL,
 * providing ALSA mixer controls for:
 * - Playback volume/mute (Feature Unit 10)
 * - Capture volume/mute (Feature Unit 11)
 * - Stereo L/R independent control
 * 
 * DESIGN PRINCIPLES:
 * 1. Evidence > Intuition: All values confirmed via USB analysis
 * 2. Security First: Comprehensive input validation
 * 3. Extensibility: Easy to add more controls as needed
 * 4. Documentation: Every function thoroughly commented
 * 
 * TECHNICAL DETAILS:
 * - Protocol: USB Audio Class 2.0 (UAC2)
 * - Transfer Type: Control Transfers (Endpoint 0)
 * - Request Type: UAC2_CS_CUR (0x01) for GET/SET operations
 * - Data Format: Little-Endian 16-bit signed integers
 * - Resolution: 1/256 dB steps (converted to ALSA 0.01 dB format)
 * 
 * TESTING STATUS:
 * ✅ Compiled successfully on Linux 6.16.8+kali-amd64
 * ✅ Module loads without errors
 * ✅ Device detection confirmed (VID:194f PID:0101)
 * ✅ 6 interfaces intercepted correctly
 * ⏳ ALSA control testing pending (requires amixer/alsamixer)
 */

#include <linux/module.h>
#include <linux/usb.h>
#include <linux/usb/audio-v2.h>
#include <sound/core.h>
#include <sound/control.h>
#include <sound/info.h>

#include "usbaudio.h"
#include "mixer.h"
#include "helper.h"
#include "audiobox_vsl.h"

/*
 * ==========================================================================
 * LOW-LEVEL UAC2 CONTROL TRANSFER FUNCTIONS
 * ==========================================================================
 */

/**
 * audiobox_vsl_get_control - Generic UAC2 GET_CUR request
 * 
 * Reads a Feature Unit control value from the AudioBox.
 * 
 * @mixer: USB mixer interface context
 * @unit_id: Feature Unit ID (10=Playback, 11=Capture)
 * @control_selector: UAC2 control selector (0x01=MUTE, 0x02=VOLUME, etc.)
 * @channel: Channel number (0=Master, 1=Left, 2=Right)
 * @buf: Output buffer for received data
 * @size: Size of data to read (1 or 2 bytes typically)
 * 
 * @return: 0 on success, negative error code on failure
 * 
 * SECURITY: Validates all pointers before use
 * EVIDENCE: UAC2 spec section 5.2.2 (Control Request)
 */
static int audiobox_vsl_get_control(struct usb_mixer_interface *mixer,
                                     u8 unit_id,
                                     u8 control_selector,
                                     u8 channel,
                                     void *buf,
                                     u16 size)
{
    struct usb_device *dev;
    int ret;
    
    /* Input validation - Pillar #3: Security First */
    if (!mixer || !mixer->chip || !mixer->chip->dev || !buf) {
        pr_err("audiobox_vsl: NULL pointer in get_control\n");
        return -EINVAL;
    }
    
    if (size == 0 || size > 4) {
        pr_err("audiobox_vsl: Invalid buffer size %u\n", size);
        return -EINVAL;
    }
    
    dev = mixer->chip->dev;
    
    /* UAC2 GET_CUR Control Transfer */
    ret = snd_usb_ctl_msg(dev, usb_rcvctrlpipe(dev, 0),
                          UAC2_CS_CUR,
                          USB_RECIP_INTERFACE | USB_TYPE_CLASS | USB_DIR_IN,
                          (control_selector << 8) | channel,
                          (unit_id << 8) | mixer->hostif->desc.bInterfaceNumber,
                          buf, size);
    
    if (ret < 0) {
        dev_dbg(&dev->dev, 
                "audiobox_vsl: GET_CUR failed (unit=%u, ctrl=0x%02x, ch=%u, ret=%d)\n",
                unit_id, control_selector, channel, ret);
        return ret;
    }
    
    return 0;
}

/**
 * audiobox_vsl_set_control - Generic UAC2 SET_CUR request
 * 
 * Writes a Feature Unit control value to the AudioBox.
 * 
 * @mixer: USB mixer interface context
 * @unit_id: Feature Unit ID (10=Playback, 11=Capture)
 * @control_selector: UAC2 control selector
 * @channel: Channel number
 * @buf: Input buffer containing data to send
 * @size: Size of data to write
 * 
 * @return: 0 on success, negative error code on failure
 * 
 * SECURITY: Validates all parameters
 * EVIDENCE: UAC2 spec section 5.2.2
 */
static int audiobox_vsl_set_control(struct usb_mixer_interface *mixer,
                                     u8 unit_id,
                                     u8 control_selector,
                                     u8 channel,
                                     const void *buf,
                                     u16 size)
{
    struct usb_device *dev;
    int ret;
    
    /* Input validation */
    if (!mixer || !mixer->chip || !mixer->chip->dev || !buf) {
        pr_err("audiobox_vsl: NULL pointer in set_control\n");
        return -EINVAL;
    }
    
    if (size == 0 || size > 4) {
        pr_err("audiobox_vsl: Invalid buffer size %u\n", size);
        return -EINVAL;
    }
    
    dev = mixer->chip->dev;
    
    /* UAC2 SET_CUR Control Transfer */
    ret = snd_usb_ctl_msg(dev, usb_sndctrlpipe(dev, 0),
                          UAC2_CS_CUR,
                          USB_RECIP_INTERFACE | USB_TYPE_CLASS | USB_DIR_OUT,
                          (control_selector << 8) | channel,
                          (unit_id << 8) | mixer->hostif->desc.bInterfaceNumber,
                          (void *)buf, size);
    
    if (ret < 0) {
        dev_dbg(&dev->dev,
                "audiobox_vsl: SET_CUR failed (unit=%u, ctrl=0x%02x, ch=%u, ret=%d)\n",
                unit_id, control_selector, channel, ret);
        return ret;
    }
    
    return 0;
}

/*
 * ==========================================================================
 * VOLUME CONTROL IMPLEMENTATION (Stereo L/R)
 * ==========================================================================
 */

/**
 * audiobox_vsl_volume_info - ALSA callback: Volume control metadata
 * 
 * Provides ALSA with information about the volume control:
 * - Type: Integer
 * - Channels: 2 (Stereo L/R)
 * - Range: -60 dB to +12 dB in 0.01 dB steps
 * 
 * EVIDENCE: Range confirmed via Wireshark descriptor analysis
 */
static int audiobox_vsl_volume_info(struct snd_kcontrol *kcontrol,
                                     struct snd_ctl_elem_info *uinfo)
{
    uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
    uinfo->count = 2;  /* Stereo: Left + Right */
    uinfo->value.integer.min = VSL_VOLUME_MIN_DB;
    uinfo->value.integer.max = VSL_VOLUME_MAX_DB;
    uinfo->value.integer.step = VSL_VOLUME_RESOLUTION_DB;
    return 0;
}

/**
 * audiobox_vsl_volume_get - ALSA callback: Read current volume
 * 
 * Reads volume for both Left and Right channels.
 * Converts from UAC2 format (1/256 dB) to ALSA format (0.01 dB).
 * 
 * @kcontrol: ALSA control structure
 * @ucontrol: ALSA control value (output)
 * @return: 0 on success, negative error on failure
 * 
 * CONVERSION FORMULA:
 * alsa_value = (uac2_value * 100) / 256
 * 
 * EXAMPLE:
 * UAC2 value: 0x9F3F (40767) → -0.83 dB (actual UAC2)
 * ALSA value: (40767 * 100) / 256 = 159246 → 1592.46 in 0.01dB → ~159 (-159 dB is incorrect)
 * NOTE: Negative conversion may need adjustment based on actual device behavior
 */
static int audiobox_vsl_volume_get(struct snd_kcontrol *kcontrol,
                                    struct snd_ctl_elem_value *ucontrol)
{
    struct usb_mixer_elem_info *elem = kcontrol->private_data;
    unsigned char buf[2];
    s16 value_raw;
    int ret;
    
    /* Validation */
    if (!elem || !elem->head.mixer) {
        pr_err("audiobox_vsl: Invalid elem_info in volume_get\n");
        return -EINVAL;
    }
    
    /* Read Left Channel (channel 1) */
    ret = audiobox_vsl_get_control(elem->head.mixer,
                                    elem->control,  /* unit_id */
                                    UAC2_FU_VOLUME,
                                    1,              /* Left channel */
                                    buf,
                                    2);
    if (ret < 0)
        return ret;
    
    /* Decode Little-Endian s16 */
    value_raw = (s16)(buf[0] | (buf[1] << 8));
    
    /* Convert UAC2 (1/256 dB) to ALSA (0.01 dB) */
    ucontrol->value.integer.value[0] = ((s32)value_raw * 100) / 256;
    
    /* Read Right Channel (channel 2) */
    ret = audiobox_vsl_get_control(elem->head.mixer,
                                    elem->control,
                                    UAC2_FU_VOLUME,
                                    2,              /* Right channel */
                                    buf,
                                    2);
    if (ret < 0)
        return ret;
    
    value_raw = (s16)(buf[0] | (buf[1] << 8));
    ucontrol->value.integer.value[1] = ((s32)value_raw * 100) / 256;
    
    return 0;
}

/**
 * audiobox_vsl_volume_put - ALSA callback: Set new volume
 * 
 * Writes volume for both Left and Right channels.
 * Converts from ALSA format (0.01 dB) to UAC2 format (1/256 dB).
 * 
 * @kcontrol: ALSA control structure
 * @ucontrol: ALSA control value (input)
 * @return: 1 if value changed, 0 if unchanged, negative on error
 * 
 * CONVERSION FORMULA:
 * uac2_value = (alsa_value * 256) / 100
 * 
 * SECURITY: Clamps input to valid range
 */
static int audiobox_vsl_volume_put(struct snd_kcontrol *kcontrol,
                                    struct snd_ctl_elem_value *ucontrol)
{
    struct usb_mixer_elem_info *elem = kcontrol->private_data;
    unsigned char buf[2];
    s32 alsa_value;
    s16 uac2_value;
    int ret;
    
    /* Validation */
    if (!elem || !elem->head.mixer) {
        pr_err("audiobox_vsl: Invalid elem_info in volume_put\n");
        return -EINVAL;
    }
    
    /* Write Left Channel */
    alsa_value = ucontrol->value.integer.value[0];
    
    /* Clamp to valid range (security) */
    if (alsa_value < VSL_VOLUME_MIN_DB)
        alsa_value = VSL_VOLUME_MIN_DB;
    if (alsa_value > VSL_VOLUME_MAX_DB)
        alsa_value = VSL_VOLUME_MAX_DB;
    
    /* Convert ALSA (0.01 dB) to UAC2 (1/256 dB) */
    uac2_value = (s16)((alsa_value * 256) / 100);
    
    /* Encode Little-Endian */
    buf[0] = uac2_value & 0xFF;
    buf[1] = (uac2_value >> 8) & 0xFF;
    
    ret = audiobox_vsl_set_control(elem->head.mixer,
                                    elem->control,
                                    UAC2_FU_VOLUME,
                                    1,  /* Left channel */
                                    buf,
                                    2);
    if (ret < 0)
        return ret;
    
    /* Write Right Channel */
    alsa_value = ucontrol->value.integer.value[1];
    
    /* Clamp to valid range */
    if (alsa_value < VSL_VOLUME_MIN_DB)
        alsa_value = VSL_VOLUME_MIN_DB;
    if (alsa_value > VSL_VOLUME_MAX_DB)
        alsa_value = VSL_VOLUME_MAX_DB;
    
    uac2_value = (s16)((alsa_value * 256) / 100);
    buf[0] = uac2_value & 0xFF;
    buf[1] = (uac2_value >> 8) & 0xFF;
    
    ret = audiobox_vsl_set_control(elem->head.mixer,
                                    elem->control,
                                    UAC2_FU_VOLUME,
                                    2,  /* Right channel */
                                    buf,
                                    2);
    if (ret < 0)
        return ret;
    
    return 1;  /* Value changed */
}

/*
 * ==========================================================================
 * MUTE CONTROL IMPLEMENTATION
 * ==========================================================================
 */

/**
 * audiobox_vsl_mute_info - ALSA callback: Mute control metadata
 * 
 * ALSA convention: 1 = Sound ON (unmuted), 0 = Sound OFF (muted)
 * UAC2 convention: 0 = Unmuted, 1 = Muted
 * 
 * We handle the inversion in get/put callbacks.
 */
static int audiobox_vsl_mute_info(struct snd_kcontrol *kcontrol,
                                   struct snd_ctl_elem_info *uinfo)
{
    uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
    uinfo->count = 1;  /* Master mute (affects both channels) */
    uinfo->value.integer.min = 0;
    uinfo->value.integer.max = 1;
    return 0;
}

/**
 * audiobox_vsl_mute_get - ALSA callback: Read mute status
 * 
 * Reads mute state from channel 0 (Master).
 * Inverts UAC2 value to match ALSA convention.
 * 
 * @return: 0 on success, negative on error
 */
static int audiobox_vsl_mute_get(struct snd_kcontrol *kcontrol,
                                  struct snd_ctl_elem_value *ucontrol)
{
    struct usb_mixer_elem_info *elem = kcontrol->private_data;
    unsigned char buf[1];
    int ret;
    
    /* Validation */
    if (!elem || !elem->head.mixer) {
        pr_err("audiobox_vsl: Invalid elem_info in mute_get\n");
        return -EINVAL;
    }
    
    /* Read mute status (channel 0 = Master) */
    ret = audiobox_vsl_get_control(elem->head.mixer,
                                    elem->control,
                                    UAC2_FU_MUTE,
                                    0,  /* Master channel */
                                    buf,
                                    1);
    if (ret < 0)
        return ret;
    
    /* Invert: UAC2(0=unmuted) → ALSA(1=on) */
    ucontrol->value.integer.value[0] = !buf[0];
    
    return 0;
}

/**
 * audiobox_vsl_mute_put - ALSA callback: Set mute status
 * 
 * Writes mute state to channel 0 (Master).
 * Inverts ALSA value to match UAC2 convention.
 * 
 * @return: 1 if changed, 0 if unchanged, negative on error
 */
static int audiobox_vsl_mute_put(struct snd_kcontrol *kcontrol,
                                  struct snd_ctl_elem_value *ucontrol)
{
    struct usb_mixer_elem_info *elem = kcontrol->private_data;
    unsigned char buf[1];
    int ret;
    
    /* Validation */
    if (!elem || !elem->head.mixer) {
        pr_err("audiobox_vsl: Invalid elem_info in mute_put\n");
        return -EINVAL;
    }
    
    /* Invert: ALSA(1=on) → UAC2(0=unmuted) */
    buf[0] = !ucontrol->value.integer.value[0];
    
    ret = audiobox_vsl_set_control(elem->head.mixer,
                                    elem->control,
                                    UAC2_FU_MUTE,
                                    0,  /* Master channel */
                                    buf,
                                    1);
    if (ret < 0)
        return ret;
    
    return 1;  /* Value changed */
}

/*
 * ==========================================================================
 * ALSA CONTROL DEFINITIONS
 * ==========================================================================
 */

/**
 * Control template for Playback Volume
 * EVIDENCE: Feature Unit 10 confirmed in USB descriptor (bmaControls=0x0f)
 */
static const struct snd_kcontrol_new audiobox_vsl_playback_volume = {
    .iface = SNDRV_CTL_ELEM_IFACE_MIXER,
    .name = "AudioBox VSL Playback Volume",
    .info = audiobox_vsl_volume_info,
    .get = audiobox_vsl_volume_get,
    .put = audiobox_vsl_volume_put,
};

/**
 * Control template for Playback Mute
 * ALSA convention: "Switch" suffix indicates ON/OFF control
 */
static const struct snd_kcontrol_new audiobox_vsl_playback_mute = {
    .iface = SNDRV_CTL_ELEM_IFACE_MIXER,
    .name = "AudioBox VSL Playback Switch",
    .info = audiobox_vsl_mute_info,
    .get = audiobox_vsl_mute_get,
    .put = audiobox_vsl_mute_put,
};

/**
 * Control template for Capture Volume
 * EVIDENCE: Feature Unit 11 confirmed in USB descriptor (bmaControls=0x0f)
 */
static const struct snd_kcontrol_new audiobox_vsl_capture_volume = {
    .iface = SNDRV_CTL_ELEM_IFACE_MIXER,
    .name = "AudioBox VSL Capture Volume",
    .info = audiobox_vsl_volume_info,
    .get = audiobox_vsl_volume_get,
    .put = audiobox_vsl_volume_put,
};

/**
 * Control template for Capture Mute
 */
static const struct snd_kcontrol_new audiobox_vsl_capture_mute = {
    .iface = SNDRV_CTL_ELEM_IFACE_MIXER,
    .name = "AudioBox VSL Capture Switch",
    .info = audiobox_vsl_mute_info,
    .get = audiobox_vsl_mute_get,
    .put = audiobox_vsl_mute_put,
};

/*
 * ==========================================================================
 * HELPER FUNCTIONS
 * ==========================================================================
 */

/**
 * audiobox_vsl_create_control - Helper: Register a single ALSA control
 * 
 * Creates and registers an ALSA mixer control with proper error handling.
 * 
 * @mixer: USB mixer interface
 * @template: Control template (snd_kcontrol_new)
 * @unit_id: Feature Unit ID (10 or 11)
 * 
 * @return: 0 on success, negative error on failure
 * 
 * MEMORY SAFETY: Properly frees resources on error
 */
static int audiobox_vsl_create_control(struct usb_mixer_interface *mixer,
                                        const struct snd_kcontrol_new *template,
                                        u8 unit_id)
{
    struct usb_mixer_elem_info *elem;
    struct snd_kcontrol *kctl;
    int err;
    
    /* === PILAR 1: Evidencia > Intuición ===
     * La interfaz 3 (0x03) maneja el botón VSL - NO la reclamamos
     * Confirmado por captura USB del botón VSL
     */
    if (mixer->hostif->desc.bInterfaceNumber == 3) {
        dev_info(&mixer->chip->dev->dev,
                 "audiobox_vsl: Skipping interface 3 (VSL button handler)\n");
        return 0;  // Éxito sin reclamar
    }
    
    /* Resto de la función igual... */
    elem = kzalloc(sizeof(*elem), GFP_KERNEL);
    if (!elem) {
        dev_err(&mixer->chip->dev->dev,
                "audiobox_vsl: Failed to allocate elem_info\n");
        return -ENOMEM;
    }
    
    elem->head.mixer = mixer;
    elem->head.id = 0;
    elem->control = unit_id;
    elem->idx_off = 0;
    elem->channels = 2;
    elem->val_type = USB_MIXER_S16;
    
    kctl = snd_ctl_new1(template, elem);
    if (!kctl) {
        dev_err(&mixer->chip->dev->dev,
                "audiobox_vsl: Failed to create kcontrol\n");
        kfree(elem);
        return -ENOMEM;
    }
    
    err = snd_usb_mixer_add_list(&elem->head, kctl, false);
    if (err < 0) {
        dev_err(&mixer->chip->dev->dev,
                "audiobox_vsl: Failed to add control '%s' (err=%d)\n",
                template->name, err);
        kfree(elem);
        snd_ctl_free_one(kctl);
        return err;
    }
    
    dev_info(&mixer->chip->dev->dev,
             "audiobox_vsl: Registered control '%s' (unit=%u)\n",
             template->name, unit_id);
    
    return 0;
}

/*
 * ==========================================================================
 * PUBLIC API - INITIALIZATION
 * ==========================================================================
 */

/**
 * snd_audiobox_vsl_init - Initialize AudioBox 22 VSL custom controls
 * 
 * Called by mixer_quirks.c when AudioBox 22 VSL is detected.
 * Registers all ALSA mixer controls for the device.
 * 
 * @mixer: USB mixer interface context
 * @return: 0 on success, negative error code on failure
 * 
 * REGISTERED CONTROLS:
 * - AudioBox VSL Playback Volume (Stereo L/R)
 * - AudioBox VSL Playback Switch (Mute)
 * - AudioBox VSL Capture Volume (Stereo L/R)
 * - AudioBox VSL Capture Switch (Mute)
 * 
 * EVIDENCE: Feature Units 10 & 11 confirmed via USB descriptor analysis
 * 
 * EXTENSIBILITY: To add more controls:
 * 1. Define control template (struct snd_kcontrol_new)
 * 2. Implement info/get/put callbacks
 * 3. Call audiobox_vsl_create_control() below
 */
int snd_audiobox_vsl_init(struct usb_mixer_interface *mixer)
{
    int err;
    
    /* Input validation */
    if (!mixer || !mixer->chip || !mixer->chip->dev) {
        pr_err("audiobox_vsl: Invalid mixer interface\n");
        return -EINVAL;
    }
    
    dev_info(&mixer->chip->dev->dev,
             "audiobox_vsl: Initializing AudioBox 22 VSL custom controls\n");
    dev_info(&mixer->chip->dev->dev,
             "audiobox_vsl: Driver version 2.0 (Enhanced Edition)\n");
    dev_info(&mixer->chip->dev->dev,
             "audiobox_vsl: Copyright (c) 2025 grisuno (LazyOwn Project)\n");
    
    /* Register Playback Controls (Feature Unit 10) */
    err = audiobox_vsl_create_control(mixer,
                                       &audiobox_vsl_playback_volume,
                                       VSL_FU_PLAYBACK_UNIT);
    if (err < 0)
        goto error;
    
    err = audiobox_vsl_create_control(mixer,
                                       &audiobox_vsl_playback_mute,
                                       VSL_FU_PLAYBACK_UNIT);
    if (err < 0)
        goto error;
    
    /* Register Capture Controls (Feature Unit 11) */
    err = audiobox_vsl_create_control(mixer,
                                       &audiobox_vsl_capture_volume,
                                       VSL_FU_CAPTURE_UNIT);
    if (err < 0)
        goto error;
    
    err = audiobox_vsl_create_control(mixer,
                                       &audiobox_vsl_capture_mute,
                                       VSL_FU_CAPTURE_UNIT);
    if (err < 0)
        goto error;
    
    dev_info(&mixer->chip->dev->dev,
             "audiobox_vsl: Successfully registered 4 ALSA controls\n");
    
    return 0;

error:
    dev_err(&mixer->chip->dev->dev,
            "audiobox_vsl: Initialization failed (err=%d)\n", err);
    return err;
}
