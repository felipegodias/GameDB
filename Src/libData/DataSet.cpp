#include "GameDB/Data/DataSet.hpp"

namespace GDB
{
    const Vector<UniquePtr<DataTable>>& DataSet::GetDataTables() const
    {
        return _dataTables;
    }

    DataTable* DataSet::AddDataTable(UniquePtr<DataTable> dataTable)
    {
        const OnPropertyChangedData data = {this, _dataTables.size()};
        _dataTables.push_back(std::move(dataTable));
        _onPropertyChanged(data);
        return _dataTables[_dataTables.size() - 1].get();
    }

    DataSet::OnPropertyChanged* DataSet::GetOnPropertyChanged()
    {
        return &_onPropertyChanged;
    }
}
