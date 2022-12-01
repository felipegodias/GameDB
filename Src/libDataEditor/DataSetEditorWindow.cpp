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
            auto* window = editor->GetWindow<DataSetEditorWindow>();
            if (window != nullptr)
            {
                return window;
            }

            auto dataSet = diContainer.Resolve<SharedPtr<DataSet>>();
            window = editor->AddWindow<DataSetEditorWindow>(dataSet);
            return window;
        }
    }

    DataSetEditorWindow::DataSetEditorWindow(Editor* editor, const SharedPtr<DataSet>& dataSet)
        : EditorWindow(editor, ICON_FA_DATABASE " DataSet"),
          _dataSet(dataSet)
    {
        GDB_PROFILE_FUNCTION();
        GetEditorMenu()->AddItem(ICON_FA_CIRCLE_PLUS " New Table", [this]
        {
            auto* window = Resolve<CreateDataTableEditorWindow*, CreateDataTableEditorWindow::ResolveData>({
                _dataSet.lock()
            });
            window->Show();
        });
    }

    void DataSetEditorWindow::OnEnabled()
    {
        GDB_PROFILE_FUNCTION();
    }

    void DataSetEditorWindow::OnDisabled()
    {
        GDB_PROFILE_FUNCTION();
    }

    void DataSetEditorWindow::OnUpdate()
    {
        GDB_PROFILE_FUNCTION();
    }

    void DataSetEditorWindow::OnRender()
    {
        GDB_PROFILE_FUNCTION();
        const SharedPtr<DataSet> dataSet = _dataSet.lock();
        for (const auto& table : dataSet->GetDataTables())
        {
            if (ImGui::Button(table->GetName().c_str(), ImVec2(-1, 0)))
            {
                auto* dataTableEditorWindow = Resolve<DataTableEditorWindow*, DataTableEditorWindow::ResolveData>({
                    table
                });
                dataTableEditorWindow->Show();
            }
        }
    }

    DataSetEditorWindow::DIInstaller::DIInstaller(DIContainer* diContainer)
    {
        diContainer->RegisterFactory<DataSetEditorWindow*>(DataSetEditorWindowFactory);
    }
}
