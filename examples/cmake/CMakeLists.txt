cmake_minimum_required(VERSION 3.12)
project(essl_strip_demo CXX)

find_program(RE2C_EXECUTABLE NAMES re2c REQUIRED)

set(GENERATED ${CMAKE_CURRENT_BINARY_DIR}/essl_strip.cpp)
add_custom_command(
    OUTPUT ${GENERATED}
    COMMAND ${RE2C_EXECUTABLE} -c -i -o ${GENERATED} ${CMAKE_CURRENT_SOURCE_DIR}/essl_strip.re
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/essl_strip.re
    VERBATIM)

add_library(essl_strip ${GENERATED})
target_include_directories(essl_strip PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(essl_strip_demo main.cpp)
target_link_libraries(essl_strip_demo essl_strip)

add_executable(essl_strip_tests tests.cpp)
target_link_libraries(essl_strip_tests essl_strip)

enable_testing()
add_test(NAME essl_strip_tests COMMAND essl_strip_tests)
