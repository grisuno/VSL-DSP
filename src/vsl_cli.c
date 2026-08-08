#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include "vsl_dsp_logic.h"
#include "vsl_dsp_transport.h"
#include "vsl_config.h"

typedef enum {
    PARAM_TYPE_GAIN,
    PARAM_TYPE_FREQ
} ParamType;

typedef struct {
    const char  *name;
    uint16_t     param_id;
    uint16_t     channel;
    const char  *desc;
    ParamType    type;
    VSL_Parameter coeffs;
} ParamEntry;

static const VSL_Parameter GAIN_COEFFS = {
    .dsp_param_id    = 0x1A01,
    .max_encoded_int = 65535,
    .coeff_offset_A  = -10.0f,
    .coeff_C1        = 20.0f,
    .log_factor      = 4.60517f,
    .curve_min_map   = 0.0f,
    .curve_max_map   = 1.0f,
    .freq_min_hz     = 0.0f,
    .freq_max_hz     = 0.0f
};

static const VSL_Parameter FREQ_HPF_COEFFS = {
    .dsp_param_id    = 0x2B05,
    .max_encoded_int = 65535,
    .coeff_offset_A  = 0.0f,
    .coeff_C1        = 0.0f,
    .log_factor      = 0.0f,
    .curve_min_map   = 0.0f,
    .curve_max_map   = 0.0f,
    .freq_min_hz     = 20.0f,
    .freq_max_hz     = 20000.0f
};

#define MAX_CHANNELS 18

static const ParamEntry param_table[] = {
    {"gain1",  0x1A01, 1, "Gain Channel 1",   PARAM_TYPE_GAIN, GAIN_COEFFS},
    {"gain2",  0x1A02, 2, "Gain Channel 2",   PARAM_TYPE_GAIN, GAIN_COEFFS},
    {"hpf1",   0x2B05, 1, "HPF Frequency Ch1", PARAM_TYPE_FREQ, FREQ_HPF_COEFFS},
    {"hpf2",   0x2B06, 2, "HPF Frequency Ch2", PARAM_TYPE_FREQ, FREQ_HPF_COEFFS},
    {NULL,     0,      0, NULL,                0,              {0}}
};

static void print_usage(FILE *fp, const char *prog)
{
    fprintf(fp,
        "Usage: %s [OPTIONS] COMMAND [ARGS...]\n"
        "\n"
        "Options:\n"
        "  -p, --pid <hex>      USB product ID (default: 0x0101 = 22 VSL)\n"
        "  -m, --model <tag>    Model tag: 22vsl, 44vsl, 1818vsl\n"
        "  -h, --help           Show this help\n"
        "  -V, --version        Show version\n"
        "\n"
        "Commands:\n"
        "  gain <ch> <val>      Set channel gain (val in 0.0..1.0)\n"
        "  freq <ch> <hz>       Set HPF frequency (Hz)\n"
        "  raw  <id> <val>      Send raw param ID (hex) with linear value\n"
        "  list                 List known parameters\n"
        "\n"
        "Examples:\n"
        "  %s gain 1 0.75               Gain ch1 at 75%%\n"
        "  %s --model 44vsl gain 3 0.5  Gain ch3 on 44 VSL\n"
        "  %s freq 1 80                 HPF ch1 at 80 Hz\n"
        "  %s raw 1A01 0.5              Raw: param 0x1A01 value 0.5\n"
        "  %s list                      List parameters\n",
        prog, prog, prog, prog, prog, prog);
}

static void print_version(void)
{
    printf("vsl-cli 2.0.0\n"
           "PreSonus AudioBox VSL DSP control tool\n"
           "License: AGPL-3.0-or-later\n");
}

static void print_list(uint16_t product_id)
{
    const ParamEntry *p;
    const VSL_ModelInfo *model;

    model = VSL_ModelLookup(product_id);

    printf("Model: %s (%04x:%04x)\n\n",
           model ? model->name : "unknown",
           VSL_VENDOR_ID, product_id);
    printf("Known VSL DSP parameters:\n");
    printf("  %-12s %-6s %-8s %s\n", "Name", "Ch", "ID", "Description");
    printf("  %-12s %-6s %-8s %s\n", "----", "--", "--", "-----------");
    for (p = param_table; p->name; p++) {
        printf("  %-12s %-6u 0x%04X  %s\n",
               p->name, p->channel, p->param_id, p->desc);
    }
}

