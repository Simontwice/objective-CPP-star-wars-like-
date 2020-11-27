#include "Terra.h"
#include "../../misc/Includes.h"

#ifndef _OCEAN_H_
#define _OCEAN_H_

class Ocean : public Terra {
TerrainType terrain;
public:

    Ocean() : Terra(), terrain(OCEAN) {}

    virtual ~Ocean() = default;

    Ocean(const Ocean &) = delete;

    Ocean &operator=(const Ocean &) = delete;

    virtual TerrainType what_terra() { return terrain; }

    void print() override { std::cout << "~"; }

};

#endif // _OCEAN_H_

