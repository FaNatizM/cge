cmake_minimum_required( VERSION 3.14 )
project(
   cge
   VERSION 1.0.0
   DESCRIPTION "Console Game Engine C++ library built with CMake"
   LANGUAGES CXX )




#----------------------------------------------------------------------------------------------------------------------
# general settings and options
#----------------------------------------------------------------------------------------------------------------------
string(REGEX REPLACE "( -DNDEBUG$|-DNDEBUG )" "" CMAKE_CXX_FLAGS_BETATEST "${CMAKE_CXX_FLAGS_RELEASE}" )
string(REGEX REPLACE "( -DNDEBUG$|-DNDEBUG )" "" CMAKE_C_FLAGS_BETATEST "${CMAKE_C_FLAGS_RELEASE}" )
string(REGEX REPLACE "-DNDEBUG " "" CMAKE_CXX_FLAGS_RELWITHDEBUG "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -DDEBUG" )
string(REGEX REPLACE "-DNDEBUG " "" CMAKE_C_FLAGS_RELWITHDEBUG "${CMAKE_C_FLAGS_RELWITHDEBINFO} -DDEBUG" )


include(cmake/utils.cmake)
include(GNUInstallDirs)
include( CTest )

string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" is_top_level)

# CGE_SHARED_LIBS option (undefined by default) can be used to force shared/static build
option(
   CGE_BUILD_TESTS "Build cge tests" ON )
option(CGE_BUILD_EXAMPLES "Build cge examples" ON)
option(CGE_BUILD_DOCS "Build cge documentation" OFF)
option(CGE_INSTALL "Generate target for installing cge" ${is_top_level})
set_if_undefined(CGE_INSTALL_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/cmake/cge" CACHE STRING
    "Install path for cge package-related CMake files")

if(DEFINED CGE_SHARED_LIBS)
    set(BUILD_SHARED_LIBS ${CGE_SHARED_LIBS})
endif()

if(NOT DEFINED CMAKE_BUILD_TYPE AND NOT DEFINED CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

set_if_undefined(CMAKE_CXX_VISIBILITY_PRESET hidden)
set_if_undefined(CMAKE_VISIBILITY_INLINES_HIDDEN ON)

add_library(cge) # initialized below
add_library(cge::cge ALIAS cge)




#----------------------------------------------------------------------------------------------------------------------
# cge dependencies
#----------------------------------------------------------------------------------------------------------------------

# Search for your dependencies here




#----------------------------------------------------------------------------------------------------------------------
# cge sources
#----------------------------------------------------------------------------------------------------------------------

include(GenerateExportHeader)
set(export_file_name "export_shared.h")

if(NOT BUILD_SHARED_LIBS)
    set(export_file_name "export_static.h")
endif()

generate_export_header(cge EXPORT_FILE_NAME include/cge/${export_file_name})

set( sources
   include/cge/export.h
   include/cge/HCGE.h

   include/cge/CCGEUI.h
   src/CCGEUI.cpp
   include/cge/CCGEUICommand.h
   src/CCGEUICommand.cpp
   include/cge/CCGEEngine.h
   src/CCGEEngine.cpp

   include/cge/HCGEMacroses.h
   include/cge/HCGEKeyboard.hpp

   include/cge/CCGEPoint.h
   src/CCGEPoint.cpp
   include/cge/CCGETexture.h
   src/CCGETexture.cpp
   include/cge/CCGEScene.h
   src/CCGEScene.cpp
   include/cge/CCGEPlace.h
   src/CCGEPlace.cpp
   include/cge/CCGELocation.h
   src/CCGELocation.cpp
   include/cge/CCGEViewer.h
   src/CCGEViewer.cpp
   include/cge/CCGEObject.h
   src/CCGEObject.cpp
   include/cge/CCGEModel.h
   src/CCGEModel.cpp
   include/cge/CCGEModelPoint.h
   src/CCGEModelPoint.cpp
   include/cge/CCGEModelChain.h
   src/CCGEModelChain.cpp
   include/cge/CCGEEntityID.h
   src/CCGEEntityID.cpp
   include/cge/CCGEEntity.h
   src/CCGEEntity.cpp
   include/cge/CCGEItem.h
   src/CCGEItem.cpp
   include/cge/CCGEItemsCreator.h
   src/CCGEItemsCreator.cpp
   include/cge/CCGEDecoration.h
   src/CCGEDecoration.cpp
   include/cge/CCGEUnit.h
   src/CCGEUnit.cpp

   include/cge/eng/CCGEEvent.h
   src/eng/CCGEEvent.cpp
   include/cge/eng/CCGEEventManagerItem.h
   src/eng/CCGEEventManagerItem.cpp
   include/cge/eng/CCGETrigger.h
   src/eng/CCGETrigger.cpp
   include/cge/eng/CCGECondition.h
   src/eng/CCGECondition.cpp
   include/cge/eng/CCGEAction.h
   src/eng/CCGEAction.cpp

   src/HCGE.cpp )
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sources})




