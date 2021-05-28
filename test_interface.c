#include "test_interface.h"
#include <stdio.h>

TestGroup new_TestGroup(CMFixtureFunction setup, CMFixtureFunction teardown, struct CMUnitTest* tests, int number_of_tests)
{
    TestGroup group;
    group.setup = setup;
    group.teardown = teardown;
    group.tests = tests;
    group.number_of_tests = number_of_tests;
    return group;
}

void destroy_TestGroup(TestGroup group)
{

}