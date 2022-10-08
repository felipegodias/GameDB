#ifndef PLUTO_GAME_DB_STRING_VALUE_H
#define PLUTO_GAME_DB_STRING_VALUE_H

#include <string>

#include "BaseValue.hpp"

namespace Pluto::GameDB
{
    /**
     * \brief 
     */
    class StringValue final : public BaseValue
    {
    public:
        explicit StringValue(std::string value);
        StringValue(const StringValue& other) = default;
        StringValue(StringValue&& other) noexcept = default;
        StringValue& operator=(const StringValue& other) = default;
        StringValue& operator=(StringValue&& other) noexcept = default;
        ~StringValue() override;

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] std::string& GetValue();

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] const std::string& GetValue() const;

        /**
         * \brief 
         * \param value 
         */
        void SetValue(std::string value);

    private:
        /**
         * \brief 
         */
        std::string _value;
    };
}

#endif // ! PLUTO_GAME_DB_STRING_VALUE_H