#----------------------------------------------------------------------------------------------------------------------
# cge target
#----------------------------------------------------------------------------------------------------------------------

include(CMakePackageConfigHelpers)

target_sources(cge PRIVATE ${sources})
target_compile_definitions(cge PUBLIC "$<$<NOT:$<BOOL:${BUILD_SHARED_LIBS}>>:CGE_STATIC_DEFINE>")

target_include_directories(cge
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>")

set_target_properties(cge PROPERTIES
    SOVERSION ${PROJECT_VERSION_MAJOR}
    VERSION ${PROJECT_VERSION})

if(CGE_INSTALL AND NOT CMAKE_SKIP_INSTALL_RULES)
    configure_package_config_file(cmake/cge-config.cmake.in cge-config.cmake
        INSTALL_DESTINATION "${CGE_INSTALL_CMAKEDIR}")

    write_basic_package_version_file(cge-config-version.cmake
        COMPATIBILITY SameMajorVersion)

    install(TARGETS cge EXPORT cge_export
        RUNTIME COMPONENT cge
        LIBRARY COMPONENT cge NAMELINK_COMPONENT cge-dev
        ARCHIVE COMPONENT cge-dev
        INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")
    install(DIRECTORY include/
        TYPE INCLUDE
        COMPONENT cge-dev)
    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/include/cge/${export_file_name}"
        COMPONENT cge-dev
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/cge")

    set(targets_file "cge-shared-targets.cmake")

    if(NOT BUILD_SHARED_LIBS)
        set(targets_file "cge-static-targets.cmake")
    endif()

    install(EXPORT cge_export
        COMPONENT cge-dev
        FILE "${targets_file}"
        DESTINATION "${CGE_INSTALL_CMAKEDIR}"
        NAMESPACE cge::)

    install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/cge-config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/cge-config-version.cmake"
        COMPONENT cge-dev
        DESTINATION "${CGE_INSTALL_CMAKEDIR}")

    if(MSVC)
        set(pdb_file "")
        set(pdb_file_destination "")

        if(BUILD_SHARED_LIBS)
            set(pdb_file "$<TARGET_PDB_FILE:cge>")
            set(pdb_file_destination "${CMAKE_INSTALL_BINDIR}")
        else()
            # TARGET_PDB_FILE does not work for pdb file generated for static library build, determining it manually
            set(pdb_file "$<TARGET_FILE_DIR:cge>/$<TARGET_FILE_PREFIX:cge>$<TARGET_FILE_BASE_NAME:cge>.pdb")
            set(pdb_file_destination "${CMAKE_INSTALL_LIBDIR}")
        endif()

        install(FILES "${pdb_file}"
            COMPONENT cge-dev
            CONFIGURATIONS Debug RelWithDebInfo
            DESTINATION "${pdb_file_destination}"
            OPTIONAL)
    endif()
endif()




#----------------------------------------------------------------------------------------------------------------------
# other targets
#----------------------------------------------------------------------------------------------------------------------

if(CGE_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

if(CGE_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

if(CGE_BUILD_DOCS)
    find_package(Doxygen REQUIRED)
    doxygen_add_docs(docs include)
endif()
