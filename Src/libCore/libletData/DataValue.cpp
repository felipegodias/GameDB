#include "GameDB/Data/DataValue.hpp"

namespace GDB
{
    DataValue::DataValue(const DataId id, DataType* dataType)
        : _id(id),
          _dataType(dataType)
    {
    }

    DataValue::~DataValue() = default;

    DataId DataValue::GetId() const
    {
        return _id;
    }

    DataType* DataValue::GetDataType() const
    {
        return _dataType;
    }
}
