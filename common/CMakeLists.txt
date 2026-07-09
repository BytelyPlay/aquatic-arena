cmake_minimum_required(VERSION 4.3)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

file(GLOB_RECURSE MODULE_INTERFACES
        "src/modules/*.ixx"
)

add_library(Common STATIC src/modules/utils/Concepts.ixx
        src/modules/utils/FileUtils.cpp
        src/modules/utils/Logger.cpp
        src/modules/vecs/Vec.cpp)

target_sources(
        Common
        PUBLIC
        FILE_SET CXX_MODULES FILES ${MODULE_INTERFACES}
)