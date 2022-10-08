#include "GameDB/Data/BaseType.hpp"

#include "GameDB/Data/BaseValue.hpp"
#include "GameDB/Debug/Assert.hpp"

namespace Pluto::GameDB
{
    BaseType::~BaseType() = default;

    std::string_view BaseType::GetName() const
    {
        GAME_DB_ASSERT(true, "Not implemented!");
        return "";
    }

    std::unique_ptr<BaseValue> BaseType::InstantiateValue() const
    {
        GAME_DB_ASSERT(true, "Not implemented!");
        return nullptr;
    }
}
