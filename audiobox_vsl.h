// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * PreSonus AudioBox 22 VSL - Header File
 * Enhanced Multi-Control Implementation
 * 
 * Copyright (c) 2025 by grisuno (LazyOwn Project)
 * 
 * REFERENCE DOCUMENTATION:
 * - USB Audio Class 2.0 Specification (audio20.pdf)
 * - Feature Unit Control Selectors: Section A.17.7
 * - Wireshark Analysis: Feature Unit 10 & 11 confirmed
 * 
 * CONFIRMED CAPABILITIES (from USB descriptor analysis):
 * - Feature Unit 10 (Playback): bmaControls = 0x0000000f (MUTE + VOLUME)
 * - Feature Unit 11 (Capture):  bmaControls = 0x0000000f (MUTE + VOLUME)
 * 
 * EVIDENCE-BASED DESIGN:
 * All control selectors are derived from official USB Audio Class specs
 * or confirmed via hardware testing. No assumptions made.
 */

#ifndef __AUDIOBOX_VSL_H
#define __AUDIOBOX_VSL_H

/* Forward declaration - avoids circular dependencies */
struct usb_mixer_interface;

/*
 * Feature Unit Control Selectors (UAC2)
 * Reference: USB Audio Class 2.0 Spec, Sections A.10 (UAC1) and A.17.7 (UAC2)
 * 
 * NOTE: Values 0x01-0x0a are defined in <uapi/linux/usb/audio.h> (UAC1)
 *       Values 0x0b-0x10 are defined in <linux/usb/audio-v2.h> (UAC2)
 *       We redefine them here for clarity and self-documentation.
 */

/* UAC1 Control Selectors (0x00 - 0x0a) */
#define UAC_FU_CONTROL_UNDEFINED        0x00
#define UAC_FU_MUTE                     0x01  /* Boolean: 0=Off, 1=On */
#define UAC_FU_VOLUME                   0x02  /* s16: 1/256 dB steps */
#define UAC_FU_BASS                     0x03  /* s16: dB */
#define UAC_FU_MID                      0x04  /* s16: dB */
#define UAC_FU_TREBLE                   0x05  /* s16: dB */
#define UAC_FU_GRAPHIC_EQUALIZER        0x06  /* Multi-band EQ */
#define UAC_FU_AUTOMATIC_GAIN           0x07  /* Boolean: AGC */
#define UAC_FU_DELAY                    0x08  /* u16: milliseconds */
#define UAC_FU_BASS_BOOST               0x09  /* Boolean */
#define UAC_FU_LOUDNESS                 0x0a  /* Boolean */

/* UAC2 Additional Control Selectors (0x0b - 0x10) */
#define UAC2_FU_INPUT_GAIN              0x0b  /* s16: Mic preamp gain */
#define UAC2_FU_INPUT_GAIN_PAD          0x0c  /* Boolean: Pad attenuation */
#define UAC2_FU_PHASE_INVERTER          0x0d  /* Boolean: Phase flip */
#define UAC2_FU_UNDERFLOW               0x0e  /* Boolean: Status flag */
#define UAC2_FU_OVERFLOW                0x0f  /* Boolean: Status flag */
#define UAC2_FU_LATENCY                 0x10  /* u16: Latency control */

/* Compatibility aliases (prefer UAC2_ prefix for consistency) */
#ifndef UAC2_FU_MUTE
#define UAC2_FU_MUTE                    UAC_FU_MUTE
#endif

#ifndef UAC2_FU_VOLUME
#define UAC2_FU_VOLUME                  UAC_FU_VOLUME
#endif

/*
 * AudioBox 22 VSL Feature Unit IDs
 * CONFIRMED via Wireshark USB descriptor analysis (packet #6)
 * 
 * Feature Unit 10: Playback path (USB → Speakers)
 * Feature Unit 11: Capture path (Microphone → USB)
 */
#define VSL_FU_PLAYBACK_UNIT            10
#define VSL_FU_CAPTURE_UNIT             11

/*
 * ALSA Volume Range Configuration
 * Format: 0.01 dB steps (standard ALSA format)
 * 
 * Conversion: UAC2 uses 1/256 dB steps internally
 * Formula: alsa_value = (uac2_value * 100) / 256
 */
#define VSL_VOLUME_MIN_DB               -6000  /* -60.00 dB */
#define VSL_VOLUME_MAX_DB               1200   /* +12.00 dB */
#define VSL_VOLUME_RESOLUTION_DB        1      /* 0.01 dB steps */

/*
 * Public API - Initialization Function
 * 
 * Called by mixer_quirks.c when AudioBox 22 VSL is detected
 * Registers all ALSA controls for the device
 * 
 * @mixer: USB mixer interface context
 * @return: 0 on success, negative error code on failure
 */
int snd_audiobox_vsl_init(struct usb_mixer_interface *mixer);

#endif /* __AUDIOBOX_VSL_H */
