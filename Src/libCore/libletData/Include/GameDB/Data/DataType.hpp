#ifndef GDB_LIBLET_DATA_DATA_TYPE_HPP
#define GDB_LIBLET_DATA_DATA_TYPE_HPP

#include <string>
#include <memory>

#include "DataId.hpp"

namespace GDB
{
    class DataValue;

    /**
     * \brief
     */
    class DataType
    {
    public:
        virtual ~DataType() = 0;

        /**
         * \brief
         * \return
         */
        [[nodiscard]] virtual DataId GetId() const = 0;

        /**
         * \brief
         * \return
         */
        [[nodiscard]] virtual const std::string& GetName() const = 0;

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] virtual std::unique_ptr<DataValue> Instantiate() = 0;
    };
}

#endif // !GDB_LIBLET_DATA_DATA_TYPE_HPP
