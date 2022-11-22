add_library(gdb.libCore INTERFACE)

target_link_libraries(gdb.libCore INTERFACE
	gdb.libContainer
	gdb.libData
	gdb.libDataSerializer
	gdb.libDebug
	gdb.libDI
	gdb.libEvent
	gdb.libFileSystem
	gdb.libFormat
	gdb.libJson
	gdb.libKernel
	gdb.libLog
	gdb.libMath
	gdb.libMemory
	gdb.libProfiler
	gdb.libProject
)
