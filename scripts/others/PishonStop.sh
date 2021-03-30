#!/bin/sh
####################################
# This script need superuser authority to execute.
# First write by cygao on 2019.7.3
# Version:      v0.1 First write.
####################################
set -e
#read maxport from PishonConfig.cfg
file=$PISHON_PATH/config/PishonConfig.cfg
if [ ! -f $file ];then
    echo "Error: $file is not a file"
    exit 1
fi

maxport=0   #maxport num
while read line
do
    configname=$(echo $line|awk -F'=' '{print $1}')
    if [ "$configname" = "maxPort" ];then
        maxport=$(echo $line|awk -F'=' '{print $2}')
        break
    fi
done <$file     #input string: $file
maxport=$(($maxport-1));  #i.e. change index range: 0~maxport-1

#kill all sniffer
ps -a |grep tclsh|awk '{print $1}'|xargs sudo kill -9

#delete vbr and cancel close port when exit platform
$PISHON_PATH/initscripts/del_vbr.sh $maxport
$PISHON_PATH/initscripts/cancel_closeUdpPort.sh

echo "========Pishon Platform Stopped========"

