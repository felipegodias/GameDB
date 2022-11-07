#ifndef PLUTO_GAME_DB_JSON_H
#define PLUTO_GAME_DB_JSON_H

#include <nlohmann/json.hpp>

namespace Pluto::GameDB
{
    using Json = nlohmann::json;
    using OrderedJson = nlohmann::ordered_json;

#define GAME_DB_JSON_DEFINE_TYPE_NON_INTRUSIVE(Type, ...)  \
    inline void to_json(OrderedJson& nlohmann_json_j, const Type& nlohmann_json_t) { NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_TO, __VA_ARGS__)) } \
    inline void to_json(Json& nlohmann_json_j, const Type& nlohmann_json_t) { NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_TO, __VA_ARGS__)) } \
    inline void from_json(const Json& nlohmann_json_j, Type& nlohmann_json_t) { NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_FROM, __VA_ARGS__)) }
}

#endif // ! PLUTO_GAME_DB_JSON_H
