#include "GameDB/Data/DataColumn.hpp"

namespace GDB
{
    DataColumn::DataColumn(const DataId id, std::string name, std::unique_ptr<DataType> dataType)
        : _id(id),
          _name(std::move(name)),
          _dataType(std::move(dataType))
    {
    }

    DataId DataColumn::GetId() const
    {
        return _id;
    }

    const std::string& DataColumn::GetName() const
    {
        return _name;
    }

    void DataColumn::SetName(std::string name)
    {
        _name = std::move(name);
    }

    DataType* DataColumn::GetDataType() const
    {
        return _dataType.get();
    }
}
