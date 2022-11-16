add_library(gdb.libCore INTERFACE)

target_link_libraries(gdb.libCore INTERFACE
	gdb.libContainer
	gdb.libData
	gdb.libDataSerializer
	gdb.libDebug
	gdb.libDI
	gdb.libFormat
	gdb.libJson
	gdb.libMemory
	gdb.libProject
)
