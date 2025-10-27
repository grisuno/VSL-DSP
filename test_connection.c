// test_connection.c

#include <stdio.h>
#include "vsl_config.h" 
#include "vsl_dsp_transport.h" // Asumiendo que esta es la plantilla B

int main() {
    printf("Intentando conectar al dispositivo VSL %04X:%04X...\n", 
           VSL_VENDOR_ID, VSL_PRODUCT_ID);
           
    // Intentar inicializar el dispositivo (abrir el handle HID)
    if (VSL_Init_Device(VSL_VENDOR_ID, VSL_PRODUCT_ID) == 0) {
        printf("\n✅ ¡Conexión Exitosa! El dispositivo está abierto.\n");
        // Aquí iría el test de envío de paquete real (Próximo paso)
        
    } else {
        printf("\n❌ Error de conexión. El handle no pudo ser abierto.\n");
    }

    VSL_Close_Device();
    return 0;
}