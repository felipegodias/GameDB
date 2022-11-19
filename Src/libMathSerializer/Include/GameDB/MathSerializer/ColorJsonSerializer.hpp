#ifndef GDB_LIB_MATH_SERIALIZER_COLOR_JSON_SERIALIZER_HPP
#define GDB_LIB_MATH_SERIALIZER_COLOR_JSON_SERIALIZER_HPP

#include "GameDB/Json/Json.hpp"
#include "GameDB/Math/Color.hpp"

namespace GDB
{
    void to_json(Json& json, const Color& color);
    void from_json(const Json& json, Color& color);
}

#endif // !GDB_LIB_MATH_SERIALIZER_COLOR_JSON_SERIALIZER_HPP
