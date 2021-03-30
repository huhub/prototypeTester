add_compile_options(-fPIC)

aux_source_directory(. DIR_SRCS)
add_library( utils ${DIR_SRCS})
target_link_libraries(utils rpc mem algo crc)
