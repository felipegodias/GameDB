#include "GameDB/DebugEditor/ConsoleEditorWindow.hpp"

#include <imgui.h>

namespace GDB
{
    ConsoleEditorWindow::ConsoleEditorWindow(const Log* log)
        : EditorWindow("Console")
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

    void ConsoleEditorWindow::OnAwake()
    {
    }

    void ConsoleEditorWindow::OnUpdate()
    {
    }

    void ConsoleEditorWindow::OnGUI()
    {
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
