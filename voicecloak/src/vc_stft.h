#ifndef VC_STFT_H
#define VC_STFT_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Short-Time Fourier Transform context.
 *
 * Allocated via vc_stft_create(). Window size and hop size are fixed
 * at creation time. Window size must be a power of 2.
 */
typedef struct vc_stft_s vc_stft_t;

/**
 * @brief Allocate STFT context.
 * @param fft_size  FFT size (power of 2, e.g. 2048).
 * @param hop_size  Hop size in samples (e.g. fft_size / 4).
 * @return Context pointer or NULL on failure.
 */
vc_stft_t *vc_stft_create(size_t fft_size, size_t hop_size);

/**
 * @brief Release STFT context.
 */
void vc_stft_destroy(vc_stft_t *st);

/**
 * @brief Forward STFT: decompose a mono float buffer into complex frames.
 * @param st       STFT context.
 * @param samples  Input float samples, length = num_samples.
 * @param num_samples  Number of input samples.
 * @param mag      Output: magnitude per bin per frame (row-major, num_frames * (fft_size/2+1)).
 * @param phase    Output: phase per bin per frame (row-major, same layout as mag).
 * @param num_frames_out  Output: number of frames produced.
 * @return 0 on success, -1 on error.
 */
int vc_stft_forward(vc_stft_t *st,
                    const float *samples, size_t num_samples,
                    float **mag, float **phase,
                    size_t *num_frames_out);

/**
 * @brief Inverse STFT: reconstruct signal from modified magnitude/phase.
 * @param st        STFT context.
 * @param mag       Input magnitude (row-major, num_frames * nbins).
 * @param phase     Input phase (row-major, same layout).
 * @param num_frames Number of frames.
 * @param samples_out  Output: reconstructed float samples (caller must pre-allocate).
 * @param num_samples_out  Number of samples to reconstruct.
 * @return 0 on success, -1 on error.
 */
int vc_stft_inverse(vc_stft_t *st,
                    const float *mag, const float *phase,
                    size_t num_frames,
                    float *samples_out, size_t num_samples_out);

/**
 * @brief Inverse STFT with custom synthesis hop (for pitch shifting).
 * @param synth_hop  Synthesis hop size in samples (may differ from analysis hop).
 */
int vc_stft_inverse_hop(vc_stft_t *st,
                        const float *mag, const float *phase,
                        size_t num_frames,
                        float *samples_out, size_t num_samples_out,
                        size_t synth_hop);

/**
 * @brief Number of frequency bins (fft_size/2 + 1).
 */
size_t vc_stft_num_bins(const vc_stft_t *st);

#ifdef __cplusplus
}
#endif

#endif
