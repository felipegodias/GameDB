add_library(gdb.libMathSerializer STATIC
    "ColorJsonSerializer.cpp"
    "Vector2JsonSerializer.cpp"
)

target_include_directories(gdb.libMathSerializer PUBLIC
    "Include"
)

target_link_libraries(gdb.libMathSerializer PUBLIC
    gdb.libMath
    gdb.libJson
)
