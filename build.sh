#!/usr/bin/env bash




clear
cd $( dirname "${0}" )


bin_path="${PWD}/bin"
build_path="${PWD}/build"
sources_path="${PWD}/src"


cd "${build_path}"
echo "${PWD}"


sources=()
sources+=( ${sources_path}/main.cpp )
sources+=( ${sources_path}/CEngine.h )
sources+=( ${sources_path}/CEngine.cpp)
sources+=( ${sources_path}/CMap.h )
sources+=( ${sources_path}/CMap.cpp )
sources+=( ${sources_path}/CMapObject.h )
sources+=( ${sources_path}/CMapObject.cpp )
sources+=( ${sources_path}/CUI.h )
sources+=( ${sources_path}/CUI.cpp )
sources+=( ${sources_path}/CUICommand.h )
sources+=( ${sources_path}/CUICommand.cpp )
sources+=( ${sources_path}/private/HKeyboard.hpp )


g++ ${sources[*]} -o "${bin_path}/map.exe"


[ ${?} -eq 0 ] && "${bin_path}/map.exe"
