# CLAUDE.md

> **Mission:** build a free software open source driver (kernel module
> plus userspace library) for the PreSonus AudioBox VSL family of USB
> audio interfaces, by reverse engineering the disassembled Android
> driver and exposing a USB-HID control plane to Linux. Every constant
> must be traceable to a source of evidence; assumption is the enemy
> of reverse engineering.

This file is the working contract for any agent (human or AI) that
works on this repository. **These rules override default behaviour.**

---

## 1. The six unbreakable principles

1. **Zero Assumption.** No value is invented. No VID, PID, Report ID,
   or endianness is guessed. If a value is missing from the
   disassembly, it is left as `/* FIXME: extract from the
   disassembly */` and the blocker is documented; it is **never**
   filled with a plausible placeholder. Every constant has a
   verifiable source (Ghidra/IDA, `lsusb`, USB capture, the binary
   `.so`, or, for the kernel detector, the published `lsusb` table).
2. **Evidence over Intuition.** Every constant, offset, or mask in
   userspace code is linked to a function from the disassembly
   (`FUN_00412345`, `FUN_00132c90`, ...) or to a real-hardware
   capture. "Probably little-endian" is not evidence.
3. **Safe by Default.** The insecure configuration must not be
   representable. Pointer validation, `sizeof` buffer bounds, return
   code handling, no `strcpy`, no overflow. Fail closed: if a
   guarantee cannot be verified, the operation is rejected. The 64
   byte HID packet is a hard limit, not a suggestion.
4. **Non-Interference (the detector must not break audio).** The
   kernel module does **not** claim the USB interface: `probe`
   returns `-ENODEV` so `snd-usb-audio` (ALSA) keeps owning
   playback, capture, and mixer. The module is a detector and
   logger; it must never compete with the standard audio driver. If
   a module load silences or captures the device, that is a
   critical bug.
5. **Traceability (immutable naming).** Names extracted from the
   disassembly are kept verbatim: `VSL_Encode_Gain`,
   `VSL_Map_Frequency`, `VSL_Decode_Frequency`, `VSL_Parameter`,
   `FUN_00412345`, `FUN_Send_Packet`. They are not renamed to
   `_v2`, `_New`, or `_Fixed`. Traceability to the original binary
   is a requirement, not a stylistic preference.
6. **Extensible by Design.** Every contract anticipates growth
   without refactoring. For the detector: a single
   `audiobox_models[]` array in `audiobox_vsl.h` is the source of
   truth for the USB device table, the model enum, and the lookup
   function. Adding a new product ID is a one-line change in that
   array plus a unit test.

**Doctrine of separation (kernel vs userspace):** the `.ko` module
and the HIDAPI library are distinct contracts with distinct
responsibilities. The kernel detects and logs; the userspace
controls the DSP. Responsibilities are never mixed, and DSP logic
is never introduced inside the kernel module.

---

## 2. Language and style constraints

- **Kernel:** pure C, Linux kernel headers, C11 GCC. No C++, no
  Rust, no userspace dependencies inside the module. Standard
  kernel headers (`<linux/module.h>`, `<linux/usb.h>`,
  `<linux/printk.h>`); never libc.
- **Userspace (PoC and library):** pure C, C11, with HIDAPI
  (`-lhidapi-libusb`). C++ wrappers via `extern "C"`.
- **Identifiers and strings are English.** Documentation
  (`spec/`, this file, `README.md`) may also be English; the
  source code itself is always English. The exception: the
  immutable names from the disassembly (`FUN_*`) are preserved
  as-is.
- **No emojis in kernel or userspace source.** No emojis in
  `README.md`, `CLAUDE.md`, or `spec/`. Comments in source are
  allowed only to explain a non-obvious *why*; headers carry
  contract documentation as Doxygen-style `@brief` / `@param`
  docstrings.
- **Prefix by module.** `audiobox_` for the kernel detector,
  `VSL_` for the userspace DSP library. No unnecessary mutable
  global state. The HID handle is an explicit singleton
  (`vsl_device_handle`) with a clear lifecycle
  (`VSL_Init_Device` / `VSL_Close_Device`). Every `malloc` /
  `hid_open` has an idempotent releaser.
