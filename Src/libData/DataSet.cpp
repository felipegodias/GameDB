#include "GameDB/Data/DataSet.hpp"
#include "GameDB/libLog.hpp"
#include "GameDB/libProfiler.hpp"
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
        GDB_PROFILE_FUNCTION();
        return _dataTables;
    }

    void DataSet::AddDataTable(SharedPtr<DataTable> dataTable)
    {
        GDB_PROFILE_FUNCTION();
        if (dataTable == nullptr)
        {
            throw std::runtime_error("DataTable argument can not be null!");
        }

        GDB_LOG_VERBOSE("Main", "Adding new table with name '{0}' to DataSet.", dataTable->GetName());

        const OnPropertyChangedData data = {this, _dataTables.size()};
        _dataTables.push_back(std::move(dataTable));
        _onPropertyChanged(data);
    }

    void DataSet::RemoveDataTable(const DataTable& dataTable)
    {
        GDB_PROFILE_FUNCTION();
        GDB_LOG_VERBOSE("Main", "Removing table with name '{0}' from DataSet.", dataTable.GetName());

        _dataTables.erase(std::remove_if(_dataTables.begin(), _dataTables.end(),
                                         [&dataTable](const SharedPtr<DataTable>& it)
                                         {
                                             return it.get() == &dataTable;
                                         }), _dataTables.end());
    }

    DataSet::OnPropertyChanged* DataSet::GetOnPropertyChanged()
    {
        GDB_PROFILE_FUNCTION();
        return &_onPropertyChanged;
    }

    DataSet::DIInstaller::DIInstaller(DIContainer* diContainer)
    {
        diContainer->RegisterFactory<SharedPtr<DataSet>>(DataSetFactory);
    }
}
