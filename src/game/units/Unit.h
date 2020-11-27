#include "../misc/Names.h"
#ifndef _UNIT_H_
#define _UNIT_H_

class Unit {

protected:
    int movement_points;
    int speed;
    int range;
    bool alive;

public:

    Unit() = delete;

    Unit(int a, int b) : movement_points(a), speed(a), range(b), alive(true) {} // powstaja z szybkoscia i zasiegiem
    virtual ~Unit() {}

    Unit(const Unit &) = delete;

    Unit &operator=(const Unit &) = delete;

    virtual Affiliation get_affiliation() const = 0;

    virtual UnitType say_your_name() const = 0;

    virtual void print()=0;

    void replenish_points() { movement_points = speed; }

    int get_range() { return range; }

    int get_movement() const { return movement_points; }

    bool subtract_movement_points(int used_points);

    bool is_alive() {
        return alive;
    }
    void kill_self() {
    	alive=false;
	}

	void revive()
	{
	    alive=true;
	}

	virtual int get_visited(Unit* unit) = 0;

	virtual void hello()=0;

	void replenish(){movement_points=speed;}

};

#endif // _UNIT_H
