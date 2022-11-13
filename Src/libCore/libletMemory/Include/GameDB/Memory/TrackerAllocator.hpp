#ifndef GDB_LIBLET_MEMORY_TRACKED_ALLOCATOR_HPP
#define GDB_LIBLET_MEMORY_TRACKED_ALLOCATOR_HPP

#include <cstdlib>

namespace GDB
{
    /**
     * \brief 
     * \tparam AllocatorTy 
     */
    template <typename AllocatorTy>
    class TrackedAllocator
    {
    public:
        /**
         * \brief 
         * \param size 
         * \return 
         */
        static void* Allocate(const std::size_t size)
        {
            void* ptr = AllocatorTy::Allocate(size);
            _allocated += size;
            return ptr;
        }

        /**
         * \brief 
         * \param ptr 
         * \param size 
         */
        static void Deallocate(void* ptr, const std::size_t size)
        {
            _allocated -= size;
            AllocatorTy::Deallocate(ptr, size);
        }

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] static std::size_t GetAllocated()
        {
            return _allocated;
        }

    private:
        TrackedAllocator() = default;

        inline static std::size_t _allocated = 0;
    };
}

#endif // !GDB_LIBLET_MEMORY_TRACKED_ALLOCATOR_HPP
