# VSL-DSP — Driver & Cliente Open Source para PreSonus AudioBox 22 VSL

> **Misión:** desarrollar un cliente open source (driver de kernel + librería
> userspace) funcional para el dispositivo de audio PreSonus AudioBox 22 VSL,
> mediante ingeniería inversa del driver Android desensamblado y comunicación
> USB-HID en Linux. Cada constante debe ser trazable al desensamblado original;
> la suposición es el enemigo de la ingeniería inversa.

Este archivo es el contrato de trabajo para cualquier agente (humano o IA) que
tenga este repositorio. **Estas reglas anulan comportamientos por defecto.**

---

## 1. Los seis principios inquebrantables

1. **Zero Assumption (No Suposición Absoluta)** — Ningún valor se asume. No se
   inventan VID/PID, Report ID ni endianness. Si falta un valor del desensamblado,
   se deja como `/* FIXME: extraer del desensamblado */` y se documenta el
   bloqueador; **nunca** se rellena con un placeholder plausible. Toda constante
   debe tener una fuente comprobable (Ghidra/IDA, `lsusb`, captura USB, o el
   binario `.so`).
2. **Evidence over Intuition** — Cada constante, offset o máscara del código
   userspace debe poderse enlazar a una función del desensamblado
   (`FUN_00412345`, `FUN_00132c90`, etc.) o a una captura del hardware real.
   "Probablemente es Little-Endian" no es evidencia.
3. **Safe by Default** — La configuración insegura **no debe ser representable**
   en la API. Validación de punteros, límites de buffer (`sizeof`), manejo de
   errores de retorno, sin `strcpy`/overflow. Fallar cerrado: si una garantía no
   se puede verificar, se rechaza la operación. Los 64 bytes del paquete HID son
   un límite duro, no un sugerencia.
4. **Non-Interference (el detector no rompe el audio)** — El driver de kernel
   **no reclama** la interfaz USB: `probe` retorna `-ENODEV` para que
   `snd-usb-audio` (ALSA) siga gestionando playback/capture/mixer. El módulo es
   detector y logger; **jamás** debe competir con el driver de audio estándar. Si
   una carga del módulo silencia o captura el dispositivo, es un bug crítico.
5. **Traceability (Nomenclatura Inmutable)** — Los nombres extraídos del
   desensamblado se mantienen 1:1: `VSL_Encode_Gain`, `VSL_Map_Frequency`,
   `VSL_Decode_Frequency`, `VSL_Parameter`, `FUN_00412345`, `FUN_Send_Packet`.
   No se renombran a `_v2`/`_New`/`_Fixed`. La trazabilidad al binario original
   es un requerimiento, no un capricho estético.
6. **Extensible by Design** — Todo código userspace debe anticipar 100+
   parámetros DSP futuros sin refactoring: enum centralizado de IDs
   (`VSL_ParamID`), base de datos indexable (`VSL_Params_Database[]`), API
   genérica `VSL_Set_Parameter(id, value)`. Acceso O(1) por ID.

**Doctrina de separación (kernel vs userspace):** el módulo `.ko` y la librería
HIDAPI son componentes distintos con contratos distintos. El kernel detecta y
loguea; el userspace controla el DSP. No se mezclan responsabilidades ni se
introduce lógica DSP dentro del módulo de kernel.

---

## 2. Restricciones de lenguaje y estilo

- **Kernel: C puro (kernel Linux, C11 GCC).** Nada de C++, Rust ni dependencias
  userspace dentro del módulo. Headers estándar del kernel (`<linux/module.h>`,
  `<linux/usb.h>`, `<linux/printk.h>`); **nunca** libc.
- **Userspace (PoC/librería): C puro (C11)** con HIDAPI
  (`-lhidapi-libusb`). Preparado para wrappers C++ vía `extern "C"`.
- **Identificadores y strings en inglés.** La documentación (`spec/`, este
  archivo, `README.md`) puede estar en español; el código, no. Excepción: los
  nombres inmutables del desensamblado (`FUN_*`) se mantienen tal cual.
- Sin emojis en el código fuente del kernel/userspace (los `🎉`/`🔌` del log
  del detector son herencia del README/demo y se toleran en `dev_info`; en nueva
  lógica userspace se evitan). Comentarios solo cuando explican un *porqué* no
  evidente; los headers llevan documentación de contrato.
