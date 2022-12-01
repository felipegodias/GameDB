#include "GameDB/DebugEditor/ConsoleEditorWindow.hpp"

#include <imgui.h>

#include "GameDB/libDebug.hpp"
#include "GameDB/libProfiler.hpp"
#include "GameDB/Editor/FontAwesomeIcons.hpp"

namespace GDB
{
    ConsoleEditorWindow::ConsoleEditorWindow(Editor* editor, const Log* log)
        : EditorWindow(editor, ICON_FA_TERMINAL " Console")
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

        GetEditorMenu()->AddItem("Clear", []
        {
        });
    }

    void ConsoleEditorWindow::OnEnabled()
    {
        GDB_PROFILE_FUNCTION();
    }

    void ConsoleEditorWindow::OnDisabled()
    {
        GDB_PROFILE_FUNCTION();
    }

    void ConsoleEditorWindow::OnUpdate()
    {
        GDB_PROFILE_FUNCTION();
    }

    void ConsoleEditorWindow::OnRender()
    {
        GDB_PROFILE_FUNCTION();
        if (ImGui::BeginTable("Console", 1))
        {
            for (const auto& logEntry : _sinks[0].lock()->GetLogEntries())
            {
                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                ImGui::Text("%s", logEntry.formatterMessage.c_str());
            }
            ImGui::EndTable();
        }
    }
}
