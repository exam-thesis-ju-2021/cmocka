#include "test_assertions.h"
#include "../src/module_a.h"
#include <math.h>

static void test_assertion_equal_memory_block_array(void** state);
static void test_assertion_equal_string_array(void** state);
static void test_assertion_equal_ptr_array(void** state);
static void test_assertion_equal_double_array(void** state);
static void test_assertion_equal_float_array(void** state);
static void test_assertion_equal_hex32_array(void** state);
static void test_assertion_equal_uint32_array(void** state);
static void test_assertion_equal_int32_array(void** state);
static void test_assertion_equal_memory_block(void** state);
static void test_assertion_equal_string(void** state);
static void test_assertion_equal_ptr(void** state);
static void test_assertion_hex32_range(void** state);
static void test_assertion_double_range(void** state);
static void test_assertion_float_range(void** state);
static void test_assertion_uint32_range(void** state);
static void test_assertion_int32_range(void** state);
static void test_assertion_masked_bit_low(void** state);
static void test_assertion_masked_bit_high(void** state);
static void test_assertion_masked_bits_low(void** state);
static void test_assertion_masked_bits_high(void** state);
static void test_assertion_masked_bits_match(void** state);
static void test_assertion_double_non_determinate(void** state);
static void test_assertion_float_non_determinate(void** state);
static void test_assertion_double_determinate(void** state);
static void test_assertion_float_not_nan(void** state);
static void test_assertion_double_nan(void** state);
static void test_assertion_float_nan(void** state);
static void test_assertion_double_not_negative_infinity(void** state);
static void test_assertion_float_not_negative_infinity(void** state);
static void test_assertion_double_negative_infinity(void** state);
static void test_assertion_float_negative_infinity(void** state);
static void test_assertion_double_not_infinity(void** state);
static void test_assertion_float_not_infinity(void** state);
static void test_assertion_double_infinity(void** state);
static void test_assertion_float_infinity(void** state);
static void test_assertion_double_equal(void** state);
static void test_assertion_float_equal(void** state);
static void test_assertion_hex32_equal(void** state);
static void test_assertion_uint32_equal(void** state);
static void test_assertion_int32_equal(void** state);
static void test_assert_not_null(void** state);
static void test_assert_null(void** state);
static void test_assertion_boolean_false(void** state);
static void test_assertion_boolean_true(void** state);

static CMFixtureFunction _setup(void** state)
{
    initialize_hardware();
    return 0;
}

static CMFixtureFunction _teardown(void** state)
{
    reset_hardware();
    return 0;
}

static void test_assertion_boolean_true(void** state);
static void test_assertion_boolean_false(void** state);

