cmake_minimum_required(VERSION 3.28)
project(SnakeRaylib)

set(CMAKE_CXX_STANDARD 23)

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games

add_subdirectory(lib/raylib) # Copy the folder in this directory to you project

add_executable(SnakeRaylib main.cpp) # <---
target_link_libraries(SnakeRaylib PRIVATE raylib) # Rename SnakeRaylib to your project name
target_compile_definitions(SnakeRaylib PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/")