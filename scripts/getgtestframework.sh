#!/bin/bash
if [ -f "$1/CMakeLists.txt" ]; then
    rm $1/CMakeLists.txt
    mv $1/tests $1/bak
fi

touch $1/CMakeLists.txt
echo "add_subdirectory(src)" > $1/CMakeLists.txt
echo "if(BUILD_TESTING)" >> $1/CMakeLists.txt
echo "    add_subdirectory(tests)" >> $1/CMakeLists.txt
echo "endif()" >> $1/CMakeLists.txt

mkdir $1/tests
cp $1/src/*.c $1/tests/
cd $1/tests
rename "s/\.c/test.cc/" * //
#cat /dev/null > *.cc
sed -i '1, $d' `ls *.cc`
echo '#include <gtest/gtest.h>' | tee -a `ls *.cc`
echo -e 'extern "C" { \n' | tee -a `ls *.cc`
echo -e '}\n' | tee -a `ls *.cc`
echo -e 'TEST(filename, funcname) {\n' | tee -a `ls *.cc`
echo '}' | tee -a `ls *.cc`

touch CMakeLists.txt
echo "set(CMAKE_CXX_FLAGS \"\${CMAKE_CXX_FLAGS} -std=c++11\")" > CMakeLists.txt
echo "set (LIBS \${LIBS} )" >> CMakeLists.txt
echo "" >> CMakeLists.txt
echo "add_executable(filename filename.cc)" >> CMakeLists.txt
echo "target_link_libraries(filename \${LIBS})" >> CMakeLists.txt
echo "add_test(filename \${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/filename)" >> CMakeLists.txt
