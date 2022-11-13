#ifndef GDB_LIBLET_DATA_DATA_VALUE_HPP
#define GDB_LIBLET_DATA_DATA_VALUE_HPP

#include "DataId.hpp"

namespace GDB
{
    class DataType;

    /**
     * \brief 
     */
    class DataValue
    {
    public:
        DataValue(DataId id, DataType* dataType);

        virtual ~DataValue() = 0;

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] DataId GetId() const;

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] DataType* GetDataType() const;

    private:
        DataId _id;
        DataType* _dataType;
    };
}

#endif // !GDB_LIBLET_DATA_DATA_VALUE_HPP
