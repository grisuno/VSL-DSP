#ifndef VC_WAV_H
#define VC_WAV_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Read a mono PCM WAV file into a float buffer [-1.0, 1.0].
 * @param path         File path.
 * @param samples_out  Output: allocated float array.
 * @param num_samples_out Output: number of samples.
 * @param sample_rate_out Output: sample rate (Hz).
 * @return 0 on success, -1 on error.
 */
int vc_wav_read(const char *path,
                float **samples_out, size_t *num_samples_out,
                uint32_t *sample_rate_out);

/**
 * @brief Write a mono float buffer to a 16-bit PCM WAV file.
 * @param path       File path.
 * @param samples    Float samples in [-1.0, 1.0].
 * @param num_samples Number of samples.
 * @param sample_rate Sample rate (Hz).
 * @return 0 on success, -1 on error.
 */
int vc_wav_write(const char *path,
                 const float *samples, size_t num_samples,
                 uint32_t sample_rate);

#ifdef __cplusplus
}
#endif

#endif
