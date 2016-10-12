#include "Character.h"

Character::Character()
    :health(1000), damage(50), armor(10), resistance(10), mana(10), name("pero"), speed(10)
{
    //ctor
}

Character::~Character()
{
    //dtor
}


int Character::get_health() const
{
    return this->health;
}
int Character::get_mana() const
{
    return this->mana;
}
int Character::get_damage() const
{
    return this->damage;
}
int Character::get_armor() const
{
    return this->armor;
}
int Character::get_speed() const
{
    return this->speed;
}
int Character::get_resistance() const
{
    return this->resistance;
}

void Character::set_health(int x)
{
    if(x < 0)
        x = 0;
    this->health = x;
}
void Character::set_mana(int x)
{
    if(x < 0)
        x = 0;
    this->mana = x;
}
void Character::set_damage(int x)
{
    this->damage = x;
}
void Character::set_speed(int x)
{
    this->speed = x;
}
void Character::set_resistance(int x)
{
    this->resistance = x;
}
void Character::set_armor(int x)
{
    this->armor = x;
}


void Character::autoattack(const Character* attacker)
{
    // from LOL :D :D
    int harm_done = (double)attacker->get_damage() *
                         (double)((this->get_armor() >= 0) ? 100/(double)(100+(double)this->get_armor())
                                               : 2 - 100/(double)(100-this->get_armor()));

    this->set_health(this->get_health() - harm_done);
}
