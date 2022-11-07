#ifndef PLUTO_GAME_DB_EDITOR_VECTOR_2_H
#define PLUTO_GAME_DB_EDITOR_VECTOR_2_H

#include "GameDB/Serializers/Json.hpp"

namespace Pluto::GameDB::Editor
{
    struct Vector2 final
    {
        float x = 0.0F; // NOLINT(readability-identifier-length)
        float y = 0.0F; // NOLINT(readability-identifier-length)
    };

    GAME_DB_JSON_DEFINE_TYPE_NON_INTRUSIVE(
        Vector2,
        x,
        y
    );
}

#endif // ! PLUTO_GAME_DB_EDITOR_VECTOR_2_H
