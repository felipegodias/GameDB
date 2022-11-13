#ifndef GDB_LIBLET_DATA_DATA_VALUE_STRING_HPP
#define GDB_LIBLET_DATA_DATA_VALUE_STRING_HPP

#include "DataValue.hpp"
#include "GameDB/Container/String.hpp"

namespace GDB
{
    /**
     * \brief 
     */
    class DataValueString final : public DataValue
    {
    public:
        DataValueString(DataId id, DataType* dataType);

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] const String& GetValue() const;

        /**
         * \brief 
         * \param value 
         */
        void SetValue(String value);

    private:
        String _value;
    };
}

#endif // !GDB_LIBLET_DATA_DATA_VALUE_STRING_HPP
