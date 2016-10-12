#ifndef CUI_H
#define CUI_H

#include <iostream>
#include "Hero.h"
#include "Weapon.h"
#include "Chest.h"
#include "Boots.h"
#include "Monster.h"
#include "Map.h"
#include "Game.h"

#include <iomanip>

class CUI
{
private:
    const Directions DIRECTION;
    Game game;
public:
    CUI(std::string path);
    ~CUI();

    void GAME_OVER() const;
    void print_battle(Battle* battle);

    void print() const;
    char get_input() const;
    void proceed_input(char option);
    void proceed_battle_input(char option, Battle* battle);
};

#endif // CUI_H
