#include "GameDB/DataEditor/DataTableEditorWindow.hpp"

#include <imgui.h>

#include "GameDB/libData.hpp"
#include "GameDB/libDebug.hpp"
#include "GameDB/libProfiler.hpp"
#include "GameDB/DataEditor/CreateDataColumnEditorWindow.hpp"
#include "GameDB/DataEditor/DataEditorWidgets.hpp"
#include "GameDB/DataEditor/EditDataColumnEditorWindow.hpp"
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

        GetEditorMenu()->AddItem(ICON_FA_CIRCLE_PLUS " New Column", [this]
        {
            [[maybe_unused]] auto* window = Resolve<
                CreateDataColumnEditorWindow*, CreateDataColumnEditorWindow::ResolveData>({_dataTable.lock()});
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
                InputDataValue(value.value());
            }
        }

        SharedPtr<DataColumn> columnToDelete = nullptr;
        int hoveredColumn = -1;
        for (size_t i = 0; i < dataTable->GetColumns().size(); ++i)
        {
            const int column = static_cast<int>(i);
            const int id = column;

            ImGui::PushID(id);
            if (ImGui::TableGetColumnFlags(column) & ImGuiTableColumnFlags_IsHovered)
            {
                hoveredColumn = column;
            }

            constexpr std::string_view popupId = "ColumnPopup";
            if (hoveredColumn == column && ImGui::IsMouseReleased(1))
            {
                ImGui::OpenPopup(popupId.data());
            }

            ImGui::SetNextWindowSize(ImVec2(200, 0));
            if (ImGui::BeginPopup(popupId.data()))
            {
                ImGui::BeginDisabled(column == 0);
                if (ImGui::Button(ICON_FA_PEN_TO_SQUARE " Edit Column", ImVec2(-1, 0)))
                {
                    [[maybe_unused]] auto* window = Resolve<
                        EditDataColumnEditorWindow*, EditDataColumnEditorWindow::ResolveData>({
                        dataTable->GetColumns()[i]
                    });
                    ImGui::CloseCurrentPopup();
                }

                if (ImGui::Button(ICON_FA_TRASH " Delete Column", ImVec2(-1, 0)))
                {
                    columnToDelete = dataTable->GetColumns()[i];
                    ImGui::CloseCurrentPopup();
                }
                ImGui::EndDisabled();
                ImGui::EndPopup();
            }
            ImGui::PopID();
        }
        ImGui::EndTable();

        if (columnToDelete != nullptr)
        {
            dataTable->DeleteColumn(columnToDelete);
        }
    }

    DataTableEditorWindow::DIInstaller::DIInstaller(DIContainer* diContainer)
    {
        diContainer->RegisterFactory<DataTableEditorWindow*, ResolveData>(DataTableEditorWindowFactory);
    }
}
