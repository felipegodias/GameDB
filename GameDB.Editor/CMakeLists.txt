add_library(GameDB.Editor STATIC 
    "Src/Color.cpp"
    "Src/HelloWorld.cpp"
    "Src/Application.cpp"
    "Src/Palette.cpp"
    "Src/Style.cpp"
    "Src/Theme.cpp"
    "Src/Vector2.cpp"
)

target_include_directories(GameDB.Editor PUBLIC
    "Include"
)

target_link_libraries(GameDB.Editor PUBLIC GameDB)

target_link_libraries(GameDB.Editor PRIVATE
    GLEW::GLEW
    glfw
    imgui::imgui
    libCore
)

message (${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

add_custom_command(TARGET GameDB.Editor POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Resources ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIGURATION>/Resources
)