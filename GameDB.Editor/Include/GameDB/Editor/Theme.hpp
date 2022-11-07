#ifndef PLUTO_GAME_DB_EDITOR_THEME_H
#define PLUTO_GAME_DB_EDITOR_THEME_H

#include <string>

#include "Palette.hpp"
#include "Style.hpp"
#include "GameDB/Serializers/Json.hpp"

namespace Pluto::GameDB::Editor
{
    /**
     * \brief 
     */
    struct Theme final
    {
        std::string name;
        std::string font;
        Style style;
        Palette palette;
    };

    GAME_DB_JSON_DEFINE_TYPE_NON_INTRUSIVE(
        Theme,
        name,
        font,
        style,
        palette
    );
}

#endif // ! PLUTO_GAME_DB_EDITOR_THEME_H
