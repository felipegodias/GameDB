#include "GameDB/Editor/EditorWindow.hpp"

#include <imgui.h>

#include "GameDB/libDebug.hpp"
#include "GameDB/libProfiler.hpp"
#include "GameDB/Editor/Editor.hpp"
#include "GameDB/Format/Format.hpp"

namespace GDB
{
    namespace
    {
        void DrawMenuItems(Editor* editor, const Map<String, UniquePtr<EditorMenuItem>>& items)
        {
            GDB_PROFILE_FUNCTION();
            for (const auto& [name, item] : items)
            {
                if (ImGui::MenuItem(name.c_str()))
                {
                    editor->PushAction(item->GetCallback());
                }
            }
        }

        void DrawMenuGroups(Editor* editor, const Map<String, UniquePtr<EditorMenuGroup>>& groups)
        {
            GDB_PROFILE_FUNCTION();
            for (const auto& [name, group] : groups)
            {
                if (ImGui::BeginMenu(name.c_str()))
                {
                    DrawMenuGroups(editor, group->GetGroups());
                    DrawMenuItems(editor, group->GetItems());
                    ImGui::EndMenu();
                }
            }
        }
    }

    EditorWindow::EditorWindow(Editor* editor, String name, const Type type)
        : _editor(editor),
          _name(std::move(name)),
          _type(type),
          _state(State::Disabled),
          _editorMenu(MakeUnique<EditorMenu>())
    {
        GDB_PROFILE_FUNCTION();
    }

    EditorWindow::~EditorWindow() = default;

    const String& EditorWindow::GetName() const
    {
        GDB_PROFILE_FUNCTION();
        return _name;
    }

    EditorWindow::State EditorWindow::GetState() const
    {
        GDB_PROFILE_FUNCTION();
        return _state;
    }

    EditorMenu* EditorWindow::GetEditorMenu() const
    {
        GDB_PROFILE_FUNCTION();
        return _editorMenu.get();
    }

    void EditorWindow::Update()
    {
        GDB_PROFILE_FUNCTION();

        switch (_state)
        {
        case State::WaitingForEnable:
            OnEnabled();
            _state = State::Enabled;
            break;
        case State::Enabled:
            OnUpdate();
            break;
        case State::WaitingForDisable:
            OnDisabled();
            _state = State::Disabled;
            break;
        case State::None:
        case State::Disabled:
            break;
        }
    }

    void EditorWindow::Render()
    {
        GDB_PROFILE_FUNCTION();
        if (_state != State::Enabled)
        {
            return;
        }

        OnPreRender();

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
                DrawMenuGroups(_editor, _editorMenu->GetGroups());
                DrawMenuItems(_editor, _editorMenu->GetItems());
                ImGui::EndMenuBar();
            }

            OnRender();
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

        OnPostRender();

        if (!open)
        {
            Hide();
        }
    }

    void EditorWindow::Show()
    {
        GDB_PROFILE_FUNCTION();

        if (_state != State::Enabled)
        {
            _state = State::WaitingForEnable;
        }
    }

    void EditorWindow::Hide()
    {
        GDB_PROFILE_FUNCTION();
        if (_state != State::Disabled)
        {
            _state = State::WaitingForDisable;
        }
    }

    void EditorWindow::OnEnabled()
    {
        GDB_PROFILE_FUNCTION();
    }

    void EditorWindow::OnDisabled()
    {
        GDB_PROFILE_FUNCTION();
    }

    void EditorWindow::OnUpdate()
    {
        GDB_PROFILE_FUNCTION();
    }

    void EditorWindow::OnPreRender()
    {
        GDB_PROFILE_FUNCTION();
    }

    void EditorWindow::OnRender()
    {
        GDB_PROFILE_FUNCTION();
    }

    void EditorWindow::OnPostRender()
    {
        GDB_PROFILE_FUNCTION();
    }
}
