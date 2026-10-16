# Vendor DSP formatters, UC branch ai_4.7.2 (three-binary comparison)

Decompiled with Ghidra 12.1.4 headless (`analyzeHeadless`, Jython
unavailable without PyGhidra/full JDK 21, so export scripts are
`.java` run via `-postScript`) from
`libfatchannelplugins.so` (UC Remote ai_4.7.2 AAB, sha256
`e3fb430ba5d09859a5e5aa4d82565d7b41ac30f512a27f21d25cb3d261bd1dfe`).
Method: search bytes `00 00 10 c3` (-144.0f) -> code xrefs ->
decompile referrers -> dump vtable slots. Ghidra project `VSL`
kept under `/tmp/opencode/vsl-re/gproj` during the session.

Independent corroboration via REA 4.0.1 + Ghidra 12.1.4 provider
(requires full JDK 21: `~/tools/jdk-21.0.12.1+1`, Temurin; the apt
`openjdk-21-jdk-headless` satisfies REA but has no X toolkit, so the
Ghidra GUI cannot start on it):

- `rea analyze` fender libucnet: `ev_231493d5…`, 1389 procedures,
  341 strings.
- `rea analyze` ai_4.7.2 libucnet: `ev_89b82a86…`, 1362 procedures,
  700 strings. Drift is manual (md5, counts, JNI rename) because
  `rea compare` / `rea evidence-export` reject re-imported stdout
  bundles (`evidence_integrity_mismatch`, tool-side limitation).
- `rea function` ai_4.7.2 `0x1390d8`: `ev_d58c5dfb…`; `0x139014`:
  `ev_c0e71d32…`. Pseudocode is byte-identical to the manual
  decompiles below: two independent paths agree.

## Binaries compared

| File | Size | Key libs (arm64) |
|------|------|------------------|
| `fender_universal_control_android_5_1_0_112930.apk` | 140800179 | libucnet 330936, libfatchannelplugins 248112, no quantumusbdevice |
| `ucremoteapp-android-release_v5_0_0_110112.apk` (Descargas) | ~125M | libucnet 330936, libfatchannelplugins 247904, libquantumusbdevice 587256 |
| `ucremoteapp-android-release_ai_4_7_2-108537.aab` (Descargas) | ~152M | libucnet 379104, libfatchannelplugins 265080, libquantumusbdevice 623112 |

All libs stripped, NDK r29, `for Android 26`. AAB lib paths carry a
`base/` prefix. fender 5.1.0 and UC 5.0.0 share only sizes, not
content (md5 differs on every lib). UCNET JNI package renamed
`dev.ccl.core` (5.x) -> `com.ccl.core` (ai_4.7.2).

## -144.0f constant sites (float LE `00 00 10 c3`)

| Lib | Offsets |
|-----|---------|
| fender 5.1.0 libfatchannelplugins | 0xc808, 0xd458, 0xd480 |
| UC 5.0.0 libfatchannelplugins | 0xc760, 0xd2f8, 0xd320 |
| ai_4.7.2 libfatchannelplugins | 0xf418, 0x10638, 0x10660 |
| ai_4.7.2 libucnet | 0xda0e, zero code xrefs (data-embedded constant; table-driven design, VA `0x0010da0e`) |
| ai_4.7.2 libquantumusbdevice | 0x1a108, 0x1a2bc, 0x1a2e4 |
| libucremoteapp (all) | 6 sites each |

## Formatter object pair (ai_4.7.2, VA base 0x100000)

`FUN_00139550` and `FUN_00139598` are twin factories: `malloc(0x30)`,
store vtable (`PTR_FUN_0013ffc8` / `PTR_FUN_00140000`), constant
`1.0f`, the -144.0f word at `0x0010f418`, a descriptor at
`0x00110634` / `0x0011065c`, and count `5`. Two instances matches
the `GainDBFormatter` / `DbInfinityFormatter` split: dB gain and
negative infinity are separate objects, not one curve.

Vtable slots (both tables share the first five):

