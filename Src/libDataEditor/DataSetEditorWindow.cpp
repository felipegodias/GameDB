#include "GameDB/DataEditor/DataSetEditorWindow.hpp"

#include <imgui.h>
#include <imgui_stdlib.h>

#include "GameDB/libDebug.hpp"
#include "GameDB/libProfiler.hpp"
#include "GameDB/DataEditor/DataTableEditorWindow.hpp"
#include "GameDB/DI/DIContainer.hpp"
#include "GameDB/Editor/Editor.hpp"

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
        GDB_PROFILE_FUNCTION();
    }

    void DataSetEditorWindow::OnUpdate()
    {
        GDB_PROFILE_FUNCTION();
    }

    void DataSetEditorWindow::OnGUI()
    {
        GDB_PROFILE_FUNCTION();
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
