#include "GameDB/Data/Table.hpp"

namespace Pluto::GameDB
{
    Table::Table(Guid instanceId, std::unique_ptr<Schema> schema)
        : _instanceId(instanceId),
          _schema(std::move(schema))
    {
    }

    const Guid& Table::GetInstanceId() const
    {
        return _instanceId;
    }

    NotNull<Schema*> Table::GetSchema() const
    {
        return _schema.get();
    }
}
