#include "GameDB/DataEditor/CreateDataColumnEditorWindow.hpp"

#include <imgui.h>

#include "GameDB/libEditor.hpp"
#include "GameDB/libProfiler.hpp"
#include "GameDB/Data/DataTypeString.hpp"
#include "GameDB/Format/Format.hpp"

namespace GDB
{
    namespace
    {
        CreateDataColumnEditorWindow* CreateDataColumnEditorWindowFactory(
            const DIContainer& di, const CreateDataColumnEditorWindow::ResolveData& data)
        {
            auto* editor = di.Resolve<Editor*>();
            SharedPtr<CreateDataColumnEditorWindow> window = editor->GetWindow<CreateDataColumnEditorWindow>();
            if (window != nullptr)
            {
                return window.get();
            }

            window = editor->AddWindow<CreateDataColumnEditorWindow>(data.dataTable);
            return window.get();
        }
    }

    CreateDataColumnEditorWindow::CreateDataColumnEditorWindow(const SharedPtr<DataTable>& dataTable)
        : EditorWindow(ICON_FA_CIRCLE_PLUS " Create Column", Type::Modal),
          _dataTable(dataTable)
    {
        GDB_PROFILE_FUNCTION();
    }

    void CreateDataColumnEditorWindow::OnAwake()
    {
        GDB_PROFILE_FUNCTION();
    }

    void CreateDataColumnEditorWindow::OnUpdate()
    {
        GDB_PROFILE_FUNCTION();
    }

    void CreateDataColumnEditorWindow::OnGUI()
    {
        GDB_PROFILE_FUNCTION();

        const String columnNameId = Format("{0}_{1}", GetInstanceId(), "ColumnName");

        ImGui::PushID(columnNameId.c_str());
        ImGui::PushItemWidth(-FLT_MIN);
        ImGui::Text("Name:");
        ImGui::SameLine();
        InputText("###v", &_columnName);
        ImGui::PopID();

        ImGui::BeginDisabled(!IsInputValid());
        if (ImGui::Button("Create", ImVec2(-1, 0)))
        {
            const SharedPtr<DataTable> dataTable = _dataTable.lock();
            dataTable->AddColumn(MakeUnique<DataColumn>(DataId::Random(), _columnName, dataTable.get(),
                                                        MakeUnique<DataTypeString>()));
            Destroy();
        }
        ImGui::EndDisabled();
    }

    bool CreateDataColumnEditorWindow::IsInputValid() const
    {
        GDB_PROFILE_FUNCTION();

        if (_columnName.empty())
        {
            return false;
        }

        const SharedPtr<DataTable> dataTable = _dataTable.lock();
        for (const auto& column : dataTable->GetColumns())
        {
            if (column->GetName() == _columnName)
            {
                return false;
            }
        }

        return true;
    }

    CreateDataColumnEditorWindow::DIInstaller::DIInstaller(DIContainer* diContainer)
    {
        diContainer->RegisterFactory<CreateDataColumnEditorWindow*, ResolveData>(CreateDataColumnEditorWindowFactory);
    }
}
