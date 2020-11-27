#include "../terra/EarthFormations.h"
#include "../../units/UnitHeader.h"
#ifndef _SQUARE_H_
#define _SQUARE_H_

class Square {
private:
    Unit *inhabitant;
    DD *detector;
    Terra *landscape;
    bool in_sight;

public:

    Square() : inhabitant(nullptr), detector(nullptr), landscape(nullptr),  in_sight(false) {}

    Square(char t) : inhabitant(nullptr), detector(nullptr),
                                                     in_sight(false) {
        Terra *p = nullptr;
        switch(t)
        {
            case 'f': p = new Field; break;
            case 'm': p = new Mountain; break;
            case 'r': p = new River; break;
            case 'w': p = new Woods; break;
            case 'o': p = new Ocean; break;
            default: break;
        }
        landscape = p;

    }

    ~Square() {
        delete detector;
        delete landscape;
    }

    Square &operator=(const Square &) = delete;

    Square(const Square &) = delete;

    TerrainType what_terra() { return landscape->what_terra(); }

    UnitType what_unittype() { return inhabitant->say_your_name(); }

    bool anyone_there() { return inhabitant != nullptr; }

    void set_inhabitant(Unit *g) {
        inhabitant = g;
    }

    Unit *get_inhabitant()
    {
        return inhabitant;
    }

    void delete_inhabitant() { inhabitant = nullptr; }

    void kill_inhabitant() { inhabitant->kill_self();}

    void set_detector(DD *g) { detector = g;}

    DD *get_detector() {
        return detector;
    }

    void delete_detector() {detector = nullptr;}

    void kill_detector()
    {
        if(detector != nullptr)
        {
            detector->kill_self();
            delete_detector();
            std::cout<<"zabity";
        }

    }

    void print()
    {

    	if(in_sight)
        {
		    if (inhabitant) inhabitant -> print();
            else if (detector) detector -> print();
            else landscape -> print();
		}
		else std::cout << "?";
    }


    void flatten() {
        delete landscape;
        landscape = new Field();
    }
    void set_visible(){in_sight=true;}

    void set_invisible(){in_sight=false;}

    bool is_in_sight(){return in_sight;}

    void revive(){inhabitant->revive();}

};

#endif // _SQUARE_H_
