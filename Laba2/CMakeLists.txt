cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)
project(Laba2)


file(GLOB SRC_FILES *.cpp ../read/read.cpp)
add_executable(Laba2 ${SRC_FILES})
target_link_libraries(Laba2 gtest_main gmock spdlog)
#target_include_directories(AssemblyTranslate ../read/read.h ../queue/queue.h)

add_test(NAME Laba2 COMMAND Laba2)

