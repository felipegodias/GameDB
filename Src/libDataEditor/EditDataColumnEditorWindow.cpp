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
            auto* window = editor->GetWindow<EditDataColumnEditorWindow>();
            if (window != nullptr)
            {
                return window;
            }

            window = editor->AddWindow<EditDataColumnEditorWindow>(data.dataColumn);
            return window;
        }
    }

    EditDataColumnEditorWindow::EditDataColumnEditorWindow(Editor* editor, const SharedPtr<DataColumn>& dataColumn)
        : EditorWindow(editor, ICON_FA_PEN_TO_SQUARE " Edit Column", Type::Modal),
          _dataColumn(dataColumn)
    {
        GDB_PROFILE_FUNCTION();
    }

    void EditDataColumnEditorWindow::OnEnabled()
    {
        GDB_PROFILE_FUNCTION();
    }

    void EditDataColumnEditorWindow::OnDisabled()
    {
        GDB_PROFILE_FUNCTION();
    }

    void EditDataColumnEditorWindow::OnUpdate()
    {
        GDB_PROFILE_FUNCTION();
    }

    void EditDataColumnEditorWindow::OnRender()
    {
        GDB_PROFILE_FUNCTION();

        ImGui::SetWindowSize(ImVec2(300, 0));

        InputTextWithLabelOnLeft("Column Name:", &_columnName);

        ImGui::BeginDisabled(!IsInputValid());
        if (ImGui::Button("Save", ImVec2(-1, 0)))
        {
            const SharedPtr<DataColumn> dataColumn = _dataColumn.lock();
            dataColumn->SetName(_columnName);
            Hide();
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
