cmake_minimum_required( VERSION 2.8 )


project( wrd_test )


set( SOURCES
   ../../src/HMacroses.h
   ../../src/CPoint.h
   ../../src/CPoint.cpp
   ../../src/CGETexture.h
   ../../src/CGETexture.cpp
   ../../src/CGEScene.h
   ../../src/CGEScene.cpp
   main.cpp )


add_executable( ge_test ${SOURCES} )


target_link_libraries( ge_test LINK_PUBLIC )
