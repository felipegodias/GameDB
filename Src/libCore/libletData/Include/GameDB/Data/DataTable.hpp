#ifndef GDB_LIBLET_DATA_DATA_TABLE_HPP
#define GDB_LIBLET_DATA_DATA_TABLE_HPP

#include <memory>
#include <string>
#include <vector>

#include "DataColumn.hpp"
#include "DataId.hpp"
#include "DataRow.hpp"

namespace GDB
{
    /**
     * \brief 
     */
    class DataTable
    {
    public:
        DataTable(DataId id, std::string name);

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] DataId GetId() const;

        /**
         * \brief
         * \return
         */
        [[nodiscard]] const std::string& GetName() const;

        /**
         * \brief 
         * \param name 
         */
        void SetName(std::string name);

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] const std::vector<std::unique_ptr<DataColumn>>& GetColumns() const;

        /**
         * \brief 
         * \param column 
         */
        void AddColumn(std::unique_ptr<DataColumn> column);

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] const std::vector<std::unique_ptr<DataRow>>& GetRows() const;

        /**
         * \brief 
         * \param dataRow 
         */
        DataRow* AddRow();

    private:
        DataId _id;
        std::string _name;
        std::vector<std::unique_ptr<DataColumn>> _columns;
        std::vector<std::unique_ptr<DataRow>> _rows;
    };
}

#endif // !GDB_LIBLET_DATA_DATA_TABLE_HPP
