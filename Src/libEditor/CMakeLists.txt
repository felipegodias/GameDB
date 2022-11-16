add_library(gdb.libEditor STATIC 
	"Editor.cpp"
	"EditorMenu.cpp"
	"EditorMenuGroup.cpp"
	"EditorMenuItem.cpp"
	"EditorWindow.cpp"
)

target_include_directories(gdb.libEditor PUBLIC
    "Include"
)

target_link_libraries(gdb.libEditor PUBLIC
	gdb.libCore
	imgui::imgui
)
