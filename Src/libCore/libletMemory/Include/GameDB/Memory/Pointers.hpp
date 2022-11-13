#ifndef GDB_LIBLET_MEMORY_POINTERS_HPP
#define GDB_LIBLET_MEMORY_POINTERS_HPP

#include <memory>
#include <functional>

#include "GeneralAllocator.hpp"

namespace GDB
{
    template <typename Ty>
    using UniquePtr = std::unique_ptr<Ty, std::function<void(void*)>>;

    template <typename Ty, typename AllocatorTy = GeneralAllocator, typename ... ArgsTy, std::enable_if_t<
                  std::is_constructible_v<Ty, ArgsTy...>, int>  = 0>
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
}

#endif // !GDB_LIBLET_MEMORY_POINTERS_HPP
