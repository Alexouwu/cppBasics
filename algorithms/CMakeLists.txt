cmake_minimum_required(VERSION 3.18)

project(algorithms)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

add_executable(algorithms algorithms.cpp)

target_compile_features(algorithms PRIVATE cxx_std_17)
