#ifndef WEAPON_H
#define WEAPON_H

#include <Item.h>


class Weapon : public Item
{
private:
    unsigned damage_from;
    unsigned damage_to;
public:
    Weapon();
    ~Weapon();
};

#endif // WEAPON_H
