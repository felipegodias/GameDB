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
        Vector2 windowPadding;
        Vector2 framePadding;
        Vector2 cellPadding;
        Vector2 itemSpacing;
        Vector2 itemInnerSpacing;
        Vector2 touchExtraPadding;
        float indentSpacing = 0.0F;
        float scrollbarSize = 0.0F;
        float grabMinSize = 0.0F;
        float windowBorderSize = 0.0F;
        float childBorderSize = 0.0F;
        float popupBorderSize = 0.0F;
        float frameBorderSize = 0.0F;
        float tabBorderSize = 0.0F;
        float windowRounding = 0.0F;
        float childRounding = 0.0F;
        float frameRounding = 0.0F;
        float popupRounding = 0.0F;
        float scrollbarRounding = 0.0F;
        float grabRounding = 0.0F;
        float logSliderDeadZone = 0.0F;
        float tabRounding = 0.0F;
    };
}

#endif // !GDB_LIB_EDITOR_THEME_STYLE_HPP
