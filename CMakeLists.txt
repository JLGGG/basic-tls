cmake_minimum_required(VERSION 3.23)
project(tls_main)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Manually set the GMP library and include paths
# include_directories("/usr/local/include")
# include_directories("/usr/local/lib")
# set(GMP_LIBRARY "/usr/local/lib/libgmp.a")
# set(GMPXX_LIBRARY "/usr/local/lib/libgmpxx.a")

include_directories("/opt/homebrew/Cellar/gmp/6.2.1_1/include")
include_directories("/opt/homebrew/Cellar/gmp/6.2.1_1/lib")
set(GMP_LIBRARY "/opt/homebrew/Cellar/gmp/6.2.1_1/lib/libgmp.a")
set(GMPXX_LIBRARY "/opt/homebrew/Cellar/gmp/6.2.1_1/lib/libgmpxx.a")

set(CMAKE_C_COMPILER /usr/bin/gcc CACHE PATH "" FORCE)
set(CMAKE_CXX_COMPILER /usr/bin/g++ CACHE PATH "" FORCE)
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
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

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

