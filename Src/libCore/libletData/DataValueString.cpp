#include "GameDB/Data/DataValueString.hpp"

namespace GDB
{
    DataValueString::DataValueString(const DataId id, DataType* dataType)
        : DataValue(id, dataType)
    {
    }

    const String& DataValueString::GetValue() const
    {
        return _value;
    }

    void DataValueString::SetValue(String value)
    {
        _value = std::move(value);
    }
}
