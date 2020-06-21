cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(tetris)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(Qt5 COMPONENTS Widgets REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

add_executable(tetris src/main.cpp src/view_qt.cpp src/model.cpp src/figure.cpp src/figure1.cpp src/figure2.cpp src/controller.cpp src/point.cpp src/figure4.cpp src/pile.cpp)

target_link_libraries(tetris Qt5::Widgets)
