#ifndef GDB_LIBLET_DATA_DATA_ROW_HPP
#define GDB_LIBLET_DATA_DATA_ROW_HPP

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
        explicit DataRow(DataId id);

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] DataId GetId() const;

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
        DataId _id;
        UnorderedMap<DataId, UniquePtr<DataValue>> _columns;
    };
}

#endif // !GDB_LIBLET_DATA_DATA_ROW_HPP
