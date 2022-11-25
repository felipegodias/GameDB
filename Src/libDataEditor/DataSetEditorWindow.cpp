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
    namespace
    {
        DataSetEditorWindow* DataSetEditorWindowFactory(const DIContainer& diContainer)
        {
            auto* editor = diContainer.Resolve<Editor*>();
            SharedPtr<DataSetEditorWindow> window = editor->GetWindow<DataSetEditorWindow>();
            if (window != nullptr)
            {
                return window.get();
            }

            auto dataSet = diContainer.Resolve<SharedPtr<DataSet>>();
            window = editor->AddWindow<DataSetEditorWindow>(dataSet);
            return window.get();
        }
    }

    DataSetEditorWindow::DataSetEditorWindow(const SharedPtr<DataSet>& dataSet)
        : EditorWindow(ICON_FA_DATABASE " DataSet"),
          _dataSet(dataSet)
    {
        GDB_PROFILE_FUNCTION();
        GetEditorMenu()->AddItem(ICON_FA_CIRCLE_PLUS " New Table", [this]
        {
            [[maybe_unused]] auto* window = DIContainer::Global()->Resolve<
                CreateDataTableEditorWindow*, CreateDataTableEditorWindow::ResolveData>({_dataSet.lock()});
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
        const SharedPtr<DataSet> dataSet = _dataSet.lock();
        for (const auto& table : dataSet->GetDataTables())
        {
            if (ImGui::Button(table->GetName().c_str(), ImVec2(-1, 0)))
            {
                [[maybe_unused]] auto* dataTableEditorWindow = Resolve<
                    DataTableEditorWindow*, DataTableEditorWindow::ResolveData>({table});
            }
        }
    }

    DataSetEditorWindow::DIInstaller::DIInstaller(DIContainer* diContainer)
    {
        diContainer->RegisterFactory<DataSetEditorWindow*>(DataSetEditorWindowFactory);
    }
}
