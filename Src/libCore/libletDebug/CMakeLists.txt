add_library(libletDebug STATIC 
    "Assert.cpp"
    "Log.cpp"
    "Logger.cpp"
    "LoggerSink.cpp"
    "LoggerSinkStdOut.cpp"
    "ProfileFrameSample.cpp"
    "Profiler.cpp"
    "ProfileScopeSample.cpp"
)

target_include_directories(libletDebug PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/Include"
)

target_link_libraries(libletDebug PUBLIC
	fmt::fmt-header-only
)
