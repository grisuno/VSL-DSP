# `avatar/avatar_main.c`

> Source: [avatar/avatar_main.c:1](../../avatar/avatar_main.c#L1) | language `c` | coverage 0.0% | [API index](../index.md)

## Contents

- **Functions:** [`main`](#main)

## Call Graph

Solid arrows stay in this module, dashed arrows leave it.

```mermaid
flowchart LR
    n_avatar_avatar_main_c__main(["main"])
    n_avatar_avatar_logic_h__avatar_classify["avatar_logic.avatar_classify"]
    n_avatar_avatar_logic_h__avatar_hf_ratio_f32["avatar_logic.avatar_hf_ratio_f32"]
    n_avatar_avatar_logic_h__avatar_rms_f32["avatar_logic.avatar_rms_f32"]
    n_avatar_avatar_logic_h__avatar_rms_to_dbfs["avatar_logic.avatar_rms_to_dbfs"]
    n_avatar_avatar_logic_h__avatar_smooth["avatar_logic.avatar_smooth"]
    n_avatar_avatar_logic_h__avatar_smooth_init["avatar_logic.avatar_smooth_init"]
    n_avatar_avatar_logic_h__avatar_state_name["avatar_logic.avatar_state_name"]
    n_avatar_avatar_logic_h__avatar_zcr_f32["avatar_logic.avatar_zcr_f32"]
    n_avatar_avatar_main_c__main -.-> n_avatar_avatar_logic_h__avatar_classify
    n_avatar_avatar_main_c__main -.-> n_avatar_avatar_logic_h__avatar_hf_ratio_f32
    n_avatar_avatar_main_c__main -.-> n_avatar_avatar_logic_h__avatar_rms_f32
    n_avatar_avatar_main_c__main -.-> n_avatar_avatar_logic_h__avatar_rms_to_dbfs
    n_avatar_avatar_main_c__main -.-> n_avatar_avatar_logic_h__avatar_smooth
    n_avatar_avatar_main_c__main -.-> n_avatar_avatar_logic_h__avatar_smooth_init
    n_avatar_avatar_main_c__main -.-> n_avatar_avatar_logic_h__avatar_state_name
    n_avatar_avatar_main_c__main -.-> n_avatar_avatar_logic_h__avatar_zcr_f32
```

## Functions

<a id="main"></a>

### `main`

`function` | [avatar/avatar_main.c:191](../../avatar/avatar_main.c#L191)

```c
int main(int argc, char **argv)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `argc` | `int` |  |  |
| `argv` | `char **` |  |  |

**Returns:** `int`

*Calls:* [`avatar_classify`](avatar.avatar_logic.h.md#avatar_classify), [`avatar_hf_ratio_f32`](avatar.avatar_logic.h.md#avatar_hf_ratio_f32), [`avatar_rms_f32`](avatar.avatar_logic.h.md#avatar_rms_f32), [`avatar_rms_to_dbfs`](avatar.avatar_logic.h.md#avatar_rms_to_dbfs), [`avatar_smooth`](avatar.avatar_logic.h.md#avatar_smooth), [`avatar_smooth_init`](avatar.avatar_logic.h.md#avatar_smooth_init), [`avatar_state_name`](avatar.avatar_logic.h.md#avatar_state_name), [`avatar_zcr_f32`](avatar.avatar_logic.h.md#avatar_zcr_f32)

---
