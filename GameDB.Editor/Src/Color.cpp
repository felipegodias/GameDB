#include "GameDB/Editor/Color.hpp"

#include <sstream>

namespace Pluto::GameDB::Editor
{
    namespace
    {
        constexpr float minColorValue = 0.0F;
        constexpr float maxColorValue = 255.0F;
        constexpr unsigned int redChannelMask = 0xff000000;
        constexpr unsigned int redChannelShift = 24;
        constexpr unsigned int blueChannelMask = 0x00ff0000;
        constexpr unsigned int blueChannelShift = 16;
        constexpr unsigned int greenChannelMask = 0x0000ff00;
        constexpr unsigned int greenChannelShift = 8;
        constexpr unsigned int alphaChannelMask = 0x000000ff;
        constexpr unsigned int alphaChannelShift = 0;

        /**
         * \brief 
         * \param channel 
         * \return 
         */
        float normalizeColorChannel(const uint8_t channel)
        {
            return std::clamp(static_cast<float>(channel) / maxColorValue, minColorValue, maxColorValue);
        }
    }

    Color::Color()
        : r(0),
          g(0),
          b(0),
          a(0)
    {
    }

    Color::Color(const float red, const float green, const float blue, const float alpha) // NOLINT(bugprone-easily-swappable-parameters)
        : r(red),
          g(green),
          b(blue),
          a(alpha)
    {
    }

    bool Color::TryParse(const std::string_view str)
    {
        // Validate!

        [[maybe_unused]] char hashtag = ' ';
        unsigned int color = 0;
        std::istringstream iss(str.data());
        iss >> hashtag >> std::hex >> color;

        r = normalizeColorChannel(static_cast<uint8_t>((color & redChannelMask) >> redChannelShift));
        g = normalizeColorChannel(static_cast<uint8_t>((color & greenChannelMask) >> greenChannelShift));
        b = normalizeColorChannel(static_cast<uint8_t>((color & blueChannelMask) >> blueChannelShift));
        a = normalizeColorChannel(static_cast<uint8_t>((color & alphaChannelMask) >> alphaChannelShift));
        return true;
    }

    std::string Color::ToString() const
    {
        const unsigned int color =
            (static_cast<uint8_t>(r * maxColorValue) << redChannelShift) +
            (static_cast<uint8_t>(g * maxColorValue) << greenChannelShift) +
            (static_cast<uint8_t>(b * maxColorValue) << blueChannelShift) +
            (static_cast<uint8_t>(a * maxColorValue) << alphaChannelShift);

        constexpr int hexLength = 8;
        std::stringstream strStream;
        strStream << "#" << std::setw(hexLength) << std::setfill('0') << std::hex << color;
        return strStream.str();
    }

    void Color::ToJson(nlohmann::json& json, const Color& color)
    {
        json = color.ToString();
    }

    void Color::FromJson(const nlohmann::json& json, Color& color)
    {
        color.TryParse(json.get<std::string>());
    }

    void to_json(nlohmann::json& json, const Color& color)
    {
        Color::ToJson(json, color);
    }

    void from_json(const nlohmann::json& json, Color& color)
    {
        Color::FromJson(json, color);
    }
}
