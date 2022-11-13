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
        [[nodiscard]] DataId GetId() const override;
        [[nodiscard]] const std::string& GetName() const override;
        [[nodiscard]] std::unique_ptr<DataValue> Instantiate() override;
    };
}

#endif // !GDB_LIBLET_DATA_DATA_TYPE_STRING_HPP
