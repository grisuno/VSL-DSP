#ifndef VC_DSP_H
#define VC_DSP_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    VC_MODE_SUBTLE = 0,
    VC_MODE_WITNESS = 1
} VcMode;

int vc_dsp_pitch_shift(const float *samples, size_t num_samples,
                       uint32_t sample_rate, float semitones,
                       float **out, size_t *out_len);

int vc_dsp_formant_shift(const float *samples, size_t num_samples,
                         uint32_t sample_rate, float shift_factor,
                         float **out, size_t *out_len);

int vc_dsp_spectral_scramble(const float *samples, size_t num_samples,
                             uint32_t sample_rate, float intensity,
                             float **out, size_t *out_len);

int vc_dsp_cloak(const float *samples, size_t num_samples,
                 uint32_t sample_rate,
                 const unsigned char *pitch_seed,
                 const unsigned char *formant_seed,
                 const unsigned char *spectral_seed,
                 VcMode mode,
                 float **out, size_t *out_len);

#ifdef __cplusplus
}
#endif

#endif
