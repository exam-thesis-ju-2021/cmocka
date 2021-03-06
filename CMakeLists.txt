# Copyright 2020 OLIVIER LE DOEUFF
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software
# and associated documentation files (the "Software"), to deal in the Software without restriction,
# including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
# subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all copies or
# substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
# DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH
# THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(CMockaExample VERSION 1.0 LANGUAGES C)

include(cmake/FetchCMocka.cmake)

add_library(lib src/hardware.c
			src/module_a.c
			src/peripheral.c
			src/peripherals.c
			src/peripherals/divide_by_half.c
			src/peripherals/multiply_by_two.c
			src/peripherals/power_of_two.c
			src/peripherals/square_root.c)

add_executable(CMockaExample 
	"tests.c"  
	"tests/test_assertions.c" 
	"tests/test_assertions.h" 
	"test_interface.h" 
	"test_interface.c" 
	"tests/test_extensibility.h" 
	"tests/test_extensibility.c" 
	"tests/test_fixtures.h" 
	"tests/test_fixtures.c" 
	"tests/test_mocking.c" 
	"mocks/mock_module_a.h" 
	"mocks/mock_module_a.c")

target_compile_features(CMockaExample PRIVATE c_std_99)
target_link_libraries(CMockaExample PRIVATE cmocka-static lib)

enable_testing()
add_test(NAME CMockaExample COMMAND CMockaExample)


