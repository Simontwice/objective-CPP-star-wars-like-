#include <vector>
#include "units/Unit.h"
#include "misc/Pair.h"

#ifndef _UNIT_POSITION_STRUCT_
#define _UNIT_POSITION_STRUCT_

class UnitPosition {
public:

    Unit *unit;
    Pair position;

    UnitPosition(Unit *u, Pair p) : unit(u), position(p) {}
};

#endif // _UNIT_POSITION_STRUCT_