- Nombres con prefijo de módulo (`audiobox_` para el detector kernel, `VSL_` para
  la librería DSP userspace). Sin estado global mutable innecesario; el handle
  HID es singleton explícito (`vsl_device_handle`) con ciclo de vida claro
  (`VSL_Init_Device`/`VSL_Close_Device`). Cada `malloc`/`hid_open` tiene su
  liberador idempotente.

---

## 3. Metodología: SDD + TDD estricto + BDD Given-When-Then

Para cada módulo, el ciclo es inviolable y **en este orden**, modo boyscout
extintor de deuda técnica:

1. **Spec** — `spec/<modulo>.md`: entradas, salidas, tabla de errores, garantías
   de seguridad, qué queda fuera de alcance, y —crítico para este proyecto— la
   **fuente de cada constante** (función del desensamblado o captura USB). Usando
   Dado-Cuando-Entonces (BDD).
2. **Test (rojo)** — `tests/test_<modulo>.c` (userspace: CMocka; kernel: KUnit o
   framework de módulo test). Debe **fallar** porque no hay implementación todavía.
   Para la lógica DSP pura (encode/decode gain, mapeo de frecuencia, conversión
   float→int) los tests son unitarios sobre funciones puras sin I/O — son la
   superficie verificable directamente. Para el detector kernel, test de carga/
   descarga del módulo y verificación de logs vía `dmesg`.
3. **Code (verde)** — `src/<modulo>.c` (o raíz para el `.ko`) con el código mínimo
   para pasar. Las llamadas USB-HID userspace usan HIDAPI; el módulo kernel usa la
   API USB del kernel. **Sin placeholders compilables**: un valor desconocido se
   marca como bloqueador y el test se adapta (skip condicional), nunca se finge.
4. **Refactor** — endurecer punteros, límites, legibilidad, sin romper pruebas.
   Si ves código duplicado lo unificas — esto es imperativo: busca código
   duplicado y extínguelo sin perder funcionalidad. Nunca está fuera de scope.
   Modo boyscout: si ves deuda técnica la extingues sin romper funcionalidades;
   lo mismo con fallos de seguridad o vulnerabilidades — su extinción nunca está
   fuera de scope. Si puedes hacer lo mismo que haces en 40 líneas en 10 o 1,
   bienvenido, siempre y cuando respete DRY/SOLID y no pierda funcionalidad ni
   agregue más deuda técnica.
5. **Validación** —
   - Userspace: `make test` (CMocka), `make asan` (ASan+UBSan), `valgrind`,
     `cppcheck` limpios. El test confirmado del proyecto (conversión float→int:
     `0.75 → 40793`) debe pasar siempre.
   - Kernel: `make` compila el `.ko` sin warnings; `make modprobe` carga el módulo;
     conectar/desconectar el AudioBox produce logs en `dmesg` y **no interfiere**
     con `snd-usb-audio` (playback/capture siguen funcionando — esto se verifica
     con `aplay`/`arecord` o `alsamixer` tras la carga).
   - Validación cruzada DSP: tabla
     `Control GUI → Valor User → Código Output → Match?`. Cada celda "TBD" debe
     resolverse con evidencia del hardware/desensamblado antes de cerrar.
6. **Fuzzing** — los paths que toman input externo se fuzzean: el parser de
   reportes HID y el path de paquetes DSP recibidos del dispositivo (libFuzzer
   sobre `VSL_Decode_*` y el parser de feature reports; AFL++ sobre el binario
   userspace). Cero crashes/leaks/UB antes de cerrar.
7. **Documentación** — **recién después de validar y fuzzear** se documenta: se
   actualiza la spec, este `CLAUDE.md` (bloqueador → resuelto, doctrina nueva), la
   memoria y el `README.md`. Documentar antes de validar es documentar lo que
   todavía no es verdad.

**No escribas la implementación antes que la spec y el test.** No avances de
fase sin que la anterior esté verde, validada y fuzzeada (donde aplique).

**Diseño orientado a prueba:** la lógica DSP matemática (curvas de ganancia,
mapeo logarítmico de frecuencia, conversión float→int) va en **funciones puras
sin I/O** (la superficie verificable directamente); los orquestadores con
HIDAPI/USB solo cablean y llaman a esas funciones puras. La función de envío USB
(`FUN_Send_Packet`) solo arma el buffer y escribe; la matemática ya está hecha y
testada arriba.

