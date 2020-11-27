#include"RebelUnit.h"
#ifndef _LUKE_H_
#define _LUKE_H_

class Luke : public RebelUnit {
public:

    Luke() = delete;
    Luke(int a, int b, int index) : RebelUnit(a, b, index) {}//
    virtual ~Luke() = default;

    Luke(const Luke &) = delete;

    Luke &operator=(const Luke &) = delete;

    // virtual void move(const Square& square) {}

    virtual UnitType say_your_name() const { return LUKE; }
    virtual void print() {std::cout<<"L";}
    virtual void hello(){std::cout <<"LUKE";}
};

#endif // _LUKE_H_

