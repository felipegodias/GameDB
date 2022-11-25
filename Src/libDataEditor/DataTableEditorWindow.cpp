#include "GameDB/DataEditor/DataTableEditorWindow.hpp"

#include <imgui.h>
#include <imgui_stdlib.h>

#include "GameDB/libData.hpp"
#include "GameDB/libDebug.hpp"
#include "GameDB/libProfiler.hpp"
#include "GameDB/Editor/FontAwesomeIcons.hpp"

namespace GDB
{
    DataTableEditorWindow::DataTableEditorWindow(DataTable* dataTable)
        : EditorWindow(ICON_FA_TABLE " " + dataTable->GetName()),
          _dataTable(dataTable)
    {
        GetEditorMenu()->AddItem(ICON_FA_CIRCLE_PLUS " New Row", [dataTable]
        {
            dataTable->AddRow();
        });
    }

    void DataTableEditorWindow::OnAwake()
    {
        GDB_PROFILE_FUNCTION();
    }

    void DataTableEditorWindow::OnUpdate()
    {
        GDB_PROFILE_FUNCTION();
    }

    void DataTableEditorWindow::OnGUI()
    {
        GDB_PROFILE_FUNCTION();
        const int tableColumns = static_cast<int>(_dataTable->GetColumns().size());
        if (tableColumns == 0)
        {
            return;
        }

        const ImGuiTableFlags flags = ImGuiTableFlags_ScrollY | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable;
        ImGui::BeginTable("Table", tableColumns, flags);
        ImGui::TableSetupScrollFreeze(1, 1);
        for (const auto& column : _dataTable->GetColumns())
        {
            ImGui::TableSetupColumn(column->GetName().c_str());
        }
        ImGui::TableHeadersRow();

        for (const auto& row : _dataTable->GetRows())
        {
            ImGui::TableNextRow();
            for (const auto& column : _dataTable->GetColumns())
            {
                ImGui::TableNextColumn();
                std::optional<DataValue*> value = row->GetValue(*column);
                auto* const stringValue = dynamic_cast<DataValueString*>(value.value());
                auto str = std::string(stringValue->GetValue());

                ImGui::PushID(stringValue->GetDataId().GetValue());
                ImGui::PushItemWidth(-FLT_MIN);
                ImGui::InputText("##v", &str);
                ImGui::PopID();
                stringValue->SetValue(String(str));
            }
        }

        ImGui::EndTable();
    }
}
