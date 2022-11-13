#ifndef GDB_LIBLET_DATA_DATA_COLUMN_HPP
#define GDB_LIBLET_DATA_DATA_COLUMN_HPP

#include <memory>
#include <string>

#include "DataId.hpp"
#include "DataType.hpp"

namespace GDB
{
    /**
     * \brief 
     */
    class DataColumn
    {
    public:
        DataColumn(DataId id, std::string name, std::unique_ptr<DataType> dataType);

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
        [[nodiscard]] DataType* GetDataType() const;

    private:
        DataId _id;
        std::string _name;
        std::unique_ptr<DataType> _dataType;
    };
}

#endif // !GDB_LIBLET_DATA_DATA_COLUMN_HPP
