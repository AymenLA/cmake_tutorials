cmake_minimum_required(VERSION 3.18)
project(MYBINARYAPP VERSION 0.1)

set(PRODUCT_NAME "MYBINARYAPP")
set(PRODUCTION_YEAR 2022)
set(PRODUCTION_WEEK 34)

message(STATUS "Main cmakelists file CMAKE CURRENT SOURCE DIR : ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "Main cmakelists file CMAKE SOURCE DIR : ${CMAKE_SOURCE_DIR}")
message(STATUS "Main cmakelists file CMAKE CURRENT BINARY DIR : ${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "Main cmakelists file CMAKE BINARY DIR : ${CMAKE_BINARY_DIR}")

if(DEBUG)
    message(STATUS "DEBUG build")
else()
    message(STATUS "PRODUCTION build")
    set(DEBUG 0)
endif()

add_subdirectory(${CMAKE_SOURCE_DIR}/lib)

if(NOT TARGET component_lib)
    message(FATAL_ERROR "target component_lib not avalable")
endif()

message(STATUS "running Main application cmakelists file")
set(SRC_FILES main.cpp 
              src/Sum.cpp)
set(INCLUDE_DIRS include/ lib/)

configure_file(${CMAKE_SOURCE_DIR}/include/dconfiguration.h.ini include/dconfiguration.h)

add_executable(mybinary ${SRC_FILES})
target_include_directories(mybinary PUBLIC ${INCLUDE_DIRS} ${CMAKE_BINARY_DIR}/include)
target_link_libraries(mybinary PUBLIC component_lib)

function(add_two_variables arg1 arg2)
    message(STATUS "running function add_two_variables with ${arg1} = ${${arg1}} - ${arg2} = ${${arg2}}")
    set(RESULT 0)
    math(EXPR RESULT "${${arg1}} + ${${arg2}}")
    message(STATUS "result running function add_two_variables = ${RESULT}")
    set(TOTO "toto is set in function" PARENT_SCOPE)
endfunction()

set(VAR1 1)
set(VAR2 2)
add_two_variables(VAR1 VAR2)
message(STATUS "this variable is set in function, here is its value : ${TOTO}")
message(STATUS "this variable is set in function, here is its value : ${TATA}")