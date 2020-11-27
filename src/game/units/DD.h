#include"RebelUnit.h"
#ifndef _DD_H_
#define _DD_H_

class DD : public RebelUnit {
public:

    DD() = delete;
    DD(int a, int b, int p_index) : RebelUnit(a, b, p_index) {}
    virtual ~DD() = default;

    DD(const DD &) = delete;

    DD &operator=(const DD &) = delete;

    // virtual void move(const Square& square) {}

    virtual UnitType say_your_name() const {
        return DETECTOR;
    }
    virtual void print(){std::cout<<"d";}
    virtual void hello(){std::cout <<"DETECTOR";}

};
#endif // _DD_H_
