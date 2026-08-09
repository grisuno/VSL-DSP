#ifndef VC_ALSA_H
#define VC_ALSA_H

#include <stddef.h>
#include <stdint.h>
#include <signal.h>
#include "vc_stream.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Configuration for a real-time ALSA processing session.
 *
 * The capture and playback device names are ALSA PCM names discovered
 * at runtime (e.g. "hw:VSL", "plughw:2,0", "default"); nothing is
 * hardcoded. Rate and channel count are requested but the negotiated
 * values from the device win. The DSP engine is created internally
 * with the negotiated rate; the transform callback and its context
 * are supplied by the caller.
 */
typedef struct {
    const char *capture_dev;
    const char *playback_dev;
    unsigned int rate;            /* desired sample rate (Hz)          */
    unsigned int channels;        /* desired channel count             */
    unsigned int period_frames;   /* ALSA period size in frames        */
    size_t fft_size;              /* engine FFT size                   */
    size_t hop_size;              /* engine hop size                   */
    vc_spectral_fn fn;            /* per-frame transform, or NULL      */
    void *user;                   /* transform context                 */
    volatile sig_atomic_t *stop;  /* set non-zero to end the loop      */
} vc_alsa_cfg_t;

/**
 * @brief Print the available ALSA PCM devices to stdout.
 * @return 0 on success, -1 on error.
 */
int vc_alsa_list(void);

/**
 * @brief Open capture and playback, run the processing loop until
 *        *cfg->stop becomes non-zero or a fatal error occurs.
 * @return 0 on clean stop, -1 on error.
 */
int vc_alsa_run(const vc_alsa_cfg_t *cfg);

#ifdef __cplusplus
}
#endif

#endif
