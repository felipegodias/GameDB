#include "GameDB/Editor/Editor.hpp"

#include <algorithm>
#include <imgui.h>

#include "GameDB/libDebug.hpp"
#include "GameDB/libLog.hpp"
#include "GameDB/libProfiler.hpp"
#include "GameDB/DI/DIContainer.hpp"
#include "GameDB/FileSystem/FileSystem.hpp"
#include "GameDB/libEditorTheme.hpp"
#include "GameDB/libEditorThemeSerializer.hpp"
#include "GameDB/Editor/FontAwesomeIcons.hpp"

namespace GDB
{
    namespace
    {
        bool reloadThemeNeeded = true;

        void ReloadTheme()
        {
            GDB_PROFILE_FUNCTION();
            auto* fileSystem = DIContainer::Global()->Resolve<FileSystem*>();
            UniquePtr<File> themeFile = fileSystem->GetFile("/res/Themes/Default.json");
            UniquePtr<std::iostream> themeFileStream = themeFile->Open();

            Json themeJson;
            *themeFileStream >> themeJson;
            Theme theme = themeJson;
            Theme::Apply(theme);
        }
    }

    Editor::Editor()
    {
        GDB_PROFILE_FUNCTION();
        const float fontScale = 1.25F;
        const float robotoFontSize = 16.0F;

        ImGui::GetIO().Fonts->AddFontFromFileTTF("Resources/Fonts/Roboto-Regular.ttf", robotoFontSize * fontScale);

        const float fontAwesomeFontSize = 13.0F;
        ImFontConfig config;
        config.MergeMode = true;
        config.GlyphMinAdvanceX = fontAwesomeFontSize * fontScale; // Use if you want to make the icon monospaced
        static const ImWchar icon_ranges[] = {ICON_MIN_FA, ICON_MAX_FA, 0};

        ImGui::GetIO().Fonts->AddFontFromFileTTF("Resources/Fonts/" FONT_ICON_FILE_NAME_FAR,
                                                 fontAwesomeFontSize * fontScale, &config, icon_ranges);
        ImGui::GetIO().Fonts->AddFontFromFileTTF("Resources/Fonts/" FONT_ICON_FILE_NAME_FAS,
                                                 fontAwesomeFontSize * fontScale, &config, icon_ranges);

        ImGui::GetStyle().WindowMenuButtonPosition = ImGuiDir_None;
    }

    const Editor::EditorWindowList& Editor::GetWindows() const
    {
        return _windows;
    }

    void Editor::ConsumeActions()
    {
        GDB_PROFILE_FUNCTION();
        for (size_t i = 0; i < _actions.size(); ++i)
        {
            _actions[i]();
        }

        _actions.clear();
    }

    void Editor::UpdateWindows()
    {
        GDB_PROFILE_FUNCTION();

        Vector<size_t> idxToRemove;
        for (size_t i = 0; i < _windows.size(); ++i)
        {
            if (_windows[i]->GetState() == EditorWindow::State::Disabled)
            {
                idxToRemove.push_back(i);
                continue;
            }

            _windows[i]->Update();
        }

        // TODO: Optimize this if needed... Can just swap elements to the back since order ain't required.
        for (const size_t i : idxToRemove)
        {
            _windows.erase(_windows.begin() + static_cast<EditorWindowList::difference_type>(i));
        }
    }

    void Editor::RenderWindows() const
    {
        GDB_PROFILE_FUNCTION();
        if (reloadThemeNeeded)
        {
            ReloadTheme();
            reloadThemeNeeded = false;
        }

        ImGui::ShowDemoWindow();
        ImGui::BeginMainMenuBar();
        ImGui::MenuItem("File");
        ImGui::MenuItem("Project");
        ImGui::MenuItem("Window");
        ImGui::MenuItem("Help");
        if (ImGui::MenuItem("Reload Theme"))
        {
            reloadThemeNeeded = true;
        }
        ImGui::EndMainMenuBar();

        ImGui::DockSpaceOverViewport();

        const size_t windowsSize = _windows.size();
        for (size_t i = 0; i < windowsSize; ++i)
        {
            _windows[i]->Render();
        }
    }

    void Editor::AddWindow(UniquePtr<EditorWindow> window)
    {
        GDB_PROFILE_FUNCTION();
        _windows.push_back(std::move(window));
    }

    void Editor::PushAction(ActionCallback actionCallback)
    {
        GDB_PROFILE_FUNCTION();
        _actions.push_back(std::move(actionCallback));
    }
}
