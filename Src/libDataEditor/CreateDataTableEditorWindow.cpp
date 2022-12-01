#include "GameDB/DataEditor/CreateDataTableEditorWindow.hpp"

#include <imgui.h>

#include "GameDB/libDI.hpp"
#include "GameDB/libProfiler.hpp"
#include "GameDB/Container/Set.hpp"
#include "GameDB/Data/DataTypeString.hpp"
#include "GameDB/Editor/Editor.hpp"
#include "GameDB/Editor/EditorWidgets.hpp"
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
            auto* window = editor->GetWindow<CreateDataTableEditorWindow>();
            if (window != nullptr)
            {
                return window;
            }

            window = editor->AddWindow<CreateDataTableEditorWindow>(data.dataSet);
            return window;
        }
    }

    CreateDataTableEditorWindow::CreateDataTableEditorWindow(Editor* editor, const SharedPtr<DataSet>& dataSet)
        : EditorWindow(editor, ICON_FA_CIRCLE_PLUS " Create Table", Type::Modal),
          _dataSet(dataSet)
    {
        GDB_PROFILE_FUNCTION();
    }

    void CreateDataTableEditorWindow::OnEnabled()
    {
        GDB_PROFILE_FUNCTION();
    }

    void CreateDataTableEditorWindow::OnDisabled()
    {
        GDB_PROFILE_FUNCTION();
    }

    void CreateDataTableEditorWindow::OnUpdate()
    {
        GDB_PROFILE_FUNCTION();
    }

    void CreateDataTableEditorWindow::OnRender()
    {
        GDB_PROFILE_FUNCTION();

        ImGui::SetWindowSize(ImVec2(300, 0));

        InputTextWithLabelOnLeft("Table Name:", &_tableName);

        ImGui::BeginDisabled(!IsInputValid());
        if (ImGui::Button("Create", ImVec2(-1, 0)))
        {
            const SharedPtr<DataSet> dataSet = _dataSet.lock();
            const SharedPtr<DataTable> dataTable = dataSet->AddDataTable(DataId::Random(), _tableName);
            dataTable->AddColumn(
                MakeUnique<DataColumn>(DataId::Random(), "Id", dataTable.get(), MakeUnique<DataTypeString>()));
            Hide();
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

        return true;
    }
}
