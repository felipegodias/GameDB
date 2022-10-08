#ifndef PLUTO_GAME_DB_BASE_VALUE_H
#define PLUTO_GAME_DB_BASE_VALUE_H

namespace Pluto::GameDB
{
    /**
     * \brief 
     */
    class BaseValue
    {
    public:
        virtual ~BaseValue() = 0;

    protected:
        BaseValue() = default;
        BaseValue(const BaseValue& other) = default;
        BaseValue(BaseValue&& other) noexcept = default;
        BaseValue& operator=(const BaseValue& other) = default;
        BaseValue& operator=(BaseValue&& other) noexcept = default;
    };
}

#endif // ! PLUTO_GAME_DB_BASE_VALUE_H
