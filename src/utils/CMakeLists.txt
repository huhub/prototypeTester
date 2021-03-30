add_compile_options(-fPIC)
aux_source_directory(. DIR_COMMON_SRCS)

add_library(utils ${DIR_COMMON_SRCS})
