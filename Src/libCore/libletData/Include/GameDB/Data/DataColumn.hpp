#ifndef GDB_LIBLET_DATA_DATA_COLUMN_HPP
#define GDB_LIBLET_DATA_DATA_COLUMN_HPP

#include "DataId.hpp"
#include "DataType.hpp"
#include "GameDB/Container/String.hpp"
#include "GameDB/Memory/Pointers.hpp"

namespace GDB
{
    /**
     * \brief 
     */
    class DataColumn
    {
    public:
        DataColumn(DataId dataId, String name, UniquePtr<DataType> dataType);

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
        [[nodiscard]] DataType* GetDataType() const;

    private:
        DataId _dataId;
        String _name;
        UniquePtr<DataType> _dataType;
    };
}

#endif // !GDB_LIBLET_DATA_DATA_COLUMN_HPP
