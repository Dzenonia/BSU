cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)
project(Laba4)


file(GLOB SRC_FILES *.cpp)
add_executable(Laba4 ${SRC_FILES})
target_link_libraries(Laba4 gtest_main gmock spdlog)

add_test(NAME Laba4 COMMAND Laba4)

