// SPDX-License-Identifier: GPL-2.0
#include <linux/module.h>
#include <linux/usb.h>
#include <sound/core.h>
#include <sound/control.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("grisuno");
MODULE_DESCRIPTION("AudioBox 22 VSL Quirk");

#define VENDOR_ID  0x194f
#define PRODUCT_ID 0x0101

static int audiobox_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
    dev_info(&intf->dev, "🎉 AudioBox 22 VSL Quirk Cargado!\n");
    return -ENODEV; // No reclamar interfaz
}

static void audiobox_disconnect(struct usb_interface *intf)
{
    dev_info(&intf->dev, "AudioBox VSL desconectado\n");
}

static const struct usb_device_id audiobox_table[] = {
    { USB_DEVICE(VENDOR_ID, PRODUCT_ID) },
    { }
};
MODULE_DEVICE_TABLE(usb, audiobox_table);

static struct usb_driver audiobox_driver = {
    .name = "audiobox_vsl_quirk",
    .probe = audiobox_probe,
    .disconnect = audiobox_disconnect,
    .id_table = audiobox_table,
};

module_usb_driver(audiobox_driver);
