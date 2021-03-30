include_directories( ./include )
aux_source_directory( ./src DIR_CRC_SRC )

add_library( crc SHARED ${DIR_CRC_SRC} )
install(TARGETS crc LIBRARY DESTINATION lib)
