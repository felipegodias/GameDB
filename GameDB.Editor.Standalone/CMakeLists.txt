add_executable(GameDB.Editor.Standalone
    "Src/Main.cpp"
)

target_link_libraries(GameDB.Editor.Standalone PRIVATE 
    libCore
    GameDB.Editor
    argparse::argparse
    fmt::fmt-header-only
)

install(TARGETS GameDB.Editor.Standalone)
