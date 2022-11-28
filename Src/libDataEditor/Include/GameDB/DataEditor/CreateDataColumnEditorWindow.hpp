#ifndef GDB_LIB_DATA_EDITOR_CREATE_DATA_COLUMN_EDITOR_WINDOW_HPP
#define GDB_LIB_DATA_EDITOR_CREATE_DATA_COLUMN_EDITOR_WINDOW_HPP

#include "GameDB/Container/String.hpp"
#include "GameDB/Data/DataTable.hpp"
#include "GameDB/DI/DIContainer.hpp"
#include "GameDB/Editor/EditorWindow.hpp"
#include "GameDB/Memory/Pointers.hpp"

namespace GDB
{
    /**
     * \brief
     */
    class CreateDataColumnEditorWindow final : public EditorWindow
    {
    public:
        /**
         * \brief
         */
        struct ResolveData
        {
            SharedPtr<DataTable> dataTable;
        };

        explicit CreateDataColumnEditorWindow(const SharedPtr<DataTable>& dataTable);

    protected:
        void OnAwake() override;
        void OnUpdate() override;
        void OnGUI() override;

    private:
        WeakPtr<DataTable> _dataTable;
        String _columnName;

        [[nodiscard]] bool IsInputValid() const;

        GDB_DI_INSTALLER();
    };
}

#endif // !GDB_LIB_DATA_EDITOR_CREATE_DATA_COLUMN_EDITOR_WINDOW_HPP
