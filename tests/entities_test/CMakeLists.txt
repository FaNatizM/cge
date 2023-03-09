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
   ../../src/CWRDObject.h
   ../../src/CWRDObject.cpp
   ../../src/CWRDModel.h
   ../../src/CWRDModel.cpp
   ../../src/CWRDModelPoint.h
   ../../src/CWRDModelPoint.cpp
   ../../src/CWRDEntityID.h
   ../../src/CWRDEntityID.cpp
   ../../src/CWRDEntity.h
   ../../src/CWRDEntity.cpp
   ../../src/CWRDDecoration.h
   ../../src/CWRDDecoration.cpp
   ../../src/CWRDItem.h
   ../../src/CWRDItem.cpp
   ../../src/CWRDUnit.h
   ../../src/CWRDUnit.cpp
   ../../src/CWRDItemsCreator.h
   ../../src/CWRDItemsCreator.cpp
   main.cpp )


add_executable( entities_test ${SOURCES} )


target_link_libraries( entities_test LINK_PUBLIC )