TestGroup create_test_assertions()
{
	const struct CMUnitTest arr[] = {
		cmocka_unit_test(test_assertion_equal_memory_block_array),
		cmocka_unit_test(test_assertion_equal_string_array),
		cmocka_unit_test(test_assertion_equal_ptr_array),
		cmocka_unit_test(test_assertion_equal_double_array),
		cmocka_unit_test(test_assertion_equal_float_array),
		cmocka_unit_test(test_assertion_equal_hex32_array),
		cmocka_unit_test(test_assertion_equal_uint32_array),
		cmocka_unit_test(test_assertion_equal_int32_array),
		cmocka_unit_test(test_assertion_equal_memory_block),
		cmocka_unit_test(test_assertion_equal_string),
		cmocka_unit_test(test_assertion_equal_ptr),
		cmocka_unit_test(test_assertion_hex32_range),
		cmocka_unit_test(test_assertion_double_range),
		cmocka_unit_test(test_assertion_float_range),
		cmocka_unit_test(test_assertion_uint32_range),
		cmocka_unit_test(test_assertion_int32_range),
		//cmocka_unit_test(test_assertion_masked_bit_low),
		//cmocka_unit_test(test_assertion_masked_bit_high),
		//cmocka_unit_test(test_assertion_masked_bits_low),
		//cmocka_unit_test(test_assertion_masked_bits_high),
		//cmocka_unit_test(test_assertion_masked_bits_match),
		cmocka_unit_test(test_assertion_double_non_determinate),
		cmocka_unit_test(test_assertion_float_non_determinate),
		cmocka_unit_test(test_assertion_double_determinate),
		cmocka_unit_test(test_assertion_float_not_nan),
		cmocka_unit_test(test_assertion_double_nan),
		cmocka_unit_test(test_assertion_float_nan),
		cmocka_unit_test(test_assertion_double_not_negative_infinity),
		cmocka_unit_test(test_assertion_float_not_negative_infinity),
		cmocka_unit_test(test_assertion_double_negative_infinity),
		cmocka_unit_test(test_assertion_float_negative_infinity),
		cmocka_unit_test(test_assertion_double_not_infinity),
		cmocka_unit_test(test_assertion_float_not_infinity),
		cmocka_unit_test(test_assertion_double_infinity),
		cmocka_unit_test(test_assertion_float_infinity),
		cmocka_unit_test(test_assertion_double_equal),
		cmocka_unit_test(test_assertion_float_equal),
		cmocka_unit_test(test_assertion_hex32_equal),
		cmocka_unit_test(test_assertion_uint32_equal),
		cmocka_unit_test(test_assertion_int32_equal),
		cmocka_unit_test(test_assert_not_null),
		cmocka_unit_test(test_assert_null),
		cmocka_unit_test(test_assertion_boolean_false),
		cmocka_unit_test(test_assertion_boolean_true)
	};

	const int SIZE = sizeof(arr) / sizeof(arr[0]);

    struct CMUnitTest* tests = malloc(SIZE * sizeof(struct CMUnitTest));

	for (int i = 0; i < SIZE; i++)
		tests[i] = arr[i];

    return new_TestGroup(_setup, _teardown, tests, SIZE);
}


static void test_assertion_boolean_true(void** state)
{
	bool act = (NULL == NULL);
	assert_true(act);
}

static void test_assertion_boolean_false(void** state)
{
	bool act = (NULL != NULL);
	assert_false(act);
}

static void test_assert_null(void** state)
{
	int32_t* act = NULL;
	assert_null(act);
}

static void test_assert_not_null(void** state)
{
	int32_t act = 128;
	assert_non_null(&act);
}

static void test_assertion_int32_equal(void** state)
{
	int32_t exp = 128;
	assert_int_equal(exp, (int32_t)divide_by_half((int32_t)multiply_by_two(exp)));
	assert_int_equal(exp, (int32_t)square_root((int32_t)power_of_two(exp)));
}

static void test_assertion_uint32_equal(void** state)
{
	uint32_t exp = 128;
	assert_int_equal(exp, (uint32_t)divide_by_half((uint32_t)multiply_by_two(exp)));
	assert_int_equal(exp, (uint32_t)square_root((uint32_t)power_of_two(exp)));
}

static void test_assertion_hex32_equal(void** state)
{
	int32_t exp = 0x00000800u;
	assert_int_equal(exp, (int32_t)divide_by_half((int32_t)multiply_by_two(exp)));
	assert_int_equal(exp, (int32_t)square_root((int32_t)power_of_two(exp)));
}

static void test_assertion_float_equal(void** state)
{
	float exp = 128.000f;
	assert_float_equal(exp, (float)divide_by_half((float)multiply_by_two(exp)), 0.01f);
	assert_float_equal(exp, (float)square_root((float)power_of_two(exp)), 0.01f);
}

static void test_assertion_double_equal(void** state)
{
	double exp = 128.000;
	assert_float_equal(exp, (double)divide_by_half((double)multiply_by_two(exp)), 0.01f);
	assert_float_equal(exp, (double)square_root((double)power_of_two(exp)), 0.01f);
}

static void test_assertion_float_infinity(void** state)
{
	float act = INFINITY;
	assert_true(INFINITY == act);
}

