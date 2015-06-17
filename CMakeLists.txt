cmake_minimum_required(VERSION 2.8)
project(cpp_playground)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O0")

# package
find_package(Pangolin 0.1 QUIET)
if(${Pangolin_FOUND})
  message("Pangolin found: ${Pangolin_LIBRARIES}.")
  add_definitions(-DUSE_PANGOLIN)
  list(APPEND LINK_LIBS  ${Pangolin_LIBRARIES})
  list(APPEND INCLUDE_DIRS ${Pangolin_INCLUDE_DIRS})
else()
  message("Pangolin not found.")
endif()

include_directories(utils ${INCLUDE_DIRS})

add_subdirectory(virtual_function)
add_subdirectory(thread)
add_subdirectory(cache)
add_subdirectory(misc)

add_subdirectory(utils)
