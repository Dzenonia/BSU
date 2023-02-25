cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)
project(myRoom)

file(GLOB SRC_FILES *.cpp)
add_executable(myRoom ${SRC_FILES})
target_link_libraries(myRoom gtest_main gmock spdlog queue read)

#add_test(NAME myRoom COMMAND myRoom)
