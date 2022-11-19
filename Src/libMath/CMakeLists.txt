add_library(gdb.libMath STATIC
    "Color.cpp"
    "Vector2.cpp"
)

target_include_directories(gdb.libMath PUBLIC
    "Include"
)

target_link_libraries(gdb.libMath PUBLIC
    gdb.libContainer
)
