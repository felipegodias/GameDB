#ifndef GDB_LIB_DATA_EDITOR_DATA_TABLE_EDITOR_WINDOW_HPP
#define GDB_LIB_DATA_EDITOR_DATA_TABLE_EDITOR_WINDOW_HPP

#include "GameDB/Data/DataTable.hpp"
#include "GameDB/DI/DIContainer.hpp"
#include "GameDB/Editor/EditorWindow.hpp"

namespace GDB
{
    class DataTableEditorWindow final : public EditorWindow
    {
    public:
        /**
         * \brief 
         */
        struct ResolveData
        {
            SharedPtr<DataTable> dataTable;
        };

        explicit DataTableEditorWindow(const SharedPtr<DataTable>& dataTable);

        /**
         * \brief 
         * \return 
         */
        WeakPtr<DataTable> GetDataTable() const;

    protected:
        void OnAwake() override;
        void OnUpdate() override;
        void OnGUI() override;

    private:
        WeakPtr<DataTable> _dataTable;

        GDB_DI_INSTALLER();
    };
}

#endif // !GDB_LIB_DATA_EDITOR_DATA_TABLE_EDITOR_WINDOW_HPP
