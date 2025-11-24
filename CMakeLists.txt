cmake_minimum_required(VERSION 4.0)
project(SandStormEngine)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(SandStormEngine main.cpp
        Engine/engine.cpp
        Engine/engine.h
        Engine/system.h
        Engine/system_render.cpp
        Engine/system_render.h)

target_link_libraries(SandStormEngine ${SDL2_LIBRARIES})
