add_library(gdb.libDataEditor STATIC 
	"DataSetEditorWindow.cpp"
	"DataTableEditorWindow.cpp"
)

target_include_directories(gdb.libDataEditor PUBLIC
    "Include"
)

target_link_libraries(gdb.libDataEditor PUBLIC
	gdb.libData
	gdb.libEditor
	gdb.libProfiler
)
