cmake_minimum_required(VERSION 3.0.0)
project(text_io)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES main.cpp util/file.io.cpp)

set(HEADERS util/file.io.hpp)

add_executable(text_io ${SOURCES} ${HEADERS})
