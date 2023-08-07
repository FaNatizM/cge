cmake_minimum_required( VERSION 2.8 )


project( snake LANGUAGES CXX )


include( "../../cmake/utils.cmake" )
string( COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" is_top_level )


if ( is_top_level )
    find_package( cge REQUIRED )
endif()


set( SOURCES
   CRules.h
   CRules.cpp
   CGame.h
   CGame.cpp
   CUI.h
   CUI.cpp
   main.cpp )
source_group( TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES} )


add_executable( snake )
target_sources( snake PRIVATE ${SOURCES} )
target_link_libraries( snake PRIVATE cge::cge )


if ( NOT is_top_level )
    win_copy_deps_to_target_dir( snake cge::cge )
endif()
