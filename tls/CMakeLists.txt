cmake_minimum_required(VERSION 3.23)
project(tls_core)

file(GLOB SOURCE "src/*")
file(GLOB TEST_SOURCE "gtest/*")

add_executable(${PROJECT_NAME} ${SOURCE})
add_executable(${PROJECT_NAME}_test ${TEST_SOURCE})

target_link_libraries(${PROJECT_NAME} PRIVATE 
    fmt::fmt
    ${GMP_LIBRARY}
    # nettle
)
target_include_directories(${PROJECT_NAME} PRIVATE 
    ${GMP_INCLUDE_DIR}
    # ${NETTLE_INCLUDE_DIR}
)

# For testing
target_link_libraries(${PROJECT_NAME}_test PRIVATE 
    gtest_main
)