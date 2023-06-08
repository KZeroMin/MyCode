cmake_minimum_required(VERSION 3.0.0)
project(assembler)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES main.cpp file.io.cpp)

set(HEADERS file.io.hpp)

add_executable(assembler ${SOURCES})