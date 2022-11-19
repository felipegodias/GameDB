#include "GameDB/DataEditor/DataTableEditorWindow.hpp"

#include <imgui.h>
#include <imgui_stdlib.h>

#include "GameDB/libData.hpp"

namespace GDB
{
    DataTableEditorWindow::DataTableEditorWindow(DataTable* dataTable)
        : EditorWindow(dataTable->GetName()),
          _dataTable(dataTable)
    {
        GetEditorMenu()->AddItem("New Row", [dataTable]
        {
            dataTable->AddRow();
        });

        GetEditorMenu()->AddItem("Edit Table", [dataTable]
        {
            dataTable->AddRow();
        });
    }

    void DataTableEditorWindow::OnAwake()
    {
    }

    void DataTableEditorWindow::OnUpdate()
    {
    }

    void DataTableEditorWindow::OnGUI()
    {
        const int tableColumns = static_cast<int>(_dataTable->GetColumns().size());
        if (tableColumns == 0)
        {
            return;
        }

        ImGui::BeginTable("Table", tableColumns);
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
                const auto stringValue = dynamic_cast<DataValueString*>(value.value());
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
