# Project Memory

> Cross-session context for agents. Sections 1-6 are regenerated from the source tree with zero LLM tokens: declared rules are quoted verbatim with `file:line`, measured baselines come from the scan. Section 7 is written by agents and humans and is preserved across rebuilds.

Generated from 69 files at commit `1b5ad1bd1665`. Read this first, then `readmenator-wiki/index.md`, then `readmenator . ask "<question>"` for anything specific.

## 1. Purpose and domain

- What it is: AudioBox VSL family of USB audio interfaces.** No other open source (`README.md:4`)
- Domain vocabulary (term, files): `voicecloak` (37), `vsl` (25), `brief` (20), `dsp` (20), `create` (19), `rate` (18), `legacy` (17), `float` (16), `destroy` (16), `gain` (15), `max` (14), `null` (13), `success` (13), `cplusplus` (13), `ifdef` (13)
- Subsystem `voicecloak/src: vc_denoise`: 14 files, core `voicecloak/src/vc_denoise.h`: vc_denoise_params_t: @brief Noise reduction settings.  reduction: over-subtraction factor...
- Subsystem `voicecloak/src: vc_effects`: 13 files, core `voicecloak/src/vc_effects.c`: ring_modulate: Soft square: a hard edge multiplies the voice by infinitely many harmonics that...
- Subsystem `legacy`: 11 files, core `legacy/vsl_hid_io.py`: VSL-DSP HID I/O Module (OPCIONAL) Comunicación real con hardware via hidapi.
- Subsystem `voicecloak/src: vc_crypto`: 10 files, core `voicecloak/src/vc_crypto.h`: vc_crypto_keygen: @brief Generate an RSA-4096 keypair and write to PEM files. @param pubkey_path...
- Subsystem `src`: 6 files, core `src/vsl_config.h`: pid: ifdef __cplusplus
- Subsystem `root`: 4 files, core `legacy/mixer_quirks.c`: rc_config: Sound Blaster remote control configuration  format of remote control data: Extigy...
- Subsystem `avatar`: 4 files, core `avatar/avatar_config.h`
- Business rules that the code cannot show live in section 7: record them there.

## 2. Workflow

Detected commands:
- `python -m pytest -q` (tests/ layout)
- `make all` (Makefile)
- `make modules` (Makefile)
- `make tests` (Makefile)
- `make test` (Makefile)
- `make asan` (Makefile)
- `make test-dsp` (Makefile)
- `make test-transport` (Makefile)
- `make vsl-cli` (Makefile)
- `make avatar-test` (Makefile)
- `make avatar-asan` (Makefile)
- `make avatar-build` (Makefile)

Session protocol:
1. Start: read this file, then `readmenator . fresh` (exit 1 means run `readmenator . --rebuild`).
2. Orient: `readmenator-wiki/index.md`; for a question use `readmenator . ask "<question>"` (local = entities + sources, `--global` = community reports).
3. Before editing a file: `grep -n '<file>' readmenator-agent/GOTCHAS.md readmenator-agent/SECURITY.md`.
4. After the change: run the tests above, then `readmenator . --rebuild` so the maps, wiki, and this file stay true.
5. End: record decisions, business rules, and gotchas with `readmenator . remember "<note>" --kind decision`.

## 3. Rules and constraints

