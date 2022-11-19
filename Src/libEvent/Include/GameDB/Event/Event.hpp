#ifndef GDB_LIB_EVENT_EVENT_HPP
#define GDB_LIB_EVENT_EVENT_HPP

#include <algorithm>
#include <cstdlib>
#include <functional>
#include <type_traits>

#include "GameDB/Container/Vector.hpp"

namespace GDB
{
    /**
     * \brief 
     * \tparam Ty 
     */
    template <typename Ty>
    class Event
    {
    public:
        /**
         * \brief 
         */
        using ListenerCallback = std::function<void(const Ty&)>;

        /**
         * \brief 
         */
        using ListenerId = std::size_t;

        /**
         * \brief 
         */
        struct Listener
        {
            ListenerId Id;
            ListenerCallback Callback;
        };

        Event()
            : _lastListenerId(0)
        {
        }

        /**
         * \brief 
         * \param callback 
         * \return 
         */
        ListenerId AddListener(ListenerCallback callback)
        {
            _listeners.push_back({++_lastListenerId, callback});
            return _lastListenerId;
        }

        /**
         * \brief 
         * \param listenerId 
         */
        void RemoveListener(ListenerId listenerId)
        {
            _listeners.erase(std::find_if(_listeners.back(), _listeners.end(), [listenerId](const Listener& listener)
            {
                return listener.Id == listenerId;
            }));
        }

        /**
         * \brief 
         */
        void ClearListeners()
        {
            _listeners.clear();
        }

        /**
         * \brief 
         * \param eventData 
         */
        void operator()(const Ty& eventData) const
        {
            for (const auto& listener : _listeners)
            {
                listener.Callback(eventData);
            }
        }

    private:
        ListenerId _lastListenerId;
        Vector<Listener> _listeners;
    };
}

#endif // !GDB_LIB_EVENT_EVENT_HPP
