#ifndef GDB_LIBLET_DATA_DATA_TYPE_HPP
#define GDB_LIBLET_DATA_DATA_TYPE_HPP

#include "DataId.hpp"
#include "GameDB/Container/String.hpp"
#include "GameDB/Memory/Pointers.hpp"

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
        [[nodiscard]] virtual DataId GetDataId() const = 0;

        /**
         * \brief
         * \return
         */
        [[nodiscard]] virtual const String& GetName() const = 0;

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] virtual UniquePtr<DataValue> Instantiate() = 0;
    };
}

#endif // !GDB_LIBLET_DATA_DATA_TYPE_HPP
