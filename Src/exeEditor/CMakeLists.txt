add_executable(gdb.exeEditor
    "Main.cpp"
)

target_link_libraries(gdb.exeEditor PRIVATE 
    gdb.libWindow
    gdb.libEditor
    gdb.libDataEditor
    argparse::argparse
)

configure_file("Include/GameDB/Config.hpp.in" "GameDB/Include/GameDB/Config.hpp")

target_include_directories(gdb.exeEditor PRIVATE
    "Include"
    "${CMAKE_CURRENT_BINARY_DIR}/GameDB/Include"
)
