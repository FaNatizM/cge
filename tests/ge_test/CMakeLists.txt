cmake_minimum_required( VERSION 2.8 )


project( ge_test )


set( SOURCES
   ../../src/HCGEMacroses.h
   ../../src/CCGEPoint.h
   ../../src/CCGEPoint.cpp
   ../../src/CCGETexture.h
   ../../src/CCGETexture.cpp
   ../../src/CCGEScene.h
   ../../src/CCGEScene.cpp
   main.cpp )


add_executable( ge_test ${SOURCES} )


target_link_libraries( ge_test LINK_PUBLIC )
