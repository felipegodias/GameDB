#ifndef GDB_LIB_DI_DI_CONTAINER_H
#define GDB_LIB_DI_DI_CONTAINER_H

#include <any>
#include <functional>
#include <optional>
#include <stdexcept>
#include <typeindex>
#include <unordered_map>

namespace GDB
{
    /**
     * \brief 
     */
    class DIContainer
    {
    public:
        template <typename Ty>
        using Factory = std::function<Ty(const DIContainer&)>;

        DIContainer()
            : _parent(nullptr)
        {
        }

        explicit DIContainer(DIContainer* parent)
            : _parent(parent)
        {
        }

        /**
         * \brief 
         * \tparam Ty 
         * \return 
         */
        template <typename Ty>
        std::optional<Ty> Resolve() const
        {
            const auto factoriesIt = _factories.find(typeid(Ty));
            if (factoriesIt == _factories.end())
            {
                if (_parent == nullptr)
                {
                    // TODO: LOG!
                    return std::nullopt;
                }

                return _parent->Resolve<Ty>();
            }

            Factory<Ty> factory = std::any_cast<Factory<Ty>>(factoriesIt->second);
            return factory(*this);
        }

        /**
         * \brief 
         * \tparam Ty 
         * \param factory 
         */
        template <typename Ty>
        void RegisterFactory(Factory<Ty> factory)
        {
            _factories[typeid(Ty)] = factory;
        }

        /**
         * \brief 
         * \tparam Ty 
         */
        template <typename Ty>
        void RemoveFactory()
        {
            const auto factoriesIt = _factories.find(typeid(Ty));
            if (factoriesIt == _factories.end())
            {
                throw std::runtime_error("");
            }

            _factories.erase(factoriesIt);
        }

    private:
        DIContainer* _parent;
        std::unordered_map<std::type_index, std::any> _factories;
    };
}

#endif // !GDB_LIB_DI_DI_CONTAINER_H
