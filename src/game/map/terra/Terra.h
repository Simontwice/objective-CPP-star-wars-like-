#include "../../misc/Names.h"
#ifndef _TERRA_H_
#define _TERRA_H_

class Terra {

public:

    Terra() {}

    virtual ~Terra() {}

    Terra(const Terra &) = delete;

    Terra &operator=(const Terra &) = delete;

    virtual TerrainType what_terra() = 0;

    virtual void print() = 0;
};

#endif // _TERRA_H_
