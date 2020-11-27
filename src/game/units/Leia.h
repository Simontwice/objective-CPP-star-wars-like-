#include"RebelSoldier.h"
#ifndef _LEIA_H_
#define _LEIA_H_
class Leia : public RebelSoldier {
public:

    Leia() = delete;
    Leia(int a, int b, int p_index) : RebelSoldier(a, b, p_index) {}
    ~Leia() = default;

    Leia(const Leia &) = delete;

    Leia &operator=(const Leia &) = delete;

    // virtual void move(const Square& square) {}

    virtual UnitType say_your_name() const { return LEIA; }
    virtual void print(){std::cout<<"I";}
    virtual void hello(){std::cout <<"LEIA";}

};

#endif // _LEIA_H_
