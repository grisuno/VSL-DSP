# 🎯 VSL-DSP Open Source Driver
Desarrollar un Cliente Open Source (Driver/Library) funcional para dispositivos de audio VSL-DSP

## 🧬 BASE DE CONOCIMIENTO INMUTABLE
Estado del Proyecto: 90% Completo - 3 Bloqueadores Críticos
Componente	Estado	Evidencia Técnica
- Arquitectura	✅ CONFIRMADA	C puro, separación modular (vsl_dsp_logic.c + vsl_dsp_transport.c), preparado para wrappers C++ via extern "C"
- Codificación de Ganancia	✅ IMPLEMENTADA	VSL_Encode_Gain() - Curva exponencial: coeff_offset_A + coeff_C1 * exp(norm_factor * log_factor)
- Codificación de Frecuencia	✅ IMPLEMENTADA	VSL_Map_Frequency() / VSL_Decode_Frequency() - Mapeo logarítmico base 2: exp2f(log2_min + pos * (log2_max - log2_min))
- Conversión Float→Int	✅ VALIDADA	Escala: 1000.0f → 65535 <br> Test confirmado: 0.75 → 40793
- Estructura de Parámetros	✅ CONFIRMADA	VSL_Parameter con 8 campos: {coeff_offset_A, coeff_C1, log_factor, curve_min_map, curve_max_map, freq_min_hz, freq_max_hz, dsp_param_id, max_encoded_int}
- Protocolo USB-HID	✅ PARCIALMENTE CONFIRMADO	Tipo: HID Feature/Output Report<br>Tamaño: 64 bytes (0x40)<br>Payload mínimo: 6 bytes
- Implementación I/O	✅ FUNCIONAL	HIDAPI userspace, compilación exitosa: gcc -lhidapi-libusb



## 📍 BLOQUEADORES CRÍTICOS (Valores Pendientes)

```c
// ESTOS 3 VALORES DEBEN SER EXTRAÍDOS DEL DESENSAMBLADO:
#define VSL_VENDOR_ID   0x????  // ⚠️ CRÍTICO - Buscar en strings o constantes hexadecimales
#define VSL_PRODUCT_ID  0x????  // ⚠️ CRÍTICO - Buscar en strings o constantes hexadecimales  
#define VSL_REPORT_ID   0x??    // ⚠️ CRÍTICO - Buscar en buf[0] antes de FUN_00412345
```

## 📐 CONOCIMIENTO CONFIRMADO DE LA ESCUCHA WIRESHARK

```c
void FUN_00412345(int param_1, VSL_DSP_Packet *packet_data) {
    // Llamada a función de transferencia USB/HID
    iVar2 = (*(code *)param_1)(buf, 0x40, 0, 0);  
    //                              ↑     ↑  ↑  ↑
    //                              │     │  │  └─ Flags/Timeout (0)
    //                              │     │  └──── Reserved (0)
    //                              │     └─────── Longitud: 64 bytes
    //                              └───────────── Buffer de datos
    
    if (iVar2 < 0) {
        // Manejo de error de escritura USB
        FUN_00412ab0(L"Error al escribir en el dispositivo USB.");
    }
    return;
}
```
**Implicaciones Confirmadas:**
- ✅ Tamaño del paquete HID: **64 bytes (0x40 hex)** - Estándar HID
- ✅ Tipo de transferencia: **Control Transfer** o **Feature Report**
- ⚠️ **Pendiente**: Construcción de `buf[]` en la función padre 
---

```c
// Tabla de validación (llenar con datos reales):
/*
┌─────────────────┬──────────────┬───────────────┬─────────┐
│ Control GUI     │ Valor User   │ Código Output │ Match?  │
├─────────────────┼──────────────┼───────────────┼─────────┤
│ Gain 0%         │ 0.0f         │ 0x0000        │ ⚠️ TBD  │
│ Gain 25%        │ 0.25f        │ 0x????        │ ⚠️ TBD  │
│ Gain 50%        │ 0.5f         │ 0x7FFF        │ ⚠️ TBD  │
│ Gain 75%        │ 0.75f        │ 0x9F39(40793) │ ✅ OK   │
│ Gain 100%       │ 1.0f         │ 0xFFFF        │ ⚠️ TBD  │
│ Freq @ 1kHz     │ ~0.5f        │ 0x????        │ ⚠️ TBD  │
└─────────────────┴──────────────┴───────────────┴─────────┘
*/

```

📦 PLANTILLAS DE CÓDIGO (Reference Implementation)
A) Enumeración de Dispositivos (vsl_discover.c)
```c
#include <stdio.h>
#include <wchar.h>
#include <hidapi/hidapi.h>

void VSL_Enumerate_All_Devices(void) {
    struct hid_device_info *devs, *cur_dev;
    
    if (hid_init()) {
        fprintf(stderr, "Error: Cannot initialize HIDAPI\n");
        return;
    }
    
    devs = hid_enumerate(0x0, 0x0);  // Enumerar TODOS
    cur_dev = devs;
    
    printf("=== HID Devices Enumeration ===\n\n");
    
    while (cur_dev) {
        printf("VID:PID       : 0x%04hx:0x%04hx\n", 
               cur_dev->vendor_id, cur_dev->product_id);
        
        if (cur_dev->manufacturer_string)
            wprintf(L"Manufacturer  : %ls\n", cur_dev->manufacturer_string);
        if (cur_dev->product_string)
            wprintf(L"Product       : %ls\n", cur_dev->product_string);
        if (cur_dev->serial_number)
            wprintf(L"Serial        : %ls\n", cur_dev->serial_number);
        
        printf("Path          : %s\n", cur_dev->path);
        printf("Interface     : %d\n", cur_dev->interface_number);
        printf("Usage Page    : 0x%04hx\n", cur_dev->usage_page);
        printf("Usage         : 0x%04hx\n", cur_dev->usage);
        printf("---\n\n");
        
        cur_dev = cur_dev->next;
    }
    
    hid_free_enumeration(devs);
    hid_exit();
}

int main(void) {
    VSL_Enumerate_All_Devices();
    return 0;
}
```
Compilar:

