
find_package(Subversion)
if(SUBVERSION_FOUND)
    Subversion_WC_INFO(${PROJECT_SOURCE_DIR} Project)
    set(svn_ver ${Project_WC_REVISION})
endif()

string(TIMESTAMP compile_time "%Y-%m-%d %H:%M")
set(verfilename "${PROJECT_SOURCE_DIR}/include/common/version.h")
file( WRITE ${verfilename} "/*\n * Software Development Kit for Pishon\n * @file: version.h\n * @description: sdk revision\n * @note: Copyright (C) 2020\n\n * You should have received a copy of the Fisilink License\n * along with this program; if not, write to Fisilink\n */\n\n#ifndef __SDK_VERSION_H\n#define __SDK_VERSION_H\n" )
file( APPEND ${verfilename} "/** Version Macro */\nstatic const char *SDK_VERSION=\"SDK_${svn_ver}_${MODE}_${compile_time}\";" )
file( APPEND ${verfilename} "\n#endif\n" )
