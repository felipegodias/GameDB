add_library(gdb.libDebug STATIC 
    "Assert.cpp"
)

target_include_directories(gdb.libDebug PUBLIC
    "Include"
)

target_link_libraries(gdb.libDebug PUBLIC
	gdb.libContainer
    gdb.libLog
)
