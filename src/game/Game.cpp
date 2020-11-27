#include "Game.h"
#include "misc/NextSpot.h"
#include <conio.h>

Game::Game(int** movement, char **terra, char **enemies, std::unordered_map<std::string, int> params)
{
    Map* m = new Map(movement,terra,params["width"],params["length"]);
    map = m;
    game_time=params["time_limit"];
    this->params=params;
    for (int i = 0; i < params["width"]; ++i)
    {
        for (int j = 0; j < params["length"]; ++j)
        {
            if (enemies[i][j] != '0')
            {
                Unit* newman = nullptr;
                switch (enemies[i][j])
                {
                    case 'c':
                    {
                        newman = new Chancellor(0, params["Enemy_radius"], empire.size());
                    }
                        break;
                    case 'v':
                    {
                        newman= new Vader(params["Vader_speed"], params["Enemy_radius"], empire.size());
                    }
                        break;
                    case 'r':
                    {
                        newman = new Robot(params["Robot_speed"], params["Enemy_radius"], empire.size());
                    }
                        break;
                    default: break;
                }
                if(newman)
                {
                    UnitPosition* U= new UnitPosition(newman, Pair(i, j));
                    empire.push_back(U);
                    map->set_inhabitant_at(newman,Pair(i,j));
                }
            }

        }
    }

    int max_width = params["width"];
    int width = params["start_area_width"];
    int length = params["start_area_length"];

    int a1 = params["Rebel_soldier_number"];
    int a2 = params["Programmer_number"];

    Pair coordinates=Pair();

    for (int i = 0; i < a1; ++i)
     {
        coordinates = NextSpot(width, length, i);
        Unit* newman = new RebelSoldier(params["Rebel_soldier_speed"], params["Rebel_soldier_radius"], rebels.size());
        UnitPosition* U = new UnitPosition(newman, Pair(max_width - coordinates.x - 1, coordinates.y));
        rebels.push_back(U);


    }

    for (int i = a1; i < a1+a2; ++i)
    {

        coordinates = NextSpot(width, length, i);
        Unit* newman = new Programmer(params["Programmer_speed"], params["Programmer_radius"], rebels.size());
        UnitPosition* U = new UnitPosition(newman, Pair(max_width - coordinates.x - 1, coordinates.y));
        rebels.push_back(U);

    }

    Unit* newman = new Leia(params["Leia_speed"], params["Leia_radius"], rebels.size());
    coordinates = NextSpot(width, length, a1+a2);
    UnitPosition* U = new UnitPosition(newman, Pair(max_width - coordinates.x - 1, coordinates.y));

    rebels.push_back(U);
    coordinates = NextSpot(width, length, a1+a2+1);
    newman = new Luke(params["Luke_speed"], params["Luke_radius"], rebels.size());
    U = new UnitPosition(newman, Pair(max_width - coordinates.x - 1, coordinates.y));
    rebels.push_back(U);


    for (int i = 0; i < (int)rebels.size(); ++i)
    {
        coordinates = NextSpot(width, length, i);
        map->set_inhabitant_at(rebels[i]->unit,Pair(max_width - coordinates.x - 1,coordinates.y));
    }
}
void Game::print_vector(std::vector<UnitPosition*> vec)
{
    for(int i=0; i<(int) vec.size(); ++i)
    {
        if(vec[i]->unit->is_alive())
        {
            std::cout<<i<<":";
            std::cout<<"[ "<<vec[i]->position.x<<","<<vec[i]->position.y<<" ] ";
            vec[i]->unit->hello();
            std::cout<<": "<<vec[i]->unit->get_movement()<<"\n";
        }

    }
}

void Game::poor_print_vector(std::vector<UnitPosition*> vec)
{
        for(int i=0; i<(int) vec.size(); ++i)
    {
        if(vec[i]->unit->is_alive())
        {
            std::cout<<i<<":";
            std::cout<<"[ "<<vec[i]->position.x<<","<<vec[i]->position.y<<" ] ";
        }

    }
    std::cout<<"\n";
}


void Game::print_rebels(){std::cout<<" \n Rebels: \n" ; print_vector(rebels);}

void Game::print_empire(){std::cout<<" Empire: \n" ; print_vector(empire);}

void Game::print_detectors(){std::cout<<" Detectors: \n" ; poor_print_vector(detectors);}

