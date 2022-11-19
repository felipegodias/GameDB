add_library(gdb.libEditorTheme STATIC
    "Palette.cpp"
    "Style.cpp"
    "Theme.cpp"
)

target_include_directories(gdb.libEditorTheme PUBLIC
    "Include"
)

target_link_libraries(gdb.libEditorTheme PUBLIC
    gdb.libCore
    imgui::imgui
)
