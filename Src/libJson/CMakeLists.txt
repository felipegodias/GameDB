add_library(gdb.libJson STATIC 
    "Json.cpp"
)

target_include_directories(gdb.libJson PUBLIC
    "Include"
)

target_link_libraries(gdb.libJson PUBLIC
    nlohmann_json::nlohmann_json
)
