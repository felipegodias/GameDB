#include "GameDB/DataEditor/DataSetEditorWindow.hpp"

#include <imgui.h>
#include <imgui_stdlib.h>

#include "GameDB/DI/DIContainer.hpp"
#include "GameDB/Editor/Editor.hpp"
#include "GameDB/DataEditor/DataTableEditorWindow.hpp"

namespace GDB
{
    DataSetEditorWindow::DataSetEditorWindow(DataSet* dataSet)
        : EditorWindow("DataSet"),
          _dataSet(dataSet)
    {
        GetEditorMenu()->AddItem("New Table", []
        {
            //dataSet->AddDataTable();
        });
    }

    void DataSetEditorWindow::OnAwake()
    {
    }

    void DataSetEditorWindow::OnUpdate()
    {
    }

    void DataSetEditorWindow::OnGUI()
    {
        auto* const editor = DIContainer::Global()->Resolve<Editor*>();
        for (const auto& table : _dataSet->GetDataTables())
        {
            if (ImGui::Button(table->GetName().c_str(), ImVec2(-1, 0)))
            {
                editor->AddWindow<DataTableEditorWindow>(table.get());
            }
        }
    }
}
