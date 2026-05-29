cmake_minimum_required(VERSION 4.3)
project(AquaticEverything)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

add_subdirectory(renderingengine)
add_subdirectory(gameengine)
add_subdirectory(game)

# Only AquaRenderingEngine is allowed to depend on this.
add_subdirectory(libs/glfw)

add_library(glad STATIC libs/glad/src/gl.c)
target_include_directories(glad PUBLIC libs/glad/include)