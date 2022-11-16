add_library(gdb.libDebug STATIC 
    "Assert.cpp"
    "Log.cpp"
    "Logger.cpp"
    "LoggerSink.cpp"
    "LoggerSinkStdOut.cpp"
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
