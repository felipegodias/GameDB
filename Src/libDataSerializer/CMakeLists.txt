add_library(gdb.libDataSerializer INTERFACE)

target_include_directories(gdb.libDataSerializer INTERFACE
    "Include"
)

target_link_libraries(gdb.libDataSerializer INTERFACE
	gdb.libData
	gdb.libJson
)
