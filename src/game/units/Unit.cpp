#include"Unit.h"


bool Unit::subtract_movement_points(int used_points) {
        if (used_points > movement_points) {
            return 0;
        }
        else {
            movement_points -= used_points;
            return 1;
        }
}
