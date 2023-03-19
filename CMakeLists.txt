cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)
project(BSU)

#include(cmake/BuildConfig.cmake)

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

enable_testing()
include(cmake/ClangTidyCheck.cmake)

include_directories(queue)
include_directories(read)

add_subdirectory(queue)
add_subdirectory(read)
add_subdirectory(AssemblyTranslate)
add_subdirectory(Laba2)
add_subdirectory(Laba3)
add_subdirectory(Laba4)
add_subdirectory(Laba5)
add_subdirectory(Laba7)
add_subdirectory(kr1)
add_subdirectory(free_room)
add_subdirectory(string)


add_test(NAME BSU COMMAND BSU)
