#include "GameDB/Editor/Editor.hpp"

#include <algorithm>
#include <imgui.h>

#include "GameDB/DI/DIContainer.hpp"
#include "GameDB/FileSystem/FileSystem.hpp"

namespace GDB
{
    Editor::Editor()
    {
        const float fontSize = 16.0F;
        const float fontScale = 1.25F;

        auto* fileSystem = DIContainer::Global()->Resolve<FileSystem*>();
        auto file = fileSystem->GetFile("/res/Themes/Default.json");

        ImGui::GetIO().Fonts->AddFontFromFileTTF("Resources/Fonts/Roboto-Regular.ttf", fontSize * fontScale);
    }

    void Editor::AwakeWindows()
    {
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
        for (const auto& window : _activeWindows)
        {
            window->Update();
        }
    }

    void Editor::RenderWindows() const
    {
        ImGui::ShowDemoWindow();
        ImGui::BeginMainMenuBar();
        ImGui::MenuItem("File");
        ImGui::MenuItem("Project");
        ImGui::MenuItem("Window");
        ImGui::MenuItem("Help");
        ImGui::EndMainMenuBar();

        ImGui::DockSpaceOverViewport();
        for (const auto& window : _activeWindows)
        {
            window->Render();
        }
    }

    void Editor::DestroyWindows()
    {
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
