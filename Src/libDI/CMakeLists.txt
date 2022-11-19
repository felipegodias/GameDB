add_library(gdb.libDI STATIC
    "DIContainer.cpp"
    "SingletonContainer.cpp"
)

target_include_directories(gdb.libDI PUBLIC
    "Include"
)

target_link_libraries(gdb.libDI PUBLIC
	gdb.libContainer
    gdb.libMemory
)
