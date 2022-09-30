add_library(GameDB.Editor STATIC 
    "Src/HelloWorld.cpp"
    "Src/Application.cpp"
)

target_include_directories(GameDB.Editor PUBLIC
    "Include"
)

target_link_libraries(GameDB.Editor PUBLIC GameDB)

target_link_libraries(GameDB.Editor PRIVATE
    GLEW::GLEW
    glfw
    imgui::imgui
)
