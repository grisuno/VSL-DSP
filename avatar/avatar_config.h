#ifndef AVATAR_CONFIG_H
#define AVATAR_CONFIG_H

/**
 * @brief Single source of truth for avatar defaults.
 *
 * Thresholds are a working hypothesis tunable via CLI; calibrate
 * with real AudioBox hardware before closing the contract.
 * Image paths are repository-root relative.
 */

#define AVATAR_DEFAULT_PCM "plughw:CARD=VSL"
#define AVATAR_FALLBACK_PCM "default"

#define AVATAR_IMG_CLOSED "img/cgoblin.png"
#define AVATAR_IMG_OPEN "img/cgobling.png"
#define AVATAR_IMG_SIBILANT "img/cgoblin2.png"

#define AVATAR_DEFAULT_SILENCE_DB (-50.0f)
#define AVATAR_DEFAULT_ZCR_THR (0.25f)
#define AVATAR_DEFAULT_HF_THR (0.60f)
#define AVATAR_DEFAULT_HOLD_MS (120U)

#define AVATAR_FRAME_SAMPLES (1024U)
#define AVATAR_DEFAULT_RATE (48000U)
#define AVATAR_WIN_W (512)
#define AVATAR_WIN_H (512)

#endif
