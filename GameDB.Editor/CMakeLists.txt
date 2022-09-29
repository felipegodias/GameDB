add_library(GameDB.Editor STATIC 
    "Src/HelloWorld.cpp"
)

target_include_directories(GameDB.Editor PUBLIC
    "Include"
)

target_link_libraries(GameDB.Editor PUBLIC GameDB)
