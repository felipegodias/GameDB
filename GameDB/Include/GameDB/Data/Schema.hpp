#ifndef PLUTO_GAME_DB_SCHEMA_H
#define PLUTO_GAME_DB_SCHEMA_H

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
        Schema(Guid instanceId, std::vector<std::unique_ptr<Field>> fields);

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] const Guid& GetInstanceId() const;

        /**
         * \brief
         * \param field
         */
        void AddField(std::unique_ptr<Field> field);

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
        [[nodiscard]] const std::vector<std::unique_ptr<Field>>& GetFields() const;

        /**
         * \brief 
         * \param instanceId 
         * \return 
         */
        [[nodiscard]] Field* GetField(const Guid& instanceId) const;

        /**
         * \brief 
         * \param name 
         * \return 
         */
        [[nodiscard]] Field* GetField(std::string_view name) const;

    private:
        /**
         * \brief 
         */
        Guid _instanceId;

        /**
         * \brief 
         */
        std::vector<std::unique_ptr<Field>> _fields;
    };
}

#endif // ! PLUTO_GAME_DB_SCHEMA_H
