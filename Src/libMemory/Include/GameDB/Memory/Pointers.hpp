#ifndef GDB_LIB_MEMORY_POINTERS_HPP
#define GDB_LIB_MEMORY_POINTERS_HPP

#include <functional>
#include <memory>
#include <gsl/pointers>

#include "GeneralAllocator.hpp"

namespace GDB
{
    template <typename Ty>
    using NotNull = gsl::not_null<Ty>;

    template <typename Ty>
    using UniquePtr = std::unique_ptr<Ty, std::function<void(void*)>>;

    template <typename Ty>
    using SharedPtr = std::shared_ptr<Ty>;

    template <typename Ty>
    using WeakPtr = std::weak_ptr<Ty>;

    template <typename Ty, typename AllocatorTy = FreeListTypeAllocator<Ty, TrackedMallocAllocator>,
              typename ... ArgsTy, std::enable_if_t<std::is_constructible_v<Ty, ArgsTy...>, bool>  = true>
    UniquePtr<Ty> MakeUnique(ArgsTy&& ... args)
    {
        void* ptr = AllocatorTy::Allocate(sizeof(Ty));
        Ty* tyPtr = static_cast<Ty*>(ptr);
        new(tyPtr) Ty(std::forward<ArgsTy>(args)...);

        return UniquePtr<Ty>(
            tyPtr,
            [](void* ptrToDelete)
            {
                Ty* toFree = static_cast<Ty*>(ptrToDelete);
                toFree->~Ty();
                AllocatorTy::Deallocate(ptrToDelete, sizeof(Ty));
            }
        );
    }

    template <typename Ty, typename AllocatorTy = FreeListTypeAllocator<Ty, TrackedMallocAllocator>,
              typename ... ArgsTy, std::enable_if_t<std::is_constructible_v<Ty, ArgsTy...>, bool>  = true>
    SharedPtr<Ty> MakeShared(ArgsTy&& ... args)
    {
        void* ptr = AllocatorTy::Allocate(sizeof(Ty));
        Ty* tyPtr = static_cast<Ty*>(ptr);
        new(tyPtr) Ty(std::forward<ArgsTy>(args)...);

        return SharedPtr<Ty>(
            tyPtr,
            [](void* ptrToDelete)
            {
                Ty* toFree = static_cast<Ty*>(ptrToDelete);
                toFree->~Ty();
                AllocatorTy::Deallocate(ptrToDelete, sizeof(Ty));
            }
        );
    }
}

#endif // !GDB_LIB_MEMORY_POINTERS_HPP
