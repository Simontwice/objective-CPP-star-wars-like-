#include"EmpireUnit.h"
#ifndef _CHANCELLOR_H_
#define _CHANCELLOR_H_
class Chancellor : public EmpireUnit {
public:

    Chancellor() = delete;
    Chancellor(int a, int b, int ind) : EmpireUnit(a, b, ind){}

    Chancellor(const Chancellor &) = delete;

    Chancellor &operator=(const Chancellor &) = delete;

    // virtual void move(const Square& square) {}

    virtual UnitType say_your_name() const { return CHANCELLOR; }
    virtual void print(){std::cout<<"C";}
    virtual int get_visited(Unit* unit)
    {
        switch(unit->get_affiliation())
        {
            case REBEL:
                {
                    if(unit->say_your_name() == LEIA )
                    {
                        return 3; break;
                    }
                    else {return 2; break;}
                }

            case EMPIRE: return -1;break;
            default: return -1;break;
        }
    }

    virtual void hello(){std::cout <<"CHANCELLOR";}

};
#endif
