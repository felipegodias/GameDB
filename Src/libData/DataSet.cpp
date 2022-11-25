#include "GameDB/Data/DataSet.hpp"
#include "GameDB/DI/SingletonContainer.hpp"

namespace GDB
{
    namespace
    {
        SharedPtr<DataSet> DataSetFactory([[maybe_unused]] const DIContainer& di)
        {
            static SharedPtr<DataSet> dataSet = MakeShared<DataSet>();
            return dataSet;
        }
    }

    const Vector<SharedPtr<DataTable>>& DataSet::GetDataTables() const
    {
        return _dataTables;
    }

    void DataSet::AddDataTable(SharedPtr<DataTable> dataTable)
    {
        const OnPropertyChangedData data = {this, _dataTables.size()};
        _dataTables.push_back(std::move(dataTable));
        _onPropertyChanged(data);
    }

    DataSet::OnPropertyChanged* DataSet::GetOnPropertyChanged()
    {
        return &_onPropertyChanged;
    }

    DataSet::DIInstaller::DIInstaller(DIContainer* diContainer)
    {
        diContainer->RegisterFactory<SharedPtr<DataSet>>(DataSetFactory);
    }
}
