add_library(gdb.libContainer STATIC 
    "Map.cpp"
    "RingBuffer.cpp"
    "String.cpp"
    "StringStream.cpp"
    "UnorderedMap.cpp"
    "UnorderedSet.cpp"
    "Vector.cpp"
)

target_include_directories(gdb.libContainer PUBLIC
    "Include"
)

target_link_libraries(gdb.libContainer PUBLIC
	gdb.libMemory
)
