#ifndef GDB_LIB_DATA_EDITOR_DATA_SET_EDITOR_WINDOW_HPP
#define GDB_LIB_DATA_EDITOR_DATA_SET_EDITOR_WINDOW_HPP

#include "GameDB/Data/DataSet.hpp"
#include "GameDB/Editor/EditorWindow.hpp"

namespace GDB
{
    class DataSetEditorWindow final : public EditorWindow
    {
    public:
        explicit DataSetEditorWindow(DataSet* dataSet);

    protected:
        void OnAwake() override;
        void OnUpdate() override;
        void OnGUI() override;

    private:
        DataSet* _dataSet;
    };
}

#endif // !GDB_LIB_DATA_EDITOR_DATA_SET_EDITOR_WINDOW_HPP
