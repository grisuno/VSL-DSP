/**
 * @brief PNGTuber avatar: ALSA capture -> 3-state mouth -> SDL2 window.
 *
 * Capture-only. Never claims HID/USB, never writes DSP. Run from the
 * repository root so img/ paths resolve. VoiceCloak route: point -D
 * at the virtual PCM voicecloak-rt writes to (pulse / Loopback).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <signal.h>
#include <getopt.h>
#include <alsa/asoundlib.h>
#include <SDL.h>
#include <SDL_image.h>

#include "avatar_config.h"
#include "avatar_logic.h"

static volatile sig_atomic_t g_stop = 0;

static void on_sigint(int sig)
{
    (void)sig;
    g_stop = 1;
}

static void usage(const char *argv0)
{
    fprintf(stdout,
            "Usage: %s [-D pcm] [--silence DB] [--zcr F] [--hf F] [--hold MS] [--list] [--no-gui]\n"
            "\n"
            "  -D pcm        ALSA capture device (default %s, fallback %s)\n"
            "  --silence DB  silence ceiling dBFS (default %.1f)\n"
            "  --zcr F       sibilant ZCR gate (default %.2f)\n"
            "  --hf F        sibilant HF gate (default %.2f)\n"
            "  --hold MS     release hold for CLOSED in ms (default %u)\n"
            "  --list        list ALSA PCMs and exit\n"
            "  --no-gui      print CLOSED|OPEN|SIBILANT per frame, no window\n"
            "\n"
            "Images (repo root relative):\n"
            "  closed   %s\n"
            "  open     %s\n"
            "  sibilant %s\n",
            argv0, AVATAR_DEFAULT_PCM, AVATAR_FALLBACK_PCM,
            (double)AVATAR_DEFAULT_SILENCE_DB,
            (double)AVATAR_DEFAULT_ZCR_THR, (double)AVATAR_DEFAULT_HF_THR,
            AVATAR_DEFAULT_HOLD_MS,
            AVATAR_IMG_CLOSED, AVATAR_IMG_OPEN, AVATAR_IMG_SIBILANT);
}

static int list_pcms(void)
{
    void **hints = NULL;
    void **it = NULL;

    if (snd_device_name_hint(-1, "pcm", &hints) < 0) {
        fprintf(stderr, "avatar: cannot list PCMs\n");
        return -1;
    }
    for (it = hints; *it != NULL; it++) {
        char *name = snd_device_name_get_hint(*it, "NAME");
        char *desc = snd_device_name_get_hint(*it, "DESC");
        if (name != NULL) {
            fprintf(stdout, "%s%s%s\n", name, desc != NULL ? " - " : "",
                    desc != NULL ? desc : "");
            free(name);
        }
        if (desc != NULL) {
            free(desc);
        }
    }
    snd_device_name_free_hint(hints);
    return 0;
}

static const char *env_or(const char *name, const char *fallback)
{
    const char *v = getenv(name);
    return (v != NULL && v[0] != '\0') ? v : fallback;
}

static snd_pcm_t *open_capture(const char *dev, unsigned int rate,
                               unsigned int *got_rate, unsigned int *got_ch,
                               snd_pcm_format_t *got_fmt)
{
    static const snd_pcm_format_t candidates[] = {
        SND_PCM_FORMAT_S32_LE, SND_PCM_FORMAT_S16_LE, SND_PCM_FORMAT_FLOAT_LE
    };
    snd_pcm_t *pcm = NULL;
    snd_pcm_hw_params_t *hw = NULL;
    size_t i;
    int err;

    err = snd_pcm_open(&pcm, dev, SND_PCM_STREAM_CAPTURE, 0);
    if (err < 0) {
        fprintf(stderr, "avatar: cannot open capture '%s': %s\n", dev,
                snd_strerror(err));
        return NULL;
    }
    snd_pcm_hw_params_alloca(&hw);
    snd_pcm_hw_params_any(pcm, hw);
    if (snd_pcm_hw_params_set_access(pcm, hw, SND_PCM_ACCESS_RW_INTERLEAVED) < 0) {
        fprintf(stderr, "avatar: '%s' no interleaved access\n", dev);
        snd_pcm_close(pcm);
        return NULL;
    }
    *got_fmt = SND_PCM_FORMAT_UNKNOWN;
    for (i = 0U; i < sizeof(candidates) / sizeof(candidates[0]); i++) {
        if (snd_pcm_hw_params_set_format(pcm, hw, candidates[i]) == 0) {
            *got_fmt = candidates[i];
            break;
        }
    }
    if (*got_fmt == SND_PCM_FORMAT_UNKNOWN) {
        fprintf(stderr, "avatar: '%s' no supported sample format\n", dev);
        snd_pcm_close(pcm);
        return NULL;
    }
    *got_ch = 1U;
    if (snd_pcm_hw_params_set_channels_near(pcm, hw, got_ch) < 0) {
        fprintf(stderr, "avatar: '%s' cannot set channels\n", dev);
        snd_pcm_close(pcm);
        return NULL;
    }
    *got_rate = rate;
    if (snd_pcm_hw_params_set_rate_near(pcm, hw, got_rate, 0) < 0) {
        fprintf(stderr, "avatar: '%s' cannot set rate\n", dev);
        snd_pcm_close(pcm);
        return NULL;
    }
    {
        snd_pcm_uframes_t period = AVATAR_FRAME_SAMPLES;
        if (snd_pcm_hw_params_set_period_size_near(pcm, hw, &period, 0) < 0) {
            fprintf(stderr, "avatar: '%s' cannot set period\n", dev);
            snd_pcm_close(pcm);
            return NULL;
        }
    }
    if (snd_pcm_hw_params(pcm, hw) < 0) {
        fprintf(stderr, "avatar: '%s' cannot apply hw params\n", dev);
        snd_pcm_close(pcm);
        return NULL;
    }
    if (snd_pcm_prepare(pcm) < 0) {
        fprintf(stderr, "avatar: '%s' cannot prepare\n", dev);
        snd_pcm_close(pcm);
        return NULL;
    }
    return pcm;
}

/** @brief Convert one interleaved period to mono float, explicit clamp. */
static void to_mono_f32(const uint8_t *raw, float *out, size_t frames,
                        unsigned int ch, snd_pcm_format_t fmt)
{
    size_t f;
    size_t c;

    for (f = 0U; f < frames; f++) {
        double acc = 0.0;
        for (c = 0U; c < ch; c++) {
            size_t idx = f * ch + c;
            double v = 0.0;
            if (fmt == SND_PCM_FORMAT_S16_LE) {
                int16_t s;
                memcpy(&s, raw + (idx * sizeof(int16_t)), sizeof(int16_t));
                v = (double)s / 32768.0;
            } else if (fmt == SND_PCM_FORMAT_S32_LE) {
                int32_t s;
                memcpy(&s, raw + (idx * sizeof(int32_t)), sizeof(int32_t));
                v = (double)s / 2147483648.0;
            } else {
                float s;
                memcpy(&s, raw + (idx * sizeof(float)), sizeof(float));
                v = isfinite((double)s) ? (double)s : 0.0;
            }
            if (v > 1.0) {
                v = 1.0;
            } else if (v < -1.0) {
                v = -1.0;
            }
            acc += v;
        }
        out[f] = (float)(acc / (double)(ch == 0U ? 1U : ch));
    }
}

