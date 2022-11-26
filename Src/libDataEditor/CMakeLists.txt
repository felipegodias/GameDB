add_library(gdb.libDataEditor STATIC 
	"CreateDataTableEditorWindow.cpp"
	"DataEditorWidgets.cpp"
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
