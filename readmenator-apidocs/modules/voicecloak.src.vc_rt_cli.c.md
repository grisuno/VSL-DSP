# `voicecloak/src/vc_rt_cli.c`

> Source: [voicecloak/src/vc_rt_cli.c:1](../../voicecloak/src/vc_rt_cli.c#L1) | language `c` | coverage 0.0% | [API index](../index.md)

## Contents

- **Functions:** [`main`](#main)
- **Macros:** [`_POSIX_C_SOURCE`](#_posix_c_source), [`M_PI`](#m_pi)

## Call Graph

Solid arrows stay in this module, dashed arrows leave it.

```mermaid
flowchart LR
    n_voicecloak_src_vc_rt_cli_c__main(["main"])
    n_voicecloak_src_vc_alsa_h__vc_alsa_list["vc_alsa.vc_alsa_list"]
    n_voicecloak_src_vc_rt_cli_c__main -.-> n_voicecloak_src_vc_alsa_h__vc_alsa_list
```

## Functions

<a id="main"></a>

### `main`

`function` | [voicecloak/src/vc_rt_cli.c:504](../../voicecloak/src/vc_rt_cli.c#L504)

```c
int main(int argc, char *argv[])
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `argc` | `int` |  |  |
| `argv` | `char * []` |  |  |

**Returns:** `int`

*Calls:* [`vc_alsa_list`](voicecloak.src.vc_alsa.h.md#vc_alsa_list)

---

## Macros

<a id="_posix_c_source"></a>

### `_POSIX_C_SOURCE`

`macro` | [voicecloak/src/vc_rt_cli.c:1](../../voicecloak/src/vc_rt_cli.c#L1)

```c
#define _POSIX_C_SOURCE
```

---

<a id="m_pi"></a>

### `M_PI`

`macro` | [voicecloak/src/vc_rt_cli.c:19](../../voicecloak/src/vc_rt_cli.c#L19)

```c
#define M_PI
```

---
