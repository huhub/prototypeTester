#!/bin/bash
#open error check
set -e

echo "compling platform"
cd $PISHON_PATH
if [ ! -d "armBuild" ]; then
    mkdir -p armBuild
    cd armBuild
else
    cd armBuild
    rm -rf *
fi
cmake -DCMAKE_TOOLCHAIN_FILE=../cmake/toolchain_aarch64.cmake -DMODE=FPGA -DDEBUG=ON ..
make
cd $PISHON_PATH

if [ ! -d "build" ]; then
    mkdir -p build
    cd build
else
    cd build
    rm -rf *
fi
cmake -DDEBUG=on ..
make
cd $PISHON_PATH
echo "compile server for SoC verison finished."
