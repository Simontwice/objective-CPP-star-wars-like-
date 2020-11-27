
#ifndef _MAP_H_
#define _MAP_H_

#include <unordered_map>
#include <vector>
#include "Square.h"
#include "../../misc/Pair.h"
#include "../../UnitPosition.h"

class Map {
private:

    Square ***board;
    int length;
    int width;
    int **movement_matrix;

public:

    Map(int** m, char **terra, int w, int l);

    ~Map() {
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < width; ++j) {
                delete board[i][j];
            }
        }
        delete board;
    }

    Map(const Map &) = delete;

    Map &operator=(const Map &) = delete;

    Unit* get_inhabitant_at(Pair coord){return board[coord.x][coord.y]->get_inhabitant();}

    void set_inhabitant_at(Unit* inhabitant, Pair coord){board[coord.x][coord.y]->set_inhabitant(inhabitant);}

    void delete_inhabitant_at(Pair coord){board[coord.x][coord.y]->delete_inhabitant();}

    void kill_inhabitant_at(Pair coord){board[coord.x][coord.y]->kill_inhabitant();}

    bool move_unit(Pair start_position, Pair end_position);

    bool is_it_in_map(int x, int y);

    bool is_in_sight(Pair p){return board[p.x][p.y]->is_in_sight();}

    bool can_bot_advance(Unit* bot, Pair p);

    bool can_I_walk(Unit* bot, Pair p);

    bool is_rebel_at_square(Pair p){if(board[p.x][p.y]->get_inhabitant()==nullptr) return 0; return (board[p.x][p.y]->get_inhabitant()->get_affiliation() == REBEL);}

    bool is_dd_at_square(Pair p){if(board[p.x][p.y]->get_detector()==nullptr) return 0; return 1;}

    bool set_detector_at(Pair p,int index, int range){if(board[p.x][p.y]->get_detector()==nullptr) {board[p.x][p.y]->set_detector(new DD(0,range,index)); return true;}return false;}

    DD* get_dd_at(Pair p){if(board[p.x][p.y]->get_detector()==nullptr) return nullptr; return board[p.x][p.y]->get_detector(); }

    void stomp_dd(Pair p) {if(is_dd_at_square(p)) {board[p.x][p.y]->kill_detector(); }}

    bool flatten_at(Pair p){if(board[p.x][p.y]->what_terra()==FIELD) return false; else {board[p.x][p.y]->flatten(); return true;}}

    void revive_at(Pair p){board[p.x][p.y]->revive();}

    void set_visible_at(Pair p){board[p.x][p.y]->set_visible();}

    void set_invisible_at(Pair p){board[p.x][p.y]->set_invisible();}

    void show_everything();

    void print();

};
#endif // _MAP_H_

