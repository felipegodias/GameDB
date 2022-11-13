#ifndef GDB_LIBLET_DATA_DATA_ROW_HPP
#define GDB_LIBLET_DATA_DATA_ROW_HPP

#include <memory>
#include <optional>
#include <unordered_map>

#include "DataColumn.hpp"
#include "DataId.hpp"
#include "DataValue.hpp"

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
        void SetValue(const DataColumn& column, std::unique_ptr<DataValue> dataValue);

    private:
        DataId _id;
        std::unordered_map<DataId, std::unique_ptr<DataValue>> _columns;
    };
}

#endif // !GDB_LIBLET_DATA_DATA_ROW_HPP
