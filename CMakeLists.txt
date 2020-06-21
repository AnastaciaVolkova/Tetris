cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")
set( CMAKE_AUTOMOC ON )
project(tetris)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Gui REQUIRED)

QT5_WRAP_CPP(MOC_Files
  src/view_qt.hpp
  src/view_qt.cpp
)
add_executable(tetris src/main.cpp src/view_qt.cpp src/view_qt.hpp src/model.cpp src/figure.cpp src/figure1.cpp src/figure2.cpp src/controller.cpp src/point.cpp src/figure4.cpp src/pile.cpp ${MOC_Files})

target_link_libraries(tetris Qt5::Widgets Qt5::Gui)
