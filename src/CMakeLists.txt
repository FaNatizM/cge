cmake_minimum_required( VERSION 2.8 )


project( src )


set( SOURCES
   CCGEGame.h
   CCGEGame.cpp
   CCGEUI.h
   CCGEUI.cpp
   CCGEUICommand.h
   CCGEUICommand.cpp
   CCGEEngine.h
   CCGEEngine.cpp

   HCGEMacroses.h
   CCGEPoint.h
   CCGEPoint.cpp
   CCGETexture.h
   CCGETexture.cpp
   CCGEScene.h
   CCGEScene.cpp
   CCGEPlace.h
   CCGEPlace.cpp
   CCGELocation.h
   CCGELocation.cpp
   CCGEViewer.h
   CCGEViewer.cpp
   CCGEObject.h
   CCGEObject.cpp
   CCGEModel.h
   CCGEModel.cpp
   CCGEModelPoint.h
   CCGEModelPoint.cpp
   CCGEModelChain.h
   CCGEModelChain.cpp
   CCGEEntityID.h
   CCGEEntityID.cpp
   CCGEEntity.h
   CCGEEntity.cpp
   CCGEItem.h
   CCGEItem.cpp
   CCGEItemsCreator.h
   CCGEItemsCreator.cpp
   main.cpp )


set( TARGET snake )
add_executable( ${TARGET} ${SOURCES} )


target_link_libraries( ${TARGET} LINK_PUBLIC )
