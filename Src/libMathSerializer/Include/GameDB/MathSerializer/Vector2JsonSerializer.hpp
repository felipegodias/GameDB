#ifndef GDB_LIB_MATH_SERIALIZER_VECTOR_2_JSON_SERIALIZER_HPP
#define GDB_LIB_MATH_SERIALIZER_VECTOR_2_JSON_SERIALIZER_HPP

#include "GameDB/Json/Json.hpp"
#include "GameDB/Math/Vector2.hpp"

namespace GDB
{
    GAME_DB_JSON_DEFINE_TYPE_NON_INTRUSIVE(
        Vector2,
        x,
        y
    );
}

#endif // !GDB_LIB_MATH_SERIALIZER_VECTOR_2_JSON_SERIALIZER_HPP
