// vsl_dsp_transport.h (CORREGIDO)

#ifndef VSL_DSP_TRANSPORT_H
#define VSL_DSP_TRANSPORT_H

#include <stdint.h>
#include <stddef.h>
#include <hidapi/hidapi.h> 
#include "vsl_config.h" // Solo incluye la configuración

// Estructura de Paquete: Sin 'header' (lo quitaste en la estructura typedef)
typedef struct {
    uint16_t param_id;
    uint16_t encoded_value;
} VSL_DSP_Packet;


// 1. Funciones de Inicialización y Cierre (¡Ambas declaradas!)
int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id); // Faltaba esta declaración
void VSL_Close_Device(void);
hid_device* VSL_Get_Device_Handle(void);

// 2. Funciones de Envío
void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length); 
void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float);

#endif // VSL_DSP_TRANSPORT_H