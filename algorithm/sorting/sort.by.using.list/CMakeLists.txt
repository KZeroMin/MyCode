cmake_minimum_required(VERSION 3.0.0)
project(list_sort)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES 
    main.cpp 
    file.io/file.io.cpp
    )

set(HEADERS 
    file.io/file.io.hpp
    )

add_executable(list_sort ${SOURCES} ${HEADERS})
