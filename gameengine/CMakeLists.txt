cmake_minimum_required(VERSION 4.3)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

file(GLOB_RECURSE MODULE_INTERFACES
        "src/modules/*.ixx"
)

add_library(AquaEngine STATIC src/modules/AquaEngine.cpp)

target_sources(
        AquaEngine
        PUBLIC
        FILE_SET CXX_MODULES FILES ${MODULE_INTERFACES}
)
target_link_libraries(AquaEngine PRIVATE AquaRenderingEngine)