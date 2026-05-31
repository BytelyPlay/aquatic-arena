cmake_minimum_required(VERSION 4.3)
project(AquaticEverything)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

add_subdirectory(renderingengine)
add_subdirectory(gameengine)
add_subdirectory(game)

# libs
add_subdirectory(libs/glfw)
add_subdirectory(libs/glm)

add_library(glad STATIC libs/glad/src/gl.c
        libs/stb_image/stb_image.cpp)
add_library(stb_image STATIC libs/stb_image/stb_image.cpp)

target_include_directories(stb_image PUBLIC libs/stb_image/include)
target_include_directories(glad PUBLIC libs/glad/include)