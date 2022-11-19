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
            return { color.R, color.G, color.B, color.A };
        }

        ImVec2 ToImVec2(const Vector2& vector2)
        {
            return { vector2.X, vector2.Y };
        }
    }

    void Theme::Apply(const Theme& theme)
    {
        const float fontSize = 16.0F;
        const float fontScale = 1.25F;

        //std::filesystem::path fontPath = "/res/Fonts";
        //fontPath /= theme.Font;
        //auto fileSystem = DIContainer::Global()->Resolve<FileSystem*>();
        //auto file = fileSystem->GetFile("/res/Themes/Default.json");

        ImGui::GetIO().Fonts->AddFontFromFileTTF("Resources/Fonts/Roboto-Regular.ttf", fontSize * fontScale);

        ImGuiStyle& style = ImGui::GetStyle();
        style.WindowPadding = ToImVec2(theme.Style.WindowPadding);
        style.FramePadding = ToImVec2(theme.Style.FramePadding);
        style.CellPadding = ToImVec2(theme.Style.CellPadding);
        style.ItemSpacing = ToImVec2(theme.Style.ItemSpacing);
        style.ItemInnerSpacing = ToImVec2(theme.Style.ItemInnerSpacing);
        style.TouchExtraPadding = ToImVec2(theme.Style.TouchExtraPadding);
        style.IndentSpacing = theme.Style.IndentSpacing;
        style.ScrollbarSize = theme.Style.ScrollbarSize;
        style.GrabMinSize = theme.Style.GrabMinSize;
        style.WindowBorderSize = theme.Style.WindowBorderSize;
        style.ChildBorderSize = theme.Style.ChildBorderSize;
        style.PopupBorderSize = theme.Style.PopupBorderSize;
        style.FrameBorderSize = theme.Style.FrameBorderSize;
        style.TabBorderSize = theme.Style.TabBorderSize;
        style.WindowRounding = theme.Style.WindowRounding;
        style.ChildRounding = theme.Style.ChildRounding;
        style.FrameRounding = theme.Style.FrameRounding;
        style.PopupRounding = theme.Style.PopupRounding;
        style.ScrollbarRounding = theme.Style.ScrollbarRounding;
        style.GrabRounding = theme.Style.GrabRounding;
        style.LogSliderDeadzone = theme.Style.LogSliderDeadZone;
        style.TabRounding = theme.Style.TabRounding;

        gsl::span colors(style.Colors);
        colors[ImGuiCol_Text] = ToImVec4(theme.Palette.Text);
        colors[ImGuiCol_TextDisabled] = ToImVec4(theme.Palette.TextDisabled);
        colors[ImGuiCol_WindowBg] = ToImVec4(theme.Palette.WindowBg);
        colors[ImGuiCol_ChildBg] = ToImVec4(theme.Palette.ChildBg);
        colors[ImGuiCol_PopupBg] = ToImVec4(theme.Palette.PopupBg);
        colors[ImGuiCol_Border] = ToImVec4(theme.Palette.Border);
        colors[ImGuiCol_BorderShadow] = ToImVec4(theme.Palette.BorderShadow);
        colors[ImGuiCol_FrameBg] = ToImVec4(theme.Palette.FrameBg);
        colors[ImGuiCol_FrameBgHovered] = ToImVec4(theme.Palette.FrameBgHovered);
        colors[ImGuiCol_FrameBgActive] = ToImVec4(theme.Palette.FrameBgActive);
        colors[ImGuiCol_TitleBg] = ToImVec4(theme.Palette.TitleBg);
        colors[ImGuiCol_TitleBgActive] = ToImVec4(theme.Palette.TitleBgActive);
        colors[ImGuiCol_TitleBgCollapsed] = ToImVec4(theme.Palette.TitleBgCollapsed);
        colors[ImGuiCol_MenuBarBg] = ToImVec4(theme.Palette.MenuBarBg);
        colors[ImGuiCol_ScrollbarBg] = ToImVec4(theme.Palette.ScrollbarBg);
        colors[ImGuiCol_ScrollbarGrab] = ToImVec4(theme.Palette.ScrollbarGrab);
        colors[ImGuiCol_ScrollbarGrabHovered] = ToImVec4(theme.Palette.ScrollbarGrabHovered);
        colors[ImGuiCol_ScrollbarGrabActive] = ToImVec4(theme.Palette.ScrollbarGrabActive);
        colors[ImGuiCol_CheckMark] = ToImVec4(theme.Palette.CheckMark);
        colors[ImGuiCol_SliderGrab] = ToImVec4(theme.Palette.SliderGrab);
        colors[ImGuiCol_SliderGrabActive] = ToImVec4(theme.Palette.SliderGrabActive);
        colors[ImGuiCol_Button] = ToImVec4(theme.Palette.Button);
        colors[ImGuiCol_ButtonHovered] = ToImVec4(theme.Palette.ButtonHovered);
        colors[ImGuiCol_ButtonActive] = ToImVec4(theme.Palette.ButtonActive);
        colors[ImGuiCol_Header] = ToImVec4(theme.Palette.Header);
        colors[ImGuiCol_HeaderHovered] = ToImVec4(theme.Palette.HeaderHovered);
        colors[ImGuiCol_HeaderActive] = ToImVec4(theme.Palette.HeaderActive);
        colors[ImGuiCol_Separator] = ToImVec4(theme.Palette.Separator);
        colors[ImGuiCol_SeparatorHovered] = ToImVec4(theme.Palette.SeparatorHovered);
        colors[ImGuiCol_SeparatorActive] = ToImVec4(theme.Palette.SeparatorActive);
        colors[ImGuiCol_ResizeGrip] = ToImVec4(theme.Palette.ResizeGrip);
        colors[ImGuiCol_ResizeGripHovered] = ToImVec4(theme.Palette.ResizeGripHovered);
        colors[ImGuiCol_ResizeGripActive] = ToImVec4(theme.Palette.ResizeGripActive);
        colors[ImGuiCol_Tab] = ToImVec4(theme.Palette.Tab);
        colors[ImGuiCol_TabHovered] = ToImVec4(theme.Palette.TabHovered);
        colors[ImGuiCol_TabActive] = ToImVec4(theme.Palette.TabActive);
        colors[ImGuiCol_TabUnfocused] = ToImVec4(theme.Palette.TabUnfocused);
        colors[ImGuiCol_TabUnfocusedActive] = ToImVec4(theme.Palette.TabUnfocusedActive);
        colors[ImGuiCol_DockingPreview] = ToImVec4(theme.Palette.DockingPreview);
        colors[ImGuiCol_DockingEmptyBg] = ToImVec4(theme.Palette.DockingEmptyBg);
        colors[ImGuiCol_PlotLines] = ToImVec4(theme.Palette.PlotLines);
        colors[ImGuiCol_PlotLinesHovered] = ToImVec4(theme.Palette.PlotLinesHovered);
        colors[ImGuiCol_PlotHistogram] = ToImVec4(theme.Palette.PlotHistogram);
        colors[ImGuiCol_PlotHistogramHovered] = ToImVec4(theme.Palette.PlotHistogramHovered);
        colors[ImGuiCol_TableHeaderBg] = ToImVec4(theme.Palette.TableHeaderBg);
        colors[ImGuiCol_TableBorderStrong] = ToImVec4(theme.Palette.TableBorderStrong);
        colors[ImGuiCol_TableBorderLight] = ToImVec4(theme.Palette.TableBorderLight);
        colors[ImGuiCol_TableRowBg] = ToImVec4(theme.Palette.TableRowBg);
        colors[ImGuiCol_TableRowBgAlt] = ToImVec4(theme.Palette.TableRowBgAlt);
        colors[ImGuiCol_TextSelectedBg] = ToImVec4(theme.Palette.TextSelectedBg);
        colors[ImGuiCol_DragDropTarget] = ToImVec4(theme.Palette.DragDropTarget);
        colors[ImGuiCol_NavHighlight] = ToImVec4(theme.Palette.NavHighlight);
        colors[ImGuiCol_NavWindowingHighlight] = ToImVec4(theme.Palette.NavWindowingHighlight);
        colors[ImGuiCol_NavWindowingDimBg] = ToImVec4(theme.Palette.NavWindowingDimBg);
        colors[ImGuiCol_ModalWindowDimBg] = ToImVec4(theme.Palette.ModalWindowDimBg);
    }
}
