set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_SYSROOT /opt/windriver/wrlinux-small/10.17.41/sysroots/aarch64-wrs-linux)
#set(CMAKE_STAGING_PREFIX /opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu)

set(tools /opt/windriver/wrlinux-small/10.17.41/sysroots/x86_64-wrlinuxsdk-linux/usr/bin/aarch64-wrs-linux)
set(CMAKE_C_COMPILER ${tools}/aarch64-wrs-linux-gcc)
set(CMAKE_CXX_COMPILER ${tools}/aarch64-wrs-linux-g++)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
