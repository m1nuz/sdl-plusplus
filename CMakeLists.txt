cmake_minimum_required(VERSION 3.0)
project(sdl-plusplus)

include_directories(include)
file(GLOB sources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
     src/*.cpp)
file(GLOB headers RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
     include/sdl/*.*)

add_definitions(-D_GLIBCXX_HAVE_GETS)

add_library(sdlplusplus ${headers} ${sources})
set_property(TARGET sdlplusplus PROPERTY CXX_STANDARD 14)

add_executable(window-example ${CMAKE_CURRENT_SOURCE_DIR}/examples/window.cpp)
set_property(TARGET window-example PROPERTY CXX_STANDARD 14)
set_property(TARGET window-example APPEND_STRING PROPERTY COMPILE_FLAGS ${cpp_flags})
target_link_libraries(window-example sdlplusplus -lSDL2)

add_executable(opengl-example ${CMAKE_CURRENT_SOURCE_DIR}/examples/opengl.cpp)
set_property(TARGET opengl-example PROPERTY CXX_STANDARD 14)
set_property(TARGET opengl-example APPEND_STRING PROPERTY COMPILE_FLAGS ${cpp_flags})
target_link_libraries(opengl-example sdlplusplus -lSDL2 -lGL)

