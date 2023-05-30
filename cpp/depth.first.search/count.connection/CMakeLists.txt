cmake_minimum_required(VERSION 3.0.0)
project(myProject)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES main.cpp file_util/file_util.cpp graph_util/graph_util.cpp dfs_network/dfs_network.cpp)

set(HEADER file_util/file_util.hpp graph_util/graph_util.hpp dfs_network/dfs_network.hpp)

add_executable(myProject ${SOURCES} ${HEADER})
