#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <cmocka.h>

#include "src/hardware.h"
#include "src/module_a.h"
#include "src/peripheral.h"
#include "src/peripherals.h"
#include "src/peripherals/divide_by_half.h"
#include "src/peripherals/multiply_by_two.h"
#include "src/peripherals/power_of_two.h"
#include "src/peripherals/square_root.h"

#include "file.h"


static int groupSetup(void** state) {
    initialize_hardware();
    return 0;
}

static int groupTeardown(void** state) {
    reset_hardware();
    return 0;
}


//Assert tests stated bellow

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

static void test_assert_memmory_equal(void** state) {
    //char* exp = "abcd";
    //char* act = "abcd";
    int exp = 128;
    int act = 128;
    printf("%x", &exp);
    printf("\n");
    printf("%x", &act);
    printf("\n");
    assert_memory_equal(&exp, &act, sizeof(exp));
}

static void test_assert_memmory_not_equal(void** state) {
    //char* exp = "abcd";
    //char* act = "128";
    //int *exp = 256;
    //int *act = 128;
    //assert_memory_not_equal(exp, act, sizeof(exp));
}


static void test_file(void** state) {
    assert_int_equal(9, add(4, 5));
}


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
        cmocka_unit_test(test_assert_null),
        cmocka_unit_test(test_assert_non_null),
        cmocka_unit_test(test_assert_ptr_equal),
        cmocka_unit_test(test_assert_ptr_not_equal),
        cmocka_unit_test(test_assert_array_equal),
        cmocka_unit_test(test_assert_memmory_equal),
        cmocka_unit_test(test_assert_memmory_not_equal),

        
        cmocka_unit_test(test_file),
    };

    return cmocka_run_group_tests(tests, groupSetup, groupTeardown);
}