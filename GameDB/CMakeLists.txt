add_library(GameDB STATIC 
    "Src/HelloWorld.cpp"
)

configure_file("Include/GameDB/Config.hpp.in" "GameDB/Include/GameDB/Config.hpp")

target_include_directories(GameDB PUBLIC
    "Include"
    "${CMAKE_CURRENT_BINARY_DIR}/GameDB/Include"
)
