cmake_minimum_required( VERSION 2.8 )


set( TARGET matrix_test )
project( ${TARGET} )


set( SOURCES
   ../../src/math/CBoundsMatrix.hpp
   ../../src/math/CSquareMatrix.hpp
   ../../src/math/HMatrixOperations.hpp
   ../../src/math/HMatrixTests.hpp
   main.cpp )


add_executable( ${TARGET} ${SOURCES} )


target_link_libraries( ${TARGET} LINK_PUBLIC )
