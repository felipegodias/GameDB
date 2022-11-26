#include "GameDB/DataEditor/CreateDataTableEditorWindow.hpp"

#include <imgui.h>
#include <imgui_stdlib.h>

#include "GameDB/libDI.hpp"
#include "GameDB/libProfiler.hpp"
#include "GameDB/Container/UnorderedSet.hpp"
#include "GameDB/Data/DataTypeString.hpp"
#include "GameDB/Editor/Editor.hpp"
#include "GameDB/Editor/FontAwesomeIcons.hpp"
#include "GameDB/Format/Format.hpp"

namespace GDB
{
    namespace
    {
        CreateDataTableEditorWindow* CreateDataTableEditorWindowFactory(
            const DIContainer& di, const CreateDataTableEditorWindow::ResolveData& data)
        {
            auto* editor = di.Resolve<Editor*>();
            SharedPtr<CreateDataTableEditorWindow> window = editor->GetWindow<CreateDataTableEditorWindow>();
            if (window != nullptr)
            {
                return window.get();
            }

            window = editor->AddWindow<CreateDataTableEditorWindow>(data.dataSet);
            return window.get();
        }
    }

    CreateDataTableEditorWindow::CreateDataTableEditorWindow(const SharedPtr<DataSet>& dataSet)
        : EditorWindow(ICON_FA_CIRCLE_PLUS " Create Table", Type::Modal),
          _dataSet(dataSet)
    {
        GDB_PROFILE_FUNCTION();
    }

    void CreateDataTableEditorWindow::OnAwake()
    {
        GDB_PROFILE_FUNCTION();
    }

    void CreateDataTableEditorWindow::OnUpdate()
    {
        GDB_PROFILE_FUNCTION();
    }

    void CreateDataTableEditorWindow::OnGUI()
    {
        GDB_PROFILE_FUNCTION();
        const String tableNameId = Format("{0}_{1}", GetInstanceId(), "TableName");
        auto tableName = std::string(_tableName);
        ImGui::PushID(tableNameId.c_str());
        ImGui::PushItemWidth(-FLT_MIN);
        ImGui::Text("Name:");
        ImGui::SameLine();
        ImGui::InputText("##v", &tableName);
        ImGui::PopID();
        _tableName = tableName;

        if (ImGui::BeginTable("ColumnsTable", 1))
        {
            ImGui::TableSetupColumn("Columns");
            ImGui::TableHeadersRow();

            for (size_t i = 0; i < _tableColumns.size(); ++i)
            {
                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                auto str = std::string(_tableColumns[i]);

                String id = Format("{0}_{1}", GetInstanceId(), i);

                ImGui::PushID(id.c_str());
                ImGui::PushItemWidth(-FLT_MIN);
                ImGui::InputText("##v", &str);
                ImGui::PopID();

                _tableColumns[i] = str;
            }

            ImGui::EndTable();
        }

        ImGui::Spacing();

        if (ImGui::Button("New Column", ImVec2(-1, 0)))
        {
            _tableColumns.push_back("");
        }

        ImGui::BeginDisabled(!IsInputValid());
        if (ImGui::Button("Create", ImVec2(-1, 0)))
        {
            const SharedPtr<DataSet> dataSet = _dataSet.lock();
            const SharedPtr<DataTable> dataTable = dataSet->AddDataTable(DataId::Random(), _tableName);
            for (const auto& column : _tableColumns)
            {
                dataTable->AddColumn(MakeUnique<DataColumn>(DataId::Random(), column, MakeUnique<DataTypeString>()));
            }
            Destroy();
        }
        ImGui::EndDisabled();
    }

    CreateDataTableEditorWindow::DIInstaller::DIInstaller(DIContainer* diContainer)
    {
        diContainer->RegisterFactory<CreateDataTableEditorWindow*, ResolveData>(CreateDataTableEditorWindowFactory);
    }

    bool CreateDataTableEditorWindow::IsInputValid() const
    {
        if (_tableName.empty())
        {
            return false;
        }

        const SharedPtr<DataSet> dataSet = _dataSet.lock();
        for (const auto& dataTable : dataSet->GetDataTables())
        {
            if (dataTable->GetName() == _tableName)
            {
                return false;
            }
        }

        if (_tableColumns.empty())
        {
            return false;
        }

        UnorderedSet<String> columns;
        for (const auto& tableColumn : _tableColumns)
        {
            if (tableColumn.empty())
            {
                return false;
            }

            if (columns.find(tableColumn) != columns.end())
            {
                return false;
            }

            columns.emplace(tableColumn);
        }

        return true;
    }
}
