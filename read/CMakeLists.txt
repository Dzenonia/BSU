cmake_minimum_required(VERSION 3.22)

project(read)

enable_testing()

file(GLOB SRC_FILES *.cpp)
#add_executable(read ${SRC_FILES})
add_library(read ${SRC_FILES})
target_link_libraries(read gtest_main gmock)

add_test(NAME read COMMAND read)