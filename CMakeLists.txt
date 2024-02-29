cmake_minimum_required(VERSION 3.5)

project(Graphic VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Concurrent PrintSupport)

include_directories(qcustomplot)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        graphwindow.ui
        graphwindow.h
        graphwindow.cpp
        graphic.h
        graphic.cpp
)

add_executable(Graphic
    ${PROJECT_SOURCES}

)

set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")

add_subdirectory(qcustomplot)

target_link_libraries(Graphic Qt6::Widgets Qt6::Concurrent Qt6::PrintSupport qcustomplot)


