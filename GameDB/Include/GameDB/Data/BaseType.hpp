#ifndef PLUTO_GAME_DB_BASE_TYPE_H
#define PLUTO_GAME_DB_BASE_TYPE_H

#include <memory>
#include <string_view>

namespace Pluto::GameDB
{
    class BaseValue;

    /**
     * \brief 
     */
    class BaseType
    {
    public:
        virtual ~BaseType() = 0;

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] virtual std::string_view GetName() const = 0;

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] virtual std::unique_ptr<BaseValue> InstantiateValue() const = 0;

    protected:
        BaseType() = default;
        BaseType(const BaseType& other) = default;
        BaseType(BaseType&& other) noexcept = default;
        BaseType& operator=(const BaseType& other) = default;
        BaseType& operator=(BaseType&& other) noexcept = default;
    };
}

#endif // ! PLUTO_GAME_DB_BASE_TYPE_H
