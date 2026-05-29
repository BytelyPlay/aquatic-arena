cmake_minimum_required(VERSION 4.3)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

file(GLOB_RECURSE MODULE_INTERFACES
        "src/modules/*.ixx"
)

add_executable(AquaticArena src/main.cpp
        src/modules/LoggerImpl.ixx
        src/modules/LoggerImpl.cpp)

target_sources(
        AquaticArena
        PUBLIC
        FILE_SET CXX_MODULES FILES ${MODULE_INTERFACES}
)

target_link_libraries(AquaticArena PRIVATE AquaEngine)
