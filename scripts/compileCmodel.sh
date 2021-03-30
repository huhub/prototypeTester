#!/bin/bash
#open error check
set -e

echo "compling platform and cmodel..."
export PISHON_PATH=`pwd`
cd $PISHON_PATH
if [ ! -d "build" ]; then
    mkdir -p build
    cd build
else
    cd build
    rm -rf *
fi
cmake -DMODE=CMODEL -DCMLOG=ON -DDEBUG=ON -DUNIT_TEST=ON ..
make
cd $PISHON_PATH
echo "compile cmodel-SDK for host version finished."
