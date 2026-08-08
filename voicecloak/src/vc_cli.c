#include "vc_wav.h"
#include "vc_dsp.h"
#include "vc_crypto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static void print_usage(const char *prog) {
    printf(
        "VoiceCloak - cryptographically secure voice anonymizer\n"
        "\n"
        "Usage: %s <command> [options]\n"
        "\n"
        "Commands:\n"
        "  keygen                        Generate RSA-4096 keypair\n"
        "  cloak   -k <pubkey> <in.wav> <out.wav>\n"
        "              [--mode subtle|witness]\n"
        "                                Anonymize voice recording\n"
        "  info    <in.wav>              Show metadata about a cloaked file\n"
        "\n"
        "Modes:\n"
        "  subtle    Light pitch shift, minimal artifacts (default)\n"
        "  witness   Aggressive: full octave pitch, formant warping,\n"
        "            spectral scrambling. TV-style witness protection.\n"
        "\n"
        "Key files:\n"
        "  keygen produces:  voicecloak_key.pub  (public key)\n"
        "                     voicecloak_key.pem  (private key)\n"
        "  cloak produces:   <out.wav>           (anonymized audio)\n"
        "                     <out.wav>.vc        (encrypted session seed)\n"
        "\n"
        "Examples:\n"
        "  %s keygen\n"
        "  %s cloak -k voicecloak_key.pub interview.wav interview_anon.wav\n"
        "  %s cloak -k voicecloak_key.pub --mode witness interview.wav anon.wav\n"
        "  %s info interview_anon.wav\n",
        prog, prog, prog, prog, prog);
}

static int cmd_keygen(void) {
    printf("Generating RSA-4096 keypair...\n");
    if (vc_crypto_keygen("voicecloak_key.pub", "voicecloak_key.pem") != 0) {
        fprintf(stderr, "Error: key generation failed.\n");
        return 1;
    }
    printf("Public key:  voicecloak_key.pub\n");
    printf("Private key: voicecloak_key.pem\n");
    printf("Keep voicecloak_key.pem secure. It cannot be regenerated.\n");
    return 0;
}

static int cmd_cloak(const char *pubkey_path,
                     const char *in_path, const char *out_path,
                     VcMode mode) {
    float *samples = NULL;
    size_t num_samples = 0;
    uint32_t sample_rate = 0;

    printf("Loading: %s\n", in_path);
    if (vc_wav_read(in_path, &samples, &num_samples, &sample_rate) != 0) {
        fprintf(stderr, "Error: cannot read WAV file '%s'.\n", in_path);
        return 1;
    }
    printf("  Samples: %zu, Rate: %u Hz, Duration: %.1fs\n",
           num_samples, sample_rate, (float)num_samples / (float)sample_rate);

    /* Generate random 96-byte master seed */
    unsigned char master_seed[VC_TOTAL_SEED_BYTES];
    {
        FILE *ur = fopen("/dev/urandom", "rb");
        if (!ur || fread(master_seed, 1, VC_TOTAL_SEED_BYTES, ur) != VC_TOTAL_SEED_BYTES) {
            fprintf(stderr, "Error: cannot read random seed.\n");
            free(samples); if (ur) fclose(ur); return 1;
        }
        fclose(ur);
    }

    /* Seal the seed with RSA public key */
    unsigned char enc_seed[512];
    size_t enc_len = sizeof(enc_seed);
    printf("Encrypting session seed with RSA-4096...\n");
    if (vc_crypto_seal(pubkey_path, master_seed, VC_TOTAL_SEED_BYTES,
                       enc_seed, &enc_len) != 0) {
        fprintf(stderr, "Error: RSA seal failed. Check public key path.\n");
        free(samples); return 1;
    }
    printf("  Seed encrypted: %zu bytes\n", enc_len);

    /* Save sidecar */
    {
        char sidecar_path[4096];
        snprintf(sidecar_path, sizeof(sidecar_path), "%s.vc", out_path);
        FILE *sf = fopen(sidecar_path, "wb");
        if (!sf) {
            fprintf(stderr, "Error: cannot write sidecar file.\n");
            free(samples); return 1;
        }
        fwrite(enc_seed, 1, enc_len, sf);
        fclose(sf);
        printf("  Sidecar: %s\n", sidecar_path);
    }

    /* Derive sub-seeds */
    unsigned char pitch_seed[VC_CRYPTO_KEY_BYTES];
    unsigned char formant_seed[VC_CRYPTO_KEY_BYTES];
    unsigned char spectral_seed[VC_CRYPTO_KEY_BYTES];
    if (vc_crypto_derive_seeds(master_seed, VC_TOTAL_SEED_BYTES,
                               pitch_seed, formant_seed, spectral_seed) != 0) {
        fprintf(stderr, "Error: HKDF seed derivation failed.\n");
        free(samples); return 1;
    }

    /* Apply voice cloaking */
    printf("Applying voice cloaking transforms...\n");
    float *cloaked = NULL;
    size_t cloaked_len = 0;
    if (vc_dsp_cloak(samples, num_samples, sample_rate,
                     pitch_seed, formant_seed, spectral_seed,
                     mode,
                     &cloaked, &cloaked_len) != 0) {
        fprintf(stderr, "Error: DSP cloaking failed.\n");
        free(samples); return 1;
    }
    free(samples);
    printf("  Output samples: %zu (%.1fs)\n",
           cloaked_len, (float)cloaked_len / (float)sample_rate);

    printf("Writing: %s\n", out_path);
    if (vc_wav_write(out_path, cloaked, cloaked_len, sample_rate) != 0) {
        fprintf(stderr, "Error: cannot write output WAV.\n");
        free(cloaked); return 1;
    }
    free(cloaked);

    printf("Done. Voice cloaked successfully.\n");
    printf("The seed is encrypted in '%s.vc'.\n", out_path);
    printf("Without voicecloak_key.pem, the transformation is irreversible.\n");
    return 0;
}

