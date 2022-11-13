#include "GameDB/Data/DataId.hpp"

#include <limits>
#include <random>

namespace GDB
{
    const DataId DataId::Empty(0);

    DataId::DataId(const ValueType value)
        : _value(value)
    {
    }

    bool DataId::operator==(const DataId& rhs) const
    {
        return _value == rhs._value;
    }

    bool DataId::operator!=(const DataId& rhs) const
    {
        return !(*this == rhs);
    }

    DataId::ValueType DataId::GetValue() const
    {
        return _value;
    }

    DataId DataId::Random()
    {
        static thread_local std::mt19937 generator;
        std::uniform_int_distribution<ValueType> distribution(1, std::numeric_limits<ValueType>::max());
        const ValueType value = distribution(generator);
        return DataId(value);
    }
}
