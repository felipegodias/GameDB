add_library(gdb.libDataEditor STATIC 
	"DataTableEditorWindow.cpp"
)

target_include_directories(gdb.libDataEditor PUBLIC
    "Include"
)

target_link_libraries(gdb.libDataEditor PUBLIC
	gdb.libData
	gdb.libEditor
)