---

## 4. Stack tecnológico (decisiones vigentes)

| Componente | Tecnología | Nota |
| :-- | :-- | :-- |
| Detector kernel | Linux USB core (`module_usb_driver`, `usb_driver`) | C puro, GPL-2.0-or-later. `probe` retorna `-ENODEV` (no reclama la interfaz). VID `0x194f`, PID `0x0101`. |
| Librería DSP userspace | C puro + **HIDAPI** (`hidapi-libusb`) | Comunicación USB-HID: Feature/Output Report, 64 bytes (`0x40`), payload mínimo 6 bytes. |
| Origen del código | Ingeniería inversa driver Android | `FUN_00132c90` (Encode Gain), `FUN_00132d00` (Map Frequency), `FUN_00132da8` (Decode Frequency), `FUN_00412345` (USB Send). Nombres inmutables. |
| Pruebas userspace | CMocka | TDD. `sudo apt install libcmocka-dev`. |
| Pruebas kernel | KUnit / carga+`dmesg` | Verificación de no-interferencia con ALSA. |
| Wrappers | `extern "C"` | Preparado para bindings C++ futuros sin romper la API C. |
| Protocolo | USB-HID, paquete 64 bytes | Confirmado del desensamblado (`0x40` en `FUN_00412345`). |

### Modelo matemático confirmado (DSP)

- **Codificación de ganancia** (`VSL_Encode_Gain`): curva exponencial
  `coeff_offset_A + coeff_C1 * exp(norm_factor * log_factor)`.
- **Mapeo de frecuencia** (`VSL_Map_Frequency`/`VSL_Decode_Frequency`): logarítmico
  base 2, `exp2f(log2_min + pos * (log2_max - log2_min))`.
- **Conversión float→int** (`VSL_Final_Encode_To_Int`): escala `1000.0f → 65535`.
  Test validado: `0.75 → 40793`.
- **Estructura de parámetro** (`VSL_Parameter`, 8 campos):
  `{coeff_offset_A, coeff_C1, log_factor, curve_min_map, curve_max_map, freq_min_hz, freq_max_hz, dsp_param_id, max_encoded_int}`.

### Bloqueadores críticos (valores pendientes de extraer del desensamblado)

Estos tres valores **no se asumen**. Deben extraerse con evidencia antes de
considerar el proyecto completo:

```c
#define VSL_VENDOR_ID   0x????  /* FIXME: del desensamblado o lsusb */
#define VSL_PRODUCT_ID  0x????  /* FIXME: del desensamblado o lsusb */
#define VSL_REPORT_ID   0x??    /* FIXME: buf[0] antes de FUN_00412345 */
```

5. Compilación, hardening y verificación
Kernel (detector)
make usa el build system del kernel (KDIR), que ya aplica sus flags de
hardening. El módulo se compila con la cadena del kernel en uso.

Targets del Makefile (única fuente de verdad de los comandos):

make / make all — compila audiobox_vsl.ko.
make install — copia a /lib/modules/$(uname -r)/extra/, depmod.
make uninstall — elimina el .ko y depmod.
make modprobe — carga el módulo (sudo modprobe audiobox_vsl).
make clean — limpia artefactos de build.
El Makefile es la única fuente de verdad de los comandos. Los scripts
(install.sh, configure) son wrappers delgados que delegan al sistema; si
duplican lógica de compilación se desincronizan y se convierten en deuda técnica
— unificar.

