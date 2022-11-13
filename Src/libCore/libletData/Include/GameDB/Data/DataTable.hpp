#ifndef GDB_LIBLET_DATA_DATA_TABLE_HPP
#define GDB_LIBLET_DATA_DATA_TABLE_HPP

#include "DataColumn.hpp"
#include "DataId.hpp"
#include "DataRow.hpp"
#include "GameDB/Container/String.hpp"
#include "GameDB/Container/Vector.hpp"
#include "GameDB/Memory/Pointers.hpp"

namespace GDB
{
    /**
     * \brief 
     */
    class DataTable
    {
    public:
        DataTable(DataId id, String name);

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] DataId GetId() const;

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
        [[nodiscard]] const Vector<UniquePtr<DataColumn>>& GetColumns() const;

        /**
         * \brief 
         * \param column 
         */
        void AddColumn(UniquePtr<DataColumn> column);

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] const Vector<UniquePtr<DataRow>>& GetRows() const;

        /**
         * \brief 
         * \param dataRow 
         */
        DataRow* AddRow();

    private:
        DataId _id;
        String _name;
        Vector<UniquePtr<DataColumn>> _columns;
        Vector<UniquePtr<DataRow>> _rows;
    };
}

#endif // !GDB_LIBLET_DATA_DATA_TABLE_HPP
