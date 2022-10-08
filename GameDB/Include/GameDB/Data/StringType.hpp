#ifndef PLUTO_GAME_DB_STRING_TYPE_H
#define PLUTO_GAME_DB_STRING_TYPE_H

#include "BaseType.hpp"

namespace Pluto::GameDB
{
    /**
     * \brief 
     */
    class StringType final : public BaseType
    {
    public:
        StringType() = default;
        StringType(const StringType& other) = default;
        StringType(StringType&& other) noexcept = default;
        StringType& operator=(const StringType& other) = default;
        StringType& operator=(StringType&& other) noexcept = default;
        ~StringType() override;

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] std::string_view GetName() const override;

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] std::unique_ptr<BaseValue> InstantiateValue() const override;
    };
}

#endif // ! PLUTO_GAME_DB_STRING_TYPE_H
