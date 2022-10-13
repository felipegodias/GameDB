#ifndef PLUTO_GAME_DB_EDITOR_PALETTE_H
#define PLUTO_GAME_DB_EDITOR_PALETTE_H

#include <nlohmann/json.hpp>

#include "Color.hpp"

namespace Pluto::GameDB::Editor
{
    /**
     * \brief 
     */
    struct Palette final
    {
        Color text;
        Color textDisabled;
        Color windowBg;
        Color childBg;
        Color popupBg;
        Color border;
        Color borderShadow;
        Color frameBg;
        Color frameBgHovered;
        Color frameBgActive;
        Color titleBg;
        Color titleBgActive;
        Color titleBgCollapsed;
        Color menuBarBg;
        Color scrollbarBg;
        Color scrollbarGrab;
        Color scrollbarGrabHovered;
        Color scrollbarGrabActive;
        Color checkMark;
        Color sliderGrab;
        Color sliderGrabActive;
        Color button;
        Color buttonHovered;
        Color buttonActive;
        Color header;
        Color headerHovered;
        Color headerActive;
        Color separator;
        Color separatorHovered;
        Color separatorActive;
        Color resizeGrip;
        Color resizeGripHovered;
        Color resizeGripActive;
        Color tab;
        Color tabHovered;
        Color tabActive;
        Color tabUnfocused;
        Color tabUnfocusedActive;
        Color dockingPreview;
        Color dockingEmptyBg;
        Color plotLines;
        Color plotLinesHovered;
        Color plotHistogram;
        Color plotHistogramHovered;
        Color tableHeaderBg;
        Color tableBorderStrong;
        Color tableBorderLight;
        Color tableRowBg;
        Color tableRowBgAlt;
        Color textSelectedBg;
        Color dragDropTarget;
        Color navHighlight;
        Color navWindowingHighlight;
        Color navWindowingDimBg;
        Color modalWindowDimBg;
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(
        Palette,
        text,
        textDisabled,
        windowBg,
        childBg,
        popupBg,
        border,
        borderShadow,
        frameBg,
        frameBgHovered,
        frameBgActive,
        titleBg,
        titleBgActive,
        titleBgCollapsed,
        menuBarBg,
        scrollbarBg,
        scrollbarGrab,
        scrollbarGrabHovered,
        scrollbarGrabActive,
        checkMark,
        sliderGrab,
        sliderGrabActive,
        button,
        buttonHovered,
        buttonActive,
        header,
        headerHovered,
        headerActive,
        separator,
        separatorHovered,
        separatorActive,
        resizeGrip,
        resizeGripHovered,
        resizeGripActive,
        tab,
        tabHovered,
        tabActive,
        tabUnfocused,
        tabUnfocusedActive,
        dockingPreview,
        dockingEmptyBg,
        plotLines,
        plotLinesHovered,
        plotHistogram,
        plotHistogramHovered,
        tableHeaderBg,
        tableBorderStrong,
        tableBorderLight,
        tableRowBg,
        tableRowBgAlt,
        textSelectedBg,
        dragDropTarget,
        navHighlight,
        navWindowingHighlight,
        navWindowingDimBg,
        modalWindowDimBg
    );
}

#endif // ! PLUTO_GAME_DB_EDITOR_PALETTE_H
