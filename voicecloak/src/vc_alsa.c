#define _GNU_SOURCE

#include "vc_alsa.h"
#include "vc_stream.h"

#include <alloca.h>
#include <alsa/asoundlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    snd_pcm_t        *pcm;
    snd_pcm_format_t  fmt;
    unsigned int      channels;
    size_t            bps;   /* bytes per sample */
} vc_pcm_t;

static size_t fmt_bps(snd_pcm_format_t f) {
    switch (f) {
        case SND_PCM_FORMAT_S16_LE:   return 2;
        case SND_PCM_FORMAT_S32_LE:   return 4;
        case SND_PCM_FORMAT_FLOAT_LE: return 4;
        default:                      return 0;
    }
}

static int open_stream(vc_pcm_t *s, const char *dev, snd_pcm_stream_t dir,
                       unsigned int rate, unsigned int channels,
                       snd_pcm_uframes_t period, const char *tag) {
    static const snd_pcm_format_t candidates[] = {
        SND_PCM_FORMAT_S32_LE, SND_PCM_FORMAT_S16_LE, SND_PCM_FORMAT_FLOAT_LE
    };
    int err = snd_pcm_open(&s->pcm, dev, dir, 0);
    if (err < 0) {
        fprintf(stderr, "vc_alsa: cannot open %s device '%s': %s\n",
                tag, dev, snd_strerror(err));
        return -1;
    }

    snd_pcm_hw_params_t *hw;
    snd_pcm_hw_params_alloca(&hw);
    snd_pcm_hw_params_any(s->pcm, hw);

    if (snd_pcm_hw_params_set_access(s->pcm, hw,
                                     SND_PCM_ACCESS_RW_INTERLEAVED) < 0) {
        fprintf(stderr, "vc_alsa: %s no interleaved access\n", tag);
        return -1;
    }

    size_t i;
    int fmt_ok = -1;
    for (i = 0; i < sizeof(candidates) / sizeof(candidates[0]); ++i) {
        if (snd_pcm_hw_params_set_format(s->pcm, hw, candidates[i]) == 0) {
            s->fmt = candidates[i];
            fmt_ok = 0;
            break;
        }
    }
    if (fmt_ok < 0) {
        fprintf(stderr, "vc_alsa: %s no supported sample format\n", tag);
        return -1;
    }

    unsigned int ch = channels;
    if (snd_pcm_hw_params_set_channels_near(s->pcm, hw, &ch) < 0) {
        fprintf(stderr, "vc_alsa: %s cannot set channels\n", tag);
        return -1;
    }
    s->channels = ch;

    unsigned int r = rate;
    if (snd_pcm_hw_params_set_rate_near(s->pcm, hw, &r, 0) < 0) {
        fprintf(stderr, "vc_alsa: %s cannot set rate\n", tag);
        return -1;
    }

    snd_pcm_uframes_t p = period;
    if (snd_pcm_hw_params_set_period_size_near(s->pcm, hw, &p, 0) < 0) {
        fprintf(stderr, "vc_alsa: %s cannot set period\n", tag);
        return -1;
    }
    snd_pcm_uframes_t buffer = p * 4;
    snd_pcm_hw_params_set_buffer_size_near(s->pcm, hw, &buffer);

    if (snd_pcm_hw_params(s->pcm, hw) < 0) {
        fprintf(stderr, "vc_alsa: %s cannot apply hw params\n", tag);
        return -1;
    }

    s->bps = fmt_bps(s->fmt);
    fprintf(stderr, "vc_alsa: %s '%s' rate=%u ch=%u fmt=%s period=%lu\n",
            tag, dev, r, s->channels, snd_pcm_format_name(s->fmt),
            (unsigned long)p);
    return 0;
}

static void raw_to_mono(const unsigned char *raw, float *mono,
                        snd_pcm_uframes_t frames, const vc_pcm_t *s) {
    snd_pcm_uframes_t f;
    for (f = 0; f < frames; ++f) {
        const unsigned char *base = raw + (size_t)f * s->channels * s->bps;
        float v;
        switch (s->fmt) {
            case SND_PCM_FORMAT_S16_LE: {
                int16_t x;
                memcpy(&x, base, sizeof(x));
                v = (float)x / 32768.0f;
                break;
            }
            case SND_PCM_FORMAT_S32_LE: {
                int32_t x;
                memcpy(&x, base, sizeof(x));
                v = (float)((double)x / 2147483648.0);
                break;
            }
            case SND_PCM_FORMAT_FLOAT_LE: {
                memcpy(&v, base, sizeof(v));
                break;
            }
            default:
                v = 0.0f;
                break;
        }
        mono[f] = v;
    }
}

static void mono_to_raw(unsigned char *raw, const float *mono,
                        snd_pcm_uframes_t frames, const vc_pcm_t *s) {
    snd_pcm_uframes_t f;
    unsigned int c;
    for (f = 0; f < frames; ++f) {
        float v = mono[f];
        if (v >  1.0f) v =  1.0f;
        if (v < -1.0f) v = -1.0f;
        unsigned char *base = raw + (size_t)f * s->channels * s->bps;
        for (c = 0; c < s->channels; ++c) {
            unsigned char *dst = base + (size_t)c * s->bps;
            switch (s->fmt) {
                case SND_PCM_FORMAT_S16_LE: {
                    int16_t x = (int16_t)lrintf(v * 32767.0f);
                    memcpy(dst, &x, sizeof(x));
                    break;
                }
                case SND_PCM_FORMAT_S32_LE: {
                    int32_t x = (int32_t)lrint((double)v * 2147483647.0);
                    memcpy(dst, &x, sizeof(x));
                    break;
                }
                case SND_PCM_FORMAT_FLOAT_LE: {
                    memcpy(dst, &v, sizeof(v));
                    break;
                }
                default:
                    break;
            }
        }
    }
}

