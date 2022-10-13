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
        float r = 0.0F; // NOLINT(readability-identifier-length)
        float g = 0.0F; // NOLINT(readability-identifier-length)
        float b = 0.0F; // NOLINT(readability-identifier-length)
        float a = 0.0F; // NOLINT(readability-identifier-length)

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
    };

    // Converters for nlohmann/json.
    void to_json(nlohmann::json& json, const Color& color);
    void from_json(const nlohmann::json& json, Color& color);
}

#endif // ! PLUTO_GAME_DB_EDITOR_COLOR_H
