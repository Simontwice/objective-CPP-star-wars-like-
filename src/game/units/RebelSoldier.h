#include "RebelUnit.h"
#include "../misc/Includes.h"
#ifndef _REBEL_SOLDIER_H_
#define _REBEL_SOLDIER_H_

class RebelSoldier : public RebelUnit {
public:

    RebelSoldier() = delete;
    RebelSoldier(int a, int b, int p_index) : RebelUnit(a, b, p_index) {}
    ~RebelSoldier() = default;

    RebelSoldier(const RebelSoldier &) = delete;

    RebelSoldier &operator=(const RebelSoldier &) = delete;

    virtual UnitType say_your_name() const { return REBEL_SOLDIER; }
    virtual void print(){std::cout<<"S";}
    virtual void hello(){std::cout <<"SOLDIER";}
};

#endif // _REBEL_SOLDIER_H_
