cmake_minimum_required(VERSION 4.3)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

file(GLOB_RECURSE MODULE_INTERFACES
        "src/modules/*.ixx"
)
find_package(OpenGL REQUIRED)

add_library(AquaRenderingEngineApi STATIC
        src/modules/utils/Concepts.ixx
)

target_link_libraries(AquaRenderingEngineApi PRIVATE glad GL glfw glm::glm stb_image)

target_sources(
        AquaRenderingEngineApi
        PUBLIC
        FILE_SET CXX_MODULES FILES ${MODULE_INTERFACES}
)