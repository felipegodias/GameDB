#include "GameDB/Data/DataTable.hpp"

namespace GDB
{
    DataTable::DataTable(DataSet* dataSet, const DataId dataId, String name)
        : _dataSet(dataSet),
          _dataId(dataId),
          _name(std::move(name))
    {
    }

    DataSet* DataTable::GetDataSet() const
    {
        return _dataSet;
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

    const Vector<SharedPtr<DataColumn>>& DataTable::GetColumns() const
    {
        return _columns;
    }

    void DataTable::AddColumn(SharedPtr<DataColumn> column)
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

    void DataTable::DeleteColumn(SharedPtr<DataColumn> column)
    {
        auto removeIfPredicate = [&column](const SharedPtr<DataColumn>& it)
        {
            return column == it;
        };

        _columns.erase(std::remove_if(_columns.begin(), _columns.end(), removeIfPredicate), _columns.end());
    }

    const Vector<SharedPtr<DataRow>>& DataTable::GetRows() const
    {
        return _rows;
    }

    SharedPtr<DataRow> DataTable::AddRow()
    {
        const OnPropertyChangedData data = {this, _name, _columns.size(), _rows.size()};
        auto row = MakeShared<DataRow>(DataId::Random());
        _rows.push_back(row);
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
