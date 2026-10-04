# Second Brain

*Last synthesized: 2026-10-04 | 64 files | 7 concept pages | offline, zero tokens*

> Raw sources -> readmenator wiki -> links (Karpathy LLM Wiki Pattern, deterministic).
> Start here, then open one community page. Prefer grep over full reads.

## Vault Overview

The codebase centres on `mixer_quirks.c`, `vsl_config.h`, `vc_rt_cli.c`. Architecturally it is 6 layers, dominant utility (38 files) across 7 import-based communities. Recorded risk surface: 0 security findings and 0 dependency cycles.

Surprising tissue lives between root, avatar, legacy: 1 extracted cross-community imports and 19 inferred bridges. Follow `connections.json` sorted by strength before refactoring.

Open work clusters around documentation (33% file coverage), 0 security findings, 2 taint paths, and 5 suggested exploration questions in `queries.md`.

## Stats

| Metric | Value |
|--------|-------|
| Files | 64 |
| Symbols | 811 |
| Resolved imports | 76 |
| Languages | c, h, py, sh |
| Communities | 7 |
| Doc coverage | 33% (21/64 files) |
| Security findings | 0 |
| Estimated read cost | ~12612 tokens (chars/4, offline so $0) |

## Reading Order

1. Skim Stats and God Nodes below for blast radius.
2. Open the largest community page first, then follow Connections.
3. Use `queries.md` for the next question; log the answer there.

```
grep -rn '<keyword>' index.md community_*.md
readmenator query "<question>" --target VSL-DSP
```

## Concept Wiki

- [root (4 files, cohesion 1.00)](./community_0_root.md)
- [avatar (5 files, cohesion 1.00)](./community_1_avatar.md)
- [legacy (11 files, cohesion 1.00)](./community_2_legacy.md)
- [src (6 files, cohesion 1.00)](./community_3_src.md)
- [voicecloak/src (community 4) (24 files, cohesion 0.92)](./community_4_voicecloak_src.md)
- [voicecloak/src (community 5) (7 files, cohesion 0.70)](./community_5_voicecloak_src.md)
- [orphans (7 files, cohesion 0.00)](./community_6_orphans.md)

## God Nodes

| File | Score |
|------|-------|
| `legacy/mixer_quirks.c` | 32.9 |
| `legacy/vsl_config.h` | 14.8 |
| `voicecloak/src/vc_rt_cli.c` | 13.0 |
| `voicecloak/src/vc_stream.h` | 12.8 |
| `voicecloak/src/vc_fft.h` | 12.2 |

## Strongest Connections

- 5 -> 4: depends_on (strength 0.9, EXTRACTED)
- 0 -> 1: shares_context (strength 0.5, INFERRED)
- 0 -> 3: shares_context (strength 0.5, INFERRED)
- 0 -> 4: shares_context (strength 0.5, INFERRED)
- 0 -> 5: shares_context (strength 0.5, INFERRED)
- 1 -> 3: shares_context (strength 0.5, INFERRED)
- 1 -> 4: shares_context (strength 0.5, INFERRED)
- 1 -> 5: shares_context (strength 0.5, INFERRED)
- 2 -> 3: shares_context (strength 0.5, INFERRED)
- 2 -> 4: shares_context (strength 0.5, INFERRED)

## Navigation Tips

- Obsidian Graph View works: every community page links back here.
- `connections.json` is machine-readable for GraphRAG pipelines.
- `REPORT.md` states what was extracted vs inferred and current limits.
- Regenerate offline: `readmenator . --rebuild` (no network, no tokens).
