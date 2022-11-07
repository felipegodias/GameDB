#ifndef PLUTO_GAME_DB_POINTERS_H
#define PLUTO_GAME_DB_POINTERS_H

#include <gsl/pointers>

namespace Pluto::GameDB
{
    template <typename Ty>
    using NotNull = gsl::not_null<Ty>;
}

#endif // ! PLUTO_GAME_DB_POINTERS_H
