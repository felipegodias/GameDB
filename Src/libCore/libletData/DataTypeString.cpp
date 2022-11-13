#include "GameDB/Data/DataTypeString.hpp"

#include "GameDB/Data/DataValueString.hpp"

namespace GDB
{
    DataId DataTypeString::GetId() const
    {
        static DataId id = DataId::Random();
        return id;
    }

    const String& DataTypeString::GetName() const
    {
        static String name = "String";
        return name;
    }

    UniquePtr<DataValue> DataTypeString::Instantiate()
    {
        return MakeUnique<DataValueString>(DataId::Random(), this);
    }
}
