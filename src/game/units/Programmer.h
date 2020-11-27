#include"RebelUnit.h"
#ifndef _PROGRAMMER_H_
#define _PROGRAMMER_H_

class Programmer : public RebelUnit {
public:

    Programmer() = delete;
    Programmer(int a, int b, int index) : RebelUnit(a, b, index) {}
    ~Programmer() = default;

    Programmer(const Programmer &) = delete;

    Programmer &operator=(const Programmer &) = delete;

    // virtual void move(const Square& square) {}

    virtual UnitType say_your_name() const { return PROGRAMMER; }
    virtual void print() {std::cout<<"P";}
    virtual void hello(){std::cout <<"PROGRAMMER";}

};

#endif // _PROGRAMMER_H_
