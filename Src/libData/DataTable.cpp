#include "GameDB/Data/DataTable.hpp"

#include "GameDB/libLog.hpp"
#include "GameDB/libProfiler.hpp"

namespace GDB
{
    DataTable::DataTable(DataSet* dataSet, const DataId dataId, String name)
        : _dataSet(dataSet),
          _dataId(dataId),
          _name(std::move(name))
    {
        GDB_PROFILE_FUNCTION();
    }

    DataSet* DataTable::GetDataSet() const
    {
        GDB_PROFILE_FUNCTION();
        return _dataSet;
    }

    DataId DataTable::GetDataId() const
    {
        GDB_PROFILE_FUNCTION();
        return _dataId;
    }

    const String& DataTable::GetName() const
    {
        GDB_PROFILE_FUNCTION();
        return _name;
    }

    void DataTable::SetName(String name)
    {
        GDB_PROFILE_FUNCTION();
        GDB_LOG_VERBOSE("Main", "Renaming data table from '{0}' to '{1}'.", _name, name);

        const OnPropertyChangedData data = {this, _name, _columns.size(), _rows.size()};
        _name = std::move(name);
        _onPropertyChanged(data);
    }

    const Vector<SharedPtr<DataColumn>>& DataTable::GetColumns() const
    {
        GDB_PROFILE_FUNCTION();
        return _columns;
    }

    void DataTable::AddColumn(SharedPtr<DataColumn> column)
    {
        GDB_PROFILE_FUNCTION();
        if (column == nullptr)
        {
            throw std::runtime_error("DataColumn argument can not be null!");
        }

        GDB_LOG_VERBOSE("Main", "Adding new table column with name '{0}' to table '{1}'.", column->GetName(), _name);

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
        GDB_PROFILE_FUNCTION();
        GDB_LOG_VERBOSE("Main", "Removing table column with name '{0}' from table '{1}'.", column->GetName(), _name);

        auto removeIfPredicate = [&column](const SharedPtr<DataColumn>& it)
        {
            return column == it;
        };

        _columns.erase(std::remove_if(_columns.begin(), _columns.end(), removeIfPredicate), _columns.end());
    }

    const Vector<SharedPtr<DataRow>>& DataTable::GetRows() const
    {
        GDB_PROFILE_FUNCTION();
        return _rows;
    }

    SharedPtr<DataRow> DataTable::AddRow()
    {
        GDB_PROFILE_FUNCTION();
        GDB_LOG_VERBOSE("Main", "Adding new table row to table '{0}'.", _name);

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
        GDB_PROFILE_FUNCTION();
        return &_onPropertyChanged;
    }
}