```bash
gcc vsl_discover.c -o vsl_discover -lhidapi-libusb -Wall -Wextra
sudo ./vsl_discover | grep -i "presonus\|audiobox" -A 8
```
B) Gestión de Dispositivo (Singleton Pattern)
```c
// vsl_dsp_transport.c - Versión Production

static hid_device *vsl_device_handle = NULL;

int VSL_Init_Device(uint16_t vendor_id, uint16_t product_id) {
    if (vsl_device_handle) {
        fprintf(stderr, "Warning: Device already initialized\n");
        return 0;  // Ya está abierto
    }
    
    if (hid_init() != 0) {
        fprintf(stderr, "Error: HIDAPI init failed\n");
        return -1;
    }
    
    vsl_device_handle = hid_open(vendor_id, product_id, NULL);
    if (!vsl_device_handle) {
        fprintf(stderr, "Error: Cannot open VSL device %04X:%04X\n",
                vendor_id, product_id);
        hid_exit();
        return -2;
    }
    
    printf("VSL Device opened successfully: %04X:%04X\n",
           vendor_id, product_id);
    return 0;
}

void VSL_Close_Device(void) {
    if (vsl_device_handle) {
        hid_close(vsl_device_handle);
        vsl_device_handle = NULL;
        printf("VSL Device closed\n");
    }
    hid_exit();
}

hid_device* VSL_Get_Device_Handle(void) {
    return vsl_device_handle;
}
```
C) Construcción de Paquete (Template Final - Pendiente de 3 valores)
```c
void FUN_Send_Packet(const VSL_DSP_Packet *packet, size_t packet_length) {
    hid_device *handle = VSL_Get_Device_Handle();
    
    // Validación de estado
    if (!handle) {
        fprintf(stderr, "Error: Device not initialized. Call VSL_Init_Device() first.\n");
        return;
    }
    
    if (!packet) {
        fprintf(stderr, "Error: NULL packet pointer\n");
        return;
    }
    
    // Construcción del buffer HID (64 bytes confirmado)
    unsigned char buf[64] = {0};
    
    // ⚠️ PENDIENTE: Obtener del desensamblado
    buf[0] = VSL_REPORT_ID;  // ← Valor crítico pendiente
    
    // Payload (Little-Endian asumido, verificar en desensamblado)
    buf[1] = packet->param_id & 0xFF;
    buf[2] = (packet->param_id >> 8) & 0xFF;
    buf[3] = packet->encoded_value & 0xFF;
    buf[4] = (packet->encoded_value >> 8) & 0xFF;
    // buf[5-63] = 0x00 (padding, ya inicializado)
    
    // Envío HID (usar hid_write para Output Report o hid_send_feature_report)
    int res = hid_write(handle, buf, sizeof(buf));
    
    if (res < 0) {
        fprintf(stderr, "HID Write Error: %ls\n", hid_error(handle));
    } else {
        printf("Packet sent: ID=0x%04X, Value=%u (%d bytes written)\n",
               packet->param_id, packet->encoded_value, res);
    }
}
```

---

## ✅ CHECKLIST DE FINALIZACIÓN DEL PROYECTO

### **Fase Actual: 90% - Bloqueadores Críticos**

| Tarea | Estado | Notas |
|-------|--------|-------|
| **Lógica matemática DSP** | ✅ **COMPLETA** | Gain, Frequency encoding/decoding |
| **Conversión Float→Int** | ✅ **VALIDADA** | Test: 0.75 → 40793 |
| **Estructura de parámetros** | ✅ **CONFIRMADA** | `VSL_Parameter` con 8 campos |
| **HIDAPI integrado** | ✅ **COMPILABLE** | `gcc -lhidapi-libusb` exitoso |
| **Tamaño de paquete** | ✅ **CONFIRMADO** | 64 bytes (0x40) del desensamblado |
| **VID/PID del dispositivo** | ⚠️ **BLOQUEADOR #1** | Ejecutar `vsl_discover` o buscar en desensamblado |
| **Report ID** | ⚠️ **BLOQUEADOR #2** | Buscar `buf[0]` antes de `FUN_00412345` |
| **Endianness verificado** | ⚠️ **BLOQUEADOR #3** | Verificar orden de bytes en desensamblado |
| **Test con hardware real** | ⏳ **PENDIENTE** | Requiere bloqueadores #1, #2, #3 resueltos |
| **Documentación API** | ⏳ **PENDIENTE** | Post-validación con hardware |

---





![Python](https://img.shields.io/badge/python-3670A0?style=for-the-badge&logo=python&logoColor=ffdd54) ![Shell Script](https://img.shields.io/badge/shell_script-%23121011.svg?style=for-the-badge&logo=gnu-bash&logoColor=white) ![Flask](https://img.shields.io/badge/flask-%23000.svg?style=for-the-badge&logo=flask&logoColor=white) [![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/Y8Y2Z73AV)
