#include "GameDB/Data/Guid.hpp"

#include <random>

namespace Pluto::GameDB
{
    const Guid Guid::Empty(0);

    Guid::Guid(const size_t value)
        : _value(value)
    {
    }

    bool Guid::operator==(const Guid& rhs) const
    {
        return _value == rhs._value;
    }

    bool Guid::operator!=(const Guid& rhs) const
    {
        return !(*this == rhs);
    }

    Guid Guid::Random()
    {
        static thread_local std::mt19937 generator;
        std::uniform_int_distribution<size_t> distribution(1, std::numeric_limits<size_t>::max());
        const size_t value = distribution(generator);
        return Guid(value);
    }
}
