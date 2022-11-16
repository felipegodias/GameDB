#ifndef GDB_LIB_MEMORY_MALLOC_ALLOCATOR_HPP
#define GDB_LIB_MEMORY_MALLOC_ALLOCATOR_HPP

#include <gsl/pointers>

namespace GDB
{
    /**
     * \brief 
     */
    class MallocAllocator
    {
    public:
        /**
         * \brief 
         * \param size 
         * \return 
         */
        [[nodiscard]] static gsl::owner<void*> Allocate(std::size_t size);

        /**
         * \brief 
         * \param ptr 
         * \param size 
         */
        static void Deallocate(gsl::owner<void*> ptr, std::size_t size);

    private:
        MallocAllocator() = default;
    };
}

#endif // !GDB_LIB_MEMORY_MALLOC_ALLOCATOR_HPP
