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
        DataValue(DataId dataId, DataType* dataType);

        virtual ~DataValue() = 0;

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] DataId GetDataId() const;

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] DataType* GetDataType() const;

    private:
        DataId _dataId;
        DataType* _dataType;
    };
}

#endif // !GDB_LIBLET_DATA_DATA_VALUE_HPP
