#include "GameDB/Data/StringValue.hpp"

namespace Pluto::GameDB
{
    StringValue::StringValue(std::string value)
        : _value(std::move(value))
    {
    }

    StringValue::~StringValue() = default;

    std::string& StringValue::GetValue()
    {
        return _value;
    }

    const std::string& StringValue::GetValue() const
    {
        return _value;
    }

    void StringValue::SetValue(std::string value)
    {
        _value = std::move(value);
    }
}