static int cmd_info(const char *path) {
    printf("File: %s\n", path);

    float *samples = NULL;
    size_t num_samples = 0;
    uint32_t sample_rate = 0;
    if (vc_wav_read(path, &samples, &num_samples, &sample_rate) != 0) {
        fprintf(stderr, "Error: cannot read WAV file.\n");
        return 1;
    }
    printf("  Samples: %zu\n", num_samples);
    printf("  Rate:    %u Hz\n", sample_rate);
    printf("  Length:  %.2fs\n", (float)num_samples / (float)sample_rate);
    free(samples);

    char sidecar_path[4096];
    snprintf(sidecar_path, sizeof(sidecar_path), "%s.vc", path);
    FILE *sf = fopen(sidecar_path, "rb");
    if (sf) {
        size_t sz = 0;
        unsigned char buf[1024];
        sz = fread(buf, 1, sizeof(buf), sf);
        fclose(sf);
        printf("  Sidecar: %s (%zu bytes encrypted seed)\n", sidecar_path, sz);
        /* Small seeds (< 256 bytes) are RSA-encrypted 96-byte seeds */
        if (sz <= 256)
            printf("  Seed:    RSA-4096 encrypted (96 bytes plaintext)\n");
        else
            printf("  Seed:    RSA-4096 encrypted\n");
    } else {
        printf("  Sidecar: none (file is not cloaked)\n");
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) { print_usage(argv[0]); return 1; }

    if (strcmp(argv[1], "keygen") == 0)
        return cmd_keygen();

    if (strcmp(argv[1], "info") == 0) {
        if (argc < 3) { fprintf(stderr, "Usage: %s info <file.wav>\n", argv[0]); return 1; }
        return cmd_info(argv[2]);
    }

    if (strcmp(argv[1], "cloak") == 0) {
        const char *pubkey = NULL, *in = NULL, *out = NULL;
        VcMode mode = VC_MODE_SUBTLE;
        int i;
        for (i = 2; i < argc; ++i) {
            if (strcmp(argv[i], "-k") == 0 && i + 1 < argc) {
                pubkey = argv[++i];
            } else if (strcmp(argv[i], "--mode") == 0 && i + 1 < argc) {
                ++i;
                if (strcmp(argv[i], "witness") == 0) mode = VC_MODE_WITNESS;
                else if (strcmp(argv[i], "subtle") == 0) mode = VC_MODE_SUBTLE;
                else { fprintf(stderr, "Unknown mode: %s\n", argv[i]); return 1; }
            } else if (!in)  { in  = argv[i]; }
            else if (!out) { out = argv[i]; }
        }
        if (!pubkey || !in || !out) {
            fprintf(stderr, "Usage: %s cloak -k <pubkey> <in.wav> <out.wav>\n", argv[0]);
            return 1;
        }
        return cmd_cloak(pubkey, in, out, mode);
    }

    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        print_usage(argv[0]); return 0;
    }

    fprintf(stderr, "Unknown command: %s\n", argv[1]);
    print_usage(argv[0]);
    return 1;
}
