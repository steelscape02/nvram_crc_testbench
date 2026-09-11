cmake_minimum_required(VERSION 3.10)
project(nvram_crc_testbench C)

# Enforce C99 standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Enable compiler warnings
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Werror)
endif()

# Include directories
include_directories(include tests)

# Source files for the core library
set(LIB_SOURCES
    src/crc.c
    src/nvram_manager.c
)

# Test executable source files
set(TEST_SOURCES
    tests/mock_nvram.c
    tests/test_main.c
)

# Build the desktop test runner
add_executable(unit_tests ${LIB_SOURCES} ${TEST_SOURCES})