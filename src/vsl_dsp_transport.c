#include "vsl_dsp_transport.h"
#include <stdio.h>
#include <stdlib.h>

/* Stub implementation for HID transport - to be replaced with real HIDAPI code */
vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id) {
    (void)vendor_id;
    (void)product_id;
    fprintf(stderr, "VSL_Init_Device: stub called (not implemented)\\n");
    return (vsl_device_handle)0x1; /* dummy non-null handle */
}

void VSL_Close_Device(vsl_device_handle handle) {
    (void)handle;
    fprintf(stderr, "VSL_Close_Device: stub called (not implemented)\\n");
}

int VSL_Send_Parameter(vsl_device_handle handle, uint16_t dsp_param_id, uint32_t encoded_value) {
    (void)handle;
    (void)dsp_param_id;
    (void)encoded_value;
    fprintf(stderr, "VSL_Send_Parameter: stub called (not implemented)\\n");
    return -1; /* indicate not implemented */
}