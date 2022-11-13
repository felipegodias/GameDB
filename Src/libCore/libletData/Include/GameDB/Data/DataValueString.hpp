#ifndef GDB_LIBLET_DATA_DATA_VALUE_STRING_HPP
#define GDB_LIBLET_DATA_DATA_VALUE_STRING_HPP

#include <string>

#include "DataValue.hpp"

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
        [[nodiscard]] const std::string& GetValue() const;

        /**
         * \brief 
         * \param value 
         */
        void SetValue(std::string value);

    private:
        std::string _value;
    };
}

#endif // !GDB_LIBLET_DATA_DATA_VALUE_STRING_HPP