int vc_alsa_list(void) {
    void **hints = NULL;
    if (snd_device_name_hint(-1, "pcm", &hints) < 0) {
        fprintf(stderr, "vc_alsa: cannot enumerate PCM devices\n");
        return -1;
    }
    printf("Available ALSA PCM devices:\n");
    void **h;
    for (h = hints; *h != NULL; ++h) {
        char *name = snd_device_name_get_hint(*h, "NAME");
        char *desc = snd_device_name_get_hint(*h, "DESC");
        char *ioid = snd_device_name_get_hint(*h, "IOID");
        if (name) {
            printf("  %-24s [%s]\n", name, ioid ? ioid : "Duplex");
            if (desc) {
                char *nl = strchr(desc, '\n');
                if (nl) *nl = '\0';
                printf("      %s\n", desc);
            }
        }
        free(name); free(desc); free(ioid);
    }
    snd_device_name_free_hint(hints);
    return 0;
}

int vc_alsa_run(const vc_alsa_cfg_t *cfg) {
    if (!cfg || !cfg->capture_dev || !cfg->playback_dev || !cfg->stop)
        return -1;

    vc_pcm_t cap = {0}, play = {0};
    int rc = -1;
    unsigned char *raw_in = NULL, *raw_out = NULL;
    float *mono_in = NULL, *mono_out = NULL;
    vc_stream_t *st = NULL;

    if (open_stream(&cap, cfg->capture_dev, SND_PCM_STREAM_CAPTURE,
                    cfg->rate, cfg->channels, cfg->period_frames, "capture") < 0)
        goto done;
    if (open_stream(&play, cfg->playback_dev, SND_PCM_STREAM_PLAYBACK,
                    cfg->rate, cfg->channels, cfg->period_frames, "playback") < 0)
        goto done;

    unsigned int neg_rate = 0;
    int dir = 0;
    {
        snd_pcm_hw_params_t *hw;
        snd_pcm_hw_params_alloca(&hw);
        snd_pcm_hw_params_current(cap.pcm, hw);
        snd_pcm_hw_params_get_rate(hw, &neg_rate, &dir);
    }
    if (neg_rate == 0) neg_rate = cfg->rate;

    st = vc_stream_create(cfg->fft_size, cfg->hop_size, neg_rate);
    if (!st) {
        fprintf(stderr, "vc_alsa: invalid engine config\n");
        goto done;
    }

    snd_pcm_uframes_t period = cfg->period_frames;
    raw_in   = (unsigned char *)malloc((size_t)period * cap.channels * cap.bps);
    raw_out  = (unsigned char *)malloc((size_t)period * play.channels * play.bps);
    mono_in  = (float *)malloc((size_t)period * sizeof(float));
    mono_out = (float *)malloc((size_t)period * sizeof(float));
    if (!raw_in || !raw_out || !mono_in || !mono_out) {
        fprintf(stderr, "vc_alsa: out of memory\n");
        goto done;
    }

    snd_pcm_prepare(cap.pcm);
    snd_pcm_prepare(play.pcm);

    /* Prime playback with one period of silence to build a buffer margin. */
    memset(raw_out, 0, (size_t)period * play.channels * play.bps);
    snd_pcm_writei(play.pcm, raw_out, period);

    snd_pcm_start(cap.pcm);

    fprintf(stderr, "vc_alsa: running (latency %zu samples). Ctrl-C to stop.\n",
            vc_stream_latency_samples(st));

    while (!*cfg->stop) {
        snd_pcm_sframes_t got = snd_pcm_readi(cap.pcm, raw_in, period);
        if (got < 0) {
            got = snd_pcm_recover(cap.pcm, (int)got, 1);
            if (got < 0) {
                fprintf(stderr, "vc_alsa: capture error: %s\n",
                        snd_strerror((int)got));
                break;
            }
            continue;
        }
        snd_pcm_uframes_t frames = (snd_pcm_uframes_t)got;

        raw_to_mono(raw_in, mono_in, frames, &cap);
        vc_stream_process(st, mono_in, mono_out, (size_t)frames,
                          cfg->fn, cfg->user);
        mono_to_raw(raw_out, mono_out, frames, &play);

        snd_pcm_uframes_t written = 0;
        while (written < frames) {
            snd_pcm_sframes_t w = snd_pcm_writei(
                play.pcm,
                raw_out + (size_t)written * play.channels * play.bps,
                frames - written);
            if (w < 0) {
                w = snd_pcm_recover(play.pcm, (int)w, 1);
                if (w < 0) {
                    fprintf(stderr, "vc_alsa: playback error: %s\n",
                            snd_strerror((int)w));
                    goto stop_loop;
                }
                continue;
            }
            written += (snd_pcm_uframes_t)w;
        }
    }
stop_loop:
    rc = 0;

done:
    if (cap.pcm)  { snd_pcm_drop(cap.pcm); snd_pcm_close(cap.pcm); }
    if (play.pcm) { snd_pcm_drain(play.pcm); snd_pcm_close(play.pcm); }
    vc_stream_destroy(st);
    free(raw_in); free(raw_out); free(mono_in); free(mono_out);
    return rc;
}
