add_library(libletFormat STATIC 
    "Format.cpp"
 )

target_include_directories(libletFormat PUBLIC
    "Include"
)

target_link_libraries(libletFormat PUBLIC
    libletContainer
	fmt::fmt-header-only
)
