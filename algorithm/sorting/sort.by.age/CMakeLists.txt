cmake_minimum_required(VERSION 3.0.0)
project(sort_by_age)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES 
    main.cpp 
    file.io/file.io.cpp
    )

set(HEADERS 
    file.io/file.io.hpp
    )

add_executable(sort_by_age ${SOURCES} ${HEADERS})
