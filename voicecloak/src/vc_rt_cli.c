#define _POSIX_C_SOURCE 200809L

#include "vc_alsa.h"
#include "vc_stream.h"
#include "vc_rt.h"
#include "vc_fft.h"
#include "vc_crypto.h"
#include "vc_presets.h"
#include "vc_denoise.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <math.h>
#include <errno.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

static volatile sig_atomic_t g_stop = 0;

static void on_sigint(int sig) {
    (void)sig;
    g_stop = 1;
}

static int parse_float(const char *text, float *out) {
    if (!text || !out) return -1;
    errno = 0;
    char *end = NULL;
    float value = strtof(text, &end);
    if (errno != 0 || end == text || *end != '\0' || !isfinite(value))
        return -1;
    *out = value;
    return 0;
}

static void print_usage(const char *prog) {
    printf(
        "VoiceCloak real-time - live voice changer over an ALSA interface\n"
        "\n"
        "Usage: %s <command> [options]\n"
        "\n"
        "Commands:\n"
        "  list                          List ALSA PCM devices\n"
        "  selftest                      Run the engine on a synthetic tone\n"
        "  live [options]                Process a live stream\n"
        "\n"
        "Live options:\n"
        "  -D <dev>       Capture PCM (default: default; e.g. hw:VSL)\n"
        "  -P <dev>       Playback PCM (default: default; e.g. hw:VSL)\n"
        "  --mode <m>     subtle | witness (random seed within mode ranges)\n"
        "  --preset <p>   robot|monster|woman|man|space|underwater|church|phaser\n"
        "  --semitones N  Fixed pitch shift in -24..24 semitones\n"
        "  --formant F    Fixed formant factor (0.3-3.0, overrides mode)\n"
        "  --scramble S   Fixed scramble intensity (0.0-1.0, overrides mode)\n"
        "  --fft N        FFT size, power of two (default 1024)\n"
        "  --hop N        Hop size, fft/hop in {2,4} (default 256)\n"
        "  --rate R       Requested sample rate (default 48000)\n"
        "  --channels C   Requested channel count (default 2)\n"
        "  --period P     ALSA period in frames (default 256)\n"
        "  --target-dbfs DB  RMS target (default -18)\n"
        "  --max-gain-db DB  Maximum AGC boost (default +12)\n"
        "  --ceiling-dbfs DB Peak ceiling (default -1)\n"
        "  --attack-ms MS / --release-ms MS  RMS smoothing times\n"
        "  --limiter-release-ms MS  Limiter release time (default 50)\n"
        "  --no-agc       Disable RMS gain; keep peak limiter enabled\n"
        "  --drive D      Soft saturation drive 0-8 before the limiter\n"
        "                 (default: preset value, 0 = off)\n"
        "  --ring-amount A  Ring modulation depth 0-1 (robot or no preset)\n"
        "  --ring-hz F    Ring carrier frequency in Hz\n"
        "  --ring-wave W  Ring carrier: sine | square\n"
        "  --denoise      Remove background noise before the voice transform\n"
        "  --noise-learn-ms MS  Noise print length at start (default 1500,\n"
        "                 stay silent; output is muted meanwhile)\n"
        "  --noise-profile FILE Load a saved noise print instead of learning\n"
        "  --noise-save FILE    Save the learned noise print on exit\n"
        "  --noise-reduction R  Over-subtraction 1-6 (default 2)\n"
        "  --noise-floor-db DB  Lowest per-bin gain -60..0 (default -24)\n"
        "  --noise-gate-snr-db DB   Silence threshold above the print (default 6)\n"
        "  --noise-gate-range-db DB Silence attenuation 0-60 (default 30)\n"
        "\n"
        "Examples:\n"
        "  %s list\n"
        "  %s selftest\n"
        "  %s live -D hw:VSL -P hw:VSL --mode witness\n"
        "  %s live -D hw:VSL -P hw:VSL --semitones 7 --formant 1.3\n"
        "  %s live -D hw:VSL -P pulse --preset robot\n",
        prog, prog, prog, prog, prog, prog);
}

