#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmocka.h>

#include "tests/test_assertions.h"
#include "tests/test_extensibility.h"
#include "tests/test_fixtures.h"
#include "tests/test_mocking.h"

int main()
{
    const TestGroup assertions = create_test_assertions();
    const TestGroup extensibility = create_test_extensibility();
    const TestGroup fixtures = create_test_fixtures();
    const TestGroup mocking = create_test_mocking();

    _cmocka_run_group_tests("assertions.tests", assertions.tests, assertions.number_of_tests, assertions.setup, assertions.teardown);
    printf("\n\n");
    _cmocka_run_group_tests("extensibility.tests", extensibility.tests, extensibility.number_of_tests, extensibility.setup, extensibility.teardown);
    printf("\n\n");
    _cmocka_run_group_tests("fixtures.tests", fixtures.tests, fixtures.number_of_tests, fixtures.setup, fixtures.teardown);
    printf("\n\n");
    _cmocka_run_group_tests("mocking.tests", mocking.tests, mocking.number_of_tests, mocking.setup, mocking.teardown);

    return 0;
}