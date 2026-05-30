cmake_minimum_required(VERSION 4.3)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

file(GLOB_RECURSE MODULE_INTERFACES
        "src/modules/*.ixx"
)
find_package(OpenGL REQUIRED)

add_library(AquaRenderingEngine STATIC src/modules/AquaticRendering.cpp
        src/modules/AquaticRendering.ixx
        src/modules/utils/Logger.ixx
        src/modules/utils/Logger.cpp
        src/modules/shaders/Shader.ixx
        src/modules/api/vecs/Vec4.ixx
        src/modules/api/vecs/Vec4.cpp
        src/modules/concepts/Concepts.ixx
        src/modules/api/vecs/Vec4.ixx
        src/modules/vbo/VBO.ixx
        src/modules/vbo/VBO.cpp
        src/modules/vao/VAO.ixx
        src/modules/vao/VAO.cpp
        src/modules/meshes/Mesh.ixx
        src/modules/ebo/EBO.ixx
        src/modules/ebo/EBO.cpp
        src/modules/meshes/Mesh.cpp
)

target_link_libraries(AquaRenderingEngine PRIVATE glad GL glfw glm::glm)

target_sources(
        AquaRenderingEngine
        PUBLIC
        FILE_SET CXX_MODULES FILES ${MODULE_INTERFACES}
)