#ifndef PLUTO_GAME_DB_SCHEMA_H
#define PLUTO_GAME_DB_SCHEMA_H

#include <optional>
#include <vector>

#include "Field.hpp"

namespace Pluto::GameDB
{
    /**
     * \brief 
     */
    class Schema
    {
    public:
        Schema(Guid instanceId, std::vector<Field> fields);

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] const Guid& GetInstanceId() const;

        /**
         * \brief
         * \param field
         */
        void AddField(Field field);

        /**
         * \brief
         * \param instanceId
         * \return
         */
        bool RemoveField(const Guid& instanceId);

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] const std::vector<Field>& GetFields() const;

        /**
         * \brief 
         * \param instanceId 
         * \return 
         */
        [[nodiscard]] std::optional<std::reference_wrapper<const Field>> GetField(const Guid& instanceId) const;

        /**
         * \brief
         * \param instanceId
         * \return
         */
        [[nodiscard]] std::optional<std::reference_wrapper<Field>> GetField(const Guid& instanceId);

        /**
         * \brief 
         * \param name 
         * \return 
         */
        [[nodiscard]] std::optional<std::reference_wrapper<const Field>> GetField(std::string_view name) const;

        /**
         * \brief
         * \param name
         * \return
         */
        [[nodiscard]] std::optional<std::reference_wrapper<Field>> GetField(std::string_view name);

    private:
        /**
         * \brief 
         */
        Guid _instanceId;

        /**
         * \brief 
         */
        std::vector<Field> _fields;
    };
}

#endif // ! PLUTO_GAME_DB_SCHEMA_H
