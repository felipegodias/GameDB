#ifndef PLUTO_GAME_DB_TABLE_H
#define PLUTO_GAME_DB_TABLE_H

#include <gsl/pointers>

#include "Schema.hpp"

namespace Pluto::GameDB
{
    /**
     * \brief 
     */
    class Table final
    {
    public:
        Table(Guid instanceId, std::unique_ptr<Schema> schema);

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] const Guid& GetInstanceId() const;

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] gsl::not_null<Schema*> GetSchema() const;

    private:
        /**
         * \brief 
         */
        Guid _instanceId;

        /**
         * \brief 
         */
        std::unique_ptr<Schema> _schema;
    };
}

#endif // ! PLUTO_GAME_DB_TABLE_H
