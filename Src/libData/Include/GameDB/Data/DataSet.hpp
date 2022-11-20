#ifndef GDB_LIB_DATA_DATA_SET_HPP
#define GDB_LIB_DATA_DATA_SET_HPP

#include <type_traits>

#include "DataId.hpp"
#include "DataTable.hpp"
#include "GameDB/Container/Vector.hpp"
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
        [[nodiscard]] const Vector<UniquePtr<DataTable>>& GetDataTables() const;

        /**
         * \brief 
         * \param dataTable 
         * \return 
         */
        DataTable* AddDataTable(UniquePtr<DataTable> dataTable);

        /**
         * \brief 
         * \tparam ArgsTy 
         * \param args 
         * \return 
         */
        template <typename ... ArgsTy, std::enable_if_t<std::is_constructible_v<DataTable, ArgsTy...>, bool>  = true>
        DataTable* AddDataTable(ArgsTy&& ... args)
        {
            return AddDataTable(MakeUnique<DataTable>(std::forward<ArgsTy>(args)...));
        }

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] OnPropertyChanged* GetOnPropertyChanged();

    private:
        Vector<UniquePtr<DataTable>> _dataTables;
        OnPropertyChanged _onPropertyChanged;
    };
}

#endif // !GDB_LIB_DATA_DATA_SET_HPP
