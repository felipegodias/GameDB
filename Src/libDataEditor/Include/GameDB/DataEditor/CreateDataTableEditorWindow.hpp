#ifndef GDB_LIB_DATA_EDITOR_CREATE_DATA_TABLE_EDITOR_WINDOW_HPP
#define GDB_LIB_DATA_EDITOR_CREATE_DATA_TABLE_EDITOR_WINDOW_HPP

#include "GameDB/Container/String.hpp"
#include "GameDB/Container/Vector.hpp"
#include "GameDB/Data/DataSet.hpp"
#include "GameDB/Editor/EditorWindow.hpp"
#include "GameDB/Memory/Pointers.hpp"
#include "GameDB/DI/DIContainer.hpp"

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

        explicit CreateDataTableEditorWindow(const SharedPtr<DataSet>& dataSet);

    protected:
        void OnAwake() override;
        void OnUpdate() override;
        void OnGUI() override;

    private:
        WeakPtr<DataSet> _dataSet;
        String _tableName;
        Vector<String> _tableColumns;

        GDB_DI_INSTALLER();
    };
}

#endif // !GDB_LIB_DATA_EDITOR_CREATE_DATA_TABLE_EDITOR_WINDOW_HPP
