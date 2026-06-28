#ifndef VSL_DSP_TRANSPORT_H
#define VSL_DSP_TRANSPORT_H

#include <stdint.h>
#include "vsl_dsp_logic.h"

#ifdef __cplusplus
extern "C" {
#endif

/** Opaque handle for the HID device */
typedef void* vsl_device_handle;

/**
 * @brief Initialize the HID device connection.
 * @param vendor_id USB vendor ID (e.g., 0x194f)
 * @param product_id USB product ID (e.g., 0x0101)
 * @return Valid handle on success, NULL on failure.
 */
vsl_device_handle VSL_Init_Device(uint16_t vendor_id, uint16_t product_id);

/**
 * @brief Close the HID device connection.
 * @param handle The device handle returned by VSL_Init_Device.
 */
void VSL_Close_Device(vsl_device_handle handle);

/**
 * @brief Build and send a DSP parameter packet to the device.
 * @param handle The device handle.
 * @param dsp_param_id The DSP parameter ID (from VSL_Parameter::dsp_param_id).
 * @param encoded_float The encoded float value (from VSL_Final_Encode_To_Int, converted to float?).
 *        Note: The actual packet building is done in VSL_Build_And_Send_Packet in vsl_dsp_logic.c.
 *        This function is a placeholder for the HID transport.
 * @return 0 on success, negative error code on failure.
 */
int VSL_Send_Parameter(vsl_device_handle handle, uint16_t dsp_param_id, uint32_t encoded_value);

#ifdef __cplusplus
}
#endif

#endif // VSL_DSP_TRANSPORT_H