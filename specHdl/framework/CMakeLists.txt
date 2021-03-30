add_compile_options(-fPIC)
aux_source_directory(. DIR_SAVE_SRCS )

add_library( cframe ${DIR_SAVE_SRCS} )
target_link_libraries( cframe cmodel utils algo )
