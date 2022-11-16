add_library(gdb.libMemory STATIC 
    "FreeListAllocator.cpp"
    "GeneralAllocator.cpp"
    "MallocAllocator.cpp"
    "NewAllocator.cpp"
    "Pointers.cpp"
    "StlContainerAllocator.cpp"
    "ThresholdAllocator.cpp"
    "TrackerAllocator.cpp"
 )

target_include_directories(gdb.libMemory PUBLIC
    "Include"
)

target_link_libraries(gdb.libMemory PUBLIC
	Microsoft.GSL::GSL
)
