#include "GameDB/DataEditor/DataTableEditorWindow.hpp"

#include <imgui.h>
#include <imgui_stdlib.h>

#include "GameDB/libData.hpp"
#include "GameDB/libDebug.hpp"
#include "GameDB/libProfiler.hpp"
#include "GameDB/Editor/Editor.hpp"
#include "GameDB/Editor/FontAwesomeIcons.hpp"

namespace GDB
{
    namespace
    {
        DataTableEditorWindow* DataTableEditorWindowFactory(const DIContainer& di,
                                                            const DataTableEditorWindow::ResolveData& resolveData)
        {
            SharedPtr<DataTableEditorWindow> window = nullptr;
            auto* editor = di.Resolve<Editor*>();
            editor->ForEachWindow<DataTableEditorWindow>([&](const SharedPtr<DataTableEditorWindow>& it)
            {
                if (it->GetDataTable().lock() == resolveData.dataTable)
                {
                    window = it;
                    return false;
                }

                return true;
            });

            if (window != nullptr)
            {
                return window.get();
            }

            window = editor->AddWindow<DataTableEditorWindow>(resolveData.dataTable);
            return window.get();
        }
    }

    DataTableEditorWindow::DataTableEditorWindow(const SharedPtr<DataTable>& dataTable)
        : EditorWindow(ICON_FA_TABLE " " + dataTable->GetName()),
          _dataTable(dataTable)
    {
        GDB_PROFILE_FUNCTION();
        GetEditorMenu()->AddItem(ICON_FA_CIRCLE_PLUS " New Row", [this]
        {
            _dataTable.lock()->AddRow();
        });

        GetEditorMenu()->AddItem(ICON_FA_TRASH " Delete Table", [this]
        {
            const SharedPtr<DataTable> dataTable = _dataTable.lock();
            dataTable->GetDataSet()->RemoveDataTable(*dataTable);
        });
    }

    WeakPtr<DataTable> DataTableEditorWindow::GetDataTable() const
    {
        return _dataTable;
    }

    void DataTableEditorWindow::OnAwake()
    {
        GDB_PROFILE_FUNCTION();
    }

    void DataTableEditorWindow::OnUpdate()
    {
        GDB_PROFILE_FUNCTION();
        if (_dataTable.expired())
        {
            Destroy();
        }
    }

    void DataTableEditorWindow::OnGUI()
    {
        GDB_PROFILE_FUNCTION();
        if (_dataTable.expired())
        {
            return;
        }

        const SharedPtr<DataTable> dataTable = _dataTable.lock();
        const int tableColumns = static_cast<int>(dataTable->GetColumns().size());
        if (tableColumns == 0)
        {
            return;
        }

        constexpr ImGuiTableFlags flags = ImGuiTableFlags_ScrollY | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg |
            ImGuiTableFlags_Resizable;
        ImGui::BeginTable("Table", tableColumns, flags);
        ImGui::TableSetupScrollFreeze(1, 1);
        for (const auto& column : dataTable->GetColumns())
        {
            ImGui::TableSetupColumn(column->GetName().c_str());
        }
        ImGui::TableHeadersRow();

        for (const auto& row : dataTable->GetRows())
        {
            ImGui::TableNextRow();
            for (const auto& column : dataTable->GetColumns())
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

    DataTableEditorWindow::DIInstaller::DIInstaller(DIContainer* diContainer)
    {
        diContainer->RegisterFactory<DataTableEditorWindow*, ResolveData>(DataTableEditorWindowFactory);
    }
}
