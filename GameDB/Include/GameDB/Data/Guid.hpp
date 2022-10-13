#ifndef PLUTO_GAME_DB_GUID_H
#define PLUTO_GAME_DB_GUID_H

namespace Pluto::GameDB
{
    /**
     * \brief 
     */
    class Guid final
    {
    public:
        using ValueType = unsigned int;

        explicit Guid(ValueType value);

        bool operator==(const Guid& rhs) const;
        bool operator!=(const Guid& rhs) const;

        static Guid Random();

        static const Guid Empty;

    private:
        ValueType _value;
    };
}

#endif // ! PLUTO_GAME_DB_GUID_H
