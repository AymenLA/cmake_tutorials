cmake_minimum_required(VERSION 3.18)
message(STATUS "running Component cmakelists file")

add_library(component_lib include/Component.hpp
                          src/Component.cpp)
target_include_directories(component_lib PUBLIC include/)
message(STATUS "lib cmakelists file CMAKE CURRENT SOURCE DIR : ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "lib cmakelists file CMAKE SOURCE DIR : ${CMAKE_SOURCE_DIR}")
message(STATUS "lib cmakelists file CMAKE CURRENT BINARY DIR : ${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "lib cmakelists file CMAKE BINARY DIR : ${CMAKE_BINARY_DIR}")
set(TATA "tata is set in cmakelists of component_lib"  PARENT_SCOPE) 