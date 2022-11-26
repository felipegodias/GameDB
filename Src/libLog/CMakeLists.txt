add_library(gdb.libLog STATIC 
    "Log.cpp"
    "LogEntry.cpp"
    "LogSink.cpp"
    "LogSinkStdOut.cpp"
    "LogSpool.cpp"
    "LogType.cpp"
)

target_include_directories(gdb.libLog PUBLIC
    "Include"
)

target_link_libraries(gdb.libLog PUBLIC
	gdb.libContainer
    gdb.libKernel
)
