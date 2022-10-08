#ifndef PLUTO_GAME_DB_GUID_H
#define PLUTO_GAME_DB_GUID_H

namespace Pluto::GameDB
{
    class Guid final
    {
    public:
        explicit Guid(size_t value);

        bool operator==(const Guid& rhs) const;
        bool operator!=(const Guid& rhs) const;

        static Guid Random();

        static const Guid Empty;

    private:
        size_t _value;
    };
}

#endif // ! PLUTO_GAME_DB_GUID_H
