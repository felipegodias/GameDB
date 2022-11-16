#ifndef GDB_LIB_DATA_DATA_ID_HPP
#define GDB_LIB_DATA_DATA_ID_HPP

#include <string>

namespace GDB
{
    /**
     * \brief 
     */
    class DataId final
    {
    public:
        using ValueType = unsigned int;

        explicit DataId(ValueType value);

        bool operator==(const DataId& rhs) const;
        bool operator!=(const DataId& rhs) const;

        ValueType GetValue() const;

        /**
         * \brief 
         * \return 
         */
        static DataId Random();

        /**
         * \brief 
         */
        static const DataId Empty;

    private:
        ValueType _value;
    };
}

namespace std {

    template <>
    struct hash<GDB::DataId>
    {
        std::size_t operator()(const GDB::DataId& dataId) const noexcept
        {
            return std::hash<GDB::DataId::ValueType>()(dataId.GetValue());
        }
    };

}

#endif // !GDB_LIB_DATA_DATA_ID_HPP