static const VSL_Parameter *
lookup_coeffs_by_param_id(uint16_t param_id)
{
    const ParamEntry *p;
    for (p = param_table; p->name; p++) {
        if (p->param_id == param_id) return &p->coeffs;
    }
    return NULL;
}

static const ParamEntry *
find_entry_by_name(const char *name)
{
    const ParamEntry *p;
    for (p = param_table; p->name; p++) {
        if (strcmp(p->name, name) == 0) return p;
    }
    return NULL;
}

static int do_send(uint16_t product_id,
                   uint16_t param_id,
                   float    user_value,
                   const VSL_Parameter *coeffs)
{
    vsl_device_handle dev;
    float    encoded_float;
    uint16_t encoded_int;
    int      ret;

    dev = VSL_Init_Device(VSL_VENDOR_ID, product_id);
    if (!dev) {
        fprintf(stderr, "Error: Cannot open device %04x:%04x.\n",
                VSL_VENDOR_ID, product_id);
        fprintf(stderr, "Check: is the device connected?\n");
        fprintf(stderr, "Check: udev rules or run as root.\n");
        return 1;
    }

    encoded_float = VSL_Encode_Gain(user_value, coeffs);
    encoded_int   = VSL_Final_Encode_To_Int(encoded_float, coeffs);

    printf("Device: %04x:%04x\n", VSL_VENDOR_ID, product_id);
    printf("Param:  0x%04X\n", param_id);
    printf("  User value:    %.4f\n", user_value);
    printf("  Encoded float: %.4f\n", encoded_float);
    printf("  Encoded int:   %u (0x%04X)\n", encoded_int, encoded_int);

    ret = VSL_Send_Parameter(dev, param_id, encoded_int);
    if (ret == 0)
        printf("  Result:        OK\n");
    else
        printf("  Result:        FAILED\n");

    VSL_Close_Device(dev);
    return (ret == 0) ? 0 : 1;
}

static int do_send_freq(uint16_t product_id,
                        uint16_t param_id,
                        float    freq_hz,
                        const VSL_Parameter *coeffs)
{
    vsl_device_handle dev;
    float    encoded_float;
    uint16_t encoded_int;
    int      ret;

    dev = VSL_Init_Device(VSL_VENDOR_ID, product_id);
    if (!dev) {
        fprintf(stderr, "Error: Cannot open device %04x:%04x.\n",
                VSL_VENDOR_ID, product_id);
        return 1;
    }

    encoded_float = VSL_Map_Frequency(
        fmaxf(0.0f, fminf(freq_hz / coeffs->freq_max_hz, 1.0f)), coeffs);
    encoded_int   = VSL_Final_Encode_To_Int(encoded_float, coeffs);

    printf("Device: %04x:%04x\n", VSL_VENDOR_ID, product_id);
    printf("Param:  0x%04X\n", param_id);
    printf("  Frequency:     %.1f Hz\n", freq_hz);
    printf("  Encoded float: %.4f\n", encoded_float);
    printf("  Encoded int:   %u (0x%04X)\n", encoded_int, encoded_int);

    ret = VSL_Send_Parameter(dev, param_id, encoded_int);
    if (ret == 0)
        printf("  Result:        OK\n");
    else
        printf("  Result:        FAILED\n");

    VSL_Close_Device(dev);
    return (ret == 0) ? 0 : 1;
}

