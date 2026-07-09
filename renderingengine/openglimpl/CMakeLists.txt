cmake_minimum_required(VERSION 4.3)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

add_subdirectory(api)

file(GLOB_RECURSE MODULE_INTERFACES
        "src/modules/*.ixx"
)
find_package(OpenGL REQUIRED)

add_library(OpenGLEngineImpl STATIC api/src/modules/OpenGLRenderingEngine.cpp
        api/src/modules/OpenGLRenderingEngine.ixx
        src/modules/shaders/Shader.ixx
        src/modules/vbo/VBO.ixx
        src/modules/vbo/VBO.cpp
        src/modules/vao/VAO.ixx
        src/modules/vao/VAO.cpp
        src/modules/meshes/CompilableMesh.ixx
        src/modules/ebo/EBO.ixx
        src/modules/ebo/EBO.cpp
        src/modules/meshes/CompilableMesh.cpp
        src/modules/meshes/CompilableMesh.cpp
        src/modules/textures/Texture.ixx
        src/modules/textures/Texture.cpp
        src/modules/vbo/SimpleVBO.ixx
        src/modules/vbo/SimpleVBO.cpp
        src/modules/shaders/Shader.cpp
        src/modules/vao/SimpleVAO.ixx
        src/modules/vao/SimpleVAO.cpp
        src/modules/utils/OpenGLUtils.ixx
        src/modules/utils/OpenGLUtils.cpp
        src/modules/models/CompilableModel.ixx
        src/modules/models/CompilableModel.cpp
        src/modules/ebo/SimpleEBO.ixx
        src/modules/ebo/SimpleEBO.cpp
)

target_link_libraries(OpenGLEngineImpl PRIVATE
        glad GL glfw glm::glm stb_image AquaRenderingEngineApi Common)

target_sources(
        OpenGLEngineImpl
        PUBLIC
        FILE_SET CXX_MODULES FILES ${MODULE_INTERFACES}
)