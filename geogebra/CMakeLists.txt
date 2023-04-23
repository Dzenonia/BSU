cmake_minimum_required(VERSION 3.21)
project(geogebra)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)


set(SOURCES main.cpp mainwindow.cpp mainwindow.h graphwidjet.cpp)

#qt6_add_big_resources(RESOURCES)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME}
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )