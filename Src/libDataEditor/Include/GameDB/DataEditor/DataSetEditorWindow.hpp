#ifndef GDB_LIB_DATA_EDITOR_DATA_SET_EDITOR_WINDOW_HPP
#define GDB_LIB_DATA_EDITOR_DATA_SET_EDITOR_WINDOW_HPP

#include "GameDB/Data/DataSet.hpp"
#include "GameDB/DI/DIContainer.hpp"
#include "GameDB/Editor/EditorWindow.hpp"
#include "GameDB/Memory/Pointers.hpp"

namespace GDB
{
    class DataSetEditorWindow final : public EditorWindow
    {
    public:
        DataSetEditorWindow(Editor* editor, const SharedPtr<DataSet>& dataSet);

    protected:
        void OnEnabled() override;
        void OnDisabled() override;
        void OnUpdate() override;
        void OnRender() override;

    private:
        WeakPtr<DataSet> _dataSet;

        GDB_DI_INSTALLER();
    };
}

#endif // !GDB_LIB_DATA_EDITOR_DATA_SET_EDITOR_WINDOW_HPP
