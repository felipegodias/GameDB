#ifndef GDB_LIB_EDITOR_THEME_PALETTE_HPP
#define GDB_LIB_EDITOR_THEME_PALETTE_HPP

#include "GameDB/Math/Color.hpp"

namespace GDB
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
}

#endif // !GDB_LIB_EDITOR_THEME_PALETTE_HPP
