#include "GameDB/HelloWorld.hpp"
#include "GameDB/Data/Schema.hpp"

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
        Schema schema(Guid::Random(), {});

        return "Hello GameDB";
    }
}
