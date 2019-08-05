cmake_minimum_required(VERSION 2.8)

project(boost_asio C CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -g -Wall -o0 -Wno-unused-variable -pthread")
include_directories(/usr/local/include/boost)
link_directories(/usr/local/lib)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_subdirectory(src)


