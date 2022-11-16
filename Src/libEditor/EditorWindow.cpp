#include "GameDB/Editor/EditorWindow.hpp"

#include <imgui.h>

namespace GDB
{
    namespace
    {
        void DrawMenuItems(const Map<String, UniquePtr<EditorMenuItem>>& items)
        {
            for (const auto& [name, item] : items)
            {
                if (ImGui::MenuItem(name.c_str()))
                {
                    item->InvokeCallback();
                }
            }
        }

        void DrawMenuGroups(const Map<String, UniquePtr<EditorMenuGroup>>& groups)
        {
            for (const auto& [name, group]:groups)
            {
                if (ImGui::BeginMenu(name.c_str()))
                {
                    DrawMenuGroups(group->GetGroups());
                    DrawMenuItems(group->GetItems());
                    ImGui::EndMenu();
                }
            }
        }
    }

    EditorWindow::EditorWindow(String name, const bool isActive)
        : _name(std::move(name)),
          _isActive(isActive),
          _isAwaken(false),
          _editorMenu(MakeUnique<EditorMenu>())
    {
    }

    EditorWindow::~EditorWindow() = default;

    const String& EditorWindow::GetName() const
    {
        return _name;
    }

    bool EditorWindow::IsActive() const
    {
        return _isActive;
    }

    void EditorWindow::SetActive(const bool active)
    {
        _isActive = active;
    }

    bool EditorWindow::IsAwaken() const
    {
        return _isAwaken;
    }

    EditorMenu* EditorWindow::GetEditorMenu() const
    {
        return _editorMenu.get();
    }

    void EditorWindow::Awake()
    {
        if (_isAwaken)
        {
            return;
        }

        _isAwaken = true;
        OnAwake();
    }

    void EditorWindow::Update()
    {
        if (!_isActive || !_isAwaken)
        {
            return;
        }

        OnUpdate();
    }

    void EditorWindow::Render()
    {
        if (!_isActive || !_isAwaken)
        {
            return;
        }

        ImGuiWindowFlags windowFlags = ImGuiWindowFlags_None;
        const bool showMenu = !_editorMenu->GetItems().empty() || !_editorMenu->GetGroups().empty();
        if (showMenu)
        {
            windowFlags |= ImGuiWindowFlags_MenuBar;
        }

        bool b;
        if (ImGui::Begin(_name.c_str(), &b, windowFlags))
        {
            if (showMenu)
            {
                ImGui::BeginMenuBar();
                DrawMenuGroups(_editorMenu->GetGroups());
                DrawMenuItems(_editorMenu->GetItems());
                ImGui::EndMenuBar();
            }

            OnGUI();
        }
        ImGui::End();
    }

    void EditorWindow::OnAwake()
    {
    }

    void EditorWindow::OnUpdate()
    {
    }

    void EditorWindow::OnGUI()
    {
    }
}
