#include "GameDB/DebugEditor/ConsoleEditorWindow.hpp"

#include <imgui.h>
#include <regex>

#include "GameDB/libDebug.hpp"
#include "GameDB/libProfiler.hpp"
#include "GameDB/Editor/EditorWidgets.hpp"
#include "GameDB/Editor/FontAwesomeIcons.hpp"

namespace GDB
{
    ConsoleEditorWindow::ConsoleEditorWindow(Editor* editor, const Log* log)
        : EditorWindow(editor, ICON_FA_TERMINAL " Output Log")
    {
        for (const auto& [spool, logSpool] : log->GetSpools())
        {
            std::optional<WeakPtr<LoggerSinkConsole>> sink = logSpool->GetSink<LoggerSinkConsole>();
            if (!sink.has_value())
            {
                continue;
            }

            _sinks.push_back(sink.value());
        }

        GetEditorMenu()->AddItem("Clear", [this]
        {
            _sinks[0].lock()->Clear();
        });
    }

    void ConsoleEditorWindow::OnUpdate()
    {
        GDB_PROFILE_FUNCTION();
        if (_sinks[0].expired())
        {
            Hide();
        }
    }

    void ConsoleEditorWindow::OnPreRender()
    {
        GDB_PROFILE_FUNCTION();
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
    }

    void ConsoleEditorWindow::OnRenderMenuBar()
    {
        GDB_PROFILE_FUNCTION();
        ImGui::PushID("search");
        const ImVec2 cursor = ImGui::GetCursorPos();
        ImGui::SetCursorPos({ cursor.x, cursor.y + 4 });

        ImGui::SetNextItemWidth(150);
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(2, 2));
        InputText("##v", &_filter);
        ImGui::PopStyleVar();

        ImVec2 finalCursorPos = ImGui::GetCursorPos();
        finalCursorPos.y = cursor.y;

        ImGui::SetCursorPos(finalCursorPos);
        ImGui::PopID();
    }

    void ConsoleEditorWindow::OnRender()
    {
        GDB_PROFILE_FUNCTION();
        if (ImGui::BeginTable("Table", 1, ImGuiTableFlags_RowBg))
        {
            for (const auto& logEntry : _sinks[0].lock()->GetLogEntries())
            {
                if (!_filter.empty() && logEntry.formatterMessage.find(_filter) == -1)
                {
                    continue;
                }

                ImGui::TableNextRow();
                ImGui::TableNextColumn();

                const ImVec2 sz = ImGui::CalcTextSize(logEntry.formatterMessage.c_str());
                const ImVec2 cursor = ImGui::GetCursorPos();
                ImGui::InvisibleButton("##IB", ImVec2(sz.x + ImGui::GetStyle().ItemInnerSpacing.x * 2,
                                                      sz.y + ImGui::GetStyle().ItemInnerSpacing.y * 2));
                const ImVec2 finalCursorPos = ImGui::GetCursorPos();
                ImGui::SetCursorPos({
                    cursor.x + ImGui::GetStyle().ItemInnerSpacing.x, cursor.y + ImGui::GetStyle().ItemInnerSpacing.y
                });

                ImGui::Text("%s", logEntry.formatterMessage.c_str());
                ImGui::SetCursorPos(finalCursorPos);
            }
            ImGui::EndTable();
        }
    }

    void ConsoleEditorWindow::OnPostRender()
    {
        GDB_PROFILE_FUNCTION();
        ImGui::PopStyleVar();
    }
}
