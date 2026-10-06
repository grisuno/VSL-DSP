# Fat Channel Parameter Registry (PreSonus vendor reference)

Reverse-engineered from `libfatchannelplugins.so` (Universal Control
Android app, sha256
`e082c51431a508ab2b6ae8b99cc8305f30880c489bf470c9dae55163668b4ba3`)
with REA + Ghidra 12.1.4. Method: `search gain.db` -> `xrefs 0x10a77b`
-> `decompile 0x134760` (`_INIT_0`, 0x134308-0x134edf), which builds
one static entry per parameter. Evidence envelopes carry IDs
`ev_c763dac2…`, `ev_1de02e2b…`, `ev_165705491b…`.

## Entry schema

Each entry is `{dispatch_fn, name, channel_index, flags}`:

| Name | Handler | Index | Flags | Meaning for VSL-DSP |
|------|---------|-------|-------|---------------------|
| `freq.0` | …eb18 | 0 | – | EQ band 0 frequency |
| `freq.1` | …eb18 | 1 | – | EQ band 1 frequency |
| `gain.db` | …ec38 | 1 | – | dB-domain gain (sibling of `gain.N`) |
| `gain.db.value` | …ec38 | 0 | – | cached dB value mirror |
| `db.inf` | …ec68 | 1 | – | dedicated negative-infinity path |
| `db.inf.value` | …ec68 | 0 | – | cached -inf mirror |
| `gain.0` | …ec08 | 0 | 1 | per-channel linear gain |
| `gain.1` | …ec08 | 1 | 1 | per-channel linear gain |
| `gain.0.value` | …ec08 | 0 | 0 | cached gain mirror |
| `gain.1.value` | …ec08 | 1 | 0 | cached gain mirror |
| `gain.value` | …ec08 | 2 | 0 | master gain |
| `bpm.0` / `bpm.1` | …ed58 | 0 / 1 | 1 | tempo-synced params |
| `pan.100` | …ed28 | 1 | – | pan (two slots share the handler) |
| `cents` / `degrees` | …edb8 | 0 | – | tuner/pitch units share one handler |
| `ratio` | …ecf8 | – | – | compressor ratio (own handler) |
| `count` | …ed88 | 4 | – | counter param, channel field reused as width |

Full `_INIT_0` enumeration (31 static-init blocks, Ghidra 12.1.4
direct disassembly + REA envelope `ev_97f2f29a…`): the handlers above
plus duplicate mirror slots (`bpm.0` registered twice, `pan.100`
twice). Entries whose first field is not a string carry a numeric id
instead of a name; their meaning is unresolved.

## Vendor math confirmed against VSL-DSP

- dB floor pair (new 2026-10-06 evidence): `FUN_0011ccfc` case 6
  returns `-144.0` below linear `6.309573e-08`, else `20*log10(x)`;
  `FUN_0011f5b8` inverts with `powf(10, db*0.05)` floored at the same
  pair. Adopted as `VSL_DB_NEG_INF = -144.0f` and
  `VSL_DB_FLOOR_LINEAR = 6.309573e-08f`.
- Encode shape (`libstudiolivepanel.so`): `FUN_004d54c8` computes
  `p[0x20] + expf(clamp01(x) * p[0x2c]) * p[0x24]`; `FUN_004d56ec`
  adds the `(x-min)/(max-min)` normalization; `FUN_00928bd0` is the
  double-precision twin. This is exactly the `VSL_Encode_Gain`
  structure (`offset_A + C1*exp(norm*log_factor)`), so the formula
  stands on vendor evidence. The `GAIN_COEFFS` values in `vsl_cli`
  (`-10/20/4.60517`) are NOT in this app generation and stay
  hypotheses pinned by the `0.75 -> 40793` pipeline test.
- GOTCHA for future RE: the registry handler slots live in
  `.data.rel.ro` and are runtime-relocated; static reads return the
  pre-relocation stub (`0x1342f8`, a lone `ret`). Resolve handler
  bodies via relocation targets or caller xrefs, never via file
  bytes of the slots.

## Adopted into VSL-DSP

- `gain.db` exists as a dB-domain sibling, not a unit flag:
  `vsl_cli db <ch> <dB>` + `db1`/`db2` table entries, backed by
  `VSL_Linear_To_DB` / `VSL_DB_To_Linear` (`src/vsl_dsp_logic.*`).
- `db.inf` is a separate handler, so VSL-DSP treats -inf as its own
  domain (`VSL_DB_NEG_INF`, linear exactly `0.0`) instead of folding
  it into the bottom of the gain curve.
- `.value` mirrors confirm the vendor caches last-sent values next to
  live params; VSL-DSP has no read-back path, so no mirror is kept.

## Not adopted (unknown vendor codes)

The numeric wire codes of the `db.inf` mute path were not recovered
(the handler pointers are runtime-relocated, file bytes read zero),
so VSL-DSP sends no invented mute code. `-inf` maps to linear `0.0`
through the existing curve and is documented as not-a-mute.
