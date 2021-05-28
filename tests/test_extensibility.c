#include "test_extensibility.h"
#include "../src/module_a.h"
#include "../src/peripherals.h"
#include "../src/hardware.h"
#include "../src/peripheral.h"
#include "../src/peripherals/divide_by_half.h"
#include "../src/peripherals/multiply_by_two.h"
#include "../src/peripherals/power_of_two.h"
#include "../src/peripherals/square_root.h"

void assert_pin_state(PinState expected, uint16_t gpio);

static void test_extensibility(void** state);


static CMFixtureFunction _setup(void** state)
{
	hw_init();
    return 0;
}

static CMFixtureFunction _teardown(void** state)
{
	hw_reset();
    return 0;
}


TestGroup create_test_extensibility()
{
	const struct CMUnitTest arr[] = {
		cmocka_unit_test(test_extensibility)
	};

	const int SIZE = sizeof(arr) / sizeof(arr[0]);

	struct CMUnitTest* tests = malloc(SIZE * sizeof(struct CMUnitTest));

	for (int i = 0; i < SIZE; i++)
		tests[i] = arr[i];

	return new_TestGroup(_setup, _teardown, tests, SIZE);
}


static void test_extensibility(void** state)
{
	uint16_t pin = 4;
	digital_write(pin, HIGH);
	assert_pin_state(HIGH, 4);
}

void assert_pin_state(PinState expected, uint16_t gpio)
{
	printf("Executing extended assertion...\n");

	char* output = (char*)malloc(128 * sizeof(char));
	if (!output) {
		mock_assert(-1, "Failed to allocate memory for 'char* output'\n", "test_extensibility.c", 40);
		return;
	}

	if (digital_read(gpio) == expected)
	{
		sprintf(output, "Custom assertion '%s' passed.\n", __func__);
		print_message(output);
		assert_true(true);
	}
	else
	{
		sprintf(output, "Custom assertion '%s' failed.\n", __func__);
		print_message(output);
		assert_true(false);
	}

	free(output);
}