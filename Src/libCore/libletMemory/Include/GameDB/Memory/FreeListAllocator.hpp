#ifndef GDB_LIBLET_MEMORY_FREE_LIST_ALLOCATOR_HPP
#define GDB_LIBLET_MEMORY_FREE_LIST_ALLOCATOR_HPP

#include <cmath>
#include <vector>

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
            std::size_t Elements;
            std::byte* Block;
        };

        /**
         * \brief 
         * \param size 
         * \return 
         */
        static void* Allocate([[maybe_unused]] std::size_t size)
        {
            if (_freeQueue.empty())
            {
                _freeQueue.push_back(1);
            }

            const std::size_t freeIdx = _freeQueue.back();
            _freeQueue.pop_back();

            if (_freeQueue.empty())
            {
                _freeQueue.push_back(freeIdx + 1);
            }

            const auto buffersIdx = static_cast<std::size_t>(std::log2(freeIdx));
            if (_buffers.size() <= buffersIdx)
            {
                size_t elements = static_cast<std::size_t>(std::pow(2, buffersIdx));
                auto* block = static_cast<std::byte*>(AllocatorTy::Allocate(elements * BlockSize));
                _buffers.push_back({ elements, block });
            }

            const size_t idx = freeIdx - _buffers[buffersIdx].Elements;
            void* ptr = &_buffers[buffersIdx].Block[idx * BlockSize];
            return ptr;
        }

        /**
         * \brief 
         * \param ptr 
         * \param size 
         */
        static void Deallocate(void* ptr, [[maybe_unused]] std::size_t size)
        {
            auto bytePtr = static_cast<std::byte*>(ptr);
            for (size_t i = 0 ; i < _buffers.size(); ++i)
            {
                if (_buffers[i].Block <= bytePtr && bytePtr <= _buffers[i].Block + _buffers[i].Elements * BlockSize)
                {
                    const size_t idx = (bytePtr - _buffers[i].Block) / BlockSize;
                    const size_t freeIdx = static_cast<size_t>(std::pow(2, i)) + idx;
                    _freeQueue.push_back(freeIdx);
                }
            }
        }

    private:
        FreeListAllocator() = default;

        inline static Vector<Buffer> _buffers;
        inline static Vector<std::size_t> _freeQueue;
    };

    template <typename Ty, typename AllocatorTy>
    using FreeListTypeAllocator = FreeListAllocator<sizeof(Ty), AllocatorTy>;
}

#endif // !GDB_LIBLET_MEMORY_FREE_LIST_ALLOCATOR_HPP
