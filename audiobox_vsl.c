// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * PreSonus AudioBox 22 VSL - Simple USB driver
 *
 * This driver is a simple USB driver that detects the AudioBox 22 VSL device
 * and logs its connection/disconnection. It does not interfere with the
 * standard snd-usb-audio driver.
 *
 * Copyright (c) 2025 by grisuno (LazyOwn Project)
 */

#include <linux/module.h>
#include <linux/usb.h>
#include <linux/printk.h>

#define VENDOR_ID  0x194f
#define PRODUCT_ID 0x0101

static int audiobox_probe(struct usb_interface *intf,
                          const struct usb_device_id *id)
{
    struct usb_device *udev = interface_to_usbdev(intf);

    dev_info(&intf->dev,
             "🎉 AudioBox 22 VSL detected! Vendor: %04x, Product: %04x\n",
             le16_to_cpu(udev->descriptor.idVendor),
             le16_to_cpu(udev->descriptor.idProduct));
    dev_info(&intf->dev,
             "Manufacturer: %s\n",
             udev->manufacturer ? udev->manufacturer : "(null)");
    dev_info(&intf->dev,
             "Product: %s\n",
             udev->product ? udev->product : "(null)");
    dev_info(&intf->dev,
             "Serial: %s\n",
             udev->serial ? udev->serial : "(null)");

    /* We do not claim the interface, letting snd-usb-audio handle it */
    return -ENODEV;
}

static void audiobox_disconnect(struct usb_interface *intf)
{
    dev_info(&intf->dev, "🔌 AudioBox 22 VSL disconnected\n");
}

static const struct usb_device_id audiobox_table[] = {
    { USB_DEVICE(VENDOR_ID, PRODUCT_ID) },
    { } /* Terminating entry */
};
MODULE_DEVICE_TABLE(usb, audiobox_table);

static struct usb_driver audiobox_driver = {
    .name       = "audiobox_vsl",
    .probe      = audiobox_probe,
    .disconnect = audiobox_disconnect,
    .id_table   = audiobox_table,
};

module_usb_driver(audiobox_driver);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("grisuno <lazyown.redteam@gmail.com>");
MODULE_DESCRIPTION("PreSonus AudioBox 22 VSL simple USB detector");
MODULE_VERSION("1.0");