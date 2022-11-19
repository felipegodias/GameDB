#ifndef GDB_LIB_EDITOR_THEME_SERIALIZER_PALETTE_JSON_SERIALIZER_HPP
#define GDB_LIB_EDITOR_THEME_SERIALIZER_PALETTE_JSON_SERIALIZER_HPP

#include "GameDB/EditorTheme/Palette.hpp"
#include "GameDB/Json/Json.hpp"
#include "GameDB/MathSerializer/ColorJsonSerializer.hpp"

namespace GDB
{
    GAME_DB_JSON_DEFINE_TYPE_NON_INTRUSIVE(
        Palette,
        Text,
        TextDisabled,
        WindowBg,
        ChildBg,
        PopupBg,
        Border,
        BorderShadow,
        FrameBg,
        FrameBgHovered,
        FrameBgActive,
        TitleBg,
        TitleBgActive,
        TitleBgCollapsed,
        MenuBarBg,
        ScrollbarBg,
        ScrollbarGrab,
        ScrollbarGrabHovered,
        ScrollbarGrabActive,
        CheckMark,
        SliderGrab,
        SliderGrabActive,
        Button,
        ButtonHovered,
        ButtonActive,
        Header,
        HeaderHovered,
        HeaderActive,
        Separator,
        SeparatorHovered,
        SeparatorActive,
        ResizeGrip,
        ResizeGripHovered,
        ResizeGripActive,
        Tab,
        TabHovered,
        TabActive,
        TabUnfocused,
        TabUnfocusedActive,
        DockingPreview,
        DockingEmptyBg,
        PlotLines,
        PlotLinesHovered,
        PlotHistogram,
        PlotHistogramHovered,
        TableHeaderBg,
        TableBorderStrong,
        TableBorderLight,
        TableRowBg,
        TableRowBgAlt,
        TextSelectedBg,
        DragDropTarget,
        NavHighlight,
        NavWindowingHighlight,
        NavWindowingDimBg,
        ModalWindowDimBg
    );
}

#endif // !GDB_LIB_EDITOR_THEME_SERIALIZER_PALETTE_JSON_SERIALIZER_HPP
