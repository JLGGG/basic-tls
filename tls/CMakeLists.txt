MESSAGE(STATUS "===============================")
MESSAGE(STATUS "TLS Core Configuration")
MESSAGE(STATUS "===============================")
project(tls)

file(GLOB SOURCE CONFIGURE_DEPENDS "src/*")

add_library(${PROJECT_NAME} STATIC ${SOURCE})

target_link_libraries(${PROJECT_NAME} PUBLIC 
    fmt::fmt
    ${GMP_LIBRARY}
)
target_include_directories(${PROJECT_NAME} PUBLIC 
    src
    ${GMP_INCLUDE_DIR}
)

# For testing
if(INSTALL_GTEST)
    MESSAGE(STATUS "GTEST ON")

    file(GLOB TEST_SOURCE CONFIGURE_DEPENDS "gtest/*")

    add_executable(${PROJECT_NAME}_test ${TEST_SOURCE})
    target_link_libraries(${PROJECT_NAME}_test PRIVATE 
        gtest_main
        ${PROJECT_NAME}
        ${GMP_LIBRARY}
    )
    target_include_directories(${PROJECT_NAME}_test PRIVATE 
        ${GMP_INCLUDE_DIR}
    )
endif()