Declared:
- **Zero Assumption.** No value is invented. No VID, PID, Report ID, (`CLAUDE.md:18`)
- **Evidence over Intuition.** Every constant, offset, or mask in (`CLAUDE.md:25`)
- **Safe by Default.** The insecure configuration must not be (`CLAUDE.md:29`)
- **Non-Interference (the detector must not break audio).** The (`CLAUDE.md:34`)
- **Traceability (immutable naming).** Names extracted from the (`CLAUDE.md:41`)
- **Extensible by Design.** Every contract anticipates growth (`CLAUDE.md:47`)
- Apply the complete cycle of section 3 in order: spec -> red test (`CLAUDE.md:561`)
- **Zero Assumption.** When in doubt about a constant from the (`CLAUDE.md:566`)
- **Fail closed.** When in doubt about safety (buffer, pointer, (`CLAUDE.md:570`)
- **Do not break audio.** The kernel detector always returns (`CLAUDE.md:574`)
- **Immutable naming.** Keep `VSL_Encode_Gain`, `FUN_00412345`, (`CLAUDE.md:578`)
- Be honest about what is not verified: code that cannot be (`CLAUDE.md:581`)
- Verify that every symbol, flag, or constant exists before (`CLAUDE.md:584`)
- New commands go in the `Makefile` (single source of truth), not (`CLAUDE.md:586`)
- Boy-scout mode: retiring technical debt and security flaws is (`CLAUDE.md:588`)
- Lateral thinking when the environment demands it (e.g. libusb-1.0 (`CLAUDE.md:591`)
- After every change: re-run `make` and `make test` from a clean (`CLAUDE.md:595`)

Measured baseline:
- Security findings at medium or above: 0 (see `readmenator-agent/SECURITY.md`); do not add new ones.
- Dependency cycles: 0; layer violations: 0 (see `readmenator-agent/GOTCHAS.md`).

## 4. Style norms

Declared:
- **Kernel:** pure C, Linux kernel headers, C11 GCC. No C++, no (`CLAUDE.md:64`)
- **Userspace (PoC and library):** pure C, C11, with libusb-1.0 (`CLAUDE.md:68`)
- **Identifiers and strings are English.** Documentation (`CLAUDE.md:70`)
- **No emojis in kernel or userspace source.** No emojis in (`CLAUDE.md:75`)
- **Prefix by module.** `audiobox_` for the kernel detector, (`CLAUDE.md:80`)
- **No hardcoded values, no magic numbers, no absolute system (`CLAUDE.md:86`)

Measured baseline:
- c: 35 files, 636 symbols; docstrings on 5% of symbols; functions snake_case (95%); types PascalCase (16%); median file 191 lines, max 4569.
- h: 23 files, 244 symbols; docstrings on 43% of symbols; functions snake_case (76%); types PascalCase (0%); median file 71 lines, max 158.
- py: 7 files, 39 symbols; docstrings on 90% of symbols; functions snake_case (100%); types PascalCase (100%); median file 219 lines, max 305.
- sh: 4 files, 21 symbols; docstrings on 0% of symbols; functions snake_case (100%); median file 161 lines, max 516.
- Tests: 10 files under legacy, tests, voicecloak/tests; follow the existing naming (e.g. `test_connection.c`).

## 5. Minimum deliverables

Declared:
- none declared in instruction files (add them to AGENTS.md or record them in section 7)

Measured baseline:
- Tests pass: `python -m pytest -q`.
- Docstring coverage stays at or above 18%.
- No new security findings at medium or above (current: 0).
- No new dependency cycles (current: 0).
- Files stay under 300 lines where possible (`readmenator . lint`).
- Docs refreshed: `readmenator . --rebuild`, and decisions recorded in section 7.

## 6. Risks to respect

- God nodes (changes ripple widely): `legacy/mixer_quirks.c`, `voicecloak/src/vc_stream.h`, `voicecloak/src/vc_rt_cli.c`, `legacy/vsl_config.h`, `voicecloak/src/vc_rt.h`
- Hotspots (complex and central): `legacy/mixer_quirks.c`, `voicecloak/src/vc_rt_cli.c`, `voicecloak/tests/test_vc_denoise.c`, `voicecloak/tests/test_vc_presets.c`, `voicecloak/tests/test_vc_stream.c`
- Full blast radius: `readmenator-agent/GOTCHAS.md`; findings: `readmenator-agent/SECURITY.md`.

## 7. Session log (preserved across rebuilds)

Append with `readmenator . remember "<note>" --kind <kind>` (kinds: business, decision, rule, workflow, style, deliverable, gotcha, todo, note) or the MCP tool `readmenator.remember`. Record business rules, decisions and their reasons, workflow changes, and anything the next session must not rediscover.

<!-- readmenator:memory:notes:begin -->
<!-- readmenator:memory:notes:end -->
