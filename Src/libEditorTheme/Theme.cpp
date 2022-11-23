#include "GameDB/EditorTheme/Theme.hpp"

#include <imgui.h>
#include <gsl/span>

#include "GameDB/DI/DIContainer.hpp"
#include "GameDB/FileSystem/FileSystem.hpp"

namespace GDB
{
    namespace 
    {
        ImVec4 ToImVec4(const Color& color)
        {
            return { color.r, color.g, color.b, color.a };
        }

        ImVec2 ToImVec2(const Vector2& vector2)
        {
            return { vector2.x, vector2.y };
        }
    }

    void Theme::Apply(const Theme& theme)
    {
        ImGuiStyle& style = ImGui::GetStyle();
        style.WindowPadding = ToImVec2(theme.style.windowPadding);
        style.FramePadding = ToImVec2(theme.style.framePadding);
        style.CellPadding = ToImVec2(theme.style.cellPadding);
        style.ItemSpacing = ToImVec2(theme.style.itemSpacing);
        style.ItemInnerSpacing = ToImVec2(theme.style.itemInnerSpacing);
        style.TouchExtraPadding = ToImVec2(theme.style.touchExtraPadding);
        style.IndentSpacing = theme.style.indentSpacing;
        style.ScrollbarSize = theme.style.scrollbarSize;
        style.GrabMinSize = theme.style.grabMinSize;
        style.WindowBorderSize = theme.style.windowBorderSize;
        style.ChildBorderSize = theme.style.childBorderSize;
        style.PopupBorderSize = theme.style.popupBorderSize;
        style.FrameBorderSize = theme.style.frameBorderSize;
        style.TabBorderSize = theme.style.tabBorderSize;
        style.WindowRounding = theme.style.windowRounding;
        style.ChildRounding = theme.style.childRounding;
        style.FrameRounding = theme.style.frameRounding;
        style.PopupRounding = theme.style.popupRounding;
        style.ScrollbarRounding = theme.style.scrollbarRounding;
        style.GrabRounding = theme.style.grabRounding;
        style.LogSliderDeadzone = theme.style.logSliderDeadZone;
        style.TabRounding = theme.style.tabRounding;

        gsl::span colors(style.Colors);
        colors[ImGuiCol_Text] = ToImVec4(theme.palette.text);
        colors[ImGuiCol_TextDisabled] = ToImVec4(theme.palette.textDisabled);
        colors[ImGuiCol_WindowBg] = ToImVec4(theme.palette.windowBg);
        colors[ImGuiCol_ChildBg] = ToImVec4(theme.palette.childBg);
        colors[ImGuiCol_PopupBg] = ToImVec4(theme.palette.popupBg);
        colors[ImGuiCol_Border] = ToImVec4(theme.palette.border);
        colors[ImGuiCol_BorderShadow] = ToImVec4(theme.palette.borderShadow);
        colors[ImGuiCol_FrameBg] = ToImVec4(theme.palette.frameBg);
        colors[ImGuiCol_FrameBgHovered] = ToImVec4(theme.palette.frameBgHovered);
        colors[ImGuiCol_FrameBgActive] = ToImVec4(theme.palette.frameBgActive);
        colors[ImGuiCol_TitleBg] = ToImVec4(theme.palette.titleBg);
        colors[ImGuiCol_TitleBgActive] = ToImVec4(theme.palette.titleBgActive);
        colors[ImGuiCol_TitleBgCollapsed] = ToImVec4(theme.palette.titleBgCollapsed);
        colors[ImGuiCol_MenuBarBg] = ToImVec4(theme.palette.menuBarBg);
        colors[ImGuiCol_ScrollbarBg] = ToImVec4(theme.palette.scrollbarBg);
        colors[ImGuiCol_ScrollbarGrab] = ToImVec4(theme.palette.scrollbarGrab);
        colors[ImGuiCol_ScrollbarGrabHovered] = ToImVec4(theme.palette.scrollbarGrabHovered);
        colors[ImGuiCol_ScrollbarGrabActive] = ToImVec4(theme.palette.scrollbarGrabActive);
        colors[ImGuiCol_CheckMark] = ToImVec4(theme.palette.checkMark);
        colors[ImGuiCol_SliderGrab] = ToImVec4(theme.palette.sliderGrab);
        colors[ImGuiCol_SliderGrabActive] = ToImVec4(theme.palette.sliderGrabActive);
        colors[ImGuiCol_Button] = ToImVec4(theme.palette.button);
        colors[ImGuiCol_ButtonHovered] = ToImVec4(theme.palette.buttonHovered);
        colors[ImGuiCol_ButtonActive] = ToImVec4(theme.palette.buttonActive);
        colors[ImGuiCol_Header] = ToImVec4(theme.palette.header);
        colors[ImGuiCol_HeaderHovered] = ToImVec4(theme.palette.headerHovered);
        colors[ImGuiCol_HeaderActive] = ToImVec4(theme.palette.headerActive);
        colors[ImGuiCol_Separator] = ToImVec4(theme.palette.separator);
        colors[ImGuiCol_SeparatorHovered] = ToImVec4(theme.palette.separatorHovered);
        colors[ImGuiCol_SeparatorActive] = ToImVec4(theme.palette.separatorActive);
        colors[ImGuiCol_ResizeGrip] = ToImVec4(theme.palette.resizeGrip);
        colors[ImGuiCol_ResizeGripHovered] = ToImVec4(theme.palette.resizeGripHovered);
        colors[ImGuiCol_ResizeGripActive] = ToImVec4(theme.palette.resizeGripActive);
        colors[ImGuiCol_Tab] = ToImVec4(theme.palette.tab);
        colors[ImGuiCol_TabHovered] = ToImVec4(theme.palette.tabHovered);
        colors[ImGuiCol_TabActive] = ToImVec4(theme.palette.tabActive);
        colors[ImGuiCol_TabUnfocused] = ToImVec4(theme.palette.tabUnfocused);
        colors[ImGuiCol_TabUnfocusedActive] = ToImVec4(theme.palette.tabUnfocusedActive);
        colors[ImGuiCol_DockingPreview] = ToImVec4(theme.palette.dockingPreview);
        colors[ImGuiCol_DockingEmptyBg] = ToImVec4(theme.palette.dockingEmptyBg);
        colors[ImGuiCol_PlotLines] = ToImVec4(theme.palette.plotLines);
        colors[ImGuiCol_PlotLinesHovered] = ToImVec4(theme.palette.plotLinesHovered);
        colors[ImGuiCol_PlotHistogram] = ToImVec4(theme.palette.plotHistogram);
        colors[ImGuiCol_PlotHistogramHovered] = ToImVec4(theme.palette.plotHistogramHovered);
        colors[ImGuiCol_TableHeaderBg] = ToImVec4(theme.palette.tableHeaderBg);
        colors[ImGuiCol_TableBorderStrong] = ToImVec4(theme.palette.tableBorderStrong);
        colors[ImGuiCol_TableBorderLight] = ToImVec4(theme.palette.tableBorderLight);
        colors[ImGuiCol_TableRowBg] = ToImVec4(theme.palette.tableRowBg);
        colors[ImGuiCol_TableRowBgAlt] = ToImVec4(theme.palette.tableRowBgAlt);
        colors[ImGuiCol_TextSelectedBg] = ToImVec4(theme.palette.textSelectedBg);
        colors[ImGuiCol_DragDropTarget] = ToImVec4(theme.palette.dragDropTarget);
        colors[ImGuiCol_NavHighlight] = ToImVec4(theme.palette.navHighlight);
        colors[ImGuiCol_NavWindowingHighlight] = ToImVec4(theme.palette.navWindowingHighlight);
        colors[ImGuiCol_NavWindowingDimBg] = ToImVec4(theme.palette.navWindowingDimBg);
        colors[ImGuiCol_ModalWindowDimBg] = ToImVec4(theme.palette.modalWindowDimBg);
    }
}
