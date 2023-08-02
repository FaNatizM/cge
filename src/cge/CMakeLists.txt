cmake_minimum_required( VERSION 2.8 )


project( cge )


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
   CCGEItemsCreator.cpp )


set( TARGET cge )
add_library( ${TARGET} ${SOURCES} )
add_library( cge::cge ALIAS cge )


target_link_libraries( ${TARGET} LINK_PUBLIC )
