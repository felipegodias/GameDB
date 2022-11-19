#ifndef GDB_LIB_DI_DI_CONTAINER_HPP
#define GDB_LIB_DI_DI_CONTAINER_HPP

#include <any>
#include <functional>
#include <typeindex>

#include "GameDB/Container/UnorderedMap.hpp"

namespace GDB
{
    /**
     * \brief 
     */
    class DIContainer
    {
    public:
        template <typename Ty>
        using FactoryNoArg = std::function<Ty(const DIContainer&)>;

        template <typename Ty, typename ArgTy>
        using FactoryWithArg = std::function<Ty(const DIContainer&, const ArgTy&)>;

        DIContainer();

        explicit DIContainer(DIContainer* parent);

        /**
         * \brief 
         * \return 
         */
        static DIContainer* Global();

        /**
         * \brief 
         * \tparam Ty 
         * \return 
         */
        template <typename Ty>
        [[nodiscard]] Ty Resolve() const
        {
            using Factory = FactoryNoArg<Ty>;
            auto factory = std::any_cast<Factory>(FindFactory(typeid(Factory)));
            return factory(*this);
        }

        /**
         * \brief 
         * \tparam Ty 
         * \tparam ArgTy 
         * \param arg 
         * \return 
         */
        template <typename Ty, typename ArgTy>
        [[nodiscard]] Ty Resolve(const ArgTy& arg) const
        {
            using Factory = FactoryWithArg<Ty, ArgTy>;
            auto factory = std::any_cast<Factory>(FindFactory(typeid(Factory)));
            return factory(*this, arg);
        }

        /**
         * \brief 
         * \tparam Ty 
         * \param factory 
         */
        template <typename Ty>
        void RegisterFactory(FactoryNoArg<Ty> factory)
        {
            RegisterFactory(typeid(FactoryNoArg<Ty>), std::move(factory));
        }

        /**
         * \brief 
         * \tparam Ty 
         * \tparam ArgTy 
         * \param factory 
         */
        template <typename Ty, typename ArgTy>
        void RegisterFactory(FactoryWithArg<Ty, ArgTy> factory)
        {
            RegisterFactory(typeid(FactoryWithArg<Ty, ArgTy>), std::move(factory));
        }

        /**
         * \brief 
         * \tparam Ty 
         */
        template <typename Ty>
        void RemoveFactory()
        {
            RemoveFactory(typeid(FactoryNoArg<Ty>));
        }

        /**
         * \brief 
         * \tparam Ty 
         * \tparam ArgTy 
         */
        template <typename Ty, typename ArgTy>
        void RemoveFactory()
        {
            RemoveFactory(typeid(FactoryWithArg<Ty, ArgTy>));
        }

    private:
        [[nodiscard]] std::any FindFactory(std::type_index factoryType) const;
        void RegisterFactory(std::type_index factoryType, std::any factory);
        void RemoveFactory(std::type_index factoryType);

        DIContainer* _parent;
        UnorderedMap<std::type_index, std::any> _factories;
    };
}

#endif // !GDB_LIB_DI_DI_CONTAINER_HPP
