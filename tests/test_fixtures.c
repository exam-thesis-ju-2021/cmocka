#include "test_extensibility.h"
#include <stdbool.h>

static void test_verification(void** state);

static CMFixtureFunction _setup(void** state)
{
	printf("Verifying that setup() is executed.\n");
	return 0;
}

static CMFixtureFunction _teardown(void** state)
{
	printf("Verifying that teardown() is executed.\n");
	return 0;
}

TestGroup create_test_fixtures()
{
	const struct CMUnitTest arr[] = {
		cmocka_unit_test(test_verification)
	};

	const int SIZE = sizeof(arr) / sizeof(arr[0]);

	struct CMUnitTest* tests = malloc(SIZE * sizeof(struct CMUnitTest));

	for (int i = 0; i < SIZE; i++)
		tests[i] = arr[i];

	return new_TestGroup(_setup, _teardown, tests, SIZE);
}

static void test_verification(void** state)
{
	assert_true(true);
	printf("Verifying that test_fixtures() has been run in between setup() and tearDown().\n");
}
