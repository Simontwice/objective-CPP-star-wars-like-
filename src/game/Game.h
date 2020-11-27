//#include"MoveEngine.h"

#ifndef _GAME_H_
#define _GAME_H_

#include "map/map_structures/Map.h"
#include "misc/Pair.h"
#include <vector>
#include <thread>
#include <string>
#include <iostream>

class Game
{
private:
//    MoveEngine* m_engine;
    Map* map;
    std::unordered_map <std::string, int> params;
    std::vector<UnitPosition*> rebels;
    std::vector<UnitPosition*> empire;
    std::vector<UnitPosition*> detectors;
    int **movement_matrix;
    int game_time;
public:


    Game(int** movement, char **terra, char **enemies, std::unordered_map<std::string, int> params);

    ~Game(){ delete map;}

    void print_vector(std::vector<UnitPosition*> vec);

    void poor_print_vector(std::vector<UnitPosition*> vec);

    void print_rebels();

    void print_empire();

    void print_detectors();

    bool crew_alive();

    bool chancellor_threatened();

    bool chancellor_dead();

    bool game_over() {if(!crew_alive() or chancellor_dead()) return 1; return 0;}

    void announce_end(){if(chancellor_dead()) std::cout<<"\n VICTORY! \n"; else std::cout<<"\n DEFEAT! \n";}

    bool move_bot(UnitPosition *unitpos);

    void move_bots();

    void show_map(){map->print();}

    void update_visibility();

    void see_around(Pair p, int range);

    void show_everything(){map->show_everything();map->print();}

    bool MoveEngine_ExecuteInteraction(Pair standing_position, UnitPosition* unitpos);

    bool MoveEngine_Move(Pair standing_position, UnitPosition* unitpos);

    bool MoveEngine_AttackMove(Pair standing_position, UnitPosition* unitpos);

    bool MoveEngine_SuicideMove(Pair moving_position, UnitPosition* unitpos);

    bool MoveEngine_LeiaFinalShowdown(Pair standing_position, UnitPosition* unitpos);

    bool MoveEngine_SetDetector(UnitPosition* unitpos);

    bool MoveEngine_Flatten(UnitPosition* unitpos);

    void replenish_points();

    bool get_order();

    bool end_turn();

    void run();
};
#endif // _GAME_H_
