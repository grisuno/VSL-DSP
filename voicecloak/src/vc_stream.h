#ifndef VC_STREAM_H
#define VC_STREAM_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Streaming STFT overlap-add engine for real-time processing.
 *
 * Unlike the offline vc_stft, this engine keeps constant sample rate:
 * it emits exactly as many output samples as input samples consumed,
 * which is mandatory for a live audio stream. Analysis hop equals
 * synthesis hop; a per-frame spectral callback modifies magnitude and
 * phase in place. Latency is one FFT frame.
 */
typedef struct vc_stream_s vc_stream_t;

/**
 * @brief Per-frame spectral transform callback.
 * @param mag    In/out magnitude per bin (length nbins).
 * @param phase  In/out phase per bin (length nbins).
 * @param nbins  fft_size/2 + 1.
 * @param sample_rate  Stream sample rate in Hz.
 * @param hop    Analysis/synthesis hop in samples.
 * @param user   Opaque context (holds any cross-frame transform state).
 *
 * The callback rewrites mag/phase to the synthesis spectrum. State
 * that must persist across frames (phase-vocoder accumulators) lives
 * in @p user, not in the engine.
 */
typedef void (*vc_spectral_fn)(float *mag, float *phase, size_t nbins,
                               uint32_t sample_rate, size_t hop,
                               void *user);

/**
 * @brief Create a streaming engine.
 * @param fft_size  Power of two.
 * @param hop_size  Must divide fft_size; fft_size/hop_size in {2,4}.
 * @param sample_rate  Stream sample rate in Hz (> 0).
 * @return Context or NULL on invalid arguments / allocation failure.
 */
vc_stream_t *vc_stream_create(size_t fft_size, size_t hop_size,
                              uint32_t sample_rate);

/** @brief Release a streaming engine. NULL-safe. */
void vc_stream_destroy(vc_stream_t *st);

/** @brief Algorithmic latency in samples (one FFT frame). */
size_t vc_stream_latency_samples(const vc_stream_t *st);

/**
 * @brief Process a block, producing exactly @p n output samples.
 * @param st   Engine.
 * @param in   Input samples (length n).
 * @param out  Output samples (length n). May alias @p in.
 * @param n    Number of samples.
 * @param fn   Spectral transform, or NULL for identity passthrough.
 * @param user Context passed to @p fn.
 * @return 0 on success, -1 on invalid arguments.
 */
int vc_stream_process(vc_stream_t *st,
                      const float *in, float *out, size_t n,
                      vc_spectral_fn fn, void *user);

#ifdef __cplusplus
}
#endif

#endif
