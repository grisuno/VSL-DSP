#ifndef VC_FFT_H
#define VC_FFT_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Radix-2 Cooley-Tukey FFT (decimation-in-time).
 * @param n      FFT size, must be a power of 2.
 * @param real   Input/output real parts.
 * @param imag   Input/output imaginary parts.
 * @param inverse 0 for forward FFT, 1 for inverse IFFT.
 *
 * The inverse transform includes the 1/n scaling factor so that
 * FFT(IFFT(x)) == IFFT(FFT(x)) == x.
 */
void vc_fft(size_t n, float *real, float *imag, int inverse);

#ifdef __cplusplus
}
#endif

#endif
