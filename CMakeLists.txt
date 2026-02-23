cmake_minimum_required(VERSION 3.29)
project(cool_raylib C)

set(CMAKE_C_STANDARD 99)

find_package(raylib CONFIG REQUIRED)

add_executable(cool_raylib main.c
        window.c)


target_link_libraries(cool_raylib PRIVATE raylib)