#include "GameDB/DataEditor/DataSetEditorWindow.hpp"

#include <imgui.h>
#include <imgui_stdlib.h>

#include "GameDB/libDebug.hpp"
#include "GameDB/libProfiler.hpp"
#include "GameDB/DataEditor/CreateDataTableEditorWindow.hpp"
#include "GameDB/DataEditor/DataTableEditorWindow.hpp"
#include "GameDB/Editor/Editor.hpp"
#include "GameDB/Editor/FontAwesomeIcons.hpp"

namespace GDB
{
    DataSetEditorWindow::DataSetEditorWindow(const SharedPtr<DataSet>& dataSet)
        : EditorWindow(ICON_FA_DATABASE " DataSet"),
          _dataSet(dataSet)
    {
        GetEditorMenu()->AddItem(ICON_FA_CIRCLE_PLUS " New Table", [this]
        {
            Editor::CreateWindow<CreateDataTableEditorWindow>(_dataSet.lock());
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
        const SharedPtr<DataSet> dataSet = _dataSet.lock();
        for (const auto& table : dataSet->GetDataTables())
        {
            if (ImGui::Button(table->GetName().c_str(), ImVec2(-1, 0)))
            {
                editor->AddWindow<DataTableEditorWindow>(table.get());
            }
        }
    }
}
