#ifndef PLUTO_GAME_DB_EDITOR_THEME_H
#define PLUTO_GAME_DB_EDITOR_THEME_H

#include <string>
#include <nlohmann/json.hpp>

#include "Palette.hpp"
#include "Style.hpp"

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

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(
        Theme,
        name,
        font,
        style,
        palette
    );
}

#endif // ! PLUTO_GAME_DB_EDITOR_THEME_H