- **No hardcoded values, no magic numbers, no absolute system
  paths in scripts.** Every configurable value lives in the
  `Makefile` (kernel module build) or in the central configuration
  file for the relevant contract. Scripts (`install.sh`,
  `configure`) are thin wrappers that delegate to the Makefile.

---

## 3. Methodology: SDD + strict TDD + BDD Given-When-Then

For every module, the cycle is inviolable and **in this order**:

1. **Spec** — `spec/<module>.md`: inputs, outputs, error table,
   security guarantees, non-goals, and (critical for this project)
   the source of every constant. Given-When-Then BDD scenarios.
2. **Test (red)** — `tests/test_<module>.c` (userspace: CMocka;
   kernel: KUnit or load+`dmesg`). Must fail because the
   implementation does not exist yet. For pure DSP logic
   (encode/decode gain, frequency mapping, float to int) the
   tests are unit tests on pure functions without I/O; they are
   the directly verifiable surface. For the kernel detector, the
   tests are load/unload of the module and log inspection.
3. **Code (green)** — `src/<module>.c` (or root for the `.ko`)
   with the minimum code to pass. USB-HID calls in userspace use
   HIDAPI; the kernel module uses the kernel USB API. **No
   compilable placeholders:** an unknown value is a blocker and
   the test is adapted (conditional skip), never faked.
4. **Refactor** — harden pointers, bounds, readability, without
   breaking tests. If duplicate code is seen, unify it; this is
   imperative. Boy-scout mode: if technical debt is seen, retire
   it without losing functionality. The same applies to security
   flaws: their retirement is never out of scope. If 40 lines
   can become 10, welcome, as long as DRY/SOLID is respected and
   no functionality is lost and no more debt is added.
5. **Validation** —
   - Userspace: `make test` (CMocka), `make asan` (ASan+UBSan),
     `valgrind`, `cppcheck` clean. The validated project test
     (float to int: `0.75 -> 40793`) must always pass.
   - Kernel: `make` compiles the `.ko` with no warnings; `make
     modprobe` loads the module; connecting or disconnecting an
     AudioBox produces log lines in `dmesg` and **does not
     interfere** with `snd-usb-audio` (playback/capture still
     work, verified with `aplay` / `arecord` / `alsamixer` after
     load).
   - DSP cross validation: table
     `Control GUI -> User value -> Code output -> Match?`. Every
     "TBD" cell must be resolved with hardware or disassembly
     evidence before the contract is closed.
6. **Fuzzing** — every path that takes external input is fuzzed:
   the HID report parser and the DSP packet path received from
   the device (libFuzzer on `VSL_Decode_*` and the feature
   report parser; AFL++ on the userspace binary). Zero crashes,
   zero leaks, zero undefined behaviour before closure.
7. **Documentation** — **only after validation and fuzzing** is
   the spec, this file, the memory, and `README.md` updated.
   Documenting before validating is documenting what is not yet
   true.

**Do not write the implementation before the spec and the test.**
Do not advance phases until the previous one is green, validated,
and fuzzed (where applicable).

**Test-oriented design:** the DSP math (gain curves, logarithmic
frequency mapping, float to int conversion) lives in **pure
functions without I/O** (the directly verifiable surface); the
HIDAPI/USB orchestrators only wire things up and call those pure
functions. The USB send function (`FUN_Send_Packet`) only builds
the buffer and writes; the math is already done and tested above.

---

## 4. Technology stack (current decisions)

| Component                | Technology                                                | Note                                                                                                |
| ------------------------ | --------------------------------------------------------- | --------------------------------------------------------------------------------------------------- |
| Kernel detector          | Linux USB core (`module_usb_driver`, `usb_driver`)         | Pure C, GPL-2.0-or-later. `probe` returns `-ENODEV` (does not claim the interface). Supports three product IDs: 0x0101, 0x0102, 0x0103. Single source of truth in `audiobox_vsl.h`. |
| Userspace DSP library    | Pure C + **HIDAPI** (`hidapi-libusb`)                     | USB-HID communication: Feature/Output Report, 64 bytes (`0x40`), minimum 6 byte payload.            |
| Source of the code       | Reverse engineering of the Android driver                 | `FUN_00132c90` (Encode Gain), `FUN_00132d00` (Map Frequency), `FUN_00132da8` (Decode Frequency), `FUN_00412345` (USB Send). Immutable names. |
| Userspace tests          | CMocka                                                    | TDD. `sudo apt install libcmocka-dev`.                                                              |
| Kernel tests             | KUnit / load+`dmesg`                                      | Verifies non-interference with ALSA.                                                                |
| Wrappers                 | `extern "C"`                                              | Prepared for future C++ bindings without breaking the C API.                                       |
| Protocol                 | USB-HID, 64 byte packet                                   | Confirmed from the disassembly (`0x40` in `FUN_00412345`).                                          |

