/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * PreSonus AudioBox VSL Family - Public Interface
 *
 * Single source of truth for the supported product IDs and human
 * readable model names. The kernel detector and the userspace test
 * suite both include this header. The kernel-only declarations
 * (USB device table probe, ALSA mixer init hook) are guarded by
 * __KERNEL__ so the file is safe to compile in userspace.
 *
 * Why no UAC_FU_* here: the UAC1/UAC2 Feature Unit control selectors
 * are defined by the kernel headers <linux/usb/audio.h> and
 * <linux/usb/audio-v2.h>. Re-declaring them in this header would
 * cause a redefinition diagnostic and risk diverging from the
 * canonical values. Callers must include the kernel header instead.
 *
 * Author: grisuno (LazyOwn Project)
 */

#ifndef AUDIOBOX_VSL_H
#define AUDIOBOX_VSL_H

#include <linux/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief PreSonus USB vendor ID shared by every AudioBox VSL model.
 */
#define AUDIOBOX_VENDOR_ID 0x194fU

/**
 * @brief Product IDs of the AudioBox VSL family.
 *
 * The enumerator value is the 16-bit product ID reported by the USB
 * device, so the enum can be passed directly to USB device matching
 * APIs and to audiobox_lookup_model().
 */
typedef enum {
    AUDIOBOX_MODEL_22_VSL   = 0x0101U,
    AUDIOBOX_MODEL_44_VSL   = 0x0102U,
    AUDIOBOX_MODEL_1818_VSL = 0x0103U
} audiobox_model_pid_t;

/**
 * @brief Pair of product ID and canonical human readable model name.
 *
 * The product_name field is a pointer to a static string literal that
 * lives for the lifetime of the kernel. Callers must not free it.
 */
typedef struct {
    uint16_t    pid;
    const char *product_name;
} audiobox_model_info_t;

/**
 * @brief Authoritative table of supported AudioBox VSL models.
 *
 * Indexed positionally by the kernel module to build the USB device
 * table and by the lookup function to translate a product ID into a
 * model name. To add a new model, append exactly one entry here; the
 * rest of the module is generated from this table.
 */
static const audiobox_model_info_t audiobox_models[] = {
    { AUDIOBOX_MODEL_22_VSL,   "AudioBox 22 VSL"   },
    { AUDIOBOX_MODEL_44_VSL,   "AudioBox 44 VSL"   },
    { AUDIOBOX_MODEL_1818_VSL, "AudioBox 1818 VSL" }
};

/**
 * @brief Number of entries in audiobox_models[].
 *
 * Computed at compile time from the array size; never modified at
 * runtime. Safe to use as the upper bound of any loop over the table.
 */
static const size_t audiobox_models_count =
    sizeof(audiobox_models) / sizeof(audiobox_models[0]);

/**
 * @brief Look up the model info entry for a given USB product ID.
 *
 * @param pid 16-bit product ID reported by the USB device.
 * @return Pointer to a const entry in audiobox_models[] on match.
 *         NULL if pid does not correspond to any supported model.
 *
 * Pure function: no side effects, no allocation, safe to call from
 * any context including the USB probe path. The returned pointer
 * remains valid for the lifetime of the kernel. Defined as a
 * static inline so both the kernel module and the userspace test
 * suite can include this header and exercise the lookup without
 * linking against kernel-only object files.
 */
static inline const audiobox_model_info_t *
audiobox_lookup_model(uint16_t pid)
{
    size_t i;

    for (i = 0; i < audiobox_models_count; ++i) {
        if (audiobox_models[i].pid == pid) {
            return &audiobox_models[i];
        }
    }
    return NULL;
}

#ifdef __KERNEL__

#include <linux/usb.h>
#include <sound/core.h>

struct usb_mixer_interface;

/**
 * @brief ALSA mixer init hook for AudioBox VSL devices.
 *
 * Optional entry point used by the upstream sound/usb/mixer_quirks.c
 * dispatch table. Not invoked by the detector itself. Returns 0 on
 * success, a negative errno on failure.
 */
int snd_audiobox_vsl_init(struct usb_mixer_interface *mixer);

#endif /* __KERNEL__ */

#ifdef __cplusplus
}
#endif

#endif /* AUDIOBOX_VSL_H */
