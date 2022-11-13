#ifndef PLUTO_GAME_DB_EDITOR_APPLICATION_H
#define PLUTO_GAME_DB_EDITOR_APPLICATION_H

#include <GameDB/DI/DIContainer.hpp>

namespace Pluto::GameDB::Editor
{
    class Application
    {
    public:
        void Run();

    private:
        DIContainer _diContainer;
    };
}

#endif // !PLUTO_GAME_DB_EDITOR_APPLICATION_H
