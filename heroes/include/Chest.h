#ifndef CHEST_H
#define CHEST_H

#include <Item.h>


class Chest : public Item
{
private:
    unsigned health;
    unsigned armor;
    unsigned resistance;
public:
    Chest();
    ~Chest();
};

#endif // CHEST_H
