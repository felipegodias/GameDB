#include "GameDB/HelloWorld.hpp"
#include "GameDB/Data/Schema.hpp"
#include "GameDB/Data/Table.hpp"
#include "GameDB/Data/BaseType.hpp"

#include <chrono>
#include <fstream>
#include <iostream>
#include <memory>
#include <fmt/format.h>
#include <nlohmann/json.hpp>

using Json = nlohmann::ordered_json;

namespace Pluto::GameDB
{
    std::string GetGameDBHelloWorld()
    {
        /*
        auto schema = std::make_unique<Schema>(Guid::Empty, std::vector<std::unique_ptr<Field>>());
        Table table(Guid::Empty, std::move(schema));
        table.GetSchema()->GetField("")->SetName("");
        */
        //Field field(Guid::Random(), "First", nullptr);
        //schemaA.AddField(std::move(field));
        //schemaA.GetField(Guid::Random()).value() = Field();

        return "Hello GameDB";
    }
}
