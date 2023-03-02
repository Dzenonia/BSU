cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)
project(Laba5)


file(GLOB SRC_FILES *.cpp)
add_executable(Laba5 ${SRC_FILES})
target_link_libraries(Laba5 gtest_main gmock spdlog)

add_test(NAME Laba5 COMMAND Laba5)

