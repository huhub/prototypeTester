#!/bin/sh
set -e
for i in $(seq 0 $1);do
    sudo sh -c "echo 1 > /proc/sys/net/ipv6/conf/vbr"$i"/disable_ipv6"
#cat /proc/sys/net/ipv6/conf/vbr$i/disable_ipv6
done
