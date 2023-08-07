cmake_minimum_required(VERSION 3.14)
project( cge-version LANGUAGES CXX)

include("../../cmake/utils.cmake")
string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" is_top_level)

if(is_top_level)
    find_package(cge REQUIRED)
endif()

set(sources main.cpp)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sources})

add_executable(cge-version)
target_sources(cge-version PRIVATE ${sources})
target_link_libraries(cge-version PRIVATE cge::cge)

if(NOT is_top_level)
    win_copy_deps_to_target_dir( cge-version cge::cge )
endif()
