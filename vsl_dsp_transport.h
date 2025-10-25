// vsl_dsp_transport.h

#ifndef VSL_DSP_TRANSPORT_H
#define VSL_DSP_TRANSPORT_H

#include <stdint.h>
#include <stddef.h> // Para size_t

// Definición de la estructura del paquete DSP (La hipótesis más común)
typedef struct {
    uint16_t header;         // Byte(s) de control/checksum (0x0000 o fijo)
    uint16_t param_id;       // ID binario del parámetro (Ej: 0x1A01)
    uint16_t encoded_value;  // Valor codificado (0 a 65535)
} VSL_DSP_Packet;

// Constantes de escala final para la conversión float -> int
#define VSL_MAX_ENCODED_INT 65535
#define VSL_SCALE_FACTOR 65.535f 

// Declaración de la función de I/O de bajo nivel (solo la simulación)
void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t length);
void VSL_Build_And_Send_Packet(uint16_t param_id, float encoded_value);
#endif // VSL_DSP_TRANSPORT_H
