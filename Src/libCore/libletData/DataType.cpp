#include "GameDB/Data/DataType.hpp"

#include "GameDB/Data/DataValue.hpp"

namespace GDB
{
    DataType::~DataType() = default;

    DataId DataType::GetDataId() const
    {
        return DataId::Empty;
    }

    const String& DataType::GetName() const
    {
        static String name;
        return name;
    }

    UniquePtr<DataValue> DataType::Instantiate()
    {
        return nullptr;
    }
}
