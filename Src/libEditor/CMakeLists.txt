add_library(gdb.libEditor STATIC 
	"Editor.cpp"
	"EditorMenu.cpp"
	"EditorMenuGroup.cpp"
	"EditorMenuItem.cpp"
	"EditorWidgets.cpp"
	"EditorWindow.cpp"
	"FontAwesomeIcons.cpp"
)

target_include_directories(gdb.libEditor PUBLIC
    "Include"
)

target_link_libraries(gdb.libEditor PUBLIC
	gdb.libCore
	gdb.libLog
	gdb.libProfiler
	gdb.libEditorTheme
	gdb.libEditorThemeSerializer
	imgui::imgui
)
