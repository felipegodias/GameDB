#ifndef GDB_LIB_DATA_DATA_SET_HPP
#define GDB_LIB_DATA_DATA_SET_HPP

#include <type_traits>

#include "DataId.hpp"
#include "DataTable.hpp"
#include "GameDB/Container/Vector.hpp"
#include "GameDB/DI/DIContainer.hpp"
#include "GameDB/Event/Event.hpp"

namespace GDB
{
    /**
     * \brief 
     */
    class DataSet
    {
    public:
        /**
         * \brief 
         */
        struct OnPropertyChangedData
        {
            const DataSet* dataSet;
            std::size_t oldDataTablesSize;
        };

        /**
         * \brief 
         */
        using OnPropertyChanged = Event<OnPropertyChangedData>;

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] const Vector<SharedPtr<DataTable>>& GetDataTables() const;

        /**
         * \brief 
         * \param dataTable 
         * \return 
         */
        void AddDataTable(SharedPtr<DataTable> dataTable);

        /**
         * \brief 
         * \tparam ArgsTy 
         * \param args 
         * \return 
         */
        template <typename ... ArgsTy,
                  std::enable_if_t<std::is_constructible_v<DataTable, DataSet*, ArgsTy...>, bool>  = true>
        SharedPtr<DataTable> AddDataTable(ArgsTy&& ... args)
        {
            auto dataTable = MakeShared<DataTable>(this, std::forward<ArgsTy>(args)...);
            AddDataTable(dataTable);
            return dataTable;
        }

        void RemoveDataTable(const DataTable& dataTable);

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] OnPropertyChanged* GetOnPropertyChanged();

    private:
        Vector<SharedPtr<DataTable>> _dataTables;
        OnPropertyChanged _onPropertyChanged;

        GDB_DI_INSTALLER();
    };
}

#endif // !GDB_LIB_DATA_DATA_SET_HPP
