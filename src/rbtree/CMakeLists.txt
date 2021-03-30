add_compile_options(-fPIC -std=gnu11)

aux_source_directory(. DIR_LOG_SRCS)

add_library(rbtree ${DIR_LOG_SRCS})
target_link_libraries(rbtree  utils)
install(TARGETS log ARCHIVE DESTINATION lib)
