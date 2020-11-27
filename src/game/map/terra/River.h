#include"Terra.h"
#ifndef _RIVER_H_
#define _RIVER_H_

class River : public Terra {
TerrainType terrain;
public:

    River() : Terra(), terrain(RIVER) {}

    virtual ~River() = default;

    River(const River &) = delete;

    River &operator=(const River &) = delete;

    virtual TerrainType what_terra() { return terrain; }

    void print() { std::cout << "="; }

};

#endif // _RIVER_H_


