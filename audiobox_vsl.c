// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * PreSonus AudioBox 22 VSL - Custom DSP Controls
 * 
 * Copyright (c) 2025 by grisuno (LazyOwn Project)
 */

#include <linux/usb.h>
#include <linux/usb/audio-v2.h>  // ← Para UAC2_CS_CUR
#include <sound/core.h>
#include <sound/control.h>

#include "usbaudio.h"
#include "mixer.h"
#include "helper.h"
#include "audiobox_vsl.h"

/* PreSonus AudioBox 22 VSL */
#define USB_ID_AUDIOBOX_22VSL  0x194f0101

/* Feature Unit IDs */
#define FU_PLAYBACK_UNIT  10
#define FU_CAPTURE_UNIT   11

/* Control Selector para Feature Units UAC2 */
#define UAC2_FU_VOLUME  0x02
#define UAC2_FU_MUTE    0x01

/**
 * audiobox_vsl_get_volume - Leer volumen de un canal
 */
static int audiobox_vsl_get_volume(struct usb_mixer_interface *mixer,
                                    u8 unit_id, u8 channel, s16 *value)
{
    struct usb_device *dev = mixer->chip->dev;
    unsigned char buf[2];
    int ret;
    
    /* UAC2 GET_CUR Request */
    ret = snd_usb_ctl_msg(dev, usb_rcvctrlpipe(dev, 0),
                          UAC2_CS_CUR,
                          USB_RECIP_INTERFACE | USB_TYPE_CLASS | USB_DIR_IN,
                          (UAC2_FU_VOLUME << 8) | channel,
                          (unit_id << 8) | mixer->hostif->desc.bInterfaceNumber,
                          buf, sizeof(buf));
    
    if (ret < 0) {
        dev_err(&dev->dev, "AudioBox VSL: Failed to get volume (ret=%d)\n", ret);
        return ret;
    }
    
    /* Little-Endian 16-bit signed */
    *value = buf[0] | (buf[1] << 8);
    return 0;
}

/**
 * audiobox_vsl_set_volume - Establecer volumen de un canal
 */
static int audiobox_vsl_set_volume(struct usb_mixer_interface *mixer,
                                    u8 unit_id, u8 channel, s16 value)
{
    struct usb_device *dev = mixer->chip->dev;
    unsigned char buf[2];
    
    /* Little-Endian encoding */
    buf[0] = value & 0xFF;
    buf[1] = (value >> 8) & 0xFF;
    
    /* UAC2 SET_CUR Request */
    return snd_usb_ctl_msg(dev, usb_sndctrlpipe(dev, 0),
                           UAC2_CS_CUR,
                           USB_RECIP_INTERFACE | USB_TYPE_CLASS | USB_DIR_OUT,
                           (UAC2_FU_VOLUME << 8) | channel,
                           (unit_id << 8) | mixer->hostif->desc.bInterfaceNumber,
                           buf, sizeof(buf));
}

/**
 * audiobox_vsl_volume_get - Callback ALSA para leer volumen
 */
static int audiobox_vsl_volume_get(struct snd_kcontrol *kcontrol,
                                    struct snd_ctl_elem_value *ucontrol)
{
    struct usb_mixer_elem_info *elem = kcontrol->private_data;
    s16 value;
    int ret;
    
    ret = audiobox_vsl_get_volume(elem->head.mixer,
                                   FU_PLAYBACK_UNIT,
                                   1,  /* Left channel */
                                   &value);
    if (ret < 0)
        return ret;
    
    /* Convertir de 1/256 dB a 0.01 dB (formato ALSA estándar) */
    ucontrol->value.integer.value[0] = (value * 100) / 256;
    return 0;
}

/**
 * audiobox_vsl_volume_put - Callback ALSA para establecer volumen
 */
static int audiobox_vsl_volume_put(struct snd_kcontrol *kcontrol,
                                    struct snd_ctl_elem_value *ucontrol)
{
    struct usb_mixer_elem_info *elem = kcontrol->private_data;
    s16 value;
    
    /* Convertir de 0.01 dB a 1/256 dB */
    value = (ucontrol->value.integer.value[0] * 256) / 100;
    
    return audiobox_vsl_set_volume(elem->head.mixer,
                                    FU_PLAYBACK_UNIT,
                                    1,  /* Left channel */
                                    value);
}

/**
 * audiobox_vsl_volume_info - Información del control de volumen
 */
static int audiobox_vsl_volume_info(struct snd_kcontrol *kcontrol,
                                     struct snd_ctl_elem_info *uinfo)
{
    uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
    uinfo->count = 1;
    uinfo->value.integer.min = -6000;  /* -60 dB */
    uinfo->value.integer.max = 1200;   /* +12 dB */
    uinfo->value.integer.step = 1;     /* 0.01 dB steps */
    return 0;
}

/**
 * Definición del control ALSA
 */
static const struct snd_kcontrol_new audiobox_vsl_controls[] = {
    {
        .iface = SNDRV_CTL_ELEM_IFACE_MIXER,
        .name = "AudioBox VSL Playback Volume",
        .info = audiobox_vsl_volume_info,
        .get = audiobox_vsl_volume_get,
        .put = audiobox_vsl_volume_put,
    },
};

/**
 * snd_audiobox_vsl_init - Inicialización del quirk
 */
int snd_audiobox_vsl_init(struct usb_mixer_interface *mixer)
{
    struct usb_mixer_elem_info *elem;
    struct snd_kcontrol *kctl;
    int err;
    
    dev_info(&mixer->chip->dev->dev, 
             "Initializing AudioBox 22 VSL custom controls\n");
    
    /* Crear elemento del mixer */
    elem = kzalloc(sizeof(*elem), GFP_KERNEL);
    if (!elem)
        return -ENOMEM;
    
    elem->head.mixer = mixer;
    elem->head.id = 0;
    elem->control = FU_PLAYBACK_UNIT;
    elem->idx_off = 0;
    elem->channels = 1;
    elem->val_type = USB_MIXER_S16;
    
    /* Crear control ALSA */
    kctl = snd_ctl_new1(&audiobox_vsl_controls[0], elem);
    if (!kctl) {
        kfree(elem);
        return -ENOMEM;
    }
    
    /* Agregar control al mixer */
    err = snd_usb_mixer_add_list(&elem->head, kctl, false);
    if (err < 0) {
        dev_err(&mixer->chip->dev->dev,
                "Failed to add AudioBox VSL controls (err=%d)\n", err);
        kfree(elem);
        snd_ctl_free_one(kctl);
        return err;
    }
    
    return 0;
}
