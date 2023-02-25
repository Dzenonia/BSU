cmake_minimum_required(VERSION 3.22)

project(queue)

enable_testing()

file(GLOB SRC_FILES *.cpp)

#add_executable(queue ${SRC_FILES})
add_library(queue ${SRC_FILES})
target_link_libraries(queue gtest_main gmock)
add_test(NAME queue COMMAND queue)