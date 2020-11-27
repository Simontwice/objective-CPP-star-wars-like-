#include"Map.h"


Map::Map(int** m, char **terra, int l, int w)
{
    movement_matrix=m;
    length=l; width=w;
    board = new Square **[w];
    for (int i = 0; i < l; ++i) {
        board[i] = new Square *[l];
    }

    for (int i = 0; i < w; ++i)
    {
        for (int j = 0; j < l; ++j)
        {
            board[i][j] = new Square(terra[i][j]);
        }
    }
}

void Map::print()
{
        std::cout << "\n";

        for (int j = 0; j < width; ++j) {

            for (int i = 0; i < length; ++i) {
            	if(i==0) std::cout<<" ";
                board[j][i]->print();
            }
            std::cout << "\n";
        }
}



void Map::show_everything()
{
        for(int j=0;j < width; ++j)
        {
            for (int i = 0; i < length; ++i)
                board[j][i]->set_visible();
        }
}
bool Map::move_unit(Pair start_position, Pair end_position)
{
    TerrainType destination_landscape = board[end_position.x][end_position.y]->what_terra();
    Unit* MovingUnit = board[start_position.x][start_position.y]->get_inhabitant();
    int MoveCost = movement_matrix[(int)MovingUnit->say_your_name()][(int)destination_landscape];
//    std::cout<<"\n move cost:"<<MoveCost<<"\n";

    if ( (MoveCost>=0)  and (MovingUnit->subtract_movement_points ( MoveCost )) )
    {
        set_inhabitant_at(MovingUnit,end_position);
      //  std::cout<<"\n postawiony"<<"\n";
        delete_inhabitant_at(start_position);
      //  std::cout<<"\n usuniety"<<"\n";

        return true;
    }
    else return false;
}

bool Map::is_it_in_map(int x, int y){return x>=0 and y>=0 and x<width and y<length;}

bool Map::can_I_walk(Unit* bot, Pair p)
{
    bool can_cross = (movement_matrix[bot->say_your_name()][board[p.x][p.y]->what_terra()] >= 0);
    bool enough_movement = (movement_matrix[bot->say_your_name()][board[p.x][p.y]->what_terra()] <= bot->get_movement());

    return can_cross and enough_movement;

}

bool Map::can_bot_advance(Unit* bot, Pair p)
{
    bool can_cross = (movement_matrix[bot->say_your_name()][board[p.x][p.y]->what_terra()] >= 0);
    bool enough_movement = (movement_matrix[bot->say_your_name()][board[p.x][p.y]->what_terra()] <= bot->get_movement());
    bool can_kill=true;
    if(get_inhabitant_at(p)==nullptr) can_kill=true;
    else
    {
        can_kill = (get_inhabitant_at(p) -> get_visited(bot) == 1);
    }

    return can_cross and enough_movement and can_kill;

}


