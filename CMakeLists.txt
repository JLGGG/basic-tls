cmake_minimum_required(VERSION 3.23)
project(tls_main)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Manually set the GMP library and include paths
include_directories("/usr/local/include")
include_directories("/usr/local/lib")
set(GMP_LIBRARY "/usr/local/lib/libgmp.a")
set(GMPXX_LIBRARY "/usr/local/lib/libgmpxx.a")

message("CMAKE_C_COMPILER: ${CMAKE_C_COMPILER}")
message("CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")

include(FetchContent)
# Set CMP0135 policy to NEW to avoid the warning
cmake_policy(SET CMP0135 NEW)
FetchContent_Declare(fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 9.1.0
)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
set(gtest_build_tests OFF CACHE BOOL "Enable gtest tests" FORCE)

FetchContent_Declare(
  googlebenchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG        v1.8.0
)
set(benchmark_enable_testing OFF CACHE BOOL "Enable gbench tests" FORCE)

FetchContent_MakeAvailable(googletest googlebenchmark)

# Also requires one of: libbfd (gnu binutils), libdwarf, libdw (elfutils)
# When using a stack trace, you must link ${BACKWARD_ENABLE} to the add_library or add_executable command.
# And then, you must call an add_bacward(${PROJECT_NAME}). 
FetchContent_Declare(backward
        GIT_REPOSITORY https://github.com/bombela/backward-cpp
        GIT_TAG v1.6)
FetchContent_MakeAvailable(backward)

# Set compiler flags
add_compile_options(-W -Wall)

add_subdirectory(tls)

