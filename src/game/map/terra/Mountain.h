#include"Terra.h"
#ifndef _MOUNTAIN_H_
#define _MOUNTAIN_H_

class Mountain : public Terra {
TerrainType terrain;
public:

    Mountain() : Terra(), terrain(MOUNTAIN) {}

    virtual ~Mountain() = default;

    Mountain(const Mountain &) = delete;

    Mountain &operator=(const Mountain &) = delete;

    virtual TerrainType what_terra() { return terrain; }

    void print() override { std::cout << "^"; }

};

#endif // _MOUNTAIN_H_


