#ifndef GDB_LIB_MEMORY_TRACKED_ALLOCATOR_HPP
#define GDB_LIB_MEMORY_TRACKED_ALLOCATOR_HPP

#include <cstdlib>
#include <gsl/pointers>

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
        static gsl::owner<void*> Allocate(const std::size_t size)
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
        static void Deallocate(gsl::owner<void*> ptr, const std::size_t size)
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

#endif // !GDB_LIB_MEMORY_TRACKED_ALLOCATOR_HPP
