#!/bin/bash
#open error check
set -e

echo "compling platform and cmodel..."
cd $PISHON_PATH
if [ ! -d "build" ]; then
    mkdir -p build
    cd build
else
    cd build
    rm -rf *
fi
cmake -DMODE=COSIM -DCOSIM_PATH=/mnt/shared/work/Rio/sw2asic/Baseline_v0.5/Include/ ..
make

cd $PISHON_PATH
echo "compile remote for host version finished."
