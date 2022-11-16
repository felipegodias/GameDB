add_library(gdb.libWindow STATIC 
	"Window.cpp"	
)

target_include_directories(gdb.libWindow PUBLIC
    "Include"
)

target_link_libraries(gdb.libWindow PUBLIC
    gdb.libCore
    GLEW::GLEW
    glfw
    imgui::imgui
)
