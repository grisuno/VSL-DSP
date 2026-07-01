/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * PreSonus AudioBox VSL Family - USB detector kernel module
 *
 * Detects every member of the PreSonus AudioBox VSL family (22 VSL,
 * 44 VSL, 1818 VSL) on the USB bus and logs connection and
 * disconnection events to the kernel ring buffer. The module is a
 * passive observer: probe() returns -ENODEV so the standard
 * snd-usb-audio driver keeps owning the audio interface and
 * playback/capture/mixer continue to work without re-plug.
 *
 * The list of supported product IDs is defined in audiobox_vsl.h as
 * audiobox_models[]. The USB device table below is generated from
 * that single source of truth.
 *
 * Author: grisuno (LazyOwn Project)
 */

#include "audiobox_vsl.h"

#include <linux/module.h>
#include <linux/printk.h>
#include <linux/usb.h>

#define AUDIOBOX_DRIVER_NAME  "audiobox_vsl"
#define AUDIOBOX_DRIVER_DESC  "PreSonus AudioBox VSL family USB detector"
#define AUDIOBOX_DRIVER_LIC   "GPL"

static const struct usb_device_id audiobox_device_table[] = {
    { USB_DEVICE(AUDIOBOX_VENDOR_ID, AUDIOBOX_MODEL_22_VSL)   },
    { USB_DEVICE(AUDIOBOX_VENDOR_ID, AUDIOBOX_MODEL_44_VSL)   },
    { USB_DEVICE(AUDIOBOX_VENDOR_ID, AUDIOBOX_MODEL_1818_VSL) },
    { }
};
MODULE_DEVICE_TABLE(usb, audiobox_device_table);

static int audiobox_probe(struct usb_interface *intf,
                          const struct usb_device_id *id)
{
    struct usb_device *udev = interface_to_usbdev(intf);
    uint16_t pid = le16_to_cpu(udev->descriptor.idProduct);
    const audiobox_model_info_t *model = audiobox_lookup_model(pid);
    const char *name = (model != NULL) ? model->product_name : "unknown";
    const char *mfg = (udev->manufacturer != NULL) ? udev->manufacturer : "(null)";
    const char *prod = (udev->product != NULL) ? udev->product : "(null)";
    const char *serial = (udev->serial != NULL) ? udev->serial : "(null)";

    dev_info(&intf->dev,
             "audiobox_vsl: detected '%s' (%04x:%04x)\n",
             name,
             le16_to_cpu(udev->descriptor.idVendor),
             pid);
    dev_info(&intf->dev, "audiobox_vsl:   manufacturer=%s product=%s serial=%s\n",
             mfg, prod, serial);

    return -ENODEV;
}

static void audiobox_disconnect(struct usb_interface *intf)
{
    struct usb_device *udev = interface_to_usbdev(intf);
    uint16_t pid = le16_to_cpu(udev->descriptor.idProduct);
    const audiobox_model_info_t *model = audiobox_lookup_model(pid);
    const char *name = (model != NULL) ? model->product_name : "unknown";

    dev_info(&intf->dev, "audiobox_vsl: disconnected '%s' (%04x:%04x)\n",
             name,
             le16_to_cpu(udev->descriptor.idVendor),
             pid);
}

static struct usb_driver audiobox_driver = {
    .name       = AUDIOBOX_DRIVER_NAME,
    .probe      = audiobox_probe,
    .disconnect = audiobox_disconnect,
    .id_table   = audiobox_device_table,
};

module_usb_driver(audiobox_driver);

MODULE_LICENSE(AUDIOBOX_DRIVER_LIC);
MODULE_AUTHOR("grisuno <lazyown.redteam@gmail.com>");
MODULE_DESCRIPTION(AUDIOBOX_DRIVER_DESC);
MODULE_VERSION("2.0.0");
