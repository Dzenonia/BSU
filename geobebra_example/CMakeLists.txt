cmake_minimum_required(VERSION 3.21)
project(geobebra_example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(geobebra_example
        main.cpp
        main_window.cpp
        paint_widget.cpp
        plot_descriptor_widget.cpp
        )

target_link_libraries(geobebra_example
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )