cmake_minimum_required( VERSION 2.8 )


project( ge_test LANGUAGES CXX )


set(
   CMAKE_BUILD_TYPE Debug )


include( "../../cmake/utils.cmake" )
string( COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" is_top_level )


if ( is_top_level )
    find_package( cge REQUIRED )
endif()


set( SOURCES
   main.cpp )
source_group( TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES} )


add_executable( ge_test )
target_sources(
   ge_test PRIVATE ${SOURCES} )
target_link_libraries(
   ge_test PRIVATE cge::cge )


add_test(
   NAME ge_test
   COMMAND bash
      "../../../tools/run_test.sh"
      "../build/tests/ge_test/ge_test" )


if ( NOT is_top_level )
   win_copy_deps_to_target_dir(
      ge_test cge::cge )
endif()
