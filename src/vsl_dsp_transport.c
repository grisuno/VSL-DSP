#include "vsl_dsp_transport.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libusb-1.0/libusb.h>

/*
 * The AudioBox 22 VSL has no standard USB HID interface. Its VSL DSP
 * control plane is accessed through USB bulk transfers on the MIDI
 * interface (interface 4, EP 0x02 OUT). The 64-byte packet format is
 * the same as identified in the Android driver disassembly:
 *
 *   buf[0]   = Report ID (working hypothesis: 0x06)
 *   buf[1-2] = Parameter ID (Little-Endian)
 *   buf[3-4] = Encoded Value (Little-Endian)
 *   buf[5-63]= Padding (zero)
 *
 * FIXME: VSL_REPORT_ID must be extracted from the disassembly
 * (buf[0] before FUN_00412345). Currently 0x06 from legacy/vsl_config.h,
 * not yet verified in Ghidra.
 */
#define VSL_VENDOR_ID   0x194f
#define VSL_PRODUCT_ID  0x0101
#define VSL_REPORT_ID   0x06
#define VSL_PACKET_SIZE 64

#define MIDI_IFACE      4
#define EP_MIDI_OUT     0x02

struct vsl_device {
    libusb_device_handle *handle;
    uint16_t vendor_id;
    uint16_t product_id;
};

vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id)
{
    struct vsl_device *dev;

    dev = (struct vsl_device *)malloc(sizeof(struct vsl_device));
    if (!dev) return NULL;

    if (libusb_init(NULL) != 0) {
        free(dev);
        return NULL;
    }

    dev->handle = libusb_open_device_with_vid_pid(NULL, vendor_id, product_id);
    if (!dev->handle) {
        libusb_exit(NULL);
        free(dev);
        return NULL;
    }

    dev->vendor_id = vendor_id;
    dev->product_id = product_id;

    libusb_set_auto_detach_kernel_driver(dev->handle, 1);
    libusb_detach_kernel_driver(dev->handle, MIDI_IFACE);
    libusb_claim_interface(dev->handle, MIDI_IFACE);

    return (vsl_device_handle)dev;
}

void VSL_Close_Device(vsl_device_handle handle)
{
    struct vsl_device *dev;

    if (!handle) return;
    dev = (struct vsl_device *)handle;

    if (dev->handle) {
        libusb_release_interface(dev->handle, MIDI_IFACE);
        libusb_attach_kernel_driver(dev->handle, MIDI_IFACE);
        libusb_close(dev->handle);
    }
    libusb_exit(NULL);
    free(dev);
}

int VSL_Send_Parameter(vsl_device_handle handle,
                       uint16_t dsp_param_id,
                       uint32_t encoded_value)
{
    unsigned char buf[VSL_PACKET_SIZE];
    struct vsl_device *dev;
    int transferred, ret;

    if (!handle) return -1;
    dev = (struct vsl_device *)handle;
    if (!dev->handle) return -1;

    memset(buf, 0, sizeof(buf));
    buf[0] = VSL_REPORT_ID;
    buf[1] = (unsigned char)(dsp_param_id & 0xFF);
    buf[2] = (unsigned char)((dsp_param_id >> 8) & 0xFF);
    buf[3] = (unsigned char)(encoded_value & 0xFF);
    buf[4] = (unsigned char)((encoded_value >> 8) & 0xFF);

    ret = libusb_bulk_transfer(dev->handle, EP_MIDI_OUT,
                               buf, sizeof(buf), &transferred, 1000);
    if (ret != 0) {
        fprintf(stderr, "VSL_Send_Parameter: bulk write failed: %s\n",
                libusb_error_name(ret));
        return -1;
    }

    return 0;
}
