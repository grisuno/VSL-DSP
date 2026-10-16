#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <string.h>
#include <cmocka.h>
#include "vsl_dsp_transport.h"

static void test_build_packet_layout(void **state)
{
    (void)state;
    unsigned char buf[VSL_PACKET_SIZE];

    memset(buf, 0xAA, sizeof(buf));
    assert_int_equal(VSL_Build_Packet(0x1A01U, 0x9F69U, buf), 0);
    assert_int_equal(buf[0], (int)VSL_REPORT_ID);
    assert_int_equal(buf[1], 0x01);
    assert_int_equal(buf[2], 0x1AU);
    assert_int_equal(buf[3], 0x69);
    assert_int_equal(buf[4], 0x9FU);
    for (size_t i = 5; i < sizeof(buf); ++i) {
        assert_int_equal(buf[i], 0);
    }
}

static void test_build_packet_zero_values(void **state)
{
    (void)state;
    unsigned char buf[VSL_PACKET_SIZE];

    memset(buf, 0xAA, sizeof(buf));
    assert_int_equal(VSL_Build_Packet(0x0000U, 0x0000U, buf), 0);
    for (size_t i = 0; i < sizeof(buf); ++i) {
        if (i == 0) {
            assert_int_equal(buf[i], (int)VSL_REPORT_ID);
        } else {
            assert_int_equal(buf[i], 0);
        }
    }
}

static void test_build_packet_max_values(void **state)
{
    (void)state;
    unsigned char buf[VSL_PACKET_SIZE];

    memset(buf, 0, sizeof(buf));
    assert_int_equal(VSL_Build_Packet(0xFFFFU, 0xFFFFU, buf), 0);
    assert_int_equal(buf[1], 0xFF);
    assert_int_equal(buf[2], 0xFF);
    assert_int_equal(buf[3], 0xFF);
    assert_int_equal(buf[4], 0xFF);
}

static void test_build_packet_null_fails_closed(void **state)
{
    (void)state;

    assert_int_not_equal(VSL_Build_Packet(0x1A01U, 0x9F69U, NULL), 0);
}

static void test_send_null_handle_fails_closed(void **state)
{
    (void)state;

    assert_int_equal(VSL_Send_Parameter(NULL, 0x1A01U, 0x9F69U), -1);
    VSL_Close_Device(NULL);
}

static void test_probe_null_buffer_fails_closed(void **state)
{
    (void)state;

    assert_int_not_equal(VSL_Probe_Device(0x194FU, 0x0101U, NULL, 256), 0);
}

static void test_probe_zero_length_fails_closed(void **state)
{
    (void)state;
    char buf[64];

    memset(buf, 0xAA, sizeof(buf));
    assert_int_not_equal(VSL_Probe_Device(0x194FU, 0x0101U, buf, 0), 0);
}

static void test_probe_absent_device_fails_closed(void **state)
{
    (void)state;
    char buf[256];

    memset(buf, 0, sizeof(buf));
    assert_int_not_equal(VSL_Probe_Device(0x1234U, 0x5678U, buf, sizeof(buf)), 0);
    assert_int_equal(buf[0], '\0');
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_build_packet_layout),
        cmocka_unit_test(test_build_packet_zero_values),
        cmocka_unit_test(test_build_packet_max_values),
        cmocka_unit_test(test_build_packet_null_fails_closed),
        cmocka_unit_test(test_send_null_handle_fails_closed),
        cmocka_unit_test(test_probe_null_buffer_fails_closed),
        cmocka_unit_test(test_probe_zero_length_fails_closed),
        cmocka_unit_test(test_probe_absent_device_fails_closed),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