### Confirmed math model (DSP)

- **Gain encoding** (`VSL_Encode_Gain`): exponential curve
  `coeff_offset_A + coeff_C1 * exp(norm_factor * log_factor)`.
- **Frequency mapping** (`VSL_Map_Frequency` /
  `VSL_Decode_Frequency`): base 2 logarithm,
  `exp2f(log2_min + pos * (log2_max - log2_min))`.
- **Float to int conversion** (`VSL_Final_Encode_To_Int`): scale
  `1000.0f -> 65535`. Validated test: `0.75 -> 40793`.
- **Parameter struct** (`VSL_Parameter`, 8 fields):
  `{coeff_offset_A, coeff_C1, log_factor, curve_min_map,
  curve_max_map, freq_min_hz, freq_max_hz, dsp_param_id,
  max_encoded_int}`.

### Active blockers (values pending extraction from the disassembly)

These three values **are not assumed**. They must be extracted with
evidence before the userspace I/O path is considered complete:

```c
#define VSL_VENDOR_ID   0x????  /* FIXME: from the disassembly or lsusb */
#define VSL_PRODUCT_ID  0x????  /* FIXME: from the disassembly or lsusb */
#define VSL_REPORT_ID   0x??    /* FIXME: buf[0] before FUN_00412345 */
```

The kernel detector does not depend on any of these: it only needs
the VID and the list of supported PIDs, both of which are public.

---

## 5. Build, hardening, and verification

### Kernel (detector)

The Makefile is the single source of truth. The kernel build
delegates to the in-tree kbuild system which already applies its
hardening flags.

Makefile targets (single source of truth for commands):

| Target       | Effect                                                            |
| ------------ | ----------------------------------------------------------------- |
| `make`       | Build `audiobox_vsl.ko` and run the CMocka test suite (default).  |
| `make modules` | Build the kernel module only.                                   |
| `make test`  | Build and run the CMocka unit test suite.                         |
| `make asan`  | Build and run the test suite under AddressSanitizer + UBSan.      |
| `make clean` | Remove build artefacts.                                           |
| `sudo make install` | Copy the module to `/lib/modules/$(uname -r)/extra/` and run `depmod`. |
| `sudo make uninstall` | Remove the module from the extra dir and run `depmod`.    |
| `sudo make modprobe` | Load the module into the running kernel.                     |
| `sudo make rmmod`    | Unload the module from the running kernel.                  |
| `make info`   | Print resolved build variables.                                  |
| `make help`   | List every available target.                                     |
| `make deb`    | Build Debian package (.deb) for the kernel module                 |
| `make deb`    | Build Debian package (.deb) for the kernel module.               |

`install.sh` and `configure` are thin wrappers that delegate to
the system. If they duplicate build logic, they desynchronise and
become technical debt; unified, they remain one-liners.

### Userspace (DSP library)

Compilation flags:

```
gcc -std=c11 -O2 -g -Wall -Wextra -Werror -Wshadow -Wpedantic \
    -Wstrict-prototypes -Wmissing-prototypes -Wconversion \
    -Wsign-conversion -Wold-style-definition \
    -fstack-protector-strong -D_FORTIFY_SOURCE=2
```

`make asan` adds `-fsanitize=address,undefined -fno-omit-frame-pointer`
to the flags. Every PR must pass `make` (kernel) and `make test` +
`make asan` (userspace, where applicable) cleanly before merge.

### `.DEFAULT_GOAL` is intentionally omitted from the Makefile

Setting `.DEFAULT_GOAL` in the project's Makefile triggers a kbuild
sub-make recursion bug in 6.x kernels that requires write access to
the kernel source directory. Leaving the default goal implicit
(first target wins) keeps the build portable across kernel
configurations.

---

## 6. Repository layout