int main(int argc, char *argv[])
{
    uint16_t            product_id = VSL_PRODUCT_ID_22VSL;
    const char         *prog       = argv[0];
    const ParamEntry   *entry;
    const VSL_Parameter *coeffs;
    unsigned long       param_id_ul;
    unsigned long       ch;
    float               user_value;
    char               *end;
    int                 i;

    if (argc < 2) {
        print_usage(stderr, prog);
        return 1;
    }

    i = 1;
    while (i < argc && argv[i][0] == '-') {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_usage(stdout, prog);
            return 0;
        }
        if (strcmp(argv[i], "-V") == 0 || strcmp(argv[i], "--version") == 0) {
            print_version();
            return 0;
        }
        if ((strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--pid") == 0)
            && i + 1 < argc) {
            ++i;
            product_id = (uint16_t)strtoul(argv[i], &end, 16);
            if (*end != '\0' || product_id == 0) {
                fprintf(stderr, "Invalid PID: %s\n", argv[i]);
                return 1;
            }
        } else if ((strcmp(argv[i], "-m") == 0 || strcmp(argv[i], "--model") == 0)
                   && i + 1 < argc) {
            ++i;
            const VSL_ModelInfo *m = VSL_ModelLookupByTag(argv[i]);
            if (!m) {
                fprintf(stderr, "Unknown model: %s\n", argv[i]);
                fprintf(stderr, "Known: 22vsl, 44vsl, 1818vsl\n");
                return 1;
            }
            product_id = m->pid;
        } else {
            fprintf(stderr, "Unknown option: %s\n", argv[i]);
            print_usage(stderr, prog);
            return 1;
        }
        ++i;
    }

    if (i >= argc) {
        print_usage(stderr, prog);
        return 1;
    }

    if (strcmp(argv[i], "list") == 0 || strcmp(argv[i], "params") == 0) {
        print_list(product_id);
        return 0;
    }

    if (strcmp(argv[i], "gain") == 0) {
        if (i + 2 >= argc) {
            fprintf(stderr, "Usage: %s gain <channel> <value_0_1>\n", prog);
            return 1;
        }
        ch = strtoul(argv[i + 1], NULL, 10);
        if (ch < 1 || ch > MAX_CHANNELS) {
            fprintf(stderr, "Channel must be 1-%d\n", MAX_CHANNELS);
            return 1;
        }
        user_value = strtof(argv[i + 2], NULL);
        param_id_ul = 0x1A00UL + ch;
        coeffs = lookup_coeffs_by_param_id((uint16_t)param_id_ul);
        if (!coeffs) coeffs = &GAIN_COEFFS;
        return do_send(product_id, (uint16_t)param_id_ul, user_value, coeffs);
    }

    if (strcmp(argv[i], "freq") == 0) {
        if (i + 2 >= argc) {
            fprintf(stderr, "Usage: %s freq <channel> <freq_hz>\n", prog);
            return 1;
        }
        ch = strtoul(argv[i + 1], NULL, 10);
        if (ch < 1 || ch > MAX_CHANNELS) {
            fprintf(stderr, "Channel must be 1-%d\n", MAX_CHANNELS);
            return 1;
        }
        user_value = strtof(argv[i + 2], NULL);
        param_id_ul = 0x2B04UL + ch;
        coeffs = lookup_coeffs_by_param_id((uint16_t)param_id_ul);
        if (!coeffs) coeffs = &FREQ_HPF_COEFFS;
        return do_send_freq(product_id, (uint16_t)param_id_ul,
                            user_value, coeffs);
    }

    if (strcmp(argv[i], "raw") == 0) {
        if (i + 2 >= argc) {
            fprintf(stderr, "Usage: %s raw <param_id_hex> <value_0_1>\n", prog);
            return 1;
        }
        param_id_ul = strtoul(argv[i + 1], &end, 16);
        if (*end != '\0' || param_id_ul > 0xFFFFUL) {
            fprintf(stderr, "Invalid param ID: %s\n", argv[i + 1]);
            return 1;
        }
        user_value = strtof(argv[i + 2], NULL);
        coeffs = lookup_coeffs_by_param_id((uint16_t)param_id_ul);
        if (!coeffs) coeffs = &GAIN_COEFFS;
        return do_send(product_id, (uint16_t)param_id_ul, user_value, coeffs);
    }

    entry = find_entry_by_name(argv[i]);
    if (entry) {
        if (i + 1 >= argc) {
            fprintf(stderr, "Usage: %s %s <value>\n", prog, entry->name);
            return 1;
        }
        user_value = strtof(argv[i + 1], NULL);
        if (entry->type == PARAM_TYPE_FREQ)
            return do_send_freq(product_id, entry->param_id,
                                user_value, &entry->coeffs);
        else
            return do_send(product_id, entry->param_id,
                           user_value, &entry->coeffs);
    }

    param_id_ul = strtoul(argv[i], &end, 16);
    if (*end == '\0' && param_id_ul <= 0xFFFFUL) {
        if (i + 1 >= argc) {
            fprintf(stderr, "Usage: %s %s <value_0_1>\n", prog, argv[i]);
            return 1;
        }
        user_value = strtof(argv[i + 1], NULL);
        coeffs = lookup_coeffs_by_param_id((uint16_t)param_id_ul);
        if (!coeffs) coeffs = &GAIN_COEFFS;
        return do_send(product_id, (uint16_t)param_id_ul, user_value, coeffs);
    }

    fprintf(stderr, "Unknown command: %s\n", argv[i]);
    print_usage(stderr, prog);
    return 1;
}
