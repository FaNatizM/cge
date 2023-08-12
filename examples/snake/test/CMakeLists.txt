cmake_minimum_required( VERSION 2.8 )


project( snake_test LANGUAGES CXX )


set(
   CMAKE_BUILD_TYPE Debug )


include( "../../../cmake/utils.cmake" )
string( COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" is_top_level )


if ( is_top_level )
    find_package( cge REQUIRED )
endif()


set( SOURCES
   ../CRules.h
   ../CRules.cpp
   CTest.h
   CTest.cpp
   main.cpp )


add_executable( snake_test )
target_sources(
   snake_test PRIVATE ${SOURCES} )
target_link_libraries(
   snake_test PRIVATE cge::cge )


add_test(
   NAME snake_test
   COMMAND bash
      "../../../../tools/run_test.sh"
      "../build/examples/snake/test/snake_test" )


if ( NOT is_top_level )
   win_copy_deps_to_target_dir(
      snake_test cge::cge )
endif()
