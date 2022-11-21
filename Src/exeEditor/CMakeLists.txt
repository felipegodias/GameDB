add_executable(gdb.exeEditor
    "Main.cpp"
)

target_link_libraries(gdb.exeEditor PRIVATE 
    gdb.libWindow
    gdb.libEditor
    gdb.libEditorThemeSerializer
    gdb.libDataEditor
    gdb.libDebugEditor
    argparse::argparse
)

configure_file("Include/GameDB/Config.hpp.in" "GameDB/Include/GameDB/Config.hpp")

target_include_directories(gdb.exeEditor PRIVATE
    "Include"
    "${CMAKE_CURRENT_BINARY_DIR}/GameDB/Include"
)

add_custom_command(TARGET gdb.exeEditor POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Resources ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIGURATION>/Resources
)