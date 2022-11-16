#ifndef GDB_LIB_MEMORY_FREE_LIST_ALLOCATOR_HPP
#define GDB_LIB_MEMORY_FREE_LIST_ALLOCATOR_HPP

#include <cmath>
#include <vector>
#include <gsl/pointers>

#include "StlContainerAllocator.hpp"

namespace GDB
{
    /**
     * \brief 
     * \tparam BlockSize 
     * \tparam AllocatorTy 
     */
    template <size_t BlockSize, typename AllocatorTy>
    class FreeListAllocator
    {
    public:
        template <typename Ty>
        using Vector = std::vector<Ty, StlContainerAllocator<Ty, AllocatorTy>>;

        /**
         * \brief
         */
        struct Buffer
        {
            gsl::owner<std::byte*> Block;
        };

        /**
         * \brief 
         */
        struct FreeBlock
        {
            FreeBlock* Next;
        };

        /**
         * \brief 
         * \param size 
         * \return 
         */
        static gsl::owner<void*> Allocate([[maybe_unused]] std::size_t size)
        {
            if (_freeBlock == nullptr)
            {
                // Resize buffer.
                const size_t elements = static_cast<size_t>(std::pow(2, _buffers.size()));
                auto block = static_cast<std::byte*>(AllocatorTy::Allocate(elements * BlockSize));
                _buffers.push_back({ block });
                for (long long i = elements - 1; i >= 0; --i)
                {
                    Deallocate(block + i * BlockSize, BlockSize);
                }
            }

            FreeBlock* ptr = _freeBlock;
            _freeBlock = _freeBlock->Next;
            return ptr;
        }

        /**
         * \brief 
         * \param ptr 
         * \param size 
         */
        static void Deallocate(const gsl::owner<void*> ptr, [[maybe_unused]] std::size_t size)
        {
            FreeBlock* block = static_cast<FreeBlock*>(ptr);
            block->Next = _freeBlock;
            _freeBlock = block;
        }

    private:
        FreeListAllocator() = default;

        inline static Vector<Buffer> _buffers;
        inline static FreeBlock* _freeBlock = nullptr;
    };

    template <typename Ty, typename AllocatorTy>
    using FreeListTypeAllocator = FreeListAllocator<sizeof(Ty), AllocatorTy>;
}

#endif // !GDB_LIB_MEMORY_FREE_LIST_ALLOCATOR_HPP
