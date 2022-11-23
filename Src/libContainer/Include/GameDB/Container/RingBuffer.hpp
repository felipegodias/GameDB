#ifndef GDB_LIB_CONTAINER_RING_BUFFER_HPP
#define GDB_LIB_CONTAINER_RING_BUFFER_HPP

#include <array>
#include <cassert>
#include <cmath>
#include <type_traits>

namespace GDB
{
    /**
     * \brief 
     * \tparam Ty 
     * \tparam Capacity 
     */
    template <typename Ty, std::size_t Capacity>
    class RingBuffer
    {
    public:
        // TODO: Implement iterators

        RingBuffer()
            : _size(0),
              _front(0)
        {
        }

        /**
         * \brief 
         * \param idx 
         * \return 
         */
        [[nodiscard]] Ty& operator[](const std::size_t idx)
        {
            return At(idx);
        }

        /**
         * \brief
         * \param idx
         * \return
         */
        [[nodiscard]] const Ty& operator[](const std::size_t idx) const
        {
            return At(idx);
        }

        /**
         * \brief 
         * \return 
         */
        [[nodiscard]] std::size_t GetSize() const
        {
            return _size;
        }

        /**
         * \brief 
         * \param idx 
         * \return 
         */
        [[nodiscard]] Ty& At(size_t idx)
        {
            assert(idx < _size);
            idx = static_cast<std::size_t>(std::fmod(_front + idx, Capacity));
            return _array[idx];
        }

        /**
         * \brief
         * \param idx
         * \return
         */
        [[nodiscard]] const Ty& At(size_t idx) const
        {
            assert(idx < _size);
            idx = static_cast<std::size_t>(std::fmod(_front + idx, Capacity));
            return _array[idx];
        }

        /**
         * \brief 
         * \tparam ArgsTy 
         * \param args 
         * \return 
         */
        template <typename ... ArgsTy, std::enable_if_t<std::is_constructible_v<Ty, ArgsTy...>, bool>  = true>
        Ty& EmplaceBack(ArgsTy&& ... args)
        {
            if (_size < Capacity)
            {
                _array[_size] = Ty(std::forward<ArgsTy>(args)...);
                return _array[_size++];
            }

            _array[_front] = Ty(std::forward<ArgsTy>(args)...);
            Ty& element = _array[_front++];
            if (_front == _size)
            {
                _front = 0;
            }
            return element;
        }

        /**
         * \brief 
         * \param value 
         */
        void PushBack(const Ty& value)
        {
            EmplaceBack(value);
        }

        /**
         * \brief 
         * \param value 
         */
        void PushBack(Ty&& value)
        {
            EmplaceBack(std::move(value));
        }

    private:
        std::size_t _size;
        std::size_t _front;
        std::array<Ty, Capacity> _array;
    };
}

#endif // !GDB_LIB_CONTAINER_RING_BUFFER_HPP
