#ifndef VC_PRESETS_H
#define VC_PRESETS_H

#include "vc_effects.h"
#include "vc_rt.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    const char *name;
    vc_rt_params_t cloak;
    vc_effects_params_t effects;
} vc_preset_t;

/**
 * @brief Resolve a named real-time voice/effect preset.
 * @return 0 on match; -1 for unknown name or invalid arguments.
 */
int vc_preset_lookup(const char *name, vc_preset_t *out);

#ifdef __cplusplus
}
#endif

#endif
