#ifndef _NEXT_SPOT_H_
#define _NEXT_SPOT_H_

#include"Pair.h"

Pair NextSpot(int szer, int wys, int next)
{
    Pair a=Pair(next / szer + 1, next % szer + 1);
    return a;
}




#endif // _NEXT_SPOT_H_

