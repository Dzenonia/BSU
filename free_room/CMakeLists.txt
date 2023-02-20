cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)
project(myRoom)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)

FetchContent_MakeAvailable(googletest)

include(FetchContent)
FetchContent_Declare(
        spdlog
        URL https://github.com/gabime/spdlog/archive/refs/heads/v1.x.zip
)

FetchContent_MakeAvailable(spdlog)

file(GLOB SRC_FILES *.cpp)
add_executable(myRoom ${SRC_FILES})
target_link_libraries(myRoom gtest_main gmock spdlog)

add_test(NAME myRoom COMMAND myRoom)
