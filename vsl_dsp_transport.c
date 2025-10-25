// vsl_dsp_transport.c

#include "vsl_dsp_transport.h"
#include <stdio.h>
#include <math.h> 
#include <hidapi/hidapi.h>
#include <string.h>

// Reemplazar con los IDs de tu dispositivo
#define VSL_VENDOR_ID 0x1234 // Ejemplo: 0x1234
#define VSL_PRODUCT_ID 0x5678 // Ejemplo: 0x5678
#define VSL_REPORT_ID 0x01 // Usualmente 0x00 o 0x01 para un Output Report

/**
 * @brief Función de I/O real usando HIDAPI.
 * @note DEBE SER REEMPLAZADA con la lógica específica de tu dispositivo (Report ID, longitud, etc.)
 */
void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length) {
    
    // 1. Abrir el dispositivo
    hid_device *handle = hid_open(VSL_VENDOR_ID, VSL_PRODUCT_ID, NULL);
    if (!handle) {
        fprintf(stderr, "Error: No se pudo abrir el dispositivo VSL.\n");
        return;
    }
    
    // 2. Preparar el buffer de salida (Ejemplo: Reporte de 64 bytes)
    // El primer byte es el Report ID (0x01, por ejemplo)
    unsigned char buf[64] = {0}; 
    buf[0] = VSL_REPORT_ID;
    
    // 3. Copiar los datos del paquete (ID + Valor) al buffer después del Report ID
    // Aquí asumimos que el paquete es de 4 bytes (ID + Value) o 6 bytes (Header + ID + Value)
    // Usaremos memcpy para copiar 4 bytes (solo ID y Value, ignorando el header simulado por ahora)
    
    // Asegurarse de que los datos estén en el orden correcto (Little-Endian vs Big-Endian)
    // Si tu DSP usa Little-Endian (lo más común):
    uint16_t net_id = packet->param_id; 
    uint16_t net_value = packet->encoded_value;

    // Copiar ID (2 bytes) y Value (2 bytes) al buffer, iniciando en buf[1] (después del Report ID)
    memcpy(&buf[1], &net_id, sizeof(uint16_t)); 
    memcpy(&buf[3], &net_value, sizeof(uint16_t)); 
    
    // 4. Enviar el paquete (el Output Report)
    int res = hid_send_feature_report(handle, buf, sizeof(buf)); // O hid_write()
    
    if (res < 0) {
        fprintf(stderr, "Error al enviar el paquete HID: %ls\n", hid_error(handle));
    } else {
        printf("--- Paquete DSP Enviado --- Report ID 0x%02X, Bytes: %d\n", VSL_REPORT_ID, res);
        // Desglose del contenido para depuración
        printf("ID: 0x%04X, Value: %u\n", packet->param_id, packet->encoded_value);
    }
    
    // 5. Cerrar el dispositivo (o mantenerlo abierto si es un bucle de control)
    hid_close(handle);
}

// Implementación de la función de construcción y envío
void VSL_Build_And_Send_Packet(uint16_t dsp_param_id, float encoded_float) {
    
    // 1. FMUL y FCVTZS: Conversión Float -> Int con escala
    float scaled_float = encoded_float * VSL_SCALE_FACTOR;
    
    // Truncar a entero (FCVTZS) y Clamping al rango 0-65535
    // roundf simula el comportamiento de truncamiento/redondeo de la FCVTZS
    uint16_t final_int = (uint16_t)fmaxf(0.0f, fminf(roundf(scaled_float), VSL_MAX_ENCODED_INT));

    // 2. Construcción del Paquete
    VSL_DSP_Packet packet = {
        .header = 0x0000, // Reemplazar si el protocolo usa un header diferente
        .param_id = dsp_param_id,
        .encoded_value = final_int
    };
    
    // 3. I/O (Llamada de envío)
    FUN_Send_Packet(&packet, sizeof(VSL_DSP_Packet));
}
