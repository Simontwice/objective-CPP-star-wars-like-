#include"Robot.h"
#ifndef _VADER_H_
#define _VADER_H_

class Vader : public Robot {
public:

    Vader() = delete;
    Vader(int a, int b, int ind) : Robot(a, b,ind) {
    }
    virtual ~Vader() = default;

    Vader(const Vader &) = delete;

    Vader &operator=(const Vader &) = delete;

    // virtual void move(const Square& square) {}

    virtual UnitType say_your_name() const { return VADER; }
    virtual void print(){std::cout<<"V";}
    virtual int get_visited(Unit* unit)
    {
        switch(unit->get_affiliation())
        {
            case REBEL:
                if(unit->say_your_name()==LUKE)
                {
                    return 1; break;
                }
                else {return 2;break;}
            case EMPIRE: return -1;break;
            default: return -1;break;
        }
    }
    virtual void hello(){std::cout <<"VADER";}

};

#endif // _ROBOT_H_

