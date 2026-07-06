cmake_minimum_required(VERSION 4.3)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

file(GLOB_RECURSE MODULE_INTERFACES
        "src/modules/*.ixx"
)

add_library(AquaRenderingEngineApi STATIC
        src/modules/utils/Concepts.ixx
        src/modules/AquaticRendering.ixx
        src/modules/renderable/Renderable.ixx
        src/modules/utils/RenderableAccessor.ixx
        src/modules/vecs/Vec.cpp
        src/modules/renderable/RenderableSnapshot.ixx
        src/modules/utils/RenderableAccessor.cpp
        src/modules/AquaticRendering.cpp
)

target_link_libraries(AquaRenderingEngineApi PRIVATE AquaRenderingEngineImpl)

target_sources(
        AquaRenderingEngineApi
        PUBLIC
        FILE_SET CXX_MODULES FILES ${MODULE_INTERFACES}
)