#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmocka.h>

#include "src/hardware.h"
#include "src/module_a.h"
#include "src/peripheral.h"
#include "src/peripherals.h"
#include "src/peripherals/divide_by_half.h"
#include "src/peripherals/multiply_by_two.h"
#include "src/peripherals/power_of_two.h"
#include "src/peripherals/square_root.h"



// function declarations
void ASSERT_PIN_STATE(PinState expected, uint16_t gpio);

//Setup and teardown tests 

static int groupSetup(void** state) {
    initialize_hardware();
    printf("Verification of setup\n");
    return 0;
}

static int groupTeardown(void** state) {
    reset_hardware();
    printf("Verification of teardown\n");
    return 0;
}


//Assert tests 

static void test_assert_true(void **state) {
    assert_true(divide_by_half(128) == multiply_by_two(32));
}

static void test_assert_int_equal(void **state)
{
    assert_int_equal((int)divide_by_half(128), (int)multiply_by_two(32));
}

static void test_assert_int16_equal(void** state)
{
    assert_int_equal((int16_t)divide_by_half(128), (int16_t)multiply_by_two(32));
}

static void test_assert_float_equal(void** state)
{
    assert_float_equal((float)divide_by_half(128), (float)multiply_by_two(32), 0);
}

static void test_assert_double_equal(void** state)
{
    assert_float_equal(divide_by_half(128), multiply_by_two(32), 0);
}

static void test_assert_hex_equal(void** state)
{
    int32_t exp = 0x00000800u;
    assert_int_equal(exp, (int32_t)divide_by_half((int32_t)multiply_by_two(exp)));
    assert_int_equal(exp, (int32_t)square_root((int32_t)power_of_two(exp)));
}


static void test_assert_string_equal(void** state)
{
    char* exp = "Hello World";
    char* act = "Hello World";
    assert_string_equal(exp, act);
}

static void test_assert_null(void** state) {
    int* act = NULL;
    assert_null(act);
}

static void test_assert_non_null(void** state) {
    int* act = 10;
    assert_non_null(act);
}

static void test_assert_ptr_equal(void** state) {
    int* exp = 10;
    int* act = exp;
    assert_ptr_equal(exp, act);
}

static void test_assert_ptr_not_equal(void** state) {
    int* exp = 10;
    int* act = 5;
    assert_ptr_not_equal(exp, act);
}

static void test_assert_array_equal(void** state) {
    int exp[] = { 1,2,3,4,5 };
    int act[] = { 1,2,3,4,5 };
    fail_msg("no assert for arrays");
}

static void test_assert_memmory_equal_string(void** state) {
    char* exp = "abcd";
    char* act = "abcd";
    assert_memory_equal(exp, act, sizeof(exp));
}

static void test_assert_memmory_equal_int(void** state) {
    int exp = 128;
    int act = 128;
    assert_memory_equal(&exp, &act, sizeof(exp));
}

static void test_assert_memmory_not_equal(void** state) {
    int exp = 256;
    int act = 128;
    assert_memory_not_equal(&exp, &act, sizeof(exp));
}

static void test_assert_in_range(void** state) {
    assert_in_range(divide_by_half(128), power_of_two(7), multiply_by_two(33));
}


// test extensibility


static void test_extensibility(void** state){
    uint16_t pin = 4;
    digital_write(pin, HIGH);
    ASSERT_PIN_STATE(HIGH, 4);
}

void ASSERT_PIN_STATE(PinState expected, uint16_t gpio)
{
    char* output = (char*)malloc(128 * sizeof(char));

    if (digital_read(gpio) != expected)
    {
        sprintf(output, "Custom assertion '%s' failed.", __func__);
        fail_msg("%s", output);
    }

    free(output);
}


// test memory leak detection

static void test_memory_leak_detection(void** state) {
    char* memory = (char*)test_malloc(128 * sizeof(char));
    memory = "Hello world";
    //printf("%s", memory);
    //test_free(*memory);
    //free(memory);
}

// test exception handling for signals
// exceptions cant be handeled, and no info can be found on how to recover the test state on a exception. 
/*
static void test_exception_handling_causeException(void** state) {
    int i = *(int*)0;
}

static void test_exception_handling_verification(void** state) {
    printf("Program kept running\n");
}
*/




int main()
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(test_assert_true),
        cmocka_unit_test(test_assert_int_equal),
        cmocka_unit_test(test_assert_int16_equal),
        cmocka_unit_test(test_assert_float_equal),
        cmocka_unit_test(test_assert_string_equal),
        cmocka_unit_test(test_assert_double_equal),
        cmocka_unit_test(test_assert_hex_equal),
        cmocka_unit_test(test_assert_null),
        cmocka_unit_test(test_assert_non_null),
        cmocka_unit_test(test_assert_ptr_equal),
        cmocka_unit_test(test_assert_ptr_not_equal),
        cmocka_unit_test(test_assert_array_equal),
        cmocka_unit_test(test_assert_memmory_equal_string),
        cmocka_unit_test(test_assert_memmory_equal_int),
        cmocka_unit_test(test_assert_memmory_not_equal),
        cmocka_unit_test(test_assert_in_range),
        cmocka_unit_test(test_extensibility),
        cmocka_unit_test(test_memory_leak_detection),
        //cmocka_unit_test(test_exception_handling_causeException),
        //cmocka_unit_test(test_exception_handling_verification),


    };

    return cmocka_run_group_tests(tests, groupSetup, groupTeardown);
}