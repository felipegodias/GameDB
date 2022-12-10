add_library(gdb.libLogEditor STATIC
    "ConsoleEditorWindow.cpp"
    "LoggerSinkConsole.cpp"
)

target_include_directories(gdb.libLogEditor PUBLIC
    "Include"
)

target_link_libraries(gdb.libLogEditor PUBLIC
    gdb.libLog
    gdb.libEditor
)
