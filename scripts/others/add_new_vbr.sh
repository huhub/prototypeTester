#!/bin/sh

tmpName=$(ifconfig | head -n 1 | awk '{if(NF > 1) print $1}')
nicName=${tmpName%:*}
for((i=0; i<=$1; i++ )); do
#    sudo brctl addbr vbr"$i"
#    sudo brctl stp vbr"$i" off
#    sudo ifconfig vbr"$i" up
#    sudo ifconfig vbr"$i" 192.168.20.$i
    sudo ifconfig ${nicName}:$UID-$i 192.133.100.$i up
done
