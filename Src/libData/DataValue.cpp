#include "GameDB/Data/DataValue.hpp"

namespace GDB
{
    DataValue::DataValue(const DataId dataId, DataType* dataType)
        : _dataId(dataId),
          _dataType(dataType)
    {
    }

    DataValue::~DataValue() = default;

    DataId DataValue::GetDataId() const
    {
        return _dataId;
    }

    DataType* DataValue::GetDataType() const
    {
        return _dataType;
    }
}
