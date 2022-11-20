#ifndef GDB_LIB_MATH_COLOR_HPP
#define GDB_LIB_MATH_COLOR_HPP

#include "GameDB/Container/String.hpp"

namespace GDB
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
        [[nodiscard]] String ToString() const;
    };
}

#endif // !GDB_LIB_MATH_VECTOR_2_HPP
