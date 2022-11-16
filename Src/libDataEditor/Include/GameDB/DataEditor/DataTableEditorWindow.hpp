#ifndef GDB_LIB_DATA_EDITOR_DATA_TABLE_EDITOR_WINDOW_HPP
#define GDB_LIB_DATA_EDITOR_DATA_TABLE_EDITOR_WINDOW_HPP

#include "GameDB/Data/DataTable.hpp"
#include "GameDB/Editor/EditorWindow.hpp"

namespace GDB
{
    class DataTableEditorWindow final : public EditorWindow
    {
    public:
        DataTableEditorWindow(DataTable* dataTable, bool isActive);

    protected:
        void OnAwake() override;
        void OnUpdate() override;
        void OnGUI() override;

    private:
        DataTable* _dataTable;
    };
}

#endif // !GDB_LIB_DATA_EDITOR_DATA_TABLE_EDITOR_WINDOW_HPP
