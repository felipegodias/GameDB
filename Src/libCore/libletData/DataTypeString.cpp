#include "GameDB/Data/DataTypeString.hpp"

#include "GameDB/Data/DataValueString.hpp"

namespace GDB
{
    DataId DataTypeString::GetId() const
    {
        static DataId id = DataId::Random();
        return id;
    }

    const std::string& DataTypeString::GetName() const
    {
        static std::string name = "String";
        return name;
    }

    std::unique_ptr<DataValue> DataTypeString::Instantiate()
    {
        return std::make_unique<DataValueString>(DataId::Random(), this);
    }
}
