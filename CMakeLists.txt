cmake_minimum_required(VERSION 3.23)
project(bomberman)

find_package(raylib 3.0 REQUIRED)

add_executable(bomberman src/main.cpp src/graphics/Graphics.cpp)
target_link_libraries(bomberman raylib)
