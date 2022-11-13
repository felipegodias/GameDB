#include "GameDB/Data/DataValueString.hpp"

namespace GDB
{
    DataValueString::DataValueString(const DataId id, DataType* dataType)
        : DataValue(id, dataType)
    {
    }

    const std::string& DataValueString::GetValue() const
    {
        return _value;
    }

    void DataValueString::SetValue(std::string value)
    {
        _value = std::move(value);
    }
}
