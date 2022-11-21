add_library(gdb.libDebug STATIC 
    "Assert.cpp"
    "Log.cpp"
    "LogEntry.cpp"
    "LogSink.cpp"
    "LogSinkStdOut.cpp"
    "LogSpool.cpp"
    "LogType.cpp"
    "Profiler.cpp"
    "ProfileScopeGuard.cpp"
    "ProfileSectionGuard.cpp"
)

target_include_directories(gdb.libDebug PUBLIC
    "Include"
)

target_link_libraries(gdb.libDebug PUBLIC
	gdb.libContainer
)
