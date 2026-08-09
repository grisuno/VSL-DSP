#define _POSIX_C_SOURCE 200809L

#include "vc_alsa.h"
#include "vc_stream.h"
#include "vc_rt.h"
#include "vc_fft.h"
#include "vc_crypto.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

static volatile sig_atomic_t g_stop = 0;

static void on_sigint(int sig) {
    (void)sig;
    g_stop = 1;
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
        "  --semitones N  Fixed pitch shift in semitones (overrides mode)\n"
        "  --formant F    Fixed formant factor (0.3-3.0, overrides mode)\n"
        "  --scramble S   Fixed scramble intensity (0.0-1.0, overrides mode)\n"
        "  --fft N        FFT size, power of two (default 1024)\n"
        "  --hop N        Hop size, fft/hop in {2,4} (default 256)\n"
        "  --rate R       Requested sample rate (default 48000)\n"
        "  --channels C   Requested channel count (default 2)\n"
        "  --period P     ALSA period in frames (default 256)\n"
        "\n"
        "Examples:\n"
        "  %s list\n"
        "  %s selftest\n"
        "  %s live -D hw:VSL -P hw:VSL --mode witness\n"
        "  %s live -D hw:VSL -P hw:VSL --semitones 7 --formant 1.3\n",
        prog, prog, prog, prog, prog);
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
    vc_rt_params_t p = { ratio, 1.0f, 0.0f };
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
    int witness = 0, have_fixed = 0;
    float semis = 0.0f, formant = 1.0f, scramble = 0.0f;
    size_t fft = 1024, hop = 256;
    unsigned int rate = 48000, channels = 2, period = 256;

    int i;
    for (i = 2; i < argc; ++i) {
        if (!strcmp(argv[i], "-D") && i + 1 < argc) cap_dev = argv[++i];
        else if (!strcmp(argv[i], "-P") && i + 1 < argc) play_dev = argv[++i];
        else if (!strcmp(argv[i], "--mode") && i + 1 < argc) {
            ++i;
            if (!strcmp(argv[i], "witness")) witness = 1;
            else if (!strcmp(argv[i], "subtle")) witness = 0;
            else { fprintf(stderr, "Unknown mode: %s\n", argv[i]); return 1; }
        }
        else if (!strcmp(argv[i], "--semitones") && i + 1 < argc) {
            semis = (float)atof(argv[++i]); have_fixed = 1;
        }
        else if (!strcmp(argv[i], "--formant") && i + 1 < argc) {
            formant = (float)atof(argv[++i]); have_fixed = 1;
        }
        else if (!strcmp(argv[i], "--scramble") && i + 1 < argc) {
            scramble = (float)atof(argv[++i]); have_fixed = 1;
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
        else { fprintf(stderr, "Unknown option: %s\n", argv[i]); return 1; }
    }

    vc_rt_params_t p;
    if (resolve_params(have_fixed, semis, formant, scramble, witness, &p) != 0)
        return 1;

    vc_rt_ctx_t *ctx = vc_rt_create(fft / 2 + 1, p);
    if (!ctx) { fprintf(stderr, "live: engine context alloc failed\n"); return 1; }

    printf("Mode: %s | pitch x%.3f | formant x%.3f | scramble %.3f\n",
           have_fixed ? "fixed" : (witness ? "witness" : "subtle"),
           (double)p.pitch_ratio, (double)p.formant_factor,
           (double)p.scramble_intensity);

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
    cfg.fn            = vc_rt_transform;
    cfg.user          = ctx;
    cfg.stop          = &g_stop;

    int rc = vc_alsa_run(&cfg);
    vc_rt_destroy(ctx);
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
