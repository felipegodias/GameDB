#include "GameDB/MathSerializer/ColorJsonSerializer.hpp"

namespace GDB
{
    void to_json(Json& json, const Color& color)
    {
        json = color.ToString();
    }

    void from_json(const Json& json, Color& color)
    {
        color.TryParse(json.get<std::string>());
    }
}
