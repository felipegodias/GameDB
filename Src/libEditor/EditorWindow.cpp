#include "GameDB/Editor/EditorWindow.hpp"

#include <imgui.h>

#include "GameDB/libDebug.hpp"
#include "GameDB/libProfiler.hpp"
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

    EditorWindow::EditorWindow(String name, const Type type)
        : _instanceId(NextInstanceId()),
          _name(std::move(name)),
          _type(type),
          _state(State::WaitingForAwake),
          _editorMenu(MakeUnique<EditorMenu>())
    {
    }

    EditorWindow::~EditorWindow() = default;

    int EditorWindow::GetInstanceId() const
    {
        return _instanceId;
    }

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
        bool render = false;
        if (_type == Type::Regular)
        {
            render = ImGui::Begin(_name.c_str(), &open, windowFlags);
        }
        else if (_type == Type::Modal)
        {
            render = ImGui::BeginPopupModal(_name.c_str(), &open, windowFlags);
        }

        if (render)
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

        if (_type == Type::Regular)
        {
            ImGui::End();
        }
        else if (_type == Type::Modal)
        {
            if (render)
            {
                ImGui::EndPopup();
            }

            if (!ImGui::IsPopupOpen(_name.c_str()) && open)
            {
                ImGui::OpenPopup(_name.c_str());
            }
        }

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
