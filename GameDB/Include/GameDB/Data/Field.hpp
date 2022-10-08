#ifndef PLUTO_GAME_DB_FIELD_H
#define PLUTO_GAME_DB_FIELD_H

#include <memory>
#include <string>

#include "Guid.hpp"

namespace Pluto::GameDB
{
    class BaseType;

    /**
     * \brief 
     */
    class Field final
    {
    public:
        Field();
        Field(Guid instanceId, std::string name, std::unique_ptr<BaseType> type);

        Field(const Field& other) = delete;
        Field(Field&& other) noexcept = default;
        Field& operator=(const Field& other) = delete;
        Field& operator=(Field&& other) noexcept = default;
        ~Field();

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] const Guid& GetInstanceId() const;

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] const std::string& GetName() const;

        /**
         * \brief 
         * \param name 
         */
        void SetName(std::string name);

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] const BaseType& GetType() const;

        /**
         * \brief
         * \return
         */
        [[nodiscard]] BaseType& GetType();

    private:
        /**
         * \brief 
         */
        Guid _instanceId;

        /**
         * \brief 
         */
        std::string _name;

        /**
         * \brief 
         */
        std::unique_ptr<BaseType> _type;
    };
}

#endif // ! PLUTO_GAME_DB_FIELD_H
