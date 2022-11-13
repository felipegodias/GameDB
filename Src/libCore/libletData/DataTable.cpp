#include "GameDB/Data/DataTable.hpp"

namespace GDB
{
    DataTable::DataTable(const DataId id, std::string name)
        : _id(id),
          _name(std::move(name))
    {
    }

    DataId DataTable::GetId() const
    {
        return _id;
    }

    const std::string& DataTable::GetName() const
    {
        return _name;
    }

    void DataTable::SetName(std::string name)
    {
        _name = std::move(name);
    }

    const std::vector<std::unique_ptr<DataColumn>>& DataTable::GetColumns() const
    {
        return _columns;
    }

    void DataTable::AddColumn(std::unique_ptr<DataColumn> column)
    {
        DataType* dataType = column->GetDataType();
        for (const auto& row : _rows)
        {
            row->SetValue(*column, dataType->Instantiate());
        }
        _columns.push_back(std::move(column));
    }

    const std::vector<std::unique_ptr<DataRow>>& DataTable::GetRows() const
    {
        return _rows;
    }

    DataRow* DataTable::AddRow()
    {
        _rows.push_back(std::make_unique<DataRow>(DataId::Random()));
        DataRow* row = _rows[_rows.size() - 1].get();
        for (const auto& column : _columns)
        {
            row->SetValue(*column, column->GetDataType()->Instantiate());
        }
        return row;
    }
}
