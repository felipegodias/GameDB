#ifndef PLUTO_GAME_DB_BASE_VALUE_H
#define PLUTO_GAME_DB_BASE_VALUE_H

#include "BaseType.hpp"

namespace Pluto::GameDB
{
    /**
     * \brief 
     */
    class BaseValue
    {
    public:
        //explicit BaseValue(const BaseType& type);
        virtual ~BaseValue() = 0;

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] const BaseType& GetType() const;

    protected:
        BaseValue();
        BaseValue(const BaseValue& other) = default;
        BaseValue(BaseValue&& other) noexcept = default;
        BaseValue& operator=(const BaseValue& other) = default;
        BaseValue& operator=(BaseValue&& other) noexcept = default;

    private:
        const BaseType* _type;
    };
}

#endif // ! PLUTO_GAME_DB_BASE_VALUE_H
