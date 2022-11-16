#ifndef GDB_LIB_DATA_DATA_ROW_HPP
#define GDB_LIB_DATA_DATA_ROW_HPP

#include <optional>

#include "DataColumn.hpp"
#include "DataId.hpp"
#include "DataValue.hpp"
#include "GameDB/Container/UnorderedMap.hpp"
#include "GameDB/Memory/Pointers.hpp"

namespace GDB
{
    /**
     * \brief 
     */
    class DataRow
    {
    public:
        explicit DataRow(DataId dataId);

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] DataId GetDataId() const;

        /**
         * \brief 
         * \param column 
         * \return 
         */
        [[nodiscard]] std::optional<DataValue*> GetValue(const DataColumn& column) const;

        /**
         * \brief 
         * \param column 
         * \param dataValue 
         */
        void SetValue(const DataColumn& column, UniquePtr<DataValue> dataValue);

    private:
        DataId _dataId;
        UnorderedMap<DataId, UniquePtr<DataValue>> _columns;
    };
}

#endif // !GDB_LIB_DATA_DATA_ROW_HPP
