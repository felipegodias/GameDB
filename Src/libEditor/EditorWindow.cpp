#include "GameDB/Editor/EditorWindow.hpp"

#include <imgui.h>

#include "GameDB/libDebug.hpp"
#include "GameDB/Format/Format.hpp"

namespace GDB
{
    namespace
    {
        void DrawMenuItems(const Map<String, UniquePtr<EditorMenuItem>>& items)
        {
            GDB_PROFILE_FUNCTION();
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
            GDB_PROFILE_FUNCTION();
            for (const auto& [name, group] : groups)
            {
                if (ImGui::BeginMenu(name.c_str()))
                {
                    DrawMenuGroups(group->GetGroups());
                    DrawMenuItems(group->GetItems());
                    ImGui::EndMenu();
                }
            }
        }

        int NextInstanceId()
        {
            static int instanceId = 0;
            return instanceId++;
        }
    }

    EditorWindow::EditorWindow(String name)
        : _instanceId(NextInstanceId()),
          _name(std::move(name)),
          _state(State::WaitingForAwake),
          _editorMenu(MakeUnique<EditorMenu>())
    {
    }

    EditorWindow::~EditorWindow() = default;

    const String& EditorWindow::GetName() const
    {
        return _name;
    }

    EditorWindow::State EditorWindow::GetState() const
    {
        return _state;
    }

    EditorMenu* EditorWindow::GetEditorMenu() const
    {
        return _editorMenu.get();
    }

    void EditorWindow::Awake()
    {
        GDB_PROFILE_FUNCTION();
        if (_state != State::WaitingForAwake)
        {
            return;
        }

        _state = State::Active;
        OnAwake();
    }

    void EditorWindow::Update()
    {
        GDB_PROFILE_FUNCTION();
        if (_state != State::Active)
        {
            return;
        }

        OnUpdate();
    }

    void EditorWindow::Render()
    {
        GDB_PROFILE_FUNCTION();
        if (_state != State::Active)
        {
            return;
        }

        ImGuiWindowFlags windowFlags = ImGuiWindowFlags_None;
        const bool showMenu = !_editorMenu->GetItems().empty() || !_editorMenu->GetGroups().empty();
        if (showMenu)
        {
            windowFlags |= ImGuiWindowFlags_MenuBar;
        }

        bool open = true;
        if (ImGui::Begin(Format("{0}###{1}", _name, _instanceId).c_str(), &open, windowFlags))
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

        if (!open)
        {
            Destroy();
        }
    }

    void EditorWindow::Destroy()
    {
        GDB_PROFILE_FUNCTION();
        _state = State::WaitingForDestroy;
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