```
VSL-DSP/
├── CLAUDE.md                      # this file (working contract)
├── Makefile                       # build, test, install (single source of truth)
├── audiobox_vsl.c                 # kernel detector module
├── audiobox_vsl.h                 # public interface and configuration
├── install.sh                     # wrapper: installs build dependencies
├── configure                      # wrapper: verifies build environment
├── README.md                      # user-facing documentation
├── LICENSE                        # GPL-2.0-or-later
├── CODE_OF_CONDUCT.md
├── CONTRIBUTING.md
├── SECURITY.md
├── pull_request_template.md
├── docs/                          # additional documentation
├── spec/                          # BDD specifications (SDD)
│   └── audiobox_vsl.md
├── src/                           # userspace DSP library (active)
│   ├── vsl_dsp_logic.c
│   ├── vsl_dsp_logic.h
│   ├── vsl_dsp_transport.c
│   └── vsl_dsp_transport.h
├── tests/                         # CMocka unit test suite
│   └── test_audiobox_vsl.c
├── .github/                       # issue and pull request templates
└── legacy/                        # historical artefacts (see legacy/README.md)
    ├── README.md
    ├── ... (Python PoC, DKMS installer, packet captures, ...)
```

The `src/`, `tests/`, and `spec/` layout is the SDD/TDD target. The
kernel detector lives at the repository root because it is the
entry point of the project.

---

## 7. Roadmap by phase

Closed = spec + green test + ASan/UBSan clean (and, where
applicable, fuzzing and proof with real hardware). What only
compiles but cannot be exercised here is marked pending real-hardware
test, never as verified.

### 7.1 Current state

| Component                            | Status        | Evidence                                                                                                                                                       |
| ------------------------------------ | ------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Kernel detector (USB)                | Closed        | `audiobox_vsl.c`: probe returns `-ENODEV`, logs via `dev_info`, does not interfere with `snd-usb-audio`. Compiles and loads.                                  |
| VID/PID detector                     | Confirmed     | `0x194f:0x0101`, `0x194f:0x0102`, `0x194f:0x0103` from the public `lsusb` table. Single source of truth in `audiobox_vsl.h`.                                 |
| Detector unit test suite             | Closed        | `tests/test_audiobox_vsl.c` with CMocka: 10 tests covering the model table, the lookup function, and edge cases. All passing under `-Wall -Wextra -Werror`.   |
| Architecture of the library          | Confirmed     | Pure C, modular `vsl_dsp_logic.c` + `vsl_dsp_transport.c`, `extern "C"` wrappers.                                                                              |
| Gain encoding                        | Implemented   | `VSL_Encode_Gain`, exponential curve confirmed from the disassembly.                                                                                          |
| Frequency mapping                    | Implemented   | `VSL_Map_Frequency` / `VSL_Decode_Frequency`, base 2 logarithm.                                                                                                |
| Float to int conversion              | Validated     | `0.75 -> 40793` (test confirmed).                                                                                                                              |
| Parameter struct                     | Confirmed     | `VSL_Parameter` (8 fields).                                                                                                                                    |
| HID packet                           | Confirmed     | 64 bytes (`0x40`) from the disassembly.                                                                                                                        |
| VID/PID library                      | Blocker #1    | Extract from the disassembly or `vsl_discover`.                                                                                                                |
| Report ID library                    | Blocker #2    | `buf[0]` before `FUN_00412345`.                                                                                                                                |
| Endianness                           | Blocker #3    | Verify bit shifts in the disassembly.                                                                                                                          |
| Test with real hardware              | Pending       | Requires blockers #1-#3 for the userspace I/O path.                                                                                                            |
| Public API documentation             | Pending       | Post validation with real hardware.                                                                                                                            |

### 7.2 Closed milestones (summary)

- **Phase 1** — Kernel USB detector. `audiobox_vsl.c` with
  `module_usb_driver`, table `{USB_DEVICE(0x194f, 0x0101),
  USB_DEVICE(0x194f, 0x0102), USB_DEVICE(0x194f, 0x0103)}`, probe
  that logs vendor/product/manufacturer/product/serial and returns
  `-ENODEV`, disconnect that logs the model name. Makefile with
  `all/modules/test/asan/clean/install/uninstall/modprobe/rmmod/info/help`.
  `install.sh` (dependencies) and `configure` (environment
  verification). Compiles and loads; real-hardware verification
  pending on the owner's machine.
