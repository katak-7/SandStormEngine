cmake_minimum_required(VERSION 4.0)
project(SandStormEngine)

set(CMAKE_CXX_STANDARD 20)

add_executable(SandStormEngine main.cpp
        Engine/engine.cpp
        Engine/engine.h
        Engine/System/system.h
        Engine/System/system_render.cpp
        Engine/System/system_render.h)
