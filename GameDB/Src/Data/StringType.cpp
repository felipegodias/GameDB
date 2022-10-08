#include "GameDB/Data/StringType.hpp"

#include "GameDB/Data/StringValue.hpp"

namespace Pluto::GameDB
{
    StringType::~StringType() = default;

    std::string_view StringType::GetName() const
    {
        return "String";
    }

    std::unique_ptr<BaseValue> StringType::InstantiateValue() const
    {
        return std::make_unique<StringValue>("");
    }
}
