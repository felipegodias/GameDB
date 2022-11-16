#include "GameDB/Data/DataColumn.hpp"

namespace GDB
{
    DataColumn::DataColumn(const DataId dataId, String name, UniquePtr<DataType> dataType)
        : _dataId(dataId),
          _name(std::move(name)),
          _dataType(std::move(dataType))
    {
    }

    DataId DataColumn::GetDataId() const
    {
        return _dataId;
    }

    const String& DataColumn::GetName() const
    {
        return _name;
    }

    void DataColumn::SetName(String name)
    {
        _name = std::move(name);
    }

    DataType* DataColumn::GetDataType() const
    {
        return _dataType.get();
    }
}
