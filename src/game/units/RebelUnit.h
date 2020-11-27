#include"Unit.h"
#ifndef _REBEL_UNIT_H_
#define _REBEL_UNIT_H_

class RebelUnit : public Unit {
private:
    int index;

public:

    RebelUnit() = delete;
    RebelUnit(int a, int b, int p_index) : Unit(a, b), index(p_index) {}
    virtual ~RebelUnit() {}

    RebelUnit(const RebelUnit &) = delete;

    RebelUnit &operator=(const RebelUnit &) = delete;

    virtual UnitType say_your_name() const = 0;

    virtual Affiliation get_affiliation() const { return REBEL; }

    int get_index() {
        return index;
    }
    virtual int get_visited(Unit* unit)
    {
        switch(unit->get_affiliation())
        {
            case REBEL: return -1; break;
            case EMPIRE: return 1;break;
            default: return -1;break;
        }
    }

    virtual void hello()=0;

};

#endif // _REBEL_UNIT_H_
