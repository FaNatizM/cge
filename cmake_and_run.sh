g_scpt_path=$( dirname $( readlink -f ${0} ) )
g_this_path="${PWD}"
cd "${g_scpt_path}"


cd ./
g_rep_root="${PWD}"
cd "${g_scpt_path}"


g_exe_args=()
while [ -n "${1}" ]; do
   g_exe_args+=( "${1}" )
   shift
done

echo ${g_exe_args[*]}


g_args=()
g_args+=( "examples/snake/snake" )
g_args+=( "${PWD}" )
g_args+=( "${g_rep_root}/build" )
g_args+=( "${HOME}" )


# Загрузка библиотеки
source "${g_rep_root}/tools/build_tools.sh"
[ ${0} -ne 0 ] && return -1


f_BT_CMakeAndRun ${g_args[*]} ${g_exe_args[*]}
echo "Result code: ${?}"


cd "${g_this_path}"
