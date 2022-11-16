#include "GameDB/Data/DataRow.hpp"

namespace GDB
{
    DataRow::DataRow(const DataId dataId)
        : _dataId(dataId)
    {
    }

    DataId DataRow::GetDataId() const
    {
        return _dataId;
    }

    std::optional<DataValue*> DataRow::GetValue(const DataColumn& column) const
    {
        const auto columnsIt = _columns.find(column.GetDataId());
        if (columnsIt == _columns.end())
        {
            return std::nullopt;
        }

        return columnsIt->second.get();
    }

    void DataRow::SetValue(const DataColumn& column, UniquePtr<DataValue> dataValue)
    {
        _columns[column.GetDataId()] = std::move(dataValue);
    }
}
