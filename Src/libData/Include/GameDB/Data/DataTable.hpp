#ifndef GDB_LIB_DATA_DATA_TABLE_HPP
#define GDB_LIB_DATA_DATA_TABLE_HPP

#include "DataColumn.hpp"
#include "DataId.hpp"
#include "DataRow.hpp"
#include "GameDB/Container/String.hpp"
#include "GameDB/Container/Vector.hpp"
#include "GameDB/Event/Event.hpp"
#include "GameDB/Memory/Pointers.hpp"

namespace GDB
{
    class DataSet;

    /**
     * \brief 
     */
    class DataTable
    {
    public:
        struct OnPropertyChangedData
        {
            const DataTable* dataTable;
            String oldName;
            std::size_t oldColumnsSize;
            std::size_t oldRowsSize;
        };

        using OnPropertyChanged = Event<OnPropertyChangedData>;

        DataTable(DataSet* dataSet, DataId dataId, String name);

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] DataSet* GetDataSet() const;

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] DataId GetDataId() const;

        /**
         * \brief
         * \return
         */
        [[nodiscard]] const String& GetName() const;

        /**
         * \brief 
         * \param name 
         */
        void SetName(String name);

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] const Vector<SharedPtr<DataColumn>>& GetColumns() const;

        /**
         * \brief 
         * \param column 
         */
        void AddColumn(SharedPtr<DataColumn> column);

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] const Vector<SharedPtr<DataRow>>& GetRows() const;

        /**
         * \brief 
         * \return 
         */
        SharedPtr<DataRow> AddRow();

        /**
         * \brief 
         * \return 
         */
        OnPropertyChanged* GetOnPropertyChanged();

    private:
        DataSet* _dataSet;
        DataId _dataId;
        String _name;
        Vector<SharedPtr<DataColumn>> _columns;
        Vector<SharedPtr<DataRow>> _rows;
        OnPropertyChanged _onPropertyChanged;
    };
}

#endif // !GDB_LIB_DATA_DATA_TABLE_HPP
