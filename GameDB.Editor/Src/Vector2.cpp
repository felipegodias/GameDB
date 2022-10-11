#include "GameDB/Editor/Vector2.hpp"

namespace Pluto::GameDB::Editor
{
    void Vector2::ToJson(nlohmann::json& json, const Vector2& vector2)
    {
        json["x"] = vector2.x;
        json["y"] = vector2.y;
    }

    void Vector2::FromJson(const nlohmann::json& json, Vector2& vector2)
    {
        vector2.x = json["x"].get<float>();
        vector2.y = json["y"].get<float>();
    }

    void to_json(nlohmann::json& json, const Vector2& vector2)
    {
        Vector2::ToJson(json, vector2);
    }

    void from_json(const nlohmann::json& json, Vector2& vector2)
    {
        Vector2::FromJson(json, vector2);
    }
}
