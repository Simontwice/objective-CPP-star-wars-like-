#ifndef _NAMES_H_
#define _NAMES_H_

enum UnitType : int { // enum of unit types
    REBEL_SOLDIER=0,
    LEIA=1,
    PROGRAMMER=2,
    LUKE=3,
    ROBOT=4,
    VADER=5,
    CHANCELLOR=6,
    DETECTOR=7
};

enum TerrainType : int { // enum of terrains
    OCEAN=0,
    FIELD=1,
    MOUNTAIN=2,
    RIVER=3,
    WOODS=4
};

enum Affiliation { // the goodies and baddies
    EMPIRE,
    REBEL
};

#endif
