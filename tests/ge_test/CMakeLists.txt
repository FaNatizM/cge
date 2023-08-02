cmake_minimum_required( VERSION 2.8 )


project( ge_test )


set( SOURCES
   ../../src/cge/HCGEMacroses.h
   ../../src/cge/CCGEPoint.h
   ../../src/cge/CCGEPoint.cpp
   ../../src/cge/CCGETexture.h
   ../../src/cge/CCGETexture.cpp
   ../../src/cge/CCGEScene.h
   ../../src/cge/CCGEScene.cpp
   main.cpp )


add_executable( ge_test ${SOURCES} )


target_link_libraries( ge_test LINK_PUBLIC )
