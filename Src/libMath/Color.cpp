#include "GameDB/Math/Color.hpp"

#include <iomanip>

#include "GameDB/Container/StringStream.hpp"

namespace GDB
{
    namespace
    {
        constexpr float minColorValue = 0.0F;
        constexpr float maxColorValue = 255.0F;
        constexpr unsigned int redChannelMask = 0xff000000;
        constexpr unsigned int redChannelShift = 24;
        constexpr unsigned int greenChannelMask = 0x00ff0000;
        constexpr unsigned int greenChannelShift = 16;
        constexpr unsigned int blueChannelMask = 0x0000ff00;
        constexpr unsigned int blueChannelShift = 8;
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

    bool Color::TryParse(const std::string_view str)
    {
        // Validate!

        [[maybe_unused]] char hashTag = '#';
        unsigned int color = 0;
        StringStream iss(str.data());
        iss >> hashTag >> std::hex >> color;

        r = normalizeColorChannel(static_cast<uint8_t>((color & redChannelMask) >> redChannelShift));
        g = normalizeColorChannel(static_cast<uint8_t>((color & greenChannelMask) >> greenChannelShift));
        b = normalizeColorChannel(static_cast<uint8_t>((color & blueChannelMask) >> blueChannelShift));
        a = normalizeColorChannel(static_cast<uint8_t>((color & alphaChannelMask) >> alphaChannelShift));
        return true;
    }

    String Color::ToString() const
    {
        const unsigned int color =
            (static_cast<uint8_t>(r * maxColorValue) << redChannelShift) +
            (static_cast<uint8_t>(g * maxColorValue) << greenChannelShift) +
            (static_cast<uint8_t>(b * maxColorValue) << blueChannelShift) +
            (static_cast<uint8_t>(a * maxColorValue) << alphaChannelShift);

        constexpr int hexLength = 8;
        StringStream strStream;
        strStream << "#" << std::setw(hexLength) << std::setfill('0') << std::hex << color;
        return strStream.str();
    }
}
