#ifndef PLUTO_GAME_DB_EDITOR_VECTOR_2_H
#define PLUTO_GAME_DB_EDITOR_VECTOR_2_H

#include <nlohmann/json.hpp>

namespace Pluto::GameDB::Editor
{
    struct Vector2 final
    {
        float x; // NOLINT(readability-identifier-length)
        float y; // NOLINT(readability-identifier-length)

        /**
         * \brief
         * \param json
         * \param vector2
         */
        static void ToJson(nlohmann::json& json, const Vector2& vector2);

        /**
         * \brief
         * \param json
         * \param vector2
         */
        static void FromJson(const nlohmann::json& json, Vector2& vector2);
    };

    // Converters for nlohmann/json.
    void to_json(nlohmann::json& json, const Vector2& vector2);
    void from_json(const nlohmann::json& json, Vector2& vector2);
}

#endif // ! PLUTO_GAME_DB_EDITOR_VECTOR_2_H