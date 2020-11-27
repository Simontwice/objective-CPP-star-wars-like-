#include <unordered_map>
#include "input_readers/ArrayReader.h"
#include "input_readers/ParamReader.h"
#include "game/Game.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//using namespace std;

int main(int argc, char **argv) {

    std::unordered_map<std::string, int> params = read_params("resources/pars.txt"); //get parameters from file
    char **terrain = read_char_array("resources/terrain.txt"); // get terrain from file
    char **enemies = read_char_array("resources/enemies.txt"); // get enemies and their positions from file
    int **movement_costs = read_int_array("resources/movement_costs.txt");

    Game *game = new Game(movement_costs, terrain, enemies, params);
    game->run();

    delete game;
    delete terrain;
    delete enemies;
    delete movement_costs;
    return 0;
}
