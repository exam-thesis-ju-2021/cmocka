#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "cmocka.h"

void initialize_hardware()
{
	return mock();
}

void reset_hardware()
{
	return mock();
}

double divide_by_half(double value)
{
	return (double)mock();
}

double multiply_by_two(double value)
{
	return (double)mock();
}

double power_of_two(double value)
{
	return (double)mock();
}

double square_root(double value)
{
	return (double)mock();
}