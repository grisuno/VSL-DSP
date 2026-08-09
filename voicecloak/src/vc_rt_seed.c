#include "vc_rt.h"
#include "vc_crypto.h"
#include <math.h>

int vc_rt_derive(const unsigned char *pitch_seed,
                 const unsigned char *formant_seed,
                 const unsigned char *spectral_seed,
                 int witness_mode, vc_rt_params_t *out) {
    if (!pitch_seed || !formant_seed || !spectral_seed || !out) return -1;

    vc_prng_t *pp = vc_prng_create(pitch_seed);
    vc_prng_t *pf = vc_prng_create(formant_seed);
    vc_prng_t *ps = vc_prng_create(spectral_seed);
    if (!pp || !pf || !ps) {
        vc_prng_destroy(pp); vc_prng_destroy(pf); vc_prng_destroy(ps);
        return -1;
    }

    float pitch_semitones, formant_factor, scramble_intensity;
    if (witness_mode) {
        pitch_semitones    = vc_prng_float(pp, -10.0f, 10.0f);
        formant_factor     = vc_prng_float(pf, 0.5f, 1.8f);
        scramble_intensity = vc_prng_float(ps, 0.6f, 1.0f);
    } else {
        pitch_semitones    = vc_prng_float(pp, -3.0f, 3.0f);
        formant_factor     = vc_prng_float(pf, 0.85f, 1.15f);
        scramble_intensity = vc_prng_float(ps, 0.1f, 0.3f);
    }

    vc_prng_destroy(pp);
    vc_prng_destroy(pf);
    vc_prng_destroy(ps);

    out->pitch_ratio        = vc_rt_semitones_to_ratio(pitch_semitones);
    out->formant_factor     = formant_factor;
    out->scramble_intensity = scramble_intensity;
    return 0;
}
