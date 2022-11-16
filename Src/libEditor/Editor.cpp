#include "GameDB/Editor/Editor.hpp"

#include "imgui.h"

namespace GDB
{
    void Editor::MainLoop() const
    {
        ImGui::ShowDemoWindow();
        AwakeWindows();
        UpdateWindows();
        RenderWindows();
    }

    void Editor::AwakeWindows() const
    {
        for (const auto& window : _windows)
        {
            if (!window->IsAwaken())
            {
                window->Awake();
            }
        }
    }

    void Editor::UpdateWindows() const
    {
        for (const auto& window : _windows)
        {
            window->Update();
        }
    }

    void Editor::RenderWindows() const
    {
        for (const auto& window : _windows)
        {
            window->Render();
        }
    }

    EditorWindow* Editor::AddWindow(UniquePtr<EditorWindow> window)
    {
        _windows.push_back(std::move(window));
        return _windows[_windows.size() - 1].get();
    }
}
