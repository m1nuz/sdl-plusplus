cmake_minimum_required(VERSION 2.8)
project(sdl-plusplus)

list(APPEND CMAKE_CXX_FLAGS "-std=c++11 -g -Wall")

include_directories(include)
file(GLOB sources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
     src/*.cpp)
file(GLOB headers RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
     include/*.*)

add_library(sdlplusplus ${headers} ${sources})

add_executable(window-example ${CMAKE_CURRENT_SOURCE_DIR}/examples/window.cpp)
target_link_libraries(window-example sdlplusplus -lSDL2)

add_executable(opengl-example ${CMAKE_CURRENT_SOURCE_DIR}/examples/opengl.cpp)
target_link_libraries(opengl-example sdlplusplus -lSDL2 -lGL)
