add_library(gdb.libEvent STATIC 
    "Event.cpp"
 )

target_include_directories(gdb.libEvent PUBLIC
    "Include"
)

target_link_libraries(gdb.libEvent PUBLIC
    gdb.libContainer
)
