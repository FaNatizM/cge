# Переход в каталог проекта
g_scpt_path="$( dirname ${0} )"
g_this_path="${PWD}"
cd "${g_scpt_path}"


g_tests=()
# g_tests+=( tests/ge_test )
g_tests+=( tests/wrd_test )

for g_test in ${g_tests[*]}; do
   bash "${g_test}/build_and_run.sh"
done


cd "${g_this_path}"
