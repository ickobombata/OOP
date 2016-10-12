#include "CUI.h"

CUI::CUI(std::string path)
    :game(path)
{
    char option;
    try
    {
        int i = 0;
        while(true)
        {
            game.update();

            print();

            option = get_input();
            proceed_input(option);
            // if in battle print sonmethiugn
            if(game.in_battle())
            {
            /////// do the battle
                //std::cout << game.is_over();
                //get_input();
                Battle* battle = game.get_battle();
                system("clear");
                std::cout << "Press any key to start the battle!\n";
                option = get_input();
                while(!battle->is_over())
                {
                    print_battle(battle);
                    option = get_input();
                    proceed_battle_input(option, battle);

                }
                if(game.is_hero_alive())
                    game.won_battle();
                else
                {
                    GAME_OVER();
                    break;
                }

            }
        }
    }
    catch(...)
    {}
}

CUI::~CUI()
{
    //dtor
}

void CUI::GAME_OVER() const
{
    system("clear");

    std::cout << "THE GAME IS OVER YOU LOST";
}
void CUI::print_battle(Battle* battle)
{
    system("clear");
    battle->print_battle();

    std::cout << std::endl << "Commands : \n"
                           << "a - autoattack\n"
                           << "d - defend\n"
                           << "s - use spell\n";
}
void CUI::proceed_input(char option)
{
    if(option == 'a')
        game.move_hero(DIRECTION.left);
    if(option == 's')
        game.move_hero(DIRECTION.down);
    if(option == 'w')
        game.move_hero(DIRECTION.up);
    if(option == 'd')
        game.move_hero(DIRECTION.right);
    if(option == 'p')
        throw 'END';
}

void CUI::proceed_battle_input(char option, Battle* battle)
{
    if(option == 'a')
        battle->hero_autoattack();
    if(option == 'd')
        battle->hero_defend();
    if(option == 'p')
        throw 'END';
}

char CUI::get_input() const
{  // Set terminal to raw mode
  system("stty raw");

  // Wait for single character
  char input = getchar();

  // Reset terminal to normal "cooked" mode
  system("stty cooked");
  return input;
}

void CUI::print() const
{
    system("clear");

    for(int i = 0 ; i < game.get_map()->height(); ++i)
    {
        for(int j = 0; j < game.get_map()->width(); ++j)
            game.get_map()->get_cell(i, j)->print();
        std::cout << std::endl;
    }
}
