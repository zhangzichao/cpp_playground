set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
add_executable(thread main.cpp)

# TODO: how to achieve multiple windows
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lX11")
if(${Pangolin_FOUND})
  add_executable(multi_windows multi_win.cpp)
  target_link_libraries(multi_windows ${LINK_LIBS})
endif()
