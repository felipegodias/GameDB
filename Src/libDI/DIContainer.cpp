#include "GameDB/DI/DIContainer.hpp"

#include <stdexcept>
#include <utility>

namespace GDB
{
    DIContainer* DIContainer::Global()
    {
        static DIContainer diContainer;
        return &diContainer;
    }

    DIContainer::DIContainer()
        : _parent(nullptr)
    {
    }

    DIContainer::DIContainer(DIContainer* parent)
        : _parent(parent)
    {
    }

    std::any DIContainer::FindFactory(const std::type_index factoryType) const
    {
        const auto factoriesIt = _factories.find(factoryType);
        if (factoriesIt != _factories.end())
        {
            return factoriesIt->second;
        }

        if (_parent == nullptr)
        {
            throw std::runtime_error("");
        }

        return _parent->FindFactory(factoryType);
    }

    void DIContainer::RegisterFactory(const std::type_index factoryType, std::any factory)
    {
        _factories[factoryType] = std::move(factory);
    }

    void DIContainer::RemoveFactory(const std::type_index factoryType)
    {
        const auto factoriesIt = _factories.find(factoryType);
        if (factoriesIt == _factories.end())
        {
            throw std::runtime_error("");
        }

        _factories.erase(factoriesIt);
    }

    void DIContainer::Clear()
    {
        _factories.clear();
    }
}
