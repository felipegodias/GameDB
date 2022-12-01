#ifndef GDB_LIB_DATA_EDITOR_CREATE_DATA_TABLE_EDITOR_WINDOW_HPP
#define GDB_LIB_DATA_EDITOR_CREATE_DATA_TABLE_EDITOR_WINDOW_HPP

#include "GameDB/Container/String.hpp"
#include "GameDB/Data/DataSet.hpp"
#include "GameDB/DI/DIContainer.hpp"
#include "GameDB/Editor/EditorWindow.hpp"
#include "GameDB/Memory/Pointers.hpp"

namespace GDB
{
    /**
     * \brief
     */
    class CreateDataTableEditorWindow final : public EditorWindow
    {
    public:
        /**
         * \brief
         */
        struct ResolveData
        {
            SharedPtr<DataSet> dataSet;
        };

        CreateDataTableEditorWindow(Editor* editor, const SharedPtr<DataSet>& dataSet);

    protected:
        void OnEnabled() override;
        void OnDisabled() override;
        void OnUpdate() override;
        void OnRender() override;

    private:
        WeakPtr<DataSet> _dataSet;
        String _tableName;

        [[nodiscard]] bool IsInputValid() const;

        GDB_DI_INSTALLER();
    };
}

#endif // !GDB_LIB_DATA_EDITOR_CREATE_DATA_TABLE_EDITOR_WINDOW_HPP