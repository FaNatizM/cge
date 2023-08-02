cmake_minimum_required( VERSION 2.8 )


set( TARGET matrix_test )
project( ${TARGET} )


set( SOURCES
   ../../src/cge/math/CBoundsMatrix.hpp
   ../../src/cge/math/CSquareMatrix.hpp
   ../../src/cge/math/HMatrixOperations.hpp
   ../../src/cge/math/HMatrixTests.hpp
   main.cpp )


add_executable( ${TARGET} ${SOURCES} )


target_link_libraries( ${TARGET} LINK_PUBLIC )
