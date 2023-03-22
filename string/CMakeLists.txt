cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 23)
project(string)


file(GLOB SRC_FILES *.cpp)
add_executable(string ${SRC_FILES})
target_link_libraries(string gtest_main gmock spdlog)

add_test(NAME string COMMAND string)

