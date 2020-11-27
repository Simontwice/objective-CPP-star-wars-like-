#include"Terra.h"
#ifndef _WOODS_H_
#define _WOODS_H_

class Woods : public Terra {
    TerrainType terrain;
public:

    Woods() : Terra(), terrain(WOODS) {}

    virtual ~Woods() = default;

    Woods(const Woods &) = delete;

    Woods &operator=(const Woods &) = delete;

    virtual TerrainType what_terra() { return WOODS; }

    void print() { std::cout << "|"; }

};

#endif // _WOODS_H_

