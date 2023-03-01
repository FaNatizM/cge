# Библиотека средств сборки
C_OUT="/dev/null"




# Функция очистки консоли
f_BT_Clear() {
   clear
   clear
}



# Получение списка исходников
# из каталога
f_BT_GetSrcList() {
   local a_path="${1}"


   [ ! -d "${a_path}" ] && return -1

   local filter='grep -P ".h$|.cpp$|.hpp$"'
   local src=( $( ls "${a_path}" | ${filter} ) )


   local file=
   local src_list=()
   for file in ${src[*]}; do
      src_list+=( "${a_path}/${file}" )
   done

   echo "${src_list[*]}"
   return 0
}



# Функция создания списка исхрдников
# из файла с относительными путями к ним
f_BT_CreateSrcList() {
   local a_project="${1}"
   local a_list="${2}"


   [ ! -d "${a_project}" ] && return -1
   [ ! -f "${a_list}" ] && return -1

   local src=( $( tr -d '\0' < "${a_list}" ) )


   local file=
   local src_list=()
   for file in ${src[*]}; do
      src_list+=( "${a_project}/${file}" )
   done

   echo "${src_list[*]}"
   return 0
}



f_BT_CreateBuildDir() {
   local a_path="${1}"

   # Создание каталога сборочных файлов
   if [ ! -d "${a_path}" ]; then
      mkdir -p "${a_path}"
   fi

   if [ ! -d "${a_path}" ]; then
      return -1
   fi

   return 0
}



f_BT_BuildExeByCLang() {
   local a_build_path="${1}"
   local a_src_path="${2}"
   local a_src=( "$(echo ${3} )" )


   local command="clang++ ${a_src[*]}"
   echo -e "\n${command}\n"
   ${command}
   local result=${?}


   # Чистка src
   local objects=( $( ls "${a_src_path}" | grep -e '.gch$' ) )
   local file=
   for file in ${objects[*]}; do
      mv -v "${a_src_path}/${file}" "${a_build_path}"
   done


   return ${result}
}



f_BT_BuildExeByGPP() {
   local a_build_path="${1}"
   local a_src_path="${2}"
   local a_src=( "$(echo ${3} )" )


   local command="g++ ${a_src[*]}"
   echo -e "\n${command}\n"
   ${command}
   local result=${?}


   # Чистка src
   local objects=( $( ls "${a_src_path}" | grep -e '.o$' ) )
   local file=
   for file in ${objects[*]}; do
      mv -v "${a_src_path}/${file}" "${a_build_path}"
   done


   return ${result}
}



# Перемещение и запуск исполняемого файла
f_BT_MoveAndRun() {
   local a_bin_from="${1}"
   local a_bin="${2}"


   if [ ! -f "${a_bin_from}" ]; then
      return -1
   fi


   # Создание каталога для исполняемого файла
   local bin_path="$( dirname ${a_bin} )"
   [ ! -d "${bin_path}" ] && mkdir -p "${bin_path}"
   [ ! -d "${bin_path}" ] && return -1


   mv -v "${a_bin_from}" "${a_bin}"
   if [ ! -f "${a_bin}" ]; then
      return -1
   fi

   chmod +x "${a_bin}"


   if [ -f "${a_bin}" ]; then
      "${a_bin}"
      return ${?}
   fi

   return -1
}



f_BT_BuildAndRun() {
   local a_args=()
   local args_count=0
   while [ -n "${1}" ]; do
      a_args+=( "${1}" )
      args_count=$[${args_count}+1]
      shift
   done

   local a_project_path=
   local a_build_path=
   local a_src_path=
   local a_src_list=
   local a_bin=

   if [ ${args_count} -eq 4 ]; then
      a_project_path=${a_args[0]}
      a_build_path=${a_args[1]}
      a_src_path=${a_args[2]}
      a_bin=${a_args[3]}
   fi

   if [ ${args_count} -eq 5 ]; then
      echo -e "\nBuild by src file"
      a_project_path=${a_args[0]}
      a_build_path=${a_args[1]}
      a_src_path=${a_args[2]}
      a_src_list=${a_args[3]}
      a_bin=${a_args[4]}
   fi


   f_BT_Clear


   local src=()
   if [ -f "${a_src_list}" ]; then
      src=( "$( f_BT_CreateSrcList ${a_project_path} ${a_src_list} )" )
   else
      src=( "$( f_BT_GetSrcList ${a_src_path} )" )
   fi

   [ ${?} -ne 0 ] && return -1


   f_BT_CreateBuildDir "${a_build_path}"
   [ ${?} -ne 0 ] && return -2


   # Компиляция
   local gpp_clang="$( g++ --version 2>"${C_OUT}" | grep -e 'clang' )"
   local gpp=${?}

   clang++ -v 2>"${C_OUT}"
   local clang=${?}
   if [ ${gpp} -eq 0 ] && [ -z "${gpp_clang}" ]; then
      f_BT_BuildExeByGPP "${a_build_path}" "${a_src_path}" "${src[*]}"
      [ ${?} -ne 0 ] && return -3
   elif [ ${clang} -eq 0 ]; then
      f_BT_BuildExeByCLang "${a_build_path}" "${a_src_path}" "${src[*]}"
      [ ${?} -ne 0 ] && return -3
   else
      [ ${?} -ne 0 ] && return -4
   fi


   f_BT_MoveAndRun "./a.out" "${a_bin}"
   local result=${?}
   [ ${result} -ne 0 ] && return -5
   return ${result}
}
