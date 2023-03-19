cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)
project(Laba7)


file(GLOB SRC_FILES *.cpp)

enable_language(ASM_MASM)

set(ASM_SOURCES remainder.s)

set(SOURCES main.cpp ${ASM_SOURCES})

set_source_files_properties(${ASM_SOURCES} PROPERTIES LANGUAGE ASM_MASM)

add_executable(Laba7 ${SOURCES})

target_link_libraries(Laba7 gtest_main gmock spdlog)

#add_test(NAME Laba7 COMMAND Laba7)

