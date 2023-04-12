cmake_minimum_required( VERSION 2.8 )


project( menu_test )


set( SOURCES
   ../../src/private/HKeyboard.hpp
   ../../src/menu/CCGEMenu.hpp
   main.cpp )


add_executable( menu_test ${SOURCES} )


target_link_libraries( menu_test LINK_PUBLIC )
