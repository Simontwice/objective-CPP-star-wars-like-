#ifndef _PAIR_H_
#define _PAIR_H_

#include <iostream>

class Pair {
public:
    int x;
    int y;

    Pair(int a=-1, int b=-1) : x(a), y(b) {}

    ~Pair() = default;
    void print(){std::cout<<"\n"<<x<<" "<<y<<"\n";}
};
#endif // _PAIR_H_




