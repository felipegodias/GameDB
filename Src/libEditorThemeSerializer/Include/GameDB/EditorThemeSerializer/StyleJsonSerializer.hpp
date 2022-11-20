#ifndef GDB_LIB_EDITOR_THEME_SERIALIZER_STYLE_JSON_SERIALIZER_HPP
#define GDB_LIB_EDITOR_THEME_SERIALIZER_STYLE_JSON_SERIALIZER_HPP

#include "GameDB/EditorTheme/Style.hpp"
#include "GameDB/Json/Json.hpp"
#include "GameDB/MathSerializer/Vector2JsonSerializer.hpp"

namespace GDB
{
    GAME_DB_JSON_DEFINE_TYPE_NON_INTRUSIVE(
        Style,
        windowPadding,
        framePadding,
        cellPadding,
        itemSpacing,
        itemInnerSpacing,
        touchExtraPadding,
        indentSpacing,
        scrollbarSize,
        grabMinSize,
        windowBorderSize,
        childBorderSize,
        popupBorderSize,
        frameBorderSize,
        tabBorderSize,
        windowRounding,
        childRounding,
        frameRounding,
        popupRounding,
        scrollbarRounding,
        grabRounding,
        logSliderDeadZone,
        tabRounding
    );
}

#endif // !GDB_LIB_EDITOR_THEME_SERIALIZER_STYLE_JSON_SERIALIZER_HPP
