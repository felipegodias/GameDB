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
        const float fontScale = 1.25F;
        const float robotoFontSize = 16.0F;

        ImGui::GetIO().Fonts->AddFontFromFileTTF("Resources/Fonts/Roboto-Regular.ttf", robotoFontSize * fontScale);

        const float fontAwesomeFontSize = 13.0F;
        ImFontConfig config;
        config.MergeMode = true;
        config.GlyphMinAdvanceX = fontAwesomeFontSize * fontScale; // Use if you want to make the icon monospaced
        static const ImWchar icon_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };

        ImGui::GetIO().Fonts->AddFontFromFileTTF("Resources/Fonts/" FONT_ICON_FILE_NAME_FAR, fontAwesomeFontSize * fontScale, &config, icon_ranges);
        ImGui::GetIO().Fonts->AddFontFromFileTTF("Resources/Fonts/" FONT_ICON_FILE_NAME_FAS, fontAwesomeFontSize * fontScale, &config, icon_ranges);
    }

    void Editor::AwakeWindows()
    {
        GDB_PROFILE_FUNCTION();
        // Using raw for loop because the awake of one window
        // can instantiate multiple other windows.
        for (size_t i = 0; i < _toAwakeWindows.size(); ++i) // NOLINT(modernize-loop-convert)
        {
            _toAwakeWindows[i]->Awake();
            _activeWindows.push_back(_toAwakeWindows[i]);
        }
        _toAwakeWindows.clear();
    }

    void Editor::UpdateWindows() const
    {
        if (reloadThemeNeeded)
        {
            ReloadTheme();
            reloadThemeNeeded = false;
        }

        GDB_PROFILE_FUNCTION();
        for (const auto& window : _activeWindows)
        {
            window->Update();
        }
    }

    void Editor::RenderWindows() const
    {
        GDB_PROFILE_FUNCTION();
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
        for (const auto& window : _activeWindows)
        {
            window->Render();
        }
    }

    void Editor::DestroyWindows()
    {
        GDB_PROFILE_FUNCTION();
        const auto removeIt
            = std::remove_if(_activeWindows.begin(),
                             _activeWindows.end(),
                             [](const SharedPtr<EditorWindow>& window)
                             {
                                 return window->GetState() == EditorWindow::State::WaitingForDestroy;
                             });
        _activeWindows.erase(removeIt, _activeWindows.end());
    }

    WeakPtr<EditorWindow> Editor::AddWindow(SharedPtr<EditorWindow> window)
    {
        _toAwakeWindows.push_back(std::move(window));
        return _toAwakeWindows[_toAwakeWindows.size() - 1];
    }
}
