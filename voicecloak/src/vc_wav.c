#include "vc_wav.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    char     riff[4];
    uint32_t file_size;
    char     wave[4];
} WavHeader;

typedef struct {
    uint16_t audio_format;
    uint16_t num_channels;
    uint32_t sample_rate;
    uint32_t byte_rate;
    uint16_t block_align;
    uint16_t bits_per_sample;
} WavFmtBody;

typedef struct {
    char     id[4];
    uint32_t size;
} WavDataChunk;
#pragma pack(pop)

static int read_bytes(FILE *fp, void *buf, size_t n) {
    return fread(buf, 1, n, fp) == n ? 0 : -1;
}

static int write_bytes(FILE *fp, const void *buf, size_t n) {
    return fwrite(buf, 1, n, fp) == n ? 0 : -1;
}

static float sample_to_float(const unsigned char *p, int bps) {
    if (bps == 8) {
        return ((float)((int)p[0]) - 128.0f) / 128.0f;
    }
    if (bps == 16) {
        int16_t v;
        memcpy(&v, p, 2);
        return (float)v / 32768.0f;
    }
    if (bps == 24) {
        int32_t v = 0;
        v |= (int32_t)p[0];
        v |= (int32_t)p[1] << 8;
        v |= (int32_t)((int8_t)p[2]) << 16;
        return (float)v / 8388608.0f;
    }
    if (bps == 32) {
        int32_t v;
        memcpy(&v, p, 4);
        return (float)v / 2147483648.0f;
    }
    return 0.0f;
}

static void float_to_sample(float f, unsigned char *p, int bps) {
    float clamped = fmaxf(-1.0f, fminf(f, 1.0f));
    if (bps == 16) {
        int16_t v = (int16_t)(clamped * 32767.0f);
        memcpy(p, &v, 2);
    } else if (bps == 24) {
        int32_t v = (int32_t)(clamped * 8388607.0f);
        p[0] = (unsigned char)(v & 0xFF);
        p[1] = (unsigned char)((v >> 8) & 0xFF);
        p[2] = (unsigned char)((v >> 16) & 0xFF);
    } else if (bps == 32) {
        int32_t v = (int32_t)(clamped * 2147483647.0f);
        memcpy(p, &v, 4);
    }
}

static int find_chunk(FILE *fp, const char *id, uint32_t *size) {
    char buf[4];
    uint32_t sz;
    while (1) {
        if (read_bytes(fp, buf, 4) != 0) return -1;
        if (read_bytes(fp, &sz, 4) != 0) return -1;
        if (memcmp(buf, id, 4) == 0) {
            if (memcmp(id, "data", 4) == 0 && size) *size = sz;
            else if (size) *size = sz;
            return 0;
        }
        fseek(fp, (long)sz, SEEK_CUR);
    }
}

int vc_wav_read(const char *path,
                float **samples_out, size_t *num_samples_out,
                uint32_t *sample_rate_out) {
    FILE *fp = NULL;
    unsigned char *raw = NULL;
    float *out = NULL;
    size_t num_samples = 0;
    uint32_t sample_rate = 0;
    uint16_t num_channels = 0, bps = 0;
    uint32_t data_size = 0;

    fp = fopen(path, "rb");
    if (!fp) goto fail;

    WavHeader hdr;
    if (read_bytes(fp, &hdr, sizeof(hdr)) != 0) goto fail;
    if (memcmp(hdr.riff, "RIFF", 4) != 0 || memcmp(hdr.wave, "WAVE", 4) != 0)
        goto fail;

    uint32_t fmt_size;
    if (find_chunk(fp, "fmt ", &fmt_size) != 0) goto fail;
    if (fmt_size < 16) goto fail;

    WavFmtBody fmt;
    memset(&fmt, 0, sizeof(fmt));
    {
        size_t to_read = fmt_size < sizeof(fmt) ? fmt_size : sizeof(fmt);
        if (read_bytes(fp, &fmt, to_read) != 0) goto fail;
        if (fmt_size > sizeof(fmt))
            fseek(fp, (long)(fmt_size - sizeof(fmt)), SEEK_CUR);
    }
    if (fmt.audio_format != 1) goto fail; /* PCM only */

    num_channels = fmt.num_channels;
    sample_rate  = fmt.sample_rate;
    bps          = fmt.bits_per_sample;

    if (find_chunk(fp, "data", &data_size) != 0) goto fail;

    size_t bytes_per_sample = (size_t)(bps / 8);
    size_t total_frames     = data_size / (bytes_per_sample * (size_t)num_channels);
    num_samples = total_frames;

    raw = (unsigned char *)malloc(data_size);
    if (!raw) goto fail;
    if (read_bytes(fp, raw, data_size) != 0) goto fail;
    fclose(fp); fp = NULL;

    out = (float *)malloc(num_samples * sizeof(float));
    if (!out) goto fail;

    size_t i;
    for (i = 0; i < num_samples; ++i) {
        size_t frame_off = i * (size_t)num_channels * bytes_per_sample;
        float sum = 0.0f;
        size_t ch;
        for (ch = 0; ch < (size_t)num_channels; ++ch) {
            size_t off = frame_off + ch * bytes_per_sample;
            sum += sample_to_float(raw + off, (int)bps);
        }
        out[i] = sum / (float)num_channels; /* mix to mono */
    }

    free(raw);
    *samples_out     = out;
    *num_samples_out = num_samples;
    if (sample_rate_out) *sample_rate_out = sample_rate;
    return 0;

fail:
    if (fp) fclose(fp);
    free(raw);
    free(out);
    return -1;
}

int vc_wav_write(const char *path,
                 const float *samples, size_t num_samples,
                 uint32_t sample_rate) {
    FILE *fp = NULL;
    uint16_t num_channels = 1;
    uint16_t bps = 16;
    uint32_t byte_rate = sample_rate * (uint32_t)num_channels * (uint32_t)(bps / 8);
    uint16_t block_align = num_channels * (bps / 8);
    uint32_t data_size = (uint32_t)num_samples * (uint32_t)block_align;
    uint32_t file_size = 4 + 24 + 8 + data_size; /* RIFFhdr + fmt + datahdr + data */

    fp = fopen(path, "wb");
    if (!fp) return -1;

    if (write_bytes(fp, "RIFF", 4) != 0) goto fail;
    if (write_bytes(fp, &file_size, 4) != 0) goto fail;
    if (write_bytes(fp, "WAVE", 4) != 0) goto fail;

    if (write_bytes(fp, "fmt ", 4) != 0) goto fail;
    uint32_t fmt_size = 16;
    if (write_bytes(fp, &fmt_size, 4) != 0) goto fail;
    uint16_t af = 1;
    if (write_bytes(fp, &af, 2) != 0) goto fail;
    if (write_bytes(fp, &num_channels, 2) != 0) goto fail;
    if (write_bytes(fp, &sample_rate, 4) != 0) goto fail;
    if (write_bytes(fp, &byte_rate, 4) != 0) goto fail;
    if (write_bytes(fp, &block_align, 2) != 0) goto fail;
    if (write_bytes(fp, &bps, 2) != 0) goto fail;

    if (write_bytes(fp, "data", 4) != 0) goto fail;
    if (write_bytes(fp, &data_size, 4) != 0) goto fail;

    size_t i;
    for (i = 0; i < num_samples; ++i) {
        unsigned char buf[2];
        float_to_sample(samples[i], buf, 16);
        if (write_bytes(fp, buf, 2) != 0) goto fail;
    }

    fclose(fp);
    return 0;

fail:
    if (fp) fclose(fp);
    return -1;
}
