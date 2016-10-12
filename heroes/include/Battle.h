#ifndef BATTLE_H
#define BATTLE_H

#include "Hero.h"
#include "Monster.h"
#include <iomanip>

class Battle
{
public:
    Hero* hero;
    Monster* monster;
    std::pair<int, int> m_coords;
public:
    Battle(Hero* hero, Monster* monster, std::pair<int, int> m_coords);
    ~Battle();
    void attack(void(*func)(Hero* hero, Monster* monster));

    void hero_autoattack();
    void hero_defend();

    void monster_autoattack();

    bool is_over() const {return (!this->hero->is_alive() || !this->monster->is_alive()) ? true : false;}

    std::pair<int, int> get_monster_coordinates() const;

    void print_battle() const;
};

#endif // BATTLE_H