Userspace (librería DSP)
Compilación: gcc -Wall -Wextra -Werror -std=c11 -O2 -fstack-protector-strong -D_FORTIFY_SOURCE=3 src/*.c -o vsl_dsp -lhidapi-libusb.

Targets propuestos (a centralizar en el Makefile):

make lib — compila la librería/CLI userspace.
make test — suite CMocka.
make asan — la misma suite bajo ASan+UBSan.
make fuzz / make fuzz-afl — libFuzzer / AFL++ sobre parser HID y DSP.
make discover — compila vsl_discover.c (enumeración HID para hardware real).
Todo PR debe pasar make (kernel) y make test + make asan (userspace, donde
aplique) limpios antes de integrarse.

6. Estructura del repositorio
Plaintext



VSL-DSP/
├── CLAUDE.md                          # este archivo
├── Makefile                           # build kernel + (futuro) userspace
├── audiobox_vsl.c                     # fuente del módulo detector kernel
├── audiobox_vsl.h                     # header (compatibilidad del árbol)
├── install.sh                         # wrapper: dependencias de build
├── configure                          # wrapper: verifica entorno de build
├── 🎯 VSL-DSP Open Source Driver - System P.md  # system prompt / plan maestro
├── vsl_dsp_poc/                       # PoC Python de ingeniería inversa USB-HID
│   └── README.md
├── vsl_protocol_analysis.txt          # análisis de protocolo (referencia)
├── docs/                              # documentación adicional
├── spec/                              # especificaciones SDD (a crear)
│   └── &lt;modulo&gt;.md
├── src/                               # implementaciones userspace (a crear)
│   └── &lt;modulo&gt;.c                     # vsl_dsp_logic.c, vsl_dsp_transport.c
└── tests/                             # suites CMocka / KUnit (a crear)
    └── test_&lt;modulo&gt;.c
La estructura spec/, src/, tests/ es el objetivo SDD/TDD. Hoy el
repositorio vive en la raíz (driver kernel) + vsl_dsp_poc/ (PoC). Al migrar
la librería DSP a C userspace, se adopta el layout modular de Freedom.

7. Hoja de ruta por fases
Convención de estado: cerrado = spec + test verde + ASan/UBSan limpio
(y, donde aplique, fuzzing y prueba con hardware real). Lo que solo compila
pero no se pudo ejercitar aquí se marca pendiente de prueba con hardware,
nunca como verificado.

7.1 Estado actual
Componente	Estado	Evidencia
Detector kernel (USB)	✅ CERRADO	audiobox_vsl.c: probe→-ENODEV, logs dev_info, no interfiere con snd-usb-audio. Compila y carga.
VID/PID detector	✅ Confirmado	0x194f:0x0101 del hardware real.
Arquitectura librería	✅ Confirmada	C puro, separación modular vsl_dsp_logic.c + vsl_dsp_transport.c, wrappers extern "C".
Codificación ganancia	✅ Implementada	VSL_Encode_Gain — curva exponencial confirmada del desensamblado.
Mapeo frecuencia	✅ Implementada	VSL_Map_Frequency/VSL_Decode_Frequency — log base 2.
Conversión float→int	✅ Validada	0.75 → 40793 (test confirmado).
Estructura parámetros	✅ Confirmada	VSL_Parameter (8 campos).
Paquete HID	✅ Confirmado	64 bytes (0x40) del desensamblado.
VID/PID librería	⚠️ BLOQUEADOR #1	Extraer del desensamblado o vsl_discover.
Report ID librería	⚠️ BLOQUEADOR #2	buf[0] antes de FUN_00412345.
Endianness	⚠️ BLOQUEADOR #3	Verificar bit-shifts en desensamblado.
Test con hardware	⏳ Pendiente	Requiere bloqueadores #1–#3.
Docs API	⏳ Pendiente	Post-validación con hardware.
Decisiones de doctrina vigentes (no evidentes en el código; no re-litigar):

probe retorna -ENODEV por diseño: el detector no reclama la interfaz.
Cambiar esto rompería el audio ALSA. Es la invariant más importante del módulo
kernel. Ver [[vsl-dsp-non-interference]].
Zero Assumption sobre los 3 bloqueadores: mientras no haya evidencia, los
valores quedan como FIXME y el path de envío real se marca pendiente. No se
"adelanta" con valores plausibles. Ver [[vsl-dsp-zero-assumption]].
Singleton HID explícito: vsl_device_handle con VSL_Init_Device/
VSL_Close_Device. Reentrante en init (devuelve 0 si ya abierto). No hay
segundo handle. Ver [[vsl-dsp-hid-singleton]].
Separación lógica/transporte: la matemática DSP es pura y testeable sin
hardware; el transporte HIDAPI es el orquestador que cablea. No se mezclan.
Ver [[vsl-dsp-logic-transport-split]].
7.2 Hitos cerrados (resumen)
Fase 1 — Detector kernel USB. Módulo audiobox_vsl.c con
module_usb_driver, tabla {USB_DEVICE(0x194f, 0x0101)}, probe que loguea
vendor/product/manufacturer/product/serial y retorna -ENODEV, disconnect
que loguea. Makefile con all/install/uninstall/modprobe/clean.
install.sh (dependencias) + configure (verificación de entorno).
(Compila y carga; verificación con hardware real pendiente al dueño.)
Fase 2 — Ingeniería inversa del driver Android. Identificadas
FUN_00132c90 (Encode Gain), FUN_00132d00 (Map Frequency),
FUN_00132da8 (Decode Frequency), FUN_00412345 (USB Send, 64 bytes 0x40).
PoC Python en vsl_dsp_poc/ para protocolo USB-HID. Documento de análisis en
vsl_protocol_analysis.txt.
Fase 3 — Lógica DSP userspace (C puro). VSL_Encode_Gain,
VSL_Map_Frequency/VSL_Decode_Frequency, VSL_Final_Encode_To_Int,
VSL_Parameter (8 campos). Test validado 0.75 → 40793. Arquitectura modular
vsl_dsp_logic.c + vsl_dsp_transport.c. Compila con -lhidapi-libusb.
7.3 Roadmap — por cruzar
Fase 4 — Resolver bloqueadores críticos. Extraer VID/PID (librería),
Report ID y endianness del desensamblado o hardware. Opciones: (A) análisis
Ghidra/IDA de FUN_00412345 y su llamador; (B) vsl_discover +
usbhid-dump con hardware real; (C) strings/objdump del .so Android.
Fase 5 — Integración I/O real. FUN_Send_Packet con los 3 valores
resueltos. Test end-to-end con hardware: tabla de validación cruzada
Control GUI → Valor → Output → Match?. Verificar mute, volumen, EQ.
Fase 6 — Base de datos de parámetros (100+). VSL_ParamID enum +
VSL_Params_Database[] + API genérica VSL_Set_Parameter(id, value).
Extracción masiva del desensamblado, un parámetro por spec+test.
Fase 7 — Wrappers C++ y bindings. extern "C" + cabecera de fachada.
Mantener la API C estable.
Fase 8 — Empaquetado y distribución. .deb/dkms para el módulo kernel;
paquete para la librería userspace. Integración con el build system.
Pendiente de fondo: fuzzing del parser HID/DSP; tests KUnit del detector;
documentación API post-validación; modo boyscout continuo sobre deuda técnica.
8. Reglas para el asistente (IA)
Aplica el ciclo completo de §3 en orden: spec → test rojo → código verde →
refactor → validación (ASan / dmesg+ALSA) → fuzzing → documentación. No te
saltes pasos ni adelantes implementación sin spec+test, y no documentes antes
de validar y fuzzear.
Zero Assumption. Ante la duda sobre una constante del desensamblado,
pregunta con evidencia dirigida (método socrático inverso: "en Ghidra, ve a
FUN_00412345, presiona X, entra al llamador, copia buf[0]"). Nunca inventes
VID/PID/Report ID/endianness.
Falla cerrado. Ante la duda de seguridad (buffer, puntero, I/O), rechaza;
nunca degrades una garantía por conveniencia. Validación de punteros, límites
de buffer con sizeof, manejo de errores de retorno, sin strcpy.
No rompas el audio. El detector kernel siempre retorna -ENODEV en
probe. Nunca reclames la interfaz USB. Si una carga del módulo silencia o
captura el dispositivo, es un bug crítico.
Nomenclatura inmutable. Mantén VSL_Encode_Gain, FUN_00412345, etc. No
renombres "para mejorar". La trazabilidad al desensamblado es un requerimiento.
Sé honesto sobre lo no verificado: el código que no se pueda ejercitar aquí (I/O
con hardware real, carga del módulo sin el dispositivo) se marca como pendiente
de prueba con hardware, no como verificado.
Verifica que cada símbolo/flag/constante existe antes de recomendarlo
(lsusb, hid_enumerate, dmesg, modprobe).
Comandos nuevos van al Makefile (única fuente de verdad), no a scripts
sueltos que se desincronizan (ver §5).
Modo boyscout: resolver deuda técnica y fallos de seguridad nunca está
fuera de scope, siempre sin perder funcionalidad. Busca y extingue código
duplicado.
Pensamiento lateral cuando el entorno lo exija (ej: HIDAPI ausente en
repositorios → compilar desde source; Kali sin paquete → ruta alternativa).
Documenta la solución no obvia en la spec.