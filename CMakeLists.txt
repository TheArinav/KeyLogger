cmake_minimum_required(VERSION 3.16)
project(KeyLogger)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

# Get the kernel version using uname -r and store it in KERNEL_VERSION
execute_process(COMMAND uname -r OUTPUT_VARIABLE KERNEL_VERSION OUTPUT_STRIP_TRAILING_WHITESPACE)

# Include kernel headers based on the kernel version and architecture
include_directories(/usr/src/linux-headers-${KERNEL_VERSION}/include)
include_directories(/usr/src/linux-headers-${KERNEL_VERSION}/arch/x86/include)
include_directories(/usr/src/linux-headers-${KERNEL_VERSION}/arch/x86/include/generated)
include_directories(/usr/src/linux-headers-${KERNEL_VERSION}/arch/x86/include/uapi)

# Recursively find all .c, .cpp, .h, and .hpp files in the src directory
file(GLOB_RECURSE ALL_SOURCES
        "src/*.c"
        "src/*.cpp"
        "src/*.h"
        "src/*.hpp"
        )

# Add the executable
add_executable(KeyLogger ${ALL_SOURCES})
