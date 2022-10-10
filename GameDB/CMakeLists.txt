add_library(GameDB STATIC 
    "Src/Data/BaseType.cpp"
    "Src/Data/BaseValue.cpp"
    "Src/Data/Field.cpp"
    "Src/Data/Guid.cpp"
    "Src/Data/Schema.cpp"
    "Src/Data/StringType.cpp"
    "Src/Data/StringValue.cpp"
    "Src/Debug/Assert.cpp"
    "Src/HelloWorld.cpp"
 )

configure_file("Include/GameDB/Config.hpp.in" "GameDB/Include/GameDB/Config.hpp")

target_include_directories(GameDB PUBLIC
    "Include"
    "${CMAKE_CURRENT_BINARY_DIR}/GameDB/Include"
)

target_link_libraries(GameDB PUBLIC
    Microsoft.GSL::GSL
)    

target_link_libraries(GameDB PRIVATE
    fmt::fmt
    nlohmann_json::nlohmann_json
)
