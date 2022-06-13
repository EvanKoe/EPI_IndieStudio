cmake_minimum_required(VERSION 3.17)
project(bomberman)
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -lstdc++fs")
set(CMAKE_CXX_STANDARD 17)

SET(raylib_FOUND TRUE)

if (UNIX)
  SET(CMAKE_CXX_FLAGS "-g")
endif()

find_package(raylib 4.0.0 QUIET)
  if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
      raylib
      URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED)
      set(FETCHCONTENT_QUIET NO)
      FetchContent_Populate(raylib)
      set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
      add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
  endif()

FILE(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR}
  "src/*.cpp"
  "src/map/*.cpp"
  "src/engine/*.cpp"
        "src/engine/objects/*.cpp"
        "src/engine/objects/Bomb/*.cpp"
        "src/engine/objects/PowerUp/*.cpp"
        "src/engine/objects/Entities/*.cpp"
        "src/engine/objects/Entities/Enemy/*.cpp"
        "src/engine/objects/Entities/Player/*.cpp"
        "src/graphics/*.cpp"
  "src/graphics/Objects/*.cpp"
)

INCLUDE_DIRECTORIES(
  "${CMAKE_CURRENT_SOURCE_DIR}/src/"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/graphics/"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/graphics/Objects/"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/graphics/Entities/"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/engine/"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/engine/objects/"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/engine/objects/PowerUp/"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/engine/objects/Bomb/"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/engine/objects/Entities/"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/engine/objects/Entities/Player/"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/engine/objects/Entities/Enemy/"
)

add_executable(bomberman ${SOURCES})
target_link_libraries(bomberman raylib)
