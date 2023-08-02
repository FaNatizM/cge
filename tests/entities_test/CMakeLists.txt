cmake_minimum_required( VERSION 2.8 )


project( wrd_test )


set( SOURCES
   ../../src/HCGEMacroses.h
   ../../src/CCGEPoint.h
   ../../src/CCGEPoint.cpp
   ../../src/CCGETexture.h
   ../../src/CCGETexture.cpp
   ../../src/CCGEScene.h
   ../../src/CCGEScene.cpp
   ../../src/CCGEObject.h
   ../../src/CCGEObject.cpp
   ../../src/CCGEModel.h
   ../../src/CCGEModel.cpp
   ../../src/CCGEModelPoint.h
   ../../src/CCGEModelPoint.cpp
   ../../src/CCGEEntityID.h
   ../../src/CCGEEntityID.cpp
   ../../src/CCGEEntity.h
   ../../src/CCGEEntity.cpp
   ../../src/CCGEDecoration.h
   ../../src/CCGEDecoration.cpp
   ../../src/CCGEItem.h
   ../../src/CCGEItem.cpp
   ../../src/CCGEUnit.h
   ../../src/CCGEUnit.cpp
   ../../src/CCGEItemsCreator.h
   ../../src/CCGEItemsCreator.cpp
   main.cpp )


add_executable( entities_test ${SOURCES} )


target_link_libraries( entities_test LINK_PUBLIC )
