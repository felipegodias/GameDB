#ifndef GDB_LIB_EDITOR_THEME_SERIALIZER_PALETTE_JSON_SERIALIZER_HPP
#define GDB_LIB_EDITOR_THEME_SERIALIZER_PALETTE_JSON_SERIALIZER_HPP

#include "GameDB/EditorTheme/Palette.hpp"
#include "GameDB/Json/Json.hpp"
#include "GameDB/MathSerializer/ColorJsonSerializer.hpp"

namespace GDB
{
    GAME_DB_JSON_DEFINE_TYPE_NON_INTRUSIVE(
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

#endif // !GDB_LIB_EDITOR_THEME_SERIALIZER_PALETTE_JSON_SERIALIZER_HPP
