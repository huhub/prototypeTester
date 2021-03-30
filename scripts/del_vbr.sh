#!/bin/sh
set -e
tmpName=$(ifconfig | head -n 1 | awk '{if(NF > 1) print $1}')
nicName=${tmpName%:*}
#for i in $(seq 0 $1);do
for((i=0; i<=$1; i++ )); do
    sudo ifconfig vport$UID-$i down
    sudo brctl delbr vport$UID-$i
done
