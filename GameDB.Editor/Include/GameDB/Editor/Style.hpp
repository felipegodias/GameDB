#ifndef PLUTO_GAME_DB_EDITOR_STYLE_H
#define PLUTO_GAME_DB_EDITOR_STYLE_H

#include "Vector2.hpp"
#include "GameDB/Serializers/Json.hpp"

namespace Pluto::GameDB::Editor
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
        float logSliderDeadzone = 0.0F;
        float tabRounding = 0.0F;
    };

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
        logSliderDeadzone,
        tabRounding
    );
}

#endif // ! PLUTO_GAME_DB_EDITOR_STYLE_H
