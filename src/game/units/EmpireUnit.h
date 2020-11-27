#include"Unit.h"
#ifndef _EMPIRE_UHIT_H_
#define _EMPIRE_UHIT_H_

class EmpireUnit : public Unit {
private:
    int index;
public:

    EmpireUnit() = delete;

    EmpireUnit(int a, int b, int pindex) : Unit(a, b),index(pindex)  {}
    virtual ~EmpireUnit() {}

    EmpireUnit(const EmpireUnit &) = delete;

    EmpireUnit &operator=(const EmpireUnit &) = delete;

//    virtual void move(const Square& square) = 0;

    virtual UnitType say_your_name() const = 0;

    virtual Affiliation get_affiliation() const { return EMPIRE; }
    virtual int get_visited(Unit* unit)
    {
        switch(unit->get_affiliation())
        {
            case REBEL: return 2; break;
            case EMPIRE: return -1;break;
            default: return -1;break;
        }
    }

    virtual void hello()=0;

};

#endif // _EMPIRE_UHIT_H_


