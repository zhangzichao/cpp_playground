cmake_minimum_required(VERSION 2.8)
project(cpp_playground)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O0")

include_directories(utils ${INCLUDE_DIRS})

add_subdirectory(virtual_function)
add_subdirectory(utils)
