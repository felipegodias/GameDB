add_library(gdb.libFormat STATIC 
    "Format.cpp"
 )

target_include_directories(gdb.libFormat PUBLIC
    "Include"
)

target_link_libraries(gdb.libFormat PUBLIC
    gdb.libContainer
	fmt::fmt-header-only
)
