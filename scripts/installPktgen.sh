#!/bin/sh
####################################
# This script need superuser authority to execute.
# First write by cygao on 2019.7.3
# Version:      v0.1 First write.
####################################
# open error check
set -e

tclVersion=`echo 'puts $tcl_version;exit 0' | tclsh`
tclSubVersion=${tclVersion:2:2}

echo "compiling libpcap..."
cd $PISHON_PATH/tools/libpcap-0.7.1
if [ -f "Makefile" ]; then
    make distclean
fi
chmod +x ./configure
./configure
make

echo "compiling pktgen..."
cd $PISHON_PATH/pktgen
if [ -f "Makefile" ]; then
    make distclean
fi
chmod +x ./configure
if [ $tclSubVersion -eq 5 ]
then
    sudo ./configure --with-libpcap=../tools/libpcap-0.7.1 --with-tcl=/usr/local/lib --with-tclinclude=/usr/local/include/ --libdir=/usr/local/lib/tcl8.5
else
    sudo ./configure --with-libpcap=../tools/libpcap-0.7.1 --with-tcl=/usr/lib/tcl8.6 --with-tclinclude=/usr/include/tcl8.6 --libdir=/usr/share/tcltk/tcl8.6
fi 
make
sudo make install
sudo tclsh mkIndex.tcl


cd $PISHON_PATH
echo "compile finished."
