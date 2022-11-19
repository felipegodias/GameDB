#ifndef GDB_LIB_EDITOR_THEME_THEME_HPP
#define GDB_LIB_EDITOR_THEME_THEME_HPP

#include "Palette.hpp"
#include "Style.hpp"
#include "GameDB/Container/String.hpp"

namespace GDB
{
    /**
     * \brief
     */
    struct Theme final
    {
        String Name;
        String Font;
        Style Style;
        Palette Palette;

        static void Apply(const Theme& theme);
    };
}

#endif // !GDB_LIB_EDITOR_THEME_THEME_HPP
