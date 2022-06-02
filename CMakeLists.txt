cmake_minimum_required(VERSION 3.17)
project(bomberman)

FIND_PACKAGE(raylib REQUIRED)

FILE(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")
add_executable(bomberman ${SOURCES})
target_link_libraries(bomberman raylib)

if (NOT raylib_FOUND)
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




#FIND_PACKAGE(raylib REQUIRED) TARGET_LINK_LIBRARIES(target_name raylib) CMAKE_MINIMUM_REQUIRED(VERSION 3.11)
#if (NOT raylib_FOUND) INCLUDE(FetchContent) FetchContent_Declare(raylib URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz)
#FetchContent_GetProperties(raylib) if (NOT raylib_POPULATED) SET(FETCHCONTENT_QUIET NO) FetchContent_Populate(raylib) SET(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
#ADD_SUBDIRECTORY(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR}) SET(raylib_FOUND TRUE) endif() endif()
