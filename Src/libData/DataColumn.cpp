#include "GameDB/Data/DataColumn.hpp"

namespace GDB
{
    DataColumn::DataColumn(const DataId dataId, String name, DataTable* dataTable, UniquePtr<DataType> dataType)
        : _dataId(dataId),
          _name(std::move(name)),
          _dataTable(dataTable),
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

    DataTable* DataColumn::GetDataTable() const
    {
        return _dataTable;
    }

    DataType* DataColumn::GetDataType() const
    {
        return _dataType.get();
    }
}
