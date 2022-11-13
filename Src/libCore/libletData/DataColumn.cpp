#include "GameDB/Data/DataColumn.hpp"

namespace GDB
{
    DataColumn::DataColumn(const DataId id, String name, UniquePtr<DataType> dataType)
        : _id(id),
          _name(std::move(name)),
          _dataType(std::move(dataType))
    {
    }

    DataId DataColumn::GetId() const
    {
        return _id;
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
