#ifndef VSL_DSP_TRANSPORT_H
#define VSL_DSP_TRANSPORT_H

#include <stdint.h>
#include "vsl_dsp_logic.h"
#include "vsl_config.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void* vsl_device_handle;

/**
 * @brief Open a VSL device by USB VID/PID and claim the MIDI control interface.
 * @param vendor_id USB vendor ID (typically VSL_VENDOR_ID).
 * @param product_id USB product ID for the specific VSL model.
 * @return Opaque handle on success, NULL on failure.
 */
vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id);

/**
 * @brief Release the MIDI interface and close the device.
 * @param handle Handle from VSL_Init_Device. NULL is a safe no-op.
 */
void VSL_Close_Device(vsl_device_handle handle);

/**
 * @brief Send a DSP parameter value to the device via USB bulk transfer.
 * @param handle Handle from VSL_Init_Device.
 * @param dsp_param_id 16-bit DSP parameter identifier.
 * @param encoded_value 16-bit encoded integer value.
 * @return 0 on success, negative on error.
 */
int VSL_Send_Parameter(vsl_device_handle handle,
                       uint16_t dsp_param_id,
                       uint16_t encoded_value);

#ifdef __cplusplus
}
#endif

#endif
