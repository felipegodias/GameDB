add_library(GameDB STATIC 
    "Src/Core/Pointers.cpp"
    "Src/Data/BaseType.cpp"
    "Src/Data/BaseValue.cpp"
    "Src/Data/Field.cpp"
    "Src/Data/Guid.cpp"
    "Src/Data/Schema.cpp"
    "Src/Data/StringType.cpp"
    "Src/Data/StringValue.cpp"
    "Src/Data/Table.cpp"
    "Src/Data/TableRow.cpp"
    "Src/Debug/Assert.cpp"
    "Src/DI/DIContainer.cpp"
    "Src/Serializers/Json.cpp"
    "Src/HelloWorld.cpp"
 )

configure_file("Include/GameDB/Config.hpp.in" "GameDB/Include/GameDB/Config.hpp")

target_include_directories(GameDB PUBLIC
    "Include"
    "${CMAKE_CURRENT_BINARY_DIR}/GameDB/Include"
)

target_link_libraries(GameDB PUBLIC
    Microsoft.GSL::GSL
    fmt::fmt-header-only
    nlohmann_json::nlohmann_json
    spdlog::spdlog
)