- **Phase 2** — Reverse engineering of the Android driver.
  Identified `FUN_00132c90` (Encode Gain), `FUN_00132d00` (Map
  Frequency), `FUN_00132da8` (Decode Frequency), `FUN_00412345`
  (USB Send, 64 bytes 0x40). Python PoC in `legacy/` for the
  USB-HID protocol. Protocol analysis document in
  `legacy/vsl_protocol_analysis.txt`.
- **Phase 3** — DSP logic in pure C. `VSL_Encode_Gain`,
  `VSL_Map_Frequency` / `VSL_Decode_Frequency`,
  `VSL_Final_Encode_To_Int`, `VSL_Parameter` (8 fields). Validated
  test `0.75 -> 40793`. Modular architecture
  `vsl_dsp_logic.c` + `vsl_dsp_transport.c`. Compiles with
  `-lhidapi-libusb`.

### 7.3 Roadmap to cross

- **Phase 4** — Resolve the critical blockers. Extract VID/PID
  (library), Report ID, and endianness from the disassembly or
  hardware. Options: (A) Ghidra/IDA analysis of `FUN_00412345` and
  its caller; (B) `vsl_discover` + `usbhid-dump` with real
  hardware; (C) `strings` / `objdump` of the Android `.so`.
- **Phase 5** — Real I/O integration. `FUN_Send_Packet` with the
  three resolved values. End to end test with hardware: cross
  validation table Control GUI -> Value -> Output -> Match?.
  Verify mute, volume, EQ.
- **Phase 6** — Parameter database (100+). `VSL_ParamID` enum +
  `VSL_Params_Database[]` + generic `VSL_Set_Parameter(id, value)`
  API. Mass extraction from the disassembly, one parameter per
  spec+test.
- **Phase 7** — C++ wrappers and bindings. `extern "C"` + facade
  header. Keep the C API stable.
- **Phase 8** — Packaging and distribution. `.deb` / DKMS for the
  kernel module; package for the userspace library. Integration
  with the build system.

Background tasks: fuzzing the HID/DSP parser; KUnit tests of the
detector; public API documentation post validation; continuous
boy-scout mode on technical debt.

---

## 8. Rules for the AI assistant

- Apply the complete cycle of section 3 in order: spec -> red test
  -> green code -> refactor -> validation (ASan / dmesg+ALSA) ->
  fuzzing -> documentation. Do not skip steps and do not write
  code without spec+test, and do not document before validating
  and fuzzing.
- **Zero Assumption.** When in doubt about a constant from the
  disassembly, ask with directed evidence (Socratic method: "in
  Ghidra, go to `FUN_00412345`, press X, enter the caller, copy
  `buf[0]`"). Never invent VID/PID/Report ID/endianness.
- **Fail closed.** When in doubt about safety (buffer, pointer,
  I/O), reject; never degrade a guarantee for convenience. Pointer
  validation, `sizeof` buffer bounds, return code handling, no
  `strcpy`.
- **Do not break audio.** The kernel detector always returns
  `-ENODEV` in `probe`. Never claim the USB interface. If a
  module load silences or captures the device, that is a critical
  bug.
- **Immutable naming.** Keep `VSL_Encode_Gain`, `FUN_00412345`,
  etc. Do not rename "to improve". Traceability to the
  disassembly is a requirement.
- Be honest about what is not verified: code that cannot be
  exercised here (I/O with real hardware, module load without the
  device) is marked pending real-hardware test, never as verified.
- Verify that every symbol, flag, or constant exists before
  recommending it (`lsusb`, `hid_enumerate`, `dmesg`, `modprobe`).
- New commands go in the `Makefile` (single source of truth), not
  in loose scripts that desynchronise (see section 5).
- Boy-scout mode: retiring technical debt and security flaws is
  never out of scope, always without losing functionality. Look
  for and extinguish duplicate code.
- Lateral thinking when the environment demands it (e.g. HIDAPI
  absent from repositories -> compile from source; Kali without
  the package -> alternate route). Document the non-obvious
  solution in the spec.
- After every change: re-run `make` and `make test` from a clean
  state. If either fails, the change is not done.
