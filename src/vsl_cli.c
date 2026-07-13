/*
 * vsl-cli: PreSonus AudioBox VSL DSP control tool
 *
 * Sends DSP parameter changes to the device via USB-HID.
 *
 * Usage:
 *   vsl-cli <param_id_hex> <value_0_1>     Send encoded parameter
 *   vsl-cli gain <channel> <value_0_1>     Set channel gain
 *   vsl-cli list                            List known parameters
 *
 * Examples:
 *   vsl-cli gain 1 0.75     Set channel 1 gain to 75%
 *   vsl-cli 1A01 0.75       Same as above (0x1A01 = Gain CH1)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include "vsl_dsp_logic.h"
#include "vsl_dsp_transport.h"

#define VSL_VENDOR_ID   0x194f
#define VSL_PRODUCT_ID  0x0101

typedef struct {
    const char *name;
    uint16_t param_id;
    const char *desc;
    VSL_Parameter coeffs;
} ParamEntry;

static const VSL_Parameter GAIN_CH1_COEFFS = {
    .dsp_param_id = 0x1A01,
    .max_encoded_int = 65535,
    .coeff_offset_A = -10.0f,
    .coeff_C1 = 20.0f,
    .log_factor = 4.60517f,
    .curve_min_map = 0.0f,
    .curve_max_map = 1.0f,
    .freq_min_hz = 0.0f,
    .freq_max_hz = 0.0f
};

static const VSL_Parameter FREQ_HPF_CH1_COEFFS = {
    .dsp_param_id = 0x2B05,
    .max_encoded_int = 65535,
    .coeff_offset_A = 0.0f,
    .coeff_C1 = 0.0f,
    .log_factor = 0.0f,
    .curve_min_map = 0.0f,
    .curve_max_map = 0.0f,
    .freq_min_hz = 20.0f,
    .freq_max_hz = 20000.0f
};

static const ParamEntry param_table[] = {
    {"gain1",  0x1A01, "Gain Channel 1",   GAIN_CH1_COEFFS},
    {"gain2",  0x1A02, "Gain Channel 2",   GAIN_CH1_COEFFS},
    {"hpf1",   0x2B05, "HPF Frequency Ch1", FREQ_HPF_CH1_COEFFS},
    {"hpf2",   0x2B06, "HPF Frequency Ch2", FREQ_HPF_CH1_COEFFS},
    {NULL,     0,      NULL,               {0}}
};

static void print_list(void)
{
    const ParamEntry *p;

    printf("Known VSL DSP parameters:\n");
    printf("  %-12s %-8s %s\n", "Name", "ID", "Description");
    printf("  %-12s %-8s %s\n", "----", "--", "-----------");
    for (p = param_table; p->name; p++) {
        printf("  %-12s 0x%04X  %s\n", p->name, p->param_id, p->desc);
    }
    printf("\nUsage:\n");
    printf("  vsl-cli gain 1 0.75        Set gain ch1 to 75%%\n");
    printf("  vsl-cli 1A01 0.75          Raw: param 0x1A01, value 0.75\n");
}

static const ParamEntry *find_by_name(const char *name)
{
    const ParamEntry *p;
    for (p = param_table; p->name; p++) {
        if (strcmp(p->name, name) == 0)
            return p;
    }
    return NULL;
}

static int do_send_param(uint16_t param_id, float user_value, const VSL_Parameter *coeffs)
{
    vsl_device_handle dev;
    float encoded_float;
    uint32_t encoded_int;
    int ret;

    dev = VSL_Init_Device(VSL_VENDOR_ID, VSL_PRODUCT_ID);
    if (!dev) {
        fprintf(stderr, "Error: Cannot open VSL device.\n");
        fprintf(stderr, "Try: lsusb | grep 194f\n");
        fprintf(stderr, "Check permissions on /dev/hidraw* or /dev/bus/usb/*\n");
        return 1;
    }

    encoded_float = VSL_Encode_Gain(user_value, coeffs);
    encoded_int = VSL_Final_Encode_To_Int(encoded_float, coeffs);

    printf("Param 0x%04X\n", param_id);
    printf("  User value:      %.4f\n", user_value);
    printf("  Encoded float:   %.4f\n", encoded_float);
    printf("  Encoded int:     %u (0x%04X)\n", encoded_int, encoded_int);

    ret = VSL_Send_Parameter(dev, param_id, encoded_int);
    if (ret == 0) {
        printf("  Sent:            OK\n");
    } else {
        printf("  Send:            FAILED\n");
    }

    VSL_Close_Device(dev);
    return ret == 0 ? 0 : 1;
}

int main(int argc, char *argv[])
{
    unsigned long param_id;
    float user_value;
    const ParamEntry *entry;
    char *end;

    if (argc < 2) {
        fprintf(stderr, "Usage:\n");
        fprintf(stderr, "  vsl-cli <param_id_hex> <value_0_1>\n");
        fprintf(stderr, "  vsl-cli gain <channel> <value_0_1>\n");
        fprintf(stderr, "  vsl-cli list\n");
        return 1;
    }

    if (strcmp(argv[1], "list") == 0) {
        print_list();
        return 0;
    }

    if (strcmp(argv[1], "gain") == 0) {
        if (argc < 4) {
            fprintf(stderr, "Usage: vsl-cli gain <channel> <value_0_1>\n");
            return 1;
        }
        unsigned long ch = strtoul(argv[2], NULL, 10);
        if (ch < 1 || ch > 2) {
            fprintf(stderr, "Channel must be 1 or 2\n");
            return 1;
        }
        user_value = strtof(argv[3], NULL);
        param_id = 0x1A00 + ch;
        return do_send_param((uint16_t)param_id, user_value, &GAIN_CH1_COEFFS);
    }

    entry = find_by_name(argv[1]);
    if (entry) {
        if (argc < 3) {
            fprintf(stderr, "Usage: vsl-cli %s <value_0_1>\n", argv[1]);
            return 1;
        }
        user_value = strtof(argv[2], NULL);
        return do_send_param(entry->param_id, user_value, &entry->coeffs);
    }

    param_id = strtoul(argv[1], &end, 16);
    if (*end != '\0' || param_id > 0xFFFF) {
        fprintf(stderr, "Invalid parameter ID: %s (use hex, e.g. 1A01)\n", argv[1]);
        return 1;
    }

    if (argc < 3) {
        fprintf(stderr, "Usage: vsl-cli %s <value_0_1>\n", argv[1]);
        return 1;
    }
    user_value = strtof(argv[2], NULL);
    if (user_value < 0.0f || user_value > 1.0f) {
        fprintf(stderr, "Value must be between 0.0 and 1.0\n");
        return 1;
    }

    return do_send_param((uint16_t)param_id, user_value, &GAIN_CH1_COEFFS);
}
