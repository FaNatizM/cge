cmake_minimum_required( VERSION 2.8 )


project( snake LANGUAGES CXX )


set(
   CMAKE_BUILD_TYPE Debug )

string(REGEX REPLACE "( -DNDEBUG$|-DNDEBUG )" "" CMAKE_CXX_FLAGS_BETATEST "${CMAKE_CXX_FLAGS_RELEASE}" )
string(REGEX REPLACE "( -DNDEBUG$|-DNDEBUG )" "" CMAKE_C_FLAGS_BETATEST "${CMAKE_C_FLAGS_RELEASE}" )
string(REGEX REPLACE "-DNDEBUG " "" CMAKE_CXX_FLAGS_RELWITHDEBUG "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -DDEBUG" )
string(REGEX REPLACE "-DNDEBUG " "" CMAKE_C_FLAGS_RELWITHDEBUG "${CMAKE_C_FLAGS_RELWITHDEBINFO} -DDEBUG" )


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


add_subdirectory( test )
