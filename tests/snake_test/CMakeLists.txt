cmake_minimum_required( VERSION 2.8 )


set ( PROJECT snake_test )
project( ${PROJECT} )


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
   ../../src/CWRDModelChain.h
   ../../src/CWRDModelChain.cpp
   ../../src/CWRDEntityID.h
   ../../src/CWRDEntityID.cpp
   ../../src/CWRDEntity.h
   ../../src/CWRDEntity.cpp
   ../../src/CWRDItem.h
   ../../src/CWRDItem.cpp
   ../../src/CWRDItemsCreator.h
   ../../src/CWRDItemsCreator.cpp
   main.cpp )


add_executable( ${PROJECT} ${SOURCES} )


target_link_libraries( ${PROJECT} LINK_PUBLIC )