| Slot | Points to | Role |
|------|-----------|------|
| 0-1 | FUN_00139298, FUN_0013928c/a8 | object lifetime |
| 2 | FUN_0013b820 | no-op (pure virtual gap) |
| 3 | FUN_00139014 | dB -> linear + range clamp + table lerp |
| 4 | FUN_001390d8 | linear -> dB + range clamp + table lerp |
| 5+ | tanf, __strncpy_chk, data refs | string/taper helpers of the second table |

## FUN_001390d8: linear -> dB (vendor)

```c
if (6.309573e-08f <= linear)
    db = log10f(linear) * 20.0f;
else
    db = -144.0f;
```

then clamp into `[lo, hi]` object fields and, when a mapping table
is present, piecewise-linear interpolation over it. Boundary uses
`<=`: the exact floor value is computed, not early-returned.
`VSL_Linear_To_DB` (`x < VSL_DB_FLOOR_LINEAR` guard) has identical
semantics.

## FUN_00139014: dB -> linear (vendor)

Input clamped into `[0, 1]` with `fminnm`, table lerp when present,
then:

```c
if (db < -144.0f)
    return (wide)0x33877f3f;
return powf(10.0f, db * 0.05f);   /* 10^(dB/20) */
```

`0x33877f3f` is bit-identical to `(float)6.309573e-08`
(`VSL_DB_FLOOR_LINEAR`). `VSL_DB_To_Linear` (`db < VSL_DB_NEG_INF`
guard, `powf(10, db/20)`) matches bit-for-bit including the floor.

## Cross-family corroboration

`libquantumusbdevice.so` (Quantum HD 2 / HD 8 / ES 2 / ES 4 strings,
absent from the fender 5.1.0 APK) exports the same formatter
classes: `Presonus::Dsp::FreqFormatter`, `GainDBFormatter`,
`GainFormatter`, `DbInfinityFormatter`. The gain.db / db.inf split
is a platform-wide vendor pattern, not a VSL quirk.

## Open leads (no invention, blockers for later)

- Mapping-table contents for VSL gain params: layout known
  (pointer + count fields), entries unresolved.
- `tanf` slot in the second vtable: taper role unresolved.
- `0x00110634` / `0x0011065c` descriptors: counted-string reads
  came back empty, format unresolved.
- ai_4.7.2 libucnet `0xda0e` floor site: zero code xrefs
  (VA `0x0010da0e`, data-embedded constant). Closed as table-embedded,
  consistent with the table-driven formatter design.

## GhidraMCP live-test status (2026-10-07)

- Bridge `bridge_mcp_ghidra.py` (release 1.4): installed via
  `lazyaddons/ghidramcp.yaml`, `--help` verified, registered as
  LazyOwn `ghidramcp` command. Contract checked against plugin
  source: endpoints `methods/classes/decompile/renameFunction/`
  `renameData/segments/imports/exports/searchFunctions/`
  `get_function_by_address/disassemble_function/...` all exist in
  `GhidraMCPPlugin.java` (`HttpServer`, default port 8080, server
  starts in plugin constructor).
- Plugin installed to
  `~/.config/ghidra/ghidra_12.1.4_PUBLIC/Extensions/GhidraMCP/`
  (upstream zip ships a bogus `Module.manifest`, removed; only
  `extension.properties` + `lib/GhidraMCP.jar` are needed) and
  declared in CodeBrowser `_code_browser.tcd`
  (`com.lauriewired.GhidraMCPPlugin`).
- GUI verified on Xvfb with full Temurin JDK 21
  (`~/tools/jdk-21.0.12.1+1`; the apt `openjdk-21-jdk-headless`
  has no X toolkit so the GUI cannot start on it): project VSL
  opens, all three `.so` open in CodeBrowser.
- Remaining step (30 s, human): open Ghidra normally, open project
  VSL, double-click any `.so`. The plugin then serves `:8080` and
  the bridge runs end to end. Automation limit found: synthetic
  X11 keys are ignored without a keymap (`setxkbmap us` fixes),
  and JFileChooser list clicks do not register; middle-click
  paste (`xclip -selection primary`) into file fields works.
- `spec/fatchannel_registry.md` cites `FUN_0011ccfc` /
  `FUN_0011f5b8` from an older lib build (sha256 `e082c514…`);
  those addresses do not exist in the fender 5.1.0 libucnet range
  (ends `0x0011f95c`). Version drift, not contradiction.
