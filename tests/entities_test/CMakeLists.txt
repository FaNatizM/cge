cmake_minimum_required( VERSION 2.8 )


project( wrd_test )


set( SOURCES
   ../../src/cge/HCGEMacroses.h
   ../../src/cge/CCGEPoint.h
   ../../src/cge/CCGEPoint.cpp
   ../../src/cge/CCGETexture.h
   ../../src/cge/CCGETexture.cpp
   ../../src/cge/CCGEScene.h
   ../../src/cge/CCGEScene.cpp
   ../../src/cge/CCGEObject.h
   ../../src/cge/CCGEObject.cpp
   ../../src/cge/CCGEModel.h
   ../../src/cge/CCGEModel.cpp
   ../../src/cge/CCGEModelPoint.h
   ../../src/cge/CCGEModelPoint.cpp
   ../../src/cge/CCGEEntityID.h
   ../../src/cge/CCGEEntityID.cpp
   ../../src/cge/CCGEEntity.h
   ../../src/cge/CCGEEntity.cpp
   ../../src/cge/CCGEDecoration.h
   ../../src/cge/CCGEDecoration.cpp
   ../../src/cge/CCGEItem.h
   ../../src/cge/CCGEItem.cpp
   ../../src/cge/CCGEUnit.h
   ../../src/cge/CCGEUnit.cpp
   ../../src/cge/CCGEItemsCreator.h
   ../../src/cge/CCGEItemsCreator.cpp
   main.cpp )


add_executable( entities_test ${SOURCES} )


target_link_libraries( entities_test LINK_PUBLIC )
