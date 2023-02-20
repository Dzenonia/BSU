cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)
project(AssemblyTranslate)


file(GLOB SRC_FILES *.cpp ../read/read.cpp)
add_executable(AssemblyTranslate ${SRC_FILES})
target_link_libraries(AssemblyTranslate gtest_main gmock spdlog)
#target_include_directories(AssemblyTranslate ../read/read.h ../queue/queue.h)

add_test(NAME AssemblyTranslate COMMAND AssemblyTranslate)
