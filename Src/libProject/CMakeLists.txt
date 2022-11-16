add_library(gdb.libProject INTERFACE)

target_include_directories(gdb.libProject INTERFACE
    "Include"
)

target_link_libraries(gdb.libProject INTERFACE
	gdb.libData
	gdb.libDataSerializer
)
