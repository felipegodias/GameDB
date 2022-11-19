#ifndef GDB_LIB_EDITOR_THEME_STYLE_HPP
#define GDB_LIB_EDITOR_THEME_STYLE_HPP

#include "GameDB/Math/Vector2.hpp"

namespace GDB
{
    /**
     * \brief
     */
    struct Style final
    {
        Vector2 WindowPadding;
        Vector2 FramePadding;
        Vector2 CellPadding;
        Vector2 ItemSpacing;
        Vector2 ItemInnerSpacing;
        Vector2 TouchExtraPadding;
        float IndentSpacing = 0.0F;
        float ScrollbarSize = 0.0F;
        float GrabMinSize = 0.0F;
        float WindowBorderSize = 0.0F;
        float ChildBorderSize = 0.0F;
        float PopupBorderSize = 0.0F;
        float FrameBorderSize = 0.0F;
        float TabBorderSize = 0.0F;
        float WindowRounding = 0.0F;
        float ChildRounding = 0.0F;
        float FrameRounding = 0.0F;
        float PopupRounding = 0.0F;
        float ScrollbarRounding = 0.0F;
        float GrabRounding = 0.0F;
        float LogSliderDeadZone = 0.0F;
        float TabRounding = 0.0F;
    };
}

#endif // !GDB_LIB_EDITOR_THEME_STYLE_HPP
