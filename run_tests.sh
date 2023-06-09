# Переход в каталог проекта
g_scpt_path="$( dirname ${0} )"
g_this_path="${PWD}"
cd "${g_scpt_path}"


g_tests=()
g_tests+=( tests/ge_test )
g_tests+=( tests/wrd_test )
g_tests+=( tests/entities_test )


for g_test in ${g_tests[*]}; do
   echo -e "\n\n${g_test}"
   rm -rf ./build
   bash "${g_test}/cmake_and_run.sh"
   if [ ${?} -ne 0 ]; then
      echo "\nTest ${g_test} has been failed!"
   fi
done


cd "${g_this_path}"
