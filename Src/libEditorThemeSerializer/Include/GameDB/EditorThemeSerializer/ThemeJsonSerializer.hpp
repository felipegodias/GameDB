#ifndef GDB_LIB_EDITOR_THEME_SERIALIZER_THEME_JSON_SERIALIZER_HPP
#define GDB_LIB_EDITOR_THEME_SERIALIZER_THEME_JSON_SERIALIZER_HPP

#include "PaletteJsonSerializer.hpp"
#include "StyleJsonSerializer.hpp"
#include "GameDB/EditorTheme/Theme.hpp"
#include "GameDB/Json/Json.hpp"

namespace GDB
{
    GAME_DB_JSON_DEFINE_TYPE_NON_INTRUSIVE(
        Theme,
        Name,
        Font,
        Style,
        Palette
    );
}

#endif // !GDB_LIB_EDITOR_THEME_SERIALIZER_THEME_JSON_SERIALIZER_HPP
