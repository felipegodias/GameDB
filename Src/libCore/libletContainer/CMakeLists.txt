add_library(libletContainer STATIC 
    "String.cpp"
    "UnorderedMap.cpp"
    "UnorderedSet.cpp"
    "Vector.cpp"
)

target_include_directories(libletContainer PUBLIC
    "Include"
)

target_link_libraries(libletContainer PUBLIC
	libletMemory
)
