#include "GameDB/Data/Field.hpp"

#include "GameDB/Data/BaseType.hpp"

namespace Pluto::GameDB
{
    Field::Field(const Guid instanceId, std::string name, std::unique_ptr<BaseType> type)
        : _instanceId(instanceId),
          _name(std::move(name)),
          _type(std::move(type))
    {
    }

    Field::~Field() = default;

    const Guid& Field::GetInstanceId() const
    {
        return _instanceId;
    }

    const std::string& Field::GetName() const
    {
        return _name;
    }

    void Field::SetName(std::string name)
    {
        _name = std::move(name);
    }

    const BaseType& Field::GetType() const
    {
        return *_type;
    }

    BaseType& Field::GetType()
    {
        return *_type;
    }
}
