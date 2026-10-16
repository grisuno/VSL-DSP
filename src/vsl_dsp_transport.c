#include "vsl_dsp_transport.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libusb-1.0/libusb.h>

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

    if (libusb_kernel_driver_active(dev->handle, VSL_MIDI_IFACE)) {
        libusb_detach_kernel_driver(dev->handle, VSL_MIDI_IFACE);
    }
    if (libusb_claim_interface(dev->handle, VSL_MIDI_IFACE) != 0) {
        libusb_close(dev->handle);
        libusb_exit(NULL);
        free(dev);
        return NULL;
    }

    return (vsl_device_handle)dev;
}

void VSL_Close_Device(vsl_device_handle handle)
{
    struct vsl_device *dev;
    int released, attached;

    if (!handle) return;
    dev = (struct vsl_device *)handle;

    if (dev->handle) {
        released = libusb_release_interface(dev->handle, VSL_MIDI_IFACE);
        attached = -1;
        if (released == 0) {
            attached = libusb_attach_kernel_driver(dev->handle,
                                                   VSL_MIDI_IFACE);
        }
        if (released != 0 || attached != 0) {
            fprintf(stderr,
                    "VSL_Close_Device: MIDI iface %u not restored "
                    "(release=%s attach=%s); re-enumerate the device\n",
                    VSL_MIDI_IFACE,
                    libusb_error_name(released),
                    attached == -1 ? "skipped" : libusb_error_name(attached));
        }
        libusb_close(dev->handle);
    }
    libusb_exit(NULL);
    free(dev);
}

int VSL_Probe_Device(uint16_t vendor_id,
                     uint16_t product_id,
                     char *out,
                     size_t out_len)
{
    libusb_device_handle *handle;
    libusb_device *device;
    struct libusb_device_descriptor desc;
    unsigned int bus_number;
    unsigned int device_address;
    unsigned char manufacturer[64];
    unsigned char product[64];
    unsigned char serial[32];
    int written;

    if (!out || out_len == 0) return -1;
    out[0] = '\0';

    if (libusb_init(NULL) != 0) return -1;

    handle = libusb_open_device_with_vid_pid(NULL, vendor_id, product_id);
    if (!handle) {
        libusb_exit(NULL);
        return -1;
    }
    device = libusb_get_device(handle);

    if (libusb_get_device_descriptor(device, &desc) != 0) {
        libusb_close(handle);
        libusb_exit(NULL);
        return -1;
    }

    manufacturer[0] = '\0';
    product[0] = '\0';
    serial[0] = '\0';
    if (libusb_get_string_descriptor_ascii(handle, desc.iManufacturer,
            manufacturer, (int)sizeof(manufacturer)) < 0) {
        manufacturer[0] = '\0';
    }
    if (libusb_get_string_descriptor_ascii(handle, desc.iProduct,
            product, (int)sizeof(product)) < 0) {
        product[0] = '\0';
    }
    if (libusb_get_string_descriptor_ascii(handle, desc.iSerialNumber,
            serial, (int)sizeof(serial)) < 0) {
        serial[0] = '\0';
    }

    bus_number = (unsigned int)libusb_get_bus_number(device);
    device_address = (unsigned int)libusb_get_device_address(device);
    libusb_close(handle);
    libusb_exit(NULL);

    written = snprintf(out, out_len,
                       "manufacturer=%s product=%s serial=%s bus=%u addr=%u",
                       (const char *)manufacturer, (const char *)product,
                       (const char *)serial, bus_number, device_address);
    if (written < 0 || (size_t)written >= out_len) {
        out[0] = '\0';
        return -1;
    }

    return 0;
}

int VSL_Build_Packet(uint16_t dsp_param_id,
                     uint16_t encoded_value,
                     unsigned char *out)
{
    if (!out) return -1;

    memset(out, 0, VSL_PACKET_SIZE);
    out[0] = (unsigned char)VSL_REPORT_ID;
    /* FIXME blocker #3: little-endian assumed, verify in FUN_00412345 */
    out[1] = (unsigned char)(dsp_param_id & 0xFFU);
    out[2] = (unsigned char)((dsp_param_id >> 8) & 0xFFU);
    out[3] = (unsigned char)(encoded_value & 0xFFU);
    out[4] = (unsigned char)((encoded_value >> 8) & 0xFFU);

    return 0;
}

int VSL_Send_Parameter(vsl_device_handle handle,
                       uint16_t dsp_param_id,
                       uint16_t encoded_value)
{
    unsigned char buf[VSL_PACKET_SIZE];
    struct vsl_device *dev;
    int transferred, ret;

    if (!handle) return -1;
    dev = (struct vsl_device *)handle;
    if (!dev->handle) return -1;

    if (VSL_Build_Packet(dsp_param_id, encoded_value, buf) != 0) return -1;

    ret = libusb_bulk_transfer(dev->handle, VSL_EP_MIDI_OUT,
                               buf, sizeof(buf), &transferred,
                               VSL_USB_TIMEOUT_MS);
    if (ret != 0) {
        fprintf(stderr, "VSL_Send_Parameter: bulk write failed: %s\n",
                libusb_error_name(ret));
        return -1;
    }
    if (transferred != (int)sizeof(buf)) {
        fprintf(stderr, "VSL_Send_Parameter: short write %d of %zu\n",
                transferred, sizeof(buf));
        return -1;
    }

    return 0;
}
