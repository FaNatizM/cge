g_scpt_path="$( dirname ${0} )"
g_this_path="${PWD}"
cd "${g_scpt_path}"


cd ../../
g_project_path="${PWD}"
cd "${g_scpt_path}"


# Загрузка библиотеки
source "${g_project_path}/tools/build_tools.sh"


g_args=()
g_args+=( "${g_project_path}" )
g_args+=( "${g_project_path}/build" )
g_args+=( "${g_project_path}/src" )
g_args+=( "${PWD}/src.list" )
g_args+=( "${HOME}/ge_test" )

f_BT_BuildAndRunByCLang ${g_args[*]}
echo "Result code: ${?}"


cd "${g_this_path}"
