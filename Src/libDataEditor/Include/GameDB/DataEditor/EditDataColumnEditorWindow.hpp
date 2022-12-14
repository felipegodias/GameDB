#ifndef GDB_LIB_DATA_EDITOR_EDIT_DATA_COLUMN_EDITOR_WINDOW_HPP
#define GDB_LIB_DATA_EDITOR_EDIT_DATA_COLUMN_EDITOR_WINDOW_HPP

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
    class EditDataColumnEditorWindow final : public EditorWindow
    {
    public:
        /**
         * \brief
         */
        struct ResolveData
        {
            SharedPtr<DataColumn> dataColumn;
        };

        EditDataColumnEditorWindow(Editor* editor, const SharedPtr<DataColumn>& dataColumn);

    protected:
        void OnEnabled() override;
        void OnDisabled() override;
        void OnUpdate() override;
        void OnRender() override;

    private:
        WeakPtr<DataColumn> _dataColumn;
        String _columnName;

        [[nodiscard]] bool IsInputValid() const;

        GDB_DI_INSTALLER();
    };
}

#endif // !GDB_LIB_DATA_EDITOR_EDIT_DATA_COLUMN_EDITOR_WINDOW_HPP
