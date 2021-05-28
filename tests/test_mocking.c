#include "test_mocking.h"
#include "../mocks/mock_module_a.h"
#include <math.h>
#include <stdint.h>

static void test_assertion_double_equal(void** state);
static void test_assertion_float_equal(void** state);
static void test_assertion_hex32_equal(void** state);
static void test_assertion_uint32_equal(void** state);
static void test_assertion_int32_equal(void** state);

static CMFixtureFunction _setup(void** state)
{
	return 0;
}

static CMFixtureFunction _teardown(void** state)
{
	return 0;
}

TestGroup create_test_mocking()
{
	const struct CMUnitTest arr[] = {
		cmocka_unit_test(test_assertion_double_equal),
		cmocka_unit_test(test_assertion_float_equal),
		cmocka_unit_test(test_assertion_hex32_equal),
		cmocka_unit_test(test_assertion_uint32_equal),
		cmocka_unit_test(test_assertion_int32_equal)
	};

	const int SIZE = sizeof(arr) / sizeof(arr[0]);

	struct CMUnitTest* tests = malloc(SIZE * sizeof(struct CMUnitTest));

	for (int i = 0; i < SIZE; i++)
		tests[i] = arr[i];

	return new_TestGroup(_setup, _teardown, tests, SIZE);
}

static void test_assertion_int32_equal(void** state)
{
	int32_t exp = 128;
	will_return(multiply_by_two, exp * 2);
	will_return(divide_by_half, (exp * 2) / 2);
	will_return(power_of_two, pow(exp, 2));
	will_return(square_root, sqrt(pow(exp, 2)));

	assert_int_equal(exp, (int32_t)divide_by_half((int32_t)multiply_by_two(exp)));
	assert_int_equal(exp, (int32_t)square_root((int32_t)power_of_two(exp)));
}

static void test_assertion_uint32_equal(void** state)
{
	uint32_t exp = 128;
	will_return(multiply_by_two, exp * 2);
	will_return(divide_by_half, (exp * 2) / 2);
	will_return(power_of_two, pow(exp, 2));
	will_return(square_root, sqrt(pow(exp, 2)));

	assert_int_equal(exp, (uint32_t)divide_by_half((uint32_t)multiply_by_two(exp)));
	assert_int_equal(exp, (uint32_t)square_root((uint32_t)power_of_two(exp)));
}

static void test_assertion_hex32_equal(void** state)
{
	int32_t exp = 0x00000800u;
	will_return(multiply_by_two, exp * 2);
	will_return(divide_by_half, (exp * 2) / 2);
	will_return(power_of_two, pow(exp, 2));
	will_return(square_root, sqrt(pow(exp, 2)));

	assert_int_equal(exp, (int32_t)divide_by_half((int32_t)multiply_by_two(exp)));
	assert_int_equal(exp, (int32_t)square_root((int32_t)power_of_two(exp)));
}

static void test_assertion_float_equal(void** state)
{
	float exp = 128.000f;
	will_return(multiply_by_two, exp * 2);
	will_return(divide_by_half, (exp * 2) / 2);
	will_return(power_of_two, pow(exp, 2));
	will_return(square_root, sqrt(pow(exp, 2)));

	assert_float_equal(exp, (float)divide_by_half((float)multiply_by_two(exp)), 0.01f);
	assert_float_equal(exp, (float)square_root((float)power_of_two(exp)), 0.01f);
}

static void test_assertion_double_equal(void** state)
{
	double exp = 128.000;
	will_return(multiply_by_two, exp * 2);
	will_return(divide_by_half, (exp * 2) / 2);
	will_return(power_of_two, pow(exp, 2));
	will_return(square_root, sqrt(pow(exp, 2)));

	assert_float_equal(exp, (double)divide_by_half((double)multiply_by_two(exp)), 0.01f);
	assert_float_equal(exp, (double)square_root((double)power_of_two(exp)), 0.01f);
}