static float dominant_freq(const float *x, size_t n, unsigned int sr) {
    size_t nf = 8192;
    if (n < nf) return 0.0f;
    float *re = (float *)calloc(nf, sizeof(float));
    float *im = (float *)calloc(nf, sizeof(float));
    if (!re || !im) { free(re); free(im); return 0.0f; }
    size_t i;
    for (i = 0; i < nf; ++i) {
        float w = 0.5f * (1.0f - cosf(2.0f * (float)M_PI *
                                      (float)i / (float)(nf - 1)));
        re[i] = x[i] * w;
    }
    vc_fft(nf, re, im, 0);
    size_t best = 1;
    float bestmag = -1.0f;
    for (i = 1; i < nf / 2; ++i) {
        float m = re[i] * re[i] + im[i] * im[i];
        if (m > bestmag) { bestmag = m; best = i; }
    }
    free(re); free(im);
    return (float)best * (float)sr / (float)nf;
}

static int cmd_selftest(void) {
    unsigned int sr = 48000;
    size_t fft = 2048, hop = 512, n = 24000;
    float in_freq = 1000.0f, ratio = 2.0f, expect = 2000.0f;

    float *in = (float *)malloc(n * sizeof(float));
    float *out = (float *)malloc(n * sizeof(float));
    if (!in || !out) { free(in); free(out); return 1; }
    size_t i;
    for (i = 0; i < n; ++i)
        in[i] = 0.6f * sinf(2.0f * (float)M_PI * in_freq *
                            (float)i / (float)sr);

    vc_stream_t *st = vc_stream_create(fft, hop, sr);
    vc_rt_params_t p = { ratio, 1.0f, 0.0f, 0 };
    vc_rt_ctx_t *ctx = vc_rt_create(fft / 2 + 1, p);
    if (!st || !ctx) {
        fprintf(stderr, "selftest: setup failed\n");
        vc_stream_destroy(st); vc_rt_destroy(ctx); free(in); free(out);
        return 1;
    }
    vc_stream_process(st, in, out, n, vc_rt_transform, ctx);

    size_t skip = vc_stream_latency_samples(st) + 4096;
    float got_in  = dominant_freq(in, n, sr);
    float got_out = dominant_freq(out + skip, n - skip, sr);
    int ok = fabsf(got_out - expect) < 0.03f * expect;

    printf("selftest: input dominant  = %.1f Hz (expected %.1f)\n",
           (double)got_in, (double)in_freq);
    printf("selftest: pitch x%.2f     = %.1f Hz (expected %.1f)\n",
           (double)ratio, (double)got_out, (double)expect);
    printf("selftest: %s\n", ok ? "PASS" : "FAIL");

    vc_stream_destroy(st); vc_rt_destroy(ctx); free(in); free(out);
    return ok ? 0 : 1;
}

static int resolve_params(int have_fixed, float semis, float formant,
                          float scramble, int witness, vc_rt_params_t *p) {
    if (have_fixed) {
        p->pitch_ratio        = vc_rt_semitones_to_ratio(semis);
        p->formant_factor     = formant;
        p->scramble_intensity = scramble;
        p->robotize           = 0;
        return 0;
    }
    unsigned char master[VC_TOTAL_SEED_BYTES];
    FILE *ur = fopen("/dev/urandom", "rb");
    if (!ur || fread(master, 1, VC_TOTAL_SEED_BYTES, ur) != VC_TOTAL_SEED_BYTES) {
        if (ur) fclose(ur);
        fprintf(stderr, "live: cannot read random seed\n");
        return -1;
    }
    fclose(ur);
    unsigned char ps[VC_CRYPTO_KEY_BYTES], fs[VC_CRYPTO_KEY_BYTES],
                  ss[VC_CRYPTO_KEY_BYTES];
    if (vc_crypto_derive_seeds(master, VC_TOTAL_SEED_BYTES, ps, fs, ss) != 0)
        return -1;
    return vc_rt_derive(ps, fs, ss, witness, p);
}

