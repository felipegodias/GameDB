#ifndef GDB_LIB_EDITOR_THEME_SERIALIZER_STYLE_JSON_SERIALIZER_HPP
#define GDB_LIB_EDITOR_THEME_SERIALIZER_STYLE_JSON_SERIALIZER_HPP

#include "GameDB/EditorTheme/Style.hpp"
#include "GameDB/Json/Json.hpp"
#include "GameDB/MathSerializer/Vector2JsonSerializer.hpp"

namespace GDB
{
    GAME_DB_JSON_DEFINE_TYPE_NON_INTRUSIVE(
        Style,
        WindowPadding,
        FramePadding,
        CellPadding,
        ItemSpacing,
        ItemInnerSpacing,
        TouchExtraPadding,
        IndentSpacing,
        ScrollbarSize,
        GrabMinSize,
        WindowBorderSize,
        ChildBorderSize,
        PopupBorderSize,
        FrameBorderSize,
        TabBorderSize,
        WindowRounding,
        ChildRounding,
        FrameRounding,
        PopupRounding,
        ScrollbarRounding,
        GrabRounding,
        LogSliderDeadZone,
        TabRounding
    );
}

#endif // !GDB_LIB_EDITOR_THEME_SERIALIZER_STYLE_JSON_SERIALIZER_HPP
