#ifndef GDB_LIBLET_MEMORY_MALLOC_ALLOCATOR_HPP
#define GDB_LIBLET_MEMORY_MALLOC_ALLOCATOR_HPP

#include <cstdlib>

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
        [[nodiscard]] static void* Allocate(std::size_t size);

        /**
         * \brief 
         * \param ptr 
         * \param size 
         */
        static void Deallocate(void* ptr, std::size_t size);

    private:
        MallocAllocator() = default;
    };
}

#endif // !GDB_LIBLET_MEMORY_MALLOC_ALLOCATOR_HPP
