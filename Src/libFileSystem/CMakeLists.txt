add_library(gdb.libFileSystem STATIC
    "File.cpp"
    "FileSystem.cpp"
    "NativeFile.cpp"
    "NativeFileSystem.cpp"
    "VirtualFileSystem.cpp"
)

target_include_directories(gdb.libFileSystem PUBLIC
    "Include"
)

target_link_libraries(gdb.libFileSystem PUBLIC
    gdb.libContainer
    gdb.libMemory
)
