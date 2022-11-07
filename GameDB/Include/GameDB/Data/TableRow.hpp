#ifndef PLUTO_GAME_DB_TABLE_ROW_H
#define PLUTO_GAME_DB_TABLE_ROW_H

#include <memory>
#include <unordered_map>

#include "BaseValue.hpp"
#include "Field.hpp"
#include "Guid.hpp"

namespace Pluto::GameDB
{
    /**
     * \brief 
     */
    class TableRow final
    {
    public:
        void SetValue(const Field& field, std::unique_ptr<BaseValue> value);
        [[nodiscard]] BaseValue* GetValue(const Field& field) const;

    private:
        Guid _instanceId;
        std::unordered_map<Guid, std::unique_ptr<BaseValue>> _values;
    };
}

#endif // ! PLUTO_GAME_DB_TABLE_ROW_H
