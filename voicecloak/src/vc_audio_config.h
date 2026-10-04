#ifndef VC_AUDIO_CONFIG_H
#define VC_AUDIO_CONFIG_H

/** @brief Accepted sample-rate interval for live effect engines. */
#define VC_AUDIO_MIN_SAMPLE_RATE 8000U
#define VC_AUDIO_MAX_SAMPLE_RATE 384000U

/** @brief Fail-closed bound between DSP stages, before final limiting. */
#define VC_AUDIO_MAX_INTERNAL_SAMPLE 16.0f

#define VC_LEVEL_MIN_TARGET_DBFS (-60.0f)
#define VC_LEVEL_MAX_TARGET_DBFS 0.0f
#define VC_LEVEL_MIN_CEILING_DBFS (-24.0f)
#define VC_LEVEL_MAX_CEILING_DBFS 0.0f
#define VC_LEVEL_MAX_GAIN_DB 36.0f
#define VC_LEVEL_MIN_TIME_MS 0.1f
#define VC_LEVEL_MAX_TIME_MS 5000.0f
#define VC_LEVEL_RMS_FLOOR 1e-12f

#endif
