cmake_minimum_required(VERSION 3.8)
project(powerFour)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Grid.cpp Grid.h PowerFour.cpp PowerFour.h Colors.h)
add_executable(powerFour ${SOURCE_FILES})