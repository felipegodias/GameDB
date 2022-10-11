#ifndef PLUTO_GAME_DB_EDITOR_COLOR_H
#define PLUTO_GAME_DB_EDITOR_COLOR_H

#include <string>
#include <nlohmann/json.hpp>

namespace Pluto::GameDB::Editor
{
    /**
     * \brief 
     */
    struct Color final
    {
        float r; // NOLINT(readability-identifier-length)
        float g; // NOLINT(readability-identifier-length)
        float b; // NOLINT(readability-identifier-length)
        float a; // NOLINT(readability-identifier-length)

        Color();
        Color(float red, float green, float blue, float alpha);

        /**
         * \brief 
         * \param str 
         */
        bool TryParse(std::string_view str);

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] std::string ToString() const;

        /**
         * \brief 
         * \param json 
         * \param color 
         */
        static void ToJson(nlohmann::json& json, const Color& color);

        /**
         * \brief 
         * \param json 
         * \param color 
         */
        static void FromJson(const nlohmann::json& json, Color& color);
    };

    // Converters for nlohmann/json.
    void to_json(nlohmann::json& json, const Color& color);
    void from_json(const nlohmann::json& json, Color& color);
}

#endif // ! PLUTO_GAME_DB_EDITOR_COLOR_H
