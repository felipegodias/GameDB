#ifndef GDB_LIBLET_MEMORY_STL_CONTAINER_ALLOCATOR_HPP
#define GDB_LIBLET_MEMORY_STL_CONTAINER_ALLOCATOR_HPP

#include <cstdlib>

namespace GDB
{
    /**
     * \brief 
     * \tparam Ty 
     * \tparam AllocatorTy 
     */
    template <typename Ty, class AllocatorTy>
    class StlContainerAllocator
    {
    public:
        using value_type = Ty;

        StlContainerAllocator() noexcept = default;

        template <class BinderTy>
        StlContainerAllocator(const StlContainerAllocator<BinderTy, AllocatorTy>&) noexcept
        {
        }

        /**
         * \brief 
         * \param n 
         * \return 
         */
        value_type* allocate(const std::size_t n)
        {
            void* block = AllocatorTy::Allocate(sizeof(Ty) * n);
            return static_cast<value_type*>(block);
        }

        /**
         * \brief 
         * \param ptr 
         * \param n 
         */
        void deallocate(value_type* ptr, [[maybe_unused]] const std::size_t n)
        {
            AllocatorTy::Deallocate(ptr, sizeof(value_type) * n);
        }
    };
}

#endif // !GDB_LIBLET_MEMORY_STL_CONTAINER_ALLOCATOR_HPP