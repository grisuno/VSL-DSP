# 🎯 🎯 VSL-DSP Open Source Driver - ✅ PROYECTO COMPLETADO
![1_NFRogTqj0gCKMQEIMw19Pg](https://github.com/user-attachments/assets/29cea052-00c0-4ef6-88cb-bb293f254959)

Desarrollar un Cliente Open Source (Driver/Library) funcional para dispositivos de audio VSL-DSP
<img width="5652" height="12737" alt="NotebookLM Mind Map" src="https://github.com/user-attachments/assets/97e82732-83f0-4fb8-98e5-85ba5df3851d" />
## 🎉 ESTADO DEL PROYECTO: 100% COMPLETADO
¡Protocolo completamente descifrado e implementado con éxito!

## 🔓 Descubrimiento Crítico
A través de análisis exhaustivo con Wireshark y captura de tráfico USB, se descubrió que el AudioBox 22 VSL NO usa Bulk Transfers como se asumía inicialmente, sino USB Audio Class 2.0 Control Transfers estándar.

## 🧬 ARQUITECTURA FINAL CONFIRMADA
Protocolo Identificado: USB Audio Class 2.0 (UAC2)

Componente             |  Estado             |  Evidencia Técnica                                 
-----------------------+---------------------+----------------------------------------------------
Tipo de Protocolo      |  ✅IDENTIFICADO      |  USB Audio Class 2.0 Control Requests (NO HID/Bulk)
Tipo de Transferencia  |  ✅CONFIRMADO        |  Control Transfers (0x02) en endpoint 0x80         
Feature Units          |  ✅MAPEADOS          |  Unit 10 (Playback), Unit 11 (Capture)             
Control Requests       |  ✅IMPLEMENTADOS     |  SET_CUR (0x01), GET_CUR (0x01), GET_RANGE (0x02)  
Encoding de Volumen    |  ✅VALIDADO          |  16-bit Little-Endian, 1/256 dB steps              
VID/PID                |  ✅CONFIRMADOS       |  0x194F:0x0101                                     
Test con Hardware      |  ✅EXITOSO           |  Control de volumen y mute funcionando             
Driver Python          |  ✅PRODUCTION-READY  |  API completa y documentada                        
```python
# ID
VENDOR_ID = 0x194F
PRODUCT_ID = 0x0101

# USB Audio Class Control Requests
UAC2_REQUEST_CUR = 0x01      # GET_CUR / SET_CUR
UAC2_REQUEST_RANGE = 0x02    # GET_RANGE
UAC2_REQUEST_MEM = 0x03      # GET_MEM / SET_MEM

# Control Selectors
FU_MUTE_CONTROL = 0x01
FU_VOLUME_CONTROL = 0x02
FU_BASS_CONTROL = 0x03
FU_MID_CONTROL = 0x04
FU_TREBLE_CONTROL = 0x05
FU_GRAPHIC_EQUALIZER_CONTROL = 0x06
FU_AUTOMATIC_GAIN_CONTROL = 0x07
FU_DELAY_CONTROL = 0x08
FU_BASS_BOOST_CONTROL = 0x09
FU_LOUDNESS_CONTROL = 0x0A
```

![unnamed](https://github.com/user-attachments/assets/92ac8607-e7ed-4a88-a872-03578ed3e100)


## 📍 🚀 Implementación Funcional
Driver Python Production-Ready
```python
from vsl_dsp_driver import (
    VSL_DSP_Driver,
    UNIT_PLAYBACK,
    UNIT_CAPTURE,
    CHANNEL_LEFT,
    CHANNEL_RIGHT
)

# Inicializar driver
driver = VSL_DSP_Driver()
driver.initialize()

# Control de volumen (funciona en hardware real)
driver.set_volume(UNIT_PLAYBACK, CHANNEL_LEFT, -6.0)   # ✅ Verificado
driver.set_volume(UNIT_PLAYBACK, CHANNEL_RIGHT, -6.0)  # ✅ Verificado

# Leer volumen actual
vol = driver.get_volume(UNIT_PLAYBACK, CHANNEL_LEFT)   # ✅ Verificado
print(f"Volumen: {vol:.2f} dB")

# Control de mute
driver.set_mute(UNIT_PLAYBACK, CHANNEL_LEFT, True)     # ✅ Verificado

# Obtener rangos soportados
min_db, max_db, step = driver.get_volume_range(UNIT_PLAYBACK, CHANNEL_LEFT)

# Liberar recursos
driver.cleanup()
```

<img width="1140" height="859" alt="image" src="https://github.com/user-attachments/assets/09007847-271c-4a0b-a8e2-765b9aa74556" />

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
## 📊 Especificación Técnica del Protocolo
Control Transfers UAC2
Estructura de Request:
```c
bmRequestType: 0x21  // Class, Interface, OUT
bRequest: 0x01       // SET_CUR / GET_CUR
wValue: (Control_Selector << 8) | Channel
wIndex: (Unit_ID << 8) | Interface
data: [value_low, value_high]  // Little-Endian
```
---

## Control Selectors Implementados:

- FU_MUTE_CONTROL = 0x01: Control de silencio

- FU_VOLUME_CONTROL = 0x02: Control de volumen

### Feature Units del AudioBox 22 VSL:

- Unit 10: Playback (USB → Speakers)

2 canales + Master

- Rango típico: -60 dB a +12 dB

- Unit 11: Capture (Microphone → USB)

2 canales + Master

- Rango típico: 0 dB a +35 dB

## Encoding de Volumen:
```text
Valor dB → Valor UAC2 = dB * 256
Ejemplo: -6.0 dB → -1536 (0xFA00 en Little-Endian)
```

## 🔬 Proceso de Ingeniería Inversa
Metodología Aplicada
Análisis inicial con Ghidra → Funciones matemáticas DSP identificadas

- Captura USB con Wireshark → Protocolo real descubierto (UAC2, no Bulk)

- Análisis de descriptores USB → Feature Units y endpoints mapeados

- Implementación Python → Driver funcional con pyusb

- Validación con hardware → Tests exitosos confirmados

## Herramientas Utilizadas
- Ghidra: Desensamblado del driver Android

- Wireshark + usbmon: Captura de tráfico USB

- pyusb: Implementación del driver Python

- lsusb: Análisis de descriptores USB

## 📦 Instalación y Uso
Requisitos
```bash
# Python 3.8+
sudo apt install python3 python3-pip
```
# Dependencias USB
```bash
sudo pip3 install pyusb
```
## Instalación
```bash
# Clonar repositorio
git clone https://github.com/grisuno/vsl-dsp-driver
cd vsl-dsp-driver
```
```bash
# Ejecutar aplicación de ejemplo
sudo python3 app.py
```

## ✅ CHECKLIST DE PROYECTO COMPLETADO

Tarea                   |  Estado      |  Notas                                
------------------------+--------------+---------------------------------------
Protocolo identificado  |  ✅COMPLETO   |  USB Audio Class 2.0 Control Transfers
Feature Units mapeados  |  ✅COMPLETO   |  Unit 10 (Playback), Unit 11 (Capture)
VID/PID confirmados     |  ✅COMPLETO   |  0x194F:0x0101                        
Encoding implementado   |  ✅COMPLETO   |  16-bit LE, 1/256 dB steps            
Driver Python           |  ✅COMPLETO   |  Production-ready con API documentada 
Test con hardware real  |  ✅COMPLETO   |  Validado con AudioBox 22 VSL         
Control de volumen      |  ✅FUNCIONAL  |  SET_CUR/GET_CUR implementados        
Control de mute         |  ✅FUNCIONAL  |  Probado con hardware                 
Lectura de rangos       |  ✅FUNCIONAL  |  GET_RANGE implementado               
Documentación           |  ✅COMPLETA   |  README, API docs, ejemplos           

Progreso: ██████████████████████ 100% COMPLETO 🎉

## 🔧 Troubleshooting
Error: "Resource busy"
```bash
# Descargar driver del kernel
sudo rmmod snd_usb_audio

# Ejecutar aplicación
sudo python3 app.py

# Recargar driver
sudo modprobe snd_usb_audio
Error: "Cannot import VSL_DSP_Driver"
Asegúrate de tener los archivos separados correctamente:

vsl_dsp_driver.py - Solo la clase del driver

app.py - Tu aplicación que importa el driver
```

### Sin permisos USB
```bash
# Ejecutar con sudo
sudo python3 app.py

# O configurar udev rules (permanente)
echo 'SUBSYSTEM=="usb", ATTR{idVendor}=="194f", ATTR{idProduct}=="0101", MODE="0666"' | sudo tee /etc/udev/rules.d/99-audiobox.rules
sudo udevadm control --reload-rules
```

## 🎓 Lecciones Aprendidas
- No asumir el protocolo: La suposición inicial de Bulk Transfers era incorrecta

- Wireshark es esencial: La captura USB reveló el protocolo real (UAC2)

- Los descriptores USB contienen la verdad: Los Feature Units estaban documentados en los descriptores

- UAC2 es estándar: No requiere protocolos propietarios complejos

- Python + pyusb es suficiente: No se necesitó C/C++ para el PoC funcional

## 🚀 Próximos Pasos
 - GUI con PyQt/GTK para control visual

 - Integración con PulseAudio/PipeWire

- Soporte para más controles DSP (EQ, compressor)

- Port a C/C++ para mejor rendimiento

- Daemon de sistema para control persistente

- Soporte para otros modelos AudioBox VSL

## 📚 Referencias Técnicas
- USB Audio Class 2.0 Specification: Protocolo estándar implementado

- AudioBox 22 VSL: Dispositivo de prueba​

- Descriptor USB: 6 interfaces, Feature Units 10 y 11 confirmados

- pyusb Documentation: Biblioteca de comunicación USB

## 🤝 Contribuciones
Este proyecto demuestra que la ingeniería inversa de protocolos USB puede revelar que muchos dispositivos "propietarios" en realidad usan estándares abiertos (UAC2 en este caso).​

## Contribuciones bienvenidas:

Tests con otros modelos AudioBox VSL

Implementaciones en otros lenguajes (C)

Descubrimiento de controles DSP adicionales


## Documentación antigua a continuación.

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
<img width="658" height="911" alt="image" src="https://github.com/user-attachments/assets/d66aea1c-7fe7-4e60-bdf0-fb90cf9fe7cc" />

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
<img width="1727" height="724" alt="image" src="https://github.com/user-attachments/assets/7f23fbfe-bc5e-4e10-80a7-54b325fc3938" />


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
<img width="800" height="943" alt="image" src="https://github.com/user-attachments/assets/b018fafa-013a-48c5-8a74-b18feaa13102" />


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
<img width="807" height="858" alt="image" src="https://github.com/user-attachments/assets/2ede9d70-ae80-4936-89b3-b0e4292dec81" />

---


<img width="709" height="873" alt="image" src="https://github.com/user-attachments/assets/123af69c-3f1a-4661-98fe-ba340dc4d373" />

---
# VSL-DSP Open Source Driver - Python PoC

## 🎯 Descripción

Prueba de Concepto (PoC) production-ready del protocolo VSL-DSP para dispositivos de audio USB-HID, desarrollado mediante ingeniería inversa del driver Android.

## 🚀 Instalación

### Requisitos
- Python 3.8+
- (Opcional) hidapi para I/O real: `pip install hidapi`

### Setup
```bash
# Clonar o descargar los archivos
cd vsl_dsp_poc/

# (Opcional) Crear entorno virtual
python3 -m venv venv
source venv/bin/activate  # Linux/Mac
# venv\Scripts\activate   # Windows

# Instalar dependencias opcionales
pip install -r requirements.txt
```

## 📖 Uso

### 1. Ejecutar PoC Matemática (Sin Hardware)
```bash
python vsl_poc_main.py
```

**Output esperado:**
- Tests de codificación de ganancia
- Tests de mapeo de frecuencia
- Construcción y validación de paquetes
- Flujo completo User Input → HID Packet

### 2. Descubrir Dispositivos HID (Con Hardware)
```bash
# Enumerar todos los dispositivos HID
python vsl_hid_io.py --enumerate

# Filtrar por fabricante
python vsl_hid_io.py --enumerate | grep -i "presonus"
```

### 3. Configurar Valores Reales

Editar `vsl_config.py`:
```python
# Reemplazar con valores reales
VSL_VENDOR_ID = 0x????   # Del output de --enumerate
VSL_PRODUCT_ID = 0x????  # Del output de --enumerate
VSL_REPORT_ID = 0x??     # Del desensamblado
```

### 4. Test de I/O Real (Requiere Configuración)
```bash
python vsl_hid_io.py
```

## 🏗️ Arquitectura
```
vsl_config.py       → Configuración y constantes
    ↓
vsl_core.py         → Lógica matemática DSP
    ↓
vsl_transport.py    → Construcción de paquetes HID
    ↓
vsl_hid_io.py       → I/O real con hardware (opcional)
    ↓
vsl_poc_main.py     → Tests y validación
```

## 🧪 Tests Incluidos

| Test | Descripción | Status |
|------|-------------|--------|
| **Gain Encoding** | Validación de curva exponencial | ✅ |
| **Frequency Mapping** | Mapeo logarítmico 20Hz-20kHz | ✅ |
| **Packet Construction** | Formato HID 64 bytes | ✅ |
| **Edge Cases** | Clamping y validación de rangos | ✅ |
| **Full Workflow** | User Input → HID Packet completo | ✅ |

## 📐 Formato del Paquete HID
```
Offset | Size | Description
-------|------|-------------
0x00   | 1    | Report ID (VSL_REPORT_ID)
0x01   | 2    | Parameter ID (Little-Endian)
0x03   | 2    | Encoded Value (Little-Endian)
0x05   | 59   | Padding (0x00)
-------|------|-------------
Total: 64 bytes (0x40)
```

**Ejemplo (Gain 75% → 0x9F39 / 40793):**
```
[0x01, 0x01, 0x1A, 0x39, 0x9F, 0x00, 0x00, ...]
  │     │_____│    │_____│
  │       │         └─ Value: 0x9F39 (40793)
  │       └─ Param ID: 0x1A01
  └─ Report ID
```

## 🔧 Troubleshooting

### Error: "hidapi no está disponible"
```bash
pip install hidapi
```

### Error: "Configuración inválida"
Verifica que `VSL_VENDOR_ID`, `VSL_PRODUCT_ID` y `VSL_REPORT_ID` estén configurados en `vsl_config.py`.

### Error: "Cannot open VSL device"
- Verifica que el dispositivo esté conectado: `lsusb`
- Ejecuta con permisos: `sudo python vsl_hid_io.py`
- Verifica VID/PID correctos

## 📚 Referencias

- **Origen:** Ingeniería inversa driver Android
- **Funciones clave desensambladas:**
  - `FUN_00132c90`: Encoding de ganancia
  - `FUN_00132d00`: Mapeo de frecuencia
  - `FUN_00132da8`: Decoding de frecuencia
  - `FUN_00412345`: Envío USB

## 📝 Licencia

TBD (GPL-3.0 / MIT)

## 🤝 Contribuciones

Este es un proyecto de ingeniería inversa educativo. 
Para contribuir con valores de VID/PID/Report ID o coeficientes adicionales, abrir un issue.

---

**Versión:** 1.0  
**Estado:** Production-Ready PoC (90% completo)  
**Última Actualización:** 2025-10-25


## 🔗 Links (Because Sharing Is Power)
- 📓 Wiki: [https://deepwiki.com/grisuno/blacksandbeacon](https://deepwiki.com/grisuno/blacksandbeacon)
- 📰 Blog: [https://medium.com/@lazyown.redteam/black-sand-beacon-when-your-linux-box-starts-whispering-to-c2-in-aes-256-cfb-and-no-one-notices-105ca5ed9547](https://medium.com/@lazyown.redteam/black-sand-beacon-when-your-linux-box-starts-whispering-to-c2-in-aes-256-cfb-and-no-one-notices-105ca5ed9547)
- 🎤 Podcast: [https://www.podbean.com/eas/pb-qe42t-198ee9d](https://www.podbean.com/eas/pb-qe42t-198ee9d)
- 🐙 GitHub: [https://github.com/grisuno/beacon](https://github.com/grisuno/beacon)
- 🐙 GitHub: [https://github.com/grisuno/LazyOwn](https://github.com/grisuno/LazyOwn)
- 🩸 Patreon: [https://www.patreon.com/c/LazyOwn](https://www.patreon.com/c/LazyOwn)
- 🐙 GitHub: [https://github.com/grisuno/CVE-2022-22077](https://github.com/grisuno/CVE-2022-22077)
- 🧠 LazyOwn Framework: [https://github.com/grisuno/LazyOwn](https://github.com/grisuno/LazyOwn)
- 🌐 Web: [https://grisuno.github.io/LazyOwn/](https://grisuno.github.io/LazyOwn/)
- 📰 Blog: [https://medium.com/@lazyown.redteam](https://medium.com/@lazyown.redteam)
- 🎥 Videolog: [https://youtu.be/spgLpv3XkiA](https://youtu.be/spgLpv3XkiA)
- 🧪 QuantumVault: [https://quantumvault.pro/landing](https://quantumvault.pro/landing)
- 🧑‍💻 HTB: [https://app.hackthebox.com/users/1998024](https://app.hackthebox.com/users/1998024)
- ☕ Ko-fi: [https://ko-fi.com/grisuno](https://ko-fi.com/grisuno) (Buy me a yerba mate for the next all-nighter)




![Python](https://img.shields.io/badge/python-3670A0?style=for-the-badge&logo=python&logoColor=ffdd54) ![Shell Script](https://img.shields.io/badge/shell_script-%23121011.svg?style=for-the-badge&logo=gnu-bash&logoColor=white) ![Flask](https://img.shields.io/badge/flask-%23000.svg?style=for-the-badge&logo=flask&logoColor=white) [![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/Y8Y2Z73AV)
