#include "GameDB/Data/Schema.hpp"

#include "GameDB/Data/BaseType.hpp"

#include <stdexcept>

namespace Pluto::GameDB
{
    Schema::Schema(const Guid instanceId, std::vector<Field> fields)
        : _instanceId(instanceId),
          _fields(std::move(fields))
    {
    }

    const Guid& Schema::GetInstanceId() const
    {
        return _instanceId;
    }

    void Schema::AddField(Field field)
    {
        const auto fieldsIt = std::find_if(_fields.begin(), _fields.end(), [&](const Field& fieldIt)
        {
            return fieldIt.GetInstanceId() == field.GetInstanceId() || fieldIt.GetName() == field.GetName();
        });

        // Checks if an field with the id or name already exists!
        if (fieldsIt == _fields.end())
        {
            throw std::runtime_error("");
        }

        _fields.push_back(std::move(field));
    }

    bool Schema::RemoveField(const Guid& instanceId)
    {
        const auto fieldsIt = std::find_if(_fields.begin(), _fields.end(), [&](const Field& fieldIt)
        {
            return fieldIt.GetInstanceId() == instanceId;
        });

        if (fieldsIt == _fields.end())
        {
            return false;
        }

        _fields.erase(fieldsIt);
        return true;
    }

    const std::vector<Field>& Schema::GetFields() const
    {
        return _fields;
    }

    std::optional<std::reference_wrapper<const Field>> Schema::GetField(const Guid& instanceId) const
    {
        const auto fieldsIt = std::find_if(_fields.begin(), _fields.end(), [&](const Field& fieldIt)
        {
            return fieldIt.GetInstanceId() == instanceId;
        });

        if (fieldsIt == _fields.end())
        {
            return std::nullopt;
        }

        return *fieldsIt;
    }

    std::optional<std::reference_wrapper<Field>> Schema::GetField(const Guid& instanceId)
    {
        const auto fieldsIt = std::find_if(_fields.begin(), _fields.end(), [&](const Field& fieldIt)
        {
            return fieldIt.GetInstanceId() == instanceId;
        });

        if (fieldsIt == _fields.end())
        {
            return std::nullopt;
        }

        return *fieldsIt;
    }

    std::optional<std::reference_wrapper<const Field>> Schema::GetField(const std::string_view name) const
    {
        const auto fieldsIt = std::find_if(_fields.begin(), _fields.end(), [&](const Field& fieldIt)
        {
            return fieldIt.GetName() == name;
        });

        if (fieldsIt == _fields.end())
        {
            return std::nullopt;
        }

        return *fieldsIt;
    }

    std::optional<std::reference_wrapper<Field>> Schema::GetField(const std::string_view name)
    {
        const auto fieldsIt = std::find_if(_fields.begin(), _fields.end(), [&](const Field& fieldIt)
        {
            return fieldIt.GetName() == name;
        });

        if (fieldsIt == _fields.end())
        {
            return std::nullopt;
        }

        return *fieldsIt;
    }
}
