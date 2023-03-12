cmake_minimum_required( VERSION 2.8 )


project( src )


set( SOURCES
   CGame.h
   CGame.cpp
   CUI.h
   CUI.cpp
   CUICommand.h
   CUICommand.cpp
   CEngine.h
   CEngine.cpp

   HMacroses.h
   CPoint.h
   CPoint.cpp
   CGETexture.h
   CGETexture.cpp
   CGEScene.h
   CGEScene.cpp
   CWRDPlace.h
   CWRDPlace.cpp
   CWRDLocation.h
   CWRDLocation.cpp
   CWRDViewer.h
   CWRDViewer.cpp
   CWRDObject.h
   CWRDObject.cpp
   CWRDModel.h
   CWRDModel.cpp
   CWRDModelPoint.h
   CWRDModelPoint.cpp
   CWRDModelChain.h
   CWRDModelChain.cpp
   CWRDEntityID.h
   CWRDEntityID.cpp
   CWRDEntity.h
   CWRDEntity.cpp
   CWRDItem.h
   CWRDItem.cpp
   CWRDItemsCreator.h
   CWRDItemsCreator.cpp
   main.cpp )


set( TARGET snake)
add_executable( ${TARGET} ${SOURCES} )


target_link_libraries( ${TARGET} LINK_PUBLIC )
