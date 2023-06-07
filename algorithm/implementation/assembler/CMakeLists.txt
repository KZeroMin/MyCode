cmake_minimum_required(VERSION 3.0.0)
project(assembler)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES main.cpp)

add_executable(assembler ${SOURCES})