cmake_minimum_required(VERSION 3.17)
project(bomberman)
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -lstdc++fs")
set(CMAKE_CXX_STANDARD 17)

if (win32)
  INCLUDE(FetchContent)
  FetchContent_Declare(raylib URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz)
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED)
    SET(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    SET(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    ADD_SUBDIRECTORY(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    SET(raylib_FOUND TRUE)
  endif()
endif()

find_package(raylib 4.0.0 QUIET)

FILE(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR}
  "src/*.cpp"
  "src/map/*.cpp"
  "src/game control/*.cpp"
  "src/graphics/*.cpp"
  "src/graphics/Objects/*.cpp"
)

INCLUDE_DIRECTORIES(
  "${CMAKE_CURRENT_SOURCE_DIR}/src/"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/graphics/"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/graphics/Objects/"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/graphics/Entities/"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/game control/"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/game control/Enemy"
)

add_executable(bomberman ${SOURCES})
target_link_libraries(bomberman raylib)
