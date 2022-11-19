#include "GameDB/Data/DataTable.hpp"

namespace GDB
{
    DataTable::DataTable(const DataId dataId, String name)
        : _dataId(dataId),
          _name(std::move(name))
    {
    }

    DataId DataTable::GetDataId() const
    {
        return _dataId;
    }

    const String& DataTable::GetName() const
    {
        return _name;
    }

    void DataTable::SetName(String name)
    {
        const OnPropertyChangedData data = {this, _name, _columns.size(), _rows.size()};
        _name = std::move(name);
        _onPropertyChanged(data);
    }

    const Vector<UniquePtr<DataColumn>>& DataTable::GetColumns() const
    {
        return _columns;
    }

    void DataTable::AddColumn(UniquePtr<DataColumn> column)
    {
        const OnPropertyChangedData data = {this, _name, _columns.size(), _rows.size()};

        DataType* dataType = column->GetDataType();
        for (const auto& row : _rows)
        {
            row->SetValue(*column, dataType->Instantiate());
        }
        _columns.push_back(std::move(column));
        _onPropertyChanged(data);
    }

    const Vector<UniquePtr<DataRow>>& DataTable::GetRows() const
    {
        return _rows;
    }

    DataRow* DataTable::AddRow()
    {
        const OnPropertyChangedData data = {this, _name, _columns.size(), _rows.size()};
        _rows.push_back(MakeUnique<DataRow>(DataId::Random()));
        DataRow* row = _rows[_rows.size() - 1].get();
        for (const auto& column : _columns)
        {
            row->SetValue(*column, column->GetDataType()->Instantiate());
        }
        _onPropertyChanged(data);
        return row;
    }

    DataTable::OnPropertyChanged* DataTable::GetOnPropertyChanged()
    {
        return &_onPropertyChanged;
    }
}