static void test_assertion_double_infinity(void** state)
{
	double act = INFINITY;
	assert_true(INFINITY == act);
}

static void test_assertion_float_not_infinity(void** state)
{
	float act = 0.0f;
	assert_false(isinf(INFINITY) == isinf(act));
}

static void test_assertion_double_not_infinity(void** state)
{
	double act = 0.0;
	assert_false(isinf(INFINITY) == isinf(act));
}

static void test_assertion_float_negative_infinity(void** state)
{
	float act = -INFINITY;
	assert_true(-INFINITY == act);
}

static void test_assertion_double_negative_infinity(void** state)
{
	double act = -INFINITY;
	assert_true(-INFINITY == act);
}

static void test_assertion_float_not_negative_infinity(void** state)
{
	float act = -0.0f;
	assert_false(isinf(-INFINITY) == isinf(act));
}

static void test_assertion_double_not_negative_infinity(void** state)
{
	double act = -0.0;
	assert_false(isinf(-INFINITY) == isinf(act));
}

static void test_assertion_float_nan(void** state)
{
	float divider = 0.0f;
	float act = 0.0f / divider;
	assert_true(isnan(act));
}

static void test_assertion_double_nan(void** state)
{
	double divider = 0.0;
	double act = 0.0 / divider;
	assert_true(isnan(act));
}

static void test_assertion_float_not_nan(void** state)
{
	float act = 0.0f;
	assert_true(!isnan(act));
}

static void test_assertion_double_not_nan(void** state)
{
	double act = 0.0;
	assert_true(!isnan(act));
}


static void test_assertion_float_determinate(void** state)
{
	float act = 0.0f;
	assert_true(!isnan(act) && isfinite(act));
}

static void test_assertion_double_determinate(void** state)
{
	double act = 0.0;
	assert_true(!isnan(act) && isfinite(act));
}

static void test_assertion_float_non_determinate(void** state)
{
	float act = INFINITY;
	assert_true(isnan(act) || !isfinite(act));
}

static void test_assertion_double_non_determinate(void** state)
{
	double act = INFINITY;
	assert_true(isnan(act) || !isfinite(act));
}

static void test_assertion_masked_bits_match(void** state)
{
	int32_t mask = 0b00001111;
	int32_t exp = 0b10101111;
	int32_t act = 0b01011111;

	//TEST_ASSERT_BITS(mask, exp, act);
}

static void test_assertion_masked_bits_high(void** state)
{
	int32_t mask = 0b00001111;
	int32_t exp = 0b10101111; /* Not used in Unity */
	int32_t act = 0b01011111;

	//TEST_ASSERT_BITS_HIGH(mask, act);
}

static void test_assertion_masked_bits_low(void** state)
{
	int32_t mask = 0b00001111;
	int32_t exp = 0b10100000; /* Not used in Unity */
	int32_t act = 0b10100000;

	//TEST_ASSERT_BITS_LOW(mask, act);
}

static void test_assertion_masked_bit_high(void** state)
{
	int32_t mask = 0b10000000;	/* Not used in Unity */

	int32_t bit = 7;
	int32_t exp = 0b00000000;	/* Not used in Unity */
	exp ^= 1UL << bit;			/* Not used in Unity */

	int32_t act = 0b10000000;

	//TEST_ASSERT_BIT_HIGH(bit, act);
}

static void test_assertion_masked_bit_low(void** state)
{
	int32_t mask = 0b10000000;	/* Not used in Unity */

	int32_t bit = 7;
	int32_t exp = 0b11111111;	/* Not used in Unity */
	exp &= ~(1UL << bit);		/* Not used in Unity */

	int32_t act = 0b01111111;

	//TEST_ASSERT_BIT_LOW(bit, act);
}


static void test_assertion_int32_range(void** state)
{
	int32_t delta = 128;
	int32_t exp = 256;
	int32_t act = exp + delta;

	assert_in_range(act, exp - delta, exp + delta);
}

