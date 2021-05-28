
#ifndef TEST_INTERFACE_H
#define TEST_INTERFACE_H

#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmocka.h>

typedef struct TestGroup {
    CMFixtureFunction setup;
    CMFixtureFunction teardown;
    struct CMUnitTest *tests;
    int number_of_tests;
} TestGroup;

TestGroup new_TestGroup(CMFixtureFunction setup, CMFixtureFunction teardown, struct CMUnitTest* tests, int number_of_tests);
void destroy_TestGroup(TestGroup group);


#endif