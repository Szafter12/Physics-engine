cmake_minimum_required(VERSION 3.10)
project(Engine C)

set(CMAKE_C_STANDARD 11)

add_executable(${PROJECT_NAME} src/main.c
        src/Engine/Engine.c
        src/Engine/Engine.h
        src/Engine/Physics.c
        src/Engine/Physics.h
        src/Engine/World.c
        src/Engine/World.h)

find_package(raylib CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

