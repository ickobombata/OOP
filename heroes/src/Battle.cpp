#include "Battle.h"

Battle::Battle(Hero* hero, Monster* monster, std::pair<int, int> m_coords)
    :hero(NULL), monster(NULL), m_coords(m_coords)
{
    //ctor
    this->hero = hero;
    this->monster = monster;
}

Battle::~Battle()
{
    //dtor
}

std::pair<int, int> Battle::get_monster_coordinates() const
{
    return m_coords;
}


void Battle::hero_autoattack()
{
    monster->autoattack(hero);
    hero->autoattack(monster);
}
void Battle::hero_defend()
{
    this->hero->set_health(hero->get_health() + 20);// NOT NOT NOT NOT
    // again MONSTER ATTACKS
}
void Battle::attack(void(*func)(Hero* hero, Monster* monster))
{
    func(hero, monster);
    hero->autoattack(monster);
}
void Battle::monster_autoattack()
{
    hero->autoattack(monster);
}

void Battle::print_battle() const
{
    int health_bar_size = 15;
    std::cout << hero->get_name() << "-|";
    std::cout << std::setw(health_bar_size) << hero->get_health() << "|     "
              << monster->get_name() << "-|" << std::setw(health_bar_size) << monster->get_health()  //* 100 / health_bar_size
              << "|";
    std::cout << "battle output";
}
