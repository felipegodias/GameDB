add_executable(GameDB.Editor.Standalone
    "Src/Main.cpp"
)

target_link_libraries(GameDB.Editor.Standalone PRIVATE 
    GameDB.Editor
)

install(TARGETS GameDB.Editor.Standalone)
