cmake_minimum_required(VERSION 3.23)
project(tls_main)

include(FetchContent)

set(CMAKE_CXX_STANDARD 17)

# Manually set the GMP library and include paths
set(GMP_LIBRARY "/usr/local/lib/libgmp.dylib") 
set(GMP_INCLUDE_DIR "/usr/local/include")  

# # Find Nettle
# find_package(Nettle REQUIRED)

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

add_subdirectory(tls)

