add_library(gdb.libDebugEditor STATIC
    "ConsoleEditorWindow.cpp"
    "LoggerSinkConsole.cpp"
)

target_include_directories(gdb.libDebugEditor PUBLIC
    "Include"
)

target_link_libraries(gdb.libDebugEditor PUBLIC
    gdb.libDebug
    gdb.libEditor
)
