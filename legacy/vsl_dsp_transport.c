// vsl_dsp_transport.c (Añadir la Plantilla B completa aquí)

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <hidapi/hidapi.h>
#include <stdlib.h>
#include "vsl_config.h" 
#include "vsl_dsp_transport.h" 

// Handle de Singleton (Regla #5: Diseño Escalable)
static hid_device *vsl_device_handle = NULL;


// =======================================================
// IMPLEMENTACIÓN DE TRANSPORTE FALTANTE
// =======================================================

// vsl_dsp_transport.c (Refactorización de VSL_Init_Device)

// ... (las inclusiones y el singleton handle) ...

int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id) {
    if (vsl_device_handle) return 0;
    
    // 1. Inicializar HIDAPI
    if (hid_init() != 0) {
        fprintf(stderr, "Error: HIDAPI init failed\n");
        return -1;
    }
    
    // 2. Enumerar todos los dispositivos PreSonus (194f)
    struct hid_device_info *devs, *cur_dev;
    // Usamos 0:0 para listar todos los dispositivos HID y encontrar la ruta correcta
    devs = hid_enumerate(0x0, 0x0); 
    cur_dev = devs;
    
    char *target_path = NULL;
    
    // 3. Buscar la interfaz de control (la que coincida con nuestro VID/PID)
    while (cur_dev) {
        if (cur_dev->vendor_id == vendor_id && cur_dev->product_id == product_id) {
            // Encontrado! Tomar la ruta (path) y salir
            target_path = strdup(cur_dev->path);
            break; 
        }
        cur_dev = cur_dev->next;
    }
    
    hid_free_enumeration(devs);
    
    if (target_path) {
        // 4. Intentar abrir el dispositivo por la ruta exacta
        vsl_device_handle = hid_open_path(target_path);
        free(target_path);
    }

    if (!vsl_device_handle) {
        // Si sigue fallando, es definitivamente un problema de permisos/kernel.
        fprintf(stderr, "Error: Cannot open VSL device %04X:%04X via path.\n",
                vendor_id, product_id);
        hid_exit();
        return -2;
    }
    
    printf("VSL Device handle opened successfully via path: %04X:%04X\n", vendor_id, product_id);
    return 0;
}

void VSL_Close_Device(void) {
    if (vsl_device_handle) {
        hid_close(vsl_device_handle);
        vsl_device_handle = NULL;
        printf("VSL Device handle closed\n");
    }
    hid_exit();
}

hid_device* VSL_Get_Device_Handle(void) {
    return vsl_device_handle;
}

// ... (El resto de tus funciones FUN_Send_Packet y VSL_Build_And_Send_Packet)

// NOTA: En VSL_Build_And_Send_Packet, ¡quita la línea del header!
/*
    VSL_DSP_Packet packet = {
        //.header = 0x0000, // << QUITAR ESTA LINEA
        .param_id = dsp_param_id,
        .encoded_value = final_int
    };
*/
/**
 * @brief Función de I/O real usando HIDAPI.
 * @note DEBE SER REEMPLAZADA con la lógica específica de tu dispositivo (Report ID, longitud, etc.)
 */
void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length) {
    
    // 1. Abrir el dispositivo
    hid_device *handle = VSL_Get_Device_Handle(); // O usar el handle estático vsl_device_handle
    if (!handle) {
        fprintf(stderr, "Error: Dispositivo VSL no inicializado.\n");
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
    int res = hid_write(handle, buf, sizeof(buf));
    
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
        .param_id = dsp_param_id,
        .encoded_value = final_int
    };
    
    // 3. I/O (Llamada de envío)
    FUN_Send_Packet(&packet, sizeof(VSL_DSP_Packet));
}
