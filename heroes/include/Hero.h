#ifndef HERO_H
#define HERO_H

#include <string>
#include "Weapon.h"
#include "Chest.h"
#include "Boots.h"
#include "Character.h"
#include <vector>

class Hero : public Character
{
private:
    Boots* boots;
    Chest* chest;
    Weapon* weapon;
    std::vector<Item> inventory;
    std::pair<int, int> coords;
public:
    Hero();
    ~Hero();

    void set_coordinates(int x, int y);
    std::pair<int, int> get_coordinates() const;

    virtual void print() const;

    virtual std::pair<int, int> move(std::pair<int, int> dir);
};

#endif // HERO_H
