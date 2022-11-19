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
        Color Text;
        Color TextDisabled;
        Color WindowBg;
        Color ChildBg;
        Color PopupBg;
        Color Border;
        Color BorderShadow;
        Color FrameBg;
        Color FrameBgHovered;
        Color FrameBgActive;
        Color TitleBg;
        Color TitleBgActive;
        Color TitleBgCollapsed;
        Color MenuBarBg;
        Color ScrollbarBg;
        Color ScrollbarGrab;
        Color ScrollbarGrabHovered;
        Color ScrollbarGrabActive;
        Color CheckMark;
        Color SliderGrab;
        Color SliderGrabActive;
        Color Button;
        Color ButtonHovered;
        Color ButtonActive;
        Color Header;
        Color HeaderHovered;
        Color HeaderActive;
        Color Separator;
        Color SeparatorHovered;
        Color SeparatorActive;
        Color ResizeGrip;
        Color ResizeGripHovered;
        Color ResizeGripActive;
        Color Tab;
        Color TabHovered;
        Color TabActive;
        Color TabUnfocused;
        Color TabUnfocusedActive;
        Color DockingPreview;
        Color DockingEmptyBg;
        Color PlotLines;
        Color PlotLinesHovered;
        Color PlotHistogram;
        Color PlotHistogramHovered;
        Color TableHeaderBg;
        Color TableBorderStrong;
        Color TableBorderLight;
        Color TableRowBg;
        Color TableRowBgAlt;
        Color TextSelectedBg;
        Color DragDropTarget;
        Color NavHighlight;
        Color NavWindowingHighlight;
        Color NavWindowingDimBg;
        Color ModalWindowDimBg;
    };
}

#endif // !GDB_LIB_EDITOR_THEME_PALETTE_HPP
