add_executable(GameDB.Editor.Standalone
    "Src/Main.cpp"
)

target_link_libraries(GameDB.Editor.Standalone PRIVATE 
    GameDB.Editor
    argparse::argparse
    fmt::fmt
)

install(TARGETS GameDB.Editor.Standalone)
