include_directories(${PROJECT_SOURCE_DIR}/include)
add_compile_options(-fPIC)

add_executable(sdk sdk.c)
target_link_libraries(sdk )
install(TARGETS cli ARCHIVE DESTINATION lib)
