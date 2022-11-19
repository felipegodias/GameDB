add_library(gdb.libEditorThemeSerializer STATIC
    "PaletteJsonSerializer.cpp"
    "StyleJsonSerializer.cpp"
    "ThemeJsonSerializer.cpp"
)

target_include_directories(gdb.libEditorThemeSerializer PUBLIC
    "Include"
)

target_link_libraries(gdb.libEditorThemeSerializer PUBLIC
    gdb.libEditorTheme
    gdb.libJson
    gdb.libMathSerializer
)
