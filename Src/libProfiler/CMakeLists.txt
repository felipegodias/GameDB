add_library(gdb.libProfiler STATIC 
    "Profiler.cpp"
    "ProfileScopeGuard.cpp"
    "ProfileSectionGuard.cpp"
)

target_include_directories(gdb.libProfiler PUBLIC
    "Include"
)

target_link_libraries(gdb.libProfiler PUBLIC
	gdb.libContainer
    gdb.libDebug
)
