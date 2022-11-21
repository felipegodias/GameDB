add_library(gdb.libDebug STATIC 
    "Assert.cpp"
    "Log.cpp"
    "LogEntry.cpp"
    "LogSink.cpp"
    "LogSinkStdOut.cpp"
    "LogSpool.cpp"
    "LogType.cpp"
    "ProfileFrameSample.cpp"
    "Profiler.cpp"
    "ProfileScopeSample.cpp"
)

target_include_directories(gdb.libDebug PUBLIC
    "Include"
)

target_link_libraries(gdb.libDebug PUBLIC
	gdb.libContainer
)
