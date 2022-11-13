add_library(libletMemory STATIC 
    "GeneralAllocator.cpp"
    "MallocAllocator.cpp"
    "NewAllocator.cpp"
    "Pointers.cpp"
    "StlContainerAllocator.cpp"
    "ThresholdAllocator.cpp"
 )

target_include_directories(libletMemory PUBLIC
    "Include"
)

target_link_libraries(libletMemory PUBLIC
	Microsoft.GSL::GSL
)
