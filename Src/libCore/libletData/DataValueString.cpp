#include "GameDB/Data/DataValueString.hpp"

namespace GDB
{
    DataValueString::DataValueString(const DataId dataId, DataType* dataType)
        : DataValue(dataId, dataType)
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
