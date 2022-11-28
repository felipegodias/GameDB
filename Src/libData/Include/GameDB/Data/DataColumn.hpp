#ifndef GDB_LIB_DATA_DATA_COLUMN_HPP
#define GDB_LIB_DATA_DATA_COLUMN_HPP

#include "DataId.hpp"
#include "DataType.hpp"
#include "GameDB/Container/String.hpp"
#include "GameDB/Memory/Pointers.hpp"

namespace GDB
{
    class DataTable;

    /**
     * \brief 
     */
    class DataColumn
    {
    public:
        DataColumn(DataId dataId, String name, DataTable* dataTable, UniquePtr<DataType> dataType);

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
        [[nodiscard]] DataTable* GetDataTable() const;

        /**
         * \brief
         * \return
         */
        [[nodiscard]] DataType* GetDataType() const;

    private:
        DataId _dataId;
        String _name;
        DataTable* _dataTable;
        UniquePtr<DataType> _dataType;
    };
}

#endif // !GDB_LIB_DATA_DATA_COLUMN_HPP
