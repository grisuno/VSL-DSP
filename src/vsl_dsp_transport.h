#ifndef VSL_DSP_TRANSPORT_H
#define VSL_DSP_TRANSPORT_H

#include <stdint.h>
#include "vsl_dsp_logic.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void* vsl_device_handle;

vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id);

void VSL_Close_Device(vsl_device_handle handle);

int VSL_Send_Parameter(vsl_device_handle handle,
                       uint16_t dsp_param_id,
                       uint32_t encoded_value);

#ifdef __cplusplus
}
#endif

#endif
