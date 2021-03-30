cmake_minimum_required(VERSION 3.5)

project( SDK VERSION 0.1.1 LANGUAGES C CXX )

set( OFFSET 76509 )
#set(CMAKE_C_FLAGS "-pthread -Wall -Wextra -Wundef -Wcast-align -fPIC -Wshadow -Werror=implicit-function-declaration ")
set(CMAKE_C_FLAGS "-Wshadow")

option(MODE "running on hardware or cmodel" unknown)
if(${MODE} STREQUAL "FPGA")
    add_definitions( -DINST_OFFSET=${OFFSET} )
    add_definitions( -DUSING_HW=1 )
    add_definitions( -DBUS_TYPE=1 )
elseif(${MODE} STREQUAL "CMODEL")
    # random instance offset for tipc
    string( RANDOM ALPHABET 123456789 randSeed )
    add_definitions( -DINST_OFFSET=${randSeed} )
    add_definitions( -DUSING_HW=0 )
elseif(${MODE} STREQUAL "COSIM")
    add_definitions( -DCFG_DUMP=1 )
    option(COSIM_PATH "bus info files for cosim" OFF)
    if (COSIM_PATH)
        add_definitions( -DENCODE_PATH="${COSIM_PATH}" )
    else()
        add_definitions( -DENCODE_PATH="/mnt/shared/work/Rio/sw2asic/Baseline_v0.5/Include/" ) 
    endif (COSIM_PATH)

    option(POST_SIM "post rtl simulation" OFF)
    if (POST_SIM)
        add_definitions( -DUMP_LEVEL=1 )
    else()
        add_definitions( -DUMP_LEVEL=0 )
    endif()
endif(${MODE} STREQUAL "FPGA")

# for debug
option(DEBUG "-g options" OFF)
if (${DEBUG} STREQUAL "ON")
    add_definitions( -g -rdynamic )
    IF (${MODE} STREQUAL "FPGA") 
        add_definitions( -funwind-tables -ffunction-sections -ldl )
    endif (${MODE} STREQUAL "FPGA")
endif (${DEBUG} STREQUAL "ON")

# for googletest
option(UNIT_TEST "build google test" OFF)
if (${UNIT_TEST} STREQUAL "ON") 
    enable_testing()
endif (${UNIT_TEST} STREQUAL "ON")

# for cmodel log
option(CMLOG "output cmodel log" OFF)
if (${CMLOG} STREQUAL "ON")
    add_definitions( -DPISHON_DEBUG )
endif (${CMLOG} STREQUAL "ON")

# for case path stored file
add_definitions( -DCASEPATHFILE="tcltools/currentCasePath.log" )
include(cmake/version.cmake)

option(COVERAGE "Code coverage included" OFF)
if(${COVERAGE} STREQUAL "ON")
    include(cmake/CodeCoverage.cmake)
    append_coverage_compiler_flags()
    setup_target_for_coverage_lcov(
        NAME sdkcoverage
        EXECUTABLE ${PROJECT_BINARY_DIR}/bin/sdkserver --simulator --interaction
    )
endif(${COVERAGE} STREQUAL "ON")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

add_subdirectory(src)
if (${MODE} STREQUAL "CMODEL")
    add_subdirectory(cmodel)
endif(${MODE} STREQUAL "CMODEL")
install(DIRECTORY config DESTINATION bin/..)
install(PROGRAMS PishonStart.sh DESTINATION bin/..)