int main(int argc, char **argv)
{
    const char *pcm_name = env_or("AVATAR_PCM", AVATAR_DEFAULT_PCM);
    const char *img_closed = env_or("AVATAR_IMG_CLOSED", AVATAR_IMG_CLOSED);
    const char *img_open = env_or("AVATAR_IMG_OPEN", AVATAR_IMG_OPEN);
    const char *img_sib = env_or("AVATAR_IMG_SIBILANT", AVATAR_IMG_SIBILANT);
    avatar_cfg_t cfg = {
        .silence_db = AVATAR_DEFAULT_SILENCE_DB,
        .zcr_thr = AVATAR_DEFAULT_ZCR_THR,
        .hf_thr = AVATAR_DEFAULT_HF_THR,
        .hold_ms = AVATAR_DEFAULT_HOLD_MS
    };
    int no_gui = 0;
    int opt;
    int long_idx = 0;
    static struct option longs[] = {
        { "silence", required_argument, NULL, 's' },
        { "zcr", required_argument, NULL, 'z' },
        { "hf", required_argument, NULL, 'f' },
        { "hold", required_argument, NULL, 'h' },
        { "list", no_argument, NULL, 'l' },
        { "no-gui", no_argument, NULL, 'n' },
        { "help", no_argument, NULL, '?' },
        { NULL, 0, NULL, 0 }
    };

    while ((opt = getopt_long(argc, argv, "D:", longs, &long_idx)) != -1) {
        switch (opt) {
        case 'D':
            pcm_name = optarg;
            break;
        case 's':
            cfg.silence_db = strtof(optarg, NULL);
            break;
        case 'z':
            cfg.zcr_thr = strtof(optarg, NULL);
            break;
        case 'f':
            cfg.hf_thr = strtof(optarg, NULL);
            break;
        case 'h':
            cfg.hold_ms = (unsigned int)strtoul(optarg, NULL, 10);
            break;
        case 'l':
            return list_pcms() == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
        case 'n':
            no_gui = 1;
            break;
        default:
            usage(argv[0]);
            return EXIT_FAILURE;
        }
    }
    if (!isfinite((double)cfg.silence_db) || !isfinite((double)cfg.zcr_thr) ||
        !isfinite((double)cfg.hf_thr)) {
        fprintf(stderr, "avatar: non-finite threshold rejected\n");
        return EXIT_FAILURE;
    }

    signal(SIGINT, on_sigint);
    signal(SIGTERM, on_sigint);

    {
        snd_pcm_t *pcm = NULL;
        unsigned int rate = AVATAR_DEFAULT_RATE;
        unsigned int got_rate = 0U;
        unsigned int got_ch = 0U;
        snd_pcm_format_t fmt = SND_PCM_FORMAT_UNKNOWN;
        size_t bps = 0U;
        uint8_t *raw = NULL;
        float *mono = NULL;
        size_t raw_bytes;
        avatar_smooth_t sm;
        SDL_Window *win = NULL;
        SDL_Renderer *ren = NULL;
        SDL_Texture *tex[3] = { NULL, NULL, NULL };
        const char *paths[3];
        avatar_state_t shown = AVATAR_CLOSED;
        int tried_fallback = 0;

        pcm = open_capture(pcm_name, rate, &got_rate, &got_ch, &fmt);
        if (pcm == NULL && strcmp(pcm_name, AVATAR_FALLBACK_PCM) != 0) {
            tried_fallback = 1;
            fprintf(stderr, "avatar: trying fallback '%s'\n", AVATAR_FALLBACK_PCM);
            pcm = open_capture(AVATAR_FALLBACK_PCM, rate, &got_rate, &got_ch, &fmt);
        }
        if (pcm == NULL) {
            if (!tried_fallback) {
                fprintf(stderr, "avatar: no capture device; run --list\n");
            }
            return EXIT_FAILURE;
        }
        if (fmt == SND_PCM_FORMAT_S16_LE) {
            bps = sizeof(int16_t);
        } else if (fmt == SND_PCM_FORMAT_S32_LE) {
            bps = sizeof(int32_t);
        } else {
            bps = sizeof(float);
        }
        raw_bytes = (size_t)AVATAR_FRAME_SAMPLES * (size_t)got_ch * bps;
        raw = (uint8_t *)calloc(1U, raw_bytes);
        mono = (float *)calloc((size_t)AVATAR_FRAME_SAMPLES, sizeof(float));
        if (raw == NULL || mono == NULL) {
            fprintf(stderr, "avatar: out of memory\n");
            free(raw);
            free(mono);
            snd_pcm_close(pcm);
            return EXIT_FAILURE;
        }

        avatar_smooth_init(&sm, AVATAR_CLOSED, 0U, cfg.hold_ms);

        paths[AVATAR_CLOSED] = img_closed;
        paths[AVATAR_OPEN] = img_open;
        paths[AVATAR_SIBILANT] = img_sib;

        if (!no_gui) {
            size_t k;
            if (SDL_Init(SDL_INIT_VIDEO) != 0) {
                fprintf(stderr, "avatar: SDL_Init: %s\n", SDL_GetError());
                free(raw);
                free(mono);
                snd_pcm_close(pcm);
                return EXIT_FAILURE;
            }
            if ((IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) & (IMG_INIT_PNG | IMG_INIT_JPG)) == 0) {
                fprintf(stderr, "avatar: IMG_Init: %s\n", IMG_GetError());
                SDL_Quit();
                free(raw);
                free(mono);
                snd_pcm_close(pcm);
                return EXIT_FAILURE;
            }
            win = SDL_CreateWindow("avatar - CLOSED", SDL_WINDOWPOS_CENTERED,
                                   SDL_WINDOWPOS_CENTERED, AVATAR_WIN_W,
                                   AVATAR_WIN_H, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
            if (win == NULL) {
                fprintf(stderr, "avatar: window: %s\n", SDL_GetError());
                IMG_Quit();
                SDL_Quit();
                free(raw);
                free(mono);
                snd_pcm_close(pcm);
                return EXIT_FAILURE;
            }
            ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (ren == NULL) {
                fprintf(stderr, "avatar: renderer: %s\n", SDL_GetError());
                SDL_DestroyWindow(win);
                IMG_Quit();
                SDL_Quit();
                free(raw);
                free(mono);
                snd_pcm_close(pcm);
                return EXIT_FAILURE;
            }
            for (k = 0U; k < 3U; k++) {
                SDL_Surface *sf = IMG_Load(paths[k]);
                if (sf == NULL) {
                    fprintf(stderr, "avatar: cannot load '%s': %s\n", paths[k],
                            IMG_GetError());
                    SDL_DestroyRenderer(ren);
                    SDL_DestroyWindow(win);
                    IMG_Quit();
                    SDL_Quit();
                    free(raw);
                    free(mono);
                    snd_pcm_close(pcm);
                    return EXIT_FAILURE;
                }
                tex[k] = SDL_CreateTextureFromSurface(ren, sf);
                SDL_FreeSurface(sf);
                if (tex[k] == NULL) {
                    fprintf(stderr, "avatar: texture '%s': %s\n", paths[k],
                            SDL_GetError());
                    SDL_DestroyRenderer(ren);
                    SDL_DestroyWindow(win);
                    IMG_Quit();
                    SDL_Quit();
                    free(raw);
                    free(mono);
                    snd_pcm_close(pcm);
                    return EXIT_FAILURE;
                }
            }
        }

        fprintf(stderr, "avatar: capture '%s' rate=%u ch=%u frame=%u (Ctrl-C quits)\n",
                pcm_name, got_rate, got_ch, AVATAR_FRAME_SAMPLES);

        while (!g_stop) {
            snd_pcm_sframes_t n;
            float rms;
            float db;
            float zcr;
            float hf;
            avatar_state_t inst;
            avatar_state_t cur;
            uint64_t now_ms;

            if (!no_gui) {
                SDL_Event ev;
                while (SDL_PollEvent(&ev) != 0) {
                    if (ev.type == SDL_QUIT) {
                        g_stop = 1;
                    }
                }
                if (g_stop) {
                    break;
                }
            }

            n = snd_pcm_readi(pcm, raw, (snd_pcm_uframes_t)AVATAR_FRAME_SAMPLES);
            if (n == -EPIPE || n == -ESTRPIPE) {
                snd_pcm_recover(pcm, (int)n, 0);
                continue;
            }
            if (n < 0) {
                fprintf(stderr, "avatar: capture: %s\n", snd_strerror((int)n));
                break;
            }
            if (n == 0) {
                continue;
            }
            to_mono_f32(raw, mono, (size_t)n, got_ch, fmt);
            rms = avatar_rms_f32(mono, (size_t)n);
            db = avatar_rms_to_dbfs(rms);
            zcr = avatar_zcr_f32(mono, (size_t)n);
            hf = avatar_hf_ratio_f32(mono, (size_t)n);
            inst = avatar_classify(db, zcr, hf, &cfg);
            now_ms = no_gui ? 0U : (uint64_t)SDL_GetTicks64();
            if (no_gui) {
                static uint64_t tick = 0U;
                tick += 21U;
                now_ms = tick;
            }
            cur = avatar_smooth(&sm, inst, now_ms);

            if (no_gui) {
                fprintf(stdout, "%s rms=%.1f zcr=%.3f hf=%.3f\n",
                        avatar_state_name(cur), (double)db, (double)zcr,
                        (double)hf);
                fflush(stdout);
                continue;
            }
            if (cur != shown) {
                char title[64];
                shown = cur;
                snprintf(title, sizeof(title), "avatar - %s", avatar_state_name(shown));
                SDL_SetWindowTitle(win, title);
            }
            SDL_RenderClear(ren);
            SDL_RenderCopy(ren, tex[shown], NULL, NULL);
            SDL_RenderPresent(ren);
        }

        if (!no_gui) {
            size_t k;
            for (k = 0U; k < 3U; k++) {
                SDL_DestroyTexture(tex[k]);
            }
            SDL_DestroyRenderer(ren);
            SDL_DestroyWindow(win);
            IMG_Quit();
            SDL_Quit();
        }
        free(raw);
        free(mono);
        snd_pcm_close(pcm);
    }
    return EXIT_SUCCESS;
}
