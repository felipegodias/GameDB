#include "GameDB/Data/Schema.hpp"

#include <algorithm>
#include <stdexcept>

#include "GameDB/Data/BaseType.hpp"


namespace Pluto::GameDB
{
    Schema::Schema(const Guid instanceId, std::vector<std::unique_ptr<Field>> fields)
        : _instanceId(instanceId),
          _fields(std::move(fields))
    {
    }

    const Guid& Schema::GetInstanceId() const
    {
        return _instanceId;
    }

    void Schema::AddField(std::unique_ptr<Field> field)
    {
        const auto fieldsIt = std::find_if(_fields.begin(), _fields.end(), [&](const auto& fieldIt)
        {
            return fieldIt->GetInstanceId() == field->GetInstanceId() || fieldIt->GetName() == field->GetName();
        });

        // Checks if an field with the id or name already exists!
        if (fieldsIt != _fields.end())
        {
            throw std::runtime_error("");
        }

        _fields.push_back(std::move(field));
    }

    bool Schema::RemoveField(const Guid& instanceId)
    {
        const auto fieldsIt = std::find_if(_fields.begin(), _fields.end(), [&](const auto& fieldIt)
        {
            return fieldIt->GetInstanceId() == instanceId;
        });

        if (fieldsIt == _fields.end())
        {
            return false;
        }

        _fields.erase(fieldsIt);
        return true;
    }

    const std::vector<std::unique_ptr<Field>>& Schema::GetFields() const
    {
        return _fields;
    }

    Field* Schema::GetField(const Guid& instanceId) const
    {
        const auto fieldsIt = std::find_if(_fields.begin(), _fields.end(), [&](const auto& fieldIt)
        {
            return fieldIt->GetInstanceId() == instanceId;
        });

        if (fieldsIt == _fields.end())
        {
            return nullptr;
        }

        return fieldsIt->get();
    }

    Field* Schema::GetField(const std::string_view name) const
    {
        const auto fieldsIt = std::find_if(_fields.begin(), _fields.end(), [&](const auto& fieldIt)
        {
            return fieldIt->GetName() == name;
        });

        if (fieldsIt == _fields.end())
        {
            return nullptr;
        }

        return fieldsIt->get();
    }
}