bool Game::move_bot(UnitPosition *unitpos)
    {

        Unit* bot = unitpos -> unit;
        int x = unitpos -> position.x, y = unitpos -> position.y;

       // std::cout<<"\n "<<"["<<x<<","<<y<<"] \n";

        std::vector <Pair> priority_squares;
        std::vector <Pair> available_squares;
        std::vector <Pair> chosen_set;

        for (int i = -1; i < 2; ++i)
        {
            for (int j = -1; j < 2; ++j)
            {
                if ( !map -> is_it_in_map(x+i,y+j) ) continue;

                if ( i == 0 && j == 0 )continue;

                if ( map -> can_bot_advance( bot,Pair(x+i,y+j) ) )
                {
                    available_squares.emplace_back(Pair(x+i, y+j));
                }
            }
        }

        //std::cout<<"liczba mozliwych pol:"<<(int)available_squares.size() ;

        for( int i=0 ; i < (int)available_squares.size() ; i++)
        {
            if(map->is_rebel_at_square(available_squares[i]) || map->is_dd_at_square(available_squares[i]))
            {
               //std::cout<<"\n BEDZIE NOWY EMPLACE priORITY \n";
            priority_squares.emplace_back(available_squares[i]);
            }

        }
        //std::cout<<"\n koniec PRIORITY \n";
        //std::cout<<"\n ruszam ziomka \n"<<"liczba priority pol:"<<(int)priority_squares.size() ;


        if (available_squares.empty()) {return 0;}

        if (priority_squares.empty()) {chosen_set=available_squares;}

        else chosen_set = priority_squares;

        //std::cout<<"\n LOSUJ RUCH \n";

        int rand_value = rand();
        //std::cout<<"losuje: \n"<<chosen_set.size();
        int chosen_square_index = rand_value % chosen_set.size();
        //std::cout<<chosen_square_index;

        Pair chosen_square_coordinates = chosen_set[chosen_square_index];

        //std::cout<<"wybrane pole: \n"<<chosen_square_coordinates.x<<chosen_square_coordinates.y<<"\n";

        MoveEngine_ExecuteInteraction(chosen_square_coordinates , unitpos);

      //  std::cout<<"ruszyl sie\n";

        if ( map->is_in_sight(Pair(x,y)) || map->is_in_sight(chosen_square_coordinates))
        {
            map->print();
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
        return 1;


    }

void Game::move_bots()
{
//        std::cout<<"\n teraz move_bots \n";
        for (int i=0; i<(int)empire.size(); ++i)
            {
              //  std::cout<<"\n teraz "<<i<<"\n"<<(int)empire[i]->unit->is_alive();
                while (empire[i]->unit->is_alive() and move_bot(empire[i]))
                {
                    update_visibility();
                //    std::cout<<"\n bot sie ruszyl \n";
                    if (!crew_alive()) break;
                }
                if (!crew_alive()) break;
            }
//        print_empire();

}

bool Game::MoveEngine_ExecuteInteraction(Pair standing_position, UnitPosition* unitpos)
{

    Unit *standingUnit = map->get_inhabitant_at(standing_position);
    Unit *movingUnit =  unitpos->unit;

   // std::cout<<"\n mam ich \n";

    int move=0;

    if(standingUnit!=nullptr) {move = standingUnit->get_visited(movingUnit);}
//    std::cout<<"\n patrze na move \n";
    switch(move) {
        case -1:std::cout<<"\n can't do it! \n"; return false; //nic sie nie dzieje
        case 0: return MoveEngine_Move(standing_position,unitpos);
        case 1: return MoveEngine_AttackMove(standing_position,unitpos);
        case 2: return MoveEngine_SuicideMove(standing_position,unitpos);
        case 3: return MoveEngine_LeiaFinalShowdown(standing_position, unitpos);
        default: return false;
    }
}

bool Game::MoveEngine_Move(Pair standing_position, UnitPosition* unitpos)
{
    Pair moving_position = unitpos->position;
 //   std::cout<<"\n zwykly ruch \n";
    if(map->move_unit(moving_position,standing_position))
    {
        if(unitpos->unit->get_affiliation() == EMPIRE)
        {
            if(map->is_dd_at_square(standing_position))
            {
                map->stomp_dd(standing_position);
                std::cout<<"killed";
            }

        }
        unitpos->position = standing_position;
        //std::cout<<"\n zwykly ruch skonczony \n";
        return true;
    }

    else
    {
        std::cout<<"\n can't move here! \n";
        return false;
    }
}

bool Game::MoveEngine_AttackMove(Pair standing_position, UnitPosition* unitpos)
{
    Pair moving_position = unitpos->position;
    map->kill_inhabitant_at(standing_position);
    if(map->move_unit(moving_position,standing_position)) return true;
    else {map->revive_at(standing_position); return false;}
}

bool Game::MoveEngine_SuicideMove(Pair standing_position, UnitPosition* unitpos)
{
    Pair moving_position = unitpos->position;
    if(map->can_I_walk(unitpos->unit,standing_position))
    {
        map->kill_inhabitant_at(moving_position);
        map->delete_inhabitant_at(moving_position);
        return true;
    }
    else return false;
}

bool Game::MoveEngine_LeiaFinalShowdown(Pair standing_position, UnitPosition* unitpos)
{
    Pair moving_position = unitpos->position;


    if(chancellor_threatened())
    {

        return MoveEngine_AttackMove(standing_position,unitpos);
    }
    else
    {
        std::cout<<"\n She can't convince him herself! \n";
        return false;
    }
}

bool Game::MoveEngine_SetDetector(UnitPosition* unitpos)
{
    Pair standing_position = unitpos->position;
    if(map->get_inhabitant_at(standing_position)->get_movement() >= params["dd_setup_time"])
    {
        if(map->set_detector_at(standing_position,(int)detectors.size(),params["DD_radius"]))
        {
            std::cout<<"detector placed \n";
            map->get_inhabitant_at(standing_position)->subtract_movement_points(params["dd_setup_time"]);
            detectors.emplace_back(new UnitPosition(map->get_dd_at(standing_position), standing_position));
            return true;
        }
        else  {std::cout<<"detector is already there! \n"; return false;}
    }
    else {std::cout<<"not enough movement! \n"; return false;}

}

bool Game::MoveEngine_Flatten(UnitPosition* unitpos)
{
    if(unitpos->unit->get_movement() >= params["landscaping_time"])
    {
        if(map->flatten_at(unitpos->position))
        {
            unitpos->unit->subtract_movement_points(params["landscaping_time"]);
            std::cout<<"\n Successfully converted into plains. \n";
            return true;
        }
        else
        {
            std::cout<<"\n These are plains! \n";
             return false;
        }


    }
    else
    {
        std::cout<<"\n Not enough movement! \n";
        return false;
    }


}

bool Game::chancellor_dead()
{
    for (UnitPosition* i : empire)
        if(i->unit->say_your_name() == CHANCELLOR and i->unit->is_alive())
        {
            return false;
        }

    return true;
}

bool Game::chancellor_threatened()
{
    int x=-1,y=-1;
    for(int i=0; i<(int)empire.size();++i)
    {

        if(empire[i]->unit->say_your_name()==CHANCELLOR)
        {
        x = empire[i]->position.x;
        y = empire[i]->position.y;
        break;
        }

    }
    if((x!=-1) and (y!= -1))
    {
        for(int i=-1; i<2; ++i)
    	{
    		for(int j=-1; j<2; ++j)
    		{
    			if(i == 0 and j == 0 ) continue;
    			if (map->is_it_in_map(x+i,y+j) and map->get_inhabitant_at(Pair(x+i,y+j))!=nullptr )
    			{
    				switch (map->get_inhabitant_at(Pair(x+i,y+j))->say_your_name())
    			    {
    				case PROGRAMMER:
    				case LUKE: std::cout<<"\n jest! \n";return true;
                    default:  break;
					}

				}
			}
		}
    }

    return false;
}

bool Game::crew_alive()
{
    bool Leia_alive;bool Help_alive;

    for(int i=0; i< (int)rebels.size();++i)
    {
        switch(rebels[i]->unit->say_your_name())
        {
            case LEIA:
            {
                if (!rebels[i]->unit->is_alive()) return false;
                else Leia_alive = true;
                break;
            }
            case PROGRAMMER:
            case LUKE: if (rebels[i]->unit->is_alive()) {Help_alive=true; break;}
            default: break;
        }
    }
    return Leia_alive and Help_alive;
}

void Game:: update_visibility()
{

    for (int i = 0; i < params["width"]; ++i)
    {
        for (int j = 0; j < params["length"]; ++j)
        {
            map->set_invisible_at(Pair(i,j));
        }

    }


    for(int i=0; i<(int)rebels.size(); ++i)
    {
        if(rebels[i]->unit->is_alive())  see_around(rebels[i]->position, rebels[i]->unit->get_range());
    }
    for(int j=0; j<(int)detectors.size(); ++j)
    {
        std::cout<<detectors[j]->unit->get_range();
        if(detectors[j]->unit->is_alive()) see_around(detectors[j]->position, detectors[j]->unit->get_range());
    }
}


void Game::see_around(Pair p, int range)
{
    int x=p.x; int y=p.y;
    for (int i = x - range; i <= x + range; ++i)
    {
            for (int j = y-range; j <= y+range; ++j)
            {
                if(!map->is_it_in_map(i,j)) continue;
                map->set_visible_at(Pair(i,j));
            }
    }
}

bool Game::end_turn()
{
    if(game_over())return false;
    else
    {
        move_bots();
        update_visibility();
        std::cout << "\n" << game_time << " TURNS LEFT!";
        replenish_points();
        game_time--;
        return true;
    }

}

void Game::replenish_points()
{
    for (UnitPosition* i : empire) i->unit->replenish();
    for (UnitPosition* i : rebels) i->unit->replenish();
}

void Game::run()
{
    	update_visibility();
    	show_map();

        while (get_order() && 0 < game_time) {}

        announce_end();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

bool Game::get_order()
{
    print_rebels();
    update_visibility();

    std::string a;
    std::cout<<"\n select number - selects a unit \n end - ends turn \n quit - forfeits the game \n";
    std::cin >> a;

    if(a ==  "quit") return false;
    else if(a ==  "end")
    {
        if(end_turn())return true;
        else return false;
    }
    else if(a ==  "select")
    {
        std::cout<<"\n Pick a unit \n";
        int number;
        std::cin >> number;
        while( number >=(int) rebels.size() || ( number < (int)rebels.size() and !rebels[number]->unit->is_alive()))
        {
            if(number >=(int) rebels.size()) std::cout<<"\n Pick a unit! \n";
            else std::cout<<"\n This unit is dead! \n";
            std::cin>>number;

        }
        Unit* chosen_rebel = rebels[number]->unit;

        std::cout << "\n Character " << number<< " is selected. \n Use w/a/s/d keys to move and n key to set a detector. \n Use c to see detector list. \n Use f to flatten a square. \n Use m to see movement points. \n Use p to see the map. \n Use q to unselect." << std::endl;
        bool should_print =false;
        char input = getch();
        while(input != 'q' and chosen_rebel->is_alive())
        {
            Pair position = rebels[number]->position;
            switch(input)
            {
                case 'a': if(MoveEngine_ExecuteInteraction(Pair(position.x , position.y -1 ),rebels[number]))	{should_print=1; break;} else {should_print=0;	break;}
                case 'd': if(MoveEngine_ExecuteInteraction(Pair(position.x , position.y +1 ),rebels[number]))	{should_print=1; break;} else {should_print=0;	break;}
                case 'w': if(MoveEngine_ExecuteInteraction(Pair(position.x -1, position.y  ),rebels[number]))	{should_print=1; break;} else {should_print=0;	break;}
                case 's': if(MoveEngine_ExecuteInteraction(Pair(position.x +1, position.y  ),rebels[number]))	{should_print=1; break;} else {should_print=0;	break;}
                case 'n': MoveEngine_SetDetector(rebels[number]); should_print=0; break;
                case 'f': MoveEngine_Flatten(rebels[number]); should_print=0; break;
                case 'm': print_rebels(); should_print=0; break;
                case 'c': print_detectors();should_print=0; break;
//                case 'e': print_empire(); should_print=0; break;
                case 'p': show_map();should_print=0; break;
                default: should_print =0; break;
            }
            update_visibility();
            if(should_print)
            {
                show_map();
            }
            input = getch();
        }
        std::cout << "Rebel " << number << " unselected \n";
        return true;
    }
    return true; //default, when input is wrong
}


