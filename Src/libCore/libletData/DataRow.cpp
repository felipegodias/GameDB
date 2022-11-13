#include "GameDB/Data/DataRow.hpp"

namespace GDB
{
    DataRow::DataRow(const DataId id)
        : _id(id)
    {
    }

    DataId DataRow::GetId() const
    {
        return _id;
    }

    std::optional<DataValue*> DataRow::GetValue(const DataColumn& column) const
    {
        const auto columnsIt = _columns.find(column.GetId());
        if (columnsIt == _columns.end())
        {
            return std::nullopt;
        }

        return columnsIt->second.get();
    }

    void DataRow::SetValue(const DataColumn& column, UniquePtr<DataValue> dataValue)
    {
        _columns[column.GetId()] = std::move(dataValue);
    }
}
