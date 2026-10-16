# Second Brain

*Last synthesized: 2026-10-07 | 69 files | 8 concept pages | offline, zero tokens*

> Raw sources -> readmenator wiki -> links (Karpathy LLM Wiki Pattern, deterministic).
> Start here, then open one community page. Prefer grep over full reads.

## Vault Overview

The codebase centres on `mixer_quirks.c`, `vc_stream.h`, `vc_rt_cli.c`. Architecturally it is 5 layers, dominant utility (46 files) across 8 import-based communities. Recorded risk surface: 0 security findings and 0 dependency cycles.

Surprising tissue lives between voicecloak/src: vc_denoise, voicecloak/src: vc_effects, legacy: 2 extracted cross-community imports and 18 inferred bridges. Follow `connections.json` sorted by strength before refactoring.

Open work clusters around documentation (32% file coverage), 0 security findings, 2 taint paths, and 5 suggested exploration questions in `queries.md`.

## Stats

| Metric | Value |
|--------|-------|
| Files | 69 |
| Symbols | 937 |
| Resolved imports | 87 |
| Languages | c, h, py, sh |
| Communities | 8 |
| Doc coverage | 32% (22/69 files) |
| Security findings | 0 |
| Estimated read cost | ~15071 tokens (chars/4, offline so $0) |

## Reading Order

1. Skim Stats and God Nodes below for blast radius.
2. Open the largest community page first, then follow Connections.
3. Use `queries.md` for the next question; log the answer there.

```
grep -rn '<keyword>' index.md community_*.md
readmenator query "<question>" --target readmenator_VSL-DSP_ukqgsa32
```

## Concept Wiki

- [voicecloak/src: vc_denoise (14 files, cohesion 0.67)](./community_0_voicecloak_src_vc_denoise.md)
- [voicecloak/src: vc_effects (13 files, cohesion 0.68)](./community_1_voicecloak_src_vc_effects.md)
- [legacy (11 files, cohesion 1.00)](./community_2_legacy.md)
- [voicecloak/src: vc_crypto (10 files, cohesion 0.77)](./community_3_voicecloak_src_vc_crypto.md)
- [src (6 files, cohesion 1.00)](./community_4_src.md)
- [root (4 files, cohesion 1.00)](./community_5_root.md)
- [avatar (4 files, cohesion 1.00)](./community_6_avatar.md)
- [orphans (7 files, cohesion 0.00)](./community_7_orphans.md)

## God Nodes

| File | Score |
|------|-------|
| `legacy/mixer_quirks.c` | 32.9 |
| `voicecloak/src/vc_stream.h` | 15.3 |
| `voicecloak/src/vc_rt_cli.c` | 15.0 |
| `legacy/vsl_config.h` | 14.8 |
| `voicecloak/src/vc_rt.h` | 13.7 |

## Strongest Connections

- 0 -> 1: depends_on (strength 0.9, EXTRACTED)
- 0 -> 3: depends_on (strength 0.9, EXTRACTED)
- 0 -> 2: shares_context (strength 0.5, INFERRED)
- 0 -> 4: shares_context (strength 0.5, INFERRED)
- 0 -> 5: shares_context (strength 0.5, INFERRED)
- 0 -> 7: shares_context (strength 0.5, INFERRED)
- 1 -> 2: shares_context (strength 0.5, INFERRED)
- 1 -> 4: shares_context (strength 0.5, INFERRED)
- 1 -> 5: shares_context (strength 0.5, INFERRED)
- 1 -> 7: shares_context (strength 0.5, INFERRED)

## Navigation Tips

- Obsidian Graph View works: every community page links back here.
- `connections.json` is machine-readable for GraphRAG pipelines.
- `REPORT.md` states what was extracted vs inferred and current limits.
- Regenerate offline: `readmenator . --rebuild` (no network, no tokens).
