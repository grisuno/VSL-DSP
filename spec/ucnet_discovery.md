# UCNET Discovery (PreSonus vendor reference)

Reverse-engineered from `libucnet.so` (Universal Control Android app,
sha256 `ea7349f306fb49dfc176a938b80f484163ec3f996ea9dded120208c6d296c5eb`)
with REA + Ghidra 12.1.4. Method: `search "official port"` (string at
`0x10ab4c`) -> `xrefs` (code ref `0x13ee80`) -> `decompile`
(`FUN_0013e9f8`). Evidence IDs `ev_c4aac266…`, `ev_6c5a8d92…`,
`ev_d7d97be8…`.

## Observed facts

- Discovery socket: `socket(AF_INET=2, SOCK_DGRAM=2, IPPROTO_UDP=0x11)`.
- Bind: `INADDR_ANY` port bytes `0xBA 0xC1` = UDP **47809**.
- Log line: `Enabled UDP multicast on official port %d (%d sockets)`.
- Session events: `UC Discovery` alive/leave/query/timeout with server
  id and tcp+udp port pairs (`Server "%s" (id = "%s") ... tcp %d udp %d`).
- Peer discovery on Android goes through `NsdDiscoveryHandler`
  (`dev/ccl/core/NsdDiscoveryHandler`), i.e. mDNS/DNS-SD alongside
  the raw UCNET UDP channel; TCP carries the control session
  (`Started listening on TCP port %d`).

## For VSL-DSP

The kernel detector stays USB-only (out of scope by design). Any
future network remote for `vsl_cli` must follow this shape: mDNS
advertisement plus a UCNET-style UDP beacon on 47809 with alive/leave
semantics, TCP for control. Verification not yet performed (needs a
device speaking UCNET on the LAN and a packet capture); do not treat
the port as a connect target until a capture confirms the handshake.
