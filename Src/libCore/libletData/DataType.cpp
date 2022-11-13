#include "GameDB/Data/DataType.hpp"

#include "GameDB/Data/DataValue.hpp"

namespace GDB
{
    DataType::~DataType() = default;

    DataId DataType::GetId() const
    {
        return DataId::Empty;
    }

    const std::string& DataType::GetName() const
    {
        static std::string name;
        return name;
    }

    std::unique_ptr<DataValue> DataType::Instantiate()
    {
        return nullptr;
    }
}