static int cmd_live(int argc, char *argv[]) {
    const char *cap_dev = "default", *play_dev = "default";
    const char *preset_name = NULL;
    int witness = 0, have_fixed = 0;
    int mode_specified = 0;
    float semis = 0.0f, formant = 1.0f, scramble = 0.0f;
    size_t fft = 1024, hop = 256;
    unsigned int rate = 48000, channels = 2, period = 256;
    vc_level_config_t level_config;
    vc_effects_params_t effect_params = {0};
    vc_eq_params_t eq_params = {0};
    float drive = 0.0f, ring_amount = 0.0f, ring_hz = 0.0f;
    int have_drive = 0, have_ring_amount = 0, have_ring_hz = 0;
    int have_ring_wave = 0;
    vc_ring_waveform_t ring_wave = VC_RING_WAVE_SINE;
    int denoise_enabled = 0, denoise_option = 0;
    const char *noise_profile = NULL, *noise_save = NULL;
    vc_denoise_params_t denoise_params;
    vc_denoise_params_defaults(&denoise_params);
    vc_level_config_defaults(&level_config);

    int i;
    for (i = 2; i < argc; ++i) {
        if (!strcmp(argv[i], "-D") && i + 1 < argc) cap_dev = argv[++i];
        else if (!strcmp(argv[i], "-P") && i + 1 < argc) play_dev = argv[++i];
        else if (!strcmp(argv[i], "--mode") && i + 1 < argc) {
            ++i;
            if (!strcmp(argv[i], "witness")) witness = 1;
            else if (!strcmp(argv[i], "subtle")) witness = 0;
            else { fprintf(stderr, "Unknown mode: %s\n", argv[i]); return 1; }
            mode_specified = 1;
        }
        else if (!strcmp(argv[i], "--preset") && i + 1 < argc) {
            preset_name = argv[++i];
        }
        else if (!strcmp(argv[i], "--semitones") && i + 1 < argc) {
            if (parse_float(argv[++i], &semis) != 0) {
                fprintf(stderr, "Invalid --semitones value\n"); return 1;
            }
            have_fixed = 1;
        }
        else if (!strcmp(argv[i], "--formant") && i + 1 < argc) {
            if (parse_float(argv[++i], &formant) != 0) {
                fprintf(stderr, "Invalid --formant value\n"); return 1;
            }
            have_fixed = 1;
        }
        else if (!strcmp(argv[i], "--scramble") && i + 1 < argc) {
            if (parse_float(argv[++i], &scramble) != 0) {
                fprintf(stderr, "Invalid --scramble value\n"); return 1;
            }
            have_fixed = 1;
        }
        else if (!strcmp(argv[i], "--fft") && i + 1 < argc) {
            fft = (size_t)strtoul(argv[++i], NULL, 10);
        }
        else if (!strcmp(argv[i], "--hop") && i + 1 < argc) {
            hop = (size_t)strtoul(argv[++i], NULL, 10);
        }
        else if (!strcmp(argv[i], "--rate") && i + 1 < argc) {
            rate = (unsigned int)strtoul(argv[++i], NULL, 10);
        }
        else if (!strcmp(argv[i], "--channels") && i + 1 < argc) {
            channels = (unsigned int)strtoul(argv[++i], NULL, 10);
        }
        else if (!strcmp(argv[i], "--period") && i + 1 < argc) {
            period = (unsigned int)strtoul(argv[++i], NULL, 10);
        }
        else if (!strcmp(argv[i], "--target-dbfs") && i + 1 < argc) {
            if (parse_float(argv[++i], &level_config.target_dbfs) != 0) {
                fprintf(stderr, "Invalid --target-dbfs value\n"); return 1;
            }
        }
        else if (!strcmp(argv[i], "--max-gain-db") && i + 1 < argc) {
            if (parse_float(argv[++i], &level_config.max_gain_db) != 0) {
                fprintf(stderr, "Invalid --max-gain-db value\n"); return 1;
            }
        }
        else if (!strcmp(argv[i], "--ceiling-dbfs") && i + 1 < argc) {
            if (parse_float(argv[++i], &level_config.ceiling_dbfs) != 0) {
                fprintf(stderr, "Invalid --ceiling-dbfs value\n"); return 1;
            }
        }
        else if (!strcmp(argv[i], "--attack-ms") && i + 1 < argc) {
            if (parse_float(argv[++i], &level_config.attack_ms) != 0) {
                fprintf(stderr, "Invalid --attack-ms value\n"); return 1;
            }
        }
        else if (!strcmp(argv[i], "--release-ms") && i + 1 < argc) {
            if (parse_float(argv[++i], &level_config.release_ms) != 0) {
                fprintf(stderr, "Invalid --release-ms value\n"); return 1;
            }
        }
        else if (!strcmp(argv[i], "--limiter-release-ms") && i + 1 < argc) {
            if (parse_float(argv[++i], &level_config.limiter_release_ms) != 0) {
                fprintf(stderr, "Invalid --limiter-release-ms value\n"); return 1;
            }
        }
        else if (!strcmp(argv[i], "--no-agc")) {
            level_config.agc_enabled = 0;
        }
        else if (!strcmp(argv[i], "--drive") && i + 1 < argc) {
            if (parse_float(argv[++i], &drive) != 0) {
                fprintf(stderr, "Invalid --drive value\n"); return 1;
            }
            have_drive = 1;
        }
        else if (!strcmp(argv[i], "--ring-amount") && i + 1 < argc) {
            if (parse_float(argv[++i], &ring_amount) != 0) {
                fprintf(stderr, "Invalid --ring-amount value\n"); return 1;
            }
            have_ring_amount = 1;
        }
        else if (!strcmp(argv[i], "--ring-hz") && i + 1 < argc) {
            if (parse_float(argv[++i], &ring_hz) != 0) {
                fprintf(stderr, "Invalid --ring-hz value\n"); return 1;
            }
            have_ring_hz = 1;
        }
        else if (!strcmp(argv[i], "--denoise")) {
            denoise_enabled = 1;
        }
        else if (!strcmp(argv[i], "--noise-profile") && i + 1 < argc) {
            noise_profile = argv[++i];
            denoise_option = 1;
        }
        else if (!strcmp(argv[i], "--noise-save") && i + 1 < argc) {
            noise_save = argv[++i];
            denoise_option = 1;
        }
        else if (!strcmp(argv[i], "--noise-learn-ms") && i + 1 < argc) {
            if (parse_float(argv[++i], &denoise_params.learn_ms) != 0) {
                fprintf(stderr, "Invalid --noise-learn-ms value\n"); return 1;
            }
            denoise_option = 1;
        }
        else if (!strcmp(argv[i], "--noise-reduction") && i + 1 < argc) {
            if (parse_float(argv[++i], &denoise_params.reduction) != 0) {
                fprintf(stderr, "Invalid --noise-reduction value\n"); return 1;
            }
            denoise_option = 1;
        }
        else if (!strcmp(argv[i], "--noise-floor-db") && i + 1 < argc) {
            if (parse_float(argv[++i], &denoise_params.floor_db) != 0) {
                fprintf(stderr, "Invalid --noise-floor-db value\n"); return 1;
            }
            denoise_option = 1;
        }
        else if (!strcmp(argv[i], "--noise-gate-snr-db") && i + 1 < argc) {
            if (parse_float(argv[++i], &denoise_params.gate_snr_db) != 0) {
                fprintf(stderr, "Invalid --noise-gate-snr-db value\n"); return 1;
            }
            denoise_option = 1;
        }
        else if (!strcmp(argv[i], "--noise-gate-range-db") && i + 1 < argc) {
            if (parse_float(argv[++i], &denoise_params.gate_range_db) != 0) {
                fprintf(stderr, "Invalid --noise-gate-range-db value\n"); return 1;
            }
            denoise_option = 1;
        }
        else if (!strcmp(argv[i], "--ring-wave") && i + 1 < argc) {
            ++i;
            if (!strcmp(argv[i], "sine")) ring_wave = VC_RING_WAVE_SINE;
            else if (!strcmp(argv[i], "square")) ring_wave = VC_RING_WAVE_SQUARE;
            else { fprintf(stderr, "Unknown --ring-wave: %s\n", argv[i]); return 1; }
            have_ring_wave = 1;
        }
        else { fprintf(stderr, "Unknown option: %s\n", argv[i]); return 1; }
    }

    if (have_fixed &&
        (semis < VC_RT_MIN_SEMITONES || semis > VC_RT_MAX_SEMITONES ||
         formant < VC_RT_MIN_FORMANT_FACTOR ||
         formant > VC_RT_MAX_FORMANT_FACTOR ||
         scramble < 0.0f || scramble > VC_RT_MAX_SCRAMBLE_INTENSITY)) {
        fprintf(stderr, "Fixed voice settings out of range\n");
        return 1;
    }

    vc_rt_params_t p = {0};
    if (preset_name) {
        if (have_fixed || mode_specified) {
            fprintf(stderr, "--preset cannot be combined with --mode/voice transform options\n");
            return 1;
        }
        vc_preset_t preset;
        if (vc_preset_lookup(preset_name, &preset) != 0) {
            fprintf(stderr, "Unknown preset: %s\n", preset_name);
            return 1;
        }
        p = preset.cloak;
        effect_params = preset.effects;
        eq_params = preset.eq;
        level_config.saturation_drive = preset.saturation_drive;
    } else if (resolve_params(have_fixed, semis, formant, scramble,
                              witness, &p) != 0) {
        return 1;
    }
    if (have_drive) level_config.saturation_drive = drive;

    if (have_ring_amount || have_ring_hz || have_ring_wave) {
        if (effect_params.kind == VC_EFFECT_NONE) {
            if (!have_ring_amount || !have_ring_hz) {
                fprintf(stderr, "A plain ring effect needs --ring-amount and --ring-hz\n");
                return 1;
            }
            effect_params.kind = VC_EFFECT_RING_MOD;
        } else if (effect_params.kind != VC_EFFECT_RING_MOD &&
                   effect_params.kind != VC_EFFECT_METALLIC) {
            fprintf(stderr, "Ring options are not supported by this preset effect\n");
            return 1;
        }
        if (have_ring_amount) effect_params.ring_amount = ring_amount;
        if (have_ring_hz) effect_params.rate_hz = ring_hz;
        if (have_ring_wave) effect_params.waveform = ring_wave;
    }

    /* Validate the sample-domain stages before any device is opened. */
    {
        vc_effects_t *fx_probe = vc_effects_create(rate, &effect_params);
        vc_eq_t *eq_probe = vc_eq_create(rate, &eq_params);
        vc_level_t *level_probe = vc_level_create(rate, &level_config);
        int valid = fx_probe && eq_probe && level_probe;
        vc_effects_destroy(fx_probe);
        vc_eq_destroy(eq_probe);
        vc_level_destroy(level_probe);
        if (!valid) {
            fprintf(stderr, "Effect, ring, drive, or level settings out of range\n");
            return 1;
        }
    }

    if (denoise_option && !denoise_enabled) {
        fprintf(stderr, "--noise-* options require --denoise\n");
        return 1;
    }
    vc_denoise_t *denoise = NULL;
    if (denoise_enabled) {
        denoise = vc_denoise_create(fft / 2 + 1, &denoise_params);
        if (!denoise) {
            fprintf(stderr, "Noise reduction settings out of range\n");
            return 1;
        }
        if (noise_profile && vc_denoise_load(denoise, noise_profile) != 0) {
            fprintf(stderr, "Invalid noise profile: %s (fft size and format must match)\n",
                    noise_profile);
            vc_denoise_destroy(denoise);
            return 1;
        }
    }

    vc_rt_ctx_t *ctx = vc_rt_create(fft / 2 + 1, p);
    if (!ctx) {
        fprintf(stderr, "live: engine context alloc failed\n");
        vc_denoise_destroy(denoise);
        return 1;
    }
    vc_spectral_chain_t chain;
    vc_spectral_chain_init(&chain);
    if ((denoise && vc_spectral_chain_add(&chain, vc_denoise_transform,
                                          denoise) != 0) ||
        vc_spectral_chain_add(&chain, vc_rt_transform, ctx) != 0) {
        fprintf(stderr, "live: spectral chain setup failed\n");
        vc_rt_destroy(ctx);
        vc_denoise_destroy(denoise);
        return 1;
    }

    printf("Mode: %s | pitch x%.3f | formant x%.3f | scramble %.3f\n",
           preset_name ? preset_name :
           (have_fixed ? "fixed" : (witness ? "witness" : "subtle")),
           (double)p.pitch_ratio, (double)p.formant_factor,
           (double)p.scramble_intensity);
    printf("Level: AGC %s | target %.1f dBFS | max gain +%.1f dB | ceiling %.1f dBFS\n",
           level_config.agc_enabled ? "on" : "off",
           (double)level_config.target_dbfs,
           (double)level_config.max_gain_db,
           (double)level_config.ceiling_dbfs);
    printf("Tone: drive %.2f | high-pass %.0f Hz | presence %+.1f dB @ %.0f Hz\n",
           (double)level_config.saturation_drive, (double)eq_params.highpass_hz,
           (double)eq_params.presence_gain_db, (double)eq_params.presence_hz);
    if (denoise && !vc_denoise_is_ready(denoise))
        printf("Noise reduction: learning the noise print for %.0f ms, stay silent "
               "(output muted meanwhile)\n", (double)denoise_params.learn_ms);
    else if (denoise)
        printf("Noise reduction: profile loaded from %s\n", noise_profile);
    if (p.robotize && hop > 0U)
        printf("Robot pitch: %.2f Hz (rate / hop, set by --rate and --hop)\n",
               (double)rate / (double)hop);

    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = on_sigint;
    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);

    vc_alsa_cfg_t cfg;
    memset(&cfg, 0, sizeof(cfg));
    cfg.capture_dev   = cap_dev;
    cfg.playback_dev  = play_dev;
    cfg.rate          = rate;
    cfg.channels      = channels;
    cfg.period_frames = period;
    cfg.fft_size      = fft;
    cfg.hop_size      = hop;
    cfg.fn            = vc_spectral_chain_run;
    cfg.user          = &chain;
    cfg.effect_params = effect_params;
    cfg.eq_params     = eq_params;
    cfg.level_config  = level_config;
    cfg.stop          = &g_stop;

    int rc = vc_alsa_run(&cfg);
    if (noise_save) {
        if (vc_denoise_save(denoise, noise_save) == 0)
            printf("\nNoise print saved to %s\n", noise_save);
        else
            fprintf(stderr, "\nNoise print not saved (not learned yet or write error)\n");
    }
    vc_rt_destroy(ctx);
    vc_denoise_destroy(denoise);
    printf("\nStopped.\n");
    return rc == 0 ? 0 : 1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) { print_usage(argv[0]); return 1; }
    if (!strcmp(argv[1], "list")) return vc_alsa_list();
    if (!strcmp(argv[1], "selftest")) return cmd_selftest();
    if (!strcmp(argv[1], "live")) return cmd_live(argc, argv);
    if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
        print_usage(argv[0]); return 0;
    }
    fprintf(stderr, "Unknown command: %s\n", argv[1]);
    print_usage(argv[0]);
    return 1;
}