static void test_assertion_uint32_range(void** state)
{
	uint32_t delta = 128;
	uint32_t exp = 256;
	uint32_t act = exp + delta;

	assert_in_range(act, exp - delta, exp + delta);
}

static void test_assertion_float_range(void** state)
{
	float delta = 128.000f;
	float exp = 256.000f;
	float act = exp + delta;

	assert_in_range(act, exp - delta, exp + delta);
}

static void test_assertion_double_range(void** state)
{
	double delta = 128.000;
	double exp = 256.000;
	double act = exp + delta;

	assert_in_range(act, exp - delta, exp + delta);
}

static void test_assertion_hex32_range(void** state)
{
	int32_t delta = 0x80u;
	int32_t exp = 0x100u;
	int32_t act = exp + delta;

	assert_in_range(act, exp - delta, exp + delta);
}

static void test_assertion_equal_ptr(void** state)
{
	int32_t value = 128;
	int32_t* exp = &value;
	int32_t* act = &*exp;

	assert_ptr_equal(exp, act);
}

static void test_assertion_equal_string(void** state)
{
	char exp[] = "assert";
	char act[] = "assert";

	assert_string_equal(exp, act);
}

static void test_assertion_equal_memory_block(void** state)
{
	const int32_t LENGTH = 10;
	int32_t* exp = (int32_t*)malloc(LENGTH * sizeof(int));

	if (!exp) {
		return;
	}

	int32_t* act = &*exp;
	assert_memory_equal(exp, act, LENGTH);
	free(act);
}

static void test_assertion_equal_int32_array(void** state)
{
	const int32_t LENGTH = 10;

	int32_t exp[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
	int32_t act[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

	for (size_t i = 0; i < LENGTH; i++) assert_int_equal(exp[i], act[i]);
}

static void test_assertion_equal_uint32_array(void** state)
{
	const int32_t LENGTH = 10;

	uint32_t exp[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
	uint32_t act[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

	for (size_t i = 0; i < LENGTH; i++) assert_int_equal(exp[i], act[i]);
}

static void test_assertion_equal_hex32_array(void** state)
{
	const int32_t LENGTH = 10;

	uint32_t exp[] = { 0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200 };
	uint32_t act[] = { 0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200 };

	for (size_t i = 0; i < LENGTH; i++) assert_int_equal(exp[i], act[i]);
}

static void test_assertion_equal_float_array(void** state)
{
	const int32_t LENGTH = 10;

	float exp[] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f };
	float act[] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f };

	for (size_t i = 0; i < LENGTH; i++) assert_float_equal(exp[i], act[i], 0.01f);
}

static void test_assertion_equal_double_array(void** state)
{
	const int32_t LENGTH = 10;

	double exp[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };
	double act[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };

	for (size_t i = 0; i < LENGTH; i++) assert_float_equal(exp[i], act[i], 0.01f);
}

static void test_assertion_equal_ptr_array(void** state)
{
	const int32_t LENGTH = 10;

	int32_t exp[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
	int32_t* act = &exp[0];

	for (size_t i = 0; i < LENGTH; i++) assert_ptr_equal(exp[i], act[i]);
}

static void test_assertion_equal_string_array(void** state)
{
	const int32_t LENGTH = 3;

	char* exp[] = { "assert1", "assert2", "assert3" };
	char* act[] = { "assert1", "assert2", "assert3" };

	for (size_t i = 0; i < LENGTH; i++) assert_string_equal(exp[i], act[i]);
}

static void test_assertion_equal_memory_block_array(void** state)
{
	const int32_t LENGTH = 32;
	const int32_t BLOCKS = 4;

	int32_t* exp = (int32_t*)malloc(LENGTH * BLOCKS * sizeof(int32_t));

	if (!exp) {
		return;
	}

	int32_t* act = &*exp;
	for (size_t i = 0; i < BLOCKS; i++) assert_memory_equal(&exp[i * LENGTH], &act[i * LENGTH], LENGTH);
	free(act);
}