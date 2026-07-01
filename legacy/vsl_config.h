// vsl_config.h (VERSION CORREGIDA)

#ifndef VSL_CONFIG_H
#define VSL_CONFIG_H

#include <stdint.h>

// =======================================================
// BLOQUEADORES CRÍTICOS (Hardware)
// =======================================================
#define VSL_VENDOR_ID   0x194f
#define VSL_PRODUCT_ID  0x0101
#define VSL_REPORT_ID   0x06

// =======================================================
// CONSTANTES CRÍTICAS VSL-DSP (Necesarias para la lógica)
// =======================================================

// Factor de escala usado en la fórmula VSL (Confirmado en la PoC Python)
#define VSL_SCALE_FACTOR        1000.0f 

// Máximo valor codificado de 16 bits (0xFFFF)
#define VSL_MAX_ENCODED_INT     65535 

#define VSL_PACKET_SIZE         64      // 0x40 bytes
#define VSL_PAYLOAD_SIZE        5       // Byte 1 (ID LSB) a Byte 4 (Value MSB)

#endif // VSL_CONFIG_H