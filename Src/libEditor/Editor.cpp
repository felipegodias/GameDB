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

        void IndexedForEach(const Editor::EditorWindowList& windows,
                            const std::function<void(EditorWindow*)>& callback)
        {
            GDB_PROFILE_FUNCTION();
            // Not using a foreach here because the callback can change the state of the container.
            for (size_t i = 0; i < windows.size(); ++i) // NOLINT
            {
                callback(windows[i].get());
            }
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

    void Editor::AwakeWindows() const
    {
        GDB_PROFILE_FUNCTION();
        IndexedForEach(_windows, [](EditorWindow* window)
        {
            if (window->GetState() == EditorWindow::State::WaitingForAwake)
            {
                window->Awake();
            }
        });
    }

    void Editor::UpdateWindows() const
    {
        GDB_PROFILE_FUNCTION();
        if (reloadThemeNeeded)
        {
            ReloadTheme();
            reloadThemeNeeded = false;
        }


        IndexedForEach(_windows, [](EditorWindow* window)
        {
            if (window->GetState() == EditorWindow::State::Active)
            {
                window->Update();
            }
        });
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

        IndexedForEach(_windows, [](EditorWindow* window)
        {
            if (window->GetState() == EditorWindow::State::Active)
            {
                window->Render();
            }
        });
    }

    void Editor::DestroyWindows()
    {
        GDB_PROFILE_FUNCTION();
        const auto removeIt
            = std::remove_if(_windows.begin(),
                             _windows.end(),
                             [](const SharedPtr<EditorWindow>& window)
                             {
                                 return window->GetState() == EditorWindow::State::WaitingForDestroy;
                             });
        _windows.erase(removeIt, _windows.end());
    }

    void Editor::AddWindow(SharedPtr<EditorWindow> window)
    {
        GDB_PROFILE_FUNCTION();
        _windows.push_back(std::move(window));
    }
}
