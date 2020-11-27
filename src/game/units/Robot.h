#include"EmpireUnit.h"
#ifndef _ROBOT_H_
#define _ROBOT_H_

class Robot : public EmpireUnit {
public:

    Robot() = delete;
    Robot(int a, int b, int p_index) : EmpireUnit(a, b, p_index) {}
    virtual ~Robot() = default;

    Robot(const Robot &) = delete;

    Robot &operator=(const Robot &) = delete;

    // virtual void move(const Square& square) {}

    virtual UnitType say_your_name() const { return ROBOT; }
    virtual void print(){std::cout<<"R";}
    virtual int get_visited(Unit* unit)
    {
        switch(unit->get_affiliation())
        {
            case REBEL:
                if(unit->say_your_name()==PROGRAMMER)
                {
                    return 1; break;
                }
                else {return 2;break;}
            case EMPIRE: return -1;break;
            default: return -1;break;
        }
    }
    virtual void hello(){std::cout <<"ROBOT";}
};
#endif // _ROBOT_H_
