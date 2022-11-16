#include "GameDB/Data/DataTypeString.hpp"

#include "GameDB/Data/DataValueString.hpp"

namespace GDB
{
    DataId DataTypeString::GetDataId() const
    {
        static DataId dataId = DataId::Random();
        return dataId;
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
