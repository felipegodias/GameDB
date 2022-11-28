#include "GameDB/DataEditor/EditDataColumnEditorWindow.hpp"

#include "GameDB/libEditor.hpp"
#include "GameDB/libProfiler.hpp"
#include "GameDB/libFormat.hpp"

namespace GDB
{
    namespace
    {
        EditDataColumnEditorWindow* CreateEditDataColumnEditorWindowFactory(
            const DIContainer& di, const EditDataColumnEditorWindow::ResolveData& data)
        {
            auto* editor = di.Resolve<Editor*>();
            SharedPtr<EditDataColumnEditorWindow> window = editor->GetWindow<EditDataColumnEditorWindow>();
            if (window != nullptr)
            {
                return window.get();
            }

            window = editor->AddWindow<EditDataColumnEditorWindow>(data.dataColumn);
            return window.get();
        }
    }

    EditDataColumnEditorWindow::EditDataColumnEditorWindow(const SharedPtr<DataColumn>& dataColumn)
        : EditorWindow(ICON_FA_PEN_TO_SQUARE " Edit Column", Type::Modal),
          _dataColumn(dataColumn)
    {
        GDB_PROFILE_FUNCTION();
    }

    void EditDataColumnEditorWindow::OnAwake()
    {
        GDB_PROFILE_FUNCTION();
    }

    void EditDataColumnEditorWindow::OnUpdate()
    {
        GDB_PROFILE_FUNCTION();
    }

    void EditDataColumnEditorWindow::OnGUI()
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
        if (ImGui::Button("Save", ImVec2(-1, 0)))
        {
            const SharedPtr<DataColumn> dataColumn = _dataColumn.lock();
            dataColumn->SetName(_columnName);
            Destroy();
        }
        ImGui::EndDisabled();
    }

    bool EditDataColumnEditorWindow::IsInputValid() const
    {
        GDB_PROFILE_FUNCTION();

        if (_columnName.empty())
        {
            return false;
        }

        const SharedPtr<DataColumn> dataColumn = _dataColumn.lock();
        for (const auto& column : dataColumn->GetDataTable()->GetColumns())
        {
            if (column->GetName() == _columnName && column != dataColumn)
            {
                return false;
            }
        }

        return true;
    }

    EditDataColumnEditorWindow::DIInstaller::DIInstaller(DIContainer* diContainer)
    {
        diContainer->RegisterFactory<EditDataColumnEditorWindow*, ResolveData>(CreateEditDataColumnEditorWindowFactory);
    }
}
