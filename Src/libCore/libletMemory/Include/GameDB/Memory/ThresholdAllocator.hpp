#ifndef GDB_LIBLET_MEMORY_THRESHOLD_ALLOCATOR_HPP
#define GDB_LIBLET_MEMORY_THRESHOLD_ALLOCATOR_HPP

#include <cstdlib>
#include <gsl/pointers>

namespace GDB
{
    /**
     * \brief 
     * \tparam Threshold 
     * \tparam SmallerAllocatorTy
     * \tparam GreaterAllocatorTy 
     */
    template <std::size_t Threshold, typename SmallerAllocatorTy, typename GreaterAllocatorTy>
    class ThresholdAllocator
    {
    public:
        /**
         * \brief 
         * \param size 
         * \return 
         */
        static gsl::owner<void*> Allocate(const std::size_t size)
        {
            if (size > Threshold)
            {
                return GreaterAllocatorTy::Allocate(size);
            }

            return SmallerAllocatorTy::Allocate(size);
        }

        /**
         * \brief 
         * \param ptr 
         * \param size 
         */
        static void Deallocate(gsl::owner<void*> ptr, const std::size_t size)
        {
            if (size > Threshold)
            {
                return GreaterAllocatorTy::Deallocate(ptr, size);
            }

            return SmallerAllocatorTy::Deallocate(ptr, size);
        }

    private:
        ThresholdAllocator() = default;
    };
}

#endif // !GDB_LIBLET_MEMORY_THRESHOLD_ALLOCATOR_HPP
