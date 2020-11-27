#include"Terra.h"
#ifndef _FIELD_H_
#define _FIELD_H_

class Field : public Terra {
TerrainType terrain;
public:

    Field() : Terra(), terrain(FIELD){}

    virtual ~Field() = default;

    Field(const Field &) = delete;

    Field &operator=(const Field &) = delete;

    virtual TerrainType what_terra() { return terrain; }

    void print() override { std::cout << " "; }

};

#endif // _FIELD_H_

