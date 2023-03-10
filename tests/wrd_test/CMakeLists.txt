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
   ../../src/CWRDPlace.h
   ../../src/CWRDPlace.cpp
   ../../src/CWRDLocation.h
   ../../src/CWRDLocation.cpp
   ../../src/CWRDViewer.h
   ../../src/CWRDViewer.cpp
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
   ../../src/CWRDItem.h
   ../../src/CWRDItem.cpp
   ../../src/CWRDItemsCreator.h
   ../../src/CWRDItemsCreator.cpp
   main.cpp )


add_executable( wrd_test ${SOURCES} )


target_link_libraries( wrd_test LINK_PUBLIC )
