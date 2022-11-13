#ifndef GDB_LIBLET_DATA_DATA_TYPE_STRING_HPP
#define GDB_LIBLET_DATA_DATA_TYPE_STRING_HPP

#include "DataType.hpp"

namespace GDB
{
    /**
     * \brief 
     */
    class DataTypeString final : public DataType
    {
    public:
        [[nodiscard]] DataId GetDataId() const override;
        [[nodiscard]] const String& GetName() const override;
        [[nodiscard]] UniquePtr<DataValue> Instantiate() override;
    };
}

#endif // !GDB_LIBLET_DATA_DATA_TYPE_STRING_HPP
