cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)
project(kr1)


file(GLOB SRC_FILES *.cpp)
add_executable(kr1 ${SRC_FILES})
target_link_libraries(kr1 gtest_main gmock spdlog)

add_test(NAME kr1 COMMAND kr1)

