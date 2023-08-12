# Переход в каталог проекта
g_scpt_path="$( dirname ${0} )"
g_this_path="${PWD}"
cd "${g_scpt_path}"


g_tests=()
g_tests+=( "${1}" )


for g_test in ${g_tests[*]}; do
   echo -e "\n\n${g_test}"
   test_exe=$( basename ${g_test} )
   cp -frv "${g_test}" "${HOME}/${test_exe}"
   chmod 777 "${HOME}/${test_exe}"
   "${HOME}/${test_exe}"
   if [ ${?} -ne 0 ]; then
      echo "\nTest ${g_test} has been failed!"
   fi
done


cd "${g_this_path}"
