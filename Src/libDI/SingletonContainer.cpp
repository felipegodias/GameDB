#include "GameDB/DI/SingletonContainer.hpp"

namespace GDB
{
    SingletonContainer* SingletonContainer::Global()
    {
        static SingletonContainer singletonContainer;
        return &singletonContainer;
    }

    void SingletonContainer::Clear()
    {
        _instances.clear();
    }
}
