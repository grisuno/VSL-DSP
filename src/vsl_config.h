#ifndef VSL_CONFIG_H
#define VSL_CONFIG_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define VSL_VENDOR_ID         0x194fU
#define VSL_PRODUCT_ID_22VSL  0x0101U
#define VSL_PRODUCT_ID_44VSL  0x0102U
#define VSL_PRODUCT_ID_1818VSL 0x0103U

#define VSL_REPORT_ID         0x06U
#define VSL_PACKET_SIZE       64U
#define VSL_MIDI_IFACE        4U
#define VSL_EP_MIDI_OUT       0x02U

typedef struct {
    uint16_t    pid;
    const char *tag;
    const char *name;
} VSL_ModelInfo;

static const VSL_ModelInfo VSL_MODELS[] = {
    {VSL_PRODUCT_ID_22VSL,   "22vsl",   "AudioBox 22 VSL"},
    {VSL_PRODUCT_ID_44VSL,   "44vsl",   "AudioBox 44 VSL"},
    {VSL_PRODUCT_ID_1818VSL, "1818vsl", "AudioBox 1818 VSL"},
};

static const size_t VSL_MODELS_COUNT =
    sizeof(VSL_MODELS) / sizeof(VSL_MODELS[0]);

static inline const VSL_ModelInfo *
VSL_ModelLookup(uint16_t pid)
{
    size_t i;
    for (i = 0; i < VSL_MODELS_COUNT; ++i) {
        if (VSL_MODELS[i].pid == pid) {
            return &VSL_MODELS[i];
        }
    }
    return NULL;
}

static inline const VSL_ModelInfo *
VSL_ModelLookupByTag(const char *tag)
{
    size_t i;
    if (tag == NULL) return NULL;
    for (i = 0; i < VSL_MODELS_COUNT; ++i) {
        if (VSL_MODELS[i].tag[0] == tag[0]) {
            const char *a = VSL_MODELS[i].tag;
            const char *b = tag;
            while (*a && *b && *a == *b) { ++a; ++b; }
            if (*a == '\0' && *b == '\0') {
                return &VSL_MODELS[i];
            }
        }
    }
    return NULL;
}

#ifdef __cplusplus
}
#endif

#endif /* VSL_CONFIG_H */
