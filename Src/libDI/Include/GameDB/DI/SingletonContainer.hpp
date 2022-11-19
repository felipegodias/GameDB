#ifndef GDB_LIB_DI_SINGLETON_CONTAINER_HPP
#define GDB_LIB_DI_SINGLETON_CONTAINER_HPP

#include <any>
#include <typeindex>

#include "GameDB/Container/UnorderedMap.hpp"
#include "GameDB/Memory/Pointers.hpp"

namespace GDB
{
    class SingletonContainer
    {
    public:
        static SingletonContainer* Global();

        template <typename Ty>
        Ty* GetInstance() const
        {
            const auto instancesIt = _instances.find(typeid(Ty));
            if (instancesIt == _instances.end())
            {
                return nullptr;
            }

            Ty* instance = static_cast<Ty*>(instancesIt->second.get());
            return instance;
        }

        template <typename Ty, typename ... ArgsTy,
                  std::enable_if_t<std::is_constructible_v<Ty, ArgsTy...>, bool>  = true>
        Ty* RegisterInstance(ArgsTy&& ... args)
        {
            auto instance = MakeUnique<Ty>(std::forward<ArgsTy>(args)...);
            Ty* instancePtr = instance.get();
            _instances.emplace(typeid(Ty), std::move(instance));
            return instancePtr;
        }

        template <typename Ty>
        void RemoveInstance()
        {
            const auto instancesIt = _instances.find(typeid(Ty));
            _instances.erase(instancesIt);
        }

    private:
        UnorderedMap<std::type_index, UniquePtr<void>> _instances;
    };
}

#endif // !GDB_LIB_DI_SINGLETON_CONTAINER_HPP
